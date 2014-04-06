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
        std::shared_ptr<ResponseBlank> response = getResponseBuilder()->getResponse403();
        std::shared_ptr<std::string> content(new std::string("403. Distanation is Forbidden: " + parsedRequest->getUrl()));
        response->setContentType("text/html");
        response->setContent(content);
        sendResponse(parsedRequest, response);
    }
    else
    {
        if(boost::filesystem::exists(path))
        {
            if(boost::filesystem::is_regular_file(path))
            {
                if(boost::filesystem::file_size(path)<Settings::MAX_FILE_SIZE)
                {
                    std::ifstream is("/home/constantine/HTTProot/test.txt", std::ifstream::binary);
                    if(is)
                    {
                        std::shared_ptr<ResponseBlank> response = (getResponseBuilder())->getResponse200();

                        is.seekg(0, is.end);
                        int length = is.tellg();
                        is.seekg(0, is.beg);

                        std::shared_ptr<std::string> content(new std::string);
                        content->reserve(length);
                        char* buffer = new char[length];
                        is.read (buffer, length);
                        *content = std::move(std::string(buffer));

                        response->setContent(content);

                        boost::regex ext_re(".?*/?(.*)$");
                        boost::smatch matcher;
                        boost::regex_search(parsedRequest->getUrl(),matcher,ext_re);

                        std::string ext = matcher[1].str();
                        if(ext == ".html")
                            response->setContentType("text/html");
                        else if(ext == ".css")
                            response->setContentType("text/css");
                        else if(ext == ".js")
                            response->setContentType("text/javascript");
                        else if(ext == ".png")
                            response->setContentType("text/png");
                        else if(ext == ".gif")
                            response->setContentType("text/gif");
                        else if(ext == ".swf")
                            response->setContentType("application/x-shockwave-flash");
                        else if(ext == ".jpeg" || ext==".jpg")
                            response->setContentType("image/jpeg");
                        else
                            response->setContentType("text/plain");

                        sendResponse(parsedRequest, response);
                    }

                        //
                       // std::shared_ptr<std::string> content(new std::string);
                        //const char** str_buf =  &content->c_str();
                       // = buffer;
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


}

void DefaultRule::sendResponse(std::shared_ptr<ParsedRequest> parsedRequest, std::shared_ptr<Response> response)
{
    bufferevent_write(parsedRequest->getRequest()->getOutputBuffer(),response->getHeaderText()->c_str(),response->getHeaderText()->length());
    bufferevent_write(parsedRequest->getRequest()->getOutputBuffer(),response->getContentText()->c_str(),response->getContentText()->length());
}
