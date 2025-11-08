#include <iostream>
#include <queue>

using namespace std;

struct paciente{
    string nome;
    char prioridade;
    int horas, minutos;
};

struct filas{
    queue<paciente> vermelha, amarela, verde, branca;
};

void mostrarMenu()
{
    cout << "=== Escolha uma opcao ===" << endl;
    cout << "C - Cadastrar paciente" << endl;
    cout << "A - Atender paciente" << endl;
    cout << "D - Exibir dados das filas" << endl;
    cout << "Q - Sair do sistema" << endl;
}

int calculoEspera(int chegadaHora, int chegadaMinutos, int horaAtendimento, int minutoAtendimento){
    int converterMinutos = ((horaAtendimento * 60 + minutoAtendimento) - (chegadaHora * 60 + chegadaMinutos));
    return converterMinutos;
}

void cadastro(filas &fila, int &picoLotacao){
    paciente aux;
    cin.ignore();
    cout << "Digite o nome do paciente: " << endl;
    getline(cin, aux.nome);
    cout << "Digite a prioridade (V, A, D, B): " << endl 
        << "Digite as horas e os minutos (HH MM): " << endl;
    cin >> aux.prioridade >> aux.horas >> aux.minutos;
    aux.prioridade = toupper(aux.prioridade);
    switch (aux.prioridade){
        case 'V':
        {
            fila.vermelha.push(aux);
        }break; 

        case 'A':
        {
            fila.amarela.push(aux);
        }break;

        case 'D':
        {
            fila.verde.push(aux);
        }break;

        case 'B':
        {
            fila.branca.push(aux);
        }break;
    }
    int pacientesFilas = fila.vermelha.size() + fila.amarela.size() + fila.verde.size() + fila.branca.size();
    if(picoLotacao < pacientesFilas)
        picoLotacao = pacientesFilas;
}

void atender(filas &fila, int &hh, int &mm, int &esperaMaxima, int &totalAtendidos, 
    int &atendidosV, int &atendidosA, int &atendidosD, int &atendidosB){
        paciente pacientes;
        if(fila.vermelha.empty() && fila.amarela.empty() && fila.verde.empty() && fila.branca.empty())
            cout << hh << " " << mm << " Sem pacientes aguardando atendimento" << endl;
        else if (!fila.vermelha.empty()){
                pacientes = fila.vermelha.front();
                fila.vermelha.pop();
                atendidosV++;
                totalAtendidos++;

        }else if(!fila.amarela.empty()){
                pacientes = fila.amarela.front();
                fila.amarela.pop();
                atendidosA++;
                totalAtendidos++;

        }else if(!fila.verde.empty()){
                pacientes = fila.verde.front();
                fila.verde.pop();
                atendidosD++;
                totalAtendidos++;

        }else if(!fila.branca.empty()){
                pacientes = fila.branca.front();
                fila.branca.pop();
                atendidosB++;
                totalAtendidos++;
        }

        int espera = calculoEspera(pacientes.horas, pacientes.minutos, hh, mm);
        if (esperaMaxima < espera)
            esperaMaxima = espera;
        cout << "Tempo de espera: " << espera << " minutos" << endl;
}

void relatorio(){

}

int main()
{
    filas fila;
    char opcao;
    int hh = 0, mm = 0, esperaMaxima = 0, picoLotacao = 0;
    int totalAtendidos = 0, atendidosV = 0, atendidosA = 0, atendidosD = 0, atendidosB = 0;
    do
    {
        mostrarMenu();
        cin >> opcao;
        opcao = toupper(opcao);
        switch (opcao)
        {
            case 'C':
            {
                cadastro(fila, picoLotacao);
            }
            break;

            case 'A':
            {
                cout << "Digite a hora do atendimento(HH MM): " << endl;
                cin >> hh >> mm;
                atender(fila, hh, mm, esperaMaxima, totalAtendidos, atendidosV, atendidosA, atendidosD, atendidosB);
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

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 'Q'); 

    return 0;
}