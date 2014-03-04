// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/range/adaptor/type_erased.hpp>
#include "type_erased_test.hpp"

#include <boost/test/unit_test.hpp>

#include <boost/range/value_type.hpp>
#include <boost/array.hpp>
#include <boost/cstdint.hpp>

#include <algorithm>
#include <list>
#include <deque>
#include <vector>

namespace boost_range_adaptor_type_erased_test
{
    namespace
    {

void test_type_erased()
{
    test_driver< std::list<int> >();
    test_driver< std::vector<int> >();

    test_driver< std::list<MockType> >();
    test_driver< std::vector<MockType> >();
}

void test_type_erased_random_access()
{
    test_type_erased_exercise_buffer_types< std::deque<int>, boost::random_access_traversal_tag >();
    test_type_erased_exercise_buffer_types< std::vector<int>, boost::random_access_traversal_tag >();

    test_type_erased_exercise_buffer_types< std::deque<MockType>, boost::random_access_traversal_tag >();
    test_type_erased_exercise_buffer_types< std::vector<MockType>, boost::random_access_traversal_tag >();
}

    } // anonymous namespace
} // namespace boost_range_adaptor_type_erased_test

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.type_erased" );

    test->add( BOOST_TEST_CASE( &boost_range_adaptor_type_erased_test::test_type_erased ) );
    test->add( BOOST_TEST_CASE( &boost_range_adaptor_type_erased_test::test_type_erased_random_access ) );

    return test;
}

