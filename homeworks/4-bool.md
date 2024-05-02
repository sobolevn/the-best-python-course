## Теория

База:
- Почему `all([]) is True` https://buttondown.email/hillelwayne/archive/why-all-is-true-prod-is-1-etc

Документация:
- https://docs.python.org/3/library/stdtypes.html#typebool
- https://docs.python.org/3/library/stdtypes.html#truth
- https://docs.python.org/3/c-api/bool.html

Исходники:
- Заголовок: https://github.com/python/cpython/blob/main/Include/boolobject.h и
- Имплементация, включая `_PyTrue_Struct` и `_PyFalseStruct`: https://github.com/python/cpython/blob/main/Objects/boolobject.c
- FlowGraph: https://github.com/python/cpython/blob/main/Python/flowgraph.c
