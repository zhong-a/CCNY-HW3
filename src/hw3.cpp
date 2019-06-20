#include "hw3.h"

void insertHead(Node*& head, Node*& entry) {
    Node* temp = head;
    head = entry;
    head->setLink(temp);
}

void insertTail(Node*& head, Node*& entry) {
    if (head == NULL) {
        insertHead(head, entry);
        return;
    }
    while (head->getLink() != NULL) {
        head = head->getLink();
    }
    head->setLink(entry);
}

void insertInd(Node*& head, Node*& entry, size_t pos) {
    if (head == NULL) {
        insertHead(head, entry);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->getLink();
    }
    Node* link_temp = temp->getLink();
    temp->setLink(entry);
    entry->setLink(link_temp);
}

void insert(Node*  prev, Node*  entry) {
    Node* temp = prev->getLink();
    prev->setLink(entry);
    entry->setLink(temp);
}

void insertHead(Node*& head, const Node::nodeDatatype& entry) {
    if (head == NULL) {
        head = new Node();
        head->setData(entry);
        return;
    }
    Node* temp;
    temp->setData(head->getData());
    temp->setLink(head->getLink());
    head->setData(entry);
    head->setLink(temp);
}

void insertTail(Node*& head, const Node::nodeDatatype& entry) {
    if (head == NULL) {
        head = new Node();
        head->setData(entry);
        return;
    }
    Node* temp = head;
    while (temp->getLink() != NULL) {
        temp = temp->getLink();
    }
    Node* new_tail = new Node();
    new_tail->setData(entry);
    temp->setLink(new_tail);
}

void insertInd (Node*& head, const Node::nodeDatatype& entry, size_t pos) {
    if (head == NULL && pos == 0) {
        head = new Node();
        head->setData(entry);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->getLink();
    }
    Node* temp_link = temp->getLink();
    Node* new_node = new Node();
    new_node->setData(entry);
    temp->setLink(new_node);
    new_node->setLink(temp_link);
}

void insert    (Node*  prev, const Node::nodeDatatype& entry) { prev->setData(entry); }

bool isCycle(Node* head) {
    Node* temp = new Node();
    while (head != NULL) {
        if (head->getLink() == NULL) {
            return false;
        }
        if (head->getLink() == temp) {
            return true;
        }
        Node* nex = head->getLink();
        head->setLink(temp);
        head = nex;
    }
    return false;
}

bool isEmpty(Node* head) {
    return (head == NULL);
}

bool isValid(Node* head, size_t pos) {
    if (head == NULL) {
        return false;
    }
    const Node* temp = head;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            return false;
        }
        temp = temp->getLink();
    }
    return true;
}

size_t length(Node* head) {
    size_t size = 0;
    const Node* temp = head;
    while (temp != NULL) {
        temp = temp->getLink();
        size++;
    }
    return size;
}

Node* listLocate      (Node* head, size_t position) {
    Node* temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->getLink();
    }
    return temp;
}

const Node* listLocate(const Node* head, size_t pos) {
    const Node* temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->getLink();
    }
    return temp;
}

Node* listSearch      (Node* head, const Node::nodeDatatype& target) {
    for (Node* temp = head; temp != NULL; temp = temp->getLink()) {
        if (temp->getData() == target) {
            return temp;
        }
    }
    return NULL;
}

const Node* listSearch(const Node* head, const Node::nodeDatatype& target) {
    for (const Node* temp = head; temp != NULL; temp = temp->getLink()) {
        if (temp->getData() == target) {
            return temp;
        }
    }
    return NULL;
}

void removeHead  (Node*& head) {
    if (head == NULL) {
        return;
    }
    head = head->getLink();
}

void removeTail  (Node*& head) {
    if (head == NULL) {
        return;
    }
    if (head->getLink() == NULL) {
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->getLink()->getLink() != NULL) {
        temp = temp->getLink();
    }
    temp->setLink(NULL);
}

void removeInd   (Node*& head, size_t pos) {
    if (pos == 0) {
        removeHead(head);
        return;
    }
    Node* temp = head;
    for (int i = 0 ; i < pos - 1; i++) {
        temp = temp->getLink();
    }
    assert(temp->getLink() != NULL);
    Node* link_temp = temp->getLink()->getLink();
    temp->setLink(link_temp);
}

void remove      (Node*  prev) {
    assert(prev->getLink() != NULL);
    Node* temp = prev->getLink();
    temp = temp->getLink();
    prev->setLink(temp);
}

void removeAll   (Node*& head) {head = NULL;}

void removeFromTo(Node*& head, size_t from, size_t to) {
    Node* temp = head;
    for (int i = 0; i < from - 1; i++) {
        assert(temp->getLink() != NULL);
        temp = temp->getLink();
    }
    for (int j = from; j < to; j++) {
        remove(temp);
    }
}

void removeHeadTo(Node*& head, size_t to) {
    for (int i = 0 ; i < to - 1; i++) {
        remove(head);
    }
    removeHead(head);
}
void removeToTail(Node*& head, size_t from) {
    for (int i = 0; i < from - 1; i++) {
        assert(head->getLink() != NULL);
        head = head->getLink();
    }
    while (head != NULL) {
        remove(head);
    }
}

void reverse(Node*& head) {
    Node* temp = head;
    Node* prev = NULL;
    Node* nex = NULL;
    while (temp != NULL) {
        nex = temp->getLink();
        temp->setLink(prev);
        prev = temp;
        temp = nex;
    }
    head = prev;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->getData() << " ";
    }
    cout << endl;
}

void swap(Node*& head, size_t pos) {
    if (head == NULL || head->getLink() == NULL) {//only one item
        return;
    }
    if (pos == 0) {
        Node* s = head->getLink();
        Node* s_out = s->getLink();
        s->setLink(head);
        head->setLink(s_out);
        head = s;
    }
    Node* prev = head;
    Node* s1 = head->getLink();
    for (int i = 0; i < pos - 1; i++) {
        if (s1->getLink() == NULL) {
            return;
        }
        s1 = s1->getLink();
        prev = prev->getLink();
    }
    Node* s2 = s1->getLink();
    Node* s2_out = s2->getLink();
    prev->setLink(s2);
    s2->setLink(s1);
    s1->setLink(s2_out);
}

void swapHead(Node*& head, size_t pos) {
    if (head == NULL || pos == 0) {
        return;
    }
    if (pos == 1) {
        Node* s = head->getLink();
        Node* s_next = s->getLink();
        s->setLink(head);
        head->setLink(s_next);
        head = s;
        return;
    }
    Node* head_next = head->getLink();
    Node* s = head->getLink();
    Node* prev = head;
    for (int i = 0; i < pos - 1; i ++) {
        if (s->getLink() == NULL) {
            return;
        }
        s = s->getLink();
        prev = prev->getLink();
    }
    Node* s_next = s->getLink();
    prev->setLink(head);
    head->setLink(s_next);
    s->setLink(head_next);
    head = s;
    
}

void swap(Node*& head, size_t posI, size_t posJ) {
    if (head == NULL || head->getLink() == NULL) {// Empty or only one item
        return;
    }
    Node* prev_i = head;
    Node* prev_j = head;
    Node* p_i = head->getLink();
    Node* p_j = head->getLink();
    if (posI == 0) {
        swapHead(head, posJ);
    }
    else if (posJ == 0) {
        swapHead(head, posI);
    }
    else {
        if (posJ = posI + 1) {
            swap(head, posI);
            return;
        }
        for (int i = 0; i < posI - 1; i++) {
            if (p_i->getLink() == NULL) {
                return;
            }
            p_i = p_i->getLink();
            prev_i = prev_i->getLink();
        }
        for (int j = 0; j < posJ - 1; j++) {
            if (p_j->getLink() == NULL) {
                return;
            }
            p_j = p_j->getLink();
            prev_j = prev_j->getLink();
        }
        Node* i_next = p_i->getLink();
        Node* j_next = p_j->getLink();
        prev_i->setLink(p_j);
        p_j->setLink(i_next);
        prev_j->setLink(p_i);
        p_i->setLink(j_next);
    }
}
            


