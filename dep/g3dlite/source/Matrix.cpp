/**
 @file Matrix.cpp
 @author Morgan McGuire, http://graphics.cs.williams.edu
 */
#include "G3D/Matrix.h"
#include "G3D/TextOutput.h"

static inline G3D::Matrix::T negate(G3D::Matrix::T x) {
    return -x;
}

namespace G3D {

int Matrix::debugNumCopyOps  = 0;
int Matrix::debugNumAllocOps = 0;

void Matrix::serialize(TextOutput& t) const {
    t.writeSymbol("%");
    t.writeNumber(rows());
    t.writeSymbol("x");
    t.writeNumber(cols());
    t.pushIndent();
    t.writeNewline();

    t.writeSymbol("[");
    for (int r = 0; r < rows(); ++r) {
        for (int c = 0; c < cols(); ++c) {
            t.writeNumber(impl->get(r, c));
            if (c < cols() - 1) {
                t.writeSymbol(",");
            } else {
                if (r < rows() - 1) {
                    t.writeSymbol(";");
                    t.writeNewline();
                }
            }
        }
    }
    t.writeSymbol("]");
    t.popIndent();
    t.writeNewline();
}


std::string Matrix::toString(const std::string& name) const {
	std::string s;

    if (name != "") {
        s += format("%s = \n", name.c_str());
    }

	s += "[";
    for (int r = 0; r < rows(); ++r) {
        for (int c = 0; c < cols(); ++c) {
            double v = impl->get(r, c);

			if (::fabs(v) < 0.00001) {
				// Don't print "negative zero"
                s += format("% 10.04g", 0.0);
			} else if (v == iRound(v)) {
                // Print integers nicely
                s += format("% 10.04g", v);
            } else {
                s += format("% 10.04f", v);
            }

            if (c < cols() - 1) {
                s += ",";
            } else if (r < rows() - 1) {
                s += ";\n ";
			} else {
				s += "]\n";
			}
        }
    }
	return s;
}


#define INPLACE(OP)\
    ImplRef A = impl;\
\
    if (! A.isLastReference()) {\
        impl = new Impl(A->R, A->C);\
    }\
\
    A->OP(B, *impl);

Matrix& Matrix::operator*=(const T& B) {
    INPLACE(mul)
    return *this;
}


Matrix& Matrix::operator-=(const T& B) {
    INPLACE(sub)
    return *this;
}


Matrix& Matrix::operator+=(const T& B) {
    INPLACE(add)
    return *this;
}


Matrix& Matrix::operator/=(const T& B) {
    INPLACE(div)
    return *this;
}


Matrix& Matrix::operator*=(const Matrix& B) {
    // We can't optimize this one
    *this = *this * B;
    return *this;
}


Matrix& Matrix::operator-=(const Matrix& _B) {
    const Impl& B = *_B.impl;
    INPLACE(sub)
    return *this;
}


Matrix& Matrix::operator+=(const Matrix& _B) {
    const Impl& B = *_B.impl;
    INPLACE(add)
    return *this;
}


void Matrix::arrayMulInPlace(const Matrix& _B) {
    const Impl& B = *_B.impl;
    INPLACE(arrayMul)
}


void Matrix::arrayDivInPlace(const Matrix& _B) {
    const Impl& B = *_B.impl;
    INPLACE(arrayDiv)
}

#undef INPLACE

Matrix Matrix::fromDiagonal(const Matrix& d) {
    debugAssert((d.rows() == 1) || (d.cols() == 1));

    int n = d.numElements();
    Matrix D = zero(n, n);
    for (int i = 0; i < n; ++i) {
        D.set(i, i, d.impl->data[i]);
    }

    return D;
}

void Matrix::set(int r, int c, T v) {
    if (! impl.isLastReference()) {
        // Copy the data before mutating; this object is shared
        impl = new Impl(*impl);
    }
    impl->set(r, c, v);
}


void Matrix::setRow(int r, const Matrix& vec) {
    debugAssertM(vec.cols() == cols(),
        "A row must be set to a vector of the same size.");
    debugAssertM(vec.rows() == 1,
        "A row must be set to a row vector.");

    debugAssert(r >= 0);
    debugAssert(r < rows());

    if (! impl.isLastReference()) {
        // Copy the data before mutating; this object is shared
        impl = new Impl(*impl);
    }
    impl->setRow(r, vec.impl->data);
}


void Matrix::setCol(int c, const Matrix& vec) {
    debugAssertM(vec.rows() == rows(),
        "A column must be set to a vector of the same size.");
    debugAssertM(vec.cols() == 1,
        "A column must be set to a column vector.");

    debugAssert(c >= 0);

    debugAssert(c < cols());

    if (! impl.isLastReference()) {
        // Copy the data before mutating; this object is shared
        impl = new Impl(*impl);
    }
    impl->setCol(c, vec.impl->data);
}


Matrix::T Matrix::get(int r, int c) const {
    return impl->get(r, c);
}


Matrix Matrix::row(int r) const {
    debugAssert(r >= 0);
    debugAssert(r < rows());
    Matrix out(1, cols());
    out.impl->setRow(1, impl->elt[r]);
    return out;
}


Matrix Matrix::col(int c) const {
    debugAssert(c >= 0);
    debugAssert(c < cols());
    Matrix out(rows(), 1);

    T* outData = out.impl->data;
    // Get a pointer to the first element in the column
    const T* inElt = &(impl->elt[0][c]);
    int R = rows();
    int C = cols();
    for (int r = 0; r < R; ++r) {
        outData[r] = *inElt;
        // Skip around to the next row
        inElt += C;
    }

    return out;
}


Matrix Matrix::zero(int R, int C) {
    Impl* A = new Impl(R, C);
    A->setZero();
    return Matrix(A);
}


Matrix Matrix::one(int R, int C) {
    Impl* A = new Impl(R, C);
    for (int i = R * C - 1; i >= 0; --i) {
        A->data[i] = 1.0;
    }
    return Matrix(A);
}


Matrix Matrix::random(int R, int C) {
    Impl* A = new Impl(R, C);
    for (int i = R * C - 1; i >= 0; --i) {
        A->data[i] = G3D::uniformRandom(0.0, 1.0);
    }
    return Matrix(A);
}


Matrix Matrix::identity(int N) {
    Impl* m = new Impl(N, N);
    m->setZero();
    for (int i = 0; i < N; ++i) {
        m->elt[i][i] = 1.0;
    }
    return Matrix(m);
}


// Implement an explicit-output unary method by trampolining to the impl
#define TRAMPOLINE_EXPLICIT_1(method)\
void Matrix::method(Matrix& out) const {\
    if ((out.impl == impl) && impl.isLastReference()) {\
        impl->method(*out.impl);\
    } else {\
        out = this->method();\
    }\
}

TRAMPOLINE_EXPLICIT_1(abs)
TRAMPOLINE_EXPLICIT_1(negate)
TRAMPOLINE_EXPLICIT_1(arrayLog)
TRAMPOLINE_EXPLICIT_1(arrayExp)
TRAMPOLINE_EXPLICIT_1(arrayCos)
TRAMPOLINE_EXPLICIT_1(arraySin)

void Matrix::mulRow(int r, const T& v) {
    debugAssert(r >= 0 && r < rows());

    if (! impl.isLastReference()) {
        impl = new Impl(*impl);
    }

    impl->mulRow(r, v);
}


void Matrix::transpose(Matrix& out) const {
    if ((out.impl == impl) && impl.isLastReference() && (impl->R == impl->C)) {
        // In place
        impl->transpose(*out.impl);
    } else {
        out = this->transpose();
    }
}


Matrix3 Matrix::toMatrix3() const {
    debugAssert(impl->R == 3);
    debugAssert(impl->C == 3);
    return Matrix3(
        impl->get(0,0), impl->get(0,1), impl->get(0,2),
        impl->get(1,0), impl->get(1,1), impl->get(1,2),
        impl->get(2,0), impl->get(2,1), impl->get(2,2));
}


Matrix4 Matrix::toMatrix4() const {
    debugAssert(impl->R == 4);
    debugAssert(impl->C == 4);
    return Matrix4(
        impl->get(0,0), impl->get(0,1), impl->get(0,2), impl->get(0,3),
        impl->get(1,0), impl->get(1,1), impl->get(1,2), impl->get(1,3),
        impl->get(2,0), impl->get(2,1), impl->get(2,2), impl->get(2,3),
        impl->get(3,0), impl->get(3,1), impl->get(3,2), impl->get(3,3));
}


Vector2 Matrix::toVector2() const {
    debugAssert(impl->R * impl->C == 2);
    if (impl->R > impl->C) {
        return Vector2(impl->get(0,0), impl->get(1,0));
    } else {
        return Vector2(impl->get(0,0), impl->get(0,1));
    }
}


Vector3 Matrix::toVector3() const {
    debugAssert(impl->R * impl->C == 3);
    if (impl->R > impl->C) {
        return Vector3(impl->get(0,0), impl->get(1,0), impl->get(2, 0));
    } else {
        return Vector3(impl->get(0,0), impl->get(0,1), impl->get(0, 2));
    }
}


Vector4 Matrix::toVector4() const {
    debugAssert(
        ((impl->R == 4) && (impl->C == 1)) || 
        ((impl->R == 1) && (impl->C == 4)));
    
    if (impl->R > impl->C) {
        return Vector4(impl->get(0,0), impl->get(1,0), impl->get(2, 0), impl->get(3,0));
    } else {
        return Vector4(impl->get(0,0), impl->get(0,1), impl->get(0, 2), impl->get(0,3));
    }
}


void Matrix::swapRows(int r0, int r1) {
    debugAssert(r0 >= 0 && r0 < rows());
    debugAssert(r1 >= 0 && r1 < rows());

    if (r0 == r1) {
        return;
    }

    if (! impl.isLastReference()) {
        impl = new Impl(*impl);
    }

    impl->swapRows(r0, r1);
}


void Matrix::swapAndNegateCols(int c0, int c1) {
    debugAssert(c0 >= 0 && c0 < cols());
    debugAssert(c1 >= 0 && c1 < cols());

    if (c0 == c1) {
        return;
    }

    if (! impl.isLastReference()) {
        impl = new Impl(*impl);
    }

    impl->swapAndNegateCols(c0, c1);
}

Matrix Matrix::subMatrix(int r1, int r2, int c1, int c2) const {
    debugAssert(r2>=r1);
    debugAssert(c2>=c1);
    debugAssert(c2<cols());
    debugAssert(r2<rows());
    debugAssert(r1>=0);
    debugAssert(c1>=0);

    Matrix X(r2 - r1 + 1, c2 - c1 + 1);

    for (int r = 0; r < X.rows(); ++r) {
        for (int c = 0; c < X.cols(); ++c) {
            X.set(r, c, get(r + r1, c + c1));
        }
    }

    return X;
}


bool Matrix::anyNonZero() const {
    return impl->anyNonZero();
}


bool Matrix::allNonZero() const {
    return impl->allNonZero();
}


void Matrix::svd(Matrix& U, Array<T>& d, Matrix& V, bool sort) const {
    debugAssert(rows() >= cols());
    debugAssertM(&U != &V, "Arguments to SVD must be different matrices");
    debugAssertM(&U != this, "Arguments to SVD must be different matrices");
    debugAssertM(&V != this, "Arguments to SVD must be different matrices");

    int R = rows();
    int C = cols();

    // Make sure we don't overwrite a shared matrix
    if (! V.impl.isLastReference()) {
        V = Matrix::zero(C, C);
    } else {
        V.impl->setSize(C, C);
    }

    if (&U != this || ! impl.isLastReference()) {
        // Make a copy of this for in-place SVD
        U.impl = new Impl(*impl);
    }

    d.resize(C);
    const char* ret = svdCore(U.impl->elt, R, C, d.getCArray(), V.impl->elt);

    debugAssertM(ret == NULL, ret);
    (void)ret;

    if (sort) {
        // Sort the singular values from greatest to least

        Array<SortRank> rank;
        rank.resize(C);
        for (int c = 0; c < C; ++c) {
            rank[c].col   = c;
            rank[c].value = d[c];
        }

        rank.sort(SORT_INCREASING);

        Matrix Uold = U;
        Matrix Vold = V;

        U = Matrix(U.rows(), U.cols());
        V = Matrix(V.rows(), V.cols());

        // Now permute U, d, and V appropriately
        for (int c0 = 0; c0 < C; ++c0) {
            const int c1 = rank[c0].col;

            d[c0] = rank[c0].value;
            U.setCol(c0, Uold.col(c1));
            V.setCol(c0, Vold.col(c1));
        }

    }
}


#define COMPARE_SCALAR(OP)\
Matrix Matrix::operator OP (const T& scalar) const {\
    int R = rows();\
    int C = cols();\
    int N = R * C;\
    Matrix out = Matrix::zero(R, C);\
\
    const T* raw = impl->data;\
    T* outRaw = out.impl->data;\
    for (int i = 0; i < N; ++i) {\
        outRaw[i] = raw[i] OP scalar;\
    }\
\
    return out;\
}

COMPARE_SCALAR(<)
COMPARE_SCALAR(<=)
COMPARE_SCALAR(>)
COMPARE_SCALAR(>=)
COMPARE_SCALAR(==)
COMPARE_SCALAR(!=)

#undef COMPARE_SCALAR

double Matrix::normSquared() const {
    int R = rows();
    int C = cols();
    int N = R * C;

    double sum = 0.0;

    const T* raw = impl->data;
    for (int i = 0; i < N; ++i) {
        sum += square(raw[i]);
    }

    return sum;
}

double Matrix::norm() const {
    return sqrt(normSquared());
}

///////////////////////////////////////////////////////////

Matrix::Impl::Impl(const Matrix3& M) : elt(NULL), data(NULL), R(0), C(0), dataSize(0){
    setSize(3, 3);
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            set(r, c, M[r][c]);
        }
    }

}


Matrix::Impl::Impl(const Matrix4& M): elt(NULL), data(NULL), R(0), C(0), dataSize(0) {
    setSize(4, 4);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            set(r, c, M[r][c]);
        }
    }
}


void Matrix::Impl::setSize(int newRows, int newCols) {
    if ((R == newRows) && (C == newCols)) {
        // Nothing to do
        return;
    }

    int newSize = newRows * newCols;

    R = newRows; C = newCols;

    // Only allocate if we need more space
    // or the size difference is ridiculous
    if ((newSize > dataSize) || (newSize < dataSize / 4)) {
        System::alignedFree(data);
        data = (float*)System::alignedMalloc(R * C * sizeof(T), 16);
        ++Matrix::debugNumAllocOps;
        dataSize = newSize;
    }

    // Construct the row pointers
    //delete[] elt;
    System::free(elt);
    elt = (T**)System::malloc(R * sizeof(T*));// new T*[R];

    for (int r = 0; r < R; ++ r) {
        elt[r] = data + r * C;
    }
}


Matrix::Impl::~Impl() {
    //delete[] elt;
    System::free(elt);
    System::alignedFree(data);
}


Matrix::Impl& Matrix::Impl::operator=(const Impl& m) {
    setSize(m.R, m.C);
    System::memcpy(data, m.data, R * C * sizeof(T));
    ++Matrix::debugNumCopyOps;
    return *this;
}


void Matrix::Impl::setZero() {
    System::memset(data, 0, R * C * sizeof(T));
}


void Matrix::Impl::swapRows(int r0, int r1) {
    T* R0 = elt[r0];
    T* R1 = elt[r1];

    for (int c = 0; c < C; ++c) {
        T temp = R0[c];
        R0[c] = R1[c];
        R1[c] = temp;
    }
}


void Matrix::Impl::swapAndNegateCols(int c0, int c1) {
    for (int r = 0; r < R; ++r) {
        T* row = elt[r];

        const T temp = -row[c0];
        row[c0] = -row[c1];
        row[c1] = temp;
    }
}


void Matrix::Impl::mulRow(int r, const T& v) {
    T* row = elt[r];

    for (int c = 0; c < C; ++c) {
        row[c] *= v;
    }
}


void Matrix::Impl::mul(const Impl& B, Impl& out) const {
    const Impl& A = *this;

    debugAssertM(
        (this != &out) && (&B != &out),
        "Output argument to mul cannot be the same as an input argument.");

    debugAssert(A.C == B.R);
    debugAssert(A.R == out.R);
    debugAssert(B.C == out.C);

    for (int r = 0; r < out.R; ++r) {
        for (int c = 0; c < out.C; ++c) {
            T sum = 0.0;
            for (int i = 0; i < A.C; ++i) {
                sum += A.get(r, i) * B.get(i, c);
            }
            out.set(r, c, sum);
        }
    }
}


// We're about to define several similar methods,
// so use a macro to share implementations.  This
// must be a macro because the difference between
// the macros is the operation in the inner loop.
#define IMPLEMENT_ARRAY_2(method, OP)\
void Matrix::Impl::method(const Impl& B, Impl& out) const {\
    const Impl& A = *this;\
                            \
    debugAssert(A.C == B.C);\
    debugAssert(A.R == B.R);\
    debugAssert(A.C == out.C);\
    debugAssert(A.R == out.R);\
                            \
    for (int i = R * C - 1; i >= 0; --i) {\
        out.data[i] = A.data[i] OP B.data[i];\
    }\
}


#define IMPLEMENT_ARRAY_1(method, f)\
void Matrix::Impl::method(Impl& out) const {\
    const Impl& A = *this;\
                            \
    debugAssert(A.C == out.C);\
    debugAssert(A.R == out.R);\
                            \
    for (int i = R * C - 1; i >= 0; --i) {\
        out.data[i] = f(A.data[i]);\
    }\
}


#define IMPLEMENT_ARRAY_SCALAR(method, OP)\
void Matrix::Impl::method(Matrix::T B, Impl& out) const {\
    const Impl& A = *this;\
                            \
    debugAssert(A.C == out.C);\
    debugAssert(A.R == out.R);\
                            \
    for (int i = R * C - 1; i >= 0; --i) {\
        out.data[i] = A.data[i] OP B;\
    }\
}

IMPLEMENT_ARRAY_2(add, +)
IMPLEMENT_ARRAY_2(sub, -)
IMPLEMENT_ARRAY_2(arrayMul, *)
IMPLEMENT_ARRAY_2(arrayDiv, /)

IMPLEMENT_ARRAY_SCALAR(add, +)
IMPLEMENT_ARRAY_SCALAR(sub, -)
IMPLEMENT_ARRAY_SCALAR(mul, *)
IMPLEMENT_ARRAY_SCALAR(div, /)

IMPLEMENT_ARRAY_1(abs,      ::fabs)
IMPLEMENT_ARRAY_1(negate,   ::negate)
IMPLEMENT_ARRAY_1(arrayLog, ::log)
IMPLEMENT_ARRAY_1(arraySqrt, ::sqrt)
IMPLEMENT_ARRAY_1(arrayExp, ::exp)
IMPLEMENT_ARRAY_1(arrayCos, ::cos)
IMPLEMENT_ARRAY_1(arraySin, ::sin)

#undef IMPLEMENT_ARRAY_SCALAR
#undef IMPLEMENT_ARRAY_1
#undef IMPLEMENT_ARRAY_2

// lsub is special because the argument order is reversed
void Matrix::Impl::lsub(Matrix::T B, Impl& out) const {
    const Impl& A = *this;

    debugAssert(A.C == out.C);
    debugAssert(A.R == out.R);

    for (int i = R * C - 1; i >= 0; --i) {
        out.data[i] = B - A.data[i];
    }
}


void Matrix::Impl::inverseViaAdjoint(Impl& out) const {
    debugAssert(&out != this);

    // Inverse = adjoint / determinant

    adjoint(out);

    // Don't call the determinant method when we already have an
    // adjoint matrix; there's a faster way of computing it: the dot
    // product of the first row and the adjoint's first col.
    double det = 0.0;
    for (int r = R - 1; r >= 0; --r) {
        det += elt[0][r] * out.elt[r][0];
    }

	out.div(Matrix::T(det), out);
}


void Matrix::Impl::transpose(Impl& out) const {
    debugAssert(out.R == C);
    debugAssert(out.C == R);

    if (&out == this) {
        // Square matrix in place
        for (int r = 0; r < R; ++r) {
            for (int c = r + 1; c < C; ++c) {
                T temp = get(r, c);
                out.set(r, c, get(c, r));
                out.set(c, r, temp);
            }
        }
    } else {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                out.set(c, r, get(r, c)); 
            }
        }
    }
}


void Matrix::Impl::adjoint(Impl& out) const {    
    cofactor(out);
    // Transpose is safe to perform in place
    out.transpose(out);
}


void Matrix::Impl::cofactor(Impl& out) const {
    debugAssert(&out != this);
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            out.set(r, c, cofactor(r, c));
        }
    } 
}


Matrix::T Matrix::Impl::cofactor(int r, int c) const {
    // Strang p. 217
    float s = isEven(r + c) ? 1.0f : -1.0f;

    return s * determinant(r, c);
}


Matrix::T Matrix::Impl::determinant(int nr, int nc) const {
    debugAssert(R > 0);
    debugAssert(C > 0);
    Impl A(R - 1, C - 1);
    withoutRowAndCol(nr, nc, A);
    return A.determinant();
}


void Matrix::Impl::setRow(int r, const T* vals) {
    debugAssert(r >= 0);
    System::memcpy(elt[r], vals, sizeof(T) * C);
}


void Matrix::Impl::setCol(int c, const T* vals) {
    for (int r = 0; r < R; ++r) {
        elt[r][c] = vals[r];
    }
}


Matrix::T Matrix::Impl::determinant() const {

    debugAssert(R == C);

    // Compute using cofactors
    switch(R) {
    case 0:
        return 0;

    case 1:
        // Determinant of a 1x1 is the element
        return elt[0][0];

    case 2:
        // Determinant of a 2x2 is ad-bc
        return elt[0][0] * elt[1][1] - elt[0][1] * elt[1][0];

    case 3:
        {
          // Determinant of an nxn matrix is the dot product of the first
          // row with the first row of cofactors.  The base cases of this
          // method get called a lot, so we spell out the implementation
          // for the 3x3 case.

          float cofactor00 = elt[1][1] * elt[2][2] - elt[1][2] * elt[2][1];
          float cofactor10 = elt[1][2] * elt[2][0] - elt[1][0] * elt[2][2];
          float cofactor20 = elt[1][0] * elt[2][1] - elt[1][1] * elt[2][0];
      
		  return Matrix::T(
            elt[0][0] * cofactor00 +
            elt[0][1] * cofactor10 +
            elt[0][2] * cofactor20);
        }
      
    default:
        {
            // Determinant of an n x n matrix is the dot product of the first
            // row with the first row of cofactors
            T det = 0;

            for (int c = 0; c < C; ++c) {
                det += elt[0][c] * cofactor(0, c);
            }

            return det;
        }
    }
}


void Matrix::Impl::withoutRowAndCol(int excludeRow, int excludeCol, Impl& out) const {
    debugAssert(out.R == R - 1);
    debugAssert(out.C == C - 1);

    for (int r = 0; r < out.R; ++r) {
        for (int c = 0; c < out.C; ++c) {
            out.elt[r][c] = elt[r + ((r >= excludeRow) ? 1 : 0)][c + ((c >= excludeCol) ? 1 : 0)];
        }
    }
}


Matrix Matrix::pseudoInverse(float tolerance) const {
    if ((cols() == 1) || (rows() == 1)) {
        return vectorPseudoInverse();
    } else if ((cols() <= 4) || (rows() <= 4)) {
        return partitionPseudoInverse();
    } else {
        return svdPseudoInverse(tolerance);
    }
}

/*
    Public function for testing purposes only. Use pseudoInverse(), as it contains optimizations for 
    nonsingular matrices with at least one small (<5) dimension.
*/
Matrix Matrix::svdPseudoInverse(float tolerance) const {
   	if (cols() > rows()) {
		return transpose().svdPseudoInverse(tolerance).transpose();
	}

    // Matrices from SVD
    Matrix U, V;

    // Diagonal elements
    Array<T> d;

	svd(U, d, V);

    if (rows() == 1) {
        d.resize(1, false);
    }

	if (tolerance < 0) {
		// TODO: Should be eps(d[0]), which is the largest diagonal
		tolerance = G3D::max(rows(), cols()) * 0.0001f;
	}

	Matrix X;

	int r = 0;
	for (int i = 0; i < d.size(); ++i) {
		if (d[i] > tolerance) {
			d[i] = Matrix::T(1) / d[i];
			++r;
		}
	}

	if (r == 0) {
		// There were no non-zero elements
		X = zero(cols(), rows());
	} else {
		// Use the first r columns
        
        // Test code (the rest is below)
        /*
        d.resize(r);
        Matrix testU = U.subMatrix(0, U.rows() - 1, 0, r - 1);
        Matrix testV = V.subMatrix(0, V.rows() - 1, 0, r - 1);
        Matrix testX = testV * Matrix::fromDiagonal(d) * testU.transpose();
        X = testX;
        */
        

        // We want to do this:
        //
        //   d.resize(r);
        //   U = U.subMatrix(0, U.rows() - 1, 0, r - 1);
        //   X = V * Matrix::fromDiagonal(d) * U.transpose();
        //
        // but creating a large diagonal matrix and then
        // multiplying by it is wasteful.  So we instead
        // explicitly perform A = (D * U')' = U * D, and 
        // then multiply X = V * A'.

        Matrix A = Matrix(U.rows(), r);

        const T* dPtr = d.getCArray();
        for (int i = 0; i < A.rows(); ++i) {
            const T* Urow = U.impl->elt[i];
            T* Arow = A.impl->elt[i];
            const int Acols = A.cols();
            for (int j = 0; j < Acols; ++j) {
                // A(i,j) = U(i,:) * D(:,j)
                // This is non-zero only at j = i because D is diagonal
                // A(i,j) = U(i,j) * D(j,j)
                Arow[j] = Urow[j] * dPtr[j];
            }
        }

        //
        // Compute X = V.subMatrix(0, V.rows() - 1, 0, r - 1) * A.transpose()
        // 
        // Avoid the explicit subMatrix call, and by storing A' instead of A, avoid
        // both the transpose and the memory incoherence of striding across memory
        // in big steps.

        alwaysAssertM(A.cols() == r, 
            "Internal dimension mismatch during pseudoInverse()");
        alwaysAssertM(V.cols() >= r, 
            "Internal dimension mismatch during pseudoInverse()");

        X = Matrix(V.rows(), A.rows());
        T** Xelt = X.impl->elt;
        for (int i = 0; i < X.rows(); ++i) {
            const T* Vrow = V.impl->elt[i];
            for (int j = 0; j < X.cols(); ++j) {
                const T* Arow = A.impl->elt[j];
                T sum = 0;
                for (int k = 0; k < r; ++k) {
                    sum += Vrow[k] * Arow[k];
                }
                Xelt[i][j] = sum;
            }
        }

        /*
        // Test that results are the same after optimizations:
        Matrix diff = X - testX;
        T n = diff.norm();
        debugAssert(n < 0.0001);
        */
    }
	return X;
}

// Computes pseudoinverse for a vector
Matrix Matrix::vectorPseudoInverse() const {
    // If vector A has nonzero elements: transpose A, then divide each elt. by the squared norm
    // If A is zero vector: transpose A
    double x = 0.0;

    if (anyNonZero()) {
        x = 1.0 / normSquared();
    }

    Matrix A(cols(), rows());
    T** Aelt = A.impl->elt;
    for (int r = 0; r < rows(); ++r) {
        const T* MyRow = impl->elt[r];
        for (int c = 0; c < cols(); ++c) {
            Aelt[c][r] = T(MyRow[c] * x); 
        }
    }
    return Matrix(A);
}


Matrix Matrix::rowPartPseudoInverse() const{
    int m = rows();
    int n = cols();
    alwaysAssertM((m<=n),"Row-partitioned block matrix pseudoinverse requires R<C");

    // B = A * A'
    Matrix A = *this;
    Matrix B = Matrix(m,m);

    T** Aelt = A.impl->elt;
    T** Belt = B.impl->elt;
    for (int i = 0; i < m; ++i) {
        const T* Arow = Aelt[i];
        for (int j = 0; j < m; ++j) {
            const T* Brow = Aelt[j];
            T sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += Arow[k] * Brow[k];
            }
            Belt[i][j] = sum;
        }
    }
    
    // B has size m x m
    switch (m) {
    case 2:
        return row2PseudoInverse(B);

    case 3:
        return row3PseudoInverse(B);

    case 4:
        return row4PseudoInverse(B);

    default:
        alwaysAssertM(false, "G3D internal error: Should have used the vector or general case!");
        return Matrix();
    }
}

Matrix Matrix::colPartPseudoInverse() const{
    int m = rows();
    int n = cols();
    alwaysAssertM((m>=n),"Column-partitioned block matrix pseudoinverse requires R>C");
    // TODO: Put each of the individual cases in its own helper function
    // TODO: Push the B computation down into the individual cases
    // B = A' * A
    Matrix A = *this;
    Matrix B = Matrix(n, n);
    T** Aelt = A.impl->elt;
    T** Belt = B.impl->elt;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            T sum = 0;
            for (int k = 0; k < m; ++k) {
                sum += Aelt[k][i] * Aelt[k][j];
            }
            Belt[i][j] = sum;
        }
    }

    // B has size n x n
    switch (n) {
    case 2:
        return col2PseudoInverse(B);

    case 3:
        return col3PseudoInverse(B);

    case 4:
        return col4PseudoInverse(B);

    default:
        alwaysAssertM(false, "G3D internal error: Should have used the vector or general case!");
        return Matrix();
    }
}

Matrix Matrix::col2PseudoInverse(const Matrix& B) const {

    Matrix A = *this;
    int m = rows();
    int n = cols();
    (void)n;

    // Row-major 2x2 matrix
    const float B2[2][2] = 
       {{B.get(0,0), B.get(0,1)}, 
        {B.get(1,0), B.get(1,1)}};

    float det = (B2[0][0]*B2[1][1]) - (B2[0][1]*B2[1][0]);

    if (fuzzyEq(det, T(0))) {
        
        // Matrix was singular; the block matrix pseudo-inverse can't
        // handle that, so fall back to the old case
        return svdPseudoInverse();

    } else {
        // invert using formula at http://www.netsoc.tcd.ie/~jgilbert/maths_site/applets/algebra/matrix_inversion.html

        // Multiply by Binv * A'
        Matrix X(cols(), rows());

        T** Xelt = X.impl->elt;
        T** Aelt = A.impl->elt;
        float binv00 =  B2[1][1]/det, binv01 = -B2[1][0]/det;
        float binv10 = -B2[0][1]/det, binv11 =  B2[0][0]/det;
        for (int j = 0; j < m; ++j) {
            const T* Arow = Aelt[j];
            float a0 = Arow[0];
            float a1 = Arow[1];
            Xelt[0][j] = binv00 * a0 + binv01 * a1;
            Xelt[1][j] = binv10 * a0 + binv11 * a1;
        }
        return X;
    }
}

Matrix Matrix::col3PseudoInverse(const Matrix& B) const {
    Matrix A = *this;
    int m = rows();
    int n = cols();

    Matrix3 B3 = B.toMatrix3(); 
    if (fuzzyEq(B3.determinant(), (T)0.0)) {

        // Matrix was singular; the block matrix pseudo-inverse can't
        // handle that, so fall back to the old case
        return svdPseudoInverse();

    } else {
        Matrix3 B3inv = B3.inverse();

        // Multiply by Binv * A'
        Matrix X(cols(), rows());

        T** Xelt = X.impl->elt;
        T** Aelt = A.impl->elt;
        for (int i = 0; i < n; ++i) {
            T* Xrow = Xelt[i];
            for (int j = 0; j < m; ++j) {
                const T* Arow = Aelt[j];
                T sum = 0;
                const float* Binvrow = B3inv[i];
                for (int k = 0; k < n; ++k) {
                    sum += Binvrow[k] * Arow[k];
                }
                Xrow[j] = sum;
            }
        }
        return X;
    }
}

Matrix Matrix::col4PseudoInverse(const Matrix& B) const {
    Matrix A = *this;
    int m = rows();
    int n = cols();

    Matrix4 B4 = B.toMatrix4(); 
    if (fuzzyEq(B4.determinant(), (T)0.0)) {

        // Matrix was singular; the block matrix pseudo-inverse can't
        // handle that, so fall back to the old case
        return svdPseudoInverse();

    } else {
        Matrix4 B4inv = B4.inverse();

        // Multiply by Binv * A'
        Matrix X(cols(), rows());

        T** Xelt = X.impl->elt;
        T** Aelt = A.impl->elt;
        for (int i = 0; i < n; ++i) {
            T* Xrow = Xelt[i];
            for (int j = 0; j < m; ++j) {
                const T* Arow = Aelt[j];
                T sum = 0;
                const float* Binvrow = B4inv[i];
                for (int k = 0; k < n; ++k) {
                    sum += Binvrow[k] * Arow[k];
                }
                Xrow[j] = sum;
            }
        }
        return X;
    }
}

Matrix Matrix::row2PseudoInverse(const Matrix& B) const {

    Matrix A = *this;
    int m = rows();
    int n = cols();
    (void)m;

    // Row-major 2x2 matrix
    const float B2[2][2] = 
       {{B.get(0,0), B.get(0,1)}, 
        {B.get(1,0), B.get(1,1)}};

    float det = (B2[0][0]*B2[1][1]) - (B2[0][1]*B2[1][0]);

    if (fuzzyEq(det, T(0))) {
        
        // Matrix was singular; the block matrix pseudo-inverse can't
        // handle that, so fall back to the old case
        return svdPseudoInverse();

    } else {
        // invert using formula at http://www.netsoc.tcd.ie/~jgilbert/maths_site/applets/algebra/matrix_inversion.html

        // Multiply by Binv * A'
        Matrix X(cols(), rows());

        T** Xelt = X.impl->elt;
        T** Aelt = A.impl->elt;
        float binv00 =  B2[1][1]/det, binv01 = -B2[1][0]/det;
        float binv10 = -B2[0][1]/det, binv11 =  B2[0][0]/det;
        for (int j = 0; j < n; ++j) {
            Xelt[j][0] = Aelt[0][j] * binv00 + Aelt[1][j] * binv10;
            Xelt[j][1] = Aelt[0][j] * binv01 + Aelt[1][j] * binv11;
        }
        return X;
    }
}

Matrix Matrix::row3PseudoInverse(const Matrix& B) const {

    Matrix A = *this;
    int m = rows();
    int n = cols();

    Matrix3 B3 = B.toMatrix3(); 
    if (fuzzyEq(B3.determinant(), (T)0.0)) {

        // Matrix was singular; the block matrix pseudo-inverse can't
        // handle that, so fall back to the old case
        return svdPseudoInverse();

    } else {
        Matrix3 B3inv = B3.inverse();

        // Multiply by Binv * A'
        Matrix X(cols(), rows());

        T** Xelt = X.impl->elt;
        T** Aelt = A.impl->elt;
        for (int i = 0; i < n; ++i) {
            T* Xrow = Xelt[i];
            for (int j = 0; j < m; ++j) {
                T sum = 0;
                for (int k = 0; k < m; ++k) {
                    sum += Aelt[k][i] * B3inv[j][k];
                }
                Xrow[j] = sum;
            }
        }
        return X;
    }
}

Matrix Matrix::row4PseudoInverse(const Matrix& B) const {

    Matrix A = *this;
    int m = rows();
    int n = cols();

    Matrix4 B4 = B.toMatrix4(); 
    if (fuzzyEq(B4.determinant(), (T)0.0)) {

        // Matrix was singular; the block matrix pseudo-inverse can't
        // handle that, so fall back to the old case
        return svdPseudoInverse();

    } else {
        Matrix4 B4inv = B4.inverse();

        // Multiply by Binv * A'
        Matrix X(cols(), rows());

        T** Xelt = X.impl->elt;
        T** Aelt = A.impl->elt;
        for (int i = 0; i < n; ++i) {
            T* Xrow = Xelt[i];
            for (int j = 0; j < m; ++j) {
                T sum = 0;
                for (int k = 0; k < m; ++k) {
                    sum += Aelt[k][i] * B4inv[j][k];
                }
                Xrow[j] = sum;
            }
        }
        return X;
    }
}

// Uses the block matrix pseudoinverse to compute the pseudoinverse of a full-rank mxn matrix with m >= n
// http://en.wikipedia.org/wiki/Block_matrix_pseudoinverse
Matrix Matrix::partitionPseudoInverse() const {

    // Logic:
    // A^-1 = (A'A)^-1 A'
    // A has few (n) columns, so A'A is small (n x n) and fast to invert
    
    int m = rows();
    int n = cols();

    if (m < n) {
        // TODO: optimize by pushing through the transpose
        //return transpose().partitionPseudoInverse().transpose();
        return rowPartPseudoInverse();

    } else {
        return colPartPseudoInverse();
    }
}

void Matrix::Impl::inverseInPlaceGaussJordan() {
    debugAssertM(R == C, 
        format(
        "Cannot perform Gauss-Jordan inverse on a non-square matrix."
        " (Argument was %dx%d)",
        R, C));

    // Exchange to float elements
#   define SWAP(x, y) {float temp = x; x = y; y = temp;}

    // The integer arrays pivot, rowIndex, and colIndex are
    // used for bookkeeping on the pivoting
    static Array<int> colIndex, rowIndex, pivot;

    int col = 0, row = 0;

    colIndex.resize(R);
    rowIndex.resize(R);
    pivot.resize(R);

    static const int NO_PIVOT = -1;

    // Initialize the pivot array to default values.
    for (int i = 0; i < R; ++i) {
        pivot[i] = NO_PIVOT;
    }

    // This is the main loop over the columns to be reduced
    // Loop over the columns.
    for (int c = 0; c < R; ++c) {

        // Find the largest element and use that as a pivot
        float largestMagnitude = 0.0;

        // This is the outer loop of the search for a pivot element
        for (int r = 0; r < R; ++r) {

            // Unless we've already found the pivot, keep going
            if (pivot[r] != 0) {

                // Find the largest pivot
                for (int k = 0; k < R; ++k) {
                    if (pivot[k] == NO_PIVOT) {
                        const float mag = fabs(elt[r][k]);

                        if (mag >= largestMagnitude) {
                            largestMagnitude = mag;
                            row = r; col = k;
                        }
                    }
                }
            }
        }

        pivot[col] += 1;

        // Interchange columns so that the pivot element is on the diagonal (we'll have to undo this
        // at the end)
        if (row != col) {
            for (int k = 0; k < R; ++k) {
                SWAP(elt[row][k], elt[col][k])
            }
        }

        // The pivot is now at [row, col]
        rowIndex[c] = row; 
        colIndex[c] = col;
    
        double piv = elt[col][col];

        debugAssertM(piv != 0.0, "Matrix is singular");

        // Divide everything by the pivot (avoid computing the division
        // multiple times).
        const double pivotInverse = 1.0 / piv;
        elt[col][col] = 1.0;

        for (int k = 0; k < R; ++k) {
			elt[col][k] *= Matrix::T(pivotInverse);
        }

        // Reduce all rows
        for (int r = 0; r < R; ++r) {
            // Skip over the pivot row
            if (r != col) {

                double oldValue = elt[r][col];
                elt[r][col] = 0.0;

                for (int k = 0; k < R; ++k) {
					elt[r][k] -= Matrix::T(elt[col][k] * oldValue);
                }
            }
        }
    }


    // Put the columns back in the correct locations
    for (int i = R - 1; i >= 0; --i) {
        if (rowIndex[i] != colIndex[i]) {
            for (int k = 0; k < R; ++k) {
                SWAP(elt[k][rowIndex[i]], elt[k][colIndex[i]]);
            }
        }
    } 
    
#   undef SWAP
}


bool Matrix::Impl::anyNonZero() const {
    int N = R * C;
    for (int i = 0; i < N; ++i) {
        if (data[i] != 0.0) {
            return true;
        }
    }
    return false;
}


bool Matrix::Impl::allNonZero() const {
    int N = R * C;
    for (int i = 0; i < N; ++i) {
        if (data[i] == 0.0) {
            return false;
        }
    }
    return true;
}


/** Helper for svdCore */ 
static double pythag(double a, double b) {
    
    double at = fabs(a), bt = fabs(b), ct, result;

    if (at > bt) { 
        ct = bt / at; 
        result = at * sqrt(1.0 + square(ct)); 
    } else if (bt > 0.0) { 
        ct = at / bt; 
        result = bt * sqrt(1.0 + square(ct)); 
    } else {
        result = 0.0;
    }

    return result;
}

#define SIGN(a, b) ((b) >= 0.0 ? fabs(a) : -fabs(a))

const char* Matrix::svdCore(float** U, int rows, int cols, float* D, float** V) {
    const int MAX_ITERATIONS = 30;

    int flag, i, its, j, jj, k, l = 0, nm = 0;
    double c, f, h, s, x, y, z;
    double anorm = 0.0, g = 0.0, scale = 0.0;

    // Temp row vector
    double* rv1;
  
    debugAssertM(rows >= cols, "Must have more rows than columns");
  
    rv1 = (double*)System::alignedMalloc(cols * sizeof(double), 16);
    debugAssert(rv1);

    // Householder reduction to bidiagonal form
    for (i = 0; i < cols; ++i) {
        
        // Left-hand reduction
        l = i + 1;
        rv1[i] = scale * g;
        g = s = scale = 0.0;
        
        if (i < rows) {

            for (k = i; k < rows; ++k) {
                scale += fabs((double)U[k][i]);
            }

            if (scale) {
                for (k = i; k < rows; ++k) {
                    U[k][i] = (float)((double)U[k][i]/scale);
                    s += ((double)U[k][i] * (double)U[k][i]);
                }

                f = (double)U[i][i];

                // TODO: what is this 2-arg sign function?
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                U[i][i] = (float)(f - g);
                
                if (i != cols - 1) {
                    for (j = l; j < cols; j++) {

                        for (s = 0.0, k = i; k < rows; ++k) {
                            s += ((double)U[k][i] * (double)U[k][j]);
                        }

                        f = s / h;
                        for (k = i; k < rows; ++k) {
                            U[k][j] += (float)(f * (double)U[k][i]);
                        }
                    }
                }
                for (k = i; k < rows; ++k) {
                    U[k][i] = (float)((double)U[k][i]*scale);
                }
            }
        }
        D[i] = (float)(scale * g);
    
        // right-hand reduction
        g = s = scale = 0.0;
        if (i < rows && i != cols - 1) {
            for (k = l; k < cols; ++k) {
                scale += fabs((double)U[i][k]);
            }

            if (scale) {
                for (k = l; k < cols; ++k) {
                    U[i][k] = (float)((double)U[i][k]/scale);
                    s += ((double)U[i][k] * (double)U[i][k]);
                }

                f = (double)U[i][l];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                U[i][l] = (float)(f - g);

                for (k = l; k < cols; ++k) {
                    rv1[k] = (double)U[i][k] / h;
                }

                if (i != rows - 1) {

                    for (j = l; j < rows; ++j) {
                        for (s = 0.0, k = l; k < cols; ++k) {
                            s += ((double)U[j][k] * (double)U[i][k]);
                        }

                        for (k = l; k < cols; ++k) { 
                            U[j][k] += (float)(s * rv1[k]);
                        }
                    }
                }

                for (k = l; k < cols; ++k) {
                    U[i][k] = (float)((double)U[i][k]*scale);
                }
            }
        }

        anorm = max(anorm, fabs((double)D[i]) + fabs(rv1[i]));
    }
  
    // accumulate the right-hand transformation
    for (i = cols - 1; i >= 0; --i) {
        if (i < cols - 1) {
            if (g) {
                for (j = l; j < cols; j++) {
                    V[j][i] = (float)(((double)U[i][j] / (double)U[i][l]) / g);
                }

                // double division to avoid underflow 
                for (j = l; j < cols; ++j) {
                    for (s = 0.0, k = l; k < cols; k++) {
                        s += ((double)U[i][k] * (double)V[k][j]);
                    }

                    for (k = l; k < cols; ++k) {
                        V[k][j] += (float)(s * (double)V[k][i]);
                    }
                }
            }

            for (j = l; j < cols; ++j) {
                V[i][j] = V[j][i] = 0.0;
            }
        }

        V[i][i] = 1.0;
        g = rv1[i];
        l = i;
    }
  
    // accumulate the left-hand transformation
    for (i = cols - 1; i >= 0; --i) {
        l = i + 1;
        g = (double)D[i];
        if (i < cols - 1) {
            for (j = l; j < cols; ++j) {
                U[i][j] = 0.0;
            }
        }

        if (g) {
            g = 1.0 / g;
            if (i != cols - 1) {
                for (j = l; j < cols; ++j) {
                    for (s = 0.0, k = l; k < rows; ++k) {
                        s += ((double)U[k][i] * (double)U[k][j]);
                    }

                    f = (s / (double)U[i][i]) * g;
                    
                    for (k = i; k < rows; ++k) {
                        U[k][j] += (float)(f * (double)U[k][i]);
                    }
                }
            }

            for (j = i; j < rows; ++j) {
                U[j][i] = (float)((double)U[j][i]*g);
            }
        
        } else {
            for (j = i; j < rows; ++j) {
                U[j][i] = 0.0;
            }
        }
        ++U[i][i];
    }

    // diagonalize the bidiagonal form
    for (k = cols - 1; k >= 0; --k) {
        // loop over singular values 
        for (its = 0; its < MAX_ITERATIONS; ++its) {
            // loop over allowed iterations
            flag = 1;
            
            for (l = k; l >= 0; --l) {
                // test for splitting 
                nm = l - 1;
                if (fabs(rv1[l]) + anorm == anorm) {
                    flag = 0;
                    break;
                }

                if (fabs((double)D[nm]) + anorm == anorm) {
                    break;
                }
            }

            if (flag) {
                c = 0.0;
                s = 1.0;
                for (i = l; i <= k; ++i) {
                    f = s * rv1[i];
                    if (fabs(f) + anorm != anorm) {
                        g = (double)D[i];
                        h = pythag(f, g);
                        D[i] = (float)h; 
                        h = 1.0 / h;
                        c = g * h;
                        s = (- f * h);
                        for (j = 0; j < rows; ++j) {
                            y = (double)U[j][nm];
                            z = (double)U[j][i];
                            U[j][nm] = (float)(y * c + z * s);
                            U[j][i] = (float)(z * c - y * s);
                        }
                    }
                }
            }

            z = (double)D[k];
            if (l == k) {
                // convergence
                if (z < 0.0) {
                    // make singular value nonnegative 
                    D[k] = (float)(-z);

                    for (j = 0; j < cols; ++j) {
                        V[j][k] = (-V[j][k]);
                    }
                }
                break;
            }

            if (its >= MAX_ITERATIONS) {
                free(rv1);
                rv1 = NULL;
                return "Failed to converge.";
            }
    
            // shift from bottom 2 x 2 minor
            x = (double)D[l];
            nm = k - 1;
            y = (double)D[nm];
            g = rv1[nm];
            h = rv1[k];
            f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
            g = pythag(f, 1.0);
            f = ((x - z) * (x + z) + h * ((y / (f + SIGN(g, f))) - h)) / x;
          
            // next QR transformation 
            c = s = 1.0;
            for (j = l; j <= nm; ++j) {
                i = j + 1;
                g = rv1[i];
                y = (double)D[i];
                h = s * g;
                g = c * g;
                z = pythag(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y = y * c;

                for (jj = 0; jj < cols; ++jj) {
                    x = (double)V[jj][j];
                    z = (double)V[jj][i];
                    V[jj][j] = (float)(x * c + z * s);
                    V[jj][i] = (float)(z * c - x * s);
                }
                z = pythag(f, h);
                D[j] = (float)z;
                if (z) {
                    z = 1.0 / z;
                    c = f * z;
                    s = h * z;
                }
                f = (c * g) + (s * y);
                x = (c * y) - (s * g);
                for (jj = 0; jj < rows; jj++) {
                    y = (double)U[jj][j];
                    z = (double)U[jj][i];
                    U[jj][j] = (float)(y * c + z * s);
                    U[jj][i] = (float)(z * c - y * s);
                }
            }
            rv1[l] = 0.0;
            rv1[k] = f;
            D[k] = (float)x;
        }
    }

    System::alignedFree(rv1);
    rv1 = NULL;

    return NULL;
}

#undef SIGN

}
