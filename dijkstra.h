//
// Created by Roman on 27/3/26.
//

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <cmath>

using namespace std;

class Node {
    string name;
    double lat{}, lon{};
    double distance=INFINITY;
    double incomingDuration{};
    Node* parent=nullptr;
    bool isMarked=false;

public:
    Node() = default;
    Node(string n, double lat, double lon);

    [[nodiscard]] string getName() const;
    [[nodiscard]] double getLatitude() const;
    [[nodiscard]] double getLongitude() const;
    [[nodiscard]] double getDistance() const;
    [[nodiscard]] double getIncomingDuration() const;
    [[nodiscard]] Node *getParent() const;
    [[nodiscard]] bool getMarked() const;

    void setDistance(double d);
    void setIncomingDuration(double d);
    void setParent(Node* p);
    void setMarked(bool m);

    ~Node() = default;
};

class Edge {
    Node* from{};
    Node* to{};
    string dep_time;
    double duration{};
    double price{};

public:
    Edge() = default;
    Edge(Node* from, Node* to, string  dep_time, double duration, double price);

    [[nodiscard]] Node *getFrom() const;
    [[nodiscard]] Node *getTo() const;
    [[nodiscard]] double getDuration() const;
    [[nodiscard]] double getPrice() const;

    virtual ~Edge() = default;
};

class Dijkstra;

class Graph {
    friend class Dijkstra;

    int nodeCount;
    int edgeCount;
    Node** nodes = nullptr;
    Edge** edges = nullptr;

    [[nodiscard]] Node* findNode(const string& name) const;
public:
    Graph();
    ~Graph();

    [[nodiscard]] int getNodeCount() const;
    [[nodiscard]] int getEdgeCount() const;
};

class Dijkstra {
    friend class Graph;

    Node** markedNodes = nullptr;
    int markedNodeCount = 0;
    public:

    Dijkstra(const Graph& graph);
    ~Dijkstra();

    static int find_min_distance_ix(const Graph& graph);

    static void dijkstra_algo(const Graph& graph, const string& input);

    void find_trace(const Graph& graph, const Node* from, const string& input);
    void reversed_output() const;
    void dijkstra_funct(const Graph& graph, const string& from, const string& to);
};

#endif //DIJKSTRA_H

