/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
TCName: Boss_Arlokk
TC%Complete: 95
TCComment: Wrong cleave and red aura is missing not yet added.
TCComment: Prowlers moving through wall hopefully mmaps will fix.
TCComment: Can't test LOS until mmaps.
TCCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "zulgurub.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_FEAST_PROWLER           = 1,
    SAY_DEATH                   = 2
};

enum Spells
{
    SPELL_SHADOW_WORD_PAIN      = 24212, // Corrected
    SPELL_GOUGE                 = 12540, // Corrected
    SPELL_MARK_OF_ARLOKK        = 24210, // triggered spell 24211 Added to spell_dbc
    SPELL_RAVAGE                = 24213, // Corrected
    SPELL_CLEAVE                = 25174, // Searching for right spell
    SPELL_PANTHER_TRANSFORM     = 24190, // Transform to panther now used
    SPELL_SUMMON_PROWLER        = 24246, // Added to Spell_dbc
    SPELL_VANISH_VISUAL         = 24222, // Added
    SPELL_VANISH                = 24223, // Added
    SPELL_SUPER_INVIS           = 24235  // Added to Spell_dbc
};

enum Events
{
    EVENT_SHADOW_WORD_PAIN      = 1,
    EVENT_GOUGE                 = 2,
    EVENT_MARK_OF_ARLOKK        = 3,
    EVENT_RAVAGE                = 4,
    EVENT_TRANSFORM             = 5,
    EVENT_VANISH                = 6,
    EVENT_VANISH_2              = 7,
    EVENT_TRANSFORM_BACK        = 8,
    EVENT_VISIBLE               = 9,
    EVENT_SUMMON_PROWLERS       = 10
};

enum Phases
{
    PHASE_ALL                   = 0,
    PHASE_ONE                   = 1,
    PHASE_TWO                   = 2
};

enum Weapon
{
    WEAPON_DAGGER               = 10616
};

enum Misc
{
    MAX_PROWLERS_PER_SIDE       = 15
};

Position const PosMoveOnSpawn[1] =
{
    { -11561.9f, -1627.868f, 41.29941f, 0.0f }
};

class boss_arlokk : public CreatureScript
{
    public: boss_arlokk() : CreatureScript("boss_arlokk") { }

        struct boss_arlokkAI : public BossAI
        {
            boss_arlokkAI(Creature* creature) : BossAI(creature, DATA_ARLOKK) { }

            void Reset() override
            {
                if (events.IsInPhase(PHASE_TWO))
                    me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, false); // hack
                _Reset();
                _summonCountA = 0;
                _summonCountB = 0;
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(WEAPON_DAGGER));
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, uint32(WEAPON_DAGGER));
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(0, PosMoveOnSpawn[0]);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, urand(7000, 9000), 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_GOUGE, urand(12000, 15000), 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_SUMMON_PROWLERS, 6000, 0, PHASE_ALL);
                events.ScheduleEvent(EVENT_MARK_OF_ARLOKK, urand(9000, 11000), 0, PHASE_ALL);
                events.ScheduleEvent(EVENT_TRANSFORM, urand(15000, 20000), 0, PHASE_ONE);
                Talk(SAY_AGGRO);

                // Sets up list of Panther spawners to cast on
                std::list<Creature*> triggerList;
                GetCreatureListWithEntryInGrid(triggerList, me, NPC_PANTHER_TRIGGER, 100.0f);
                if (!triggerList.empty())
                {
                    uint8 sideA = 0;
                    uint8 sideB = 0;
                    for (std::list<Creature*>::const_iterator itr = triggerList.begin(); itr != triggerList.end(); ++itr)
                    {
                        if (Creature* trigger = *itr)
                        {
                            if (trigger->GetPositionY() < -1625.0f)
                            {
                                _triggersSideAGUID[sideA] = trigger->GetGUID();
                                ++sideA;
                            }
                            else
                            {
                                _triggersSideBGUID[sideB] = trigger->GetGUID();
                                ++sideB;
                            }
                        }
                    }
                }
            }

            void EnterEvadeMode() override
            {
                BossAI::EnterEvadeMode();
                if (GameObject* object = ObjectAccessor::GetGameObject(*me, instance->GetData64(GO_GONG_OF_BETHEKK)))
                    object->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                me->DespawnOrUnsummon(4000);
            }

            void SetData(uint32 id, uint32 /*value*/) override
            {
                if (id == 1)
                    --_summonCountA;
                else if (id == 2)
                    --_summonCountB;
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
                        case EVENT_SHADOW_WORD_PAIN:
                            DoCastVictim(SPELL_SHADOW_WORD_PAIN, true);
                            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, urand(5000, 7000), 0, PHASE_ONE);
                            break;
                        case EVENT_GOUGE:
                            DoCastVictim(SPELL_GOUGE, true);
                            break;
                        case EVENT_SUMMON_PROWLERS:
                            if (_summonCountA < MAX_PROWLERS_PER_SIDE)
                            {
                                if (Unit* trigger = ObjectAccessor::GetUnit(*me, _triggersSideAGUID[urand(0, 4)]))
                                {
                                    trigger->CastSpell(trigger, SPELL_SUMMON_PROWLER);
                                    ++_summonCountA;
                                }
                            }
                            if (_summonCountB < MAX_PROWLERS_PER_SIDE)
                            {
                                if (Unit* trigger = ObjectAccessor::GetUnit(*me, _triggersSideBGUID[urand(0, 4)]))
                                {
                                    trigger->CastSpell(trigger, SPELL_SUMMON_PROWLER);
                                    ++_summonCountB;
                                }
                            }
                            events.ScheduleEvent(EVENT_SUMMON_PROWLERS, 6000, 0, PHASE_ALL);
                            break;
                        case EVENT_MARK_OF_ARLOKK:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, urand(1, 3), 0.0f, false, -SPELL_MARK_OF_ARLOKK);
                            if (!target)
                                target = me->GetVictim();
                            if (target)
                            {
                                DoCast(target, SPELL_MARK_OF_ARLOKK, true);
                                Talk(SAY_FEAST_PROWLER, target);
                            }
                            events.ScheduleEvent(EVENT_MARK_OF_ARLOKK, urand(120000, 130000));
                            break;
                        }
                        case EVENT_TRANSFORM:
                        {
                            DoCast(me, SPELL_PANTHER_TRANSFORM); // SPELL_AURA_TRANSFORM
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_UNEQUIP));
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, uint32(EQUIP_UNEQUIP));
                            /*
                            const CreatureTemplate* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            */
                            me->AttackStop();
                            DoResetThreat();
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_VANISH_VISUAL);
                            DoCast(me, SPELL_VANISH);
                            events.ScheduleEvent(EVENT_VANISH, 1000, 0, PHASE_ONE);
                            break;
                        }
                        case EVENT_VANISH:
                            DoCast(me, SPELL_SUPER_INVIS);
                            me->SetWalk(false);
                            me->GetMotionMaster()->MovePoint(0, frand(-11551.0f, -11508.0f), frand(-1638.0f, -1617.0f), me->GetPositionZ());
                            events.ScheduleEvent(EVENT_VANISH_2, 9000, 0, PHASE_ONE);
                            break;
                        case EVENT_VANISH_2:
                            DoCast(me, SPELL_VANISH);
                            DoCast(me, SPELL_SUPER_INVIS);
                            events.ScheduleEvent(EVENT_VISIBLE, urand(7000, 10000), 0, PHASE_ONE);
                            break;
                        case EVENT_VISIBLE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                AttackStart(target);
                            me->RemoveAura(SPELL_SUPER_INVIS);
                            me->RemoveAura(SPELL_VANISH);
                            events.ScheduleEvent(EVENT_RAVAGE, urand(10000, 14000), 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_TRANSFORM_BACK, urand(15000, 18000), 0, PHASE_TWO);
                            events.SetPhase(PHASE_TWO);
                            me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, true); // hack
                            break;
                        case EVENT_RAVAGE:
                            DoCastVictim(SPELL_RAVAGE, true);
                            events.ScheduleEvent(EVENT_RAVAGE, urand(10000, 14000), 0, PHASE_TWO);
                            break;
                        case EVENT_TRANSFORM_BACK:
                        {
                            me->RemoveAura(SPELL_PANTHER_TRANSFORM); // SPELL_AURA_TRANSFORM
                            DoCast(me, SPELL_VANISH_VISUAL);
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(WEAPON_DAGGER));
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, uint32(WEAPON_DAGGER));
                            /*
                            const CreatureTemplate* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            */
                            me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, false); // hack
                            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, urand(4000, 7000), 0, PHASE_ONE);
                            events.ScheduleEvent(EVENT_GOUGE, urand(12000, 15000), 0, PHASE_ONE);
                            events.ScheduleEvent(EVENT_TRANSFORM, urand(16000, 20000), 0, PHASE_ONE);
                            events.SetPhase(PHASE_ONE);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _summonCountA;
            uint8 _summonCountB;
            uint64 _triggersSideAGUID[5];
            uint64 _triggersSideBGUID[5];
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_arlokkAI>(creature);
        }
};

/*######
## npc_zulian_prowler
######*/

enum ZulianProwlerSpells
{
    SPELL_SNEAK_RANK_1_1         = 22766,
    SPELL_SNEAK_RANK_1_2         = 7939,  // Added to Spell_dbc
    SPELL_MARK_OF_ARLOKK_TRIGGER = 24211  // Added to Spell_dbc
};

enum ZulianProwlerEvents
{
    EVENT_ATTACK                 = 1
};

Position const PosProwlerCenter[1] =
{
    { -11556.7f, -1631.344f, 41.2994f, 0.0f }
};

class npc_zulian_prowler : public CreatureScript
{
    public: npc_zulian_prowler() : CreatureScript("npc_zulian_prowler") { }

        struct npc_zulian_prowlerAI : public ScriptedAI
        {
            npc_zulian_prowlerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                if (me->GetPositionY() < -1625.0f)
                    _sideData = 1;
                else
                    _sideData = 2;

                DoCast(me, SPELL_SNEAK_RANK_1_1);
                DoCast(me, SPELL_SNEAK_RANK_1_2);

                if (Unit* arlokk = ObjectAccessor::GetUnit(*me, _instance->GetData64(NPC_ARLOKK)))
                    me->GetMotionMaster()->MovePoint(0, arlokk->GetPositionX(), arlokk->GetPositionY(), arlokk->GetPositionZ());
                _events.ScheduleEvent(EVENT_ATTACK, 6000);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                me->GetMotionMaster()->Clear(false);
                me->RemoveAura(SPELL_SNEAK_RANK_1_1);
                me->RemoveAura(SPELL_SNEAK_RANK_1_2);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_MARK_OF_ARLOKK_TRIGGER) // Should only hit if line of sight
                    me->Attack(caster, true);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Unit* arlokk = ObjectAccessor::GetUnit(*me, _instance->GetData64(NPC_ARLOKK)))
                {
                    if (arlokk->IsAlive())
                        arlokk->GetAI()->SetData(_sideData, 0);
                }
                me->DespawnOrUnsummon(4000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (UpdateVictim())
                {
                    DoMeleeAttackIfReady();
                    return;
                }

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ATTACK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 100, false))
                                me->Attack(target, true);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            int32 _sideData;
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_zulian_prowlerAI>(creature);
        }
};

/*######
## go_gong_of_bethekk
######*/

Position const PosSummonArlokk[1] =
{
    { -11507.22f, -1628.062f, 41.38264f, 3.159046f }
};

class go_gong_of_bethekk : public GameObjectScript
{
    public: go_gong_of_bethekk() : GameObjectScript("go_gong_of_bethekk") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go) override
        {
            if (go->GetInstanceScript())
            {
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                go->SendCustomAnim(0);
                go->SummonCreature(NPC_ARLOKK, PosSummonArlokk[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 600000);
            }
            return true;
        }
};

void AddSC_boss_arlokk()
{
    new boss_arlokk();
    new npc_zulian_prowler();
    new go_gong_of_bethekk();
}
