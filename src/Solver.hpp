//
// Created by dodo on 1/11/19.
//

#ifndef RUBIKS_S_CUBE_SOLVER_SOLVER_H
#define RUBIKS_S_CUBE_SOLVER_SOLVER_H

#include <queue>
#include <unordered_map>

#include "Cube.hpp"


// hash_combine from boost library


class CubeHash {
public:
    std::size_t operator()(const Cube& cube) const {
        return cube.hash_function();
    }
};

class Node {
public:
    Cube cube;
    Node *prev;
    int moves;
    int prev_turn;

    Node(Node *_node) : cube(_node->cube), prev(_node) {
        prev_turn = 13;
        moves = _node->moves+1;
    }

    Node(Cube &_cube) : cube(_cube) {
        prev = nullptr;
        prev_turn = 13;
        moves = 0;
    }
};

class AStarCompare {
public:
    bool operator()(Node* n1, Node* n2) {
        return n1->cube.manhattanDistance()-n1->moves < n2->cube.manhattanDistance()-n1->moves ;
    }
};



class IDAStarSolver {
private:
    Cube cube;
    std::priority_queue<Node*, std::vector<Node*>, AStarCompare> pq;
    std::unordered_map<Cube, bool, CubeHash> map;
    int limit;
    int last;

public:
    IDAStarSolver(Cube &_cube) {
        cube = _cube;   
        int limit = cube.manhattanDistance();
    }

    Node* solve() {
        Node *root = new Node(cube);
        map[cube] = true;
        pq.push(root);
        while(!pq.empty()) {
            Node *currentNode = pq.top();
            //std::cout << currentNode->cube << " " << currentNode->cube.manhattanDistance() << std::endl;
            if (currentNode->cube.isSolved()) {
                std::cout << "solved" << std::endl;
                return currentNode;
            }
            pq.pop();
            for (int i = 0; i < 12; i++) {
                if (i % 2 == 0 && i == currentNode->prev_turn+1) continue;
                if (i % 2 == 1 && i == currentNode->prev_turn-1) continue;
                Node *next = new Node(currentNode);
                next->prev_turn = i;
                next->cube.turn(i);
                if (map.find(next->cube) != map.end() || next->cube.manhattanDistance() < limit) {
                    last = next->cube.manhattanDistance();
                    delete next;
                    continue;
                }
                pq.push(next);
            }
            if (pq.empty()) {
                pq.push(root);
                limit = std::max(limit, last);
            }
        }
    }
};


#endif //RUBIKS_S_CUBE_SOLVER_SOLVER_H
