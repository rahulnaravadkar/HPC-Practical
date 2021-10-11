#include<iostream>
#include<mpi.h>

using namespace std;

int main() {

	MPI_Init(NULL,NULL);

	int rank,world_size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);

	MPI_Request send_request,recv_request;
	MPI_Status status;

	int curr_process = rank % world_size;
	int next_process = (rank+1) % world_size;
	int prev_process = (rank-1) % world_size;

	int num = curr_process;
	MPI_Isend(&num,1,MPI_INT,next_process,0,MPI_COMM_WORLD,&send_request);
	cout << "Sender Process: - " << curr_process << "\nSender Data: - " << num << "\n";


	int k=10;
	MPI_Irecv(&k,1,MPI_INT,prev_process,0,MPI_COMM_WORLD,&recv_request);
	cout << "Receiver Process: - " << next_process << "\nReceiver Data: - " << k << "\n\n";
	
		  	
	MPI_Finalize();
	return 0;

}

// Compile using
// mpicxx -o Question2 Question2.cpp

// Run using 
// mpirun -np 4 ./Question2.cpp
// here 4 represents the no_of_processes
