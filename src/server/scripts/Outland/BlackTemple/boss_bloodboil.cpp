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

/* ScriptData
SDName: Boss_Bloodboil
SD%Complete: 80
SDComment: Bloodboil not working correctly, missing enrage
SDCategory: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "black_temple.h"

enum Bloodboil
{
    //Speech'n'Sound
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_SPECIAL                 = 2,
    SAY_ENRAGE                  = 3,
    SAY_DEATH                   = 4,

    //Spells
    SPELL_ACID_GEYSER           = 40630,
    SPELL_ACIDIC_WOUND          = 40481,
    SPELL_ARCING_SMASH          = 40599,
    SPELL_BLOODBOIL             = 42005,                      // This spell is AoE whereas it shouldn't be
    SPELL_FEL_ACID              = 40508,
    SPELL_FEL_RAGE_SELF         = 40594,
    SPELL_FEL_RAGE_TARGET       = 40604,
    SPELL_FEL_RAGE_2            = 40616,
    SPELL_FEL_RAGE_3            = 41625,
    SPELL_BEWILDERING_STRIKE    = 40491,
    SPELL_EJECT1                = 40486,                      // 1000 Physical damage + knockback + script effect (should handle threat reduction I think)
    SPELL_EJECT2                = 40597,                      // 1000 Physical damage + Stun (used in phase 2?)
    SPELL_TAUNT_GURTOGG         = 40603,
    SPELL_INSIGNIFIGANCE        = 40618,
    SPELL_BERSERK               = 45078
};


//This is used to sort the players by distance in preparation for the Bloodboil cast.

class boss_gurtogg_bloodboil : public CreatureScript
{
public:
    boss_gurtogg_bloodboil() : CreatureScript("boss_gurtogg_bloodboil") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_gurtogg_bloodboilAI>(creature);
    }

    struct boss_gurtogg_bloodboilAI : public ScriptedAI
    {
        boss_gurtogg_bloodboilAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

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

        void Reset() OVERRIDE
        {
            instance->SetBossState(DATA_GURTOGG_BLOODBOIL, NOT_STARTED);

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

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            DoZoneInCombat();
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_GURTOGG_BLOODBOIL, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            instance->SetBossState(DATA_GURTOGG_BLOODBOIL, DONE);

            Talk(SAY_DEATH);
        }

        // Note: This seems like a very complicated fix. The fix needs to be handled by the core, as implementation of limited-target AoE spells are still not limited.
        void CastBloodboil()
        {
            // Get the Threat List
            std::list<HostileReference*> m_threatlist = me->getThreatManager().getThreatList();

            if (m_threatlist.empty()) // He doesn't have anyone in his threatlist, useless to continue
                return;

            std::list<Unit*> targets;
            std::list<HostileReference*>::const_iterator itr = m_threatlist.begin();
            for (; itr!= m_threatlist.end(); ++itr)             //store the threat list in a different container
            {
                Unit* target = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                                                //only on alive players
                if (target && target->IsAlive() && target->GetTypeId() == TYPEID_PLAYER)
                    targets.push_back(target);
            }

            //Sort the list of players
            targets.sort(Trinity::ObjectDistanceOrderPred(me, false));
            //Resize so we only get top 5
            targets.resize(5);

            //Aura each player in the targets list with Bloodboil. Aura code copied+pasted from Aura command in Level3.cpp
            /*SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BLOODBOIL);
            if (spellInfo)
            {
                for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    Unit* target = *itr;
                    if (!target) return;
                    for (uint32 i = 0; i<3; ++i)
                    {
                        uint8 eff = spellInfo->Effect[i];
                        if (eff >= TOTAL_SPELL_EFFECTS)
                            continue;

                        Aura* Aur = new Aura(spellInfo, i, target, target, target);
                        target->AddAura(Aur);
                    }
                }
            }*/
        }

        void RevertThreatOnTarget(uint64 guid)
        {
            if (Unit* unit = Unit::GetUnit(*me, guid))
            {
                if (DoGetThreat(unit))
                    DoModifyThreatPercent(unit, -100);
                if (TargetThreat)
                    me->AddThreat(unit, TargetThreat);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (ArcingSmashTimer <= diff)
            {
                DoCastVictim(SPELL_ARCING_SMASH);
                ArcingSmashTimer = 10000;
            } else ArcingSmashTimer -= diff;

            if (FelAcidTimer <= diff)
            {
                DoCastVictim(SPELL_FEL_ACID);
                FelAcidTimer = 25000;
            } else FelAcidTimer -= diff;

            if (!me->HasAura(SPELL_BERSERK))
            {
                if (EnrageTimer <= diff)
                {
                    DoCast(me, SPELL_BERSERK);
                    Talk(SAY_ENRAGE);
                } else EnrageTimer -= diff;
            }

            if (Phase1)
            {
                if (BewilderingStrikeTimer <= diff)
                {
                    DoCastVictim(SPELL_BEWILDERING_STRIKE);
                    float mt_threat = DoGetThreat(me->GetVictim());
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                        me->AddThreat(target, mt_threat);
                    BewilderingStrikeTimer = 20000;
                } else BewilderingStrikeTimer -= diff;

                if (EjectTimer <= diff)
                {
                    DoCastVictim(SPELL_EJECT1);
                    DoModifyThreatPercent(me->GetVictim(), -40);
                    EjectTimer = 15000;
                } else EjectTimer -= diff;

                if (AcidicWoundTimer <= diff)
                {
                    DoCastVictim(SPELL_ACIDIC_WOUND);
                    AcidicWoundTimer = 10000;
                } else AcidicWoundTimer -= diff;

                if (BloodboilTimer <= diff)
                {
                    if (BloodboilCount < 5)                      // Only cast it five times.
                    {
                        //CastBloodboil(); // Causes issues on windows, so is commented out.
                        DoCastVictim(SPELL_BLOODBOIL);
                        ++BloodboilCount;
                        BloodboilTimer = 10000*BloodboilCount;
                    }
                } else BloodboilTimer -= diff;
            }

            if (!Phase1)
            {
                if (AcidGeyserTimer <= diff)
                {
                    DoCastVictim(SPELL_ACID_GEYSER);
                    AcidGeyserTimer = 30000;
                } else AcidGeyserTimer -= diff;

                if (EjectTimer <= diff)
                {
                    DoCastVictim(SPELL_EJECT2);
                    EjectTimer = 15000;
                } else EjectTimer -= diff;
            }

            if (PhaseChangeTimer <= diff)
            {
                if (Phase1)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        Phase1 = false;

                        TargetThreat = DoGetThreat(target);
                        TargetGUID = target->GetGUID();
                        target->CastSpell(me, SPELL_TAUNT_GURTOGG, true);
                        if (DoGetThreat(target))
                            DoModifyThreatPercent(target, -100);
                        me->AddThreat(target, 50000000.0f);
                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                                                                // If VMaps are disabled, this spell can call the whole instance
                        DoCast(me, SPELL_INSIGNIFIGANCE, true);
                        DoCast(target, SPELL_FEL_RAGE_TARGET, true);
                        DoCast(target, SPELL_FEL_RAGE_2, true);
                        /* These spells do not work, comment them out for now.
                        DoCast(target, SPELL_FEL_RAGE_2, true);
                        DoCast(target, SPELL_FEL_RAGE_3, true);*/

                        //Cast this without triggered so that it appears in combat logs and shows visual.
                        DoCast(me, SPELL_FEL_RAGE_SELF);

                        Talk(SAY_SPECIAL);

                        AcidGeyserTimer = 1000;
                        PhaseChangeTimer = 30000;
                    }
                }
                else                                           // Encounter is a loop pretty much. Phase 1 -> Phase 2 -> Phase 1 -> Phase 2 till death or enrage
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
