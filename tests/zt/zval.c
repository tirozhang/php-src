#include<stdio.h>

//zval
typedef struct _zval_struct zval;

//type
typedef unsigned char zend_uchar;
//obj
typedef struct _zend_object_value {
	zend_object_handle handle;
	zend_object_handlers *handlers;
} zend_object_value;

//val
typedef union _zvalue_value {
	long lval;					/* long value */
	double dval;				/* double value */
	struct {
		char *val;
		int len;
	} str;
	HashTable *ht;				/* hash table value */
	zend_object_value obj;
} zvalue_value;

struct _zval_struct {
	/* Variable information */
	zvalue_value value;		/* value */
	zend_uint refcount__gc;
	zend_uchar type;	/* active type */
	zend_uchar is_ref__gc;
};


