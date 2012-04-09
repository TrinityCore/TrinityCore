//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef DETOURCOMMON_H
#define DETOURCOMMON_H

template<class T> inline void dtSwap(T& a, T& b) { T t = a; a = b; b = t; }
template<class T> inline T dtMin(T a, T b) { return a < b ? a : b; }
template<class T> inline T dtMax(T a, T b) { return a > b ? a : b; }
template<class T> inline T dtAbs(T a) { return a < 0 ? -a : a; }
template<class T> inline T dtSqr(T a) { return a*a; }
template<class T> inline T dtClamp(T v, T mn, T mx) { return v < mn ? mn : (v > mx ? mx : v); }

float dtSqrt(float x);

inline void dtVcross(float* dest, const float* v1, const float* v2)
{
	dest[0] = v1[1]*v2[2] - v1[2]*v2[1];
	dest[1] = v1[2]*v2[0] - v1[0]*v2[2];
	dest[2] = v1[0]*v2[1] - v1[1]*v2[0]; 
}

inline float dtVdot(const float* v1, const float* v2)
{
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

inline void dtVmad(float* dest, const float* v1, const float* v2, const float s)
{
	dest[0] = v1[0]+v2[0]*s;
	dest[1] = v1[1]+v2[1]*s;
	dest[2] = v1[2]+v2[2]*s;
}

inline void dtVlerp(float* dest, const float* v1, const float* v2, const float t)
{
	dest[0] = v1[0]+(v2[0]-v1[0])*t;
	dest[1] = v1[1]+(v2[1]-v1[1])*t;
	dest[2] = v1[2]+(v2[2]-v1[2])*t;
}

inline void dtVadd(float* dest, const float* v1, const float* v2)
{
	dest[0] = v1[0]+v2[0];
	dest[1] = v1[1]+v2[1];
	dest[2] = v1[2]+v2[2];
}

inline void dtVsub(float* dest, const float* v1, const float* v2)
{
	dest[0] = v1[0]-v2[0];
	dest[1] = v1[1]-v2[1];
	dest[2] = v1[2]-v2[2];
}

inline void dtVscale(float* dest, const float* v, const float t)
{
	dest[0] = v[0]*t;
	dest[1] = v[1]*t;
	dest[2] = v[2]*t;
}

inline void dtVmin(float* mn, const float* v)
{
	mn[0] = dtMin(mn[0], v[0]);
	mn[1] = dtMin(mn[1], v[1]);
	mn[2] = dtMin(mn[2], v[2]);
}

inline void dtVmax(float* mx, const float* v)
{
	mx[0] = dtMax(mx[0], v[0]);
	mx[1] = dtMax(mx[1], v[1]);
	mx[2] = dtMax(mx[2], v[2]);
}

inline void dtVset(float* dest, const float x, const float y, const float z)
{
	dest[0] = x; dest[1] = y; dest[2] = z;
}

inline void dtVcopy(float* dest, const float* a)
{
	dest[0] = a[0];
	dest[1] = a[1];
	dest[2] = a[2];
}

inline float dtVlen(const float* v)
{
	return dtSqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

inline float dtVlenSqr(const float* v)
{
	return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
}

inline float dtVdist(const float* v1, const float* v2)
{
	const float dx = v2[0] - v1[0];
	const float dy = v2[1] - v1[1];
	const float dz = v2[2] - v1[2];
	return dtSqrt(dx*dx + dy*dy + dz*dz);
}

inline float dtVdistSqr(const float* v1, const float* v2)
{
	const float dx = v2[0] - v1[0];
	const float dy = v2[1] - v1[1];
	const float dz = v2[2] - v1[2];
	return dx*dx + dy*dy + dz*dz;
}

inline float dtVdist2D(const float* v1, const float* v2)
{
	const float dx = v2[0] - v1[0];
	const float dz = v2[2] - v1[2];
	return dtSqrt(dx*dx + dz*dz);
}

inline float dtVdist2DSqr(const float* v1, const float* v2)
{
	const float dx = v2[0] - v1[0];
	const float dz = v2[2] - v1[2];
	return dx*dx + dz*dz;
}

inline void dtVnormalize(float* v)
{
	float d = 1.0f / dtSqrt(dtSqr(v[0]) + dtSqr(v[1]) + dtSqr(v[2]));
	v[0] *= d;
	v[1] *= d;
	v[2] *= d;
}

inline bool dtVequal(const float* p0, const float* p1)
{
	static const float thr = dtSqr(1.0f/16384.0f);
	const float d = dtVdistSqr(p0, p1);
	return d < thr;
}

inline unsigned int dtNextPow2(unsigned int v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

inline unsigned int dtIlog2(unsigned int v)
{
	unsigned int r;
	unsigned int shift;
	r = (v > 0xffff) << 4; v >>= r;
	shift = (v > 0xff) << 3; v >>= shift; r |= shift;
	shift = (v > 0xf) << 2; v >>= shift; r |= shift;
	shift = (v > 0x3) << 1; v >>= shift; r |= shift;
	r |= (v >> 1);
	return r;
}

inline int dtAlign4(int x) { return (x+3) & ~3; }

inline int dtOppositeTile(int side) { return (side+4) & 0x7; }

inline float dtVdot2D(const float* u, const float* v)
{
	return u[0]*v[0] + u[2]*v[2];
}

inline float dtVperp2D(const float* u, const float* v)
{
	return u[2]*v[0] - u[0]*v[2];
}

inline float dtTriArea2D(const float* a, const float* b, const float* c)
{
	const float abx = b[0] - a[0];
	const float abz = b[2] - a[2];
	const float acx = c[0] - a[0];
	const float acz = c[2] - a[2];
	return acx*abz - abx*acz;
}

inline bool dtOverlapQuantBounds(const unsigned short amin[3], const unsigned short amax[3],
								 const unsigned short bmin[3], const unsigned short bmax[3])
{
	bool overlap = true;
	overlap = (amin[0] > bmax[0] || amax[0] < bmin[0]) ? false : overlap;
	overlap = (amin[1] > bmax[1] || amax[1] < bmin[1]) ? false : overlap;
	overlap = (amin[2] > bmax[2] || amax[2] < bmin[2]) ? false : overlap;
	return overlap;
}

inline bool dtOverlapBounds(const float* amin, const float* amax,
							const float* bmin, const float* bmax)
{
	bool overlap = true;
	overlap = (amin[0] > bmax[0] || amax[0] < bmin[0]) ? false : overlap;
	overlap = (amin[1] > bmax[1] || amax[1] < bmin[1]) ? false : overlap;
	overlap = (amin[2] > bmax[2] || amax[2] < bmin[2]) ? false : overlap;
	return overlap;
}

void dtClosestPtPointTriangle(float* closest, const float* p,
							  const float* a, const float* b, const float* c);

bool dtClosestHeightPointTriangle(const float* p, const float* a, const float* b, const float* c, float& h);

bool dtIntersectSegmentPoly2D(const float* p0, const float* p1,
							  const float* verts, int nverts,
							  float& tmin, float& tmax,
							  int& segMin, int& segMax);

bool dtPointInPolygon(const float* pt, const float* verts, const int nverts);

bool dtDistancePtPolyEdgesSqr(const float* pt, const float* verts, const int nverts,
							float* ed, float* et);

float dtDistancePtSegSqr2D(const float* pt, const float* p, const float* q, float& t);

void dtCalcPolyCenter(float* tc, const unsigned short* idx, int nidx, const float* verts);

bool dtOverlapPolyPoly2D(const float* polya, const int npolya,
						 const float* polyb, const int npolyb);

#endif // DETOURCOMMON_H
