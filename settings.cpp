#include "settings.h"

std::set<std::string> Settings::ALLOWED_METHODS = {"GET","HEAD","POST"};
std::string Settings::ROOT="/home/constantine/HTTProot";
std::string Settings::SERVER_NAME = "HighLoadServer.0.1";
size_t Settings::MAX_FILE_SIZE = 8388608;

Settings::Settings()
{


}
