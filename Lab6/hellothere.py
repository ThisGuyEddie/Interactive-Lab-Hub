#!/usr/bin/env python3

from vosk import Model, KaldiRecognizer
import sys
import os
import wave
import pygame


message = "hello there"
pygame.init()
if not os.path.exists("model"):
    print ("Please download the model from https://github.com/alphacep/vosk-api/blob/master/doc/models.md and unpack as 'model' in the current folder.")
    exit (1)

wf = wave.open(sys.argv[1], "rb")
if wf.getnchannels() != 1 or wf.getsampwidth() != 2 or wf.getcomptype() != "NONE":
    print ("Audio file must be WAV format mono PCM.")
    exit (1)

model = Model("model")
# You can also specify the possible word list
rec = KaldiRecognizer(model, wf.getframerate(), message)

while True:
    data = wf.readframes(4000)
    if len(data) == 0:
        break
    if rec.AcceptWaveform(data):
        print(rec.Result())
            if rec.Result() = message:
		print("General Kenobi!)
                pygame.mixer.music.load("generalkenobi.wav")
		exit(1)

    else: 
        print(rec.PartialResult())

print(rec.FinalResult())
