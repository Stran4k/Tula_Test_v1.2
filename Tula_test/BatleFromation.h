#pragma once
#ifndef BATLEFROMATION_H
#define BATLEFROMATION_H

#include <iostream>
#include <cmath>
#include <vector>



struct  Armored_Car
{
    double Coordinate_X;
    double Coordinate_Y;
    double Coordinate_Z;

    int  leteral_frequency;

    void AddCoordinates(const double& count_x, const double& count_y, const double& count_z);//добавление координат авто

};




struct Batle_Fromation : Armored_Car  //хранилище дистанции между бронеавтомобилями
{
    
    std::vector <int>  betweenTheseCars;

    std::vector <double> distaceBetweenCars;
};



class CreateBatlleMap :Batle_Fromation
{
private:

    bool param_frequency = false;
    Armored_Car* ArmCar;
    Batle_Fromation* BatForm;

public:

    CreateBatlleMap(const int n);//Cоздание и запонение информации о бронеавтомобилях и частоте

    void distribution(const int n); //Распределение частот между бронеавтомобилями

    void CommandCenter(const int n);// хранилище данных БМ

    double Distace_AC(const int numbBM_1, const int numbBM_2);//Расчет расстояния между бронеавтомобилями

    ~CreateBatlleMap();
};


#endif

