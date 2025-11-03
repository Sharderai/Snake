#ifndef GLOBAL_GAME_VALUES_H
#define GLOBAL_GAME_VALUES_H

static class GlobalGameValues {
    public:
        static GlobalGameValues& getInstance();

        void setXLim(int);
        int getXLim();
        void setYLim(int);
        int getYLim();

        void destroy();

    private:
        GlobalGameValues();
        ~GlobalGameValues() = default;

        inline static GlobalGameValues* instance = nullptr;
        int limitX;
        int limitY;
};

GlobalGameValues::GlobalGameValues() {
    limitX = 0;
    limitY = 0;
}


GlobalGameValues& GlobalGameValues::getInstance() {
    if (!instance) {
        instance = new GlobalGameValues();
    }

    return *instance;
}


void GlobalGameValues::setXLim(int x) {
    limitX = x;
}


int GlobalGameValues::getXLim() {
    return limitX;
}


void GlobalGameValues::setYLim(int y) {
    limitY = y;
}


int GlobalGameValues::getYLim() {
    return limitY;
}


void GlobalGameValues::destroy() {
    delete instance;
    instance = nullptr;
}

#endif