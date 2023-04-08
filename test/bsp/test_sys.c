#ifdef TEST

#include "unity.h"
#include "stdbool.h"

#include "sys.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sys_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement sys");
}

void test_sys_forceFailure(void)
{
    TEST_ASSERT_EQUAL(2,1);
}

#endif // TEST
