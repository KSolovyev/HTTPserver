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

    boost::regex hasQueryString(".+[?].*");
    std::string filePart;
    boost::smatch match;
    //removing query string
    if(boost::regex_search(parsedRequest->getDecodedUrl(),match,hasQueryString))
    {
        boost::regex filePart_re("(^.+?)[?].*$");

        boost::regex_search(parsedRequest->getDecodedUrl(),match,filePart_re);
        filePart = match[1];
    }
    else
        filePart = parsedRequest->getDecodedUrl();
    if(filePart[0]!='/')
        filePart = "/"+filePart;

    //Removing /../ sequences
    std::string filePath = Settings::ROOT + filePart;
    boost::regex escape_re("\/?[^\/^(..)]*/../");

    while(boost::regex_search(filePath,match,escape_re))
        filePath=boost::regex_replace(filePath,escape_re,"/");

    boost::filesystem::path path(filePath);

    if(parsedRequest->getMethod()=="GET")
    {

        if(filePath.find(Settings::ROOT)==std::string::npos)
        {
            std::shared_ptr<ResponseBlank> response = getResponseBuilder()->getResponse403();
            std::shared_ptr<std::string> content(new std::string("403. Distanation is Forbidden: " + parsedRequest->getUrl()));
            response->setContentType("text/html");
            response->setContent(content);
            sendResponse(parsedRequest, response);
        }
        else if(boost::filesystem::is_directory(path))
        {
            auto last = filePath.end();
            last--;
            char s = *last;
            if(s!='/')
                path+= boost::filesystem::path("/index.html");
            else
                path+= boost::filesystem::path("index.html");

            if(!boost::filesystem::exists(path))
            {
                std::shared_ptr<ResponseBlank> response = getResponseBuilder()->getResponse403();
                std::shared_ptr<std::string> content(new std::string("403. Forbidden: "+ parsedRequest->getUrl()));
                response->setContentType("text/html");
                response->setContent(content);
                sendResponse(parsedRequest, response);
            }
            sendFile(path, parsedRequest);
        }
        else
        {
            sendFile(path, parsedRequest);
        }
    }
    else
    {
        std::shared_ptr<ResponseBlank> response = (getResponseBuilder())->getResponse405();
        std::shared_ptr<std::string> content(new std::string("405. Method not allowed: "+ parsedRequest->getUrl()));
        response->setContent(content);
        response->setContentType("text/html");
        sendResponse(parsedRequest, response);


    }


}

void DefaultRule::sendResponse(std::shared_ptr<ParsedRequest> parsedRequest, std::shared_ptr<Response> response)
{
    bufferevent_lock(parsedRequest->getRequest()->getOutputBuffer());
    bufferevent_write(parsedRequest->getRequest()->getOutputBuffer(),response->getHeaderText()->c_str(),response->getHeaderText()->length());
    bufferevent_write(parsedRequest->getRequest()->getOutputBuffer(),response->getContentText()->c_str(),response->getContentText()->length());
    bufferevent_write(parsedRequest->getRequest()->getOutputBuffer(),"\r\n\r\n",4);
    bufferevent_enable( parsedRequest->getRequest()->getOutputBuffer(), (EV_WRITE ) );
    bufferevent_flush(parsedRequest->getRequest()->getOutputBuffer(),EV_WRITE,BEV_FINISHED);
    bufferevent_unlock(parsedRequest->getRequest()->getOutputBuffer());
}

void DefaultRule::sendFile(boost::filesystem::path path, std::shared_ptr<ParsedRequest> parsedRequest)
{

    if(boost::filesystem::exists(path))
    {
        if(boost::filesystem::is_regular_file(path))
        {
            if(boost::filesystem::file_size(path)<Settings::MAX_FILE_SIZE)
            {
                std::ifstream is(path.string(), std::ifstream::binary);
                if(is)
                {
                    std::shared_ptr<ResponseBlank> response = (getResponseBuilder())->getResponse200();

                    is.seekg(0, is.end);
                    int length = is.tellg();
                    is.seekg(0, is.beg);

                    std::shared_ptr<std::string> content(new std::string);
                    content->reserve(length);
                    char* buffer = new char[length];
                    memset(buffer,0,length);
                    is.read (buffer, length);
                    *content = std::move(std::string(buffer,length));

                    response->setContent(content);

                    boost::regex ext_re("(\.[a-z]+)([?].*)?$");
                    boost::smatch matcher;
                    boost::regex_search(path.string(),matcher,ext_re);

                    std::string ext = matcher[0].str();
                    if(ext == ".html")
                        response->setContentType("text/html");
                    else if(ext == ".css")
                        response->setContentType("text/css");
                    else if(ext == ".js")
                        response->setContentType("text/javascript");
                    else if(ext == ".png")
                        response->setContentType("image/png");
                    else if(ext == ".gif")
                        response->setContentType("image/gif");
                    else if(ext == ".swf")
                        response->setContentType("application/x-shockwave-flash");
                    else if(ext == ".jpeg" || ext==".jpg")
                        response->setContentType("image/jpeg");
                    else
                        response->setContentType("text/plain");

                    sendResponse(parsedRequest, response);
                }

            }
            else
            {
                std::shared_ptr<ResponseBlank> response = (getResponseBuilder())->getResponse405();
                std::shared_ptr<std::string> content(new std::string("405. Method not allowed: "+ parsedRequest->getUrl()));
                response->setContent(content);
                response->setContentType("text/html");
                sendResponse(parsedRequest, response);
            }
        }
        else
        {
            std::shared_ptr<ResponseBlank> response = (getResponseBuilder())->getResponse405();
            std::shared_ptr<std::string> content(new std::string("405. Method not allowed: "+ parsedRequest->getUrl()));
            response->setContent(content);
            response->setContentType("text/html");
            sendResponse(parsedRequest, response);
        }
    }
    else
    {
        std::shared_ptr<ResponseBlank> response = getResponseBuilder()->getResponse404();
        std::shared_ptr<std::string> content(new std::string("404. Page not found: "+ parsedRequest->getUrl()));
        response->setContentType("text/html");
        response->setContent(content);
        sendResponse(parsedRequest, response);
    }
}
