#include "GrundKlassen/GrundKlassen.H"

class Fenster;
class GlyphKontext;
class BBaum;

class Zeile {};
class Spalte {};
class Zeichen;

class Zeichensatz {
public:
	Zeichensatz(char*);
};



#include "Fliegengewicht.H"



void FliegengewichtDemo() {
	GlyphKontext glyphKontext;
	Zeichensatz* times12 = new Zeichensatz("Times-Roman-12");
	Zeichensatz* timesKursiv12 = new Zeichensatz("Times-Kursiv-12");
	// ...

	glyphKontext.SetzeZeichensatz(times12, 6);

	glyphKontext.FuegeHinzu(6);
	glyphKontext.SetzeZeichensatz(timesKursiv12, 6);
}

