Ring Counter implementation using AVR DA 
========================================

Introduction
============

This example demonstrates  3-bit ring counter implementation  using all 6 Look-Up-tables (LUTs) available with the CCL peripheral of AVR128DA48 MCU. It also illustrates how to do the cascaded connections of the D-Flipflops.
Note: This example could be generated with 48 and 64 pin AVR DA devices.


Basics of Ring Counter
======================
The ring counter is a type of counter composed of flipflops connected into a shift register, with the output of the last flipflop fed to the input of the first flipflop, making a circular or ring in structure. It is a synchronous counter which has a common clock signal that triggers all the flipflops at the same time. It is initialized such that only one of the flipflop output is 1 while the remainder is 0. Number of states of Ring counter is equal to number of flipflops used. To design three-bit ring counter, three flipflops are required. 

The sequence of output from the three-bit ring counter are:  100,     010 ,    001 ,    100 ,    010 ,    001 


Demo Description
================

*	To realize 3-bit Ring Counter, 3 D flip-flops are required. The AVR128DA48 Curiosity Nano board from Microchip is used to realize the 3-bit Ring Counter.
*	The 3 D flip-flops are cascaded in such a way that output of D flip-flop 0 is fed to the input of D flip-flop 1, D flip-flop 1 output is fed to the D flip-flop 2 input and, D flip-flop 2 output is fed to the D flip-flop 0 input through Event system.
*	The on-board mechanical switch (SW0) is used as a trigger for the Timer B to generate a single pulse, which is used as a clock signal to all the three flipflops.
*	For each switch press event, data gets shifted from output of the D flip-flip 0 to the D flip-flop 1 input, D flip-flop 1 output to the D flip-flop 2 input and, D flip-flop 2 output to the D flip-flop 0 input.
*	The on-board indication LED blinks, whenever a switch (SW0) press event is reported.
*	The 3-bit ring counter data gets transferred to the terminal window of  data visualizer tool through mEDBG of the AVR128DA48 Curiosity Nano board.

Video of the demo is available here: https://www.youtube.com/watch?v=BYyyZrUc0Wo.

For more details about the example and configuration details in Studio IDE, refer the example posted on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-3bit-ring-counter-start-example.git

This example is also generated using MPLAB X IDE and is available on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-3bit-ring-counter-mcc-example.git


Supported evaluation kit
========================

*   `AVR128DA48 Curiosity Nano Evaluation Kit <https://www.microchip.com/developmenttools/ProductDetails/DM164151>`_

Demo Operation
==============
*	After the Curiosity Nano board is powered on, load the firmware to AVR128DA48 MCU.
*	To observe data, open terminal window by connecting to serial port control panel and click on connect button.
*	Before each switch press, read the instructions provided on the terminal window. E.g. Press switch- To display first state of the Ring Counter.
*	First state of the ring counter i.e. First state=1 0 0 is displayed by default on the terminal window, only once at the start of the functionality, without a switch press event.
*	After each switch press event, user needs to wait for the next instruction to be displayed on the terminal window. 
*	Press Switch (SW0) to display the second state of ring counter and observe the text Second state = 0 1 0 is displayed on  the terminal window.
*	Press Switch (SW0) to display the third state of ring counter and observe the text Third state = 0 0 1 is displayed on the terminal window.
*	Again, the first instruction to the user is displayed on the terminal window and the sequence of operation, i.e. first state of the ring counter, continues.


Running the demo
================

*  Select  "EXPORT PROJECT" tab and click "Download Pack" to save the .atzip file.
*  Import .atzip file into Atmel Studio 7, File->Import->Atmel Start Project.
*  Build Solution and make sure no compiler errors occur.
*  Press "Start without debugging" or use "CTRL+ALT+F5" hotkeys to run the application.


