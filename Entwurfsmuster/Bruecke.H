class Fenster {
public:
	Fenster(Anzeige* inhalt);

	// vom Fenster bearbeitete Anfragen
	virtual void ZeichneInhalt();

	virtual void Oeffne();
	virtual void Schliesse();
	virtual void ZumIcon();
	virtual void ZumFenster();

	// an die Implementierung weitergeleitete Anfragen
	virtual void SetzeUrsprung(const Punkt& ursprung);
	virtual void SetzeAusmasse(const Punkt& ausmasse);
	virtual void NachVorne();
	virtual void NachHinten();

	virtual void ZeichneLinie(const Punkt&, const Punkt&);
	virtual void ZeichneRechteck(const Punkt&, const Punkt&);
	virtual void ZeichnePolygon(const Punkt[], int n);
	virtual void ZeichneText(const char*, const Punkt&);

protected:
	FensterImp* GibFensterImp();
	Anzeige* GibAnzeige();

private:
	FensterImp* _imp;
	Anzeige* _inhalt;
};



class FensterImp {
public:
	virtual void ImpOben() = 0;
	virtual void ImpUnten() = 0;
	virtual void ImpSetzeAusmasse(const Punkt&) = 0;
	virtual void ImpSetzeUrsprung(const Punkt&) = 0;

	virtual void GeraetRechteck(Koordinate, Koordinate,
		Koordinate, Koordinate) = 0;
	virtual void GeraetText(const char*,
		Koordinate, Koordinate) = 0;
	virtual void GeraetBitmap(const char*,
		Koordinate, Koordinate) = 0;
	// und noch viel mehr Funktionen zum Zeichnen auf Fenstern

protected:
	FensterImp();
};



class AnwendungsFenster : public Fenster {
public:
	// ...
	virtual void ZeichneInhalt();
};

void AnwendungsFenster::ZeichneInhalt() {
	GibAnzeige()->ZeichneAuf(this);
}



class IconFenster : public Fenster {
public:
	// ...
	virtual void ZeichneInhalt();

private:
	const char* _bitmapName;
};



void IconFenster::ZeichneInhalt() {
	FensterImp* imp = GibFensterImp();
	if (imp != 0) {
		imp->GeraetBitmap(_bitmapName, 0.0, 0.0);
	}
}



void Fenster::ZeichneRechteck(const Punkt& p1, const Punkt& p2) {
	FensterImp* imp = GibFensterImp();
	imp->GeraetRechteck(p1.X(), p1.Y(), p2.X(), p2.Y());
}



class XFensterImp : public FensterImp {
public:
	XFensterImp();

	virtual void GeraetRechteck(Koordinate, Koordinate,
		Koordinate, Koordinate);
	// der Rest der oeffentlichen Schnittstelle...

private:
	// eine ganze Menge X-Window-System spezifischen Zustands
	// zum Beispiel
	Display* _dpy;
	Drawable _winid;
	GC _gc;
	// usw.
};



class PMFensterImp : public FensterImp {
public:
	PMFensterImp();
	virtual void GeraetRechteck(Koordinate, Koordinate,
		Koordinate, Koordinate);

	// der Rest der oeffentlichen Schnittstelle...

private:
	// eine ganze Menge PM-Fenster spezifischen Zustands,
	// zum Beispiel:
	HPS _hps;
};



void XFensterImp::GeraetRechteck(Koordinate x0, Koordinate y0,
	Koordinate x1, Koordinate y1)
{
	int x = round(min(x0, x1));
	int y = round(min(y0, y1));
	int w = round(abs(x0 - x1));
	int h = round(abs(y0 - y1));
	XDrawRectangle(_dpy, _winid, _gc, x, y, w, h);
}



void PMFensterImp::GeraetRechteck(Koordinate x0, Koordinate y0,
	Koordinate x1, Koordinate y1)
{
	Koordinate links = min(x0, x1);
	Koordinate rechts = max(x0, x1);
	Koordinate unten = min(y0, y1);
	Koordinate oben = max(y0, y1);

	PPOINTL punkt[4];

	punkt[0].x = links; punkt[0].y = oben;
	punkt[1].x = rechts; punkt[1].y = oben;
	punkt[2].x = rechts; punkt[2].y = unten;
	punkt[3].x = links; punkt[3].y = unten;

	if ((GpiBeginPath(_hps,1L) == false) ||
		(GpiSetCurrentPosition(_hps, &punkt[3]) == false) ||
		(GpiPolyLine(_hps, 4L, punkt) == GPI_ERROR) ||
		(GpiEndPath(_hps) == false))
	{
		// Fehler berichten
	}
	else
	{
		GpiStrokePath(_hps, 1L, 0L);
	}
}



FensterImp* Fenster::GibFensterImp() {
	if (_imp == 0) {
		_imp = FensterSystemFabrik::GibExemplar()->ErzeugeFensterImp();
	}
	return _imp;
}


