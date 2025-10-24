#include <iostream>
#include <queue>

using namespace std;

struct cliente{
    string nome;
    char prioridade;
    int horas, minutos;
};

int main(){
    queue<cliente>vermelha, amarela, verde, branca;
    cliente aux;
    char opcao;
    do{

        cout << "Fazer um menu" << endl; // fazer o menu com as opcoes 
        cin >> opcao;
        opcao = toupper(opcao);
        switch (opcao){
            case 'C':
                {
                    cin.ignore();
                    getline(cin, aux.nome);
                    cin >> aux.prioridade >> aux.horas >> aux.minutos;
                    if (aux.prioridade == 'V'){
                        vermelha.push(aux);
                    }
                    else if (aux.prioridade == 'A'){
                        amarela.push(aux);
                    }
                    else if(aux.prioridade == 'D'){
                        verde.push(aux);
                    }
                    else if(aux.prioridade == 'B'){
                        branca.push(aux);
                    }
                }
                break;

            case 'A':
                {

                }
                break;

            case 'D': 
                {

                }
                break;

            case 'Q': 
                {
        
                }
            break;

            case 'S': 
                {
                    cout << "Saindo do sistema..." << endl;
                }
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;  

        }

    } while (opcao != 'S'); // fazer a opcao pra sair





    return 0;
}