//
// Created by igorg on 22/10/2018.
//

#ifndef funcoesauxiliares_h
#define funcoesauxiliares_h

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

using namespace std;


//Funcao necessaria para dividir string em vector de string, utilizando caractere delimitador
void split(string& str, vector<string>& cont, char delim);


/* LETRA B */
vector<Livro*> retornaLivros_mesmoIdioma(vector<Livro*>, string);

/* LETRA C */
/* Retorna colecao de livros ELETRONICOS, ordenados pelo ano de publicacao, contendo somente aqueles que possuem mesma extensao de arquivo */
map<int, Eletronico*> retornaEletronicos_mesmaExtensao(vector<Livro*>, string);

/* LETRA D */
vector<Impresso*> retornaImpressos_nLivrarias(vector<Livro*>, unsigned int);

/* LETRA E */
/* Retorna True em caso de sucesso na pesquisa de presenca de escritor em algum livro */
bool retornaBool_escritorAudiobook(vector<Livro*>, string);

/* LETRA F */
vector<Livro*> retornaLivos_mesmoTitulo(vector<Livro*>, string);

/* LETRA G */
/* Retorna container contendo todos os keywords disponiveis em todos os livros */
set<string> retornaKeywords(vector<Livro*>);

/* LETRA H */
map<string, Livro*> retornaLivros_nCapitulos(vector<Livro*>, unsigned int);


/* LETRA I */
void retornaIterador_Titulo(vector<Livro*>&, vector<Livro*>::iterator&, vector<Livro*>::iterator&, vector<Livro*>::iterator&, const string&);
bool mesmoTituloImpresso(Livro*, const string&);
bool mesmoTituloEletronico(Livro*, const string&);
bool mesmoTituloAudioBook(Livro*, const string&);

/* LETRA J */
void imprimeLivros_tipoSaida(vector<Livro*>, int);

/* LETRA K */
unsigned int retornaQtLivros_colecao(vector<Livro*>, string);

bool keywordIgual(string, string);

/* LETRA L */
void fazMapeamento(vector<Livro*>&, map<string, string>&);
void retornaLivroMapeado(Livro*, map<string, string>&);


void readFile(vector<Livro*>& livros);

#endif
