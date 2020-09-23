#include <string>

class Horse {
    public:
        Horse(std::string name, int speed) : _name{name}, _speed{speed}, _position{30} { }
        std::string name();
        int position();
        int speed();
        int move();
    protected:
        std::string _name;
        int _position;
        int _speed;
};
