#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "view.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();           // Exit the program
        void on_color_click();          // Set the pen color
        void on_width_click();          // Set the pen width
        void on_new_click();            // Create a new drawing
        void on_open_click();           // Open the drawing
        void on_save_click();           // Save the drawing
        void on_save_as_click();        // Save the drawing to a new file
    private:
        View *view;                     // The drawing area
};
#endif
