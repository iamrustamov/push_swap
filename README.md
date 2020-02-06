# PUSH SWAP

Суть проекта заключается в том, что надо отсортировать стек целых чисел ограниченным набором инструкций, при использовании
минимально возможных количеств действий.

[Методичка | Subject ](https://github.com/Binary-Hackers/42_Subjects/blob/master/00_Projects/02_Algorithmic/push_swap.pdf)

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |


## Клонирование проекта:
```
git clone git@github.com:iamrustamov/push_swap.git

```
## Как запустить программу:
```
Производим клонирование!
cd push_swap/
make
ARG="random numbers"; /.push_swap $ARG // Печать всех интрукций которые потребовались для сортировки стека
ARG="random numbers"; ./push_swap $ARG | wc -l // Печать колличества инструкций которые потребовались для сортировки стека
ARG="random numbers"; ./push_swap $ARG | ./checker $ARG // Вывод "ОК" если стек отсортировался, иначе "Error!"

*random numbers - последовательность целых чисел без дубликатов в интервале int (integer)
```

## Codestyle
Проект написан в строгом соответствии с [Norminette codestyle](https://github.com/Binary-Hackers/42_Subjects/blob/master/04_Norme/norme_2_0_1.pdf)
