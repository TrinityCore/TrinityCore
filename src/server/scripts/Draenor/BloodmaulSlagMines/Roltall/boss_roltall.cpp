#include "boss_roltall.h"

struct boss_roltallAI : public BossAI
{
    boss_roltallAI(Creature *creature) : BossAI(creature, DATA_ROLTALL) { }
};

void AddSC_boss_roltall()
{
    new BloodmaulSlagMinesAILoader<boss_roltallAI>("boss_roltall");
}
