#ifndef _VIEW_H
#define _VIEW_H

#include "line.h"
#include <vector>
#include <gtkmm/drawingarea.h>

using namespace std;

class View : public Gtk::DrawingArea {
  public:
     View(Gtk::Window& window);

     // ////////
     // File I/O

     // Save the current drawing to the provided output stream
     void save(ostream& os);

     // Get the drawing's current filename
     string get_filename();

     // ///////////////////
     // Getters and setters

     // Specify pen color for subsequent lines
     void set_pen_color(Gdk::RGBA new_color);
     Gdk::RGBA get_pen_color();

     // Specify pen width for subsequent lines
     void set_pen_width(double new_width);
     double get_pen_width();

     // True if all data has been saved to a file
     bool saved();


     // ///////////////
     // Signal handlers

     // Response to a request from the OS to redraw the window
     bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

     // Response to an attempt to close the main window
     bool on_my_delete_event(GdkEventAny* event);

  protected:
     // Response to a button press
     bool on_button_press_event(GdkEventButton * event) override;

  private:

     // //////////////
     // Private fields

     // Main window (as parent for dialogs)
     Gtk::Window& win;   

     // Filename of the currently open drawing
     string filename = "untitled.ctp";

     // The current drawing color and opacity
     Gdk::RGBA color = Gdk::RGBA("red");

     // The current drawing width
     int width = 3;

     // Coordinates for most recent click
     int x1, y1;

     // List of lines already drawn
     vector<Line> lines; 

     // Create a new Line and add it to the lines vector
     void new_line(int _x1, int _y1, int _x2, int _y2, Gdk::RGBA _color, double _width);

     // True if any changes since last save
     bool dirty = false;

     // True to draw line to next click
     bool click_in_progress = false; 
};
#endif
