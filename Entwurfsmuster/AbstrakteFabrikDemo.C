#include "GrundKlassen/LabyrinthDefs.H"

class LabyrinthFabrik;
class Zauberspruch;

class LabyrinthSpiel {
public:
	Labyrinth* ErzeugeLabyrinth(LabyrinthFabrik&);
};

class VerzauberterRaum : public Raum {
public:
	VerzauberterRaum(int, Zauberspruch*);
};

class TuerMitZauberspruch : public Tuer {
public:
	TuerMitZauberspruch(Raum*, Raum*);
};



#include "AbstrakteFabrik.H"



class LabyrinthMitBombenFabrik : public LabyrinthFabrik {
public:
	LabyrinthMitBombenFabrik();

	virtual Wand* ErzeugeWand() const;

	virtual Raum* ErzeugeRaum(int) const;
};

Wand* LabyrinthMitBombenFabrik::ErzeugeWand() const {
//	return new BombardierbareWand;
}

Raum* LabyrinthMitBombenFabrik::ErzeugeRaum(int n) const {
//	return new RaumMitBombe(n);
}



void AbstrakteFabrikDemo() {
	LabyrinthSpiel spiel;
	LabyrinthMitBombenFabrik fabrik;

	spiel.ErzeugeLabyrinth(fabrik);
}

