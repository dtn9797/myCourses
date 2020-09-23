#include "library.h"
#include "publication.h"
#include "book.h"
#include "periodical.h"
#include "newspaper.h"
#include "audio.h"
#include "video.h"

void Library::add_publication(Publication* pub) {
  publications.push_back(pub);
}

void Library::add_patron(Patron pat) {
  patrons.push_back(pat);
}

void Library::check_out(int publication_index, int patron_index) {
  publications[publication_index]->check_out(patrons[patron_index]);
}

void Library::check_in(int publication_index) {
  publications[publication_index]->check_in();
}

string Library::publication_to_string(int publication_index) {
  return publications[publication_index]->to_string();
}

string Library::patron_to_string(int patron_index) {
  return patrons[patron_index].to_string();
}

int Library::number_of_publications() {
  return publications.size();
}

int Library::number_of_patrons() {
  return patrons.size();
}

void Library::easter_egg() {
 add_publication(new Book("The Firm", "John Grisham", "1991",
       Genre::fiction, Media::book, Age::adult, "0440245923", 0));
 add_publication(new Book("Foundation", "Isaac Asimov", "1942",
        Genre::fiction, Media::book, Age::adult, "0385177259", 1));
 add_publication(new Book("Foundation and Empire", "Isaac Asimov", "1943",
        Genre::fiction, Media::book, Age::adult, "0385177259", 1));
 add_publication(new Book("Second Foundation", "Isaac Asimov", "1944",
        Genre::fiction, Media::book, Age::adult, "0385177259", 1));
 add_publication(new Audio("War of the Worlds", "Jeff Wayne", "1977",
        Genre::performance, Media::audio, Age::teen, "9780711969148", 0, 1));
 add_publication(new Video("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
        Genre::performance, Media::video, Age::children, "0142410314", 1, 0, 0));
 add_patron(Patron("Larry", "817-555-1111"));
 add_patron(Patron("Curly", "817-555-2222"));
 add_patron(Patron("Moe", "817-555-3333"));
}
