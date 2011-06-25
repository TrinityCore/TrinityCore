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
SDName: Boss_Bloodboil
SD%Complete: 80
SDComment: Bloodboil not working correctly, missing enrage
SDCategory: Black Temple
EndScriptData */

#include "ScriptPCH.h"
#include "black_temple.h"

//Speech'n'Sound
#define SAY_AGGRO               -1564029
#define SAY_SLAY1               -1564030
#define SAY_SLAY2               -1564031
#define SAY_SPECIAL1            -1564032
#define SAY_SPECIAL2            -1564033
#define SAY_ENRAGE1             -1564034
#define SAY_ENRAGE2             -1564035
#define SAY_DEATH               -1564036

//Spells
//Phase 1
#define SPELL_ARCING_SMASH_1        40599
#define SPELL_ACIDIC_WOUND          40484 //Trigger Aura
#define SPELL_BEWILDERING_STRIKE    40491
#define SPELL_EJECT_1               40486
#define SPELL_FELBREATH_1           40508
#define SPELL_BLOODBOIL             42005

//Phase 2
#define SPELL_ARCING_SMASH_2        40457
#define SPELL_EJECT_2               40597
#define SPELL_FELBREATH_2           40595
#define SPELL_FEL_GEYSER            40569
#define SPELL_FEL_GEYSER_DAMAGE     40593
#define SPELL_FEL_GEYSER_STUN       40591

//Fel Rage
#define SPELL_INSIGNIFIGANCE        40618
#define SPELL_TAUNT_GURTOGG         40603
#define SPELL_FEL_RAGE_SELF         40594
#define SPELL_FEL_RAGE_1            40604
#define SPELL_FEL_RAGE_2            40616
#define SPELL_FEL_RAGE_3            41625
#define SPELL_FEL_RAGE_SCALE        46787

#define SPELL_CHARGE                40602
#define SPELL_BERSERK               45078

#define COORD_Z_HOME                64.0f

// Schon Definiert
////This is used to sort the players by distance in preparation for the Bloodboil cast.
//struct ObjectDistanceOrderReversed : public std::binary_function<const Unit *, const Unit *, bool>
//{
//    const Unit* m_pSource;
//    ObjectDistanceOrderReversed(const Unit* pSource) : m_pSource(pSource) {};
//
//    bool operator()(const Unit* pLeft, const Unit* pRight) const
//    {
//        return !m_pSource->GetDistanceOrder(pLeft, pRight);
//    }
//};

class boss_gurtogg_bloodboil : public CreatureScript
{
public:
    boss_gurtogg_bloodboil() : CreatureScript("boss_gurtogg_bloodboil") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_gurtogg_bloodboilAI (_Creature);
    }

    struct boss_gurtogg_bloodboilAI : public ScriptedAI
    {
        boss_gurtogg_bloodboilAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            SetImmuneToPushPullEffects(true);
        }

        InstanceScript* pInstance;

        uint64 TargetGUID;

        float TargetThreat;

        uint32 BloodboilTimer;
        uint32 BloodboilCount;

        uint32 FelGeyserTimer;
        //uint32 AcidicWoundTimer;
        uint32 BewilderingStrikeTimer;

        uint32 ArcingSmashTimer;
        uint32 FelBreathTimer;
        uint32 EjectTimer;

        uint32 PhaseChangeTimer;

        uint32 EnrageTimer;

        uint32 Charge_Timer;

        bool Phase1;

        uint32 pulse_Timer;

        void Reset()
        {
            if(pInstance)
                pInstance->SetData(DATA_GURTOGGBLOODBOILEVENT, NOT_STARTED);

            TargetGUID = 0;

            TargetThreat = 0;

            BloodboilTimer = 10000;
            BloodboilCount = 0;

            FelGeyserTimer = 1000;
            //AcidicWoundTimer = 6000;
            BewilderingStrikeTimer = 15000;

            ArcingSmashTimer = 19000;
            FelBreathTimer = 25000;
            EjectTimer = 10000;

            PhaseChangeTimer = 65000;
            EnrageTimer = 600000;

            Phase1 = true;

            Charge_Timer = 30000;

            pulse_Timer = 10000;

            DoCast(me,SPELL_ACIDIC_WOUND,true);

            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();
            DoScriptText(SAY_AGGRO, me);
            if(pInstance)
                pInstance->SetData(DATA_GURTOGGBLOODBOILEVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(SAY_SLAY1, me); break;
            case 1: DoScriptText(SAY_SLAY2, me); break;
            }
        }

        void JustDied(Unit* /*victim*/)
        {
            if(pInstance)
                pInstance->SetData(DATA_GURTOGGBLOODBOILEVENT, DONE);

            DoScriptText(SAY_DEATH, me);

            CleanUpAura();
        }

        void CleanUpAura()
        {
            Map *map = me->GetMap();
            if(map->IsDungeon())
            {
                InstanceMap::PlayerList const &PlayerList = ((InstanceMap*)map)->GetPlayers();
                for (InstanceMap::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* i_pl = i->getSource())
                    {
                        if(i_pl->isAlive())
                        {
                            i_pl->RemoveAurasDueToSpell(SPELL_INSIGNIFIGANCE);
                            i_pl->RemoveAurasDueToSpell(SPELL_FEL_RAGE_1);
                            i_pl->RemoveAurasDueToSpell(SPELL_FEL_RAGE_2);
                            i_pl->RemoveAurasDueToSpell(SPELL_FEL_RAGE_3);
                            i_pl->RemoveAurasDueToSpell(SPELL_FEL_RAGE_SCALE);
                        }
                    }
                }
            }
        }

        // Note: This seems like a very complicated fix. The fix needs to be handled by the core, as implementation of limited-target AoE spells are still not limited.
        void CastBloodboil()
        {
            std::list<Unit *> targets;
            Map *map = me->GetMap();
            if(map->IsDungeon())
            {
                InstanceMap::PlayerList const &PlayerList = ((InstanceMap*)map)->GetPlayers();
                for (InstanceMap::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* i_pl = i->getSource())
                    {
                         if(i_pl && i_pl->isAlive())
                            targets.push_back(i_pl);
                    }
                }
            }

            //Sort the list of players
            targets.sort(Trinity::ObjectDistanceOrderPred(me, false));
            //Resize so we only get top 5
            targets.resize(5);

            //Aura each player in the targets list with Bloodboil.
            for(std::list<Unit *>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                Unit* target = *itr;
                if(target && target->isAlive())
                    me->AddAura(SPELL_BLOODBOIL, target);
            }
            targets.clear();
        }

        void RevertThreatOnTarget(uint64 guid)
        {
            Unit* pUnit = NULL;
            pUnit = Unit::GetUnit((*me), guid);
            if(pUnit)
            {
                if(DoGetThreat(pUnit))
                    DoModifyThreatPercent(pUnit, -100);
                if(TargetThreat)
                    me->AddThreat(pUnit, TargetThreat);
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

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;
        
            if(Phase1)
            {
                if(pulse_Timer < diff)
                {
                    if(me->GetPositionZ() > (COORD_Z_HOME+15))
                    {
                        EnterEvadeMode();
                        return;
                    }

                    DoAttackerAreaInCombat(me->getVictim(),50);
                    pulse_Timer = 10000;
                }else pulse_Timer -= diff;
            }

            if(!me->HasAura(SPELL_BERSERK, 0))
            {
                if(EnrageTimer < diff)
                {
                    DoCast(me, SPELL_BERSERK);
                    switch(rand()%2)
                    {
                    case 0: DoScriptText(SAY_ENRAGE1, me); break;
                    case 1: DoScriptText(SAY_ENRAGE2, me); break;
                    }
                }else EnrageTimer -= diff;
            }

            if(ArcingSmashTimer < diff)
            {
                DoCast(me->getVictim(),Phase1 ? SPELL_ARCING_SMASH_1 : SPELL_ARCING_SMASH_2);
                ArcingSmashTimer = 10000;
            }else ArcingSmashTimer -= diff;

            if(FelBreathTimer < diff)
            {
                DoCast(me->getVictim(),Phase1 ? SPELL_FELBREATH_1 : SPELL_FELBREATH_2);
                FelBreathTimer = 25000;
            }else FelBreathTimer -= diff;

            if(EjectTimer < diff)
            {
                DoCast(me->getVictim(),Phase1 ? SPELL_EJECT_1 : SPELL_EJECT_2);
                EjectTimer = 15000;
            }else EjectTimer -= diff;


            if(Charge_Timer < diff)
            {
                if(me->GetDistance2d(me->getVictim()) > 15)
                    DoCast(me->getVictim(),SPELL_CHARGE);
                Charge_Timer = 10000;
            }else Charge_Timer -= diff;

            if(Phase1)
            {
                if(BewilderingStrikeTimer < diff)
                {
                    DoCast(me->getVictim(), SPELL_BEWILDERING_STRIKE);
                    //float mt_threat = DoGetThreat(me->getVictim());
                    //if (Unit *ptarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                    //    me->AddThreat(ptarget, mt_threat);
                    BewilderingStrikeTimer = 20000;
                }else BewilderingStrikeTimer -= diff;

                //if(EjectTimer < diff)
                //{
                //    DoCast(me->getVictim(), SPELL_EJECT1);
                //    DoModifyThreatPercent(me->getVictim(), -40);
                //    EjectTimer = 15000;
                //}else EjectTimer -= diff;

                //if(AcidicWoundTimer < diff)
                //{
                //    DoCast(me->getVictim(), SPELL_ACIDIC_WOUND);
                //    AcidicWoundTimer = 10000;
                //}else AcidicWoundTimer -= diff;

                if(BloodboilTimer < diff)
                {
                    if(BloodboilCount < 5)                      // Only cast it five times.
                    {
                        CastBloodboil(); // Causes issues on windows, so is commented out.
                        //DoCast(me->getVictim(), SPELL_BLOODBOIL);
                        ++BloodboilCount;
                        BloodboilTimer = 10000;
                    }
                }else BloodboilTimer -= diff;
            }

            if(!Phase1)
            {
                //if(FelGeyserTimer < diff)
                //{
                //    DoCast(me->getVictim(), SPELL_FEL_GEYSER,true);
                //    FelGeyserTimer = 30000;
                //}else FelGeyserTimer -= diff;

                if(me->getVictim() && me->getVictim()->IsImmunedToDamage(SPELL_SCHOOL_MASK_ALL))
                    me->getThreatManager().modifyThreatPercent(me->getVictim(),-100);
            }

            if(PhaseChangeTimer < diff)
            {
                if(Phase1)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0,100,true);
                    if(target && target->isAlive())
                    {
                        Phase1 = false;

                        TargetThreat = DoGetThreat(target);
                        TargetGUID = target->GetGUID();
                        if(DoGetThreat(target))
                            DoModifyThreatPercent(target, -100);
                        me->AddThreat(target, 50000000.0f);
                        target->CastSpell(me, SPELL_TAUNT_GURTOGG, true);
                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

                        // If VMaps are disabled, this spell can call the whole instance
                        DoCast(me, SPELL_INSIGNIFIGANCE, true);
                        DoCast(target,SPELL_FEL_RAGE_1, true);
                        DoCast(target,SPELL_FEL_RAGE_2, true);
                        DoCast(target,SPELL_FEL_RAGE_3, true);
                        DoCast(target,SPELL_FEL_RAGE_SCALE, true);
                        DoCast(target,SPELL_FEL_GEYSER,true);

                        //Cast this without triggered so that it appears in combat logs and shows visual.
                        DoCast(me, SPELL_FEL_RAGE_SELF);

                        switch(rand()%2)
                        {
                        case 0: DoScriptText(SAY_SPECIAL1, me); break;
                        case 1: DoScriptText(SAY_SPECIAL2, me); break;
                        }

                        FelGeyserTimer = 1;
                        PhaseChangeTimer = 30000;
                    }
                }else                                           // Encounter is a loop pretty much. Phase 1 -> Phase 2 -> Phase 1 -> Phase 2 till death or enrage
                {
                    if(TargetGUID)
                        RevertThreatOnTarget(TargetGUID);
                    TargetGUID = 0;
                    Phase1 = true;
                    BloodboilTimer = 10000;
                    BloodboilCount = 0;
                    /*AcidicWoundTimer += 2000;*/
                    ArcingSmashTimer += 2000;
                    FelBreathTimer += 2000;
                    EjectTimer += 2000;
                    PhaseChangeTimer = 65000;
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                }
            }else PhaseChangeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_fel_geyser : public CreatureScript
{
public:
    npc_fel_geyser() : CreatureScript("npc_fel_geyser") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new npc_fel_geyserAI (_Creature);
    }

    struct npc_fel_geyserAI : public Scripted_NoMovementAI
    {
        npc_fel_geyserAI(Creature *c) : Scripted_NoMovementAI(c)
        {
        }

        uint32 damage_timer;

        void Reset()
        {
            damage_timer = 1000;
        }

        void UpdateAI(const uint32 diff)
        {
            if(damage_timer < diff)
            {
                DoCastAOE(SPELL_FEL_GEYSER_DAMAGE);
                damage_timer = 60000;
            }else damage_timer -= diff;
        }

    };
};
void AddSC_boss_gurtogg_bloodboil()
{
    new boss_gurtogg_bloodboil();
    new npc_fel_geyser();
    //UPDATE creature_template SET scriptname = 'npc_fel_geyser' WHERE entry = 23254;
}
