#ifndef _APLICACAO_HPP_
#define _APLICACAO_HPP_

#include "Bolsista.hpp"
#include <vector>

using namespace std;

class Aplicacao {
private:
    vector<Bolsista *> bolsistas;
    void adicionaBolsista(Bolsista *);
    bool carregaCSV(string nomeArquivo);
    void consultaBolsistaZeroAno(int ano);
    void consultaMediaAnual(int ano);
    void rankingValoresBolsa();
    void consultaCriptografada(string nome);
public:
    Aplicacao();
    ~Aplicacao();
    void inicializarMenu();
};

#endif