#pragma once
#ifndef SFMT_PARAMS607_H
#define SFMT_PARAMS607_H

#define SFMT_POS1	2
#define SFMT_SL1	15
#define SFMT_SL2	3
#define SFMT_SR1	13
#define SFMT_SR2	3
#define SFMT_MSK1	0xfdff37ffU
#define SFMT_MSK2	0xef7f3f7dU
#define SFMT_MSK3	0xff777b7dU
#define SFMT_MSK4	0x7ff7fb2fU
#define SFMT_PARITY1	0x00000001U
#define SFMT_PARITY2	0x00000000U
#define SFMT_PARITY3	0x00000000U
#define SFMT_PARITY4	0x5986f054U


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
	(vector unsigned char)(5,6,7,0,9,10,11,4,13,14,15,8,19,19,19,12)
    #define SFMT_ALTI_SR2_PERM64 \
	(vector unsigned char)(13,14,15,0,1,2,3,4,19,19,19,8,9,10,11,12)
#else	/* For OTHER OSs(Linux?) */
    #define SFMT_ALTI_SL1	{SFMT_SL1, SFMT_SL1, SFMT_SL1, SFMT_SL1}
    #define SFMT_ALTI_SR1	{SFMT_SR1, SFMT_SR1, SFMT_SR1, SFMT_SR1}
    #define SFMT_ALTI_MSK	{SFMT_MSK1, SFMT_MSK2, SFMT_MSK3, SFMT_MSK4}
    #define SFMT_ALTI_MSK64	{SFMT_MSK2, SFMT_MSK1, SFMT_MSK4, SFMT_MSK3}
    #define SFMT_ALTI_SL2_PERM	{3,21,21,21,7,0,1,2,11,4,5,6,15,8,9,10}
    #define SFMT_ALTI_SL2_PERM64 {3,4,5,6,7,29,29,29,11,12,13,14,15,0,1,2}
    #define SFMT_ALTI_SR2_PERM	{5,6,7,0,9,10,11,4,13,14,15,8,19,19,19,12}
    #define SFMT_ALTI_SR2_PERM64 {13,14,15,0,1,2,3,4,19,19,19,8,9,10,11,12}
#endif	/* For OSX */
#define SFMT_IDSTR	"SFMT-607:2-15-3-13-3:fdff37ff-ef7f3f7d-ff777b7d-7ff7fb2f"

#endif /* SFMT_PARAMS607_H */
