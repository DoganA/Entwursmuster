class Geraet {
public:
	virtual ~Geraet();

	const char* Name() { return _name; }

	virtual Watt Leistung();
	virtual Betrag NettoPreis();
	virtual Betrag DiscountPreis();

	virtual void NimmEntgegen(GeraetBesucher&);

protected:
	Geraet(const char*);

private:
	const char* _name;
};


// nachtraeglich eingefuehrt D.R.
class FloppyDisk : public Geraet {
public:
	virtual void NimmEntgegen(GeraetBesucher&);
};


// nachtraeglich eingefuehrt, muesste eigentlich von 
// ZusammengesetzesGeraet erben. D.R.
class Gehaeuse : public Geraet {
public:
	virtual void NimmEntgegen(GeraetBesucher&);

protected:
	Liste<Geraet*> _teile;
};



class GeraetBesucher {
public:
	virtual ~GeraetBesucher();

	virtual void BesucheFloppyDisk(FloppyDisk*);
	virtual void BesucheKarte(Karte*);
	virtual void BesucheGehaeuse(Gehaeuse*);
	virtual void BesucheBus(Bus*);
	// und so weiter fuer andere konkrete Unterklassen von Geraet

protected:
	GeraetBesucher();
};



void FloppyDisk::NimmEntgegen(GeraetBesucher& besucher) {
	besucher.BesucheFloppyDisk(this);
}



void Gehaeuse::NimmEntgegen(GeraetBesucher& besucher) {
	for(ListenIterator<Geraet*> iter(&_teile); !iter.IstFertig(); iter.Weiter()) {
		iter.AktuellesElement()->NimmEntgegen(besucher);
	}
	besucher.BesucheGehaeuse(this);
}



class PreisBerechnungsBesucher : public GeraetBesucher {
public:
	PreisBerechnungsBesucher();

	Betrag& GibGesamtPreis();

	virtual void BesucheFloppyDisk(FloppyDisk*);
	virtual void BesucheKarte(Karte*);
	virtual void BesucheGehaeuse(Gehaeuse*);
	virtual void BesucheBus(Bus*);
	// ...

private:
	Betrag _gesamt;
};

void PreisBerechnungsBesucher::BesucheFloppyDisk(FloppyDisk* element) {
	_gesamt += element->NettoPreis();
}

void PreisBerechnungsBesucher::BesucheGehaeuse(Gehaeuse* element) {
	_gesamt += element->DiscountPreis();
}



class StuecklistenBesucher : public GeraetBesucher {
public:
	StuecklistenBesucher();

	Stueckliste& GibStueckliste();

	virtual void BesucheFloppyDisk(FloppyDisk*);
	virtual void BesucheKarte(Karte*);
	virtual void BesucheGehaeuse(Gehaeuse*);
	virtual void BesucheBus(Bus*);
	// ...

private:
	Stueckliste _stueckliste;
};

void StuecklistenBesucher::BesucheFloppyDisk(FloppyDisk* element) {
	_stueckliste.FuegeHinzu(element);
}

void StuecklistenBesucher::BesucheGehaeuse(Gehaeuse* element) {
	_stueckliste.FuegeHinzu(element);
}


