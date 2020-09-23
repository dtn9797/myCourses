#ifndef __WALKING_ROBOT_H
#define __WALKING_ROBOT_H

#include "robot.h"

class Walking_robot : public Robot {
  public:
    void announce() override;
};

#endif
