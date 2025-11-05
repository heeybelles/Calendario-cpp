#include <iostream>
#include <iomanip>
using namespace std;
 
  class Calendario {
  private:
   int ano, mes;
 
  public: 
    Calendario(int a, int m) {
       if (m < 1) m = 1;
           if (m > 12) m = 12;
          this->ano = a;
          this->mes = m;
    }
 
    // 1º Método:
    bool Bissexto() const {
      if ( ( (ano % 4 == 0) && (ano % 100 != 0) ) || (ano % 400 == 0) )
      return true;
      else
   return false;
  }
 
   // 2º Método
    int DiaDaSemana(int dia) const {
      int a = ano;
      int f = a + dia + 3 * (mes - 1) - 1;
 
     if (mes < 3) a--;
      else f -= int(0.4 * mes + 2.3);
 
        f += int (a / 4) - int ((a / 100 + 1) * 0.75);
 
         f %= 7;
         
           if (f < 0) f += 7;
          return f + 1;
    }
 
        // 3º Método:
        void ImprimeCalendario() const {
           cout << "Calendario: " << setfill('0') << setw(2) << mes << "/" << ano << "\n\n";
                cout << "DOM\tSEG\tTER\tQUA\tQUI\tSEX\tSAB\n\n";
 
           short TamanhoDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
           if (Bissexto()) {
              TamanhoDoMes[1] = 29;
       }
 
        int inicio = DiaDaSemana(1);
         for (int j = 1; j < inicio; j++) cout << "\t";
 
         for (int dia = 1; dia <= TamanhoDoMes[mes - 1]; dia++) {
           if (dia < 10) cout << '0' << dia << "\t";
                else cout << dia << "\t";
 
           if (DiaDaSemana(dia) == 7) cout<<"\n";
           }
            cout << "\n";
        }
 
      void setAno(int a) {
       this->ano = a;
    }
    
     void setMes(int m) {
        if (m>=1 && m<=12)
          this->mes = m;
    }
    
      int getAno() const {
        return ano;
    }
    
      int getMes() const {
      return mes;
      }
 };
 
 //Exibindo valores
   int main() {
     int ano, mes;
        cout << "Ano: ";
           cin >> ano;
             cout << "Mes (1-12): ";
              cin >> mes;
         Calendario userCal(ano, mes);
         userCal.ImprimeCalendario();
 
    return 0;
}