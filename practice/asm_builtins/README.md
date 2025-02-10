# Builtins implemented in x86_64 ASM

Reimplements some parts of the Python's builtins but in ASM. Currently supports:
- `builtins.print`, which calls `sys_write` syscall with x86_64 ASM directly from C

Why? Because I am bored. I created this just for fun for a video in my [the-best-python-course](https://github.com/sobolevn/the-best-python-course).

Please, don't use this!


## Usage

```python
>>> import asm_builtins

>>> asm_builtins.print("hello", "world")
"hello world"
```

😱


## Install

Clone this locally, `cd` into this folder and then:

```bash
pip install .
```


## License

[WTFPL](https://en.wikipedia.org/wiki/WTFPL)
