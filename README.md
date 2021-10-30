# Arduino_MIDIPot
Simple code for interfacing potentiometers with an Arduino / Sparkfun Pro Micro using the MIDIUSB library

Very basic anti-jitter by setting a dead zone on the potentiometers as there are 1032 steps for the analouge read and only 127 for the midi control velocity. There are 'smarter'ways to do this but this saves some overhead by letting us only send an update when the value is significantly changed, in theory this deadzone would be fine up to 6-7 samples ish without any noticeable impact.

Running at 10Hz (+ execution time) currently which is plenty enough for my use case 
