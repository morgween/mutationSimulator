    #include "../Headers/Population.h"

    Population::Population(Queue<Virus *> vL, int tU) {
        step = 0;
        virusesList = vL;
        timeUnits = tU;
        theBestOfAllTime = virusesList.getBest()->toString();
        bestIndex = virusesList.getBest()->getErrorIndex();
    }

    Population::Population() : virusesList() {
        step = 0;
        timeUnits = 0;
        bestIndex = 0;
    }
    Population::Population(const Population &other) : virusesList(other.virusesList) {
        theBestOfAllTime = other.theBestOfAllTime;
        bestIndex = other.bestIndex;
        timeUnits = other.timeUnits;
        step = other.step;
        isEnded = other.isEnded;
    }

    Population::Population(Population &&other) : virusesList(other.virusesList) {
        theBestOfAllTime = other.theBestOfAllTime;
        bestIndex = other.bestIndex;
        timeUnits = other.timeUnits;
        step = other.step;
        isEnded = other.isEnded;
    }

    Population &Population::operator=(Population &other) {
        virusesList = other.virusesList;
        theBestOfAllTime = other.theBestOfAllTime;
        bestIndex = other.bestIndex;
        timeUnits = other.timeUnits;
        step = other.step;
        isEnded = other.isEnded;
        return *this;
    }

    Population &Population::operator=(Population &&other) {
        virusesList = other.virusesList;
        theBestOfAllTime = other.theBestOfAllTime;
        bestIndex = other.bestIndex;
        timeUnits = other.timeUnits;
        step = other.step;
        isEnded = other.isEnded;
        return *this;
    }

    void Population::happyEnding() {
        virusesList.sortByPriority(true);
        std::cout << virusesList << "\n\n"
                << theBestOfAllTime << std::endl;
        Globals::destroy();
        std::exit(-1);
    }

    void Population::update() {
        if (step == 0) {
            virusesList.sortByPriority(true);
            if (step != timeUnits) {
                step++;
                return;
            } else {
                happyEnding();
            }
        }
        if (!isAllP) updateGroup();
        updateVectors();
        if (!virusesList.isSorted()) {
            virusesList.sortByPriority(true);
        }

        if (virusesList.getBest()->getErrorIndex() < bestIndex) {
            theBestOfAllTime = virusesList.getBest()->toString();
            bestIndex = virusesList.getBest()->getErrorIndex();
        }
        if (virusesList.getBest()->getErrorIndex() == 0.0 || step == timeUnits) {
            isEnded = true;
            happyEnding();
            return;
        }
        step++;
    }
    Population Population::operator++(int) {
        update();
        return *this;
    }

    void Population::print() {
        std::cout << virusesList << std::endl;
    }

    void Population::updateVectors() {
        int size = virusesList.getSize();
        Queue<Virus *> tmpQueue;
        for (int i = 0; i < size; i++) {
            Virus *v1 = virusesList.peek();
            virusesList.dequeue();
            v1->update();
            tmpQueue.enqueue(v1);
        }
        for (int i = 0; i < size; i++) {
            virusesList.enqueue(tmpQueue.peek());
            tmpQueue.dequeue();
        }
    }
    void Population::updateGroup() {
        // if Papilloma - find next virus that is not papilloma and the dequeue it
        Queue<Virus *> tmpQueue;
        int size = virusesList.getSize();
        int i = 0;

        // dequeue until not of type papilloma
        while (i < size && virusesList.peek()->getSubGroup() == 'P') {
            tmpQueue.enqueue(virusesList.peek());
            virusesList.dequeue();
            i++;
        }
        if (i == size) {
            isAllP = true;
        } else
            virusesList.dequeue();  // dequeue virus that is not papilloma

        // enqueue back
        while (i > 0) {
            virusesList.enqueueWithPriority(tmpQueue.peek(), true);
            tmpQueue.dequeue();
            i--;
        }

        if (virusesList.getBest()->getSubGroup() == 'L') {
            Lentivirus *tmp = new Lentivirus(*dynamic_cast<Lentivirus *>(virusesList.getBest()));
            tmp->updateName();
            virusesList.enqueueWithPriority(tmp, true);

        } else if (virusesList.getBest()->getSubGroup() == 'M') {
            Mimivirus *tmp = new Mimivirus(*dynamic_cast<Mimivirus *>(virusesList.getBest()));
            tmp->updateName();
            virusesList.enqueueWithPriority(tmp, true);

        } else if (virusesList.getBest()->getSubGroup() == 'P' && !isAllP) {
            Papilloma *tmp = new Papilloma(*dynamic_cast<Papilloma *>(virusesList.getBest()));
            tmp->updateName();
            virusesList.enqueueWithPriority(tmp, true);

        } else {
            return;
        }
    }