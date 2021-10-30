#include "MIDIUSB.h"

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

int pot1Pin = 18;
float pot1Val = 0;
float pot1ValN = 0;
int pot1Velocity = 0;


int pot2Pin = 19;
float pot2Val = 0;
float pot2ValN = 0;
int pot2Velocity = 0;

int pot3Pin = 20;
float pot3Val = 0;
float pot3ValN = 0;
int pot3Velocity = 0;

int pot4Pin = 21;
float pot4Val = 0;
float pot4ValN = 0;
int pot4Velocity = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN_TX,INPUT);
  pinMode(LED_BUILTIN_RX,INPUT);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {
  // put your main code here, to run repeatedly:
pot1ValN = analogRead(pot1Pin);
pot2ValN = analogRead(pot2Pin);
pot3ValN = analogRead(pot3Pin);
pot4ValN = analogRead(pot4Pin);

if (abs(pot1ValN - pot1Val) > 3){
if (pot1ValN == 0){
  pot1Velocity = 0;
}
else if (pot1ValN == 1023){
  pot1Velocity = 127;
}
else {
  pot1Velocity = ((pot1ValN / 1023) * 127);
}
pot1Val = pot1ValN;
controlChange(0, 10, pot1Velocity);
}


if (abs(pot2ValN - pot2Val) > 3){
if (pot2ValN == 0){
  pot2Velocity = 0;
}
else if (pot2ValN == 1023){
  pot2Velocity = 127;
}
else {
  pot2Velocity = ((pot2ValN / 1023) * 127);
}
pot2Val = pot2ValN;
controlChange(0, 11, pot2Velocity);
}


if (abs(pot3ValN - pot3Val) > 3){
if (pot3ValN == 0){
  pot3Velocity = 0;
}
else if (pot3ValN == 1023){
  pot3Velocity = 127;
}
else {
  pot3Velocity = ((pot3ValN / 1023) * 127);
}
pot3Val = pot3ValN;
controlChange(0, 12, pot3Velocity);
}

if (abs(pot4ValN - pot4Val) > 3){
if (pot4ValN == 0){
  pot4Velocity = 0;
}
else if (pot4ValN == 1023){
  pot4Velocity = 127;
}
else {
  pot4Velocity = ((pot4ValN / 1023) * 127);
}
pot4Val = pot3ValN;
controlChange(0, 13, pot4Velocity);
}



MidiUSB.flush();
delay(100);


 // Serial.print("P1:");
 // Serial.print(pot1Val);
 // Serial.print("P2:");
 // Serial.print(pot2Val);
 // Serial.print("P3:");
 // Serial.print(pot3Val);
 // Serial.print("P4:");
 // Serial.println(pot4Val);
}
