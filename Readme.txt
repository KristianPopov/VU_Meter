1.What is VU meter?
VU meter is a device displaying a representation of the signal level in audio equipment.
There are different types of VU meters (electromechanical, digital and others).
They can display one or multiple audio channels (mono or stereo VU meters).

2. About the project
Video from the project can be found here:

The current device is a stereo VU meter with 5 LEDs per channel based on Metaboard project 
(see https://metalab.at/wiki/Metaboard for more information).
The device is completely compatible with Arduino and other AVR based platforms.
It has one audio input and one audio output with 3.5mm stereo audio jacks. You need power supply for your microcontroller.

3.Hardware (see schematics)
  Pieces :

   One Arduino or Metaboard or other microcontroller

   There are two stereo 3.5 audio female jacks
   - one for audio input
   - one for audio output
   note: The jacks are connected together and there is no matter which is input or output.

   5 LEDs per channel - 3 green for low and middle values, 2 red for high values.

   10x150 ohms resistors to limit LED current to 20mA


  Connections:

   Audio jacks are connected together in the following way:
	jack 1 ground pin with jack 2 ground pin
	jack 1 left channel pin with jack 2 left channel pin
	jack 1 right channel pin with right 2 left channel pin
	
   LEDs are connected in the following way:
   	Every LED cathode is connected with 150 ohms resistor to ground.
	
	Every LED anode is connected with Arduino/Metaboard like that:

	Right Channel LEDs:
	1st LED anode is connected with pin 0 
	2nd LED anode is connected with pin 1  
   	3rd LED anode is connected with pin 2
	4th LED anode is connected with pin 3 
	5th LED anode is connected with pin 4

	Left Channel LEDs:
	1st LED anode is connected with pin 5 
	2nd LED anode is connected with pin 6  
   	3rd LED anode is connected with pin 8
	4th LED anode is connected with pin 9 
	5th LED anode is connected with pin 10

   Analog input pin 4 is connected to left channel pin of the audio jacks
   Analog input pin 5 is connected to right channel pin of the audio jacks
   Ground pin on the microcontroler is connected to ground pins of the audio jacks

   Software:

   For the project can be used every AVR gcc compiler or Arduino IDE or other compiler.
   Here is the code from Arduino IDE:

   	#define AUDIO_LEFT 4
	#define AUDIO_RIGHT 5

	int right_ch[5] = {0,1,2,3,4}; //setting output pins for right channel LEDs
	int left_ch[5] = {5,6,8,9,10}; //setting output pins for left channel LEDs

	// the setup function runs once when you press reset or power the board
	void setup() {
		for(int i=0; i<5; i++){
      			pinMode(right_ch[i], OUTPUT); //setting every pin
      			pinMode(left_ch[i], OUTPUT);
    		}
	}

	// the loop function runs over and over again forever
	void loop() {
  
  		int left_value = analogRead(AUDIO_LEFT)/8; //reads signal level from left audio channel and converts it in range 0-127
  		int right_value = analogRead(AUDIO_RIGHT)/8; //reads signal level from right audio channel and converts it in range 0-127

  		for(int i=0; i<5; i++){ //Turns off every LED
      			digitalWrite(right_ch[i],LOW);
      			digitalWrite(left_ch[i],LOW);
  		}
  
  		if(left_value>5) left_value=5; //Setting limit to 200mV and preventing next for cycle from problems
  		if(right_value>5) right_value=5; //See above
  
  		for(int i=0; i<right_value; i++){ //Turns on every LED which is under signal value.
      			digitalWrite(right_ch[i],HIGH); //Every LED turns on in every 40mV
  		}
  
  		for(int i=0; i<left_value; i++){ //Same as above but with left channel
      			digitalWrite(left_ch[i],HIGH);
  		}
   	} 

4. Modifications
   Feel free to make modifications and improvements of this project. 
   There's no SMD elements and It's easy to assembly at home.
   You can use other microcontrollers. 

5. Notes
   I recommend to plug first audio cables in audio jacks and at last plug the power supply.
   I don't take any responsibility for damage on your microcontroller or 
   computer or any other hardware.
   You use this circuit and software on your own risk!!!

6. Questions
   If there are any questions about this project you can ask me on this e_mail: kriso.popov@gmail.com
   Enjoy!!!

by Kristian Popov