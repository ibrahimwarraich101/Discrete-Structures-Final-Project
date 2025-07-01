//#include <iostream>
//using namespace std;
//
//const int MAX = 100;
//
//int parent_find(int parents[], int node)
//{
//    if (parents[node] == node)
//        return node;
//    return parent_find(parents, parents[node]);
//}
//
//void set_of_union(int parents[], int ranks[], int node1, int node2)
//{
//    int rootU = parent_find(parents, node1);
//    int rootV = parent_find(parents, node2);
//
//    if (ranks[rootU] > ranks[rootV])
//    {
//        parents[rootV] = rootU;
//    }
//    else if (ranks[rootU] < ranks[rootV])
//    {
//        parents[rootU] = rootV;
//    }
//    else
//    {
//        parents[rootV] = rootU;
//        ranks[rootU]++;
//    }
//}
//
//void kruskal_MST(int adjacent_matrix[MAX][MAX], int num_of_vetices)
//{
//    int parents[MAX], ranks[MAX], mst_edges[MAX][3];
//    int edges[MAX * MAX][3];
//    int edge_count = 0;
//
//    for (int i = 0; i < num_of_vetices; i++)
//
//    {
//        parents[i] = i;
//        ranks[i] = 0;
//    }
//
//    for (int i = 0; i < num_of_vetices; i++)
//    {
//        for (int j = i + 1; j < num_of_vetices; j++)
//        {
//            if (adjacent_matrix[i][j] != 0) {
//                edges[edge_count][0] = i;
//                edges[edge_count][1] = j;
//                edges[edge_count][2] = adjacent_matrix[i][j];
//                edge_count++;
//            }
//        }
//    }
//
//    for (int i = 0; i < edge_count - 1; i++)
//    {
//        for (int j = i + 1; j < edge_count; j++)
//        {
//            if (edges[i][2] > edges[j][2])
//            {
//                swap(edges[i][0], edges[j][0]);
//                swap(edges[i][1], edges[j][1]);
//                swap(edges[i][2], edges[j][2]);
//            }
//        }
//    }
//
//    int mst_edge_count = 0, total_cost = 0;
//    for (int i = 0; i < edge_count && mst_edge_count < num_of_vetices - 1; i++)
//    {
//        int node1 = edges[i][0];
//        int node2 = edges[i][1];
//        int weight = edges[i][2];
//
//        if (parent_find(parents, node1) != parent_find(parents, node2))
//        {
//            mst_edges[mst_edge_count][0] = node1;
//            mst_edges[mst_edge_count][1] = node2;
//            mst_edges[mst_edge_count][2] = weight;
//            total_cost += weight;
//            mst_edge_count++;
//            set_of_union(parents, ranks, node1, node2);
//        }
//    }
//
//    cout << "\nKruskal's Minimum Spanning Tree(MST):\n";
//    for (int i = 0; i < mst_edge_count; i++)
//    {
//        cout << mst_edges[i][0] << " - " << mst_edges[i][1] << " Weight: " << mst_edges[i][2] << endl;
//    }
//    cout << "\nMinimum cost using the Kruskal's: " << total_cost << endl;
//}
//
//void prims_MST(int adjacent_matrix[MAX][MAX], int num_of_vetices)
//{
//    bool includedInMST[MAX]{};
//    int parent[MAX], key[MAX]{};
//    int total_cost = 0;
//
//    for (int i = 0; i < num_of_vetices; i++)
//    {
//        key[i] = 100000;
//        parent[i] = -1;
//        includedInMST[i] = false;
//    }
//
//    key[0] = 0;
//
//    for (int count = 0; count < num_of_vetices; count++)
//    {
//        int minKey = 100000, selectedVertex = -1;
//        for (int vertex = 0; vertex < num_of_vetices; vertex++)
//        {
//            if (!includedInMST[vertex] && key[vertex] < minKey)
//            {
//                minKey = key[vertex];
//                selectedVertex = vertex;
//            }
//        }
//
//        includedInMST[selectedVertex] = true;
//        total_cost += key[selectedVertex];
//
//        for (int vertex = 0; vertex < num_of_vetices; vertex++)
//        {
//            if (adjacent_matrix[selectedVertex][vertex] && !includedInMST[vertex] &&
//                adjacent_matrix[selectedVertex][vertex] < key[vertex]) {
//                key[vertex] = adjacent_matrix[selectedVertex][vertex];
//                parent[vertex] = selectedVertex;
//            }
//        }
//    }
//
//    cout << "\n\nPrim's Minimum Spanning Tree(MST):\n";
//    for (int i = 1; i < num_of_vetices; i++) {
//        cout << parent[i] << " - " << i
//            << " Weight: " << adjacent_matrix[i][parent[i]] << endl;
//    }
//    cout << "\nMinimum cost using the Prim's: " << total_cost << endl;
//}
//
//int main()
//{
//    int num_of_vetices;
//    int adjacent_matrix[MAX][MAX] = { 0 };
//
//    cout << "Enter the number of vertices: ";
//    cin >> num_of_vetices; cout << endl;
//
//    cout << "Enter the adjacency matrix (use '0' for no edge):\n";
//    for (int i = 0; i < num_of_vetices; i++)
//    {
//        for (int j = 0; j < num_of_vetices; j++)
//        {
//            cin >> adjacent_matrix[i][j];
//        }
//    }
//
//    kruskal_MST(adjacent_matrix, num_of_vetices);
//    prims_MST(adjacent_matrix, num_of_vetices);
//
//    cout << endl << endl;
//    system("pause");
//    return 0;
//}
