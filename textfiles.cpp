// Programa que lee un archivo CSV para texto
// Creado jhon alejandro mariaca
// Inspirado en: profesor cesar aceros


#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

void parseCSV()
{
	ifstream data("Book.csv");//sacamos datos del archivo 
	string line;
	vector<vector<string>> parsedCsv;
	int rowcount=0;//creamos e inicializamos variables
	int colcount=0;//creamos e inicializamos variables
	while(getline(data,line))//creamo el ciclo while que nos mande a repetir la accion mientras extraemos los datos
	{
		stringstream lineStream(line);
		string cell;
		vector<string> parsedRow;
		colcount=0;//reseteamos el valor de la variable cada vez que se cumpla el while
		while(getline(lineStream,cell,','))//decimos que diference los datos a extraer teniendo en cuenta las comas que separan a las columnas
		{
			
			parsedRow.push_back(cell);
			colcount++;//creamos el contador cada vez que se hace una nueva celda
				

		}
		rowcount++;
		parsedCsv.push_back(parsedRow);

	}
	for(int i=0; i<rowcount; i++){// creamos un for para que la respuesta nos la de por columnas y por filas
		for (int j=0; j < colcount ; j++){
		cout << parsedCsv[i][j] <<" - ";//imprimimos la respuesta y le decimos al pograma que nos separe cada celda con un guion
	
		}
		cout << '\n';

	}


}
int main()
{
	parseCSV();
	return 0;//fin programa
}
