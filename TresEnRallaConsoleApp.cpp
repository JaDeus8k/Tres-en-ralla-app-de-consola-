#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

char t[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

char ca = 'x';
char ca2 = 'y';
int partidas = 1;
bool turno =  true;


void iniciar();

void Itabla()
{
    cout << "--------------" << endl;
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "[" << t[0][i] << "]";
    }
    cout << endl;
    //cout<<"["<<t[1][0]<<"]";
    for (int i = 0; i < 3; i++)
    {
        cout << "[" << t[1][i] << "]";
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "[" << t[2][i] << "]";
    }

    cout << endl;
}
void Ltabla()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t[i][j] = ' ';
        }
    }
}

void Controles()
{
    ca = 'x';
    cout << "------------" << endl
         << endl;

    cout << ":[Eliga la columna y la fila]: " << endl;
    if (turno == true)
    {
        char c;
        cin >> c;
        int i;
        cin >> i;
        switch (c)
        {
        case 'a':
            switch (i)
            {
            case 1:
                if(t[0][0] == ' '){
                    t[0][0] = ca;
                }else{cout<<"\n[AccionInvalida]";}
                break;
            case 2:
                if(t[1][0] == ' '){
                    t[1][0] = ca;
                }else{cout<<"\n[AccionInvalida]";}
                break;
            case 3:
                if(t[2][0] == ' '){
                    t[2][0] = ca;
                }else{cout<<"\n[AccionInvalida]";}
                break;
            default:
                cout << "\n[Fila inexistente]" << endl;
            }

            break;
        case 'b':
            switch (i)
            {
            case 1:
                if(t[0][1] == ' '){
                    t[0][1] = ca;
                }else{cout<<"\n[AccionInvalida]: ya colocaste una 'x' en esa posicion...";}
                break;

            case 2:
                if(t[1][1] == ' '){
                    t[1][1] = ca;
                }else{cout<<"\n[AccionInvalida]: ya colocaste una 'x' en esa posicion...";}
               break;

            case 3:
                if(t[2][1] == ' '){
                    t[2][1] = ca;
                }else{cout<<"/n[AccionInvalida]: ya colocaste una 'x' en esa posicion...";}
                break;

            default:
                cout << "\n[AccionInvalida]: ya colocaste una 'x' en esa posicion..."<< endl;
            }
            break;
        case 'c':
            switch (i)
            {
            case 1:
                if(t[0][2] == ' '){
                    t[0][2] = ca;
                }else{cout<<"\n[AccionInvalida]: ya colocaste una 'x' en esa posicion...";}
                break;
            case 2:
                if(t[1][2] == ' '){
                   
                    t[1][2] = ca;
                }else{cout<<"\n[AccionInvalida]: ya colocaste una 'x' en esa posicion...";}
                break;
            case 3:
                if(t[2][2] == ' '){
                    t[2][2] = ca;
                }else{cout<<"\n[AccionInvalida]: ya colocaste una 'x' en esa posicion...";}
                break;
            default:
                cout << "\n[Fila inexistente]" << endl;
                Controles();
            }

            break;
        default:
            cout << "\n[Columna inexistente]" << endl;
            Controles();
            
        }
        cout << endl
         << endl;
    
    }
    
    else
    {
        cout << "espere subturno"<<endl;
        system("pause");
        
    }
    //CONTROLES

    //CONTROLES

    
}
      
     

void ia()
{

    //MOVIEMIENTOS RD IA
    srand(time(NULL));
    
    int c, i, a,b;
        
        c = 0 + rand() % (3 - 1);        i = 0 + rand() % (3 - 1);
        a = 0 + rand() % (3 - 1);        b = 0 + rand() % (3 - 1);
    
        
    
    
    if(c == a){
            c = rand() % 4 + 0;
        }else if(t[i][c] == ' ' ){    
        t[i][c] = ca2;
    }
            
            if(i == b){
                
                i = rand() % 4 + 0;
                
            }else if(t[i][c] != ' '){    
        t[i][c] = ca2;
    }
 
    
    //MOVIEMIENTOS IA
}




void comparar(char tt[3][3])
{
    if (tt[0][0] == 'x' & tt[0][1] == 'x' & tt[0][2] == 'x' or tt[0][0] == 'x' & tt[1][0] == 'x' & tt[2][0] == 'x' or tt[0][1] == 'x' & tt[1][1] == 'x' & tt[2][1] == 'x' or tt[0][2] == 'x' & tt[1][2] == 'x' & tt[2][1] == 'x' or tt[1][0] == 'x' & tt[1][1] == 'x' & tt[1][2] == 'x' or tt[2][0] == 'x' & tt[2][1] == 'x' & tt[2][2] == 'x' or tt[0][0] == 'x' & tt[1][1] == 'x' & tt[2][2] == 'x' or tt[0][2] == 'x' & tt[1][1] == 'x' & tt[2][0] == 'x')
    {
        cout << "\n[partida ganada por: " << ca << "]" << endl;
        Ltabla();

        partidas--;
        if (partidas == 0)
        {
            cout << "\n[juego ganado por: " << ca << "]" << endl;
            Ltabla();
            cout << "\n[volver a jugar?]: [y/n] " << endl;
            char vj;
            cin >> vj;
            if (vj == 'y')
            {
                iniciar();
            }
            else
            {
                system("exit");
            }
        }
    }
    else if (tt[0][0] == 'y' & tt[0][1] == 'y' & tt[0][2] == 'y' or tt[0][0] == 'y' & tt[1][0] == 'y' & tt[2][0] == 'y' or tt[0][1] == 'y' & tt[1][1] == 'y' & tt[2][1] == 'y' or tt[0][2] == 'y' & tt[1][2] == 'y' & tt[2][1] == 'y' or tt[1][0] == 'y' & tt[1][1] == 'y' & tt[1][2] == 'y' or tt[2][0] == 'y' & tt[2][1] == 'y' & tt[2][2] == 'x' or tt[0][0] == 'y' & tt[1][1] == 'y' & tt[2][2] == 'y' or tt[0][2] == 'y' & tt[1][1] == 'y' & tt[2][0] == 'y')
    {
        cout << "\n[partida ganada por: " << ca2 << "]" << endl;
        Ltabla();

        partidas--;
        if (partidas == 0)
        {
            cout << "\n[juego ganado por: " << ca2 << "]" << endl;
            Ltabla();
            cout << "\n[volver a jugar?]: [y/n] " << endl;
            char vj;
            cin >> vj;
            if (vj == 'y')
            {
                Ltabla();
                Itabla();
                iniciar();
            }
            else
            {
                system("exit");
            }
        }
    }
}
void iniciar()
{
    cout << "\ncuantas partidas quieres jugar?: " << endl;

    cin >> partidas;

    while (true)
    {
         
        
        ia();
     
        system("pause");
        cout<<"\n[jugada de la IA]; "<<endl;
        Itabla();
        Controles();
        Itabla();
        comparar(t);
            
        
    }
}
int main()
{
    iniciar();
}