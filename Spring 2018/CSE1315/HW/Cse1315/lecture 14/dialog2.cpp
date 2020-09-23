#include <gtkmm.h>
#include <iostream>

int main(int argc, char *argv[]) {
    Gtk::Main kit(argc, argv);
    Gtk::Dialog *dialog = new Gtk::Dialog();

    dialog->add_button("Hello, World!", 42);

    std::cout << dialog->run() << std::endl;
    delete dialog;
}

