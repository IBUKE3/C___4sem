#include <iostream>
#include <string>

using std::cout;

class Logger {
    Logger();
    ~Logger();
    Logger& operator=(const Logger &) = delete;
    Logger(const Logger &) = delete;
public:
    Logger& log(int);
    Logger& log(const char*);
    Logger& log(char);
    static Logger& instance();
};

Logger::Logger() {
    cout << "Logger is created\n";
}

Logger::~Logger() {
    cout << "Logger is destroyed\n";
}

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

Logger& Logger::log(int i) {
    cout << i;
    return instance();
}

Logger& Logger::log(const char* s) {
    cout << s;
    return instance();
}

Logger& Logger::log(char c) {
    cout << c;
    return instance();
}

class IntCharPair {
    int n;
    char c;
    public:
    IntCharPair(int, char);
    friend Logger& log(Logger& l, const IntCharPair& p);
};

IntCharPair::IntCharPair(int i, char ch) : n{i}, c{ch} {}

Logger& log(Logger& l, const IntCharPair& p) {
    Logger::instance().log('(').log(p.n).log(',').log(' ').log(p.c).log(')');
    return Logger::instance();
}






