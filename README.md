# IT-Contest-3-Algorithm

## 언어별 시간제한

* C, C++ = `기본시간제한`
* Python = `기본시간제한 * 2 + 1` 초
* Java = `기본시간제한 * 2` 초

## 서브태스크 세팅

* 본 대회에는 서브태스크 문제가 사용되었습니다. 서브태스크 설정은 기본적으로 각 문제 폴더의 config.json을 따릅니다.
* 각 문제의 config.json에서 `genscript` 속성은 각 문제에서 데이터를 생성하는 제너레이터 스크립트와 서브태스크 그룹 등을 포함하는 리스트입니다.
* 이 스크립트의 순서는 실제 데이터 (폴더 `IO`)의 순서와 동일합니다.
* 각 문제의 config.json에서 `subtask_group` 속성은 각 서브태스크 그룹의 이름과 위계적으로 종속되는 그룹의 이름을 포함하는 리스트입니다.

## 포팅 가이드

* 각 문제 폴더의 config.json은 문제에서 중요한 config를 대부분 포함합니다.
  * `checker`, `checker_language`, `validator`, `validator_language`는 각각 체커, 체커 언어 (기본 C++17), 밸리데이터, 밸리데이터 언어 (마찬가지, 기본 C++17)입니다. 이하에 문제별로 다시 제시하고 있으므로 별도로 읽을 필요는 없습니다.
  * `limits.time`은 TL, `limits.memory`는 ML입니다.
  * `generators`는 문제의 제너레이터 목록입니다. 제너레이터 파일은 각 문제의 `generator` 폴더에 있습니다.
  * `subtask_group`은 서브태스크 세팅에 설명하였으므로 생략합니다.
  * `genscript`에서 `is_example`이 `true`인 것만 예제 데이터에 해당합니다.
* 각 문제의 `problem.md`에 사진 링크가 있는 경우가 있습니다. 각 사진 링크는 [Project PS](https://project-ps.com/)의 AWS에 연결되어 있기 때문에 그대로 복사할 경우 불필요한 트래픽이 발생할 수 있습니다. 이에 따라 각 플랫폼에서 별도로 업로드한 사진 링크를 사용할 것을 강하게 권장합니다.

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
