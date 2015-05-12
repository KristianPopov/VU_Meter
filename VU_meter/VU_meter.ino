/*
  VU meter
  VU meter is a device displaying a representation of the signal level in audio equipment.
  The current device is a stereo VU meter with 5 LEDs per channel.
  
  Video from the project can be found here:
  https://www.youtube.com/watch?v=QyQhYzr_F-o

  modified 29 April 2015
  by Kristian Popov
 */
#define AUDIO_LEFT 4
#define AUDIO_RIGHT 5

int right_ch[5] = {0,1,2,3,4}; //set output pins for right channel LEDs
int left_ch[5] = {5,6,8,9,10}; //set output pins for left channel LEDs

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
