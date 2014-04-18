#include "responseblank.h"

ResponseBlank::ResponseBlank()
{

}

std::shared_ptr<std::string> ResponseBlank::getHeaderText() throw(BadResponse)
{
    if(responseCode.empty())
    {
        throw BadResponse("response code is empty");
    }
    if(contentType.empty())
    {
        throw BadResponse("content-type is empty");
    }
    std::shared_ptr<std::string> responseText(new std::string);

    *responseText = (httpVersion==""?"HTTP/1.1 ":"HTTP/"+httpVersion+" ")+
            (responseCode)+"\n"+
            (server == ""?"Server: " + Settings::SERVER_NAME +"\n":"Server: " + server +"\n")+
            "Date: " + getCurrentDate()+"\n"+
            "Content-Type: " + contentType + "\n"+
            "Content-Length: " + std::to_string(content->length())+"\n"+
            (connection==""?"Connection: close":"Connection: " + connection)+"\r"+ "\n"+
            "\r" + "\n";

    return responseText;


}

std::shared_ptr<std::string> ResponseBlank::getContentText()
{
    return content;
}
std::string ResponseBlank::getHttpVersion() const
{
    return httpVersion;
}

void ResponseBlank::setHttpVersion(const std::string &value)
{
    httpVersion = value;
}
std::string ResponseBlank::getServer() const
{
    return server;
}

void ResponseBlank::setServer(const std::string &value)
{
    server = value;
}
std::string ResponseBlank::getContentLength() const
{
    return std::to_string(content->length());
}


std::string ResponseBlank::getContentType() const
{
    return contentType;
}

void ResponseBlank::setContentType(const std::string &value)
{
    contentType = value;
}
std::string ResponseBlank::getConnection() const
{
    return connection;
}

void ResponseBlank::setConnection(const std::string &value)
{
    connection = value;
}
std::string ResponseBlank::getDate() const
{
    return getCurrentDate();
}


std::shared_ptr<std::string> ResponseBlank::getContent() const
{
    return content;
}

void ResponseBlank::setContent(const std::shared_ptr<std::string> &value)
{
    content = value;
}
std::string ResponseBlank::getResponseCode() const
{
    return responseCode;
}

void ResponseBlank::setResponseCode(const std::string &value)
{
    responseCode = value;
}


std::string ResponseBlank::getCurrentDate()const
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime t = second_clock::universal_time();

    std::stringstream ss;
    time_facet* facet2 = new time_facet("%a, %d %b %Y %H:%M:%S GMT");
    ss.imbue(std::locale(ss.getloc(),facet2));
    ss<<t;

    return ss.str();
}







