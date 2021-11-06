#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"
void portb_out_init() {
  // low-level code to
  // initialize port
  ANSELB = 0;
  TRISBCLR = 0xFFFF;
}
void portb_out_write(uint16_t val)
{
    uint16_t temp1, temp2, temp3, out;
  // low-level code to
  // write port
    temp1 = val & 0x003F;
    temp2 = val & 0x07E0;
    temp3 = val & 0x3800;
    temp2 = temp2 << 1;
    temp3 = temp3 << 2;
    out = temp3 | temp2 | temp1;  
    LATB = out;
}