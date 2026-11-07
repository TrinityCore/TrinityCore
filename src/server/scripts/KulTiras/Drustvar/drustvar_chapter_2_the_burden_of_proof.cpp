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
#include "Locales.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
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

enum TheBurdenOfProofData
{
    QUEST_THE_BURDEN_OF_PROOF       = 48198,

    NPC_CONSTABLE_HENRY_FRAMER      = 125394,
    NPC_LUCILLE_WAYCREST            = 128529,

    CONVO_ACTOR_CONSTABLE           = 59853,
    CONVO_ACTOR_LUCILLE             = 60052,

    CONVO_LINE_WITCH_TEST_INTRO     = 12722,
    CONVO_LINE_FIRST_TEST_GIVEN     = 12739,
    CONVO_LINE_SECOND_TEST_GIVEN    = 12743,
    CONVO_LINE_THIRD_TEST_GIVEN     = 12752,

    CREDIT_TALK_TO_CONSTABLE        = 125394,
    CREDIT_FIRST_TEST_GIVEN         = 125509,
    CREDIT_SECOND_TEST_GIVEN        = 125510,
    CREDIT_THIRD_TEST_GIVEN         = 125511,

    OBJECTIVE_TALK_TO_CONSTABLE     = 291661,
    OBJECITVE_FIRST_TEST_GIVEN      = 291664,
    OBJECTIVE_SECOND_TEST_GIVEN     = 291665,
    OBJECTIVE_THIRD_TEST_GIVEN      = 291971,

    SPELL_CUT_ONIONS                = 250130,
    SPELL_CUT_ONIONS_FORCE_CAST     = 248808,
    SPELL_EVENT_ONIONS_CUT          = 250231,
    SPELL_EVENT_LUCILLE_CRYING      = 248944,
    SPELL_RELEASE_BLOODFLIES        = 250131,
    SPELL_EVENT_FLIES_RELEASED      = 250232,
    SPELL_LUCILLE_BITING_INSECTS    = 248961,
    SPELL_ADMINISTERING_VENOM       = 250132,
    SPELL_EVENT_TOXIN_GIVEN         = 250233,
    SPELL_LUCILLE_VOMIT             = 248934,

    PATH_CONSTABLE_START_TRIAL      = 12539400,
    PATH_CONSTABLE_FIRST_TEST       = 12539401,
    PATH_CONSTABLE_SECOND_TEST      = 12539402,
    PATH_CONSTABLE_THIRD_TEST       = 12539403,
};

// 5685 - Conversation
class conversation_burden_of_proof_speak_with_constable : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* constableObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_CONSTABLE_HENRY_FRAMER, .IgnorePhases = true });
        if (!constableObject)
            return;

        TempSummon* constableClone = constableObject->SummonPersonalClone(constableObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!constableClone)
            return;

        constableClone->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

        conversation->AddActor(CONVO_ACTOR_CONSTABLE, 0, constableClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            if (Creature* constableClone = conversation->GetActorCreature(0))
                constableClone->GetMotionMaster()->MovePath(PATH_CONSTABLE_START_TRIAL, false);

        }, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_WITCH_TEST_INTRO));

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            Creature* constableClone = conversation->GetActorCreature(0);
            if (!constableClone)
                return;

            player->KilledMonsterCredit(CREDIT_TALK_TO_CONSTABLE);
            constableClone->DespawnOrUnsummon();

        }, conversation->GetLastLineEndTime(privateOwnerLocale));
    }
};

// 250118 - Ping Lucille
class spell_drustvar_ping_lucille_burden_of_proof : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CUT_ONIONS, SPELL_RELEASE_BLOODFLIES, SPELL_ADMINISTERING_VENOM });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Player* player = Object::ToPlayer(GetCaster());
        if (!player)
            return;

        if (player->GetQuestObjectiveData(QUEST_THE_BURDEN_OF_PROOF, OBJECTIVE_TALK_TO_CONSTABLE) && !player->GetQuestObjectiveData(QUEST_THE_BURDEN_OF_PROOF, OBJECITVE_FIRST_TEST_GIVEN))
            player->CastSpell(player, SPELL_CUT_ONIONS, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        else if (player->GetQuestObjectiveData(QUEST_THE_BURDEN_OF_PROOF, OBJECITVE_FIRST_TEST_GIVEN) && !player->GetQuestObjectiveData(QUEST_THE_BURDEN_OF_PROOF, OBJECTIVE_SECOND_TEST_GIVEN))
            player->CastSpell(player, SPELL_RELEASE_BLOODFLIES, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        else if (player->GetQuestObjectiveData(QUEST_THE_BURDEN_OF_PROOF, OBJECTIVE_SECOND_TEST_GIVEN) && !player->GetQuestObjectiveData(QUEST_THE_BURDEN_OF_PROOF, OBJECTIVE_THIRD_TEST_GIVEN))
            player->CastSpell(player, SPELL_ADMINISTERING_VENOM, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_ping_lucille_burden_of_proof::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 248808 - Cut Onions
class spell_drustvar_cut_onions_burden_of_proof : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVENT_ONIONS_CUT });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_EVENT_ONIONS_CUT, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_cut_onions_burden_of_proof::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 5694 - Conversation
// 5695 - Conversation
// 5696 - Conversation
class conversation_burden_of_proof_base : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void SummonClones(Unit* creator)
    {
        if (Creature* constableObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_CONSTABLE_HENRY_FRAMER, .IgnorePhases = true }))
        {
            if (TempSummon* constableClone = constableObject->SummonPersonalClone(constableObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer()))
            {
                _constableCloneGUID = constableClone->GetGUID();
                constableClone->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            }
        }

        if (Creature* lucilleObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_LUCILLE_WAYCREST, .IgnorePhases = true }))
        {
            if (TempSummon* lucilleClone = lucilleObject->SummonPersonalClone(lucilleObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer()))
            {
                _lucilleCloneGUID = lucilleClone->GetGUID();
                lucilleClone->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }

    void ScheduleEvents(uint32 pathId, int32 lineId, uint32 creditEntry) const
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([this, pathId]()
        {
            if (Creature* constableClone = GetConstableClone())
                constableClone->GetMotionMaster()->MovePath(pathId, false);

        }, conversation->GetLineEndTime(privateOwnerLocale, lineId));

        conversation->m_Events.AddEvent([this, creditEntry, conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            player->KilledMonsterCredit(creditEntry);

            if (Creature* constableClone = GetConstableClone())
                constableClone->DespawnOrUnsummon();

            if (Creature* lucilleClone = GetLucilleClone())
                lucilleClone->DespawnOrUnsummon();

        }, conversation->GetLastLineEndTime(privateOwnerLocale));
    }

    Creature* GetConstableClone() const
    {
        return ObjectAccessor::GetCreature(*conversation, _constableCloneGUID);
    }

    Creature* GetLucilleClone() const
    {
        return ObjectAccessor::GetCreature(*conversation, _lucilleCloneGUID);
    }

protected:
    ObjectGuid _constableCloneGUID;
    ObjectGuid _lucilleCloneGUID;
};

// 5694 - Conversation
class conversation_burden_of_proof_first_test_given : public conversation_burden_of_proof_base
{
public:
    using conversation_burden_of_proof_base::conversation_burden_of_proof_base;

    void OnCreate(Unit* creator) override
    {
        SummonClones(creator);

        Creature* constableClone = GetConstableClone();
        if (!constableClone)
            return;

        Creature* lucilleClone = GetLucilleClone();
        if (!lucilleClone)
            return;

        lucilleClone->CastSpell(nullptr, SPELL_EVENT_LUCILLE_CRYING, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });

        conversation->AddActor(CONVO_ACTOR_CONSTABLE, 1, constableClone->GetGUID());
        conversation->AddActor(CONVO_ACTOR_LUCILLE, 2, lucilleClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        ScheduleEvents(PATH_CONSTABLE_FIRST_TEST, CONVO_LINE_FIRST_TEST_GIVEN, CREDIT_FIRST_TEST_GIVEN);
    }
};

// 249108 - Release Bloodflies
class spell_drustvar_release_bloodflies_burden_of_proof : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVENT_FLIES_RELEASED });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_EVENT_FLIES_RELEASED, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_release_bloodflies_burden_of_proof::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 5695 - Conversation
class conversation_burden_of_proof_second_test_given : public conversation_burden_of_proof_base
{
public:
    using conversation_burden_of_proof_base::conversation_burden_of_proof_base;

    void OnCreate(Unit* creator) override
    {
        SummonClones(creator);

        Creature* constableClone = GetConstableClone();
        if (!constableClone)
            return;

        Creature* lucilleClone = GetLucilleClone();
        if (!lucilleClone)
            return;

        lucilleClone->CastSpell(nullptr, SPELL_LUCILLE_BITING_INSECTS, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });

        conversation->AddActor(CONVO_ACTOR_CONSTABLE, 2, constableClone->GetGUID());
        conversation->AddActor(CONVO_ACTOR_LUCILLE, 0, lucilleClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        ScheduleEvents(PATH_CONSTABLE_SECOND_TEST, CONVO_LINE_SECOND_TEST_GIVEN, CREDIT_SECOND_TEST_GIVEN);
    }
};

// 249110 - Administering Venom
class spell_drustvar_administering_venom_burden_of_proof : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVENT_TOXIN_GIVEN });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_EVENT_TOXIN_GIVEN, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_administering_venom_burden_of_proof::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 5696 - Conversation
class conversation_burden_of_proof_third_test_given : public conversation_burden_of_proof_base
{
public:
    using conversation_burden_of_proof_base::conversation_burden_of_proof_base;

    void OnCreate(Unit* creator) override
    {
        SummonClones(creator);

        Creature* constableClone = GetConstableClone();
        if (!constableClone)
            return;

        Creature* lucilleClone = GetLucilleClone();
        if (!lucilleClone)
            return;

        lucilleClone->CastSpell(nullptr, SPELL_LUCILLE_VOMIT, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });

        conversation->AddActor(CONVO_ACTOR_CONSTABLE, 3, constableClone->GetGUID());
        conversation->AddActor(CONVO_ACTOR_LUCILLE, 0, lucilleClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        ScheduleEvents(PATH_CONSTABLE_THIRD_TEST, CONVO_LINE_THIRD_TEST_GIVEN, CREDIT_THIRD_TEST_GIVEN);
    }
};

void AddSC_drustvar_chapter_2_the_burden_of_proof()
{
    // Conversation
    RegisterConversationAI(conversation_guards_intro_standing_accused);
    RegisterConversationAI(conversation_burden_of_proof_speak_with_constable);
    RegisterConversationAI(conversation_burden_of_proof_first_test_given);
    RegisterConversationAI(conversation_burden_of_proof_second_test_given);
    RegisterConversationAI(conversation_burden_of_proof_third_test_given);

    // Spell
    RegisterSpellScript(spell_drustvar_ping_lucille_burden_of_proof);
    RegisterSpellScript(spell_drustvar_cut_onions_burden_of_proof);
    RegisterSpellScript(spell_drustvar_release_bloodflies_burden_of_proof);
    RegisterSpellScript(spell_drustvar_administering_venom_burden_of_proof);
}
