package main

import (
	"log"
	"os/exec"
)

func main() {
	cmd := exec.Command("./a.out")
	cmd.StdinPipe()
	cmd.StdoutPipe()
	err := cmd.Run()

	if err != nil {
		log.Fatal(err)
	}
}
