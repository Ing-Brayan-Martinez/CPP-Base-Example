#include "../include/example.h"

namespace Example {

    namespace {

        int getInt() {
            return 10;
        }

    }

    string getHello() {
        const int result = getInt();
        return "hello";
    }

}

