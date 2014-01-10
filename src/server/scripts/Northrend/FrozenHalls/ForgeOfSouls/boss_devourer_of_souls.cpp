/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "Player.h"
#include "SpellInfo.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "forge_of_souls.h"

/*
 * @todo
 * - Fix model id during unleash soul -> seems DB issue 36503 is missing (likewise 36504 is also missing).
 * - Fix outro npc movement
 */

enum Yells
{
    SAY_FACE_AGGRO                              = 0,
    SAY_FACE_ANGER_SLAY                         = 1,
    SAY_FACE_SORROW_SLAY                        = 2,
    SAY_FACE_DESIRE_SLAY                        = 3,
    SAY_FACE_DEATH                              = 4,
    EMOTE_MIRRORED_SOUL                         = 5,
    EMOTE_UNLEASH_SOUL                          = 6,
    SAY_FACE_UNLEASH_SOUL                       = 7,
    EMOTE_WAILING_SOUL                          = 8,
    SAY_FACE_WAILING_SOUL                       = 9,

    SAY_JAINA_OUTRO                             = 0,
    SAY_SYLVANAS_OUTRO                          = 0
};

enum Spells
{
    SPELL_PHANTOM_BLAST                         = 68982,
    H_SPELL_PHANTOM_BLAST                       = 70322,
    SPELL_MIRRORED_SOUL_PROC_AURA               = 69023,
    SPELL_MIRRORED_SOUL_DAMAGE                  = 69034,
    SPELL_MIRRORED_SOUL_TARGET_SELECTOR         = 69048,
    SPELL_MIRRORED_SOUL_BUFF                    = 69051,
    SPELL_WELL_OF_SOULS                         = 68820,
    SPELL_UNLEASHED_SOULS                       = 68939,
    SPELL_WAILING_SOULS_STARTING                = 68912,  // Initial spell cast at begining of wailing souls phase
    SPELL_WAILING_SOULS_BEAM                    = 68875,  // the beam visual
    SPELL_WAILING_SOULS                         = 68873,  // the actual spell
    H_SPELL_WAILING_SOULS                       = 70324,
//    68871, 68873, 68875, 68876, 68899, 68912, 70324,
// 68899 trigger 68871
};

enum Events
{
    EVENT_PHANTOM_BLAST         = 1,
    EVENT_MIRRORED_SOUL         = 2,
    EVENT_WELL_OF_SOULS         = 3,
    EVENT_UNLEASHED_SOULS       = 4,
    EVENT_WAILING_SOULS         = 5,
    EVENT_WAILING_SOULS_TICK    = 6,
    EVENT_FACE_ANGER            = 7,
};

enum Models
{
    DISPLAY_ANGER               = 30148,
    DISPLAY_SORROW              = 30149,
    DISPLAY_DESIRE              = 30150,
};

struct outroPosition
{
    uint32 entry[2];
    Position movePosition;
} outroPositions[] =
{
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5590.47f, 2427.79f, 705.935f, 0.802851f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5593.59f, 2428.34f, 705.935f, 0.977384f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5600.81f, 2429.31f, 705.935f, 0.890118f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5600.81f, 2421.12f, 705.935f, 0.890118f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5601.43f, 2426.53f, 705.935f, 0.890118f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5601.55f, 2418.36f, 705.935f, 1.15192f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5598, 2429.14f, 705.935f, 1.0472f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5594.04f, 2424.87f, 705.935f, 1.15192f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 5597.89f, 2421.54f, 705.935f, 0.610865f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5598.57f, 2434.62f, 705.935f, 1.13446f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5585.46f, 2417.99f, 705.935f, 1.06465f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5605.81f, 2428.42f, 705.935f, 0.820305f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5591.61f, 2412.66f, 705.935f, 0.925025f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5593.9f, 2410.64f, 705.935f, 0.872665f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 5586.76f, 2416.73f, 705.935f, 0.942478f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 5592.23f, 2419.14f, 705.935f, 0.855211f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 5594.61f, 2416.87f, 705.935f, 0.907571f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 5589.77f, 2421.03f, 705.935f, 0.855211f } },

    { { NPC_KORELN, NPC_LORALEN }, { 5602.58f, 2435.95f, 705.935f, 0.959931f } },
    { { NPC_ELANDRA, NPC_KALIRA }, { 5606.13f, 2433.16f, 705.935f, 0.785398f } },
    { { NPC_JAINA_PART2, NPC_SYLVANAS_PART2 }, { 5606.12f, 2436.6f, 705.935f, 0.890118f } },

    { { 0, 0 }, { 0.0f, 0.0f, 0.0f, 0.0f } }
};

Position const CrucibleSummonPos = {5672.294f, 2520.686f, 713.4386f, 0.9599311f};

enum Misc
{
    DATA_THREE_FACED                = 1
};

class boss_devourer_of_souls : public CreatureScript
{
    public:
        boss_devourer_of_souls() : CreatureScript("boss_devourer_of_souls") { }

        struct boss_devourer_of_soulsAI : public BossAI
        {
            boss_devourer_of_soulsAI(Creature* creature) : BossAI(creature, DATA_DEVOURER_EVENT)
            {
            }

            void InitializeAI() OVERRIDE
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(FoSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() OVERRIDE
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetDisplayId(DISPLAY_ANGER);
                me->SetReactState(REACT_AGGRESSIVE);

                events.Reset();
                summons.DespawnAll();

                threeFaced = true;

                instance->SetData(DATA_DEVOURER_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_FACE_AGGRO);

                if (!me->FindNearestCreature(NPC_CRUCIBLE_OF_SOULS, 60)) // Prevent double spawn
                    instance->instance->SummonCreature(NPC_CRUCIBLE_OF_SOULS, CrucibleSummonPos);
                events.ScheduleEvent(EVENT_PHANTOM_BLAST, 5000);
                events.ScheduleEvent(EVENT_MIRRORED_SOUL, 8000);
                events.ScheduleEvent(EVENT_WELL_OF_SOULS, 30000);
                events.ScheduleEvent(EVENT_UNLEASHED_SOULS, 20000);
                events.ScheduleEvent(EVENT_WAILING_SOULS, urand(60000, 70000));

                instance->SetData(DATA_DEVOURER_EVENT, IN_PROGRESS);
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                int32 textId = 0;
                switch (me->GetDisplayId())
                {
                    case DISPLAY_ANGER:
                        textId = SAY_FACE_ANGER_SLAY;
                        break;
                    case DISPLAY_SORROW:
                        textId = SAY_FACE_SORROW_SLAY;
                        break;
                    case DISPLAY_DESIRE:
                        textId = SAY_FACE_DESIRE_SLAY;
                        break;
                    default:
                        break;
                }

                if (textId)
                    Talk(textId);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                summons.DespawnAll();

                Position spawnPoint = {5618.139f, 2451.873f, 705.854f, 0};

                Talk(SAY_FACE_DEATH);

                instance->SetData(DATA_DEVOURER_EVENT, DONE);

                int32 entryIndex;
                if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                    entryIndex = 0;
                else
                    entryIndex = 1;

                for (int8 i = 0; outroPositions[i].entry[entryIndex] != 0; ++i)
                {
                    if (Creature* summon = me->SummonCreature(outroPositions[i].entry[entryIndex], spawnPoint, TEMPSUMMON_DEAD_DESPAWN))
                    {
                        summon->GetMotionMaster()->MovePoint(0, outroPositions[i].movePosition);
                        if (summon->GetEntry() == NPC_JAINA_PART2)
                            summon->AI()->Talk(SAY_JAINA_OUTRO);
                        else if (summon->GetEntry() == NPC_SYLVANAS_PART2)
                            summon->AI()->Talk(SAY_SYLVANAS_OUTRO);
                    }
                }
            }

            void SpellHitTarget(Unit* /*target*/, const SpellInfo* spell) OVERRIDE
            {
                if (spell->Id == H_SPELL_PHANTOM_BLAST)
                    threeFaced = false;
            }

            uint32 GetData(uint32 type) const OVERRIDE
            {
                if (type == DATA_THREE_FACED)
                    return threeFaced;

                return 0;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PHANTOM_BLAST:
                            DoCastVictim(SPELL_PHANTOM_BLAST);
                            events.ScheduleEvent(EVENT_PHANTOM_BLAST, 5000);
                            break;
                        case EVENT_MIRRORED_SOUL:
                            DoCastAOE(SPELL_MIRRORED_SOUL_TARGET_SELECTOR);
                            Talk(EMOTE_MIRRORED_SOUL);
                            events.ScheduleEvent(EVENT_MIRRORED_SOUL, urand(15000, 30000));
                            break;
                        case EVENT_WELL_OF_SOULS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_WELL_OF_SOULS);
                            events.ScheduleEvent(EVENT_WELL_OF_SOULS, 20000);
                            break;
                        case EVENT_UNLEASHED_SOULS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_UNLEASHED_SOULS);
                            me->SetDisplayId(DISPLAY_SORROW);
                            Talk(SAY_FACE_UNLEASH_SOUL);
                            Talk(EMOTE_UNLEASH_SOUL);
                            events.ScheduleEvent(EVENT_UNLEASHED_SOULS, 30000);
                            events.ScheduleEvent(EVENT_FACE_ANGER, 5000);
                            break;
                        case EVENT_FACE_ANGER:
                            me->SetDisplayId(DISPLAY_ANGER);
                            break;

                        case EVENT_WAILING_SOULS:
                            me->SetDisplayId(DISPLAY_DESIRE);
                            Talk(SAY_FACE_WAILING_SOUL);
                            Talk(EMOTE_WAILING_SOUL);
                            DoCast(me, SPELL_WAILING_SOULS_STARTING);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                me->SetFacingToObject(target);
                                DoCast(me, SPELL_WAILING_SOULS_BEAM);
                            }

                            beamAngle = me->GetOrientation();

                            beamAngleDiff = M_PI/30.0f; // PI/2 in 15 sec = PI/30 per tick
                            if (RAND(true, false))
                                beamAngleDiff = -beamAngleDiff;

                            me->InterruptNonMeleeSpells(false);
                            me->SetReactState(REACT_PASSIVE);

                            //Remove any target
                            me->SetTarget(0);

                            me->GetMotionMaster()->Clear();
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                            wailingSoulTick = 15;
                            events.DelayEvents(18000); // no other events during wailing souls
                            events.ScheduleEvent(EVENT_WAILING_SOULS_TICK, 3000); // first one after 3 secs.
                            break;

                        case EVENT_WAILING_SOULS_TICK:
                            beamAngle += beamAngleDiff;
                            me->SetFacingTo(beamAngle);
                            me->StopMoving();

                            DoCast(me, SPELL_WAILING_SOULS);

                            if (--wailingSoulTick)
                                events.ScheduleEvent(EVENT_WAILING_SOULS_TICK, 1000);
                            else
                            {
                                me->SetReactState(REACT_AGGRESSIVE);
                                me->SetDisplayId(DISPLAY_ANGER);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                                me->GetMotionMaster()->MoveChase(me->GetVictim());
                                events.ScheduleEvent(EVENT_WAILING_SOULS, urand(60000, 70000));
                            }
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool threeFaced;

            // wailing soul event
            float beamAngle;
            float beamAngleDiff;
            int8 wailingSoulTick;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_devourer_of_soulsAI>(creature);
        }
};

// 69051 - Mirrored Soul
class spell_devourer_of_souls_mirrored_soul : public SpellScriptLoader
{
    public:
        spell_devourer_of_souls_mirrored_soul() : SpellScriptLoader("spell_devourer_of_souls_mirrored_soul") { }

        class spell_devourer_of_souls_mirrored_soul_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_devourer_of_souls_mirrored_soul_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MIRRORED_SOUL_PROC_AURA))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(GetCaster(), SPELL_MIRRORED_SOUL_PROC_AURA, true);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_devourer_of_souls_mirrored_soul_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_devourer_of_souls_mirrored_soul_SpellScript();
        }
};

// 69023 - Mirrored Soul (Proc)
class spell_devourer_of_souls_mirrored_soul_proc : public SpellScriptLoader
{
    public:
        spell_devourer_of_souls_mirrored_soul_proc() : SpellScriptLoader("spell_devourer_of_souls_mirrored_soul_proc") { }

        class spell_devourer_of_souls_mirrored_soul_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_devourer_of_souls_mirrored_soul_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MIRRORED_SOUL_DAMAGE))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetCaster() && GetCaster()->IsAlive();
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 damage = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), 45));
                GetTarget()->CastCustomSpell(SPELL_MIRRORED_SOUL_DAMAGE, SPELLVALUE_BASE_POINT0, damage, GetCaster(), true);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_devourer_of_souls_mirrored_soul_proc_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_devourer_of_souls_mirrored_soul_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_devourer_of_souls_mirrored_soul_proc_AuraScript();
        }
};

// 69048 - Mirrored Soul (Target Selector)
class spell_devourer_of_souls_mirrored_soul_target_selector : public SpellScriptLoader
{
    public:
        spell_devourer_of_souls_mirrored_soul_target_selector() : SpellScriptLoader("spell_devourer_of_souls_mirrored_soul_target_selector") { }

        class spell_devourer_of_souls_mirrored_soul_target_selector_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_devourer_of_souls_mirrored_soul_target_selector_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MIRRORED_SOUL_BUFF))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_MIRRORED_SOUL_BUFF, false);
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_devourer_of_souls_mirrored_soul_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_devourer_of_souls_mirrored_soul_target_selector_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_devourer_of_souls_mirrored_soul_target_selector_SpellScript();
        }
};

class achievement_three_faced : public AchievementCriteriaScript
{
    public:
        achievement_three_faced() : AchievementCriteriaScript("achievement_three_faced") { }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* Devourer = target->ToCreature())
                if (Devourer->AI()->GetData(DATA_THREE_FACED))
                    return true;

            return false;
        }
};

void AddSC_boss_devourer_of_souls()
{
    new boss_devourer_of_souls();
    new spell_devourer_of_souls_mirrored_soul();
    new spell_devourer_of_souls_mirrored_soul_proc();
    new spell_devourer_of_souls_mirrored_soul_target_selector();
    new achievement_three_faced();
}
