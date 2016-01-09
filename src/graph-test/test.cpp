#include <iostream>
#include "graph.h"
using namespace std;

unsigned int N, M;
vector<conductor> E;
vector<comp> I;

istream &operator>>(istream &is, comp &e) {
	double re, im;
	is >> re >> im;
	e = comp(re, im);
	return is;
}

istream &operator>>(istream &is, conductor &e) {
	is >> e.edge_info.from >> e.edge_info.to;
	is >> e.elect_info.imp >> e.elect_info.emf;
	return is;
}

void Init() {
	cin >> N >> M;
	conductor e;
	for (uint i = 0; i < M; ++i) {
		cin >> e;
		E.push_back(e);
	}
}

void solve() {
	graph *G = new graph(N, E);
	G->get_current(I);
	delete G;

	for (uint i = 0; i < M; ++i) {
		cout << I[i] << endl;
	}
}

int main() {
	Init();
	solve();
}
