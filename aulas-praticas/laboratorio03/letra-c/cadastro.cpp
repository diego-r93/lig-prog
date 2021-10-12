#include "cadastro.h"

void Cadastro::setNome(string nome) {
   this->nome = checkName(nome);
}

string Cadastro::getNome() {
   return nome;
}

void Cadastro::setProfissao(string profissao) {
   this->profissao = profissao;
}

string Cadastro::getProfissao() {
   return profissao;
}

void Cadastro::setIdade(int idade) {
   this->idade = idade;
}

int Cadastro::getIdade() {
   return idade;
}

string Cadastro::checkName(string name) {
   if (name.length() > 10) {
      name = name.substr(0, 10);
      cout << "O nome inserido é maior do que o valor máximo" << endl;
      cout << "O nome foi truncado para: " << name << endl;
   }
   return name;
}

