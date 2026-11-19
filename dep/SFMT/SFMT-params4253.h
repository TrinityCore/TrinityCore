#pragma once
#ifndef SFMT_PARAMS4253_H
#define SFMT_PARAMS4253_H

#define SFMT_POS1	17
#define SFMT_SL1	20
#define SFMT_SL2	1
#define SFMT_SR1	7
#define SFMT_SR2	1
#define SFMT_MSK1	0x9f7bffffU
#define SFMT_MSK2	0x9fffff5fU
#define SFMT_MSK3	0x3efffffbU
#define SFMT_MSK4	0xfffff7bbU
#define SFMT_PARITY1	0xa8000001U
#define SFMT_PARITY2	0xaf5390a3U
#define SFMT_PARITY3	0xb740b3f8U
#define SFMT_PARITY4	0x6c11486dU


/* PARAMETERS FOR ALTIVEC */
#if defined(__APPLE__)	/* For OSX */
    #define SFMT_ALTI_SL1 \
	(vector unsigned int)(SFMT_SL1, SFMT_SL1, SFMT_SL1, SFMT_SL1)
    #define SFMT_ALTI_SR1 \
	(vector unsigned int)(SFMT_SR1, SFMT_SR1, SFMT_SR1, SFMT_SR1)
    #define SFMT_ALTI_MSK \
	(vector unsigned int)(SFMT_MSK1, SFMT_MSK2, SFMT_MSK3, SFMT_MSK4)
    #define SFMT_ALTI_MSK64 \
	(vector unsigned int)(SFMT_MSK2, SFMT_MSK1, SFMT_MSK4, SFMT_MSK3)
    #define SFMT_ALTI_SL2_PERM \
	(vector unsigned char)(1,2,3,23,5,6,7,0,9,10,11,4,13,14,15,8)
    #define SFMT_ALTI_SL2_PERM64 \
	(vector unsigned char)(1,2,3,4,5,6,7,31,9,10,11,12,13,14,15,0)
    #define SFMT_ALTI_SR2_PERM \
	(vector unsigned char)(7,0,1,2,11,4,5,6,15,8,9,10,17,12,13,14)
    #define SFMT_ALTI_SR2_PERM64 \
	(vector unsigned char)(15,0,1,2,3,4,5,6,17,8,9,10,11,12,13,14)
#else	/* For OTHER OSs(Linux?) */
    #define SFMT_ALTI_SL1	{SFMT_SL1, SFMT_SL1, SFMT_SL1, SFMT_SL1}
    #define SFMT_ALTI_SR1	{SFMT_SR1, SFMT_SR1, SFMT_SR1, SFMT_SR1}
    #define SFMT_ALTI_MSK	{SFMT_MSK1, SFMT_MSK2, SFMT_MSK3, SFMT_MSK4}
    #define SFMT_ALTI_MSK64	{SFMT_MSK2, SFMT_MSK1, SFMT_MSK4, SFMT_MSK3}
    #define SFMT_ALTI_SL2_PERM	{1,2,3,23,5,6,7,0,9,10,11,4,13,14,15,8}
    #define SFMT_ALTI_SL2_PERM64 {1,2,3,4,5,6,7,31,9,10,11,12,13,14,15,0}
    #define SFMT_ALTI_SR2_PERM	{7,0,1,2,11,4,5,6,15,8,9,10,17,12,13,14}
    #define SFMT_ALTI_SR2_PERM64 {15,0,1,2,3,4,5,6,17,8,9,10,11,12,13,14}
#endif	/* For OSX */
#define SFMT_IDSTR	"SFMT-4253:17-20-1-7-1:9f7bffff-9fffff5f-3efffffb-fffff7bb"

#endif /* SFMT_PARAMS4253_H */
