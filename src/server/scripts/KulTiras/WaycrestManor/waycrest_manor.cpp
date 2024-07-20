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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "waycrest_manor.h"

enum WaycrestManorSpells
{
    SPELL_ORGAN_MISSILES              = 267646,
    SPELL_DEATH_REALM_PHASE           = 263332,
    SPELL_WAYCRESTS_DEFEATED_ALLIANCE = 267597,
    SPELL_WAYCRESTS_DEFEATED_HORDE    = 267595,
    SPELL_COSMETIC_MISSILE_TRANSFORM  = 267669
};

enum WaycrestManorMisc
{
    // Conversations after Waycrests are defeated
    CONVERSATION_LINE_LUCILLE_WAYCREST = 16957,
    CONVERSATION_LINE_GORAK_TUL_HORDE  = 16850,
    CONVO_ACTOR_IDX_GORAK_TUL          = 0,

    PATH_GORAK_TUL                     = 13616100
};

enum WaycrestManorEvents
{
    EVENT_GORAK_TUL_TRANSFORM = 1,
    EVENT_GORAK_TUL_MOVE
};

// 267643 - Organ Missiles
struct at_waycrest_manor_organ_missiles : AreaTriggerAI
{
    at_waycrest_manor_organ_missiles(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(100ms, 300ms, [this](TaskContext task)
        {
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(at->GetPosition(), SPELL_ORGAN_MISSILES, TRIGGERED_IGNORE_CAST_IN_PROGRESS);

            task.Repeat(100ms, 300ms);
        });
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            Creature* casterCreature = caster->ToCreature();
            if (!casterCreature)
                return;

            InstanceScript* instance = casterCreature->GetInstanceScript();
            if (!instance)
                return;

            casterCreature->RemoveAurasDueToSpell(SPELL_DEATH_REALM_PHASE);
            casterCreature->SetUninteractible(false);
            casterCreature->CastSpell(casterCreature, instance->instance->GetTeamInInstance() == HORDE ? SPELL_WAYCRESTS_DEFEATED_HORDE : SPELL_WAYCRESTS_DEFEATED_ALLIANCE);
        }
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 267646 - Organ Missiles
class spell_waycrest_manor_organ_missiles : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ frand(-26.0f, -15.0f), frand(-26.0f, 21.0f), 0.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_waycrest_manor_organ_missiles::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 267595 - Waycrest Manor - Waycrests Defeated (Horde)
// 267597 - Waycrest Manor - Waycrests Defeated (Alliance)
// 7351 - Conversation
// 7352 - Conversation
class conversation_waycrest_manor_waycrests_defeated : public ConversationScript
{
public:
    conversation_waycrest_manor_waycrests_defeated() : ConversationScript("conversation_waycrest_manor_waycrests_defeated") { }

    void OnConversationStart(Conversation* conversation) override
    {
        if (Milliseconds const* gorakTulMoveStartTimeAlliance = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVERSATION_LINE_LUCILLE_WAYCREST))
            _events.ScheduleEvent(EVENT_GORAK_TUL_TRANSFORM, *gorakTulMoveStartTimeAlliance);
        else if (Milliseconds const* gorakTulMoveStartTimeHorde = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVERSATION_LINE_GORAK_TUL_HORDE))
            _events.ScheduleEvent(EVENT_GORAK_TUL_TRANSFORM, *gorakTulMoveStartTimeHorde + 3s);
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_GORAK_TUL_TRANSFORM:
            {
                Creature* gorakTul = conversation->GetActorCreature(CONVO_ACTOR_IDX_GORAK_TUL);
                if (!gorakTul)
                    break;

                gorakTul->CastSpell(gorakTul, SPELL_COSMETIC_MISSILE_TRANSFORM);
                _events.ScheduleEvent(EVENT_GORAK_TUL_MOVE, 1s);
                break;
            }
            case EVENT_GORAK_TUL_MOVE:
            {
                Creature* gorakTul = conversation->GetActorCreature(CONVO_ACTOR_IDX_GORAK_TUL);
                if (!gorakTul)
                    break;

                // To-Do: This is wrong, this path has HasSplineFilter which is NYI
                /*
                ServerToClient: SMSG_ON_MONSTER_MOVE (0x2DD4) Length: 191 ConnIdx: 1 Time: 07/19/2024 09:17:19.888 Number: 8254
                MoverGUID: Full: 0x204128E8C084F840001FF700001A1123 Creature/0 R4170/S8183 Map: 1862 (Waycrest Manor) Entry: 136161 (Gorak Tul) Low: 1708323
                Position: X: -524.88715 Y: -260.56772 Z: 182.55463
                (MovementMonsterSpline) (MovementSpline) Flags: 2438990336 (Flying, Catmullrom, CanSwim, UncompressedPath, Unknown5, Steering, Unknown10)
                (MovementMonsterSpline) (MovementSpline) HasSplineFilter: True
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) MonsterSplineFilterKey: 2
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) BaseSpeed: 5
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) StartOffset: 0
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) DistToPrevFilterKey: 0
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) AddedToStart: 1
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [0] IDx: 0
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [0] Speed: 500
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [1] IDx: 1
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [1] Speed: 1500
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) FilterFlags: 2
                (MovementMonsterSpline) (MovementSpline) [0] Points: X: -525.816 Y: -261.41666 Z: 188.96046
                (MovementMonsterSpline) (MovementSpline) [1] Points: X: -532.49304 Y: -279.55383 Z: 186.57698
                (MovementMonsterSpline) (MovementSpline) [2] Points: X: -526.13367 Y: -292.1389 Z: 185.22873
                (MovementMonsterSpline) (MovementSpline) [3] Points: X: -501.00696 Y: -316.64932 Z: 171.55269
                (MovementMonsterSpline) (MovementSpline) [4] Points: X: -488.12326 Y: -329.7795 Z: 161.65425
                (MovementMonsterSpline) (MovementSpline) [5] Points: X: -470.80383 Y: -326.80557 Z: 159.51692
                (MovementMonsterSpline) (MovementSpline) [6] Points: X: -460.06772 Y: -335.67188 Z: 158.33897
                (MovementMonsterSpline) (MovementSpline) [7] Points: X: -446.75 Y: -343.94272 Z: 155.77182
                (MovementMonsterSpline) (MovementSpline) [8] Points: X: -441.15625 Y: -344.0955 Z: 157.48708
                (MovementMonsterSpline) (MovementSpline) CalculatedSpeedXY: 46.351273
                */

                gorakTul->GetMotionMaster()->MovePath(PATH_GORAK_TUL, false);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_waycrest_manor()
{
    RegisterAreaTriggerAI(at_waycrest_manor_organ_missiles);
    RegisterSpellScript(spell_waycrest_manor_organ_missiles);

    new conversation_waycrest_manor_waycrests_defeated();
}
