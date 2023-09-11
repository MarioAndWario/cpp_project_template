#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE hello_world

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hello_world) {
  BOOST_TEST("HELLO_WORLD" == "HELLO_WORLD");
}