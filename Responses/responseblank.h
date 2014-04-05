#ifndef RESPONSEBLANK_H
#define RESPONSEBLANK_H
#include "response.h"
#include "badresponse.h"
#include <memory>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <sstream>


class ResponseBlank : public Response
{
public:
    ResponseBlank();
    virtual std::shared_ptr<std::string> getHeaderText() throw(BadResponse);
    virtual std::shared_ptr<std::string> getContentText();

    std::string getHttpVersion() const;
    void setHttpVersion(const std::string &value);

    std::string getServer() const;
    void setServer(const std::string &value);

    std::string getContentLength() const;

    std::string getContentType() const;
    void setContentType(const std::string &value);

    std::string getConnection() const;
    void setConnection(const std::string &value);

    std::string getDate() const;

    std::shared_ptr<std::string> getContent() const;
    void setContent(const std::shared_ptr<std::string> &value);

    std::string getResponseCode() const;
    void setResponseCode(const std::string &value);

private:
    std::string responseCode;
    std::string httpVersion;
    std::string server;
//    std::string contentLength;
    std::string contentType;
    std::string connection;
    std::string date;
    std::shared_ptr<std::string> content;

    std::string getCurrentDate() const;
};

#endif // RESPONSEBLANK_H
