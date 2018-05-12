#include "GrundKlassen/GrundKlassen.H"
#include <string.h>

class Kontext;
class VariablenAusdruck;



#include "Interpreter.H"



// implementiert lediglich die rein virtuellen Operationen leer um
// den Compiler zufriedenzustellen
class DummyAusdruck : public BoolescherAusdruck {
public:
	virtual BoolescherAusdruck* Ersetze(const char*, BoolescherAusdruck&) {};
	virtual BoolescherAusdruck* Kopiere() const {};
	virtual bool WerteAus(Kontext&);
};

class Konstante : public DummyAusdruck {
public:
	Konstante(bool);
};

class OderAusdruck : public DummyAusdruck {
public:
	OderAusdruck(BoolescherAusdruck*, BoolescherAusdruck*);
};

class NichtAusdruck : public DummyAusdruck {
public:
	NichtAusdruck(BoolescherAusdruck*);
};



void InterpreterDemo() {
	BoolescherAusdruck* ausdruck;
	Kontext kontext;

	VariablenAusdruck* x = new VariablenAusdruck("X");
	VariablenAusdruck* y = new VariablenAusdruck("Y");

	ausdruck = new OderAusdruck(
		new UndAusdruck(new Konstante(true), x),
		new UndAusdruck(y, new NichtAusdruck(x)));

	kontext.WeiseZu(x, false);
	kontext.WeiseZu(y, true);

	bool resultat = ausdruck->WerteAus(kontext);

	VariablenAusdruck* z = new VariablenAusdruck("Z");
	NichtAusdruck nichtZ(z);

	BoolescherAusdruck* ersetzung = ausdruck->Ersetze("Y", nichtZ);

	kontext.WeiseZu(z, true);

	resultat = ersetzung->WerteAus(kontext);
}

