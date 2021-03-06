/*
Copyright (c) 2015, Cisco Systems
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef COMMON_SIMDKERNELS_H
#define COMMON_SIMDKERNELS_H

#include <stdint.h>
void block_avg_simd(uint8_t *p,uint8_t *r0, uint8_t *r1, int sp, int s0, int s1, int width, int height);
int sad_calc_simd_unaligned(uint8_t *a, uint8_t *b, int astride, int bstride, int width, int height);
void get_inter_prediction_luma_simd(int width, int height, int xoff, int yoff, unsigned char *restrict qp, int qstride, const unsigned char *restrict ip, int istride, int bipred);
void get_inter_prediction_chroma_simd(int width, int height, int xoff, int yoff, unsigned char *restrict qp, int qstride, const unsigned char *restrict ip, int istride);
void transform_simd(const int16_t *block, int16_t *coeff, int size, int fast);
void inverse_transform_simd(const int16_t *coeff, int16_t *block, int size);
void clpf_block4(const uint8_t *src, uint8_t *dst, int sstride, int dstride, int x0, int y0, int width, int height);
void clpf_block8(const uint8_t *src, uint8_t *dst, int sstride, int dstride, int x0, int y0, int width, int height);
SIMD_INLINE void clpf_block_simd(const uint8_t *src, uint8_t *dst, int sstride, int dstride, int x0, int y0, int size, int width, int height) {
  (size == 4 ? clpf_block4 : clpf_block8)(src, dst, sstride, dstride, x0, y0, width, height);
}

#endif
