// how does cpu works in programming languages?

// how go is better than other programming language, what's their limitations?


// Go compile down files to it's binary form


// dynamically-typed languages perform type checking at runtime, while statically typed languages perform type checking at compile time.
// statically-typed language is a language (such as Java, C, or C++) where variable types are known at compile time.


`
Go is a statically typed compile language used for  high performance server side applications.

Simplicity and efficiency

Go code can be compile down to machine(binary) code, so no need of interpreter language(python)


package main := makes a file standalone executable

func main(){   //?program will start executing here

}

go has various standard library of core packages

go build start.go   //? gives a binary executable file
./start             //? will run it


to get our depedendencies, we can connect to remote package on github with //todo go mod init package_name

if-else is also called control flow

concurrency (go routines):= a function can run simultaneously with another functions utilising multiple threads on a cpu


one core runs one instruction at a time
Parallel execution is needed to exploit multi-core systems and it must use multiple processor

Concurrent execution




identifiers := name of variables we declare
Keywords := represent some predefined actions


defer statements delay the execution of the function or method or an anonymous method until the nearby functions returns

UTF-8 is an encoding system for Unicode. It can translate any Unicode character to a matching unique binary string,  and can also translate the binary string back to a Unicode character.//? like 'a' = 97 = 01100001 = 'a'

Pointers is a variable that is used to store the memory address of another variable. //? The memory address is always found in hexadecimal format(starting with 0x like 0xc000076280)
`

