#include <iostream>
#include <string>

using namespace std;

/*
Funcao encarregada de verificar se o input do utilizador e valido. Em caso positivo, retorna o valor introduzido a funcao.
Em caso negativo, avisa o utilizador que introduziu uma opcao invalida e funciona ate que o valor seja valido.
Desenvolvido para as interfaces.
*/
int verifyInput(int low, int high)
{
	int inputValue;
	string input;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Escolha uma opcao (" << low << "-" << high << "): ";

		getline(cin, input);

		if (isdigit(input[0]))
		{
			//Apenas aceita como input numeros entre o limite inferior e superior (inclusive)
			if (stoi(input) >= low && stoi(input) <= high &&input.size()<2)
				validInput = true;
			else
				cout << "Input invalido! Tente novamente..." << endl;
		}
		//Qualquer outro input e recusado, e e novamente pedido ao utilizador que introduza um número.
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	inputValue = stoi(input);

	return inputValue;
}


/*
Verifica se o input do utilizador e um numero positivo.
*/
bool isNumber(string input)
{
	bool isNumber;

	if (input == "")
		return false;
	else
	{
		for (int i = 0; i < input.size(); i++)
			if (isdigit(input[i]))
				isNumber = true;
			else
			{
				isNumber = false;
				break;
			}
	}
	return isNumber;

}