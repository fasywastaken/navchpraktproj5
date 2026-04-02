// //
// // Created by fasy on 27/3/26.
// //
// #ifndef DIJIKSTRA_H
// #define DIJIKSTRA_H
// #include <iostream>
// #include <cmath>
//
// #include "train.h"
// #ifndef NAVCHPRAKT5_DIJIKSTRA_H
// #define NAVCHPRAKT5_DIJIKSTRA_H
// using namespace std;
//
// class Node {
//     string name;
//     double distance=INFINITY;
//     Node* parent=nullptr;
//     bool visited=false;
//
// public:
//     Node() = default;
//     Node(string n);
//
//     [[nodiscard]] string getName() const;
//     [[nodiscard]] int getDistance() const;
//     [[nodiscard]] bool getParent() const;
//     [[nodiscard]] bool getVisited() const;
//
//     void setDistance(int d);
//     void setParent(Node* p);
//     void setVisited(bool v);
//
//     ~Node() = default;
// };
//
// class Edge {
//     Node* from;
//     Node* to;
//     double price;
//
// public:
//     Edge() = default;
//     Edge(Node* from, Node* to, double price);
//
//     Node* getFrom();
//     Node* getTo();
//     double getPrice();
//     virtual ~Edge() = default;
// };
//
// class Dijikstra;
//
// class Graph {
//     friend class Dijikstra;
//     int nodeCount;
//     int edgeCount;
//     Node** nodes = nullptr;
//     Edge** edges = nullptr;
//
//     Node* findNode(string name);
// public:
//     Graph() : nodeCount(0), edgeCount(0) {
//         string name;
//         string a;
//         string b;
//         double p;
//     };
//
//
//
// };
//
//


// #endif //NAVCHPRAKT5_DIJIKSTRA_H
// #endif // DIJIKSTRA_H
