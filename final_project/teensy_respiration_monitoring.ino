
// Including the necessary head files.
#include <SD.h>
#include <SPI.h>

// Connect the MEMS AUD output to the Teensy 4.1 40 pin
int mic = 21;

// Variables to find the peak-to-peak amplitude of AUD output
const int sampleTime = 5000;
int micOut;

//previous Volume Unit value
int preValue = 0;

// make a string for assembling the data to log:
String dataString = "";

// Teensy 4.1 on-board: BUILTIN_SDCARD
const int chipSelect = BUILTIN_SDCARD;

// File dataFile;

// Mode Select Char for Bluetooth Mode Switch Case
char mode = 'T';

File dataFile;

// Initial setup

void setup()
{
	//  mode = 'T';     // Uncomment to hard code the teensy to Transmit Mode
	Serial.begin(9600);     // Sets the baud rate to 9600 Hz for the Teensy
	Serial2.begin(9600);    // Sets the baud rate to 9600 Hz for the Bluetooth Transmission
	
    // see if the card is present and can be initialized:
	if (!SD.begin(chipSelect))
	{
		Serial.println("Card failed, or not present");
		return;
	}
	Serial.println("card initialized.");

	dataFile = SD.open("micOutput.txt", FILE_WRITE);
	if (!dataFile)
	{
		Serial.println("error opening micOutput.txt @ setup");
	}
}

void loop()
{
	int micOut = findPTPAmp();
	int volume = VUMeter(micOut);

	if (Serial2.available() > 0)
	{
		// 'T' : Transmit RAW datastream live over Bluetooth
		// 'G' : Get contents from SD Card
		// 'S' : Store Raw Data to SD Card

		if (Serial2.read() == 'T')
		{
			Serial.println('Transmitting RAW Signal (mode: T)');
			mode = 'T';
		}

		if (Serial2.read() == 'G')
		{
			mode = 'G';
			Serial.println('Getting contents from SD Card (mode: G)');
		}
		if (Serial2.read() == 'S')
		{
			mode = 'S';
			Serial.println('Storing RAW to SD Card (mode: S)');
		}
	}
	switch (mode)
	{
	case 'T':
		// 'T' : Transmit RAW datastream live over Bluetooth
		Serial.println(micOut);
		Serial2.println(micOut);

	case 'G':
		// Stream SD Card Contents
		// re-open the file for reading:
		//     Serial.println('Getting from SD (mode: G)');

		dataFile = SD.open("micOutput.txt");

		if (dataFile)
		{
			//       Serial.println("(mode: G) micOutput.txt:");

			// read from the file until there's nothing else in it:
			while (dataFile.available())
			{
				Serial.write(dataFile.read());
				Serial2.write(dataFile.read());
			}
			// close the file:
			dataFile.close();
		}
		else
		{
			// if the file didn't open, print an error:
			// Serial.println("error opening micOutput.txt (mode: G)");
			mode = 'T';
			return;
		}

	case 'S':
		// Store micOut readings to SD Card
		// read mic input and append to dataString:

		if (!SD.begin(chipSelect))
		{
			// Serial.println("initialization failed! (mode: S)");
			mode = 'T';
			return;
		}
		// Serial.println("initialization done.");

		dataString += String(micOut);
		dataString += ",";

		// File dataFile = SD.open("micOutput.txt", FILE_WRITE);

		// if the file opened okay, write to it:
		if (dataFile)
		{
			dataFile.println(dataString);
			Serial.println(dataString);
		}
		else
		{
			// Serial.println("error opening micOutput.txt (mode: S)");
			mode = 'T';
			return;
		}
	}
}

// Find the Peak-to-Peak Amplitude Function
int findPTPAmp()
{
	// Time variables to find the peak-to-peak amplitude
	unsigned long startTime = millis(); // Start of sample window
	unsigned int PTPAmp = 0;

	// Signal variables to find the peak-to-peak amplitude
	unsigned int maxAmp = 0;
	unsigned int minAmp = 1023;

	// Find the max and min of the mic output within the sampleTime (ms) timeframe
	while (millis() - startTime < sampleTime)
	{
		micOut = analogRead(mic);
		if (micOut < 1023) //prevent erroneous readings
		{
			if (micOut > maxAmp)
			{
				maxAmp = micOut; //save only the max reading
			}
			else if (micOut < minAmp)
			{
				minAmp = micOut; //save only the min reading
			}
		}
	}

	PTPAmp = maxAmp - minAmp;					 // (max amp) - (min amp) = peak-to-peak amplitude
	double micOut_Volts = (PTPAmp * 3.3) / 1024; // Convert ADC into voltage
	//Serial.println(PTPAmp);       //Uncomment this line for help debugging (be sure to also comment out the VUMeter function)

	//Return the PTP amplitude to use in the soundLevel function.

	return micOut_Volts; // return PTPAmp (Peak-to-Peak Amplitude) or micOut_Volts  (active voltage readings)
}

// Volume Unit Meter function: map the PTP amplitude to a volume unit between 0 and 10.
int VUMeter(int micAmp)
{

	// Map the mic peak-to-peak amplitude to a volume unit between 0 and 10.
	// Amplitude is used instead of voltage to give a larger (and more accurate) range for the map function.

	int fill = map(micAmp, 23, 750, 0, 10);

	// Update the volume unit value iff it changes from previous value
	//  while(fill != preValue)
	//  {
	//    Serial.println(fill);
	//    preValue = fill;
	//  }
	Serial.println(fill);
	preValue = fill;
	return preValue;
}
