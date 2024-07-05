## Теория

База:
- https://standards.ieee.org/ieee/754/4211 и https://standards.ieee.org/ieee/754/6210/
- https://0.30000000000000004.com
- Как перевести число в `float` / `double`? https://www.wikihow.com/Convert-a-Number-from-Decimal-to-IEEE-754-Floating-Point-Representation и https://class.ece.iastate.edu/arun/CprE281_F05/ieee754/ie2.html
- Опасности float: http://www.indowsway.com/floatingpoint.htm
- Что каждый разработчик должен знать про float? https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html
- Что такое FLOPS: https://ru.wikipedia.org/wiki/FLOPS

Инструменты:
- Визуализация IEEE754: https://bartaz.github.io/ieee754-visualization и https://www.h-schmidt.net/FloatConverter/IEEE754.html
- Онлайн калькулятор для превращения чисел: https://www.binaryconvert.com/result_double.html
- Калькулятор IEEE754 `+`: http://weitz.de/ieee

Видео:
- Сложение двух `float`'ов: https://www.youtube.com/watch?v=mKJiD2ZAlwM

Документация:
- float точность и способы использования: https://docs.python.org/3/tutorial/floatingpoint.html
- `float` тип: https://docs.python.org/3/library/functions.html#float
- `fractions`: https://docs.python.org/3/library/fractions.html
- `sys.float_info`: https://docs.python.org/3/library/sys.html#sys.float_info
- `sys.float_repr_style`: https://docs.python.org/3/library/sys.html#sys.float_repr_style

Исходники:
- Получение exponent и mantissa из double в glibc: https://git.musl-libc.org/cgit/musl/tree/src/math/frexp.c
- Симуляции `float` на питоне: https://github.com/robclewley/ieee754_simulation
- `floatobject.h`: https://github.com/python/cpython/blob/main/Include/floatobject.h
- `floatobject.c`: https://github.com/python/cpython/blob/main/Objects/floatobject.c
- `dtoa.c`: https://github.com/python/cpython/blob/main/Python/dtoa.c

Альтернативные реализации:
- https://github.com/mdickinson/bigfloat

Книги:
- Numerical Computing With IEEE Floating Point Arithmetic: Including One Theorem, One Rule of Thumb, and One Hundred and One Exercises First Edition by Michael L. Overton  https://www.amazon.com/Numerical-Computing-Floating-Point-Arithmetic/dp/0898714826


## Практика

Написать скрипт, который переводит введенное пользователем
число с плавающей точкой в:
1. float 32x битный формат
2. double 64х битный формат

Как пример вывода можно использовать пример со слайда:

```
Number: 85.125
Binary sign: 0
Binary whole part: 1010101
Binary frac part: 001
Binary form: 1010101.001
Exponent: 2**6
Biased exponent: 1029
Binary exponent: 10000000101
Binary mantissa: 010101001

Final result:
0 10000000101 0101010010000000000000000000000000000000000000000000
s eeeeeeeeeee mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
```
