#include "Aplicacao.hpp"
#include "Bolsista.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>


Aplicacao::Aplicacao(){
}

Aplicacao::~Aplicacao(){
	for(int i=bolsistas.size()-1;i>0;i--){
		delete bolsistas.at(i);
	}
	bolsistas.clear();
}

void Aplicacao::adicionaBolsista(Bolsista *c){
	bolsistas.push_back(c);
}

vector<string> separaCampos(string linha, char separador){
		vector<string> res;
		string campo = "";
		for (int i=0; i<linha.size(); ++i) {
			char c = linha.at(i);
			if (c == separador) {
				res.push_back(campo);
				campo = "";
			}
			else
				campo.append(1,c);
		}
		res.push_back(campo);
		return res;
}

bool Aplicacao::carregaCSV(string nomeArquivo){
	Bolsista *bolsista;
	ifstream carregaCSV;
    string linha2;
	carregaCSV.open(nomeArquivo, ios::in);
	if(!carregaCSV.is_open()) return false;
	getline(carregaCSV, linha2);
	while(!carregaCSV.eof()){
        string linha1;

		getline(carregaCSV, linha1);
        if(linha1 == "") break; //eof não esta funcionando corretamente, entao adicionado como garantia para o final
		vector<string> linhaAux = separaCampos(linha1,';');
		
        string nome_bol = linhaAux[0];
		string cpf_bol = linhaAux[1];
		string nome_entidade_ens = linhaAux[2];
		int mes_ref = stod(linhaAux[3]);
		int ano_ref = stod(linhaAux[4]);
		string sg_dir = linhaAux[5];
		string sg_sis_orig = linhaAux[6];
		int cd_mod_pag = stod(linhaAux[7]);
		string ds_mod_pag = linhaAux[8];
		string cd_moe = linhaAux[9];
		float vl_bol_pag = stof(linhaAux[10]);

        bolsista = new Bolsista(nome_bol, cpf_bol, nome_entidade_ens, mes_ref, ano_ref, sg_dir, sg_sis_orig, cd_mod_pag, ds_mod_pag, cd_moe, vl_bol_pag);
        adicionaBolsista(bolsista);
	}
	carregaCSV.close();
	return 0;
}

void Aplicacao::consultaBolsistaZeroAno(int ano){
    int achou=0;
    for (int i=0; i<bolsistas.size();i++){
        if(bolsistas.at(i)->obtemAnoRef()==ano){
            achou=1;
            cout<<"Nome: "<<bolsistas.at(i)->obtemNome()<<" CPF: "<<bolsistas.at(i)->obtemCPF()<<" Entidade de Ensino: "<<bolsistas.at(i)->obtemEntEns()<<" Valor da Bolsa: "<<bolsistas.at(i)->obtemValorBolsa()<<endl;
            break;
        }
    }
    if(achou!=1) cout<<"Ano invalido!"<<endl;
}

void Aplicacao::consultaMediaAnual(int ano){
    int qtd_bolsistas=0;
    long double total_bolsas=0;
    int achou=0;

    for(int i=0; i<bolsistas.size();i++){
        if(bolsistas.at(i)->obtemAnoRef() == ano){
            qtd_bolsistas++;
            total_bolsas+=bolsistas.at(i)->obtemValorBolsa();
            achou=1;
        }
    }
    if (achou!=0) cout<<"A média dos valores das bolsas do ano é: "<<total_bolsas/qtd_bolsistas<<endl;
    else cout<<"Ano invalido"<<endl;
}

void Aplicacao::rankingValoresBolsa(){
    int a,b,c,d; //os tres primeiros bolsistas que irao ser ordenados para após comecar a ordenacao total
    for(int j=0; j<2;j++){
        a = 0;
        b = 1;
        c = 2;
            if(bolsistas.at(a)->obtemValorBolsa() > bolsistas.at(b)->obtemValorBolsa() && bolsistas.at(a)->obtemValorBolsa() > bolsistas.at(c)->obtemValorBolsa()){
                if(bolsistas.at(c)->obtemValorBolsa() > bolsistas.at(b)->obtemValorBolsa()){
                    d=b;
                    b=c;
                    c=d;
                }
            }
            else if(bolsistas.at(b)->obtemValorBolsa() > bolsistas.at(a)->obtemValorBolsa() && bolsistas.at(b)->obtemValorBolsa() > bolsistas.at(c)->obtemValorBolsa()){
                if(bolsistas.at(a)->obtemValorBolsa() >= bolsistas.at(c)->obtemValorBolsa()){
                    d=a;
                    a=b;
                    b=d;
                }
                else if(bolsistas.at(c)->obtemValorBolsa() > bolsistas.at(a)->obtemValorBolsa()){
                    d=a;
                    a=b;
                    b=c;
                    c=d;
                }
            }
            else if (bolsistas.at(c)->obtemValorBolsa() > bolsistas.at(a)->obtemValorBolsa() && bolsistas.at(c)->obtemValorBolsa() > bolsistas.at(b)->obtemValorBolsa()){
                if(bolsistas.at(a)->obtemValorBolsa() >= bolsistas.at(b)->obtemValorBolsa()){
                    d=a;
                    a=c;
                    c=b;
                    b=d;
                }
                else if(bolsistas.at(b)->obtemValorBolsa() > bolsistas.at(a)->obtemValorBolsa()){
                    d=a;
                    a=c;
                    c=d;
                }
            }

        if(j==0){
            for(int i=3;i<bolsistas.size(); i++){
                if(bolsistas.at(i)->obtemValorBolsa()>bolsistas.at(a)->obtemValorBolsa()){
                    c=b;
                    b=a;
                    a=i;
                    
                }
                else if(bolsistas.at(i)->obtemValorBolsa()>bolsistas.at(b)->obtemValorBolsa()){
                    c=b;
                    b=i;
                }
                else if(bolsistas.at(i)->obtemValorBolsa()>bolsistas.at(c)->obtemValorBolsa()){
                    c=i;
                }
            }
            cout<<"Top 3 maiores bolsas:"<<endl;
            cout<<"Nome: "<<bolsistas.at(a)->obtemNome()<<endl;
            cout<<"Nome: "<<bolsistas.at(b)->obtemNome()<<endl;
            cout<<"Nome: "<<bolsistas.at(c)->obtemNome()<<endl;
        }
        else{
            for(int i=3;i<bolsistas.size(); i++){
                if(bolsistas.at(i)->obtemValorBolsa()<bolsistas.at(c)->obtemValorBolsa()){
                    b=a;
                    a=b;
                    c=i;
                }
                else if(bolsistas.at(i)->obtemValorBolsa()<bolsistas.at(b)->obtemValorBolsa()){
                    a=b;
                    b=i;
                }
                else if(bolsistas.at(i)->obtemValorBolsa()<bolsistas.at(a)->obtemValorBolsa()){
                    a=i;
                }
            }

            cout<<"Top 3 menores bolsas:"<<endl;
            cout<<"Nome: "<<bolsistas.at(c)->obtemNome()<<endl;
            cout<<"Nome: "<<bolsistas.at(b)->obtemNome()<<endl;
            cout<<"Nome: "<<bolsistas.at(a)->obtemNome()<<endl;
        }
    }
}

string criptografar(string nome){
    if(nome.size()>3){
        int inicio,fim;
        inicio=1;
        fim=nome.size()-2;

        while(inicio<fim){
            char tmp=nome[inicio];
            nome[inicio]=nome[fim];
            nome[fim]=tmp;
            inicio++;
            fim--;
        }
    }
    else{ 
        int inicio,fim;
        inicio=0;
        fim=nome.size()-1;

        while(inicio<fim){
            char tmp=nome[inicio];
            nome[inicio]=nome[fim];
            nome[fim]=tmp;
            inicio++;
            fim--;
        }
    }
    for(int i=0;i<nome.size();i++) nome[i]=nome[i]+1;
    return nome;

}

void Aplicacao::consultaCriptografada(string nome){
    for(int i=0;i<nome.size();i++)nome[i]=toupper(nome[i]);

    vector<string> nomeInf = separaCampos(nome,' ');
    vector<Bolsista *> encontrados;

    for(int i=0; i<bolsistas.size();i++){
        int igual=0;
        vector<string> nomeBusc = separaCampos(bolsistas.at(i)->obtemNome(),' ');
        for(int j=0;j<nomeBusc.size();j++){
            for(int k=0; k<nomeInf.size();k++){
                if(nomeInf.at(k)==nomeBusc.at(j)){
                    if(encontrados.size()!=0){
                        int achou=0;
                        for(int g=0; g<encontrados.size();g++){
                            if(encontrados.at(g)->obtemCPF()==bolsistas.at(i)->obtemCPF()) achou==1;
                        }
                        if(achou!=1) encontrados.push_back(bolsistas.at(i));
                    }
                    else encontrados.push_back(bolsistas.at(i));
                }
            }
        }
    }
        if(encontrados.size()>0){
            for(int i=0;i<encontrados.size();i++){
                cout<<"Nome criptografado: ";
                vector<string> nomes = separaCampos(encontrados.at(i)->obtemNome(),' ');
                for(int j=0;j<nomes.size();j++){
                    cout<<criptografar(nomes.at(j))<<" ";
                }
                cout<<endl<<"Ano: "<<encontrados.at(i)->obtemAnoRef()<<endl<<"Entidade de Ensino: "<<encontrados.at(i)->obtemEntEns()<<endl<<"Valor da Bolsa: "<<encontrados.at(i)->obtemValorBolsa()<<endl;
                cout<<"------------------------------------------------------------------------------"<<endl;
            }
        }
        else cout<<"Nome inexistente nos registros!"<<endl;
}

void Aplicacao::inicializarMenu(){ //menu para acesso do usuario
    int op=0;
    carregaCSV("br-capes-bolsistas-uab.csv");
    while(op!=5){
        cout<<"************************************************"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"*            Informação Bolsistas:             *"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"*   1- Consultar bolsa zero por ano            *"<<endl;
        cout<<"*   2- Pesquisa por nome (resposta codificada) *"<<endl;
        cout<<"*   3- Consulta média anual                    *"<<endl;
        cout<<"*   4- Ranking valores de bolsa                *"<<endl;
        cout<<"*   5 -Terminar programa                       *"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"************************************************"<<endl;
    
        cout<<"Selecione a opcao desejada:"<<endl;
        cin>>op;
        int ano;
        string nome,tmp;
        switch(op){
            case 1:
                
                cout<<"Informe o ano desejado:"<<endl;
                cin>>ano;
                consultaBolsistaZeroAno(ano);
                break;
            case 2:
                cout<<"Informe o nome desejado:"<<endl;
                getline(cin, tmp);
                getline(cin, nome);
                consultaCriptografada(nome);
                cout<<" "<<endl;
                break;
            case 3:
                //int ano;
                cout<<"Informe o ano desejado:"<<endl;
                cin>>ano;
                consultaMediaAnual(ano);
                break;
            case 4:
                rankingValoresBolsa();
                break;
            case 5:
                break;
            default:
                cout<<"Opcao invalida"<<endl;
        }
    }
}
    
