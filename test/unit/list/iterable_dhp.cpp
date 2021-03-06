/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2016

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "test_iterable_list_hp.h"
#include <cds/container/iterable_list_dhp.h>

namespace {
    namespace cc = cds::container;
    typedef cds::gc::DHP gc_type;

    class IterableList_DHP : public cds_test::iterable_list_hp
    {
    protected:
        void SetUp()
        {
            typedef cc::IterableList< gc_type, item > list_type;

            cds::gc::dhp::GarbageCollector::Construct( 16, list_type::c_nHazardPtrCount );
            cds::threading::Manager::attachThread();
        }

        void TearDown()
        {
            cds::threading::Manager::detachThread();
            cds::gc::dhp::GarbageCollector::Destruct();
        }
    };

    TEST_F( IterableList_DHP, less_ordered )
    {
        typedef cc::IterableList< gc_type, item,
            typename cc::iterable_list::make_traits<
                cds::opt::less< lt<item> >
                ,cds::opt::item_counter< cds::atomicity::item_counter >
            >::type
        > list_type;

        list_type l;
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

    TEST_F( IterableList_DHP, compare_ordered )
    {
        typedef cc::IterableList< gc_type, item,
            typename cc::iterable_list::make_traits<
                cds::opt::compare< cmp<item> >
                , cds::opt::item_counter< cds::atomicity::item_counter >
            >::type
        > list_type;

        list_type l;
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

    TEST_F( IterableList_DHP, mix_ordered )
    {
        typedef cc::IterableList< gc_type, item,
            typename cc::iterable_list::make_traits<
                cds::opt::compare< cmp<item> >
                ,cds::opt::less< lt<item> >
                , cds::opt::item_counter< cds::atomicity::item_counter >
            >::type
        > list_type;

        list_type l;
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

    TEST_F( IterableList_DHP, backoff )
    {
        struct traits : public cc::iterable_list::traits
        {
            typedef lt<item> less;
            typedef cds::atomicity::item_counter item_counter;
            typedef cds::backoff::empty back_off;
        };
        typedef cc::IterableList<gc_type, item, traits > list_type;

        list_type l;
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

    TEST_F( IterableList_DHP, seq_cst )
    {
        struct traits : public cc::iterable_list::traits
        {
            typedef lt<item> less;
            typedef cds::atomicity::item_counter item_counter;
            typedef cds::opt::v::sequential_consistent memory_model;
        };
        typedef cc::IterableList<gc_type, item, traits > list_type;

        list_type l;
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

    TEST_F( IterableList_DHP, stat )
    {
        struct traits: public cc::iterable_list::traits
        {
            typedef lt<item> less;
            typedef cds::atomicity::item_counter item_counter;
            typedef cds::container::iterable_list::stat<> stat;

        };
        typedef cc::IterableList<gc_type, item, traits > list_type;

        list_type l;
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

    TEST_F( IterableList_DHP, wrapped_stat )
    {
        struct traits: public cc::iterable_list::traits
        {
            typedef lt<item> less;
            typedef cds::atomicity::item_counter item_counter;
            typedef cds::container::iterable_list::wrapped_stat<> stat;

        };
        typedef cc::IterableList<gc_type, item, traits > list_type;

        cds::container::iterable_list::stat<> st;
        list_type l( st );
        test_common( l );
        test_ordered_iterator( l );
        test_hp( l );
    }

} // namespace
