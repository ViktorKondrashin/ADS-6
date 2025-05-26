// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  class TPQueue {
 public:
  TPQueue() = default;
  ~TPQueue() {
    // Удаление всех узлов
    while (head != nullptr) {
      Node* tempNode = head;
      head = head->next;
      delete tempNode;
    }
  }

  // Вставка и продвижение по приоритету узла в списке (O(n))
  void push(T elem) {
    Node* newNode = new Node{elem, nullptr};
    // Вариант с отсутствием всех узлов
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node* cur = head;
    Node* prev = nullptr;
    // Выбираем место для нового узла
    while (cur != nullptr && cur->data.prior >= elem.prior) {
      prev = cur;
      cur = cur->next;
    }
    if (cur == nullptr) {
      prev->next = newNode;
    } else if (prev == nullptr) {
      newNode->next = head;
      head = newNode;
    } else {
      prev->next = newNode;
      newNode->next = cur;
    }
  }

  // Удаление одного узла с головы (O(1))
  T pop() {
    if (isEmpty()) {
      throw std::runtime_error("Delete in empty list");
    }
    Node* tempNode = head;
    T tempElem = head->data;
    head = head->next;
    delete tempNode;
    return tempElem;
  }

  bool isEmpty() const { return head == nullptr; }

 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* head = nullptr;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
