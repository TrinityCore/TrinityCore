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
#include "ScriptedCreature.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Group.h"
#include "Spell.h"
#include "SpellScript.h"

enum Points
{
    POINT_NONE                      = 0,
    POINT_ID_TORG_DRAKEFLAYER_INTRO = 1,
    POINT_ID_SULLY_KNEECAPPER_INTRO = 1,
};

enum TwilightHightlandsArena
{
    // Quests
    QUEST_ID_COC_THE_BLOODEYE_BRUISER   = 27863,
    QUEST_ID_COC_THE_DEADLY_DRAGONMAW   = 27864,
    QUEST_ID_COC_THE_WAYWARD_WILDHAMMER = 27865,

    // Events
    EVENT_SAY_REMEMBER = 1,
    EVENT_ANNOUNCE_BATTLE_1,
    EVENT_SUMMON_HURP_DERP,

    EVENT_ANNOUNCE_BATTLE_2_ALLIANCE,
    EVENT_SUMMON_TORG_DRAKEFLAYER,

    EVENT_ANNOUNCE_BATTLE_2_HORDE,
    EVENT_SUMMON_SULLY_KNEECAPPER,


    // Texts
    SAY_REMEMBER                    = 0,
    // Hurp'Derp
    SAY_INTRO_BATTLE_1              = 1,
    SAY_START_BATTLE_1              = 2,
    SAY_HURP_DERP_DEFEATED          = 3,
    // Torg Drakeflayer
    SAY_INTRO_BATTLE_2_ALLIANCE     = 4,
    SAY_TORG_DRAKEFLAYER_DEFEATED   = 5,
    // Sully Kneedcapper
    SAY_INTRO_BATTLE_2_HORDE        = 6,
    SAY_START_BATTLE_2_HORDE        = 7,
    SAY_SULLY_KNEECAPPER_DEFEATED   = 8,

    // Creatures
    NPC_HURP_DERP                   = 46944,
    NPC_TORG_DRAKEFLAYER            = 46945,
    NPC_SULLY_KNEECAPPER            = 46946
};

Position const HurpDerpSpawnPosition        = { -4133.8647f, -5192.587f,    -9.481462f, 2.447715520858764648f };
Position const HurpDerpMovePosition         = { -4182.394f,  -5148.4478f,   -7.7360706f };
Position const TorgDrakeflayerSpawnPosition = { -4136.02f,   -5137.94f,     40.58253f, 3.379617214202880859 };
Position const TorgDrakeflayerJumpPosition  = { -4168.87f,   -5145.91f,     -7.73344f };
Position const SullyKneecapperSpawnPosition = { -4235.0522f, -5133.8877f,   -4.938032f, 5.69227f };

// 46935 - Gurgthock
struct npc_th_gurgthock : public ScriptedAI
{
    npc_th_gurgthock(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (!_playerGUID.IsEmpty())
            return;

        _playerGUID = player->GetGUID();
        me->setActive(true);
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        _events.ScheduleEvent(EVENT_SAY_REMEMBER, 1ms);

        switch (quest->GetQuestId())
        {
            case QUEST_ID_COC_THE_BLOODEYE_BRUISER:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_1, 8s + 500ms);
                break;
            case QUEST_ID_COC_THE_DEADLY_DRAGONMAW:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_2_ALLIANCE, 8s + 500ms);
                break;
            case QUEST_ID_COC_THE_WAYWARD_WILDHAMMER:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_2_HORDE, 6s);
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        // Summon has been defeated. Enable Questgiver and complete quest for killer's group
        summon->DespawnOrUnsummon(3s);

        switch (summon->GetEntry())
        {
            case NPC_HURP_DERP:
                Talk(SAY_HURP_DERP_DEFEATED, killer);
                CompleteQuest(summon, QUEST_ID_COC_THE_BLOODEYE_BRUISER);
                break;
            case NPC_TORG_DRAKEFLAYER:
                Talk(SAY_TORG_DRAKEFLAYER_DEFEATED, killer);
                CompleteQuest(summon, QUEST_ID_COC_THE_DEADLY_DRAGONMAW);
                break;
            case NPC_SULLY_KNEECAPPER:
                Talk(SAY_SULLY_KNEECAPPER_DEFEATED, killer);
                CompleteQuest(summon, QUEST_ID_COC_THE_WAYWARD_WILDHAMMER);
                break;
            default:
                break;
        }

        me->setActive(false);
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        _playerGUID.Clear();
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        // Summon has entered evade mode. Fail quest and reset quest giver
        if (summon->IsAlive())
        {
            switch (summon->GetEntry())
            {
                case NPC_HURP_DERP:
                    FailQuest(summon, QUEST_ID_COC_THE_BLOODEYE_BRUISER);
                    break;
                case NPC_TORG_DRAKEFLAYER:
                    FailQuest(summon, QUEST_ID_COC_THE_DEADLY_DRAGONMAW);
                    break;
                case NPC_SULLY_KNEECAPPER:
                    FailQuest(summon, QUEST_ID_COC_THE_WAYWARD_WILDHAMMER);
                    break;
                default:
                    break;
            }

            me->setActive(false);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            _playerGUID.Clear();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SAY_REMEMBER:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_REMEMBER, player);
                    break;
                case EVENT_ANNOUNCE_BATTLE_1:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_1, player);
                    _events.ScheduleEvent(EVENT_SUMMON_HURP_DERP, 8s);
                    break;
                case EVENT_SUMMON_HURP_DERP:
                    Talk(SAY_START_BATTLE_1);
                    if (Creature* hurpDerp = DoSummon(NPC_HURP_DERP, HurpDerpSpawnPosition))
                    {
                        hurpDerp->SetHomePosition(HurpDerpMovePosition);
                        hurpDerp->GetMotionMaster()->MovePoint(POINT_NONE, HurpDerpMovePosition);
                    }
                    break;
                case EVENT_ANNOUNCE_BATTLE_2_ALLIANCE:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_2_ALLIANCE, player);
                    _events.ScheduleEvent(EVENT_SUMMON_TORG_DRAKEFLAYER, 6s);
                    break;
                case EVENT_SUMMON_TORG_DRAKEFLAYER:
                    if (Creature* torg = DoSummon(NPC_TORG_DRAKEFLAYER, TorgDrakeflayerSpawnPosition))
                    {
                        torg->SetHomePosition(TorgDrakeflayerJumpPosition);
                        torg->GetMotionMaster()->MoveJump(TorgDrakeflayerJumpPosition, 11.5f, 16.f, POINT_ID_TORG_DRAKEFLAYER_INTRO);
                    }
                    break;
                case EVENT_ANNOUNCE_BATTLE_2_HORDE:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_2_HORDE, player);
                    _events.ScheduleEvent(EVENT_SUMMON_SULLY_KNEECAPPER, 6s);
                    break;
                case EVENT_SUMMON_SULLY_KNEECAPPER:
                    Talk(SAY_START_BATTLE_2_HORDE);
                    DoSummon(NPC_SULLY_KNEECAPPER, SullyKneecapperSpawnPosition);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;

    void CompleteQuest(Creature const* defeatedBoss, uint32 questId)
    {
        Unit* unit = ObjectAccessor::GetUnit(*me, _playerGUID);
        if (!unit || !unit->IsPlayer())
            return;

        Player* player = unit->ToPlayer();
        player->GroupEventHappens(questId, defeatedBoss);
    }

    void FailQuest(Creature* const boss, uint32 questId)
    {
        Unit* unit = ObjectAccessor::GetUnit(*me, _playerGUID);
        if (!unit || !unit->IsPlayer())
            return;

        Player* player = unit->ToPlayer();

        if (Group* group = player->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* member = itr->GetSource();
                if (member && member->IsAtGroupRewardDistance(boss) && !player->GetCorpse())
                    member->FailQuest(questId);
            }
        }
        else
            player->FailQuest(questId);
    }
};

// 94999 - Grab Targetting
class spell_th_grab_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject const* target)
        {
            Unit const* unit = target->ToUnit();
            return (!unit || !unit->IsInCombatWith(GetCaster()));
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_th_grab_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_th_grab_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

std::array<Position, 2> ChargeDestinations =
{
    Position(-4204.6f, -5180.2f, -8.61639f),
    Position(-4194.45f, -5104.34f, -7.22446f)
};

// 88540 - Charge
class spell_th_charge : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        // While the target type indicates a nearby entry target, there is no sniffable unit target at given coordinates.
        dest.Relocate(Trinity::Containers::SelectRandomContainerElement(ChargeDestinations));
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_th_charge::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

void AddSC_twilight_highlands()
{
    RegisterCreatureAI(npc_th_gurgthock);
    RegisterSpellScript(spell_th_grab_targeting);
    RegisterSpellScript(spell_th_charge);
}
