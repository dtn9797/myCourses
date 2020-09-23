#include "chug_robot_decorator.h"

Chug_robot_decorator::Chug_robot_decorator(Robot& decorated_robot)
    : Robot_decorator(decorated_robot) { }

void Chug_robot_decorator::announce() {
    _decorated_robot.announce();
    cout << "Chug! Chug!" << endl;
}
