/* @(#) $Id: //bas/711_REL/src/include/sapdecf.h#1 $ SAP*/
/*-----------------------------------------------------------------------------
 *
 * (c) Copyright SAP AG, Walldorf 
 *
 * sapdecf.h - Global header file for basic decimal arithmetic.
 *
 * Maintainer: Ulrich Brink, Klaus Kretzschmar
 * Topic:      
 * Main File:  
 *
 *----------------------------------------------------------------------------*/

/*-------------------------------------------------------------------
 * This is a global header file for the definition of decimal
 * floating point types and functions operating on them.
 *
 * "saptype.h" must be included before this file. Do not assume
 * that anything else has been included before!
 *-------------------------------------------------------------------*/


/*-HISTORY---------------------------------------------------------------------
  * 06.09.2005 kkr  first implementation
 *----------------------------------------------------------------------------*/
/**
 @file sapdecf.h
 */


#ifndef SAPDECF_H
#define SAPDECF_H

/**
 *brief Error return codes.
 *The return codes are set to the value decNumber has 
*/
typedef enum { 
  /** decNumber shared library could not be loaded*/
  DECF_NOT_SUPPORTED = -2,
  /** decNumber shared library has wrong version */
  DECF_WRONG_VERSION = -1,
  /** no exception occurred */
  DECF_OK = 0,       
  /** an inexact exception occurred */
  DECF_INEXACT ,      
  /** an underflow exception occurred */
  DECF_UNDERFLOW ,    
  /** an overflow exception occurred */
  DECF_OVERFLOW ,     
  /** a conversion syntax exception occured */
  DECF_CONV_SYNTAX ,  
  /** a division by zero exception occurred */
  DECF_DIV_ZERO ,     
  /** an invalid operation exception occured */
  DECF_INVALID_OP ,
  /** a memory allocation error occured */
  DECF_NO_MEMORY     
} DECF_RETURN;



/**
 * \brief Rounding modes (IEEE 854 compliant).
 * Please compare with libDecimal.h before edit
*/
typedef enum { 
	/** round towards +infinity */ 
	DECF_ROUND_CEILING   = 0,     
	/** round away from 0 */ 
	DECF_ROUND_UP        = 1,   
	/** 0.5 rounds up */ 
	DECF_ROUND_HALF_UP   = 2,     
	/** 0.5 rounds to nearest even */ 
	DECF_ROUND_HALF_EVEN = 3,      
	/** 0.5 rounds down */ 
	DECF_ROUND_HALF_DOWN = 4,    
	/** round towards 0 (truncate) */ 
	DECF_ROUND_DOWN      = 5,  
	/** round towards -infinity */ 
	DECF_ROUND_FLOOR     = 6,      
	/** enum must be less than this */ 
	DECF_ROUND_MAX       = 7        
} DecFRounding;

#ifdef SAPwithINT_LITTLEENDIAN
/** Minimum (in the sense of total ordering) IEEE 754r value = -Infinity */
static const DecFloat16 DecFloat16NegInf = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8}};
/** Minimum (in the sense of total ordering) IEEE 754r value = -Infinity */
static const DecFloat34 DecFloat34NegInf = {{0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0xf8}};
#else
static const DecFloat16 DecFloat16NegInf = {{0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
static const DecFloat34 DecFloat34NegInf = {{0xf8, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
#endif /* SAPwithINT_LITTLEENDIAN */


BEGIN_externC
/* mutex lock and unlock */
void decf_mutex_lock(void);
void decf_mutex_unlock(void);

/* library initialization */

/** 
* \brief Decimal Floating Point Library Initialization 
*
* This function loads the decNumber shared library and
* initializes the global decimal floating point 
* environment. 
* 
* @return DECF_OK             --  Fine
* @return DECF_NOT_SUPPORTED  --  Shared library could not be loaded
* @return DECF_WRONG_VERSION  --  Shared library has wrong version (check dev-traces)
*/
DECF_RETURN InitDecFloatLib(void); 

/* DecFloat <-> String conversions */
/**
 * \brief Convert DecFloat16 into numeric String.
 * 
 * This function converts DecFloat16 number into a numeric string of type SAP_UC*.
 * The caller is responsible for the memory handling.
 * 
 * @param  numstr   A pointer to a SAP_UC buffer of type DecFloat16Buff.
 * @param  dfp16    A pointer to a 64-bit IEEE 754r variable
 * @return DECF_OK              -- Fine
 */
DECF_RETURN DecFloat16ToString(DecFloat16  dfp16, DecFloat16Buff* numstr);

/**
 * \brief Convert DecFloat34 into numeric String.
 * 
 * This function converts DecFloat34 number into a numeric string of type SAP_UC*.
 * The caller is responsible for the memory handling.
 * 
 * @param  numstr   A pointer to a SAP_UC buffer of type DecFloat16Buff.
 * @param  dfp34    A pointer to a 128-bit IEEE 754r variable
 * @return DECF_OK              -- Fine
 */
DECF_RETURN DecFloat34ToString(DecFloat34  dfp34, DecFloat34Buff* numstr);

/**
 * \brief Convert numeric String into Decfloat16.
 * 
 * This function converts a numeric string of type SAP_UC* into a Decfloat16 number.
 * The caller is responsible for the memory handling.
 * 
 * @param  numstr   A pointer to an array of SAP_UC* containing the numeric string.
 * @param  dfp16    A pointer to a 64-bit IEEE 754r variable
 * @return DECF_OK              -- Fine
 * @return DECF_OVERFLOW        -- Exponent too big
 * @return DECF_CONV_SYNTAX     -- Numeric string conatins non-numeric characters (f.g. spaces)
 * @return DECF_NO_MEMORY       -- A memoy allocation error occured       
 */
DECF_RETURN StringToDecFloat16(const SAP_UC* numstr, DecFloat16*  dfp16);

/**
 * \brief Convert numeric String into a Decfloat34 variable.
 * 
 * This function converts a numeric string of type SAP_UC* into a Decfloat34 number.
 * The caller is responsible for the memory handling.
 * 
 * @param  numstr   A pointer to an array of SAP_UC* containing the numeric string.
 * @param  dfp34    A pointer to a 128-bit IEEE 754r variable
 * @return DECF_OK              -- Fine
 * @return DECF_OVERFLOW        -- Exponent too big
 * @return DECF_CONV_SYNTAX     -- Numeric string conatins non-numeric characters (f.g. spaces)
 * @return DECF_NO_MEMORY       -- A memoy allocation error occured       
 */
DECF_RETURN StringToDecFloat34(const SAP_UC* numstr, DecFloat34*  dfp34); 

/* DecFloat <-> DecFloat conversion */
DECF_RETURN DecFloat16ToDecFloat34(DecFloat34*  dfp34_res, DecFloat16  dfp16);
DECF_RETURN DecFloat34ToDecFloat16(DecFloat16*  dfp16_res, DecFloat34  dfp34);

/* DecFloat <-> binary sortable DecFloat conversion */
/**
 * \brief Convert 64-bit IEEE 754r decimal floating point variable to 8 byte binary sortable format and store scale information.
 *
 * This function stores the normalized binary sortable format into a binary array of 8 bytes. 
 * The scale information is stored in a separate variable. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16raw_res A pointer to an array of 8 bytes.
 * @param scale        A pointer to a SAP_SHORT variable.
 * @param dfp16        A 64-bit IEEE 754r decimal floating point variable
 * @return DECF_OK         -- Fine 
 * @return DECF_INVALID_OP -- Some internal errors
 */
DECF_RETURN DecFloat16ToDecFloat16Raw(DecFloat16Raw* dfp16raw_res, SAP_SHORT* scale, DecFloat16  dfp16);

/**
 * \brief Convert 8 byte binary sortable format into 64-bit IEEE 754r decimal floating point variable.
 *
 * In order set the scale information of the IEEE 754r variable, this function needs 
 * additional information about the scale. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16_res    A pointer to a 64-bit IEEE 754r variable
 * @param dfp16raw     A 8-byte sortable decimal floating point variable
 * @param scale        A scale of the sortable decimal floating point variable.
 * 
 * @return DECF_OK         -- Fine 
 * @return DECF_NO_MEMORY  -- A memoy allocation error occured      
 * @return DECF_INVALID_OP -- Some internal errors
 */
DECF_RETURN DecFloat16RawToDecFloat16(DecFloat16*  dfp16_res, DecFloat16Raw dfp16raw, SAP_SHORT scale);

/**
 * \brief Convert 128-bit IEEE 754r decimal floating point variable to 16 byte binary sortable format and store scale information.
 *
 * This function stores the normalized binary sortable format into a binary array of 16 bytes. 
 * The scale information is stored in a separate variable. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16raw_res A pointer to an array of 16 bytes.
 * @param scale        A pointer to a SAP_SHORT variable.
 * @param dfp16        A 128-bit IEEE 754r decimal floating point variable
 * @return DECF_OK          -- Fine
 * @return DECF_NO_MEMORY   -- A memoy allocation error occured      
 * @return DECF_INVALID_OP  -- Some internal errors
 */
DECF_RETURN DecFloat34ToDecFloat34Raw(DecFloat34Raw* dfp34raw_res, SAP_SHORT* scale, DecFloat34  dfp34);

/**
 * \brief Convert 16 byte binary sortable format into 128-bit IEEE 754r decimal floating point variable.
 *
 * In order set the scale information of the IEEE 754r variable, this function needs 
 * additional information about the scale. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp34_res    A pointer to a 128-bit IEEE 754r variable
 * @param dfp34raw     A 8-byte sortable decimal floating point variable
 * @param scale        A scale of the sortable decimal floating point variable.
 * 
 * @return DECF_OK          -- Fine 
 * @return DECF_NO_MEMORY   -- A memoy allocation error occured    
 * @return DECF_INVALID_OP  -- Some internal errors
 */
DECF_RETURN DecFloat34RawToDecFloat34(DecFloat34*  dfp34_res, DecFloat34Raw dfp34raw, SAP_SHORT scale);


/**
 * \brief Convert 64-bit IEEE 754r decimal floating point variable to 8 byte binary sortable format and store scale information.
 *
 * This function stores the normalized binary sortable format into a binary array of 8 bytes. 
 * The scale information is stored in a separate variable. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16raw_res A pointer to an array of 8 bytes.
 * @param scale        A pointer to a SAP_SHORT variable.
 * @param dfp16        A 64-bit IEEE 754r decimal floating point variable
 * @return DECF_OK          -- Fine 
 * @return DECF_NO_MEMORY   -- A memoy allocation error occured    
 * @return DECF_INVALID_OP  -- Some internal errors
 */
DECF_RETURN DecFloat16ToDecFloat16RawDB(DecFloat16Raw* dfp16raw_res, SAP_SHORT* scale, DecFloat16  dfp16); 

/**
 * \brief Convert 8 byte binary sortable format into 64-bit IEEE 754r decimal floating point variable.
 *
 * In order set the scale information of the IEEE 754r variable, this function needs 
 * additional information about the scale. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16_res    A pointer to a 64-bit IEEE 754r variable
 * @param dfp16raw     A 8-byte sortable decimal floating point variable
 * @param scale        A scale of the sortable decimal floating point variable.
 * 
 * @return DECF_OK          -- Fine 
 * @return DECF_NO_MEMORY   -- A memoy allocation error occured    
 * @return DECF_INVALID_OP  -- Some internal errors
 */
DECF_RETURN DecFloat16RawToDecFloat16DB(DecFloat16*  dfp16_res, DecFloat16Raw dfp16raw, SAP_SHORT scale); 

/**
 * \brief Convert 128-bit IEEE 754r decimal floating point variable to 16 byte binary sortable format and store scale information.
 *
 * This function stores the normalized binary sortable format into a binary array of 16 bytes. 
 * The scale information is stored in a separate variable. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16raw_res A pointer to an array of 16 bytes.
 * @param scale        A pointer to a SAP_SHORT variable.
 * @param dfp16        A 128-bit IEEE 754r decimal floating point variable
 * @return DECF_OK         -- Fine 
 * @return DECF_NO_MEMORY  -- A memoy allocation error occured    
 * @return DECF_INVALID_OP -- Some internal errors
 */
DECF_RETURN DecFloat34ToDecFloat34RawDB(DecFloat34Raw* dfp34raw_res, SAP_SHORT* scale, DecFloat34  dfp34);

/**
 * \brief Convert 16 byte binary sortable format into 128-bit IEEE 754r decimal floating point variable.
 *
 * In order set the scale information of the IEEE 754r variable, this function needs 
 * additional information about the scale. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp34_res    A pointer to a 128-bit IEEE 754r variable
 * @param dfp34raw     A 8-byte sortable decimal floating point variable
 * @param scale        A scale of the sortable decimal floating point variable.
 * 
 * @return DECF_OK          -- Fine
 * @return DECF_NO_MEMORY   -- A memoy allocation error occured    
 * @return DECF_INVALID_OP  -- Some internal errors
 */
DECF_RETURN DecFloat34RawToDecFloat34DB(DecFloat34*  dfp34_res, DecFloat34Raw dfp34raw, SAP_SHORT scale); 

/**
 * \brief Convert 64-bit IEEE 754r decimal floating point variable to 8 byte binary sortable format without scale information.
 *
 * This function stores the normalized binary sortable format into a binary array of 8 bytes. 
 * The scale information of the original IEEE 754r type is not stored. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp16raw_res A pointer to an array of 8 bytes.
 * @param dfp16        A 64-bit IEEE 754r decimal floating point variable
 * @return DECF_OK         -- Fine 
 * @return DECF_INVALID_OP -- Some internal errors
 */
DECF_RETURN NormDecFloat16ToDecFloat16Raw(DecFloat16Raw* dfp16raw_res, DecFloat16  dfp16);

/**
 * \brief Convert 8 byte binary sortable format into 64-bit IEEE 754r decimal floating point variable.
 *
 * This conversion neglects scale information.
 * The caller is responsible for the memory handling.
 *
 * @param dfp16_res    A pointer to a 64-bit IEEE 754r variable
 * @param dfp16raw     A 8-byte sortable decimal floating point variable
 * 
 * @return DECF_OK         -- Fine 
 * @return DECF_NO_MEMORY  -- A memoy allocation error occured      
 * @return DECF_INVALID_OP -- Some internal errors
 */
DECF_RETURN DecFloat16RawToNormDecFloat16(DecFloat16*  dfp16_res, DecFloat16Raw dfp16raw);

/**
 * \brief Convert 128-bit IEEE 754r decimal floating point variable to 16 byte binary sortable format without scale information.
 *
 * This function stores the normalized binary sortable format into a binary array of 16 bytes. 
 * The scale information of the original IEEE 754r type is not stored. The caller is responsible for the 
 * memory handling.
 *
 * @param dfp34raw_res A pointer to an array of 16 bytes.
 * @param dfp34        A 128-bit IEEE 754r decimal floating point variable
 * @return DECF_OK         -- Fine 
 * @return DECF_INVALID_OP -- Some internal errors
 */
DECF_RETURN NormDecFloat34ToDecFloat34Raw(DecFloat34Raw* dfp34raw_res, DecFloat34  dfp34);

/**
 * \brief Convert 16 byte binary sortable format into 128-bit IEEE 754r decimal floating point variable.
 *
 * This conversion neglects scale information.
 * The caller is responsible for the memory handling.
 *
 * @param dfp34_res    A pointer to a 128-bit IEEE 754r variable
 * @param dfp34raw     A 8-byte sortable decimal floating point variable
 * 
 * @return DECF_OK          -- Fine 
 * @return DECF_NO_MEMORY   -- A memoy allocation error occured    
 * @return DECF_INVALID_OP  -- Some internal errors
 */
DECF_RETURN DecFloat34RawToNormDecFloat34(DecFloat34*  dfp34_res, DecFloat34Raw dfp34raw);

/* DecFloat <-> Integer conversion */
DECF_RETURN DecFloat16ToSAP_INT(SAP_INT* i, DecFloat16  dfp16);
DECF_RETURN SAP_INTToDecFloat16(DecFloat16*  dfp16_res, SAP_INT i);

DECF_RETURN DecFloat34ToSAP_INT(SAP_INT* i, DecFloat34  dfp34);
DECF_RETURN SAP_INTToDecFloat34(DecFloat34*  dfp34_res, SAP_INT i);

/* DecFloat <-> Double conversion */
DECF_RETURN DecFloat16ToSAP_DOUBLE(SAP_DOUBLE* d, DecFloat16  dfp16);
DECF_RETURN SAP_DOUBLEToDecFloat16(DecFloat16*  dfp16_res, SAP_DOUBLE i);

DECF_RETURN DecFloat34ToSAP_DOUBLE(SAP_DOUBLE* d, DecFloat34  dfp34);
DECF_RETURN SAP_DOUBLEToDecFloat34(DecFloat34*  dfp34_res, SAP_DOUBLE i);


/* DecFloat <-> BCD conversion */
/**
 * \brief Convert to ABAP type P (BCD).
 *
 * Convert a 64-bit IEEE 754r decimal floating point variable into the
 * ABAP type P. 
 *
 * INPUT:  
 * @param  dfp16        Decfloat value
 * @param  length       Length of BCD buffer in bytes
 * @param  decPlaces    Number of decimal places (Nachkommastellen) of the 
 *                      BCD number
 * OUTPUT: 
 * @param  bcd          Unaligned BCD number
 *
 * @return DECF_OK
 * @return DECF_INEXACT
 * @return DECF_UNDERFLOW  
 * @return DECF_OVERFLOW    Overflow. A higher level should raise a catchable 
 *                          exception.
 * @return DECF_NO_MEMORY   The caller should abort.
 * @return DECF_INVALID_OP  Garbage input. The caller should abort.
 */
DECF_RETURN  DecFloat16ToBCD(SAP_RAW* bcd_res, DecFloat16 dfp16, intR length, intR decPlaces);

/**
 * \brief Round IEEE value such that it fits into ABAP type P (BCD).
 *
 * Round a 64-bit IEEE 754r decimal floating point value according to
 * decPlaces and check that it fits into the BCD type specified.
 * When returning from this function, dfp16 has at most decPlaces
 * decimal places, but it may have less.
 *
 * INPUT:  
 * @param  length       Length of BCD buffer in bytes
 * @param  decPlaces    Number of decimal places (Nachkommastellen) of the 
 *                      BCD number
 * CHANGE: 
 * @param  dfp16        Decfloat value
 *
 * @return DECF_OK
 * @return DECF_INEXACT
 * @return DECF_UNDERFLOW  
 * @return DECF_OVERFLOW    Overflow. A higher level should raise a catchable 
 *                          exception.
 * @return DECF_NO_MEMORY   The caller should abort.
 * @return DECF_INVALID_OP  Garbage input. The caller should abort.
 */
DECF_RETURN  DecFloat16RoundForDEC(DecFloat16* dfp16, intR length, intR decPlaces);

/**
 * \brief Compare an IEEE value with a DF16_DEC value.
 *
 * This function rounds an IEEE value according the specified number of
 * decimal places (Nachkommastellen) and compares the result with 
 * another DecFloat value. (The latter is assumed to be a DF16_DEC
 * value which has already been rounded.)

 * INPUT:
 * @param  unroundedDf  IEEE decimal floating point value, will be rounded
 * @param  roundedDf    DF16_DEC value in IEEE decimal floating point format
 * @param  decPlaces    Number of decimal places (Nachkommastellen) of the 
 *                      DF16_DEC type
 * OUTPUT:
 * @param  p_rc         DECF_OK, DECF_INEXACT, DECF_UNDERFLOW: No special
 *                      action necessary;
 *                      DECF_NO_MEMORY: The caller should abort;
 *                      DECF_INVALID_OP: Garbage input, the caller should abort
 *
 * @return              -1 if rounded IEEE value <  roundedDf
 *                      0  if rounded IEEE value numerically equal to roundedDf
 *                      1  if rounded IEEE value >  roundedDf.
 *                      If p_rc is DECF_INVALID_OP,
 *                      the return value is guaranteed to be non-zero.
 */
SAP_INT DecFloat16CompareForDEC(DecFloat16 unroundedDf,
                                DecFloat16 roundedDf, 
                                intR decPlaces,
                                DECF_RETURN* p_rc);

/**
 * \brief Convert from ABAP type P (BCD) to 64-bit IEEE 754r
 *
 * Convert a BCD number (ABAP type P) into a 64-bit IEEE 754r decimal 
 * floating point variable.
 *
 * INPUT:  
 * @param  bcd          Unaligned BCD number
 * @param  length       Length of BCD number in bytes
 * @param  decPlaces    Number of decimal places of the BCD number
 *
 * OUTPUT:
 * @param  dfp16_res    Decfloat value
 *
 * @return DECF_OK
 * @return DECF_INEXACT
 * @return DECF_NO_MEMORY   The caller should abort.
 * @return DECF_INVALID_OP  Garbage input. The caller should abort.
 */
DECF_RETURN  BCDToDecFloat16(DecFloat16* dfp16_res, SAP_RAW*  bcd, intR length, intR decPlaces );


/**
 * \brief Convert to ABAP type P (BCD).
 *
 * Convert a 128-bit IEEE 754r decimal floating point variable into the
 * ABAP type P. 
 *
 * INPUT:  
 * @param  dfp34        Decfloat value
 * @param  length       Length of BCD buffer in bytes
 * @param  decPlaces    Number of decimal places (Nachkommastellen) of the 
 *                      BCD number
 * OUTPUT: 
 * @param  bcd          Unaligned BCD number
 *
 * @return DECF_OK
 * @return DECF_INEXACT
 * @return DECF_UNDERFLOW  
 * @return DECF_OVERFLOW    Overflow. A higher level should raise a catchable 
 *                          exception.
 * @return DECF_NO_MEMORY   The caller should abort.
 * @return DECF_INVALID_OP  Garbage input. The caller should abort.
 */
DECF_RETURN DecFloat34ToBCD(SAP_RAW* bcd_res, DecFloat34 dfp34, intR length, intR decPlaces);

/**
 * \brief Round IEEE value such that it fits into ABAP type P (BCD).
 *
 * Round a 128-bit IEEE 754r decimal floating point value according to
 * decPlaces and check that it fits into the BCD type specified.
 *
 * INPUT:  
 * @param  length       Length of BCD buffer in bytes
 * @param  decPlaces    Number of decimal places (Nachkommastellen) of the 
 *                      BCD number
 * CHANGE: 
 * @param  dfp34        Decfloat value
 *
 * @return DECF_OK
 * @return DECF_INEXACT
 * @return DECF_UNDERFLOW  
 * @return DECF_OVERFLOW    Overflow. A higher level should raise a catchable 
 *                          exception.
 * @return DECF_NO_MEMORY   The caller should abort.
 * @return DECF_INVALID_OP  Garbage input. The caller should abort.
 */
DECF_RETURN  DecFloat34RoundForDEC(DecFloat34* dfp34, intR length, intR decPlaces);

/**
 * \brief Compare an IEEE value with a DF34_DEC value.
 *
 * This function rounds an IEEE value according the specified number of
 * decimal places (Nachkommastellen) and compares the result with 
 * another DecFloat value. (The latter is assumed to be a DF34_DEC
 * value which has already been rounded.)

 * INPUT:
 * @param  unroundedDf  IEEE decimal floating point value, will be rounded
 * @param  roundedDf    DF34_DEC value in IEEE decimal floating point format
 * @param  decPlaces    Number of decimal places (Nachkommastellen) of the 
 *                      DF34_DEC type
 * OUTPUT:
 * @param  p_rc         DECF_OK, DECF_INEXACT, DECF_UNDERFLOW: No special
 *                      action necessary;
 *                      DECF_NO_MEMORY: The caller should abort;
 *                      DECF_INVALID_OP: Garbage input; the caller should abort
 *
 * @return              -1 if rounded IEEE value <  roundedDf
 *                      0  if rounded IEEE value numerically equal to roundedDf
 *                      1  if rounded IEEE value >  roundedDf.
 *                      If p_rc is DECF_OVERFLOW or DECF_INVALID_OP,
 *                      the return value is guaranteed to be non-zero.
 */
SAP_INT DecFloat34CompareForDEC(DecFloat34 unroundedDf,
                                DecFloat34 roundedDf, 
                                intR decPlaces,
                                DECF_RETURN* p_rc);

/**
 * \brief Convert from ABAP type P (BCD) to 128-bit IEEE 754r
 *
 * Convert a BCD number (ABAP type P) into a 128-bit IEEE 754r decimal 
 * floating point variable.
 *
 * INPUT:  
 * @param  bcd          Unaligned BCD number
 * @param  length       Length of BCD number in bytes
 * @param  decPlaces    Number of decimal places of the BCD number
 *
 * OUTPUT:
 * @param  dfp34_res    Decfloat value
 *
 * @return DECF_OK
 * @return DECF_NO_MEMORY   The caller should abort.
 * @return DECF_INVALID_OP  Garbage input. The caller should abort.
 */
DECF_RETURN BCDToDecFloat34(DecFloat34* dfp34_res, SAP_RAW* bcd, intR length, intR decPlaces );




/* Decfloat arithmetic operations */
/**
 * \brief Computes the sum of two DecFloat16 numbers. 
 * 
 * The number *dfp16_res is set to dfp16_lhs + dfp16_rhs. 
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16_lhs  Left-hand-site operand.
 * @param dfp16_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers. 
 */
DECF_RETURN DecFloat16_Add(DecFloat16* dfp16_res, DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs );

/**
 * \brief Computes the sum of two DecFloat34 numbers. 
 * 
 * The number *dfp34_res is set to dfp34_lhs + dfp34_rhs. 
 * @param dfp34_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp34_lhs  Left-hand-site operand.
 * @param dfp34_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers. 
 */
DECF_RETURN DecFloat34_Add(DecFloat34* dfp34_res, DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs );

/**
 * \brief Computes the difference of two DecFloat16 numbers. 
 * 
 * The number *dfp16_res is set to dfp16_lhs - dfp16_rhs. 
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16_lhs  Left-hand-site operand.
 * @param dfp16_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers. 
 */
DECF_RETURN DecFloat16_Sub(DecFloat16* dfp16_res, DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs );

/**
 * \brief Computes the difference of two DecFloat34 numbers. 
 * 
 * The number *dfp34_res is set to dfp34_lhs - dfp34_rhs. 
 * @param dfp34_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp34_lhs  Left-hand-site operand.
 * @param dfp34_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers. 
 */
DECF_RETURN DecFloat34_Sub(DecFloat34* dfp34_res, DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs );

/**
 * \brief Computes the multiplication of two DecFloat16 numbers. 
 * 
 * The number *dfp16_res is set to dfp16_lhs * dfp16_rhs. 
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16_lhs  Left-hand-site operand.
 * @param dfp16_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers. 
 */
DECF_RETURN DecFloat16_Mult(DecFloat16* dfp16_res, DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs );

/**
 * \brief Computes the division of two DecFloat34 numbers. 
 * 
 * The number *dfp34_res is set to dfp34_lhs / dfp34_rhs. 
 * @param dfp34_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp34_lhs  Left-hand-site operand.
 * @param dfp34_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers. 
 */
DECF_RETURN DecFloat34_Mult(DecFloat34* dfp34_res, DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs );

/**
 * \brief Computes the division of two DecFloat16 numbers. 
 * 
 * The number *dfp16_res is set to dfp16_lhs / dfp16_rhs. 
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16_lhs  Left-hand-site operand.
 * @param dfp16_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_DIV_ZERO -- Division by zero.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers or division is not defined (f.g. 0/0). 
 */
DECF_RETURN DecFloat16_Div(DecFloat16* dfp16_res, DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs );

/**
 * \brief Computes the division of two DecFloat34 numbers. 
 * 
 * The number *dfp34_res is set to dfp34_lhs / dfp34_rhs. 
 * @param dfp34_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp34_lhs  Left-hand-site operand.
 * @param dfp34_rhs  Right-hand-site operand.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_DIV_ZERO -- Division by zero.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers or division is not defined (f.g. 0/0). 
 */
DECF_RETURN DecFloat34_Div(DecFloat34* dfp34_res, DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs );

DECF_RETURN DecFloat16_DIV(DecFloat16* dfp16_res, DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs );
DECF_RETURN DecFloat34_DIV(DecFloat34* dfp34_res, DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs );

DECF_RETURN DecFloat16_MOD(DecFloat16* dfp16_res, DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs );
DECF_RETURN DecFloat34_MOD(DecFloat34* dfp34_res, DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs );


/* Relational and logical operations */
/* Op ==  */
/**
 * \brief Equality operation for DecFloat16 numbers.
 *
 * This function checks whether two DecFloat16 numbers 
 * are numerically equal, i.e. it is independent of the
 * scale of the numbers.
 *
 * @param  dfp16_lhs  Left-hand-site operand.
 * @param  dfp16_rhs  Right-hand-site operand.
 * @param  prc        Return code. Possible values: DECF_OK -- Fine, DECF_NO_MEMORY -- A memory allocation error occured,DECF_INVALID_OP -- Arguments are no-numbers .
 *
 * @return  TRUE,FALSE
 * 
 */
SAP_BOOL DecFloat16_EQ(DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs, DECF_RETURN* prc );

/**
 * \brief Equality operation for DecFloat34 numbers.
 *
 * This function checks whether two DecFloat34 numbers 
 * are numerically equal, i.e. it is independent of the
 * scale of the numbers.
 *
 * @param  dfp34_lhs  Left-hand-site operand.
 * @param  dfp34_rhs  Right-hand-site operand.
 * @param  prc        Return code. Possible values: DECF_OK -- Fine, DECF_NO_MEMORY -- A memory allocation error occured,DECF_INVALID_OP -- Arguments are no-numbers .
 *
 * @return  TRUE,FALSE
 * 
 */
SAP_BOOL DecFloat34_EQ(DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs, DECF_RETURN* prc  );

/* Op >  */
/**
 * \brief Relation�l ">" operation for DecFloat16 numbers.
 *
 * This function checks whether a DecFloat16 number
 * is numerically greater than another,  independent of the
 * scale of the numbers.
 *
 * @param  dfp16_lhs  Left-hand-site operand.
 * @param  dfp16_rhs  Right-hand-site operand.
 * @param  prc        Return code. Possible values: DECF_OK -- Fine, DECF_NO_MEMORY -- A memory allocation error occured,DECF_INVALID_OP -- Arguments are no-numbers .
 *
 * @return  TRUE,FALSE
 * 
 */
SAP_BOOL DecFloat16_GT(DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs, DECF_RETURN* prc );

/**
 * \brief Relation�l ">" operation for DecFloat34 numbers.
 *
 * This function checks whether a DecFloat34 number
 * is numerically greater than another,  independent of the
 * scale of the numbers.
 *
 * @param  dfp34_lhs  Left-hand-site operand.
 * @param  dfp34_rhs  Right-hand-site operand.
 * @param  prc        Return code. Possible values: DECF_OK -- Fine, DECF_NO_MEMORY -- A memory allocation error occured,DECF_INVALID_OP -- Arguments are no-numbers .
 *
 * @return  TRUE,FALSE
 * 
 */
SAP_BOOL DecFloat34_GT(DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs, DECF_RETURN* prc );

/* Op <  */
/**
 * \brief Relation�l "<" operation for DecFloat16 numbers.
 *
 * This function checks whether a DecFloat16 number
 * is numerically lower than another,  independent of the
 * scale of the numbers.
 *
 * @param  dfp16_lhs  Left-hand-site operand.
 * @param  dfp16_rhs  Right-hand-site operand.
 * @param  prc        Return code. Possible values: DECF_OK -- Fine, DECF_NO_MEMORY -- A memory allocation error occured,DECF_INVALID_OP -- Arguments are no-numbers .
 *
 * @return  TRUE,FALSE
 * 
 */
SAP_BOOL DecFloat16_LT(DecFloat16  dfp16_lhs, DecFloat16  dfp16_rhs, DECF_RETURN* prc );

/**
 * \brief Relation�l "<" operation for DecFloat34 numbers.
 *
 * This function checks whether a DecFloat34 number
 * is numerically lower than another,  independent of the
 * scale of the numbers.
 *
 * @param  dfp34_lhs  Left-hand-site operand.
 * @param  dfp34_rhs  Right-hand-site operand.
 * @param  prc        Return code. Possible values: DECF_OK -- Fine, DECF_NO_MEMORY -- A memory allocation error occured,DECF_INVALID_OP -- Arguments are no-numbers .
 *
 * @return  TRUE,FALSE
 * 
 */
SAP_BOOL DecFloat34_LT(DecFloat34  dfp34_lhs, DecFloat34  dfp34_rhs, DECF_RETURN* prc );

/**
 * \brief This function compares two DecFloat16 numbers numerically. 
 * 
 * if dfp16_lhs  < dfp16_rhs then the function returns -1.
 * 
 * if dfp16_lhs == dfp16_rhs then the function returns  0.
 * 
 * if dfp16_lhs > dfp16_rhs then the function returns  1.
 *
 * @param  dfp16_lhs  Left-hand-site operand.
 * @param  dfp16_rhs  Right-hand-site operand.
 *
 * @return -1,0,1
 */
SAP_INT DecFloat16Compare(DecFloat16 dfp16_lhs, DecFloat16 dfp16_rhs, DECF_RETURN* p_rc);

/**
 * \brief This function compares two DecFloat34 numbers numerically. 
 * 
 * if dfp34_lhs  < dfp34_rhs then the function returns -1.
 * 
 * if dfp34_lhs == dfp34_rhs then the function returns  0.
 * 
 * if dfp34_lhs > dfp34_rhs then the function returns  1.
 *
 * @param  dfp34_lhs  Left-hand-site operand.
 * @param  dfp34_rhs  Right-hand-site operand.
 *
 * @return -1,0,1
 */
SAP_INT DecFloat34Compare(DecFloat34 dfp34_lhs, DecFloat34 dfp34_rhs, DECF_RETURN* p_rc);

/* Rounding */
DECF_RETURN DecFloat16RoundDec(DecFloat16* dfp16, SAP_INT dec, DecFRounding decFRound);
DECF_RETURN DecFloat16RoundPrec(DecFloat16* dfp16, SAP_INT prec, DecFRounding decFRound);

DECF_RETURN DecFloat34RoundDec(DecFloat34* dfp34, SAP_INT dec, DecFRounding decFRound);
DECF_RETURN DecFloat34RoundPrec(DecFloat34* dfp34, SAP_INT prec, DecFRounding decFRound);

/* Rescaling */
DECF_RETURN DecFloat16RescaleDec(DecFloat16* dfp16, SAP_INT dec, DecFRounding decFRound);
DECF_RETURN DecFloat16RescalePrec(DecFloat16* dfp16, SAP_INT prec, DecFRounding decFRound);

DECF_RETURN DecFloat34RescaleDec(DecFloat34* dfp34, SAP_INT dec, DecFRounding decFRound);
DECF_RETURN DecFloat34RescalePrec(DecFloat34* dfp34, SAP_INT prec, DecFRounding decFRound);

/* Utility Functions */
SAP_BOOL DecFloat16IsInfinite(DecFloat16 dfp16);
SAP_BOOL DecFloat34IsInfinite(DecFloat34 dfp34);

SAP_BOOL DecFloat16IsFinite(DecFloat16 dfp16);
SAP_BOOL DecFloat34IsFinite(DecFloat34 dfp34);

SAP_BOOL DecFloat16IsNaN(DecFloat16 dfp16);
SAP_BOOL DecFloat34IsNaN(DecFloat34 dfp34);

DecFloat16* DecFloat16Zero(DecFloat16* dfp16);
DecFloat34* DecFloat34Zero(DecFloat34* dfp34);

DecFloat16 DecFloat16Ceil(DecFloat16 dfp16, DECF_RETURN* p_rc);
DecFloat34 DecFloat34Ceil(DecFloat34 dfp34, DECF_RETURN* p_rc); 

DecFloat16 DecFloat16Floor(DecFloat16 dfp16, DECF_RETURN* p_rc);
DecFloat34 DecFloat34Floor(DecFloat34 dfp34, DECF_RETURN* p_rc); 

/** /brief Minimum IEEE 754r value = -Infinity */
DecFloat16 GetMinDecFloat16(void);
/** /brief Minimum IEEE 754r value = -Infinity */
DecFloat34 GetMinDecFloat34(void);

DECF_RETURN DecFloat16GetExponent(SAP_INT* exponent, DecFloat16 dfp16);
DECF_RETURN DecFloat34GetExponent(SAP_INT* exponent, DecFloat34 dfp34);

DECF_RETURN DecFloat16GetNumOfDigits(SAP_INT* digits, DecFloat16 dfp16);
DECF_RETURN DecFloat34GetNumOfDigits(SAP_INT* digits, DecFloat34 dfp34);



/**
 * \brief Converts a DecFloat16 number into its preferred network byte order.
 *
 * The preferred neutral network byte order is Big-Endian. 
 * The caller is responsible for the memory handling
 * 
 * @param   dfp16_neutral A pointer to a DecFloat16 number where the result is written to.
 * @param   dfp16         The DecFloat16 number to be converted.
 *
 * @return  DECF_OK -- Fine.
 * 
 */
DECF_RETURN DecFloat16ToDecFloat16Neutral(DecFloat16* dfp16_neutral, DecFloat16 dfp16);

/**
 * \brief Converts a neutral DecFloat16 number into its machine-dependent encoding (big- or little-endian).
 *
 * The preferred neutral network byte order is Big-Endian. 
 * The caller is responsible for the memory handling
 * 
 * @param   dfp16                A pointer to a DecFloat16 number where the result is written to.
 * @param   dfp16_neutal         The neutral DecFloat16 number to be converted.
 *
 * @return  DECF_OK -- Fine.
 * 
 */
DECF_RETURN DecFloat16NeutralToDecFloat16(DecFloat16* dfp16, DecFloat16 dfp16_neutral);

/**
 * \brief Converts a DecFloat34 number into its preferred network byte order.
 *
 * The preferred neutral network byte order is Big-Endian. 
 * The caller is responsible for the memory handling
 * 
 * @param   dfp34_neutral A pointer to a DecFloat34 number where the result is written to.
 * @param   dfp34         The DecFloat34 number to be converted.
 *
 * @return  DECF_OK -- Fine.
 * 
 */
DECF_RETURN DecFloat34ToDecFloat34Neutral(DecFloat34* dfp34_neutral, DecFloat34 dfp34);

/**
 * \brief Converts a neutral DecFloat34 number into its machine-dependent encoding (big- or little-endian).
 *
 * The preferred neutral network byte order is Big-Endian. 
 * The caller is responsible for the memory handling
 * 
 * @param   dfp34                A pointer to a DecFloat34 number where the result is written to.
 * @param   dfp34_neutal         The neutral DecFloat34 number to be converted.
 *
 * @return  DECF_OK -- Fine.
 * 
 */
DECF_RETURN DecFloat34NeutralToDecFloat34(DecFloat34* dfp34, DecFloat34 dfp34_neutral);


/* Normalization functions */

/**
 * \brief In-place normalization of a DecFloat16 number.
 *
 * In-place normalization of a DecFloat16 number. Trailing zeros are removed.
 * The sign of zero is removed.
 * 
 * @param   dfp16 A pointer to a DecFloat16 number.
 *
 * @return  DECF_OK -- Fine.
 * @return  DECF_NO_MEMORY -- A memory allocation error occured.
 * @return  DECF_INVALID_OP -- Arguments are no-numbers . 
 * 
 */
DECF_RETURN DecFloat16Normalize(DecFloat16* dfp16);

/**
 * \brief In-place normalization of a DecFloat34 number.
 *
 * In-place normalization of a DecFloat16 number. Trailing zeros are removed.
 * responsible for the memory handling. 
 * 
 * @param   dfp34 A pointer to a DecFloat34 number.
 *0
 * @return  DECF_OK -- Fine.
 * @return  DECF_NO_MEMORY -- A memory allocation error occured.
 * @return  DECF_INVALID_OP -- Arguments are no-numbers . 
 * 
 */
DECF_RETURN DecFloat34Normalize(DecFloat34* dfp34);

/**
 * \brief Converts a DecFloat16 number to a normalized DecFloat16 number.
 *
 * The result is stored in norm_dfp16. The caller is responsible for the memory handling. 
 * Trailing zeros are removed. The sign of zero is removed.
 * 
 * @param   norm_dfp16 A pointer to a DecFloat16 number where the result is written to.
 * @param   dfp16      The DecFloat16 number to be normalized.
 *
 * @return  DECF_OK -- Fine.
 * @return  DECF_NO_MEMORY -- A memory allocation error occured.
 * @return  DECF_INVALID_OP -- Arguments are no-numbers . 
 * 
 */
DECF_RETURN DecFloat16ToNormDecFloat16(DecFloat16* norm_dfp16, DecFloat16 dfp16);

/**
 * \brief Converts a DecFloat34 number to a normalized DecFloat34 number.
 *
 * The result is stored in norm_dfp34. The caller is responsible for the memory handling. 
 * Trailing zeros are removed. The sign of zero is removed.
 * 
 * @param   norm_dfp34 A pointer to a DecFloat34 number where the result is written to.
 * @param   dfp34      The DecFloat34 number to be normalized.
 *
 * @return  DECF_OK -- Fine.
 * @return  DECF_NO_MEMORY -- A memory allocation error occured.
 * @return  DECF_INVALID_OP -- Arguments are no-numbers . 
 * 
 */
DECF_RETURN DecFloat34ToNormDecFloat34(DecFloat34* norm_dfp34, DecFloat34 dfp34);


/* Mathematical functions */

/**
 * \brief Returns the result of raising the base to the power of the exponent. 
 * 
 * The exponent must be a whole number, i.e. any digits in the fractional part of the
 * exponent must be zero.
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param base       Base of the power operation.
 * @param exponent   Exponent of the power operation
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers or exponent contains fractional digits. 
 */
DECF_RETURN DecFloat16_Pow(DecFloat16* dfp16_res, DecFloat16 base, SAP_INT exponent);

/**
 * \brief Returns the result of raising the base to the power of the exponent. 
 * 
 * The exponent must be a whole number, i.e. any digits in the fractional part of the
 * exponent must be zero.
 * @param dfp34_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param base       Base of the power operation.
 * @param exponent   Exponent of the power operation
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers or exponent contains fractional digits. 
 */
DECF_RETURN DecFloat34_Pow(DecFloat34* dfp34_res, DecFloat34 base, SAP_INT exponent);

/**
 * \brief Returns the result of raising the base to the power of the exponent. 
 * 
 * The exponent can be a fractional number.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param base       Base of the power operation.
 * @param exponent   Exponent of the power operation
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers or exponent contains fractional digits. 
 */
DECF_RETURN DecFloat16_fPow(DecFloat16* dfp16_res, DecFloat16 base, DecFloat16 exponent);

/**
 * \brief Returns the result of raising the base to the power of the exponent. 
 * 
 * The exponent can be a fractional number.
 *
 * @param dfp34_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param base       Base of the power operation.
 * @param exponent   Exponent of the power operation
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Arguments are no-numbers or exponent contains fractional digits. 
 */
DECF_RETURN DecFloat34_fPow(DecFloat34* dfp34_res, DecFloat34 base, DecFloat34 exponent);


/**
 * \brief Returns the square root of a DecFloat16. 
 * 
 * The number *dfp16_res is set to the square root of dfp16, rounded if necessary, to 
 * 16 digits using the DECF_ROUND_HALF_EVEN rounding mode.
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat16_Sqrt(DecFloat16* dfp16_res, DecFloat16 dfp16);

/**
 * \brief Returns the square root of a DecFloat34. 
 * 
 * The number *dfp34_res is set to the square root of dfp34, rounded if necessary, to 
 * 34 digits using the DECF_ROUND_HALF_EVEN rounding mode.
 * @param dfp16_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat34_Sqrt(DecFloat34* dfp34_res, DecFloat34 dfp34);

/**
 * \brief Exponential function for DecFloat16 numbers. 
 * 
 * The number is set to e raised to the power of rhs, rounded if necessary using 
 * the round�half�even rounding algorithm.
 *
 * Finite results will always be full precision and inexact, except when rhs is a zero or
 * �Infinity (giving 1 or 0 respectively). Inexact results will almost always be correctly
 * rounded, but may be up to 1 ulp (unit in last place) in error in rare cases.
 *
 * This is a mathematical function; the 10**6 restrictions on precision and range apply as
 * described above.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat16_Exp(DecFloat16* dfp16_res, DecFloat16 dfp16);

/**
 * \brief Exponential function for DecFloat34 numbers. 
 *
 * The number is set to e raised to the power of rhs, rounded if necessary using 
 * the round�half�even rounding algorithm.
 *
 * Finite results will always be full precision and inexact, except when rhs is a zero or
 * �Infinity (giving 1 or 0 respectively). Inexact results will almost always be correctly
 * rounded, but may be up to 1 ulp (unit in last place) in error in rare cases.
 *
 * This is a mathematical function; the 10**6 restrictions on precision and range apply as
 * described above.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat34_Exp(DecFloat34* dfp34_res, DecFloat34 dfp34);

/**
 * \brief Natural logarithm function for DecFloat16 numbers. 
 * 
 * The number is set to the natural logarithm (in base e) of rhs, rounded if necessary using 
 * the round�half�even rounding algorithm.
 *
 * Finite results will always be full precision and inexact, except when rhs is a zero or
 * �Infinity (giving 1 or 0 respectively). Inexact results will almost always be correctly
 * rounded, but may be up to 1 ulp (unit in last place) in error in rare cases.
 *
 * This is a mathematical function; the 10**6 restrictions on precision and range apply as
 * described above.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat16_Ln(DecFloat16* dfp16_res, DecFloat16 dfp16);

/**
 * \brief Natural logarithm function for DecFloat34 numbers. 
 *
 * The number is set to the natural logarithm (in base e) of rhs, rounded if necessary using 
 * the round�half�even rounding algorithm.
 *
 * Finite results will always be full precision and inexact, except when rhs is a zero or
 * �Infinity (giving 1 or 0 respectively). Inexact results will almost always be correctly
 * rounded, but may be up to 1 ulp (unit in last place) in error in rare cases.
 *
 * This is a mathematical function; the 10**6 restrictions on precision and range apply as
 * described above.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat34_Ln(DecFloat34* dfp34_res, DecFloat34 dfp16);


/**
 * \brief Logarithm in base 10 function for DecFloat16 numbers. 
 * 
 * The number is set to the logarithm in base 10 of rhs, rounded if necessary using 
 * the round�half�even rounding algorithm.
 *
 * Finite results will always be full precision and inexact, except when rhs is a zero or
 * �Infinity (giving 1 or 0 respectively). Inexact results will almost always be correctly
 * rounded, but may be up to 1 ulp (unit in last place) in error in rare cases.
 *
 * This is a mathematical function; the 10**6 restrictions on precision and range apply as
 * described above.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 64-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat16_Log10(DecFloat16* dfp16_res, DecFloat16 dfp16);

/**
 * \brief Logarithm in base 10 function for DecFloat34 numbers. 
 *
 * The number is set to the logarithm in base 10 of rhs, rounded if necessary using 
 * the round�half�even rounding algorithm.
 *
 * Finite results will always be full precision and inexact, except when rhs is a zero or
 * �Infinity (giving 1 or 0 respectively). Inexact results will almost always be correctly
 * rounded, but may be up to 1 ulp (unit in last place) in error in rare cases.
 *
 * This is a mathematical function; the 10**6 restrictions on precision and range apply as
 * described above.
 *
 * @param dfp16_res  Pointer to the IEEE 754r 128-bit variable where the result is stored.
 * @param dfp16      Argument value.
 * 
 * @return            DECF_OK -- Fine
 * @return            DECF_OVERFLOW -- Exponent of result too big.
 * @return            DECF_NO_MEMORY -- A memory allocation error occured.
 * @return            DECF_INVALID_OP -- Argument is no-number or negative. 
 */
DECF_RETURN DecFloat34_Log10(DecFloat34* dfp34_res, DecFloat34 dfp16);



END_externC
#endif /* DECFARITHM_H */
