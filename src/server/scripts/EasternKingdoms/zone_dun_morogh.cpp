/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"

enum FrozenMountaineer
{
    DATA_SET_ICE_BROKEN      = 1,
    EVENT_RUN_AWAY           = 1,
    SAY_MONSTEREMOTE         = 0,
    SPELL_SUMMON_FROZEN_TOMB = 77906,
    SPELL_FREEZE_ANIM        = 77910
};

/*######
# npc_frozen_mountaineer
######*/

class npc_frozen_mountaineer : public CreatureScript
{
public:
    npc_frozen_mountaineer() : CreatureScript("npc_frozen_mountaineer") { }

    struct npc_frozen_mountaineerAI : public ScriptedAI
    {
        npc_frozen_mountaineerAI(Creature* creature) : ScriptedAI(creature), _dataOneSet(false) { }

        void Reset() override
        {
            _events.Reset();
            DoCastSelf(SPELL_SUMMON_FROZEN_TOMB, true);
            DoCastSelf(SPELL_FREEZE_ANIM, true);
        }

        void SetData(uint32 /*type*/, uint32 data) override
        {
            if (data == DATA_SET_ICE_BROKEN && !_dataOneSet)
            {
                me->RemoveAllAuras();
                Talk(SAY_MONSTEREMOTE);
                _dataOneSet = true;
                _events.ScheduleEvent(EVENT_RUN_AWAY, Seconds(3));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_dataOneSet)
                return;

            _events.Update(diff);

            if (_events.ExecuteEvent() == EVENT_RUN_AWAY)
            {
                me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (std::cos(me->GetOrientation()) * 15.0f), me->GetPositionY() + (std::sin(me->GetOrientation()) * 15.0f), me->GetPositionZ());
                me->DespawnOrUnsummon(Seconds(2));
            }
        }
    private:
        EventMap _events;
        bool _dataOneSet;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frozen_mountaineerAI(creature);
    }
};

void AddSC_dun_morogh()
{
    new npc_frozen_mountaineer();
}
