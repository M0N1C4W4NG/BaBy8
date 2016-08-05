#include <Servo.h>
Servo servoRight;
Servo servoLeft;

char dataIn='S';
char determinant;
char det;
int vel = 200; //Bluetooth Stuff

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);
  Serial.begin(9600);
}

void forward(){
  servoLeft.writeMicroseconds(1600);
  servoRight.writeMicroseconds(1400);
}

void backward(){
  servoLeft.writeMicroseconds(1400);
  servoRight.writeMicroseconds(1600);
}

void turnRight(){
  servoLeft.writeMicroseconds(1400);
  servoRight.writeMicroseconds(1400);
}

void turnLeft(){
  servoLeft.writeMicroseconds(1600);
  servoRight.writeMicroseconds(1600);
}

void stopservos(){
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void loop() {det = check();
  // put your main code here, to run repeatedly:
  while (det == 'F'){  // F, move forward
       servoLeft.writeMicroseconds(1500+vel);
       servoRight.writeMicroseconds(1500-vel);
       det = check();}
     
  while (det == 'B'){   // B, move back
       servoLeft.writeMicroseconds(1500-vel);
       servoRight.writeMicroseconds(1500+vel);
       det = check();}

  while (det == 'L'){   // L, move wheels left
       servoLeft.writeMicroseconds(1500-vel);
       servoRight.writeMicroseconds(1500-vel);
       det = check();}
      
  while (det == 'R'){   // R, move wheels right
       servoLeft.writeMicroseconds(1500+vel);
       servoRight.writeMicroseconds(1500+vel);
       det = check();}
    
  while (det == 'I'){   // I, turn right forward
       servoLeft.writeMicroseconds(1500+vel);
       servoRight.writeMicroseconds(1500+vel*2);
       det = check();}
    
  while (det == 'J'){   // J, turn right back
       servoLeft.writeMicroseconds(1500-vel);
       servoRight.writeMicroseconds(1500-vel*2);
       det = check();}  
     
  while (det == 'G'){   // G, turn left forward
       servoLeft.writeMicroseconds(1500-vel*2);
       servoRight.writeMicroseconds(1500-vel);
       det = check();}
    
  while (det == 'H'){   // H, turn left back
       servoLeft.writeMicroseconds(1500+vel*2);
       servoRight.writeMicroseconds(1500+vel);
       det = check();}  
     
  while (det == 'S'){   // S, stop
       servoLeft.writeMicroseconds(1500);
       servoRight.writeMicroseconds(1500);
       det = check();}

}
int check()
  {if( Serial.available()>0){
  // if data is available to read
   dataIn = Serial.read();         // read it and store it in 'val'
   Serial.print("I received: ");
   Serial.println(dataIn);
   if (dataIn == 'F'){determinant = 'F';} 
        else if (dataIn == 'B'){determinant = 'B';}else if (dataIn == 'L'){determinant = 'L';}
        else if (dataIn == 'R'){determinant = 'R';}else if (dataIn == 'I'){determinant = 'I';} 
        else if (dataIn == 'J'){determinant = 'J';}else if (dataIn == 'G'){determinant = 'G';}   
        else if (dataIn == 'H'){determinant = 'H';}else if (dataIn == 'S'){determinant = 'S';}
        else if (dataIn == '0'){vel = 0;}else if (dataIn == '1'){vel = 38;}
        else if (dataIn == '2'){vel = 56;}else if (dataIn == '3'){vel = 74;}
        else if (dataIn == '4'){vel = 92;}else if (dataIn == '5'){vel = 110;}
        else if (dataIn == '6'){vel = 128;}else if (dataIn == '7'){vel = 146;}
        else if (dataIn == '8'){vel = 164;}else if (dataIn == '9'){vel = 182;}
        else if (dataIn == 'q'){vel = 200;}
        else if (dataIn == 'U'){determinant = 'U';}else if (dataIn == 'u'){determinant = 'u';}
        else if (dataIn == 'W'){determinant = 'W';}else if (dataIn == 'w'){determinant = 'w';}
  }return determinant;}


