#include "beep_robot_decorator.h"

Beep_robot_decorator::Beep_robot_decorator(Robot& decorated_robot)
    : Robot_decorator(decorated_robot) { }

void Beep_robot_decorator::announce() {
    _decorated_robot.announce();
    cout << "Beep! Beep!" << endl;
}
