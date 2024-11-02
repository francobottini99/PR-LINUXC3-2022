# C Language Practices in GNU/Linux

This repository addresses memory mapping in the context of a C program executed on GNU/Linux. The primary goal is to access data in a binary file called `datos`, sourced from the RMA1 weather radar in Ciudad Universitaria (UNC). The program is expected to perform memory mapping, cast the data according to a provided structure, and solve several incremental activities.

### Authors:
- **Bottini, Franco Nicolas**

## Project Structure

The project is organized as follows:

- **inc/Lab6.h:** Header file containing the RMA1 data structure and function declarations.
- **src/Lab6.c:** Source file implementing functions for loading the file and obtaining samples.
- **main.c:** Main program that uses the functions implemented in Lab6.c.
- **Makefile:** File for compiling and building the project.

## Compilation and Execution

To compile the project, use the following command:

```bash
make
```

This command generates the executable "lab6." Then, you can run the program with:

```bash
./lab6
```

## Program Operation

The program performs the following actions:

1. Loads the binary file "datos" using the `load_rawdata` function.
2. Obtains the samples through the `get_samples` function, which maps the file and returns an array of RMA1 structures.
3. Calculates the total number of samples and the average of the `validSamples` variable.
4. Prints the results to the console.

## Additional Questions

### 1. Why is memory mapping important in this context?

Memory mapping is crucial in this context because it allows direct access to data stored in the binary file without explicitly reading it. By mapping the file into memory, a correspondence is created between the program's memory and the file on disk. This facilitates the efficient handling of large data sets and improves performance by avoiding multiple file reads.

### 2. How is the used memory released?

Memory is freed at the end of the program. The samples obtained are released through the `free(samples)` function. Additionally, the `munmap` function is used to release the memory allocated for mapping the file.

## Conclusions

Using memory mapping provides an efficient way to access and manipulate data stored in files. The program structure facilitates code understanding and modification, and the modular organization improves maintainability. Compilation with specific flags and the absence of errors and warnings ensure code robustness.
