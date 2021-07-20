#include <example.h>
#include <hello.h>

namespace Example {

    namespace {

        int getInt() {
            return 10;
        }

    }

    string getHello() {
        const string msg = getMessager();
        const int result = getInt();
        return "hello";
    }

}

