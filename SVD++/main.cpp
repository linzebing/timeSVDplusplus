/*
Author: Zebing Lin
Email:linzebing1995@gmail.com
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
    double lr = 0.007;
    double theta = 0.005;
    int factor = 50;
    string trainFile = "train.txt";
    string crossFile = "cross.txt";
    string testFile = "test.txt";
    string outFile = "5120309085_5120309016_5120309005.txt";

    SVD svd(NULL,NULL,0,NULL,NULL, trainFile, crossFile, testFile, outFile, lr, theta, factor);
    double rmse = svd.MyTrain();
    return 0;
}
