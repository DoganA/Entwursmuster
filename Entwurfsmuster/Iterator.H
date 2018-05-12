template<class Element>
class Iterator {
public:
	virtual void Start() = 0;
	virtual void Weiter() = 0;
	virtual bool IstFertig() const = 0;
	virtual Element AktuellesElement() const = 0;

protected:
	Iterator();
};



template<class Element>
class ListenIterator : public Iterator<Element> {
public:
	ListenIterator(const Liste<Element>* eineListe);
	virtual void Start();
	virtual void Weiter();
	virtual bool IstFertig() const;
	virtual Element AktuellesElement() const;

private:
	const Liste<Element>* _liste;
	long _position;
};



template<class Element>
ListenIterator<Element>::ListenIterator(
	const Liste<Element>* eineListe) :
		_liste(eineListe), _position(0)
{}



template<class Element>
void ListenIterator<Element>::Start() {
	_position = 0;
}



template<class Element>
void ListenIterator<Element>::Weiter() {
	_position++;
}



template<class Element>
bool ListenIterator<Element>::IstFertig() const {
	return _position >= _liste->AnzahlElemente();
}



template<class Element>
Element ListenIterator<Element>::AktuellesElement() const {
	if (IstFertig()) {
//		throw IteratorIllegalePosition;
	}
	return _liste->GibElement(_position);
}



template<class Element>
Iterator<Element>* Liste<Element>::ErzeugeIterator() const {
	return new ListenIterator<Element>(this);
}



template<class Element>
class IteratorZeiger {
public:
	IteratorZeiger(Iterator<Element>* iter) : _iter(iter) {}
	~IteratorZeiger() { delete _iter; }

	Iterator<Element>* operator->() { return _iter; }
	Iterator<Element>& operator*() { return *_iter; }

private:
	// verbiete Kopieren und Zuweisen, um mehrfaches
	// Lšschen von _iter zu vermeiden:
	IteratorZeiger(const IteratorZeiger&);
	IteratorZeiger& operator=(const IteratorZeiger&);

private:
	Iterator<Element>* _iter;
};



template<class Element>
class ListenTraversierer {
public:
	ListenTraversierer(Liste<Element>* eineListe);
	bool Traversiere();

protected:
	virtual bool BearbeiteElement(const Element&) = 0;

private:
	ListenIterator<Element> _iterator;
};



template<class Element>
ListenTraversierer<Element>::ListenTraversierer(
	Liste<Element>* eineListe) :
		_iterator(eineListe)
{}

template<class Element>
bool ListenTraversierer<Element>::Traversiere() {
	bool resultat = false;

	for (_iterator.Start(); !_iterator.IstFertig(); _iterator.Weiter())
	{
		resultat = BearbeiteElement(_iterator.AktuellesElement());
		if (resultat == false) break;
	}

	return resultat;
}



class DruckeNAngestelltenObjekte : public ListenTraversierer<Angestellter*> {
public:
	DruckeNAngestelltenObjekte(
		Liste<Angestellter*>* eineListe, int gesamt) :
			ListenTraversierer<Angestellter*>(eineListe),
			_gesamt(gesamt), _anzahl(0)
{}

protected:
	bool BearbeiteElement(Angestellter* const&);

private:
	int _gesamt;
	int _anzahl;
};

bool DruckeNAngestelltenObjekte::BearbeiteElement(
	Angestellter* const& angestellter)
{
	_anzahl++;
	angestellter->Drucke();
	return _anzahl < _gesamt;
}



template<class Element>
class FilternderListenTraversierer {
public:
	FilternderListenTraversierer(Liste<Element>* eineListe);
	bool Traversiere();

protected:
	virtual bool BearbeiteElement(const Element&) = 0;
	virtual bool PruefeElement(const Element&) = 0;

private:
	ListenIterator<Element> _iterator;
};



template<class Element>
void FilternderListenTraversierer<Element>::Traversiere() {
	bool resultat = false;

	for (iterator.Start(); !iterator.IstFertig(); _iterator.Weiter())
	{
		if (PruefeElement(_iterator.AktuellesElement())) {
			resultat = BearbeiteElement(_iterator.AktuellesElement());
			if (resultat == false) break;
		}
	}

	return resultat;
}

