## Теория

База:
- `bytearray`: https://docs.python.org/3/library/stdtypes.html#bytearray
- Методы `MutableSequence`: https://docs.python.org/3/library/collections.abc.html#collections-abstract-base-classes
- `MutableSequence`: https://docs.python.org/3/library/collections.abc.html#collections.abc.MutableSequence

Жесть:
- Выбор стратегии для ресайза: https://github.com/python/cpython/blob/6309e9e07a855e08c223a0e295710c8bd66e793d/Objects/bytearrayobject.c#L195-L223
- Изменение `->ob_start`: https://github.com/python/cpython/blob/6309e9e07a855e08c223a0e295710c8bd66e793d/Objects/bytearrayobject.c#L457-L476

Мой PR с фиксом бага в `bytearray_getbuffer`: https://github.com/python/cpython/pull/126981
