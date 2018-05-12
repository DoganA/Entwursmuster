// Sorry, uebersetzt nicht. Waere zuviel Arbeit gewesen,
// das vernuenftig abzurunden und einzubetten.

void Rechteck::Zeichne(Fenster* fenster) {
	fenster->ZeichneRechteck(_x0, _y0, _x1, _y1);
}

void MonoGlyph::Zeichne(Fenster* fenster) {
	_komponente->Zeichne(fenster);
}

void Rahmen::Zeichne(Fenster* fenster) {
	MonoGlyph::Zeichne(fenster);
	ZeichneRahmen(fenster);
}

Scrollbar* scrollbar = new MotifScrollbar;

Scrollbar* scrollbar = guiFabrik->ErzeugeScrollbar();

GUIFabrik* guiFabrik = new MotifFabrik;

GUIFabrik* guiFabrik;
const char* stilName = getenv("LOOK_AND_FEEL");
// Benutzer oder Umgebung liefert dies beim Hochfahren

if (strcmp(stilName, "Motif") == 0) {
	guiFabrik = new MotifFabrik;
}
else if (strcmp(stilName, "Presentation_Manager") == 0) {
	guiFabrik = new PMFabrik;
}
else {
	guiFabrik = new DefaultGUIFabrik;
}

void Rechteck::Zeichne(Fenster* fenster) {
	fenster->ZeichneRechteck(_x0, _y0, _x1, _y1);
}

void Fenster::ZeichneRechteck(Koordinate x0, Koordinate y0,
	Koordinate x1, Koordinate y1)
{
	_imp->GeraetRechteck(x0, y0, x1, y1);
}

void XWindowImp::GeraetRechteck(Koordinate x0, Koordinate y0,
	Koordinate x1, Koordinate y1)
{
	int x = round(min(x0, x1));
	int y = round(min(y0, y1));
	int b = round(abs(x0 - x1));
	int h = round(abs(y0 - y1));
	XDrawRectangle(_dpy, _winid, _gc, x, y, b, h);
}

void PMFensterImp::GeraetRechteck(Koordinate x0, Koordinate y0,
	Koordinate x1, Koordinate y1)
{
	Koordinate links = min(x0, x1);
	Koordinate rechts = max(x0, x1);
	Koordinate unten = min(y0, y1);
	Koordinate oben = max(y0, y1);

	PPOINTL punkt[4];

	punkt[0].x = links;	punkt[0].y = oben;
	punkt[1].x = rechts;	punkt[1].y = oben;
	punkt[2].x = rechts;	punkt[2].y = unten;
	punkt[3].x = links;	punkt[3].y = unten;

	if ((GpiBeginPath(_hps, 1L) == false) ||
		(GpiSetCurrentPosition(_hps, &punkt[3] == false) ||
		(GpiPolyLine(_hps, 4L, punkt) == GPI_ERROR) ||
		(GpiEndPath(_hps) == false))
	{
		// Fehlermeldung
	}
	else
	{
		GpiStrokePath(_hps, 1L, 0L);
	}
}

class FenstersystemFabrik {
public:
	virtual FensterImp* ErzeugeFensterImp() = 0;
	virtual FarbeImp* ErzeugeFarbeImp() = 0;
	virtual ZeichensatzImp* ErzeugeZeichensatzImp() = 0;

	// jeweils eine Erzeuge... Operation
	// fuer die Fenstersystem-Ressourcen
};

class PMFenstersystemFabrik : public FenstersystemFabrik {
	virtual FensterImp* ErzeugeFensterImp()
		{ return new PMFensterImp; }
	// ...
};

class XFenstersystemFabrik : public FenstersystemFabrik {
	virtual FensterImp* ErzeugeFensterImp()
		{ return new XFensterImp; }
	// ...
};

Fenster::Fenster() {
	_imp = fenstersystemFabrik->ErzeugeFensterImp();
}

void Start(Traversierung art)
void Weiter()
bool IstFertig()
Glyph* AktuellesElement()
void FuegeEin(Glyph*)

Glyph* glyph;

for (glyph->Start(PREORDER); !glyph->IstFertig(); glyph->Weiter()) {
	Glyph* aktuellesElement = glyph->AktuellesElement();

	// irgendeine Analyse
}

Glyph* glyph;
Iterator<Glyph*>* iter = glyph->ErzeugeIterator();

for (iter->Start(PREORDER); !iter->IstFertig(); iter->Weiter()) {
	Glyph* aktuellesElement = iter->AktuellesElement();

	// mach irgend etwas mit dem aktuellen Kindobjekt
}

Iterator<Glyph*>* Zeile::ErzeugeIterator() {
	return new ListenIterator<Glyph*>(_kindobjekte);
}

void PreorderIterator::Start() {
	Iterator<Glyph*>* iter = _wurzel->ErzeugeIterator();

	if (iter != 0) {
		iter->Start();
		_iteratorStack.EntferneAlle();
		_iteratorStack.Push(iter);
	}
}

Glyph* PreorderIterator::AktuellesElement() const {
	Glyph* glyph = 0;

	if (_iteratorStack.Groesse() > 0) {
		glyph = _iteratorStack.Top()->AktuellesElement();
	}
	return glyph;
}

void PreorderIterator::Weiter() {
	Iterator<Glyph*>* iter =
		_iteratorStack.Top()->AktuellesElement()->ErzeugeIterator();
	iter->Start();

	while (_iteratorStack.Groesse() > 0 &&
		_iteratorStack.Top()->IstFertig())
	{
		delete _iteratorStack.Pop();
		_iteratorStack.Top()->Weiter();
	}
}

void RechtschreibPruefer::Pruefe(Glyph* glyph) {
	Zeichen* zeichen;
	Zeile* zeile;
	Bild* bild;

	if (zeichen = dynamic_cast<Zeichen*>(glyph)) {
		// analysiere das Zeichen
	}
	else if (zeile = dynamic_cast<Zeile*>(glyph)) {
		// bereite Analyse der Kindobjekte von zeile vor
	}
	else if (bild = dynamic_cast<Bild*>(glyph)) {
		// nichts zu tun
	}
}

void Pruefe(RechtschreibPruefer&)

void GlyphUnterklasse::Pruefe(RechtschreibPruefer& pruefer) {
	pruefer.PruefeGlyphUnterklasse(this);
}

class RechtschreibPruefer {
public:
	RechtschreibPruefer();

	virtual void PruefeZeichen(Zeichen*);
	virtual void PruefeZeile(Zeile*);
	virtual void PruefeBild(Bild*);

	// ... und so weiter

	Liste<char*>& GibSchreibfehler();

protected:
	virtual bool IstFalschGeschrieben(const char*);

private:
	char _aktuellesWort[MAX_WORD_SIZE];
	Liste<char*> _schreibfehler;
};

void RechtschreibPruefer::PruefeZeichen(Zeichen* zeichen) {
	const char ch = zeichen->GibCharCode();

	if (isalpha(ch)) {
		// haengt alphabetische Zeichen an _aktuellesWort an
	}
	else {
		// es liegt ein nicht-alphabetisches Zeichen vor

		if (IstFalschGeschrieben(_aktuellesWort)) {
			// fuege _aktuellesWort in _schreibFehler ein
			_schreibFehler.HaengeAn(strdup(_aktuellesWort));
		}

		_aktuellesWort[0] = '\0';
			// setze _aktuellesWort zurueck
	}
}

RechtschreibPruefer schreibPruefer;
Komposition* komposition;

// ...

Glyph* glyph;
PreorderIterator iter(glyph);

for (iter.Start(); !iter.IstFertig(); iter.Weiter()) {
	glyph = iter.AktuellesElement();
	glyph->Pruefe(schreibPruefer);
}

class Besucher {
public:
	virtual void BesucheZeichen(Zeichen*) {}
	virtual void BesucheZeile(Zeile*) {}
	virtual void BesucheBild(Bild*) {}

	// und so weiter
};



