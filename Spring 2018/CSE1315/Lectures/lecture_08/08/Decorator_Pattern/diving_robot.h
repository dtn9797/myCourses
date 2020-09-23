#ifndef __DIVING_ROBOT_H
#define __DIVING_ROBOT_H

#include "robot.h"

class Diving_robot : public Robot {
  public:
    void announce() override;
};

#endif
