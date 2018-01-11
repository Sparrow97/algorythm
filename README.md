# Замкнутые Классы
## Краткое руководство
### Входные данные
На вход программы подается булев вектор в формате txt-файла.Путь к файлу указан в программе. В этот файл может быть записан двоичный вектор. Прмер: 011101010. 
### Выходные данные 
Подаются в другой txt файл. Пример выходных файлов: 


011101010


T0 +


T1 -


S -


M -


L +


### Запуск программы
Программа принимает 3 аргумента: файл с входными, выходными даннами, а так же файл с тестовыми данными для проверки правильности выполнения работы.

## Тесты
В тестовый файл надо записать последовательность из "-" "+", идущих в лексикографическом порядке, а именно: T0, T1, S, M, L. В данном случае + обозначает принадлежность булевой функции к конкретному классу. Пример: +--+-. Эта функция принадлежит к классам T0 и M, так как на 1 и 4 месте стоят +.

## Теория
В программе мы проверяем булеву функцию на замкнутость 5 классов. 

T0 - Булева функция сохраняет константу 0 (принадлежит классу T0), если на наборе из всех нулей функция принимает значение ноль. 
Функция, выполняющая проверку на сохранение 0: 

*void nul()*

T1 - Булева функция сохраняет константу 1 (принадлежит классу T1), если на наборе из всех единиц функция принимает значение единица.

Функция, выполняющая проверку на сохранение 1: 

*void ed()*

S - булева функция, двойственная сама к себе. Другими словами, самодвойственная функция на противоположных друг другу наборах значений аргументов принимает противоположные значения.

Функция, выполняющая проверку на самодвойственность: 

 *void smd()*
 
 Уже устали? Подождите, начинается самое интересное.
 
 M - Булева функция f(x1, …, xn) называется монотонной (принадлежит классу M), если для любой пары наборов α и β таких, что αβ, выполняется условие f(α)≤ f(β). Монотонность мы проверяем при помощи нескольких функций:
 
 *string nib()* - эта фунция переводит десятичное число в двоичный код для построения наборов
 *bool nabor()* - при помощи данной функции мы смотрим, сравнимы ли наборы, которые мы проверяем
 *void mono()* - проверяет монотонность функции
 
 L - Булева функция называется линейной (принадлежит классу L), если ее полином Жегалкина линеен. Как можно догататься, нужно построить полином Жегалкина. Строить его мы будем через таблицу истинности и АНФ. Таблица истинности задается в конструкторе класса.
 
 *void foo2()* - тут мы задаем анф
 *void lin()* - проверка линейности
 
 ## Алгоритмы
 
 Для проверки принадлежности к классам T0, T1 у нас тривиальные алгоритмы.   
 
 T0 - проверяем первый символ. Если он 0 - возвращаем true. Нет - false.  
 
 T0 - проверяем последний символ. Если он 1 - возвращаем true. Нет - false.  
 
 S - 
 1. Создаем string, который будет копией функции
 2. Применяем метод reverse к string
 3. Меняем значения 0 на 1 и наоборот.
 4. Сравниваем полученный string с изначальной функцией. Если совпали - возвращаем true. Нет - false.
 
 M - 
 1. Пробегаем по всем наборам и сравниваю каждый с каждым при помощи функции nabored. Она возвращает true при сравнимых наборах и false при несравнимых.
 2. Если наборы сравнимы - сравниваем значения на этих наборах.
 3. Если у большего набора значение - 0, а у меньшего - 1, то функция не монотонна. Если таких наборов нет, то функция монотонна.
 
L - 
1. Берем вектор значений, попарно складываем соседние значения (по mod2). Получившийся результат записываем в string и рекурсивно передаем строку в foo2() до тех пор, пока не останется одно значение. При этом записываем первое значение стрингов в anf, где anf - коэфициенты полинома, соответствующих наборов. 

 1. ![](/inc/f2e9c734a37a4bee9df7077735b7f264.png)
 
 
 2. Ищем наборы с двумя и более единицами при помощи функции bool nabored(). Если напротив набора с двумя и более единицами anf равен 1, то функция не линейна. В остальных случаях функция линейна. 
