#include "parque.h"
#include <vector>

using namespace std;

//a)
ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
    lotacao(lot), numMaximoClientes(nMaxCli), vagas(lot) {};

unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}

//b)
int ParqueEstacionamento::posicaoCliente(const string& nome) const{
    for(int i = 0; i < clientes.size(); i++){
        if (clientes[i].nome == nome) return i;
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome){
    if(clientes.size() >= numMaximoClientes)
        return false;
    else if(posicaoCliente(nome) == -1){
        InfoCartao client;
        client.nome = nome;
        client.presente = false;
        clientes.push_back(client);
        return true;
    }
    else return false;
}

//c)
bool ParqueEstacionamento::entrar(const string& nome){
    int pos = posicaoCliente(nome);
    if(pos == -1) return false;
    if(clientes[pos].presente) return false;
    if(vagas == 0) return false;
    else{
        clientes[pos].presente = true;
        vagas--;
        return true;
    }
}

//d)
bool ParqueEstacionamento::retiraCliente(const string& nome){
    vector<InfoCartao>::const_iterator it;
    for(it = clientes.begin(); it < clientes.end(); it++) {
        if ((*it).nome == nome && !(*it).presente){
                clientes.erase(it);
                return true;
            }
        }
    return false;
}

//e)
bool ParqueEstacionamento::sair(const string& nome){
    vector<InfoCartao>::iterator it;
    for(it = clientes.begin(); it < clientes.end(); it++){
        if ((*it).nome == nome){
            if ((*it).presente) {
                (*it).presente = false;
                vagas++;
                return true;
            }
            else return false;
        }
    }
    return false;
}

//f)
unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}