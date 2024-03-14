import matplotlib.pyplot as plt
import numpy as np

# Здесь нужно заменить данные времени выполнения на полученные вами результаты
lin_time = [...] # время выполнения линейного поиска
bin_time = [...] # время выполнения бинарного поиска
array_sizes = [100, 200, 400, 800, 1600, 3200, 5000, 7000, 10000, 
               15000, 20000, 25000, 35000, 45000, 60000, 75000, 
               95000, 115000, 140000, 165000, 195000, 225000, 260000, 
               295000, 335000, 375000, 420000, 465000, 500000]

plt.figure(figsize=(12, 6))

# График времени выполнения линейного поиска
plt.plot(array_sizes, lin_time, marker='o', label='Linear Search Time')

# График времени выполнения бинарного поиска
plt.plot(array_sizes, bin_time, marker='x', label='Binary Search Time')

plt.xlabel('Array Size')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Linear vs Binary Search')
plt.legend()
plt.grid(True)
plt.show()