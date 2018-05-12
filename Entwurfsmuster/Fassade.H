class Scanner {
public:
	Scanner(istream&);
	virtual ~Scanner();

	virtual Token& Scan();

private:
	istream& _eingabe;
};



class Parser {
public:
	Parser();
	virtual ~Parser();

	virtual void Parse(Scanner&, ProgrammKnotenErbauer&);
};



class ProgrammKnotenErbauer {
public:
	ProgrammKnotenErbauer();

	virtual ProgrammKnoten* NeueVariable(
		char* variablenName) const;

	virtual ProgrammKnoten* NeueZuweisung(
		ProgrammKnoten* variable, ProgrammKnoten* ausdruck) const;

	virtual ProgrammKnoten* NeueRueckkehrAnweisung(
		ProgrammKnoten* wert) const;

	virtual ProgrammKnoten* NeueBedingteAnweisung(
		ProgrammKnoten* bedingung, ProgrammKnoten* wahrZweig,
		ProgrammKnoten* falschZweig) const;

	// ...

	ProgrammKnoten* GibWurzelKnoten();

private:
	ProgrammKnoten* _knoten;
};



class ProgrammKnoten {
public:
	// Programmknoten Manipulation
	virtual void GibQuelltextPosition(int& zeile, int& index);
	// ...

	// Kindobjekt Manipulation
	virtual void FuegeHinzu(ProgrammKnoten*);
	virtual void Entferne(ProgrammKnoten*);
	// ...

	virtual void Traversiere(CodeGenerator&);

protected:
	ProgrammKnoten();
};



class CodeGenerator {
public:
	virtual void Besuche(AnweisungsKnoten*);
	virtual void Besuche(AusdrucksKnoten*);
	// ...

protected:
	CodeGenerator(BytecodeStream&);
	BytecodeStream& _ausgabe;
};



