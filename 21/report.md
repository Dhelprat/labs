# Отчет по лабораторной работе N 21 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Лапенко Карина Александровна\
Контакты: indoorbox@yandex.ru \
Работа выполнена: 05.03.2024\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Программирование на интерпретируемых командных языках

## 2. Цель работы

Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков

## 3. Задание

Вариант 20. Обход указанного каталога и вывод на экран полных путей поддиректорий

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

Написать bash-скрипт...

## 7. Сценарий выполнения работы

План:
1. Проверка на количество аргументов
2. Проверка, является ли введенный аргумент "?"
3. Проверка существования введенной директории
4. С помощью команды find находим все необходимые директории

## 8. Распечатка протокола

```
./lab.sh  
error: Incorrect number of arguments
Usage: ./lab.sh <directory>
Traverse the specified directory and display full paths of subdirectories
./lab.sh info
Usage: ./lab.sh <directory>
Traverse the specified directory and display full paths of subdirectories
./lab.sh /Users/dhelprat/Downloads/HASSE\ \(1\)/src 
/Users/dhelprat/Downloads/HASSE (1)/src
/Users/dhelprat/Downloads/HASSE (1)/src/ui
/Users/dhelprat/Downloads/HASSE (1)/src/ui/__pycache__
/Users/dhelprat/Downloads/HASSE (1)/src/database
/Users/dhelprat/Downloads/HASSE (1)/src/database/__pycache__
/Users/dhelprat/Downloads/HASSE (1)/src/resources
/Users/dhelprat/Downloads/HASSE (1)/src/resources/temp
/Users/dhelprat/Downloads/HASSE (1)/src/utils
/Users/dhelprat/Downloads/HASSE (1)/src/utils/__pycache__
/Users/dhelprat/Downloads/HASSE (1)/src/__pycache__


```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 29.02.2023 | 13:50     | Поставил чайник    | Забыл что поставил чайник     | Фатальная ошибка|
|2  | Дом           | 03.03.2023 | 02:50     | Операцию сравнения написал в () скобках | Поставил [] |             |

## 10. Замечания автора по существу работы

Было очень интересно, разобрался с bash. Ставлю лайк.

## 11. Выводы

Я разобрался с языком bash, узнал что на нём можно программировать, почти как на C.
