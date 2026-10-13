# baekjoon-solution 분석

## 목적과 현재 범위

백준 문제 풀이를 C++와 Python으로 나란히 보관하는 저장소입니다. 문제 번호별 소스와 코드 생성·포맷 확인 도구를 포함합니다.

파일별 구현을 찾아 사용하는 풀이·알고리즘 자료 모음입니다. 하나의 서비스로 일괄 실행하는 구조로 보기보다 문제 번호나 주제별 소스, 구현 예제와 보조 도구를 구분해서 읽는 것이 적절합니다.

## 주요 구성과 역할

| 경로 | 역할 또는 확인한 내용 |
| --- | --- |
| [solutions/cpp/](solutions/cpp/) | 문제 번호별 C++ 풀이 |
| [solutions/python/](solutions/python/) | 문제 번호별 Python 풀이 |
| [utils/generate.py](utils/generate.py) | 풀이 파일 생성 도구 |
| [utils/check_format.sh](utils/check_format.sh) | 포맷 확인 스크립트 |
| [utils/requirements.txt](utils/requirements.txt) | 보조 도구 의존성 |

파일 구성에서 확인되는 형식은 C++ 19개, Python 19개, Shell 3개입니다. 헤더와 예제·보조 코드를 포함한 파일 수이며 기능 개수나 구현 완성도를 뜻하지 않습니다.

## 소스에서 확인한 인터페이스

| 파일 | 정적으로 확인한 정의 |
| --- | --- |
| [solutions/python/1392/main.py](solutions/python/1392/main.py) | `input`, `solution` |
| [solutions/python/1522/main.py](solutions/python/1522/main.py) | `input`, `solution` |
| [solutions/python/16113/main.py](solutions/python/16113/main.py) | `input`, `solution` |
| [solutions/python/17288/main.py](solutions/python/17288/main.py) | `input`, `solution` |
| [solutions/python/2179/main.py](solutions/python/2179/main.py) | `input`, `compare`, `solution` |
| [solutions/python/25326/main.py](solutions/python/25326/main.py) | `input`, `get_index`, `solution` |

이 목록은 파일의 함수·클래스 이름과 라우트 정의를 정적으로 읽은 결과입니다. 모든 정의가 공개 API라는 뜻은 아니며 실제 호출 관계와 입력 형식은 각 구현을 함께 확인해야 합니다.

## 설치와 사용을 확인하는 방법

[utils/requirements.txt](utils/requirements.txt)에서 프로젝트 설정을 확인합니다. 의존성에는 `black`, `cpplint`, `pre-commit` 등이 있습니다.

각 문제 폴더의 `main.cpp` 또는 `main.py`를 선택해 개별 프로그램으로 실행합니다. `simulation`·`dp` 등 보조 구현도 포함되므로 파일별 용도를 확인하세요.

## 근거와 분석 범위

분석일: 2026-10-13 (Asia/Seoul). 문서 변경 전 소스 기준 커밋: `b50e88db6cce315794f7941090fad43c2a5f2b49`.

근거는 해당 기본 브랜치의 파일 목록, [README.md](README.md) 및 위에 연결한 소스·설정입니다. Python 파일과 표에 명시한 Notebook은 코드를 실행하지 않고 정적으로 살펴봤습니다. 그 외 파일은 구성과 원래 문서를 기준으로 설명했습니다. 의존성 설치, 학습, 서버·하드웨어 실행과 외부 서비스 연결은 검증하지 않았으므로 운영 상태나 성능의 증거로 사용할 수는 없습니다.
