#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "/usr/include/mkl/mkl.h"
#include <chrono>
#include <string.h>
#include "dnn_weights.h"
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef struct
{
    int label;
    float prob;
} pred_t;

float soft_max(float *vector, int index, int l)
{
    // int l = sizeof(vector);
    float deno = 0;
    for (int i = 0; i < l; i++)
    {
        deno += exp(vector[i]);
    }
    float nume = exp(vector[index]);
    float ans = nume / deno;
    return ans;
}

float *soft_max_vec(float *input, int l)
{
    // int l = sizeof(input);
    float *output = (float *)mkl_malloc(l * sizeof(float), 64);
    for (int i = 0; i < l; i++)
    {
        output[i] = soft_max(input, i, l);
    }
    return output;
}

float relu(float x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return 0;
    }
}

float *relu_mat(float *input, int row, int col)
{

    float *output = (float *)mkl_malloc(row * col * sizeof(float),64);
    for (int i = 0; i < row * col; i++)
    {

        output[i] = relu(input[i]);
    }
    return output;
}

float *dnn(string filename3)
{

    ifstream infile3;
    infile3.open(filename3);

    if(!infile3.is_open()){
        cout << "The entered mfcc_feautures file does not exist. Please enter correct input file name" << endl;
        float* fl = (float *)mkl_malloc(1 * 12 * sizeof(float),64);
        return fl;
    }

    float *inputmatrix = (float *)mkl_malloc(1 * 250 * sizeof(float),64);

    for (int i = 0; i < 1 * 250; i++)
    {
        infile3 >> inputmatrix[i];
    
    }

    float weightmatrix[] = IP1_WT;

    float biasmatrix[] = IP1_BIAS;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 250, 1, inputmatrix, 250, weightmatrix, 144, 1, biasmatrix, 144);

    float *relumatrix = (float *)mkl_malloc(144 * 1 * sizeof(float),64);

    relumatrix = relu_mat(biasmatrix, 1, 144);

    float weightmatrix2[] = IP2_WT;
    float biasmatrix2[] = IP2_BIAS;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 144, 1, relumatrix, 144, weightmatrix2, 144, 1, biasmatrix2, 144);

    float *relumatrix2 = (float *)mkl_malloc(144 * 1 * sizeof(float),64);
    relumatrix2 = relu_mat(biasmatrix2, 1, 144);

    float weightmatrix3[] = IP3_WT;
    float biasmatrix3[] = IP3_BIAS;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 144, 1, relumatrix2, 144, weightmatrix3, 144, 1, biasmatrix3, 144);

    float *relumatrix3 = (float *)mkl_malloc(144 * 1 * sizeof(float),64);
    relumatrix3 = relu_mat(biasmatrix3, 1, 144);

    float weightmatrix4[] = IP4_WT;
    float biasmatrix4[] = IP4_BIAS;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 12, 144, 1, relumatrix3, 144, weightmatrix4, 12, 1, biasmatrix4, 12);

    float *relumatrix4 = (float *)mkl_malloc(12 * 1 * sizeof(float),64);
    relumatrix4 = relu_mat(biasmatrix4, 1, 12);

    float *out = soft_max_vec(relumatrix4, 12);

    return out;
}

pred_t *libaudioAPI(const char *audiofeatures, pred_t *pred)
{

    float *arr = dnn(audiofeatures);

    vector<tuple<float, int>> sortarr;
    tuple<float, int> t;

    for (int i = 0; i < 12; i++)
    {
        t = make_tuple(arr[i], i);
        sortarr.push_back(t);
    }

    sort(sortarr.begin(), sortarr.end());

    pred[0].label = get<1>(sortarr[11]);
    pred[0].prob = get<0>(sortarr[11]);
    pred[1].label = get<1>(sortarr[10]);
    pred[1].prob = get<0>(sortarr[10]);
    pred[2].label = get<1>(sortarr[9]);
    pred[2].prob = get<0>(sortarr[9]);

     return pred;
}
