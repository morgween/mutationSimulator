#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
/*
    My main changes to default queue:
        function sortByPriority(bool) - sorts the queue by priority gets boolean value
            1 - then function know that that is pointers and need to unpack them
            0 - just use regular comparasion between two elements
*/
template <typename T>
class Queue {
   private:
    T* data;
    int size;
    int capacity;

   public:
    // Constructors, Destructor, and Assignment Operator
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& other);

    // Queue Operations
    void enqueue(const T& element);
    void enqueueWithPriority(const T& element, bool pointers = false);
    T& peek() const;
    void dequeue();
    void clear();
    int getSize();
    void sortByPriority(bool pointers = false);
    T getBest() const;
    bool isSorted();

    // Friend Function to Print the Queue
    friend std::ostream& operator<<(std::ostream& out, const Queue<T>& q);
};

#endif  // QUEUE_H_
