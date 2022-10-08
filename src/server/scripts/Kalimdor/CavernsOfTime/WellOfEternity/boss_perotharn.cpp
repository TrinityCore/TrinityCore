/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "well_of_eternity.h"
#include "ObjectMgr.h"

enum ScriptTexts
{
    SAY_AGGRO   = 0,
    SAY_DEATH   = 1,
    SAY_RAGE    = 2,
    SAY_EVENT_1 = 3, // near entrance
    SAY_EVENT_2 = 4, // near entrance
    SAY_EVENT_3 = 5, // near entrance
    SAY_FOUND   = 6, // when eyes have found a player
    SAY_ACHIEVE = 7,
    SAY_HIDING  = 8,
    SAY_INTRO   = 9,
    SAY_KILL    = 10,
    SAY_SPELL_1 = 11,
    SAY_SPELL_2 = 12,
};

enum Spells
{
    SPELL_CORRUPTING_TOUCH          = 104939,
    SPELL_CORRUPTING_TOUCH_DMG      = 108101,
    SPELL_FEL_FLAMES                = 108141,
    SPELL_FEL_FLAMES_SUMMON         = 108193,
    SPELL_FEL_FLAMES_DMG            = 109824,
    SPELL_FEL_FLAMES_AURA           = 108214,
    SPELL_FEL_FLAMES_AURA_DMG       = 108217,
    SPELL_FEL_DECAY                 = 105544,
    SPELL_FEL_DECAY_AURA            = 108124,
    SPELL_FEL_SURGE_DMG             = 108128,
    SPELL_DRAIN_ESSENCE             = 104905,
    SPELL_FEL_ADLED                 = 105545,
    SPELL_CAMOUFLAGE                = 105341,
    SPELL_CAMOUFLAGE_REMOVE         = 105541,

    SPELL_HUNTING_CHANNEL           = 105353,

    SPELL_TRACKED_LOCK_ON_PLAYER    = 105496,
    SPELL_EASY_PREY                 = 105493,
    SPELL_ATTACK_ME_PEROTHARN       = 105509,
    SPELL_ENFEEBLED                 = 105442,
    SPELL_ENDLESS_RAGE              = 105521,

    SPELL_PUNISHING_FLAMES          = 107532,
    SPELL_PUNISHING_FLAMES_DMG      = 107536, // 80m

    //illidan
    SPELL_ABSORB_FEL_ENERGY         = 105543,
    SPELL_RETURN_TO_THE_SHADOWS     = 105635,
    SPELL_CONSUME_ESSENCE           = 104738,
    SPELL_REGENERATION              = 105547,
};

enum Adds
{
    NPC_FEL_FLAMES              = 57329,
    NPC_HUNTING_SUMMON_STALKER  = 56248,
    NPC_HUNTING_SUMMON_CIRCLE   = 56182,
    NPC_HUNTING_STALKERS        = 56189,
    NPC_EYE_OF_PEROTHARN_1      = 55868,
    NPC_EYE_OF_PEROTHARN_2      = 55879,
    NPC_EASY_PREY_STALKER       = 56308,
};

enum Events
{
    EVENT_ILLIDAN_AGGRO     = 1,
    EVENT_CORRUPTING_TOUCH  = 2,
    EVENT_FEL_FLAMES        = 3,
    EVENT_FEL_DECAY         = 4,
    EVENT_ILLIDAN_BREAK     = 5,
    EVENT_CAMOUFLAGE        = 6,
    EVENT_ILLIDAN_HIDE      = 7,
    EVENT_HUNTING           = 8,
    EVENT_NEXT_MOVE         = 9,
    EVENT_EASY_PREY         = 10,
    EVENT_ILLIDAN_OUTRO_1   = 11,
    EVENT_ILLIDAN_OUTRO_2   = 12,
    EVENT_END_HUNT          = 13,

};

enum Actions
{
    ACTION_START        = 1,
    ACTION_EASY_PREY    = 2,
};

enum Points
{
    POINT_EYE       = 1,
};

const Position centerPos = {3335.07f, -4891.54f, 181.16f, 0.0f};

class boss_perotharn : public CreatureScript
{
public:
    boss_perotharn() : CreatureScript("boss_perotharn") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_perotharnAI(pCreature);
    }

    struct boss_perotharnAI : public BossAI
    {
        boss_perotharnAI(Creature* pCreature) : BossAI(pCreature, DATA_PEROTHARN)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->setActive(true);
            phase = 0;
            bAchieve = false;

            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            DoCast(me, SPELL_CAMOUFLAGE, true);
        }

        void InitializeAI() override
        {
            if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptIdOrAdd(WoEScriptName))
                me->IsAIEnabled = false;
            else if (!me->isDead())
                Reset();
        }

        void Reset() override
        {
            _Reset();

            phase = 0;
            targetGUID = ObjectGuid::Empty;
            bAchieve = false;

            if (instance->GetData(DATA_EVENT_ILLIDAN_1) == IN_PROGRESS)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                me->RemoveAura(SPELL_CAMOUFLAGE);
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_START)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                DoCast(me, SPELL_CAMOUFLAGE_REMOVE, true);
            } else if (action == ACTION_EASY_PREY)
            {
                summons.DespawnEntry(NPC_EYE_OF_PEROTHARN_1);
                summons.DespawnEntry(NPC_HUNTING_SUMMON_CIRCLE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                Talk(SAY_FOUND);
                me->RemoveAura(SPELL_HUNTING_CHANNEL);
                events.ScheduleEvent(EVENT_EASY_PREY, 2000);
            }
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_ILLIDAN_AGGRO, 6000);
            events.ScheduleEvent(EVENT_CORRUPTING_TOUCH, 5000);
            events.ScheduleEvent(EVENT_FEL_FLAMES, urand(10000, 12000));
            events.ScheduleEvent(EVENT_FEL_DECAY, urand(12000, 15000));

            if (Creature* pStalker = me->SummonCreature(NPC_HUNTING_SUMMON_STALKER, centerPos))
            {
                pStalker->SetReactState(REACT_PASSIVE);
                pStalker->CastSpell(pStalker, SPELL_PUNISHING_FLAMES, true);
            }

            DoZoneInCombat();
            instance->SetBossState(DATA_PEROTHARN, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
            instance->SetData(DATA_EVENT_ILLIDAN_1, DONE);
            if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_1, 100.0f))
                pIllidan->AI()->DoAction(1); // ACTION_PEROTHARN_DEAD

            if (me->GetMap()->IsHeroic())
                {
                   if (!me->GetMap()->GetPlayers().isEmpty())
                   {
                       for (Map::PlayerList::const_iterator i = me->GetMap()->GetPlayers().begin(); i != me->GetMap()->GetPlayers().end(); ++i)
                       {
                            if (!i->GetSource())
                                continue;

                            i->GetSource()->KilledMonsterCredit(58239);
                            i->GetSource()->KilledMonsterCredit(58240);
                            i->GetSource()->KilledMonsterCredit(58241);
                       }
                   }
                }
        }

        void KilledUnit(Unit* who) override
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void SetGUID(ObjectGuid guid, int32 /*type*/) override
        {
            targetGUID = guid;
        }

        bool AllowAchieve()
        {
            return bAchieve;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) && phase != 3)
                return;

            if (me->HealthBelowPct(60) && phase == 0)
            {
                phase = 1;
                me->SetReactState(REACT_PASSIVE);
                events.CancelEvent(EVENT_FEL_FLAMES);
                events.CancelEvent(EVENT_FEL_DECAY);
                events.CancelEvent(EVENT_CORRUPTING_TOUCH);
                me->AttackStop();
                me->RemoveAllAuras();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                Talk(SAY_SPELL_1);
                DoCastAOE(SPELL_DRAIN_ESSENCE);
                events.ScheduleEvent(EVENT_ILLIDAN_BREAK, 4000);
                return;
            }

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ILLIDAN_AGGRO:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_1, 100.0f))
                        pIllidan->AI()->Talk(1); // SAY_ILLIDAN_1_AGGRO
                    break;
                case EVENT_CORRUPTING_TOUCH:
                    DoCastVictim(SPELL_CORRUPTING_TOUCH_DMG);
                    events.ScheduleEvent(EVENT_CORRUPTING_TOUCH, urand(13000, 17000));
                    break;
                case EVENT_FEL_FLAMES:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_FEL_FLAMES);
                    events.ScheduleEvent(EVENT_FEL_FLAMES, urand(20000, 30000));
                    break;
                case EVENT_FEL_DECAY:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                        DoCast(pTarget, SPELL_FEL_DECAY);
                    events.ScheduleEvent(EVENT_FEL_DECAY, urand(20000, 30000));
                    break;
                case EVENT_ILLIDAN_BREAK:
                    DoCastAOE(SPELL_FEL_ADLED, true);
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_1, 100.0f))
                    {
                        pIllidan->AI()->Talk(5); // SAY_ILLIDAN_1_SPELL
                        pIllidan->CastSpell(pIllidan, SPELL_CONSUME_ESSENCE);
                        pIllidan->ClearUnitState(UNIT_STATE_CASTING);
                        pIllidan->CastSpell(me, SPELL_ABSORB_FEL_ENERGY);
                    }
                    events.ScheduleEvent(EVENT_CAMOUFLAGE, 6000);
                    break;
                case EVENT_CAMOUFLAGE:
                    phase = 3;
                    Talk(SAY_SPELL_2);
                    DoCast(me, SPELL_CAMOUFLAGE);
                    events.ScheduleEvent(EVENT_ILLIDAN_HIDE, 5000);
                    break;
                case EVENT_ILLIDAN_HIDE:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_1, 100.0f))
                        pIllidan->AI()->Talk(0); // SAY_ILLIDAN_1_HIDE
                    events.ScheduleEvent(EVENT_HUNTING, 2000);
                    break;
                case EVENT_HUNTING:
                    events.ScheduleEvent(EVENT_END_HUNT, 45000);
                    for (float i = 0.0f; i < 2 * float(M_PI); i += (float(M_PI) / 4))
                    {
                        Position pos;
                        pos = me->GetNearPosition(5.0f, i);
                        me->SummonCreature(NPC_HUNTING_SUMMON_CIRCLE, pos);
                        me->SummonCreature(NPC_EYE_OF_PEROTHARN_1, pos);
                    }
                    DoCast(me, SPELL_HUNTING_CHANNEL);
                    break;
                case EVENT_EASY_PREY:
                    phase = 4;
                    events.CancelEvent(EVENT_END_HUNT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(me, SPELL_CAMOUFLAGE_REMOVE, true);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    if (!targetGUID.IsEmpty())
                    {
                        if (Player* pPlayer = ObjectAccessor::GetPlayer(*me, targetGUID))
                        {
                            pPlayer->CastSpell(pPlayer, SPELL_ATTACK_ME_PEROTHARN, true);
                            DoCast(pPlayer, SPELL_TRACKED_LOCK_ON_PLAYER);
                        }
                    }
                    events.ScheduleEvent(EVENT_CORRUPTING_TOUCH, 5000);
                    events.ScheduleEvent(EVENT_FEL_FLAMES, urand(10000, 12000));
                    events.ScheduleEvent(EVENT_FEL_DECAY, urand(12000, 15000));
                    break;
                case EVENT_END_HUNT:
                    events.CancelEvent(EVENT_EASY_PREY);
                    phase = 4;
                    summons.DespawnEntry(NPC_EYE_OF_PEROTHARN_1);
                    summons.DespawnEntry(NPC_HUNTING_SUMMON_CIRCLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(me, SPELL_CAMOUFLAGE_REMOVE, true);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    Talk(SAY_ACHIEVE);
                    bAchieve = true;
                    DoCast(me, SPELL_ENFEEBLED, true);
                    events.ScheduleEvent(EVENT_CORRUPTING_TOUCH, 20000);
                    events.ScheduleEvent(EVENT_FEL_FLAMES, urand(25000, 27000));
                    events.ScheduleEvent(EVENT_FEL_DECAY, urand(27000, 30000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        uint8 phase;
        ObjectGuid targetGUID;
        bool bAchieve;
    };
};

class npc_perotharn_eye_of_perotharn : public CreatureScript
{
public:
    npc_perotharn_eye_of_perotharn() : CreatureScript("npc_perotharn_eye_of_perotharn") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_perotharn_eye_of_perotharnAI(pCreature);
    }

    struct npc_perotharn_eye_of_perotharnAI : public Scripted_NoMovementAI
    {
        npc_perotharn_eye_of_perotharnAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetReactState(REACT_PASSIVE);
            bDespawn = false;
        }

        void Reset() override
        {
            events.Reset();
            me->SetSpeed(MOVE_RUN, 0.5f);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_NEXT_MOVE, urand(500, 2000));
        }

        void MovementInform(uint32 type, uint32 data) override
        {
            if (type == POINT_MOTION_TYPE)
                if (data == POINT_EYE)
                    events.ScheduleEvent(EVENT_NEXT_MOVE, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!bDespawn)
            {
                if (Player* pTarget = me->SelectNearestPlayer(1.0f))
                {
                    bDespawn = true;
                    if (Creature* pPerotharn = me->FindNearestCreature(NPC_PEROTHARN, 300.0f))
                    {
                        pTarget->CastSpell(pTarget, SPELL_EASY_PREY, true);
                        pPerotharn->AI()->SetGUID(pTarget->GetGUID());
                        pPerotharn->AI()->DoAction(ACTION_EASY_PREY);
                    }
                }
            }

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_NEXT_MOVE:
                    me->GetMotionMaster()->MovementExpired();
                    if (urand(0, 1))
                    {
                        if (Creature* pStalker = me->FindNearestCreature(NPC_HUNTING_STALKERS, 100.0f))
                            me->GetMotionMaster()->MovePoint(POINT_EYE, pStalker->GetPositionX(), pStalker->GetPositionY(), pStalker->GetPositionZ());
                    } else
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            me->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
                    }
                    events.ScheduleEvent(EVENT_NEXT_MOVE, urand(7000, 10000));
                    break;
                default:
                    break;
                }
            }
        }

    private:
        EventMap events;
        bool bDespawn;
    };
};

class spell_perotharn_drain_essence : public SpellScriptLoader
{
public:
    spell_perotharn_drain_essence() : SpellScriptLoader("spell_perotharn_drain_essence") { }

    class spell_perotharn_drain_essence_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_perotharn_drain_essence_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetUnitOwner())
                GetUnitOwner()->SetControlled(true, UNIT_STATE_STUNNED);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetUnitOwner())
                GetUnitOwner()->SetControlled(false, UNIT_STATE_STUNNED);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_perotharn_drain_essence_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_PACIFY_SILENCE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_perotharn_drain_essence_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_PACIFY_SILENCE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_perotharn_drain_essence_AuraScript();
    }
};

class spell_perotharn_drain_essence_dmg : public SpellScriptLoader
{
public:
    spell_perotharn_drain_essence_dmg() : SpellScriptLoader("spell_perotharn_drain_essence_dmg") { }

    class spell_perotharn_drain_essence_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_perotharn_drain_essence_dmg_SpellScript);

        void RecalculateDamage()
        {
            SetHitDamage(int32(GetHitUnit()->CountPctFromCurHealth(10)));
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_perotharn_drain_essence_dmg_SpellScript::RecalculateDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_perotharn_drain_essence_dmg_SpellScript();
    }
};

typedef boss_perotharn::boss_perotharnAI PerotharnAI;

class achievement_lazy_eye : public AchievementCriteriaScript
{
public:
    achievement_lazy_eye() : AchievementCriteriaScript("achievement_lazy_eye") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        if (!target)
            return false;

        if (PerotharnAI* perotharnAI = CAST_AI(PerotharnAI, target->GetAI()))
            return perotharnAI->AllowAchieve();

        return false;
    }
};

void AddSC_boss_perotharn()
{
    new boss_perotharn();
    new npc_perotharn_eye_of_perotharn();
    new spell_perotharn_drain_essence();
    new spell_perotharn_drain_essence_dmg();
    new achievement_lazy_eye();
}
