# 8085 Emulator

**Author:** Bhavya Aggarwal  
**CST SPL | Graphic Era University (GEU) - Class of 2025**

## Overview

This project is a desktop application designed to emulate the functionality of the **8085 microprocessor**. It allows users to input 8085 assembly programs and view the results of their execution, with features to manage memory locations, registers, and flags.

## Features

This emulator provides the following key functionalities:

- **8085 Microprocessor Emulation**: 
  - Simulates the execution of 8085 assembly language programs.
  
- **Supported Instructions**:
  - **Arithmetic Commands**: `ADD`, `ADI`, `SUB`, `INR`, `DCR`, `INX`, `DCX`, `DAD`, `SUI`
  - **Logical Commands**: `CMA`, `CMP`
  - **Branching Commands**: `JMP`, `JC`, `JNC`, `JZ`, `JNZ`
  - **Load and Store Commands**: `MOV`, `MVI`, `LXI`, `LDA`, `STA`, `LHLD`, `SHLD`, `STAX`, `XCHG`
  - Two additional commands:
    - **SET**: To set values in specific memory locations.
    - **GET**: To retrieve values from specific memory locations.
  
- **Memory and Register Management**:
  - Input 8085 programs via a text file, where the first line specifies the starting memory address.
  - Set input values for particular memory locations.
  - View memory locations of stored instructions.
  - Display initial and final values of the Program Counter (PC).
  - View final values of all registers and flags in the output.

## Repository Contents

- **Source Code**: Implements the 8085 microprocessor emulator with the supported instructions.
- **CMD_instructions.txt**: Provides command-line instructions for compiling and running the emulator.
- **Sample Program File**: `sample_prg4.txt` contains a sample 8085 program for testing.
- **Executable File**: The compiled output file `a.exe` to run the emulator.

## How to Run

1. **Compilation**: Follow the instructions in `CMD_8085_instructions.txt` to compile the emulator.
2. **Input Program**: Place your 8085 program in a text file, where the first line specifies the starting memory address.
3. **Run the Emulator**: Execute `a.exe` and provide the program file as input.

## Example

Here’s an example workflow:

1. **Input File**: 
   - The input file `sample_prg4.txt` contains an 8085 assembly program.
   - The first line of the program is the starting memory address.
   
2. **Emulator Output**:
   - Displays the final state of the Program Counter (PC), registers, and flags.
   - Shows memory addresses of the instructions and user-specified memory values.

## Important Notes

- **Output File**: `a.exe`
- **Input File**: `sample_prg4.txt`
- Refer to the `CMD_8085_instructions.txt` file for detailed compilation and execution steps.

## Contributing

Contributions are welcome! If you encounter any issues or have ideas for improvements, feel free to open an issue or submit a pull request.

---

Thank you for checking out this project. I hope you find this emulator helpful!
