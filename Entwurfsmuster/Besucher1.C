#include "GrundKlassen/GrundKlassen.H"

class Klasse;
class KlasseA;
class KlasseB;
class ZusammengesetzteKlasse;

class Besucher {
public:
	virtual void BesucheKlasseA(KlasseA*);
	virtual void BesucheKlasseB(KlasseB*);
	virtual void BesucheZusammengesetzteKlasse(ZusammengesetzteKlasse*);
	// und so weiter, fuer die anderen konkreten Klassen

protected:
	Besucher();
};



class Klasse {
public:
	virtual ~Klasse();
	virtual void NimmEntgegen(Besucher&) = 0;

protected:
	Klasse();
};

class KlasseA : public Klasse {
	KlasseA();
	virtual void NimmEntgegen(Besucher& besucher)
	{ besucher.BesucheKlasseA(this); };
};

class KlasseB : public Klasse {
	KlasseB();
	virtual void NimmEntgegen(Besucher& besucher)
	{ besucher.BesucheKlasseB(this); };
};



class ZusammengesetzteKlasse : public Klasse {
public:
	virtual void NimmEntgegen(Besucher&);

private:
	Liste<Klasse*>* _kindObjekte;
};

void ZusammengesetzteKlasse::NimmEntgegen(Besucher& besucher) {
	ListenIterator<Klasse*> iter(_kindObjekte);

	for (iter.Start(); !iter.IstFertig(); iter.Weiter()) {
		iter.AktuellesElement()->NimmEntgegen(besucher);
	}
	besucher.BesucheZusammengesetzteKlasse(this);
}

