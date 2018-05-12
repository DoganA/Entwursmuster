#include "GrundKlassen/GrundDefs.H"

template<class Element> class Iterator;

template<class Element>
class AbstrakteListe {
public:
	virtual Iterator<Element>* ErzeugeIterator() const = 0;
	// ...
};

const int DEFAULT_LISTEN_KAPAZITAET = 42;

template<class Element>
class Liste : public AbstrakteListe<Element> {
public:
	Liste(long groesse = DEFAULT_LISTEN_KAPAZITAET);
	virtual Iterator<Element>* ErzeugeIterator() const;

	long AnzahlElemente() const;
	Element& GibElement(long index) const;
	// ...
};

class Angestellter {
public:
	virtual void Drucke();
};



#include "Iterator.H"



void DruckeAngestelltenObjekte(Iterator<Angestellter*>& iter) {
	for (iter.Start(); !iter.IstFertig(); iter.Weiter()) {
		iter.AktuellesElement()->Drucke();
	}
}



void IteratorDemo1() {
	Liste<Angestellter*>* angestelltenObjekte;
	// ...
	ListenIterator<Angestellter*>
		vorwaerts(angestelltenObjekte);
//	UmgekehrterListenIterator<Angestellter*>
//		rueckwaerts(angestelltenObjekte);

	DruckeAngestelltenObjekte(vorwaerts);
//	DruckeAngestelltenObjekte(rueckwaerts);
}



template<class Element>
class SkipListe : public AbstrakteListe<Element> {};

template<class Element>
class SkipListenIterator : public Iterator<Element> {
public:
	SkipListenIterator(const SkipListe<Element>*);
	virtual void Start();
	virtual void Weiter();
	virtual bool IstFertig() const;
	virtual Element AktuellesElement() const;
};

void IteratorDemo2() {
	SkipListe<Angestellter*>* angestelltenObjekte;
	// ...

	SkipListenIterator<Angestellter*>
		iterator(angestelltenObjekte);
	DruckeAngestelltenObjekte(iterator);
}



void IteratorDemo3() {
	// wir wissen lediglich, dass wir ein AbstrakteListe-Objekt haben
	AbstrakteListe<Angestellter*>* angestelltenObjekte;
	// ...

	Iterator<Angestellter*>* iterator =
		angestelltenObjekte->ErzeugeIterator();
	DruckeAngestelltenObjekte(*iterator);
	delete iterator;
}



void IteratorDemo4() {
	AbstrakteListe<Angestellter*>* angestelltenObjekte;
	// ...

	IteratorZeiger<Angestellter*> iterator(
		angestelltenObjekte->ErzeugeIterator());
	DruckeAngestelltenObjekte(*iterator);
}



void IteratorDemo5() {
	Liste<Angestellter*>* angestelltenObjekte;
	// ...

	DruckeNAngestelltenObjekte dao(angestelltenObjekte, 10);
	dao.Traversiere();

	ListenIterator<Angestellter*> iter(angestelltenObjekte);
	int anzahl = 0;

	for (iter.Start(); !iter.IstFertig(); iter.Weiter()) {
		anzahl++;
		iter.AktuellesElement()->Drucke();
		if (anzahl >= 10) break;
	}
}

