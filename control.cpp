#include <stdio.h>
/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author: 
 *    Br. Helfrich, Sungjoon Ha
 * Summary:
 *    This class implements the components of Bell - LaPadula 
 * ************************************************************************/

#include <string>     // for convenience
#include <map>       // to store controls in
#include <iostream>   // standard input and output
#include <fstream>    // the messages are read from a file
#include <cassert>    // because I am paraniod
#include "control.h"  // all the Bell-LaPadula code

using namespace std;

/**********************************
 * Control
 * The Bell-LaPadula control levels
 * ********************************/
enum Control
{
    PUBLIC,         //nothing
    CONFIDENTIAL,   //limited security
    PRIVILEGED,     //can see most
    SECRET          //complete access
};

/**********************************
 * Control from text
 * Retrun a control ENUM from a control textual description
 * ********************************/
inline Control controlFromText(const std::string & code)
{
    if (code == std::string("Public"))
        return PUBLIC;
    if (code == std::string("Coonfidential"))
        return CONFIDENTIAL;
    if (code == std::string("Privileged"))
        return PRIVILEGED;
    else
        return SECRET;
}
/**********************************
 * Allow access read
 * ********************************/
inline bool allowAccessRead(const Control & controlIndividual, const Control & controlResource)
{
    return controlIndividual >= controlResource;
}


/**********************************
 * Allow access Write
 * ********************************/
inline bool allowAccessWrite(const Control & controlIndividual, const Control & controlResource)
{
    return controlIndividual <= controlResource;
}

// enum ControlType { Public, Confidential, Privileged, Secret};

// ControlType setAssetControls(int id) {
      
//       return assetControlsMap[id];
// }


// ControlType assetControl = setAssetControls(id);
// ControlType subjectControl = authenticate(username);

// ControlType authenticate(const string & username) {

//       //iterate through the map to see if username is in it
//       map<string, ControlType>:: iterator it;
//       for (it = subjectControlMap.begin(); it != subjectControlMap.end(); it++) {
//            if (it->first == username)
//                return subjectControlMap[username];
//       }
    
//       //if username is not present set the control to public
//       subjectControlMap[username] = Public;
//       return subjectControlMap[username];
// }

// // Bool securityConditionRead( ControlType assetControl, ControlType subjectControl) {
// // 	return subjectControl >= assetControl;
// // }


// // Bool securityConditionWrite( ControlType assetControl, ControlType subjectControl) {
// // 	return subjectControl <= assetControl;
// // }

// class Control {

// public:
//     enum ControlType {Public, Privileged, Confidential, Secret};
    
//     Control();
//     Control(string username, int id);
//     ControlType setAssetControl(int id);
//     ControlType authenticate(string username);
//     bool securityConditionRead(ControlType assetControl, ControlType subjectControl);
//     bool securityConditionWrite(ControlType assetControl, ControlType subjectControl);
    

    
//     string username;
//     ControlType assetControl;
//     ControlType subjectControl;
//     map <string, ControlType> subjectControlMap;
//     map <int, ControlType> assetControlsMap;
// };






// /***********************************************
//  * CONTROL :: DEFAULT CONSTRUCTOR
//  *
//  ***********************************************/
// Control::Control() {
//     //set the control types for the subjects
//     subjectControlMap["AdmiralAbe"] = Secret;
//     subjectControlMap["CaptainCharlie"] = Confidential;
//     subjectControlMap["SeamanSam"] = Privileged;
//     subjectControlMap["SeamanSue"] = Privileged;
//     subjectControlMap["SeamanSly"] = Privileged;
    
//     //set the control types for the assets
//     assetControlsMap[100] = Confidential;
//     assetControlsMap[101] = Public;
//     assetControlsMap[102] = Confidential;
//     assetControlsMap[103] = Public;
//     assetControlsMap[104] = Public;
//     assetControlsMap[105] = Confidential;
//     assetControlsMap[106] = Secret;
//     assetControlsMap[107] = Privileged;
//     assetControlsMap[108] = Privileged;
//     assetControlsMap[109] = Secret;
// }

// /***********************************************
//  * CONTROL :: NON DEFAULT CONSTRUCTOR
//  *
//  ***********************************************/
// Control::Control(string username, int id) {
//     //set the control types for the subjects
//     subjectControlMap["AdmiralAbe"] = Secret;
//     subjectControlMap["CaptainCharlie"] = Confidential;
//     subjectControlMap["SeamanSam"] = Privileged;
//     subjectControlMap["SeamanSue"] = Privileged;
//     subjectControlMap["SeamanSly"] = Privileged;
    
//     //set the control types for the assets
//     assetControlsMap[100] = Confidential;
//     assetControlsMap[101] = Public;
//     assetControlsMap[102] = Confidential;
//     assetControlsMap[103] = Public;
//     assetControlsMap[104] = Public;
//     assetControlsMap[105] = Confidential;
//     assetControlsMap[106] = Secret;
//     assetControlsMap[107] = Privileged;
//     assetControlsMap[108] = Privileged;
//     assetControlsMap[109] = Secret;
    
//     assetControl = setAssetControl(id);
//     subjectControl = authenticate(username);
// }
// /***********************************************
//  * CONTROL :: SETASSETCONTROL
//  * returns the controltype for the given message id
//  ***********************************************/
// Control::ControlType Control::setAssetControl(int id){
   
//     return assetControlsMap[id];

// }


// /***********************************************
//  * CONTROL :: AUTHENTICATE
//  * returns the control type for the given user
//  ***********************************************/
// Control::ControlType Control::authenticate(string username) {
    
//     //iterate through the map to see if username is in it
//     map<string, ControlType>:: iterator it;
//     for (it = subjectControlMap.begin(); it != subjectControlMap.end(); it++) {
//         if (it->first == username)
//             return subjectControlMap[username];
//     }
        
//     //if username is not present set the control to public
//     subjectControlMap[username] = Public;
//     return subjectControlMap[username];
// }


// /***********************************************
//  * CONTROL :: SECURITYCONDITIONREAD
//  * returns true fi subject has ability to read the message file and false if not
//  ***********************************************/
// bool Control::securityConditionRead(ControlType assetControl, ControlType subjectControl) {
//     return subjectControl >= assetControl;
// }


// /***********************************************
//  * CONTROL  :: SECURITYCONDTIONSWRITE
//  * returns true fi subject has ability to write to the message file and false if not
//  ***********************************************/
// bool Control::securityConditionWrite(ControlType assetControl, ControlType subjectControl){
//     return subjectControl <= assetControl;
// }

