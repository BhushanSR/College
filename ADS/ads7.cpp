#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph
{
public:
    unordered_map<string, unordered_map<string, int>> adjMatrix;

    void addEdge(const string& u, const string& v, int w)
    {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    vector<pair<int, pair<string, string>>> kruskal()
    {
        vector<pair<int, pair<string, string>>> mst;

        // Create a union-find data structure to keep track of the connected components
        unordered_map<string, string> parent;
        for (const auto& pair : adjMatrix)
        {
            parent[pair.first] = pair.first;
        }

        // Create a priority queue to store the edges in ascending order of weight
        priority_queue<pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> pq;
        for (const auto& pair : adjMatrix)
        {
            const string& u = pair.first;
            for (const auto& edge : pair.second)
            {
                const string& v = edge.first;
                int weight = edge.second;
                pq.push({weight, {u, v}});
            }
        }

        // Add edges to the minimum spanning tree until all the vertices are connected
        while (!pq.empty())
        {
            // Get the edge with the lowest weight
            pair<int, pair<string, string>> edge = pq.top();
            pq.pop();

            // Check if the edge creates a cycle
            const string& u = edge.second.first;
            const string& v = edge.second.second;

            string rootU = findRoot(parent, u);
            string rootV = findRoot(parent, v);

            if (rootU != rootV)
            {
                // The edge does not create a cycle, so add it to the minimum spanning tree
                mst.push_back({edge.first, {u, v}});

                // Union the two connected components
                parent[rootU] = rootV;
            }
        }

        return mst;
    }

private:
    string findRoot(unordered_map<string, string>& parent, const string& node)
    {
        if (parent[node] != node)
        {
            parent[node] = findRoot(parent, parent[node]);
        }
        return parent[node];
    }
};

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<string> cities;

    // Accept names of cities
    for (int i = 0; i < n; i++)
    {
        string city;
        cout << "Enter name of city " << i+1 << ": ";
        cin >> city;
        cities.push_back(city);
    }

    Graph gr;

    // Add edges to the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int weight;
            cout << "Enter weight of edge between " << cities[i] << " and " << cities[j] << ": ";
            cin >> weight;

            gr.addEdge(cities[i], cities[j], weight);
        }
    }

    // Print the minimum spanning tree
    vector<pair<int, pair<string, string>>> mst = gr.kruskal();
    cout << "\nMinimum spanning tree:\n";
    for (const auto& edge : mst)
    {
        string city1 = edge.second.first;
        string city2 = edge.second.second;
        int weight = edge.first;
        cout << city1 << " - " << city2 << " : " << weight << endl;
    }

    return 0;
}