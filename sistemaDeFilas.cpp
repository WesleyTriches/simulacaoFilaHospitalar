#include <iostream>
#include <queue>


using namespace std;

struct cliente{
    string nome;
    char prioridade;
    int horas, minutos;
};

int calculoEspera(int chegadaHora, int chegadaMinutos, int horaAtendimento, int minutoAtendimento){
    int converterMinutos = ((horaAtendimento*60 + minutoAtendimento) - (chegadaHora*60 + chegadaMinutos));
    return converterMinutos;
}

int main(){
    queue<cliente>vermelha, amarela, verde, branca;
    cliente aux;
    char opcao;
    int hh = 0, mm = 0, lotacao = 0, esperaMaxima = 0;
    int totalAtendidos = 0, atendidosV = 0, atendidosA = 0, atendidosD = 0, atendidosB = 0;
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
                    cin >> hh >> mm;
                    if (!vermelha.empty()){
                        aux = vermelha.front(); vermelha.pop(); atendidosV++; totalAtendidos ++;
                    }
                    else if(!amarela.empty()){
                        aux = amarela.front(); amarela.pop(); atendidosA++; totalAtendidos ++;

                    }
                    else if(!verde.empty()){
                        aux = verde.front(); verde.pop(); atendidosD++; totalAtendidos ++;

                    }
                    else if(!branca.empty()){
                        aux = branca.front(); branca.pop(); atendidosB++; totalAtendidos ++;
                    }
                    else{
                        cout << hh << ":" << mm << " Sem pacientes aguardando atendimento" << endl;
                        break;
                    }

                    int espera = calculoEspera(aux.horas, aux.minutos, hh, mm);
                    if(esperaMaxima < espera) esperaMaxima = espera;
                    cout << "Tempo de espera" << espera << " minutos" << endl;
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