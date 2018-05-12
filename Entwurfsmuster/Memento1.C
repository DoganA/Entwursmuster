class Zustand;
class Memento;

class Urheber {
public:
	Memento* ErzeugeMemento();
	void SetzeMemento(const Memento*);
	// ...

private:
	Zustand* _zustand; // interne Datenstrukturen
	// ...
};

class Memento {
public:
	// schmale oeffentliche Schnittstelle
	virtual ~Memento();

private:
	// private Member-Variablen sind nur dem Urheber zugaenglich
	friend class Urheber;
	Memento();

	void SetzeZustand(Zustand*);
	Zustand* GibZustand();
	// ...

private:
	Zustand* _zustand;
	// ...
};


