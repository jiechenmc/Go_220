package main

import (
	"fmt"
	"io"
	"log"
	"os/exec"
	"strings"
)

func sendInput(stdin io.WriteCloser, str string) {
	_, e := stdin.Write([]byte(str))
	if e != nil {
		log.Fatal(e)
	}
}

func main() {
	cmd := exec.Command("./a.out")
	stdin, e := cmd.StdinPipe()

	if e != nil {
		log.Fatal(e)
	}
	stdout, e := cmd.StdoutPipe()

	if e != nil {
		log.Fatal(e)
	}

	if e := cmd.Start(); e != nil {
		log.Fatal(e)
	}

	sendInput(stdin, "ADD\n")
	sendInput(stdin, "SHOW\n")
	sendInput(stdin, "ADD\n")
	sendInput(stdin, "SHOW\n")

	stdin.Close()

	out, _ := io.ReadAll(stdout)

	fmt.Println(strings.TrimRight(string(out), "\n"))
	fmt.Println(strings.TrimRight(string(out), "\n") == "hello\nworld")

	if e := cmd.Wait(); e != nil {
		log.Fatal(e)
	}
}
