![PROJECT](project.jpg)
# Table of Contents

  -   [Smaart escaltor using Tiva c}
  - [Project Overview](#project-overview)
  - [Project Inspiration](#project-inspiration)
  - [Required Hardware](#required-hardware)
  - [Required Software](#required-software)
  - [Installation and Setup](#installation-and-setup)
  - [Running and Debugging](#running-and-debugging)
  - [Tiva c](#Raspberry-Pi-Pico-Pin-Diagram)
  - [Wiring](#wiring)

# Creating a smart escalator using tiva  c

## Project Overview

In this project, we aim to develop a system that uses a tiva c This model will analyze motion captured by pip motion sensor and predict the . The result will be displayed on a 128x160 TFT LCD screen. The entire process, and buzzer when motion detected andstepperr motor start running
[YouTube link](https://youtube.com/shorts/-CA0Vzc14fw?feature=shared))

## Project Inspiration

This project drew inspiration from  While the core idea remains similar,[Smaart escaltor using Tiva c} several necessary changes and enhancements have been made to adapt it to our specific requirements and goals.

## Required Hardware

1. **keil **: This project is designed for the TIva, but it may work on other boards that support c proogram with some modifications. Ensure your board has sufficient GPIO pins, as almost 80% of the tiva c GPIOs are used.This is the main microcontroller responsible for running the program. It's part of the Tiva C series from Texas Instruments.

2. **128x160 TFT LCD**: You'll need a compatible LCD display. Other displays may work with code adjustments,The code is written to interface with a 4-bit LCD display. The LCD display is connected to the GPIOB pins of the Tiva C microcontroller. The connections are defined in the code.

LCD Pins:
RS (Register Select): Connected to PB0 (GPIOB Pin 0) PB0
RW (Read/Write): Connected to PB1 (GPIOB Pin 1)PB1
EN (Enable): Connected to PB2 (GPIOB Pin 2)PB2

3. **PIP motion sensor**: for sensing the motion (PC4)

4. **HC-05 Bluetooth Module**:This module is used for wireless communication. It appears that the UART5 module of the TM4C123 is configured to communicate with this Bluetooth module. The HC-05 typically has TX and RX pins for serial communication.
5. **Jumper Cables**: You'll need male-to-female (M-F) and male-to-male (M-M) jumper cables for making various connections.

6. **buzzer**: when the motion detected buzzer starts  (PA2)
7.  **stepper motor**: when the motion detected   (PA2)
                        actually the motor starts insteds of we used the led for the output signal use pa2 as the input signal
![image](https://github.com/re1th123/smartescalatorr/assets/153987405/bd959793-069a-438e-a9f5-0a0b2a930833)

if any doubts refer to the link from the microcontoller lab  [chrome link](https://microcontrollerslab.com/stepper-motor-interfacing-with-tm4c123-tiva-launchpad-keil/)


3. **Patience**: Building and fine-tuning this system may require some patience.

The project aims to display the classification results on the 128x160 TFT LCD, making it a practical and interactive solution. It leverages CircuitPython for its versatility, ensuring compatibility with various boards supporting CircuitPython.

## Installation and Setup

1. **Install keil **: Start by installing  keil 

2. **Download Necessary Library Files**: Visit the microcontroller website to download the necessary library files
3. **Copy Code Files**: load files into your board:
   - `program.c`
   


This step ensures that you have all the required files in place for running your project successfully.



## Running and Debugging

To run and debug your code, follow these steps:

1. Use an Integrated Development Environment (IDE), preferably keil ide


3. Refer to the connection details provided below for proper setup and debugging.





## tivapin diagram
![image](https://github.com/re1th123/smartescalatorr/assets/153987405/d78bdacf-b141-4d17-abbd-da5d8b01d21e)
![image](https://github.com/re1th123/smartescalatorr/assets/153987405/9351c8a0-cb35-43cf-a5b0-8fe7cb186b9c)

![image](https://github.com/re1th123/smartescalatorr/assets/153987405/9087b586-2241-4a44-883f-a9a918179e17)
![image](https://github.com/re1th123/smartescalatorr/assets/153987405/46c346a7-1602-431b-9dc6-4df3e5123a4e)







## Wiring

For this project, a substantial amount of wiring is required. It is highly recommended to use model and jumper cables for a clean and organized setup.

### LCD Connections

| Display Pin Name | TIVA  Pins |
|------------------|--------------|
| VCC              | 5V (VBUS)        |
| GND              | GND          |
| RS             | PB0         |
| RW              |PB 1         |
| EN           |PB 2         |
| d4            | PB4        |
| d5           | PB5       |
| d6           | PB6       |
| d7           | PB7       |


### LED Connections(Stepper motor)

| Display Pin Name | TIVA  Pins |
|------------------|--------------|
| VCC              | 5V (VBUS)        |
| GND              | GND          |
| out            | PA 2      |

### PIP motion sensor Connections(Stepper motor)

| Display Pin Name | TIVA  Pins |
|------------------|--------------|
| VCC              | 5V (VBUS)        |
| GND              | GND          |
| out            | PC4     |


### buzzer Connections(Stepper motor)

| Display Pin Name | TIVA  Pins |
|------------------|--------------|
| VCC              | 5V (VBUS)        |
| GND              | GND          |
| out            | PA 2      |

### HC-05 bluetooth module Connections(Stepper motor)

| Display Pin Name | TIVA  Pins |
|------------------|--------------|
| VCC              | 5V (VBUS)        |
| GND              | GND          |
| RX            | PE4      |
| TX            | PE5      |


## Wrapping It Up

the project successfully demonstrates the integration of a Tiva C series microcontroller (TM4C123GH6PM), an HC-05 Bluetooth module, and a 4-bit LCD display to create a motion detection system. The system is designed to detect motion using a push button connected to GPIOC Pin 4 and communicate wirelessly through Bluetooth. The status of the system is indicated by LEDs (PF1, PF2, PF3), and the detected or undetected motion is displayed on the LCD screen.
