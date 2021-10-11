#include<iostream>
#include<math.h>
#include <mpi.h>

using namespace std;
 
int main(int argc, char* argv[])
{
	int arr[10] = {4,3,5,1,8,9,2,6,10,7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	int size, rank; 

	MPI_Init(NULL,NULL); 

	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	int partial_sum = 0; 

	int tmp_n = ceil(arr_size * 1.0 / size);
	
	int start = rank * tmp_n, end = min(arr_size, (rank + 1) * tmp_n);
	
	for (int i = start; i < end; i++){
		partial_sum += arr[i];
	}
	
	cout<<"\nPartial Sum by the process " << rank << " is " << partial_sum << "\n";

	int sum; 
	MPI_Reduce(&partial_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0){
		printf("Sum of array is : %d\n", sum);
	}

	MPI_Finalize(); 

	return 0; 
}

// Compile using
// mpicxx -o Question3 Question3.cpp

// Run using 
// mpirun -np 4 ./Question3
// here 4 represents the no_of_processes
