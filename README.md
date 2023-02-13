# Bolsistas
Programa que realiza a leitura de um arquivo .csv com dados de alunos bolsistas do Brasil com tais funcionalidades:
1. [Consultar bolsa zero/Ano] Permitir que o usuário informe o ano que desejar e como resultado o programa deverá exibir:
    a. As informações sobre o bolsista zero, ou seja, o primeiro bolsista daquele ano (Nome, CPF, Entidade de Ensino e Valor da Bolsa);

2. [Codificar nomes] Em alguns casos o nome do aluno bolsista não deve ser exibido por questão de sigilo. Esta funcionalidade deverá codificar o nome de um bolsista.     Para isso, permitir que o usuário busque um bolsista digitando todo o nome ou parte dele. Ao localizar o respectivo bolsista, seu nome deve ser codificado e exibido   com as seguintes informações: Nome codificado, Ano, Entidade de ensino, Valor da Bolsa. A codificação dos caracteres deve ser deduzida a partir dos seguintes       exemplos*:
PERIGO => OERIGP => PGIREO => QHJSFP
FUGA => AUGF => FGUA => GHVB
PAZ => ZAP => ABQ
* Os nomes deverão ser sempre tratados apenas em letras maiúsculas. Letras acentuadas deverão ser convertidas para as respectivas letras sem os acentos. Outros sinais deverão ser descartados. Ex. Lúcia D’Ávila  LUCIA DAVILA.

3. [Consultar média anual] Permitir que o usuário informe o ano desejado. Como resultado, o programa deverá exibir a média dos valores das bolsas daquele ano;

4. [Ranking valores de bolsa] O programa deverá listar dois tipos de colocações:
    a. Os três alunos com os valores da bolsa mais altos;   
    b. Os três alunos com os valores da bolsa mais baixos;
    
5. [Terminar o programa] Permitir que o usuário saia do programa.
