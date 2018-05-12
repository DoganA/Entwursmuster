class Geraet {
public:
	virtual ~Geraet();

	const char* Name() { return _name; }

	virtual Watt Leistung();
	virtual Betrag GesamtPreis();
	virtual Betrag DiscountPreis();

	virtual void FuegeHinzu(Geraet*);
	virtual void Entferne(Geraet*);

	virtual Iterator<Geraet*>* ErzeugeIterator();

protected:
	Geraet(const char*);

private:
	const char* _name;
};



class FloppyDisk : public Geraet {
public:
	FloppyDisk(const char*);
	virtual ~FloppyDisk();

	virtual Watt Leistung();
	virtual Betrag GesamtPreis();
	virtual Betrag DiscountPreis();
};



class ZusammengesetztesGeraet : public Geraet {
public:
	virtual ~ZusammengesetztesGeraet();

	virtual Watt Leistung();
	virtual Betrag GesamtPreis();
	virtual Betrag DiscountPreis();

	virtual void FuegeHinzu(Geraet*);
	virtual void Entferne(Geraet*);
	virtual Iterator<Geraet*>* ErzeugeIterator();

protected:
	ZusammengesetztesGeraet(const char*);

private:
	Liste<Geraet*> _teile;
};



Betrag ZusammengesetztesGeraet::GesamtPreis() {
	Iterator<Geraet*>* iter = ErzeugeIterator();
	Betrag gesamt = 0;

	for (iter->Start(); ! iter->IstFertig(); iter->Weiter()) {
		gesamt += iter->AktuellesElement()->GesamtPreis();
	}
	delete iter;
	return gesamt;
}



class Gehaeuse : public ZusammengesetztesGeraet {
public:
	Gehaeuse(const char*);
	virtual ~Gehaeuse();

	virtual Watt Leistung();
	virtual Betrag GesamtPreis();
	virtual Betrag DiscountPreis();
};


