# Гайд по тому, как редактировать видео

## Инструменты

### Работа с субтитрами

**Обратите внимание, что русские субтитры – сгеренерированы при помощи ИИ. В них могут и будут ошибки и неточности. Если хочется исправить – присылай PR.**

- Получение субтитров из видео / аудио: https://any2text.ru
- Перевод субтитров и аудио: https://github.com/FOSWLY/vot-cli

### Скрипт для создания субтитров из английского видео

Перед созданием русских субтитров необходимо создать английские!

```bash
VIDEO_LINK='...'

# First, create audio:
npx vot-cli --output=. --lang=en --reslang=ru "$VIDEO_LINK"

# Double check the audio and then you can create subs, if everything is fine:
npx vot-cli --subs --output=. --lang=en --reslang=ru "$VIDEO_LINK"

# Then, convert the output file from json to srt:
python srt-from-json.py ru.json
```
