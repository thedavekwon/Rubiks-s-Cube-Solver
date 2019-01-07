//
// Created by dodo on 1/5/19.
//
#ifndef RUBIKS_S_CUBE_SOLVER_CUBE_H
#define RUBIKS_S_CUBE_SOLVER_CUBE_H

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
        Front[0][0] = Up[0][0]; Front[1][0] = Up[1][0]; Front[2][0] = Up[2][0];
        Up[0][0] = Back[2][2]; Up[1][0] = Back[1][2]; Up[2][0] = Back[0][2];
        Back[0][2] = Down[2][0]; Back[1][2] = Down[1][0]; Back[2][2] = Down[0][0];
        Down[0][0] =  tmp[0]; Down[1][0] = tmp[1]; Down[2][0] = tmp[2];
    }
    void turnCounterLeft() {
        //non face turns
        vector<int> tmp = {Front[0][0], Front[1][0], Front[2][0]};
        Front[0][0] = Down[0][0]; Front[1][0] = Down[2][0]; Front[2][0] = Down[2][0];
        Down[0][0] = Back[2][2]; Down[1][0] = Back[1][2]; Down[2][0] = Back[0][2];
        Back[0][2] = Up[2][0]; Back[1][2] = Up[1][0]; Back[2][2] = Up[0][0];
        Up[0][0] = tmp[0]; Up[1][0] = tmp[1]; Up[2][0] = tmp[2];
    }

    void turnRight() {

    }
    void turnCounterRight(){

    }


    void turnFront() {
        vector<int> tmp = Up[2];
        Up[2] = {Left[2][2], Left[1][2], Left[0][2]};
        Left[0][2] = Down[0][0]; Left[1][2] = Down[0][1]; Left[2][2] = Down[0][2];
        Down[0] = {Right[2][0], Right[1][0], Right[0][0]};
        Right[0][1] = tmp[0]; Right[1][0] = tmp[1]; Right[2][0] = tmp[2];
    }

    void turnCounterFront() {
        vector<int> tmp = Up[2];
        Up[2] = {Right[0][1], Right[1][0], Right[2][0]};
    }

    void turnBack() {

    }

    void turnCounterBack() {

    }

    void showTable(){

    }
};

//앙 기모띵 앙 도형띵

#endif //RUBIKS_S_CUBE_SOLVER_CUBE_H
