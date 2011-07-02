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
#define SPELL_ACID_GEYSER        40630
#define SPELL_ACIDIC_WOUND       40481
#define SPELL_ARCING_SMASH       40599
#define SPELL_BLOODBOIL          42005                      // This spell is AoE whereas it shouldn't be
#define SPELL_FEL_ACID           40508
#define SPELL_FEL_RAGE_SELF      40594
#define SPELL_FEL_RAGE_TARGET    40604
#define SPELL_FEL_RAGE_2         40616
#define SPELL_FEL_RAGE_3         41625
#define SPELL_BEWILDERING_STRIKE 40491
#define SPELL_EJECT1             40486                      // 1000 Physical damage + knockback + script effect (should handle threat reduction I think)
#define SPELL_EJECT2             40597                      // 1000 Physical damage + Stun (used in phase 2?)
#define SPELL_TAUNT_GURTOGG      40603
#define SPELL_INSIGNIFIGANCE     40618
#define SPELL_BERSERK            45078

//This is used to sort the players by distance in preparation for the Bloodboil cast.

class boss_gurtogg_bloodboil : public CreatureScript
{
public:
    boss_gurtogg_bloodboil() : CreatureScript("boss_gurtogg_bloodboil") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_gurtogg_bloodboilAI (pCreature);
    }

    struct boss_gurtogg_bloodboilAI : public ScriptedAI
    {
        boss_gurtogg_bloodboilAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint64 TargetGUID;

        float TargetThreat;

        uint32 BloodboilTimer;
        uint32 BloodboilCount;
        uint32 AcidGeyserTimer;
        uint32 AcidicWoundTimer;
        uint32 ArcingSmashTimer;
        uint32 EnrageTimer;
        uint32 FelAcidTimer;
        uint32 EjectTimer;
        uint32 BewilderingStrikeTimer;
        uint32 PhaseChangeTimer;

        bool Phase1;

        void Reset()
        {
            if (pInstance)
                pInstance->SetData(DATA_GURTOGGBLOODBOILEVENT, NOT_STARTED);

            TargetGUID = 0;

            TargetThreat = 0;

            BloodboilTimer = 10000;
            BloodboilCount = 0;
            AcidGeyserTimer = 1000;
            AcidicWoundTimer = 6000;
            ArcingSmashTimer = 19000;
            EnrageTimer = 600000;
            FelAcidTimer = 25000;
            EjectTimer = 10000;
            BewilderingStrikeTimer = 15000;
            PhaseChangeTimer = 60000;

            Phase1 = true;

            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();
            DoScriptText(SAY_AGGRO, me);
            if (pInstance)
                pInstance->SetData(DATA_GURTOGGBLOODBOILEVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2), me);
        }

        void JustDied(Unit* /*victim*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_GURTOGGBLOODBOILEVENT, DONE);

            DoScriptText(SAY_DEATH, me);
        }

        // Note: This seems like a very complicated fix. The fix needs to be handled by the core, as implementation of limited-target AoE spells are still not limited.
        void CastBloodboil()
        {
            // Get the Threat List
            std::list<HostileReference *> m_threatlist = me->getThreatManager().getThreatList();

            if (m_threatlist.empty()) // He doesn't have anyone in his threatlist, useless to continue
                return;

            std::list<Unit* > targets;
            std::list<HostileReference *>::const_iterator itr = m_threatlist.begin();
            for (; itr!= m_threatlist.end(); ++itr)             //store the threat list in a different container
            {
                Unit* pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                                                //only on alive players
                if (pTarget && pTarget->isAlive() && pTarget->GetTypeId() == TYPEID_PLAYER)
                    targets.push_back(pTarget);
            }

            //Sort the list of players
            targets.sort(Trinity::ObjectDistanceOrderPred(me, false));
            //Resize so we only get top 5
            targets.resize(5);

            //Aura each player in the targets list with Bloodboil. Aura code copied+pasted from Aura command in Level3.cpp
            /*SpellEntry const *spellInfo = GetSpellStore()->LookupEntry(SPELL_BLOODBOIL);
            if (spellInfo)
            {
                for (std::list<Unit* >::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    Unit* pTarget = *itr;
                    if (!pTarget) return;
                    for (uint32 i = 0; i<3; ++i)
                    {
                        uint8 eff = spellInfo->Effect[i];
                        if (eff >= TOTAL_SPELL_EFFECTS)
                            continue;

                        Aura *Aur = new Aura(spellInfo, i, pTarget, pTarget, pTarget);
                        pTarget->AddAura(Aur);
                    }
                }
            }*/
        }

        void RevertThreatOnTarget(uint64 guid)
        {
            Unit* pUnit = NULL;
            pUnit = Unit::GetUnit((*me), guid);
            if (pUnit)
            {
                if (DoGetThreat(pUnit))
                    DoModifyThreatPercent(pUnit, -100);
                if (TargetThreat)
                    me->AddThreat(pUnit, TargetThreat);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (ArcingSmashTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ARCING_SMASH);
                ArcingSmashTimer = 10000;
            } else ArcingSmashTimer -= diff;

            if (FelAcidTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FEL_ACID);
                FelAcidTimer = 25000;
            } else FelAcidTimer -= diff;

            if (!me->HasAura(SPELL_BERSERK))
            {
                if (EnrageTimer <= diff)
                {
                    DoCast(me, SPELL_BERSERK);
                    DoScriptText(RAND(SAY_ENRAGE1, SAY_ENRAGE2), me);
                } else EnrageTimer -= diff;
            }

            if (Phase1)
            {
                if (BewilderingStrikeTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_BEWILDERING_STRIKE);
                    float mt_threat = DoGetThreat(me->getVictim());
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                        me->AddThreat(pTarget, mt_threat);
                    BewilderingStrikeTimer = 20000;
                } else BewilderingStrikeTimer -= diff;

                if (EjectTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_EJECT1);
                    DoModifyThreatPercent(me->getVictim(), -40);
                    EjectTimer = 15000;
                } else EjectTimer -= diff;

                if (AcidicWoundTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ACIDIC_WOUND);
                    AcidicWoundTimer = 10000;
                } else AcidicWoundTimer -= diff;

                if (BloodboilTimer <= diff)
                {
                    if (BloodboilCount < 5)                      // Only cast it five times.
                    {
                        //CastBloodboil(); // Causes issues on windows, so is commented out.
                        DoCast(me->getVictim(), SPELL_BLOODBOIL);
                        ++BloodboilCount;
                        BloodboilTimer = 10000*BloodboilCount;
                    }
                } else BloodboilTimer -= diff;
            }

            if (!Phase1)
            {
                if (AcidGeyserTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ACID_GEYSER);
                    AcidGeyserTimer = 30000;
                } else AcidGeyserTimer -= diff;

                if (EjectTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_EJECT2);
                    EjectTimer = 15000;
                } else EjectTimer -= diff;
            }

            if (PhaseChangeTimer <= diff)
            {
                if (Phase1)
                {
                    Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (pTarget && pTarget->isAlive())
                    {
                        Phase1 = false;

                        TargetThreat = DoGetThreat(pTarget);
                        TargetGUID = pTarget->GetGUID();
                        pTarget->CastSpell(me, SPELL_TAUNT_GURTOGG, true);
                        if (DoGetThreat(pTarget))
                            DoModifyThreatPercent(pTarget, -100);
                        me->AddThreat(pTarget, 50000000.0f);
                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                                                                // If VMaps are disabled, this spell can call the whole instance
                        DoCast(me, SPELL_INSIGNIFIGANCE, true);
                        DoCast(pTarget, SPELL_FEL_RAGE_TARGET, true);
                        DoCast(pTarget, SPELL_FEL_RAGE_2, true);
                        /* These spells do not work, comment them out for now.
                        DoCast(pTarget, SPELL_FEL_RAGE_2, true);
                        DoCast(pTarget, SPELL_FEL_RAGE_3, true);*/

                        //Cast this without triggered so that it appears in combat logs and shows visual.
                        DoCast(me, SPELL_FEL_RAGE_SELF);

                        DoScriptText(RAND(SAY_SPECIAL1, SAY_SPECIAL2), me);

                        AcidGeyserTimer = 1000;
                        PhaseChangeTimer = 30000;
                    }
                } else                                           // Encounter is a loop pretty much. Phase 1 -> Phase 2 -> Phase 1 -> Phase 2 till death or enrage
                {
                    if (TargetGUID)
                        RevertThreatOnTarget(TargetGUID);
                    TargetGUID = 0;
                    Phase1 = true;
                    BloodboilTimer = 10000;
                    BloodboilCount = 0;
                    AcidicWoundTimer += 2000;
                    ArcingSmashTimer += 2000;
                    FelAcidTimer += 2000;
                    EjectTimer += 2000;
                    PhaseChangeTimer = 60000;
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                }
            } else PhaseChangeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_gurtogg_bloodboil()
{
    new boss_gurtogg_bloodboil();
}
