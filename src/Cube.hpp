//
// Created by dodo on 1/5/19.
//
#ifndef RUBIKS_S_CUBE_SOLVER_CUBE_H
#define RUBIKS_S_CUBE_SOLVER_CUBE_H

#include <functional>
#include <iostream>
#include <random>
#include <vector>

class Cube {
private:
    std::vector<std::vector<int>> Up;
    std::vector<std::vector<int>> Down;
    std::vector<std::vector<int>> Left;
    std::vector<std::vector<int>> Right;
    std::vector<std::vector<int>> Front;
    std::vector<std::vector<int>> Back;

public:
    Cube() {
        Up = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
        Down = std::vector<std::vector<int>>(3, std::vector<int>(3, 5));
        Left = std::vector<std::vector<int>>(3, std::vector<int>(3, 2));
        Right = std::vector<std::vector<int>>(3, std::vector<int>(3, 1));
        Front = std::vector<std::vector<int>>(3, std::vector<int>(3, 4));
        Back = std::vector<std::vector<int>>(3, std::vector<int>(3, 3));
    }

    Cube(Cube &c) {
        Up = c.Up;
        Down = c.Down;
        Left = c.Left;
        Right = c.Right;
        Front = c.Front;
        Back = c.Back;
    }

    void turnCW(std::vector<std::vector<int>> &face){
        //face edge turns
        int tmp1 = face[0][0];
        face[0][0] = face[2][0];
        face[2][0] = face[2][2];
        face[2][2] = face[0][2];
        face[0][2] = tmp1;
        //face vertices turns
        int tmp2 = face[0][1];
        face[0][1] = face[1][0];
        face[1][0] = face[2][1];
        face[2][1] = face[1][2];
        face[1][2] = tmp2;
    }

    void turnCCW(std::vector<std::vector<int>> &face){
        //face edge turns
        int tmp1 = face[0][0];
        face[0][0] = face[0][2];
        face[0][2] = face[2][2];
        face[2][2] = face[2][0];
        face[2][0] = tmp1;
        //face vertices turns
        int tmp2 = face[0][1];
        face[0][1] = face[1][2];
        face[1][2] = face[2][1];
        face[2][1] = face[1][0];
        face[1][0] = tmp2;                        
    }

    void turnUp() {
        //non face turns
        std::vector<int> tmp = Front[0];
        Front[0] = Right[0];
        Right[0] = Back[0];
        Back[0] = Left[0];
        Left[0] = tmp;  
        //face turns
        turnCW(Up);                               
    }

    void turnCounterUp() {
        //non face turns
        std::vector<int> tmp = Front[0];
        Front[0] = Left[0];
        Left[0] = Back[0];
        Back[0] = Right[0];
        Right[0] = tmp;
        //face turns
        turnCCW(Up);
    }


    void turnDown() {
        //non face turns
        std::vector<int> tmp = Front[2];
        Front[2] = Left[2];
        Left[2] = Back[2];
        Back[2] = Right[2];
        Right[2] = tmp;
        //face turns
        turnCW(Down);
    }

    void turnCounterDown() {
        //non face turns
        std::vector<int> tmp = Front[2];
        Front[2] = Right[2];
        Right[2] = Back[2];
        Back[2] = Left[2];
        Left[2] = tmp;
        //face turns
        turnCCW(Down);
    }

    void turnLeft() {
        //turn left face 90 deg cw
        //non face turns
        std::vector<int> tmp = {Front[0][0], Front[1][0], Front[2][0]};
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
        //face turns
        turnCW(Left);
    }

    void turnCounterLeft() {
        //turn left face 90 deg ccw
        //non face turns
        std::vector<int> tmp = {Front[0][0], Front[1][0], Front[2][0]};
        Front[0][0] = Down[0][0];
        Front[1][0] = Down[1][0];
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
        //face turns
        turnCCW(Left);
    }

    void turnRight() {
        //turn right face 90 deg cw
        //non face turns
        std::vector<int> tmp = {Front[0][2], Front[1][2], Front[2][2]};
        Front[0][2] = Down[0][2];
        Front[1][2] = Down[1][2];
        Front[2][2] = Down[2][2];
        Down[0][2] = Back[2][0];
        Down[1][2] = Back[1][0];
        Down[2][2] = Back[0][0];
        Back[0][0] = Up[2][2];
        Back[1][0] = Up[1][2];
        Back[2][0] = Up[0][2];
        Up[0][2] = tmp[0];
        Up[1][2] = tmp[1];
        Up[2][2] = tmp[2];
        //face turns
        turnCW(Right);
    }

    void turnCounterRight() {
        //turn right face 90 deg ccw
        //non face turns
        std::vector<int> tmp = {Front[0][2], Front[1][2], Front[2][2]};
        Front[0][2] = Up[0][2];
        Front[1][2] = Up[1][2];
        Front[2][2] = Up[2][2];
        Up[0][2] = Back[2][0];
        Up[1][2] = Back[1][0];
        Up[2][2] = Back[0][0];
        Back[0][0] = Down[2][2];
        Back[1][0] = Down[1][2];
        Back[2][0] = Down[0][2];
        Down[0][2] = tmp[0];
        Down[1][2] = tmp[1];
        Down[2][2] = tmp[2];
        //face turns
        turnCCW(Right);
    }


    void turnFront() {
        std::vector<int> tmp = Up[2];
        Up[2] = {Left[2][2], Left[1][2], Left[0][2]};
        Left[2][2] = Down[0][2];
        Left[1][2] = Down[0][1];
        Left[0][2] = Down[0][0];
        Down[0] = {Right[2][0], Right[1][0], Right[0][0]};
        Right[0][0] = tmp[0];
        Right[1][0] = tmp[1];
        Right[2][0] = tmp[2];
        //face turn
        turnCW(Front);
    }

    void turnCounterFront() {
        std::vector<int> tmp = Up[2];
        Up[2] = {Right[0][0], Right[1][0], Right[2][0]};
        Right[0][0] = Down[0][2];
        Right[1][0] = Down[0][1];
        Right[2][0] = Down[0][0];
        Down[0] = {Left[2][2], Left[1][2], Left[1][2]};
        Left[2][2] = tmp[0];
        Left[1][2] = tmp[1];
        Left[0][2] = tmp[2];
        //face turn
        turnCCW(Front);
    }

    void turnBack() {
        std::vector<int> tmp = Up[0];
        Up[0] = {Right[0][2], Right[1][2], Right[2][2]};
        Right[0][2] = Down[2][2];
        Right[1][2] = Down[2][1];
        Right[2][2] = Down[2][0];
        Down[2] = {Left[0][0], Left[1][0], Left[2][0]};
        Left[0][0] = tmp[2];
        Left[1][0] = tmp[1];
        Left[2][0] = tmp[0];
        //face turn
        turnCW(Back);
    }

    void turnCounterBack() {
        std::vector<int> tmp = Up[0];
        Up[0] = {Left[2][0], Left[1][0], Left[0][0]};
        Left[2][0] = Down[2][2];
        Left[1][0] = Down[2][1];
        Left[0][0] = Down[2][0];
        Down[2] = {Right[2][2], Right[1][2], Right[0][2]};
        Right[0][2] = tmp[0];
        Right[1][2] = tmp[1];
        Right[2][2] = tmp[2];
        //face turn
        turnCCW(Back);
    }

    void turn(int num) {
        switch (num) {
            case 1:
                turnUp();
                break;
            case 2:
                turnCounterUp();
                break;
            case 3:
                turnDown();
                break;
            case 4:
                turnCounterDown();
                break;
            case 5:
                turnLeft();
                break;
            case 6:
                turnCounterLeft();
                break;
            case 7:
                turnRight();
                break;
            case 8:
                turnCounterRight();
                break;
            case 9:
                turnFront();
                break;
            case 10:
                turnCounterFront();
                break;
            case 11:
                turnBack();
                break;
            case 12:
                turnCounterBack();
                break;
            default:
                break;
        }
    }

    void shuffle(int num) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 12);
        auto command = std::bind(distribution, generator);
//        std::vector<char> shuffle_commands;
        for (int i = 0; i < num; i++) {
            int com = command();
            turn(com);
        }
    }

    bool isSolved() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (Up[i][j] != Up[1][1] || Down[i][j] != Down[1][1] || Left[i][j] != Left[1][1] || Right[i][j] != Right[1][1] || Front[i][j] != Front[1][1] || Back[i][j] != Back[1][1])
                    return false;
            }
        }
    }

    int manhattanDistance() {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (Up[i][j] != Up[1][1]) cnt++;
                if (Down[i][j] != Down[1][1]) cnt++;
                if (Left[i][j] != Left[1][1]) cnt++;
                if (Right[i][j] != Right[1][1]) cnt++;
                if (Front[i][j] != Front[1][1]) cnt++;
                if (Back[i][j] != Back[1][1]) cnt++;
            }
        }
        return -cnt;
    }

    friend std::ostream &operator<<(std::ostream &out, const Cube &c) {
        out << "       " << c.Down[0][0] << " " << c.Down[0][1] << " " << c.Down[0][2] << "       " << "\n";
        out << "       " << c.Down[1][0] << " " << c.Down[1][1] << " " << c.Down[1][2] << "       " << "\n";
        out << "       " << c.Down[2][0] << " " << c.Down[2][1] << " " << c.Down[2][2] << "       " << "\n";

        out << "       " << c.Back[2][0] << " " << c.Back[2][1] << " " << c.Back[2][2] << "       " << "\n";
        out << "       " << c.Back[1][0] << " " << c.Back[1][1] << " " << c.Back[1][2] << "       " << "\n";
        out << "       " << c.Back[0][0] << " " << c.Back[0][1] << " " << c.Back[0][2] << "       " << "\n";

        out << c.Left[2][0] << " " << c.Left[1][0] << " " << c.Left[0][0] << "  ";
        out << c.Up[0][0] << " " << c.Up[0][1] << " " << c.Up[0][2] << "  ";
        out << c.Right[0][2] << " " << c.Right[1][2] << " " << c.Right[2][2] << "\n";

        out << c.Left[2][1] << " " << c.Left[1][1] << " " << c.Left[0][1] << "  ";
        out << c.Up[1][0] << " " << c.Up[1][1] << " " << c.Up[1][2] << "  ";
        out << c.Right[0][1] << " " << c.Right[1][1] << " " << c.Right[1][2] << "\n";

        out << c.Left[2][2] << " " << c.Left[1][2] << " " << c.Left[0][2] << "  ";
        out << c.Up[2][0] << " " << c.Up[2][1] << " " << c.Up[2][2] << "  ";
        out << c.Right[0][0] << " " << c.Right[1][0] << " " << c.Right[2][0] << "\n";

        out << "       " << c.Front[0][0] << " " << c.Front[0][1] << " " << c.Front[0][2] << "       " << "\n";
        out << "       " << c.Front[1][0] << " " << c.Front[1][1] << " " << c.Front[1][2] << "       " << "\n";
        out << "       " << c.Front[2][0] << " " << c.Front[2][1] << " " << c.Front[2][2] << "       " << "\n";
        return out;
    }

    bool operator==(const Cube &c) const {
        return Up == c.Up && Down == c.Down && Left == c.Left && Right == c.Right &&
               Front == c.Front && Back == c.Back;
    }

    std::size_t hash_function() const {
        std::size_t seed = 0;
        seed = seed ^ (std::hash<std::vector<std::vector<int>>>{}(Up) << 1);
        return seed;
    }
};

void test() {
    Cube c1, c2;
    c1.turnFront();
    c1.turnCounterFront();
    if (!(c1 == c2)) std::cout << "front error" << std::endl;
    c1.turnBack();
    c1.turnCounterBack();
    if (!(c1 == c2)) std::cout << "back error" << std::endl;
    c1.turnLeft();
    c1.turnCounterLeft();
    if (!(c1 == c2)) std::cout << "left error" << std::endl;
    c1.turnRight();
    c1.turnCounterRight();
    if (!(c1 == c2)) std::cout << "right error" << std::endl;
    c1.turnUp();
    c1.turnCounterUp();
    if (!(c1 == c2)) std::cout << "up error" << std::endl;
    c1.turnDown();
    c1.turnCounterDown();
    if (!(c1 == c2)) std::cout << "down error" << std::endl;
};

#endif //RUBIKS_S_CUBE_SOLVER_CUBE_H
