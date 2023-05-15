
func stream(ints *[]int) chan int {
    streamChan := make(chan int)
    go func(ints *[]int) {
        for _, val := range *ints {
            streamChan <- val
        }
        close(streamChan)
    }(ints)
    return streamChan
}

func consume(streamChan chan int) chan int {
    squaredChan := make(chan int)
    go func() {
        for cur := range streamChan {
            squaredChan <- (cur * cur)
        }
        close(squaredChan)
    }()
    return squaredChan
}

func print(squaredChan chan int, wg *sync.WaitGroup) {
    go func() {
        for cur := range squaredChan {
            fmt.Println(cur)
        }
        wg.Done()
    }()
}
