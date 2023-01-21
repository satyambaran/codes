#include <bits/stdc++.h>

template <typename T, typename Op>
class accumulator
{
public:
    accumulator(T init, Op op);

    template <typename U>
    void generic_push(U&& value);

    void push(T value);

    T finalize();

private:
    struct pimpl;
    std::unique_ptr<pimpl> pimpl_;
};


// !!! SEE THE CLASS DECLARATION ABOVE !!! //


// You can toggle these booleans to enable only some checks
// This can be useful if some of them do not compile
constexpr bool check_001_enabled = true;
constexpr bool check_002_enabled = false;
constexpr bool check_003_enabled = false;
constexpr bool check_004_enabled = false;
constexpr bool check_005_enabled = false;
constexpr bool check_006_enabled = false;
constexpr bool check_007_enabled = false;
constexpr bool check_008_enabled = false;
constexpr bool check_009_enabled = false;

// If you want to debug your code, you can write code in this function.
// It will be executed before running the checks.
// Don't forget to remove any output from this function when you're done.
inline void user_defined_code()
{
}

// Implement the accumulator class here

// !!! SEE CHECKS IMPLEMENTATION BELOW !!! //


template <typename T>
struct strong
{
    T value;
};

class latch
{
public:
    explicit latch(int count) : count_(count)
    {
    }

    void arrive_and_wait()
    {
        std::unique_lock lock(mutex_);
        count_--;
        cv_.notify_all();
        cv_.wait(lock, [this] { return count_ == 0; });
    }

private:
    int count_{};
    std::mutex mutex_;
    std::condition_variable cv_;
};

template <typename T>
struct move_only_plus : std::plus<T>
{
    using std::plus<T>::plus;
    move_only_plus(move_only_plus const&) = delete;
    move_only_plus& operator=(move_only_plus const&) = delete;
    move_only_plus(move_only_plus&&) = default;
    move_only_plus& operator=(move_only_plus&&) = default;
    using std::plus<T>::operator();
};


// basic usage
bool check_001()
{
    if constexpr (check_001_enabled)
    {
        auto acc = accumulator(10, std::plus<int>());
        acc.push(1);
        acc.push(2);
        acc.push(3);
        return acc.finalize() == 16;
    }
    else
    {
        return false;
    }
}

// eager evaluation
bool check_002()
{
    if constexpr (check_002_enabled)
    {
        auto invoked = 0;
        auto acc = accumulator(10, [&](auto lhs, auto rhs) {
            ++invoked;
            return lhs + rhs;
            });

        acc.push(1);
        if (invoked != 1)
            return false;

        acc.push(2);
        if (invoked != 2)
            return false;

        acc.push(3);
        if (invoked != 3)
            return false;

        return acc.finalize() == 16;
    }
    else
    {
        return false;
    }
}

// T is move-only
bool check_003()
{
    if constexpr (check_003_enabled)
    {
        auto acc = accumulator(std::make_unique<int>(10), [](auto lhs, auto rhs) { return std::make_unique<int>(*lhs + *rhs); });
        acc.push(std::make_unique<int>(1));
        acc.push(std::make_unique<int>(2));
        acc.push(std::make_unique<int>(3));
        return *acc.finalize() == 16;
    }
    else
    {
        return false;
    }
}

// Op is move-only
bool check_004()
{
    if constexpr (check_004_enabled)
    {
        auto acc = accumulator(10, move_only_plus<int>());
        acc.push(1);
        acc.push(2);
        acc.push(3);
        return acc.finalize() == 16;
    }
    else
    {
        return false;
    }
}

// stateful Op
bool check_005()
{
    if constexpr (check_005_enabled)
    {
        constexpr double eps = 1e-6;
        auto acc = accumulator(0.0, [count = 0, sum = 0.0](auto _, auto rhs) mutable {
            sum += rhs;
            count++;
            return sum / count;
            });

        acc.push(0);
        acc.push(2);
        acc.push(4);
        acc.push(4);
        return std::abs(acc.finalize() - 2.5) < eps;
    }
    else
    {
        return false;
    }
}

// thread safety
bool check_006()
{
    if constexpr (check_006_enabled)
    {
        constexpr auto nthread = 10;
        constexpr auto op_per_thread = 100000;
        latch latch(nthread);
        std::vector<std::future<void>> futures;

        auto acc = accumulator(0, std::plus<int>());
        for (auto i = 0; i < nthread; ++i)
        {
            futures.push_back(std::async(std::launch::async, [&] {
                latch.arrive_and_wait();
                for (auto j = 0; j < op_per_thread; ++j)
                {
                    acc.push(1);
                }
                }));
        }
        futures.clear();

        return acc.finalize() == op_per_thread * nthread;
    }
    else
    {
        return false;
    }
}

// generic_push
bool check_007()
{
    if constexpr (check_007_enabled)
    {
        auto acc = accumulator(10, [](auto lhs, auto rhs) { return lhs + rhs.value; });
        acc.generic_push(strong<int>{1});
        acc.generic_push(strong<int>{2});
        acc.generic_push(strong<int>{3});
        return acc.finalize() == 16;
    }
    else
    {
        return false;
    }
}

// generic_push with move-only U
bool check_008()
{
    if constexpr (check_008_enabled)
    {
        auto acc = accumulator(10, [](auto lhs, auto rhs) { return lhs + *rhs; });
        acc.generic_push(std::make_unique<int>(1));
        acc.generic_push(std::make_unique<int>(2));
        acc.generic_push(std::make_unique<int>(3));
        return acc.finalize() == 16;
    }
    else
    {
        return false;
    }
}

// generic_push does not steal ownership
bool check_009()
{
    if constexpr (check_009_enabled)
    {
        auto acc = accumulator(10, [](auto lhs, auto rhs) { return lhs + *rhs; });

        auto v1 = std::make_shared<int>(1);
        auto v2 = std::make_shared<int>(2);
        auto v3 = std::make_shared<int>(3);

        acc.generic_push(v1);
        acc.generic_push(v2);
        acc.generic_push(v3);

        return acc.finalize() == 16 && v1 && v2 && v3;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::unordered_map<std::string, std::function<bool()>> checks = {
        {"check_001", [] { return check_001(); }},
        {"check_002", [] { return check_002(); }},
        {"check_003", [] { return check_003(); }},
        {"check_004", [] { return check_004(); }},
        {"check_005", [] { return check_005(); }},
        {"check_006", [] { return check_006(); }},
        {"check_007", [] { return check_007(); }},
        {"check_008", [] { return check_008(); }},
        {"check_009", [] { return check_009(); }},
    };

    user_defined_code();

    std::string check;
    std::cin >> check;
    auto success = checks.at(check)();
    std::cout << check << " - " << (success ? "OK" : "KO") << std::endl;

    return 0;
}
