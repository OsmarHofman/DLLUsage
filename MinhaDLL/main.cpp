#include "main.h"
#define SIZE 1000000
double * dados = NULL;
// a sample exported function
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            if (dados == NULL){
                dados = new double[SIZE];
                double a;
                for( a = 0; a < SIZE; a++){
                    dados[(int)a] = a;
                }
            }
            cout << "DLL carregada!" << endl;
            break;

        case DLL_PROCESS_DETACH:
            delete dados;
            cout << "DLL liberada!" << endl;
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
