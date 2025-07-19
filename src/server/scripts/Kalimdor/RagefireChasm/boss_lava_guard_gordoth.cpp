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

#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TaskScheduler.h"
#include "ragefire_chasm.h"

enum GordothSpells
{
    // Intro
    SPELL_JAIL_BREAK        = 120025,
    SPELL_GROUND_SLAM       = 120023,
    SPELL_MEAT_EXPLOSION_1  = 111778,
    SPELL_MEAT_EXPLOSION_2  = 111779,
    SPELL_MEAT_EXPLOSION_3  = 111780,
    SPELL_BLOODY_SUICIDE    = 120022,

    SPELL_GROUND_RUPTURE    = 119999,
    SPELL_SEISMIC_SLAM      = 120024,
    SPELL_ENRAGE            = 50420
};

enum GordothEvents
{
    EVENT_GROUND_RUPTURE    = 1,
    EVENT_SEISMIC_SLAM      = 2
};

enum GordothActions
{
    ACTION_JUMP             = 1
};

enum GordothMisc
{
    NPC_DARK_SHAMAN_RESEARCHER = 61644,

    GO_GORDOTH_CAGE            = 211792,
    GO_LAB_VIAL                = 211784,

    ANIMKIT_GORDOTH_NONE       = 0,

    POINT_JUMP                 = 1
};

constexpr Position GordothJumpPos = { -363.5392f, 203.36604f, -22.005634f, 0.308123469352722167f };

// Areatrigger - 7899
class at_lava_guard_gordoth_intro : public OnlyOnceAreaTriggerScript
{
public:
    at_lava_guard_gordoth_intro() : OnlyOnceAreaTriggerScript("at_lava_guard_gordoth_intro") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (player->IsGameMaster())
            return false;

        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return false;

        Creature* gordoth = instance->GetCreature(BOSS_LAVA_GUARD_GORDOTH);
        if (!gordoth)
            return false;

        gordoth->AI()->DoAction(ACTION_JUMP);

        return true;
    }
};

// 61528 - Lava Guard Gordoth
struct boss_lava_guard_gordoth : public BossAI
{
    boss_lava_guard_gordoth(Creature* creature) : BossAI(creature, BOSS_LAVA_GUARD_GORDOTH), _enrageTriggered(false) { }

    void InitializeAI() override
    {
        if (instance->GetBossState(BOSS_LAVA_GUARD_GORDOTH) != NOT_STARTED)
            me->Relocate(GordothJumpPos);
    }

    void Reset() override
    {
        _Reset();

        _enrageTriggered = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_GROUND_RUPTURE, 7300ms);
        events.ScheduleEvent(EVENT_SEISMIC_SLAM, 13300ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_enrageTriggered)
            return;

        if (me->HealthBelowPctDamaged(31, damage))
        {
            _enrageTriggered = true;
            DoCastSelf(SPELL_ENRAGE);
        }
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_JUMP)
            return;

        me->SetAIAnimKitId(ANIMKIT_GORDOTH_NONE);
        DoCastSelf(SPELL_JAIL_BREAK);
        me->GetMotionMaster()->MoveJumpWithGravity(GordothJumpPos, 50.0f, 55.5477f, POINT_JUMP, GordothJumpPos.GetOrientation());

        scheduler.Schedule(30ms, [this](TaskContext /*task*/)
        {
            if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_GORDOTH_CAGE, 50.0f))
                go->SetGoState(GO_STATE_ACTIVE);
        });
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_JUMP)
        {
            DoCast(SPELL_GROUND_SLAM);
            me->SetHomePosition(GordothJumpPos);

            std::vector<GameObject*> labVialsList;
            GetGameObjectListWithEntryInGrid(labVialsList, me, GO_LAB_VIAL, 25.0f);
            for (GameObject* vial : labVialsList)
            {
                vial->SetGoState(GO_STATE_DESTROYED);
            }

            std::vector<Creature*> darkShamanResearcherList;
            GetCreatureListWithEntryInGrid(darkShamanResearcherList, me, NPC_DARK_SHAMAN_RESEARCHER, 25.0f);
            for (Creature* darkShamanResearcher : darkShamanResearcherList)
            {
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_1, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_1, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_2, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_2, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_3, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_3, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_MEAT_EXPLOSION_3, CastSpellExtraArgs(TRIGGERED_FULL_MASK)); // According to sniff
                darkShamanResearcher->CastSpell(darkShamanResearcher, SPELL_BLOODY_SUICIDE, false);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GROUND_RUPTURE:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_GROUND_RUPTURE);
                    events.Repeat(12100ms);
                    break;
                }
                case EVENT_SEISMIC_SLAM:
                {
                    DoCast(nullptr, SPELL_SEISMIC_SLAM, CastSpellExtraArgs(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD)); // cast earlier than category cd
                    events.Repeat(36300ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _enrageTriggered;
};

void AddSC_boss_lava_guard_gordoth()
{
    new at_lava_guard_gordoth_intro();

    RegisterRagefireChasmCreatureAI(boss_lava_guard_gordoth);
}
