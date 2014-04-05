#include "defaultrule.h"

DefaultRule::DefaultRule()
{
}

DefaultRule::~DefaultRule()
{
}

bool DefaultRule::isMatching(std::string url)
{
    return true;
}

bool DefaultRule::isFinal()
{
    return true;
}

void DefaultRule::operateRequest(std::shared_ptr<ParsedRequest> parsedRequest)
{
    std::string filePath = Settings::ROOT + parsedRequest->getUrl();
    boost::filesystem::path path(filePath);



    if(path.compare(Settings::ROOT) == -1)
    {

    }


}
