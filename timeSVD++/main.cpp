/*
Author: Guang Yang
*/
//This file is used to generate predictions.
#include <cmath>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <string.h>
#include <utility>
#include "SVD.cpp"

using namespace std;

int main() {
    string trainFile = "train.txt";  //set train data
    string crossFile = "cross.txt";  //set cross validation data
    string testFile = "test.txt";  //set test data
    string outFile = "5120309085_5120309016_5120309005.txt";  //set output data
    ifstream fp("training.txt");
    ofstream ft("train.txt");
    ofstream fc("cross.txt");
    srand(time(NULL));
    char s[2048];
    while (fp.getline(s, 2000)) {
        if (rand()%100==0) {
            fc << s << endl;
        }
        else {
            ft << s << endl;
        }
    }
    fp.close();
    ft.close();
    fc.close();
    SVD svd(NULL,NULL,0,NULL,NULL, trainFile, crossFile, testFile, outFile);
    double rmse = svd.MyTrain();     //train
    return 0;
}
