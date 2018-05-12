#include "GrundKlassen/GrundKlassen.H"

class Token;
class ProgrammKnotenErbauer;
class ProgrammKnoten;
class AnweisungsKnoten;
class AusdrucksKnoten;
class CodeGenerator;
class RISCCodeGenerator;
class BytecodeStream;



#include "Fassade.H"



class AusdrucksKnoten : public ProgrammKnoten {
public:
	void Traversiere(CodeGenerator&);
	
private:
	Liste<ProgrammKnoten*>* _kindObjekte;
};

class RISCCodeGenerator : public CodeGenerator {
public:
	RISCCodeGenerator(BytecodeStream&);
};




void AusdrucksKnoten::Traversiere(CodeGenerator& codeGen) {
	codeGen.Besuche(this);

	ListenIterator<ProgrammKnoten*> iter(_kindObjekte);

	for (iter.Start(); ! iter.IstFertig(); iter.Weiter()) {
		iter.AktuellesElement()->Traversiere(codeGen);
	}
}

class Uebersetzer {
public:
	Uebersetzer();

	virtual void Uebersetze(istream&, BytecodeStream&);
};

void Uebersetzer::Uebersetze(istream& eingabe,
	BytecodeStream& ausgabe)
{
	Scanner scanner(eingabe);
	ProgrammKnotenErbauer erbauer;
	Parser parser;

	parser.Parse(scanner, erbauer);

	RISCCodeGenerator generator(ausgabe);
	ProgrammKnoten* parseBaum = erbauer.GibWurzelKnoten();
	parseBaum->Traversiere(generator);
}

