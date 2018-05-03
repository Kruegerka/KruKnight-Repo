/** 
 * @Kruegerka
 * ViewContext.H
 */

#ifndef VIEWCONTEXT_H
#define VIEWCONTEXT_H
#include "matrix.h"

class ViewContext
{
    protected:
    matrix invTransform = matrix(4,4);
    matrix transform = matrix(4,4);

	public:
		ViewContext();

        /** 
         * @brief  Transforms the matrix with the given global transformation matrix
         * @param  theMatrix: matrix to transform
         * @retval transformed matrix
         */
        matrix applyTransform(matrix theMatrix);
        
        /** 
         * @brief  Transforms the matrix with the given global inverse transformation matrix
         * @param  theMatrix: matrix to transform
         * @retval transformed matrix
         */
        matrix applyInverse(matrix theMatrix);
        
        /** 
         * @brief  Addes the scale matrix to the global transformation matrixs
         * @param  x: scale factor
         * @param  y: scale factor
         * @param  z: scale factor
         * @retval None
         */
        void scale(double x, double y, double z);
        
        /** 
         * @brief  Addes the rotation matrix to the global transformatons matrixes
         * @param  roll: rotation factor
         * @param  pitch: rotation factor
         * @param  yaw: rotation factor
         * @retval None
         */
        void rotation(double roll, double pitch, double yaw);
        
        /** 
         * @brief  addes the translation matrix to the global transformation matrixes
         * @param  x: translation factor
         * @param  y: translation factor
         * @param  z: translation factor
         * @retval None
         */
        void traslation(double x, double y, double z);
		
};
#endif