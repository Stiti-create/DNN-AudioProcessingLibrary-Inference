all:
	g++ -c -Wall -Werror -fpic audio.cpp
	g++ -shared -o libaudio.so audio.o
	export MKL_BLAS_PATH=$MKL_BLAS_PATH:/usr/include/mkl
	g++ -L. -Wall -o yourcode.out main.cpp -laudio -I MKL_BLAS_PATH -L MKL_BLAS_PATH -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm -ldl
	LD_LIBRARY_PATH=${pwd}:$LD_LIBRARY_PATH
	export LD_LIBRARY_PATH=${pwd}:$LD_LIBRARY_PATH
				
		
clean:
	rm -f yourcode.out
	unset LD_LIBRARY_PATH




