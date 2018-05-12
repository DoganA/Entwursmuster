#include "GrundDefs.H"



enum Richtung { Norden, Sueden, Osten, Westen };



class KartenEintrag {
public:
	virtual void Betrete() = 0;
};



class Raum : public KartenEintrag {
public:
	Raum(int raumNr);

	KartenEintrag* GibSeite(Richtung) const;
	void SetzeSeite(Richtung, KartenEintrag*);

	virtual void Betrete();

private:
	KartenEintrag* _seiten[4];
	int _raumNr;
};



class Wand : public KartenEintrag {
public:
	Wand();

	virtual void Betrete();
};



class Tuer : public KartenEintrag {
public:
	Tuer(Raum* = 0, Raum* = 0);

	virtual void Betrete();
	Raum* AndereSeite(Raum*);

private:
	Raum* _raum1;
	Raum* _raum2;
	bool _istOffen;
};



class Labyrinth {
public:
	Labyrinth();

	void FuegeRaumHinzu(Raum*);
	Raum* RaumNr(int) const;

private:
	// ...
};



