#include "queue.h"

template <typename T>
Queue<T>::Queue() : data(new T[10]), size(0), capacity(10) {}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
    data = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    data = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
void Queue<T>::enqueue(const T& element) {
    if (size == capacity) {
        // Double the capacity of the queue
        capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[size++] = element;
}

template <typename T>
void Queue<T>::enqueueWithPriority(const T& element, bool pointers) {
    if (size == capacity) {
        // Double the capacity of the queue
        capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    int i = size - 1;
    while (i >= 0 && data[i] < element && !pointers) {
        data[i + 1] = data[i];
        i--;
    }
    while (i >= 0 && *data[i] < *element && pointers) {
        data[i + 1] = data[i];
        i--;
    }
    data[i + 1] = element;
    size++;
}

template <typename T>
T& Queue<T>::peek() const {
    return data[0];
}

template <typename T>
void Queue<T>::dequeue() {
    // Shift all elements one position to the left
    for (int i = 1; i < size; i++) {
        data[i - 1] = data[i];
    }

    size--;
}

template <typename T>
void Queue<T>::clear() {
    size = 0;
}

template <typename T>
int Queue<T>::getSize() {
    return size;
}

template <typename T>
void Queue<T>::sortByPriority(bool pointers) {
    // using insertion sort algorithm
    for (int i = 1; i < size; i++) {
        T temp = data[i];
        int j = i - 1;
        if (pointers) {
            while (j >= 0 && *data[j] < *temp) {
                data[j + 1] = data[j];
                j--;
            }
        } else {
            while (j >= 0 && data[j] < temp) {
                data[j + 1] = data[j];
                j--;
            }
        }
        data[j + 1] = temp;
    }
}

template <typename T>
T Queue<T>::getBest() const {
    return data[size - 1];
}

template <typename T>
bool Queue<T>::isSorted() {
    // Check if the queue has fewer than 2 elements
    if (size < 2) {
        return true;
    }

    // Iterate through the elements of the queue and check if they are sorted
    for (int i = 1; i < size; i++) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& q) {
    for (int i = 0; i < q.size; i++) {
        out << q.data[i];
        if (i < q.size - 1) {
            out << "\n";
        }
    }
    return out;
}
