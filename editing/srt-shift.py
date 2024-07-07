import argparse
import sys
import datetime as dt
from io import TextIOWrapper

import srt


def _update_time(
    start: dt.datetime,
    delta: dt.timedelta,
    *,
    is_negative: bool,
) -> dt.datetime:
    if is_negative:
        return start - delta
    return start + delta


def _cut_since_with_duration(
    fileobj: TextIOWrapper,
    since: int,
    duration: str,
    *,
    is_negative: bool,
) -> int:
    delta = dt.timedelta(seconds=duration)

    captions = srt.parse(fileobj.read())
    fileobj.close()

    updated_srt = []
    for caption in captions:
        if caption.index >= since:
            caption.start = _update_time(
                caption.start, delta, is_negative=is_negative,
            )
            caption.end = _update_time(
                caption.end, delta, is_negative=is_negative,
            )
        updated_srt.append(caption)

    with open('out.srt', mode='w', encoding='utf8') as out:
        out.write(srt.compose(updated_srt))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(__name__)
    parser.add_argument('fileobj', type=argparse.FileType())
    parser.add_argument('--since', type=int)
    parser.add_argument('--seconds', type=int)
    parser.add_argument('--negative', action='store_true')
    args = parser.parse_args()

    code = _cut_since_with_duration(
        args.fileobj,
        args.since,
        duration=args.seconds,
        is_negative=args.negative,
    )
    sys.exit(code)
