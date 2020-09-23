#include "view.h"
#include "publication.h"
#include "library.h"

int main() {
  Library library;
  View view(library);

  bool passed = true;

  Publication foundation("Foundation", "Isaac Asimov", "1942", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation_empire("Foundation and Empire", "Isaac Asimov", "1943", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation2("Second Foundation", "Isaac Asimov", "1944", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication war("War of the Worlds", "Jeff Wayne", "1977",
      Genre::performance, Media::audio, Age::teen, "9780711969148");
  Publication wonka("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
      Genre::performance, Media::video, Age::children, "0142410314");

  library.add_publication(foundation);
  library.add_publication(foundation_empire);
  library.add_publication(foundation2);
  library.add_publication(war);
  library.add_publication(wonka);

  library.check_out(1, "Curly", "817-555-1212");

  //
  // Test menu
  //
  cout << endl;
  view.show_menu();

  //
  // Test list publications
  //
  cout << endl;
  view.list_publications();

  //
  // Show results
  //
  cout << endl << "Verify output for pass or fail" << endl;
}
