# Try some Python code on the Pi
We will be using Python in future modules, so try running some of the sample python code in python_games:

wormy.py catanimation.py tetromino.py

Take a look at the code in the python file, using cat, or nano.

Also try the shellscripts in the textToSpeech directory.

** How do you know what the shell script is doing? **
* 'cat' or 'vi' into the shell script and read it. 


Adapt the scripts so that they say what you want them to say.
* rec = KaldiRecognizer(model, wf.getframerate(), "hello good morning zero oh one two three four five six seven eight nine [unk]")


Now try the shellscripts in the speechToText directory.

These scripts use a program called vosk to recognize numbers.

## How do we use vosk to recognize words and phrases?
We add the words into the KaldiRecognizer line of test_words.py
## Include the output of vosk recognizing phrases you taught it to look for.
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/Lab6/hello.png) 
![](https://github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/Lab6/test.png)

## Include the listing for a shell script and model files that you use to get vosk to recognize these phrases.






# Hello Pi, Hello Arduino
With your Pi and Arduino, try out the helloPi and helloArduino sketches. Tweak them to make them do something new.

HelloPi.ino sets up the Arduino to say hello to the Pi repeatedly. HelloPi.py echos the Arduino’s message to the console in text form. sayHelloPi.py plays the helloPi.wav file whenever the Pi gets any message from the Arduino on the serialPort.

Flash the Arduino with HelloPi.ino. With HelloPi.ino running on the Arduino, run HelloPi.py on the Pi using $python HelloPi.py.

## What would you change to make sayHelloPi say something else?
Edit the "data" string in the .ino file. 

## How could you make it so that the Pi would only say something if the lights came on in the room?
Make an if condition based on the readings from a photodiode. 

## How could you make it so that the Pi would say different things based on different sensor values read by the Arduino?
Map various strings to sensor values for an build out a switch-case to


Next, try out HelloArduino. First have HelloArduino.ino listen for messages from HelloArduino.py. 
## Next, use morse_code_translator.ino. What happens differently?
* helloArduino.py has the arduino LEDs flash "SOS" in morse code. 



Change the HelloArduino.py program to take in inputs from the user to have them translated to morse code on the Arduino.
[helloArduino.py](//github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/Lab6/helloArduino.py)
## Your own voice agent
Program a simple application that understands different basic greetings (for example, Yo!, Good morning! And Good afternoon!) and responds either visibly, physically or auditorially in kind!
[hellothere.py](//github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/Lab6/hellothere.py)
[sayhellothere.py](//github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/Lab6/sayhellothere.py)
### Record someone trying out your design
[Eli's Demo](//github.com/ThisGuyEddie/Interactive-Lab-Hub/blob/master/Lab6/eli-mcgregor.MOV)
https://www.youtube.com/watch?v=nUfYooMcEqA
