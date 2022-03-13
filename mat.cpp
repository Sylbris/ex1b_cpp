#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "mat.hpp"
using namespace std;

const int ASCII_LOWER_BOUND = 33;
const int ASCII_UPPER_BOUND = 126;

namespace ariel
{
    string mat(int col, int row, char sym1, char sym2){
        
        //Edge cases for column & row.
        if(col < 1 || row < 1){
            throw invalid_argument("column or row cannot be less then 1!");
        }
        if(col % 2 == 0|| row % 2 == 0){
            throw invalid_argument("INVALID column or row number.");
        }

        //Invalid chars.
        if((int)sym1 < ASCII_LOWER_BOUND || (int)sym2 < ASCII_LOWER_BOUND || (int)sym1 > ASCII_UPPER_BOUND || (int)sym2 > ASCII_UPPER_BOUND){
            throw invalid_argument("Invalid chars inserted.");
        }

        //init
        // char carpet[row][col];
        std::vector<std::vector<char>> carpet(row, std::vector<char>(col, 0));

        int flag = 1; //sym1 first.

        //layer of carpet
        int layer = 0;

        for(layer = 0; layer <= col-layer && layer <= row-layer ; layer++) {

            //insert upper part of layer
            for (int i = 0 + layer; i < col - layer; i++) {
                if(flag == 1) {
                    carpet[layer][i] = sym1;
                }
                else {
                    carpet[layer][i] = sym2;
                }
            }
            //insert leftmost part of layer
            for (int i = layer; i < row - layer; i++) {
                if(flag == 1) {
                    carpet[i][layer] = sym1;
                }
                else
                {
                    carpet[i][layer] = sym2;
                }
            }

            //insert bottom part of layer
            for (int i = layer; i < row - layer; i++) {
                if(flag == 1) {
                    carpet[i][col - 1 - layer] = sym1;
                }
                else {
                    carpet[i][col - 1 - layer] = sym2;
                }
            }

            //insert rightmost part of layer.
            for (int i = layer; i < col - layer; i++) {
                if(flag == 1) {
                    carpet[row - 1 - layer][i] = sym1;
                }
                else {
                    carpet[row - 1 - layer][i] = sym2;
                }
            }

            flag = 1-flag;
        }

        string ans;
        for(int i = 0; i<row; i++){
            for(int j =0; j<col; j++){
                ans += carpet[i][j];
                // cout << carpet[i][j];
            }
            // cout << "\n" ;
            ans += "\n";
        }
        // cout << "\n" ;

        return ans;
    }
}