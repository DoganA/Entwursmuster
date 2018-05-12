class Grafik {
public:
	virtual ~Grafik();

	virtual void Zeichne(const Punkt& position) = 0;
	virtual void BehandleMaus(Ereignis& ereignis) = 0;

	virtual const Punkt& GibAusmasse() = 0;

	virtual void Lade(istream& von) = 0;
	virtual void Speichere(ostream& auf) = 0;

protected:
	Grafik();
};



class Bild : public Grafik {
public:
	Bild(const char* datei); // laedt Bild aus Datei
	virtual ~Bild();

	virtual void Zeichne(const Punkt& position);
	virtual void BehandleMaus(Ereignis& ereignis);

	virtual const Punkt& GibAusmasse();

	virtual void Lade(istream& von);
	virtual void Speichere(ostream& auf);

private:
	// ...
};



class BildProxy : public Grafik {
public:
	BildProxy(const char* bildDatei);
	virtual ~BildProxy();

	virtual void Zeichne(const Punkt& position);
	virtual void BehandleMaus(Ereignis& ereignis);

	virtual const Punkt& GibAusmasse();

	virtual void Lade(istream& von);
	virtual void Speichere(ostream& auf);

protected:
	Bild* GibBild();

private:
	Bild* _bild;
	Punkt _ausmasse;
	char* _dateiName;
};



BildProxy::BildProxy(const char* dateiName) {
	_dateiName = strdup(dateiName);
	// Ausmasse sind noch unbekannt
	_ausmasse = Punkt::NullPunkt;
	_bild = 0;
}

Bild* BildProxy::GibBild() {
	if (_bild == 0) {
		_bild = new Bild(_dateiName);
	}
	return _bild;
}



const Punkt& BildProxy::GibAusmasse() {
	if(_ausmasse == Punkt::NullPunkt) {
		_ausmasse = GibBild()->GibAusmasse();
	}
	return _ausmasse;
}

void BildProxy::Zeichne(const Punkt& position) {
	GibBild()->Zeichne(position);
}

void BildProxy::BehandleMaus(Ereignis& ereignis) {
	GibBild()->BehandleMaus(ereignis);
}



void BildProxy::Speichere(ostream& auf) {
	auf << _ausmasse << _dateiName;
}

void BildProxy::Lade(istream& von) {
	von >> _ausmasse >> _dateiName;
}



class TextDokument {
public:
	TextDokument();

	void FuegeHinzu(Grafik*);
	// ...
};

