#include <stdio.h>
#include "audio.h"
#include <stdlib.h>
#include <math.h>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    if(argc!=3){
        cout << "Please enter the command in correct format" << endl;
        return 0;
    }

    string audfeatarr[] = {"silence", "unknown", "yes", "no", "up", "down", "left", "right", "on", "off", "stop", "go"};
    string s1 = argv[1];
    const char* c = s1.c_str();
  

    pred_t *predout = (pred_t *) malloc(3*sizeof(pred_t));
    predout->label = 1;
    predout->prob = 0.5f;


    predout = libaudioAPI(c, predout);
    ofstream outfile;
    outfile.open(argv[2], ios::app);

    outfile << s1 << " " << audfeatarr[predout[0].label] << " " << audfeatarr[predout[1].label] << " " 
    << audfeatarr[predout[2].label] << " " << predout[0].prob << " " << predout[1].prob
    << " " << predout[2].prob << endl;

    outfile.close();


    return 0;
            
    }
