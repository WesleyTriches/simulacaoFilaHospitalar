#include <iostream>
#include <queue>

using namespace std;

struct paciente{
    string senha;
    char prioridade;
    int horas, minutos;
};

struct filas{
    queue<paciente> vermelha, amarela, verde, branca;
};

void mostrarMenu()
{
    cout << endl;
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
    cout << "Gerando senha do paciente: " << endl;
    cin >> aux.senha;
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
        if(fila.vermelha.empty() && fila.amarela.empty() && fila.verde.empty() && fila.branca.empty()){
            cout << hh << " " << mm << endl <<  "Sem pacientes aguardando atendimento" << endl;
            return;
        }
        if (!fila.vermelha.empty()){
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

void relatorio(int totalAtendidos, filas &fila){
    cout << "Relatorio de atendimentos" << endl
     << "Total de pacientes atendidos: " << totalAtendidos << endl
     << "Espera Emergencia V: " << fila.vermelha.size() << endl
     << "Espera Urgencia A: " << fila.amarela.size() << endl
     << "Espera Pouco Urgente D: " << fila.verde.size() << endl
     << "Espera Nao Urgente B: " << fila.branca.size() << endl;
}

void saida(int totalAtendidos, int atendidosV, int atendidosA, int atendidosD, int atendidosB, int esperaMaxima){
    cout << endl << "Relatorio final de atendimentos" << endl
     << "Total de pacientes atendidos: "<< totalAtendidos << endl
     << "Atendidos na fila vermelha: " << atendidosV << endl
     << "Atendidos na fila amarela: " << atendidosA << endl 
     << "Atendidos na fila verde: " << atendidosD << endl
     << "Atendidos na fila branca: " << atendidosB << endl  
     << "Espera maxima registrada: " << esperaMaxima << endl;
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
                cout << endl;
                relatorio(totalAtendidos, fila);
                cout << "Pico de lotacao: " << picoLotacao << endl;
            }
            break;

            case 'Q':
            {
                cout << endl;
                saida(totalAtendidos, atendidosV, atendidosA, atendidosD, atendidosB, esperaMaxima);
                cout << "Saindo do sistema..." << endl;
            }
            break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 'Q'); 

    return 0;
}