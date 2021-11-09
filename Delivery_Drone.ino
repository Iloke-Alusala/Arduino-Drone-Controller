/*
 * This code just initializes the drone and connect the PPM Reader to the PPM Encoder.
 * The real action happens in "PPMReader.cpp"
 */
#include "PPMReader.h"
#include "PPMEncoder.h"

// This is the output pin that will send to PPM Signal to the drone
#define OUTPUT_PIN 2 

//This pin will read the data from the Receiver
byte interruptPin = 3;

//This is how many channels the transmitter has. Most will have 8 channels
byte channelAmount = 8;

// The array that will store the channel values
int ch[9];

//The pins that are used to connect to the motor.

//This initializes the PPMReader software
PPMReader ppm(interruptPin, channelAmount);

void setup() { 
    // Set the pins to OUTPUT mode
    
    //Initialize the PPM Encoder
    ppmEncoder.begin(OUTPUT_PIN);

    //Set default channel values
    ppmEncoder.setChannelPercent(0, 50);
    ppmEncoder.setChannelPercent(1, 50);
    ppmEncoder.setChannelPercent(3, 50);
}

void loop() {
    // Read the latest valid values from all channels
    for (int channel = 1; channel <= channelAmount; ++channel) {
        ch[channel] = (ppm.latestValidChannelValue(channel, 0) - 1000)/10;
    }
    //Send the values of each channel to the drone via a Single PPM signal
    ppmEncoder.setChannelPercent(0, ch[1]);
    ppmEncoder.setChannelPercent(1, ch[2]);
    ppmEncoder.setChannelPercent(2, ch[3]);
    ppmEncoder.setChannelPercent(3, ch[4]);
    ppmEncoder.setChannelPercent(4, ch[5]);
    ppmEncoder.setChannelPercent(5, ch[6]);
    ppmEncoder.setChannelPercent(6, ch[7]);
    ppmEncoder.setChannelPercent(7, ch[8]);
    
}
