typedef int Thema;
const Thema KEIN_HILFE_THEMA = -1;

class HilfeBearbeiter {
public:
	HilfeBearbeiter(HilfeBearbeiter* = 0,
		Thema = KEIN_HILFE_THEMA);
	virtual bool HatHilfsinformation();
	virtual void SetzeBearbeiter(HilfeBearbeiter*, Thema);
	virtual void BearbeiteHilfsanfrage();

private:
	HilfeBearbeiter* _nachfolger;
	Thema _thema;
};

HilfeBearbeiter::HilfeBearbeiter(
	HilfeBearbeiter* nf, Thema thema ) :
		_nachfolger(nf), _thema(thema)
{}

bool HilfeBearbeiter::HatHilfsinformation() {
	return _thema != KEIN_HILFE_THEMA;
}

void HilfeBearbeiter::BearbeiteHilfsanfrage() {
	if (_nachfolger != 0) {
		_nachfolger->BearbeiteHilfsanfrage();
	}
}



class Widget : public HilfeBearbeiter {
protected:
	Widget(Widget* elternObjekt, Thema thema = KEIN_HILFE_THEMA);

private:
	Widget* _elternObjekt;
};

Widget::Widget(Widget* widget, Thema thema) :
	HilfeBearbeiter(widget, thema)
{
	_elternObjekt = widget;
}



class Knopf : public Widget {
public:
	Knopf(Widget* widget, Thema thema = KEIN_HILFE_THEMA);

	virtual void BearbeiteHilfsanfrage();
	// Widget-Operationen, welche die Knopf-Klasse überschreibt...
};



Knopf::Knopf(Widget* widget, Thema thema) : Widget(widget, thema) {}

void Knopf::BearbeiteHilfsanfrage() {
	if ( HatHilfsinformation()) {
		// biete Hilfsinformationen für den Knopf an
	}
	else {
		HilfeBearbeiter::BearbeiteHilfsanfrage();
	}
}



class Dialog : public Widget {
public:
	Dialog(HilfeBearbeiter* hb, Thema thema = KEIN_HILFE_THEMA);
	virtual void BearbeiteHilfsanfrage();

	// Widget-Operationen, die von Dialog überschrieben werden
	// ...
};

Dialog::Dialog(HilfeBearbeiter* hb, Thema thema) : Widget(0) {
	SetzeBearbeiter(hb, thema);
}

void Dialog::BearbeiteHilfsanfrage() {
	if (HatHilfsinformation()) {
		// biete Hilfsinformationen für den Dialog an
	}
	else {
		HilfeBearbeiter::BearbeiteHilfsanfrage();
	}
}



class Anwendung : public HilfeBearbeiter {
public:
	Anwendung(Thema thema) : HilfeBearbeiter(0, thema) {}

	virtual void BearbeiteHilfsanfrage();
	// anwendungsspezifische Operationen ...
};

void Anwendung::BearbeiteHilfsanfrage() {
	// zeige ein Liste von Hilfsthemen an
}
