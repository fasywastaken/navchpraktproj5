//
// Created by Roman on 27/3/26.
//

#include "dijkstra.h"

#include <chrono>
#include <fstream>
#include <utility>

#include "utility.h"
using namespace std;

//Node
Node::Node(string name, const double lat, const double lon) : name{std::move(name)}, lat{lat}, lon{lon} {}

string Node::getName() const {return name;}
double Node::getLatitude() const {return lat;}
double Node::getLongitude() const {return lon;}
double Node::getDistance() const {return distance;}
double Node::getIncomingDuration() const {return incomingDuration;}
bool Node::getMarked() const {return isMarked;}
Node* Node::getParent() const {return parent;}

void Node::setDistance(const double new_distance) {distance = new_distance;}
void Node::setIncomingDuration(double new_duration) {incomingDuration = new_duration;}
void Node::setParent(Node* new_parent) {parent = new_parent;}
void Node::setMarked(const bool m) {isMarked = m;}

//Edge
Edge::Edge(Node *from, Node *to, string dep_time,const double duration, const double price): from{from}, to{to}, dep_time {std::move(dep_time)}, duration{duration}, price{price} {}

Node* Edge::getFrom() const {return from;}
Node* Edge::getTo() const {return to;}
double Edge::getDuration() const {return duration;};
double Edge::getPrice() const {return price;}

//Graph

Node * Graph::findNode(const string& name) const {
    for (int i=0; i < nodeCount; i++) {
        if (nodes[i]->getName() == name) {
            return nodes[i];
        }
    }
    return nullptr;
}

Graph::Graph() : nodeCount(0), edgeCount(0) {
    //dests
    fstream destfile("destinations.txt");
    if (!destfile.is_open()) {
        cerr << "Error opening destinations.txt" << endl;
        exit(1);
    } else {
        string name;
        double lat, lon;
        int i = 0;
        while (destfile >> name >> lat >> lon) {nodeCount++;}
        nodes = new Node *[nodeCount]();
        destfile.clear(); destfile.seekg (0, ios::beg);
        while (destfile >> name >> lat >> lon) {
            nodes[i] = new Node(name, lat, lon);
            i++;
        }
        destfile.close();
    }
    //trains
    fstream trainfile("trains.txt");
    if (!trainfile.is_open()) {
        cerr << "Error opening trains.txt" << endl;
        exit(1);
    } else {
        string from, to, dep_time;
        double duration, price;
        int i = 0;
        while (trainfile >> from >> to >> dep_time >> duration >> price) {++edgeCount;}
        edges = new Edge *[edgeCount]();

        trainfile.close(); trainfile.open("trains.txt");
        while (trainfile >> from >> to >> dep_time >> duration >> price) {
            Node* startNode = findNode(from);
            Node* toNode = findNode(to);

            if (startNode != nullptr && toNode != nullptr) {
                edges[i] = new Edge(startNode, toNode, dep_time, duration, price);
                i++;
            } else {
                cerr << "Dijkstra ignored train: " << startNode <<" -> "<<toNode;
            }
        }
        trainfile.close();
    }
}

Graph::~Graph() {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] != nullptr) delete nodes[i];
    }
    delete[] nodes;

    for (int i = 0; i < edgeCount; i++) {
        if (edges[i] != nullptr) delete edges[i];
    }
    delete[] edges;
}

int Graph::getNodeCount() const { return nodeCount;}
int Graph::getEdgeCount() const { return edgeCount;}

//Dijikstra

Dijkstra::Dijkstra(const Graph& graph) {
    markedNodes = new Node *[graph.getNodeCount()];
}
Dijkstra::~Dijkstra() {
    delete[] markedNodes;
}

int Dijkstra::find_min_distance_ix(const Graph &graph) {
    double min_dist= INFINITY;
    int ix = -1;

    for (int i = 0; i < graph.getNodeCount(); i++) {
        if (graph.nodes[i]->getMarked() != true && graph.nodes[i]->getDistance() < min_dist) {
            ix = i;
            min_dist = graph.nodes[i]->getDistance();
        }
    }
    return ix;
} //Pathfinding

void Dijkstra::dijkstra_algo(const Graph& graph, const string& input) {
    Node* startNode = graph.findNode(input);
    startNode->setDistance(0);

    for (int i=0; i <graph.getNodeCount(); i++) {
        int ix = find_min_distance_ix(graph);
        if (ix == -1) {break;}
        graph.nodes[ix]->setMarked(true);

        for (int j=0; j<graph.getEdgeCount(); j++) {
            if (graph.edges[j] == nullptr) continue;
            if (graph.edges[j]->getFrom()->getName() == graph.nodes[ix]->getName()) {
                Node* trialEdge = graph.edges[j]->getTo();

                double currentDist = graph.nodes[ix]->getDistance() + graph.edges[j]->getPrice();

                if (trialEdge->getMarked() == 0 && currentDist < trialEdge->getDistance()) {
                    trialEdge->setDistance(currentDist);
                    trialEdge->setParent(graph.nodes[ix]);

                    double timeSpent = graph.nodes[ix]->getIncomingDuration() + graph.edges[j]->getDuration();
                    trialEdge->setIncomingDuration(timeSpent);
                }
            }
        }
    }
} //Algorithm

void Dijkstra::find_trace(const Graph &graph, const Node *from, const string &input) {
    Node* startNode = graph.findNode(input);
    markedNodes[markedNodeCount] = startNode;
    ++markedNodeCount;

    if (startNode->getParent() == nullptr || startNode == from){return;}

    string nextNode = startNode->getParent()->getName();
    return find_trace(graph, from, nextNode);
} //Route tracer

void Dijkstra::reversed_output() const {
    double total_km{0};
    cout << " ";
    for (int i = markedNodeCount - 1; i >= 0; i--) {
        cout << markedNodes[i]->getName(); if (i>0) {
            cout << " -> ";

            double lat1 = markedNodes[i]->getLatitude();
            double lon1 = markedNodes[i]->getLongitude();
            double lat2 = markedNodes[i-1]->getLatitude();
            double lon2 = markedNodes[i-1]->getLongitude();

            total_km += utility::haversine(lat1, lon1, lat2, lon2);
        }
    }
    cout << endl << " Total Distance: " << total_km << "Km" << endl;
    cout << " Total Cost: " << markedNodes[0]->getDistance()<< "UAH" << endl;
    cout << " Total Duration: " << markedNodes[0]->getIncomingDuration() << "h" << endl;
} //output funct

void Dijkstra::dijkstra_funct(const Graph &graph, const string &from, const string &to) {
    markedNodeCount=0;
    dijkstra_algo(graph, from);
    Node * startNode = graph.findNode(from);
    find_trace(graph, startNode, to);
    reversed_output();
} //wrapper
