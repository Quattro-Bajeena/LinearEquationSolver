#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <limits>
#include <iomanip>

#include "interval.h"
#include "utils.h"


using namespace interval_arithmetic;




inline void PrintMatrix(std::vector<std::vector<double>> matrix){

    for(int m =0; m < matrix.size(); m++){
        for(int n = 0; n < matrix[0].size(); n++){

            std::cout<<matrix[m][n]<<" ";
        }

        std::cout<<"\n";
    }


}

inline void PrintMatrix(std::vector<double> matrix){

    for(int m =0; m < matrix.size(); m++){
        std::cout<<matrix[m]<<"\n";
    }


}


inline void PrintMatrix(std::vector<std::vector<Interval<double>>> matrix){

    for(int m =0; m < matrix.size(); m++){
        for(int n = 0; n < matrix[0].size(); n++){
            std::string left, right;
            matrix[m][n].IEndsToStrings(left, right);

            std::cout<<left << ";" <<right << "  ";
        }

        std::cout<<"\n";
    }


}

inline void PrintMatrix(std::vector<Interval<double>> matrix){

    for(int m =0; m < matrix.size(); m++){
        //std::cout << "yo\n";
        std::string left, right;
        matrix[m].IEndsToStrings(left, right);
        std::cout<<left << ";"<<right<<"\n";
    }


}


inline std::vector<double> SolveEquation (std::vector<std::vector<double>> matrix,
                                  std::vector<double> constant_terms,
                                  double epsilon, int max_interations, int& done_iterations){

    std::vector<double> answers(matrix.size(), 0);
    std::vector<bool> stop_criteria(matrix.size(), false);

    int iterations = 0;


    while(std::any_of(std::begin(stop_criteria), std::end(stop_criteria),
                      [](bool b){return b==false;})){


        for(int i =0; i < matrix.size(); i++){
            double new_answer = constant_terms[i];

            double first_sum = 0;
            for(int j = 0; j < i; j++){
                first_sum += matrix[i][j] * answers[j];
            }
            new_answer -= first_sum;


            double second_sum = 0;
            for(int j = i + 1; j < matrix.size(); j++){
                second_sum += matrix[i][j] * answers[j];
            }
            new_answer -= second_sum;


            new_answer /= matrix[i][i];


            if(stop_criteria[i] == false){

                double current_epsilon = std::abs((new_answer - answers[i])/new_answer) * 100;
                stop_criteria[i] = current_epsilon < epsilon;
            }





            answers[i] = new_answer;

        }
        iterations++;

        if(iterations == max_interations){
            break;
        }

    }
    done_iterations = iterations;
    return answers;
}

inline std::vector<Interval<double>> SolveEquation (std::vector<std::vector<Interval<double>>> matrix,
                                  std::vector<Interval<double>> constant_terms,
                                  double epsilon, int max_interations, int& done_iterations){

    std::vector<Interval<double>> answers(matrix.size(), Interval<double>());
    std::vector<bool> stop_criteria(matrix.size(), false);

    int iterations = 0;


    while(std::any_of(std::begin(stop_criteria), std::end(stop_criteria),
                      [](bool b){return b==false;})){



        for(int i =0; i < matrix.size(); i++){
            std::cout << "debug 1\n";

            Interval<double> new_answer = constant_terms[i];

            Interval<double> first_sum = Interval<double>();
            for(int j = 0; j < i; j++){
                first_sum = first_sum +(matrix[i][j] * answers[j]) ;
            }
            new_answer = new_answer - first_sum;

            Interval<double> second_sum = Interval<double>();
            for(int j = i + 1; j < matrix.size(); j++){
                second_sum = second_sum + (matrix[i][j] * answers[j]);
            }
            new_answer = new_answer - second_sum;


            new_answer = new_answer / matrix[i][i];


            try{
                    if(stop_criteria[i] == false){
                    std::cout << "debug 5\n";
                    Interval<double> current_epsilon = IAbs((new_answer - answers[i])/new_answer) * 100;
                    std::cout << "debug 6\n";

                    std::string left, right;
                    current_epsilon.IEndsToStrings(left, right);
                    std::cout<<left << " ; " <<right << " \n";
                    std::cout << current_epsilon.a << " ; " << current_epsilon.b << "\n";

                    stop_criteria[i] = (current_epsilon.a < epsilon) && (current_epsilon.b < epsilon);
                    std::cout << "debug 7\n";
                }
            }
            catch(const runtime_error& e){
                std::cout<< e.what() << "\n";
                std::string left, right;
                new_answer.IEndsToStrings(left, right);
                std::cout<<left << ";"<<right<<"\n";
                std::cout << new_answer.a << ";"<<new_answer.b << "\n";
                done_iterations = iterations;
                return answers;

            }

            answers[i] = new_answer;

        }

        iterations++;
        if(iterations == max_interations){
            break;
        }

    }

    done_iterations = iterations;
    return answers;
}

inline std::vector<Interval<double>> DoubleVectorToInterval(const std::vector<double>& vec){

    std::vector<Interval<double>> vec_interval(vec.size());

    for(int i = 0; i < vec.size(); i++){
        vec_interval[i] = Interval<double>(vec[i], vec[i]);
    }

    return vec_interval;
}

inline std::vector<std::vector<Interval<double>>> DoubleMatrixToInterval(const std::vector<std::vector<double>>& matrix){

    //int matrix_size = matrix.size();
    std::vector<std::vector<Interval<double>>> matrix_interval;


    for(const std::vector<double>& row : matrix){
        matrix_interval.push_back(std::vector<Interval<double>>());
        for(const double number : row){
            matrix_interval.back().push_back(Interval<double>(number, number));
        }
    }



    return matrix_interval;
}


inline bool IsPositiveInt(const std::string& s){
    return !s.empty() && std::find_if(s.begin(), s.end(),
                        [](unsigned char c){return !std::isdigit(c);}) == s.end();

}


inline std::vector<std::vector<double>> ParseAppInputEquations(
                                                      const std::string& input,
                                                      const std::string& delimiter){

    std::vector<std::vector<double>> matrix;

    std::istringstream iss(input);

    int matrix_size = -1;
    for(std::string line; std::getline(iss, line); ){
        std::vector<double> row;

        std::string token;
        double number;
        size_t pos;
        while((pos = line.find(delimiter)) != std::string::npos){
            token = line.substr(0, pos);
            //std::cout << token << "\n";
            line.erase(0, pos + delimiter.length());

            try{
                trim(token);
                number = std::stod(token);
            }
            catch(const std::invalid_argument& e){
                std::cout << e.what() << "\n";
                return std::vector<std::vector<double>>();
            }

            row.push_back(number);
        }

        //Ugly, but the last number remains in "line" string
        try{
            trim(token);
            number = std::stod(line);
        }
        catch(const std::invalid_argument& e){
            std::cout << e.what() << "\n";
            return std::vector<std::vector<double>>();
        }
        row.push_back(number);


        //std::cout << line << "\n";
        //std::cout<< "\n";

        if(matrix_size == -1){
            matrix_size = row.size();
        }
        else if(matrix_size != row.size()){
            return std::vector<std::vector<double>>();
        }

        matrix.push_back(row);

    }

    if(matrix_size != matrix.size()){
        return std::vector<std::vector<double>>();
    }

    return matrix;

}

inline std::vector<double> ParseAppInputConstants(const std::string& input){
    std::vector<double> constants;
    std::istringstream iss(input);

    double number;
    for(std::string line; std::getline(iss, line); ){

        try{
            trim(line);
            number = std::stod(line);
        }
        catch(const std::invalid_argument& e){
            std::cout << e.what() << "\n";
            return std::vector<double>();
        }

        constants.push_back(number);

    }

    return constants;
}


/*
inline void Test1(){
    std::vector<std::vector<double>> matrix = {
        {10, -1, 2, 0},
        {-1, 11, -1, 3},
        {2, -1, 10, -1},
        {0, 3, -1, 8}

    };
    double epsilon = 0.00000000001f;
    std::vector<double> constant_terms = {6, 25, -11, 15};

    int done_iterations;
    std::vector<double> answers = SolveEquation(matrix, constant_terms, epsilon, 1000, done_iterations);


    std::cout<<"-----------------------\n";
    PrintMatrix(answers);


    std::cout<<"Hello World\n";



}

inline void Test2(){

    std::string number_str = "5.3";
    Interval<double> number = IntRead<double>("5.3");
    Interval<double> number2 = Interval<double>(1.3, 1.3);
    Interval<double> number3 = Interval<double>();

    std::vector<Interval<double>> constant_terms = {IntRead<double>("6"), IntRead<double>("25"), IntRead<double>("-11"), IntRead<double>("15")};

    std::vector<std::vector<Interval<double>>> matrix = {
        {IntRead<double>("10"), IntRead<double>("-1"), IntRead<double>("2"),  IntRead<double>("0")},
        {IntRead<double>("-1"), IntRead<double>("11"), IntRead<double>("-1"), IntRead<double>("3")},
        {IntRead<double>("2"),  IntRead<double>("-1"), IntRead<double>("10"), IntRead<double>("-1")},
        {IntRead<double>("0"),  IntRead<double>("3"),  IntRead<double>("-1"), IntRead<double>("8")}
    };

    //std::string left, right;
    //number2.IEndsToStrings(left,right);
    //std::cout<< left << " " << right <<"\n";

    std::cout<<"-------------------\n";
    PrintMatrix(constant_terms);
    std::cout<<"-------------------\n";
    PrintMatrix(matrix);

    std::cout<<"-------------------\n";
    std::vector<Interval<double>> answers = SolveEquation(matrix, constant_terms, 0.01, 1000);
    PrintMatrix(answers);


}
*/



