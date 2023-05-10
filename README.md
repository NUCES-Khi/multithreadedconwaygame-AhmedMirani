# ConwayGameOfLife-Using-Threads

1.	Use a two-dimensional array to represent the grid of cells, and implement the rules of the game using conditional statements:
-	Initialize the grid of cells with random values.
-	Implement the rules of the Game of Life using conditional statements. For each cell in the grid, determine its state in the next generation based on the number of live neighbors it has. Update the grid accordingly.
-	Repeat the above step for a specified number of generations.

![ss1](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/ce91ed61-1efd-4c48-84fb-7f02c8ac805b)
![ss2](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/12a2f416-a27d-4be4-9394-276148be29e2)

 
2.	Create multiple POSIX threads to run the Game of Life algorithm concurrently:
-	Divide the grid into equal-sized portions and assign each portion to a separate thread.
-	Each thread will calculate the next generation for its assigned portion of the grid and update the shared grid using a mutex to prevent data races.
-	Synchronize the threads using condition variables to ensure that each thread has finished updating the grid before the next generation is calculated.

3.	Use mutexes and condition variables to synchronize access to shared data structures such as the grid of cells:
-	Use a mutex to prevent data races when updating the shared grid.
-	Use a condition variable to signal to the main thread that a thread has finished updating its portion of the grid.

![ss3](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/b89447b7-2a22-4f9f-a32b-3d528264d36e)

![ss4](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/a01788b5-ac12-4442-86da-52cc5fe50fa9)


4.	Use shell scripting to measure the speedup achieved by running the final application with various numbers of threads:
-	Use the time command to measure the execution time of your program with different numbers of threads.
-	Plot a graph to visualize the speedup achieved by running the program with various numbers of threads.

![ss5](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/cf7794e0-f024-46f4-adf4-0ce11a21dd57)

![ss8](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/804b249f-3f15-4e14-9381-ff8284348256)


5.	Submit a report detailing your implementation, including any design decisions you made and the results of your speedup measurements:
-	Describe your implementation approach, including the design decisions you made regarding thread allocation, synchronization mechanisms, and data structures used.
-	Present the results of your speedup measurements in a table or graph and analyze the performance gains achieved by running the program with multiple threads.

![ss6](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/bbc646dc-138c-40ac-9ff5-b26b303c0a9e)

![ss7](https://github.com/NUCES-Khi/multithreadedconwaygame-AhmedMirani/assets/126978743/acf96344-3a07-4b88-87f9-a3b3545d48e1)



The program is using multiple threads to perform a computation intensive task of calculating the next generation of cells in a circular automation. The use of multiple threads can help to speed up the execution time of the program allowing different parts of the grid to be updated in parallel. However, the performance gain may be limited by the fact that the threads need to synchronize with each other at each generation. Therefore, the more the number of threads, the more execution time.
