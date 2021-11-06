#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
void porta_in_init() {
  // low-level code to
  // initialize port
  ANSELA = 0;
  TRISASET = 0x0F;


}
uint8_t porta_in_read() {
  // low-level code to
  // read port
  CNPUA = 0x1F;
  return 0&PORTA;
}