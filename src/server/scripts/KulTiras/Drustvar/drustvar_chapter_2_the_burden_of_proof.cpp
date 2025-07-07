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

#include "Conversation.h"
#include "ConversationAI.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum StandingAccusedData
{
    NPC_STANDING_ACCUESED_BELLA         = 127714,
    NPC_STANDING_ACCUSED_GUARD          = 125391,
    NPC_STANDING_ACCUSED_MARSHAL        = 125385,

    PATH_MARSHAL_EVERITE_READE_INTRO    = 12538500,
    PATH_BELLA_INTRO                    = 12771400,
    PATH_WAYCREST_GUARD_ONE_INTRO       = 12539103,
    PATH_WAYCREST_GUARD_TWO_INTRO       = 12539102,
    PATH_WAYCREST_GUARD_THREE_INTRO     = 12539100,
    PATH_WAYCREST_GUARD_FOUR_INTRO      = 12539101
};

// 5665 - Conversation
class conversation_guards_intro_standing_accused : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    static constexpr Position BellaIntroSpawnPos = { -390.261f, 1360.479f, 21.509799f, 5.260458f };
    static constexpr Position MarshalIntroSpawnPos = { -392.267f, 1356.739f, 22.34238f, 5.33823f };
    static constexpr Position GuardOneIntroSpawnPos = { -402.040f, 1362.930f, 23.69840f, 5.30345f };
    static constexpr Position GuardTwoIntroSpawnPos = { -398.108f, 1363.3499f, 22.9922f, 5.30345f };
    static constexpr Position GuardThreeIntroSpawnPos = { -390.244f, 1365.810f, 22.76930f, 5.30345f };
    static constexpr Position GuardFourIntroSpawnPos = { -386.5169f, 1368.359f, 22.89900f, 5.30345f };

    enum ConversationStandingAccusedIntroData
    {
        CONVO_ACTOR_MARSHAL_EVERIT_READE    = 61576
    };

    static TempSummon* SummonPersonalCloneFromClosestCreatureWithOptions(Unit* creator, FindCreatureOptions const& options, Position const& position)
    {
        if (Creature* creature = GetClosestCreatureWithOptions(creator, 50.0f, options))
            return creature->SummonPersonalClone(position, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        return nullptr;
    }

    void OnCreate(Unit* creator) override
    {
        if (TempSummon* marshalClone = SummonPersonalCloneFromClosestCreatureWithOptions(creator, { .CreatureId = NPC_STANDING_ACCUSED_MARSHAL, .IgnorePhases = true }, MarshalIntroSpawnPos))
        {
            marshalClone->GetMotionMaster()->MovePath(PATH_MARSHAL_EVERITE_READE_INTRO, false);

            conversation->AddActor(CONVO_ACTOR_MARSHAL_EVERIT_READE, 2, marshalClone->GetGUID());
            conversation->Start();
        }

        if (TempSummon* bellaClone = SummonPersonalCloneFromClosestCreatureWithOptions(creator, { .CreatureId = NPC_STANDING_ACCUESED_BELLA, .IgnorePhases = true }, BellaIntroSpawnPos))
            bellaClone->GetMotionMaster()->MovePath(PATH_BELLA_INTRO, false);

        if (TempSummon* guardClone = SummonPersonalCloneFromClosestCreatureWithOptions(creator, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardOne", .IgnorePhases = true }, GuardOneIntroSpawnPos))
            guardClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_ONE_INTRO, false);

        if (TempSummon* guardClone = SummonPersonalCloneFromClosestCreatureWithOptions(creator, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardTwo", .IgnorePhases = true }, GuardTwoIntroSpawnPos))
            guardClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_TWO_INTRO, false);

        if (TempSummon* guardClone = SummonPersonalCloneFromClosestCreatureWithOptions(creator, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardThree", .IgnorePhases = true }, GuardThreeIntroSpawnPos))
            guardClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_THREE_INTRO, false);

        if (TempSummon* guardClone = SummonPersonalCloneFromClosestCreatureWithOptions(creator, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardFour", .IgnorePhases = true }, GuardFourIntroSpawnPos))
            guardClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_FOUR_INTRO, false);

        PhasingHandler::OnConditionChange(creator);
    }

    void OnStart() override
    {
        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            if (Creature* marshalClone = conversation->GetActorCreature(2))
                marshalClone->DespawnOrUnsummon();

        }, conversation->GetLastLineEndTime(conversation->GetPrivateObjectOwnerLocale()));
    }
};

void AddSC_drustvar_chapter_2_the_burden_of_proof()
{
    // Conversation
    RegisterConversationAI(conversation_guards_intro_standing_accused);
}
