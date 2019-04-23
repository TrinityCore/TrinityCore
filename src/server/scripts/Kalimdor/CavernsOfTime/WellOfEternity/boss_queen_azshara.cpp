/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

enum ScriptedTexts
{
    SAY_AGGRO       = 0,
    SAY_INTERRUPT   = 1,
    SAY_END_1       = 2,
    SAY_END_2       = 3,
    SAY_END_3       = 4,
    SAY_WIPE        = 5,
    SAY_KILL        = 6,
    SAY_PUPPET      = 7,
    SAY_ALL         = 8,
    SAY_ADDS_1      = 9,
    SAY_ADDS_2      = 10,
    SAY_ADDS_3      = 11,
};

enum Spells
{
    SPELL_SERVANT_OF_THE_QUEEN      = 102334,
    SPELL_TOTAL_OBEDIENCE           = 103241,
    SPELL_TOTAL_OBEDIENCE_1         = 110096, // ?

    // Enchanted Magus
    SPELL_ARCANE_SHOCK              = 102463,
    SPELL_HAMMER_OF_DIVINITY_1      = 102454,
    SPELL_HAMMER_OF_DIVINITY_2      = 102454,
    SPELL_HAMMER_OF_DIVINITY_DUMMY  = 102460,
    SPELL_ARCANE_BOMB               = 102455,
    SPELL_ARCANE_BOMB_DUMMY         = 109122,
    SPELL_FIREBALL                  = 102265,
    SPELL_FIREBOMB                  = 102482,
    SPELL_BLASTWAVE                 = 102483,
    SPELL_BLADES_OF_ICE             = 102467,
    SPELL_BLADES_OF_ICE_DMG         = 102468,
    SPELL_ICE_FLING                 = 102478,
    SPELL_COLDFLAME                 = 102465,
    SPELL_COLDFLAME_DMG             = 102466,

    SPELL_PUPPET_CROSS              = 102310,
    SPELL_PUPPET_STRING_HOVER       = 102312,
    SPELL_PUPPET_STRING_DUMMY_1     = 102315,
    SPELL_PUPPET_STRING_DUMMY_2     = 102318,
    SPELL_PUPPET_STRING_DUMMY_3     = 102319,
    SPELL_PUPPET_STRING_SCRIPT_1    = 102333,
    SPELL_PUPPET_STRING_SCRIPT_2    = 102345,
};

enum Adds
{
    NPC_HAND_OF_QUEEN           = 54728,
    NPC_ENCHANTED_MAGUS_ARCANE  = 54884,
    NPC_ENCHANTED_MAGUS_FIRE    = 54882,
    NPC_ENCHANTED_MAGUS_FROST   = 54883,
    NPC_HAMMER_OF_DIVINITY_1    = 54864,
    NPC_HAMMER_OF_DIVINITY_2    = 54865,
};

enum Events
{
    EVENT_ADDS_1                = 1,
    EVENT_ADDS_2                = 2,
    EVENT_ADDS_3                = 3,
    EVENT_SERVANT_OF_THE_QUEEN  = 4,
    EVENT_TOTAL_OBEDIENCE       = 5,
    EVENT_END                   = 6,
    EVENT_ARCANE_SHOCK          = 7,
    EVENT_ARCANE_BOMB           = 8,
    EVENT_FIREBALL              = 9,
    EVENT_FIREBOMB              = 10,
    EVENT_BLASTWAVE             = 11,
    EVENT_BLADES_OF_ICE         = 12,
    EVENT_COLDFLAME             = 13,
    EVENT_ICE_FLING             = 14,
};

enum Actions
{
    ACTION_ATTACK   = 1,
};

const Position addsPos[6] =
{
    {3453.030029f, -5282.740234f, 230.04f, 4.45f}, // fire 1
    {3443.540039f, -5280.370117f, 230.04f, 4.66f}, // frost 1
    {3461.139893f, -5283.169922f, 230.04f, 4.31f}, // arcane 1
    {3435.590088f, -5278.350098f, 230.04f, 4.50f}, // fire 2
    {3469.729980f, -5282.430176f, 230.04f, 4.53f}, // frost 2
    {3428.43f,     -5274.59f,     230.04f, 4.20f}  // arcane 2
};

const uint32 addsEntry[6] =
{
    NPC_ENCHANTED_MAGUS_FIRE,
    NPC_ENCHANTED_MAGUS_FROST,
    NPC_ENCHANTED_MAGUS_ARCANE,
    NPC_ENCHANTED_MAGUS_FIRE,
    NPC_ENCHANTED_MAGUS_FROST,
    NPC_ENCHANTED_MAGUS_ARCANE
};

class boss_queen_azshara : public CreatureScript
{
public:
    boss_queen_azshara() : CreatureScript("boss_queen_azshara") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_queen_azsharaAI(pCreature);
    }

    struct boss_queen_azsharaAI : public BossAI
    {
        boss_queen_azsharaAI(Creature* pCreature) : BossAI(pCreature, DATA_AZSHARA)
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

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }

        void InitializeAI() override
        {
            if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(WoEScriptName))
                me->IsAIEnabled = false;
            else if (!me->isDead())
                Reset();
        }

        void Reset() override
        {
            _Reset();

            memset(addsGUIDs, 0, sizeof(addsGUIDs));

            for (uint8 i = 0; i < 6; ++i)
                if (Creature* pAdd = me->SummonCreature(addsEntry[i], addsPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
                    addsGUIDs[i] = pAdd->GetGUID();

            addsCount = 0;
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            Talk(SAY_AGGRO);

            addsCount = 0;

            events.RescheduleEvent(EVENT_ADDS_1, 11000);

            DoZoneInCombat();
            instance->SetBossState(DATA_AZSHARA, IN_PROGRESS);
        }

        void JustReachedHome() override
        {
            Talk(SAY_WIPE);
            addsCount = 0;
        }

        void AttackStart(Unit* who) override
        {
            if(who)
                me->Attack(who, false);
        }

        void KilledUnit(Unit* who) override
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                Talk(SAY_INTERRUPT);
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (!me->IsInCombat())
                return;

            if (summon->GetEntry() == NPC_ENCHANTED_MAGUS_FIRE ||
                summon->GetEntry() == NPC_ENCHANTED_MAGUS_ARCANE ||
                summon->GetEntry() == NPC_ENCHANTED_MAGUS_FROST)
                addsCount++;

            if ((addsCount == 2) || (addsCount == 4))
                events.ScheduleEvent(EVENT_ADDS_1, 6000);
            else if (addsCount == 6)
            {
                events.Reset();
                me->InterruptNonMeleeSpells(false);
                Talk(SAY_END_1);
                events.ScheduleEvent(EVENT_END, 6000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TOTAL_OBEDIENCE:
                    Talk(SAY_ALL);
                    //DoCastAOE(SPELL_TOTAL_OBEDIENCE);
                    break;
                case EVENT_ADDS_1:
                    Talk((addsCount / 2) + 9);
                    events.RescheduleEvent(EVENT_ADDS_2, 7000);
                    break;
                case EVENT_ADDS_2:
                    if (Creature* pAdd = ObjectAccessor::GetCreature(*me, addsGUIDs[addsCount]))
                        pAdd->AI()->Talk(addsCount / 2);
                    events.RescheduleEvent(EVENT_ADDS_3, 6000);
                    break;
                case EVENT_ADDS_3:
                    for (uint8 i = addsCount; i < (addsCount + 2); ++i)
                    {
                        if (Creature* pAdd = ObjectAccessor::GetCreature(*me, addsGUIDs[i]))
                        {
                            pAdd->SetReactState(REACT_AGGRESSIVE);
                            pAdd->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            DoZoneInCombat(pAdd);
                            pAdd->AI()->DoAction(ACTION_ATTACK);
                        }
                    }
                    events.ScheduleEvent(EVENT_TOTAL_OBEDIENCE, urand(10000, 20000));
                    break;
                case EVENT_END:
                {
                    me->SummonGameObject(210025, 3465.447f, -5238.09f, 230.575f, 4.54f, QuaternionData(), 200000);
                    if (me->GetMap()->IsHeroic())
                    {
                        if (!me->GetMap()->GetPlayers().isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = me->GetMap()->GetPlayers().begin(); i != me->GetMap()->GetPlayers().end(); ++i)
                            {
                                if (!i->GetSource())
                                    continue;

                                i->GetSource()->KilledMonsterCredit(NPC_AZSHARA);
                                i->GetSource()->ModifyCurrency(CURRENCY_TYPE_JUSTICE_POINTS, 7000);
                            }
                        }
                    }

                    instance->SetBossState(DATA_AZSHARA, DONE);
                    //instance->DespawnObjects(instance->GetGuidData(DATA_ROYAL_CACHE), DAY);
                    //player->ModifyCurrency(CURRENCY_TYPE_JUSTICE_POINTS, 7000);
                    me->DespawnOrUnsummon();
                    break;
                }
                default:
                    break;
                }
            }
        }
    private:
        EventMap events;
        ObjectGuid addsGUIDs[6];
        uint8 addsCount;
    };
};

class npc_queen_azshara_enchanted_magus : public CreatureScript
{
public:
    npc_queen_azshara_enchanted_magus() : CreatureScript("npc_queen_azshara_enchanted_magus") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_queen_azshara_enchanted_magusAI(pCreature);
    }

    struct npc_queen_azshara_enchanted_magusAI : public ScriptedAI
    {
        npc_queen_azshara_enchanted_magusAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void Reset() override
        {
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_ATTACK)
            {
                if (me->GetEntry() == NPC_ENCHANTED_MAGUS_FIRE)
                {
                    events.ScheduleEvent(EVENT_FIREBALL, 1000);
                    events.ScheduleEvent(EVENT_FIREBOMB, urand(10000, 15000));
                    events.ScheduleEvent(EVENT_BLASTWAVE, urand(10000, 20000));
                } else if (me->GetEntry() == NPC_ENCHANTED_MAGUS_FROST)
                {
                    events.ScheduleEvent(EVENT_BLADES_OF_ICE, urand(5000, 10000));
                    events.ScheduleEvent(EVENT_COLDFLAME, urand(12000, 20000));
                    events.ScheduleEvent(EVENT_ICE_FLING, urand(2000, 15000));
                } else if (me->GetEntry() == NPC_ENCHANTED_MAGUS_ARCANE)
                {
                    events.ScheduleEvent(EVENT_ARCANE_SHOCK, urand(10000, 15000));
                    events.ScheduleEvent(EVENT_ARCANE_BOMB, urand(5000, 10000));
                }
            }
        }

        /*void MovementInform(uint32 type, uint32 data) override
        {
        if (me->GetEntry() == NPC_ENCHANTED_MAGUS_FROST && data == EVENT_CHARGE)
        if (Player* pPlayer = me->SelectNearestPlayer(5.0f))
        DoCast(pPlayer, SPELL_BLADES_OF_ICE_DMG, true);
        }*/

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIREBALL:
                    DoCastVictim(SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 3000);
                    break;
                case EVENT_FIREBOMB:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_FIREBOMB);
                    events.ScheduleEvent(EVENT_FIREBOMB, urand(15000, 20000));
                    break;
                case EVENT_BLASTWAVE:
                    DoCastAOE(SPELL_BLASTWAVE);
                    events.ScheduleEvent(EVENT_BLASTWAVE, urand(15000, 20000));
                    break;
                case EVENT_ICE_FLING:
                    DoCastAOE(SPELL_ICE_FLING);
                    events.ScheduleEvent(EVENT_ICE_FLING, urand(10000, 20000));
                    break;
                case EVENT_BLADES_OF_ICE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_BLADES_OF_ICE);
                    events.ScheduleEvent(EVENT_BLADES_OF_ICE, urand(12000, 20000));
                    break;
                case EVENT_COLDFLAME:
                    //if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    //DoCast(pTarget, SPELL_COLDFLAME);
                    events.ScheduleEvent(EVENT_COLDFLAME, urand(16000, 25000));
                    break;
                case EVENT_ARCANE_SHOCK:
                    me->StopMoving();
                    DoCast(me, SPELL_ARCANE_SHOCK);
                    events.ScheduleEvent(EVENT_ARCANE_SHOCK, urand(12000, 20000));
                    break;
                case EVENT_ARCANE_BOMB:
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            Creature* pStalker1 = me->SummonCreature(NPC_HAMMER_OF_DIVINITY_2, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), pTarget->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                            Creature* pStalker2 = me->SummonCreature(NPC_HAMMER_OF_DIVINITY_1, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ() + 30.0f, pTarget->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);

                            if (pStalker1 && pStalker2)
                                pStalker2->GetMotionMaster()->MovePoint(0, pStalker1->GetPositionX(), pStalker1->GetPositionY(), pStalker1->GetPositionZ());
                        }
                        events.ScheduleEvent(EVENT_ARCANE_BOMB, urand(18000, 25000));
                        break;
                    }
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };
};

class npc_queen_azshara_hammer_of_divinity : public CreatureScript
{
public:
    npc_queen_azshara_hammer_of_divinity() : CreatureScript("npc_queen_azshara_hammer_of_divinity") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_queen_azshara_hammer_of_divinityAI(pCreature);
    }

    struct npc_queen_azshara_hammer_of_divinityAI : public Scripted_NoMovementAI
    {
        npc_queen_azshara_hammer_of_divinityAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            bDespawn = false;
            me->SetSpeed(MOVE_RUN, 0.1f);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (bDespawn)
                return;

            if (Creature* pStalker = me->FindNearestCreature(NPC_HAMMER_OF_DIVINITY_2, 1.0f))
            {
                bDespawn = true;
                DoCastAOE(SPELL_ARCANE_BOMB);
                pStalker->DespawnOrUnsummon(500);
                me->DespawnOrUnsummon(500);
            }
        }
    private:
        bool bDespawn;
    };
};

class spell_queen_azshara_coldflame : public SpellScriptLoader
{
public:
    spell_queen_azshara_coldflame() : SpellScriptLoader("spell_queen_azshara_coldflame") { }

    class spell_queen_azshara_coldflame_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_queen_azshara_coldflame_AuraScript);

        bool Load() override
        {
            count = 0;
            return true;
        }

        void PeriodicTick(AuraEffect const* /*aurEff*/)
        {
            if (!GetCaster())
                return;

            count++;

            if (count > 11)
            {
                GetCaster()->RemoveAura(SPELL_COLDFLAME);
                return;
            }

            Position pos;
            pos = GetCaster()->GetNearPosition(3.0f * (count / 2), 0.0f);
            GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_COLDFLAME_DMG, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_queen_azshara_coldflame_AuraScript::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }

    private:
        uint8 count;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_queen_azshara_coldflame_AuraScript();
    }
};

class spell_queen_azshara_arcane_bomb : public SpellScriptLoader
{
public:
    spell_queen_azshara_arcane_bomb() : SpellScriptLoader("spell_queen_azshara_arcane_bomb") { }

    class spell_queen_azshara_arcane_bomb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_queen_azshara_arcane_bomb_SpellScript);

        void ChangeSummonPos(SpellEffIndex /*effIndex*/)
        {
            WorldLocation summonPos = *GetExplTargetDest();
            Position offset = {0.0f, 0.0f, 15.0f, 0.0f};
            summonPos.RelocateOffset(offset);
            SetExplTargetDest(summonPos);
            GetHitDest()->RelocateOffset(offset);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_queen_azshara_arcane_bomb_SpellScript::ChangeSummonPos, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };


    SpellScript* GetSpellScript() const override
    {
        return new spell_queen_azshara_arcane_bomb_SpellScript();
    }
};

void AddSC_boss_queen_azshara()
{
    new boss_queen_azshara();
    new npc_queen_azshara_enchanted_magus();
    new npc_queen_azshara_hammer_of_divinity();
    new spell_queen_azshara_coldflame();
    //new spell_queen_azshara_arcane_bomb();
}
