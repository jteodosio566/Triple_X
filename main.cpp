//
//  main.cpp
//  TripleX.cpp
//
//  Created by JOSE M TEODOSIO MEZA 2017 on 8/17/20.
//  Copyright © 2020 MacBook Pro 2017. All rights reserved.
//
/* This is a game where the user has to use math to guess a 3 digit code*/
#include <iostream>
#include <ctime>

void Welcome_Message(int difficulty)
{
    //Welcome message
    std::cout << "You are a secret agent breaking into a level " << difficulty << " secure server room";
    std::cout << std::endl;
    std::cout << "Enter the correct code to continue";
}
bool Play_Game(int difficulty)
{
    Welcome_Message(difficulty);
    //Declare 3 number code
    const int Code_a = (rand() % (4 + difficulty)) + 1;//First#Code random #
    const int Code_b = (rand() % (4 + difficulty)) + 1;//Second#Code random #
    const int Code_c = (rand() % (4 + difficulty)) + 1;//Third#Code random #
    const int Code_Sum = Code_a + Code_b + Code_c;//First Hint
    const int Code_Product = Code_a * Code_b * Code_c; //Second Hint
    
    //print sum and product hints
    std::cout << std::endl;
    std::cout << "There are 3 digits in the code" << std::endl;
    std::cout << "The sum of the 3 digits is " << Code_Sum << std::endl;
    std::cout << "The product of the 3 digits is " << Code_Product << std::endl;
    
    int Guess_a, Guess_b, Guess_c;//Variables inputs of user
    
    std::cout << "DARE TO ENTER THE CODE with spaces" << std::endl;//prompt the user to enter code
    std::cin >> Guess_a >> Guess_b >> Guess_c;
    std::cout << "You entered: " << Guess_a << Guess_b << Guess_c << std::endl;
    
    //Values to compare the right answer
    int Guess_Sum = Guess_a + Guess_b + Guess_c;
    int Guess_Product = Guess_a * Guess_b * Guess_c;
    
    //check if values are equals
    if(Guess_Sum == Code_Sum && Guess_Product == Code_Product)
    {
        std::cout << "Congratulations you have break my barrier" << std::endl;
        return true;
    }
    else
    {
        std::cout << " YOU LOSE LEARN TO HACK" << std::endl;
        return false;
    }
}
int main()
{
    srand(time(NULL));//creates a new random sequence based on time of the day
    int lvl_dif = 1;//level dificulty
    const int max_dif = 5;//max diff
    
    while(lvl_dif <= max_dif)
    {
        bool lvl_complete = Play_Game(lvl_dif);
        std::cin.clear();//clears any errors
        std::cin.ignore();//discards the buffer
        if (lvl_complete)//increase difficulty
        {
            ++ lvl_dif;
        }
    }
    std::cout << "GREAT JOB AGGENT, YOU HAVE ALL THE FILES" << std::endl;
    return 0;
}
