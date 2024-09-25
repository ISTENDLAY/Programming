# Лабораторная работа №0

## Задание:
1. Создайте репозиторий для дисциплины на GitHub.
2. Склонируйте его себе на ПК.
3. Напишите свою первую программу.
4. Скомпилируйте и запустите её.
5. Получите по отдельности результаты каждого этапа компиляции.
6. Напишите отчёт в `README.md`. Отчёт должен содержать:
   - Задание
   - Описание проделанной работы
   - Консольные команды
   - Скриншоты результатов
   - Ссылки на используемые материалы
7. Сделайте коммит и пуш.
8. Добавьте для себя в отчёт шпаргалку по работе с git.
9. Соберите для своей программы 2 библиотеки - статическую и динамическую.

## Ход работы: 
Я создал репозиторий на GitHub: [https://github.com/ISTENDLAY/Programming](https://github.com/ISTENDLAY/Programming), далее с помощью команды `git clone` я скопировал его по ssh (ssh-key был сгенерирован и подключен к GitHub задолго до выполнения данной работы, поэтому процесс генерации и подключения описывать не буду).

Я написал программу `isprimary.c`, которая получает на вход число, а на выход выдает статус числа простое/сложное.   

Для компиляции использовал:
```bash
gcc isprimary.c -lm -o isprimary
```

Для запуска использовал:
```bash
./isprimary 
```

Для поэтапной компиляции использовал следующие команды:
```bash
gcc -E isprimary.c -o isprimary.i
gcc -S isprimary.i -o isprimary.s
gcc -c isprimary.s -o isprimary.o
gcc isprimary.o -lm isprimary
```

Для ознакомления с файлами, появившимися в ходе промежуточных этапов компиляции, я использовал текстовый редактор `nano`:
```bash
nano isprimary.i
```

Далее я создал директорию `lib`:
```bash
mkdir lib
```

Там я создал 2 файла: `main.c` и `isprimary.c`:
```bash
touch main.c isprimary.c
```

Я реализовал функцию проверки числа на простое/составное в `isprimary.c`, а в `main.c` написал основную логику, включая ввод/вывод.

Далее я создал объектные файлы данных программ:
```bash
gcc -c main.c -o main.o
gcc -c isprimary.c -o isprimary.o
```

### Статическая библиотека
Для создания статической библиотеки я добавил объектный файл `isprimary.o` в архив `libisprimary.a`:
```bash
ar rcs libisprimary.a isprimary.o
```

Далее я залинковал объектный файл `main.o` со статической и math библиотекой (в программе используется функция `sqrt()`):
```bash
gcc main.o -L. -lisprimary -lm -o main
```

Получился исполняемый файл `main`, который работает так же корректно, как и изначальный `isprimary`, запускал командой: 
```bash
./main
```
![alt text](https://github.com/ISTENDLAY/Programming/blob/main/img/dynamic_commands.png?raw=true)


### Динамическая библиотека
Для создания динамической библиотеки сначала создал `libprimary.so`: 
```bash
gcc isprimary.c -shared -o libprimary.so
```

Для линковки использовал следующую команду:
```bash
gcc main.o -L. -lprimary -lm -o main_dynamic
```

Далее, чтобы линкер мог найти библиотеку, я добавил текущую директорию в переменную `LD_LIBRARY_PATH`:
```bash
export LD_LIBRARY_PATH=:/home/istend/All_code/University/Programming 
```

Теперь можно запускать исполняемый файл:
```bash
./main_dynamic
```

## Источники:
- [Stack Overflow: Find out what a given gcc option flag is doing](https://stackoverflow.com/questions/26274062/find-out-what-a-given-gcc-option-flag-is-doing)
- [SPEC CPU2017: GCC Flags](https://www.spec.org/cpu2017/flags/gcc.2018-02-16.html)
- [Stack Overflow: How can I compile to assembly with gcc](https://stackoverflow.com/questions/8021874/how-can-i-compile-to-assembly-with-gcc)
- [Stack Overflow: GCC Preprocessor](https://stackoverflow.com/questions/3917316/gcc-preprocessor)
- [YouTube: Introduction to Compiling with GCC](https://www.youtube.com/watch?v=pkMg_df8gHs)
- [YouTube: GCC Basics](https://www.youtube.com/watch?v=KT1vyEbqfVk)
- [YouTube: Understanding Shared Libraries in GCC](https://www.youtube.com/watch?v=FirqVUxQWvU)
