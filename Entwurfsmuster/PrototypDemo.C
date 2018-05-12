#include "GrundKlassen/GrundDefs.H"


class Tuer;

class Labyrinth {};
class KartenEintrag {};
class Raum : public KartenEintrag {};
class RaumMitBombe : public Raum {};
class Wand : public KartenEintrag {};

class LabyrinthFabrik {
public:
	LabyrinthFabrik();

	virtual Labyrinth* ErzeugeLabyrinth() const;
	virtual Wand* ErzeugeWand() const;
	virtual Raum* ErzeugeRaum(int n) const;
	virtual Tuer* ErzeugeTuer(Raum* raum1, Raum* raum2) const;
};

class LabyrinthSpiel {
public:
	Labyrinth* ErzeugeLabyrinth(LabyrinthFabrik&);
};



#include "Prototyp.H"



void PrototypDemo() {
	LabyrinthSpiel spiel;
	LabyrinthPrototypFabrik einfacheLabyrinthFabrik(
		new Labyrinth, new Wand, new Raum, new Tuer
	);

	Labyrinth* labyrinth = spiel.ErzeugeLabyrinth(einfacheLabyrinthFabrik);

	LabyrinthPrototypFabrik bombardierbareLabyrinthFabrik(
		new Labyrinth, new BombardierbareWand,
		new RaumMitBombe, new Tuer
	);
}


