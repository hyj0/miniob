//
// Created by projector on 9/20/22.
//
#include <string.h>

#include "gtest/gtest.h"
#include "common/lang/bitmap.h"
#include <sstream>
#include <sql/parser/parse.h>

using namespace common;

TEST(test_sql_insert, test_sql_insert)
{
    {
        const char *st = "INSERT INTO insert_table VALUES (2);";
        Query sqln = Query();
        memset(&sqln, 0, sizeof(sqln));
        RC rc = parse(st, &sqln);
        ASSERT_EQ(rc, RC::SUCCESS);
    }
    {
        const char *st = "INSERT INTO insert_table VALUES (2,'N2',1,1);";
        Query sqln = Query();
        memset(&sqln, 0, sizeof(sqln));
        RC rc = parse(st, &sqln);
        ASSERT_EQ(rc, RC::SUCCESS);
    }
    {
        const char *st = "INSERT INTO insert_table VALUES (2,'N2',1,1),(3,'N3',2,1);";
        Query sqln = Query();
        memset(&sqln, 0, sizeof(sqln));
        RC rc = parse(st, &sqln);
        ASSERT_EQ(rc, RC::SUCCESS);
    }
    {
        const char *st = "INSERT INTO insert_table VALUES (2,'N2',1,1),(3,'N3',2,1, 3);";
        Query sqln = Query();
        memset(&sqln, 0, sizeof(sqln));
        RC rc = parse(st, &sqln);
        ASSERT_EQ(rc, RC::SQL_SYNTAX);
    }

    printf("ok\n");
    return;
}

int main(int argc, char **argv)
{
    // ����gtest����������в���
    testing::InitGoogleTest(&argc, argv);

    // ����RUN_ALL_TESTS()�������в�������
    // main��������RUN_ALL_TESTS()�����н��
    return RUN_ALL_TESTS();
}