#include <iostream>
#include <vector>

// The product interface
class Robot {
  public: 
    virtual void announce() = 0;
};

// The concrete product classes
class WalkingRobot : public Robot {
  public:
    void announce() override {
      std::cout << "Make way!" << std::endl;
    }
};

class FlyingRobot : public Robot {
  public:
    void announce() override {
      std::cout << "Heads up!" << std::endl;
    }
};

class DivingRobot : public Robot {
  public:
     void announce() override {
       std::cout << "Glub! Glub!" << std::endl;
     }
};

// The Creator interface
class RobotCreator {
  public:
    static Robot* getRobot(std::string criteria);
};

// The concrete creator (factory) class
class RobotFactory : public RobotCreator {
  public:
    static Robot* getRobot(std::string criteria) {
      if (criteria == "walks") 
        return new WalkingRobot();
      else if (criteria == "flies") 
        return new FlyingRobot();
      else
        return new DivingRobot();
    }
};

int main() {
    std::vector<std::string> criteria = {"walks", "flies", "dives"};
    for(std::string s: criteria) {
      Robot* robot = RobotFactory::getRobot(s);
      robot->announce();
    }
};
