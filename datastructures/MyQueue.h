#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

#include "../GlobVals/Globals.h"

/*
    My main changes to default queue:
        function sortByPriority(bool) - sorts the queue by priority
        that gets boolean value
        if true - then function know that that is pointers and need to unpack them
        if false - just use regular comparasion between two elements
*/
template <typename T>
class Queue {
   private:
    T* data;
    int size;
    int capacity;

   public:
    // Constructs a new queue with a default capacity of 10.
    Queue() : data(new T[10]), size(0), capacity(10) {}

    // Constructs a new queue as a copy of an existing queue.
    Queue(const Queue<T>& other) {
        data = new T[other.capacity];
        size = other.size;
        capacity = other.capacity;
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Destroys the queue.
    ~Queue() {
        delete[] data;
    }

    // Assigns one queue to another, so that they have the same elements.
    Queue<T>& operator=(const Queue<T>& other) {
        data = new T[other.capacity];
        size = other.size;
        capacity = other.capacity;
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Adds a new element to the end of the queue.
    void enqueue(const T& element) {
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

    // Adds a new element to the queue with a given priority.
    // This function assumes that the queue is already sorted and inserts the element in the correct position.
    void enqueueWithPriority(const T& element, bool pointers = false) {
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

    // Returns the element at the head of the queue.
    T& peek() {
        return data[0];
    }

    // Removes the element at the head of the queue.
    void dequeue() {
        // Shift all elements one position to the left
        for (int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }

        size--;
    }

    // Clears the queue.
    void clear() {
        size = 0;
    }

    // Returns the number of elements in the queue.
    int getSize() {
        return size;
    }

    // Sorts the queue by priority using the operator < function that is implemented between two members.
    void sortByPriority(bool pointers = false) {
        // Insertion sort algorithm
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

    T getBest() {
        return data[size - 1];
    }

    bool isSorted() {
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

    friend std::ostream& operator<<(std::ostream& out, const Queue<T>& q) {
        for (int i = 0; i < q.size; i++) {
            out << q.data[i];
            if (i < q.size - 1) {
                out << "\n";
            }
        }
        return out;
    }

    bool isEmpty() {
        return size == 0;
    }
};

#endif  // QUEUE_H_
