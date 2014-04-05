#include "responseblanktest.h"

class ResponseBlankTest: public testing::Test
{
public:
    void SetUp()
    {
        responseBlank = responseBuilder.getResponseBlank();
    }

    void TearDown()
    {

    }
    std::shared_ptr<ResponseBlank> responseBlank;
    ResponseBuilder responseBuilder;
};


TEST_F(ResponseBlankTest, CreationTest)
{
    ASSERT_TRUE((bool)responseBlank);
}

TEST_F(ResponseBlankTest, FunctionalTest)
{
    responseBlank->setConnection("close");
    responseBlank->setContentType("text/html");
    responseBlank->setHttpVersion("1.1");
    responseBlank->setServer("HighLoadServer.0.1");
    responseBlank->setResponseCode("200 OK");
    responseBlank->setContent(std::shared_ptr<std::string>(new std::string("blablabla")));

    std::shared_ptr<std::string> header = responseBlank->getHeaderText();

   // std::cout<<*header;


    boost::smatch matcher;
    boost::regex re("HTTP/(1.[10]) ([0-5]{3}) [\w ]*\nServer: ([\w/. \(\)]*)\nDate: ([\w, :]*)\nContent-Type: ([\w/]*)\nContent-Length: ([\d]*)\nConnection: ([\w]*)\n\n");

    boost::regex rehead("^HTTP/(1.[10]) ([0-5]{3}) [a-zA-Z ]*$");
    //boost::regex reserver("^Server: ([\w/\. \(\)]*)$");
    boost::regex reserver("^Server: ([a-zA-Z0-9 \.\(\)]+?)$");
    boost::regex redate("^Date: ([a-zA-Z0-9 \:\,]+?)$");
    boost::regex recontenttype("^Content-Type: ([a-z\/]*?)$");
    boost::regex recontentlength("^Content-Length: ([0-9]*?)$");
    boost::regex reconnection("^Connection: ([a-zA-z \-]*?)$");
    boost::regex ending("^$");

    ASSERT_TRUE(boost::regex_search (*header,matcher,rehead));


    ASSERT_EQ(matcher[1].str(),"1.1");
    ASSERT_EQ(matcher[2].str(),"200");

    ASSERT_TRUE(boost::regex_search (*header,matcher,reserver));

    ASSERT_EQ(matcher[1].str(),"HighLoadServer.0.1");

    ASSERT_TRUE(boost::regex_search (*header,matcher,redate));

    ASSERT_TRUE(boost::regex_search (*header,matcher,recontenttype));

    ASSERT_EQ(matcher[1].str(),"text/html");

    ASSERT_TRUE(boost::regex_search (*header,matcher,recontentlength));

    ASSERT_EQ(matcher[1].str(),"9");

    ASSERT_TRUE(boost::regex_search (*header,matcher,reconnection));

    ASSERT_EQ(matcher[1].str(),"close");

    ASSERT_TRUE(boost::regex_search (*header,matcher,ending));


}
