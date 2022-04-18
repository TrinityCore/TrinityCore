/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "InstanceScript.h"
#include "nexus.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_SPARK                                   = 47751,
    H_SPELL_SPARK                                 = 57062,
    SPELL_RIFT_SHIELD                             = 47748,
    SPELL_CHARGE_RIFT                             = 47747, // Works wrong (affect players, not rifts)
    SPELL_CREATE_RIFT                             = 47743, // Don't work, using WA
    SPELL_ARCANE_ATTRACTION                       = 57063, // No idea, when it's used
};

enum Adds
{
    NPC_CRAZED_MANA_WRAITH                        = 26746,
    NPC_CHAOTIC_RIFT                              = 26918
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_DEATH                                     = 1,
    SAY_RIFT                                      = 2,
    SAY_SHIELD                                    = 3,
    SAY_RIFT_EMOTE                                = 4, // Needs to be added to script
    SAY_SHIELD_EMOTE                              = 5  // Needs to be added to script
};

enum RiftSpells
{
    SPELL_CHAOTIC_ENERGY_BURST                    = 47688,
    SPELL_CHARGED_CHAOTIC_ENERGY_BURST            = 47737,
    SPELL_ARCANEFORM                              = 48019, // Chaotic Rift visual
};

Position const RiftLocation[6] =
{
    { 652.64f, -273.70f, -8.75f, 0.0f },
    { 634.45f, -265.94f, -8.44f, 0.0f },
    { 620.73f, -281.17f, -9.02f, 0.0f },
    { 626.10f, -304.67f, -9.44f, 0.0f },
    { 639.87f, -314.11f, -9.49f, 0.0f },
    { 651.72f, -297.44f, -9.37f, 0.0f }
};

enum Misc
{
    DATA_CHAOS_THEORY                           = 1
};

struct boss_anomalus : public ScriptedAI
{
    boss_anomalus(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = me->GetInstanceScript();
    }

    void Initialize()
    {
        Phase = 0;
        uiSparkTimer = 5000;
        uiChaoticRiftGUID.Clear();
        chaosTheory = true;
    }

    InstanceScript* instance;

    uint8 Phase;
    uint32 uiSparkTimer;
    ObjectGuid uiChaoticRiftGUID;
    bool chaosTheory;

    void Reset() override
    {
        Initialize();

        instance->SetBossState(DATA_ANOMALUS, NOT_STARTED);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);

        instance->SetBossState(DATA_ANOMALUS, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);

        instance->SetBossState(DATA_ANOMALUS, DONE);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_CHAOS_THEORY)
            return chaosTheory ? 1 : 0;

        return 0;
    }

    void SummonedCreatureDies(Creature* summoned, Unit* /*who*/) override
    {
        if (summoned->GetEntry() == NPC_CHAOTIC_RIFT)
            chaosTheory = false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->GetDistance(me->GetHomePosition()) > 60.0f)
        {
            // Not blizzlike, hack to avoid an exploit
            EnterEvadeMode();
            return;
        }

        if (me->HasAura(SPELL_RIFT_SHIELD))
        {
            if (!uiChaoticRiftGUID.IsEmpty())
            {
                Creature* Rift = ObjectAccessor::GetCreature(*me, uiChaoticRiftGUID);
                if (Rift && Rift->isDead())
                {
                    me->RemoveAurasDueToSpell(SPELL_RIFT_SHIELD);
                    uiChaoticRiftGUID.Clear();
                }
                return;
            }
        }
        else
            uiChaoticRiftGUID.Clear();

        if ((Phase == 0) && HealthBelowPct(50))
        {
            Phase = 1;
            Talk(SAY_SHIELD);
            DoCast(me, SPELL_RIFT_SHIELD);
            if (Creature* Rift = me->SummonCreature(NPC_CHAOTIC_RIFT, RiftLocation[urand(0, 5)], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1s))
            {
                //DoCast(Rift, SPELL_CHARGE_RIFT);
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    Rift->AI()->AttackStart(target);
                uiChaoticRiftGUID = Rift->GetGUID();
                Talk(SAY_RIFT);
            }
        }

        if (uiSparkTimer <= diff)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_SPARK);
            uiSparkTimer = 5000;
        }
        else
            uiSparkTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct npc_chaotic_rift : public ScriptedAI
{
    npc_chaotic_rift(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = me->GetInstanceScript();
        SetCombatMovement(false);
    }

    void Initialize()
    {
        uiChaoticEnergyBurstTimer = 1000;
        uiSummonCrazedManaWraithTimer = 5000;
    }

    InstanceScript* instance;

    uint32 uiChaoticEnergyBurstTimer;
    uint32 uiSummonCrazedManaWraithTimer;

    void Reset() override
    {
        Initialize();
        me->SetDisplayFromModel(1);
        DoCast(me, SPELL_ARCANEFORM, false);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (uiChaoticEnergyBurstTimer <= diff)
        {
            Creature* Anomalus = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANOMALUS));
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            {
                if (Anomalus && Anomalus->HasAura(SPELL_RIFT_SHIELD))
                    DoCast(target, SPELL_CHARGED_CHAOTIC_ENERGY_BURST);
                else
                    DoCast(target, SPELL_CHAOTIC_ENERGY_BURST);
            }
            uiChaoticEnergyBurstTimer = 1000;
        }
        else
            uiChaoticEnergyBurstTimer -= diff;

        if (uiSummonCrazedManaWraithTimer <= diff)
        {
            if (Creature* Wraith = me->SummonCreature(NPC_CRAZED_MANA_WRAITH, me->GetPositionX() + 1, me->GetPositionY() + 1, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1s))
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    Wraith->AI()->AttackStart(target);
            Creature* Anomalus = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANOMALUS));
            if (Anomalus && Anomalus->HasAura(SPELL_RIFT_SHIELD))
                uiSummonCrazedManaWraithTimer = 5000;
            else
                uiSummonCrazedManaWraithTimer = 10000;
        }
        else
            uiSummonCrazedManaWraithTimer -= diff;
    }
};

class achievement_chaos_theory : public AchievementCriteriaScript
{
    public:
        achievement_chaos_theory() : AchievementCriteriaScript("achievement_chaos_theory")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Anomalus = target->ToCreature())
                if (Anomalus->AI()->GetData(DATA_CHAOS_THEORY))
                    return true;

            return false;
        }
};

void AddSC_boss_anomalus()
{
    RegisterNexusCreatureAI(boss_anomalus);
    RegisterNexusCreatureAI(npc_chaotic_rift);
    new achievement_chaos_theory();
}
