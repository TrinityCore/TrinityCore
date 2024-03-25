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
#include "CellImpl.h"
#include "Containers.h"
#include "Conversation.h"
#include "CreatureAIImpl.h"
#include "EventProcessor.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum MardumSpellData
{
    SPELL_START_DEMON_HUNTER_PLAY_SCENE = 193525
};

enum MardumQuestData
{
    QUEST_DEMON_HUNTER_INTRO_TRACKER    = 40076
};

enum MardumConversationData
{
    CONVO_DEMONHUNTER_INTRO_START       = 705
};

enum MardumSoundData
{
    SOUND_METAL_WEAPON_UNSHEATH = 700,
    SOUND_SPELL_DOUBLE_JUMP     = 53780,
};

class scene_demonhunter_intro : public SceneScript
{
public:
    scene_demonhunter_intro() : SceneScript("scene_demonhunter_intro") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        Conversation::CreateConversation(CONVO_DEMONHUNTER_INTRO_START, player, *player, player->GetGUID(), nullptr);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        PhasingHandler::OnConditionChange(player);
    }
};

// 196030 - Start: Quest Invis
class spell_demon_hunter_intro_aura : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_START_DEMON_HUNTER_PLAY_SCENE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_demon_hunter_intro_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum TheInvasionBeginsQuestData
{
    QUEST_THE_INVASION_BEGINS                   = 40077,

    CONVO_THE_INVASION_BEGINS                   = 922,

    NPC_KAYN_SUNFURY_INVASION_BEGINS            = 93011,
    NPC_JAYCE_DARKWEAVER_INVASION_BEGINS        = 98228,
    NPC_ALLARI_THE_SOULEATER_INVASION_BEGINS    = 98227,
    NPC_CYANA_NIGHTGLAIVE_INVASION_BEGINS       = 98290,
    NPC_KORVAS_BLOODTHORN_INVASION_BEGINS       = 98292,
    NPC_SEVIS_BRIGHTFLAME_INVASION_BEGINS       = 99918,
    NPC_WRATH_WARRIOR_INVASION_BEGINS           = 94580,

    SPELL_THE_INVASION_BEGINS                   = 187382,
    SPELL_TRACK_TARGET_IN_CHANNEL               = 175799,
    SPELL_DEMON_HUNTER_GLIDE_STATE              = 199303
};

enum TheInvasionsBeginsWaypointData
{
    // Kayn
    PATH_KAYN_ATTACK_DEMON                      = 9301100,
    PATH_KAYN_AFTER_DEMON                       = 9301101,

    // Path before Jump
    PATH_JAYCE_INVASION_BEGINS                  = 9822800,
    PATH_ALLARI_INVASION_BEGINS                 = 9822700,
    PATH_CYANA_INVASION_BEGINS                  = 9829000,
    PATH_KORVAS_INVASION_BEGINS                 = 9829200,
    PATH_SEVIS_INVASION_BEGINS                  = 9991800,

    // Path after Jump
    PATH_JAYCE_JUMP_INVASION_BEGINS             = 9822801,
    PATH_ALLARI_JUMP_INVASION_BEGINS            = 9822701,
    PATH_CYANA_JUMP_INVASION_BEGINS             = 9829001,
    PATH_KORVAS_JUMP_INVASION_BEGINS            = 9829201,
    PATH_SEVIS_JUMP_INVASION_BEGINS             = 9991801,

    POINT_ILLIDARI_LAND_POS                     = 1,
    POINT_KAYN_TRIGGER_DOUBLE_JUMP              = 2,
    POINT_KAYN_MOVE_TO_DEMON                    = 3,
};

enum TheInvasionBeginsAnimKitsData
{
    ANIM_DH_WINGS                               = 58110,
    ANIM_DH_RUN                                 = 9767,
    ANIM_DH_RUN_ALLARI                          = 9180,
};

enum TheInvasionBeginsVisualData
{
    SPELL_VISUAL_KIT_KAYN_GLIDE                 = 59738,
    SPELL_VISUAL_KIT_KAYN_WINGS                 = 59406,
    SPELL_VISUAL_KIT_KAYN_DOUBLE_JUMP           = 58110,
    SPELL_VISUAL_KIT_KORVAS_JUMP                = 63071,
    SPELL_VISUAL_KIT_WRATH_WARRIOR_DIE          = 58476,
};

Position const WrathWarriorSpawnPosition        = { 1081.9166f, 3183.8716f, 26.335993f };
Position const KaynJumpPos                      = { 1172.17f, 3202.55f, 54.3479f };
Position const KaynDoubleJumpPosition           = { 1094.2384f, 3186.058f, 28.81562f };
Position const JayceJumpPos                     = { 1119.24f, 3203.42f, 38.1061f };
Position const AllariJumpPos                    = { 1120.08f, 3197.2f, 36.8502f };
Position const KorvasJumpPos                    = { 1117.89f, 3196.24f, 36.2158f };
Position const SevisJumpPos                     = { 1120.74f, 3199.47f, 37.5157f };
Position const CyanaJumpPos                     = { 1120.34f, 3194.28f, 36.4321f };

// 93011 - Kayn Sunfury
struct npc_kayn_sunfury_invasion_begins : public ScriptedAI
{
    npc_kayn_sunfury_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_INVASION_BEGINS)
        {
            PhasingHandler::OnConditionChange(player);
            player->CastSpell(WrathWarriorSpawnPosition, SPELL_THE_INVASION_BEGINS, false);
            Conversation::CreateConversation(CONVO_THE_INVASION_BEGINS, player, *player, player->GetGUID(), nullptr, false);
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_KAYN_ATTACK_DEMON)
        {
            Creature* wrathWarrior = me->FindNearestCreatureWithOptions(100.0f, { .CreatureId = NPC_WRATH_WARRIOR_INVASION_BEGINS, .IgnorePhases = true, .OwnerGuid = me->GetOwnerGUID() });
            if (!wrathWarrior)
                return;

            me->SetFacingToObject(wrathWarrior);

            wrathWarrior->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_WRATH_WARRIOR_DIE, 0, 0);
            wrathWarrior->KillSelf();

            _scheduler.Schedule(600ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath(PATH_KAYN_AFTER_DEMON, false);
            });
        }
        else if (pathId == PATH_KAYN_AFTER_DEMON)
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_KAYN_TRIGGER_DOUBLE_JUMP)
        {
            TempSummon* summon = me->ToTempSummon();
            if (!summon)
                return;
            WorldObject* summoner = summon->GetSummoner();
            if (!summoner)
                return;
            Player* summonerPlayer = summoner->ToPlayer();
            if (!summonerPlayer)
                return;

            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_KAYN_WINGS, 4, 3000);
            me->PlayObjectSound(SOUND_SPELL_DOUBLE_JUMP, me->GetGUID(), summonerPlayer);
            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_KAYN_DOUBLE_JUMP, 0, 0);
            me->GetMotionMaster()->MoveJumpWithGravity(KaynDoubleJumpPosition, 24.0, 0.9874f, POINT_KAYN_MOVE_TO_DEMON);
        }
        else if (pointId == POINT_KAYN_MOVE_TO_DEMON)
        {
            me->SetAIAnimKitId(ANIM_DH_RUN);
            me->GetMotionMaster()->MovePath(PATH_KAYN_ATTACK_DEMON, false, {}, 4.0f);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 98228 - Jayce Darkweaver
struct npc_jayce_darkweaver_invasion_begins : public ScriptedAI
{
    npc_jayce_darkweaver_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_JAYCE_INVASION_BEGINS)
        {
            me->CastSpell(nullptr, SPELL_DEMON_HUNTER_GLIDE_STATE, true);
            me->GetMotionMaster()->MoveJumpWithGravity(JayceJumpPos, 12.0f, 15.2792f, POINT_ILLIDARI_LAND_POS);
        }
        else if (pathId == PATH_JAYCE_JUMP_INVASION_BEGINS)
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_ILLIDARI_LAND_POS)
        {
            me->RemoveAurasDueToSpell(SPELL_DEMON_HUNTER_GLIDE_STATE);
            me->GetMotionMaster()->MovePath(PATH_JAYCE_JUMP_INVASION_BEGINS, false);
        }
    }
};

// 98227 - Allari the Souleater
struct npc_allari_the_souleater_invasion_begins : public ScriptedAI
{
    npc_allari_the_souleater_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_ALLARI_INVASION_BEGINS)
        {
            me->CastSpell(nullptr, SPELL_DEMON_HUNTER_GLIDE_STATE, true);
            me->GetMotionMaster()->MoveJumpWithGravity(AllariJumpPos, 12.0f, 9.2722f, POINT_ILLIDARI_LAND_POS);
        }
        else if (pathId == PATH_ALLARI_JUMP_INVASION_BEGINS)
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_ILLIDARI_LAND_POS)
        {
            me->RemoveAurasDueToSpell(SPELL_DEMON_HUNTER_GLIDE_STATE);
            me->GetMotionMaster()->MovePath(PATH_ALLARI_JUMP_INVASION_BEGINS, false);
        }
    }
};

// 98292 - Korvas Bloodthorn
struct npc_korvas_bloodthorn_invasion_begins : public ScriptedAI
{
    npc_korvas_bloodthorn_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_KORVAS_INVASION_BEGINS)
        {
            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_KORVAS_JUMP, 4, 2000);
            me->GetMotionMaster()->MoveJumpWithGravity(KorvasJumpPos, 24.0f, 19.2911f, POINT_ILLIDARI_LAND_POS);
        }
        else if (pathId == PATH_KORVAS_JUMP_INVASION_BEGINS)
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_ILLIDARI_LAND_POS)
        {
            me->RemoveAurasDueToSpell(SPELL_DEMON_HUNTER_GLIDE_STATE);
            me->GetMotionMaster()->MovePath(PATH_KORVAS_JUMP_INVASION_BEGINS, false);
        }
    }
};

// 99918 - Sevis Brightflame
struct npc_sevis_brightflame_invasion_begins : public ScriptedAI
{
    npc_sevis_brightflame_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_SEVIS_INVASION_BEGINS)
        {
            me->CastSpell(nullptr, SPELL_DEMON_HUNTER_GLIDE_STATE, true);
            me->GetMotionMaster()->MoveJumpWithGravity(SevisJumpPos, 12.0f, 13.3033f, POINT_ILLIDARI_LAND_POS);
        }
        else if (pathId == PATH_SEVIS_JUMP_INVASION_BEGINS)
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_ILLIDARI_LAND_POS)
        {
            me->RemoveAurasDueToSpell(SPELL_DEMON_HUNTER_GLIDE_STATE);
            me->GetMotionMaster()->MovePath(PATH_SEVIS_JUMP_INVASION_BEGINS, false);
        }
    }
};

// 98290 - Cyana Nightglaive
struct npc_cyana_nightglaive_invasion_begins : public ScriptedAI
{
    npc_cyana_nightglaive_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_CYANA_INVASION_BEGINS)
        {
            me->CastSpell(nullptr, SPELL_DEMON_HUNTER_GLIDE_STATE, true);
            me->GetMotionMaster()->MoveJumpWithGravity(CyanaJumpPos, 12.0f, 8.4555f, POINT_ILLIDARI_LAND_POS);
        }
        else if (pathId == PATH_CYANA_JUMP_INVASION_BEGINS)
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (pointId == POINT_ILLIDARI_LAND_POS)
        {
            me->RemoveAurasDueToSpell(SPELL_DEMON_HUNTER_GLIDE_STATE);
            me->GetMotionMaster()->MovePath(PATH_CYANA_JUMP_INVASION_BEGINS, false);
        }
    }
};

// 922 - The Invasion Begins
class conversation_the_invasion_begins : public ConversationScript
{
public:
    conversation_the_invasion_begins() : ConversationScript("conversation_the_invasion_begins") { }

    enum TheInvasionBeginsConversationData
    {
        CONVO_LINE_TRIGGER_FACING       = 2529,
        CONVO_LINE_START_PATH           = 2288,

        CONVO_ACTOR_IDX_KAYN            = 1,
        CONVO_ACTOR_IDX_KORVAS          = 2,
    };

    enum TheInvasionBeginsEventData
    {
        EVENT_ILLIDARI_FACE_PLAYERS     = 1,
        EVENT_ILLIDARI_START_PATH
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kaynObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_KAYN_SUNFURY_INVASION_BEGINS, .IgnorePhases = true });
        Creature* jayceObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_JAYCE_DARKWEAVER_INVASION_BEGINS, .IgnorePhases = true });
        Creature* allariaObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_ALLARI_THE_SOULEATER_INVASION_BEGINS, .IgnorePhases = true });
        Creature* cyanaObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_CYANA_NIGHTGLAIVE_INVASION_BEGINS, .IgnorePhases = true });
        Creature* korvasObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_KORVAS_BLOODTHORN_INVASION_BEGINS, .IgnorePhases = true });
        Creature* sevisObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_SEVIS_BRIGHTFLAME_INVASION_BEGINS, .IgnorePhases = true });
        if (!kaynObject || !jayceObject || !allariaObject || !cyanaObject || !korvasObject || !sevisObject)
            return;

        TempSummon* kaynClone = kaynObject->SummonPersonalClone(kaynObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* jayceClone = jayceObject->SummonPersonalClone(jayceObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* allariaClone = allariaObject->SummonPersonalClone(allariaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* cyanaClone = cyanaObject->SummonPersonalClone(cyanaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* korvasClone = korvasObject->SummonPersonalClone(korvasObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* sevisClone = sevisObject->SummonPersonalClone(sevisObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!kaynClone || !jayceClone || !allariaClone || !cyanaClone || !korvasClone || !sevisClone)
            return;

        _jayceGUID = jayceClone->GetGUID();
        _allariGUID = allariaClone->GetGUID();
        _cyanaGUID = cyanaClone->GetGUID();
        _sevisGUID = sevisClone->GetGUID();
        allariaClone->SetAIAnimKitId(ANIM_DH_RUN_ALLARI);
        kaynClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

        conversation->AddActor(CONVO_THE_INVASION_BEGINS, CONVO_ACTOR_IDX_KAYN, kaynClone->GetGUID());
        conversation->AddActor(CONVO_THE_INVASION_BEGINS, CONVO_ACTOR_IDX_KORVAS, korvasClone->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        if (Milliseconds const* illidariFacingLineStarted = conversation->GetLineStartTime(privateOwnerLocale, CONVO_LINE_TRIGGER_FACING))
            _events.ScheduleEvent(EVENT_ILLIDARI_FACE_PLAYERS, *illidariFacingLineStarted);

        if (Milliseconds const* illidariStartPathLineStarted = conversation->GetLineStartTime(privateOwnerLocale, CONVO_LINE_START_PATH))
            _events.ScheduleEvent(EVENT_ILLIDARI_START_PATH, *illidariStartPathLineStarted);
    }

    static void StartCloneChannel(ObjectGuid guid, Conversation* conversation)
    {
        Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
        if (!privateObjectOwner)
            return;

        Creature* clone = ObjectAccessor::GetCreature(*conversation, guid);
        if (!clone)
            return;

        clone->CastSpell(privateObjectOwner, SPELL_TRACK_TARGET_IN_CHANNEL, false);
    }

    static void StartCloneMovement(ObjectGuid cloneGUID, uint32 pathId, uint32 animKit, Conversation* conversation)
    {
        Creature* clone = ObjectAccessor::GetCreature(*conversation, cloneGUID);
        if (!clone)
            return;

        clone->InterruptNonMeleeSpells(true);
        clone->GetMotionMaster()->MovePath(pathId, false);
        if (animKit)
            clone->SetAIAnimKitId(animKit);
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_ILLIDARI_FACE_PLAYERS:
            {
                StartCloneChannel(conversation->GetActorUnit(CONVO_ACTOR_IDX_KAYN)->GetGUID(), conversation);
                StartCloneChannel(conversation->GetActorUnit(CONVO_ACTOR_IDX_KORVAS)->GetGUID(), conversation);
                StartCloneChannel(_jayceGUID, conversation);
                StartCloneChannel(_allariGUID, conversation);
                StartCloneChannel(_cyanaGUID, conversation);
                StartCloneChannel(_sevisGUID, conversation);
                break;
            }
            case EVENT_ILLIDARI_START_PATH:
            {
                Creature* kaynClone = conversation->GetActorCreature(CONVO_ACTOR_IDX_KAYN);
                if (!kaynClone)
                    break;

                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    return;

                Player* player = privateObjectOwner->ToPlayer();
                if (!player)
                    return;

                kaynClone->PlayObjectSound(SOUND_METAL_WEAPON_UNSHEATH, kaynClone->GetGUID(), player);
                kaynClone->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_KAYN_GLIDE, 4, 3000);
                kaynClone->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_KAYN_WINGS, 4, 4000);
                kaynClone->GetMotionMaster()->MoveJumpWithGravity(KaynJumpPos, 20.5f, 396.3535f, POINT_KAYN_TRIGGER_DOUBLE_JUMP);
                kaynClone->SetSheath(SHEATH_STATE_MELEE);
                kaynClone->SetNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);

                StartCloneMovement(conversation->GetActorUnit(CONVO_ACTOR_IDX_KORVAS)->GetGUID(), PATH_KORVAS_INVASION_BEGINS, ANIM_DH_RUN, conversation);
                StartCloneMovement(_jayceGUID, PATH_JAYCE_INVASION_BEGINS, 0, conversation);
                StartCloneMovement(_allariGUID, PATH_ALLARI_INVASION_BEGINS, ANIM_DH_RUN_ALLARI, conversation);
                StartCloneMovement(_cyanaGUID, PATH_CYANA_INVASION_BEGINS, 0, conversation);
                StartCloneMovement(_sevisGUID, PATH_SEVIS_INVASION_BEGINS, ANIM_DH_RUN, conversation);
                break;
            }
            default:
                break;
        }
    }

private:
    ObjectGuid _jayceGUID;
    ObjectGuid _allariGUID;
    ObjectGuid _cyanaGUID;
    ObjectGuid _sevisGUID;
    EventMap _events;
};

// 98459 - Kayn Sunfury
// 98458 - Jayce Darkweaver
// 98456 - Allari the Souleater
// 98460 - Korvas Bloodthorn
// 99919 - Sevis Brightflame
// 98457 - Cyana Nightglaive
struct npc_illidari_fighting_invasion_begins : public ScriptedAI
{
    npc_illidari_fighting_invasion_begins(Creature* creature) : ScriptedAI(creature) { }

    enum IllidariFightingSpells
    {
        SPELL_ILLIDARI_CHAOS_STRIKE = 197639,
        SPELL_ILLIDARI_FEL_RUSH = 200879,
    };

    enum IllidariFightingEvents
    {
        EVENT_CHAOS_STRIKE = 1,
        EVENT_FEL_RUSH
    };

    Unit* GetNextTarget()
    {
        std::list<Unit*> targetList;
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck checker(me, me, 100.0f);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targetList, checker);
        Cell::VisitAllObjects(me, searcher, 100.0f);
        targetList.remove_if([](Unit* possibleTarget)
        {
            return possibleTarget->isAttackingPlayer();
        });
        return Trinity::Containers::SelectRandomContainerElement(targetList);
    }

    void ScheduleTargetSelection()
    {
        _oocScheduler.Schedule(200ms, [this](TaskContext context)
        {
            Unit* target = GetNextTarget();
            if (!target)
            {
                context.Repeat(500ms);
                return;
            }
            AttackStart(target);
        });
    }

    void JustAppeared() override
    {
        ScheduleTargetSelection();
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CHAOS_STRIKE, 5s);
        _events.ScheduleEvent(EVENT_FEL_RUSH, 7s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        // manualling calling it to not move to home position but move to next target instead
        _EnterEvadeMode(why);
        Reset();
        ScheduleTargetSelection();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            _oocScheduler.Update(diff);
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (_events.ExecuteEvent())
        {
            case EVENT_CHAOS_STRIKE:
                DoCastVictim(SPELL_ILLIDARI_CHAOS_STRIKE);
                _events.ScheduleEvent(EVENT_CHAOS_STRIKE, 5s);
                break;
            case EVENT_FEL_RUSH:
                DoCastVictim(SPELL_ILLIDARI_FEL_RUSH);
                _events.ScheduleEvent(SPELL_ILLIDARI_FEL_RUSH, 7s);
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
    TaskScheduler _oocScheduler;
};

enum ETIAshtongueIntroData
{
    QUEST_ENTER_THE_ILLIDARI_ASHTONGUE      = 40378,

    NPC_KAYN_SUNFURY_ASHTONGUE              = 98229,
    NPC_KORVAS_BLOODTHORN_ASHTONGUE         = 98354,
    NPC_SEVIS_BRIGHTFLAME_ASHTONGUE         = 99916,
    NPC_ALLARI_SOULEATER_ASHTONGUE          = 94410,

    DISPLAY_ID_SEVIS_MOUNT                  = 64385,

    SAY_KAYN_ACTIVATE_GATEWAY               = 0,
    SAY_KAYN_CUT_A_HOLE                     = 1,
    SAY_KORVAS_SLAY_MORE_DEMONS             = 0,
    SAY_SEVIS_SAY_FIND_ALLARI               = 1,

    SPELL_VISUAL_KIT_SEVIS_MOUNT            = 36264,

    SPELL_CAST_MOUNT_DH_FELSABER            = 200175,
    SPELL_ASHTONGUE_FELLSABER_KILL_CREDIT   = 200254,

    PATH_KAYN_SUNFURY_NEAR_TELEPORT         = 9822900,
    PATH_KORVAS_BLOODTHORN_NEAR_TELEPORT    = 9835400,
    PATH_SEVIS_BRIGHTFLAME_GATEWAY          = 9991600,
};

// 98229 - Kayn Sunfury
struct npc_kayn_sunfury_ashtongue_intro : public ScriptedAI
{
    npc_kayn_sunfury_ashtongue_intro(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ENTER_THE_ILLIDARI_ASHTONGUE)
        {
            PhasingHandler::OnConditionChange(player);
            Creature* kaynObject = GetClosestCreatureWithOptions(player, 10.0f, { .CreatureId = NPC_KAYN_SUNFURY_ASHTONGUE, .IgnorePhases = true });
            Creature* korvasObject = GetClosestCreatureWithOptions(player, 10.0f, { .CreatureId = NPC_KORVAS_BLOODTHORN_ASHTONGUE, .IgnorePhases = true });
            if (!kaynObject || !korvasObject)
                return;

            TempSummon* kaynClone = kaynObject->SummonPersonalClone(kaynObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
            TempSummon* korvasClone = korvasObject->SummonPersonalClone(korvasObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
            if (!kaynClone || !korvasClone)
                return;

            korvasClone->SetEmoteState(EMOTE_STATE_READY1H);
            kaynClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_QUESTGIVER));
        }
    }
};

// 98229 - Kayn Sunfury
struct npc_kayn_sunfury_ashtongue_intro_private : public ScriptedAI
{
    npc_kayn_sunfury_ashtongue_intro_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        Creature* korvasObject = GetClosestCreatureWithOptions(me, 10.0f, { .CreatureId = NPC_KORVAS_BLOODTHORN_ASHTONGUE, .IgnorePhases = true, .PrivateObjectOwnerGuid = me->GetPrivateObjectOwner()});
        if (!korvasObject)
            return;

        ObjectGuid korvasGuid = korvasObject->GetGUID();

        _scheduler.Schedule(1s, [this, korvasGuid](TaskContext task)
        {
            Unit* privateObjectOwner = ObjectAccessor::GetUnit(*me, me->GetPrivateObjectOwner());
            if (!privateObjectOwner)
                return;

            Unit* korvas = ObjectAccessor::GetUnit(*me, korvasGuid);
            if (!korvas)
                return;

            Talk(SAY_KAYN_ACTIVATE_GATEWAY, me);
            me->CastSpell(privateObjectOwner, SPELL_TRACK_TARGET_IN_CHANNEL, false);
            korvas->CastSpell(privateObjectOwner, SPELL_TRACK_TARGET_IN_CHANNEL, false);

            task.Schedule(6s, [this, korvasGuid](TaskContext task)
            {
                Talk(SAY_KAYN_CUT_A_HOLE, me);

                task.Schedule(6s, [this, korvasGuid](TaskContext task)
                {
                    Creature* korvas = ObjectAccessor::GetCreature(*me, korvasGuid);
                    if (!korvas)
                        return;

                    if (!korvas->IsAIEnabled())
                        return;

                    korvas->AI()->Talk(SAY_KORVAS_SLAY_MORE_DEMONS, me);
                    me->InterruptNonMeleeSpells(true);
                    me->GetMotionMaster()->MovePath(PATH_KAYN_SUNFURY_NEAR_TELEPORT, false);
                    me->SetAIAnimKitId(ANIM_DH_RUN);
                    me->DespawnOrUnsummon(10s);

                    task.Schedule(2s, [this, korvasGuid](TaskContext /*task*/)
                    {
                        Creature* korvas = ObjectAccessor::GetCreature(*me, korvasGuid);
                        if (!korvas)
                            return;

                        korvas->InterruptNonMeleeSpells(true);
                        korvas->GetMotionMaster()->MovePath(PATH_KORVAS_BLOODTHORN_NEAR_TELEPORT, false);
                        korvas->SetAIAnimKitId(ANIM_DH_RUN);
                        korvas->DespawnOrUnsummon(12s);
                    });
                });
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* KaynSunfuryNearLegionBannerAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_kayn_sunfury_ashtongue_intro_private(creature);
    return new npc_kayn_sunfury_ashtongue_intro(creature);
};

// 1053 - Enter the Illidari: Ashtongue
class scene_enter_the_illidari_ashtongue : public SceneScript
{
public:
    scene_enter_the_illidari_ashtongue() : SceneScript("scene_enter_the_illidari_ashtongue") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        Creature* sevisObject = GetClosestCreatureWithOptions(player, 30.0f, { .CreatureId = NPC_SEVIS_BRIGHTFLAME_ASHTONGUE, .IgnorePhases = true });
        if (!sevisObject)
            return;

        TempSummon* sevisClone = sevisObject->SummonPersonalClone(sevisObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        if (!sevisClone)
            return;

        sevisClone->CastSpell(player, SPELL_TRACK_TARGET_IN_CHANNEL, false);
        sevisClone->DespawnOrUnsummon(15s);
    }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "SEEFELSABERCREDIT")
            player->CastSpell(player, SPELL_ASHTONGUE_FELLSABER_KILL_CREDIT, true);
        else if (triggerName == "UPDATEPHASE")
            PhasingHandler::OnConditionChange(player);
    }
};

// 99916 - Sevis Brightflame (Ashtongue Gateway)
struct npc_sevis_brightflame_ashtongue_gateway_private : public ScriptedAI
{
    npc_sevis_brightflame_ashtongue_gateway_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            Talk(SAY_SEVIS_SAY_FIND_ALLARI, me);

            task.Schedule(2s, [this](TaskContext task)
            {
                me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SEVIS_MOUNT, 0, 0);
                me->SetMountDisplayId(DISPLAY_ID_SEVIS_MOUNT);

                task.Schedule(3s, [this](TaskContext /*task*/)
                {
                    me->InterruptNonMeleeSpells(true);
                    me->GetMotionMaster()->MovePath(PATH_SEVIS_BRIGHTFLAME_GATEWAY, false);
                });
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* SevisBrightflameAshtongueGatewayAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_sevis_brightflame_ashtongue_gateway_private(creature);
    return new NullCreatureAI(creature);
};

// 200255 - Accepting Felsaber Gift
class spell_accepting_felsaber_gift : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_CAST_MOUNT_DH_FELSABER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_accepting_felsaber_gift::HandleHitTarget, EFFECT_3, SPELL_EFFECT_DUMMY);
    }
};

// 32 - Mardum - Trigger KillCredit for Quest "Enter the Illidari: Ashtongue"
struct at_enter_the_illidari_ashtongue_allari_killcredit : AreaTriggerAI
{
    at_enter_the_illidari_ashtongue_allari_killcredit(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) != QUEST_STATUS_INCOMPLETE)
            return;

        player->KilledMonsterCredit(NPC_ALLARI_SOULEATER_ASHTONGUE);
    }
};

enum ETICoilskarIntroData
{
    NPC_SEVIS_BRIGHTFLAME_COILSKAR      = 99917,
    SAY_SEVIS_SAY_MEET_AT_LAST_GATEWAY  = 2,

    PATH_SEVIS_BRIGHTFLAME_COILSKAR     = 9991700
};

// 1077 - Enter the Illidari: Coilskar
class scene_enter_the_illidari_coilskar : public SceneScript
{
public:
    scene_enter_the_illidari_coilskar() : SceneScript("scene_enter_the_illidari_coilskar") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        PhasingHandler::OnConditionChange(player);
        Creature* sevisObject = GetClosestCreatureWithOptions(player, 30.0f, { .CreatureId = NPC_SEVIS_BRIGHTFLAME_COILSKAR, .IgnorePhases = true });
        if (!sevisObject)
            return;

        sevisObject->SummonPersonalClone(sevisObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
    }
};

// 99917 - Sevis Brightflame (Coilskar Gateway)
struct npc_sevis_brightflame_coilskar_gateway_private : public ScriptedAI
{
    npc_sevis_brightflame_coilskar_gateway_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        TempSummon* summon = me->ToTempSummon();
        if (!summon)
            return;

        Unit* summoner = summon->GetSummonerUnit();
        if (!summoner)
            return;

        me->SetFacingToObject(summoner);
        me->DespawnOrUnsummon(14s);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            Talk(SAY_SEVIS_SAY_MEET_AT_LAST_GATEWAY, me);

            task.Schedule(2s, [this](TaskContext task)
            {
                me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SEVIS_MOUNT, 0, 0);
                me->SetMountDisplayId(DISPLAY_ID_SEVIS_MOUNT);

                task.Schedule(3s, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePath(PATH_SEVIS_BRIGHTFLAME_COILSKAR, false);
                });
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* SevisBrightflameCoilskarGatewayAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_sevis_brightflame_coilskar_gateway_private(creature);
    return new NullCreatureAI(creature);
};

enum EyeOnThePrizeData
{
    NPC_COLOSSAL_INFERNAL_BALEFUL               = 96159,

    QUEST_EYE_ON_THE_PRIZE                      = 39049,

    DISPLAYID_BALEFUL_EYE                       = 38795,

    // Inquisitor Baleful text
    SAY_BALEFUL_AGGRO                           = 0,
    SAY_BALEFUL_AEGIS                           = 1,
    SAY_BALEFUL_DEATH                           = 2,

    // Inquisitor Baleful events
    EVENT_BALEFUL_MIND_SPIKE                    = 1,
    EVENT_BALEFUL_BEAMING_GAZE,
    EVENT_BALEFUL_INCITE_MADNESS,
    EVENT_BALEFUL_COLOSS_INFERNAL_SMASH,

    // Inquisitor Baleful points
    POINT_BALEFUL_AEGIS_UP                      = 1,
    POINT_BALEFUL_AEGIS_DOWN,

    // Inquisitor Baleful actions
    ACTION_BALEFUL_AEGIS_DOWN                   = 1,

    // Inquisitor Baleful spells
    SPELL_BALEFUL_MIND_SPIKE                    = 194519,
    SPELL_BALEFUL_BEAMING_GAZE                  = 195058,
    SPELL_BALEFUL_INCITE_MADNESS                = 194529,
    SPELL_BALEFUL_LEGION_AEGIS                  = 192665,
    SPELL_BALEFUL_DIE_KNOCKBACK                 = 190742,
    SPELL_BALEFUL_TAKING_POWER                  = 203925,
    SPELL_BALEFUL_KILL_CREDIT                   = 188559,

    // Baleful Infernal Coloss
    SPELL_BALEFUL_COLOSS_INFERNAL_SMASH         = 192709,
    SPELL_BALEFUL_COLOSS_INFERNAL_SMASH_CAST    = 183938,

    // Baleful Beaming Eye
    SPELL_BALEFUL_BEAMING_EYE_SUMMON            = 195061,
    SPELL_BALEFUL_BEAMING_EYE_CREATE_AT         = 195051
};

class BalefulColossSmashEvent : public BasicEvent
{
public:
    BalefulColossSmashEvent(Creature* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64, uint32) override
    {
        Unit* target = _owner->AI()->SelectTarget(SelectTargetMethod::Random, 0, 150.0f, true);
        _owner->CastSpell(target, SPELL_BALEFUL_COLOSS_INFERNAL_SMASH, false);
        return true;
    }

private:
    Creature* _owner;
};

Position const BalefulAegisPos = { 592.4335f, 2433.1067f, -62.91178f };

// 93105 - Inquisitor Baleful
struct npc_inquisitor_baleful_molten_shore : public ScriptedAI
{
    npc_inquisitor_baleful_molten_shore(Creature* creature) : ScriptedAI(creature), _castedLegionAegis(false) { }

    void JustAppeared() override
    {
        // Blizz use a personal spawn for every DH on Quest: 39049 which leads to issues
        TempSummon* balefulColoss = me->SummonCreature(NPC_COLOSSAL_INFERNAL_BALEFUL, 523.4045f, 2428.4113f, -117.0033f, 0.10887321f, TEMPSUMMON_MANUAL_DESPAWN, 0s);
        if (!balefulColoss)
            return;

        _balefulColossGUID = balefulColoss->GetGUID();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_BALEFUL_AGGRO);
        _events.ScheduleEvent(EVENT_BALEFUL_MIND_SPIKE, 3s);
        _events.ScheduleEvent(EVENT_BALEFUL_BEAMING_GAZE, 7s);
        _events.ScheduleEvent(EVENT_BALEFUL_INCITE_MADNESS, 11s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_BALEFUL_AEGIS_DOWN)
            me->GetMotionMaster()->MovePoint(POINT_BALEFUL_AEGIS_DOWN, me->GetHomePosition());
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_BALEFUL_AEGIS_UP)
            me->SetFacingTo(0.19842f);
        else if (pointId == POINT_BALEFUL_AEGIS_DOWN)
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_castedLegionAegis && me->HealthBelowPctDamaged(60, damage))
        {
            if (Creature* balefulColoss = ObjectAccessor::GetCreature(*me, _balefulColossGUID))
            {
                balefulColoss->m_Events.AddEventAtOffset(new BalefulColossSmashEvent(balefulColoss), 1s);
                balefulColoss->m_Events.AddEventAtOffset(new BalefulColossSmashEvent(balefulColoss), 4s);
                balefulColoss->m_Events.AddEventAtOffset(new BalefulColossSmashEvent(balefulColoss), 8s);
                balefulColoss->m_Events.AddEventAtOffset(new BalefulColossSmashEvent(balefulColoss), 13s);
            }

            DoCast(SPELL_BALEFUL_LEGION_AEGIS);
            me->SetReactState(REACT_PASSIVE);
            Talk(SAY_BALEFUL_AEGIS);
            me->GetMotionMaster()->MovePoint(POINT_BALEFUL_AEGIS_UP, BalefulAegisPos);
            _castedLegionAegis = true;
        }
    }

    void Reset() override
    {
        _castedLegionAegis = false;
        _events.Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCast(SPELL_BALEFUL_DIE_KNOCKBACK);
        Talk(SAY_BALEFUL_DEATH);

        if (Creature* balefulColoss = ObjectAccessor::GetCreature(*me, _balefulColossGUID))
            balefulColoss->KillSelf();

        for (ObjectGuid tapperGUID : me->GetTapList())
        {
            if (Player* tapper = ObjectAccessor::GetPlayer(*me, tapperGUID))
            {
                tapper->CastSpell(tapper, SPELL_BALEFUL_KILL_CREDIT, false);
                tapper->CastSpell(tapper, SPELL_BALEFUL_TAKING_POWER, false);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BALEFUL_MIND_SPIKE:
                    DoCastVictim(SPELL_BALEFUL_MIND_SPIKE);
                    _events.ScheduleEvent(EVENT_BALEFUL_MIND_SPIKE, 7s);
                    break;
                case EVENT_BALEFUL_BEAMING_GAZE:
                    DoCastVictim(SPELL_BALEFUL_BEAMING_GAZE);
                    _events.ScheduleEvent(EVENT_BALEFUL_BEAMING_GAZE, 11s);
                    break;
                case EVENT_BALEFUL_INCITE_MADNESS:
                    DoCastVictim(SPELL_BALEFUL_INCITE_MADNESS);
                    _events.ScheduleEvent(EVENT_BALEFUL_INCITE_MADNESS, 30s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _castedLegionAegis;
    ObjectGuid _balefulColossGUID;
};

// 99160 - Beaming Eye
struct npc_baleful_beaming_eye : public ScriptedAI
{
    npc_baleful_beaming_eye(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetDisplayId(DISPLAYID_BALEFUL_EYE, true);
        DoCastSelf(SPELL_BALEFUL_BEAMING_EYE_CREATE_AT);
        // ToDo: rotation isn't changing orientation, turnspeed should be random
        me->GetMotionMaster()->MoveRotate(0, RAND(ROTATE_DIRECTION_LEFT, ROTATE_DIRECTION_RIGHT), 10s);
    }
};

// 192665 - Legion Aegis
class spell_mardum_baleful_legion_aegis : public AuraScript
{
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            if (UnitAI* ai = GetTarget()->GetAI())
                ai->DoAction(ACTION_BALEFUL_AEGIS_DOWN);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_mardum_baleful_legion_aegis::HandleRemove, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 192709 - Infernal Smash
class spell_mardum_coloss_infernal_smash_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BALEFUL_COLOSS_INFERNAL_SMASH_CAST });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_BALEFUL_COLOSS_INFERNAL_SMASH_CAST, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mardum_coloss_infernal_smash_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 195058 - Beaming Gaze (selector)
class spell_mardum_baleful_beaming_gaze_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BALEFUL_BEAMING_EYE_SUMMON });
    }

    void SummonBeamingEye(Unit* origin, float angle)
    {
        Position dest = origin->GetPosition();
        origin->MovePositionToFirstCollision(dest, 6.5f, angle);
        dest.m_positionZ += 0.35f;
        origin->CastSpell(dest, SPELL_BALEFUL_BEAMING_EYE_SUMMON, true);
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        SummonBeamingEye(hitUnit, float(M_PI));
        SummonBeamingEye(hitUnit, float(-M_PI) / 4.0f);
        SummonBeamingEye(hitUnit, float(M_PI) / 4.0f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mardum_baleful_beaming_gaze_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum SetThemFreeData
{
    NPC_CYANA_NIGHTGLAIVE_FREED     = 94377,
    NPC_IZAL_WHITEMOON_FREED        = 93117,
    NPC_BELATH_DAWNBLADE_FREED      = 94400,
    NPC_MANNETHREL_DARKSTAR_FREED   = 93230,

    SAY_CYANA_NIGHTGLAIVE_FREED     = 1,
    SAY_IZAL_WHITEMOON_FREED        = 1,
    SAY_BELATH_DAWNBLADE_FREED      = 1,
    SAY_MANNETHRE_DARKSTAR_FREED    = 1,

    PATH_CYANA_NIGHTGLAIVE_FREED    = 9437700,
    PATH_IZAL_WHITEMOON_FREED       = 9311700,
    PATH_BELATH_DAWNBLADE_FREED     = 9440000,
    PATH_MANNETHREL_DARKSTAR_FREED  = 9323000,

    ANIM_DH_WALK_DAZED              = 1078
};

// 94377 - Cyana Nightglaive
struct npc_cyana_nightglaive_freed_private : public ScriptedAI
{
    npc_cyana_nightglaive_freed_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->DespawnOrUnsummon(19s);

        _scheduler.Schedule(2s + 500ms, [this](TaskContext task)
        {
            Talk(SAY_CYANA_NIGHTGLAIVE_FREED, me);

            task.Schedule(3s, [this](TaskContext /*task*/)
            {
                me->GetMotionMaster()->MovePath(PATH_CYANA_NIGHTGLAIVE_FREED, false);
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* CyanaNightglaiveFreedAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_cyana_nightglaive_freed_private(creature);
    return new NullCreatureAI(creature);
};

// 93117 - Izal Whitemoon
struct npc_izal_whitemoon_freed_private : public ScriptedAI
{
    npc_izal_whitemoon_freed_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->DespawnOrUnsummon(18s);

        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            Talk(SAY_IZAL_WHITEMOON_FREED, me);

            task.Schedule(3s, [this](TaskContext /*task*/)
            {
                me->GetMotionMaster()->MovePath(PATH_CYANA_NIGHTGLAIVE_FREED, false);
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* IzalWhitemoonFreedAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_izal_whitemoon_freed_private(creature);
    return new NullCreatureAI(creature);
};

// 94400 - Belath Dawnblade
struct npc_belath_dawnblade_freed_private : public ScriptedAI
{
    npc_belath_dawnblade_freed_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->DespawnOrUnsummon(5min); // wtf blizz

        _scheduler.Schedule(3s, [this](TaskContext task)
        {
            Talk(SAY_BELATH_DAWNBLADE_FREED, me);

            task.Schedule(6s, [this](TaskContext /*task*/)
            {
                me->GetMotionMaster()->MovePath(PATH_BELATH_DAWNBLADE_FREED, false);
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* BelathDawnbladeFreedAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_belath_dawnblade_freed_private(creature);
    return new NullCreatureAI(creature);
};

// 93230 - Mannethrel Darkstar
struct npc_mannethrel_darkstar_freed_private : public ScriptedAI
{
    npc_mannethrel_darkstar_freed_private(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->DespawnOrUnsummon(28s);

        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            Talk(SAY_BELATH_DAWNBLADE_FREED, me);

            task.Schedule(6s, [this](TaskContext /*task*/)
            {
                me->SetAIAnimKitId(ANIM_DH_WALK_DAZED);
                me->GetMotionMaster()->MovePath(PATH_MANNETHREL_DARKSTAR_FREED, false);
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* MannethrelDarkstarFreedAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_mannethrel_darkstar_freed_private(creature);
    return new NullCreatureAI(creature);
};

// 204711 - Set Them Free: Cyana Nightglaive Freed Kill Credit
// 204714 - Set Them Free: Izal Whitemoon Freed Kill Credit
// 204712 - Set Them Free: Belath Dawnblade Freed Kill Credit
// 204715 - Set Them Free: Mannethrel Darkstar Freed Kill Credit
template<uint32 CreatureId>
class spell_freed_killcredit_set_them_free : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            Creature* staticObject = GetClosestCreatureWithOptions(player, 10.0f, { .CreatureId = CreatureId, .IgnorePhases = true });
            if (!staticObject)
                return;

            staticObject->SummonPersonalClone(staticObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_freed_killcredit_set_them_free::HandleHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

enum ETIShivarraData
{
    NPC_SEVIS_BRIGHTFLAME_SHIVARRA          = 99915,

    GOSSIP_MENU_SACRIFICE_PLAYER            = 19132,
    GOSSIP_MENU_SACRIFICE_SEVIS             = 19133,

    GOSSIP_OPTION_SACRIFICE_PLAYER          = 0,
    GOSSIP_OPTION_SACRIFICE_SEVIS           = 0,

    SAY_SEVIS_PLAYER_SACRIFICE              = 1,
    SAY_SEVIS_GET_SACRIFICED                = 2,

    ANIM_KIT_SWING_WEAPON                   = 8973,
    ANIM_KIT_KNEEL                          = 2312,
    ANIM_KIT_SALUTE                         = 3342,
    ANIM_KIT_ONESHOT_GET_HIT                = 881,

    SPELL_VISUAL_SACRIFICE_PLAYER           = 55406,

    PATH_SEVIS_GATEWAY_SHIVARRA             = 9991500,

    POINT_SEVIS_GATEWAY_SHIVARRA            = 1,

    SPELL_SACRIFICE_SEVIS                   = 196731,
    SPELL_SEVIS_SACRIFICE_ME                = 196735,
    SPELL_SEVIS_CHAOS_STRIKE                = 204317,
    SPELL_SEVIS_SOUL_MISSILE_02             = 191664,
    SPELL_SEVIS_KILLED_ME_AURA              = 203292,
    SPELL_TRIGGER_SHIVARRA_CONV_WHEN_DEAD   = 196866,

    ACTION_SACRIFICE_PLAYER                 = 1,
    ACTION_SACRIFICE_SEVIS,

    QUEST_SEVIS_SACRIFICE_TRACKER           = 40087,
};

Position const SevisBrightflameShivarraGatewayPosition = { 1587.9618f, 2543.091f, 62.18399f, 3.49967908f };

// 99915 - Sevis Brightflame (Shivarra Gateway)
struct npc_sevis_brightflame_shivarra_gateway : public ScriptedAI
{
    npc_sevis_brightflame_shivarra_gateway(Creature* creature) : ScriptedAI(creature), _soulMissileCounter(0) { }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        if (menuId == GOSSIP_MENU_SACRIFICE_PLAYER && gossipListId == GOSSIP_OPTION_SACRIFICE_PLAYER)
        {
            CloseGossipMenuFor(player);
            player->CastSpell(nullptr, SPELL_SEVIS_SACRIFICE_ME, false);
            return true;
        }
        else if (menuId == GOSSIP_MENU_SACRIFICE_SEVIS && gossipListId == GOSSIP_OPTION_SACRIFICE_SEVIS)
        {
            CloseGossipMenuFor(player);
            player->CastSpell(me, SPELL_SACRIFICE_SEVIS, false);
            return true;
        }
        return false;
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_SACRIFICE_PLAYER:
                SacrificePlayer();
                break;
            case ACTION_SACRIFICE_SEVIS:
                SacrificeSelf();
                break;
            default:
                break;
        }
    }

    void SacrificeSelf()
    {
        me->PlayOneShotAnimKitId(ANIM_KIT_ONESHOT_GET_HIT);
        Talk(SAY_SEVIS_GET_SACRIFICED, me);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            me->KillSelf();

            _soulMissileCounter = 0;
            task.Schedule(2s, [this](TaskContext task)
            {
                DoCast(SPELL_SEVIS_SOUL_MISSILE_02);
                _soulMissileCounter++;

                if (_soulMissileCounter < 3)
                    task.Repeat(2s);
            });
        });
    }

    void SacrificePlayer()
    {
        me->DespawnOrUnsummon(22s);
        Talk(SAY_SEVIS_PLAYER_SACRIFICE, me);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            TempSummon* summon = me->ToTempSummon();
            if (!summon)
                return;

            Unit* summoner = summon->GetSummonerUnit();
            if (!summoner)
                return;

            me->GetMotionMaster()->MoveCloserAndStop(POINT_SEVIS_GATEWAY_SHIVARRA, summoner, 2.0f);

            task.Schedule(2s, [this](TaskContext task)
            {
                me->SendPlaySpellVisualKit(SPELL_VISUAL_SACRIFICE_PLAYER, 4, 1000);
                me->SetAIAnimKitId(ANIM_KIT_SWING_WEAPON);
                DoCast(SPELL_SEVIS_CHAOS_STRIKE);

                task.Schedule(2s, [this](TaskContext task)
                {
                    me->SetAIAnimKitId(ANIM_KIT_KNEEL);

                    task.Schedule(5s, [this](TaskContext task)
                    {
                        me->SetAIAnimKitId(ANIM_KIT_SALUTE);

                        task.Schedule(3s, [this](TaskContext task)
                        {
                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SEVIS_MOUNT, 0, 0);
                            me->SetMountDisplayId(DISPLAY_ID_SEVIS_MOUNT);

                            task.Schedule(2s, [this](TaskContext /*task*/)
                            {
                                me->GetMotionMaster()->MovePath(PATH_SEVIS_GATEWAY_SHIVARRA, false);
                            });
                        });
                    });
                });
            });
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    uint8 _soulMissileCounter;
};

// EventID 47550
class event_sevis_sacrifice_player : public EventScript
{
public:
    event_sevis_sacrifice_player() : EventScript("event_sevis_sacrifice_player") { }

    void OnTrigger(WorldObject* /*object*/, WorldObject* invoker, uint32 /*eventId*/) override
    {
        if (Creature* creature = invoker->SummonCreature(NPC_SEVIS_BRIGHTFLAME_SHIVARRA, SevisBrightflameShivarraGatewayPosition, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, invoker->GetGUID()))
        {
            if (Player* player = invoker->ToPlayer())
            {
                player->KilledMonsterCredit(NPC_SEVIS_BRIGHTFLAME_SHIVARRA);
                player->CastSpell(nullptr, SPELL_SEVIS_KILLED_ME_AURA, false);
            }
            creature->AI()->DoAction(ACTION_SACRIFICE_PLAYER);
        }
    }
};

// EventID 47549
class event_sevis_sacrifice_self : public EventScript
{
public:
    event_sevis_sacrifice_self() : EventScript("event_sevis_sacrifice_self") { }

    void OnTrigger(WorldObject* /*object*/, WorldObject* invoker, uint32 /*eventId*/) override
    {
        if (Creature* creature = invoker->SummonCreature(NPC_SEVIS_BRIGHTFLAME_SHIVARRA, SevisBrightflameShivarraGatewayPosition, TEMPSUMMON_TIMED_DESPAWN, 60s, 0, 0, invoker->GetGUID()))
        {
            if (Player* player = invoker->ToPlayer())
                player->KilledMonsterCredit(NPC_SEVIS_BRIGHTFLAME_SHIVARRA);
            creature->AI()->DoAction(ACTION_SACRIFICE_SEVIS);
        }
    }
};

// XX - Mardum - Trigger Conversation for Quest "Enter the Illidari: Shivarra"
struct at_enter_the_illidari_shivarra_conversation : AreaTriggerAI
{
    at_enter_the_illidari_shivarra_conversation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || !player->HasAura(SPELL_SEVIS_KILLED_ME_AURA))
            return;

        player->CastSpell(nullptr, SPELL_TRIGGER_SHIVARRA_CONV_WHEN_DEAD, true);
    }
};

// 38765 - Enter the Illidari: Shivarra
class quest_enter_the_illidari_shivarra : public QuestScript
{
public:
    quest_enter_the_illidari_shivarra() : QuestScript("quest_enter_the_illidari_shivarra") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->RemoveActiveQuest(QUEST_SEVIS_SACRIFICE_TRACKER, false);
            player->RemoveRewardedQuest(QUEST_SEVIS_SACRIFICE_TRACKER);
        }
    }
};

enum GiveMeSightBeyondSightData
{
    KILLCREDIT_FACE_THE_CAVE            = 96437,

    SPELL_DH_SPECTRAL_SIGHT             = 188501,
    SPELL_GIVE_ME_SIGHT_PERIODIC_AURA   = 191095,
    SPELL_GIVE_ME_SIGHT_PERIODIC_DUMMY  = 191097
};

Position const RockslideCavePosition = { 1237.1528f, 1642.6180f, 103.1518f, 5.8055872f };

// 191097 - Give Me Sight Beyond Sight: Periodic Trigger Dummy
class spell_give_me_sight_beyond_sight_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player || !player->HasAura(SPELL_DH_SPECTRAL_SIGHT))
            return;

        float angleToWall = player->GetAbsoluteAngle(RockslideCavePosition);
        float playerOrientation = player->GetOrientation();
        if (playerOrientation >= Position::NormalizeOrientation(angleToWall - float(M_PI) / 4) && playerOrientation <= Position::NormalizeOrientation(angleToWall + float(M_PI) / 4))
        {
            player->KilledMonsterCredit(KILLCREDIT_FACE_THE_CAVE);
            player->RemoveAurasDueToSpell(SPELL_GIVE_ME_SIGHT_PERIODIC_AURA);
            player->RemoveAurasDueToSpell(SPELL_GIVE_ME_SIGHT_PERIODIC_DUMMY);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_give_me_sight_beyond_sight_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_zone_mardum()
{
    // Creature
    RegisterCreatureAI(npc_kayn_sunfury_invasion_begins);
    RegisterCreatureAI(npc_jayce_darkweaver_invasion_begins);
    RegisterCreatureAI(npc_allari_the_souleater_invasion_begins);
    RegisterCreatureAI(npc_korvas_bloodthorn_invasion_begins);
    RegisterCreatureAI(npc_sevis_brightflame_invasion_begins);
    RegisterCreatureAI(npc_cyana_nightglaive_invasion_begins);
    RegisterCreatureAI(npc_illidari_fighting_invasion_begins);
    RegisterCreatureAI(npc_inquisitor_baleful_molten_shore);
    RegisterCreatureAI(npc_baleful_beaming_eye);
    RegisterCreatureAI(npc_sevis_brightflame_shivarra_gateway);

    // AISelector
    new FactoryCreatureScript<CreatureAI, &KaynSunfuryNearLegionBannerAISelector>("npc_kayn_sunfury_ashtongue_intro");
    new FactoryCreatureScript<CreatureAI, &SevisBrightflameAshtongueGatewayAISelector>("npc_sevis_brightflame_ashtongue_gateway_private");
    new FactoryCreatureScript<CreatureAI, &SevisBrightflameCoilskarGatewayAISelector>("npc_sevis_brightflame_coilskar_gateway_private");
    new FactoryCreatureScript<CreatureAI, &CyanaNightglaiveFreedAISelector>("npc_cyana_nightglaive_freed_private");
    new FactoryCreatureScript<CreatureAI, &IzalWhitemoonFreedAISelector>("npc_izal_whitemoon_freed_private");
    new FactoryCreatureScript<CreatureAI, &BelathDawnbladeFreedAISelector>("npc_belath_dawnblade_freed_private");
    new FactoryCreatureScript<CreatureAI, &MannethrelDarkstarFreedAISelector>("npc_mannethrel_darkstar_freed_private");

    // AreaTrigger
    RegisterAreaTriggerAI(at_enter_the_illidari_ashtongue_allari_killcredit);
    RegisterAreaTriggerAI(at_enter_the_illidari_shivarra_conversation);

    // EventScript
    new event_sevis_sacrifice_player();
    new event_sevis_sacrifice_self();

    // Conversation
    new conversation_the_invasion_begins();

    // Scene
    new scene_demonhunter_intro();
    new scene_enter_the_illidari_ashtongue();
    new scene_enter_the_illidari_coilskar();

    // Quests
    new quest_enter_the_illidari_shivarra();

    // Spells
    RegisterSpellScript(spell_demon_hunter_intro_aura);
    RegisterSpellScript(spell_accepting_felsaber_gift);
    RegisterSpellScript(spell_mardum_baleful_legion_aegis);
    RegisterSpellScript(spell_mardum_coloss_infernal_smash_selector);
    RegisterSpellScript(spell_mardum_baleful_beaming_gaze_selector);
    RegisterSpellScript(spell_give_me_sight_beyond_sight_periodic);
    RegisterSpellScriptWithArgs(spell_freed_killcredit_set_them_free<NPC_CYANA_NIGHTGLAIVE_FREED>, "spell_cyana_nightglaive_killcredit_set_them_free");
    RegisterSpellScriptWithArgs(spell_freed_killcredit_set_them_free<NPC_IZAL_WHITEMOON_FREED>, "spell_izal_whitemoon_killcredit_set_them_free");
    RegisterSpellScriptWithArgs(spell_freed_killcredit_set_them_free<NPC_BELATH_DAWNBLADE_FREED>, "spell_belath_dawnblade_killcredit_set_them_free");
    RegisterSpellScriptWithArgs(spell_freed_killcredit_set_them_free<NPC_MANNETHREL_DARKSTAR_FREED>, "spell_mannethrel_darkstar_killcredit_set_them_free");
};
