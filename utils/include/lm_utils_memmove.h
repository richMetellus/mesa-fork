// Copyright (c) 2021-2022 Microchip Technology Inc. and its subsidiaries.
// SPDX-License-Identifier: MIT

#ifndef LM_UTILS_MEMMOVE_H
#define LM_UTILS_MEMMOVE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Typically these functions are used wihtout a need for a return type.
void lmu_memmove(void *dst, const void *src, size_t n);

#if defined(__arm__)
#pragma coverity compliance deviate                                            \
    "MISRA C-2023 Rule 8.6"                                                    \
    "This is implemented in ASM which is not being picked up by coverity"
void *lmu_memmove_arm(void *dst, const void *src, size_t n);
#elif defined(__aarch64__)
#pragma coverity compliance deviate                                            \
    "MISRA C-2023 Rule 8.6"                                                    \
    "This is implemented in ASM which is not being picked up by coverity"
void *lmu_memmove_aarch64(void *dst, const void *src, size_t n);
#endif

void *lmu_memmove_(void *dst, const void *src, size_t n);
void *lmu_memmove_no_asm(void *dst, const void *src, size_t n);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
