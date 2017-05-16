/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Nerubenkan
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_ENCASINGWEBS          = 4962,
    SPELL_PIERCEARMOR           = 6016,
    SPELL_CRYPT_SCARABS         = 31602,
    SPELL_RAISEUNDEADSCARAB     = 17235
};

enum NerubenkanEvents
{
    EVENT_ENCASINGWEBS          = 1,
    EVENT_PIERCEARMOR           = 2,
    EVENT_CRYPT_SCARABS         = 3,
    EVENT_RAISEUNDEADSCARAB     = 4,
};
enum NerubenkanCreatures
{
    NPC_UNDEAD_SCARAB           = 10876
};

class boss_nerubenkan : public CreatureScript
{
public:
    boss_nerubenkan() : CreatureScript("boss_nerubenkan") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_nerubenkanAI>(creature);
    }

    struct boss_nerubenkanAI : public ScriptedAI
    {
        boss_nerubenkanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }
       
        void Reset() override
        {
            _events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_CRYPT_SCARABS, 3 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_ENCASINGWEBS, 7 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_PIERCEARMOR, 19 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_RAISEUNDEADSCARAB, 3 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_NERUB, IN_PROGRESS);
        }

        void RaiseUndeadScarab(Unit* victim)
        {
            if (Creature* pUndeadScarab = DoSpawnCreature(10876, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000))
                if (pUndeadScarab->AI())
                    pUndeadScarab->AI()->AttackStart(victim);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ENCASINGWEBS:
                        DoCastVictim(SPELL_ENCASINGWEBS);
                        _events.ScheduleEvent(EVENT_ENCASINGWEBS, 30 * IN_MILLISECONDS);
                        break;
                    case EVENT_PIERCEARMOR:
                        if (urand(0, 3) < 2)
                            DoCastVictim(SPELL_PIERCEARMOR);
                        _events.ScheduleEvent(EVENT_PIERCEARMOR, 35 * IN_MILLISECONDS);
                        break;
                    case EVENT_CRYPT_SCARABS:
                        DoCastVictim(SPELL_CRYPT_SCARABS);
                        _events.ScheduleEvent(EVENT_CRYPT_SCARABS, 20 * IN_MILLISECONDS);
                        break;
                    case EVENT_RAISEUNDEADSCARAB:
                        RaiseUndeadScarab(me->GetVictim());
                        _events.ScheduleEvent(EVENT_RAISEUNDEADSCARAB, 16 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* instance;
        EventMap _events;
    };

};

void AddSC_boss_nerubenkan()
{
    new boss_nerubenkan();
}
