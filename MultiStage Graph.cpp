#include <iostream>
using namespace std;
const int node = 12;
const float null = INT_MAX;
int BackwardApproach(float MultiStageGraph[node][node])
{
 float distance[node];
 int previous[node];
 distance[node - 1] = 0;
 previous[node - 1] = -1;
 for (int row = node - 2; row >= 0; row--)
 {
 distance[row] = null;
 for (int column = 0; column < node; column++)
 {
 if (MultiStageGraph[row][column] == null)
 {
 continue;
 }
 if (distance[row] > MultiStageGraph[row][column] + distance[column])
 {
 distance[row] = MultiStageGraph[row][column] + distance[column];
 previous[row] = column;
 }
 }
 }
 return distance[0];
}
int forwardApproach(float graph[node][node])
{
 float distance[node][node];
 int forward[node][node];
 for (int i = 0; i < node; i++)
 {
 for (int j = 0; j < node; j++)
 {
 distance[i][j] = graph[i][j];
 if (graph[i][j] != null)
 {
 forward[i][j] = j;
 }
 else
 {
 forward[i][j] = -1;
 }
 }
 }
 for (int k = 0; k < node; k++)
 {
 for (int i = 0; i < node; i++)
 {
 for (int j = 0; j < node; j++)
 {
 if (distance[i][k] + distance[k][j] < distance[i][j])
 {
 distance[i][j] = distance[i][k] + distance[k][j];
forward[i][j] = forward[i][k];
 }
 }
 }
 }
 return distance[0][node - 1];
}
void FindShortestPath()
{
 /*cout << "*******************************************************************************" <<
endl;
 cout << "******************************Adjacency Table**************************" << endl;
 cout << "*******************************************************************************" << endl;
 cout << " |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 " << endl;
 cout<< " 1|0 |9 |7 |3 |2 |~ |~ |~ |~ |~ |~ |~ " << endl;
 cout << " 2|~ |0 |~ |~ |~ |~ |2 |1 |~ |~ |~ |~ " << endl;
 cout << " 3|~ |~ |0 |~ |~ |~ |7 |~ |~ |~ |~ |~ " << endl;
 cout << " 4|~ |~ |~ |0 |~ |~ |~ |11 |~ |~ |~ |~ " << endl;
 cout << " 5|~ |~ |~ |~ |0 |~ |11 |8 |~ |~ |~ |~ " << endl;
 cout << " 6|~ |~ |~ |~ |~ |0 |~ |~ |6 |5 |~ |~ " << endl;
 cout << " 7|~ |~ |~ |~ |~ |~ |0 |~ |4 |3 |~ |~ " << endl;
 cout << " 8|~ |~ |~ |~ |~ |~ |~ |0 |~ |5 |6 |~ " << endl;
 cout << " 9|~ |~ |~ |~ |~ |~ |~ |~ |0 |~ |~ |4 " << endl;
 cout << " 10|~ |~ |~ |~ |~ |~ |~ |~ |~ |0 |~ |2 " << endl;
 cout << " 11|~ |~ |~ |~ |~ |~ |~ |~ |~ |~ |0 |5 " << endl;
 cout << " 12|~ |~ |~ |~ |~ |~ |~ |~ |~ |~ |~ |0 " << endl;
 cout << endl << endl << endl;*/
 float graph[node][node] = { {0, 9, 7, 3, 2, null, null, null, null, null, null, null},
 {null, 0, null, null, null, null, 2, 1, null, null, null, null},
{null, null, 0, null, null, null, 7, null, null, null, null, null},
 {null, null, null, 0, null, null, null, 11, null, null, null, null},
 {null, null, null, null, 0, null, 11, 8, null, null, null, null},
{null, null, null, null, null, 0, null, null, 6, 5, null, null},
{null, null, null, null, null, null, 0, null, 4, 3, null, null},
{null, null, null, null, null, null, null, 0, null, 5, 6, null},
{null, null, null, null, null, null, null, null, 0, null, null, 4},
{null, null, null, null, null, null, null, null, null, 0, null, 2},
{null, null, null, null, null, null, null, null, null, null, 0, 5},
{null, null, null, null, null, null, null, null, null, null, null, 0} };
 int res = BackwardApproach(graph);
 cout << "\t\t Shortest distance using Backward Approach : " << res << endl;
 cout << endl;
 int resforwardApproach = forwardApproach(graph);
 cout << "\t\t Shortest distance using forward Approach : " << resforwardApproach << endl;
}
int main()
{

 FindShortestPath();
 cout << endl;
 return 0;
}
