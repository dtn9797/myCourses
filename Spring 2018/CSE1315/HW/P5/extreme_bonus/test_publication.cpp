#include "publication.h"
#include "patron.h"

int main() {
  bool passed = true;

  string name = "Professor Rice";
  string number = "817-555-1212";

  Patron patron(name, number);

  //
  // Test constructor
  //

  Publication publication("The Firm", "John Grisham", "1991", 
     Genre::fiction, Media::book, Age::adult, "0440245923");
  Publication foundation("Foundation", "Isaac Asimov", "1942",
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation_empire("Foundation and Empire", "Isaac Asimov", "1943",
      Genre::fiction, Media::book, Age::adult, "0385177259"); // same ISBN!
  Publication foundation2("Second Foundation", "Isaac Asimov", "1944",
      Genre::fiction, Media::book, Age::adult, "0385177259"); // same ISBN!
  Publication war("War of the Worlds", "Jeff Wayne", "1977",
      Genre::performance, Media::audio, Age::teen, "9780711969148");
  Publication wonka("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
      Genre::performance, Media::video, Age::children, "0142410314");

  if (publication == foundation) {
    passed = false;
    cerr << "publication == foundation, but shouldn't be!";
  }

  if (foundation2 != foundation) {
    passed = false;
    cerr << "foundation2 != foundation, but should be!";
  }

  if (foundation != foundation_empire || foundation_empire != foundation2) {
    passed = false;
    cerr << "foundation != foundation2 != foundation_empire, but should be equal!";
  }

  //
  // Test check_out(patron)
  //
  publication.check_out(patron);

  if (!publication.is_checked_out()) {
    passed = false;
    cerr << "is_checked_out() reported false after check_out(patron)" << endl;
  }
    
  //
  // Test check_in()
  //

  publication.check_in();

  if (publication.is_checked_out()) {
    passed = false;
    cerr << "is_checked_out() reported true after check_in()" << endl;
  }
    
  //
  // Report results
  //

  if (!passed) {
    cout << "fail" << endl;
    return -1;
  }

  return 0;

}
