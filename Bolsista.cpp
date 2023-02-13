#include "Bolsista.hpp"

	Bolsista::Bolsista(string nome_bol, string cpf_bol, string nome_entidade_ens, int mes_ref, int ano_ref, string sg_dir, string sg_sis_orig, int cd_mod_pag, string ds_mod_pag, string cd_moe, float vl_bol_pag){
	
	nm_bolsista = nome_bol;
        cpf_bolsista = cpf_bol;
        nm_entidade_ensino = nome_entidade_ens;
        me_referencia = mes_ref;
        an_referencia = ano_ref;
        sg_diretoria = sg_dir;
        sg_sistema_origem = sg_sis_orig;
        cd_modalidade_sgb = cd_mod_pag;
        ds_modalidade_pagamento = ds_mod_pag;
        cd_moeda = cd_moe;
        vl_bolsista_pagamento = vl_bol_pag;
	}

	string Bolsista::obtemNome(){
		return nm_bolsista;
	}

    string Bolsista::obtemCPF(){
		return cpf_bolsista;
	}

    string Bolsista::obtemEntEns(){
		return nm_entidade_ensino;
	}

	float Bolsista::obtemValorBolsa(){
		return vl_bolsista_pagamento;
	}

	int Bolsista::obtemAnoRef(){
		return an_referencia;
	}


