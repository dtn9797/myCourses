#include "horse.h"

std::string Horse::name() {return _name;}
int Horse::position() {return _position;}
int Horse::speed() {return _speed;}
int Horse::move() {if (_position > 0) --_position;}

