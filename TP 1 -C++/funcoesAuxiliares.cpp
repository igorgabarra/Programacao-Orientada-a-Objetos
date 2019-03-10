#include "funcoesAuxiliares.h"

#include "livro.h"
#include "audioBook.h"
#include "Eletronico.h"
#include "impresso.h"

#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>

#include <fstream>
#include <iostream>
#include <functional>
#include <memory>

#define tamanhoArquivo 16


using namespace std;


//Funcao necessaria para dividir string em vector de string, utilizando caractere delimitador
void split(string& str, vector<string>& cont, char delim){
    stringstream ss(str);
    string token;

    while(getline(ss, token, delim))
        cont.push_back(token);
}


/* LETRA B */
vector<Livro*> retornaLivros_mesmoIdioma(vector<Livro*> livros, string idioma){
    vector<Livro*> auxiliar; /* Vetor auxiliar que armazena colecao de livros contendo o idioma pesquisado */

    for(unsigned int i=0; i < livros.size(); i++){ /* Pesquisa entre todos os livros presentes na colecao */
        if(livros[i]->getIdiomaOriginal() == idioma) /* Verifica se idioma do livro[i] é o mesmo do pesquisado */
            auxiliar.push_back(livros[i]); /* Caso seja igual, insere o livro[i] no vetor auxiliar */
    }


    return auxiliar; /* Retorna colecao de livros contendo somente os que possuem mesmo idioma */
}

/* LETRA C */
/* Retorna colecao de livros ELETRONICOS, ordenados pelo ano de publicacao, contendo somente aqueles que possuem mesma extensao de arquivo */
map<int, Eletronico*> retornaEletronicos_mesmaExtensao(vector<Livro*> livros, string extensao){
    map<int, Eletronico*> aux; /* Container Map auxiliar que armazena livros eletronicos com mesmo formato de audio */
    Eletronico* livro; /* Variavel utilizada para conversao utilizando dynamic_cast */

    for(unsigned int i=0; i < livros.size(); i++){ /* Pesquisa entre todos os elementos presentes na colecao livros */
        if((livro = dynamic_cast<Eletronico*>(livros[i])) != nullptr)/* Realiza conversao de Livro* para Eletronico* e confere se foi realizado com sucesso */
            if(livro->getFormatoArquivo() == extensao)
                aux.insert(pair<int, Eletronico*>(livro->getAnoPublicacao(), livro)); /* Caso a conversao ocorra sem erros, insere no container map um par contendo o ano de publicacao e o livro eletronico */
    }

    return aux; /* Retorna colecao de livros eletronicos ordenados pelo ano de publicacao */
}


/* LETRA D */
vector<Impresso*> retornaImpressos_nLivrarias(vector<Livro*> livros, unsigned int nLivrarias){
   vector<Impresso*> auxiliar;
   Impresso* impresso;

   for(auto* it : livros){
       if((impresso = dynamic_cast<Impresso*>(it)) != nullptr)
           if(impresso->getLivrarias().size() >= nLivrarias)
               auxiliar.push_back(impresso);
   }

   return auxiliar;
}


/* LETRA E */
/* Retorna True em caso de sucesso na pesquisa de presenca de escritor em algum livro */
bool retornaBool_escritorAudiobook(vector<Livro*> livros, string escritor){
    AudioBook* audioBook; /* Variavel utilizada para conversao utilizando dynamic_cast */
    vector<string> escritores;

    for(auto* it : livros){ /* Pesquisa entre todos os elementos presentos na colecao de livros */
        if((audioBook = dynamic_cast<AudioBook*>(it)) != nullptr){ /* Realiza conversao de Livro* para AudioBook* e verifica se foi realizado com sucesso */
            escritores = audioBook->getEscritores();
            for(unsigned int j=0; j < escritores.size(); j++){ /* Caso a conversao ocorra com sucesso, percorre a colecao de escritores de determinado livro ate verificar ocorrencia (no pior caso, ate o final da colecao) */
                if(escritores[j] == escritor)  /* Verifica se escritor[j] e igual ao escritor a ser procurado */
                    return true; /* Em caso de serem iguais, processo eh finalizado indicando que escritor for encontrado */
            }
        }
    }
    return false; /* Caso nao exista ocorrencia do escritor a ser procurado em nenhum livro, a funcao retorna ao sistema indicando a nao ocorrencia de casamento */
}


/* LETRA F */
vector<Livro*> retornaLivos_mesmoTitulo(vector<Livro*> livros, string titulo){
    vector<Livro*> auxiliar;

    for(auto* it: livros){
        if(it->getTitulo() == titulo)
            auxiliar.push_back(it);
    }

    return auxiliar;
}


/* LETRA G */
/* Retorna container contendo todos os keywords disponiveis em todos os livros */
set<string> retornaKeywords(vector<Livro*> livros){
    set<string> auxiliar; /* Container auxiliar utilizado para armazenamento de todas as keywords existentes no sistema */
    vector<string> aux; /* Variavel responsavel para armazenar colecao de keywords */

    for(auto* it : livros){ /* Faz varredura em cada livro pertencente ao container */
        aux = it->getKeywords();

        for(unsigned int j = 0; j < aux.size(); j++) /* Faz varredura em todas as keywords de cada livro */
            auxiliar.insert(aux[j]); /* Faz a insercao de cada keyword, ignorando entradas que ja estao dentro do container */

        aux.clear(); /* Limpa container para receber novas keywords */
    }
    return auxiliar; /* Retorna todas as keywords presentes nos livros, sem repeticao de dados */
}


/* LETRA H */
map<string, Livro*> retornaLivros_nCapitulos(vector<Livro*> livros, unsigned int nCapitulos){
    map<string, Livro*> auxiliar;
    string primeiroEscritor;

    for(auto* it : livros){
        if(it->getCapitulos().size() <= nCapitulos){
            primeiroEscritor = it->getEscritores().front();
            auxiliar.insert(pair<string, Livro*>(primeiroEscritor, it));
        }
    }

    return auxiliar;
}

/* LETRA I */
void retornaIterador_Titulo(vector<Livro*>& livros, vector<Livro*>::iterator& i, vector<Livro*>::iterator& e, vector<Livro*>::iterator& a, const string& titulo){
        i = find_if(livros.begin(), livros.end(), bind(mesmoTituloImpresso, placeholders::_1, titulo));
        e = find_if(livros.begin(), livros.end(), bind(mesmoTituloEletronico, placeholders::_1, titulo));
        a = find_if(livros.begin(), livros.end(), bind(mesmoTituloAudioBook, placeholders::_1, titulo));
}

bool mesmoTituloImpresso(Livro* a, const string& b){
    Impresso* imp = dynamic_cast<Impresso*>(a);

    if(imp != nullptr)
        return imp->getTitulo() == b;

    else
        return false;
}

bool mesmoTituloEletronico(Livro* a, const string& b){
    Eletronico* elet = dynamic_cast<Eletronico*>(a);

    if(elet != nullptr)
        return elet->getTitulo() == b;

    else
        return false;
}

bool mesmoTituloAudioBook(Livro* a, const string& b){
    AudioBook* aud = dynamic_cast<AudioBook*>(a);

    if(aud != nullptr)
        return aud->getTitulo() == b;

    else
        return false;
}

/* LETRA J */
void imprimeLivros_tipoSaida(vector<Livro*> livros, int metodo){
    AudioBook* aud;
    Eletronico* elet;
    Impresso* imp;

    string nomearquivo = "saida.txt";
    char enter = '\n';
    ofstream arquivo(nomearquivo, ios::out);

    for(vector<Livro*>::iterator it = livros.begin(); it != livros.end(); it++) {

        if ((aud = dynamic_cast<AudioBook*>(*it)) != nullptr) {
            if (metodo == 1)
                cout << *aud << endl;

            else
                arquivo << *aud << enter;
        }

        else if ((elet = dynamic_cast<Eletronico *>(*it)) != nullptr) {
            if (metodo == 1)
                cout << *elet << endl;

            else if (metodo == 2)
                arquivo << *elet << enter;
        }

        else if ((imp = dynamic_cast<Impresso *>(*it)) != nullptr) {
            if (metodo == 1)
                cout << *imp << endl;

            else if (metodo == 2)
                arquivo << *imp << enter;
        }
    }

    arquivo.close();
}

/* LETRA K */
unsigned int retornaQtLivros_colecao(vector<Livro*> livros, string keyword){
    unsigned int contador=0; /* Contador de ocorrencias da keyword pesquisada */
    vector<string> auxiliar; /* Vector auxiliar utilizada para armazenar keywords */
    for(auto* it: livros){ /* Percorre toda a colecao de livros */
        auxiliar = it->getKeywords(); /* Vetor auxiliar recebe toda as keywords presentes em um unico livro */
        contador += count_if(auxiliar.begin(), auxiliar.end(), bind(keywordIgual, placeholders::_1, keyword)); /* Faz a contagem (utilizando funcao keywordIgual) de quantas keywords passadas por parametro estao presentes em um unico livro */

        auxiliar.clear(); /* Limpa vector auxiliar para receber nova lista de keywords */
    }

    return contador; /* Retorna quantidade de keywords iguais encontradas em toda colecao de livros */
}

bool keywordIgual(string a, string b){
    return a == b; /* Realiza comparacao entre strings */
}

/* LETRA L */
void fazMapeamento(vector<Livro*>& livros, map<string, string>& idioma){
    for_each(livros.begin(), livros.end(), bind(retornaLivroMapeado, placeholders::_1, idioma));
}

void retornaLivroMapeado(Livro* livro, map<string, string>& idioma){
    livro->setIdiomaOriginal(idioma[livro->getIdiomaOriginal()]);
}


void readFile(vector<Livro*>& livros){
    int tipoLivro, anoPublicacao;
    string titulo, colecao, idioma, nomearquivo, enter, formato, url;
    vector<string> escritores, keywords, capitulos, livrarias;

    int colunas;
    float duracao;

    for(int num=1; num<=tamanhoArquivo; num++){

        nomearquivo = to_string(num)+".txt";
        ifstream leitura(nomearquivo, ios::in);

        leitura >> tipoLivro;
        getline(leitura, enter);
        getline(leitura, titulo);

        if(tipoLivro < 1 || tipoLivro > 3){
            cerr << "Formato invalido!" << endl;
            exit(1);
        }

        else {
            getline(leitura, colecao);
            split(colecao, escritores, ';');

            leitura >> anoPublicacao;
            getline(leitura, enter);

            getline(leitura, idioma);

            getline(leitura, colecao);
            split(colecao, keywords, ';');

            getline(leitura, colecao);
            split(colecao, capitulos, ';');


            switch (tipoLivro) {
                case 1:
                    getline(leitura, colecao);
                    split(colecao, livrarias, ';');

                    leitura >> colunas;
                    getline(leitura, enter);

                    livros.push_back(new Impresso(escritores, titulo, capitulos, anoPublicacao, idioma, keywords, livrarias, colunas));
                    break;

                case 2:
                    getline(leitura, url);
                    getline(leitura, formato);

                    livros.push_back(new Eletronico(escritores, titulo, capitulos, anoPublicacao, idioma, keywords, url, formato));
                    break;

                case 3:
                    leitura >> duracao;
                    getline(leitura, enter);
                    getline(leitura, formato);

                    livros.push_back(new AudioBook(escritores, titulo, capitulos, anoPublicacao, idioma, keywords, duracao, formato));
                    break;

            }

            escritores.clear();
            keywords.clear();
            capitulos.clear();
            livrarias.clear();
        }
        leitura.close();
    }
}