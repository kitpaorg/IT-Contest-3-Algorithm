# IT-Contest-3-Algorithm

## 언어별 시간제한

* C, C++ = `기본시간제한`
* Python = `기본시간제한 * 2 + 1` 초
* Java = `기본시간제한 * 2` 초

## 서브태스크 세팅

* 본 대회에는 서브태스크 문제가 사용되었습니다. 서브태스크 설정은 기본적으로 각 문제 폴더의 config.json을 따릅니다.
* 각 문제의 config.json에서 "genscript" 속성은 각 문제에서 데이터를 생성하는 제너레이터 스크립트와 서브태스크 그룹 등을 포함하는 리스트입니다.
* 이 스크립트의 순서는 실제 데이터 (폴더 `IO`)의 순서와 동일합니다.
* 각 문제의 config.json에서 "subtask_group" 속성은 각 서브태스크 그룹의 이름과 위계적으로 종속되는 그룹의 이름을 포함하는 리스트입니다.

## 체커 셋팅

* 명시되지 않은 체커는 스탠더드 체커를 그대로 사용합니다. (Polygon 기준 ncmp)

## 예비소집 1번

* 제2회 청소년 IT경시대회 초1, 중1 문제와 동일

## 예비소집 2번

* 제목: `학술대회 참가신청`
* 시간제한: `1초`
* 메모리제한: `1024MB`
* 출제자: [`martinok1103`](https://www.acmicpc.net/user/martinok1103)
* 경로: `pb_kitpa-conference`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cc`

## A (초등부 1번, 중등부 1번)
* 제목: `맛있는 사과`
* 시간제한:`2초`
* 메모리제한: `1024MB`
* 출제자: [`kiwiyou`](https://www.acmicpc.net/user/kiwiyou)
* 경로: `a_tasty-apple`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`

## B (초등부 2번, 고등부 1번)
* 제목: `재미있는 파이프 퍼즐`
* 시간제한: `1초`
* 메모리제한: `1024MB`
* 출제자: [`ai4youej`](https://www.acmicpc.net/user/ai4youej)
* 경로: `b_connect-pipe`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`
* 체커: `./checker/yesno.cpp` (Polygon 기준 std::yesno)

## C (초등부 3번, 고등부 2번)
* 제목: `집합 연산`
* 시간제한: `5초`
* 메모리제한: `1024MB`
* 출제자: [`flappybird`](https://www.acmicpc.net/user/flappybird)
* 경로: `c_set-operations`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`

## D (중등부 2번)
* 제목: `괄호 문자열 편집기`
* 시간제한: `3초`
* 메모리제한: `1024MB`
* 출제자: [`hjroh0315`](https://www.acmicpc.net/user/hjroh0315)
* 경로: `d_rbs-query`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/vald.cpp`

## E (중등부 3번, 고등부 3번)
* 제목: `스파이`
* 시간제한: `4초`
* 메모리제한: `1024MB`
* 출제자: [`flappybird`](https://www.acmicpc.net/user/flappybird)
* 경로: `e_spies`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`

## F (고등부 4번)
* 제목: `하노이의 큐`
* 시간제한: `3초`
* 메모리제한: `1024MB`
* 출제자: [`hjroh0315`](https://www.acmicpc.net/user/hjroh0315)
* 경로: `f_queue-hanoi`
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/vald.cpp`
* 체커: `./checker/chkr.cpp`