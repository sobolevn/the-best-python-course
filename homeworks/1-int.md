## Теория

База:
- Как хранятся числа в памяти? http://www.5byte.ru/11/0008.php
- Как устроен `int` внутри? https://www.codementor.io/@arpitbhayani/python-caches-integers-16jih595jk
- Super long `int` in Python: https://www.youtube.com/watch?v=FNuwKuVF8Y0
- `int` interning (`x, y = 1, 1; id(x) == id(y) # True`): https://www.codesansar.com/python-programming/integer-interning.htm
- Immortal `int`s: https://peps.python.org/pep-0683/

Исходники:
- `int`: https://github.com/python/cpython/blob/main/Objects/longobject.c

Документация:
- `numbers.py`: https://docs.python.org/3/library/numbers.html
- Дополнительные методы на `int`: https://docs.python.org/3/library/stdtypes.html?highlight=str#additional-methods-on-integer-types
