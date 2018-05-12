struct Display;
typedef unsigned int Drawable;
typedef struct XXX { int y; }  *GC;
extern XDrawRectangle(
    Display*,
    Drawable,
    GC,
    int,
    int,
    unsigned int,
    unsigned int
);

typedef Koordinate Coord;
Coord min(Coord, Coord);
Coord max(Coord, Coord);
Coord abs(Coord);
int round(Coord);

struct PPOINTL {
    Coord x;
    Coord y;
};
const int GPI_ERROR = 1;

typedef int HPS;
int GpiBeginPath(HPS, unsigned long);
int GpiSetCurrentPosition(HPS, PPOINTL*);
int GpiPolyLine(HPS, unsigned long, PPOINTL*);
int GpiEndPath(HPS);
void ReportError();
void GpiStrokePath(HPS, unsigned long, unsigned long);
