#include <iostream>
using namespace std;

#define N 10

struct Graph {

	int size;
	bool point[N][N];

	void Input() {

		cout << "Count of heads = ";
		cin >> size;

		cout << "Input graph: " << endl;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> point[i][j];


	}
};
void printG(Graph G) {

	for (int i = 0; i < G.size; i++) {
		cout << i + 1 << " : ";
		for (int j = 0; j < G.size; j++)
			if (G.point[i][j]) cout << j + 1 << " ";
		cout << endl;
	}
}
Graph mergeG(Graph G1, Graph G2) {

	int minSize = min(G1.size, G2.size);

	if (minSize == G1.size) {
		for (int i = 0; i < minSize; i++)
			for (int j = 0; j < minSize; j++)
				G2.point[i][j] += G1.point[i][j];
		return G2;
	}
	else {
		for (int i = 0; i < minSize; i++)
			for (int j = 0; j < minSize; j++)
				G1.point[i][j] += G2.point[i][j];
		return G1;
	}

}

int main() {

	Graph G1, G2;

	G1.Input();
	G2.Input();

	printG(mergeG(G1, G2));


	return 0;
}