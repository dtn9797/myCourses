#include <gtkmm.h>

int main(int argc, char *argv[])
{
    // Initialize GTK
    Gtk::Main kit(argc, argv);

    // Create a simple dialog containing "Hello, World!"
    Gtk::MessageDialog dialog("Hello, World!");

    // Turn control over to gtkmm until the user clicks OK
    dialog.run();
}
