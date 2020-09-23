#ifndef __CONTROLLER_H
#define __CONTROLLER_H 
 
#include "library.h"
#include "view.h"

class Controller {
  public:
    Controller (Library& lib) : library(lib), view(View(library)) { }
    void cli();
    void execute_cmd(int cmd);
  private:
    Library& library; 
    View view;
};
#endif
