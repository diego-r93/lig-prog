#include "agenda.h"

Agenda::Agenda(int size) {
   tamMaxAgenda = size;
   tamMaxNome = 10;
   nomeArquivo = "dadosContatos.txt";

   lerArquivo();
}

void Agenda::insereContato(string nome, string profissao, int idade) {
   static int contaTentativas = 1;
   
   if (contatos.size() < tamMaxAgenda)
   {
      if (existeContato(nome)) {
         cout << "[CONTATO EXISTENTE] " << contaTentativas
              << "a tentativa de insercao (" << nome
              << ") NAO foi bem sucedida...\n"
              << endl;
      }
      else {
         Contato contato(verificaNome(nome), profissao, idade);
         contatos.push_back(contato);
         cout << "[CONTATO INSERIDO] " << contaTentativas
              << "a tentativa de insercao (" << nome
              << ") foi bem sucedida...\n"
              << endl;
      }
   }
   else {
      cout << "[AGENDA CHEIA] " << contaTentativas
           << "a tentativa de insercao (" << nome
           << ") NAO foi bem sucedida...\n"
           << endl;
   }

   contaTentativas++;
}

void Agenda::removeContato(string nome) {
   for (unsigned i = 0; i < contatos.size(); i++) {
      if (!contatos.at(i).getNome().compare(nome.substr(0, tamMaxNome))) {
         contatos.erase(contatos.begin() + i);
         cout << "[CONTATO REMOVIDO] " << nome << " removido!" << endl;
      }
   }
}

bool Agenda::existeContato(string nome) {
   for (unsigned i = 0; i < contatos.size(); i++) {
      if (!contatos.at(i).getNome().compare(nome.substr(0, tamMaxNome)))
         return true;
   }
   return false;
}

void Agenda::editaIdadeContato(string nome, int novaIdade) {
   for (unsigned i = 0; i < contatos.size(); i++) {
      if (!contatos.at(i).getNome().compare(nome.substr(0, tamMaxNome))) {
         contatos.at(i).setIdade(novaIdade);
         cout << "[CONTATO EDITADO] idade do contato " << nome << " editado!"
              << endl;
      }
   }
}

void Agenda::editaProfissaoContato(string nome, string novaProfissao) {
   for (unsigned i = 0; i < contatos.size(); i++) {
      if (!contatos.at(i).getNome().compare(nome.substr(0, tamMaxNome))) {
         contatos.at(i).setProfissao(novaProfissao);
         cout << "[CONTATO EDITADO] profissao do contato " << nome
              << "editado !" << endl;
      }
   }
}

void Agenda::mostraContatos() {
   cout << endl;
   cout << left << setw(15) << "Nome:"
        << setw(15) << "Profissao:"
        << setw(5) << "Idade:" << endl;
   for (unsigned i = 0; i < contatos.size(); i++)
      cout << setw(15) << contatos.at(i).getNome()
           << setw(15) << contatos.at(i).getProfissao()
           << setw(5) << contatos.at(i).getIdade() << endl;
   cout << endl;
}

string Agenda::verificaNome(string nome) {
   if (nome.length() > tamMaxNome) {
      cout << "[CUIDADO] Nome muito comprido!" << endl;
      cout << "Nome truncado a partir do " << tamMaxNome
           << "o caracter \"" << nome[tamMaxNome]
           << "\": " << nome.substr(0, tamMaxNome) << endl;
   }

   return nome.substr(0, tamMaxNome);
}

void Agenda::lerArquivo() {
   string nome, profissao;
   int idade;

   file.open(nomeArquivo, fstream::in);

   if (!file.is_open()) {
      cout << "Arquivo nao existe." << endl;
      return;
   }

   while (file.good()) {
      file >> nome >> profissao >> idade;
      insereContato(nome, profissao, idade);
   }
   file.close();
}

void Agenda::escreveArquivo() {
   file.open(nomeArquivo, fstream::out);
   for (unsigned i = 0; i < contatos.size(); i++)
      file << contatos.at(i).getNome()
           << " " << contatos.at(i).getProfissao()
           << " " << contatos.at(i).getIdade() << endl;
   file.close();
}