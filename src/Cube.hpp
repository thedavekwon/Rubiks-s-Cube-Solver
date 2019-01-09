//
// Created by dodo on 1/5/19.
//
#ifndef RUBIKS_S_CUBE_SOLVER_CUBE_H
#define RUBIKS_S_CUBE_SOLVER_CUBE_H

#include <iostream>
#include <vector>

using namespace std;

class Cube {
private:
    vector<vector<int>> Up;
    vector<vector<int>> Down;
    vector<vector<int>> Left;
    vector<vector<int>> Right;
    vector<vector<int>> Front;
    vector<vector<int>> Back;

public:
    Cube() {
        Up = vector<vector<int>>(3, vector<int>(3, 0));
        Down = vector<vector<int>>(3, vector<int>(3, 5));
        Left = vector<vector<int>>(3, vector<int>(3, 2));
        Right = vector<vector<int>>(3, vector<int>(3, 1));
        Front = vector<vector<int>>(3, vector<int>(3, 4));
        Back = vector<vector<int>>(3, vector<int>(3, 3));
    }

    Cube(const Cube &c) {
        Up = c.Up;
        Down = c.Down;
        Left = c.Left;
        Right = c.Right;
        Front = c.Front;
        Back = c.Back;
    }

    void turnUp() {
        vector<int> tmp = Front[0];
        Front[0] = Right[0];
        Right[0] = Back[0];
        Back[0] = Left[0];
        Left[0] = tmp;
    }

    void turnCounterUp() {
        vector<int> tmp = Front[0];
        Front[0] = Left[0];
        Left[0] = Back[0];
        Back[0] = Right[0];
        Front[0] = tmp;
    }


    void turnDown() {
        vector<int> tmp = Front[0];
        Front[3] = Left[3];
        Left[3] = Back[3];
        Back[3] = Right[3];
        Front[3] = tmp;
    }

    void turnCounterDown() {
        vector<int> tmp = Front[3];
        Front[3] = Right[3];
        Right[3] = Back[3];
        Back[3] = Left[3];
        Left[3] = tmp;
    }

    void turnLeft() {
        //non face turns
        vector<int> tmp = {Front[0][0], Front[1][0], Front[2][0]};
        Front[0][0] = Up[0][0];
        Front[1][0] = Up[1][0];
        Front[2][0] = Up[2][0];
        Up[0][0] = Back[2][2];
        Up[1][0] = Back[1][2];
        Up[2][0] = Back[0][2];
        Back[0][2] = Down[2][0];
        Back[1][2] = Down[1][0];
        Back[2][2] = Down[0][0];
        Down[0][0] = tmp[0];
        Down[1][0] = tmp[1];
        Down[2][0] = tmp[2];
    }

    void turnCounterLeft() {
        //non face turns
        vector<int> tmp = {Front[0][0], Front[1][0], Front[2][0]};
        Front[0][0] = Down[0][0];
        Front[1][0] = Down[2][0];
        Front[2][0] = Down[2][0];
        Down[0][0] = Back[2][2];
        Down[1][0] = Back[1][2];
        Down[2][0] = Back[0][2];
        Back[0][2] = Up[2][0];
        Back[1][2] = Up[1][0];
        Back[2][2] = Up[0][0];
        Up[0][0] = tmp[0];
        Up[1][0] = tmp[1];
        Up[2][0] = tmp[2];
    }

    void turnRight() {

    }

    void turnCounterRight() {

    }


    void turnFront() {
        vector<int> tmp = Up[2];
        Up[2] = {Left[2][2], Left[1][2], Left[0][2]};
        Left[2][2] = Down[0][2]; Left[1][2] = Down[0][1]; Left[0][2] = Down[0][0];
        Down[0] = {Right[2][0], Right[1][0], Right[0][0]};
        Right[0][0] = tmp[0]; Right[1][0] = tmp[1]; Right[2][0] = tmp[2];
    }

    void turnCounterFront() {
        vector<int> tmp = Up[2];
        Up[2] = {Right[0][0], Right[1][0], Right[2][0]};
        Right[0][0] = Down[0][2]; Right[1][0] = Down[0][1]; Right[2][0] = Down[0][0];
        Down[0] = {Left[2][2], Left[1][2], Left[1][2]};
        Left[2][2] = tmp[0]; Left[1][2] = tmp[1]; Left[0][2] = tmp[2];
    }

    void turnBack() {
        vector<int> tmp = Up[0];
        Up[0] = {Right[0][2], Right[1][2], Right[2][2]};
        Right[0][2] = Down[2][2], Right[1][2] = Down[2][1], Right[2][2] = Down[2][0];
        Down[2] = {Left[0][0], Left[1][0], Left[2][0]};
        Left[0][0] = tmp[2]; Left[1][0] = tmp[1]; Left[2][0] = tmp[0];
    }

    void turnCounterBack() {
        vector<int> tmp = Up[0];
        Up[0] = {Left[2][0], Left[1][0], Left[0][0]};
        Left[2][0] = Down[2][2], Left[1][0] = Down[2][1], Left[0][0] = Down[2][0];
        Down[2] = {Right[2][2], Right[1][2], Right[0][2]};
        Right[0][2] = tmp[0]; Right[1][2] = tmp[1]; Right[2][2] = tmp[2];
    }

    friend ostream& operator<< (ostream &out, const Cube &c) {
        out << "       " << c.Down[0][0] << " " << c.Down[0][1] << " " << c.Down[0][2] << "       " << endl;
        out << "       " << c.Down[1][0] << " " << c.Down[1][1] << " " << c.Down[1][2] << "       " << endl;
        out << "       " << c.Down[2][0] << " " << c.Down[2][1] << " " << c.Down[2][2] << "       " << endl;

        out << "       " << c.Back[2][0] << " " << c.Back[2][1] << " " << c.Back[2][2] << "       " << endl;
        out << "       " << c.Back[1][0] << " " << c.Back[1][1] << " " << c.Back[1][2] << "       " << endl;
        out << "       " << c.Back[0][0] << " " << c.Back[0][1] << " " << c.Back[0][2] << "       " << endl;

        out << c.Left[2][0] << " " << c.Left[1][0] << " " << c.Left[0][0] << "  ";
        out << c.Up[0][0] << " " << c.Up[0][1] << " " << c.Up[0][2] << "  ";
        out << c.Right[0][2] << " " << c.Right[1][2] << " " << c.Right[2][2] << endl;

        out << c.Left[2][1] << " " << c.Left[1][1] << " " << c.Left[0][1] << "  ";
        out << c.Up[1][0] << " " << c.Up[1][1] << " " << c.Up[1][2] << "  ";
        out << c.Right[0][1] << " " << c.Right[1][1] << " " << c.Right[1][2] << endl;

        out << c.Left[2][2] << " " << c.Left[1][2] << " " << c.Left[0][2] << "  ";
        out << c.Up[2][0] << " " << c.Up[2][1] << " " << c.Up[2][2] << "  ";
        out << c.Right[0][0] << " " << c.Right[1][0] << " " << c.Right[2][0] << endl;

        out << "       " << c.Front[0][0] << " " << c.Front[0][1] << " " << c.Front[0][2] << "       " << endl;
        out << "       " << c.Front[1][0] << " " << c.Front[1][1] << " " << c.Front[1][2] << "       " << endl;
        out << "       " << c.Front[2][0] << " " << c.Front[2][1] << " " << c.Front[2][2] << "       " << endl;
        return out;
    }
};


#endif //RUBIKS_S_CUBE_SOLVER_CUBE_H
