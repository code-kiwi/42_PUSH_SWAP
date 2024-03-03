# ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) PUSH_SWAP

> **Note:** This is a project from **42 learning cursus**.

## Description
This project introduces us to sorting algorithms and algorithm complexity.<br>
Given a list of numbers, we need to sort them using some predefined operations.<br>
Our final grade depends on the number of instructions we used to sort the list of numbers.<br>
This project is based on [this algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) (insertion sort with minimum cost calculation) and a [custom sort](https://han-joon-hyeok.github.io/posts/push-swap/) from a student of another 42 school in South Korea.<br>
The first one is not efficient enough to sort 500 numbers in less than 5500 instructions.

## Pinciples
For this project, we have two stacks of numbers: stack A and stack B.
All the numbers from the given list are put to stack A.
Then, in order to sort the list, we can use different instructions:
|INSTRUCTION     |MEANING                 |DESCRIPTION                                                                   |
|----------------|------------------------|------------------------------------------------------------------------------|
|`sa`            |swap a                  |Swap the first 2 elements at the top of stack a                               |
|`sb`            |swap b                  |Swap the first 2 elements at the top of stack b                               |
|`ss`            |swap a and b            |sa and sb at the same time                                                    |
|`pa`            |push a                  |Take the first element at the top of b and put it at the top of a             |
|`pb`            |push b                  |Take the first element at the top of a and put it at the top of b             |
|`ra`            |rotate a                |Shift up all elements of stack a by 1                                         |
|`rb`            |rotate b                |Shift up all elements of stack b by 1                                         |
|`rr`            |rotate a and b          |ra and rb at the same time                                                    |
|`rra`           |reverse rotate a        |Shift down all elements of stack a by 1                                       |
|`rrb`           |reverse rotate b        |Shift down all elements of stack b by 1                                       |
|`rrr`           |reverse rotate a and b  |rra and rrb at the same time                                                  |

## Setup instructions
1. Clone the repo: `git clone https://github.com/code-kiwi/42_PUSH_SWAP.git`
2. Clone the submodule libft: `git submodule update --init --recursive`
3. Compile the project `make`
4. You can compile the bonus part of the project: `make bonus`
The executable `push_swap` should be created.
If you compiled the bonus part, another executable `checker` was created.

## How to use the progam ?
- Run the `push_swap` program with the numbers as parameters:
  > `./push_swap -10 5 100 -6 10` or `./push_swap "-10 5 100 -6 10"`<br>
  > The instructions used by the program will be printed on the standard output.
- You can run the `checker` program with the same parameters:
  > `./checker -10 5 100 -6 10` or `./checker "-10 5 100 -6 10"`<br>
  > The checker program will wait for your to type the instructions you want to execute (see the list above).<br>
  > Send EOF signal to stop typing instructions `(CTRL+D on linux OS)`
  > The checker will prompt:
  > - **"OK"** if the list is sorted after applying your instructions
  > - **"KO"** is the list is not sorted
  > - **"Error"** if an error occured or if one of your instructions is invalid
- You can combine both programs:
  > `./push_swap -10 5 100 -6 10 | ./checker -10 5 100 -6 10`<br>
  > or `ARG="-10 5 100 10"; ./push_swap $ARG | ./checker $ARG`<br>
  > It will show you if the instructions given by the push_swap program really sort the list<br>

## Testing tools
I added some scripts in order to test the program.<br>
Each file needs to be copied to the root of the repository.
| FILE                      | What is does? | How to use? |
|---------------------------|-----------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------|
|generator.py               |Generates a list of random numbers with a specific size                                                          |`python generator.py SIZE_OF_LIST`                             |
|script_test_perfs.sh       |Tests the number of instructions required for sorting a fixed random list of number                              |`bash script_test_perfs.sh SIZE_OF_LIST NUMBER_OF_TESTS`       |
|script_test_valid.sh       |Tests if the push_swap instructions do sort random list of numbers (uses the given checker_linux, provided by 42)|`bash script_test_valid.sh SIZE_OF_LIST NUMBER_OF_TESTS`       |
|script_test_valid_bonus.sh |Tests if the push_swap instructions do sort random list of numbers (uses the checker from the repo)              |`bash script_test_valid_bonus.sh SIZE_OF_LIST NUMBER_OF_TESTS` |

## Grade
![PS](https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/push_swapm.png)<br><br>
`125/125`<br>
> Note really deserved because the custom algorithm needs more than 5500 instructions on 500 numbers in very specific cases.<br>
> I should have stored the instructions from both algorithms in order to take the most efficient set of instructions

## Credits
The badge comes from [this repo](https://github.com/ayogun/42-project-badges/tree/main), by [@ayogun](https://github.com/ayogun) which proposes a lot of amazing badges for 42 projects.
