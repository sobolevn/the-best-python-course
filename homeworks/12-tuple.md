## Теория

Исходники:
- `tuple`: https://github.com/python/cpython/blob/main/Include/cpython/tupleobject.h
- `collections.namedtuple`: https://github.com/python/cpython/blob/baf65715fc9002e43cd0e1010b8dba9b4c84d503/Lib/collections/__init__.py#L361
- `typing.NamedTuple`: https://github.com/python/cpython/blob/baf65715fc9002e43cd0e1010b8dba9b4c84d503/Lib/typing.py#L2961-L3106

Документация:
- `collections.namedtuple`: https://docs.python.org/3/library/collections.html#collections.namedtuple
- `typing.NamedTuple`: https://docs.python.org/3/library/typing.html#typing.NamedTuple
- `PyTuple_SetItem`: https://docs.python.org/3/c-api/tuple.html#c.PyTuple_SetItem
- `PyStructSequence`: https://docs.python.org/3/c-api/tuple.html#struct-sequence-objects
- `ast.Tuple`: https://docs.python.org/3/library/ast.html#ast.Tuple
- `typing.Tuple[...]` и `tuple[...]`: https://docs.python.org/3/library/typing.html#annotating-tuples

Жесть:
- `Tuple` против `List`. Мы на самом деле немного врем людям, говоря, что разница в мутабельности и иммутабельности. Что на самом деле является лишь деталью реализации в Python. Ведь есть языки, где оба типа данных иммутабельны: Erlang, Haskell, тд. Фундаметальное различие лежит внутри Теории Категории. Из нее мы узнаем, что `Tuple` - тип произведение, а `List` (по хорошему) - монада (в питоне всего лишь моноид в смысле `l + []` и недо-функтор в смысле `map(f, l)`). Вот почему тип `List[x]` имеет kind `* -> *`, а `Tuple[x, ...]` имеет kind `* -> ... -> *`. Повторить Теорию Категорий: https://github.com/hmemcpy/milewski-ctfp-pdf
- `tuple` должен быть иммутабельным на уровне C: https://github.com/python/cpython/issues/127058
- Algebraic Data Types: https://jrsinclair.com/articles/2019/algebraic-data-types-what-i-wish-someone-had-explained-about-functional-programming/
- Теория категорий для программистов: https://github.com/hmemcpy/milewski-ctfp-pdf
- `BUILD_TUPLE`: https://docs.python.org/3/library/dis.html#opcode-BUILD_TUPLE
- `INTRINSIC_LIST_TO_TUPLE`: https://docs.python.org/3/library/dis.html#opcode-CALL_INTRINSIC_1
