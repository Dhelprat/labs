# Отчет по практической работе N 6 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Лапенко Карина Александровна\
Контакты: indoorbox@yandex.ru \
Работа выполнена: 05.04.2024\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Обработка последовательной файловой структуры на языке Си.

## 2. Цель работы

Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом.

## 3. Задание

    4. Отпечатать список студентов, компьютеры которых нуждаются в апгрейде (более p устройств).

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

generate.c - для наполнения data.bin,
execute.c - для выполнения действия,
print.c - вывод содердимого БД;
Так же нужны файлы pc.h для содания модели данных и io.c

## 7. Сценарий выполнения работы

План:
1. Реализуем наполнение файла data.bin
2. Реализуем отображение таблицы
3. Реализуем выполнение действия, указанного в варианте
4. Вынесем функции в отельный файл

## 8. Распечатка протокола

```
../data.bin 10
Student "user1" have 2 processors and 1 external devices
Student "user3" have 2 processors and 8 external devices
Student "user5" have 2 processors and 4 external devices
Student "user10" have 2 processors and 0 external devices
Student "user2089374" have 2 processors and 8 external devices
Student "user30294" have 2 processors and 4 external devices
Student "user120" have 2 processors and 0 external devices
Student "uuuuuuuser" have 2 processors and 1 external devices
Student "looser" have 2 processors and 4 external devices
Student "user32203" have 2 processors and 8 external devices

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 14.04.2023 | 13:50     | Создал структуру, в которой не учёл все параметры, необходимые для выполнения варианта | Добавил нужные параметры | Нужно быть внимательнее |
|2  | Дом           | 14.04.2023 | 02:50     | Не написал дамп в файл | Сделал обработку данных, стал записывать структуру в файл и брать данные из файла | Забыл |

## 10. Замечания автора по существу работы

Было очень интересно прикоснуться немного к реализации своей бд.

## 11. Выводы

Я научился реализовывать простейшую базу данных на языке СИ и запросы к ней.

