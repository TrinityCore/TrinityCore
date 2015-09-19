#include "AzthPlayer.h"

AzthPlayer::AzthPlayer() {
    maxQuestRate = sConfigMgr->GetFloatDefault("Az.Rate.XP.Quest", 1.0f);
    customQuestRate = 1;
}

void AzthPlayer::setCustomQuestRate(float rate) {
    if (rate > maxQuestRate || rate < 1) {
        //TODO: print an error
        return;
    }

    customQuestRate = rate;
}

float AzthPlayer::getCustomQuestRate() {
    return customQuestRate >= 1 ? customQuestRate : 1;
}