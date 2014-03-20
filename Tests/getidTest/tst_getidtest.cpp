#include <QString>
#include <QtTest>
#include "../../getid.h"

class GetidTest : public QObject
{
    Q_OBJECT

public:
    GetidTest();

private Q_SLOTS:
    void testCase1_data();
    void testCase1();
};

GetidTest::GetidTest()
{
}

void GetidTest::testCase1_data()
{
    QTest::addColumn<int*>("address");
    QTest::addColumn<size_t>("expected");

    QTest::newRow("case new1")<<(new int)<<0;
    QTest::newRow("case new2")<<(new int)<<1;
    int *a = new int;
    QTest::newRow("case old1")<<a<<2;
    QTest::newRow("case old2")<<a<<2;
    QTest::newRow("case old3")<<a<<2;

}

void GetidTest::testCase1()
{
    getId<int> intIndex;
    QFETCH(int*,address);
    QFETCH(size_t,expected);

    size_t actual = intIndex(address);

    QCOMPARE(actual,expected);

}

QTEST_APPLESS_MAIN(GetidTest)

#include "tst_getidtest.moc"
