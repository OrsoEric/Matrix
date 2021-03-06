/****************************************************************************
**	OrangeBot Project
*****************************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************************
**	Matrix
*****************************************************************************
**  Wrapper of vector for multidimensional vectors with nicer looking syntax
**	Added a few basic matrix opperations methods as plus
*****************************************************************************
**	Author: 			Orso Eric
**	Creation Date:
**	Last Edit Date:
**	Revision:			1
**	Version:			0.1 ALFA
****************************************************************************/

/****************************************************************************
**	HYSTORY VERSION
*****************************************************************************
**	V0.1 ALPHA
**		Wrapper works. Matrix works as intended
**		Matrix multiplication inplemented
**		cout show method implemented
****************************************************************************/

/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**	IDEA:
**	Add a lambda embedded iterator. You can pass a lambda function and apply
**	that to all elements.
****************************************************************************/

/****************************************************************************
**	KNOWN BUG
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	INCLUDES
****************************************************************************/

//C++ Standard libraries
#include <iostream>	//for I/O
#include <fstream>	//for file I/O
#include <vector>
//Include user log trace
//#include "debug.h"
//Class Header
#include "matrix.h"

/****************************************************************************
**	NAMESPACES
****************************************************************************/

//Never use a whole namespace. Use only what you need from it.
using std::cout;
using std::cerr;
using std::endl;
using std::fstream;
using std::vector;

//Namespace in which class methods are stored
namespace User
{

/****************************************************************************
**	GLOBAL VARIABILE
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	CONSTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Constructor
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

template <class T>
Matrix<T>::Matrix( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("address: %p\n", (void *)this );

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//initialize structure
	this -> init();

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Trace Return
	DRETURN();

	return;
}	//end constructor: Matrix | void

/****************************************************************************
**	Initialized Constructor
**	Matrix | unsigned int, unsigned int
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

template <class T>
Matrix<T>::Matrix( unsigned int rows, unsigned int cols )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("address: %p, rows: %d, cols: %d\n", (void *)this, rows, cols );

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//save matrix size
	this -> g_rows = rows;
	this -> g_cols = cols;
	//Create the matrix
	g_data = vector<T>(rows *cols);

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Trace Return
	DRETURN();

	return;
}	//end constructor: Matrix | unsigned int, unsigned int

/****************************************************************************
**	Initialized Constructor
**	Matrix | unsigned int, unsigned int, T
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Initialize matrix and content
****************************************************************************/

template <class T>
Matrix<T>::Matrix( unsigned int rows, unsigned int cols, T init_value )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("address: %p, rows: %d, cols: %d, init value\n", (void *)this, rows, cols );

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//save matrix size
	this -> g_rows = rows;
	this -> g_cols = cols;
	//Create the matrix
	g_data = vector<T>(rows *cols, init_value);

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Trace Return
	DRETURN();

	return;
}	//end constructor: Matrix | unsigned int, unsigned int

/****************************************************************************
*****************************************************************************
**	DESTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Destructor
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

template <class T>
Matrix<T>::~Matrix( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("address: %p\n", (void *)this );

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Trace Return
	DRETURN();

	return;
}	//end default destructor

/****************************************************************************
*****************************************************************************
**	OPERATORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Reference Operator
**	at | unsigned int rows, unsigned int col
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	access to an element of the array.
**	fast method with no checks
****************************************************************************/

template <class T>
inline T &Matrix<T>::at( unsigned int row, unsigned int col )
{
	///--------------------------------------------------------------------------
	/// RETURN
	///--------------------------------------------------------------------------

	//Return reference to the right element
	return this -> g_data[ row *this ->g_cols +col];
}	//end method: at | unsigned int rows, unsigned int col

/****************************************************************************
**	Unary operator
**	operator = | const User::Matrix<T> &
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

template <class T>
void Matrix<T>::operator = ( const User::Matrix<T> &source )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("source: %p, dest: %p\n", (void *)&source, (void *)this);

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//copy over size
	this -> g_rows = source.g_rows;
	this -> g_cols = source.g_cols;
	//copy over content
	this -> g_data = source.g_data;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();
	return;
}	//end method: operator = | const User::Matrix<T> &

/****************************************************************************
**	Binary Operator
**	operator* | User::Matrix<T> &
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Overload multiplication operator. Execute matrix multiplication
****************************************************************************/

template <class T>
User::Matrix<T> Matrix<T>::operator * (User::Matrix<T> &source )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//counters
	unsigned int t, ti, tii;
	//Accumulator
	T acc;
	//Return matrix
	Matrix<T> ret;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("left operand: %p, right operand: %p\n", (void *)this, (void *)&source);

	//if: columns of left members is different from rows of right member
	if (this -> g_cols != source.g_rows)
	{
		//Trace Return from main
		DRETURN_ARG("ERR: inconsistend size of input matricies. LeftC:%d RightR: %d\n", this -> g_cols, source.g_rows);
		return ret;	//Fail. Return empty matrix
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//return matrix is size row of left member by col of right member
	ret = Matrix<T>( this -> g_rows, source.g_cols );

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	Y(r, c) = SUM(k){ L(r, k) *R(k, c) }

	//for: every row of left member
	for (t = 0;t < this -> g_rows;t++)
	{
		//for: every col of right member
		for (ti = 0;ti < source.g_cols;ti++)
		{
			//reset accumulator
			acc = (this -> at(t, 0)) * source.at(0, ti);
			//for: every col of left member | every row of right member
			for (tii = 1;tii < this -> g_cols;tii++)
			{
				//accumulate product row*col
				acc += (this -> at(t, tii)) * source.at(tii, ti);
			}
			//write back content of accumulator
			ret.at( t, ti ) = acc;
		}	//end for: every row of left member
	}	//end for: every row of left member

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN_ARG("dimensions of result | R: %d C: %d\n", ret.g_rows, ret.g_cols );

	return ret;	//OK
}	//end method: operator* | User::Matrix<T> &

/****************************************************************************
*****************************************************************************
**	SETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	GETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	TESTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Tester
**	is_valid | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	check whatever the Matrix is valid (not empty and dimensions consistent
****************************************************************************/

template <class T>
bool Matrix<T>::is_invalid( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	//if: Matrix is empty
	if ( (this -> g_rows == 0) || (this -> g_cols == 0) || (this -> g_data.empty() == true) )
	{
		DRETURN_ARG("ERR: Matrix is empty. R: %d, C: %d, vector size: %d\n", this -> g_rows, this -> g_cols, this -> g_data.size() );
		return true; //Fail
	}

	//if: matrix is inconsistent
	if ( this -> g_rows *this -> g_cols != this -> g_data.size())
	{
		DRETURN_ARG("ERR: inchoerent sizes. R*C: %d vector size: %d\n", this -> g_rows *this -> g_cols, this -> g_data.size());
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN_ARG("valid\n");

	return false;	//OK
}	//end method:


/****************************************************************************
**	Public Tester
**	is_valid | unsigned int rows, unsigned int col
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	check whatever the coordinates are in bound
****************************************************************************/

template <class T>
bool Matrix<T>::is_invalid( unsigned int row, unsigned int col )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("r: %d, c: %d\n", row, col );

	//if: indexes are out of bound
	if ((row >= this -> g_rows) || (col >= this -> g_cols))
	{
		DRETURN_ARG("ERR: Out of bound indexes. r: %d, c: %d, R: %d, C: %d\n", row, col, this -> g_rows, this -> g_cols);
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN_ARG("valid indexes\n");

	return false;	//OK
}	//end method:

/****************************************************************************
*****************************************************************************
**	PUBLIC METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Method
**	show | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	show content of matrix
****************************************************************************/

template <class T>
bool Matrix<T>::show( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//counters
	unsigned int t, ti;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("address: %p\n", (void *)this);
	//if: invalid
	if (is_invalid() == true)
	{
		DRETURN_ARG("ERR: invalid matrix\n");
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//print dimensions
	cout << "address: " << this << " rows: " << this -> g_rows << " cols: " << this -> g_cols << "\n";

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//for: every row
	for (t = 0;t < this -> g_rows;t++)
	{
		//for: every col
		for (ti = 0;ti < this -> g_cols;ti++)
		{
			cout << this -> at( t, ti ) << ",";
		}	//end for: every col
		cout << "\n";
	}	//end for: every row

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return false;	//OK
}	//end method: show | void

/****************************************************************************
*****************************************************************************
**	PRIVATE METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Method
**	init | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	initialize Matrix structure
****************************************************************************/

template <class T>
bool Matrix<T>::init( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Size of the matrix
	this -> g_rows = 0;
	this -> g_cols = 0;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end method: init | void

/****************************************************************************
**	Public Method
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

template <class T>
bool Matrix<T>::dummy( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	if (false)
	{
		std::cerr << __FUNCTION__ << ":\n";
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return false;	//OK
}	//end method:

/****************************************************************************
*****************************************************************************
**	TEMPLATE TYPES
*****************************************************************************
**	This is a quirk of the C++ language. You can't separate .h and .cpp
**	unless you specify each type might be used in the .cpp.
**	The compilers create one version for each specialization you put here.
**	The alternative is to specialize each method by themselves
*****************************************************************************
****************************************************************************/

template class Matrix<double>;
template class Matrix<float>;
template class Matrix<char>;
template class Matrix<int>;

/****************************************************************************
**	NAMESPACES
****************************************************************************/

} //End Namespace
