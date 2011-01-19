#ifndef LOG_H
#define LOG_H

#include <QString>
using namespace Qt;

namespace bacra{

     /////////////////////////////////////////////////////////
     // Class is only intended for debugging purposes. Purpose
     // is to provide common logging facilities because for
     // some reason log messages sent to std::cout don't show
     // up in my console so I have to use qDebug() instead
     //
    class Log{

        public:
        /////////////////////////////////////////////////////////
        // Function which writes given log message (however this
        // is kinda costly because we create new QString object
        // each time we want to print something.
        //
        static void debug(QString const debugText);

        static void debugByRef(QString const &debugText);

        private:
            Log();
            ~Log();
            Log& operator = (Log const &rhs);

    };

}

#endif // LOG_H
