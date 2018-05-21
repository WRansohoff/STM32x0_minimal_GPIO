# Overview

This is a minimal project to demonstrate how to support multiple microcontroller cores in a single project, with minimal code changes. The project supports both Cortex-M0 'STM32F031K6' and Cortex-M0+ 'STM32L031K6' chips.

The example project initializes pin B1 as input with a built-in pull-up resistor; it listens for button presses on a button connected to ground. pin B3 is set to push-pull output, and it is connected to a built-in LED on ST's "Nucleo" board.

# Uploading and Debugging

A Makefile is provided, and I've tested the program with 'Nucleo-32' boards for both chips. To upload the resulting program, you can use your choice of uploader/debugger. I use GDB and Texane's "stlink" project:

https://github.com/texane/stlink

It's a fairly simple process to upload g a program:

1. Build the project with `make`

2. Plug your board in - for ST's Nucleo boards, you can just use an ordinary micro-USB cable.

3. Run `st-flash write main.bin 0x08000000` to write the compiled binary file to the start of the chip's Flash memory.
