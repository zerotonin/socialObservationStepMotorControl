/* 
Date: 17.06.2013 Rev: 24.02.2022
Autor: Jan Hoffmann and Bart Geurten


Function: 

digital pin map:
D0  open
D1  open
D2  button Motor1Raf
D3  button Motor1L
D4  button Motor2R
D5  button Motor2L
D6  button AUTOMATION
D7  zero position gauge M1
D8  zero position gauge M2
D9  Motor2A
D10 Motor2B
D11 Motor1A
D12 Motor1B
D13 open
 
Belegung der Analogen Pins: 
A0  COAD
A1  COAD
A2  COAD
A3  COAD
A4  LED

*/

#include <Stepper.h>
//+++++++++++++++++++++++++++++++++++++++++Edit only here+++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++Edit only here+++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++Edit only here+++++++++++++++++++++++++++++++++++++++++++++++++++
int PAUSE   =  10000;      //sec x 1000                                                               //+++
                                                                                                      //+++
                                                                                                      //+++
                                                                                                      //+++
                                                                                                      //+++
                                                                                                      //+++
                                                                                                      //+++
//#########################################################################################################
int TPAUSE  =  50;
int pressed  =  1;
int not_pressed  =  0;
int TM1R = 0;
int TM1L = 0;
int TM2R = 0;
int TM2L = 0;
int AUTO = 0;
int NPM1 = 0;
int NPM2 = 0;
int ONCE = 0;
int time = 0;
int Test1 = 0;
int TimeOut = 0;
int BLOCK = 0;
//######################################################################################################### Eingänge definieren
int OUT       =  A5;              // line out for camera
int TMotor1R  =  2;               // Button Pin
int TMotor1L  =  3;               // Button Pin
int TMotor2R  =  4;               // Button Pin
int TMotor2L  =  5;               // Button Pin
int Automate  =  6;               // Button Pin
int ZEROPM1  =  7;                // zero gauge Pin
int ZEROPM2  =  8;                // zero gauge Pin
//######################################################################################################### Ausgänge definieren
int LED      =  A4;               // LED lights on ANALOGUE 4
int Motor2A  =  9;                // Contact to the MOTORS
int Motor2B  =  10;               // Contact to the MOTORS
int Motor1A  =  11;               // Contact to the MOTORS
int Motor1B  =  12;               // Contact to the MOTORS
//######################################################################################################### Stepper einbinden
const int stepsPerRevolution = 24;  // change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, Motor1A , Motor1B);       
Stepper myStepper2(stepsPerRevolution, Motor2A , Motor2B);    

int stepCount = 0;         // number of steps the motor has taken
//######################################################################################################### Setup
void setup() 
{
Serial.begin(9600);
//######################################################################################################### initialise pins
pinMode(TMotor1R, INPUT); 
digitalWrite(TMotor1R, LOW);                     // activate internal PULL DOWN

pinMode(TMotor1L, INPUT);
digitalWrite(TMotor1L, LOW);                     // activate internal PULL DOWN

pinMode(TMotor2R, INPUT);
digitalWrite(TMotor2R, LOW);                     // activate internal PULL DOWN

pinMode(TMotor2L, INPUT);
digitalWrite(TMotor2L, LOW);                     // activate internal PULL DOWN

pinMode(Automate, INPUT);
digitalWrite(Automate, LOW);                     // activate internal PULL DOWN

pinMode(ZEROPM1, INPUT);
digitalWrite(ZEROPM1, LOW);                      // activate internal PULL DOWN

pinMode(ZEROPM2, INPUT);
digitalWrite(ZEROPM2, LOW);                      // activate internal PULL DOWN

pinMode(OUT, OUTPUT);
digitalWrite(OUT, LOW);                          // activate internal PULL DOWN

pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);                          // activate internal PULL DOWN


DDRC = DDRC|B00000000;                           // define Port C as input
PORTC = PORTC|B00000000;                         // activate Port C Pull DOWN 

}//######################################################################################################### END Setup 

//######################################################################################################### MAIN
void loop() 
{
//######################################################################################################### Initialise Motors by searching for zero position
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+Dieser Teil kann nur einmal duchlaufen werden (nach einem Reset)+
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
while (Test1 == 0)
      {
      INIT_MOTORS();
      Test1 ++;
      }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//######################################################################################################### Check buttons and respon
//+++++++++++++++++Motor1 = right+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   digitalWrite(LED, HIGH);
   
   TM1R = digitalRead(TMotor1R);                         //read button pin
   if (TM1R == pressed)                                  // if pressed ...
      {
       delay(TPAUSE);                                    // wait to avoid bouncing
       if (digitalRead(TMotor1R) == pressed)             //test if still pressed
          {
           myStepper1.step(-1);                          // make the step
         
           while (TM1R == pressed)                       //wait on button release
            {
              TM1R = digitalRead(TMotor1R);              //check if released                 
            }
           delay(TPAUSE);                                // wait to avoid bouncing
          }
      }

 //+++++++++++++Motor1 = links+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    TM1L = digitalRead(TMotor1L);                        //read button pin
   if (TM1L == pressed)                                  // if pressed ...
      {
       delay(TPAUSE);                                    // wait to avoid bouncing
       if (digitalRead(TMotor1L) == pressed)             //test if still pressed
          {
           myStepper1.step(1);                           // make the step
         
           while (TM1L == pressed)                       //wait on button release
            {
              TM1L = digitalRead(TMotor1L);              //check if released 
            }
           delay(TPAUSE);                                // wait to avoid bouncing
          }
      }

 //+++++++++++++Motor2 = rechts+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    TM2R = digitalRead(TMotor2R);                        //read button pin
   if (TM2R == pressed)                                  // if pressed ...
      {
       delay(TPAUSE);                                    // wait to avoid bouncing
       if (digitalRead(TMotor2R) == pressed)             //test if still pressed
          {
           myStepper2.step(-1);                          // make the step
         
           while (TM2R == pressed)                       //wait on button release
            {
              TM2R = digitalRead(TMotor2R);              //check if released 
            }
           delay(TPAUSE);                                // wait to avoid bouncing
          }
      }

 //+++++++++++++Motor2 = links+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    TM2L = digitalRead(TMotor2L);                        //read button pin
   if (TM2L == pressed)                                  // if pressed ...
      {
       delay(TPAUSE);                                    // wait to avoid bouncing
       if (digitalRead(TMotor2L) == pressed)             //test if still pressed
          {
           myStepper2.step(1);                           // make the step
         
           while (TM2L == pressed)                       //wait on button release
            {
              TM2L = digitalRead(TMotor2L);              //check if released 
            }
           delay(TPAUSE);                                // wait to avoid bouncing
          }
      }

//+++++++++++++Automatick+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    AUTO = digitalRead(Automate);                      //read button pin
   if (AUTO == pressed)                                // if pressed ...
      {
       BLOCK = 0;                                      // lift BLOCKing            
       TimeOut = 0;                                    // reset 
       delay(TPAUSE);                                  // wait to avoid bouncing
       
       time = digitalRead(A0) * 1 + digitalRead(A1) * 2  // read external time and save it to 'time'
            + digitalRead(A2) * 4 + digitalRead(A3) * 8; // read external time and save it to 'time'
           Serial.print (time); 
     
       if (digitalRead(Automate) == pressed)           // test if still pressed
          {
           while (AUTO == pressed)                     // wait on button release
                 {
                  AUTO = digitalRead(Automate);        // check if released 
                  delay(TPAUSE);                       // wait to avoid bouncing
                  TimeOut ++;                          // increase Timeout 
                  if (TimeOut == 50)
                     {
                      BLOCK = 1;
                      INIT_MOTORS();             // If the button is pressed for more than 5 sec reintialise motors
                 }
           if (BLOCK == 0)
              {
               if (time > 0)                           // If time is zero do nothing
                  {
                  AUTOMATE();
                  }
              }
          }
      }
   
   }
}//######################################################################################################### END of Main
  
  
  
