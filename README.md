# Performance evaluation of a processor: Threads and Cores

## Project
***
The aim of the project is to analyze the execution time of three different kinds of functions in three different ways of execution.

### Functions:
- Summation of all elements (random numbers between -1 and 1) for a vector with 100 millions elements.
- Summation of all elements for the same vector size, but the elements are the result of the sin(x) function, where the x is each element of the first function vector.
- Summation of all elements for the same vector size, but the elements are the result of the log(x) function, where the x, as the second function vector, is each elemento of the first function vector.

### Execution ways:
- Run each function in one thread and only in one core.
- Run each function two times, one in a especific thread and the other in another thread, each one in different cores.
- Run each function two times, one in a especific thread and the other in another thread, each one on the same core.

## GNUPLOT
***
To see the values on a graphic, you can run the the .dat files using the GNUPLOT. To install the GNUPLOT you just need to open the Terminal and write "sudo apt-get install gnuplot-x11".

Now you can plot the values just put "gnuplot" on the terminal and follow these commands to plot your values <http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php>

## Program Execution
To execute the program on a Linux OS you must go to the folder, using the linux terminal, by "cd build-Processor_Management-Desktop_Qt_5_5_1_GCC_32bit-Debug", give the execution permission by "sudo chmod +x Processor_Management", remember that you need to inform your password, than execute the program by "sudo ./Processor_Management".

## Analysis
***
It was done just one test on a computer with an AMD processor with 1 socket, 2 cores and 2 threads per core. The following image is the graphic of our test:

![Graphic](build-Processor_Management-Desktop_Qt_5_5_1_GCC_32bit-Debug/Graphic.png?raw=true "Execution graphic")

## Conclusion
***

Analysing the graphics we saw that for the three ways of execution there is a bigger using of the processor when we run two functions on different threads, and more power if these threads are running on the same core. For the functions we can see that the function with log(x) elements spends more power than the function with sin(x) elements, as the function with sin(x) elements spends more power than the normal function.

## Developers
***

This work was developed by Jackson Rauup and Raul Silveira.

