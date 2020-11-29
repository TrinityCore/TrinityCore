// @tswow-begin
#ifndef TSWOW_TOTEMCREATURE_H
#define TSWOW_TOTEMCREATURE_H

#include "TemporarySummon.h"

class TC_GAME_API TotemCreature : public Minion {
    public:
        TotemCreature(SummonPropertiesEntry const* properties, Unit* owner);
};

#endif
// @tswow-end