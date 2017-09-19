#include <iostream>
#include <array>
using namespace std;

const unsigned N = 800;
struct Stack {
	array<string,N>a;
	unsigned i = 0;
};

void recuperarLaanteriorURL();//Falta definir
void recuperarLaposteriorURL();//Falta definir
void guardar(Stack&, string);
void desplegarOpciones();
void leerLinea();
void accionar(char);
char getTipo(string x);
string mostrar(string accion);
void terminar();
//-----------------
void Push(Stack&, string);
string Pop(Stack&);
//-----------------
string accion;
bool mientras=true;
Stack ant,post;

int main()
{

	do
    {   desplegarOpciones();
	}while(mientras);

    //mostrar(accion);

	system("PAUSE");

}


void guardar(Stack& pila,string texto)
{
    Push(pila,accion);
}
char getTipo(string accion)
{
    if(accion =="e" or accion =="E")
        return 'E';
    if(accion =="b" or accion =="B")
        return 'B';
    if(accion =="f" or accion =="F")
        return 'F';
    else        //es URL
        return 'Z';

}
void desplegarOpciones()
{

	cout << "Ingrese la accion o una URL:\n Back:     \"B\"\n Fordward: \"F\"\n Exit      \"E\"\n\n";
	leerLinea();
	mostrar(accion);
	accionar(getTipo(accion));
}
void accionar(char hacer)
{
    switch(hacer)
    {
        case 'E':
            cout<<"\nExit\n\n";
            terminar();
            break;
        case 'B':
            cout<<"\nIr a la Url anterior\n\n";
            //recuperarLaanteriorURL();
            break;
        case 'F':
            cout<<"\nIr a la Url posterior\n\n";
            //recuperarLaposteriorURL();
            break;
        case 'Z':
            cout<<"\nGuardar\n\n";
            guardar(ant,accion);
            break;

    }

}
void recuperarLaanteriorURL();//definir
void recuperarLaposteriorURL();//definir
void leerLinea()
{
	cin >> accion;
}
string mostrar(string url)
{
   cout<<"\n\t\tURL:www."<<accion<<".com"<<endl;
}
void terminar ()
{
    mientras=false;
}
//--------------
void Push(Stack& p, string x)
{
	p.a.at(p.i) = x;
	++p.i;
}
string Pop(Stack& p)
{
	--p.i;
	return p.a.at(p.i);
}
