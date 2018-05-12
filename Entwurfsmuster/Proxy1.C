class Bild;
extern Bild* LadeBildDatei(const char*);
	// externe Funktion

class BildZeiger {
public:
	BildZeiger(const char* bildDatei);
	virtual ~BildZeiger();

	virtual Bild* operator->();
	virtual Bild& operator*();

private:
	Bild* LadeBild();

private:
	Bild* _bild;
	const char* _bildDatei;
};

BildZeiger::BildZeiger(const char* bildDatei) {
	_bildDatei = bildDatei;
	_bild = 0;
}

Bild* BildZeiger::LadeBild() {
	if (_bild == 0) {
		_bild = LadeBildDatei(_bildDatei);
	}
	return _bild;
}



Bild* BildZeiger::operator->() {
	return LadeBild();
}

Bild& BildZeiger::operator*() {
	return *LadeBild();
}



