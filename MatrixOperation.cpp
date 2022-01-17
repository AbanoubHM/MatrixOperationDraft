
#include <iostream>
#include<string>
#include <sstream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;
int row1, col1, row2, col2;

vector<vector<double>> stringToMat(string str,int& rows,int& col){
    
        vector<string> v;
        vector<string> v2;
        stringstream ss(str);
        vector<vector<double>> mat;
        int itr = 1;
        int f = 0;

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        rows = v.size();

        for (size_t i = 0; i < v.size(); i++) {
            stringstream ssub(v[i]);
            vector<double> vv1;

            while (ssub.good()) {
                string s2;
                getline(ssub, s2, ' ');
                v2.push_back(s2);
                stringstream sss(v2[f++]);
                double x;
                sss >> x;
                vv1.push_back(x);
                
            }
            if (itr++ == 1)col = v2.size();
            mat.push_back(vv1);
            ssub.str("");
        }
        
        return mat;
        

}
vector<vector<double>> sumMat(vector<vector<double>> mat1, vector<vector<double>> mat2) {
    vector<vector<double>> mat;
    for (size_t i = 0; i < row1; i++){
        vector<double> row;
        for (size_t k = 0; k < col1; k++)
        {
            double x = mat1[i][k] + mat2[i][k];
            row.push_back(x);
        }
        mat.push_back(row);
    }
    return mat;
}
vector<vector<double>> subtMat(vector<vector<double>> mat1, vector<vector<double>> mat2) {
    vector<vector<double>> mat;
    for (size_t i = 0; i < row1; i++) {
        vector<double> row;
        for (size_t k = 0; k < col1; k++)
        {
            double x = mat1[i][k] - mat2[i][k];
            row.push_back(x);
        }
        mat.push_back(row);
    }
    return mat;
}
vector<vector<double>> mulMat(vector<vector<double>> mat1, vector<vector<double>> mat2) {
    vector<vector<double>> mat;
 
    for (size_t i = 0; i < row1; i++) {
        vector<double> row;
        for (size_t j = 0; j < col2; j++)
        {        
            double x=0;
            for (size_t k = 0; k < col1; k++)
            {
                 x+= (mat1[i][k] * mat2[k][j]);
            }
            row.push_back(x);

        }
        mat.push_back(row);
    }
    return mat;
}
void printMat(vector<vector<double>> mat,int rows , int col) {
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < col; j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {

    vector<vector<double>> mat1, mat2, matres;
    string str, sign;
    getline(cin, str);
    mat1 = stringToMat(str,row1,col1);
    getline(cin, sign);
    getline(cin, str);
    mat2 = stringToMat(str,row2,col2);
    if (sign == "+") {
        if (row1 == row2 && col1 == col2) {
            matres = sumMat(mat1, mat2);
        }
        else cout << "ERROR!";
    }
    if (sign == "-") {
        if (row1 == row2 && col1 == col2) {
            matres = subtMat(mat1, mat2);
        }
        else cout << "ERROR!";
    }
    if (sign == "*") {
        if (col1 == row2) {
            matres = mulMat(mat1, mat2);

        }
        else cout << "ERROR!";
    }
    

    printMat(matres, row1, col2);
}