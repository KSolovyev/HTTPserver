#ifndef SETTINGS_H
#define SETTINGS_H
#include <set>
#include <string>

class Settings
{
public:
    class errors
    {
    public:
        static const int NO_ERROR = 0;
        static const int WRONG_REQUEST_FORMAT = 1;
        static const int BAD_METHOD = 2;
        static const int FORBIDDEN_SIMBOLS = 3;
        static const int REQUEST_HAS_NO_BUFFER = 4;
        static const int BAD_RESPONSE = 5;
    };
    Settings();

    static std::set<std::string> ALLOWED_METHODS;
    //static set<std::string> ALLOWED_REQUEST_HEADERS = {};
    static std::string ROOT;
    static std::string SERVER_NAME;

};

#endif // SETTINGS_H
