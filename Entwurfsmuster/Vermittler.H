class DialogDirektor {
public:
	virtual ~DialogDirektor();

	virtual void ZeigeDialog();
	virtual void WidgetGeaendert(Widget*) = 0;

protected:
	DialogDirektor();
	virtual void ErzeugeWidgets() = 0;
};



class Widget {
public:
	Widget(DialogDirektor*);
	virtual void Geaendert();

	virtual void BehandleMaus(MausEreignis& ereignis);
	// ...
private:
	DialogDirektor* _direktor;
};



void Widget::Geaendert() {
	_direktor->WidgetGeaendert(this);
}



class ListBox : public Widget {
public:
	ListBox(DialogDirektor*);

	virtual const char* GibAuswahl();
	virtual void SetzeListe(Liste<char*>* listenElemente);
	virtual void BehandleMaus(MausEreignis& ereignis);
	// ...
};

class EingabeFeld : public Widget {
public:
	EingabeFeld(DialogDirektor*);

	virtual void SetzeText(const char* text);
	virtual const char* GibText();
	virtual void BehandleMaus(MausEreignis& ereignis);
	// ...
};



class Knopf : public Widget {
public:
	Knopf(DialogDirektor*);

	virtual void SetzeText(const char* text);
	virtual void BehandleMaus(MausEreignis& ereignis);
	// ...
};

void Knopf::BehandleMaus(MausEreignis& ereignis) {
	// ...
	Geaendert();
}



class ZeichensatzDialogDirektor : public DialogDirektor {
public:
	ZeichensatzDialogDirektor();
	virtual ~ZeichensatzDialogDirektor();
	virtual void WidgetGeaendert(Widget*);

protected:
	virtual void ErzeugeWidgets();

private:
	Knopf* _ok;
	Knopf* _cancel;
	ListBox* _zeichensatzListe;
	EingabeFeld* _zeichensatzName;
};



void ZeichensatzDialogDirektor::ErzeugeWidgets() {
	_ok = new Knopf(this);
	_cancel = new Knopf(this);
	_zeichensatzListe = new ListBox(this);
	_zeichensatzName = new EingabeFeld(this);

	// faelle die Listbox mit den vorhandenen Zeichensatznamen

	// fuege die Widgets zum Dialog zusammen
}



void ZeichensatzDialogDirektor::WidgetGeaendert(
	Widget* geaendertesWidget)
{
	if (geaendertesWidget == _zeichensatzListe) {
		_zeichensatzName->SetzeText(_zeichensatzListe->GibAuswahl());
	}
	else
	if (geaendertesWidget == _ok) {
		// fuehre Zeichensatzaenderung durch und beende den Dialog
	}
	else
	if (geaendertesWidget == _cancel) {
		// beende den Dialog
	}
}


