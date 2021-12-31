#include <stdio.h>
/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, Megan Allred
 * Summary:
 *    This class implements the components of Bell - LaPadula ************************************************************************/

#include <string>     // for convenience
#include <map>       // to store controls in
#include <iostream>   // standard input and output
#include <fstream>    // the messages are read from a file
#include <cassert>    // because I am paraniod
#include "control.h"  // all the Bell-LaPadula code

using namespace std;

/***********************************************
 * CONTROL :: DEFAULT CONSTRUCTOR
 *
 ***********************************************/
Control::Control() {
    //set the control types for the subjects
    subjectControlMap["AdmiralAbe"] = Secret;
    subjectControlMap["CaptainCharlie"] = Confidential;
    subjectControlMap["SeamanSam"] = Privileged;
    subjectControlMap["SeamanSue"] = Privileged;
    subjectControlMap["SeamanSly"] = Privileged;
    
    //set the control types for the assets
    assetControlsMap[100] = Confidential;
    assetControlsMap[101] = Public;
    assetControlsMap[102] = Confidential;
    assetControlsMap[103] = Public;
    assetControlsMap[104] = Public;
    assetControlsMap[105] = Confidential;
    assetControlsMap[106] = Secret;
    assetControlsMap[107] = Privileged;
    assetControlsMap[108] = Privileged;
    assetControlsMap[109] = Secret;
}

/***********************************************
 * CONTROL :: NON DEFAULT CONSTRUCTOR
 *
 ***********************************************/
Control::Control(string username, int id) {
    //set the control types for the subjects
    subjectControlMap["AdmiralAbe"] = Secret;
    subjectControlMap["CaptainCharlie"] = Confidential;
    subjectControlMap["SeamanSam"] = Privileged;
    subjectControlMap["SeamanSue"] = Privileged;
    subjectControlMap["SeamanSly"] = Privileged;
    
    //set the control types for the assets
    assetControlsMap[100] = Confidential;
    assetControlsMap[101] = Public;
    assetControlsMap[102] = Confidential;
    assetControlsMap[103] = Public;
    assetControlsMap[104] = Public;
    assetControlsMap[105] = Confidential;
    assetControlsMap[106] = Secret;
    assetControlsMap[107] = Privileged;
    assetControlsMap[108] = Privileged;
    assetControlsMap[109] = Secret;
    
    assetControl = setAssetControl(id);
    subjectControl = authenticate(username);
}
/***********************************************
 * CONTROL :: SETASSETCONTROL
 * returns the controltype for the given message id
 ***********************************************/
Control::ControlType Control::setAssetControl(int id){
   
    return assetControlsMap[id];

}


/***********************************************
 * CONTROL :: AUTHENTICATE
 * returns the control type for the given user
 ***********************************************/
Control::ControlType Control::authenticate(string username) {
    
    //iterate through the map to see if username is in it
    map<string, ControlType>:: iterator it;
    for (it = subjectControlMap.begin(); it != subjectControlMap.end(); it++) {
        if (it->first == username)
            return subjectControlMap[username];
    }
        
    //if username is not present set the control to public
    subjectControlMap[username] = Public;
    return subjectControlMap[username];
}


/***********************************************
 * CONTROL :: SECURITYCONDITIONREAD
 * returns true fi subject has ability to read the message file and false if not
 ***********************************************/
bool Control::securityConditionRead(ControlType assetControl, ControlType subjectControl) {
    return subjectControl >= assetControl;
}


/***********************************************
 * CONTROL  :: SECURITYCONDTIONSWRITE
 * returns true fi subject has ability to write to the message file and false if not
 ***********************************************/
bool Control::securityConditionWrite(ControlType assetControl, ControlType subjectControl){
    return subjectControl <= assetControl;
}

