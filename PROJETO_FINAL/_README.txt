FRANCISCO JOSE PAIVA GONCALVES  | 201704790
JOAO RUANO NETO VEIGA DE MACEDO | 201704464
PROJETO PROG | ENTREGA 2 | 19-05-2019 23h50
(Texto sem caracteres especiais/portugueses)

OBJETIVOS ("Funcionalidades a implementar")
1 - Completo
2 - Completo
3 - Completo
4 - Completo
5 - Completo
6 - Completo
7 - Completo
8 - Completo
9 - Completo
10 - Incompleto (nao implementado)

===================================================================================================
Desenlvovemos o projeto no VS CODE usando g++ e o powershell do windows
O comando 'g++ *.cpp /classes *.cpp' compila todos os programas na pasta

IMPORTANTE NOTAR que os ficheiros de texto estao dentro da pasta 'src/data' e o
programa esta implementado de maneira a considerar isso, existindo portanto uma 
funcao que faz 'reset' ao caminho para essas files sendo dps adicionado a esse 
caminho o nome da file.

O projeto ainda esta ligeiramente incompleto (maps). Os objetivos base estao (1-8) bem cumpridos e feitos com 
bastante cuidado, verificacao de modo a que seja uma navegacao agradavel e um trabalho
bem conseguido.


FUNCIONALIDADES INTERESSANTES
- As funcionalidades de pesquisa permitem pesquisar um cliente por nome (substring de nome e CASE SENSITIVE)
e tambem por NIF apesar de com o tempo apertado acabamos por apenas implementar a procura pelo NIF para efeito
de visualizacao de um so cliente (NIF/VAT ---> identificador).
- No MAIN MENU e' permitido guardar ou nao as alteracoes feitas ao longo do programa
Escrita para files tambem so ocorre se houver mudancas efetivas causadas pelo programa
- A listagem de clientes e validacao de input no interface (numeros inteiros) facilita a navegacao
nos menus. 
- O use de clearScreen() com funcoes de sistema permite manter o ecra limpo e organizado.
O uso da funcao de sistema baxkToMenu ( system("pause") ou system("read") ) permite fazer pausas para
visualizar conteudo imprimido com calma e seguir com um click rapido.

(...)
===================================================================================================
