#include "DepositSlot.h" //Definisi class DepositSlot 

//menunjukkan apakah amplop telah diterima (selalu mengembalikan nilai true,
//karena ini hanya simulasi perangkat lunak dari real deposit slot)
bool DepositSlot::isEnvelopeReceived() const
{
return true; //amplop deposit telah diterima
}
