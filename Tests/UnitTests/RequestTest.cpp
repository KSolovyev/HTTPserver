
#include"../../allForLibevent.h"
#include"../../request.cpp"
#include <unittest++/UnitTest++.h>
#include<string>

namespace requestTest
{
    struct Setings{
        Setings(){
            firstPiece = "GET /index.html";
            secondPiece = " HTTP/1.1\n\n";
            overallPiece=firstPiece + secondPiece;
            request = new Request;

        }
        ~Setings()
        {

        }
        std::string firstPiece;
        std::string secondPiece;
        std::string overallPiece;
        Request* request;

    };
}

using namespace requestTest;

TEST_FIXTURE(Setings,requestTest)
{
    request->writeBack(firstPiece);
    CHECK(!request->isReady());
    CHECK_EQUAL(firstPiece,*(request->getRequestText()));
    request->writeBack(secondPiece);
    CHECK(request->isReady());
    CHECK_EQUAL(overallPiece,*(request->getRequestText()));
}

