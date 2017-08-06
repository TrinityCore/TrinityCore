/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Desolace
SD%Complete: 100
SDComment: Quest support: 5561
SDCategory: Desolace
EndScriptData */

/* ContentData
npc_aged_dying_ancient_kodo
go_iruxos
npc_dalinda_malem
go_demon_portal
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"

enum DyingKodo
{
    SAY_SMEED_HOME                  = 0,

    QUEST_KODO                      = 5561,

    NPC_SMEED                       = 11596,
    NPC_AGED_KODO                   = 4700,
    NPC_DYING_KODO                  = 4701,
    NPC_ANCIENT_KODO                = 4702,
    NPC_TAMED_KODO                  = 11627,

    SPELL_KODO_KOMBO_ITEM           = 18153,
    SPELL_KODO_KOMBO_PLAYER_BUFF    = 18172,
    SPELL_KODO_KOMBO_DESPAWN_BUFF   = 18377,
    SPELL_KODO_KOMBO_GOSSIP         = 18362

};

class npc_aged_dying_ancient_kodo : public CreatureScript
{
public:
    npc_aged_dying_ancient_kodo() : CreatureScript("npc_aged_dying_ancient_kodo") { }

    struct npc_aged_dying_ancient_kodoAI : public ScriptedAI
    {
        npc_aged_dying_ancient_kodoAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetEntry() == NPC_SMEED && me->IsWithinDistInMap(who, 10.0f) && !me->HasAura(SPELL_KODO_KOMBO_GOSSIP))
            {
                me->GetMotionMaster()->Clear();
                DoCast(me, SPELL_KODO_KOMBO_GOSSIP, true);
                if (Creature* smeed = who->ToCreature())
                    smeed->AI()->Talk(SAY_SMEED_HOME);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_KODO_KOMBO_ITEM)
            {
                if (!(caster->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) || me->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
                    && (me->GetEntry() == NPC_AGED_KODO || me->GetEntry() == NPC_DYING_KODO || me->GetEntry() == NPC_ANCIENT_KODO))
                {
                    caster->CastSpell(caster, SPELL_KODO_KOMBO_PLAYER_BUFF, true);
                    DoCast(me, SPELL_KODO_KOMBO_DESPAWN_BUFF, true);

                    me->UpdateEntry(NPC_TAMED_KODO);
                    me->CombatStop();
                    me->GetThreatManager().ClearAllThreat();
                    me->SetSpeedRate(MOVE_RUN, 0.6f);
                    me->GetMotionMaster()->MoveFollow(caster, PET_FOLLOW_DIST, me->GetFollowAngle());
                    me->setActive(true);
                }
            }
            else if (spell->Id == SPELL_KODO_KOMBO_GOSSIP)
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                me->setActive(false);
                me->DespawnOrUnsummon(60000);
            }
        }

        bool GossipHello(Player* player) override
        {
            if (player->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) && me->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
            {
                player->TalkedToCreature(me->GetEntry(), ObjectGuid::Empty);
                player->RemoveAurasDueToSpell(SPELL_KODO_KOMBO_PLAYER_BUFF);
            }

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aged_dying_ancient_kodoAI(creature);
    }

};

/*######
## go_iruxos
## Hand of Iruxos
######*/

enum Iruxos
{
    QUEST_HAND_IRUXOS   = 5381,
    NPC_DEMON_SPIRIT    = 11876
};

class go_iruxos : public GameObjectScript
{
    public:
        go_iruxos() : GameObjectScript("go_iruxos") { }

        struct go_iruxosAI : public GameObjectAI
        {
            go_iruxosAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player) override
            {
                if (player->GetQuestStatus(QUEST_HAND_IRUXOS) == QUEST_STATUS_INCOMPLETE && !me->FindNearestCreature(NPC_DEMON_SPIRIT, 25.0f, true))
                    player->SummonCreature(NPC_DEMON_SPIRIT, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);

                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_iruxosAI(go);
        }
};

/*######
## npc_dalinda_malem. Quest 1440
######*/

enum Dalinda
{
    QUEST_RETURN_TO_VAHLARRIEL      = 1440
};

class npc_dalinda : public CreatureScript
{
public:
    npc_dalinda() : CreatureScript("npc_dalinda") { }

    struct npc_dalindaAI : public npc_escortAI
    {
        npc_dalindaAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override { }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_RETURN_TO_VAHLARRIEL);
            return;
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();

            switch (waypointId)
            {
                case 1:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    break;
                case 15:
                    if (player)
                        player->GroupEventHappens(QUEST_RETURN_TO_VAHLARRIEL, me);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_RETURN_TO_VAHLARRIEL)
            {
                Start(true, false, player->GetGUID());
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dalindaAI(creature);
    }
};

/*######
## npc_cork_gizelton
######*/

enum Caravan
{
    QUEST_BODYGUARD_FOR_HIRE = 5821,
    QUEST_GIZELTON_CARAVAN = 5943,

    EVENT_RESUME_PATH = 1,
    EVENT_WAIT_FOR_ASSIST = 2,
    EVENT_START_ESCORT = 3,

    NPC_CORK_GIZELTON = 11625,
    NPC_RIGGER_GIZELTON = 11626,
    NPC_CARAVAN_KODO = 11564,
    NPC_VENDOR_TRON = 12245,
    NPC_SUPER_SELLER = 12246,

    // For both Cork and Rigger
    SAY_CARAVAN_LEAVE = 0,
    SAY_CARAVAN_HIRE = 1,

    SAY_CORK_AMBUSH_1 = 2,
    SAY_CORK_AMBUSH_2 = 3,
    SAY_CORK_AMBUSH_3 = 4,
    SAY_CORK_END = 5,

    SAY_RIGGER_AMBUSH_1 = 2,
    SAY_RIGGER_AMBUSH_2 = 3,
    SAY_RIGGER_END = 4,

    MAX_CARAVAN_SUMMONS = 3,

    TIME_SHOP_STOP = 10 * MINUTE*IN_MILLISECONDS,
    TIME_HIRE_STOP = 4 * MINUTE*IN_MILLISECONDS,
};

enum KolkarAmbusher
{
    NPC_KOLKAR_WAYLAYER = 12976,
    NPC_KOLKAR_AMBUSHER = 12977
};

enum DemonAmbusher
{
    NPC_NETHER_SORCERESS = 4684,
    NPC_LESSER_INFERNAL = 4676,
    NPC_DOOMWARDER = 4677
};

#define NUM_AMBUSHES_BODYGUARD_FOR_HIRE 3
#define NUM_KOLKAR_AMBUSHERS 4

#define NUM_AMBUSHES_GIZELTON_CARAVAN 3
#define NUM_DEMON_AMBUSHERS 3

/// @todo Add values for orientation
const std::pair<KolkarAmbusher, Position> KOLKAR_SPAWNPOINTS[NUM_AMBUSHES_BODYGUARD_FOR_HIRE][NUM_KOLKAR_AMBUSHERS] = // QUEST_BODYGUARD_FOR_HIRE
{
    {
        std::make_pair(NPC_KOLKAR_WAYLAYER, Position(-969.05f, 1174.91f, 90.39f)),
        std::make_pair(NPC_KOLKAR_WAYLAYER, Position(-983.01f, 1192.88f, 90.01f)),

        std::make_pair(NPC_KOLKAR_AMBUSHER, Position(-985.71f, 1173.95f, 91.02f)),
        std::make_pair(NPC_KOLKAR_AMBUSHER, Position(-965.51f, 1193.58f, 92.15f))
    },

    {
        std::make_pair(NPC_KOLKAR_WAYLAYER, Position(-1147.83f, 1180.87f, 91.38f)),
        std::make_pair(NPC_KOLKAR_WAYLAYER, Position(-1160.97f, 1201.36f, 93.15f)),

        std::make_pair(NPC_KOLKAR_AMBUSHER, Position(-1163.96f, 1183.72f, 93.79f)),
        std::make_pair(NPC_KOLKAR_AMBUSHER, Position(-1146.20f, 1199.75f, 91.37f))
    },

    {
        std::make_pair(NPC_KOLKAR_WAYLAYER, Position(-1277.78f, 1218.56f, 109.30f)),
        std::make_pair(NPC_KOLKAR_WAYLAYER, Position(-1289.25f, 1239.20f, 108.79f)),

        std::make_pair(NPC_KOLKAR_AMBUSHER, Position(-1292.65f, 1221.28f, 109.99f)),
        std::make_pair(NPC_KOLKAR_AMBUSHER, Position(-1272.91f, 1234.39f, 108.14f))
    }
};

const std::pair<DemonAmbusher, Position> DEMON_SPAWNPOINTS[NUM_AMBUSHES_GIZELTON_CARAVAN][NUM_DEMON_AMBUSHERS] = // QUEST_GIZELTON_CARAVAN
{
    {
        std::make_pair(NPC_NETHER_SORCERESS, Position(-1823.7f, 2060.88f, 62.0925f, 0.252946f)),
        std::make_pair(NPC_LESSER_INFERNAL, Position(-1814.46f, 2060.13f, 62.4916f, 2.00647f)),
        std::make_pair(NPC_DOOMWARDER, Position(-1814.87f, 2080.6f, 63.6323f, 6.13453f))
    },

    {
        std::make_pair(NPC_NETHER_SORCERESS, Position(-1782.92f, 1942.55f, 60.2205f, 3.8722f)),
        std::make_pair(NPC_LESSER_INFERNAL, Position(-1786.5f, 1926.05f, 59.7502f, 3.2329f)),
        std::make_pair(NPC_DOOMWARDER, Position(-1805.74f, 1942.77f, 60.791f, 0.829597f))
    },

    {
        std::make_pair(NPC_NETHER_SORCERESS, Position(-1677.56f, 1835.67f, 58.9269f, 1.30894f)),
        std::make_pair(NPC_LESSER_INFERNAL, Position(-1675.66f, 1863.0f, 59.0008f, 0.4827f)),
        std::make_pair(NPC_DOOMWARDER, Position(-1692.31f, 1862.69f, 58.9553f, 1.45773f))
    }
};

class npc_cork_gizelton : public CreatureScript
{
public:
    npc_cork_gizelton() : CreatureScript("npc_cork_gizelton") { }

    struct npc_cork_gizeltonAI : public npc_escortAI
    {
        npc_cork_gizeltonAI(Creature* creature) : npc_escortAI(creature)
        {
            memset(&summons, 0, sizeof(summons));
        }

        void InitializeAI() override
        {
            _playerGUID = ObjectGuid();
            headNorth = true;
            events.ScheduleEvent(EVENT_START_ESCORT, 0);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_BODYGUARD_FOR_HIRE)
                SetGUID(player->GetGUID(), 0);
        }

        void CheckPlayer()
        {
            if (_playerGUID)
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    if (me->IsWithinDist(player, 60.0f))
                        return;

            _playerGUID = ObjectGuid();
            ImmuneFlagSet(false);
        }

        void SetGUID(ObjectGuid playerGUID, int32 /*id*/) override
        {
            _playerGUID = playerGUID;
            SetEscortPaused(false);
            if (Creature* active = !headNorth ? me : ObjectAccessor::GetCreature(*me, summons[0]))
                active->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            events.CancelEvent(EVENT_WAIT_FOR_ASSIST);
        }

        void SetData(uint32 field, uint32 data) override
        {
            if (field == 1 && data == 1)
                if (Player* player = me->SelectNearestPlayer(50.0f))
                    SetGUID(player->GetGUID(), 0);
        }

        bool CheckCaravan()
        {
            bool summonTooFar = false;

            for (uint8 i = 0; i < MAX_CARAVAN_SUMMONS; ++i)
            {
                if (summons[i] == 0)
                {
                    SummonHelpers();
                    return false;
                }

                Creature* summon = ObjectAccessor::GetCreature(*me, summons[i]);
                if (!summon)
                {
                    SummonHelpers();
                    return false;
                }

                if (me->GetDistance2d(summon) > 25.0f)
                    summonTooFar = true;
            }

            if (summonTooFar) // Most likely caused by a bug
                SummonHelpers();

            return true;
        }

        void RemoveSummons()
        {
            for (uint8 i = 0; i < MAX_CARAVAN_SUMMONS; ++i)
            {
                if (Creature* summon = ObjectAccessor::GetCreature(*me, summons[i]))
                    summon->DespawnOrUnsummon();

                summons[i] = ObjectGuid();
            }
        }

        void SummonHelpers()
        {
            RemoveSummons();
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

            Creature* cr = NULL;
            if ((cr = me->SummonCreature(NPC_RIGGER_GIZELTON, *me)))
            {
                cr->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                summons[0] = cr->GetGUID();
            }
            if ((cr = me->SummonCreature(NPC_CARAVAN_KODO, *me)))
                summons[1] = cr->GetGUID();
            if ((cr = me->SummonCreature(NPC_CARAVAN_KODO, *me)))
                summons[2] = cr->GetGUID();

            SummonsFollow();
        }

        void SummonedCreatureDies(Creature* creature, Unit*)
        {
            if (creature->GetGUID() == summons[0])
                summons[0] = ObjectGuid();
            else if (creature->GetGUID() == summons[1])
                summons[1] = ObjectGuid();
            else if (creature->GetGUID() == summons[2])
                summons[2] = ObjectGuid();
        }

        void SummonedCreatureDespawn(Creature* creature)
        {
            if (creature->GetGUID() == summons[0])
                summons[0] = ObjectGuid();
            else if (creature->GetGUID() == summons[1])
                summons[1] = ObjectGuid();
            else if (creature->GetGUID() == summons[2])
                summons[2] = ObjectGuid();
        }

        void SummonsFollow()
        {
            float dist = 1.0f;
            for (uint8 i = 0; i < MAX_CARAVAN_SUMMONS; ++i)
                if (Creature* summon = ObjectAccessor::GetCreature(*me, summons[i]))
                {
                    summon->GetMotionMaster()->Clear(false);
                    summon->StopMoving();
                    summon->GetMotionMaster()->MoveFollow(me, dist, (float) M_PI, MOTION_SLOT_ACTIVE);
                    dist += (i == 1 ? 9.5f : 3.0f);
                }
        }

        void RelocateSummons()
        {
            for (uint8 i = 0; i < MAX_CARAVAN_SUMMONS; ++i)
                if (Creature* summon = ObjectAccessor::GetCreature(*me, summons[i]))
                    summon->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }

        void ImmuneFlagSet(bool remove)
        {
            for (uint8 i = 0; i < MAX_CARAVAN_SUMMONS; ++i)
                if (Creature* summon = ObjectAccessor::GetCreature(*me, summons[i]))
                {
                    if (remove)
                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    else
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                }
            if (remove)
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            else
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        }

        void WaypointReached(uint32 waypointId) override
        {
            RelocateSummons();
            switch (waypointId)
            {
                // Finished north path
            case 52:
                me->SummonCreature(NPC_VENDOR_TRON, -694.61f, 1460.7f, 90.794f, 2.4f, TEMPSUMMON_TIMED_DESPAWN, TIME_SHOP_STOP + 15 * IN_MILLISECONDS);
                SetEscortPaused(true);
                events.ScheduleEvent(EVENT_RESUME_PATH, TIME_SHOP_STOP);
                CheckCaravan();
                break;
                // Finished south path
            case 193:
                me->SummonCreature(NPC_SUPER_SELLER, -1905.5f, 2463.3f, 61.52f, 5.87f, TEMPSUMMON_TIMED_DESPAWN, TIME_SHOP_STOP + 15 * IN_MILLISECONDS);
                SetEscortPaused(true);
                events.ScheduleEvent(EVENT_RESUME_PATH, TIME_SHOP_STOP);
                CheckCaravan();
                break;
                // North -> South - hire
            case 76:
                SetEscortPaused(true);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                Talk(SAY_CARAVAN_HIRE);
                events.ScheduleEvent(EVENT_WAIT_FOR_ASSIST, TIME_HIRE_STOP);
                break;
                // Sout -> North - hire
            case 208:
                SetEscortPaused(true);
                if (Creature* rigger = ObjectAccessor::GetCreature(*me, summons[0]))
                {
                    rigger->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    rigger->AI()->Talk(SAY_CARAVAN_HIRE);
                }
                events.ScheduleEvent(EVENT_WAIT_FOR_ASSIST, TIME_HIRE_STOP);
                break;
                // North -> South - complete
            case 115:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    if (CheckCaravan())
                    {
                        player->GroupEventHappens(QUEST_BODYGUARD_FOR_HIRE, player);
                        Talk(SAY_CORK_END);
                    }
                    else
                        player->FailQuest(QUEST_BODYGUARD_FOR_HIRE);
                }
                _playerGUID = ObjectGuid();
                CheckPlayer();
                break;
                // South -> North - complete
            case 240:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    if (CheckCaravan())
                    {
                        player->GroupEventHappens(QUEST_GIZELTON_CARAVAN, player);
                        if (Creature* rigger = ObjectAccessor::GetCreature(*me, summons[0]))
                            rigger->AI()->Talk(SAY_RIGGER_END);
                    }
                    else
                        player->FailQuest(QUEST_GIZELTON_CARAVAN);
                }
                _playerGUID = ObjectGuid();
                CheckPlayer();
                break;
                // North -> South - spawn attackers
            case 95:
                KolkarAmbush(0);
                break;
            case 102:
                KolkarAmbush(1);
                break;
            case 110:
                KolkarAmbush(2);
                break;
                // South -> North - spawn attackers
            case 217:
                DemonAmbush(0);
                break;
            case 224:
                DemonAmbush(1);
                break;
            case 234:
                DemonAmbush(2);
                break;
            case 282:
                SetNextWaypoint(1, false, true);
                break;
            }
        }

        void KolkarAmbush(uint8 ambushNum)
        {
            if (!_playerGUID)
                return;

            ImmuneFlagSet(true);
            Creature* cr = nullptr;

            for (uint8 i = 0; i < NUM_KOLKAR_AMBUSHERS; ++i)
            {
                std::pair<KolkarAmbusher, Position> const& spawn = KOLKAR_SPAWNPOINTS[ambushNum][i];
                if ((cr = me->SummonCreature(spawn.first, spawn.second, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, MINUTE * IN_MILLISECONDS)))
                    cr->Attack(me, false);
            }

            if (cr)
            {
                AttackStart(cr);
                me->CallForHelp(50.0f);
            }

            switch (ambushNum)
            {
            case 0:
                Talk(SAY_CORK_AMBUSH_1);
                break;
            case 1:
                Talk(SAY_CORK_AMBUSH_2);
                break;
            case 2:
                Talk(SAY_CORK_AMBUSH_3);
                break;
            }
        }

        void DemonAmbush(uint8 ambushNum)
        {
            if (!_playerGUID)
                return;

            ImmuneFlagSet(true);
            Creature* cr = nullptr;

            for (uint8 i = 0; i < NUM_DEMON_AMBUSHERS; ++i)
            {
                std::pair<DemonAmbusher, Position> const& spawn = DEMON_SPAWNPOINTS[ambushNum][i];
                if ((cr = me->SummonCreature(spawn.first, spawn.second, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, MINUTE * IN_MILLISECONDS)))
                    cr->Attack(me, false);
            }

            if (cr)
            {
                AttackStart(cr);
                me->CallForHelp(50.0f);
            }

            uint8 textId = ambushNum == 1 ? SAY_RIGGER_AMBUSH_2 : SAY_RIGGER_AMBUSH_1;

            if (Creature* rigger = ObjectAccessor::GetCreature(*me, summons[0]))
                rigger->AI()->Talk(textId);

        }

        void UpdateEscortAI(uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_RESUME_PATH:
                SetEscortPaused(false);
                if (Creature* talker = headNorth ? me : ObjectAccessor::GetCreature(*me, summons[0]))
                    talker->AI()->Talk(SAY_CARAVAN_LEAVE);

                headNorth = !headNorth;
                break;
            case EVENT_WAIT_FOR_ASSIST:
                SetEscortPaused(false);
                if (Creature* active = !headNorth ? me : ObjectAccessor::GetCreature(*me, summons[0]))
                    active->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                break;
            case EVENT_START_ESCORT:
                CheckCaravan();
                SetDespawnAtEnd(false);
                if (me->GetVictim()) // Cannot start in combat
                    events.ScheduleEvent(EVENT_START_ESCORT, 1 * IN_MILLISECONDS);
                else
                    Start(true, true, ObjectGuid(), 0, false, false, true);
                break;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        ObjectGuid summons[MAX_CARAVAN_SUMMONS];
        bool headNorth;

        ObjectGuid _playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cork_gizeltonAI(creature);
    }
};


void AddSC_desolace()
{
    new npc_aged_dying_ancient_kodo();
    new go_iruxos();
    new npc_dalinda();
    new npc_cork_gizelton();
}
