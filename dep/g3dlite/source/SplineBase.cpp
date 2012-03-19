#include "G3D/platform.h"
#include "G3D/Spline.h"

namespace G3D {

float SplineBase::getFinalInterval() const {
    if (! cyclic) {
        return 0;
    } else if (finalInterval <= 0) {
        int N = time.size();
        if (N >= 2) {
            return (time[1] - time[0] + time[N - 1] - time[N - 2]) * 0.5f;
        } else {
            return 1.0f;
        }
    } else {
        return finalInterval;
    }
}


Matrix4 SplineBase::computeBasis() {
    // The standard Catmull-Rom spline basis (e.g., Watt & Watt p108)
    // is for [u^3 u^2 u^1 u^0] * B * [p[0] p[1] p[2] p[3]]^T.
    // We need a basis formed for:
    //
    //     U * C * [2*p'[1] p[1] p[2] 2*p'[2]]^T 
    //
    //     U * C * [p2-p0 p1 p2 p3-p1]^T 
    //
    // To make this transformation, compute the differences of columns in C:
    // For [p0 p1 p2 p3]
    Matrix4 basis =
        Matrix4( -1,  3, -3,  1,
                  2, -5,  4, -1,
                 -1,  0,  1,  0,
                  0,  2,  0,  0) * 0.5f;

    // For [-p0 p1 p2 p3]^T 
    basis.setColumn(0, -basis.column(0));

    // For [-p0 p1 p2 p3-p1]^T 
    basis.setColumn(1, basis.column(1) + basis.column(3));

    // For [p2-p0 p1 p2 p3-p1]^T 
    basis.setColumn(2, basis.column(2) - basis.column(0));

    return basis;
}


float SplineBase::duration() const {
    if (time.size() == 0) {
        return 0;
    } else {
        return time.last() - time[0] + getFinalInterval();
    }
}
    

void SplineBase::computeIndexInBounds(float s, int& i, float& u) const {
    int N = time.size();
    float t0 = time[0];
    float tn = time[N - 1];
    
    i = iFloor((N - 1) * (s - t0) / (tn - t0));
    
    // Inclusive bounds for binary search
    int hi = N - 1;
    int lo = 0;
    
    while ((time[i] > s) || (time[i + 1] <= s)) {
        
        if (time[i] > s) {
            // too big
            hi = i - 1;
        } else if (time[i + 1] <= s) {
            // too small
            lo = i + 1;
        }
        
        i = (hi + lo) / 2;
    }
    
    // Having exited the above loop, i must be correct, so compute u.
    u = (s - time[i]) / (time[i + 1] - time[i]);
}


void SplineBase::computeIndex(float s, int& i, float& u) const {
    int N = time.size();
    debugAssertM(N > 0, "No control points");
    float t0 = time[0];
    float tn = time[N - 1];
    
    if (N < 2) {
        // No control points to work with
        i = 0;
        u = 0.0;
    } else if (cyclic) {
        float fi = getFinalInterval();
        
        // Cyclic spline
        if ((s < t0) || (s >= tn + fi)) {
            // Cyclic, off the bottom or top
            
            // Compute offset and reduce to the in-bounds case

            float d = duration();
            // Number of times we wrapped around the cyclic array
            int wraps = iFloor((s - t0) / d);
            
            debugAssert(s - d * wraps >= t0);
            debugAssert(s - d * wraps < tn + getFinalInterval());

            computeIndex(s - d * wraps, i, u);
            i += wraps * N;
            
        } else if (s >= tn) {
            debugAssert(s < tn + fi);
            // Cyclic, off the top but before the end of the last interval
            i = N - 1;
            u = (s - tn) / fi;
            
        } else {
            // Cyclic, in bounds
            computeIndexInBounds(s, i, u);
        }
        
    } else {
        // Non-cyclic
        
        if (s < t0) {
            // Non-cyclic, off the bottom.  Assume points are spaced
            // following the first time interval.
            
            float dt = time[1] - t0;
            float x = (s - t0) / dt;
            i = iFloor(x);
            u = x - i;
            
        } else if (s >= tn) {
            // Non-cyclic, off the top.  Assume points are spaced following
            // the last time interval.
            
            float dt = tn - time[N - 2];
            float x = N - 1 + (s - tn) / dt;
            i = iFloor(x);
            u = x - i;  
            
        } else {
            // In bounds, non-cyclic.  Assume a regular
            // distribution (which gives O(1) for uniform spacing)
            // and then binary search to handle the general case
            // efficiently.
            computeIndexInBounds(s, i, u);
            
        } // if in bounds
    } // if cyclic
}

}
