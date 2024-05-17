g++ *.cpp -o main.out -g -Wextra -Wall
valgrind --leak-check=full ./main.out
