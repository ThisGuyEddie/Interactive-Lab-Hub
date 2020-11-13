## Tasks Done

* Parts ordered
* First Revision Breadboarded
* App built for Android Phone and Watch
* Bluetooth pairing works from Glasses to Phone.

## Tasks Left to Do 
* Package Raw Data for Android Phone
    Buffer every n seconds
    Get SD card and record data
    Add request data button into the app glasses would need to receive character from phone to switch modes
* Get EAGLE drawings done
* Send board out for manufacturing
* Assemble Board
* Flash Board
* Pray it works


## Project Idea 
Anxiety disorder results in mild to severe adverse behavioral effects in 31.1% of US adults at some point in their life. Researchers have linked anxiety to faster and shallower breathing. Respiration rate may thus be a good candidate for real-time anxiety monitoring and intervention. Various sensors like Bodybeat, Hexoskin, and a mask-based humidity sensor can measure breathing. However, some are uncomfortable to wear for an extended time, and others are currently priced out of consumers’ budgets. 

This vision for a wearable respiration monitoring system takes the form of a pair of glasses with an integrated MEMS microphone placed near the hinge or bridge of the glasses. It interacts sends bluetooth data back to a phone that is running an app to detect heartrate variability (HRV). If it's determined that the HRV indicates anxiety, we will send signals from the phone to a watch that will haptically mimic a slower heartbeat which we expect wearers to align their breathing to in order to relax.

## Rough Form
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/cbm_proto.png)

## Expected parts
The major components for the prototype thus far include:
* a Teensy 4.1 Microcontroller which is compatible and programmable through 'Teensyduino' -- for collecting samples.  
* a Sparkfun MEMS Microphone Breakout Board -- for breath detection
* an Integrated Bluetooth Module -- for interfacing with our phone. 
* Power supply -- for supplying power. 

Also needed for the project are a smartwatch and smartphone. 


## Interaction Plan
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/cbm_to_phone_to_watch_small.jpg)

We expect wearers to treat the glasses and wear them as they normally would. They would need to download the phone and watch app ahead of time and then pair the glasses to the phone. We will be including a button for powering the device on/off and to enable pairing mode. The glasses themselves will continuously track breathing through the MEMS microphone which is set to a low gain and will utilize filters to eliminate frequencies not expected in normal, shallow, or rapid breathing. 
