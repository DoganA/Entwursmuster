class Subjekt;

class Beobachter {
public:
	virtual ~Beobachter();
	virtual void Aktualisiere(Subjekt* dasGeaenderteSubjekt) = 0;
protected:
	Beobachter();
};



class Subjekt {
public:
	virtual ~Subjekt();

	virtual void MeldeAn(Beobachter*);
	virtual void MeldeAb(Beobachter*);
	virtual void Benachrichtige();

protected:
	Subjekt();

private:
	Liste<Beobachter*>* _beobachter;
};

void Subjekt::MeldeAn(Beobachter* beobachter) {
	_beobachter->HaengeAn(beobachter);
}

void Subjekt::MeldeAb(Beobachter* beobachter) {
	_beobachter->Entferne(beobachter);
}

void Subjekt::Benachrichtige() {
	ListenIterator<Beobachter*> iter(_beobachter);

	for (iter.Start(); !iter.IstFertig(); iter.Weiter()) {
		iter.AktuellesElement()->Aktualisiere(this);
	}
}



class ZeitGeber : public Subjekt {
public:
	ZeitGeber();

	virtual int GibStunde();
	virtual int GibMinute();
	virtual int GibSekunde();

	void Tick();
};



void ZeitGeber::Tick() {
	// aktualisiere den internen Zustand
	// ...
	Benachrichtige();
}



class DigitalUhr : public Widget, public Beobachter {
public:
	DigitalUhr(ZeitGeber*);
	virtual ~DigitalUhr();

	virtual void Aktualisiere(Subjekt*);
		// Ÿberschreibt Operation der Beobachterklasse

	virtual void Zeichne();
		// Ÿberschreibt Operation der Widgetklasse
		// definiert, wie die Digitaluhr gezeichnet wird

private:
	ZeitGeber* _subjekt;
};

DigitalUhr::DigitalUhr(ZeitGeber* subjekt) {
	_subjekt = subjekt;
	_subjekt->MeldeAn(this);
}

DigitalUhr::~DigitalUhr() {
	_subjekt->MeldeAb(this);
}



void DigitalUhr::Aktualisiere(Subjekt* dasGeaenderteSubjekt) {
	if (dasGeaenderteSubjekt == _subjekt) {
		Zeichne();
	}
}

void DigitalUhr::Zeichne() {
	// holt die neuen Werte vom Subjekt

	int stunde = _subjekt->GibStunde();
	int minute = _subjekt->GibMinute();
	// usw.

	// zeichne die Digitaluhr
}



class AnalogUhr : public Widget, public Beobachter {
public:
	AnalogUhr(ZeitGeber*);
	virtual void Aktualisiere(Subjekt*);
	virtual void Zeichne();
	// ...
};

