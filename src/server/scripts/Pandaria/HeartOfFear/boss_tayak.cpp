/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "Weather.h"

#include "heart_of_fear.h"

enum eTayakSpells
{
    SPELL_VISINTRO_TAYAK        = 128788,
    SPELL_TEMP_SLASH_AURA       = 122854,   // Visual + Periodic trigger aura for SPELL_TEMP_SLASH_DAMAGE.
    SPELL_TEMP_SLASH_DAMAGE     = 122853,   // Aura Damage + Knock back
    SPELL_WIND_STEP_B_DMG       = 123180,   // Bleed damage for 8y targets.
    SPELL_WIND_STEP_DUMMY       = 123459,   // Aura Dummy.
    SPELL_WIND_STEP_TP_BACK     = 123460,   // Teleport back to the main target.
    SPELL_INTENSIFY_NORMAL      = 123470,   // Add spell 123471 every 1 minute, phase 1
    SPELL_INTENSIFY_TORNADO     = 132254,   // Add spell 123471 every 10 secs, phase 2
    SPELL_BLADE_TEMPEST_AUR     = 125310,   // Triggers SPELL_BLADE_TEMPEST_DMG each 0.5s, SPELL_BLADE_TEMPEST_AT.
    SPELL_BLADE_TEMPES_J_FC     = 125325,   // Force Cast SPELL_BLADE_TEMPES_JUMP in 200 yards.
    SPELL_STORM_UNLEASHED_D     = 123814,   // Boss Dummy Visual.
    SPELL_SU_AURA               = 123598,   // Aura for the tornadoes, triggers SPELL_SU_RV_SE each 0.1 secs.
    SPELL_SU_RV                 = 123599,   // Control Vehicle aura.
    SPELL_SU_DUMMY_VIS          = 124024,   // Some dummy visual (for tornadoes?).
    SPELL_SU_DMG_AURA           = 124785,   // Triggers SPELL_SU_DMG every 1 sec.
    SPELL_SU_WIND_GALE          = 123633,
    SPELL_SU_DUMMY_CRAP         = 123616,   // Applies a dummy aura on a target.
    SPELL_TAYAK_BERSERK         = 26662,    // Enrage, 490 seconds, or 8:10 minutes.

    SPELL_LORD_TAYAK_BONUS      = 132195
};

enum Yells
{
    // Blade Lord Ta'yak
    SAY_AGGRO               = 0,    // On your guard, invaders. I, Ta'yak, Lord of Blades, will be your opponent.
    SAY_DEATH               = 1,    // I'd always hoped to cut someone like that someday, to hear that sound. But to have it happen to my own prothorax is ridiculous.
    SAY_KILL_TRASH          = 2,    // 0 - Mere initiates. ; 1 - They should have studied harder. ; 2 - One technique alone is not enough. ; 3 - They failed their test. Will you?
    SAY_INTRO               = 3,    // They approach? Good. Now, if only my students were here to see and learn from the coming display of martial prowess...
    SAY_SLAY                = 4,    // 0 - A perfect cut. ; 1 - This is the technique of a Blade Lord.
    SAY_STORM_UNLEASHED     = 5,    // Can you follow my blade?
    ANN_UNSEEN              = 6,    // Blade Lord Ta'yak marks $N for [Unseen Strike]!
    SAY_ENTER_ROOM          = 7,    // Now go, impart my techniques to the initiates.
};

enum Events
{
    // Blade Lord Ta'yak
    EVENT_TEMPEST_SLASH     = 1,    // 10 seconds from pull. Every 15.5 seconds.
    EVENT_UNSEEN_STRIKE,            // 30.5 seconds from pull. Every 53 - 61 seconds.
    EVENT_UNSEEN_STRIKE_RETURN,
    EVENT_TAYAK_WIND_STEP,          // 20.5 seconds from pull. Every 25 seconds.
    EVENT_WIND_STEP_RETURN,
    EVENT_OVERWHELMING_ASS,         // 15.5 seconds from pull. Every 20.5 seconds, delayable by up to 15 seconds.

    EVENT_BLADE_TEMPEST,            // Every 60 seconds. Heroic only.
    EVENT_TAYAK_BT_END,

    EVENT_STORM_UNLEASHED,          // 20%
    EVENT_SUMMON_TORNADOES,

    EVENT_TAYAK_BERSERK,            // Enrage at 8 minutes, or, more precisely, 490 seconds.
    EVENT_STORM_MOVE,
    EVENT_STORM_REMOVE
};

enum TayakPhases
{
    PHASE_NORMAL            = 1,
    PHASE_STORM_UNLEASHED   = 2
};

enum eTayakAdds
{
    NPC_US_TORNADO          = 63278,
    NPC_GALE_WINDS_STALKER  = 63292,
    NPC_SETTHIK_TEMPEST     = 64358
};

enum eTayakActions
{
    ACTION_WIND             = 1,
    ACTION_STOP_WIND        = 2,
    ACTION_TAYAK_BT_PULL    = 7
};

enum eTayakPhases
{
    PHASE_TAYAK1                    = 2,
    PHASE_TAYAK2                    = 3
};

enum eTayakTypes
{
    TYPE_STORM_POINT    = 3,
    TYPE_PHASE_TAYAK    = 4,
    TYPE_STORM_PHASE    = 5
};

Position TayakStormPoints[2] =
{
    { -2119.072f, 184.985f, 422.162f, 1.585f }, // 20 - 10% TP point
    { -2119.072f, 379.372f, 422.162f, 4.703f }  // 10 -  0% TP point
};

Position PlayerTelePos = { -2124.063f, 281.056f, 420.901f, 0.053f }; // Tele point for players on P2 start.

// StormPoint1 Tornado summon points.
Position const Tornado1[3] =
{
    { -2123.702f, 198.023f, 420.910f, 1.561f }, // Left
    { -2119.503f, 198.023f, 420.910f, 1.561f }, // Center
    { -2114.113f, 198.023f, 420.910f, 1.561f }, // Right
};

// StormPoint2 Tornado summon points.
Position const Tornado2[3] =
{
    { -2114.113f, 363.058f, 420.910f, 4.710f }, // Left
    { -2119.503f, 363.058f, 420.910f, 4.710f }, // Center
    { -2123.702f, 363.058f, 420.910f, 4.710f }, // Right
};

// Zorlok - 62980
class boss_tayak : public CreatureScript
{
    public:
        boss_tayak() : CreatureScript("boss_tayak") { }

        struct boss_tayakAI : public BossAI
        {
            boss_tayakAI(Creature* creature) : BossAI(creature, DATA_TAYAK), summons(me)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            SummonList summons;
            ObjectGuid unseenTank;
            ObjectGuid currentTank;
            bool entranceDone;
            bool introDone;
            bool storm1Done;
            bool unseenReturn;
            uint8 tpPlayers;    // 0 - Phase 1 | 1 - TP Players | 2 - Players have been TP
            uint8 Phase;
            std::list<ObjectGuid> playerGuids;

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();

                unseenTank  = ObjectGuid::Empty;
                currentTank = ObjectGuid::Empty;
                tpPlayers   = 0;
                storm1Done   = false;
                entranceDone = false;
                introDone    = false;
                unseenReturn = false;
                Phase = PHASE_NORMAL;
                playerGuids.clear();
                me->CastSpell(me, SPELL_VISINTRO_TAYAK, true);

                std::list<Creature*> stalkerList;
                GetCreatureListWithEntryInGrid(stalkerList, me, NPC_GALE_WINDS_STALKER, 300.0f);
                for (auto stalker : stalkerList)
                    stalker->AI()->DoAction(ACTION_STOP_WIND);

                me->SetVirtualItem(0, EQUIP_TAYAK_MELJARAK);

                _Reset();
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_TAYAK_TALK_TRASH:
                    {
                        Talk(SAY_KILL_TRASH);
                        break;
                    }
                    case ACTION_TAYAK_BT_PULL:
                    {
                        // Slowly pulling players back to Ta'yak
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, me, 200.0f);

                        Position pos = { me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f };

                        for (Player* player : playerList)
                        {
                            if (player->IsAlive() && !player->HasMovementForce(me->GetGUID()))
                                player->ApplyMovementForce(me->GetGUID(), 3.f, pos);
                        }

                        // Won't reach the event until 6-7 secs as Ta'yak has UNIT_STATE_CASTING
                        events.ScheduleEvent(EVENT_TAYAK_BT_END, 100);
                        break;
                    }
                    default:
                        break;
                }
            }

            bool CheckTrash()
            {
                // -- Trashs --
                Creature* GaleSlicer = GetClosestCreatureWithEntry(me, NPC_SETTHIK_GALESLICER, 100.0f, true);
                Creature* Silentwing = GetClosestCreatureWithEntry(me, NPC_KORTHIK_SILENTWING, 100.0f, true);
                Creature* Swarmer    = GetClosestCreatureWithEntry(me, NPC_KORTHIK_SWARMER,    100.0f, true);
                Creature* Tempest    = GetClosestCreatureWithEntry(me, NPC_SETTHIK_TEMPEST,    100.0f, true);

                // -- Instructors --
                Creature* Klithak    = GetClosestCreatureWithEntry(me, NPC_INSTRUCTOR_KLITHAK, 100.0f, true);
                Creature* Takthok    = GetClosestCreatureWithEntry(me, NPC_INSTRUCTOR_TAKTHOK, 100.0f, true);
                Creature* Maltik     = GetClosestCreatureWithEntry(me, NPC_INSTRUCTOR_MALTIK,  100.0f, true);
                Creature* Zarik      = GetClosestCreatureWithEntry(me, NPC_INSTRUCTOR_ZARIK,   100.0f, true);

                if (GaleSlicer || Silentwing || Swarmer || Tempest || Klithak || Takthok || Maltik || Zarik)
                    return false;

                return true;
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                /// P2 first part
                if (me->HealthBelowPctDamaged(20, p_Damage) && Phase == PHASE_NORMAL)
                {
                    // Set phase
                    Phase = PHASE_STORM_UNLEASHED;

                    // Intensify
                    me->RemoveAura(SPELL_INTENSIFY_NORMAL);
                    me->AddAura(SPELL_INTENSIFY_TORNADO, me);

                    Talk(SAY_STORM_UNLEASHED);

                    // Cancel the P1 events except intensify
                    events.CancelEvent(EVENT_TEMPEST_SLASH);
                    events.CancelEvent(EVENT_UNSEEN_STRIKE);
                    events.CancelEvent(EVENT_TAYAK_WIND_STEP);
                    events.CancelEvent(EVENT_OVERWHELMING_ASS);
                    if (IsHeroic())
                        events.CancelEvent(EVENT_BLADE_TEMPEST);

                    me->SetReactState(REACT_PASSIVE);

                    // Teleport players and move to P2 first point.
                    me->SetSpeed(MOVE_RUN, 20.0f);
                    me->SetSpeed(MOVE_WALK, 20.0f);
                    me->SetSpeed(MOVE_FLIGHT, 20.0f);
                    me->GetMotionMaster()->MovePoint(2, PlayerTelePos);

                    DoCast(me, SPELL_STORM_UNLEASHED_D);
                    me->AddAura(SPELL_SU_DMG_AURA, me);
                }

                // Storm Unleashed 10 - 0%.
                if (me->HealthBelowPctDamaged(10, p_Damage) && Phase == PHASE_STORM_UNLEASHED && !storm1Done)
                {
                    storm1Done = true;
                    ActivateGaleWinds();

                    Talk(SAY_STORM_UNLEASHED);

                    events.CancelEvent(EVENT_SUMMON_TORNADOES);

                    // Move to P2 second point.
                    me->SetSpeed(MOVE_RUN, 20.0f);
                    me->SetSpeed(MOVE_WALK, 20.0f);
                    me->SetSpeed(MOVE_FLIGHT, 20.0f);
                    me->GetMotionMaster()->MovePoint(3, TayakStormPoints[1]);
                }
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!entranceDone && me->IsWithinDistInMap(who, 50) && who->IsPlayer())
                {
                    Talk(SAY_ENTER_ROOM);
                    entranceDone = true;
                }

                if (entranceDone && !introDone && me->IsWithinDistInMap(who, 30) && who->IsPlayer() && CheckTrash())
                {
                    Talk(SAY_INTRO);
                    introDone = true;
                    me->RemoveAura(SPELL_VISINTRO_TAYAK);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (pInstance)
                {
                    if (pInstance->GetBossState(DATA_TAYAK) == IN_PROGRESS)
                        return;

                    if (!pInstance->CheckRequiredBosses(DATA_TAYAK) || !CheckTrash())
                    {
                        EnterEvadeMode(EVADE_REASON_OTHER);
                        return;
                    }

                    if (GameObject* entranceDoor = pInstance->GetGameObject(GOB_QUARTERS_DOOR_ENTRANCE))
                        entranceDoor->SetGoState(GO_STATE_READY);
                }

                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_TEMPEST_SLASH, urand(9500, 11000));
                events.ScheduleEvent(EVENT_UNSEEN_STRIKE, urand(29500, 31500));
                events.ScheduleEvent(EVENT_TAYAK_WIND_STEP, urand(19500, 21500));
                events.ScheduleEvent(EVENT_OVERWHELMING_ASS, urand(14500, 16500));
                //events.ScheduleEvent(EVENT_INTENSIFY, 60000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_BLADE_TEMPEST, 60000);

                me->AddAura(SPELL_INTENSIFY_NORMAL, me);

                // 8:15 minutes Enrage timer
                events.ScheduleEvent(EVENT_TAYAK_BERSERK, 495000);

                if (pInstance)
                {
                    pInstance->SetData(DATA_TAYAK, IN_PROGRESS);
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                }

                if (me->HasAura(SPELL_VISINTRO_TAYAK))
                    me->RemoveAura(SPELL_VISINTRO_TAYAK);

                //me->DisableEvadeMode();
                me->DisableHealthRegen();
                _EnterCombat();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->IsPlayer())
                    Talk(SAY_SLAY);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == TYPE_PHASE_TAYAK)
                    return Phase;
                else if (type == TYPE_STORM_PHASE)
                    return storm1Done ? 1 : 0;
                return 0;
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                if (!pInstance)
                    return;

                if (pInstance->GetBossState(DATA_TAYAK) != IN_PROGRESS)
                    return;

                me->RemoveAllAuras();
                Reset();
                me->DeleteThreatList();
                me->CombatStop(false);
                me->GetMotionMaster()->MoveTargetedHome();

                if (pInstance)
                {
                    pInstance->SetData(DATA_TAYAK, FAIL);
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove

                    if (GameObject* entranceDoor = pInstance->GetGameObject(GOB_QUARTERS_DOOR_ENTRANCE))
                        entranceDoor->SetGoState(GO_STATE_ACTIVE);
                }

                _EnterEvadeMode(EVADE_REASON_OTHER);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                events.Reset();
                me->RemoveAllAuras();

                if (pInstance)
                {
                    pInstance->SetData(DATA_TAYAK, DONE);
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove

                    if (GameObject* entranceDoor = pInstance->GetGameObject(GOB_QUARTERS_DOOR_ENTRANCE))
                        entranceDoor->SetGoState(GO_STATE_ACTIVE);
                }

                // Stop Wind Gales
                std::list<Creature*> windList;
                GetCreatureListWithEntryInGrid(windList, me, NPC_GALE_WINDS_STALKER, 300.0f);
                for (auto stalker : windList)
                    stalker->AI()->DoAction(ACTION_STOP_WIND);

                summons.DespawnAll();

                _JustDied();

                Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                {
                    if (Player* l_Player = l_Itr->GetSource())
                        me->CastSpell(l_Player, SPELL_LORD_TAYAK_BONUS, true);
                }

                /*if (me->GetMap()->IsLFR())
                {
                    me->SetLootRecipient(NULL);
                    Player* l_Player = me->GetMap()->GetPlayers().begin()->GetSource();
                    if (l_Player && l_Player->GetGroup())
                        sLFGMgr->AutomaticLootAssignation(me, l_Player->GetGroup());
                }*/
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                summon->setActive(true);

                if (me->IsInCombat())
                    summon->SetInCombatWithZone();
            }

            // Phase 2 player teleportation.
            void TeleportPlayers()
            {
                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* playr = i->GetSource())
                    {
                        if (playr->IsAlive())
                            playr->TeleportTo(me->GetMapId(), PlayerTelePos.GetPositionX(), PlayerTelePos.GetPositionY(), PlayerTelePos.GetPositionZ(), PlayerTelePos.GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);
                    }
                }
            }

            void ActivateGaleWinds()
            {
                std::list<Creature*> GWStalkersList;
                GetCreatureListWithEntryInGrid(GWStalkersList, me, NPC_GALE_WINDS_STALKER, 300.0f);

                /// Remove Gale Winds movement force (in case we're in the 10%-0% phase)
                Map::PlayerList const &l_PlayerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Itr = l_PlayerList.begin(); l_Itr != l_PlayerList.end(); ++l_Itr)
                {
                    if (Player* l_Player = l_Itr->GetSource())
                    {
                        for (Creature* stalker : GWStalkersList)
                            l_Player->RemoveMovementForce(stalker->GetGUID());
                    }
                }

                for (Creature* stalker : GWStalkersList)
                    stalker->AI()->DoAction(ACTION_WIND);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    // Coming to center of the room
                    case 2:
                    {
                        // Beginning of phase 2, Ta'yak at room's center
                        TeleportPlayers();
                        events.ScheduleEvent(EVENT_STORM_UNLEASHED, 100);

                        // Moving to the other side
                        me->SetSpeed(MOVE_RUN, 20.0f);
                        me->SetSpeed(MOVE_WALK, 20.0f);
                        me->SetSpeed(MOVE_FLIGHT, 20.0f);
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->Clear();
                        tpPlayers = 1;
                        break;
                    }
                    // Coming to an edge
                    case 3:
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->Clear();
                        events.ScheduleEvent(EVENT_SUMMON_TORNADOES, 1000);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                /*if (me->EvadeModeIsDisable() && pInstance && pInstance->IsWipe())
                {
                    me->ReenableEvadeMode();
                    me->ReenableHealthRegen();
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }*/

                if ((!UpdateVictim() && !unseenReturn) || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TEMPEST_SLASH:
                        {
                            DoCast(me, SPELL_TEMPEST_SLASH);
                            events.ScheduleEvent(EVENT_TEMPEST_SLASH, urand(14500, 16500));
                            break;
                        }
                        case EVENT_UNSEEN_STRIKE:
                        {
                            unseenTank = me->GetVictim() ? me->GetVictim()->GetGUID() : ObjectGuid::Empty;
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                Talk(ANN_UNSEEN, target);
                                me->CastSpell(target, SPELL_UNSEEN_STRIKE_TR, true);
                                me->AddAura(SPELL_UNSEEN_STRIKE_MKR, target);
                                me->GetMotionMaster()->MoveChase(target);
                                me->SetReactState(REACT_PASSIVE);
                                unseenReturn = true;
                            }
                            events.ScheduleEvent(EVENT_UNSEEN_STRIKE_RETURN, 5500);
                            events.ScheduleEvent(EVENT_UNSEEN_STRIKE, urand(53000, 61000));
                            break;
                        }
                        case EVENT_UNSEEN_STRIKE_RETURN:
                        {
                            if (!unseenTank.IsEmpty())
                            {
                                me->SetReactState(REACT_AGGRESSIVE);
                                if (Player* unseenTarget = ObjectAccessor::FindPlayer(unseenTank))
                                {
                                    if (unseenTarget->IsAlive())
                                        AttackStart(unseenTarget);
                                    else
                                        SetAggro();
                                }
                                else
                                    SetAggro();
                                unseenTank = ObjectGuid::Empty;
                            }
                            else
                                SetAggro();
                            break;
                        }
                        case EVENT_TAYAK_WIND_STEP:
                        {
                            // Store current victim to return to it afterwards
                            currentTank = me->GetVictim() ? me->GetVictim()->GetGUID() : ObjectGuid::Empty;
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 50.0f, true))
                                DoCast(target, SPELL_WIND_STEP_TP);
                            events.ScheduleEvent(EVENT_WIND_STEP_RETURN, 1000);
                            events.ScheduleEvent(EVENT_TAYAK_WIND_STEP, urand(24000, 26000));
                            break;
                        }
                        case EVENT_WIND_STEP_RETURN:
                        {
                            // Return to old target
                            if (Player* currentVictim = ObjectAccessor::FindPlayer(currentTank))
                            {
                                if (currentVictim->IsAlive())
                                    DoCast(currentVictim, SPELL_WIND_STEP_TP_BACK);
                                else
                                    SetAggro();
                                currentTank = ObjectGuid::Empty;
                            }
                            else
                                SetAggro();
                            break;
                        }
                        case EVENT_OVERWHELMING_ASS:
                        {
                            // On tank
                            DoCastVictim(SPELL_OVERWHELMING_ASS);
                            events.ScheduleEvent(EVENT_OVERWHELMING_ASS, urand(20500, 35500));
                            break;
                        }
                        // Heroic
                        case EVENT_BLADE_TEMPEST:
                        {
                            DoCast(me, SPELL_BLADE_TEMPEST_AUR);
                            DoCast(SPELL_BLADE_TEMPES_J_FC);
                            events.ScheduleEvent(EVENT_BLADE_TEMPEST, 60000);
                            break;
                        }
                        case EVENT_TAYAK_BT_END:
                        {
                            // Remove ForceMovement on players
                            std::list<Player*> playerList;
                            GetPlayerListInGrid(playerList, me, 200.0f);

                            Position pos = { me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f };

                            for (Player* player : playerList)
                            {
                                std::list<Creature*> GWStalkersList;
                                GetCreatureListWithEntryInGrid(GWStalkersList, me, NPC_GALE_WINDS_STALKER, 300.0f);
                                for (Creature* stalker : GWStalkersList)
                                    player->RemoveMovementForce(stalker->GetGUID());
                            }

                            break;
                        }
                        // Phase 2
                        case EVENT_STORM_UNLEASHED:
                        {
                            // Players have just been TP : now creating list of the players.
                            if (tpPlayers == 1)
                            {
                                std::list<Player*> playerList;
                                GetPlayerListInGrid(playerList, me, 10.0f);

                                // Working with GUID, not players directly
                                for (auto player : playerList)
                                    playerGuids.push_back(player->GetGUID());

                                // Scheduling creation of storms to bring players on the side
                                if (!playerGuids.empty())
                                {
                                    events.ScheduleEvent(EVENT_STORM_UNLEASHED, 100);
                                    me->GetMotionMaster()->MovePoint(3, TayakStormPoints[0]);
                                    tpPlayers = 2;
                                }
                                // No player : maybe they're not arrived from TP : we'll try to redo this part later
                                else
                                    events.ScheduleEvent(EVENT_STORM_UNLEASHED, 100);
                                // Nothing more to do for now
                                return;
                            }

                            if (playerGuids.empty())
                                break;

                            // Creating storm to bring each player to a side of the room
                            ObjectGuid plGuid = *playerGuids.begin();
                            if (ObjectAccessor::GetPlayer(*me, plGuid))
                                if (Creature* storm = me->SummonCreature(NPC_US_TORNADO, PlayerTelePos))
                                    storm->AI()->SetData(TYPE_STORM_POINT, 1);

                            playerGuids.remove(plGuid);

                            if (!playerGuids.empty())
                                events.ScheduleEvent(EVENT_STORM_UNLEASHED, 100);
                            else
                                ActivateGaleWinds();
                            break;
                        }
                        case EVENT_SUMMON_TORNADOES:
                        {
                            // Summon the tornado and increase the counter
                            uint32 choice = urand(0, 2);
                            if (Creature* storm = me->SummonCreature(NPC_US_TORNADO, !storm1Done ? Tornado1[choice] : Tornado2[choice]))
                                storm->AI()->SetData(TYPE_STORM_POINT, 3 * storm1Done + choice);

                            events.ScheduleEvent(EVENT_SUMMON_TORNADOES, 3000);
                            break;
                        }
                        case EVENT_TAYAK_BERSERK: // Nasty if you're here!
                        {
                            me->AddAura(SPELL_TAYAK_BERSERK, me);
                            break;
                        }
                        default:
                            break;
                    }
                }
                // No melee in P2
                if (Phase == PHASE_NORMAL)
                    DoMeleeAttackIfReady();
            }

            void SetAggro()
            {
                if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO))
                {
                    AttackStart(victim);
                    me->SetInCombatWith(victim);
                }
            }
        };

        BossAI* GetAI(Creature* creature) const override
        {
            return new boss_tayakAI(creature);
        }
};

// Heart of Fear - Armsmaster Ta'yak Tempest Stalker (LTD): 62908.
class npc_tempest_slash_tornado : public CreatureScript
{
    public:
        npc_tempest_slash_tornado() : CreatureScript("npc_tempest_slash_tornado") { }

        struct npc_tempest_slash_tornadoAI : public ScriptedAI
        {
            npc_tempest_slash_tornadoAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void IsSummonedBy(Unit* summoner) override
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);

                if (summoner)
                {
                    // Random orientation in front of Ta'yak
                    float ori = summoner->GetOrientation() + ((urand(0, 1) ? 1 : -1) * frand(float(M_PI)/3.f, float(M_PI) / 2.f));
                    me->SetOrientation(ori);
                    me->SetFacingTo(ori);

                    // Applying auras and moving
                    me->SetInCombatWithZone();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

                    me->AddAura(SPELL_TEMP_SLASH_AURA, me);     // Visual aura

                    events.ScheduleEvent(EVENT_STORM_MOVE, 500);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (!id || type != POINT_MOTION_TYPE)
                    return;

                float l_NewAngle = 0.0f;

                if (id == 7)
                    /// In circle loop : just change the orientation from 1/16 of circle (that is 2 * Pi / 16, so Pi / 8)
                    l_NewAngle = Position::NormalizeOrientation(me->GetOrientation() + M_PI / 8);

                if (id == 8)
                    /// New angle = turning right to start cirle, so if we consider orientation = 0.0f, new orientation is 3 Pi / 2
                    /// And we also add the orientation for the circle. As we have 16 points, the orientation change at each point
                    /// is (2 * Pi) / 16, so Pi / 8. And (3 Pi / 2) + (Pi / 8) = (12 Pi / 8) + (Pi / 8), so : 13 Pi / 8.
                    l_NewAngle = Position::NormalizeOrientation(me->GetOrientation() + 13 * M_PI / 8);

                me->SetOrientation(l_NewAngle);
                me->SetFacingTo(l_NewAngle);
                /// As we supposed our circle will have a radius of 2yd, its perimeter is about 2 * Pi * 2 = 12.566371, and as
                /// we have 16 points, there's about 12.566371 / 16 = 0.7854 yd between two points.
                float l_PosX = me->GetPositionX() + 0.7854f * cos(me->GetOrientation());
                float l_PosY = me->GetPositionY() + 0.7854f * sin(me->GetOrientation());
                me->GetMotionMaster()->MovePoint(7, l_PosX, l_PosY, me->GetPositionZ());
            }

            void UpdateAI(const uint32 diff) override
            {
                // Despawn on Ta'yak's phase 2
                if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                {
                    if (tayak->AI()->GetData(TYPE_PHASE_TAYAK) == PHASE_STORM_UNLEASHED)
                        me->DespawnOrUnsummon();
                }

                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_STORM_MOVE)
                {
                    float x, y, z;
                    me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, frand(5.0f, 30.0f));
                    me->GetMotionMaster()->MovePoint(8, x, y, z);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_tempest_slash_tornadoAI(creature);
        }
};

// Heart of Fear - Armsmaster Ta'yak - Storm Unleashed West 1 Tornado (LTD): 63278.
class npc_storm_unleashed_tornado : public CreatureScript
{
    public:
        npc_storm_unleashed_tornado() : CreatureScript("npc_storm_unleashed_tornado") { }

        struct npc_storm_unleashed_tornadoAI : public ScriptedAI
        {
            npc_storm_unleashed_tornadoAI(Creature* creature) : ScriptedAI(creature), vehicle(creature->GetVehicleKit())
            {
                ASSERT(vehicle);
                pInstance = creature->GetInstanceScript();
            }

            Vehicle* vehicle;
            InstanceScript* pInstance;
            EventMap m_Events;
            bool storm1;
            Position m_ReachPoint;

            void IsSummonedBy(Unit* /*p_Summoner*/) override
            {
                m_Events.Reset();
                storm1 = true;
                me->AddAura(SPELL_SU_DUMMY_VIS, me);    // Visual aura.
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                me->SetSpeed(MOVE_WALK, 1.1f);
                me->SetSpeed(MOVE_RUN, 1.1f);

                m_Events.ScheduleEvent(EVENT_STORM_REMOVE, 24000);
            }

            void Eject()
            {
                if (vehicle)
                {
                    int8 seat = 0;
                    do
                    {
                        if (Unit* passenger = vehicle->GetPassenger(seat))
                            passenger->ExitVehicle();

                        ++seat;

                    } while (seat < 8);
                }

                me->RemoveAura(SPELL_SU_AURA);
                me->RemoveAura(SPELL_SU_DUMMY_VIS);
                me->DespawnOrUnsummon();
            }

            void SetData(uint32 type, uint32 value) override
            {
                if (type == TYPE_STORM_POINT)
                {
                    storm1 = value < 3 ? true : false;
                    m_ReachPoint = (value < 3 ? Tornado2[2 - value] : Tornado1[5 - value]);

                    m_Events.ScheduleEvent(EVENT_STORM_MOVE, 500);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (!id || type != POINT_MOTION_TYPE)
                    return;

                Eject();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!pInstance)
                {
                    Eject();
                    return;
                }

                // Removing storm from the 1st storm phase (20-10%) when switching on 2nd storm phase (10-0%)
                if (storm1)
                {
                    if (pInstance)
                    {
                        if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        {
                            if (tayak->AI()->GetData(TYPE_STORM_PHASE) == 1)
                                Eject();
                        }
                    }
                }

                m_Events.Update(diff);

                uint32 m_EventId = m_Events.ExecuteEvent();
                if (m_EventId == EVENT_STORM_MOVE)
                {
                    me->AddAura(SPELL_SU_AURA, me);         // Control vehicle aura.
                    me->GetMotionMaster()->MovePoint(2, m_ReachPoint);
                }

                if (m_EventId == EVENT_STORM_REMOVE)
                    Eject();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_storm_unleashed_tornadoAI(creature);
        }
};

// Gale Winds Stalker - 63292
class mob_gale_winds_stalker : public CreatureScript
{
    public :
        mob_gale_winds_stalker() : CreatureScript("mob_gale_winds_stalker") { }

        struct mob_gale_winds_stalkerAI : public ScriptedAI
        {
            mob_gale_winds_stalkerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            bool firstWind;
            bool isActive;

            void Reset() override
            {
                isActive  = false;
                firstWind = false;
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_WIND:
                    {
                        if (me->HasAura(SPELL_SU_WIND_GALE))
                            me->RemoveAura(SPELL_SU_WIND_GALE);

                        if (pInstance)
                        {
                            if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                            {
                                bool firstPos = tayak->AI()->GetData(TYPE_STORM_PHASE) == 1 ? true : false;
                                if (me->GetOrientation() < 3 && !firstWind)
                                    firstWind = true;

                                if ((firstPos && firstWind) || (!firstPos && !firstWind))
                                {
                                    DoCast(SPELL_SU_WIND_GALE);
                                    tayak->CastSpell(me, SPELL_SU_DUMMY_CRAP, false);
                                    me->SetDisplayId(1126);
                                }
                                else
                                {
                                    if (me->HasAura(SPELL_SU_WIND_GALE))
                                        me->RemoveAura(SPELL_SU_WIND_GALE);
                                    me->SetDisplayId(11686);
                                }

                                if (!isActive)
                                    isActive = true;
                            }
                        }
                        break;
                    }
                    case ACTION_STOP_WIND:
                    {
                        if (me->HasAura(SPELL_SU_WIND_GALE))
                            me->RemoveAura(SPELL_SU_WIND_GALE);

                        if (pInstance)
                        {
                            if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                            {
                                Position pos = {tayak->GetPositionX(), tayak->GetPositionY(), tayak->GetPositionZ(), 0.0f};

                                std::list<Player*> playerList;
                                GetPlayerListInGrid(playerList, me, 200.0f);

                                for (Player* player : playerList)
                                    player->RemoveAllMovementForces();
                            }

                            isActive = false;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 /*p_Diff*/) override
            {
                // Check force
                if (!pInstance || !isActive)
                    return;

                if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                {
                    Position pos = { tayak->GetPositionX(), tayak->GetPositionY(), tayak->GetPositionZ(), 0.0f };

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 20.0f);

                    for (Player* player : playerList)
                    {
                        // if player is in wind gale
                        if (player->GetPositionX() > -2109.51f || player->GetPositionX() < -2129.05f)
                        {
                            // Player doesn't have forcedMovement
                            if (player->IsAlive() && !player->HasMovementForce(me->GetGUID()))
                                player->ApplyMovementForce(me->GetGUID(), -7.0f, pos);
                            // Dead player has forcedMovement
                            else if (!player->IsAlive())
                                player->RemoveAllMovementForces();
                        }
                        // player not in wind gale
                        else
                        {
                            player->RemoveAllMovementForces();
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_gale_winds_stalkerAI(creature);
        }
};

// 123175 - Wind Step
class spell_wind_step : public SpellScriptLoader
{
    public:
        spell_wind_step() : SpellScriptLoader("spell_wind_step") { }

        class spell_wind_stepSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wind_stepSpellScript);

            void Apply()
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, caster, 10.0f);

                    for (auto player : playerList)
                        caster->AddAura(SPELL_WIND_STEP_B_DMG, player);

                    caster->CastSpell(caster, SPELL_WIND_STEP_DUMMY, false);
                }
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_wind_stepSpellScript::Apply);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wind_stepSpellScript();
        }
};

// Wind Step: 123459
class spell_tayak_wind_step: public SpellScriptLoader
{
    public:
        spell_tayak_wind_step() : SpellScriptLoader("spell_tayak_wind_step") { }

        class spell_tayak_wind_stepAuraScript: public AuraScript
        {
            PrepareAuraScript(spell_tayak_wind_stepAuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->AddAura(SPELL_WIND_STEP_DUMMY, caster);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_tayak_wind_stepAuraScript::Apply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_tayak_wind_stepAuraScript();
        }
};

// 122982 - Unseen Strike
class spell_unseen_strike_aura : public SpellScriptLoader
{
    public:
        spell_unseen_strike_aura() : SpellScriptLoader("spell_unseen_strike") { }

        class spell_unseen_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_unseen_strike_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                    caster->AddAura(SPELL_UNSEEN_STRIKE_TR, target);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_unseen_strike_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_unseen_strike_SpellScript();
        }
};

// 122994 - Unseen Strike
class spell_unseen_strike_dmg : public SpellScriptLoader
{
    public :
        spell_unseen_strike_dmg() : SpellScriptLoader("spell_unseen_strike_dmg") { }

        class spell_unseen_strike_dmgSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_unseen_strike_dmgSpellScript);

            int32 numTargets;

            void CountTargets(std::list<WorldObject*>& targets)
            {
                numTargets = targets.size();
            }

            void DealDamages(SpellEffIndex effIndex)
            {
                if (numTargets)
                    SetHitDamage(GetSpellInfo()->GetEffect(effIndex)->BasePoints / numTargets);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_unseen_strike_dmgSpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnEffectHitTarget += SpellEffectFn(spell_unseen_strike_dmgSpellScript::DealDamages, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_unseen_strike_dmgSpellScript();
        }
};

// Storm Unleashed Ride Me: 124258.
class spell_tayak_storms_vehicle: public SpellScriptLoader
{
    public:
        spell_tayak_storms_vehicle() : SpellScriptLoader("spell_tayak_storms_vehicle") { }

        class spell_tayak_storms_vehicleSpellScript: public SpellScript
        {
            PrepareSpellScript(spell_tayak_storms_vehicleSpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.clear();

                // Find the nearest player in 100 yards, and that will be the target.
                WorldObject* target = GetCaster()->ToCreature()->SelectNearestPlayer(100.0f);

                if (!target->ToPlayer()->GetVehicle())
                    targets.push_back(target);
            }

            void EffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetCaster(), SPELL_SU_RV, true); // Enter the vehicle.
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tayak_storms_vehicleSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_tayak_storms_vehicleSpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_tayak_storms_vehicleSpellScript();
        }
};

// Storm Unleashed: 124783.
class spell_tayak_storm_unleashed_dmg: public SpellScriptLoader
{
    public:
        spell_tayak_storm_unleashed_dmg() : SpellScriptLoader("spell_tayak_storm_unleashed_dmg") { }

        class spell_tayak_storm_unleashed_dmgSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_tayak_storm_unleashed_dmgSpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.clear();

                if (Unit* caster = GetCaster())
                {
                    std::list<Player*> targetList;
                    GetPlayerListInGrid(targetList, caster, 300.0f);

                    for (auto player : targetList)
                        if (player->IsOnVehicle())
                            targets.push_back(player);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tayak_storm_unleashed_dmgSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_tayak_storm_unleashed_dmgSpellScript();
        }
};

// 122853 - Tempest Slash (damage aura)
class spell_tempest_slash : public SpellScriptLoader
{
    public :
        spell_tempest_slash() : SpellScriptLoader("spell_tempest_slash") { }

        class spell_tempest_slash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_tempest_slash_AuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->AddAura(SPELL_TEMP_SLASH_DAMAGE, caster);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_tempest_slash_AuraScript::Apply, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_tempest_slash_AuraScript();
        }
};

// 123814 - Storm unleashed - Boss visual effect
class spell_tayak_su_visual : public SpellScriptLoader
{
    public:
        spell_tayak_su_visual() : SpellScriptLoader("spell_tayak_su_visual") { }

        class spell_tayak_su_visualAuraScript : public AuraScript
        {
            PrepareAuraScript(spell_tayak_su_visualAuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->AddAura(SPELL_STORM_UNLEASHED_D, caster);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_tayak_su_visualAuraScript::Apply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_tayak_su_visualAuraScript();
        }
};

// 124024 - Storm unleashed dummy visual
class spell_su_dummy_visual : public SpellScriptLoader
{
    public:
        spell_su_dummy_visual() : SpellScriptLoader("spell_su_dummy_visual") { }

        class spell_su_dummy_visualAuraScript : public AuraScript
        {
            PrepareAuraScript(spell_su_dummy_visualAuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->AddAura(SPELL_SU_DUMMY_VIS, caster);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_su_dummy_visualAuraScript::Apply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_su_dummy_visualAuraScript();
        }
};

// 123633 - Gale Winds
class spell_gale_winds : public SpellScriptLoader
{
    public:
        spell_gale_winds() : SpellScriptLoader("spell_gale_winds") { }

        class spell_gale_windsAuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gale_windsAuraScript);

            void Apply(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                    caster->AddAura(SPELL_GALE_FORCE_WINDS, caster);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_gale_windsAuraScript::Apply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gale_windsAuraScript();
        }
};

/// 123600 - Storm unleashed
class spell_su_dummy : public SpellScriptLoader
{
    public:
        spell_su_dummy() : SpellScriptLoader("spell_su_dummy") { }

        class spell_su_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_su_dummy_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<Creature*> galeList;
                    GetCreatureListWithEntryInGrid(galeList, caster, NPC_GALE_WINDS_STALKER, 15.0f);
                    for (auto gale : galeList)
                        caster->AddAura(SPELL_SU_DUMMY_CRAP, gale);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_su_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_su_dummy_SpellScript();
        }
};

/// 123616 - Storm unleashed
class spell_su_dumaura : public SpellScriptLoader
{
    public:
        spell_su_dumaura() : SpellScriptLoader("spell_su_dumaura") { }

        class spell_su_dumaura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_su_dumaura_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, caster, 40.0f);

                    for (auto player : playerList)
                        caster->AddAura(SPELL_SU_DUMMY_CRAP, player);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_su_dumaura_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_su_dumaura_SpellScript();
        }
};

// 125310
class spell_blade_tempest : public SpellScriptLoader
{
    public:
        spell_blade_tempest() : SpellScriptLoader("spell_blade_tempest") { }

        class spell_blade_tempest_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blade_tempest_SpellScript);

            void PullRaid()
            {
                if (Unit* Tayak = GetCaster())
                {
                    if (Tayak->GetEntry() == NPC_TAYAK)
                        Tayak->GetAI()->DoAction(ACTION_TAYAK_BT_PULL);
                }
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_blade_tempest_SpellScript::PullRaid);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_blade_tempest_SpellScript();
        }
};

void AddSC_boss_tayak()
{
    new boss_tayak();                       // 62543
    new npc_tempest_slash_tornado();        // 62908
    new npc_storm_unleashed_tornado();      // 63278
    new mob_gale_winds_stalker();           // 63292
    new spell_wind_step();                  // 123175
    new spell_tayak_wind_step();            // 123459
    new spell_tayak_storms_vehicle();       // 124258
    new spell_tayak_storm_unleashed_dmg();  // 124783
    new spell_tempest_slash();              // 122853
    new spell_unseen_strike_aura();         // 122982
    new spell_unseen_strike_dmg();          // 122994
    new spell_tayak_su_visual();            // 123814
    new spell_su_dummy_visual();            // 124024
    new spell_gale_winds();                 // 123633
    new spell_su_dummy();                   // 123600
    new spell_su_dumaura();                 // 123616
    new spell_blade_tempest();              // 125310
}
