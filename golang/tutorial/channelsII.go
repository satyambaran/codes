package main

import (
	"fmt"
	"time"
)

const (
	logInfo    = "INFO"
	logWarning = "WARNING"
	logError   = "ERROR"
)

type logStruct struct {
	time    time.Time
	status  string
	message string
}

var logCh = make(chan logStruct, 50)

var doneCh = make(chan struct{}) //struct with no fields, it requires zero memory allocation. this makes it signal only channel, there's zero memmory allocation but still receiving side will know that a message was sent

func main() {
	go logger()
	logCh <- logStruct{time.Now(), logInfo, "Starting"}
	time.Sleep(2000 * time.Millisecond)
	logCh <- logStruct{time.Now(), logInfo, "Ending"}
	time.Sleep(1000 * time.Millisecond)
	doneCh <- struct{}{} //first  curly braces for type sugnature second is for initialization
}
func logger() {
	for {
		select { //it'll block
		case entry := <-logCh:
			fmt.Println(entry.time.Format("2006-01-02 15:04:05"), entry.status, entry.message)
		case <-doneCh:
			break
		}
	}
}
