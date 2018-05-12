class Form {
public:
	Form();
	virtual void BegrenzungsRahmen(
		Punkt& untenLinks, Punkt& obenRechts) const;
	virtual Manipulator* ErzeugeManipulator() const;
};



class TextAnzeige {
public:
	TextAnzeige();
	void GibUrsprung(Koordinate& x, Koordinate& y) const;
	void GibAusmasse(Koordinate& breite, Koordinate& hoehe) const;
	virtual bool IstLeer() const;
};



class TextForm : public Form {
public:
	TextForm(TextAnzeige*);

	virtual void BegrenzungsRahmen(
		Punkt& untenLinks, Punkt& obenRechts) const;
	virtual bool IstLeer() const;
	virtual Manipulator* ErzeugeManipulator() const;

private:
	TextAnzeige* _text;
};

TextForm::TextForm(TextAnzeige* t) {
	_text = t;
}

void TextForm::BegrenzungsRahmen(
	Punkt& untenLinks, Punkt& obenRechts) const
{
	Koordinate unten, links, breite, hoehe;

	_text->GibUrsprung(unten, links);
	_text->GibAusmasse(breite, hoehe);

	untenLinks = Punkt(unten, links);
	obenRechts = Punkt(unten + hoehe, links + breite);
}

bool TextForm::IstLeer() const {
	return _text->IstLeer();
}

Manipulator* TextForm::ErzeugeManipulator() const {
	return new TextManipulator(this);
}


