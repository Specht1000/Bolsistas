#ifndef _BOLSISTA_HPP_
#define _BOLSISTA_HPP_

#include <string>

using namespace std;

class Bolsista {
protected:
    string nm_bolsista;
    string cpf_bolsista;
    string nm_entidade_ensino;
    int me_referencia;
    int an_referencia;
    string sg_diretoria;
    string sg_sistema_origem;
    int cd_modalidade_sgb;
    string ds_modalidade_pagamento;
    string cd_moeda;
    float vl_bolsista_pagamento;
public:
    Bolsista(string nome_bol = "", string cpf_bol = "", string nome_entidade_ens = "", int mes_ref = 0, int ano_ref = 0, string sg_dir = "", string sg_sis_orig = "", int cd_mod_pag = 0, string ds_mod_pag = "", string cd_moe = "", float vl_bol_pag = 0);
    string obtemNome();
    string obtemCPF();
    string obtemEntEns();
    float obtemValorBolsa();
    int obtemAnoRef();
};

#endif
