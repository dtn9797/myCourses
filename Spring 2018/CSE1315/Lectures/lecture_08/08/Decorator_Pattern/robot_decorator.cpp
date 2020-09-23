#include "robot_decorator.h"

Robot_decorator::Robot_decorator(Robot& decorated_robot) 
    : _decorated_robot{decorated_robot} { }

void Robot_decorator::announce() {_decorated_robot.announce();}
