//////////////////////////////////////////////////////////////////////
// File name : BasicFsmT.h
// Purpose : To define simple FSM implementation base class. 
//            This class to be inherited
//            by any class which would like to implement FSM
///////////////////////////////////////////////////////////////////////
#ifndef _BasicFsmT_h
#define _BasicFsmT_h

#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class BasicFsm
{
 public :
    BasicFsm(); // Default Constructor
    BasicFsm(string initialState);
    virtual ~BasicFsm();

    // StateMachine Method prototype
    typedef int (*pFsmMethodT) (BasicFsm* pFSM, string event, int info);

    virtual int AddState(string state);
    virtual int AddStateEventMethod(string state, string event, pFsmMethodT);
    virtual string GetState();

    virtual int Fsm(string event, int info);

    virtual int TransitionToState(string state);
    virtual int SetPreviousEvent(string event); 


 protected :

    vector<string> m_statesVec; // all valid states list in the  fsm
    vector<string> m_eventsVec; // all valid events list in the  fsm
    string m_fsmStateStr;      // current state of the state fsm
    string m_fsmPrevEventStr;  // the last event procesed by the fsm 
    string m_fsmPrevStateStr;  // the previous state of fsm 

    // the key is state and event strings concatanated together
     map<string, pFsmMethodT> m_stateEventToMethodMap;


};

#endif // _BasicFsmT_h
////////////// End File  : BasicFsmT.h  ///////////////////////////////
