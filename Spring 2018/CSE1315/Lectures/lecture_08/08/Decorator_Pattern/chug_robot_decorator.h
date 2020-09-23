#ifndef __CHUG_ROBOT_DECORATOR
#define __CHUG_ROBOT_DECORATOR

#include "robot_decorator.h"

class Chug_robot_decorator : public Robot_decorator {
  public:
    Chug_robot_decorator(Robot& decorated_robot);
    void announce() override;
};

#endif
