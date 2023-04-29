// WheelDrive - move a pair of DC motors at varying rate and direction
//
// Copyright (c) 2016, Garth Zeglin.  All rights reserved. Licensed under the
// terms of the BSD 3-clause license as included in LICENSE.
//
// This program assumes that:
//
//  1. A DRV8833 dual DC motor driver module is connected to pins 5, 6, 9, and 10.
//  2. A pair of motors is attached to the driver.
//  3. The serial console on the Arduino IDE is set to 9600 baud communications speed.

// ================================================================================
// Define constant values and global variables.

// Define the pin numbers on which the outputs are generated.
#define MOT_A1_PIN 9
#define MOT_A2_PIN 10
#define MOT_B1_PIN 11
#define MOT_B2_PIN 12

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


// ================================================================================
/// Configure the hardware once after booting up.  This runs once after pressing
//// reset or powering up the board.
void setup(void)
{
  // Initialize the stepper driver control pins to output drive mode.
  pinMode(MOT_A1_PIN, OUTPUT);
  pinMode(MOT_A2_PIN, OUTPUT);
  pinMode(MOT_B1_PIN, OUTPUT);
  pinMode(MOT_B2_PIN, OUTPUT);

  // Start with drivers off, motors coasting.
  digitalWrite(MOT_A1_PIN, LOW);
  digitalWrite(MOT_A2_PIN, LOW);
  digitalWrite(MOT_B1_PIN, LOW);
  digitalWrite(MOT_B2_PIN, LOW);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
  // Initialize the serial UART at 9600 bits per second.
  Serial.begin(9600);
}

// ================================================================================
/// Set the current on a motor channel using PWM and directional logic.
/// Changing the current will affect the motor speed, but please note this is
/// not a calibrated speed control.  This function will configure the pin output
/// state and return.
///
/// \param pwm    PWM duty cycle ranging from -255 full reverse to 255 full forward
/// \param IN1_PIN  pin number xIN1 for the given channel
/// \param IN2_PIN  pin number xIN2 for the given channel


// ================================================================================
/// Set the current on both motors.
///
/// \param pwm_A  motor A PWM, -255 to 255
/// \param pwm_B  motor B PWM, -255 to 255





// ================================================================================
/// Run one iteration of the main event loop.  The Arduino system will call this
/// function over and over forever.
void loop(void)
{
  // Generate a fixed motion sequence to demonstrate the motor modes.

 //  analogWrite(MOT_A1_PIN, 40);
  // analogWrite(MOT_B1_PIN, 40);
   //digitalWrite(MOT_A2_PIN, LOW);
   //digitalWrite(MOT_B2_PIN, LOW);
 //   analogWrite(MOT_A1_PIN, LOW);
 //   digitalWrite(MOT_A2_PIN, -10);


   // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  // Ramp speed up.
/*  for (int i = 0; i < 11; i++) {
    spin_and_wait(25*i, 25*i, 500);
  }
  // Full speed forward.
  spin_and_wait(255,255,2000);

  // Ramp speed into full reverse.
  for (int i = 0; i < 21 ; i++) {
    spin_and_wait(255 - 25*i, 255 - 25*i, 500);
  }

  // Full speed reverse.
  spin_and_wait(-255,-255,2000);

  // Stop.
  spin_and_wait(0,0,2000);

  // Full speed, forward, turn, reverse, and turn for a two-wheeled base.
  spin_and_wait(255, 255, 2000);
  spin_and_wait(0, 0, 1000);
  spin_and_wait(-255, 255, 2000);
  spin_and_wait(0, 0, 1000);
  spin_and_wait(-255, -255, 2000);
  spin_and_wait(0, 0, 1000);
  spin_and_wait(255, -255, 2000);
  spin_and_wait(0, 0, 1000);
*/
  // and repeat

      //Turning:
   //analogWrite(MOT_A1_PIN, 20);
   //analogWrite(MOT_B1_PIN, LOW);
   //digitalWrite(MOT_A2_PIN, LOW);
   //digitalWrite(MOT_B2_PIN, 0.5);
   //End Turning 
   
  if (distance <50) {
    //delay(50);
 // analogWrite(MOT_A1_PIN, LOW);
   //analogWrite(MOT_B1_PIN, LOW);
  // delay(1000);
 //  analogWrite(MOT_A1_PIN, 20);

   //Turning:
   analogWrite(MOT_A1_PIN, 20);
   analogWrite(MOT_B1_PIN, LOW);
   digitalWrite(MOT_A2_PIN, LOW);
   digitalWrite(MOT_B2_PIN, 5);
   //End Turning
   
}

else {
 // delay(50);
   analogWrite(MOT_A1_PIN, 20);
   analogWrite(MOT_B1_PIN, 20);
}

}

/****************************************************************/
