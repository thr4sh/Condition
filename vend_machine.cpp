#include "vend_machine.h"
using std::make_shared;
vend_machine::vend_machine()
{
    count= 10;
    _st_hasquart = std::make_shared(hasquart_st());
    _st_noquart;
    _st_sold;
    _st_sold_out;
    cur = _st_hasquart.get();
}
