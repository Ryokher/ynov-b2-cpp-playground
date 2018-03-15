#ifndef TYPE
#define TYPE

enum typeCartes { AM, TM, LM, AF, TF };
struct Cartes{
    char lesCases[3][3];
    typeCartes leType;
    unsigned int angleRotation;
};
const char MUR=176, ESP=32, MUF=178;
const Cartes ANGLE ={{{MUR,MUR,MUR},{MUR,ESP,ESP},{MUR,ESP,MUR}},AM,0};
const Cartes TE    ={{{MUR,MUR,MUR},{ESP,ESP,ESP},{MUR,ESP,MUR}},TM,0};
const Cartes LIGNE ={{{MUR,MUR,MUR},{ESP,ESP,ESP},{MUR,MUR,MUR}},LM,0};
const Cartes ANGLEF={{{MUF,MUF,MUF},{MUF,ESP,ESP},{MUF,ESP,MUF}},AF,0};
const Cartes TEF   ={{{MUF,MUF,MUF},{ESP,ESP,ESP},{MUF,ESP,MUF}},TF,0};

#endif // TYPE
