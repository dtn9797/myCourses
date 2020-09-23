#ifndef __BEEP_ROBOT_DECORATOR
#define __BEEP_ROBOT_DECORATOR

#include "robot_decorator.h"

class Beep_robot_decorator : public Robot_decorator {
  public:
    Beep_robot_decorator(Robot& decorated_robot);
    void announce() override;
};

#endif
