/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "Player.h"
#include "ObjectMgr.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "WaypointManager.h"
#include "MotionMaster.h"
#include "PhasingHandler.h"
#include "SpellInfo.h"
#include "Log.h"
#include "Map.h"
#include "Transport.h"
#include "DBCEnums.h"
#include "LFGMgr.h"
#include "LFGQueue.h"
#include "LFGPackets.h"
#include "DynamicObject.h"
#include "CreatureTextMgr.h"
#include "MiscPackets.h"
#include "Creature.h"
#include "Vehicle.h"
#include "TemporarySummon.h"
#include "CombatAI.h"
#include "Unit.h"

#define GOSSIP_ACCEPT_DUEL "Let''s duel"
#define EVENT_SPECIAL 20

class scene_azsuna_runes : public SceneScript
{
public:
    scene_azsuna_runes() : SceneScript("scene_azsuna_runes") { }

    // Called when a player receive trigger from scene
    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate, std::string const& triggerName) override
    {
        if (triggerName == "Credit")
        {
            uint32 killCreditEntry = 0;

            switch (sceneTemplate->ScenePackageId)
            {
            case 1378: //Azsuna - Academy - Runes A(Arcane, Quest) - PRK
            case 1695: //Azsuna - Academy - Runes D(Arcane: Sophomore) - PRK
            case 1696: //Azsuna - Academy - Runes E(Arcane: Junior) - PRK
            case 1697: //Azsuna - Academy - Runes F(Arcane: Senior) - PRK
                killCreditEntry = 89655;
                break;
            case 1379: //Azsuna - Academy - Runes B(Fire, Quest) - PRK
            case 1698: //Azsuna - Academy - Runes G(Fire: Freshman) - PRK
            case 1699: //Azsuna - Academy - Runes H(Fire: Junior) - PRK
            case 1700: //Azsuna - Academy - Runes I(Fire: Senior) - PRK
                killCreditEntry = 89656;
                break;
            case 1380: //Azsuna - Academy - Runes C(Frost, Quest) - PRK
            case 1701: //Azsuna - Academy - Runes J(Frost: Freshman) - PRK
            case 1702: //Azsuna - Academy - Runes K(Frost: Junior) - PRK
            case 1703: //Azsuna - Academy - Runes L(Frost: Senior) - PRK
                killCreditEntry = 89657;
                break;
            }

            if (killCreditEntry)
                player->KilledMonsterCredit(killCreditEntry);
        }
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate) override
    {
        uint32 nextSceneSpellId = 0;

        switch (sceneTemplate->ScenePackageId)
        {
        case 1378: nextSceneSpellId = 223283; break; //Azsuna - Academy - Runes A(Arcane, Quest) - PRK, next : fire quest
        case 1379: nextSceneSpellId = 223287; break; //Azsuna - Academy - Runes B(Fire, Quest) - PRK, next : frost quest
        default:
        case 1695: //Azsuna - Academy - Runes D(Arcane: Sophomore) - PRK
        case 1696: //Azsuna - Academy - Runes E(Arcane: Junior) - PRK
        case 1697: //Azsuna - Academy - Runes F(Arcane: Senior) - PRK
        case 1698: //Azsuna - Academy - Runes G(Fire: Freshman) - PRK
        case 1699: //Azsuna - Academy - Runes H(Fire: Junior) - PRK
        case 1700: //Azsuna - Academy - Runes I(Fire: Senior) - PRK
        case 1380: //Azsuna - Academy - Runes C(Frost, Quest) - PRK
        case 1701: //Azsuna - Academy - Runes J(Frost: Freshman) - PRK
        case 1702: //Azsuna - Academy - Runes K(Frost: Junior) - PRK
        case 1703: //Azsuna - Academy - Runes L(Frost: Senior) - PRK
            break;
        }

        if (nextSceneSpellId)
            player->CastSpell(player, nextSceneSpellId, true);
    }
};

// 93326
class npc_archmage_khadgar_93337 : public CreatureScript
{
public:
    npc_archmage_khadgar_93337() : CreatureScript("npc_archmage_khadgar_93337") { }

    enum eNpc
    {
        QUEST_INTO_THE_FRAY_DH = 44137,
        QUEST_INTO_THE_FRAY = 38834,
        SPELL_TRANSFORM_KHADGAR_RAVEN = 165291,
        EVENT_SAY_HURRY = 11,
        EVENT_TRANSFORM = 12,
        EVENT_MOVE_CAMP = 13,
        EVENT_DESPAWN = 14,
        DATA_DO_SOMETHING = 21,
    };

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_INTO_THE_FRAY)
        {
            creature->GetAI()->SetData(DATA_DO_SOMETHING, DATA_DO_SOMETHING);
        }
        return true;
    }

    struct npc_archmage_khadgar_93337_AI : public ScriptedAI
    {
        npc_archmage_khadgar_93337_AI(Creature* creature) : ScriptedAI(creature) {
            Initialize();
        }

        void Initialize() {}

        void Reset() override
        {
            me->SetWalk(false);
            me->SetSpeed(MOVE_RUN, 1.0f);
            me->SetHomePosition(me->GetPosition());
            _events.Reset();
            Initialize();
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
            case DATA_DO_SOMETHING:
                _events.ScheduleEvent(EVENT_SAY_HURRY, 300);
                break;
            default:
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                switch (id)
                {
                case 6:
                    _events.ScheduleEvent(EVENT_DESPAWN, 1000);
                    break;
                default:
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SAY_HURRY:
                    me->AI()->Talk(1);
                    _events.ScheduleEvent(EVENT_TRANSFORM, 1000);
                    break;
                case EVENT_TRANSFORM:
                    DoCast(me, SPELL_TRANSFORM_KHADGAR_RAVEN, true);
                    _events.ScheduleEvent(EVENT_MOVE_CAMP, 300);
                    break;
                case EVENT_MOVE_CAMP:
                    me->GetMotionMaster()->MovePath(9332600, false);
                    break;
                case EVENT_DESPAWN:
                    me->RemoveAurasDueToSpell(SPELL_TRANSFORM_KHADGAR_RAVEN);
                    me->GetMotionMaster()->MoveTargetedHome();
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
                }
            }
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_khadgar_93337_AI(creature);
    }
};

struct questnpc_soul_gem : public ScriptedAI
{
    questnpc_soul_gem(Creature* creature) : ScriptedAI(creature) { }

    ObjectGuid _playerGUID;

    void Reset() override
    {
        _playerGUID = ObjectGuid::Empty;
    }

    void GetTargets()
    {
        /*if (!me->GetOwner() || !me->GetOwner()->IsPlayer())
            return;*/

        std::list<Creature*> targets = me->FindAllCreaturesInRange(100.0f);

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            for (auto itr : targets)
            {
                if (itr->isDead())
                {
                    switch (itr->GetEntry())
                    {
                    case 90230:
                    case 90241:
                    case 93619:
                    case 101943:
                        me->CastSpell(itr, 178753, true);
                        me->CastSpell(itr, 178752, true);
                        itr->DespawnOrUnsummon();
                        player->KilledMonsterCredit(90298, ObjectGuid::Empty);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (Player* player = summoner->ToPlayer()) {
            _playerGUID = player->GetGUID();
            GetTargets();
        }
    }
};

enum eManaDrainedWhelpling
{
    NPC_AZUREWING_WHELPLING = 90336,
    NPC_WALPLAUZE_BESIEGT = 89050,
    QUEST_42159 = 42159,
    FACTION_HOSTILE = 2068,
    POINT_HOME = 4,
    ALLARI_SOUL = 89398,
    EAY_KILLROGA = 4277,
};

// 90167
struct questnpc_mana_drained_whelpling : public ScriptedAI
{
    questnpc_mana_drained_whelpling(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) override
    {
        me->GetScheduler().Schedule(1s, [](TaskContext context)
        {
            Creature* crea = GetContextCreature();
            crea->UpdateEntry(NPC_AZUREWING_WHELPLING);
            crea->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            crea->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
        });

        me->GetScheduler().Schedule(3s, [](TaskContext context)
        {
            GetContextCreature()->SetCanFly(true);
            GetContextCreature()->GetMotionMaster()->MoveTakeoff(0, Position(1162.338135f, 6816.301270f, 236.106567f));
        });

        me->GetScheduler().Schedule(10s, [](TaskContext context)
        {
            GetContextCreature()->DisappearAndDie();
        });
    }
};

const Position PrinceFarondisWaypoints[45] =
{
    { -139.941f, 6418.82f, 27.5658f, 4.11514f },
    { -120.835f, 6406.78f, 27.8503f, 0.0f },
    { -120.335f, 6402.53f, 27.8503f, 0.0f },
    { -122.835f, 6399.28f, 27.8503f, 0.0f },
    { -125.335f, 6391.53f, 27.8503f, 0.0f },
    { -123.085f, 6385.03f, 23.1003f, 0.0f },
    { -118.085f, 6382.03f, 18.8503f, 0.0f },
    { -109.085f, 6379.53f, 13.3503f, 0.0f },
    { -101.335f, 6382.53f, 7.6003f, 0.0f },
    { -100.444f, 6386.17f, 6.83712f, 0.0f },
    { -100.444f, 6386.17f, 6.83712f, 2.07324f },
    { -95.8294f, 6388.88f, 7.26227f, 0.0f },
    { -94.8294f, 6389.63f, 7.26227f, 0.0f },
    { -93.3294f, 6390.38f, 7.01227f, 0.0f },
    { -93.0794f, 6390.88f, 7.01227f, 0.0f },
    { -89.0794f, 6390.38f, 5.01227f, 0.0f },
    { -87.8294f, 6390.13f, 4.51227f, 0.0f },
    { -86.5794f, 6390.13f, 3.76227f, 0.0f },
    { -86.3717f, 6390.11f, 3.89118f, 0.0f },
    { -85.8717f, 6390.11f, 3.64118f, 0.0f },
    { -84.8717f, 6389.86f, 2.89118f, 0.0f },
    { -80.3717f, 6388.86f, 2.64118f, 0.0f },
    { -77.1217f, 6389.61f, 2.39118f, 0.0f },
    { -75.1217f, 6389.61f, 2.14118f, 0.0f },
    { -72.8843f, 6386.12f, 1.87715f, 0.0f },
    { -69.7899f, 6380.26f, 1.26035f, 5.40096f },
    { -69.7899f, 6380.26f, 1.26035f, 5.69111f },
    { -69.7899f, 6380.26f, 1.26035f, 5.5598f },
    { -70.8134f, 6374.45f, 1.88123f, 0.0f },
    { -76.7876f, 6324.35f, 2.20502f, 0.0f },
    { -77.9117f, 6303.3f, 1.67607f, 0.0f },
    { -78.1617f, 6297.3f, 0.926067f, 0.0f },
    { -78.4117f, 6293.3f, 0.676067f, 0.0f },
    { -79.8264f, 6279.31f, 1.2063f, 0.0f },
    { -72.6649f, 6266.31f, 3.10757f, 0.0f },
    { -70.3085f, 6262.07f, 3.71657f, 0.0f },
    { -57.191f, 6253.5f, 3.63329f, 0.0f },
    { -55.302f, 6254.65f, 3.8715f, 0.0f },
    { -53.552f, 6255.4f, 4.3715f, 0.0f },
    { -47.552f, 6258.15f, 6.8715f, 0.0f },
    { -46.302f, 6258.65f, 7.1215f, 0.0f },
    { -46.4121f, 6258.42f, 7.22652f, 0.0f },
    { -45.4121f, 6258.67f, 7.47652f, 0.0f },
    { -43.1621f, 6259.42f, 8.22652f, 0.0f },
    { -40.4149f, 6260.48f, 8.81002f, 0.0f },
};

enum PrinceEvents
{
    EVENT_FIREBALL,
    EVENT_METEOR_STORM,
    EVENT_WAYPOINT_REACHED,
};

enum PrinceCreatures
{
    NPC_PRINCE_FARONDIS = 88889,
    NPC_DROWNED_MAGISTER = 87368,
    NPC_UNBREATHING_SOUL = 87369,
};

enum PrinceSpells
{
    SPELL_FIREBALL = 178784,
    SPELL_METEOR_STORM = 179215,
    SPELL_DUEL = 52996,
    SPELL_DUEL_FLAG = 52991,
    SPELL_DUEL_VICTORY = 52994,
};

class npc_prince_farondis : public CreatureScript
{
public:
    npc_prince_farondis() : CreatureScript("npc_prince_farondis") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(37467) == QUEST_STATUS_INCOMPLETE) // The Walk of Shame
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Please, show me where the Tidestone lies.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, 26247, creature->GetGUID());


        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            if (Creature* prince = creature->SummonCreature(NPC_PRINCE_FARONDIS, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000))
            {
                PhasingHandler::AddPhase(prince, 174, true);
                PhasingHandler::AddPhase(player, 174, true);
            }
            break;
        }

        return true;
    }
};

// 88889 - Prince Farondis
class npc_prince_farondis_escort : public CreatureScript
{
public:
    npc_prince_farondis_escort() : CreatureScript("npc_prince_farondis_escort") { }

    struct npc_prince_farondis_escortAI : public ScriptedAI
    {
        npc_prince_farondis_escortAI(Creature* creature) : ScriptedAI(creature) {}

        bool paused;
        uint8 count;
        bool wp_reached;
        ObjectGuid targetGuid;
        ObjectGuid targetGuid2;
        ObjectGuid playerGuid;

        void Reset() override
        {
            paused = false;
            count = 0;
            wp_reached = false;
            targetGuid = ObjectGuid::Empty;
            targetGuid2 = ObjectGuid::Empty;
            playerGuid = ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* /*me*/) override
        {
            wp_reached = false;
            me->SetWalk(false);
            me->GetMotionMaster()->MovePoint(count, PrinceFarondisWaypoints[count]);
            me->SetSpeedRate(MOVE_RUN, 1.0f);
            events.ScheduleEvent(EVENT_WAYPOINT_REACHED, 1000);
            if (Player* player = me->SelectNearestPlayer(10.0f))
                playerGuid = player->GetGUID();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != count || paused)
                return;

            switch (id)
            {
            case 0:
                Talk(0);
                break;

            case 10:
                if (Creature* summon = me->SummonCreature(NPC_DROWNED_MAGISTER, -120.073f, 6400.717f, 6.92f, 5.64f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                {
                    EnterCombat(summon);
                    me->SetInCombatWith(summon);
                    summon->SetMaxHealth(1009570);
                    summon->SetHealth(1009570);
                    summon->SetFaction(14);
                    me->AI()->AttackStart(summon);
                    summon->GetMotionMaster()->MoveChase(me, 20.0f, summon->GetOrientation());
                    targetGuid = summon->GetGUID();
                    summon->Say("Farondis! You traitor! You brought this upon us!", LANG_UNIVERSAL);
                    me->GetMotionMaster()->Clear();
                    me->SetFacingToObject(summon, true);
                }
                break;

            case 11:
                Talk(1);
                break;

            case 26:
                if (Creature* summon = me->SummonCreature(NPC_UNBREATHING_SOUL, -63.1638f, 6379.03f, 1.200768f, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                {
                    EnterCombat(summon);
                    me->SetInCombatWith(summon);
                    summon->SetMaxHealth(1196528);
                    summon->SetHealth(1196528);
                    summon->SetFaction(14);
                    me->AI()->AttackStart(summon);
                    summon->GetMotionMaster()->MoveChase(me, 20.0f, summon->GetOrientation());
                    targetGuid2 = summon->GetGUID();
                    summon->Yell("DIE... FARONDIS....", LANG_UNIVERSAL);
                    me->GetMotionMaster()->Clear();
                    me->SetFacingToObject(summon, true);
                }
                break;

            case 44:
                Talk(2);
                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                {
                    player->KilledMonsterCredit(88746, ObjectGuid::Empty);
                    PhasingHandler::AddPhase(player, 174, true);
                    PhasingHandler::AddPhase(player, 169, true);
                }

                me->DespawnOrUnsummon();
                break;

            default:
                break;
            }

            if (id < 45)
            {
                if (!paused)
                {
                    ++count;
                    wp_reached = true;
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!paused)
            {
                events.ScheduleEvent(EVENT_FIREBALL, 1000);
                events.ScheduleEvent(EVENT_METEOR_STORM, 12000);
                paused = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_FIREBALL:
            {
                if (Unit* target = me->GetVictim())
                    me->CastSpell(target, SPELL_FIREBALL, true);

                events.ScheduleEvent(EVENT_FIREBALL, 5000);
                break;
            }

            case EVENT_METEOR_STORM:
            {
                if (Unit* target = me->GetVictim())
                    me->CastSpell(target, SPELL_METEOR_STORM, true);

                me->GetSpellHistory()->ResetAllCooldowns();
                events.ScheduleEvent(EVENT_METEOR_STORM, 2000);
                break;
            }

            case EVENT_WAYPOINT_REACHED:
            {
                if (targetGuid != ObjectGuid::Empty)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGuid))
                    {
                        if (!target->IsAlive() && paused)
                        {
                            events.CancelEvent(EVENT_FIREBALL);
                            events.CancelEvent(EVENT_METEOR_STORM);
                            ++count;
                            paused = false;
                            wp_reached = true;
                            targetGuid = ObjectGuid::Empty;
                        }
                    }
                }

                if (targetGuid2 != ObjectGuid::Empty)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGuid2))
                    {
                        if (!target->IsAlive() && paused)
                        {
                            events.CancelEvent(EVENT_FIREBALL);
                            events.CancelEvent(EVENT_METEOR_STORM);
                            ++count;
                            paused = false;
                            wp_reached = true;
                            targetGuid2 = ObjectGuid::Empty;
                        }
                    }
                }

                if (wp_reached && !paused)
                {
                    me->GetMotionMaster()->MovePoint(count, PrinceFarondisWaypoints[count]);
                    wp_reached = false;
                    me->SetWalk(false);
                    me->SetSpeedRate(MOVE_RUN, 1.0f);
                }

                events.ScheduleEvent(EVENT_WAYPOINT_REACHED, 1000);
                break;
            }
            }

            DoMeleeAttackIfReady();
        }

    protected:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prince_farondis_escortAI(creature);
    }
};


// 250361
class go_sabotaged_portal_stabilizer : public GameObjectScript
{
public:
    go_sabotaged_portal_stabilizer() : GameObjectScript("go_sabotaged_portal_stabilizer") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        player->CastSpell(go, 6478, true);
        player->KillCreditGO(250361, go->GetGUID());

        return true;
    }
};

enum
{
    NPC_AGAPANT = 90543,
};

// 214482 - Radiant Ley Crystal
class spell_gen_radiant_ley_crystal : public SpellScriptLoader
{
public:
    spell_gen_radiant_ley_crystal() : SpellScriptLoader("spell_gen_radiant_ley_crystal") { }

    class spell_gen_radiant_ley_crystal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_radiant_ley_crystal_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = ObjectAccessor::GetUnit(*caster, GetCaster()->GetTarget()))
                {
                    if (target->GetTypeId() == TYPEID_UNIT)
                    {
                        switch (target->GetEntry())
                        {
                        case 107961:
                            caster->ToPlayer()->KilledMonsterCredit(107961, ObjectGuid::Empty);
                            return SPELL_CAST_OK;
                        case 107962:
                            caster->ToPlayer()->KilledMonsterCredit(107962, ObjectGuid::Empty);
                            return SPELL_CAST_OK;
                        case 107963:
                            caster->ToPlayer()->KilledMonsterCredit(107963, ObjectGuid::Empty);
                            return SPELL_CAST_OK;
                        case 107964:
                            caster->ToPlayer()->KilledMonsterCredit(107964, ObjectGuid::Empty);
                            return SPELL_CAST_OK;
                        default:
                            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
                        }
                    }
                }
            }

            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_gen_radiant_ley_crystal_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gen_radiant_ley_crystal_SpellScript();
    }
};

// 211546 - Word of Versatility
class spell_word_of_versatility : public SpellScriptLoader
{
public:
    spell_word_of_versatility() : SpellScriptLoader("spell_word_of_versatility") {}

    class spell_word_of_versatility_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_word_of_versatility_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                    if (target->GetTypeId() == TYPEID_UNIT)
                        switch (target->GetEntry())
                        {
                        case 89278:
                        case 89969:
                            caster->ToPlayer()->KilledMonsterCredit(106642, ObjectGuid::Empty);
                            break;
                        default:
                            break;
                        }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_word_of_versatility_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_word_of_versatility_SpellScript();
    }
};

class npc_quest_43521 : public CreatureScript
{
public:
    npc_quest_43521() : CreatureScript("npc_quest_43521") { }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 /*slot*/) override
    {
        if (_Quest->GetQuestId() == 43521)
        {
            if (AchievementEntry const *ForgedforBattle = sAchievementStore.LookupEntry(10746))
            {
                player->CompletedAchievement(ForgedforBattle);
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_quest_43521AI(creature);
    }

    struct npc_quest_43521AI : public ScriptedAI
    {
        npc_quest_43521AI(Creature* creature) : ScriptedAI(creature) { }
    };
};

class npc_quest_43520 : public CreatureScript
{
public:
    npc_quest_43520() : CreatureScript("npc_quest_43520") { }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 /*slot*/) override
    {
        if (_Quest->GetQuestId() == 43520)
        {
            if (AchievementEntry const *ForgedforBattle = sAchievementStore.LookupEntry(11144))
            {
                player->CompletedAchievement(ForgedforBattle);
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_quest_43520AI(creature);
    }

    struct npc_quest_43520AI : public ScriptedAI
    {
        npc_quest_43520AI(Creature* creature) : ScriptedAI(creature) { }
    };
};

// quest local
// 210543 - Rally the Nightwatchers
class spell_rally_the_nightwatchers : public SpellScript
{
    PrepareSpellScript(spell_rally_the_nightwatchers);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {

        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                if (target->GetTypeId() == TYPEID_UNIT)
                    if (target->GetEntry() == 88782)
                        caster->ToPlayer()->KilledMonsterCredit(106273, ObjectGuid::Empty);
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_rally_the_nightwatchers::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};
/*
class ps_quest_rally_the_nightwatchers : public PlayerScript
{
public:
    ps_quest_rally_the_nightwatchers() : PlayerScript("ps_quest_rally_the_nightwatchers") { }

    void OnQuestAccept(Player* player, Quest const* quest)
    {
        if (quest->GetQuestId() == 42108)
            player->CastSpell(player, 210554, true);
    }

    void OnUpdateArea(Player* player, Area* newArea, Area* /*oldArea*///)
   /*{
        switch (newArea->GetId())
        {
        case 7357:
        case 7355:
            if (player->HasQuest(42108))
                player->CastSpell(player, 210554, true);
            break;
        default:
            break;
        }
    }
};
*/
//QQQ
class merayl_q42159 : public CreatureScript
{
public:
    merayl_q42159(const std::string str) : CreatureScript(str.c_str()) { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF)
        {
            CloseGossipMenuFor(player);
            if (player->IsInCombat() || creature->IsInCombat())
                return true;

            if (merayl_q42159AI* pInitiateAI = CAST_AI(merayl_q42159::merayl_q42159AI, creature->AI()))
            {
                if (pInitiateAI->m_bIsDuelInProgress)
                    return true;
            }
            creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            creature->RemoveUnitFlag(UNIT_FLAG_UNK_15);

            player->CastSpell(creature, SPELL_DUEL, false);
            player->CastSpell(player, SPELL_DUEL_FLAG, true);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if ((player->GetQuestStatus(QUEST_42159) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_42159) == QUEST_STATUS_INCOMPLETE)
            && creature->IsFullHealth())
        {
            if (player->HealthBelowPct(10))
                return true;

            if (player->IsInCombat() || creature->IsInCombat())
                return true;

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ACCEPT_DUEL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new merayl_q42159AI(creature);
    }

    struct merayl_q42159AI : public CombatAI
    {
        merayl_q42159AI(Creature* creature) : CombatAI(creature)
        {
            m_bIsDuelInProgress = false;
        }

        bool lose;
        ObjectGuid m_uiDuelerGUID;
        uint32 m_uiDuelTimer;
        bool m_bIsDuelInProgress;
        uint32 spelltimer;

        void Reset() override
        {
            lose = false;
            me->RestoreFaction();
            CombatAI::Reset();

            me->AddUnitFlag(UNIT_FLAG_UNK_15);

            m_uiDuelerGUID.Clear();
            m_uiDuelTimer = 5000;
            spelltimer = 2000;
            m_bIsDuelInProgress = false;
        }

        void SpellHit(Unit* pCaster, const SpellInfo* spell) override
        {
            if (!m_bIsDuelInProgress && spell->Id == SPELL_DUEL)
            {
                m_uiDuelerGUID = pCaster->GetGUID();
                m_bIsDuelInProgress = true;
            }
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage/*, DamageEffectType dmgType*/) override
        {
            if (m_bIsDuelInProgress && pDoneBy->IsControlledByPlayer())
            {
                if (pDoneBy->GetGUID() != m_uiDuelerGUID && pDoneBy->GetOwnerGUID() != m_uiDuelerGUID) // other players cannot help
                    uiDamage = 0;
                else if (uiDamage >= me->GetHealth())
                {
                    uiDamage = 0;

                    if (!lose)
                    {
                        if (Player* plr = pDoneBy->ToPlayer())
                            plr->KilledMonsterCredit(106552);

                        pDoneBy->RemoveGameObject(SPELL_DUEL_FLAG, true);
                        pDoneBy->AttackStop();
                        me->CastSpell(pDoneBy, SPELL_DUEL_VICTORY, true);
                        lose = true;
                        me->CastSpell(me, 7267, true);
                        me->RestoreFaction();
                    }
                }
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
            {
                if (m_bIsDuelInProgress)
                {
                    if (m_uiDuelTimer <= uiDiff)
                    {
                        me->SetFaction(FACTION_HOSTILE);

                        if (Unit* unit = ObjectAccessor::GetUnit(*me, m_uiDuelerGUID))
                            AttackStart(unit);
                    }
                    else
                        m_uiDuelTimer -= uiDiff;
                }
                return;
            }

            if (m_bIsDuelInProgress)
            {
                if (lose)
                {
                    if (!me->HasAura(7267))
                        EnterEvadeMode(EvadeReason::EVADE_REASON_OTHER);
                    return;
                }
                else if (me->GetVictim() && me->GetVictim()->GetTypeId() == TYPEID_PLAYER && me->GetVictim()->HealthBelowPct(10))
                {
                    me->GetVictim()->CastSpell(me->GetVictim(), 7267, true); // beg
                    me->GetVictim()->RemoveGameObject(SPELL_DUEL_FLAG, true);
                    EnterEvadeMode(EvadeReason::EVADE_REASON_OTHER);
                    return;
                }

                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (spelltimer <= uiDiff)
                {
                    uint32 spell = 0;
                    switch (me->GetEntry())
                    {
                    case 108752:
                        spell = 172673;
                        spelltimer = 2000;
                        break;
                    case 108765:
                        spell = 198623;
                        spelltimer = 2000;
                        break;
                    case 108767:
                    case 108750:
                        spell = 172757;
                        spelltimer = 11000;
                        break;
                    case 108723:
                        spell = 171777;
                        spelltimer = 5500;
                        break;
                    default:
                        break;
                    }
                    if (spell > 0)
                        DoCast(spell);
                }
                else
                    spelltimer -= uiDiff;
            }

            // TODO: spells

            CombatAI::UpdateAI(uiDiff);
        }
    };
};

class npc_q44281 : public merayl_q42159
{
public:
    npc_q44281() : merayl_q42159("npc_q44281") { }
};

// quest 37538
class npc_kimmruder_88911 : public CreatureScript
{
public:
    npc_kimmruder_88911() : CreatureScript("npc_kimmruder_88911") { }
    struct npc_kimmruder_88911AI : public ScriptedAI
    {
        npc_kimmruder_88911AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37538) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 28.0f))
                    {
                        if (!me->FindNearestCreature(89056, 50.0f, true))
                        {
                            if (!me->FindNearestCreature(89050, 50.0f, true))

                            {
                                me->SummonCreature(89056, Position(-356.077f, 6655.04f, 0.539664f, 0.215275f), TEMPSUMMON_MANUAL_DESPAWN);
                            }
                        }
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kimmruder_88911AI(creature);
    }
};

// quest 38015
struct cedonu_107962 : public ScriptedAI
{
    cedonu_107962(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(38015) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(107962);
            }
        }
    }
};

struct kharmeera_107963 : public ScriptedAI
{
    kharmeera_107963(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(38015) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(107963);
            }
        }
    }
};

struct emmigosa_107961 : public ScriptedAI
{
    emmigosa_107961(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(38015) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(107961);
            }
        }
    }
};

struct berazus_107964 : public ScriptedAI
{
    berazus_107964(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(38015) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(107964);
            }
        }
    }
};

// quest 42756
class npc_summon_91155 : public CreatureScript
{
public:
    npc_summon_91155() : CreatureScript("npc_summon_91155") { }
    struct npc_summon_91155AI : public ScriptedAI
    {
        npc_summon_91155AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(42756) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 28.0f))
                    {
                        if (!me->FindNearestCreature(91155, 40.0f, true))

                        {
                            if (!me->FindNearestCreature(108721, 40.0f, true))

                            {
                                me->SummonCreature(91155, Position(620.386f, 6650.63f, 60.0061f, 1.01631f), TEMPSUMMON_MANUAL_DESPAWN);
                            }
                        }
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_summon_91155AI(creature);
    }
};

//212782
class spell_Wand_Practice : public SpellScript
{
    PrepareSpellScript(spell_Wand_Practice);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {

        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                if (target->GetTypeId() == TYPEID_UNIT)
                    if (target->GetEntry() == 107279)
                    {
                        caster->ToPlayer()->KilledMonsterCredit(107279, ObjectGuid::Empty);
                    }

    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_Wand_Practice::HandleDummy, EFFECT_0, SPELL_EFFECT_CREATE_AREATRIGGER);
    }
};
/*
class ps_quest_Wandering : public PlayerScript
{
public:
    ps_quest_Wandering() : PlayerScript("ps_quest_Wanderings") { }

    void OnQuestAccept(Player* player, Quest const* quest)
    {
        if (quest->GetQuestId() == 42370)
            player->CastSpell(player, 212782, true);
    }

    void OnUpdateArea(Player* player, Area* newArea, Area* /*oldArea*///)
   /* {
        switch (newArea->GetId())
        {
        case 7358:
            if (player->HasQuest(42370))
                player->CastSpell(player, 212782, true);
            break;
        default:
            break;
        }
    }
}; */

// 89978
class npc_senegosa_89978 : public CreatureScript
{
public:
    npc_senegosa_89978() : CreatureScript("npc_senegosa_89978") { }
    struct npc_senegosa_89978AI : public ScriptedAI
    {
        npc_senegosa_89978AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37957) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 15.0f))
                    {
                        player->KilledMonsterCredit(90479);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_senegosa_89978AI(creature);
    }
};

class go_pylon_mana245572 : public GameObjectScript
{
public:
    go_pylon_mana245572() : GameObjectScript("go_pylon_mana245572") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37860) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(100383);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

class go_pylon_mana245573 : public GameObjectScript
{
public:
    go_pylon_mana245573() : GameObjectScript("go_pylon_mana245573") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37860) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(100384);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

class go_pylon_mana239959 : public GameObjectScript
{
public:
    go_pylon_mana239959() : GameObjectScript("go_pylon_mana239959") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37860) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(90263);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

class go_pylon_mana245574 : public GameObjectScript
{
public:
    go_pylon_mana245574() : GameObjectScript("go_pylon_mana245574") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37860) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(100385);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

class go_fel_power_run244706 : public GameObjectScript
{
public:
    go_fel_power_run244706() : GameObjectScript("go_fel_power_run244706") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(39940) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(244706);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

// 211441 - drop-stone
class spell_drop_stone : public SpellScript
{
    PrepareSpellScript(spell_drop_stone);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->FindNearestCreature(106625, 10.0f, true))
            {
                caster->ToPlayer()->KilledMonsterCredit(106625, ObjectGuid::Empty);
            }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_drop_stone::HandleDummy, EFFECT_0, SPELL_EFFECT_REMOVE_AURA);
    }
};


// quest 37991
class npc_agapant_90543 : public CreatureScript
{
public:
    npc_agapant_90543() : CreatureScript("npc_agapant_90543") { }
    struct npc_agapant_90543AI : public ScriptedAI
    {
        npc_agapant_90543AI(Creature* creature) : ScriptedAI(creature) { }
        void Reset()
        {
            say = false;
        }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37991) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 15.0f))
                    {
                        player->KilledMonsterCredit(90543);
                    }
                }
            }
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestObjectiveData(42271, 4))
                    if (Creature* Agapant = me->FindNearestCreature(NPC_AGAPANT, 20.0f, true))
                    {
                        if (!say)
                        {
                            say = true;
                            Agapant->GetScheduler().Schedule(2s, [Agapant](TaskContext context)
                            {
                                Agapant->AI()->Talk(0);
                            });
                        }
                    }
            }
        }
    private:
        bool say;
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_agapant_90543AI(creature);
    }
};

// quest 43519
class npc_lucid_strength_89939 : public CreatureScript
{
public:
    npc_lucid_strength_89939() : CreatureScript("npc_lucid_strength_89939") { }
    struct npc_lucid_strength_89939AI : public ScriptedAI
    {
        npc_lucid_strength_89939AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(43519) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 15.0f))
                    {
                        player->KilledMonsterCredit(111223);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lucid_strength_89939AI(creature);
    }
};

struct mana_drained_90880 : public ScriptedAI
{
    mana_drained_90880(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(42271) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->GetQuestObjectiveData(42271, 3))

                {
                    me->SetAIAnimKitId(4061);
                    player->KilledMonsterCredit(90880);
                    me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                    me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                }
            }
        }
    }
    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (player->GetQuestStatus(42271) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->IsInDist(me, 15.0f))
                {
                    if (player->GetQuestObjectiveData(42271, 4))
                    {
                        if (!me->FindNearestCreature(900880, 70.0f))
                        {
                            {
                                me->SummonCreature(900880, Position(642.059f, 6607.97f, 60.1522f, 1.73476f), TEMPSUMMON_MANUAL_DESPAWN);
                            }
                        }
                    }
                }
            }
            if (player->GetQuestStatus(42271) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->GetQuestObjectiveData(42271, 3))
                {
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                }
            }
        }
    }
};

struct mana_drained_900880 : public ScriptedAI
{
    mana_drained_900880(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(42271) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->GetQuestObjectiveData(42271, 4))

                {
                    me->SetAIAnimKitId(4061);
                    player->KilledMonsterCredit(122292);
                    me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                    me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                }
            }
        }
    }
    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (player->GetQuestStatus(42271) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->GetQuestObjectiveData(42271, 4))
                {
                    {
                        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    }
                }
            }
        }
    }
};

struct npc_quest_1970196 : public ScriptedAI
{
    npc_quest_1970196(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (player->GetQuestStatus(40130) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->IsInDist(me, 45.0f))
                {
                    if (!me->FindNearestCreature(98698, 70.0f))
                    {
                        {
                            me->SummonCreature(98698, Position(311.416f, 7424.86f, 144.469f, 4.66642f), TEMPSUMMON_MANUAL_DESPAWN);
                        }
                    }
                }
            }
        }
    }
};

class npc_demon_86963 : public CreatureScript
{
public:
    npc_demon_86963() : CreatureScript("npc_demon_86963") { }

    struct npc_demon_86963AI : public WorldBossAI
    {
        npc_demon_86963AI(Creature* creature) : WorldBossAI(creature) { }
        void JustDied(Unit* who/*killer*/) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37653) == QUEST_STATUS_INCOMPLETE)
                {
                    if (me->FindNearestCreature(86963, 15.0f))
                    {
                        player->KilledMonsterCredit(90298);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_demon_86963AI(creature);
    }
};

class npc_demon_89398 : public CreatureScript
{
public:
    npc_demon_89398() : CreatureScript("npc_demon_89398") { }

    bool OnGossipHello(Player* player, Creature* Creature) override
    {
        if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
        {
            player->SummonCreature(90401, Position(-91.4928977f, 6978.054199f, 12.537963f, 3.945533f), TEMPSUMMON_MANUAL_DESPAWN);
            return true;
        }
        return false;
    }
};

class npc_demon_90402 : public CreatureScript
{
public:
    npc_demon_90402() : CreatureScript("npc_demon_90402") { }

    struct npc_demon_90402AI : public WorldBossAI
    {
        npc_demon_90402AI(Creature* creature) : WorldBossAI(creature) { }
        void JustDied(Unit* who/*killer*/) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
                {
                    player->SummonGameObject(239332, -163.918f, 6917.27f, 12.6521f, 5.33958f, QuaternionData(), 0);
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_demon_90402AI(creature);
    }
};

class npc_demon_89276 : public CreatureScript
{
public:
    npc_demon_89276() : CreatureScript("npc_demon_89276") { }

    struct npc_demon_89276AI : public WorldBossAI
    {
        npc_demon_89276AI(Creature* creature) : WorldBossAI(creature) { }
        void JustDied(Unit* who/*killer*/) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
                {
                    player->SummonGameObject(237017, -157.634f, 6904.87f, 13.3225f, 5.30559f, QuaternionData(), 0);
                }
            }
        }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 35.0f))
                    {
                        {
                            player->KilledMonsterCredit(239332);
                        }
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_demon_89276AI(creature);
    }
};

class go_soul_gem239338 : public GameObjectScript
{
public:
    go_soul_gem239338() : GameObjectScript("go_soul_gem239338") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(239338);
            player->SummonCreature(90402, Position(-154.604f, 6893.52f, 14.6885f, 1.85288f), TEMPSUMMON_MANUAL_DESPAWN);
            return true;
        }
        return false;
    }
};

class go_soul_gem239332 : public GameObjectScript
{
public:
    go_soul_gem239332() : GameObjectScript("go_soul_gem239332") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(239332);
            player->SummonCreature(89276, Position(-166.148f, 6914.08f, 11.6642f, 6.21969f), TEMPSUMMON_MANUAL_DESPAWN);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

class go_soul_gem237017 : public GameObjectScript
{
public:
    go_soul_gem237017() : GameObjectScript("go_soul_gem237017") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(237017);
            player->SummonCreature(89673, Position(-161.554f, 6903.05f, 13.3184f, 0.476697f), TEMPSUMMON_MANUAL_DESPAWN);
            go->GetPhaseShift().AddPhase(-169, PhaseFlags::None, nullptr);
            return true;
        }
        return false;
    }
};

const Position AllariWaypoints[45] =
{
    { -139.941f, 6418.82f, 27.5658f, 4.11514f },
};

class npc_demon_89673 : public CreatureScript
{
public:
    npc_demon_89673() : CreatureScript("npc_demon_89673") { }

    struct npc_demon_89673AI : public WorldBossAI
    {
        npc_demon_89673AI(Creature* creature) : WorldBossAI(creature) { }
        void JustDied(Unit* who/*killer*/) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
                {
                    player->KilledMonsterCredit(240012);
                }
                if (Creature* Allari = me->FindNearestCreature(ALLARI_SOUL, 65.0f, true))
                {
                    Allari->GetMotionMaster()->MovePoint(POINT_HOME, Position(-90.0801f, 6978.73f, 12.4473f, 1.90998f), true);
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_demon_89673AI(creature);
    }
};

struct npc_quest_1970197 : public ScriptedAI
{
    npc_quest_1970197(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->IsInDist(me, 25.0f))
                {
                    if (player->GetQuestObjectiveData(37660, 8))
                    {
                        {
                            player->KilledMonsterCredit(89398);
                        }
                    }
                }
            }
        }
    }
};

struct npc_quest_107242 : public ScriptedAI
{
    npc_quest_107242(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void MoveInLineOfSight(Unit* Unit) override
    {
        if (Player* player = Unit->ToPlayer())
        {
            if ((player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE) && (player->HasAura(212754)))
            {
                if (player->GetDistance(me) < 20.0f)
                    player->KilledMonsterCredit(107242);
            }
        }
    }
};

struct npc_quest_107241 : public ScriptedAI
{
    npc_quest_107241(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void MoveInLineOfSight(Unit* Creature) override
    {
        if (Player* player = Creature->ToPlayer())
        {
            if ((player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE) && (player->HasAura(212754)))
            {
                if (player->GetDistance(me) < 20.0f)
                    player->KilledMonsterCredit(107241);
            }
        }
    }
};

struct npc_quest_107243 : public ScriptedAI
{
    npc_quest_107243(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void MoveInLineOfSight(Unit* Creature) override
    {
        if (Player* player = Creature->ToPlayer())
        {
            if ((player->GetQuestStatus(37660) == QUEST_STATUS_INCOMPLETE) && (player->HasAura(212754)))
            {
                if (player->GetDistance(me) < 20.0f)
                    player->KilledMonsterCredit(107243);
            }
        }
    }
};

// 119453
class npc_invasion_azsuna_acstris : public CreatureScript
{
public:
    npc_invasion_azsuna_acstris() : CreatureScript("npc_invasion_azsuna_acstris") { }

    struct npc_invasion_azsuna_acstrisAI : ScriptedAI
    {
        npc_invasion_azsuna_acstrisAI(Creature* creature) : ScriptedAI(creature)
        {
            ResummonAdds = true;
            TimerAdds = urand(1000, 3000);
        }

        EventMap events;
        bool ResummonAdds;
        uint32 TimerAdds;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            ResummonAdds = false;
            events.RescheduleEvent(1, 3000); // 234497
        }

        void JustDied(Unit* who) override
        {
           // if (Player* pl = me->FindNearestPlayer(50.0f))
            {
               // pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56893);
              //  pl->CreateConversation(4591);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (ResummonAdds)
            {
                if (TimerAdds <= diff)
                {
                    me->SummonCreature(119633, 1444.47f + irand(-2, 2), 6090.65f + irand(-2, 2), 480.33f);
                    TimerAdds = urand(1000, 3000);
                }
                else
                    TimerAdds -= diff;
            }
            if (me->HasUnitState(UNIT_STATE_STUNNED)) // need for this
                return;

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(234497);
                    events.RescheduleEvent(1, 3000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_acstrisAI(creature);
    }
};


// 119633
class npc_invasion_azsuna_bes : public CreatureScript
{
public:
    npc_invasion_azsuna_bes() : CreatureScript("npc_invasion_azsuna_bes") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_besAI(creature);
    }

    struct npc_invasion_azsuna_besAI : ScriptedAI
    {
        npc_invasion_azsuna_besAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            me->SetReactState(REACT_PASSIVE);
        }

        bool _introDone;

      /*  void IsSummonedBy(Unit* summoner) override
        {
           // SetFlyMode(true);
           // me->AddDelayedEvent(3000, [this]() -> void
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MovePoint(1, 1436.24f + irand(-2, 2), 6172.45f + irand(-2, 2), 1.71f);
                me->CastSpell(me, 237720);
           // });
        }*/

        void EnterCombat(Unit* who) override
        {
            _introDone = true;
            DoCast(237716);
            me->Kill(me);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 4.0f))
            {
                _introDone = true;
                DoCast(237716);
                me->Kill(me);
            }
        }

        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != POINT_MOTION_TYPE)
                return;

            if (pointId == 1)
            {
                _introDone = true;
                DoCast(237716);
                me->Kill(me);
            }
        }

    };
};
/*
// 119454 119483
class npc_invasion_azsuna_misc : public CreatureScript
{
public:
    npc_invasion_azsuna_misc() : CreatureScript("npc_invasion_azsuna_misc") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_miscAI(creature);
    }

    struct npc_invasion_azsuna_miscAI : ScriptedAI
    {
        npc_invasion_azsuna_miscAI(Creature* creature) : ScriptedAI(creature) {}

      /*  void OnSpellClick(Unit* clicker) //override
        {
            if (!clicker->IsPlayer())
                return;

            me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));

            uint32 criteria = 0;

            switch (me->GetEntry())
            {
            case 119483:
                criteria = 56889;
                break;
            case 119454:
                criteria = 56895;
                break;
            }
            if (criteria)
               // clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56889);
            me->DespawnOrUnsummon(10);

     //   }
   // };
};
*/
// 119456 119459
class npc_invasion_azsuna_dragons : public CreatureScript
{
public:
    npc_invasion_azsuna_dragons() : CreatureScript("npc_invasion_azsuna_dragons") {}

    struct npc_invasion_azsuna_dragonsAI : ScriptedAI
    {
        npc_invasion_azsuna_dragonsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
            _introDone = false;
        }

        bool _introDone;

        void Reset() override
        {
            me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
        }

       /* void OnSpellClick(Unit* clicker) //override
        {
            if (me->GetEntry() == 119459)
           //     clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56885);
          //  else
                clicker->CastSpell(me, 52391, true); //Ride Veh
        }
        */
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
           // SetFlyMode(true);
            if (who->IsPlayer())
            {
                me->GetMotionMaster()->MovePath(10993803, false);
             //   who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56891);
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone)
                if (InstanceScript *script = me->GetInstanceScript())
                  //  if (script->GetScenarionStep() == 1)
                        if (me->IsWithinDistInMap(who, 5.0f) && !who->IsOnVehicle())
                        {
                            _introDone = true;
                            who->ToPlayer()->CastSpell(me, 52391, true); //Ride Veh
                        }
        }

        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != WAYPOINT_MOTION_TYPE)
                return;

            if (me->GetVehicleKit())
            {
               // if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                {
                   // passenger->CreateConversation(4590);
                   // passenger->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56892);
                   // passenger->AddAura(55001, passenger);
                    //me->GetVehicleKit()->RemoveAllPassengers();
                    me->DespawnOrUnsummon(500);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_dragonsAI(creature);
    }
};

void AddSC_azsuna()
{
    new npc_invasion_azsuna_bes();
    //new npc_invasion_azsuna_misc();
    new npc_invasion_azsuna_dragons();
    new npc_invasion_azsuna_acstris();
    new scene_azsuna_runes();
    RegisterCreatureAI(questnpc_soul_gem);
    RegisterCreatureAI(questnpc_mana_drained_whelpling);
    new npc_prince_farondis();
    new npc_prince_farondis_escort();
    new spell_word_of_versatility();
    new go_sabotaged_portal_stabilizer();
    new spell_gen_radiant_ley_crystal();
    new npc_quest_43521();
    new npc_quest_43520();
    new npc_archmage_khadgar_93337();
    RegisterSpellScript(spell_rally_the_nightwatchers);
   // new ps_quest_rally_the_nightwatchers();
    new merayl_q42159("merayl_q42159");
    new npc_kimmruder_88911();
    new npc_summon_91155();
    RegisterCreatureAI(cedonu_107962);
    RegisterCreatureAI(kharmeera_107963);
    RegisterCreatureAI(emmigosa_107961);
    RegisterCreatureAI(berazus_107964);
    RegisterSpellScript(spell_Wand_Practice);
  //  new ps_quest_Wandering();
    new npc_senegosa_89978();
    new go_pylon_mana245572();
    new go_pylon_mana245573();
    new go_pylon_mana239959();
    new go_pylon_mana245574();
    new go_fel_power_run244706();
    RegisterSpellScript(spell_drop_stone);
    new npc_agapant_90543();
    new npc_lucid_strength_89939();
    RegisterCreatureAI(mana_drained_90880);
    RegisterCreatureAI(mana_drained_900880);
    RegisterCreatureAI(npc_quest_1970196);
    new npc_demon_86963();
    new npc_demon_90402();
    new npc_demon_89276();
    new go_soul_gem239338();
    new go_soul_gem239332();
    new go_soul_gem237017();
    new npc_demon_89673();
    RegisterCreatureAI(npc_quest_1970197);
    RegisterCreatureAI(npc_quest_107242);
    RegisterCreatureAI(npc_quest_107241);
    RegisterCreatureAI(npc_quest_107243);
}
