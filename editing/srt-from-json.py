import sys
import json
import datetime as dt
from typing import Final

_TIME_FORMAT: Final = '%H:%M:%S,%f'


def _srt_from_json(filepath: str) -> int:
    with open(filepath, encoding='utf8') as json_file:
        contents = json.loads(json_file.read())

    start_time = None
    resulting_lines = []
    for index, entry in enumerate(contents['subtitles']):
        # Number
        resulting_lines.append(f'{index + 1}\n')

        # Time
        if start_time is None:
            start_time = dt.datetime(
                year=1, month=1, day=1, hour=0, minute=0, second=0,
            ) + dt.timedelta(milliseconds=entry['startMs'])
        end = start_time + dt.timedelta(milliseconds=entry['durationMs'])
        resulting_lines.append('{0} --> {1}\n'.format(
            start_time.strftime(_TIME_FORMAT),
            end.strftime(_TIME_FORMAT),
        ))
        start_time = None

        # Content
        resulting_lines.append(entry['text'])

        # Newlines
        resulting_lines.extend(['\n'] * 2)

    with open('out.srt', 'w', encoding='utf8') as output_file:
        output_file.writelines(resulting_lines)
    return 0


if __name__ == '__main__':
    sys.exit(_srt_from_json(filepath=sys.argv[1]))
