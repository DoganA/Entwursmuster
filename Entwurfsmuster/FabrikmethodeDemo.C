#include "GrundKlassen/LabyrinthDefs.H"

class Zauberspruch;

class BombardierbareWand : public Wand {
};

class RaumMitBombe : public Raum {
public:
	RaumMitBombe(int);
};

class VerzauberterRaum : public Raum {
public:
	VerzauberterRaum(int, Zauberspruch*);
};

class TuerMitZauberspruch : public Tuer {
public:
	TuerMitZauberspruch(Raum*, Raum*);
};



#include "Fabrikmethode.H"


void FabrikmethodeDemo() {
}
