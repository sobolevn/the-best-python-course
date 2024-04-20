## Теория

База:
- Compiled vs Interpreted: https://www.freecodecamp.org/news/compiled-versus-interpreted-languages
- `.pyc`: https://peps.python.org/pep-0552

Документация:
- CAPI: https://docs.python.org/3.13/c-api

Исходники:
- JIT: https://github.com/python/cpython/tree/main/Tools/jit
- WASM: https://github.com/python/cpython/tree/main/Tools/wasm и https://github.com/psf/webassembly

## Практика

Возьмите [`mypyc`](https://github.com/python/mypy/tree/master/mypyc) и попытайтесь скомпилировать парочку модулей в своем проекте. Замерьте изменения производительности.
Какие модули дают самый большой прирост? (Подсказка: где меньше работы с сетью)
