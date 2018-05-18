#include "ViewContext.h"
#include <cmath>

ViewContext::ViewContext(){
    transform = matrix::identity(4);
    invTransform = matrix::identity(4);
    invRotateTransform = matrix::identity(4);
    RotateTransform = matrix::identity(4);
    invTranslationTransform = matrix::identity(4);
    TranslationTransform = matrix::identity(4);
    invScaleTransform = matrix::identity(4);
    ScaleTransform = matrix::identity(4);

    
};

matrix ViewContext::applyTransform(matrix theMatrix){
    //std::cout << "transform" << std::endl;
    //std::cout << theMatrix << std::endl;
    //std::cout << transform << std::endl;
    transform = PerspectiveTransform(90,100,1) * ((TranslationTransform * RotateTransform) * ScaleTransform);
    return transform * theMatrix;
}

matrix ViewContext::applyInverse(matrix theMatrix){
    //std::cout << "inverse" << std::endl;
    //std::cout << theMatrix << std::endl;
    //std::cout << invTransform << std::endl;
    return invTransform * theMatrix;
}

void ViewContext::scale(double x, double y, double z){
    matrix newScale = matrix::identity(4);
    matrix newIvnScale = matrix::identity(4);

    newScale[0][0] = x;
    newScale[1][1] = y;
    newScale[2][2] = z;

    newIvnScale[0][0] = 1/x;
    newIvnScale[1][1] = 1/y;
    newIvnScale[2][2] = 1/z;

    ScaleTransform = newScale * ScaleTransform;
    invScaleTransform = invScaleTransform * newIvnScale;
}


void ViewContext::rotation(double roll, double pitch, double yaw){
    matrix newRoll(4,4);
    matrix newPitch(4,4);
    matrix newYaw(4,4);
    matrix newInvRoll(4,4);
    matrix newInvPitch(4,4);
    matrix newInvYaw(4,4);
    // rotate along z
    newYaw[0][0] = cos(yaw);
    newYaw[1][0] = -sin(yaw); 
    newYaw[0][1] = sin(yaw);
    newYaw[1][1] = cos(yaw);
    newYaw[2][2] = 1;
    newYaw[3][3] = 1;
    
    // rotate along x
    newRoll[0][0] = cos(roll);
    newRoll[2][0] = -sin(roll);
    newRoll[0][2] = sin(roll);
    newRoll[2][2] = cos(roll);
    newRoll[1][1] = 1;
    newRoll[3][3] = 1;

    // rotate along y
    newPitch[1][1] = cos(pitch);
    newPitch[2][1] = -sin(pitch);
    newPitch[1][2] = sin(pitch);
    newPitch[2][2] = cos(pitch);
    newPitch[0][0] = 1;
    newPitch[3][3] = 1;

    // rotate along z
    newInvYaw[0][0] = cos(-yaw);
    newInvYaw[1][0] = -sin(-yaw); 
    newInvYaw[0][1] = sin(-yaw);
    newInvYaw[1][1] = cos(-yaw);
    newInvYaw[2][2] = 1;
    newInvYaw[3][3] = 1;

    // rotate along x
    newInvRoll[0][0] = cos(-roll);
    newInvRoll[0][2] = -sin(-roll);
    newInvRoll[2][0] = sin(-roll);
    newInvRoll[2][2] = cos(-roll);
    newInvRoll[1][1] = 1;
    newInvRoll[3][3] = 1;

    // rotate along y
    newInvPitch[1][1] = cos(-pitch);
    newInvPitch[1][2] = -sin(-pitch);
    newInvPitch[2][1] = sin(-pitch);
    newInvPitch[2][2] = cos(-pitch);
    newInvPitch[0][0] = 1;
    newInvPitch[3][3] = 1;

    //std::cout << newRoll << std::endl << newPitch << std::endl << newYaw << std::endl;
    //std::cout << newInvRoll << std::endl << newInvPitch << std::endl << newInvYaw << std::endl;

    RotateTransform = newRoll * newPitch * newYaw * RotateTransform;
    invRotateTransform = invRotateTransform * newInvRoll * newInvPitch * newInvYaw;
}

void ViewContext::traslation(double x, double y, double z){
    matrix newTranslate = matrix::identity(4);
    matrix newInvTranslate = matrix::identity(4);
    newTranslate[0][3] = x;
    newTranslate[1][3] = y;
    newTranslate[2][3] = z;

    newInvTranslate[0][3] = -x;
    newInvTranslate[1][3] = -y;
    newInvTranslate[2][3] = -z;

    TranslationTransform = newTranslate * TranslationTransform;
    invTranslationTransform = invTranslationTransform * newInvTranslate;
}


matrix ViewContext::PerspectiveTransform(double angle, double far, double near){

    matrix PerspectiveTransform = matrix(4,4);

    PerspectiveTransform[0][0] = 1.0/tan(angle * 0.5 * M_PI /180);
    PerspectiveTransform[1][1] = 1.0/tan(angle * 0.5 * M_PI /180);
    PerspectiveTransform[2][2] = -far / (far - near);
    PerspectiveTransform[3][2] = -(far * near) / (far - near);
    PerspectiveTransform[3][3] = 1;
    return PerspectiveTransform;
}