/** *********************************************************************** **
 ** Copyright (C) 1989-2013 Heinz van Saanen                                **
 **                                                                         **
 ** This file may be used under the terms of the GNU General Public         **
 ** License version 3 or later as published by the Free Software Foundation **
 ** and appearing in the file LICENSE.GPL included in the packaging of      **
 ** this file.                                                              **
 **                                                                         **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE **
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR        **
 ** PURPOSE.                                                                **
 **                                                                         **
 ** Verson: 1.0.4                                                           **
 ** *********************************************************************** **/

#ifndef _ATMSP_H_INCLUDED_
#define _ATMSP_H_INCLUDED_

/** Includes **/
#include <string>     // C++ strings
#include <csetjmp>    // longjump()
#include <cstdlib>    // strtod()
#include <cmath>      // Math. functions


/** *********************************************************************** **
 ** Determine maximum sizes for stack and var/val/num/con arrays.           **
 ** Note that sizes may have chache-effects e.g. Play here for tuning       **
 ** *********************************************************************** **/
#define ATMSP_SIZE 64                 // Stack, values-array and bytecode-operators
#define ATMSP_MAXNUM ATMSP_SIZE/4     // Numeric-array. Holds all numbers
#define ATMSP_MAXVAR ATMSP_SIZE/8     // Variables-array. Holds all variables
#define ATMSP_MAXCON ATMSP_SIZE/16    // Constants-array. Holds all constants


/** *********************************************************************** **
 ** Templatized stack, minimalistic version without STL overhead. Spare all **
 ** error checks as these are done in the parser anyhow                     **
 ** *********************************************************************** **/
template <typename T>
class ATMSP_STACK {

	T stack[ATMSP_SIZE];    // Stack grows from left (position 0) to right
	long sp;                // Stack-pointer (-1 for empty stack)

public:

	/// Constructor and clear
	ATMSP_STACK() : sp(-1) {}
	void clear() { sp = -1; }

	/// Usual push/pop operations
	void push(T const &elem) { stack[++sp] = elem; }
	T pop() { return stack[sp--]; }

	/// Get/set stack top without push-operation
	T top() { return stack[sp]; }
	void setTop(T const &elem) { stack[sp] = elem; }
};


/** *********************************************************************** **
 ** Templatized list, minimalistic version without STL overhead             **
 ** *********************************************************************** **/
template <typename T, size_t maxSize>
class ATMSP_LIST {

	size_t num;         // Current number of list objects
	T list[maxSize];    // Storage

public:

	/// Constructor, clear, size and array-operator
	ATMSP_LIST() : num(0) {}
	void clear() { num = 0; }
	size_t size() { return num; }
	T &operator [] (const size_t index) { return list[index]; }

	/// Add new list entry
	bool push(T const &elem) {
		if ( num < maxSize ) { list[num++] = elem; return true; }
		return false;
	}

	/// Search entry and set list index
	bool find(T const &elem, size_t &index) {
		for (size_t i=0; i<num; i++)
			if ( list[i] == elem ) { index = i; return true; }
		return false;
	}
};


/** *********************************************************************** **
 ** Bytecode struct. Executes the bytecode produced by the parser. Once     **
 ** the bytecode contains a valid set of instructions, it acts completely   **
 ** independent from the parser itself.                                     **
 ** *********************************************************************** **/
template <typename T>
struct ATMSB {

	/// Push num, var and con values onto the stack
	void ppush()  { stk.push(*val[valInd++]); }

	/// Most basic operators working for nearly any type. So int's, bignums, SSE2, ..
	void padd()   { T t(stk.pop()); stk.setTop(t+stk.top()); }
	void psub()   { T t(stk.pop()); stk.setTop(stk.top()-t); }
	void pmul()   { T t(stk.pop()); stk.setTop(t*stk.top()); }
	void pdiv()   { T t(stk.pop()); t!=(T)0 ? stk.setTop(stk.top()/t) : stk.setTop(T((fltErr=1)-1)); }
	void pchs()   { stk.setTop(-stk.top()); }

	#if !defined(COMPLEX) && !defined(MPFR)
	void pabs()   { stk.setTop(std::abs(stk.top())); }
	#else
	void pabs()   { stk.setTop(abs(stk.top())); }
	#endif

	#if !defined(COMPLEX)
	void psqrt()  { T t(stk.top()); t>=(T)0 ? stk.setTop(sqrt(t)) : stk.setTop(T((fltErr=1)-1)); }
	#else
	void psqrt()  { stk.setTop(sqrt(stk.top())); }
	#endif

	void ppow()   { T t(stk.pop()); stk.setTop(pow(stk.top(), t)); }
	void ppow2()  { stk.setTop(stk.top()*stk.top()); }
	void ppow3()  { stk.setTop(stk.top()*stk.top()*stk.top()); }
	void ppow4()  { stk.setTop((stk.top()*stk.top()) * (stk.top()*stk.top())); }

	/// Basic operators even working for compilers like MSVC
	void psin()   { stk.setTop(sin(stk.top())); }
	void pcos()   { stk.setTop(cos(stk.top())); }
	void ptan()   { stk.setTop(tan(stk.top())); }

	void psinh()  { stk.setTop(sinh(stk.top())); }
	void ptanh()  { stk.setTop(tanh(stk.top())); }
	void pcosh()  { stk.setTop(cosh(stk.top())); }

	void pexp()   { stk.setTop(exp(stk.top())); }
	void plog()   { stk.setTop(log(stk.top())); }
	void plog10() { stk.setTop(log10(stk.top())); }
	void plog2()  { stk.setTop(log10(stk.top())/log10((T)2)); }

	/// More basic operators, but not for complex
	#if !defined(COMPLEX)
	void pasin()  { T t(stk.top()); t>=(T)-1 && t<=(T)1 ? stk.setTop(asin(stk.top())) : stk.setTop(T((fltErr=1)-1)); }
	void pacos()  { T t(stk.top()); t>=(T)-1 && t<=(T)1 ? stk.setTop(acos(stk.top())) : stk.setTop(T((fltErr=1)-1)); }
	void patan()  { stk.setTop(atan(stk.top())); }
	void patan2() { T t(stk.pop()); stk.setTop(atan2(stk.top(), t)); }

	void pmax()   { T t(stk.pop()); if (t>stk.top()) stk.setTop(t); }
	void pmin()   { T t(stk.pop()); if (t<stk.top()) stk.setTop(t); }
	void psig()   { stk.top()>(T)0 ? stk.setTop((T)1) : stk.top()<(T)0 ? stk.setTop((T)-1) : stk.setTop((T)0); }

	void pfloor() { stk.setTop(floor(stk.top())); }
	void pround() { stk.setTop(floor(stk.top()+(T)0.5)); }
	#endif

	/// Indices, stack and pointers to functions for operating on bytecode
	size_t opCnt, valInd;
	ATMSP_STACK<T> stk;
	void (ATMSB<T>::*fun[ATMSP_SIZE])();

	/// All num, var and con values are consecutively mapped into the val-array.
	/// So in run() the bytecode operators work on the val-array only
	T *val[ATMSP_SIZE];
	T num[ATMSP_MAXNUM];
	T var[ATMSP_MAXVAR];
	T con[ATMSP_MAXCON];

	/// Catch NaN/inf-errors for x/0 et al. 0==success, 1 else
	size_t fltErr;

	/// Bytecode execution
	T run() {
		stk.clear(); valInd = fltErr = 0;
		for (size_t i=0; i<opCnt; i++) (*this.*fun[i])();
		return stk.top();
	}
};


/** *********************************************************************** **
 ** Parser class. Parses a string and generates the bytecode. For certain   **
 ** kind of strings ("x^2", ...) the bytecode is optimzed for speed.        **
 ** *********************************************************************** **/
template <typename T>
class ATMSP {

	/// Search-helper for constant list
	struct CONTYPE {
		std::string name;
		T val;

		CONTYPE() : val((T)0) {}
		CONTYPE(const std::string &n) : name(n), val((T)0) {}
		CONTYPE(const std::string &n, T v) : name(n), val(v) {}

		bool operator == (const CONTYPE &ct) { return name == ct.name; }
	};

	/// Recursive bytecode generation
	char *cp;                         // Character-pointer for parsing
	void expression(ATMSB<T> &bc);    // Handle expression as 1.st recursion level
	void term(ATMSB<T> &bc);          // Handle terms as 2.nd recursion level
	void factor(ATMSB<T> &bc);        // Handle factors as last recursion level

	/// Little helper functions
	bool isVar(const char *cp);       // Variable detection
	std::string skipAlphaNum();       // Variable/constant extraction

	/// Error handling and inits
	enum { noErr, funErr, varErr, conErr, parErr, memErr, nanErr };
	jmp_buf errJmp;                   // Buffer address for leaving recursions on error
	void init();                      // Init function, constant and error message lists

	/// Basic counters and indices
	size_t opCnt, varCnt, valInd, numInd, varInd, conInd, funInd;

	/// Lists. Note: 6/21 hardcoded here for not to waste any memory
	ATMSP_LIST<std::string, 6> errLst;               // Our 6 error messages
	ATMSP_LIST<std::string, 21> funLst;              // Our 21 recognized functions abs..tanh
	ATMSP_LIST<std::string, ATMSP_MAXVAR> varLst;    // Extracted variables from varString "x,y,.."
	ATMSP_LIST<CONTYPE, ATMSP_MAXCON> conLst;        // Our constants. $e and $pi are default

public:

	/// Constructor. Creates our lists funLst, conLst and errLst
	ATMSP() { init(); }

	/// Add constant to the parser. $pi and $e are yet default. $i for complex only
	/// Returns noErr==0 on success, error code else
	size_t addConstant(const std::string &name, T value) {
		return name[0]!='$' ? conErr : (conLst.push(CONTYPE(name, value)) ? noErr : memErr);
	}

	/// Parse and simultaneously generate bytecode
	/// Returns noErr==0 on success, error code else
	size_t parse(ATMSB<T> &bc, const std::string &exp, const std::string &vars);

	/// Message error-string for a specific error number
	const std::string errMessage(size_t errNum) { return errLst[errNum-1]; }
};


/** *********************************************************************** **
 ** Init/error handling and little helper functions                         **
 ** *********************************************************************** **/
template <typename T>
void ATMSP<T>::init() {

	// Default functions all/complex
	funLst.push("abs");  funLst.push("cos");  funLst.push("cosh");
	funLst.push("exp");  funLst.push("log");  funLst.push("log10");
	funLst.push("log2"); funLst.push("sin");  funLst.push("sinh");
	funLst.push("sqrt"); funLst.push("tan");  funLst.push("tanh");

	// Default functions all/cmath
	#if !defined(COMPLEX)
	funLst.push("asin");  funLst.push("acos");  funLst.push("atan");
	funLst.push("atan2"); funLst.push("max");   funLst.push("min");
	funLst.push("sig");   funLst.push("floor"); funLst.push("round");
	#endif

	// Default constants
	#if !defined(MPFR)
	conLst.push(CONTYPE("$e",  T(2.718281828459045235360287471353L)));
	conLst.push(CONTYPE("$pi", T(3.141592653589793238462643383279L)));
	#else
	conLst.push(CONTYPE("$e",  exp(T(1.0))));
	conLst.push(CONTYPE("$pi", T(4.0) * (T(4.0)*atan(T(1.0)/T(5.0)) - atan(T(1.0)/T(239.0)))));
	#endif
	#if defined(COMPLEX)
	conLst.push(CONTYPE("$i", T(0.0, 1.0)));
	#endif

	// Error messages. NaN/inf needed for expressions like "1/0"
	errLst.push("Function/expression error");
	errLst.push("Variable/expression error");
	errLst.push("Constant error");
	errLst.push("Parenthesis error");
	errLst.push("Out of memory error");
	errLst.push("NaN/inf float error");
}


// Variable detection. Check if string-part after cp signs a var or function
template <typename T>
bool ATMSP<T>::isVar(const char *cp) {
	char *tmp = (char *)cp;
	while ( isalnum(*tmp) && *tmp++ );
	return (*tmp == '(' ? false : true);
}


// Variable/constant extraction. Return alphanumeric-string and advance cp
template <typename T>
std::string ATMSP<T>::skipAlphaNum() {
	char *start = cp;
	std::string alphaString(cp++);
	while ( isalnum(*cp) && *cp++ );
	return alphaString.substr(0, cp-start);
}


/** *********************************************************************** **
 ** Core parser stuff                                                       **
 ** *********************************************************************** **/
template <typename T>
size_t ATMSP<T>::parse(ATMSB<T> &bc, const std::string &exps, const std::string &vars) {

	// First always force recursion break on errors
	size_t eLevel = noErr;
	if ( (eLevel=setjmp(errJmp)) != noErr ) return eLevel;

	// Prepare clean expression and variable strings
	std::string::size_type pos, lastPos;
	std::string es(exps), vs(vars);
	pos = 0; while ( (pos=es.find(' '), pos) != std::string::npos ) es.erase(pos, 1);
	pos = 0; while ( (pos=vs.find(' '), pos) != std::string::npos ) vs.erase(pos, 1);
	if ( es.empty() ) longjmp(errJmp, funErr);
	cp = (char *) es.c_str();

	// Split comma separated variables into varLst
	// One instance can be parsed repeatedly. So clear() is vital here
	varLst.clear();
	pos = vs.find_first_of(',', lastPos = vs.find_first_not_of(',', 0));
	while ( std::string::npos != pos || std::string::npos != lastPos ) {
		if ( !varLst.push(vs.substr(lastPos, pos-lastPos)) ) longjmp(errJmp, memErr);
		pos = vs.find_first_of(',', lastPos = vs.find_first_not_of(',', pos));
	}

	// Static parenthesis check. "Abuse" free opCnt/varCnt as open/close-counters
	opCnt = varCnt = 0;
	for (size_t i=0; i<es.size(); i++)
		if ( es[i] == '(' )
			opCnt++;
		else if ( es[i] == ')' ) {
			varCnt++;
			if ( varCnt > opCnt ) longjmp(errJmp, parErr);
		}
	if ( opCnt != varCnt ) longjmp(errJmp, parErr);

	// Reset all our counters and indices
	// opCnt  = Operator count. For bytecode and memory checks
	// varCnt = Variable count. For check if we have a constant expression
	// valInd = All num, var and con values are mapped into the bytecode-val-array
	// numInd = Numerical numbers array index
	opCnt = varCnt = valInd = numInd = 0;    

	// Run it once for parsing and generating the bytecode
	expression(bc);
	bc.opCnt = opCnt;

	// No vars in expression? Evaluate at compile time then
	if ( !varCnt ) {
		bc.num[0] = bc.run();
		if ( bc.fltErr ) longjmp(errJmp, nanErr);
		bc.val[0] = &bc.num[0];
		bc.fun[0] = &ATMSB<T>::ppush;
		bc.opCnt = 1;
	}

	return noErr;
}


template <typename T>
void ATMSP<T>::expression(ATMSB<T> &bc) {

	// Enter next recursion level
	term(bc);

	while ( *cp=='+' || *cp=='-' )
		if ( *cp++ == '+' ) {
			term(bc);
			bc.fun[opCnt++] = &ATMSB<T>::padd;
		}
		else {
			term(bc);
			bc.fun[opCnt++] = &ATMSB<T>::psub;
		}
}


template <typename T>
void ATMSP<T>::term(ATMSB<T> &bc) {

	// Enter next recursion level
	factor(bc);

	while ( *cp=='*' || *cp=='/' )
		if ( *cp++ == '*' ) {
			factor(bc);
			bc.fun[opCnt++] = &ATMSB<T>::pmul;
		}
		else {
			factor(bc);
			bc.fun[opCnt++] = &ATMSB<T>::pdiv;
		}
}


template <typename T>
void ATMSP<T>::factor(ATMSB<T> &bc) {

	/// Check available memory
	if ( numInd>=ATMSP_MAXNUM || valInd>=ATMSP_SIZE || opCnt>=ATMSP_SIZE ) longjmp(errJmp, memErr);

	/// Handle open parenthesis and unary operators first
	if ( *cp == '(' ) {
		++cp; expression(bc);
		if ( *cp++ != ')' ) longjmp(errJmp, parErr);
	}
	else if ( *cp == '+' ) {
		++cp; factor(bc);
	}
	else if ( *cp == '-' ) {
		++cp; factor(bc);
		bc.fun[opCnt++] = &ATMSB<T>::pchs;
	}

	/// Extract numbers starting with digit or dot
	else if ( isdigit(*cp) || *cp=='.' ) {
		char *end;
		bc.num[numInd] = (T)strtod(cp, &end);
		bc.val[valInd++] = &bc.num[numInd++];
		bc.fun[opCnt++] = &ATMSB<T>::ppush;
		cp = end;
	}

	/// Extract constants starting with $
	else if ( *cp == '$' ) {
		if ( !conLst.find(skipAlphaNum(), conInd) ) longjmp(errJmp, conErr);
		bc.con[conInd] = conLst[conInd].val;
		bc.val[valInd++] = &bc.con[conInd];
		bc.fun[opCnt++] = &ATMSB<T>::ppush;
	}

	/// Extract variables
	else if ( isVar(cp) ) {
		if ( varLst.find(skipAlphaNum(), varInd) ) varCnt++; else longjmp(errJmp, varErr);
		bc.val[valInd++] = &bc.var[varInd];
		bc.fun[opCnt++] = &ATMSB<T>::ppush;
	}

	/// Extract functions
	else {

		// Search function and advance cp behind open parenthesis
		if ( funLst.find(skipAlphaNum(), funInd) ) ++cp; else longjmp(errJmp, funErr);

		// Set operator function and advance cp
		switch ( funInd ) {
			case  0: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pabs;    break;
			case  1: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pcos;    break;
			case  2: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pcosh;   break;
			case  3: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pexp;    break;
			case  4: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::plog;    break;
			case  5: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::plog10;  break;
			case  6: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::plog2;   break;
			case  7: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::psin;    break;
			case  8: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::psinh;   break;
			case  9: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::psqrt;   break;
			case 10: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::ptan;    break;
			case 11: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::ptanh;   break;
			#if !defined(COMPLEX)
			case 12: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pasin;   break;
			case 13: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pacos;   break;
			case 14: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::patan;   break;
			case 15: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::patan2;  break;
			case 16: expression(bc); ++cp; expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pmax; break;
			case 17: expression(bc); ++cp; expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pmin; break;
			case 18: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::psig;    break;
			case 19: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pfloor;  break;
			case 20: expression(bc); bc.fun[opCnt++] = &ATMSB<T>::pround;  break;
			#endif
		}
		++cp;
	}

	/// At last handle univalent operators like ^ or % (not implemented here)
	if ( *cp == '^' ) {

		// Exponent a positive number? Try to optimize later
		bool optPow = isdigit( *++cp ) ? true : false;
		if ( *(cp+1) == '^' ) optPow = false;
		factor(bc);

		// Speed up bytecode for 2^2, x^3 ...
		if ( optPow ) {
			if ( *bc.val[valInd-1] == (T)2.0 ) {
				--valInd;
				bc.fun[opCnt-1] = &ATMSB<T>::ppow2;
			}
			else if ( *bc.val[valInd-1] == (T)3.0 ) {
				--valInd;
				bc.fun[opCnt-1] = &ATMSB<T>::ppow3;
			}
			else if ( *bc.val[valInd-1] == (T)4.0 ) {
				--valInd;
				bc.fun[opCnt-1] = &ATMSB<T>::ppow4;
			}
			// Exponent is a positive number, but not 2-4. Proceed with standard pow()
			else
				bc.fun[opCnt++] = &ATMSB<T>::ppow;
		}
		// Exponent is a not a number or negative. Proceed with standard pow()
		else
			bc.fun[opCnt++] = &ATMSB<T>::ppow;
	}

}

#endif    // _ATMSP_H_INCLUDED_
