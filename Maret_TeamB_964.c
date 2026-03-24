#include <stdio.h>
#include <kipr/wombat.h>



int claw = 3;

int elbow = 0;

int rightWheel = 0;

int leftWheel = 3;

int lightSensor = 4;



int keepUpdating = 1;

double startTime = 0;



//need to simulate a light sensor, so manually add in inputs

//starting with lights on value, lights off value is 3000

int testLights = 1000;



void moveStraight(int speed) {

   motor(rightWheel, speed);

   motor(leftWheel, speed);

}



void updateScreen() {

   while (keepUpdating) {

       int elapsed = (int)(seconds() - startTime);

       display_clear();

       display_printf(0, 0, "Light: %d", analog(lightSensor));

       display_printf(0, 1, "Secs : %d", elapsed);

       msleep(100);

   }

}



int main() {

   thread screenThread;



   startTime = seconds();

   shut_down_in(15.0);   // hard stop after 15 seconds



   screenThread = thread_create(updateScreen);

   thread_start(screenThread);



   enable_servos();



   // wait for light

   // You can also use: wait_for_light(lightSensor);

  // while (analog(lightSensor) < 1000) { //uncomment this for the analog sensor real test

   while (testLights < 1100) {



   enable_servos();

set_servo_position(elbow, 1024);

set_servo_position(claw, 0);





//approach the can

moveStraight(35);

msleep(2500);

ao();





//put elbow down, wait, claw close

set_servo_position(elbow, 1875);

msleep(3000);

moveStraight(20);

msleep(2500);

ao();

set_servo_position(claw, 1500);

msleep(3000);





//lift up the can w/elbow up, then set back down

set_servo_position(elbow,1024);

msleep(3000);

moveStraight(40);

msleep(2000);

set_servo_position(elbow, 1875);

msleep(150);

set_servo_position(claw, 20);

msleep(1400000);

disable_servos();



   keepUpdating = 0;

   msleep(150);

   thread_destroy(screenThread);

   }



   return 0;

}
