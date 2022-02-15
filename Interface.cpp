//
// Created by geanc on 23 dic. 2021.
//

#include "Interface.h"

void Interface::menuPrincipal() {
    Validate* validate = new Validate();
    int opcion, numDiscos, claveIntento;
    string message;
    cout<<"Digite el numero de discos para jugar: "<<endl;
    cin>>numDiscos;
    game->setN(numDiscos);
    do{
        cout<<"---------------------"<<endl
        <<"Seleccione una opcion: "<<endl
        <<"1) Ingresar el juego: "<<endl
        <<"2) Mostrar el minimo de movimientos para ganar: "<<endl
        <<"3) Mostrar el algoritmo completo paso a paso: "<<endl
        <<"0) Salir del programa: "<<endl;
        cin>>opcion;
        while(cin.fail()){
            cout<<"Error!! solo digite numeros!!"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"---------------------"<<endl
                <<"Seleccione una opcion: "<<endl
                <<"1) Ingresar el juego: "<<endl
                <<"2) Mostrar el minimo de movimientos para ganar: "<<endl
                <<"3) Mostrar el algoritmo completo paso a paso: "<<endl
                <<"0) Salir del programa: "<<endl;
            cin>>opcion;
        }
        switch (opcion) {
            case 1:
                menuJugar();
                break;
            case 2:
                cout<<"Numero minimo de movimientos es: "<<game->minimoMovimientos(numDiscos)<<endl;
                break;
            case 3:
                cout<<"Digite la clave secreta para ver la solucion: ";
                cin>>claveIntento;
                while(cin.fail()){
                    cout<<"Error!! solo digite numeros!!"<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout<<"Digite la clave secreta para ver la solucion: ";
                    cin>>claveIntento;
                }
                message = "";
                if(validate->validatePassword(claveIntento)){
                    cout<<game->solucionRecursiva(numDiscos,message);

                } else{
                    cout<<"Password incorrecta!"<<endl;
                }
                break;
            case 0:

                break;
            default:
                cout<<"Intente de nuevo"<<endl;
                break;
        }
    }while(opcion!=0);
}

Interface::Interface() {
    game = new Hanoi;
}

void Interface::menuJugar() {
    string mensaje="";
    int opcion =0;
    int i =0;
    do{
        cout<<"Inicio del juego!!!\n\n"<<game->toString()<<endl;
    cout<<"---------------------"<<endl
        <<"Seleccione una opcion"<<endl
        <<"1) De la pila 1 a la pila 2: "<<endl
        <<"2) De la pila 1 a la pila 3: "<<endl
        <<"3) De la pila 2 a la pila 1: "<<endl
        <<"4) De la pila 2 a la pila 3: "<<endl
        <<"5) De la pila 3 a la pila 1: "<<endl
        <<"6) De la pila 3 a la pila 2: "<<endl
        <<"7) Reiniciar el juego"<<endl
        <<"0) Salir"<<endl;
        cin>> opcion;
        if(opcion>=1 and opcion<=7){
            i++;
        }
        switch (opcion) {
            case 1:
               cout<<game->makeMove(1,2)<<endl;
                break;
            case 2:
                cout<<game->makeMove(1,3)<<endl;
                break;
            case 3:
                cout<<game->makeMove(2,1)<<endl;
                break;
            case 4:
                cout<<game->makeMove(2,3)<<endl;
                break;
            case 5:
                cout<<game->makeMove(3,1)<<endl;
                break;
            case 6:
                cout<<game->makeMove(3,2)<<endl;
                break;
            case 7:
                game->restart(game->getN());

            case 0:
                game->restart(game->getN());
                break;
            default:
                break;
        }
    }while(opcion!=0 and !game->finished());
    if(game->finished()){
        game->restart(game->getN());
        cout<<game->toString()<<endl<<endl;
        cout<<"Ganaste!!!\n Numero de intentos: "<<i<<endl;
    }
}
Interface::~Interface() {
    delete game;
}