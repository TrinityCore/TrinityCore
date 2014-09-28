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
Name: Boss_Bloodboil
Complete: 80
Category: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
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

class boss_gurtogg_bloodboil : public CreatureScript
{
public:
    boss_gurtogg_bloodboil() : CreatureScript("boss_gurtogg_bloodboil") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_gurtogg_bloodboilAI>(creature);
    }

    struct boss_gurtogg_bloodboilAI : public ScriptedAI
    {
        boss_gurtogg_bloodboilAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            TargetGUID.Clear();
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
        }

        InstanceScript* instance;

        ObjectGuid TargetGUID;

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

        void Reset() override
        {
            instance->SetBossState(DATA_GURTOGG_BLOODBOIL, NOT_STARTED);

            Initialize();

            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_GURTOGG_BLOODBOIL, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetBossState(DATA_GURTOGG_BLOODBOIL, DONE);

            Talk(SAY_DEATH);
        }

        void RevertThreatOnTarget(ObjectGuid guid)
        {
            if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
            {
                if (DoGetThreat(unit))
                    DoModifyThreatPercent(unit, -100);
                if (TargetThreat)
                    me->AddThreat(unit, TargetThreat);
            }
        }

        void UpdateAI(uint32 diff) override
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
                        DoCastAOE(SPELL_BLOODBOIL);
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
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
                    TargetGUID.Clear();
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

// 42005 - Bloodboil
class spell_gurtogg_bloodboil_bloodboil : public SpellScriptLoader
{
    public:
        spell_gurtogg_bloodboil_bloodboil() : SpellScriptLoader("spell_gurtogg_bloodboil_bloodboil") { }

        class spell_gurtogg_bloodboil_bloodboil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gurtogg_bloodboil_bloodboil_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() <= 5)
                    return;

                // Sort the list of players
                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), false));
                // Resize so we only get top 5
                targets.resize(5);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gurtogg_bloodboil_bloodboil_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gurtogg_bloodboil_bloodboil_SpellScript();
        }
};

void AddSC_boss_gurtogg_bloodboil()
{
    new boss_gurtogg_bloodboil();
    new spell_gurtogg_bloodboil_bloodboil();
}
