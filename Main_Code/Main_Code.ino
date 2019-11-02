#include<Servo.h>
#include<Ultrasonic.h>

// define the 2 servo motors that we'll use
Servo front;
Servo back;

// trig 12 , echo 11
Ultrasonic mySensor(12,11);

// define the angles that the motors will make
// front motor :
int center1=125;
int Right=100;
int Left=150;
// back motor :
int center2=78;
int right=88;
int left=68;

int distance;


void setup() {
  
front.attach(3);
back.attach(5);
}

void moveforward(){
 
 front.write(center1);
  back.write(center2);
  delay(65);
  front.write(Left);
  back.write(right);
  delay(100);
  front.write(center1);
  back.write(center2);
  delay(65);
  front.write(Right);
  back.write(left);
  delay(100);
}
void movebackward(){
 front.write(center1);
  back.write(center2);
  delay(65);
  front.write(Left-8);
  back.write(left);
  delay(100);
  front.write(center1-8);
  back.write(center2);
  delay(65);
  front.write(Right-8);
  back.write(right);
  delay(100);
}

void loop() {
  
// Take reading from The Ultrasonic
 distance=mySensor.read(CM);
 // if the reading is greater than 15 : move forward
 if(distance>20){
  moveforward();
  delay(150);}
  
  // if the reading is less than 15 : turn backward
  else{
    // turn 12 steps continuously
  for(int i=0;i<12;i++){
  movebackward();
  delay(150);}}

}
