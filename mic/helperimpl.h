/*  This file is part of the Vc library. {{{
Copyright © 2010-2014 Matthias Kretz <kretz@kde.org>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

#ifndef VC_MIC_DEINTERLEAVE_H
#define VC_MIC_DEINTERLEAVE_H

#include "macros.h"

namespace Vc_VERSIONED_NAMESPACE
{
namespace Internal
{

template<> struct HelperImpl<Vc::MICImpl>
{
    typedef MIC::Vector<float> float_v;
    typedef MIC::Vector<double> double_v;
    typedef MIC::Vector<int> int_v;
    typedef MIC::Vector<unsigned int> uint_v;

    template<typename V, typename M, typename A> static void deinterleave(V &a, V &b, const M *m, A);
//  template<typename A> static void deinterleave(float_v &, float_v &, const float *, A);
//  template<typename A> static void deinterleave(float_v &, float_v &, const short *, A);
//  template<typename A> static void deinterleave(float_v &, float_v &, const unsigned short *, A);
//
//  template<typename A> static void deinterleave(double_v &, double_v &, const double *, A);
//
//  template<typename A> static void deinterleave(int_v &, int_v &, const int *, A);
//  template<typename A> static void deinterleave(int_v &, int_v &, const short *, A);
//
//  template<typename A> static void deinterleave(uint_v &, uint_v &, const unsigned int *, A);
//  template<typename A> static void deinterleave(uint_v &, uint_v &, const unsigned short *, A);

    static Vc_ALWAYS_INLINE_L void prefetchForOneRead(const void *addr) Vc_ALWAYS_INLINE_R;
    static Vc_ALWAYS_INLINE_L void prefetchForModify(const void *addr) Vc_ALWAYS_INLINE_R;
    static Vc_ALWAYS_INLINE_L void prefetchClose(const void *addr) Vc_ALWAYS_INLINE_R;
    static Vc_ALWAYS_INLINE_L void prefetchMid(const void *addr) Vc_ALWAYS_INLINE_R;
    static Vc_ALWAYS_INLINE_L void prefetchFar(const void *addr) Vc_ALWAYS_INLINE_R;

    template<Vc::MallocAlignment A>
    static Vc_ALWAYS_INLINE_L void *malloc(size_t n) Vc_ALWAYS_INLINE_R;
    static Vc_ALWAYS_INLINE_L void free(void *p) Vc_ALWAYS_INLINE_R;
};

}  // namespace Internal
}  // namespace Vc

#include "deinterleave.tcc"
#include "prefetches.tcc"
#include "helperimpl.tcc"
#include "undomacros.h"

#endif // VC_MIC_DEINTERLEAVE_H