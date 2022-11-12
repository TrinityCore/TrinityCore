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
#include "SpellScript.h"
#include "MotionMaster.h"
#include "Conversation.h"
#include "ObjectAccessor.h"
#include "CreatureAIImpl.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"

// ********************************************
// * Scripting in this section occurs on ship *
// ********************************************

enum SparingPartner
{
    CONVERSATION_PREFIGHT           = 14422,
    CONVERSATION_AGGRO              = 14423,
    CONVERSATION_JUMP               = 14424,

    EQUIPMENT_SWORD                 = 108493,
    EQUIPMENT_AXE                   = 175161,

    EVENT_MOVE_TO_A_POSITION        = 1,
    EVENT_PREFIGHT_CONVERSATION     = 2,
    EVENT_WALK_BACK                 = 3,

    NPC_ALLIANCE_SPARING_PARTNER    = 157051,
    NPC_HORDE_SPARING_PARTNER       = 166814,
    NPC_SPAR_POINT_ADVERTISMENT     = 174971,
    NPC_KILL_CREDIT                 = 155607,

    PATH_ALLIANCE_SPARING_PARTNER   = 10501460,
    PATH_HORDE_SPARING_PARTNER      = 10501870,

    POSITION_SPARPOINT_ADVERTISMENT = 1,
    POSITION_SPARPOINT_READY        = 2,

    SPELL_JUMP_BEHIND               = 312757,
    SPELL_COMBAT_TRAINING           = 323071,
    SPELL_UPDATE_PHASE_SHIFT        = 82238,
    SPELL_SUMMON_COLE               = 303064,
    SPELL_SUMMON_THROG              = 325107,

    TALK_SPARING_COMPLETE           = 0
};

struct npc_sparring_partner : public ScriptedAI
{
    npc_sparring_partner(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_ALLIANCE_SPARING_PARTNER)
        {
            SetEquipmentSlots(false, EQUIPMENT_SWORD, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            _summonSpell = SPELL_SUMMON_COLE;
            _path = PATH_ALLIANCE_SPARING_PARTNER;
            _actorID = 0;
        }
        else
        {
            SetEquipmentSlots(false, EQUIPMENT_AXE, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            _summonSpell = SPELL_SUMMON_THROG;
            _path = PATH_HORDE_SPARING_PARTNER;
            _actorID = 1;
        }
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        _jumped = false;

        Unit* summoner = summonerWO->ToUnit();
        if (!summoner)
            return;

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

        switch (uiId)
        {
            case POSITION_SPARPOINT_ADVERTISMENT:
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(POSITION_SPARPOINT_READY, me->GetFirstCollisionPosition(2.0f, (float)rand_norm() * static_cast<float>(2 * M_PI)));
                break;
            case POSITION_SPARPOINT_READY:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->SetFacingToObject(player);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
                me->SetFaction(32); // *** HACK to be removed after issue with entrying combat with faction 35 fixed ***
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            player->KilledMonsterCredit(NPC_KILL_CREDIT); // *** MINOR HACK should be done when fight ends but phase change is tied to quest conditions. ***
            player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT);
            player->RemoveAura(_summonSpell);
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
                Talk(TALK_SPARING_COMPLETE, player);
                player->CastSpell(player, SPELL_COMBAT_TRAINING);
            }
        }

        if (me->HealthBelowPctDamaged(65, damage) && !_jumped)
        {
            _jumped = true;
            DoCastVictim(SPELL_JUMP_BEHIND, true);
            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            {
                Conversation* convo = Conversation::CreateConversation(CONVERSATION_JUMP, player, *player, player->GetGUID(), nullptr);
                convo->AddActor(me->GetEntry(), _actorID, me->GetGUID());
            }
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            if (who == player)
            {
                Conversation* convo = Conversation::CreateConversation(CONVERSATION_AGGRO, player, *player, player->GetGUID(), nullptr);
                convo->AddActor(me->GetEntry(), _actorID, me->GetGUID());
            }
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
                            me->GetMotionMaster()->MovePoint(POSITION_SPARPOINT_ADVERTISMENT, creature->GetPosition());
                            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        }
                        _events.ScheduleEvent(EVENT_PREFIGHT_CONVERSATION, 1s);
                    }
                    break;
                case EVENT_PREFIGHT_CONVERSATION:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        Conversation* convo = Conversation::CreateConversation(CONVERSATION_PREFIGHT, player, *player, player->GetGUID(), nullptr);
                        convo->AddActor(me->GetEntry(), _actorID, me->GetGUID());
                    }
                    break;
                case EVENT_WALK_BACK:
                    me->GetMotionMaster()->Clear();
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePath(_path, false);
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
    uint8 _actorID;
    uint32 _path;
    uint32 _summonSpell;
    ObjectGuid _playerGUID;

};

enum QuestScripts
{
    CONVERSATION_WARMING_UP         = 12798,

    NPC_WARLORD_BREKA_GRIMAXE1      = 166573,
    NPC_WARLORD_BREKA_GRIMAXE2      = 166824,
    NPC_WARLORD_BREKA_GRIMAXE3      = 166827,
    NPC_GRUNT_THROG                 = 166583,
    NPC_MITHDRAN_DAWNTRACKER        = 166590,
    NPC_LANA_JORDAN                 = 166794,
    NPC_BO                          = 166585,
    NPC_PROVISONER_JIN_HAKE         = 166799,
    NPC_CAPTAIN_GARRICK             = 156280,
    NPC_QUARTERMASTER_RICHTER       = 157042,
    NPC_KEE_LA                      = 157043,
    NPC_BJORN_STOUTHANDS            = 157044,
    NPC_AUSTIN_HUXWORTH             = 157046,
    NPC_PRIVATE_COLE                = 160664,
    NPC_MECHANICAL_BUNNY_PET        = 167337, // Gnome Hunter Pet
    NPC_MOTH_PET                    = 167342, // Draenei Hunter Pet
    NPC_DRAGONHAWK_PET              = 167343, // Blood Elf Hunter Pet
    NPC_SCORPION_PET                = 167344, // Goblin Hunter Pet
    NPC_GREY_WOLF_PET               = 167345, // Human Hunter Pet
    NPC_RED_WOLF_PET                = 167346, // Orc Hunter Pet
    NPC_TIGER_PET                   = 167347, // Night Elf Hunter Pet
    NPC_TURTLE_PET                  = 167348, // Pandaren Hunter Pet
    NPC_PLAINSTRIDER_PET            = 167349, // Tauren Hunter Pet
    NPC_RAPTOR_PET                  = 167350, // Troll Hunter Pet
    NPC_BAT_PET                     = 167351, // Undead Hunter Pet
    NPC_DOG_PET                     = 167352, // Worgan Hunter Pet
    NPC_BEAR_PET                    = 167375, // Dwarf Hunter Pet

    QUEST_WARMING_UP_ALLIANCE       = 56775,
    QUEST_WARMING_UP_HORDE          = 59926,
    QUEST_BRACE_FOR_IMPACT_ALLIANCE = 58208,
    QUEST_BRACE_FOR_IMPACT_HORDE    = 59928
};

class quest_warming_up : public QuestScript
{
public:
    quest_warming_up() : QuestScript("quest_warming_up") { }

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus /*oldStatus*/ , QuestStatus newStatus) override
    {
        switch (newStatus)
        {
            case QUEST_STATUS_COMPLETE:
                Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID(), nullptr);
                break;
            case QUEST_STATUS_REWARDED:
                if (quest->GetQuestId() == QUEST_WARMING_UP_ALLIANCE)
                {
                    Position garrickpos = { -3.0797f, -0.546193f, 5.29752f, 3.3191178f }; // transport offset

                    if (TransportBase const* transport = player->GetDirectTransport())
                        if (Creature* garrick = player->FindNearestCreature(NPC_CAPTAIN_GARRICK, 75.0f))
                        {
                            float x, y, z, o;
                            garrickpos.GetPosition(x, y, z, o);
                            transport->CalculatePassengerPosition(x, y, z, &o);
                            garrickpos.Relocate(x, y, z, o);
                            if (Creature* garrick2 = garrick->SummonPersonalClone(garrickpos, TEMPSUMMON_TIMED_DESPAWN, 60s, 0, 0, player))
                            {
                                garrick2->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                                if (garrick2->IsAIEnabled())
                                    garrick2->AI()->SetData(1, 1);
                            }
                        }
                }
                else if (quest->GetQuestId() == QUEST_WARMING_UP_HORDE)
                {
                    if (Creature* breka1 = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE1, 10.0f))
                        if (Creature* breka2 = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE2, 75.0f))
                            breka2->SummonPersonalClone(breka1->GetPosition(), TempSummonType(TEMPSUMMON_TIMED_DESPAWN), 18s, 0, 0, player);
                }
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
        if (newStatus == QUEST_STATUS_NONE)
        {
            if(player->GetTeam() == ALLIANCE)
                player->RemoveAura(SPELL_SUMMON_COLE);
            else
                player->RemoveAura(SPELL_SUMMON_THROG);
        }
    }
};

// Not working properly. Issue with phase not changing until after quest complete
class quest_brace_for_impact : public QuestScript
{
public:
    quest_brace_for_impact() : QuestScript("quest_brace_for_impact") { }

    void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_COMPLETE)
        {
            if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT_ALLIANCE)
            {
                Position garrickpos = { 35.5643f, -1.19837f, 12.1479f, 3.3272014f };
                Position richterpos = { -1.84858f, -8.38776f, 5.10018f, 1.5184366f };
                Position keelapos = { -15.3642f, 6.5793f, 5.5026f, 3.1415925f };
                Position bjornpos = { 12.8406f, -8.49553f, 4.98031f, 4.8520155f };
                Position austinpos = { -4.48607f, 9.89729f, 5.07851f, 1.5184366f };
                Position colepos = { -13.3396f, 0.702157f, 5.57996f, 0.087266445f };
                Position petpos = { -1.4492f, 8.06887f,  5.10348f, 2.6005409f };

                SpawnActor(player, NPC_CAPTAIN_GARRICK, garrickpos);
                SpawnActor(player, NPC_QUARTERMASTER_RICHTER, richterpos);
                SpawnActor(player, NPC_KEE_LA, keelapos);
                SpawnActor(player, NPC_BJORN_STOUTHANDS, bjornpos);
                SpawnActor(player, NPC_AUSTIN_HUXWORTH, austinpos);
                SpawnActor(player, NPC_PRIVATE_COLE, colepos);

                // Spawn pet
                if (player->GetClass() == CLASS_HUNTER)
                {
                    switch (player->GetRace())
                    {
                        case RACE_HUMAN:
                            SpawnActor(player, NPC_GREY_WOLF_PET, petpos);
                            break;
                        case RACE_DWARF:
                            SpawnActor(player, NPC_BEAR_PET, petpos);
                            break;
                        case RACE_NIGHTELF:
                            SpawnActor(player, NPC_TIGER_PET, petpos);
                            break;
                        case RACE_GNOME:
                            SpawnActor(player, NPC_MECHANICAL_BUNNY_PET, petpos);
                            break;
                        case RACE_DRAENEI:
                            SpawnActor(player, NPC_MOTH_PET, petpos);
                            break;
                        case RACE_WORGEN:
                            SpawnActor(player, NPC_DOG_PET, petpos);
                            break;
                        case RACE_PANDAREN_ALLIANCE:
                            SpawnActor(player, NPC_TURTLE_PET, petpos);
                            break;
                        default:
                            break;
                    }
                }
            }
            else if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT_HORDE)
            {
                Position brekapos = { 25.5237f, 0.283005f, 26.5455f, 3.3526998f };
                Position throgpos = { -10.8399f, 11.9039f, 8.88028f, 6.2308254f };
                Position mithpos = { -24.4763f, -4.48273f, 9.13471f, 0.62831855f };
                Position lanapos = { -5.1971f, -15.0268f, 8.992f, 4.712389f };
                Position bopos = { -22.1559f, 5.58041f, 9.09176f, 6.143559f };
                Position jinpos = { -31.9464f, 7.5772f, 10.6408f, 6.0737457f };
                Position petpos = { -22.8374f, -3.08287f, 9.12613f, 3.857178f };

                SpawnActor(player, NPC_WARLORD_BREKA_GRIMAXE3, brekapos);
                SpawnActor(player, NPC_GRUNT_THROG, throgpos);
                SpawnActor(player, NPC_MITHDRAN_DAWNTRACKER, mithpos);
                SpawnActor(player, NPC_LANA_JORDAN, lanapos);
                SpawnActor(player, NPC_BO, bopos);
                SpawnActor(player, NPC_PROVISONER_JIN_HAKE, jinpos);

                // Spawn pet
                if (player->GetClass() == CLASS_HUNTER)
                {
                    switch (player->GetRace())
                    {
                        case RACE_ORC:
                            SpawnActor(player, NPC_RED_WOLF_PET, petpos);
                            break;
                        case RACE_UNDEAD_PLAYER:
                            SpawnActor(player, NPC_BAT_PET, petpos);
                            break;
                        case RACE_TAUREN:
                            SpawnActor(player, NPC_PLAINSTRIDER_PET, petpos);
                            break;
                        case RACE_TROLL:
                            SpawnActor(player, NPC_RAPTOR_PET, petpos);
                            break;
                        case RACE_GOBLIN:
                            SpawnActor(player, NPC_SCORPION_PET, petpos);
                            break;
                        case RACE_BLOODELF:
                            SpawnActor(player, NPC_DRAGONHAWK_PET, petpos);
                            break;
                        case RACE_PANDAREN_HORDE:
                            SpawnActor(player, NPC_TURTLE_PET, petpos);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }

    void SpawnActor(Player* player, uint32 entry, Position position)
    {
        if (Creature* creature = player->FindNearestCreature(entry, 75.0f))
            if (TransportBase const* transport = player->GetDirectTransport())
            {
                float x, y, z, o;
                position.GetPosition(x, y, z, o);
                transport->CalculatePassengerPosition(x, y, z, &o);
                position.Relocate(x, y, z, o);
                Creature* actor = creature->SummonPersonalClone(position, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);

                // Needed for pathing
                switch (entry)
                {
                    case NPC_CAPTAIN_GARRICK:
                        if (actor->IsAIEnabled())
                            actor->AI()->SetData(1, 2);
                        break;
                    case NPC_TURTLE_PET:
                        if (actor->IsAIEnabled())
                        {
                            if (player->GetTeam() == TEAM_ALLIANCE)
                                actor->AI()->SetData(1, 1);
                            else
                                actor->AI()->SetData(1, 2);
                        }
                        break;
                    default:
                        break;
                }
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
    SPELL_BEGIN_TUTORIAL          = 295600,
    SPELL_KNOCKED_DOWN            = 305445,
    SPELL_CRASHED_LANDED_ALLIANCE = 305464,
    SPELL_CRASHED_LANDED_HORDE    = 325136
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

// Need Spell.cpp updated to handle this
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

// Need Spell.cpp updated to handle this
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

// ***************************************************************
// * Scripting in this section occurs after teleporting to beach *
// ***************************************************************

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
        if (player->GetTeam() == ALLIANCE)
            player->CastSpell(player, SPELL_CRASHED_LANDED_ALLIANCE, true);
        else
            player->CastSpell(player, SPELL_CRASHED_LANDED_HORDE, true);
    }
};

enum SpellCrashLanded
{
    NPC_CAPTAIN_GARRICK2       = 156626,
    NPC_WARLORD_BREKA_GRIMAXE4 = 166782
};

class spell_crash_landed_alliance : public SpellScript
{
    PrepareSpellScript(spell_crash_landed_alliance);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Player* player = caster->ToPlayer())
                if (Creature* garrick = player->FindNearestCreature(NPC_CAPTAIN_GARRICK2, 40.0f))
                {
                    Creature* garrick2 = garrick->SummonPersonalClone(garrick->GetPosition(), TempSummonType(TEMPSUMMON_TIMED_DESPAWN), 10s, 0, 0, player);
                    if (garrick2->IsAIEnabled())
                        garrick2->AI()->SetData(1, 1);
                }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_crash_landed_alliance::HandleEffect, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
    }
};

class spell_crash_landed_horde : public SpellScript
{
    PrepareSpellScript(spell_crash_landed_horde);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if(Player * player = caster->ToPlayer())
                if (Creature* breka = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE4, 40.0f))
                {
                    Creature* breka2 = breka->SummonPersonalClone(breka->GetPosition(), TempSummonType(TEMPSUMMON_TIMED_DESPAWN), 10s, 0, 0, player);
                    if (breka2->IsAIEnabled())
                        breka2->AI()->SetData(1, 1);
                }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_crash_landed_horde::HandleEffect, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
    }
};

void AddSC_zone_exiles_reach()
{
    // Ship
    RegisterCreatureAI(npc_sparring_partner);
    new quest_warming_up();
    new quest_stand_your_ground();
    new quest_brace_for_impact();
    new player_ship_crash();
    new scene_alliance_and_horde_ship();
    RegisterSpellScript(spell_alliance_spell_ship_crash_teleport); // Need update in spell.cpp to remove this.
    RegisterSpellScript(spell_horde_spell_ship_crash_teleport); // Need update in spell.cpp to remove this.
    // Beach
    new scene_alliance_and_horde_crash();
    RegisterSpellScript(spell_crash_landed_alliance);
    RegisterSpellScript(spell_crash_landed_horde);
}
