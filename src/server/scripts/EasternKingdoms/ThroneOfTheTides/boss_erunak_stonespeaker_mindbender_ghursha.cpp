/*
* Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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
SDName: Boss Erunak Stonespeaker & Mindbender Ghur'sha
SD%Complete: 100%
SDComment:
SDCategory: Throne of the Tides
EndScriptData */

#include "ScriptMgr.h"
#include "Vehicle.h"
#include "throne_of_the_tides.h"
#include "Spell.h"

enum Spells
{
    // Erunak Stonespeaker
    SPELL_EARTH_SHARDS = 84931, // VISUAL - missle?
    SPELL_EARTH_SHARD_AURA = 84935,
    SPELL_EARTH_SHARD_SUMMON = 84934,
    SPELL_EMBERSTRIKE = 76165,
    SPELL_LAVA_BOLT = 76171,
    SPELL_LAVA_BOLT_H = 91412,
    SPELL_MAGMA_SPLASH = 76170,
    // Mindbender Ghur'sha
    SPELL_ENSLAVE = 76207,
    SPELL_ENSLAVE_H = 91413,
    SPELL_ENSLAVE_BUFF = 76213, // Should be in SPELL_LINKED_SPELL with SPELL_ENSLAVE
    SPELL_ENSLAVE_VEHICLE = 76206,
    SPELL_ABSORB_MAGIC = 76307,
    SPELL_ABSORB_MAGIC_H = 76307,
    SPELL_MIND_FOG_SUMMON = 76234,
    SPELL_MIND_FOG_AURA = 76230, // Done in ct_addon aura
    SPELL_MIND_FOG_VISUAL = 76231, // Done in ct_addon aura
    SPELL_UNRELENTING_AGONY = 76339
};

enum eEncounterYells
{
    SAY_PHASE_1_END_MINDBENDER = 0,
    SAY_PHASE_1_END_ERUNAK = 1,
    SAY_MIND_CONTROL_1 = 2,
    SAY_MIND_CONTROL_2 = 3,
    SAY_MIND_CONTROL_3 = 4,
    SAY_MIND_FOG = 5,
    SAY_DEATH_MINDBENDER = 6,
    SAY_DEATH_ERUNAK = 7,
    SAY_KILL_PLAYER_1 = 8,
    SAY_KILL_PLAYER_2 = 9,
};

enum Adds
{
    NPC_EARTH_SHARDS    = 45469,
    NPC_MIND_FOG        = 40861,
};
enum Events
{
    EVENT_EARTH_SHARDS = 1,
    EVENT_EMBERSTRIKE = 2,
    EVENT_LAVA_BOLT = 3,
    EVENT_MAGMA_SPLASH = 4,
    EVENT_ENSLAVE = 5,
    EVENT_ABSORB_MAGIC = 6,
    EVENT_MIND_FOG = 7,
    EVENT_UNRELENTING_AGONY = 8,
};

// predicate function to select not charmed target
struct NotCharmedTargetSelector : public std::unary_function<Unit*, bool>
{
    NotCharmedTargetSelector() {}

    bool operator()(Unit const* target) const
    {
        return !target->IsCharmed();
    }
};

class boss_erunak_stonespeaker : public CreatureScript
{
public:
    boss_erunak_stonespeaker() : CreatureScript("boss_erunak_stonespeaker") { }

    struct boss_erunak_stonespeakerAI : public ScriptedAI
    {
        boss_erunak_stonespeakerAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        std::list<ObjectGuid> SummonList;
        bool isEnslaved;
        InstanceScript* pInstance;
        EventMap events;

        void Reset() override
        {
            isEnslaved = true;

            if (pInstance)
                pInstance->SetData(DATA_ERUNAK_STONESPEAKER, NOT_STARTED);
        }

        void JustSummoned(Creature* pSummon) override
        {
            switch (pSummon->GetEntry())
            {
            case NPC_EARTH_SHARDS:
                SummonList.push_back(pSummon->GetGUID());
                break;
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (me->GetVehicleKit()->GetPassenger(0))
                Talk(RAND(SAY_KILL_PLAYER_1, SAY_KILL_PLAYER_2));
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (me->GetCurrentSpell(CURRENT_GENERIC_SPELL)->m_spellInfo->Id == SPELL_LAVA_BOLT
                || me->GetCurrentSpell(CURRENT_GENERIC_SPELL)->m_spellInfo->Id == SPELL_LAVA_BOLT_H)
            for (uint8 i = 0; i < 3; ++i)
            if (spell->GetEffect(i)->Effect == SPELL_EFFECT_INTERRUPT_CAST)
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_EARTH_SHARDS, 8000);
            events.ScheduleEvent(EVENT_EMBERSTRIKE, 11000);
            events.ScheduleEvent(EVENT_LAVA_BOLT, 13000);
            events.ScheduleEvent(EVENT_MAGMA_SPLASH, 6000);
            if (pInstance)
                pInstance->SetBossState(DATA_MINDBENDER_GHURSHA, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!isEnslaved)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_EARTH_SHARDS:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_EARTH_SHARDS);
                    events.ScheduleEvent(EVENT_EARTH_SHARDS, 20000);
                    break;
                case EVENT_EMBERSTRIKE:
                    DoCast(me->GetVictim(), SPELL_EMBERSTRIKE);
                    events.ScheduleEvent(EVENT_EMBERSTRIKE, 11000);
                    break;
                case EVENT_LAVA_BOLT:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_LAVA_BOLT);
                    events.ScheduleEvent(EVENT_LAVA_BOLT, 14000);
                    break;
                case EVENT_MAGMA_SPLASH:
                    DoCast(me, SPELL_MAGMA_SPLASH);
                    events.ScheduleEvent(EVENT_MAGMA_SPLASH, 13000);
                    break;
                }
            }

            if (HealthBelowPct(50))
            {
                if (Unit * mindbender = me->GetVehicleKit()->GetPassenger(0))
                {
                    mindbender->ExitVehicle();
                    mindbender->setFaction(14);
                }

                me->CombatStop(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                Talk(SAY_PHASE_1_END_ERUNAK);
                isEnslaved = false;
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                return;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_erunak_stonespeakerAI(pCreature);
    }
};


class boss_mindbender_ghursha : public CreatureScript
{
public:
    boss_mindbender_ghursha() : CreatureScript("boss_mindbender_ghursha") { }

    struct boss_mindbender_ghurshaAI : public ScriptedAI
    {
        boss_mindbender_ghurshaAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        std::list<ObjectGuid> SummonList;

        InstanceScript *pInstance;

        uint32 EnslaveTimer;
        uint32 AbsorbMagicTimer;
        uint32 MindFogTimer;
        uint32 UnrelentingAgonyTimer;
        uint32 CastTimer;
        ObjectGuid EnslaveTargetGUID;

        void Reset() override
        {
            RemoveSummons();
            EnslaveTargetGUID = ObjectGuid::Empty;
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(RAND(SAY_KILL_PLAYER_1, SAY_KILL_PLAYER_2));
        }

        void SetSpellTimers()
        {
            AbsorbMagicTimer = 20000;
            MindFogTimer = urand(6000, 12000);
            UnrelentingAgonyTimer = 10000;
        }

        void HandleEnslave(Unit * target, bool apply)
        {
            EnslaveTargetGUID = (apply ? target->GetGUID() : ObjectGuid::Empty);
            if (apply)
            {
                me->CastSpell(target, SPELL_ENSLAVE_BUFF, true);
                target->CastSpell(target, SPELL_ENSLAVE_VEHICLE, true);
                me->EnterVehicle(target);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            else
            {
                me->ExitVehicle();
                target->RemoveAurasDueToSpell(SPELL_ENSLAVE_BUFF);
                target->RemoveAurasDueToSpell(SPELL_ENSLAVE_VEHICLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        void JustReachedHome() override
        {
            if (pInstance)
            {
                if (Creature * pErunak = pInstance->GetCreature((DATA_ERUNAK_STONESPEAKER)))
                {
                    pErunak->SetReactState(REACT_AGGRESSIVE);
                    pErunak->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pErunak->setFaction(16);
                    pErunak->Respawn(true);
                    me->DespawnOrUnsummon();
                }

                pInstance->HandleGameObject(pInstance->GetGuidData(GO_ERUNAK_STONESPEAKER_DOOR), true);
                pInstance->SetData(DATA_ERUNAK_STONESPEAKER, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_PHASE_1_END_MINDBENDER);
            EnslaveTimer = 5000;
            SetSpellTimers();
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for (std::list<ObjectGuid>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* pTemp = ObjectAccessor::GetCreature(*me, *itr))
                if (pTemp)
                    pTemp->DisappearAndDie();
            }
            SummonList.clear();
        }

        void JustSummoned(Creature* pSummon) override
        {
            SummonList.push_back(pSummon->GetGUID());
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!EnslaveTargetGUID)
            {
                if (EnslaveTimer <= diff)
                {
                    if (Unit * EnslaveTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        DoZoneInCombat();
                        DoCast(EnslaveTarget, SPELL_ENSLAVE);
                        Talk(RAND(SAY_MIND_CONTROL_1, SAY_MIND_CONTROL_2, SAY_MIND_CONTROL_3));
                        EnslaveTimer = 60000;
                        SetSpellTimers();
                        CastTimer = 2000;
                    }
                }
                else EnslaveTimer -= diff;
            }

            if (Unit * EnslaveTarget = ObjectAccessor::GetCreature(*me, EnslaveTargetGUID))
            if (EnslaveTarget->HealthBelowPct(50))
                EnslaveTarget->RemoveAurasDueToSpell(IsHeroic() ? SPELL_ENSLAVE_H : SPELL_ENSLAVE);

            if (CastTimer <= diff && !EnslaveTargetGUID.IsEmpty())
            {
                if (Unit * EnslaveTarget = ObjectAccessor::GetCreature(*me, EnslaveTargetGUID))
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, NotCharmedTargetSelector()))
                {
                    switch (EnslaveTarget->getClass())
                    {
                    case CLASS_DRUID:
                        if (urand(0, 1))
                            EnslaveTarget->CastSpell(pTarget, 8921, false);
                        else
                            EnslaveTarget->CastSpell(me, 774, false);
                        break;
                    case CLASS_HUNTER:
                        EnslaveTarget->CastSpell(pTarget, RAND(2643, 1978), false);
                        break;
                    case CLASS_MAGE:
                        EnslaveTarget->CastSpell(pTarget, RAND(44614, 30455), false);
                        break;
                    case CLASS_WARLOCK:
                        EnslaveTarget->CastSpell(pTarget, RAND(980, 686), true);
                        break;
                    case CLASS_WARRIOR:
                        EnslaveTarget->CastSpell(pTarget, RAND(46924, 845), false);
                        break;
                    case CLASS_PALADIN:
                        if (urand(0, 1))
                            EnslaveTarget->CastSpell(pTarget, 853, false);
                        else
                            EnslaveTarget->CastSpell(me, 20473, false);
                        break;
                    case CLASS_PRIEST:
                        if (urand(0, 1))
                            EnslaveTarget->CastSpell(pTarget, 34914, false);
                        else
                            EnslaveTarget->CastSpell(me, 139, false);
                        break;
                    case CLASS_SHAMAN:
                        if (urand(0, 1))
                            EnslaveTarget->CastSpell(pTarget, 421, false);
                        else
                            EnslaveTarget->CastSpell(me, 61295, false);
                        break;
                    case CLASS_ROGUE:
                        EnslaveTarget->CastSpell(pTarget, RAND(16511, 1329), false);
                        break;
                    case CLASS_DEATH_KNIGHT:
                        if (urand(0, 1))
                            EnslaveTarget->CastSpell(pTarget, 45462, true);
                        else
                            EnslaveTarget->CastSpell(pTarget, 49184, true);
                        break;
                    }
                }
                CastTimer = 3000;
            }
            else CastTimer -= diff;

            if (!EnslaveTargetGUID.IsEmpty())
                return;

            if (AbsorbMagicTimer <= diff)
            {
                DoCast(me, SPELL_ABSORB_MAGIC);
                AbsorbMagicTimer = urand(15000, 20000);
            }
            else AbsorbMagicTimer -= diff;

            if (MindFogTimer <= diff)
            {
                DoCast(me, SPELL_MIND_FOG_SUMMON);
                Talk(SAY_MIND_FOG);
                MindFogTimer = 18000;
            }
            else MindFogTimer -= diff;

            if (UnrelentingAgonyTimer <= diff)
            {
                DoCastAOE(SPELL_UNRELENTING_AGONY);
                UnrelentingAgonyTimer = 20000;
            }
            else UnrelentingAgonyTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*pKiller*/) override
        {
            Talk(SAY_DEATH_MINDBENDER);
            if (pInstance)
            {
                pInstance->HandleGameObject(pInstance->GetGuidData(GO_ERUNAK_STONESPEAKER_DOOR), true);
                pInstance->SetData(DATA_ERUNAK_STONESPEAKER, DONE);
                if (pInstance->instance->GetCreature(pInstance->GetGuidData(DATA_ERUNAK_STONESPEAKER)))
                    Talk(SAY_DEATH_ERUNAK);
            }
            RemoveSummons();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_mindbender_ghurshaAI(pCreature);
    }
};

#define mindbenderAI boss_mindbender_ghursha::boss_mindbender_ghurshaAI

class spell_mindbender_enslave : public SpellScriptLoader
{
public:
    spell_mindbender_enslave() : SpellScriptLoader("spell_mindbender_enslave") { }

    class spell_mindbender_enslave_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mindbender_enslave_AuraScript);

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            Unit* caster = GetCaster();
            if (!caster || !target || caster->GetTypeId() != TYPEID_UNIT)
                return;

            if (mindbenderAI * pAI = CAST_AI(mindbenderAI, caster->ToCreature()->AI()))
                pAI->HandleEnslave(target, true);
        }

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            Unit* caster = GetCaster();
            if (!caster || !target || caster->GetTypeId() != TYPEID_UNIT)
                return;

            if (mindbenderAI * pAI = CAST_AI(mindbenderAI, caster->ToCreature()->AI()))
            {
                pAI->HandleEnslave(target, false);
                // Kill target in heroic mode if aura expired
                if (GetId() == 91413 && GetDuration() == 0)
                    caster->Kill(target, true);
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_mindbender_enslave_AuraScript::HandleEffectApply, EFFECT_1, SPELL_AURA_MOD_CHARM, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_mindbender_enslave_AuraScript::HandleEffectRemove, EFFECT_1, SPELL_AURA_MOD_CHARM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mindbender_enslave_AuraScript();
    }
};

class npc_ghursha_mind_fog : public CreatureScript
{
public:
    npc_ghursha_mind_fog() : CreatureScript("npc_ghursha_mind_fog") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_ghursha_mind_fogAI(pCreature);
    }

    struct npc_ghursha_mind_fogAI : public Scripted_NoMovementAI
    {
        npc_ghursha_mind_fogAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            DoCast(me, SPELL_MIND_FOG_AURA, true);
            DoCast(me, SPELL_MIND_FOG_VISUAL, true);
        }
    };
};

void AddSC_boss_erunak_stonespeaker()
{
    new boss_erunak_stonespeaker();
    new boss_mindbender_ghursha();
    new spell_mindbender_enslave();
    new npc_ghursha_mind_fog();
}
