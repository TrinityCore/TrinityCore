/* 
 * File:   Hw2Player.h
 * Author: giuseppe
 *
 * Created on 6 agosto 2013, 13.23
 */

#ifndef HW2PLAYER_H
#define	HW2PLAYER_H

#include "Common.h"

class Player;

class Hw2Player {
    public:
        Hw2Player(Player *pl);
        ~Hw2Player();
        //personali
        Player *player;
		bool Frenesia,IsTourn;
		uint8 FrenzyCount,AccLvl[2];
	    uint32 Uccisioni,Morti,Suicidi,MusicaTimer;
		int32 Crediti,Totale;
		
		uint8 RpgPlGenere;
		int32 RpgCredito,RpgTotalePt,RpgEpigoni;
		uint64 RpgSupervisor;
		std::string RpgIdentity;
		
        
        bool Hw2ClassSelHandler(uint16 scelta,uint32 varia=0);
};

#endif	/* HW2PLAYER_H */

