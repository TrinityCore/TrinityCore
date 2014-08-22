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
#include "zulaman.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_DUAL_WIELD            = 29651,
    SPELL_SABER_LASH            = 43267,
    SPELL_FRENZY                = 43139,
    SPELL_FLAMESHOCK            = 43303,
    SPELL_EARTHSHOCK            = 43305,
    SPELL_TRANSFORM_SPLIT       = 43142,
    SPELL_TRANSFORM_SPLIT2      = 43573,
    SPELL_TRANSFORM_MERGE       = 43271,
    SPELL_SUMMON_LYNX           = 43143,
    SPELL_SUMMON_TOTEM          = 43302,
    SPELL_BERSERK               = 45078,
    SPELL_LYNX_FRENZY           = 43290, // Used by Spirit Lynx
    SPELL_SHRED_ARMOR           = 43243  // Used by Spirit Lynx
};

enum Hal_CreatureIds
{
    NPC_SPIRIT_LYNX             = 24143,
    NPC_TOTEM                   = 24224
};

enum PhaseHalazzi
{
    PHASE_NONE                  = 0,
    PHASE_LYNX                  = 1,
    PHASE_SPLIT                 = 2,
    PHASE_HUMAN                 = 3,
    PHASE_MERGE                 = 4,
    PHASE_ENRAGE                = 5
};

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_SABER                   = 1,
    SAY_SPLIT                   = 2,
    SAY_MERGE                   = 3,
    SAY_KILL                    = 4,
    SAY_DEATH                   = 5,
    SAY_BERSERK                 = 6
};

class boss_halazzi : public CreatureScript
{
    public:
        boss_halazzi() : CreatureScript("boss_halazzi") { }

        struct boss_halazziAI : public ScriptedAI
        {
            boss_halazziAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            SummonList summons;
            PhaseHalazzi Phase;

            uint32 FrenzyTimer;
            uint32 SaberlashTimer;
            uint32 ShockTimer;
            uint32 TotemTimer;
            uint32 CheckTimer;
            uint32 BerserkTimer;
            uint32 TransformCount;

            uint64 LynxGUID;

            void Reset() override
            {
                instance->SetData(DATA_HALAZZIEVENT, NOT_STARTED);
                summons.DespawnAll();

                LynxGUID = 0;
                TransformCount = 0;
                BerserkTimer = 600000;
                CheckTimer = 1000;

                DoCast(me, SPELL_DUAL_WIELD, true);

                Phase = PHASE_NONE;
                EnterPhase(PHASE_LYNX);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                instance->SetData(DATA_HALAZZIEVENT, IN_PROGRESS);
                Talk(SAY_AGGRO);
                EnterPhase(PHASE_LYNX);
            }

            void JustSummoned(Creature* summon) override
            {
                summon->AI()->AttackStart(me->GetVictim());
                if (summon->GetEntry() == NPC_SPIRIT_LYNX)
                    LynxGUID = summon->GetGUID();
                summons.Summon(summon);
            }

            void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
            {
                if (damage >= me->GetHealth() && Phase != PHASE_ENRAGE)
                    damage = 0;
            }

            void SpellHit(Unit*, const SpellInfo* spell) override
            {
                if (spell->Id == SPELL_TRANSFORM_SPLIT2)
                    EnterPhase(PHASE_HUMAN);
            }

            void AttackStart(Unit* who) override
            {
                if (Phase != PHASE_MERGE)
                    ScriptedAI::AttackStart(who);
            }

            void EnterPhase(PhaseHalazzi NextPhase)
            {
                switch (NextPhase)
                {
                case PHASE_LYNX:
                case PHASE_ENRAGE:
                    if (Phase == PHASE_MERGE)
                    {
                        DoCast(me, SPELL_TRANSFORM_MERGE, true);
                        me->Attack(me->GetVictim(), true);
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                    }
                    if (Creature* Lynx = ObjectAccessor::GetCreature(*me, LynxGUID))
                        Lynx->DisappearAndDie();
                    me->SetMaxHealth(600000);
                    me->SetHealth(600000 - 150000 * TransformCount);
                    FrenzyTimer = 16000;
                    SaberlashTimer = 20000;
                    ShockTimer = 10000;
                    TotemTimer = 12000;
                    break;
                case PHASE_SPLIT:
                    Talk(SAY_SPLIT);
                    DoCast(me, SPELL_TRANSFORM_SPLIT, true);
                    break;
                case PHASE_HUMAN:
                    //DoCast(me, SPELL_SUMMON_LYNX, true);
                    DoSpawnCreature(NPC_SPIRIT_LYNX, 5, 5, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    me->SetMaxHealth(400000);
                    me->SetHealth(400000);
                    ShockTimer = 10000;
                    TotemTimer = 12000;
                    break;
                case PHASE_MERGE:
                    if (Unit* pLynx = ObjectAccessor::GetUnit(*me, LynxGUID))
                    {
                        Talk(SAY_MERGE);
                        pLynx->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pLynx->GetMotionMaster()->Clear();
                        pLynx->GetMotionMaster()->MoveFollow(me, 0, 0);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveFollow(pLynx, 0, 0);
                        ++TransformCount;
                    }
                    break;
                default:
                    break;
                }
                Phase = NextPhase;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (BerserkTimer <= diff)
                {
                    Talk(SAY_BERSERK);
                    DoCast(me, SPELL_BERSERK, true);
                    BerserkTimer = 60000;
                } else BerserkTimer -= diff;

                if (Phase == PHASE_LYNX || Phase == PHASE_ENRAGE)
                {
                    if (SaberlashTimer <= diff)
                    {
                        // A tank with more than 490 defense skills should receive no critical hit
                        //DoCast(me, 41296, true);
                        DoCastVictim(SPELL_SABER_LASH, true);
                        //me->RemoveAurasDueToSpell(41296);
                        SaberlashTimer = 30000;
                    } else SaberlashTimer -= diff;

                    if (FrenzyTimer <= diff)
                    {
                        DoCast(me, SPELL_FRENZY);
                        FrenzyTimer = urand(10000, 15000);
                    } else FrenzyTimer -= diff;

                    if (Phase == PHASE_LYNX)
                    {
                        if (CheckTimer <= diff)
                        {
                            if (HealthBelowPct(25 * (3 - TransformCount)))
                                EnterPhase(PHASE_SPLIT);
                            CheckTimer = 1000;
                        } else CheckTimer -= diff;
                    }
                }

                if (Phase == PHASE_HUMAN || Phase == PHASE_ENRAGE)
                {
                    if (TotemTimer <= diff)
                    {
                        DoCast(me, SPELL_SUMMON_TOTEM);
                        TotemTimer = 20000;
                    } else TotemTimer -= diff;

                    if (ShockTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            if (target->IsNonMeleeSpellCast(false))
                                DoCast(target, SPELL_EARTHSHOCK);
                            else
                                DoCast(target, SPELL_FLAMESHOCK);
                            ShockTimer = urand(10000, 15000);
                        }
                    } else ShockTimer -= diff;

                    if (Phase == PHASE_HUMAN)
                    {
                        if (CheckTimer <= diff)
                        {
                            if (!HealthAbovePct(20) /*HealthBelowPct(10)*/)
                                EnterPhase(PHASE_MERGE);
                            else
                            {
                                Unit* Lynx = ObjectAccessor::GetUnit(*me, LynxGUID);
                                if (Lynx && !Lynx->HealthAbovePct(20) /*Lynx->HealthBelowPct(10)*/)
                                    EnterPhase(PHASE_MERGE);
                            }
                            CheckTimer = 1000;
                        } else CheckTimer -= diff;
                    }
                }

                if (Phase == PHASE_MERGE)
                {
                    if (CheckTimer <= diff)
                    {
                        Unit* Lynx = ObjectAccessor::GetUnit(*me, LynxGUID);
                        if (Lynx)
                        {
                            Lynx->GetMotionMaster()->MoveFollow(me, 0, 0);
                            me->GetMotionMaster()->MoveFollow(Lynx, 0, 0);
                            if (me->IsWithinDistInMap(Lynx, 6.0f))
                            {
                                if (TransformCount < 3)
                                    EnterPhase(PHASE_LYNX);
                                else
                                    EnterPhase(PHASE_ENRAGE);
                            }
                        }
                        CheckTimer = 1000;
                    } else CheckTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SetData(DATA_HALAZZIEVENT, DONE);
                Talk(SAY_DEATH);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_halazziAI>(creature);
        }
};

// Spirits Lynx AI
class npc_halazzi_lynx : public CreatureScript
{
    public:
        npc_halazzi_lynx() : CreatureScript("npc_halazzi_lynx") { }

        struct npc_halazzi_lynxAI : public ScriptedAI
        {
            npc_halazzi_lynxAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 FrenzyTimer;
            uint32 shredder_timer;

            void Reset() override
            {
                FrenzyTimer = urand(30000, 50000);  //frenzy every 30-50 seconds
                shredder_timer = 4000;
            }

            void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                    damage = 0;
            }

            void AttackStart(Unit* who) override
            {
                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    ScriptedAI::AttackStart(who);
            }

            void EnterCombat(Unit* /*who*/) override {/*DoZoneInCombat();*/ }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (FrenzyTimer <= diff)
                {
                    DoCast(me, SPELL_LYNX_FRENZY);
                    FrenzyTimer = urand(30000, 50000);  //frenzy every 30-50 seconds
                } else FrenzyTimer -= diff;

                if (shredder_timer <= diff)
                {
                    DoCastVictim(SPELL_SHRED_ARMOR);
                    shredder_timer = 4000;
                } else shredder_timer -= diff;

                DoMeleeAttackIfReady();
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_halazzi_lynxAI(creature);
        }
};

void AddSC_boss_halazzi()
{
    new boss_halazzi();
    new npc_halazzi_lynx();
}
