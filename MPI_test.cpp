#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//    cout << "size: " << size << endl;
//    cout << "rank: " << rank << endl;
    printf("%d in %d from C++", rank, size);
    MPI_Finalize();
}