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

#include "Object.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Transport.h"
#include "Conversation.h"
#include "TemporarySummon.h"
#include "CreatureAIImpl.h"

// Scripting in this section is from login to arriving on beach for alliance and horde

enum HordeSparingPartner
{
    CONVERSATION_PREFIGHT       = 14422,
    CONVERSATION_AGGRO          = 14423,
    CONVERSATION_JUMP           = 14424,
    EQUIPMENT_AXE               = 175161,
    EVENT_MOVE_TO_A_POSITION    = 1,
    EVENT_PREFIGHT_CONVERSATION = 2,
    EVENT_WALK_BACK             = 3,
    NPC_SPARING_PARTNER         = 166814,
    NPC_SPAR_POINT_ADVERTISMENT = 174971,
    NPC_GRUNT_THROG             = 166583,
    QUEST_KILL_CREDIT           = 155607,
    SPELL_JUMP_BEHIND           = 312757,
    SPELL_COMBAT_TRAINING       = 323071,
    SPELL_UPDATE_PHASE_SHIFT    = 82238,
    SPELL_SUMMON_THROG          = 325107,
    SAY_I_CONCEDE               = 0
};

struct npc_horde_sparring_partner : public ScriptedAI
{
    npc_horde_sparring_partner(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        SetEquipmentSlots(false, EQUIPMENT_AXE, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        _jumped = false;

        Unit* summoner = summonerWO->ToUnit();
        if (!summoner)
            return;

        if (Creature* throg = me->FindNearestCreature(NPC_GRUNT_THROG, 5.0f))
            _throgLocation = throg->GetPosition();

        if (summoner->IsPlayer())
        {
            _playerGUID = summoner->GetGUID();
            _events.ScheduleEvent(EVENT_MOVE_TO_A_POSITION, 2s);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (!me->IsAlive())
            return;

        me->CombatStop(true);
        EngagementOver();
        me->ResetPlayerDamageReq();
        _events.ScheduleEvent(EVENT_WALK_BACK, 1s);
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiId == 1)
        {
            me->SetWalk(true);
            me->GetMotionMaster()->MovePoint(2, me->GetFirstCollisionPosition(2.0f, (float)rand_norm() * static_cast<float>(2 * M_PI)));
        }

        if (uiId == 2)
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                me->SetFacingToObject(player);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            me->SetFaction(32); // *** BIG HACK to be removed after issue with entrying combat with faction 35 fixed ***
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->SetFacingTo(4.677482f);
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            player->KilledMonsterCredit(QUEST_KILL_CREDIT); /// *** MINOR HACK should be done when fight ends but phase change is tied to quest conditions. ***
            player->RemoveAura(SPELL_SUMMON_THROG);
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->GetHealth() <= damage)
        {
            damage = 0;
            me->SetHealth(1);
            DoStopAttack();
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            {
                me->SetFacingToObject(player);
                Talk(SAY_I_CONCEDE, player);
                player->CastSpell(player, SPELL_COMBAT_TRAINING);
            }
        }

        if (me->HealthBelowPct(65) && !_jumped)
        {
            _jumped = true;
            DoCastVictim(SPELL_JUMP_BEHIND, true);
            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                Conversation::CreateConversation(CONVERSATION_JUMP, player, *player, player->GetGUID(), nullptr);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            if (who == player)
                Conversation::CreateConversation(CONVERSATION_AGGRO, player, *player, player->GetGUID(), nullptr);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MOVE_TO_A_POSITION:
            {
                std::list<Creature*> sparpoints;
                GetCreatureListWithEntryInGrid(sparpoints, me, NPC_SPAR_POINT_ADVERTISMENT, 25.0f);
                Trinity::Containers::RandomResize(sparpoints, 1);
                for (Creature* creature : sparpoints)
                {
                    me->GetMotionMaster()->MovePoint(1, creature->GetPosition());
                    me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                }
                _events.ScheduleEvent(EVENT_PREFIGHT_CONVERSATION, 1s);
            }
            break;
            case EVENT_PREFIGHT_CONVERSATION:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    Conversation::CreateConversation(CONVERSATION_PREFIGHT, player, *player, player->GetGUID(), nullptr);
                }
                break;
            case EVENT_WALK_BACK:
                me->GetMotionMaster()->Clear();
                me->SetWalk(true);
                me->GetMotionMaster()->MovePath(10501870, false);
                break;
            default:
                break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    bool _jumped;
    ObjectGuid _playerGUID;
    Position _throgLocation;
};

// Handles actors for quest_brace_for_impact. Could not do spawning in quest script needed a 500ms delay for phase to change.
enum HordeBoat
{
    DATA_SET_SPAWN_ACTORS      = 1,
    EVENT_SPAWN_ACTORS         = 1,
    NPC_WARLORD_BREKA_GRIMAXE3 = 166827,
    NPC_MITHDRAN_DAWNTRACKER   = 166590,
    NPC_LANA_JORDAN            = 166794,
    NPC_BO                     = 166585,
    NPC_PROVISONER_JIN_HAKE    = 166799
};

struct npc_hboat : public ScriptedAI
{
    npc_hboat(Creature* creature) : ScriptedAI(creature), _spawn(false) { }

    void SetData(uint32 /*type*/, uint32 data) override
    {
        if (data == 1)
        {
            _events.ScheduleEvent(EVENT_SPAWN_ACTORS, 500ms);
            _spawn = true;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_spawn)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SPAWN_ACTORS:
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    if (TransportBase const* transport = player->GetDirectTransport())
                    {
                        Position brekapos = { 25.5237f, 0.283005f, 26.5455f, 3.1465182f - float(M_PI) }; // transport offset
                        Position throgpos = { -10.8399f, 11.9039f, 8.88028f, 3.3538847f - float(M_PI) }; // transport offset
                        Position mithpos = { -24.4763f, -4.48273f, 9.13471f, 3.152601f - float(M_PI) }; // transport offset
                        Position lanapos = { -5.1971f, -15.0268f, 8.992f, 2.2585895f + float(M_PI) }; // transport offset
                        Position bopos = { -22.1559f, 5.58041f, 9.09176f, 3.5204296f - float(M_PI) }; // transport offset
                        Position jinpos = { -31.9464f, 7.5772f, 10.6408f, 3.5658937f - float(M_PI) }; // transport offset

                        if (Creature* breka = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE3, 30.0f))
                        {
                            float x, y, z, o;
                            brekapos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            brekapos.Relocate(x, y, z, o);
                            breka->SummonPersonalClone(brekapos, TEMPSUMMON_TIMED_DESPAWN, 15s, 0, 0, player);
                        }

                        if (Creature* throg = player->FindNearestCreature(NPC_GRUNT_THROG, 30.0f))
                        {
                            float x, y, z, o;
                            throgpos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            throgpos.Relocate(x, y, z, o);
                            throg->SummonPersonalClone(throgpos, TEMPSUMMON_TIMED_DESPAWN, 15s, 0, 0, player);
                        }

                        if (Creature* mithdran = player->FindNearestCreature(NPC_MITHDRAN_DAWNTRACKER, 30.0f))
                        {
                            float x, y, z, o;
                            mithpos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            mithpos.Relocate(x, y, z, o);
                            mithdran->SummonPersonalClone(mithpos, TEMPSUMMON_TIMED_DESPAWN, 15s, 0, 0, player);
                        }

                        if (Creature* lana = player->FindNearestCreature(NPC_LANA_JORDAN, 30.0f))
                        {
                            float x, y, z, o;
                            lanapos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            lanapos.Relocate(x, y, z, o);
                            lana->SummonPersonalClone(lanapos, TEMPSUMMON_TIMED_DESPAWN, 15s, 0, 0, player);
                        }

                        if (Creature* bo = player->FindNearestCreature(NPC_BO, 30.0f))
                        {
                            float x, y, z, o;
                            bopos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            bopos.Relocate(x, y, z, o);
                            bo->SummonPersonalClone(bopos, TEMPSUMMON_TIMED_DESPAWN, 15s, 0, 0, player);
                        }

                        if (Creature* jin = player->FindNearestCreature(NPC_PROVISONER_JIN_HAKE, 30.0f))
                        {
                            float x, y, z, o;
                            jinpos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            jinpos.Relocate(x, y, z, o);
                            jin->SummonPersonalClone(jinpos, TEMPSUMMON_TIMED_DESPAWN, 15s, 0, 0, player);
                        }
                    }
                }
            }
            break;
            default:
                break;
            }
            _spawn = false;
        }
    }

private:
    EventMap _events;
    bool _spawn;
public:
    ObjectGuid _playerGUID;
};

enum QuestScripts
{
    CONVERSATION_WARMING_UP         = 12798,
    NPC_WARLORD_BREKA_GRIMAXE1      = 166573,
    NPC_WARLORD_BREKA_GRIMAXE2      = 166824,
    NPC_HBOAT                       = 168039
};

class quest_warming_up : public QuestScript
{
public:
    quest_warming_up() : QuestScript("quest_warming_up") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/ , QuestStatus newStatus) override
    {
        switch (newStatus)
        {
            case QUEST_STATE_COMPLETE:
                Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID(), nullptr);
                break;
            case QUEST_STATUS_REWARDED:
                if (Creature* breka1 = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE1, 5.0f))
                    if (Creature* breka2 = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE2, 75.0f))
                        breka2->SummonPersonalClone(breka1->GetPosition(), TempSummonType(TEMPSUMMON_TIMED_DESPAWN), 18s, 0, 0, player);
                break;
            default:
                break;
        }
    }
};

class quest_stand_your_ground : public QuestScript
{
public:
    quest_stand_your_ground() : QuestScript("quest_stand_your_ground") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATE_NONE)
            player->RemoveAura(SPELL_SUMMON_THROG);
    }
};

class quest_brace_for_impact : public QuestScript
{
public:
    quest_brace_for_impact() : QuestScript("quest_brace_for_impact") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_COMPLETE)
        {
            if (Creature* hBoat = player->FindNearestCreature(NPC_HBOAT, 30.0f))
            {
                ENSURE_AI(npc_hboat, hBoat->GetAI())->_playerGUID = player->GetGUID();
                hBoat->AI()->SetData(1, 1);
            }
        }
    }
};

class conversation_horde_sparing_partner : public ConversationScript
{
public:
    conversation_horde_sparing_partner() : ConversationScript("conversation_horde_sparing_partner") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {       
        std::list<Creature*> spar;
        creator->GetCreatureListWithEntryInGrid(spar, NPC_SPARING_PARTNER, 25.0f);
        for (Creature* creature : spar)
        {
            if (creature->GetDemonCreatorGUID() == creator->GetGUID()) // @TODO requires research about DemonCreator usage for summons to work
                conversation->AddActor(creature->GetEntry(), 1, creature->GetGUID());
        }
    }
};

enum PlayerScriptHordeShipCrash
{
    MOVIE_ALLIANCE_SHIP_CRASH = 895,
    MOVIE_HORDE_SHIP_CRASH    = 931,
    SPELL_ALLIANCE_SHIP_CRASH = 305446,
    SPELL_HORDE_SHIP_CRASH    = 325133
};

class player_ship_crash : public PlayerScript
{
public:
    player_ship_crash() : PlayerScript("player_ship_crash") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        switch (movieId)
        {
            case MOVIE_ALLIANCE_SHIP_CRASH:
                player->CastSpell(player, SPELL_ALLIANCE_SHIP_CRASH, true);
                break;
            case MOVIE_HORDE_SHIP_CRASH:
                player->CastSpell(player, SPELL_HORDE_SHIP_CRASH, true);
                break;
            default:
                break;
        }
    }
};

enum AllianceHordeShipSceneSpells
{
    SPELL_BEGIN_TUTORIAL = 295600,
    SPELL_KNOCKED_DOWN   = 305445,
    SPELL_CRASHED_LANDED = 325136
};

class scene_alliance_and_horde_ship : public SceneScript
{
public:
    scene_alliance_and_horde_ship() : SceneScript("scene_alliance_and_horde_ship") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }
};

class scene_alliance_and_horde_crash : public SceneScript
{
public:
    scene_alliance_and_horde_crash() : SceneScript("scene_alliance_and_horde_crash") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Begin Knockdown Aura")
            player->CastSpell(player, SPELL_KNOCKED_DOWN, true);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_CRASHED_LANDED, true);
    }
};

class spell_summon_throg_combat_training : public SpellScript
{
    PrepareSpellScript(spell_summon_throg_combat_training);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        // Needs work to relocate target position "Crashes server"
        /*
        Unit* target = GetHitUnit();

        if (TransportBase const* transport = target->GetDirectTransport())
        {
            Position throgpos = { -10.898641f, 12.044f, 8.787247f, 4.8911366f }; // transport offset
            float x, y, z, o;
            throgpos.GetPosition(x, y, z, o);
            transport->CalculatePassengerPosition(x, y, z, &o);
            throgpos.Relocate(x, y, z, o);
            GetHitDest()->WorldRelocate(target->GetTransport()->GetMapIdForSpawning(), throgpos);
        }
        */
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_summon_throg_combat_training::RelocateTransportOffset, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

class spell_alliance_spell_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_alliance_spell_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alliance_spell_ship_crash_teleport::RelocateTransportOffset, EFFECT_4, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

class spell_horde_spell_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_horde_spell_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_horde_spell_ship_crash_teleport::RelocateTransportOffset, EFFECT_3, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

// Scripting in this section is from arriving on beach for alliance and horde

void AddSC_zone_exiles_reach()
{
    // Ship
    RegisterCreatureAI(npc_horde_sparring_partner);
    RegisterCreatureAI(npc_hboat);
    new quest_warming_up();
    new quest_stand_your_ground();
    new quest_brace_for_impact();
    new conversation_horde_sparing_partner();
    new player_ship_crash();
    new scene_alliance_and_horde_ship();
    new scene_alliance_and_horde_crash();
    RegisterSpellScript(spell_summon_throg_combat_training);
    RegisterSpellScript(spell_alliance_spell_ship_crash_teleport);
    RegisterSpellScript(spell_horde_spell_ship_crash_teleport);
    // Beach
}
