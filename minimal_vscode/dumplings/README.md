# Запуск рецептов

Устанавливаем [`chef`](https://github.com/Zheoni/cooklang-chef):

```bash
cargo install --git https://github.com/Zheoni/cooklang-chef --tag "v0.10.1" --locked
```

Переходим в папку с рецептами:

```bash
cd minimal_vscode/dumplings
```

Запускаем UI:

```bash
chef serve --port 8000 --path .
```

Запускаем через CLI:

```bash
chef recipe <RECIPE_NAME>
```
