#include "myTypes.h"

/*
Fun��o encarregada de verificar se o input do utilizador � v�lido. Em caso positivo, retorna o valor introduzido � fun��o.
Em caso negativo, avisa o utilizador que introduziu uma op��o inv�lida e funciona at� que o valor seja v�lido.
Desenvolvido para as interfaces.
*/
int verifyInput(int low, int high)
{
	int inputValue;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Escolha uma op��o (" << low << "-" << high << "): ";

		//Apenas aceita como input n�meros entre o limite inferior e superior (inclusive)
		if (cin >> inputValue && low <= inputValue && high >= inputValue)
		{
			validInput = true;
			cin.ignore(1000, '\n');
		}
		//Qualquer outro input � recusado, e � novamente pedido ao utilizador que introduza um n�mero.
		else 
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Op��o inv�lida, tente novamente..." << endl << endl;
		}
	}

	return inputValue;
}