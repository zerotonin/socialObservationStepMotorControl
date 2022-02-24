//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  void INIT_MOTORS()
  {
  //++++++++++++++++für Motor1++++++++++++++++++++++++++++++++++++++++
       while (NPM1 == pressed)                                 //+
                {                                                //+
                myStepper1.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM1 = digitalRead(ZEROPM1);                     //+
                }                                                //+
                delay(TPAUSE);                                   //+
                myStepper1.step(3);                              //+
                delay(TPAUSE);                                   //+                
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       while (NPM1 == not_pressed)                            //+
                {                                                //+
                myStepper1.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM1 = digitalRead(ZEROPM1);                     //+
                }                                                //+
  //++++++++++++++++für Motor1++++++++++++++++++++++++++++++++++++++++
       while (NPM1 == pressed)                                 //+
                {                                                //+
                myStepper1.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM1 = digitalRead(ZEROPM1);                     //+
                }                                                //+
                delay(TPAUSE);                                   //+
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       while (NPM1 == not_pressed)                            //+
                {                                                //+
                myStepper1.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM1 = digitalRead(ZEROPM1);                     //+
                }                                                //+
  //++++++++++++++++für Motor2++++++++++++++++++++++++++++++++++++++++
       while (NPM2 == pressed)                                 //+
                {                                                //+
                myStepper2.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM2 = digitalRead(ZEROPM2);                     //+
                }                                                //+
                delay(TPAUSE);                                   //+          
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       while (NPM2 == not_pressed)                            //+
                {                                                //+
                myStepper2.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM2 = digitalRead(ZEROPM2);                     //+
               }                                                 //+
                myStepper2.step(3);                              //+
                delay(TPAUSE);                                   //+               
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       while (NPM2 == pressed)                                 //+
                {                                                //+
                myStepper2.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM2 = digitalRead(ZEROPM2);                     //+
                }                                                //+
                delay(TPAUSE);                                   //+          
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       while (NPM2 == not_pressed)                            //+
                {                                                //+
                myStepper2.step(1);                              //+
                delay(TPAUSE);                                   //+
                NPM2 = digitalRead(ZEROPM2);                     //+
               }                                                 //+
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  }
 
