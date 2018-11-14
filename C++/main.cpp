#include <iostream>
#include <exception>
#include <vector>
#include <set>
#include <iomanip>
#include "funcoesAuxiliares.h"

using namespace std;

struct argumentoInvalido : exception{
    const char* what() const noexcept {
        return "Argumento invalido.";
    }
};

int main(int argc, char *argv[]) {
    vector<Livro*> colecao, vectorAuxiliar;
    vector<Impresso*> vectorImpresso;
    map<int, Eletronico*> mapAuxiliar;
    map<string, Livro*> map1Auxiliar;
    map<string, string> mapStringString;
    unsigned int num;
    string strAuxiliar;
    Eletronico* eletAux;
    Impresso* impAux;
    AudioBook* audAux;
    set<string> setStringAux;
    vector<Livro*>::iterator a, e, i;

    try{
        num = atoi(argv[1]);
        if (num == 0)
            throw argumentoInvalido();
    }
    catch(exception& e){
        cerr << e.what() << " Primeiro argumento nao e aceito pelo sistema" << endl;
        exit(1);
    }

    readFile(colecao);

    switch(num){
        case 1: /* Letra B */
            strAuxiliar = argv[2];
            vectorAuxiliar = retornaLivros_mesmoIdioma(colecao, strAuxiliar);

            if(vectorAuxiliar.size() == 0)
                cout << "Livro nao encontrado!" << endl;

            else
                for(vector<Livro*>::iterator it = vectorAuxiliar.begin(); it != vectorAuxiliar.end(); it++)
                    cout << **it << endl;
        break;

        case 2: /* Letra C */
            strAuxiliar = argv[2];
            mapAuxiliar = retornaEletronicos_mesmaExtensao(colecao, strAuxiliar);

            if(mapAuxiliar.size() == 0)
                cout << "Nao foram encontrados livros com este formato." << endl;

            else
                for(auto it = mapAuxiliar.begin(); it != mapAuxiliar.end(); it++)
                    cout << *it->second << endl;
        break;

        case 3: /* Letra D */
            try{
                num = atoi(argv[2]);
                if (0 == num)
                    throw argumentoInvalido();
            }
            catch(exception& e){
                cerr << e.what() << " Segundo argumento deve indicar numero positivo de livrarias desejadas." << endl;
                exit(1);
            }

            vectorImpresso = retornaImpressos_nLivrarias(colecao, num);

            if(vectorImpresso.size() == 0)
                cout << "Nao encontrado!" << endl;
            else
                for(auto i: vectorImpresso) {
                    cout << "Livro: " << right << setfill(' ') << setw(40) << i->getTitulo();
                    cout << " | Quantidade de livrarias: " << i->getLivrarias().size() << " | " << endl;
                }
        break;

        case 4: /* Letra E */
            for(int i=2; i<argc; i++) {
                if(i!=2)
                    strAuxiliar = strAuxiliar + " " + argv[i];
                else
                    strAuxiliar = argv[i];
            }

            if(!retornaBool_escritorAudiobook(colecao, strAuxiliar))
                cout << " Escritor nao encontrado na sessao AudioBook." << endl;

            else
                cout << " Escritor encontrado!" << endl;
        break;

        case 5: /* Letra F */
            for(int i=2; i<argc; i++) {
                if(i!=2)
                    strAuxiliar = strAuxiliar + " " + argv[i];
                else
                    strAuxiliar = argv[i];
            }

            vectorAuxiliar = retornaLivos_mesmoTitulo(colecao, strAuxiliar);

            if(vectorAuxiliar.size() == 0)
                cout << " Nenhum livro encontrado." << endl;

            else
                for(auto i: vectorAuxiliar){
                    if((impAux = dynamic_cast<Impresso*>(i)) != nullptr)
                        cout << *impAux << endl;

                    else if((eletAux = dynamic_cast<Eletronico*>(i)) != nullptr)
                        cout << *eletAux << endl;

                    else if((audAux = dynamic_cast<AudioBook*>(i)) != nullptr)
                        cout << *audAux << endl;
                }
        break;

        case 6: /* Letra G */
            setStringAux = retornaKeywords(colecao);

            if(setStringAux.size() == 0)
                cout << "Nao ha nenhum keyword na colecao." << endl;

            else{
                cout << "Keywords: ";
                for(auto i: setStringAux)
                    cout << i << " | ";

                cout << endl;
            }
        break;

        case 7: /* Letra H */
            try{
                num = atoi(argv[2]);
                if (num == 0)
                    throw argumentoInvalido();
            }
            catch(exception& e){
                cerr << e.what() << " Segundo argumento deve conter numero valido de capitulos desejados." << endl;
                exit(1);
            }

            map1Auxiliar = retornaLivros_nCapitulos(colecao, num);

            if(map1Auxiliar.size() == 0)
                cout << " Nao foram encontrados livros com a exigencia requerida." << endl;

            else
                for(auto it = map1Auxiliar.begin(); it != map1Auxiliar.end(); it++)
                    cout << *it->second << endl;

        break;

        case 8: /* Letra I */
            for(int i=2; i<argc; i++) {
                if(i!=2)
                    strAuxiliar = strAuxiliar + " " + argv[i];
                else
                    strAuxiliar = argv[i];
            }

            retornaIterador_Titulo(colecao, i, e, a, strAuxiliar);

            if(i != colecao.end())
                cout << *(dynamic_cast<Impresso *>(*i)) << endl;

            if(e != colecao.end())
                cout << *(dynamic_cast<Eletronico *>(*e)) << endl;

            if(a != colecao.end())
                cout << *(dynamic_cast<AudioBook *>(*a)) << endl;
        break;

        case 9: /* Letra J */
            try{
                strAuxiliar = argv[2];
                if (strAuxiliar != "terminal" && strAuxiliar != "arquivo")
                    throw argumentoInvalido();
            }
            catch(exception& e){
                cerr << e.what() << " Segundo argumento deve indicar qual o metodo de saida de dados." << endl;
                exit(1);
            }

            if(strAuxiliar == "arquivo")
               imprimeLivros_tipoSaida(colecao, 2);

            else if(strAuxiliar == "terminal")
                imprimeLivros_tipoSaida(colecao, 1);
        break;

        case 10: /* Letra K */
            for(int i=2; i<argc; i++) {
                if(i!=2)
                    strAuxiliar = strAuxiliar + " " + argv[i];
                else
                    strAuxiliar = argv[i];
            }

            num = retornaQtLivros_colecao(colecao, strAuxiliar);

            if(num == 0)
                cout << "Nenhuma keyword encontrada." << endl;

            else
                cout << "Quantidade de ocorrencias: " << num << "." << endl;
        break;

        case 11: /* Letra L */
            mapStringString.insert(pair<string,string>("Ingles", "ING"));
            mapStringString.insert(pair<string,string>("Portugues", "POT"));
            mapStringString.insert(pair<string,string>("Espanhol", "ESP"));
            mapStringString.insert(pair<string,string>("Frances", "FRS"));

            fazMapeamento(colecao, mapStringString);

            for(auto i: colecao)
                cout << *i << endl;
        break;

    }


    return 0;
}
