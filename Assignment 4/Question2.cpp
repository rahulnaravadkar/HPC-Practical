#include <iostream>
#include <mpi.h>

using namespace std;

// Displaying rank and communicator group

int main() {
    MPI_Init(NULL, NULL);
    
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

	cout << "Hello from processor " << processor_name << " rank" << world_rank << " out of " << world_size << " processes\n";
    // printf("Hello from processor %s, rank %d out of %d processors\n",processor_name, world_rank, world_size);

    MPI_Finalize();
}

// Compile using
// mpicxx -o Question2 Question2.cpp

// Run using 
// mpirun -np 5 ./Question2
// here 5 represents the no_of_processes
