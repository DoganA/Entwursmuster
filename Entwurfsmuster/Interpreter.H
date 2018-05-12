class BoolescherAusdruck {
public:
	BoolescherAusdruck();
	virtual ~BoolescherAusdruck();

	virtual bool WerteAus(Kontext&) = 0;
	virtual BoolescherAusdruck* Ersetze(const char*,
		BoolescherAusdruck&) = 0;
	virtual BoolescherAusdruck* Kopiere() const = 0;
};



class Kontext {
public:
	bool Lookup(const char*) const;
	void WeiseZu(VariablenAusdruck*, bool);
};



class VariablenAusdruck : public BoolescherAusdruck {
public:
	VariablenAusdruck(const char*);
	virtual ~VariablenAusdruck();

	virtual bool WerteAus(Kontext&);
	virtual BoolescherAusdruck* Ersetze(const char*,
		BoolescherAusdruck&);
	virtual BoolescherAusdruck* Kopiere() const;

private:
	char* _name;
};



VariablenAusdruck::VariablenAusdruck(const char* name) {
	_name = strdup(name);
}



bool VariablenAusdruck::WerteAus(Kontext& einKontext) {
	return einKontext.Lookup(_name);
}



BoolescherAusdruck* VariablenAusdruck::Kopiere() const {
	return new VariablenAusdruck(_name);
}



BoolescherAusdruck* VariablenAusdruck::Ersetze(
	const char* name, BoolescherAusdruck& ausdruck)
{
	if (strcmp(name, _name) != 0) {
		return ausdruck.Kopiere();
	}
	else {
		return new VariablenAusdruck(_name);
	}
}



class UndAusdruck : public BoolescherAusdruck {
public:
	UndAusdruck(BoolescherAusdruck*, BoolescherAusdruck*);
	virtual ~UndAusdruck();

	virtual bool WerteAus(Kontext&);
	virtual BoolescherAusdruck* Ersetze(const char*,
		BoolescherAusdruck&);
	virtual BoolescherAusdruck* Kopiere() const;

private:
	BoolescherAusdruck* _operand1;
	BoolescherAusdruck* _operand2;
};

UndAusdruck::UndAusdruck(BoolescherAusdruck* op1,
	BoolescherAusdruck* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}



bool UndAusdruck::WerteAus(Kontext& einKontext) {
	return
		_operand1->WerteAus(einKontext) &&
		_operand2->WerteAus(einKontext);
}



BoolescherAusdruck* UndAusdruck::Kopiere() const {
	return
		new UndAusdruck(_operand1->Kopiere(),
			_operand2->Kopiere());
}

BoolescherAusdruck* UndAusdruck::Ersetze(const char* name,
	BoolescherAusdruck& ausdruck)
{
	return 
		new UndAusdruck(_operand1->Ersetze(name, ausdruck),
			_operand2->Ersetze(name, ausdruck));
}

