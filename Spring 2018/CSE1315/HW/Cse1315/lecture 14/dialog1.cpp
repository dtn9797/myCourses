#include "dialogs.h"

int main(int argc, char *argv[]) {
    Gtk::Main kit(argc, argv);

    std::vector<std::string> buttons = {"Hello, World!"};
    std::cout << Dialogs::question("", "", buttons) << std::endl;
}

