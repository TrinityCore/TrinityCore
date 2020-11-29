// @tswow-begin
#ifndef TSWOW_TOTEMCREATURE_AI_H
#define TSWOW_TOTEMCREATURE_AI_H

#include "PetAI.h"

class TC_GAME_API TotemCreatureAI: public PetAI {
    public:
        static int32 Permissible(Creature const* creature);
        explicit TotemCreatureAI(Creature* creature);
        void OwnerAttacked(Unit* target) override;
};

#endif
// @tswow-end