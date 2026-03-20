#include <kipr/wombat.h>

void turnLeft() {
    motor(0, 35);
    motor(1, 35);
    motor(2, -35);
    motor(3, -35);
    printf("turning left");
    msleep(4150);
} 

void forward(int time) {
    motor(0,50);
    motor(1,50);
    motor(2,50);
    motor(3,50);
    msleep(time);
}

void backward(int time) {
    motor(0,-50);
    motor(1,-50);
    motor(2,-50);
    motor(3,-50);
    msleep(time);
}

void turnRight() {
    motor(2, 35);
    motor(3, 35);
    motor(0, -35);
    motor(1, -35);
    printf("turning Right");
    msleep(4200);
}

void delay(int time) {
	motor(2, 0);
    motor(3, 0);
    motor(0, 0);
    motor(1, 0);
    printf("Stopped");
    msleep(time);
}

void sortTop() {
    set_servo_position(1, 2047);
    msleep(1000);
    set_servo_position(1, 460);
}

void pickUpBall() {
	set_servo_position(3, 1100);
    delay(700);
    set_servo_position(0, 2000);
    delay(700);
    set_servo_position(3, 1800);
    delay(700);
    set_servo_position(0, 900);
    delay(700);
}

void startingPosition() {
	set_servo_position(1, 0);
	set_servo_position(3, 1700);        
	set_servo_position(0, 700);
}

void dropBall() {
	set_servo_position(0, 1400);
    delay(500);
    set_servo_position(3, 1000);
    delay(500);

}

void start() {
    startingPosition();
    //set_servo_position(1,1066);
    pickUpBall();
    turnRight();
    forward(500);
    backward(250);
    dropBall();
    turnLeft();
    forward(25000);
    
    
}



int main()
{
    enable_servos();
    start();
    return 0;
}
