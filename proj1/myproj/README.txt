FRANCISCO JOSE PAIVA GONCALVES | 201704790
PROJETO PROG | ENTREGA 1 | 12-04-2019
(Texto sem caracteres especiais/portugueses)

OBJETIVOS ("Funcionalidades a implementar")
1 - Completo
2 - Completo
3 - Completo (para ja, apenas com nome [funciona com partes do nome] e NIF)
4 - Completo
5 - Incompleto (falta fazer funcoes semelhantes que foram ja feitas para os clientes)
6 - Por fazer
7 - Completo
8 - Completo

===================================================================================================
Desenlvovi o projeto no VS CODE usando g++ e o powershell do windows
O comando 'g++ *.cpp' compila todos os programas na pasta
Ha apenas uma biblioteca com as funcoes desenvolvidas

IMPORTANTE NOTAR que os ficheiros de texto estao dentro da pasta 'textfiles' e o
programa esta implementado de maneira a considerar isso, existindo portanto uma 
funcao que faz 'reset' ao caminho para essas files sendo dps adicionado a esse 
caminho o nome da file.

O projeto ainda esta incompleto. Faltam alguns (poucos) melhoramentos de *verifacacao de input*, 
funcionalidades base e pronlogamento de funcionalidades que ainda estao permaturas.
No entanto o *funcionamento base do programa esta implementado* e com boa organizacao.
ESCRITA para as files ja esta implementada a cada edicao.
INTERFACES em bom estado, exceto na parte de edicao de packs por falta de funcoes no interior 
que ainda estao por implementar (ponto 5 dos OBJETIVOS)

A funcao stoint definida em helpful.cpp permite evitar o programa crashar se o stoi tiver um erro
ao tentar "traduzir" a string, nomeadamente se nao for um numero. Nesta implementacao ainda nao esta 
totalmente utilizada, mas mais tarde vai permitir proteger o programa de inputs inadequadas.

Uma MELHORIA implementada foi a pesquisa por nome ecnontrar uma lista de clientes com o substring de input.
Isto permite uma pesquisa mais simples e direta. Ja ha mais algumas melhorias que ajudam ao bom 
funcionamento do programa mas na versao final haverao mais, como por exemplo opcoes de guardar
quando o utilizador desejar em vez de a cada vez que adiciona um pack por exemplo.

No geral ha algumas nuances que ainda nao foram tratadas (fora daquilo que ainda nao esta feito),
como por exemplo confirmar que na adicao de um pacote o utilizador introduz um destino com a formatacao
valida (hifen se precisar)
===================================================================================================
