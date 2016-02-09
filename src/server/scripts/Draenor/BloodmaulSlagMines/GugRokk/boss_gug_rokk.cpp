#include "boss_gug_rokk.h"

struct boss_gug_rokkAI : public BossAI
{
    boss_gug_rokkAI(Creature *creature) : BossAI(creature, DATA_GUG_ROKK) { }
};

void AddSC_boss_gug_rokk()
{
    new BloodmaulSlagMinesAILoader<boss_gug_rokkAI>("boss_gug_rokk");
}
