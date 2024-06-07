# Отчет по практической работе N 8 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Лапенко Карина Александровна\
Контакты: indoorbox@yandex.ru \
Работа выполнена: 05.04.2024\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Линейные списки.

## 2. Цель работы

Составить и отладить программу на языке Си для обработки линейного списка заданной организации.

## 3. Задание

Тип элемента списка: целый
Вид списка: кольцевой однонаправленный
Нестандартное действие: удалить из списка все элементы, предшествующие и последующие заданному значению


## 4. Оборудование

Процессор: Intel Core i5-8265U @ 8x 3.9GH\
ОП: 7851 Мб\
НМД: 1024 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **18.10 cosmic**\
Интерпретатор команд: **bash**, версия **4.4.19**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**

## 6. Идея, метод, алгоритм решения задачи

долго объяснять...

## 7. Сценарий выполнения работы

План:
1. Создать структуру
2. Написать функцию вывода списка
3. Написать функцию вывода длины списка
4. Написать функцию добавления элемента по индексу в список
5. Написать ту самую НеСтАнДаРтнУю фУнкЦию
6. Написать функцию удаления элемента по индексу из списка 
7. Написать меню для взаимодействия с программой

## 8. Распечатка протокола

```
Меню:
1 - добавить элемент
2 - вывести список
3 - вывести длину списка
4 - выбрать элемент
5 - удалить элемент
0 - завершить работу
Выберите операцию (0-4):1
Введите индекс: 1
Введите значение для добавления: 1
Значение успешно добавлено!
Выберите операцию (0-4):2
1 
Выберите операцию (0-4):1
Введите индекс: 1
Введите значение для добавления: 2
Значение успешно добавлено!
Выберите операцию (0-4):2
1 2
Выберите операцию (0-4):1
Введите индекс: 1
Введите значение для добавления: 5
Значение успешно добавлено!
Выберите операцию (0-4):2
1 5 2
Выберите операцию (0-4):1
Введите индекс: 0
Введите значение для добавления: 7
Значение успешно добавлено!
Выберите операцию (0-4):2
7 1 5 2
Выберите операцию (0-4):5
Введите индекс элемента для удаления: 3
Выберите операцию (0-4):2
7 1 5
Выберите операцию (0-4):5
Введите индекс элемента для удаления: 0
Выберите операцию (0-4):2
1 5
Выберите операцию (0-4):4
Введите значение для проверки: 2
Выберите операцию (0-4):2
1 5
Выберите операцию (0-4):4
Введите значение для проверки: 1
Выберите операцию (0-4):2
Список пуст
Выберите операцию (0-4):3
Длина списка: 0
Выберите операцию (0-4):0
Завершение программы

Process finished with exit code 0



```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 19.04.2023 | 13:50     | забыла про нестандартную функцию | Нужно быть внимательнее |
|2  | Дом           | 19.04.2023 | 02:50     | Не очищал память после удаления ноды | free(ptr) | Забыл |

## 10. Замечания автора по существу работы

Было очень интересно разобраться с работой линейных списков и вспомнить, как работать со ссылками.

## 11. Выводы

Очень хочется спать ()
