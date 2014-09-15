/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Say
{
    SAY_AGGRO                       = 1
};

enum Spells
{
    SPELL_BRAIN_WASH_TOTEM          = 24262,
    SPELL_POWERFULL_HEALING_WARD    = 24309,
    SPELL_HEX                       = 24053,
    SPELL_DELUSIONS_OF_JINDO        = 24306,
    SPELL_SHADE_OF_JINDO            = 24308,
    // Healing Ward Spell
    SPELL_HEAL                      = 24311,
    // Shade of Jindo Spell
    SPELL_SHADOWSHOCK               = 19460,
    SPELL_INVISIBLE                 = 24307
};

enum Events
{
    EVENT_BRAIN_WASH_TOTEM          = 1,
    EVENT_POWERFULL_HEALING_WARD    = 2,
    EVENT_HEX                       = 3,
    EVENT_DELUSIONS_OF_JINDO        = 4,
    EVENT_TELEPORT                  = 5
};

Position const TeleportLoc = { -11583.7783f, -1249.4278f, 77.5471f, 4.745f };

// Formation of summoned trolls
Position const Formation[] =
{
    { -11582.2998f, -1247.8599f, 77.6298f, 0.0f },
    { -11585.0996f, -1248.7600f, 77.6298f, 0.0f },
    { -11586.5996f, -1250.7199f, 77.6298f, 0.0f },
    { -11586.4003f, -1253.9200f, 77.6298f, 0.0f },
    { -11584.2001f, -1252.2099f, 77.6298f, 0.0f },
    { -11582.5000f, -1250.3199f, 77.6298f, 0.0f },
    { -11583.2001f, -1254.8299f, 77.6298f, 0.0f },
    { -11581.5000f, -1252.5400f, 77.6298f, 0.0f },
    { -11580.2001f, -1250.5999f, 77.6298f, 0.0f },
    { -11580.5996f, -1254.7900f, 77.6298f, 0.0f }
};

class boss_jindo : public CreatureScript
{
    public:
        boss_jindo() : CreatureScript("boss_jindo") { }

        struct boss_jindoAI : public BossAI
        {
            boss_jindoAI(Creature* creature) : BossAI(creature, DATA_JINDO) { }

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_BRAIN_WASH_TOTEM, 20000);
                events.ScheduleEvent(EVENT_POWERFULL_HEALING_WARD, 16000);
                events.ScheduleEvent(EVENT_HEX, 8000);
                events.ScheduleEvent(EVENT_DELUSIONS_OF_JINDO, 10000);
                events.ScheduleEvent(EVENT_TELEPORT, 5000);
                Talk(SAY_AGGRO);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BRAIN_WASH_TOTEM:
                            DoCast(me, SPELL_BRAIN_WASH_TOTEM);
                            events.ScheduleEvent(EVENT_BRAIN_WASH_TOTEM, urand(18000, 26000));
                            break;
                        case EVENT_POWERFULL_HEALING_WARD:
                            DoCast(me, SPELL_POWERFULL_HEALING_WARD);
                            events.ScheduleEvent(EVENT_POWERFULL_HEALING_WARD, urand(14000, 20000));
                            break;
                        case EVENT_HEX:
                            if (Unit* target = me->GetVictim())
                            {
                                DoCast(target, SPELL_HEX, true);
                                if (DoGetThreat(target))
                                    DoModifyThreatPercent(target, -80);
                            }
                            events.ScheduleEvent(EVENT_HEX, urand(12000, 20000));
                            break;
                        case EVENT_DELUSIONS_OF_JINDO:
                            // Casting the delusion curse with a shade so shade will attack the same target with the curse.
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                DoCast(target, SPELL_SHADE_OF_JINDO, true);
                                DoCast(target, SPELL_DELUSIONS_OF_JINDO);
                            }
                            events.ScheduleEvent(EVENT_DELUSIONS_OF_JINDO, urand(4000, 12000));
                            break;
                        case EVENT_TELEPORT:
                            // Teleports a random player and spawns 9 Sacrificed Trolls to attack player
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                DoTeleportPlayer(target, TeleportLoc.GetPositionX(), TeleportLoc.GetPositionY(), TeleportLoc.GetPositionZ(), TeleportLoc.GetOrientation());
                                if (DoGetThreat(me->GetVictim()))
                                    DoModifyThreatPercent(target, -100);

                                // Summon a formation of trolls
                                for (uint8 i = 0; i < 10; ++i)
                                    if (Creature* SacrificedTroll = me->SummonCreature(NPC_SACRIFICED_TROLL, Formation[i].GetPositionX(), Formation[i].GetPositionY(), Formation[i].GetPositionZ(), Formation[i].GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000))
                                        SacrificedTroll->AI()->AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_TELEPORT, urand(15000, 23000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_jindoAI(creature);
        }
};

// Healing Ward
class npc_healing_ward : public CreatureScript
{
    public:
        npc_healing_ward() : CreatureScript("npc_healing_ward") { }

        struct npc_healing_wardAI : public ScriptedAI
        {
            npc_healing_wardAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                Heal_Timer = 2000;
            }

            uint32 Heal_Timer;
            InstanceScript* instance;

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                // Heal_Timer
                if (Heal_Timer <= diff)
                {
                    if (Unit* jindo = ObjectAccessor::GetUnit(*me, instance->GetData64(DATA_JINDO)))
                        DoCast(jindo, SPELL_HEAL);
                    Heal_Timer = 3000;
                } else Heal_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_healing_wardAI>(creature);
        }
};

//Shade of Jindo
class npc_shade_of_jindo : public CreatureScript
{
    public:
        npc_shade_of_jindo() : CreatureScript("npc_shade_of_jindo") { }

        struct npc_shade_of_jindoAI : public ScriptedAI
        {
            npc_shade_of_jindoAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                ShadowShock_Timer = 1000;
            }

            uint32 ShadowShock_Timer;

            void Reset() override
            {
                Initialize();
                DoCast(me, SPELL_INVISIBLE, true);
            }

            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                // ShadowShock_Timer
                if (ShadowShock_Timer <= diff)
                {
                    DoCastVictim(SPELL_SHADOWSHOCK);
                    ShadowShock_Timer = 2000;
                } else ShadowShock_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shade_of_jindoAI(creature);
        }
};

void AddSC_boss_jindo()
{
    new boss_jindo();
    new npc_healing_ward();
    new npc_shade_of_jindo();
}
