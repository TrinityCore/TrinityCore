#include "AzthPlayer.h"

AzthPlayer::AzthPlayer() {
    maxQuestRate = sConfigMgr->GetFloatDefault("Az.Rate.XP.Quest", 1.0f);
}

void AzthPlayer::setCustomQuestRate(float rate) {
    if (rate > maxQuestRate) {
        //TODO: print an error
        return;
    }

    customQuestRate = rate;
}

float AzthPlayer::getCustomQuestRate() {
    return customQuestRate;
}