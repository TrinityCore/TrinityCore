#include "Hw2Player.h"
#include "Hw2SystemMgr.h"
#include "Player.h"

Hw2Player::Hw2Player(Player *pl) {
    player = pl;
	RpgCredito=0; 
    RpgTotalePt=0; 
    RpgIdentity="Non definita"; 
    RpgEpigoni=0; 
    RpgPlGenere=0;
	Uccisioni=0; 
    Morti=0; 
    Suicidi=0; 
    Crediti=0; 
    Totale=0; 
    FrenzyCount=0; 
    Frenesia=false; 
    MusicaTimer=0;
	RpgSupervisor = 0;
}


bool Hw2Player::Hw2ClassSelHandler(uint16 scelta,uint32 varie)
{
	switch(scelta)
	{
		case 1:
			return sHw2->AzConf[varie];
		break;
		// aggiungere case per altre funzioni
	}
	return false;
}
