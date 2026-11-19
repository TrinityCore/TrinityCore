#pragma once
#ifndef SFMT_PARAMS1279_H
#define SFMT_PARAMS1279_H

#define SFMT_POS1	7
#define SFMT_SL1	14
#define SFMT_SL2	3
#define SFMT_SR1	5
#define SFMT_SR2	1
#define SFMT_MSK1	0xf7fefffdU
#define SFMT_MSK2	0x7fefcfffU
#define SFMT_MSK3	0xaff3ef3fU
#define SFMT_MSK4	0xb5ffff7fU
#define SFMT_PARITY1	0x00000001U
#define SFMT_PARITY2	0x00000000U
#define SFMT_PARITY3	0x00000000U
#define SFMT_PARITY4	0x20000000U


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
	(vector unsigned char)(3,21,21,21,7,0,1,2,11,4,5,6,15,8,9,10)
    #define SFMT_ALTI_SL2_PERM64 \
	(vector unsigned char)(3,4,5,6,7,29,29,29,11,12,13,14,15,0,1,2)
    #define SFMT_ALTI_SR2_PERM \
	(vector unsigned char)(7,0,1,2,11,4,5,6,15,8,9,10,17,12,13,14)
    #define SFMT_ALTI_SR2_PERM64 \
	(vector unsigned char)(15,0,1,2,3,4,5,6,17,8,9,10,11,12,13,14)
#else	/* For OTHER OSs(Linux?) */
    #define SFMT_ALTI_SL1	{SFMT_SL1, SFMT_SL1, SFMT_SL1, SFMT_SL1}
    #define SFMT_ALTI_SR1	{SFMT_SR1, SFMT_SR1, SFMT_SR1, SFMT_SR1}
    #define SFMT_ALTI_MSK	{SFMT_MSK1, SFMT_MSK2, SFMT_MSK3, SFMT_MSK4}
    #define SFMT_ALTI_MSK64	{SFMT_MSK2, SFMT_MSK1, SFMT_MSK4, SFMT_MSK3}
    #define SFMT_ALTI_SL2_PERM	{3,21,21,21,7,0,1,2,11,4,5,6,15,8,9,10}
    #define SFMT_ALTI_SL2_PERM64 {3,4,5,6,7,29,29,29,11,12,13,14,15,0,1,2}
    #define SFMT_ALTI_SR2_PERM	{7,0,1,2,11,4,5,6,15,8,9,10,17,12,13,14}
    #define SFMT_ALTI_SR2_PERM64 {15,0,1,2,3,4,5,6,17,8,9,10,11,12,13,14}
#endif	/* For OSX */
#define SFMT_IDSTR	"SFMT-1279:7-14-3-5-1:f7fefffd-7fefcfff-aff3ef3f-b5ffff7f"

#endif /* SFMT_PARAMS1279_H */
