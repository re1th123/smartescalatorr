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

In this project, we aim to develop a system that uses a tiva c This model will analyze motion captured by pip motion sensor and predict the . The result will be displayed on a 128x160 TFT LCD screen. The entire process, and buzzer when motion detected [YouTube link](https://youtube.com/shorts/-CA0Vzc14fw?feature=shared))

## Project Inspiration

This project drew inspiration from  While the core idea remains similar,[Smaart escaltor using Tiva c} several necessary changes and enhancements have been made to adapt it to our specific requirements and goals.

## Required Hardware

1. *TIVA C**: This project is designed for the TIva, but it may work on other boards that support CircuitPython with some modifications. Ensure your board has sufficient GPIO pins, as almost 80% of the Pi Pico's GPIOs are used.This is the main microcontroller responsible for running the program. It's part of the Tiva C series from Texas Instruments.

2. **128x160 TFT LCD**: You'll need a compatible LCD display. Other displays may work with code adjustments,The code is written to interface with a 4-bit LCD display. The LCD display is connected to the GPIO pins of the Tiva C microcontroller. The connections are defined in the code.

LCD Pins:
RS (Register Select): Connected to PB0 (GPIOB Pin 0)
RW (Read/Write): Connected to PB1 (GPIOB Pin 1)
EN (Enable): Connected to PB2 (GPIOB Pin 2)

3. **PIP motion sensor**: for sensing the motion

4. **HC-05 Bluetooth Module**:This module is used for wireless communication. It appears that the UART5 module of the TM4C123 is configured to communicate with this Bluetooth module. The HC-05 typically has TX and RX pins for serial communication.
5. **Jumper Cables**: You'll need male-to-female (M-F) and male-to-male (M-M) jumper cables for making various connections.



3. **Patience**: Building and fine-tuning this system may require some patience.

The project aims to display the classification results on the 128x160 TFT LCD, making it a practical and interactive solution. It leverages CircuitPython for its versatility, ensuring compatibility with various boards supporting CircuitPython.

## Installation and Setup

1. **Install keil **: Start by installing  keil 

2. **Download Necessary Library Files**: Visit the microcontroller website to download the necessary library files
3. **Copy Code Files**: Copy and paste the following files into your board:
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

| Display Pin Number | Display Pin Name | TIVA  Pins |
|-------------------|------------------|--------------|
| 2                 | VCC              | 5V (VBUS)        |
| 1                 | GND              | GND          |
| 10                | d4            | GPIOB4        |
| 10                | d5           | GPIOB5       |

### OV7670 Module Connections




## Wrapping It Up

the project successfully demonstrates the integration of a Tiva C series microcontroller (TM4C123GH6PM), an HC-05 Bluetooth module, and a 4-bit LCD display to create a motion detection system. The system is designed to detect motion using a push button connected to GPIOC Pin 4 and communicate wirelessly through Bluetooth. The status of the system is indicated by LEDs (PF1, PF2, PF3), and the detected or undetected motion is displayed on the LCD screen.
