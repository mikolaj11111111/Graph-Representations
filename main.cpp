#include<iostream>
#include<fstream>
#include<vector>
#include <list>

using namespace std;

//Macierz Sasiedztwa
vector<vector<int>> AdjacencyMatrix(int rows,  int columns) {
	ifstream adjacency_matrix_data("data.txt");
	if (adjacency_matrix_data) {
		cout << "Plik otwarty\n";
		vector<vector<int>> adjacency_matrix(rows, vector<int>(columns,0));

		//Insert Values
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				adjacency_matrix_data >> adjacency_matrix[i][j];
			}
		}

		//Show Values
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << adjacency_matrix[i][j] << " ";
			}
			cout << endl;
		}
		return adjacency_matrix;
		
	}
	else {
		cout << "Nie udalo sie otworzyc pliku\n";
		return {};
	}
	
}


struct Edge {
	int from, to, weight;
};
list<Edge> EdgeListBasedOnAM(vector<vector<int>>& adjacency_matrix, int rows, int columns) {
	list<Edge> edge_list;
	//Insert Values
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (adjacency_matrix[i][j] != 0) {
				edge_list.push_back({ i + 1, j + 1, adjacency_matrix[i][j] });
			}
		}
	}
	//Show Values
	for (auto& edge : edge_list) {
		cout << "od: " << edge.from << " do: " << edge.to << " waga: " << edge.weight << endl;
	}
	return edge_list;
}


void AdjacencyListBasedOnEL(list<Edge> edge_list, int rows, int columns) {
	vector<vector<pair<int, int>>> adjacency_list(rows + 1);
	//Get Values From Edge List
	for (auto& edge : edge_list) {
		int from = edge.from;
		int to = edge.to;
		int weight = edge.weight;

		adjacency_list[from].emplace_back(to, weight);

	}

	//Show Values
	cout << "Lista sasiedztwa:\n";
	for (int i = 1; i <= rows; i++) {
		cout << i << ": ";
		for (auto& neighbor : adjacency_list[i]) {
			cout << "do: " << neighbor.first << " waga: " << neighbor.second << ", ";
		}
		cout << endl;
	}
}

int main() {
	int rows = 8;
	int columns = 8;
	
	//Lista krawedzi na podstawie macierzy sasiedztwa
	vector<vector<int>> adjacency_matrix = AdjacencyMatrix(rows, columns);
	list<Edge> edge_list = EdgeListBasedOnAM(adjacency_matrix, rows, columns);

	//Lista sasiedztwa na podstawie listy krawedzi
	AdjacencyListBasedOnEL(edge_list, rows, columns);

	//
	return 0;

}