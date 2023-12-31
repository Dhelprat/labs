# Отчет по лабораторной работе N 11 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Лапенко Карина Александровна\
Контакты: indoorbox@yandex.ru \
Работа выполнена: 20.11.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Простейшие приёмы лексического анализа

## 2. Цель работы

Написание конечного автомата, который решает поставленную задачу на языке C

## 3. Задание

Перевести все мерные длины из дюймов(in) в миллиметры(мм). Например: 10in -> 254мм

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

План:
1. Придумать конечный автомат
2. Написать конечный автомат

## 7. Сценарий выполнения работы

1. Идем по строке с состоянием 0. Если встретили цифру, сохраняем ее и переходим в состояние 1, а если букву, то переходим в состояние 4
2. Если состояние 1: Цифра - сохраняем, состояние 1; "i" - состояние 2; иначе - состояние 4
3. Если состояние 2: "n" - состояние 3; Цифра - сохраняем, состояние 1; иначе - состояние 4
4. Если состояние 3: проверяем, является ли следующий символ концом слова, и, если является, то печатаем слово и переходим в состояние 0, предварительно очистив сохраненные данные, а если следующий символ не является концом слова, то переходим в состояние 4
5. Если состояние 4: очищаем сохраненные данные и идем до конца слова, а дойдя до конца, переходим в состояние 0

## 8. Распечатка протокола

```
Тест: 10in
Вывод: 254.00mm

Тест: корыто105пуля45in
Вывод:

Тест:   100in gkuinm
        2ijg 1nl1inkl1l
        96injhghjkgj 10inцуа
Вывод:  2540.00mm
        254.00mm
```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                                                | Действие по исправлению   | Примечание     |
|---|---------------|------------|-----------|--------------------------------------------------------|---------------------------|----------------|
|1  | Дом           | 20.11.2023 | 1:50     | Забыла сохранить первую цифру числа               | Дописала             | ура |


## 10. Замечания автора по существу работы

Замечаний нет

## 11. Выводы

За время написания работы я испытала весь спектр эмоций. Сам конечный автомат мне не понравился.

