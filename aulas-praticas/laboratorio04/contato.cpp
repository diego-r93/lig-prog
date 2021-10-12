#include "contato.h"

Contato::Contato(string nome, string profissao, int idade) {
   setNome(nome);
   setProfissao(profissao);
   setIdade(idade);
}

void Contato::setNome(string nome) {
   this->nome = nome;
}

void Contato::setProfissao(string profissao) {
   this->profissao = profissao;
}

void Contato::setIdade(int idade) {
   this->idade = idade;
}

string Contato::getNome() {
   return nome;
}

string Contato::getProfissao() {
   return profissao;
}

int Contato::getIdade() {
   return idade;
}