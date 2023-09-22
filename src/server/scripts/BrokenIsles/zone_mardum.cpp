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
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
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

        DoMeleeAttackIfReady();
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

    // AISelector
    new FactoryCreatureScript<CreatureAI, &KaynSunfuryNearLegionBannerAISelector>("npc_kayn_sunfury_ashtongue_intro");
    new FactoryCreatureScript<CreatureAI, &SevisBrightflameAshtongueGatewayAISelector>("npc_sevis_brightflame_ashtongue_gateway_private");

    // AreaTrigger
    RegisterAreaTriggerAI(at_enter_the_illidari_ashtongue_allari_killcredit);

    // Conversation
    new conversation_the_invasion_begins();

    // Scene
    new scene_demonhunter_intro();
    new scene_enter_the_illidari_ashtongue();

    // Spells
    RegisterSpellScript(spell_demon_hunter_intro_aura);
    RegisterSpellScript(spell_accepting_felsaber_gift);
};
