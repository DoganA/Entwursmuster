template<class Element>
class Liste {
public:
	Liste(long groesse = DEFAULT_LISTEN_KAPAZITAET);
	Liste(Liste&);
	~Liste();
	Liste& operator=(const Liste&);

	long Anzahl() const;
	Element& Get(long index) const;
	Element& Erstes() const;
	Element& Letztes() const;
	bool Enthaelt(const Element&) const;

	void HaengeAn(const Element&);
	void FuegeVorneAn(const Element&);

	void Entferne(const Element&);
	void EntferneLetztes();
	void EntferneErstes();
	void EntferneAlle();

	Element& Top() const;
	Element& Push(const Element&);
	Element& Pop();
};


