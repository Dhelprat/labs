# Отчет по практической работе N 9 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Лапенко Карина Александровна\
Контакты: indoorbox@yandex.ru \
Работа выполнена: 05.04.2024\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Сортировка и поиск.

## 2. Цель работы

Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом
и двоичного поиска по ключу в таблице.

## 3. Задание

Напишите свой вариант

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

"Идея касается хранения. Создаем две структуры для ключа и для таблицы. Вроде отдельно, а вроде и вместе" - Д.А.

## 7. Сценарий выполнения работы

План:
1. Создать методы таблицы
2. Создать методы присваивания ключей
3. Создать сортировку, бин. поиск
4. Написать интерфейс для работы с программой

## 8. Распечатка протокола

```
Текущая таблица:
Ключ: 3051k, Значение: Говорят, мы бяки-буки,
Ключ: 24355u, Значение: Как выносит нас земля?
Ключ: 18398j, Значение: Дайте что ли карты в руки
Ключ: 1240b, Значение: Погадать на короля.
Ключ: 1002h, Значение: Ой-ля-ля, Ой-ля-ля,
Ключ: 17534n, Значение: Погадать на короля,
Ключ: 6860s, Значение: Ой-ля-ля, Ой-ля-ля,
Ключ: 16858j, Значение: Ех-ха!
Ключ: 23183f, Значение: Завтра дальняя дорога
Ключ: 10335d, Значение: Выпадает королю.
Ключ: 8283b, Значение: У него деньжонок много,
Ключ: 17826m, Значение: А я денежки люблю.

Выберите действие:
1. Сортировать таблицу
2. Найти ключ
3. Отобразить таблицу
4. Завершить работу
Введите свой выбор (1-4): 3
Текущая таблица:
Ключ: 3051k, Значение: Говорят, мы бяки-буки,
Ключ: 24355u, Значение: Как выносит нас земля?
Ключ: 18398j, Значение: Дайте что ли карты в руки
Ключ: 1240b, Значение: Погадать на короля.
Ключ: 1002h, Значение: Ой-ля-ля, Ой-ля-ля,
Ключ: 17534n, Значение: Погадать на короля,
Ключ: 6860s, Значение: Ой-ля-ля, Ой-ля-ля,
Ключ: 16858j, Значение: Ех-ха!
Ключ: 23183f, Значение: Завтра дальняя дорога
Ключ: 10335d, Значение: Выпадает королю.
Ключ: 8283b, Значение: У него деньжонок много,
Ключ: 17826m, Значение: А я денежки люблю.

Выберите действие:
1. Сортировать таблицу
2. Найти ключ
3. Отобразить таблицу
4. Завершить работу
Введите свой выбор (1-4): 1
Таблица успешно отсортирована.

Выберите действие:
1. Сортировать таблицу
2. Найти ключ
3. Отобразить таблицу
4. Завершить работу
Введите свой выбор (1-4): 3
Текущая таблица:
Ключ: 1002h, Значение: Ой-ля-ля, Ой-ля-ля,
Ключ: 1240b, Значение: Погадать на короля.
Ключ: 3051k, Значение: Говорят, мы бяки-буки,
Ключ: 6860s, Значение: Ой-ля-ля, Ой-ля-ля,
Ключ: 8283b, Значение: У него деньжонок много,
Ключ: 10335d, Значение: Выпадает королю.
Ключ: 16858j, Значение: Ех-ха!
Ключ: 17534n, Значение: Погадать на короля,
Ключ: 17826m, Значение: А я денежки люблю.
Ключ: 18398j, Значение: Дайте что ли карты в руки
Ключ: 23183f, Значение: Завтра дальняя дорога
Ключ: 24355u, Значение: Как выносит нас земля?

Выберите действие:
1. Сортировать таблицу
2. Найти ключ
3. Отобразить таблицу
4. Завершить работу
Введите свой выбор (1-4): 2
Введите ключ поиска: 1002h
Значение найдено: Ой-ля-ля, Ой-ля-ля,

Выберите действие:
1. Сортировать таблицу
2. Найти ключ
3. Отобразить таблицу
4. Завершить работу
Введите свой выбор (1-4): 4

Process finished with exit code 0



```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 19.04.2023 | 13:50     | Неправильно использовал malloc вместо realloc, из-за этого неправильно работал мой динамический массив | Стал использовать realloc | Нужно разбираться, что зачем |
|2  | Дом           | 19.04.2023 | 02:50     | Реализовал сортировку по значению, а не по ключу | Изменил | Нужно внимательнее читать задание |

## 10. Замечания автора по существу работы

Было не очень интересно разобраться с работой динамического массива, теперь я стал лучше понимать как работает vector из c++. 

## 11. Выводы

Сейчас буду спать )

