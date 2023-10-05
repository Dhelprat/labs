# Отчет по лабораторной работе N 2 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Лапенко Карина Александровна\
Контакты: indoorbox@yandex.ru \
Работа выполнена: 20.09.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Операционная среда ОС UNIX

## 2. Цель работы

Изучение и освоение программного обеспечения ОС UNIX и приобритение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.

## 3. Задание

Приобретение основных навыков работы в ОС UNIX

## 4. Оборудование

Процессор: Intel Core i7-11700 @ 2.50GHz\
ОП: 16 Гб\
НМД: 1024 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **20.10 cosmic**\
Интерпретатор команд: **bash**, версия **4.4.19**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**

## 6. Идея, метод, алгоритм решения задачи

Создать текстовый файл в новой директории, записать в него информацию о животных. Вывести информацию о содержимом текстового файла. Создать новую директорию, в которую переместить текстовый файл с данными. Удалить прежнюю директорию. Посчитать количество котов в файле. Скачать картинку кота.

## 7. Сценарий выполнения работы

План:
1. Создать директорию cats с помощью mkdir и names.txt с помощью touch
2. Записать информацию о животных в names.txt (echo)
3. Напечатать содержимое файла в виде списка names.txt (cat -n)
4. Напечатать количество строк, слов и символов в names.txt (wc -l -w -c)
5. Создать директорию new_cats (mkdir) и переместить в нее names.txt (mv)
6. Удалить директорию cats (rm -r)
7. Посчитать количество котов в names.txt (grep "cat" -c names.txt)
8. Скачать изображение кота (wget https://images.satu.kz/162448773_w640_h640_tovary-dlya-koshek.jpg)

## 8. Распечатка протокола

```
dhelprat@dhelprat-VirtualBox:~$ mkdir cats
dhelprat@dhelprat-VirtualBox:~$ cd cats
dhelprat@dhelprat-VirtualBox:~/cats$ touch names.txt
dhelprat@dhelprat-VirtualBox:~/cats$ echo "cats and names.txt successfully created!"
cats and names.txt successfully created!
dhelprat@dhelprat-VirtualBox:~/cats$ echo "cat
> cat
> dog
> parrot
> cat" > names.txt
dhelprat@dhelprat-VirtualBox:~/cats$ echo "open names.txt"
open names.txt
dhelprat@dhelprat-VirtualBox:~/cats$ cat names.txt -n
     1 cat
     2 cat
     3 dog
     4 parrot
     5 cat
dhelprat@dhelprat-VirtualBox:~/cats$ echo "here's the number of lines, words and chars:"
here's the number of lines, words and chars:
dhelprat@dhelprat-VirtualBox:~/cats$ wc -l -w -c names.txt
 5  5 23 names.txt
dhelprat@dhelprat-VirtualBox:~/cats$ cd ..
dhelprat@dhelprat-VirtualBox:~$ mkdir new_cats
dhelprat@dhelprat-VirtualBox:~$ mv cats/names.txt new_cats
dhelprat@dhelprat-VirtualBox:~$ echo "names.txt moved to new_cats"
names.txt moved to new_cats
dhelprat@dhelprat-VirtualBox:~$ rm -r cats
dhelprat@dhelprat-VirtualBox:~$ echo "cats removed"
cats removed
dhelprat@dhelprat-VirtualBox:~$ cd new_cats
dhelprat@dhelprat-VirtualBox:~/new_cats$ echo "count of cats in names.txt:"
count of cats in names.txt:
dhelprat@dhelprat-VirtualBox:~/new_cats$ grep "cat" -c names.txt
3
dhelprat@dhelprat-VirtualBox:~/new_cats$ echo "downloading cute cat..."
downloading cute cat...
dhelprat@dhelprat-VirtualBox:~/new_cats$ wget https://images.satu.kz/162448773_w640_h640_tovary-dlya-koshek.jpg
--2023-09-24 18:09:53--  https://images.satu.kz/162448773_w640_h640_tovary-dlya-koshek.jpg
Распознаётся images.satu.kz (images.satu.kz)… 193.242.216.19
Подключение к images.satu.kz (images.satu.kz)|193.242.216.19|:443... соединение установлено.
HTTP-запрос отправлен. Ожидание ответа… 200 OK
Длина: 49147 (48K) [image/jpeg]
Сохранение в: ‘162448773_w640_h640_tovary-dlya-koshek.jpg’

162448773_w640_h640 100%[===================>]  48,00K  --.-KB/s    за 0,05s   

2023-09-24 18:09:53 (993 KB/s) - ‘162448773_w640_h640_tovary-dlya-koshek.jpg’ сохранён [49147/49147]

dhelprat@dhelprat-VirtualBox:~/new_cats$ echo "cat's here! You can look at it"
cat's here! You can look at it
dhelprat@dhelprat-VirtualBox:~/new_cats$ exit

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 20.09.2023 | 19:52     | Редактировала task.sh в Windows и-за этого ничего не работало        | Переписала скрипт в Unix      | Все заработало!            |


## 10. Замечания автора по существу работы

Крайне занимательная работа...

## 11. Выводы

Это была моя первая встреча с UNIX....

