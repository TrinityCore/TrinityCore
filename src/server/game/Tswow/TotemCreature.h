// @tswow-begin
#ifndef TSWOW_TOTEMCREATURE_H
#define TSWOW_TOTEMCREATURE_H

#include "TemporarySummon.h"

class TC_GAME_API TotemCreature : public Minion {
    public:
        TotemCreature(SummonPropertiesEntry const* properties, Unit* owner);
        void InitStats(uint32 lifetime);
        void Update(uint32 time);
        void SetupTotemStats();
};

#endif
// @tswow-end
