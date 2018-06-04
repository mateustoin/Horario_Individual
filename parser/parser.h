#ifndef PARSER_H
#define PARSER_H

using namespace std;

struct Data{
    /*
     *  Disciplinas referentes aos identificadores
     */
    int *identificador;
    int *creditos;
    int *preRequisito;
    int **preReqI;
    bool **choqueHorarioI;
    int *situacao;
    int disciplinas;
    int numPeriodos;
    int numDisciplinasOp;
};

extern void atualizaDados (Data *data);
extern void solveCoin(Data *data);

#endif