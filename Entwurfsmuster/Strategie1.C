class Komposition {
public:
	virtual void Repariere();

protected:
	virtual void FormatiereMitEinfacherStrategie();
	virtual void FormatiereMitTeXStrategie();

private:
	enum { EinfacheStrategie, TeXStrategie } _umbruchStrategie;
};

void Komposition::Repariere() {
	switch (_umbruchStrategie) {
	case EinfacheStrategie:
		FormatiereMitEinfacherStrategie();
		break;
	case TeXStrategie:
		FormatiereMitTeXStrategie();
		break;
	// ...
	}
	// Fuehre die Ergebnisse mit der existierenden Komposition
	// zusammen, sofern dies notwendig ist
}

//void Komposition::Repariere() {
//	_formatierer->Formatiere();
//	// Fuehre die Ergebnisse mit der existierenden Komposition
//	// zusammen, sofern dies notwendig ist
//}



template<class StrategieKlasse>
class Kontext {
public:
	void Operation() { dieStrategie.FuehreAus(); }
	// ...

private:
	StrategieKlasse dieStrategie;
};


class EineStrategie {
public:
	void FuehreAus();
};

void Strategie1Demo() {
	Kontext<EineStrategie> einKontext;
}



