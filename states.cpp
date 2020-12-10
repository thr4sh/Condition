#include "states.h"
#include "vend_machine.h"
void noquart_st::insertQuarter()  { cout << "A quarter has been inserted\n"; _sp->setCur(_sp->getHasQuartState()); }
void noquart_st::ejectQuarter()  { cout << "Insert a quarter first\n";}
void noquart_st::turnCranck(){ cout << "And nothing happened, because there's no quarter\n"; }
void noquart_st::dispense() { cout << "Dispensed nothing as there wasn't a quarter in a first place\n"; }

void hasquart_st::insertQuarter()  { cout << "YOu already inserted a quarter. This isnt gonna bring you more candy\n"; }
void hasquart_st::ejectQuarter()  { cout << "Now, you can only turn the cranck\n";}
void hasquart_st::turnCranck(){ cout  << "A cranck has been turned\n"; _sp->setCur(_sp->getSoldState());}
void hasquart_st::dispense() { cout << "Will be dispensing candy very soon, just after you turn the crank\n";}

void sold_st::insertQuarter()  { cout << "Wait for the candy to come out\n";}
void sold_st::ejectQuarter()  { cout << "Wait for the candy to come out\n"; }
void sold_st::turnCranck(){ cout <<  "Wait for the candy to come out\n"; }
void sold_st::dispense()
{
    cout << "The candy is rolling out\n";
    _sp->releaseBall();
    if(!_sp->getCount())
    {
        cout << "This was the last one btw\n";
        _sp->setCur(_sp->getSoldOutState());
    }
    else
        _sp->setCur(_sp->getNoQuartState());
}

void sold_out_st::insertQuarter()  {cout << "A quarter has been lost in a vending machine with no goods in it!\n";}
void sold_out_st::ejectQuarter()  { cout << "The machine igonres your attempts and will thereafter\n"; }
void sold_out_st::turnCranck() { cout << "Nothing happened\n";}
void sold_out_st::dispense() { cout << "Fill it with goods to dispense first\n"; }
