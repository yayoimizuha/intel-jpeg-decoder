//
// Created by tomokazu on 2024/04/01.
//
#include "double_step_qsv_jpeg_dec.cpp"
#include <omp.h>

int main() {
    omp_set_num_threads(5);
    cout << "threads" << omp_get_num_threads() << endl;
#pragma omp parallel for
    for (int i = 0; i < 5; ++i) {
        printf("thread: %d\n",omp_get_thread_num());
    }
}