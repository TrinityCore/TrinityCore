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
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
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

constexpr Position BellaIntroSpawnPos = { -390.261f, 1360.479f, 21.509799f, 5.260458f };
constexpr Position MarshalIntroSpawnPos = { -392.267f, 1356.739f, 22.34238f, 5.33823f };
constexpr Position GuardOneIntroSpawnPos = { -402.040f, 1362.930f, 23.69840f, 5.30345f };
constexpr Position GuardTwoIntroSpawnPos = { -398.108f, 1363.3499f, 22.9922f, 5.30345f };
constexpr Position GuardThreeIntroSpawnPos = { -390.244f, 1365.810f, 22.76930f, 5.30345f };
constexpr Position GuardFourIntroSpawnPos = { -386.5169f, 1368.359f, 22.89900f, 5.30345f };

// 5665 - Conversation
class conversation_guards_intro_standing_accused : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    enum ConversationStandingAccusedIntroData
    {
        CONVO_ACTOR_MARSHAL_EVERIT_READE    = 61576
    };

    void OnCreate(Unit* creator) override
    {
        Creature* marshalObject = GetClosestCreatureWithOptions(creator, 50.0f, { .CreatureId = NPC_STANDING_ACCUSED_MARSHAL, .IgnorePhases = true });
        Creature* bellaObject = GetClosestCreatureWithOptions(creator, 50.0f, { .CreatureId = NPC_STANDING_ACCUESED_BELLA, .IgnorePhases = true });
        Creature* guardOneObject = GetClosestCreatureWithOptions(creator, 50.0f, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardOne", .IgnorePhases = true });
        Creature* guardTwoObject = GetClosestCreatureWithOptions(creator, 50.0f, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardTwo", .IgnorePhases = true });
        Creature* guardThreeObject = GetClosestCreatureWithOptions(creator, 50.0f, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardThree", .IgnorePhases = true });
        Creature* guardFourObject = GetClosestCreatureWithOptions(creator, 50.0f, { .CreatureId = NPC_STANDING_ACCUSED_GUARD, .StringId = "GuardFour", .IgnorePhases = true });
        if (!marshalObject || !bellaObject || !guardOneObject || !guardTwoObject || !guardThreeObject || !guardFourObject)
            return;

        TempSummon* marshalClone = marshalObject->SummonPersonalClone(MarshalIntroSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* bellaClone = bellaObject->SummonPersonalClone(BellaIntroSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* guardOneClone = guardOneObject->SummonPersonalClone(GuardOneIntroSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* guardTwoClone = guardTwoObject->SummonPersonalClone(GuardTwoIntroSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* guardThreeClone = guardThreeObject->SummonPersonalClone(GuardThreeIntroSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* guardFourClone = guardFourObject->SummonPersonalClone(GuardFourIntroSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!marshalClone || !bellaClone || !guardOneClone || !guardTwoClone || !guardThreeObject || !guardFourObject)
            return;

        marshalClone->GetMotionMaster()->MovePath(PATH_MARSHAL_EVERITE_READE_INTRO, false);
        bellaClone->GetMotionMaster()->MovePath(PATH_BELLA_INTRO, false);
        guardOneClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_ONE_INTRO, false);
        guardTwoClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_TWO_INTRO, false);
        guardThreeClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_THREE_INTRO, false);
        guardFourClone->GetMotionMaster()->MovePath(PATH_WAYCREST_GUARD_FOUR_INTRO, false);

        PhasingHandler::OnConditionChange(creator);

        conversation->AddActor(CONVO_ACTOR_MARSHAL_EVERIT_READE, 2, marshalClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Creature* marshalClone = conversation->GetActorCreature(2);
            if (!marshalClone)
                return;

            marshalClone->DespawnOrUnsummon();
        }, conversation->GetLastLineEndTime(privateOwnerLocale));
    }
};

void AddSC_drustvar_chapter_2_the_burden_of_proof()
{
    // Conversation
    RegisterConversationAI(conversation_guards_intro_standing_accused);
}
