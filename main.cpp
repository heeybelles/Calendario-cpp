#include <iostream>
using namespace std;
 
class Calendario {
private:
    int ano, mes;
 
public:
    Calendario(int a, int m) {
        if (m < 1) m = 1;
        if (m > 12) m = 12;
        ano = a;
        mes = m;
    }
 
    bool Bissexto() const {
        return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
    }
 
    int DiaDaSemana(int dia, int mes, int ano) const {
        if (mes < 3) {
            mes += 12;
            ano--;
        }
 
        int k = ano % 100;
        int j = ano / 100;
 
        int f = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
 
        
        int diaSemana = ((f + 6) % 7) + 1; 
        return diaSemana;
    }
 
    void ImprimeCalendario() const {
        cout << "DOM\tSEG\tTER\tQUA\tQUI\tSEX\tSAB\n\n";
 
        int TamanhoDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (Bissexto()) TamanhoDoMes[1] = 29;
 
        int primeiroDia = DiaDaSemana(1, mes, ano);
 
        
        for (int j = 1; j < primeiroDia; j++)
            cout << "\t";
 
        
        for (int dia = 1; dia <= TamanhoDoMes[mes - 1]; dia++) {
            cout << dia << "\t";
            if (DiaDaSemana(dia, mes, ano) == 7)
                cout << "\n";
        }
        cout << "\n";
    }
};
 
int main() {
    int ano, mes;
    cout << "Ano: \n";
    cin >> ano;
    cout << "Mes (1-12): \n ";
    cin >> mes;
 
    Calendario cal(ano, mes);
    cal.ImprimeCalendario();
 
    return 0;
}
