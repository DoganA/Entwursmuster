typedef int ProduktId;
const int MEINS = 1;
const int DEINS = 2;
const int IHRS = 3;

class Produkt {};
class MeinProdukt : public Produkt {};
class DeinProdukt : public Produkt {};
class IhrProdukt : public Produkt {};

class Erzeuger1 {
public:
	virtual Produkt* Erzeuge(ProduktId);
};

Produkt* Erzeuger1::Erzeuge(ProduktId id) {
	if (id == MEINS) return new MeinProdukt;
	if (id == DEINS) return new DeinProdukt;
	// Wiederholung fuer verbleibende Produkte...

	return 0;
}



class MeinErzeuger1 : public Erzeuger1 {
public:
	virtual Produkt* Erzeuge(ProduktId);
};

Produkt* MeinErzeuger1::Erzeuge(ProduktId id) {
	if (id == DEINS) return new MeinProdukt;
	if (id == MEINS) return new DeinProdukt;
	// Die Produkte wurden vertauscht

	if (id == IHRS) return new IhrProdukt;

	return Erzeuger1::Erzeuge(id);
	// wird aufgerufen, wenn alles andere fehlschlaegt
}

class Erzeuger2 {
public:
	Produkt* GibProdukt();

protected:
	virtual Produkt* ErzeugeProdukt();

private:
	Produkt* _produkt;
};

Produkt* Erzeuger2::GibProdukt() {
	if (_produkt == 0) {
		_produkt = ErzeugeProdukt();
	}
	return _produkt;
}



class Erzeuger3 {
public:
	virtual Produkt* ErzeugeProdukt() = 0;
};

template<class DasProdukt>
class StandardErzeuger : public Erzeuger {
public:
	virtual Produkt* ErzeugeProdukt();
};

template<class DasProdukt>
Produkt* StandardErzeuger<DasProdukt>::ErzeugeProdukt() {
	return new DasProdukt;
}

//class MeinProdukt : public Produkt {
//public:
//	MeinProdukt();
//	// ...
//};
//
//StandardErzeuger<MeinProdukt> meinProdukt;

