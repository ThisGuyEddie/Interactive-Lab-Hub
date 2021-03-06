## Overview
For this assignment, you are going to 

A) [Actuating DC Motors](#part-a-actuating-dc-motors) 

B) [Actuating Servo Motors](#part-b-actuating-servo-motors) 

C) [Integrating Input and Output](#part-c-integrating-input-and-output)

D) [Autonomy!](#part-d-autonomy)

E) [Paper Display](#part-e-paper-display) 

F) [Make it your own](#part-f-make-it-your-own)


## Part A. Actuating DC motors


Your kit has a vibration motor. Vibration motors are actually DC motors that have an asymmetrical weight on the main rotor, which causes the device to shake when power is applied and the motor rotates. 

![image of vibration motor](https://cdn-shop.adafruit.com/145x109/1201-01.jpg)

Use the [Fade](https://www.arduino.cc/en/tutorial/fade) circuit from Lab 01 (```Examples > 01 Basics > Fade```) and connect the vibration motor's red wire to the pin which normally would be supplying a LED with PWM'd voltage. (Remember PWM from Lab 1, Part E? [Pulse width modulation](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Lab-01#part-e-fade-a-led-using-arduino) )  The other blue wire from the vibration motor should be connected to ground, to complete the circuit. SECURE THE MOTOR TO KEEP IT FROM SHAKING ITSELF OUT OF THE CIRCUIT!

## Part B. Actuating Servo motors
![Image of servo motor](https://cdn-shop.adafruit.com/145x109/169-06.jpg)

A servo is a DC motor, geartrain, potentiometer and feedback circuit, all in a single housing.

By sending a PWM signal from your Arduino to the servo, you’re telling it what angular position you’d like it go to.

The potentiometer tells the feedback circuit the servo’s current position, and the circuit drives the motor to match the desired position.

### Part 1. Connect the Servo to your breadboard

Servo motors generally have 3 wires; power, ground and signal. [Here](https://www.adafruit.com/product/169) is the product page for the servos in your kit. 

**a. Which color wires correspond to power, ground and signal?**

Connect the servo to your breadboard, supplying power and ground to the appropriate pins. 

### Part 2. Connect the Servo to your Arduino

Now open the [Sweep](https://www.arduino.cc/en/Tutorial/Sweep) sketch in the Arduino IDE. 

```File > Examples > Servo > Sweep```

**a. Which Arduino pin should the signal line of the servo be attached to?**
Upload the sketch to the Arduino. Your servo should start sweeping back and forth, by about 180 degrees.

Change some parameters in the sketch to make the servo sweep slower, or over a smaller angle.

Brown - GND
Red - +5V
Orange - Pin 9

**b. What aspects of the Servo code control angle or speed?**
"pos +- & -=" for speed
"pos" in the for loops for setting angles


## Part C. Integrating input and output

Using what you've learned already, write code to control the servo motor circuit, either:
* adjusting the servo motor rotation to reflect the reading on a potentiometer voltage divider circuit, (Yes, it is fine to use any other analog voltage sensor!), or, 
* reflecting pre-programmed actions you design. 

## Part D. Autonomy!

Remove the USB cable

Use the 9V battery and pigtail to power the Arduino using the Vin and Ground line.

**Include a photo/movie of your autonomous device in action.**

## Part E. Paper display

Here is an Arduino breadboard with a paper faceplate on it to turn it into a display:

![]()

This is fine, but it can be a bit difficult to lay out a great and user friendly display within the constraints of the breadboard. Also, it really only works for applications where people can come and stand over the breadboard, or where you can mount the board to the wall.

Here is another prototype for a paper display:

![]()

It holds a breadboard and 9v battery, and provides a front stage on which to put writing, graphics, LEDs, buttons or displays.

This design can be made by scoring a long strip of corrugated cardboard of width X, with the following measurements:

| Y height of box <br> <sub><sup>- thickness of cardboard</sup></sub> | Z  depth of box <br><sub><sup>- thickness of cardboard</sup></sub> | Y height of box  | Z  depth of box | H height of faceplate |
| --- | --- | --- | --- | --- | 

Fold the first flap of the strip so that it sits flush against the back of the face plate, and tape, velcro or hot glue it in place. This will make a H x X interface, with a box of Z x X footprint (which you can adapt to the things you want to put in the box) and a height Y in the back. 

Make a paper display that uses the servo to show how many times a button on the front has been pressed (or any other thing you can sense or count). Ideally you should design it so that you can slide the breadboard out to work on the circuit or programming, and then slide it back in and reattach a few wires to be back in operation.


**a. Make a video of your paper display in action.**

## Part F. Make it your own

Now modify this set up to make this your own design. 

Use paper to build a paper template. Use an Olfa knifes to cut out your pattern, and glue or tape to put it together. <!--If you'd like to use the paper cutter, [here's how](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/How-to-use-the-Silhouette-Cameo-Cutter).-->

You can create a game, you can enact a pre-programmed mini puppet show, or you can visualize data in a new way.

<!--If your design involves having someone controlling the puppet in real time (e.g. using sensors), please film that happening. Otherwise, film the puppet performing it's moves. -->

**a. Make a video of your final design in action.**
