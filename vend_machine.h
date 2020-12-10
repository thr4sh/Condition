#ifndef VEND_MACHINE_H
#define VEND_MACHINE_H
#include <memory>
#include "states.h"
class vend_machine
{
    int count = 0;
    shared_ptr<sold_st> _st_sold;
    shared_ptr<noquart_st> _st_noquart;
    shared_ptr<hasquart_st> _st_hasquart;
    shared_ptr<sold_out_st> _st_sold_out;

    state *cur;
public:
    vend_machine();
    void insertQuarter() {cur->insertQuarter();};
    void EjectQuarter() {cur->ejectQuarter();};
    void turnCrank() {cur->turnCranck();};

    void releaseBall() {if(count) count--;};

    state* getSoldState() {return _st_sold.get();}
    state* getSoldOutState(){return _st_sold_out.get();}
    state* getNoQuartState(){return _st_noquart.get();}
    state* getHasQuartState(){return _st_hasquart.get();}
    int getCount(){return count;}
    void setCur(state *s) {cur = s;}
};

#endif // VEND_MACHINE_H
