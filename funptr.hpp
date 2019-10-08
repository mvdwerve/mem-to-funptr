/**
 *  funptr.hpp
 *
 *  @author Michael van der Werve
 *  @copyright 2019
 *  @license MIT
 */

/**
 *  Header guard
 */
#pragma once

template <class C>
struct funptr
{
    // c++11, bind the wrapped function in template argument
    template <void (C::*fn)()>
    static void ptr(void *data)
    {
        // call fn
        return (static_cast<C*>(data)->*fn)();
    }

    // @todo return types
    // @todo more arguments
    // @todo void * argument in random place

    // c++17
    //template <auto fn>
    //static void ptr(void *data)
    //{
    //    // call fn
    //    (static_cast<C*>(data)->*fn)();
    //}
};