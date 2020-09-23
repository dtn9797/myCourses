#include "walking_robot.h"
#include "diving_robot.h"
#include "flying_robot.h"
#include "beep_robot_decorator.h"
#include "chug_robot_decorator.h"

int main() {
    Walking_robot w;
    Diving_robot d;
    Flying_robot f;

    w.announce();
    d.announce();
    f.announce();

    cout << endl;
    Beep_robot_decorator b{w};
    b.announce();

    cout << endl;
    Chug_robot_decorator c{b};
    c.announce();
}
