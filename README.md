# DataStructure Lab (C++ From Scratch)

표준 템플릿 라이브러리(STL)를 사용하지 않고, C++을 이용해 주요 자료구조들을 직접 설계하고 구현하며 내부 동작 원리와 메모리 관리 기법을 심층적으로 학습한 프로젝트입니다.

## 🚀 프로젝트 핵심 목표

* **From Scratch 구현**: 각 자료구조의 내부 구조와 알고리즘을 외부 라이브러리 없이 직접 구현
* **메모리 최적화**: 동적 할당 관리 및 효율적인 데이터 재배치 알고리즘 학습
* **객체지향 설계**: 추상 클래스를 활용한 인터페이스 기반 설계 및 코드 재사용성 확보

---

## 🛠 구현된 자료구조



### 1. Stack & Queue

* **Stack**: 동적 배열 기반으로 구현되었으며, `Grow`와 `Reserve`를 통해 가변적인 용량 관리가 가능합니다.
* **Queue**: 메모리 효율을 위해 **원형 큐(Circular Queue)** 형태로 설계되었으며, 데이터 Full 상태 시 자동 확장을 지원합니다.

### 2. LinkedList

* **이중 연결 리스트(Doubly Linked List)** 형태로 구현되어 양방향 탐색이 가능합니다.
* 노드 삽입, 삭제, 특정 위치 접근(`At`) 기능 및 안전한 메모리 해제를 위한 `Clear`를 제공합니다.

### 3. HashTable

* **Open Addressing** 방식 중 **Linear Probing**을 채택하여 구현했습니다.
* 데이터 삭제 시 발생하는 클러스터링을 해결하기 위해 빈 슬롯을 최적화하여 채우는 재배치 로직이 포함됩니다.
* 로드 팩터(0.7)에 따라 테이블 크기를 확장하는 `ReHash` 기능을 지원합니다.

### 4. Tree & Heap

* **Binary Search Tree (BST)**: 노드 삭제 시 `DeleteByCopying`과 `DeleteByMerging` 전략을 모두 구현했습니다.
* **Heap**: `std::vector`를 기반으로 한 **Max Heap** 구조로, `Heapify` 알고리즘을 통해 우선순위 큐를 구현했습니다.

---

## 💻 주요 학습 포인트

* **C++ Modern Features**: `std::optional`을 활용하여 예외 상황을 안전하게 처리했습니다.
* **메모리 관리**: 복사 생성자와 이동 생성자를 직접 구현하여 깊은 복사와 자원 이동의 차이를 익혔습니다.
* **인터페이스 활용**: 모든 자료구조는 `IDataStructure`를 상속받아 일관된 테스트 인터페이스를 가집니다.

## ⚙️ 실행 환경

* **Language**: C++20
* **IDE**: Visual Studio 2022
* **Platform**: Windows (Win32/x64)

---

## 📝 향후 개선 계획 (Roadmap)

* [ ] HashTable에 Robin Hood Hashing 기법 적용 고려
* [ ] HashTable의 Key 타입을 `string`으로 확장 구현
* [ ] BST의 균형을 유지하기 위한 AVL Tree 또는 Red-Black Tree 확장
