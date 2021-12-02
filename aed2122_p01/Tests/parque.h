#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
};

class ParqueEstacionamento {
	unsigned vagas;
	const unsigned  lotacao;
	vector<InfoCartao> clientes;
	const unsigned numMaximoClientes;
public:
	ParqueEstacionamento(unsigned lot, unsigned nMaxCli);
	bool adicionaCliente(const string & nome);
	bool retiraCliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	int posicaoCliente(const string & nome) const;
	unsigned getNumLugares() const;
	unsigned getNumMaximoClientes() const;
	unsigned getNumLugaresOcupados() const;
	unsigned getNumClientesAtuais() const;
};
