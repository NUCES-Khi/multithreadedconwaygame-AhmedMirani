# ConwayGameOfLife-Using-Threads

1.	Use a two-dimensional array to represent the grid of cells, and implement the rules of the game using conditional statements:
-	Initialize the grid of cells with random values.
-	Implement the rules of the Game of Life using conditional statements. For each cell in the grid, determine its state in the next generation based on the number of live neighbors it has. Update the grid accordingly.
-	Repeat the above step for a specified number of generations.

![image](https://user-images.githubusercontent.com/123382738/235361951-47dd5dad-c99e-49f0-ad33-f14b716a117b.png)
![image](https://user-images.githubusercontent.com/123382738/235361966-9acc78d4-824d-44d9-b0d0-d1eae1160928.png)

 
2.	Create multiple POSIX threads to run the Game of Life algorithm concurrently:
-	Divide the grid into equal-sized portions and assign each portion to a separate thread.
-	Each thread will calculate the next generation for its assigned portion of the grid and update the shared grid using a mutex to prevent data races.
-	Synchronize the threads using condition variables to ensure that each thread has finished updating the grid before the next generation is calculated.

3.	Use mutexes and condition variables to synchronize access to shared data structures such as the grid of cells:
-	Use a mutex to prevent data races when updating the shared grid.
-	Use a condition variable to signal to the main thread that a thread has finished updating its portion of the grid.

![image](https://user-images.githubusercontent.com/123382738/235361984-f9e7c302-9480-4a62-bdeb-60388a3b676d.png)

![image](https://user-images.githubusercontent.com/123382738/235361992-3a6cf943-7bb3-4afa-b921-32493cada7a5.png)


4.	Use shell scripting to measure the speedup achieved by running the final application with various numbers of threads:
-	Use the time command to measure the execution time of your program with different numbers of threads.
-	Plot a graph to visualize the speedup achieved by running the program with various numbers of threads.

![image](https://user-images.githubusercontent.com/123382738/235362007-e400cd02-10c5-4920-9343-ff0b0b21899a.png)

![image](https://user-images.githubusercontent.com/123382738/235362018-da227687-f28c-4ce4-b2e4-32cbb1e86607.png)


5.	Submit a report detailing your implementation, including any design decisions you made and the results of your speedup measurements:
-	Describe your implementation approach, including the design decisions you made regarding thread allocation, synchronization mechanisms, and data structures used.
-	Present the results of your speedup measurements in a table or graph and analyze the performance gains achieved by running the program with multiple threads.

![image](https://user-images.githubusercontent.com/123382738/235362044-a503ab9e-d68a-483a-8fcf-7e57fa3cc652.png)

![image](https://user-images.githubusercontent.com/123382738/235362051-f873d833-162f-4f3b-9a8c-adef48c20385.png)



The program is using multiple threads to perform a computation intensive task of calculating the next generation of cells in a circular automation. The use of multiple threads can help to speed up the execution time of the program allowing different parts of the grid to be updated in parallel. However, the performance gain may be limited by the fact that the threads need to synchronize with each other at each generation. Therefore, the more the number of threads, the more execution time.
