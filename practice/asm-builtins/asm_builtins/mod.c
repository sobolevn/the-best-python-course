// TODO: possibly support other platforms and archs.
#if !defined(__x86_64__) || !defined(linux)
    #error "This module only supports x86_64 Linux for now."
#endif

#include <Python.h>

static long
sys_write_call(const char *msg, Py_ssize_t size)
{
    // TODO: allow to pass `fd` as `print(file=...)` does.
    long ret;
    asm volatile (
        // TODO: convert this ugly AT&T ASM into beautiful Intel one:
        "mov $1, %%rax\n"             // sys_write call number
        "mov $1, %%rdi\n"             // stdout=1 and stderr=2
        "mov %1, %%rsi\n"             // `msg` address
        "mov %2, %%rdx\n"             // `msg_len`
        "syscall\n"
        "mov %%rax, %0\n"             // save the result
        : "=r"(ret)
        : "r"(msg), "r"(size)         // inputs
        : "rax", "rdi", "rsi", "rdx"  // changed registers
    );

    // TODO: maybe handle special cases like `EINTR`
    return ret;
}

static PyObject *
print(PyObject *self, PyObject *args)
{
    // Don't expect much from this funny demo.
    // It does not support buffering, flushing, different `end` and `sep`.
    // It also does not support correct `stdout` captures and `file=` arguments.
    // This is just for fun.

    // TODO: this should be customizable
    const char *sep = " ";
    // TODO: this should be customizable, just like in CPython.
    const char *end = "\n";

    Py_ssize_t len = PyTuple_GET_SIZE(args);

    for (Py_ssize_t i = 0; i < len; i++) {
        PyObject *value = PyObject_Str(PyTuple_GET_ITEM(args, i));
        if (value == NULL) {
            goto error;
        }

        Py_ssize_t size;
        const char* msg = PyUnicode_AsUTF8AndSize(value, &size);
        Py_DECREF(value);
        if (msg == NULL) {
            goto error;
        }

        // Write our data with the syscall!
        // It is slow, bug prone, not portable, but it is cool!
        if (sys_write_call(msg, size) < 0) {
            goto write_error;
        }

        // Now print the separator, if there are still elements in args.
        if (i < len - 1) {
            if (sys_write_call(sep, strlen(sep)) < 0) {
                goto write_error;
            }
        }
        else if (i == len - 1) {
            // Now, print the end of the string,
            // which is the newline char by default.
            if (sys_write_call(end, strlen(end)) < 0) {
                goto write_error;
            }
        }
    }

    Py_RETURN_NONE;

write_error:
    PyErr_SetString(PyExc_OSError, "sys_write_call failed with no recover");

error:
    return NULL;
}

PyDoc_STRVAR(print__doc__,
"print($module, /, *args)\n"
"--\n"
"\n"
"Print passed args as strings.");


static PyMethodDef module_methods[] = {
    // TODO: also support `input`
    {"print", (PyCFunction)print, METH_VARARGS, print__doc__},
    {NULL}  // sentinel
};


static struct PyModuleDef asm_builtins_spec = {
    PyModuleDef_HEAD_INIT,
    "asm_builtins",
    PyDoc_STR("Builtins re-implemented in ASM"),
    -1,
    module_methods
};


PyMODINIT_FUNC PyInit_asm_builtins(void) {
    return PyModule_Create(&asm_builtins_spec);
}
