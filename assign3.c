#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<time.h>
#include <errno.h>
#include <signal.h>

#define GRID_SIZE 10
#define NUM_THREADS 5
#define NUM_GENERATIONS 10

int grid[GRID_SIZE][GRID_SIZE];
pthread_mutex_t grid_mutex;
pthread_cond_t grid_cond;

void *calculate_generation(void *arg) {
    int id = *((int*)arg);
    int start_row = id * (GRID_SIZE / NUM_THREADS);
    int end_row = (id + 1) * (GRID_SIZE / NUM_THREADS);

    for (int gen = 0; gen < NUM_GENERATIONS; gen++) {
        // calculate the next generation for this thread's portion of the grid
        for (int i = start_row; i < end_row; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                // calculate the number of live neighbors for this cell
                int live_neighbors = 0;
                for (int ii = i-1; ii <= i+1; ii++) {
                    for (int jj = j-1; jj <= j+1; jj++) {
                        if (ii == i && jj == j) continue;
                        if (ii >= 0 && ii < GRID_SIZE && jj >= 0 && jj < GRID_SIZE && grid[ii][jj] == 1) {
                            live_neighbors++;
                        }
                    }
                }

                // update the state of this cell based on the number of live neighbors
                if (grid[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                    grid[i][j] = 0;
                } else if (grid[i][j] == 0 && live_neighbors == 3) {
                    grid[i][j] = 1;
                }
            }
        }

        // wait for all threads to finish updating the grid
        pthread_mutex_lock(&grid_mutex);
        if (id == 0) {
            pthread_cond_broadcast(&grid_cond);
        } else {
            while (pthread_cond_wait(&grid_cond, &grid_mutex) != 0);
        }
        pthread_mutex_unlock(&grid_mutex);

        // print the state of the grid
        if (id == 0) {
            printf("Generation %d:\n", gen);
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                    printf("%c", (grid[i][j] == 1 ? 'X' : ' '));
                }
                printf("\n");
            }
        }
    }

    return NULL;
}


int main() {

    clock_t start_time, end_time;
    double time_taken;
    
    start_time = clock();
    // initialize the grid with random values
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // initialize the mutex and condition variable
    pthread_mutex_init(&grid_mutex, NULL);
    pthread_cond_init(&grid_cond, NULL);

    // create the threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_generation, &thread_ids[i]);
    }
    
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time Taken with %d Threads: %f",NUM_THREADS,time_taken);

    // wait for all threads to finish
    int all_threads_finished = 0;
    struct timespec timeout;
    while (!all_threads_finished) {
        pthread_mutex_lock(&grid_mutex);
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 1;  // wait for 1 second
        int ret = pthread_cond_timedwait(&grid_cond, &grid_mutex, &timeout);
        if (ret == ETIMEDOUT) {
            all_threads_finished = 1;
            for (int i = 0; i < NUM_THREADS; i++) {
                if (pthread_kill(threads[i], 0) == 0) {
                    all_threads_finished = 0;
                    break;
                }
            }
        }
        pthread_mutex_unlock(&grid_mutex);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    

    // destroy the mutex and condition variable
    pthread_mutex_destroy(&grid_mutex);
    pthread_cond_destroy(&grid_cond);

    return 0;
}


