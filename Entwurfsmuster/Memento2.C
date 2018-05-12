#include "GrundKlassen/GrundDefs.H"

class IterationsZustand {
public:
	virtual ~IterationsZustand();
};



template<class Element>
class Behaelter {
public:
	Behaelter();

	IterationsZustand* ErzeugeInitialZustand();
	void Weiter(IterationsZustand*);
	bool IstFertig(const IterationsZustand*) const;
	Element AktuellesElement(const IterationsZustand*) const;
	IterationsZustand* Kopiere(const IterationsZustand*) const;

	void HaengeAn(const Element&);
	void Entferne(const Element&);
	// ...
};



class ElementTyp {
public:
	void Bearbeite();
	// ...
};



void Memento2Demo() {
	Behaelter<ElementTyp*> einBehaelter;
	IterationsZustand* zustand;

	zustand = einBehaelter.ErzeugeInitialZustand();

	while (!einBehaelter.IstFertig(zustand)) {
		einBehaelter.AktuellesElement(zustand)->Bearbeite();
		einBehaelter.Weiter(zustand);
	}
	delete zustand;
}


