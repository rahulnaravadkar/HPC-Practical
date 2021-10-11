#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {

	MPI_Init(NULL, NULL);

	int world_rank,world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	cout << "Hello world, from process #" << world_rank << endl;

	MPI_Finalize();

	return 0;
}

// Compile using
// mpicxx -o Question1 Question1.cpp

// Run using 
// mpirun -np 5 ./Question1.cpp
// here 5 represents the no_of_processes
