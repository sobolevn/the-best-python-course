## Теория

База:
- `bytes-like`: https://docs.python.org/3/glossary.html#term-bytes-like-object
- `bytes`: https://docs.python.org/3/library/stdtypes.html#bytes
- Making the buffer protocol accessible in Python: https://peps.python.org/pep-0688

Инструменты:
- mypy: bytes и bytearray c `disable_bytearray_promotion` и `disable_memoryview_promotion` https://github.com/python/mypy/commit/2d70ac0b33b448d5ef51c0856571068dd0754af6

Жесть:
- Мутабельность `bytes` https://docs.python.org/3.13/c-api/bytes.html#c._PyBytes_Resize
- `PyBytes_Writer` API: https://github.com/capi-workgroup/decisions/issues/39
