/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "icecrown_citadel.h"
#include "Group.h"

enum eScriptTexts
{
    SAY_STINKY_DEAD             = 0,
    SAY_AGGRO                   = 1,
    EMOTE_GAS_SPORE             = 2,
    EMOTE_WARN_GAS_SPORE        = 3,
    SAY_PUNGENT_BLIGHT          = 4,
    EMOTE_WARN_PUNGENT_BLIGHT   = 5,
    EMOTE_PUNGENT_BLIGHT        = 6,
    SAY_KILL                    = 7,
    SAY_BERSERK                 = 8,
    SAY_DEATH                   = 9
};

enum eSpells
{
    // Festergut
    SPELL_INHALE_BLIGHT         = 69165,
    SPELL_INHALED_BLIGHT_1      = 69166,
    SPELL_INHALED_BLIGHT_2      = 71912,
    SPELL_PUNGENT_BLIGHT        = 69195,
    //SPELL_GASTRIC_BLOAT         = 72219, // 72214 is the proper way (with proc) but atm procs can't have cooldown for creatures
    SPELL_GASTRIC_EXPLOSION     = 72227,
    SPELL_GAS_SPORE             = 69278,
    SPELL_GAS_SPORE1            = 69279,
    SPELL_GAS_SPORE2            = 71221,

    //SPELL_VILE_GAS              = 69240,
    SPELL_INOCULATED            = 69291,
    SPELL_INOCULATED1           = 72101,
    SPELL_INOCULATED2           = 72102,
    SPELL_INOCULATED3           = 72103,
    // Stinky
    SPELL_MORTAL_WOUND          = 71127,
    SPELL_DECIMATE              = 71123,
    SPELL_PLAGUE_STENCH         = 71805,
};
//#define SPELL_PUNGENT_BLIGHT RAID_MODE<uint32>(69195, 73031, 71219, 73032)
#define SPELL_GASTRIC_BLOAT RAID_MODE<uint32>(72219, 72551, 72551, 72553)
#define SPELL_VILE_GAS RAID_MODE<uint32>(72272, 72273, 72273, 73020)
//#define SPELL_GASTRIC_EXPLOSION RAID_MODE<uint32>(72227, 72227, 72229, 72230)
// Used for HasAura checks
#define PUNGENT_BLIGHT_HELPER RAID_MODE<uint32>(69195,71219,73031,73032)
#define INOCULATED_HELPER     RAID_MODE<uint32>(69291,72101,72102,72103)

static const uint32 gaseousBlight[3]        = {69157, 69162, 69164};
static const uint32 gaseousBlightAura[3]    = {69159, 69161, 69163};
static const uint32 gaseousBlightVisual[3]  = {69126, 69152, 69154};
static const uint32 allGaseousBlight[17]    = {69125, 70469, 70468, 70140, 70139, 70138, 70137, 70136, 70135, 69162, 69161, 69159, 69157, 69154, 69152, 69126, 70470};
enum eEvents
{
    EVENT_BERSERK       = 1,
    EVENT_INHALE_BLIGHT = 2,
    EVENT_VILE_GAS      = 3,
    EVENT_GAS_SPORE     = 4,
    EVENT_GASTRIC_BLOAT = 5,

    EVENT_DECIMATE      = 6,
    EVENT_MORTAL_WOUND  = 7,
    EVENT_GASEOUS_BLIGHT= 8
};

#define DATA_INOCULATED_STACK 69291

class boss_festergut : public CreatureScript
{
    public:
        boss_festergut() : CreatureScript("boss_festergut") { }

        struct boss_festergutAI : public BossAI
        {
            boss_festergutAI(Creature* creature) : BossAI(creature, DATA_FESTERGUT_EVENT)
            {
                maxInoculatedStack = 0;
                inhaleCounter = 0;
                gasDummyGUID = 0;
                //Prevent dummies to attack players or keep them in combat
                if (Creature* gasDummy = me->FindNearestCreature(NPC_ORANGE_GAS_STALKER, 100.0f, true))
                {
                    gasDummy->SetReactState(REACT_PASSIVE);
                    gasDummyGUID = gasDummy->GetGUID();
                    _RemoveBlight();
                }
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_BERSERK, 300000);
                events.ScheduleEvent(EVENT_INHALE_BLIGHT, 35000);
                //-- Every 40 seconds except after 3rd and 6th cast, then it's 50sec CD
                events.ScheduleEvent(EVENT_GAS_SPORE, 40000);
                //-- 10 to 14 seconds according to DBM
                events.ScheduleEvent(EVENT_GASTRIC_BLOAT, urand(10000, 14000));
                events.ScheduleEvent(EVENT_GASEOUS_BLIGHT, 8000);
                events.ScheduleEvent(EVENT_VILE_GAS, urand(28000, 35000));
                maxInoculatedStack = 0;
                inhaleCounter = 0;
                me->RemoveAurasDueToSpell(SPELL_BERSERK2);
                //Prevent dummies to attack players or keep them in combat
                if (Creature* gasDummy = me->FindNearestCreature(NPC_ORANGE_GAS_STALKER, 100.0f, true))
                {
                    gasDummy->SetReactState(REACT_PASSIVE);
                    gasDummyGUID = gasDummy->GetGUID();
                    _RemoveBlight();
                }
            }

            void EnterCombat(Unit* who)
            {
                if (Creature* gasDummy = me->FindNearestCreature(NPC_ORANGE_GAS_STALKER, 100.0f, true))
                    gasDummy->Attack(who, false);
                _RemoveDebuffsFromRaid();
                Talk(SAY_AGGRO);
                if (Creature* gasDummy = me->FindNearestCreature(NPC_ORANGE_GAS_STALKER, 100.0f, true))
                    gasDummyGUID = gasDummy->GetGUID();
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_FESTERGUT_COMBAT);
                //instance->SetData(DATA_FESTERGUT_EVENT, IN_PROGRESS);
                //instance->SetBossState(DATA_FESTERGUT_EVENT, IN_PROGRESS);
                DoZoneInCombat(me);
            }

            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
                instance->SetBossState(DATA_FESTERGUT_EVENT, DONE);
                instance->SetData(DATA_FESTERGUT_EVENT, DONE);
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_FESTERGUT_DEATH);
                //Prevent dummies to attack players or keep them in combat
                if (Creature* gasDummy = me->FindNearestCreature(NPC_ORANGE_GAS_STALKER, 100.0f, true))
                {
                    gasDummy->AI()->EnterEvadeMode();
                    gasDummy->SetReactState(REACT_PASSIVE);
                    gasDummy->Kill(gasDummy);
                }
                _RemoveBlight();
                _RemoveDebuffsFromRaid();
            }
            void _RemoveDebuffsFromRaid()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GAS_SPORE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GAS_SPORE1);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GAS_SPORE2);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GASTRIC_BLOAT);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INOCULATED);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INOCULATED1);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INOCULATED2);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INOCULATED3);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VILE_GAS);
            }
            void JustReachedHome()
            {
                instance->SetBossState(DATA_FESTERGUT_EVENT, FAIL);
                instance->SetData(DATA_FESTERGUT_EVENT, FAIL);
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->EnterEvadeMode();
                _RemoveDebuffsFromRaid();
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->EnterEvadeMode();
                _RemoveDebuffsFromRaid();
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL);
                    for (uint8 i = 0; i < 3; ++i)
                        victim->RemoveAurasDueToSpell(SPELL_INOCULATED);
                    victim->RemoveAurasDueToSpell(SPELL_VILE_GAS);
                    victim->RemoveAurasDueToSpell(SPELL_GAS_SPORE);
                }
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
                // don't enter combat
            }

            void SpellHitTarget(Unit* target, SpellEntry const* spell)
            {
                if (spell->Id == PUNGENT_BLIGHT_HELPER)
                    for (uint8 i = 0; i < 3; ++i)
                        target->RemoveAurasDueToSpell(INOCULATED_HELPER);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!CheckInRoom())
                    EnterEvadeMode();
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GASEOUS_BLIGHT:
                        {
                            _RemoveBlight();
                            if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                                professor->AI()->DoAction(ACTION_FESTERGUT_GAS);
                            if (Creature* gasDummy = ObjectAccessor::GetCreature(*me, gasDummyGUID))
                                gasDummy->CastSpell(gasDummy, gaseousBlight[0], true, NULL, NULL, me->GetGUID());
                            break;
                        }
                        case EVENT_INHALE_BLIGHT:
                        {
                            _RemoveBlight();
                            if (inhaleCounter == 3)
                            {
                                Talk(EMOTE_WARN_PUNGENT_BLIGHT);
                                Talk(SAY_PUNGENT_BLIGHT);
                                me->RemoveAurasDueToSpell(SPELL_INHALE_BLIGHT);
                                me->RemoveAurasDueToSpell(SPELL_INHALED_BLIGHT_1);
                                me->RemoveAurasDueToSpell(SPELL_INHALED_BLIGHT_2);
                                DoCast(me, PUNGENT_BLIGHT_HELPER, false);
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INOCULATED);
                                inhaleCounter = 0;
                                //Refill the room with gaseous blight at maximum power
                                if (Creature* gasDummy = ObjectAccessor::GetCreature(*me, gasDummyGUID))
                                    gasDummy->CastSpell(gasDummy, gaseousBlight[inhaleCounter], true, NULL, NULL, me->GetGUID());
                            }
                            else
                            {
                                DoCast(me, SPELL_INHALE_BLIGHT);
                                // just cast and dont bother with target, conditions will handle it
                                ++inhaleCounter;
                                if (inhaleCounter < 3)
                                {
                                    if (Creature* gasDummy = ObjectAccessor::GetCreature(*me, gasDummyGUID))
                                        gasDummy->CastSpell(gasDummy, gaseousBlight[inhaleCounter], true, NULL, NULL, me->GetGUID());
                                }
                                else
                                {
                                    //-- Every 40 seconds except after 3rd and 6th cast, then it's 50sec CD
                                    events.RescheduleEvent(EVENT_GAS_SPORE, 50000);
                                }
                            }
                            events.ScheduleEvent(EVENT_INHALE_BLIGHT, urand(33500, 35000));
                            break;
                        }
                        case EVENT_VILE_GAS:
                        {
                            std::list<Unit*> targets;
                            uint32 minTargets = RAID_MODE<uint32>(3, 8, 3, 8);
                            SelectTargetList(targets, minTargets, SELECT_TARGET_RANDOM, -5.0f, true);
                            float minDist = 0.0f;
                            if (targets.size() >= minTargets)
                                minDist = -5.0f;

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, minDist, true))
                                DoCast(target, SPELL_VILE_GAS);
                            events.ScheduleEvent(EVENT_VILE_GAS, urand(28000, 35000));
                            break;
                        }
                        case EVENT_GAS_SPORE:
                            Talk(EMOTE_WARN_GAS_SPORE);
                            Talk(EMOTE_GAS_SPORE);
                            me->CastCustomSpell(SPELL_GAS_SPORE, SPELLVALUE_MAX_TARGETS, RAID_MODE<int32>(2, 3, 2, 3), me);
                            events.ScheduleEvent(EVENT_GAS_SPORE, urand(40000, 45000));
                            //events.RescheduleEvent(EVENT_VILE_GAS, urand(28000, 35000));
                            break;
                        case EVENT_GASTRIC_BLOAT:
                            DoCastVictim(SPELL_GASTRIC_BLOAT);
                            //-- 10 to 14 seconds according to DeadlyBossMods
                            events.ScheduleEvent(EVENT_GASTRIC_BLOAT, urand(10000, 14000));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK2);
                            Talk(SAY_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_INOCULATED_STACK && data > maxInoculatedStack)
                    maxInoculatedStack = data;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_INOCULATED_STACK)
                    return uint32(maxInoculatedStack);

                return 0;
            }

            void _RemoveBlight()
            {
                if (Creature* gasDummy = ObjectAccessor::GetCreature(*me, gasDummyGUID))
                {
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        gasDummy->RemoveAurasDueToSpell(gaseousBlight[i]);
                        gasDummy->RemoveAurasDueToSpell(gaseousBlightAura[i]);
                        gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
                    }
                    for (uint8 i = 0; i < 17; ++i)
                        gasDummy->RemoveAurasDueToSpell(allGaseousBlight[i]);
                }
            }

        private:
            uint64 gasDummyGUID;
            uint32 maxInoculatedStack;
            uint8 inhaleCounter;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_festergutAI(creature);
        }
};

class npc_stinky_icc : public CreatureScript
{
    public:
        npc_stinky_icc() : CreatureScript("npc_stinky_icc") { }

        struct npc_stinky_iccAI : public ScriptedAI
        {
            npc_stinky_iccAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DECIMATE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(3000, 7000));
                me->RemoveAllAuras();
            }
            void EnterCombat(Unit *who)
            {
                //Non-triggered to avoid breaking Line of Sight
                DoCast(me, SPELL_PLAGUE_STENCH);
            }
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DECIMATE:
                            DoCastVictim(SPELL_DECIMATE);
                            events.ScheduleEvent(EVENT_DECIMATE, urand(20000, 25000));
                            break;
                        case EVENT_MORTAL_WOUND:
                            DoCastVictim(SPELL_MORTAL_WOUND);
                            events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(10000, 12500));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature* festergut = me->GetCreature(*me, instance->GetData64(GUID_FESTERGUT)))
                    if (festergut->isAlive())
                        festergut->AI()->Talk(SAY_STINKY_DEAD);
            }

        private:
            EventMap events;
            InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_stinky_iccAI(creature);
        }
};

class spell_festergut_gastric_bloat : public SpellScriptLoader
{
    public:
        spell_festergut_gastric_bloat() : SpellScriptLoader("spell_festergut_gastric_bloat") { }

        class spell_festergut_gastric_bloat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_festergut_gastric_bloat_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Aura const* aura = GetHitUnit()->GetAura(GetSpellInfo()->Id);
                if (!(aura && aura->GetStackAmount() == 10))
                    return;

                SpellEntry const* spellInfo = sSpellStore.LookupEntry(SPELL_GASTRIC_EXPLOSION);
                if (!spellInfo)
                    return;

                // Get Gastric Explosion id for our difficulty
                spellInfo = sSpellMgr->GetSpellForDifficultyFromSpell(spellInfo, GetCaster());
                GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                GetHitUnit()->CastSpell(GetHitUnit(), spellInfo, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_festergut_gastric_bloat_SpellScript::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_festergut_gastric_bloat_SpellScript();
        }
};

class spell_festergut_blighted_spores : public SpellScriptLoader
{
    public:
        spell_festergut_blighted_spores() : SpellScriptLoader("spell_festergut_blighted_spores") { }

        class spell_festergut_blighted_spores_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_festergut_blighted_spores_AuraScript);

            void ExtraEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster()->IsAIEnabled || GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return;

                uint32 inoculateId = CAST_AI(ScriptedAI, GetCaster()->ToCreature()->AI())->INOCULATED_HELPER;
                uint32 currStack = 0;
                if (Aura const* inoculate = GetTarget()->GetAura(inoculateId))
                    currStack = inoculate->GetStackAmount();

                GetTarget()->CastSpell(GetTarget(), SPELL_INOCULATED, true);
                ++currStack;
                GetCaster()->ToCreature()->AI()->SetData(DATA_INOCULATED_STACK, currStack);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_festergut_blighted_spores_AuraScript::ExtraEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_festergut_blighted_spores_AuraScript();
        }
};

class achievement_flu_shot_shortage : public AchievementCriteriaScript
{
    public:
        achievement_flu_shot_shortage() : AchievementCriteriaScript("achievement_flu_shot_shortage") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->GetTypeId() == TYPEID_UNIT)
                return target->ToCreature()->AI()->GetData(DATA_INOCULATED_STACK) < 3;

            return false;
        }
};

void AddSC_boss_festergut()
{
    new boss_festergut();
    new npc_stinky_icc();
    //new spell_festergut_pungent_blight();
    new spell_festergut_gastric_bloat();
    new spell_festergut_blighted_spores();
    new achievement_flu_shot_shortage();
} 