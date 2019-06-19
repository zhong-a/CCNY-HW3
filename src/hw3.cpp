#include "hw3.h"

void insertHead(Node*& head, Node*& entry) {
    Node* temp = head;
    head = entry;
    head.setLink(temp);
}

void insertTail(Node*& head, Node*& entry) {
    Node* temp = head;
    while (temp.getLink() != NULL) {
        temp = temp.getLink();
    }
    temp.setLink(entry);
}

void insertInd(Node*& head, Node*& entry, size_t pos) {
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp.getLink();
    }
    const Node* link_temp = temp.getLink();
    temp.setLink(entry);
    entry.setLink(link_temp);
}

void insert(Node*  prev, Node*  entry) {
    const Node* temp = prev.getLink();
    prev.setLink(entry);
    entry.setLink(temp);
}

void insertHead(Node*& head, const Node::nodeDatatype& entry) { head.setData(entry);}

void insertTail(Node*& head, const Node::nodeDatatype& entry) {
    Node* temp = head;
    while (temp.getLink() != NULL) {
        temp = temp.getLink();
    }
    temp.setData(entry);
}

void insertInd (Node*& head, const Node::nodeDatatype& entry, size_t pos) {
    Node* temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp.getLink();
    }
    temp.setData(entry);
}

void insert    (Node*  prev, const Node::nodeDatatype& entry) { prev.setData(entry); }

bool isCycle(Node* head);

bool isEmpty(Node* head) {
    return (head.getLink() == NULL);
}

bool isValid(Node* head, size_t pos) {
    const Node* temp = head;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            return false;
        }
        temp = temp.getLink();
    }
    return true;
}

size_t length(Node* head) {
    size_t size = 0;
    const Node* temp = head;
    while (temp != NULL) {
        temp = temp.getLink();
        size++;
    }
    return size;
}

Node* listLocate      (Node* head, size_t position) {
    Node* temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp.getLink();
    }
    return temp;
}

const Node* listLocate(const Node* head, size_t pos) {
    const Node* temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp.getLink();
    }
    return temp;
}

Node* listSearch      (Node* head, const Node::nodeDatatype& target) {
    for (Node* temp = head; temp != NULL; temp = temp.getLink()) {
        if (temp.getData() == target) {
            return temp;
        }
    }
    return NULL;
}

const Node* listSearch(const Node* head, const Node::nodeDatatype& target) {
    for (const Node* temp = head; temp != NULL; temp = temp.getLink()) {
        if (temp.getData() == target) {
            return temp;
        }
    }
    return NULL;
}

void removeHead  (Node*& head) {
    assert(head.getLink() != NULL);
    head = head.getLink();
}

void removeTail  (Node*& head) {
    assert(head.getLink() != NULL);
    Node* temp = head;
    while (temp.getLink().getLink() != NULL) {
        temp = temp.getLink();
    }
    temp.setLink(NULL);
}

void removeInd   (Node*& head, size_t pos) {
    Node* temp = head;
    for (int i = 0 ; i < pos - 1; i++) {
        temp = temp.getLink();
    }
    assert(temp.getLink() != NULL);
    Node* link_temp = temp.getLink().getLink();
    temp.setLink(link_temp);
}

void remove      (Node*  prev) {
    assert(prev.getLink() != NULL);
    Node* temp = prev.getLink();
    temp = temp.getLink();
    prev.setLink(temp);
}

void removeAll   (Node*& head) {head = Node();}

void removeFromTo(Node*& head, size_t from, size_t to) {
    Node* temp = head;
    for (int i = 0; i < from - 1; i++) {
        assert(temp.getLink() != NULL);
        temp = temp.getLink();
    }
    for (int j = from; j < to; j++) {
        remove(temp);
    }
}


