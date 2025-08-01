# Ссылки к выпуску

- Центрируем Command Palette https://code.visualstudio.com/updates/v1_97#_move-the-command-palette-and-quick-inputs

## Настройки

```json
{
    "workbench.activityBar.location": "hidden",
    "workbench.sideBar.location": "right"
}
```

## Горячие клавиши

```json
// Place your key bindings in this file to override the defaults
[
    {
        "key": "shift+cmd+g",
        "command": "workbench.view.scm",
        "when": "workbench.scm.active"
    },
    {
        "key": "ctrl+shift+g",
        "command": "-workbench.view.scm",
        "when": "workbench.scm.active"
    },
    {
        "key": "shift+cmd+o",
        "command": "outline.focus"
    }
]
```
