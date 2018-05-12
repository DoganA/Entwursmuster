class LabyrinthFabrik {
public:
	static LabyrinthFabrik* Exemplar();

	// existierende Schnittstelle folgt hier
	// ...

protected:
	LabyrinthFabrik();

private:
	static LabyrinthFabrik* _exemplar;
};

LabyrinthFabrik* LabyrinthFabrik::_exemplar = 0;

//LabyrinthFabrik* LabyrinthFabrik::Exemplar() {
//	if (_exemplar == 0) {
//		_exemplar = new LabyrinthFabrik;
//	}
//	return _exemplar;
//}

LabyrinthFabrik* LabyrinthFabrik::Exemplar() {
	if (_exemplar == 0) {
		const char* labyrinthStil = getenv("LABYRINTHSTIL");

		if (strcmp(labyrinthStil, "bombardierbar") == 0) {
//			_exemplar = new LabyrinthMitBombenFabrik;
		}
		else if (strcmp(labyrinthStil, "verzaubert") == 0) {
//			_exemplar = new VerzaubertesLabyrinthFabrik;
		}
			// ... weitere moegliche Unterklassen
		else {
			_exemplar = new LabyrinthFabrik;
		}
	}
	return _exemplar;
}



