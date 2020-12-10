#ifndef STATES_H
#define STATES_H
#include <memory>
#include <iostream>
using std::cout;
using std::shared_ptr;
class vend_machine;
class state
{
protected:
    shared_ptr<vend_machine> _sp;
public:
    state(shared_ptr<vend_machine> s) : _sp(std::move(s)) {}
    void virtual insertQuarter() = 0;
    void virtual ejectQuarter() = 0;
    void virtual turnCranck() = 0;
    void virtual dispense() = 0;
};

class sold_out_st : public state
{
public:
    void virtual insertQuarter()  ;
    void virtual ejectQuarter()  ;
    void virtual turnCranck();
    void virtual dispense() ;
};

class noquart_st : public state
{
public:
    void virtual insertQuarter()  ;
    void virtual ejectQuarter()  ;
    void virtual turnCranck();
    void virtual dispense() ;

};
class hasquart_st : public state
{
public:
    void virtual insertQuarter()  ;
    void virtual ejectQuarter()  ;
    void virtual turnCranck();
    void virtual dispense() ;
};

class sold_st : public state
{
public:
    void virtual insertQuarter()  ;
    void virtual ejectQuarter()  ;
    void virtual turnCranck();
    void virtual dispense() ;
};

#endif // STATES_H
