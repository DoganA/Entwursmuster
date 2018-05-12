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



class TextForm : public Form, private TextAnzeige {
public:
	TextForm();

	virtual void BegrenzungsRahmen(
		Punkt& untenLinks, Punkt& obenRechts) const;
	virtual bool IstLeer() const;
	virtual Manipulator* ErzeugeManipulator() const;
};



void TextForm::BegrenzungsRahmen(
		Punkt& untenLinks, Punkt& obenRechts) const
{
	Koordinate unten, links, breite, hoehe;

	GibUrsprung(unten, links);
	GibAusmasse(breite, hoehe);

	untenLinks = Punkt(unten, links);
	obenRechts = Punkt(unten + hoehe, links + breite);
}



bool TextForm::IstLeer() const {
	return TextAnzeige::IstLeer();
}



Manipulator* TextForm::ErzeugeManipulator() const {
	return new TextManipulator(this);
}

