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

#ifndef CDSUNIT_MAP_TYPE_ITERABLE_LIST_H
#define CDSUNIT_MAP_TYPE_ITERABLE_LIST_H

#include "map_type.h"

#include <cds/container/iterable_kvlist_hp.h>
#include <cds/container/iterable_kvlist_dhp.h>

#include <cds_test/stat_iterable_list_out.h>

namespace map {

    template <typename Key, typename Value>
    struct iterable_list_type
    {
        typedef typename map_type_base<Key, Value>::key_compare compare;
        typedef typename map_type_base<Key, Value>::key_less    less;

        struct traits_IterableList_cmp_stdAlloc :
            public cc::iterable_list::make_traits<
                co::compare< compare >
            >::type
        {};
        typedef cc::IterableKVList< cds::gc::HP,  Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_HP_cmp_stdAlloc;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_DHP_cmp_stdAlloc;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_RCU_GPI_cmp_stdAlloc;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_RCU_GPB_cmp_stdAlloc;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_RCU_GPT_cmp_stdAlloc;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_RCU_SHB_cmp_stdAlloc;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_cmp_stdAlloc > IterableList_RCU_SHT_cmp_stdAlloc;
//#endif

        struct traits_IterableList_cmp_stdAlloc_stat: public traits_IterableList_cmp_stdAlloc
        {
            typedef cc::iterable_list::stat<> stat;
        };
        typedef cc::IterableKVList< cds::gc::HP, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_HP_cmp_stdAlloc_stat;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_DHP_cmp_stdAlloc_stat;
        //        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_RCU_GPI_cmp_stdAlloc_stat;
        //        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_RCU_GPB_cmp_stdAlloc_stat;
        //        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_RCU_GPT_cmp_stdAlloc_stat;
        //#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        //        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_RCU_SHB_cmp_stdAlloc_stat;
        //        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_cmp_stdAlloc_stat > IterableList_RCU_SHT_cmp_stdAlloc_stat;
        //#endif

        struct traits_IterableList_cmp_stdAlloc_seqcst :
            public cc::iterable_list::make_traits<
                co::compare< compare >
                ,co::memory_model< co::v::sequential_consistent >
            >::type
        {};
        typedef cc::IterableKVList< cds::gc::HP,  Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_HP_cmp_stdAlloc_seqcst;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_DHP_cmp_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_RCU_GPI_cmp_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_RCU_GPB_cmp_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_RCU_GPT_cmp_stdAlloc_seqcst;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_RCU_SHB_cmp_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_cmp_stdAlloc_seqcst > IterableList_RCU_SHT_cmp_stdAlloc_seqcst;
//#endif

        struct traits_IterableList_cmp_michaelAlloc :
            public cc::iterable_list::make_traits<
                co::compare< compare >,
                co::allocator< memory::MichaelAllocator<int> >
            >::type
        {};
        typedef cc::IterableKVList< cds::gc::HP,  Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_HP_cmp_michaelAlloc;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_DHP_cmp_michaelAlloc;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_RCU_GPI_cmp_michaelAlloc;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_RCU_GPB_cmp_michaelAlloc;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_RCU_GPT_cmp_michaelAlloc;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_RCU_SHB_cmp_michaelAlloc;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_cmp_michaelAlloc > IterableList_RCU_SHT_cmp_michaelAlloc;
//#endif

        struct traits_IterableList_less_stdAlloc :
            public cc::iterable_list::make_traits<
                co::less< less >
            >::type
        {};
        typedef cc::IterableKVList< cds::gc::HP,  Key, Value, traits_IterableList_less_stdAlloc > IterableList_HP_less_stdAlloc;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_less_stdAlloc > IterableList_DHP_less_stdAlloc;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_less_stdAlloc > IterableList_RCU_GPI_less_stdAlloc;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_less_stdAlloc > IterableList_RCU_GPB_less_stdAlloc;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_less_stdAlloc > IterableList_RCU_GPT_less_stdAlloc;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_less_stdAlloc > IterableList_RCU_SHB_less_stdAlloc;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_less_stdAlloc > IterableList_RCU_SHT_less_stdAlloc;
//#endif

        struct traits_IterableList_less_stdAlloc_stat: public traits_IterableList_less_stdAlloc
        {
            typedef cc::iterable_list::stat<> stat;
        };
        typedef cc::IterableKVList< cds::gc::HP, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_HP_less_stdAlloc_stat;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_DHP_less_stdAlloc_stat;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_RCU_GPI_less_stdAlloc_stat;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_RCU_GPB_less_stdAlloc_stat;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_RCU_GPT_less_stdAlloc_stat;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_RCU_SHB_less_stdAlloc_stat;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_less_stdAlloc_stat > IterableList_RCU_SHT_less_stdAlloc_stat;
//#endif

        struct traits_IterableList_less_stdAlloc_seqcst :
            public cc::iterable_list::make_traits<
                co::less< less >
                ,co::memory_model< co::v::sequential_consistent >
            >::type
        {};
        typedef cc::IterableKVList< cds::gc::HP,  Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_HP_less_stdAlloc_seqcst;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_DHP_less_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_RCU_GPI_less_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_RCU_GPB_less_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_RCU_GPT_less_stdAlloc_seqcst;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_RCU_SHB_less_stdAlloc_seqcst;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_less_stdAlloc_seqcst > IterableList_RCU_SHT_less_stdAlloc_seqcst;
//#endif

        struct traits_IterableList_less_michaelAlloc :
            public cc::iterable_list::make_traits<
                co::less< less >,
                co::allocator< memory::MichaelAllocator<int> >
            >::type
        {};
        typedef cc::IterableKVList< cds::gc::HP,  Key, Value, traits_IterableList_less_michaelAlloc > IterableList_HP_less_michaelAlloc;
        typedef cc::IterableKVList< cds::gc::DHP, Key, Value, traits_IterableList_less_michaelAlloc > IterableList_DHP_less_michaelAlloc;
//        typedef cc::IterableKVList< rcu_gpi, Key, Value, traits_IterableList_less_michaelAlloc > IterableList_RCU_GPI_less_michaelAlloc;
//        typedef cc::IterableKVList< rcu_gpb, Key, Value, traits_IterableList_less_michaelAlloc > IterableList_RCU_GPB_less_michaelAlloc;
//        typedef cc::IterableKVList< rcu_gpt, Key, Value, traits_IterableList_less_michaelAlloc > IterableList_RCU_GPT_less_michaelAlloc;
//#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
//        typedef cc::IterableKVList< rcu_shb, Key, Value, traits_IterableList_less_michaelAlloc > IterableList_RCU_SHB_less_michaelAlloc;
//        typedef cc::IterableKVList< rcu_sht, Key, Value, traits_IterableList_less_michaelAlloc > IterableList_RCU_SHT_less_michaelAlloc;
//#endif
    };

} // namespace map

#endif // ifndef CDSUNIT_MAP_TYPE_ITERABLE_LIST_H
