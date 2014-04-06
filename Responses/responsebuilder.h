#ifndef RESPONSEBUILDER_H
#define RESPONSEBUILDER_H
#include <memory>
#include <response.h>
#include <responseblank.h>

class ResponseBuilder
{
public:
    ResponseBuilder();
    std::shared_ptr<ResponseBlank> getResponse404();
    std::shared_ptr<ResponseBlank> getResponse200();
    std::shared_ptr<ResponseBlank> getResponse405();
    std::shared_ptr<ResponseBlank> getResponseBlank();
    std::shared_ptr<ResponseBlank> getResponse403() const;

private:
    std::shared_ptr<ResponseBlank> response200;
    std::shared_ptr<ResponseBlank> response404;
    std::shared_ptr<ResponseBlank> response403;
    std::shared_ptr<ResponseBlank> response405;
    std::shared_ptr<ResponseBlank> response400;
};

#endif // RESPONSEBUILDER_H
