## Project Idea : Continuous Respiration Monitor for Anxiety and Email Apnea Detection

### Motivation
Anxiety disorder results in mild to severe adverse behavioral effects in 31.1% of US adults at some point in their life [2]. Email apnea (also known as screen apnea) is a series of anxiety-producing, intermittent apneic events triggered by stress while conducting computer work and is plaguing up to 80% of office workers’ growing population [3]. While respiration monitoring can be inferred from other wearables, some are uncomfortable to wear for an extended time, and others are currently priced out of consumers’ budgets. This vision for a wearable respiration monitoring system takes the form of a pair of glasses equipped with an integrated MEMS microphone placed near the glasses’ bridge. This form factor can detect various disorders such as chronic anxiety and email apnea.

Novel microphone prototype analysis was conducted through the Teensyduino Serial Plotter and with software written to map the microphone readings’ amplitudes to a normalized and digital range of 0 to 10 for easier comprehension. By varying microphone placements on different parts of the face, it was possible to determine how reliably inhalations and exhalations would be detected quickly. 

By tying together the microphone, Android Phone and Watch apps microphone measurements would indicate when the wearer had an apneic event then trigger the watch to vibrate to alert the wearer that they needed to take a breath. 

### Results 
The initial prototype was built with a Teensy 4.1 and a MEMS Microphone Breakout. The microphone placement was decided based on the sensor’s ability to pick up breathing signals without background noise and was placed below the bridge of the glasses. Attempts were made to collect respiration recordings with the sensor placed on the wrist, but this created more opportunities to pick up background noise and produce false readings. With the sensor placed at the bridge of the glasses, we could pick up respiration sounds more optimally. The current implementation cannot recognize exhalation sounds but instead recognizes inhalations, which appear as sharp spikes in our plots.

<img src= "https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/serial_plot.png" height="250" width="250">

To begin detecting email apnea, we look at 5-second intervals of microphone readings and parse through the signals to look for signals indicative of inhalation, which typically lay in the frequency range of 60-600 Hz but can extend to 1 kHz. With our MEMS microphone readings ranging from 0-800 mV linearly mapping to the frequency response of up to 10 kHz, we disregard measurements related to readings above 1 kHz to create a digital lowpass filter. We then look for the maximum peak amplitude of our signal in our 5 second time interval and map that signal amplitude to a range of 0 to 10 for normalization, simplifying the receipt of this resultant reading in our Android application. We found that values of 2 or higher indicated an inhalation was detected, meaning our wearer was breathing normally. The Android app triggers the smartwatch to vibrate if it does not detect a value of 2 or higher for 15 seconds since that would indicate that the wearer had not taken a breath in that timeframe. 

### Power Requirement Estimations
When designing ubiquitous computing wearable devices, power consumption plays a crucial role in ensuring that the device can function long enough to justify its adoption by consumers. Using Google Glass Enterprise Edition 2 as a point of reference with its 800 mAh battery [1] and referencing the given power draw of the Teensy 4.1, 100 mAh [4], as given by PJRC, the manufacturer of the Teensy 4.1, we can estimate that our prototype could reasonably function for 8 hours of sustained respiration monitoring. When factoring in the current draw of the HC-05 (100 mAh) and the MEMS microphone (250Ah) we get an estimated 5.7 hours of continuous operation assuming each subsystem operates at its maximum power draw. 

## Rough Form
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/glasses_views.png)

![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/glasses_mockup.jpeg)


## Requisite Parts
The major components for the prototype thus far include:
* a Teensy 4.1 Microcontroller which is compatible and programmable through 'Teensyduino' -- for collecting samples.  
* a Sparkfun MEMS Microphone Breakout Board -- for breath detection
* an Integrated Bluetooth Module -- for interfacing with our phone. 
* Power supply -- for supplying power. 

Also needed for the project are a smartwatch and smartphone. 

## Interaction Plan
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/cbm_to_phone_to_watch.png)


We expect wearers to treat the glasses and wear them as they normally would. They would need to download the phone and watch app ahead of time and then pair the glasses to the phone. We will be including a button for powering the device on/off and to enable pairing mode. The glasses themselves will continuously track breathing through the MEMS microphone which is set to a low gain and will utilize filters to eliminate frequencies not expected in normal, shallow, or rapid breathing. 

## Demo Video
[![](http://img.youtube.com/vi/DEPCkV66I98/0.jpg)](http://www.youtube.com/watch?v=DEPCkV66I98 "Continuous Breathing Monitoring")




## [Wiring Diagram](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/wiring_guide.md)
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/mems_breadboard.jpg)

## Dimensions
* MEMS:  14.50 x 10.75 x 2.60 mm
* HC-05: 37.75 x 16.45 x 4.10 mm
* Teensy: 234 x 185.85 x 12.6 (or 3.3 w/o headers) mm

## References

[1] Glass Enterprise Edition 2 Tech Specs. Retrieved December 10, 2020, from https://www.google.com/glass/tech-specs/ .


[2] NIMH » Any Anxiety Disorder. Retrieved September 16, 2020 from https://www.nimh.nih.gov/health/statistics/any-anxiety-disorder.shtml

[3] Pollak S, M. Email Apnea. 2014. Retrieved December 10, 2020, from https://www.psychologytoday.com/us/blog/the-art-now/201411/email-apnea.


[4] Tauhidur Rahman, Alexander T. Adams, Mi Zhang, Erin Cherry, Bobby Zhou, Huaishu Peng, and Tanzeem Choudhury. 2014. BodyBeat: a mobile system for sensing non-speech body sounds. In Proceedings of the 12th annual international conference on Mobile systems, applications, and services - MobiSys ’14, ACM Press, Bretton Woods, New Hampshire, USA, 2–13. DOI:https://doi.org/10.1145/2594368.2594386

[5] Teensy 4.0 development board. Retrieved December 10, 2020, from https://www.pjrc.com/store/teensy40.html. 
