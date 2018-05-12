class Glyph {
public:
	virtual ~Glyph();

	virtual void Zeichne(Fenster*, GlyphKontext&);

	virtual void SetzeZeichensatz(Zeichensatz*, GlyphKontext&);
	virtual Zeichensatz* GibZeichensatz(GlyphKontext&);

	virtual void Start(GlyphKontext&);
	virtual void Weiter(GlyphKontext&);
	virtual void IstFertig(GlyphKontext&);
	virtual void AktuellesElement(GlyphKontext&);

	virtual void FuegeHinzu(Glyph*, GlyphKontext&);
	virtual void Entferne(GlyphKontext&);

protected:
	Glyph();
};



class Zeichen : public Glyph {
public:
	Zeichen(char);

	virtual void Zeichne(Fenster*, GlyphKontext&);

private:
	char _zeichencode;
};



class GlyphKontext {
public:
	GlyphKontext();
	virtual ~GlyphKontext();

	virtual void Weiter(int schrittweite = 1);
	virtual void FuegeHinzu(int anzahl = 1);

	virtual Zeichensatz* GibZeichensatz();
	virtual void SetzeZeichensatz(Zeichensatz*, int umfang);

private:
	int _index;
	BBaum* _zeichensaetze;
};



const int AnzahlZeichenCodes = 128;

class GlyphFabrik {
public:
	GlyphFabrik();
	virtual ~GlyphFabrik();

	virtual Zeichen* ErzeugeZeichen(char);
	virtual Zeile* ErzeugeZeile();
	virtual Spalte* ErzeugeSpalte();
	// ...

private:
	Zeichen* _zeichen[AnzahlZeichenCodes];
};

GlyphFabrik::GlyphFabrik() {
	for (int i = 0; i < AnzahlZeichenCodes; ++i) {
		_zeichen[i] = 0;
	}
}

Zeichen* GlyphFabrik::ErzeugeZeichen(char c) {
	if (!_zeichen[c]) {
		_zeichen[c] = new Zeichen(c);
	}
	return _zeichen[c];
}

Zeile* GlyphFabrik::ErzeugeZeile() {
	return new Zeile;
}

Spalte* GlyphFabrik::ErzeugeSpalte() {
	return new Spalte;
}


