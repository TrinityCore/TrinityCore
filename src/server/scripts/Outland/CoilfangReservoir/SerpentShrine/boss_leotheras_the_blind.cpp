/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Leotheras_The_Blind
SD%Complete: 80
SDComment: Possesion Support
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "ScriptPCH.h"
#include "serpent_shrine.h"

// --- Spells used by Leotheras The Blind
#define SPELL_WHIRLWIND         37640
#define SPELL_CHAOS_BLAST       37674
#define SPELL_BERSERK           26662
#define SPELL_INSIDIOUS_WHISPER 37676
#define SPELL_DUAL_WIELD        42459

// --- Spells used in banish phase ---
#define BANISH_BEAM             38909
#define AURA_BANISH             37833

// --- Spells used by Greyheart Spellbinders
#define SPELL_EARTHSHOCK        39076
#define SPELL_MINDBLAST         37531

// --- Spells used by Inner Demons and Creature ID
#define INNER_DEMON_ID          21857
#define AURA_DEMONIC_ALIGNMENT  37713
#define SPELL_SHADOWBOLT        39309
#define SPELL_SOUL_LINK         38007
#define SPELL_CONSUMING_MADNESS 37749 //not supported by core yet

//Misc.
#define MODEL_DEMON             20125
#define MODEL_NIGHTELF          20514
#define DEMON_FORM              21875
#define MOB_SPELLBINDER         21806

#define SAY_AGGRO               -1548009
#define SAY_SWITCH_TO_DEMON     -1548010
#define SAY_INNER_DEMONS        -1548011
#define SAY_DEMON_SLAY1         -1548012
#define SAY_DEMON_SLAY2         -1548013
#define SAY_DEMON_SLAY3         -1548014
#define SAY_NIGHTELF_SLAY1      -1548015
#define SAY_NIGHTELF_SLAY2      -1548016
#define SAY_NIGHTELF_SLAY3      -1548017
#define SAY_FINAL_FORM          -1548018
#define SAY_FREE                -1548019
#define SAY_DEATH               -1548020

class mob_inner_demon : public CreatureScript
{
public:
    mob_inner_demon() : CreatureScript("mob_inner_demon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_inner_demonAI (pCreature);
    }

    struct mob_inner_demonAI : public ScriptedAI
    {
        mob_inner_demonAI(Creature *c) : ScriptedAI(c)
        {
            victimGUID = 0;
        }

        uint32 ShadowBolt_Timer;

        uint32 Link_Timer;
        uint64 victimGUID;

        void Reset()
        {
            ShadowBolt_Timer = 10000;
            Link_Timer = 1000;
        }
        void JustDied(Unit* /*victim*/)
        {
            Unit* pUnit = Unit::GetUnit((*me), victimGUID);
            if (pUnit && pUnit->HasAura(SPELL_INSIDIOUS_WHISPER))
                pUnit->RemoveAurasDueToSpell(SPELL_INSIDIOUS_WHISPER);
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (done_by->GetGUID() != victimGUID && done_by->GetGUID() != me->GetGUID())
            {
                damage = 0;
                DoModifyThreatPercent(done_by, -100);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (!victimGUID) return;
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (me->getVictim()->GetGUID() != victimGUID)
            {
                DoModifyThreatPercent(me->getVictim(), -100);
                Unit* owner = Unit::GetUnit((*me), victimGUID);
                if (owner && owner->isAlive())
                {
                    me->AddThreat(owner, 999999);
                    AttackStart(owner);
                } else if (owner && owner->isDead())
                {
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    return;
                }
            }

            if (Link_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SOUL_LINK, true);
                Link_Timer = 1000;
            } else Link_Timer -= diff;

            if (!me->HasAura(AURA_DEMONIC_ALIGNMENT))
                DoCast(me, AURA_DEMONIC_ALIGNMENT, true);

            if (ShadowBolt_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHADOWBOLT, false);
                ShadowBolt_Timer = 10000;
            } else ShadowBolt_Timer -= diff;

           DoMeleeAttackIfReady();
        }
    };

};

//Original Leotheras the Blind AI
class boss_leotheras_the_blind : public CreatureScript
{
public:
    boss_leotheras_the_blind() : CreatureScript("boss_leotheras_the_blind") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_leotheras_the_blindAI (pCreature);
    }

    struct boss_leotheras_the_blindAI : public ScriptedAI
    {
        boss_leotheras_the_blindAI(Creature *c) : ScriptedAI(c)
        {
            c->GetPosition(x, y, z);
            pInstance = c->GetInstanceScript();
            Demon = 0;

            for (uint8 i = 0; i < 3; ++i)//clear guids
                SpellBinderGUID[i] = 0;
        }

        InstanceScript *pInstance;

        uint32 Whirlwind_Timer;
        uint32 ChaosBlast_Timer;
        uint32 SwitchToDemon_Timer;
        uint32 SwitchToHuman_Timer;
        uint32 Berserk_Timer;
        uint32 InnerDemons_Timer;
        uint32 BanishTimer;

        bool DealDamage;
        bool NeedThreatReset;
        bool DemonForm;
        bool IsFinalForm;
        bool EnrageUsed;
        float x, y, z;

        uint64 InnderDemon[5];
        uint32 InnerDemon_Count;
        uint64 Demon;
        uint64 SpellBinderGUID[3];

        void Reset()
        {
            CheckChannelers();
            BanishTimer = 1000;
            Whirlwind_Timer = 15000;
            ChaosBlast_Timer = 1000;
            SwitchToDemon_Timer = 45000;
            SwitchToHuman_Timer = 60000;
            Berserk_Timer = 600000;
            InnerDemons_Timer = 30000;
            me->SetCanDualWield(true);
            DealDamage = true;
            DemonForm = false;
            IsFinalForm = false;
            NeedThreatReset = false;
            EnrageUsed = false;
            InnerDemon_Count = 0;
            me->SetSpeed(MOVE_RUN, 2.0f, true);
            me->SetDisplayId(MODEL_NIGHTELF);
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
            DoCast(me, SPELL_DUAL_WIELD, true);
            me->SetCorpseDelay(1000*60*60);
            if (pInstance)
                pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, NOT_STARTED);
        }

        void CheckChannelers(/*bool DoEvade = true*/)
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                if (Creature *add = Unit::GetCreature(*me, SpellBinderGUID[i]))
                    add->DisappearAndDie();

                float nx = x;
                float ny = y;
                float o = 2.4f;
                if (i == 0) {nx += 10; ny -= 5; o=2.5f;}
                if (i == 1) {nx -= 8; ny -= 7; o=0.9f;}
                if (i == 2) {nx -= 3; ny += 9; o=5.0f;}
                Creature* binder = me->SummonCreature(MOB_SPELLBINDER, nx, ny, z, o, TEMPSUMMON_DEAD_DESPAWN, 0);
                if (binder)
                    SpellBinderGUID[i] = binder->GetGUID();

            }
        }
        void MoveInLineOfSight(Unit *who)
        {
            if (me->HasAura(AURA_BANISH))
                return;

            if (!me->getVictim() && who->isTargetableForAttack() && (me->IsHostileTo(who)) && who->isInAccessiblePlaceFor(me))
            {
                if (me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                    return;

                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius))
                {
                    // Check first that object is in an angle in front of this one before LoS check
                    if (me->HasInArc(M_PI/2.0f, who) && me->IsWithinLOSInMap(who))
                    {
                        AttackStart(who);
                    }
                }
            }
        }

        void StartEvent()
        {
            DoScriptText(SAY_AGGRO, me);
            if (pInstance)
                pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, IN_PROGRESS);
        }

        void CheckBanish()
        {
            uint8 AliveChannelers = 0;
            for (uint8 i = 0; i < 3; ++i)
            {
                Unit *add = Unit::GetUnit(*me, SpellBinderGUID[i]);
                if (add && add->isAlive())
                    ++AliveChannelers;
            }

            // channelers == 0 remove banish aura
            if (AliveChannelers == 0 && me->HasAura(AURA_BANISH))
            {
                // removing banish aura
                me->RemoveAurasDueToSpell(AURA_BANISH);

                // Leotheras is getting immune again
                me->ApplySpellImmune(AURA_BANISH, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);

                // changing model to bloodelf
                me->SetDisplayId(MODEL_NIGHTELF);

                // and reseting equipment
                me->LoadEquipment(me->GetEquipmentId());

                if (pInstance && pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER))
                {
                    Unit *victim = NULL;
                    victim = Unit::GetUnit(*me, pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER));
                    if (victim)
                        me->getThreatManager().addThreat(victim, 1);
                    StartEvent();
                }
            }
            else if (AliveChannelers != 0 && !me->HasAura(AURA_BANISH))
            {
                // channelers != 0 apply banish aura
                // removing Leotheras banish immune to apply AURA_BANISH
                me->ApplySpellImmune(AURA_BANISH, IMMUNITY_MECHANIC, MECHANIC_BANISH, false);
                DoCast(me, AURA_BANISH);

                // changing model
                me->SetDisplayId(MODEL_DEMON);

                // and removing weapons
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
            }
        }

        //Despawn all Inner Demon summoned
        void DespawnDemon()
        {
            for (uint8 i=0; i<5; ++i)
            {
                if (InnderDemon[i])
                {
                        //delete creature
                        Creature* pCreature = Unit::GetCreature((*me), InnderDemon[i]);
                        if (pCreature && pCreature->isAlive())
                        {
                            pCreature->DespawnOrUnsummon();
                        }
                        InnderDemon[i] = 0;
                }
            }

            InnerDemon_Count = 0;
        }

        void CastConsumingMadness() //remove this once SPELL_INSIDIOUS_WHISPER is supported by core
        {
            for (uint8 i=0; i<5; ++i)
            {
                if (InnderDemon[i] > 0)
                {
                    Creature* pUnit = Unit::GetCreature((*me), InnderDemon[i]);
                    if (pUnit && pUnit->isAlive())
                    {
                        Unit* pUnit_pTarget = Unit::GetUnit(*pUnit, CAST_AI(mob_inner_demon::mob_inner_demonAI, pUnit->AI())->victimGUID);
                        if (pUnit_pTarget && pUnit_pTarget->isAlive())
                        {
                            pUnit->CastSpell(pUnit_pTarget, SPELL_CONSUMING_MADNESS, true);
                            DoModifyThreatPercent(pUnit_pTarget, -100);
                        }
                    }
                }
            }
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            if (DemonForm)
            {
                DoScriptText(RAND(SAY_DEMON_SLAY1, SAY_DEMON_SLAY2, SAY_DEMON_SLAY3), me);
            }
            else
            {
                DoScriptText(RAND(SAY_NIGHTELF_SLAY1, SAY_NIGHTELF_SLAY2, SAY_NIGHTELF_SLAY3), me);
            }
        }

        void JustDied(Unit* /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);

            //despawn copy
            if (Demon)
            {
                if (Creature* pDemon = Unit::GetCreature(*me, Demon))
                    pDemon->DespawnOrUnsummon();
            }
            if (pInstance)
                pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, DONE);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (me->HasAura(AURA_BANISH))
            return;

            me->LoadEquipment(me->GetEquipmentId());
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (me->HasAura(AURA_BANISH) || !UpdateVictim())
            {
                if (BanishTimer <= diff)
                {
                    CheckBanish();//no need to check every update tick
                    BanishTimer = 1000;
                } else BanishTimer -= diff;
                return;
            }
            if (me->HasAura(SPELL_WHIRLWIND))
            {
                if (Whirlwind_Timer <= diff)
                {
                    Unit *newTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (newTarget)
                    {
                        DoResetThreat();
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, newTarget->GetPositionX(), newTarget->GetPositionY(), newTarget->GetPositionZ());
                    }
                    Whirlwind_Timer = 2000;
                } else Whirlwind_Timer -= diff;
            }

            // reseting after changing forms and after ending whirlwind
            if (NeedThreatReset && !me->HasAura(SPELL_WHIRLWIND))
            {
                // when changing forms seting timers (or when ending whirlwind - to avoid adding new variable i use Whirlwind_Timer to countdown 2s while whirlwinding)
                if (DemonForm)
                    InnerDemons_Timer = 30000;
                else
                    Whirlwind_Timer =  15000;

                NeedThreatReset = false;
                DoResetThreat();
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(me->getVictim());
            }

            //Enrage_Timer (10 min)
            if (Berserk_Timer < diff && !EnrageUsed)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me, SPELL_BERSERK);
                EnrageUsed = true;
            } else Berserk_Timer -= diff;

            if (!DemonForm)
            {
                //Whirldind Timer
                if (!me->HasAura(SPELL_WHIRLWIND))
                {
                    if (Whirlwind_Timer <= diff)
                    {
                        DoCast(me, SPELL_WHIRLWIND);
                        // while whirlwinding this variable is used to countdown target's change
                        Whirlwind_Timer = 2000;
                        NeedThreatReset = true;
                    } else Whirlwind_Timer -= diff;
                }
                //Switch_Timer

                if (!IsFinalForm)
                {
                    if (SwitchToDemon_Timer <= diff)
                    {
                        //switch to demon form
                        me->RemoveAurasDueToSpell(SPELL_WHIRLWIND, 0);
                        me->SetDisplayId(MODEL_DEMON);
                        DoScriptText(SAY_SWITCH_TO_DEMON, me);
                        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
                        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
                        DemonForm = true;
                        NeedThreatReset = true;
                        SwitchToDemon_Timer = 45000;
                    } else SwitchToDemon_Timer -= diff;
                }
                DoMeleeAttackIfReady();
            }
            else
            {
                //ChaosBlast_Timer
                if (!me->getVictim())
                    return;
                if (me->IsWithinDist(me->getVictim(), 30))
                    me->StopMoving();
                if (ChaosBlast_Timer <= diff)
                {
                    // will cast only when in range of spell
                    if (me->IsWithinDist(me->getVictim(), 30))
                    {
                        //DoCast(me->getVictim(), SPELL_CHAOS_BLAST, true);
                        int damage = 100;
                        me->CastCustomSpell(me->getVictim(), SPELL_CHAOS_BLAST, &damage, NULL, NULL, false, NULL, NULL, me->GetGUID());
                    }
                    ChaosBlast_Timer = 3000;
                } else ChaosBlast_Timer -= diff;
                //Summon Inner Demon
                if (InnerDemons_Timer <= diff)
                {
                    std::list<HostileReference *>& ThreatList = me->getThreatManager().getThreatList();
                    std::vector<Unit *> TargetList;
                    for (std::list<HostileReference *>::const_iterator itr = ThreatList.begin(); itr != ThreatList.end(); ++itr)
                    {
                        Unit *tempTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                        if (tempTarget && tempTarget->GetTypeId() == TYPEID_PLAYER && tempTarget->GetGUID() != me->getVictim()->GetGUID() && TargetList.size()<5)
                            TargetList.push_back(tempTarget);
                    }
                    //SpellEntry *spell = GET_SPELL(SPELL_INSIDIOUS_WHISPER);
                    for (std::vector<Unit *>::const_iterator itr = TargetList.begin(); itr != TargetList.end(); ++itr)
                    {
                        if ((*itr) && (*itr)->isAlive())
                        {
                            Creature* demon = me->SummonCreature(INNER_DEMON_ID, (*itr)->GetPositionX()+10, (*itr)->GetPositionY()+10, (*itr)->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                            if (demon)
                            {
                                demon->AI()->AttackStart((*itr));
                                CAST_AI(mob_inner_demon::mob_inner_demonAI, demon->AI())->victimGUID = (*itr)->GetGUID();

                                (*itr)->AddAura(SPELL_INSIDIOUS_WHISPER, *itr);

                                if (InnerDemon_Count > 4)
                                    InnerDemon_Count = 0;

                                //Safe storing of creatures
                                InnderDemon[InnerDemon_Count] = demon->GetGUID();

                                //Update demon count
                                ++InnerDemon_Count;
                            }
                        }
                    }
                    DoScriptText(SAY_INNER_DEMONS, me);

                    InnerDemons_Timer = 999999;
                } else InnerDemons_Timer -= diff;

                //Switch_Timer
                if (SwitchToHuman_Timer <= diff)
                {
                    //switch to nightelf form
                    me->SetDisplayId(MODEL_NIGHTELF);
                    me->LoadEquipment(me->GetEquipmentId());

                    CastConsumingMadness();
                    DespawnDemon();

                    DemonForm = false;
                    NeedThreatReset = true;

                    SwitchToHuman_Timer = 60000;
                } else SwitchToHuman_Timer -= diff;
            }

            if (!IsFinalForm && HealthBelowPct(15))
            {
                //at this point he divides himself in two parts
                CastConsumingMadness();
                DespawnDemon();
                Creature *Copy = NULL;
                Copy = DoSpawnCreature(DEMON_FORM, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 6000);
                if (Copy)
                 {
                     Demon = Copy->GetGUID();
                    if (me->getVictim())
                        Copy->AI()->AttackStart(me->getVictim());
                }
                //set nightelf final form
                IsFinalForm = true;
                DemonForm = false;

                DoScriptText(SAY_FINAL_FORM, me);
                me->SetDisplayId(MODEL_NIGHTELF);
                me->LoadEquipment(me->GetEquipmentId());
            }
        }
    };

};

//Leotheras the Blind Demon Form AI
class boss_leotheras_the_blind_demonform : public CreatureScript
{
public:
    boss_leotheras_the_blind_demonform() : CreatureScript("boss_leotheras_the_blind_demonform") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_leotheras_the_blind_demonformAI (pCreature);
    }

    struct boss_leotheras_the_blind_demonformAI : public ScriptedAI
    {
        boss_leotheras_the_blind_demonformAI(Creature *c) : ScriptedAI(c) {}

        uint32 ChaosBlast_Timer;
        bool DealDamage;

        void Reset()
        {
            ChaosBlast_Timer = 1000;
            DealDamage = true;
        }

        void StartEvent()
        {
            DoScriptText(SAY_FREE, me);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            DoScriptText(RAND(SAY_DEMON_SLAY1, SAY_DEMON_SLAY2, SAY_DEMON_SLAY3), me);
        }

        void JustDied(Unit* /*victim*/)
        {
            //invisibility (blizzlike, at the end of the fight he doesn't die, he disappears)
            DoCast(me, 8149, true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            StartEvent();
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;
            //ChaosBlast_Timer
            if (me->IsWithinDist(me->getVictim(), 30))
                me->StopMoving();

            if (ChaosBlast_Timer <= diff)
             {
                // will cast only when in range od spell
                if (me->IsWithinDist(me->getVictim(), 30))
                {
                    //DoCast(me->getVictim(), SPELL_CHAOS_BLAST, true);
                    int damage = 100;
                    me->CastCustomSpell(me->getVictim(), SPELL_CHAOS_BLAST, &damage, NULL, NULL, false, NULL, NULL, me->GetGUID());
                    ChaosBlast_Timer = 3000;
                }
             } else ChaosBlast_Timer -= diff;

            //Do NOT deal any melee damage to the target.
        }
    };
};

class mob_greyheart_spellbinder : public CreatureScript
{
public:
    mob_greyheart_spellbinder() : CreatureScript("mob_greyheart_spellbinder") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_greyheart_spellbinderAI (pCreature);
    }

    struct mob_greyheart_spellbinderAI : public ScriptedAI
    {
        mob_greyheart_spellbinderAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            leotherasGUID = 0;
            AddedBanish = false;
        }

        InstanceScript *pInstance;

        uint64 leotherasGUID;

        uint32 Mindblast_Timer;
        uint32 Earthshock_Timer;

        bool AddedBanish;

        void Reset()
        {
            Mindblast_Timer  = 3000 + rand()%5000;
            Earthshock_Timer = 5000 + rand()%5000;

            if (pInstance)
            {
                pInstance->SetData64(DATA_LEOTHERAS_EVENT_STARTER, 0);
                Creature *leotheras = Unit::GetCreature(*me, leotherasGUID);
                if (leotheras && leotheras->isAlive())
                    CAST_AI(boss_leotheras_the_blind::boss_leotheras_the_blindAI, leotheras->AI())->CheckChannelers(/*false*/);
            }
        }

        void EnterCombat(Unit* who)
        {
            me->InterruptNonMeleeSpells(false);
            if (pInstance)
                pInstance->SetData64(DATA_LEOTHERAS_EVENT_STARTER, who->GetGUID());
        }

        void JustRespawned()
        {
            AddedBanish = false;
            Reset();
        }

        void CastChanneling()
        {
            if (!me->isInCombat() && !me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            {
                if (leotherasGUID)
                {
                    Creature *leotheras = Unit::GetCreature(*me, leotherasGUID);
                    if (leotheras && leotheras->isAlive())
                        DoCast(leotheras, BANISH_BEAM);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (pInstance)
            {
                if (!leotherasGUID)
                    leotherasGUID = pInstance->GetData64(DATA_LEOTHERAS);

                if (!me->isInCombat() && pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER))
                {
                    Unit *victim = NULL;
                    victim = Unit::GetUnit(*me, pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER));
                    if (victim)
                        AttackStart(victim);
                }
            }

            if (!UpdateVictim())
            {
                CastChanneling();
                return;
            }

            if (pInstance && !pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER))
            {
                EnterEvadeMode();
                return;
            }

            if (Mindblast_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);

                if (pTarget)DoCast(pTarget, SPELL_MINDBLAST);

                Mindblast_Timer = 10000 + rand()%5000;
            } else Mindblast_Timer -= diff;

            if (Earthshock_Timer <= diff)
            {
                Map* pMap = me->GetMap();
                Map::PlayerList const &PlayerList = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                {
                    if (Player* i_pl = itr->getSource())
                    {
                        bool isCasting = false;
                        for (uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
                            if (i_pl->GetCurrentSpell(i))
                                isCasting = true;

                        if (isCasting)
                        {
                            DoCast(i_pl, SPELL_EARTHSHOCK);
                            break;
                        }
                    }
                }
                Earthshock_Timer = 8000 + rand()%7000;
            } else Earthshock_Timer -= diff;
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) {}
    };

};

void AddSC_boss_leotheras_the_blind()
{
    new boss_leotheras_the_blind();
    new boss_leotheras_the_blind_demonform();
    new mob_greyheart_spellbinder();
    new mob_inner_demon();
}
