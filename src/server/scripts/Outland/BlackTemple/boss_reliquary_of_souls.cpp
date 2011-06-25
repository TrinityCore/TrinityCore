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
SDName: Boss_Reliquary_of_Souls
SD%Complete: 90
SDComment:
SDCategory: Black Temple
EndScriptData */

#include "ScriptPCH.h"
#include "black_temple.h"
#include "Spell.h"

//Sound'n'speech
//Suffering
#define SUFF_SAY_FREED              -1564047
#define SUFF_SAY_AGGRO              -1564048
#define SUFF_SAY_SLAY1              -1564049
#define SUFF_SAY_SLAY2              -1564050
#define SUFF_SAY_SLAY3              -1564051
#define SUFF_SAY_RECAP              -1564052
#define SUFF_SAY_AFTER              -1564053
#define SUFF_EMOTE_ENRAGE           -1564054

//Desire
#define DESI_SAY_FREED              -1564055
#define DESI_SAY_SLAY1              -1564056
#define DESI_SAY_SLAY2              -1564057
#define DESI_SAY_SLAY3              -1564058
#define DESI_SAY_SPEC               -1564059
#define DESI_SAY_RECAP              -1564060
#define DESI_SAY_AFTER              -1564061

//Anger
#define ANGER_SAY_FREED             -1564062
#define ANGER_SAY_FREED2            -1564063
#define ANGER_SAY_SLAY1             -1564064
#define ANGER_SAY_SLAY2             -1564065
#define ANGER_SAY_SPEC              -1564066
#define ANGER_SAY_BEFORE            -1564067
#define ANGER_SAY_DEATH             -1564068

//Spells
#define AURA_OF_SUFFERING               41292
#define AURA_OF_SUFFERING_ARMOR         42017 // linked aura, need core support
#define ESSENCE_OF_SUFFERING_PASSIVE    41296 // periodic trigger 41294
#define ESSENCE_OF_SUFFERING_PASSIVE2   41623
#define SPELL_FIXATE_TARGET             41294 // dummy, select target
#define SPELL_FIXATE_TAUNT              41295 // force taunt
#define SPELL_ENRAGE                    41305
#define SPELL_SOUL_DRAIN                41303

#define AURA_OF_DESIRE                  41350
#define AURA_OF_DESIRE_DAMAGE           41352
#define SPELL_RUNE_SHIELD               41431
#define SPELL_DEADEN                    41410
#define SPELL_SOUL_SHOCK                41426

#define AURA_OF_ANGER                   41337
#define SPELL_SELF_SEETHE               41364 // force cast 41520
#define SPELL_ENEMY_SEETHE              41520
#define SPELL_SOUL_SCREAM               41545
#define SPELL_SPITE_TARGET              41376 // cast 41377 after 6 sec
#define SPELL_SPITE_DAMAGE              41377

#define ENSLAVED_SOUL_PASSIVE           41535
#define SPELL_SOUL_RELEASE              41542
#define SPELL_SUBMERGE                  37550 //dropout 'head'

#define CREATURE_ENSLAVED_SOUL          23469
#define NUMBER_ENSLAVED_SOUL            8

struct Position2d
{
    float x, y;
};

static Position2d Coords[]=
{
    {450.4f, 212.3f},
    {542.1f, 212.3f},
    {542.1f, 168.3f},
    {542.1f, 137.4f},
    {450.4f, 137.4f},
    {450.4f, 168.3f}
};

struct  boss_soul_essenceAI : public ScriptedAI
{
    boss_soul_essenceAI(Creature *c) : ScriptedAI(c) {}

    uint32 pulse_Timer;
    uint64 ReliquaryGUID;

    void Reset()
    {
        pulse_Timer = 10000;

        if(ReliquaryGUID)
        {
            Creature* Reliquary = (Unit::GetCreature((*me), ReliquaryGUID));
            if(Reliquary)
                Reliquary->AI()->EnterEvadeMode();
        }
    }

    //void DoAttackerAreaInCombat(Unit* attacker, float range, Unit* pUnit = NULL)
    //{
    //    if (!attacker)
    //        attacker = me;

    //    if (!pUnit)
    //        pUnit = me;

    //    Map *map = pUnit->GetMap();

    //    if (!map->IsDungeon())
    //        return;

    //    if (!pUnit->CanHaveThreatList() || pUnit->getThreatManager().isThreatListEmpty())
    //        return;

    //    Map::PlayerList const &PlayerList = map->GetPlayers();
    //    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
    //    {
    //        if (Player* i_pl = i->getSource())
    //            if (i_pl->isAlive() && attacker->GetDistance(i_pl) <= range )
    //            {
    //                pUnit->SetInCombatWith(i_pl);
    //                i_pl->SetInCombatWith(pUnit);
    //                pUnit->AddThreat(i_pl, 0.0f);
    //            }
    //    }
    //}

    void DoAggroPuls(const uint32 diff)
    {
        if(pulse_Timer < diff)
        {
            DoAttackerAreaInCombat(me->getVictim(),50);
            pulse_Timer = 10000;
        }else pulse_Timer -= diff;
    }

    void EnterCombat(Unit*) {}
    void UpdateAI(const uint32 diff) {}
};


class npc_enslaved_soul : public CreatureScript
{
public:
    npc_enslaved_soul() : CreatureScript("npc_enslaved_soul") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new npc_enslaved_soulAI (_Creature);
    }

    struct  npc_enslaved_soulAI : public ScriptedAI
    {
        npc_enslaved_soulAI(Creature *c) : ScriptedAI(c) {}

        uint64 ReliquaryGUID;

        void Reset() {ReliquaryGUID = 0;}

        void EnterCombat(Unit* who)
        {
            me->CastSpell(me, ENSLAVED_SOUL_PASSIVE, true);
            DoZoneInCombat();
        }

        void JustDied(Unit *killer);
    };
};

class boss_reliquary_of_souls : public CreatureScript
{
public:
    boss_reliquary_of_souls() : CreatureScript("boss_reliquary_of_souls") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_reliquary_of_soulsAI (_Creature);
    }

    struct  boss_reliquary_of_soulsAI : public ScriptedAI
    {
        boss_reliquary_of_soulsAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            EssenceGUID = 0;
        }

        InstanceScript* pInstance;

        uint64 EssenceGUID;

        uint32 Phase;
        uint32 Counter;
        uint32 Timer;

        uint32 SoulCount;
        uint32 SoulDeathCount;

        uint32 pulse_Timer;

        void Reset()
        {
            if(pInstance)
                pInstance->SetData(DATA_RELIQUARYOFSOULSEVENT, NOT_STARTED);

            if(EssenceGUID)
            {
                if(Creature* Essence = Unit::GetCreature(*me, EssenceGUID))
                {
                    Essence->DespawnOrUnsummon();
                }
                EssenceGUID = 0;
            }

            Phase = 0;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
        }

        //void DoAttackerAreaInCombat(Unit* attacker, float range, Unit* pUnit = NULL)
        //{
        //    if (!attacker)
        //        attacker = me;

        //    if (!pUnit)
        //        pUnit = me;

        //    Map *map = pUnit->GetMap();

        //    if (!map->IsDungeon())
        //        return;

        //    if (!pUnit->CanHaveThreatList() || pUnit->getThreatManager().isThreatListEmpty())
        //        return;

        //    Map::PlayerList const &PlayerList = map->GetPlayers();
        //    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        //    {
        //        if (Player* i_pl = i->getSource())
        //            if (i_pl->isAlive() && attacker->GetDistance(i_pl) <= range )
        //            {
        //                pUnit->SetInCombatWith(i_pl);
        //                i_pl->SetInCombatWith(pUnit);
        //                pUnit->AddThreat(i_pl, 0.0f);
        //            }
        //    }
        //}

        void DoAggroPuls(const uint32 diff)
        {
            if(pulse_Timer < diff)
            {
                DoAttackerAreaInCombat(me->getVictim(),50);
                pulse_Timer = 10000;
            }else pulse_Timer -= diff;
        }

        void EnterCombat(Unit* who)
        {
            me->AddThreat(who, 10000.0f);
            DoZoneInCombat();
            if(pInstance)
                pInstance->SetData(DATA_RELIQUARYOFSOULSEVENT, IN_PROGRESS);

            Phase = 1;
            Counter = 0;
            Timer = 0;
            pulse_Timer = 10000;
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            me->Attack(pWho, true);
        }

        bool SummonSoul()
        {
            uint32 random = rand()%6;
            float x = Coords[random].x;
            float y = Coords[random].y;
            Creature* Soul = me->SummonCreature(CREATURE_ENSLAVED_SOUL, x, y, me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 0);
            if(!Soul) return false;
            if(Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
            {
                CAST_AI(npc_enslaved_soul::npc_enslaved_soulAI,Soul->AI())->ReliquaryGUID = me->GetGUID();
                Soul->AI()->AttackStart(ptarget);
            }else EnterEvadeMode();
            return true;
        }

        void JustDied(Unit* killer)
        {
            if(pInstance)
                pInstance->SetData(DATA_RELIQUARYOFSOULSEVENT, DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!Phase)
                return;

            if(me->getThreatManager().getThreatList().empty()) // Reset if event is begun and we don't have a threatlist
            {
                EnterEvadeMode();
                return;
            }

            Creature* Essence;
            if(EssenceGUID)
            {
                Essence = Unit::GetCreature(*me, EssenceGUID);
                if(!Essence)
                {
                    EnterEvadeMode();
                    return;
                }
            }

            DoAggroPuls(diff);

            if(Timer < diff)
            {
                switch(Counter)
                {
                case 0:
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);  // I R ANNNGRRRY!
                    Timer = 3000;
                    break;
                case 1:
                    Timer = 2800;
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SUBMERGE);  // Release the cube
                    DoCast(me,SPELL_SUBMERGE);
                    break;
                case 2:
                    Timer = 5000;
                    if(Creature* Summon = DoSpawnCreature(23417+Phase, 0, 0, 0, 0, TEMPSUMMON_DEAD_DESPAWN, 0))
                    {
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SUBMERGED);  // Ribs: open
                        if (Unit *ptarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                            Summon->AI()->AttackStart(ptarget);
                        EssenceGUID = Summon->GetGUID();
                        ((boss_soul_essenceAI*)Summon->AI())->ReliquaryGUID = me->GetGUID();
                    }else EnterEvadeMode();
                    break;
                case 3:
                    Timer = 1000;
                    if(Phase == 3)
                    {
                        if(!Essence->isAlive())
                            me->CastSpell(me, 7, true);
                        else return;
                    }
                    else
                    {
                        if(Essence->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                        {
                            //Essence->AI()->EnterEvadeMode();
                            Essence->GetMotionMaster()->MoveFollow(me, 0, 0);
                        }else return;
                    }
                    break;
                case 4:
                    Timer = 1500;
                    if(Essence->IsWithinDistInMap(me, 10))
                    {
                        me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                        Essence->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SUBMERGE); //rotate and disappear
                    }
                    else
                    {
                        //Essence->AI()->EnterEvadeMode();
                        Essence->GetMotionMaster()->MoveFollow(me, 0, 0);
                        return;
                    }
                    break;
                case 5:
                    if(Phase == 1)
                    {
                        DoScriptText(SUFF_SAY_AFTER, Essence);
                    }
                    else
                    {
                        DoScriptText(DESI_SAY_AFTER, Essence);
                    }
                    Essence->DespawnOrUnsummon();
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                    EssenceGUID = 0;
                    SoulCount = 0;
                    SoulDeathCount = 0;
                    Timer = 3000;
                    break;
                case 6:
                    if(SoulCount < NUMBER_ENSLAVED_SOUL)
                    {
                        if(SummonSoul())
                            SoulCount++;
                        Timer = 500;
                        return;
                    }break;
                case 7:
                    if(SoulDeathCount >= SoulCount)
                    {
                        Counter = 1;
                        Phase++;
                        Timer = 5000;
                    }
                    return;
                default:
                    break;
                }
                Counter++;
            }else Timer -= diff;
        }
    };
};

class boss_essence_of_suffering : public CreatureScript
{
public:
    boss_essence_of_suffering() : CreatureScript("boss_essence_of_suffering") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_essence_of_sufferingAI (_Creature);
    }

    struct  boss_essence_of_sufferingAI : public boss_soul_essenceAI
    {
        boss_essence_of_sufferingAI(Creature *c) : boss_soul_essenceAI(c) {}

        uint64 StatAuraGUID;

        uint32 AggroYellTimer;
        uint32 FixateTimer;
        uint32 EnrageTimer;
        uint32 SoulDrainTimer;
        uint32 AuraTimer;

        void Reset()
        {
            StatAuraGUID = 0;

            AggroYellTimer = 5000;
            FixateTimer = 8000;
            EnrageTimer = 30000;
            SoulDrainTimer = 45000;
            AuraTimer = 5000;

            boss_soul_essenceAI::Reset();
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if(damage >= me->GetHealth())
            {
                damage = 0;
                if(!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                    DoScriptText(SUFF_SAY_RECAP, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
        }

        void EnterCombat(Unit *who)
        {
            DoScriptText(SUFF_SAY_FREED, me);
            DoZoneInCombat();
            me->CastSpell(me, AURA_OF_SUFFERING, true); // linked aura need core support
            me->CastSpell(me, ESSENCE_OF_SUFFERING_PASSIVE, true);
            me->CastSpell(me, ESSENCE_OF_SUFFERING_PASSIVE2, true);
        }

        void KilledUnit(Unit *victim)
        {
            switch(rand()%2)
            {
                case 0: DoScriptText(SUFF_SAY_SLAY1, me); break;
                case 1: DoScriptText(SUFF_SAY_SLAY2, me); break;
                case 2: DoScriptText(SUFF_SAY_SLAY3, me); break;
            }
        }

        void CastFixate()
        {
            std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
            if(m_threatlist.empty())
                return; // No point continuing if empty threatlist.
            std::list<Unit*> targets;
            std::list<HostileReference*>::iterator itr = m_threatlist.begin();
            for( ; itr != m_threatlist.end(); ++itr)
            {
                Unit* pUnit = Unit::GetUnit((*me), (*itr)->getUnitGuid());
                if(pUnit && pUnit->isAlive() && (pUnit->GetTypeId() == TYPEID_PLAYER)) // Only alive players
                    targets.push_back(pUnit);
            }
            if(targets.empty())
                return; // No targets added for some reason. No point continuing.
            targets.sort(Trinity::ObjectDistanceOrderPred(me)); // Sort players by distance.
            targets.resize(1); // Only need closest target.
            Unit* target = targets.front(); // Get the first target.
            if(target)
                target->CastSpell(me, SPELL_FIXATE_TAUNT, true);
            DoResetThreat();
            me->AddThreat(target,1000000);
        }

        void UpdateAI(const uint32 diff)
        {
            if(me->isInCombat())
            {
                //Supposed to be cast on nearest target
                if(FixateTimer < diff)
                {
                    CastFixate();
                    FixateTimer = 5000;
                    if(!(rand()%16))
                    {
                        DoScriptText(SUFF_SAY_AGGRO, me);
                    }
                }else FixateTimer -= diff;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoAggroPuls(diff);

            if(EnrageTimer < diff)
            {
                DoCast(me, SPELL_ENRAGE);
                EnrageTimer = 60000;
                DoScriptText(SUFF_EMOTE_ENRAGE, me);
            }else EnrageTimer -= diff;

            if(SoulDrainTimer < diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM,0), SPELL_SOUL_DRAIN);
                SoulDrainTimer = 60000;
            }else SoulDrainTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_essence_of_desire : public CreatureScript
{
public:
    boss_essence_of_desire() : CreatureScript("boss_essence_of_desire") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_essence_of_desireAI (_Creature);
    }

    struct  boss_essence_of_desireAI : public boss_soul_essenceAI
    {
        boss_essence_of_desireAI(Creature *c) : boss_soul_essenceAI(c) {}

        uint32 RuneShieldTimer;
        uint32 DeadenTimer;
        uint32 SoulShockTimer;

        void Reset()
        {
            RuneShieldTimer = 60000;
            DeadenTimer = 30000;
            SoulShockTimer = 5000;
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

            boss_soul_essenceAI::Reset();
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if(done_by == me)
                return;

            if(damage >= me->GetHealth())
            {
                damage = 0;
                if(!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                    DoScriptText(DESI_SAY_RECAP, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            
            }
            else
            {
                int32 bp0 = damage / 2;
                me->CastCustomSpell(done_by, AURA_OF_DESIRE_DAMAGE, &bp0, NULL, NULL, true);
            }
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if (me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                for (uint8 i = 0; i < 3; ++i)
                    if (spell->Effect[i] == SPELL_EFFECT_INTERRUPT_CAST)
                        if (me->GetCurrentSpell(CURRENT_GENERIC_SPELL)->m_spellInfo->Id == SPELL_SOUL_SHOCK
                            || me->GetCurrentSpell(CURRENT_GENERIC_SPELL)->m_spellInfo->Id == SPELL_DEADEN)
                            me->InterruptSpell(CURRENT_GENERIC_SPELL, false);
        }

        void EnterCombat(Unit *who)
        {
            DoScriptText(DESI_SAY_FREED, me);
            DoZoneInCombat();
            DoCast(me, AURA_OF_DESIRE, true);
        }

        void KilledUnit(Unit *victim)
        {
            switch(rand()%3)
            {
            case 0: DoScriptText(DESI_SAY_SLAY1, me); break;
            case 1: DoScriptText(DESI_SAY_SLAY2, me); break;
            case 2: DoScriptText(DESI_SAY_SLAY3, me); break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            DoAggroPuls(diff);

            if(RuneShieldTimer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    me->CastSpell(me, SPELL_RUNE_SHIELD, true);
                    SoulShockTimer += 2000;
                    DeadenTimer += 2000;
                    RuneShieldTimer = 60000;
                }
            }else RuneShieldTimer -= diff;

            if(SoulShockTimer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(), SPELL_SOUL_SHOCK);
                    SoulShockTimer = 5000;
                }
            }else SoulShockTimer -= diff;

            if(DeadenTimer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me->getVictim(), SPELL_DEADEN);
                    DeadenTimer = 25000 +rand()%10000;
                    if(!(rand()%2))
                    {
                        DoScriptText(DESI_SAY_SPEC, me);
                    }
                }
            }else DeadenTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_essence_of_anger : public CreatureScript
{
public:
    boss_essence_of_anger() : CreatureScript("boss_essence_of_anger") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_essence_of_angerAI (_Creature);
    }

    struct  boss_essence_of_angerAI : public boss_soul_essenceAI
    {
        boss_essence_of_angerAI(Creature *c) : boss_soul_essenceAI(c) {}

        uint64 AggroTargetGUID;

        uint32 CheckTankTimer;
        uint32 SoulScreamTimer;
        uint32 SpiteTimer;

        std::list<uint64> SpiteTargetGUID;

        bool CheckedAggro;

        void Reset()
        {
            AggroTargetGUID = 0;

            CheckTankTimer = 5000;
            SoulScreamTimer = 10000;
            SpiteTimer = 30000;

            SpiteTargetGUID.clear();

            CheckedAggro = false;

            boss_soul_essenceAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(ANGER_SAY_FREED, me); break;
            case 1: DoScriptText(ANGER_SAY_FREED2, me); break;
            }

            DoZoneInCombat();
            DoCast(me, AURA_OF_ANGER, true);
        }

        void JustDied(Unit *victim)
        {
            DoScriptText(ANGER_SAY_DEATH, me);
        }

        void KilledUnit(Unit *victim)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(ANGER_SAY_SLAY1, me); break;
            case 1: DoScriptText(ANGER_SAY_SLAY2, me); break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoAggroPuls(diff);

            if(!CheckedAggro)
            {
                AggroTargetGUID = me->getVictim()->GetGUID();
                CheckedAggro = true;
            }

            if(CheckTankTimer < diff)
            {
                if(me->getVictim()->GetGUID() != AggroTargetGUID)
                {
                    DoScriptText(ANGER_SAY_BEFORE, me);
                    DoCast(me, SPELL_SELF_SEETHE, true);
                    AggroTargetGUID = me->getVictim()->GetGUID();
                }
                CheckTankTimer = 2000;
            }else CheckTankTimer -= diff;

            if(SoulScreamTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_SOUL_SCREAM);
                SoulScreamTimer = 9000 + rand()%2000;
                if(!(rand()%3))
                {
                    DoScriptText(ANGER_SAY_SPEC, me);
                }
            }else SoulScreamTimer -= diff;

            if(SpiteTimer < diff)
            {
                DoCast(me, SPELL_SPITE_TARGET);
                SpiteTimer = 30000;
                DoScriptText(ANGER_SAY_SPEC, me);
            }else SpiteTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void npc_enslaved_soul::npc_enslaved_soulAI::JustDied(Unit *killer)
{
    if(ReliquaryGUID)
    {
        Creature* Reliquary = (Unit::GetCreature((*me), ReliquaryGUID));
        if(Reliquary)
            CAST_AI(boss_reliquary_of_souls::boss_reliquary_of_soulsAI,Reliquary->AI())->SoulDeathCount++;
    }
    DoCast(me, SPELL_SOUL_RELEASE, true);
}

void AddSC_boss_reliquary_of_souls()
{
    new boss_reliquary_of_souls();
    new boss_essence_of_suffering();
    new boss_essence_of_desire();
    new boss_essence_of_anger();
    new npc_enslaved_soul();
}
