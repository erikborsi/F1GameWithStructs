#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;


struct Garage
{
    string nameOfTheTeam;
    int distance;
};

struct Driver 
{
    string nameOfDriver;
    int ageOfDriver;
    int skillLevelOfDriver;
    Garage garage;
};


int main()
{
    Garage garage1 = {"Mercedes", 0};
    Garage garage2 = {"McLaren", 0};
    Garage garage3 = {"Renault", 0};

    Driver driver1 = { "Lewis Hamilton", 36, 94, "Mercedes"};
    Driver driver2 = { "Sergio Perez", 31, 75, "Williams"};
    Driver driver3 = { "Daniel Ricciardo", 39, 87, "Renault"};
    

    int hoursofRace;
    int randomNumber;
    

    srand(time(NULL));


    string welcomeMessage = "Hi and Welcome to the F1 racing game \n"
        "Each racer will start from the start which is 0 \n"
        "Press enter to start the race \n(Results are updated every 3 seconds)";
    

    string racingSentencePartStartOne = "------ Results after ";
    string racingSentencePartStartTwo = " hours ------";
    string racingSentencePartOne = "Distance of ";
    string racingSentencePartTwo = ": ";
    string racingSentencePartThreeREUSED = " miles";
    string racingSentencePartEnd = "-----------------------------------\n";


    string congratulationsSentencePartStart = "\n\n---------- Final results ---------";
    string congratulationsSentencePartOne = "The ";
    string congratulationsSentencePartTwo = " team won \nthe wooden spoon \ndriven by ";
    string congratulationsSentencePartThree = "\nwith the distance of ";
    string congratulationsSentencePartEnd = "-----------------------------------";
    

    cout << welcomeMessage << endl;
    cin.ignore();


    for (hoursofRace = 0; hoursofRace < 5; hoursofRace++)
    {
        cout << racingSentencePartStartOne << hoursofRace + 1 << racingSentencePartStartTwo << endl;
        
        randomNumber = rand() % 10 + 1;
        driver1.garage.distance = driver1.garage.distance + randomNumber;
        cout << racingSentencePartOne << driver1.garage.nameOfTheTeam << racingSentencePartTwo 
        << driver1.garage.distance << racingSentencePartThreeREUSED << endl;

        randomNumber = rand() % 10 + 1;
        driver2.garage.distance = driver2.garage.distance + randomNumber;
        cout << racingSentencePartOne << driver2.garage.nameOfTheTeam << racingSentencePartTwo 
            << driver2.garage.distance << racingSentencePartThreeREUSED << endl;

        randomNumber = rand() % 10 + 1;
        driver3.garage.distance = driver3.garage.distance + randomNumber;
        cout << racingSentencePartOne << driver3.garage.nameOfTheTeam << racingSentencePartTwo
            << driver3.garage.distance << racingSentencePartThreeREUSED << endl;
        
        cout << racingSentencePartEnd << endl;

        chrono::seconds dura(3);
        this_thread::sleep_for(dura);
    }


    cout << congratulationsSentencePartStart << endl;


    if (driver1.garage.distance > driver2.garage.distance && driver1.garage.distance > driver3.garage.distance)
    {
        cout << congratulationsSentencePartOne << 
            driver1.garage.nameOfTheTeam << congratulationsSentencePartTwo <<
            driver1.nameOfDriver << congratulationsSentencePartThree <<
            driver1.garage.distance << racingSentencePartThreeREUSED << endl;
    }
    else if (driver2.garage.distance > driver1.garage.distance && driver2.garage.distance > driver3.garage.distance)
    {
        cout << congratulationsSentencePartOne <<
            driver2.garage.nameOfTheTeam << congratulationsSentencePartTwo <<
            driver2.nameOfDriver << congratulationsSentencePartThree <<
            driver2.garage.distance << racingSentencePartThreeREUSED << endl;
    }
    else if (driver3.garage.distance > driver1.garage.distance && driver3.garage.distance > driver2.garage.distance)
    {
        cout << congratulationsSentencePartOne <<
            driver3.garage.nameOfTheTeam << congratulationsSentencePartTwo <<
            driver3.nameOfDriver << congratulationsSentencePartThree <<
            driver3.garage.distance << racingSentencePartThreeREUSED << endl;
    }
    else 
    {
        cout << "There are more winners today!" << endl;
        cout << "Not yet finished!" << endl;
    }


    cout << congratulationsSentencePartEnd << endl;
}