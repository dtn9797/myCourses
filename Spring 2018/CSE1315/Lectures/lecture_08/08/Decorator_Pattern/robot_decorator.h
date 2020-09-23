#ifndef __ROBOT_DECORATOR_H
#define __ROBOT_DECORATOR_H

#include "robot.h"

class Robot_decorator : public Robot {
  protected:
    Robot& _decorated_robot;
  public:
    Robot_decorator(Robot& decorated_robot);
    virtual void announce();
};

#endif
