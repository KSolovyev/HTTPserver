#include "parsedrequest_impl.h"



ParsedRequest_impl::ParsedRequest_impl(std::shared_ptr<Request> request):valid(false),errorCode(Settings::errors::NO_ERROR), request(request)
{
    parse();
}

void ParsedRequest_impl::parse() throw(WrongRequestFormat)
{
   // std::string str = "GET /stat.html HTTP/1.1\nHOST: localhost";
    std::shared_ptr<std::string> query =request->getRequestText();
    std::string firstLine = query->substr(0,query->find("\n"));

    boost::smatch splited;
    boost::regex re("([^ ]*) ([^ ]*) HTTP/(1.[10])");

    if(!boost::regex_search (firstLine,splited,re))
    {
        valid = false;
        errorCode = Settings::errors::WRONG_REQUEST_FORMAT;
        return;
    }

    method = splited[1];
    url = splited[2];
    http_version = splited[3];

    std::string body = query->substr(query->find("\n")+1);
    re.assign("(.*): (.+?)$");

    while (boost::regex_search (body,splited,re)) {
        requestFields.insert({splited[1],splited[2]});
        body = splited.suffix().str();
    }

    validate();

}

void ParsedRequest_impl::validate() throw (BadMethod, ForbiddenSimbols)
{
    {
        boost::regex re("%[0-9a-fA-F]{2}");
        if (boost::regex_search (url,re))
        {
            valid = false;
            throw ForbiddenSimbols();
        }
    }


    if(Settings::ALLOWED_METHODS.find(method) == Settings::ALLOWED_METHODS.end())
    {
        valid = false;
        throw BadMethod();
    }
    valid = true;
}


std::string ParsedRequest_impl::getField(std::string key)
{

    auto keyValue = requestFields.find(key);
    if (keyValue != requestFields.end())
    {
        return (*keyValue).second;
    }
    return "";
}


std::string ParsedRequest_impl::getMethod()
{
        return method;
}


std::string ParsedRequest_impl::getUrl()
{
    return url;
}

std::string ParsedRequest_impl::getHttpVersion()
{
    return http_version;
}

std::shared_ptr<Request> ParsedRequest_impl::getRequest()
{
    return request;
}
