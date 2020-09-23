#ifndef __FLYING_ROBOT_H
#define __FLYING_ROBOT_H

#include "robot.h"

class Flying_robot: public Robot {
  public:
    void announce() override;
};

#endif
