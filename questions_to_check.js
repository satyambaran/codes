let obj = [
    "https://www.youtube.com/watch?v=jgQjes7MgTM",



     
    "questions folder",
    "abbbbbbccccccda, remove all the occurences of bc, use stack method",
    "https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/510182271/",
    "https://leetcode.com/problems/longest-palindromic-substring/submissions/740439346/",
    "https://leetcode.com/problems/3sum/submissions/740444035/",
    "https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/740455761/", //kmp algorithm
    "https://leetcode.com/problems/longest-valid-parentheses",
    "https://leetcode.com/problems/sudoku-solver", // backtrack
    "https://leetcode.com/problems/combination-sum-ii/submissions/741639722/",
    "https://leetcode.com/problems/maximum-subarray/submissions/742064253/",
    "https://leetcode.com/problems/jump-game-ii/submissions/887630259/",

    //?string questions
    // string.replace(pos, len, str);
    //size_t k=bigstr.find(str), k==string::npos
    "https://leetcode.com/problems/find-common-characters/submissions/635828266/",
    "https://leetcode.com/problems/construct-string-from-binary-tree/submissions/748846255/",//!string+tree
    "https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/",
    "https://leetcode.com/problems/binary-tree-paths/submissions/", //! let loose all dfs case and store
    "https://leetcode.com/problems/rotate-string/submissions/741102428/", //! merge string and find the string between 0, 2n-2 https://leetcode.com/problems/repeated-substring-pattern/description/
    "https://leetcode.com/problems/remove-all-occurrences-of-a-substring/",
    "https://leetcode.com/problems/palindromic-substrings/",
    "https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/",
    "https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/",
    "https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/",
    "https://leetcode.com/problems/longest-palindromic-subsequence/submissions/725186242/",
    "https://leetcode.com/problems/longest-string-chain/submissions/742326594/",
    "https://leetcode.com/problems/longest-common-subsequence/submissions/720620054/",
    "https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/515740380/",
    "https://leetcode.com/problems/vowels-of-all-substrings/submissions/725417738/",//! total possible substrings using ith char = (i-0+1)*(n-1-i+1)
    "https://leetcode.com/problems/destination-city/submissions/893476174/",
    "https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/submissions/725337960/",
    "https://leetcode.com/problems/number-of-ways-to-select-buildings/submissions/725430129/",
    "https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/551625518/",
    "https://leetcode.com/problems/smallest-string-starting-from-leaf/submissions/631139660/",
    "https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions",
    "https://leetcode.com/problems/restore-ip-addresses/submissions/414532333/",
    "https://leetcode.com/problems/word-break/submissions/551639526/",
    "https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/submissions/742085465/",
    "https://leetcode.com/problems/longest-palindromic-substring/submissions/740439346/",
    "https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/510182271/",//! two pointer
    "https://leetcode.com/problems/interleaving-string/submissions/510555426/",//!imp
    "https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/740455761/",//! kmp
    "https://leetcode.com/problems/shortest-common-supersequence/submissions/725441958/",//! very very imp
    "https://leetcode.com/problems/word-ladder/submissions/554002228/", //! fixed length queue process, to get to next step


    // priority_queue<int>pq;4, 3, 1, -2
    // priority_queue<int, vector<int>, greater<int>> pq2; -2, 1, 3, 4 


    //?binary search
    //lower_bound := first element which has a value not less than val
    //upper_bound := first element which has a value greater than val
    /*//?
        while (l <= r) {
            mid = l + (r - l) / 2; 
            if (grid[i][mid] < 0) {
                r = mid - 1; ans = mid;
            }
            else {
                l = mid + 1;
            }
        } 
    */
    "https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/789849857/",
    "https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/789874463/",
    "https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/789882721/",
    "https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/submissions/788907798/",
    "https://leetcode.com/problems/longest-increasing-subsequence/submissions/787935818/",
    "https://leetcode.com/problems/russian-doll-envelopes/submissions/644809838/",



    //tree
    "https://leetcode.com/problems/invert-binary-tree/submissions/725480243/",
    "https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/894146690/",
    "https://leetcode.com/problems/diameter-of-binary-tree/submissions/894151232/",
    "https://leetcode.com/problems/balanced-binary-tree/submissions/637920669/", //! balanced binary tree means none of the node with left and right depth diff > 1
    "https://leetcode.com/problems/validate-binary-search-tree/submissions/755417043/",
    "https://leetcode.com/problems/longest-univalue-path/submissions/747201640/",
    "https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/submissions/427709679/",
    "https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/740268232/", //! very imp
    "https://leetcode.com/problems/binary-tree-right-side-view/submissions/417061945/",
    "https://leetcode.com/problems/add-one-row-to-tree/submissions/427713066/",
    "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/843715601/", //! imp
    "https://leetcode.com/problems/house-robber-iii/submissions/529176938/",
    "https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/submissions/750529036/",
    "https://leetcode.com/problems/recover-binary-search-tree/submissions/742379443/",
    "https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/submissions/427710013/",//!imp
    "https://leetcode.com/problems/distribute-coins-in-binary-tree/submissions/636467647/", //!very imp



    //graph

    "https://cses.fi/problemset/result/4307529/", //!bellman ford, loop through n times both of the time
    //? c should be stored -ve of what we recieved, as it tries to minimise the score
    /*
        if (ans[a] == INF) continue;
        ans[b] = min(ans[b], c + ans[a]);
    */
    /**
        if (ans[a] == INF) continue;
        if (ans[b] > c + ans[a]) {
                ans[b] = NINF;
        } 
    */
    "https://leetcode.com/problems/get-the-maximum-score/submissions/896173308/",



    // vector < int > v, u = { 1, 2, 3};
    // v=u; works
    // v={u.begin(), u.end()}; works// after either of two above, v==u true;
    
]

//option is equivalent to command + D
// to move line up and down option+arrow 
// command + L to highlight the line 