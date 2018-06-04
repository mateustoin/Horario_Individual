#include "parser.h"

void atualizaDados(Data* data){
    ifstream arquivoAluno("instancia.json", ios::in); // Abre instância com dados do aluno
    ifstream arquivoHorario("horario.txt", ios::in); // Abre instância com horários das disciplinas
    string horario1;
    
    json j;
    arquivoAluno >> j; // Transfere informações da instância para objeto do json
    
    int discUteis = -1;
    while (horario1 != "end"){ //Loop que identifica quantidade de disciplinas úteis
        arquivoHorario >> horario1; //Transfere informações dos horários para objeto do json
        if (horario1 == "0"){
            continue;
        }    
        ++discUteis;
    }
    arquivoHorario.close();

    //Fazendo segunda parte
    string horario[discUteis]; //Variável que armazena todos os horários
    ifstream arquivoHorario2("horario.txt", ios::in); // Abre instância com horários das disciplinas
    string horario2;
    int *identificador = new int[discUteis];
    int k = 0, temp = 0;
    while (horario2 != "end"){ //Loop que identifica quantidade de disciplinas úteis
        arquivoHorario2 >> horario2;
        
        if (horario2 != "0" && horario2 != "end"){
            identificador[k] = temp;
            horario[k] = horario2; //Armazena horarios p/ criação da matriz choque de horario
            k++;
        }
        temp++;
    }

    //Iterando json e armazenando Qnt. de créditos de cada cadeira
    int *credito = new int[discUteis];
    for (json::iterator it = j["cargaHoraria"].begin(); it != j["cargaHoraria"].end(); ++it) {
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os que tem horário
        int retorno = 0, iTemp = 0;
        while (iTemp < discUteis){
            if (identificador[iTemp] == i){
                retorno = 1;
                break;
            }
            iTemp++;
        }
        if (retorno == 1){
            credito[iTemp] = it.value();
            credito[iTemp] /= 15;
        }
    }

    //Iterando json e armazenando situacao (concluido = 1 ou pendente = 0)
    int *situacao = new int[discUteis];
    for (int i = 0; i < discUteis; i++){
        situacao[i] = 1;
    }
    for (json::iterator it = j["situacao"].begin(); it != j["situacao"].end(); ++it) {
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os que tem horário
        int retorno = 0, iTemp = 0;
        while (iTemp < discUteis){
            if (identificador[iTemp] == i){
                retorno = 1;
                break;
            }
            iTemp++;
        }

        if ((retorno == 1) && (it.value() != "CONCLUIDO")){
            situacao[iTemp] = 0;
        }
    }

    //CRIA E PREENCHE MATRIZ DE CHOQUE DE HORÁRIOS
    bool choqueHorario[discUteis][discUteis]; //Armazena se tem choque de horario ou não
    for (int i = 0; i < discUteis; i++){
        for (int j = 0; j < discUteis; j++){
            if (horario[i] == horario[j])
                choqueHorario[i][j] = true;
            else
                choqueHorario[i][j] = false;
        }
    }

    //CRIA E PREENCHE MATRIZ DE PRE REQUISITOS
    int preReqI[discUteis][discUteis];//Matriz de pre requisitos
    for (int i = 0; i < discUteis; i++){
        for (int j = 0; j < discUteis; j++){
            preReqI[i][j] = 0;
        }
    }
    string preRequisito[discUteis]; //Lista de pre requsitos
    for (json::iterator it = j["expressaoPreRequisito"].begin(); it != j["expressaoPreRequisito"].end(); ++it){
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os pre requisitos
        int retorno = 0, iTemp = 0;
        while (iTemp < discUteis){
            if (identificador[iTemp] == i){
                retorno = 1;
                break;
            }
            iTemp++;
        }

        //Passa para proxima iteração caso seja null
        if (it.value() == nullptr){ 
            preRequisito[iTemp] = "0";
            continue;
        }

        //Depois que encontrou pre requisito, armazena na string
        if (retorno == 1){
            preRequisito[iTemp] = it.value();
        }
    }
    
    //TRATA STRING PRE REQUISITO PARA ITERAR EM CODIGO
    for (int i = 0; i < discUteis; i++){
        if (preRequisito[i].size() == 1) //Se for null retorna 1
            continue;

        if (preRequisito[i].size() == 12){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-10);
            preRequisito[i].erase(preRequisito[i].end()-3, preRequisito[i].end());
        }

        if (preRequisito[i].size() == 14){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-12);
            preRequisito[i].erase(preRequisito[i].end()-3, preRequisito[i].end());
        }

        if (preRequisito[i].size() == 26){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-22);
            preRequisito[i].erase(preRequisito[i].end()-15, preRequisito[i].end());
        }

        if (preRequisito[i].size() == 28){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-24);
            preRequisito[i].erase(preRequisito[i].end()-17, preRequisito[i].end());
        }

        if (preRequisito[i].size() == 30){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-26);
            preRequisito[i].erase(preRequisito[i].end()-17, preRequisito[i].end());
        }

        if (preRequisito[i].size() == 36){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-34);
            preRequisito[i].erase(preRequisito[i].end()-27, preRequisito[i].end());
        }

        if (preRequisito[i].size() == 42){ //Apaga inicio e fim para filtrar código
            preRequisito[i].erase(preRequisito[i].begin(), preRequisito[i].end()-38);
            preRequisito[i].erase(preRequisito[i].end()-29, preRequisito[i].end());
        }
    }

    //TRATA MATRIZ PRE REQUISITOS PARA TRANSFORMAR STRING EM IDENTIFICADOR
    int preReqIdentificador[discUteis];
    for (int i = 0; i < discUteis; i++){ // Inicializa com requisito padrão
        preReqIdentificador[i] = 0;
    }

    for (json::iterator it = j["codigo"].begin(); it != j["codigo"].end(); ++it){
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os pre requisitos
        int retorno = 0, iTemp = 0;
        while (iTemp < discUteis){
            if (preRequisito[iTemp] == it.value()){
                retorno = 1;
                break;
            }

            iTemp++;
        }
        
        //Depois que encontrou pre requisito, armazena na string
        if (retorno == 1){
            preReqIdentificador[iTemp] = i;
        }
    }
    

    //Atribuição dos dados que serão utilizados no modelo p/ a struct
    data->creditos = credito;
    data->identificador = identificador;
    data->situacao = situacao;
    data->disciplinas = discUteis;
    data->numPeriodos = 10;
    data->numDisciplinasOp = 0;

    //Preenche matriz de choque de horário direto em i
    data->choqueHorarioI = new bool*[data->disciplinas];
    for (int i = 0; i < data->disciplinas; i++){
        data->choqueHorarioI[i] = new bool[data->disciplinas];
        for (int j = 0; j < data->disciplinas; j++){
            data->choqueHorarioI[i][j] = choqueHorario[i][j];
        }
    }

    //Preenche matriz de pre-requisitos direto em i
    data->preReqI = new int*[data->disciplinas];
    for (int i = 0; i < data->disciplinas; i++){
        data->preReqI[i] = new int[data->disciplinas];
        for (int j = 0; j < data->disciplinas; j++){
            data->preReqI[i][j] = preReqI[i][j];
        }
    }

    
    //Print genérico para visualizar se o parser exibe valores certos
    for (int i = 0; i < discUteis; i++){
        cout << i << " : " << identificador[i] << endl;
    }
    

    //Fecha arquivos
    arquivoAluno.close();
    arquivoHorario.close();
    arquivoHorario2.close();
}

void solveCoin(Data* data){
    // Cria problema
    UFFProblem* prob = UFFLP_CreateProblem();

    // Cria variaveis X
	string varName, consName;
  	stringstream s;

    for (int i = 0; i < data->disciplinas; i++) {
		for (int j = 0; j < data->numPeriodos; j++) {
                s.clear();
				s << "X(" << i << "," << j << ")";
				s >> varName;
		        UFFLP_AddVariable(prob, (char*)varName.c_str(), 0.0, 1.0, j, UFFLP_Binary);
		}
	}

    //PRIMEIRA RESTRIÇÃO DO MODELO - LIMITE DE CRÉDITOS POR PERÍODO
    for (int j = 0; j < data->numPeriodos; j++){
        s.clear();
        s << "LimCreditos_" << j;
        s >> consName;

        for (int i = 0; i < data->disciplinas; i++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->creditos[i]);
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), LIMITE_CREDITOS, UFFLP_Less);
    }

    //SEGUNDA RESTRIÇÃO
    for (int i = 0; i < data->disciplinas; i++){ // Usando número de disciplinas faltantes pois é a mesma quantidade de disciplinas obrigatórias
        if(!data->situacao[i]){
            s.clear();
            s << "Obrigatorias_" << i;
            s >> consName;
                for(int j = 0; j < data->numPeriodos; j++){
                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
                }
            UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Equal);
        }
    }

    //TERCEIRA RESTRIÇÃO DO MODELO - obriga mínimo de créditos de optativas
    s.clear();
    s << "MinOptativas_";
    s >> consName;
    for (int i = 0; i < data->numDisciplinasOp; i++){
        for (int j = 0; j < data->numPeriodos; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->creditos[i]);
        }
    }
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), data->numDisciplinasOp, UFFLP_Greater);

    //QUARTA RESTRIÇÃO- PAGA OP APENAS UMA VEZ POR PERÍODO
    for (int i = 0; i < data->numDisciplinasOp; i++){ // Usando número de disciplinas faltantes pois é a mesma quantidade de disciplinas obrigatórias
        if (!data->situacao[i]){
            s.clear();
            s << "OpUmaVez_" << i;
            s >> consName;
                for(int j = 0; j < data->numPeriodos; j++){
                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
                }
            UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Less);
        }
    }

    //QUINTA RESTRIÇÃO - PRE-REQUISITOS
    for (int i = 0; i < data->disciplinas; i++){
        for (int k = 0; k < data->disciplinas; k++){
            if (data->preReqI[i][k]){
                s.clear();
                s << "PreReq_" << i << "_" << k;
                s >> consName;

                for(int j = 0; j < data->numPeriodos; j++){
                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), j);
        
                    s.clear();
                    s << "X(" << k << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), -j);
                }

                UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Greater);
            }
        }
    }

    
    //SEXTA RESTRIÇÃO
    for(int j = 0; j < data->numPeriodos; j++){
        for(int i = 0; i < data->disciplinas; i++){
            for(int k = 0; k < data->disciplinas; k++){
                
                if ((data->choqueHorarioI[i][k] == true) && (i != k)){
                    s.clear();
                    s << "Choq_Horario_" << j << "_" << i << "_" << k;
                    s >> consName;

                    s.clear();
                    s << "X(" << k << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);

                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
                    UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Less);
                }
                
            }
        }
    }
    
    /*
    //SÉTIMA RESTRIÇÃO - PERÍODOS NECESSÁRIOS PARA TÉRMINO DO CURSO-N CONSIDERA CONJUNTO ME
    for(int i; i < data->disciplinas; i++){ // Entender contra barra e adicionar conjunto do estagio e monografia
        s.clear();
        s << "Periodos_Neces_";
        s >> consName;
        for(int j = 0; j <= data->numPeriodos; j++){
             s.clear();
             s << "X(" << i << "," << j << ")";
   	         s >> varName;
             UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->numPeriodos);
    
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), MIN_PERIODOS, UFFLP_Greater);
    }
    */
    //OITAVA RESTRIÇÃO - FORÇA ESTAGIO E MONOGRAFIA PARA O ULTIMO PERÍODO
    /*for (int i = 0; i < conj_estagio_monografia; i++){
        s.clear();
        s << "Estagio_Monografia_";
        s >> consName;
        for (int j = 0; j < data -> numPeriodos; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;

            UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->numPeriodos);
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), MIN_PERIODOS, UFFLP_Greater);
    }*/

    //NONA RESTRIÇÃO
    /*for (int i = 0; i < data->disciplinas; i++){
        s.clear();
        s << "Paga_Disciplina_";
        s >> consName;
        for (int j = 0; j < data->numPeriodos; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;

            UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Binary);
    }*/

/*--------------------------------------------------------------------------------------------------------------------------------------------
    //DÉCIMA RESTRIÇÃO
    s.clear();
    s << "Y";
   	s >> varName;
    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), MIN_PERIODOS, UFFLP_Greater); // Min_Periodos é o proprio y?
--------------------------------------------------------------------------------------------------------------------------------------------*/
    // Escreve modelo no arquivo .lp
    UFFLP_WriteLP( prob, "PAAA.lp" );
    UFFLP_SetLogInfo(prob, "mix.log" , 2);

    UFFLP_StatusType status = UFFLP_Solve( prob, UFFLP_Minimize );

    if (status == UFFLP_Optimal){

        double value;
        cout << "Solucao otima encontrada!" << endl << endl;
        cout << "Solucao:" << endl;

        UFFLP_GetObjValue( prob, &value );
        cout << "Valor da funcao objetivo = " << value << endl;


        // Imprime valor das variaveis nao-nulas

            for (int i = 0; i < data->disciplinas; i++) {
                for (int j = 0; j < data->numPeriodos; j++) {

                s.clear();
                s << "X(" << i << "," << j << ")";
                s >> varName;
                UFFLP_GetSolution( prob, (char*)varName.c_str(), &value );

                if (value > 0.1) {
                cout << varName << " = " << value << endl;
                }
            }
        }
        cout << endl;/*
            for (int i = 0; i < data->numPrepostos; i++) {
                for (int j = 0; j < data->numAudiencias; j++) {

                s.clear();
                s << "Y(" << i << "," << j << ")";
                s >> varName;
                UFFLP_GetSolution( prob, (char*)varName.c_str(), &value );

                if (value > 0.1) {
                cout << varName << " = " << value << endl;
                    }
            }*/
    }else{
        cout << "Não foi encontrada uma solução ótima, tente novamente mais tarde!" << endl;
    }


    // Destroy the problem instance
    UFFLP_DestroyProblem( prob );
}

void solveCoin_Y(Data* data){
    // Cria problema
    UFFProblem* prob = UFFLP_CreateProblem();

    // Cria variaveis X
	string varName, consName;
  	stringstream s;

    // Definindo FUNC Obj. Y
    s.clear();
    s << "Y";
    s >> varName;
    UFFLP_AddVariable(prob, (char*)varName.c_str(), 1.0, 10.0, 1, UFFLP_Integer);

    // Definindo FUNC Obj. Xij
    for (int i = 0; i < data->disciplinas; i++) {
		for (int j = 0; j < data->numPeriodos; j++) {
                s.clear();
				s << "X(" << i << "," << j << ")";
				s >> varName;
		        UFFLP_AddVariable(prob, (char*)varName.c_str(), 0.0, 1.0, 0, UFFLP_Binary);
		}
	}


    //PRIMEIRA RESTRIÇÃO DO MODELO - LIMITE DE CRÉDITOS POR PERÍODO
    for (int j = 0; j < data->numPeriodos; j++){
        s.clear();
        s << "LimCreditos_" << j;
        s >> consName;

        for (int i = 0; i < data->disciplinas; i++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->creditos[i]);
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), LIMITE_CREDITOS, UFFLP_Less);
    }

    //SEGUNDA RESTRIÇÃO
    for (int i = 0; i < data->disciplinas; i++){ // Usando número de disciplinas faltantes pois é a mesma quantidade de disciplinas obrigatórias
        if(!data->situacao[i]){
            s.clear();
            s << "Obrigatorias_" << i;
            s >> consName;
                for(int j = 0; j < data->numPeriodos; j++){
                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
                }
            UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Equal);
        }
    }

    //TERCEIRA RESTRIÇÃO DO MODELO - obriga mínimo de créditos de optativas
    s.clear();
    s << "MinOptativas_";
    s >> consName;
    for (int i = 0; i < data->numDisciplinasOp; i++){
        for (int j = 0; j < data->numPeriodos; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->creditos[i]);
        }
    }
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), data->numDisciplinasOp, UFFLP_Greater);

    //QUARTA RESTRIÇÃO- PAGA OP APENAS UMA VEZ POR PERÍODO
    for (int i = 0; i < data->numDisciplinasOp; i++){ // Usando número de disciplinas faltantes pois é a mesma quantidade de disciplinas obrigatórias
        if (!data->situacao[i]){
            s.clear();
            s << "OpUmaVez_" << i;
            s >> consName;
                for(int j = 0; j < data->numPeriodos; j++){
                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
                }
            UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Less);
        }
    }

    //QUINTA RESTRIÇÃO - PRE-REQUISITOS
    for (int i = 0; i < data->disciplinas; i++){
        for (int k = 0; k < data->disciplinas; k++){
            if (data->preReqI[i][k]){
                s.clear();
                s << "PreReq_" << i << "_" << k;
                s >> consName;

                for(int j = 0; j < data->numPeriodos; j++){
                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), j);
        
                    s.clear();
                    s << "X(" << k << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), -j);
                }

                UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Greater);
            }
        }
    }

    
    //SEXTA RESTRIÇÃO
    for(int j = 0; j < data->numPeriodos; j++){
        for(int i = 0; i < data->disciplinas; i++){
            for(int k = 0; k < data->disciplinas; k++){
                
                if ((data->choqueHorarioI[i][k] == true) && (i != k)){
                    s.clear();
                    s << "Choq_Horario_" << j << "_" << i << "_" << k;
                    s >> consName;

                    s.clear();
                    s << "X(" << k << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);

                    s.clear();
                    s << "X(" << i << "," << j << ")";
                    s >> varName;
                    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
                    UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Less);
                }
                
            }
        }
    }
    
    
    //SÉTIMA RESTRIÇÃO - PERÍODOS NECESSÁRIOS PARA TÉRMINO DO CURSO-N CONSIDERA CONJUNTO ME
    for(int i = 0; i < data->disciplinas; i++){ // Entender contra barra e adicionar conjunto do estagio e monografia
        for(int j = 0; j < data->numPeriodos; j++){
            s.clear();
            s << "Periodos_Neces_" << i << "_" << j;
            s >> consName;

            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
            UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), j);

            s.clear();
            s << "Y";
   	        s >> varName;
            UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), -1);
         
            UFFLP_AddConstraint( prob, (char*)consName.c_str(), 0, UFFLP_Less);
        }
    }
    
    //OITAVA RESTRIÇÃO - FORÇA ESTAGIO E MONOGRAFIA PARA O ULTIMO PERÍODO
    /*for (int i = 0; i < conj_estagio_monografia; i++){
        s.clear();
        s << "Estagio_Monografia_";
        s >> consName;
        for (int j = 0; j < data -> numPeriodos; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;

            UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->numPeriodos);
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), MIN_PERIODOS, UFFLP_Greater);
    }*/

    //NONA RESTRIÇÃO
    /*for (int i = 0; i < data->disciplinas; i++){
        s.clear();
        s << "Paga_Disciplina_";
        s >> consName;
        for (int j = 0; j < data->numPeriodos; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;

            UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
        }
        UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Binary);
    }*/


    //DÉCIMA RESTRIÇÃO
    s.clear();
    s << "Y";
   	s >> consName;
    s.clear();
    s << "Y";
    s >> varName;

    UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), 0, UFFLP_Greater);
    
    // Escreve modelo no arquivo .lp
    UFFLP_WriteLP( prob, "PAAA.lp" );

    UFFLP_StatusType status = UFFLP_Solve( prob, UFFLP_Minimize );
    
    if (status == UFFLP_Optimal){

        double value;
        cout << "Solucao otima encontrada!" << endl << endl;
        cout << "Solucao:" << endl;

        UFFLP_GetObjValue( prob, &value );
        cout << "Valor da funcao objetivo = " << value << endl;


        // Imprime valor das variaveis nao-nulas

            for (int i = 0; i < data->disciplinas; i++) {
                for (int j = 0; j < data->numPeriodos; j++) {

                s.clear();
                s << "X(" << i << "," << j << ")";
                s >> varName;
                UFFLP_GetSolution( prob, (char*)varName.c_str(), &value );

                if (value > 0.1) {
                cout << varName << " = " << value << endl;
                }
            }
        }
        cout << endl;/*
            for (int i = 0; i < data->numPrepostos; i++) {
                for (int j = 0; j < data->numAudiencias; j++) {

                s.clear();
                s << "Y(" << i << "," << j << ")";
                s >> varName;
                UFFLP_GetSolution( prob, (char*)varName.c_str(), &value );

                if (value > 0.1) {
                cout << varName << " = " << value << endl;
                    }
            }*/
    }else{
        cout << "Não foi encontrada uma solução ótima, tente novamente mais tarde!" << endl;
    }

    // Destroy the problem instance
    UFFLP_DestroyProblem( prob );
}