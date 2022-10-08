/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "siege_of_the_niuzao_temple.h"

enum eSpells
{
    SPELL_CAUSTIC_TAR    = 120269,
    SPELL_THOUSED_BLADES = 120759,
    SPELL_DASHING_STRIKE = 120789,
    SPELL_BOMBARD        = 120559, // Aura, triggers SPELL_BOMBARD_DUMMY every 1.5s for 15s.
    SPELL_CARRYING_TAR_A = 123032, // Target selection and slow - This is spell from player keg interact.
    SPELL_BOMBARD_DMG    = 120200,
};

enum eEvents
{
    EVENT_STRIKE         = 0,
    EVENT_BLADES         = 1,

    // Li / Lo Chu
    EVENT_START_LEFT,
    EVENT_START_RIGHT,

    EVENT_PICKUP_KEG,
    EVENT_MOVE_DROP_KEG,
    EVENT_DROP_KEG,

    EVENT_LI_LO_CHU_OUTRO,

    EVENT_LI_LO_CHU_EVADE
};

enum Actions
{
    ACTION_MOVE_STAIR = 1,

    // Yang Ironclaw
    ACTION_START_INTRO,
    ACTION_START_EVENT,
    ACTION_START_OUTRO,
    ACTION_YANG_EVADE,

    // Li / Lo Chu
    ACTION_START_LEFT,
    ACTION_START_RIGHT,
    ACTION_LI_LO_CHU_OUTRO,
    ACTION_LI_LO_CHU_EVADE
};

class boss_commander_vojak : public CreatureScript
{
    public:
        boss_commander_vojak() : CreatureScript("boss_commander_vojak") {}

        struct boss_commander_vojakAI : public BossAI
        {
            boss_commander_vojakAI(Creature* creature) : BossAI(creature, NPC_VOJAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 striketimer;
            uint32 bladetimer;

            void Reset()
            {
                _Reset();
                striketimer = 0;
                bladetimer = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                striketimer = 3000;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (striketimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                        DoCast(target, SPELL_DASHING_STRIKE);
                    striketimer = urand(8000, 10000);
                    bladetimer = 2000;
                }
                else
                    striketimer -= diff;

                if (bladetimer)
                {
                    if (bladetimer <= diff)
                    {
                        bladetimer = 0;
                        DoCast(me, SPELL_THOUSED_BLADES);
                    }
                    else
                        bladetimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_commander_vojakAI(creature);
        }
};

// Mantid Tar Keg 61817.
class npc_mantid_tar_keg_vojak : public CreatureScript
{
public:
    npc_mantid_tar_keg_vojak() : CreatureScript("npc_mantid_tar_keg_vojak") { }

    struct npc_mantid_tar_keg_vojakAI : public ScriptedAI
    {
        npc_mantid_tar_keg_vojakAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void IsSummonedBy(Unit* summoner)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_BOMBARD_DMG, true);
           // me->AddUnitFlag(UnitFlags(UNIT_FLAG_DISABLE_MOVE);
            me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
            me->SetReactState(REACT_PASSIVE);
        }

/*        void OnSpellClick(Unit* clicker)
        {
            // Handle Player pickup.
            clicker->CastSpell(clicker, SPELL_CARRYING_TAR_A, true);
            me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
            me->DespawnOrUnsummon();
        }*/

        void UpdateAI(uint32 const diff)
        {
            // No melee.
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mantid_tar_keg_vojakAI(creature);
    }
};

class npc_sikthik_warden : public CreatureScript
{
    struct npc_sikthik_wardenAI : public ScriptedAI
    {
        npc_sikthik_wardenAI(Creature * creature) : ScriptedAI(creature) {}
    };

public:
    npc_sikthik_warden() : CreatureScript("npc_sikthik_warden") {}

    CreatureAI * GetAI(Creature * creature) const override
    {
        return new npc_sikthik_wardenAI(creature);
    }
};

// Li Chu 61812.
class npc_li_chu : public CreatureScript
{
public:
    npc_li_chu() : CreatureScript("npc_li_chu") { }

    struct npc_li_chuAI : public ScriptedAI
    {
        npc_li_chuAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList summons;
        EventMap events;
        uint8 kegsMoved;

        void Reset()
        {
            events.Reset();
            summons.DespawnAll();

            kegsMoved = 0;

            if (Creature* Warden = me->FindNearestCreature(NPC_SIKTHIK_WARDEN, 50.0f, true))
                me->AI()->AttackStart(Warden);
        }

        void DamageDealt(Unit* target, uint32& damage, DamageEffectType damageType)
        {
            if (target->ToCreature())
                if (target->ToCreature()->GetEntry() == NPC_SIKTHIK_WARDEN)
                    if (target->HealthBelowPct(100))
                        damage = 0;
        }

        void EnterEvadeMode(EvadeReason /*why*/) { } // Override.

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
            summon->setActive(true);
        }

        void DoAction(int32 const action)
        {
            switch (action)
            {
            case ACTION_START_LEFT:
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_BOMBARD_DMG, true);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC));
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_START_LEFT, 100);
                break;

            case ACTION_LI_LO_CHU_OUTRO:
                events.ScheduleEvent(EVENT_LI_LO_CHU_OUTRO, 100);
                break;

            case ACTION_LI_LO_CHU_EVADE:
                events.ScheduleEvent(EVENT_LI_LO_CHU_EVADE, 100);
                break;

            default: break;
            }
        };

        void MovementInform(uint32 type, uint32 id)
        {
            if (!me->IsAlive() || type != POINT_MOTION_TYPE)
                return;

            // Handle Mantid Tar Keg pickup / drop.
            switch (id)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                events.ScheduleEvent(EVENT_DROP_KEG, 100);
                break;

            case 22: // Pickup point.
                events.ScheduleEvent(EVENT_PICKUP_KEG, 100);
                break;

            default: break;
            }
        }

        void UpdateAI(uint32 const diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_LEFT:
                    me->GetMotionMaster()->MovePoint(22, 1488.50f, 5299.22f, 184.649f);
                    break;

                case EVENT_PICKUP_KEG:
                    if (Creature* keg = me->FindNearestCreature(NPC_MANTID_TAR_KEG, 10.0f, true))
                        keg->DespawnOrUnsummon();
                    me->AddAura(SPELL_CARRYING_TAR_A, me);
                    events.ScheduleEvent(EVENT_MOVE_DROP_KEG, 100);
                    break;

                case EVENT_MOVE_DROP_KEG:
                    kegsMoved++;
                    //me->GetMotionMaster()->MovePoint(kegsMoved, liKegPositions[kegsMoved - 1].GetPositionX(), liKegPositions[kegsMoved - 1].GetPositionY(), liKegPositions[kegsMoved - 1].GetPositionZ());
                    break;

                case EVENT_DROP_KEG:
                    me->RemoveAurasDueToSpell(SPELL_CARRYING_TAR_A);
                   // me->SummonCreature(NPC_MANTID_TAR_KEG, liKegPositions[kegsMoved - 1], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    if (kegsMoved < 21)
                        events.ScheduleEvent(EVENT_START_LEFT, 100);
                    else
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MoveTargetedHome();
                    }
                    break;

                case EVENT_LI_LO_CHU_OUTRO:
                    summons.DespawnAll();
                    me->RemoveAllAuras();
                   // me->GetMotionMaster()->MovePoint(23, outroPoints[0].GetPositionX(), outroPoints[0].GetPositionY(), outroPoints[0].GetPositionZ());
                    me->DespawnOrUnsummon(5000);
                    break;

                case EVENT_LI_LO_CHU_EVADE:
                    me->RemoveAllAuras();
                    Reset();
                    me->DeleteThreatList();
                    me->CombatStop(true);
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;

                default: break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_li_chuAI(creature);
    }
};

void AddSC_boss_commander_vojak()
{
    new boss_commander_vojak();
    new npc_mantid_tar_keg_vojak();
    new npc_sikthik_warden();
    new npc_li_chu();
}
