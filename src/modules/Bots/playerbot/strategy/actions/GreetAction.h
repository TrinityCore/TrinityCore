#pragma once

#include "../Action.h"
#include "QuestAction.h"
#include "UseItemAction.h"

namespace ai
{
    class GreetAction : public Action
    {
    public:
        GreetAction(PlayerbotAI* ai);
        virtual bool Execute(Event event);
    };
}

namespace ai
{
   class ImbueWithPoisonAction : public Action
   {
   public:
      ImbueWithPoisonAction(PlayerbotAI* ai);
      virtual bool Execute(Event event);
   };
}

namespace ai
{
   class ImbueWithStoneAction : public Action
   {
   public:
      ImbueWithStoneAction(PlayerbotAI* ai);
      virtual bool Execute(Event event);
   };
}

namespace ai
{
   class ImbueWithOilAction : public Action
   {
   public:
      ImbueWithOilAction(PlayerbotAI* ai);
      virtual bool Execute(Event event);
   };
}

namespace ai
{
   class TryEmergencyAction : public Action
   {
   public:
      TryEmergencyAction(PlayerbotAI* ai);
      virtual bool Execute(Event event);
   };
}

static const uint32 uPriorizedHealingItemIds[19] =
{
    HEALTHSTONE_DISPLAYID, FEL_REGENERATION_POTION, SUPER_HEALING_POTION, CRYSTAL_HEALING_POTION, MAJOR_DREAMLESS_SLEEP_POTION, VOLATILE_HEALING_POTION,
    MAJOR_HEALING_POTION, WHIPPER_ROOT_TUBER, NIGHT_DRAGON_BREATH, LIMITED_INVULNERABILITY_POTION, GREATER_DREAMLESS_SLEEP_POTION,
    SUPERIOR_HEALING_POTION, CRYSTAL_RESTORE, DREAMLESS_SLEEP_POTION, GREATER_HEALING_POTION, HEALING_POTION, LESSER_HEALING_POTION, DISCOLORED_HEALING_POTION, MINOR_HEALING_POTION,
};
