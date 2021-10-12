#include <iostream>
#include "agenda.h"

using namespace std;

int main() {
   Agenda agenda;

   agenda.insereContato("ana", "estudante", 20);
   agenda.insereContato("aristoteles", "estudante", 21);
   
   agenda.insereContato("nao entra", "professor", 30);
   agenda.mostraContatos();
   
   agenda.removeContato("miguel");
  
   agenda.insereContato("aristoteles", "estudante", 21);
   
   agenda.insereContato("fatima", "jornalista", 50);
   agenda.mostraContatos();
   
   agenda.editaIdadeContato("aristoteles", 1000);
   agenda.editaProfissaoContato("aristoteles", "cientista");
   agenda.mostraContatos();
   
   agenda.escreveArquivo();
   
   return 0;
}