// +++++++++++++++++++++++++++++++++++uSub Routines++++++++++++++++++++++++++++++++++++++++++++++  

  void AUTOMATE()
  {
    digitalWrite(LED,HIGH);                     // turn LEDs on
    digitalWrite(OUT,HIGH);                     // toggle the OUT pin
    delay (10);
    digitalWrite(OUT,LOW);                      // toggle the OUT pin
    
    myStepper1.step(1); // Motor 1 makes one step so that the positions of the revolvers are staggered. This way
                        // whenever both motors make a step, one revolver is open and the other one closed.
    
    for (int warte=0; warte <time; warte++)       // wait here to avoid bouncing
          {
          delay(TPAUSE);                          // wait before firstz step
          }           

    for (int i=0; i<23;i++)
        {
        digitalWrite(OUT,HIGH);                // toggle the OUT pin
        myStepper1.step(1);
        myStepper2.step(1);
        delay (10);
        digitalWrite(OUT,LOW);                // toggle the OUT pin
        for (int warte=0; warte <time; warte++) 
            {
              delay(TPAUSE);

            }
        } 
    digitalWrite(OUT,HIGH);                    // toggle the OUT pin
    delay (10);
    digitalWrite(OUT,LOW);                     // toggle the OUT pin
    myStepper2.step(1);                         // move MOTOR2 to have both in line again                                   
    digitalWrite(LED,LOW);                     // LED aus
  }
  



