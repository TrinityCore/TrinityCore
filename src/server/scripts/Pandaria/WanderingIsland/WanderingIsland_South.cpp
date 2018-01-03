/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"

#define QUEST_A_NEW_FATE 29800
#define A_NEW_FATE_KILL_CREDIT 57741

class AreaTrigger_at_mandori : public AreaTriggerScript
{
    public:
        AreaTrigger_at_mandori() : AreaTriggerScript("AreaTrigger_at_mandori")
        {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
        {
            if (player->GetPositionX() < 710.0f)
                return true;

            if (player->GetQuestStatus(29792) != QUEST_STATUS_INCOMPLETE)
                return true;

            ObjectGuid playerGuid = player->GetGUID();

            Creature* Aysa = player->SummonCreature(59986, 698.04f, 3601.79f, 142.82f, 3.254830f, TEMPSUMMON_MANUAL_DESPAWN, 0, true); // Aysa
            Creature* Ji   = player->SummonCreature(59988, 698.06f, 3599.34f, 142.62f, 2.668790f, TEMPSUMMON_MANUAL_DESPAWN, 0, true); // Ji
            Creature* Jojo = player->SummonCreature(59989, 702.78f, 3603.58f, 142.01f, 3.433610f, TEMPSUMMON_MANUAL_DESPAWN, 0, true); // Jojo

            if (!Aysa || !Ji || !Jojo)
                return true;

            Aysa->AI()->SetGUID(playerGuid);
              Ji->AI()->SetGUID(playerGuid);
            Jojo->AI()->SetGUID(playerGuid);

            player->RemoveAurasDueToSpell(59073);
            player->RemoveAurasDueToSpell(59074);

            return true;
        }
};

class mob_mandori_escort : public CreatureScript
{
    public:
        mob_mandori_escort() : CreatureScript("mob_mandori_escort") { }

    struct mob_mandori_escortAI : public npc_escortAI
    {
        mob_mandori_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        enum escortEntry
        {
            NPC_AYSA    = 59986,
            NPC_JI      = 59988,
            NPC_JOJO    = 59989
        };

        uint32 IntroTimer;
        uint32 doorEventTimer;

        uint8  IntroState;
        uint8  doorEventState;

        ObjectGuid playerGuid;

        ObjectGuid mandoriDoorGuid;
        ObjectGuid peiwuDoorGuid;

        void Reset() override
        {
            IntroTimer      = 250;
            doorEventTimer  = 0;

            IntroState      = 0;
            doorEventState  = 0;

            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(ObjectGuid guid, int32 /*type*/) override
        {
            playerGuid = guid;

            if (!Is(NPC_AYSA))
                return;

            if (GameObject* mandoriDoor = me->SummonGameObject(211294, 695.26f, 3600.99f, 142.38f, 3.04f, QuaternionData(), 0))
                mandoriDoorGuid = mandoriDoor->GetGUID();

            if (GameObject* peiwuDoor = me->SummonGameObject(211298, 566.52f, 3583.46f, 92.16f, 3.14f, QuaternionData(), 0))
                peiwuDoorGuid = peiwuDoor->GetGUID();
        }

        bool Is(uint32 npc_entry)
        {
            return me->GetEntry() == npc_entry;
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 5:
                    SetEscortPaused(true);

                    // Jojo reach the waypoint 1 sec after the others
                    if (!Is(NPC_JOJO))
                        doorEventTimer = 2000;
                    else
                        doorEventTimer = 1000;
                    break;
                default:
                    break;
            }
        }

        void LastWaypointReached() override
        {
            if (Is(NPC_JI))
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                    player->AddAura(68482, player); // Phase 8192

            if (Is(NPC_AYSA))
            {
                if (GameObject* mandoriDoor = me->GetMap()->GetGameObject(mandoriDoorGuid))
                    mandoriDoor->Delete();
                if (GameObject* peiwuDoor = me->GetMap()->GetGameObject(peiwuDoorGuid))
                    peiwuDoor->Delete();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    switch (++IntroState)
                    {
                        case 1:
                            if (Is(NPC_AYSA))
                                me->Yell("Let's go !", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            IntroTimer = 1000;
                            break;
                        case 2:
                            if (Is(NPC_AYSA))
                            {
                                if (GameObject* mandoriDoor = me->GetMap()->GetGameObject(mandoriDoorGuid))
                                    mandoriDoor->SetGoState(GO_STATE_ACTIVE);

                                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                                    player->KilledMonsterCredit(59946);
                            }
                            IntroTimer = 1000;
                            break;
                        case 3:
                            Start(false, true);
                            IntroTimer = 0;
                            break;
                    }
                }
                else
                    IntroTimer -= diff;
            }

            if (doorEventTimer)
            {
                if (doorEventTimer <= diff)
                {
                    switch (++doorEventState)
                    {
                        case 1:
                            if (Is(NPC_AYSA))
                                me->Say("The door is blocked!", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            doorEventTimer = 2500;
                            break;
                        case 2:
                            if (Is(NPC_JI))
                                me->Say("They blocked it with a rock on the other side, I can't open it!", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            doorEventTimer = 4000;
                            break;
                        case 3:
                            if (Is(NPC_JOJO))
                                me->GetMotionMaster()->MoveCharge(567.99f, 3583.41f, 94.74f);
                            doorEventTimer = 150;
                            break;
                        case 4:
                            if (Is(NPC_AYSA))
                                if (GameObject* peiwuDoor = me->GetMap()->GetGameObject(peiwuDoorGuid))
                                    peiwuDoor->SetGoState(GO_STATE_ACTIVE);
                            doorEventTimer = 2000;
                            break;
                       case 5:
                            if (Is(NPC_AYSA))
                            {
                                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                                {
                                    me->Say("Well done, Jojo!", LANG_UNIVERSAL, player);
                                    player->KilledMonsterCredit(59947);
                                }
                            }
                           if (!Is(NPC_JOJO))
                               SetEscortPaused(false);
                            doorEventTimer = 2000;
                            break;
                       case 6:
                           if (Is(NPC_JOJO))
                               SetEscortPaused(false);
                            doorEventTimer = 0;
                            break;
                    }
                }
                else
                    doorEventTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_mandori_escortAI(creature);
    }
};

class npc_korga : public CreatureScript
{
    public:
        npc_korga() : CreatureScript("npc_korga") { }

        bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == 30589) // Détruire l'épave
                if (Creature* jiEscort = player->SummonCreature(60900, 424.71f, 3635.59f, 92.70f, 2.498430f, TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                    jiEscort->AI()->SetGUID(player->GetGUID());

            return true;
        }
};

class mob_ji_forest_escort : public CreatureScript
{
public:
    mob_ji_forest_escort() : CreatureScript("mob_ji_forest_escort") { }

    struct mob_ji_forest_escortAI : public npc_escortAI
    {
        mob_ji_forest_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        ObjectGuid playerGuid;

        uint32 IntroTimer;

        void Reset() override
        {
            IntroTimer      = 100;
        }

        void SetGUID(ObjectGuid guid, int32 /*type*/) override
        {
            playerGuid = guid;
        }

        void WaypointReached(uint32 /*waypointId*/) override
        {}

        void LastWaypointReached() override
        {
            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                player->AddAura(68483, player); // Phase 16384
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_ji_forest_escortAI(creature);
    }

};

class AreaTrigger_at_rescue_soldiers : public AreaTriggerScript
{
    public:
        AreaTrigger_at_rescue_soldiers() : AreaTriggerScript("AreaTrigger_at_rescue_soldiers")
        {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
        {
           if (player->GetQuestStatus(29794) != QUEST_STATUS_INCOMPLETE)
               return true;

           if (!player->HasAura(129340))
               return true;

           player->RemoveAurasDueToSpell(129340);
           player->KilledMonsterCredit(55999);

            return true;
        }
};

class npc_hurted_soldier : public CreatureScript
{
public:
    npc_hurted_soldier() : CreatureScript("npc_hurted_soldier") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hurted_soldierAI (creature);
    }

    struct npc_hurted_soldierAI : public ScriptedAI
    {
        npc_hurted_soldierAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 checkSavedTimer;
        bool HasBeenSaved;

        void Reset() override
        {
            checkSavedTimer = 2500;
            HasBeenSaved = false;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* Clicker, bool& /*result*/) override
        {
            me->RemoveAurasDueToSpell(130966); // Feign Death
            me->EnterVehicle(Clicker);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            HasBeenSaved = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (checkSavedTimer)
            {
                if (checkSavedTimer <= diff)
                {
                    if (HasBeenSaved && !me->GetVehicle())
                    {
                        me->Say("Thanks you, i'll never forget that.", LANG_UNIVERSAL, 0);
                        me->DespawnOrUnsummon(5000);
                        checkSavedTimer = 0;
                    }
                    else
                        checkSavedTimer = 2500;
                }
                else
                    checkSavedTimer -= diff;
            }
        }
    };
};

class boss_vordraka : public CreatureScript
{
    public:
        boss_vordraka() : CreatureScript("boss_vordraka") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_vordrakaAI(creature);
        }

        struct boss_vordrakaAI : public ScriptedAI
        {
            boss_vordrakaAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_Events;

            enum eDatas
            {
                QUEST_ANCIEN_MAL        = 29798,

                EVENT_DEEP_ATTACK       = 1,
                EVENT_DEEP_SEA_RUPTURE  = 2,

                SPELL_DEEP_ATTACK       = 117287,
                SPELL_DEEP_SEA_RUPTURE  = 117456,
            };

            void Reset() override
            {
                m_Events.Reset();
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                m_Events.ScheduleEvent(EVENT_DEEP_ATTACK, 6000);
                m_Events.ScheduleEvent(SPELL_DEEP_SEA_RUPTURE, 10000);
            }

            void JustDied(Unit* p_Attacker) override
            {
                if (p_Attacker->GetTypeId() != TYPEID_PLAYER)
                    return;

                std::list<Player*> l_PlayerList;
                GetPlayerListInGrid(l_PlayerList, me, 5.0f);

                for (Player* l_Player : l_PlayerList)
                {
                    if (l_Player->ToPlayer()->GetQuestStatus(QUEST_ANCIEN_MAL) == QUEST_STATUS_INCOMPLETE)
                        l_Player->ToPlayer()->KilledMonsterCredit(me->GetEntry());
                }
            }

            void UpdateAI(uint32 diff) override
            {
                m_Events.Update(diff);

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case EVENT_DEEP_ATTACK:
                    {
                        if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(l_Target, SPELL_DEEP_ATTACK, false);

                        m_Events.ScheduleEvent(EVENT_DEEP_ATTACK, 20000);
                        break;
                    }
                    case EVENT_DEEP_SEA_RUPTURE:
                    {
                        if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(l_Target, SPELL_DEEP_SEA_RUPTURE, false);

                        m_Events.ScheduleEvent(EVENT_DEEP_SEA_RUPTURE, 20000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class mob_aysa_gunship_crash : public CreatureScript
{
    public:
        mob_aysa_gunship_crash() : CreatureScript("mob_aysa_gunship_crash") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
        {
            if (quest->GetQuestId() == 30767) // Tout risquer
                if (Creature* aysa = player->SummonCreature(60729, creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                    aysa->AI()->SetGUID(player->GetGUID());

            return true;
        }

        struct mob_aysa_gunship_crashAI : public ScriptedAI
        {
            mob_aysa_gunship_crashAI(Creature* creature) : ScriptedAI(creature)
            {}

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (HealthBelowPct(70))
                    damage = 0;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_aysa_gunship_crashAI(creature);
        }
};

class mob_aysa_gunship_crash_escort : public CreatureScript
{
public:
    mob_aysa_gunship_crash_escort() : CreatureScript("mob_aysa_gunship_crash_escort") { }

    struct mob_aysa_gunship_crash_escortAI : public npc_escortAI
    {
        mob_aysa_gunship_crash_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        ObjectGuid playerGuid;
        ObjectGuid jiGuid;
        ObjectGuid fireGuid;

        uint32 IntroTimer;
        uint32 discussTimer;

        uint8  discussEvent;

        void Reset() override
        {
            IntroTimer      = 100;
            discussTimer    = 0;

            discussEvent    = 0;
        }

        void SetGUID(ObjectGuid guid, int32 /*type*/) override
        {
            playerGuid = guid;

            if (Creature* ji = me->SummonCreature(60741, 230.31f, 4006.67f, 87.27f, 3.38f, TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                jiGuid = ji->GetGUID();

            if (GameObject* gob = me->SummonGameObject(215344, 227.75f, 4006.38f, 87.06f, 0.0f, QuaternionData(), 0))
                fireGuid = gob->GetGUID();
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 8)
            {
                SetEscortPaused(true);
                discussTimer = 1000;
            }
        }

        Creature* getJi()
        {
            return me->GetMap()->GetCreature(jiGuid);
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            if (discussTimer)
            {
                if (discussTimer <= diff)
                {
                    switch (++discussEvent)
                    {
                        case 1:
                            me->Say("Ji, what are you doing ?! You can't do that !", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            if (Creature* ji = getJi())
                                ji->SetFacingToObject(me);
                            discussTimer = 3000;
                            break;
                        case 2:
                            if (Creature* ji = getJi())
                                ji->Say("We have no choice Aysa.", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            discussTimer = 3000;
                            break;
                        case 3:
                            me->Say("You are going to kill him !", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            discussTimer = 3000;
                            break;
                        case 4:
                            if (Creature* ji = getJi())
                                ji->Say("In our situation, inaction would be the greatest danger.", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            discussTimer = 3000;
                            break;
                        case 5:
                            me->Say("I hope you know what you're doing, Ji...", LANG_UNIVERSAL, ObjectAccessor::FindPlayer(playerGuid));
                            discussTimer = 5000;
                            break;
                        case 6:
                            SetEscortPaused(false);

                            if (Creature* ji = getJi())
                                ji->GetMotionMaster()->MovePoint(0, 227.21f, 3981.09f, 85.92f);

                            discussTimer = 1000;
                            break;
                        case 7:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                            {
                                player->KilledMonsterCredit(60727);
                                player->SendMovieStart(117);
                            }
                            discussTimer = 500;
                            break;
                        case 8:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                                player->NearTeleportTo(249.38f, 3939.55f, 65.61f, 1.501471f);

                            if (Creature* ji = getJi())
                                ji->DespawnOrUnsummon();

                            if (GameObject* gob = me->GetMap()->GetGameObject(fireGuid))
                                gob->Delete();

                            discussTimer = 0;
                            break;
                    }
                }
                else
                    discussTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_aysa_gunship_crash_escortAI(creature);
    }

};

#define MAX_ENNEMIES_POS   2
#define MAX_HEALER_COUNT   12
#define UPDATE_POWER_TIMER 3000

Position ennemiesPositions[MAX_ENNEMIES_POS] =
{
    {215.0f, 3951.0f, 71.4f},
    {290.0f, 3939.0f, 86.7f}
};

enum eEnums
{
    QUEST_HEALING_SHEN      = 29799,

    NPC_HEALER_A            = 60878,
    NPC_HEALER_H            = 60896,
    NPC_ENNEMY              = 60858,

    NPC_SHEN_HEAL_CREDIT    = 56011,

    EVENT_CHECK_PLAYERS     = 1,
    EVENT_UPDATE_POWER      = 2,
    EVENT_SUMMON_ENNEMY     = 3,
    EVENT_SUMMON_HEALER     = 4,

    SPELL_SHEN_HEALING      = 117783,
    SPELL_HEALER_A          = 117784,
    SPELL_HEALER_H          = 117932,
};

class npc_ji_end_event : public CreatureScript
{
public:
    npc_ji_end_event() : CreatureScript("npc_ji_end_event") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ji_end_eventAI(creature);
    }

    struct npc_ji_end_eventAI : public ScriptedAI
    {
        npc_ji_end_eventAI(Creature* creature) : ScriptedAI(creature), _summons(creature)
        {}

        EventMap   _events;
        SummonList _summons;

        bool       inProgress;
        uint8      healerCount;
        uint8      ennemiesCount;
        uint16     actualPower;

        void Reset() override
        {
            _summons.DespawnAll();

            healerCount   = 0;
            ennemiesCount = 0;
            actualPower   = 0;

            inProgress = false;

            _events.Reset();
            _events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
        }

        bool CheckPlayers()
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 100.0f);

            for (auto player : playerList)
                if (player->GetQuestStatus(QUEST_HEALING_SHEN) == QUEST_STATUS_INCOMPLETE)
                    if (player->IsAlive())
                        return true;

            return false;
        }

        void UpdatePower()
        {
            actualPower = (actualPower + healerCount <= 700) ? actualPower + healerCount: 700;

            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 100.0f);

            for (auto player : playerList)
            {
                if (player->GetQuestStatus(QUEST_HEALING_SHEN) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsAlive())
                    {
                        if (actualPower < 700) // IN_PROGRESS
                        {
                            if (!player->HasAura(SPELL_SHEN_HEALING))
                                player->CastSpell(player, SPELL_SHEN_HEALING, true);

                            player->SetPower(POWER_ALTERNATE_POWER, actualPower);
                        }
                        else
                        {
                            if (player->HasAura(SPELL_SHEN_HEALING))
                                player->RemoveAurasDueToSpell(SPELL_SHEN_HEALING);

                            player->KilledMonsterCredit(NPC_SHEN_HEAL_CREDIT);
                        }
                    }
                }
            }

            if (actualPower >= 700)
                Reset();
        }

        void SummonEnnemy()
        {
            uint8 pos = rand() % MAX_ENNEMIES_POS;
            float posJumpX = frand(228.0f, 270.0f);
            float posJumpY = frand(3949.0f, 3962.0f);

            if (Creature* ennemy = me->SummonCreature(NPC_ENNEMY, ennemiesPositions[pos].GetPositionX(), ennemiesPositions[pos].GetPositionY(), ennemiesPositions[pos].GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN))
                ennemy->GetMotionMaster()->MoveJump(Position(posJumpX, posJumpY, me->GetMap()->GetHeight(me->GetPhases(), posJumpX, posJumpY, 100.0f)), 20.0f, 20.0f);
        }

        void SummonHealer()
        {
            uint32 entry = (rand() % 2) ? NPC_HEALER_A : NPC_HEALER_H;
            float posX = frand(228.0f, 270.0f);
            float posY = frand(3949.0f, 3962.0f);

            me->SummonCreature(entry, posX, posY, me->GetMap()->GetHeight(me->GetPhases(), posX, posY, 100.0f), 1.37f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);

            switch (summon->GetEntry())
            {
                case NPC_HEALER_A:
                case NPC_HEALER_H:
                    ++healerCount;
                    break;
                case NPC_ENNEMY:
                    ++ennemiesCount;
                    break;
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            _summons.Despawn(summon);

            switch (summon->GetEntry())
            {
                case NPC_HEALER_A:
                case NPC_HEALER_H:
                    --healerCount;
                    break;
                case NPC_ENNEMY:
                    --ennemiesCount;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
                case EVENT_CHECK_PLAYERS:
                {
                    bool playerNearWithQuest = CheckPlayers();

                    if (inProgress && !playerNearWithQuest)
                    {
                        inProgress = false;
                        Reset();
                    }
                    else if (!inProgress && playerNearWithQuest)
                    {
                        inProgress = true;
                        _events.ScheduleEvent(EVENT_UPDATE_POWER,  UPDATE_POWER_TIMER);
                        _events.ScheduleEvent(EVENT_SUMMON_ENNEMY, 5000);
                        _events.ScheduleEvent(EVENT_SUMMON_HEALER, 5000);
                    }
                    _events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                    break;
                }
                case EVENT_UPDATE_POWER:
                    UpdatePower();
                    _events.ScheduleEvent(EVENT_UPDATE_POWER, UPDATE_POWER_TIMER);
                    break;
                case EVENT_SUMMON_ENNEMY:
                    if (ennemiesCount < (healerCount / 2))
                    {
                        SummonEnnemy();
                        _events.ScheduleEvent(EVENT_SUMMON_ENNEMY, 5000);
                    }
                    else
                        _events.ScheduleEvent(EVENT_SUMMON_ENNEMY, 7500);
                    break;
                case EVENT_SUMMON_HEALER:
                    if (healerCount < MAX_HEALER_COUNT)
                        SummonHealer();

                    _events.ScheduleEvent(EVENT_SUMMON_HEALER, 12500);
                    break;
            }
        }
    };
};

class npc_shen_healer : public CreatureScript
{
    public:
        npc_shen_healer() : CreatureScript("npc_shen_healer") { }

        struct npc_shen_healerAI : public ScriptedAI
        {
            npc_shen_healerAI(Creature* creature) : ScriptedAI(creature)
            {}

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, me->GetEntry() == NPC_HEALER_A ? SPELL_HEALER_A: SPELL_HEALER_H, true);
            }

            void EnterCombat(Unit*) override
            {
                return;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shen_healerAI(creature);
        }
};

#define GOSSIP_CHOOSE_FACTION     "I'm ready to choose my destiny."
#define GOSSIP_TP_STORMIND        "I would like to go to Stormwind"
#define GOSSIP_TP_ORGRI           "I would like to go to Orgrimmar"

class npc_shang_xi_choose_faction : public CreatureScript
{
    public:
        npc_shang_xi_choose_faction() : CreatureScript("npc_shang_xi_choose_faction") { }

        bool OnGossipHello(Player* p_Player, Creature* p_Creature) override
        {
            if (p_Creature->IsQuestGiver())
                p_Player->PrepareQuestMenu(p_Creature->GetGUID());

            if (p_Player->getRace() == RACE_PANDAREN_NEUTRAL)
            {
                if (p_Player->GetQuestStatus(31450) == QUEST_STATUS_INCOMPLETE)
                {
                    p_Player->KilledMonsterCredit(57741);
                    AddGossipItemFor(p_Player, GOSSIP_ICON_CHAT, GOSSIP_CHOOSE_FACTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                }
            }
            else if (p_Player->getRace() == RACE_PANDAREN_ALLIANCE)
                AddGossipItemFor(p_Player, GOSSIP_ICON_CHAT, GOSSIP_TP_STORMIND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            else if (p_Player->getRace() == RACE_PANDAREN_HORDE)
                AddGossipItemFor(p_Player, GOSSIP_ICON_CHAT, GOSSIP_TP_ORGRI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

            p_Player->PlayerTalkClass->SendGossipMenu(1, p_Creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
        {
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
                player->ShowNeutralPlayerFactionSelectUI();
            else if (action == GOSSIP_ACTION_INFO_DEF + 2)
                player->TeleportTo(0, -8866.55f, 671.93f, 97.90f, 5.31f);
            else if (action == GOSSIP_ACTION_INFO_DEF + 3)
                player->TeleportTo(1, 1577.30f, -4453.64f, 15.68f, 1.84f);

            player->PlayerTalkClass->SendCloseGossip();
            return true;
        }

        struct npc_shang_xi_choose_factionAI : public ScriptedAI
        {
            npc_shang_xi_choose_factionAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 l_CheckPlayerTimer;

            void Reset() override
            {
                l_CheckPlayerTimer = 1000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (l_CheckPlayerTimer)
                {
                    if (l_CheckPlayerTimer <= diff)
                    {
                        std::list<Player*> l_PlayerList;
                        GetPlayerListInGrid(l_PlayerList, me, 20.0f);

                        for (Player* l_Plr : l_PlayerList)
                        {
                            if (l_Plr->GetQuestStatus(QUEST_A_NEW_FATE) == QUEST_STATUS_INCOMPLETE)
                                l_Plr->KilledMonsterCredit(A_NEW_FATE_KILL_CREDIT);
                        }

                        l_CheckPlayerTimer = 1000;
                    }
                    else
                        l_CheckPlayerTimer -= diff;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shang_xi_choose_factionAI(creature);
        }
};

void AddSC_WanderingIsland_South()
{
    new AreaTrigger_at_mandori();
    new mob_mandori_escort();
    new npc_korga();
    new mob_ji_forest_escort();
    new AreaTrigger_at_rescue_soldiers();
    new npc_hurted_soldier();
    new boss_vordraka();
    new mob_aysa_gunship_crash();
    new mob_aysa_gunship_crash_escort();
    new npc_ji_end_event();
    new npc_shen_healer();
    new npc_shang_xi_choose_faction();
}
