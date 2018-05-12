#include "GrundKlassen/GrundKlassen.H"

class Widget {};



#include "Beobachter.H"


void BeobachterDemo() {
	ZeitGeber* timer = new ZeitGeber;
	AnalogUhr* analogUhr = new AnalogUhr(timer);
	DigitalUhr* digitalUhr = new DigitalUhr(timer);
}

