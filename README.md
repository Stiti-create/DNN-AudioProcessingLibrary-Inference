## ABOUT THE PROJECT:

Implemented a deep neural network (DNN) inference for classifying across 12 audio keywords (silence, unknown, yes, no, up, down, left, right, on, off, stop, go). [1x250] input features for each 1 second audio sample provided as input. The DNN comprises of FC1 [250x144] -> RELU -> FC2 [144x144] -> RELU -> FC3 [144X144] -> RELU -> FC4 [144x12] -> softmax. The output will be 12 floats representing probabilities for the 12 keywords, adding upto 1, the highest value giving the most probable keyword. The implementation is done stiching together the most efficient functions you have written for FC, RELU, softmax so far. 

*Note that the model is pre-trained and weights are provided as input, the task here is to do the inference and compute the outputs EFFICIENTLY*

## TO RUN THE FOLLOWING COMMANDS:
1. Step 1: In the terminal, give command "make" to compile all files.

2. Step 2: To run the code, give this command in terminal:
 ```
 (The command is of the form: ./yourcode.out {inputfilename} {outputfilename})
 ```

   ./yourcode.out mfcc_features/b5cf6ea8_nohash_3.txt out.txt
   ./yourcode.out mfcc_features/ca4d5368_nohash_5.txt out.txt
   ./yourcode.out mfcc_features/333784b7_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/815f0f03_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/b2ae3928_nohash_1.txt out.txt
   ./yourcode.out mfcc_features/b9cccd01_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/aac5b7c1_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/25e95412_nohash_4.txt out.txt
   ./yourcode.out mfcc_features/d9b8fab2_nohash_1.txt out.txt
   ./yourcode.out mfcc_features/c351e611_nohash_2.txt out.txt
   ./yourcode.out mfcc_features/b9f46737_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/9be15e93_nohash_3.txt out.txt
   ./yourcode.out mfcc_features/d53e25ba_nohash_1.txt out.txt
   ./yourcode.out mfcc_features/ba676390_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/8012c69d_nohash_3.txt out.txt
   ./yourcode.out mfcc_features/db9cd41d_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/cce7416f_nohash_5.txt out.txt
   ./yourcode.out mfcc_features/8dc18a75_nohash_2.txt out.txt
   ./yourcode.out mfcc_features/c9b5ff26_nohash_4.txt out.txt
   ./yourcode.out mfcc_features/695c2127_nohash_0.txt out.txt
   ./yourcode.out mfcc_features/d3831f6a_nohash_2.txt out.txt
   ./yourcode.out mfcc_features/e4be0cf6_nohash_3.txt out.txt
   ./yourcode.out mfcc_features/7846fd85_nohash_1.txt out.txt
   ./yourcode.out mfcc_features/d98dd124_nohash_2.txt out.txt
   ./yourcode.out mfcc_features/b55a09be_nohash_1.txt out.txt
   ./yourcode.out mfcc_features/ca4d5368_nohash_4.txt out.txt
   ./yourcode.out mfcc_features/3c257192_nohash_3.txt out.txt
   ./yourcode.out mfcc_features/c7dc7278_nohash_3.txt out.txt
   ./yourcode.out mfcc_features/879a2b38_nohash_1.txt out.txt
   ./yourcode.out mfcc_features/bb05582b_nohash_4.txt out.txt

The output will be printed in out.txt and will be appended.

## EXCEPTION HANDLING:

   1. If the command contains the inputtext file which doesn't exist, the code exits by printing:
   "The entered mfcc_feautures file does not exist. Please enter correct input file name" on the terminal(std_out).

   2. If the terminal command is not of the correct format, it exits with error message:
   "Please enter the command in correct format".


## OUTPUT:

sampleoutput.txt contains the outputs for the given 30 audio samples.



    
    

