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

## 예비소집 1번

* 제2회 청소년 IT경시대회 초1, 중1 문제와 동일

## 예비소집 2번

* 제목: `학술대회 참가신청`
* 출제: `martinok1103`
* 폴더: `kitpa-conference`
* 제한: TL 1초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cc`
* 체커는 스탠더드 체커를 그대로 사용합니다. (Polygon 기준 wcmp)

## A (초등부 1번, 중등부 1번)
* 제목: `맛있는 사과`
* 출제: `kiwiyou`
* 폴더: `tasty-apple`
* 제한: TL 2초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`
* 체커는 스탠더드 체커를 그대로 사용합니다. (Polygon 기준 ncmp)

## B (초등부 2번, 고등부 1번)
* 제목: `재미있는 파이프 퍼즐`
* 출제: `ai4youej`
* 폴더: `connect-pipe`
* 제한: TL 1초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`
* 체커: `./checker/yesno.cpp` (Polygon 기준 std::yesno)

## C (초등부 3번, 고등부 2번)
* 제목: `집합 연산`
* 출제: `flappybird`
* 폴더: `set-operations`
* 제한: TL 5초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`
* 체커는 스탠더드 체커를 그대로 사용합니다. (Polygon 기준 ncmp)

## D (중등부 2번)
* 제목: `괄호 문자열 편집기`
* 출제: `hjroh0315`
* 폴더: `rbs-query`
* 제한: TL 3초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/vald.cpp`
* 체커는 스탠더드 체커를 그대로 사용합니다. (Polygon 기준 ncmp)

## E (중등부 3번, 고등부 3번)
* 제목: `스파이`
* 출제: `flappybird`
* 폴더: `spies`
* 제한: TL 4초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/validator.cpp`
* 체커는 스탠더드 체커를 그대로 사용합니다. (Polygon 기준 ncmp)

## F (고등부 4번)
* 제목: `하노이의 큐`
* 출제: `hjroh0315`
* 폴더: `queue-hanoi`
* 제한: TL 3초, ML 1024MB
* 지문: `./statement/statement.md`
* 데이터: `./IO`
* 밸리데이터: `./validator/vald.cpp`
* 체커: `./checker/chkr.cpp`