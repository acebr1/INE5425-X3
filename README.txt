Instruções para Execução:

Dependências: make, g++.

make run - Executa o arquivo main.cpp.
make test - Executa os testes de unidade implementados.
make debug - Executa os testes de unidade implementados, porém imprimindo informações extras.

Os testes de unidades se baseiam em dados disponíveis no arquivo include/testValues.h

Considerações:

Alguns casos dos testes unitários foram retirados de bibliografias que efetuavam arredondamentos.
Logo erros de aproximação são esperados.

Algumas da respostas esperadas nos casos de testes de hipótese de proporção foram obtidas de 
autores que utilizavam a tabela normal e não a tabela T-student com GL = n1 + n2 - 2.
Os p-valores obtidos são muito próximos do esperado e ainda melhores.
