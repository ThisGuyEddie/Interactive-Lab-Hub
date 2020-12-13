
## Project Idea 
Anxiety disorder results in mild to severe adverse behavioral effects in 31.1% of US adults at some point in their life. Researchers have linked anxiety to faster and shallower breathing. Respiration rate may thus be a good candidate for real-time anxiety monitoring and intervention. Various sensors like Bodybeat, Hexoskin, and a mask-based humidity sensor can measure breathing. However, some are uncomfortable to wear for an extended time, and others are currently priced out of consumers’ budgets. 

This vision for a wearable respiration monitoring system takes the form of a pair of glasses with an integrated MEMS microphone placed near the hinge or bridge of the glasses. It interacts sends bluetooth data back to a phone that is running a custom-built Android app to detect heartrate variability (HRV). If it's determined that the HRV indicates anxiety, we will send signals from the phone to a watch that will haptically mimic a slower heartbeat which we expect wearers to align their breathing to in order to relax.




### Power Requirement Estimations
When designing ubiquitous computing wearable devices, power consumption plays a crucial role in ensuring that the device can function long enough to justify its adoption by consumers. Using Google Glass Enterprise Edition 2 as a point of reference with its 800 mAh battery [4] and referencing the given power draw of the Teensy 4.1, 100 mAh [14], as given by PJRC, the manufacturer of the Teensy 4.1, we can estimate that our prototype could reasonably function for 8 hours of sustained respiration monitoring. When factoring in the current draw of the HC-05 (100 mAh) and the MEMS microphone (250Ah) we get an estimated 5.7 hours of continuous operation assuming each subsystem operates at its maximum power draw. 

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
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/cbm_to_phone_to_watch_small.jpg)

We expect wearers to treat the glasses and wear them as they normally would. They would need to download the phone and watch app ahead of time and then pair the glasses to the phone. We will be including a button for powering the device on/off and to enable pairing mode. The glasses themselves will continuously track breathing through the MEMS microphone which is set to a low gain and will utilize filters to eliminate frequencies not expected in normal, shallow, or rapid breathing. 

## Wiring Diagram
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/final_project/media/mems_breadboard.jpg)

## Measurements
* MEMS:  14.50 x 10.75 x 2.60 mm
* HC-05: 37.75 x 16.45 x 4.10 mm
* Teensy: 234 x 185.85 x 12.6 (or 3.3 w/o headers) mm



## References
[1] Aiello M, Avalur D, S. Human breath detection using a microphone. 30 Aug. 2013; from http://www.cs.rug.nl/~aiellom/tesi/avalur
[2] “All About IMoodJournal.” IMoodJournal, www.imoodjournal.com/.
[3] Frans A. Boiten, Nico H. Frijda, and Cornelis J.E. Wientjes. 1994. Emotions and respiratory patterns: review and critical analysis. International Journal of Psychophysiology 17, 2 (July 1994), 103–128. DOI:https://doi.org/10.1016/0167-8760(94)90027-2

[4] Glass enterprise edition 2 tech specs. Retrieved December 10, 2020, from https://www.google.com/glass/tech-specs/ .

[5] Ikuo Homma and Yuri Masaoka. 2008. Breathing rhythms and emotions: Breathing and emotion. Experimental Physiology 93, 9 (September 2008), 1011–1021. DOI:https://doi.org/10.1113/expphysiol.2008.042424

[6] Jean Costa, Alexander T. Adams, Malte F. Jung, François Guimbretière, and Tanzeem Choudhury. 2017. EmotionCheck: A Wearable Device to Regulate Anxiety through False Heart Rate Feedback. GetMobile: Mobile Comp. and Comm. 21, 2 (June 2017), 22–25. DOI:https://doi.org/10.1145/3131214.3131222

[7] Jean Costa, Malte F. Jung, Mary Czerwinski, François Guimbretière, Trinh Le, and Tanzeem Choudhury. 2018. Regulating Feelings During Interpersonal Conflicts by Changing Voice Self-perception. <i>Proceedings of the 2018 CHI Conference on Human Factors in Computing Systems</i>. Association for Computing Machinery, New York, NY, USA, Paper 631, 1–13. DOI:https://doi.org/10.1145/3173574.31 74205

[8] John A. Chalmers, Daniel S. Quintana, Maree J.-Anne Abbott, and Andrew H. Kemp. 2014. Anxiety Disorders are Associated with Reduced Heart Rate Variability: A Meta-Analysis. Frontiers in Psychiatry 5 (2014). DOI:http://dx.doi.org/10.3389/fpsyt.2014.00080

[9] NIMH » Any Anxiety Disorder. Retrieved September 16, 2020 from https://www.nimh.nih.gov/health/statistics/any-anxiety-disorder.shtml

[10] Pollak S, M. Email Apnea. 2014. Retrieved December 10, 2020, from https://www.psychologytoday.com/us/blog/the-art-now/201411/email-apnea.
[11] “Reporter.” Reporter for iPhone, reporter-app.com/.
[12] Richard Liaw, Eric Liang, Robert Nishihara, Philipp Moritz, Joseph E. Gonzalez, and Ion Stoica. 2018. Tune: A Research Platform for Distributed Model Selection and Training. arXiv:1807.05118 [cs, stat] (July 2018). Retrieved December 12, 2020 from http://arxiv.org/abs/1807.05118
[13] Shaffer, F. and Ginsberg, J.P. 2017. An Overview of Heart Rate Variability Metrics and Norms. Frontiers in Public Health. 5, (Sep. 2017). DOI:https://doi.org/10.3389/fpubh.2017.00258.

[14] Tauhidur Rahman, Alexander T. Adams, Mi Zhang, Erin Cherry, Bobby Zhou, Huaishu Peng, and Tanzeem Choudhury. 2014. BodyBeat: a mobile system for sensing non-speech body sounds. In Proceedings of the 12th annual international conference on Mobile systems, applications, and services - MobiSys ’14, ACM Press, Bretton Woods, New Hampshire, USA, 2–13. DOI:https://doi.org/10.1145/2594368.2594386

[15] Teensy 4.0 development board. Retrieved December 10, 2020, from https://www.pjrc.com/store/teensy40.html. 
[16] ThrivePort, LLC. “‎Moodnotes - Mood Tracker.” App Store, 5 Aug. 2015, apps.apple.com/us/app/moodnotes-mood-tracker/id1019230398.
[17] Villar, Rodrigo, et al. “Validation of the Hexoskin Wearable Vest during Lying, Sitting, Standing, and Walking Activities.” Applied Physiology, Nutrition, and Metabolism, vol. 40, no. 10, 2015, pp. 1019–1024., doi:10.1139/apnm-2015-0140.
[18] Young Human, LLC. “‎Mood App: Journal.” App Store, 7 June 2017, apps.apple.com/us/app/mood-app-journal/id1241839696.
[19] Yu Pang, Jinming Jian, Tao Tu, Zhen Yang, Jiang Ling, Yuxing Li, Xuefeng Wang, Yancong Qiao, He Tian, Yi Yang, and Tian-Ling Ren. 2018. Wearable humidity sensor based on porous graphene network for respiration monitoring. Biosensors and Bioelectronics 116, (September 2018), 123–129. DOI:https://doi.org/10.1016/j.bios.2018.05.038
