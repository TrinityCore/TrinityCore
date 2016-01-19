#ifndef AZTHPLAYER_H
#define	AZTHPLAYER_H

#include "Config.h"

class AzthPlayer {
    public:
        explicit AzthPlayer();
        ~AzthPlayer();
        
        void setCustomQuestRate(float rate);
        float getCustomQuestRate();
    private:
        float customQuestRate,maxQuestRate;
};

#endif	/* AZTHPLAYER_H */

