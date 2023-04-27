// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T>
class TPQueue {
    // реализация шаблона очереди с приоритетом на связанном списке
    private:
    struct Item {
        T data;
        Item* next;
        /* data */
    };
    Item* head;
    Item* tail;

   public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    void push(const T& value) {
        Item* temp = new Item;  // create new elem
        temp->data = value;
        temp->next = nullptr;
        if (nullptr == head) {
            head = temp;  // only for first elem
            tail = temp;  // set tail, head
            return;
        }
        if (value.prior > head->data.prior) {
            // add to head if new prt > now prt
            temp->next = head;  // change ptr temp
            head = temp;        // change head
            return;
        }
        Item* cur = head; // like iterator
        while (cur->next != nullptr 
            && cur->next->data.prior >= value.prior) {
            cur = cur->next; // adding to tail by prt
        }
        temp->next = cur->next;
        cur->next = temp;
        if (nullptr == temp->next) 
            tail = temp;  // change tail
    }
    const T pop() {
        Item* temp = head;
        T result = temp->data;
        head = head->next; // change head
        delete temp;
        return result;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

