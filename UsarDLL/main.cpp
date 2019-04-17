#include <iostream>
#include <windows.h>

using namespace std;

typedef void(WINAPI* dllF)(LPCSTR);

int main()
{
    string linha;
    cout << "Aperte ENTER para carregar a DLL" << endl;
    getline(cin,linha);
    HINSTANCE dll = LoadLibrary("MinhaDLL.dll");
    if(dll !=NULL){
        cout << "\nAperte Enter para buscar a funcao" << endl;
        getline(cin,linha);
        dllF func = (dllF)GetProcAddress(dll, "SomeFunction");
        if (func != NULL){
            cout << "Funcao SomeFunction encontrada!" << endl;
            func("Olá mundo!");
        } else {
            cout << "Erro ao procurar a funcao" << endl;
        }
    } else {
     cout << "Nao foi possivel carregar a DLL" << endl;
    }
    cout << "\nAperte Enter para fechar a biblioteca" << endl;
    getline(cin, linha);
    FreeLibrary(dll);
    cout << "\nAperte Enter para sair" << endl;
    getline(cin, linha);
    return 0;
}
