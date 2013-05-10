#include <opencv2\opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

void main() {
    //read_mat
    FILE* file = fopen("PPoo", "rb");
    if (file == NULL) { cout<<"missing file PPoo ...."<<endl; exit(1); }
    int m = 0; int n = 0; int c = 0; int s = 0;
    fread(&m, sizeof(int), 1, file);
    fread(&n, sizeof(int), 1, file);
    fread(&c, sizeof(int), 1, file);
    fread(&s, sizeof(int), 1, file);
    cout<<m<<" x "<<n<<" x "<<c<<endl;

    char* data = new char[m * n * sizeof(double)];
    fread(data, sizeof(double), m*n, file);

    fclose(file);
    Mat M(m, n, CV_64F, data);

    cout<<"svd begin ......"<<endl;
    SVD svd(M);
    cout<<"svd end"<<endl;
}
