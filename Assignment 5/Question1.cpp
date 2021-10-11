#include<iostream>
#include<mpi.h>

using namespace std;

int main() {
	
	int first = 1, second = 2 , third = 3, fourth = 4;
	int receivedfr,receiveds, receivedt, receivedf;
	
	MPI_Init(NULL,NULL);
	
	int world_rank,world_size;
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	
	if(world_rank == 0){
	
		MPI_Send(&first,1,MPI_INT,1,0,MPI_COMM_WORLD);
		
	}
	
	if(world_rank == 1) {

		MPI_Recv(&receiveds,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		
		cout<<"Process Rank: - " << world_rank << "\nData Received: - "<< receiveds << "\n\n";
		
		MPI_Send(&second,1,MPI_INT,2,12,MPI_COMM_WORLD);
	}
	
	if(world_rank == 2) {
		MPI_Recv(&receivedt,1,MPI_INT,1,12,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		
		cout<<"Process Rank: - " << world_rank << "\nData Received: - "<< receivedt << "\n\n";

		
		MPI_Send(&third,1,MPI_INT,3,23,MPI_COMM_WORLD);
	}
	
	if(world_rank == 3) {
		MPI_Recv(&receivedf,1,MPI_INT,2,23,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				
		cout<<"Process Rank: - " << world_rank << "\nData Received: - "<< receivedf << "\n\n";
		
		MPI_Send(&fourth,1,MPI_INT,0,30,MPI_COMM_WORLD);
	}
	
	if(world_rank == 0) {
		MPI_Recv(&receivedfr,1,MPI_INT,3,30,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		
		cout<<"Process Rank: - " << world_rank << "\nData Received: - "<< receivedfr << "\n\n";
	}
	
	MPI_Finalize();
	
	return 0;
}

// Compile using
// mpicxx -o Question1 Question1.cpp

// Run using 
// mpirun -np 4 ./Question1
// here 4 represents the no_of_processes

