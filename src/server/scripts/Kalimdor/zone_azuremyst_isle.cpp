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

/* ScriptData
SDName: Azuremyst_Isle
SD%Complete: 75
SDComment: Quest support: 9283, 9537, 9582, 9554, ? (special flight path, proper model for mount missing). Injured Draenei cosmetic only, 9582.
SDCategory: Azuremyst Isle
EndScriptData */

/* ContentData
npc_draenei_survivor
npc_engineer_spark_overgrind
npc_injured_draenei
npc_magwin
go_ravager_cage
npc_death_ravager
EndContentData */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

/*######
## npc_draenei_survivor
######*/

enum draeneiSurvivor
{
    SAY_THANK_FOR_HEAL     = 0,
    SAY_ASK_FOR_HELP       = 1,
    SPELL_IRRIDATION       = 35046,
    SPELL_STUNNED          = 28630,
    EVENT_CAN_ASK_FOR_HELP = 1,
    EVENT_THANK_PLAYER     = 2,
    EVENT_RUN_AWAY         = 3
};

Position const CrashSite = { -4115.25f, -13754.75f };

class npc_draenei_survivor : public CreatureScript
{
public:
    npc_draenei_survivor() : CreatureScript("npc_draenei_survivor") { }

    struct npc_draenei_survivorAI : public ScriptedAI
    {
        npc_draenei_survivorAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _playerGUID.Clear();
            _canAskForHelp = true;
            _canUpdateEvents = false;
            _tappedBySpell = false;
        }

        void Reset() override
        {
            Initialize();
            _events.Reset();

            DoCastSelf(SPELL_IRRIDATION, true);

            me->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
            me->AddUnitFlag(UNIT_FLAG_IN_COMBAT);
            me->SetHealth(me->CountPctFromMaxHealth(10));
            me->SetStandState(UNIT_STAND_STATE_SLEEP);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (_canAskForHelp && who->GetTypeId() == TYPEID_PLAYER && me->IsFriendlyTo(who) && me->IsWithinDistInMap(who, 25.0f))
            {
                //Random switch between 4 texts
                Talk(SAY_ASK_FOR_HELP);

                _events.ScheduleEvent(EVENT_CAN_ASK_FOR_HELP, Seconds(16), Seconds(20));
                _canAskForHelp = false;
                _canUpdateEvents = true;
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->SpellFamilyFlags[2] & 0x80000000 && !_tappedBySpell)
            {
                _events.Reset();
                _tappedBySpell = true;
                _canAskForHelp = false;
                _canUpdateEvents = true;

                me->RemoveUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
                me->SetStandState(UNIT_STAND_STATE_STAND);

                _playerGUID = caster->GetGUID();
                if (Player* player = caster->ToPlayer())
                    player->KilledMonsterCredit(me->GetEntry());

                me->SetFacingToObject(caster);
                DoCastSelf(SPELL_STUNNED, true);
                _events.ScheduleEvent(EVENT_THANK_PLAYER, Seconds(4));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_canUpdateEvents)
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAN_ASK_FOR_HELP:
                        _canAskForHelp = true;
                        _canUpdateEvents = false;
                        break;
                    case EVENT_THANK_PLAYER:
                        me->RemoveAurasDueToSpell(SPELL_IRRIDATION);
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            Talk(SAY_THANK_FOR_HEAL, player);
                        _events.ScheduleEvent(EVENT_RUN_AWAY, Seconds(10));
                        break;
                    case EVENT_RUN_AWAY:
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (std::cos(me->GetAngle(CrashSite)) * 28.0f), me->GetPositionY() + (std::sin(me->GetAngle(CrashSite)) * 28.0f), me->GetPositionZ() + 1.0f);
                        me->DespawnOrUnsummon(Seconds(4));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        bool _canUpdateEvents;
        bool _tappedBySpell;
        bool _canAskForHelp;
        ObjectGuid _playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_draenei_survivorAI(creature);
    }
};

/*######
## npc_engineer_spark_overgrind
######*/

enum Overgrind
{
    SAY_TEXT        = 0,
    SAY_EMOTE       = 1,
    ATTACK_YELL     = 2,

    AREA_COVE       = 3579,
    AREA_ISLE       = 3639,
    QUEST_GNOMERCY  = 9537,
    SPELL_DYNAMITE  = 7978
};

class npc_engineer_spark_overgrind : public CreatureScript
{
public:
    npc_engineer_spark_overgrind() : CreatureScript("npc_engineer_spark_overgrind") { }

    struct npc_engineer_spark_overgrindAI : public ScriptedAI
    {
        npc_engineer_spark_overgrindAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            NormFaction = creature->GetFaction();
            NpcFlags = NPCFlags(creature->m_unitData->NpcFlags[0]);
        }

        void Initialize()
        {
            DynamiteTimer = 8000;
            EmoteTimer = urand(120000, 150000);

            if (me->GetAreaId() == AREA_COVE || me->GetAreaId() == AREA_ISLE)
                IsTreeEvent = true;
            else
                IsTreeEvent = false;
        }

        void Reset() override
        {
            Initialize();

            me->SetFaction(NormFaction);
            me->SetNpcFlags(NpcFlags);
        }

        void EnterCombat(Unit* who) override
        {
            Talk(ATTACK_YELL, who);
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
        {
            CloseGossipMenuFor(player);
            me->SetFaction(FACTION_MONSTER);
            me->Attack(player, true);
            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->IsInCombat() && !IsTreeEvent)
            {
                if (EmoteTimer <= diff)
                {
                    Talk(SAY_TEXT);
                    Talk(SAY_EMOTE);
                    EmoteTimer = urand(120000, 150000);
                } else EmoteTimer -= diff;
            }
            else if (IsTreeEvent)
                return;

            if (!UpdateVictim())
                return;

            if (DynamiteTimer <= diff)
            {
                DoCastVictim(SPELL_DYNAMITE);
                DynamiteTimer = 8000;
            } else DynamiteTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        uint32 NormFaction;
        NPCFlags NpcFlags;
        uint32 DynamiteTimer;
        uint32 EmoteTimer;
        bool   IsTreeEvent;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_engineer_spark_overgrindAI(creature);
    }
};

/*######
## npc_injured_draenei
######*/

class npc_injured_draenei : public CreatureScript
{
public:
    npc_injured_draenei() : CreatureScript("npc_injured_draenei") { }

    struct npc_injured_draeneiAI : public ScriptedAI
    {
        npc_injured_draeneiAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->AddUnitFlag(UNIT_FLAG_IN_COMBAT);
            me->SetHealth(me->CountPctFromMaxHealth(15));
            switch (urand(0, 1))
            {
                case 0:
                    me->SetStandState(UNIT_STAND_STATE_SIT);
                    break;

                case 1:
                    me->SetStandState(UNIT_STAND_STATE_SLEEP);
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* /*who*/) override { }

        void UpdateAI(uint32 /*diff*/) override { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_injured_draeneiAI(creature);
    }
};

/*######
## npc_magwin
######*/

enum Magwin
{
    SAY_START                   = 0,
    SAY_AGGRO                   = 1,
    SAY_PROGRESS                = 2,
    SAY_END1                    = 3,
    SAY_END2                    = 4,
    EMOTE_HUG                   = 5,
    NPC_COWLEN                  = 17311,
    SAY_COWLEN                  = 0,
    EVENT_ACCEPT_QUEST          = 1,
    EVENT_START_ESCORT          = 2,
    EVENT_STAND                 = 3,
    EVENT_TALK_END              = 4,
    EVENT_COWLEN_TALK           = 5,
    QUEST_A_CRY_FOR_HELP        = 9528
};

class npc_magwin : public CreatureScript
{
public:
    npc_magwin() : CreatureScript("npc_magwin") { }

    struct npc_magwinAI : public EscortAI
    {
        npc_magwinAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override
        {
            _events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            Talk(SAY_AGGRO, who);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_A_CRY_FOR_HELP)
            {
                _player = player->GetGUID();
                _events.ScheduleEvent(EVENT_ACCEPT_QUEST, Seconds(2));
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 17:
                        Talk(SAY_PROGRESS, player);
                        break;
                    case 28:
                        player->GroupEventHappens(QUEST_A_CRY_FOR_HELP, me);
                        _events.ScheduleEvent(EVENT_TALK_END, Seconds(2));
                        SetRun(true);
                        break;
                    case 29:
                        if (Creature* cowlen = me->FindNearestCreature(NPC_COWLEN, 50.0f, true))
                            Talk(EMOTE_HUG, cowlen);
                        Talk(SAY_END2, player);
                        break;
                }
            }
        }

        void UpdateEscortAI(uint32 diff) override
        {
            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACCEPT_QUEST:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(SAY_START, player);
                        me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
                        _events.ScheduleEvent(EVENT_START_ESCORT, Seconds(1));
                        break;
                    case EVENT_START_ESCORT:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            EscortAI::Start(true, false, player->GetGUID());
                        _events.ScheduleEvent(EVENT_STAND, Seconds(2));
                        break;
                    case EVENT_STAND: // Remove kneel standstate. Using a separate delayed event because it causes unwanted delay before starting waypoint movement.
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        break;
                    case EVENT_TALK_END:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(SAY_END1, player);
                        _events.ScheduleEvent(EVENT_COWLEN_TALK, Seconds(2));
                        break;
                    case EVENT_COWLEN_TALK:
                        if (Creature* cowlen = me->FindNearestCreature(NPC_COWLEN, 50.0f, true))
                            cowlen->AI()->Talk(SAY_COWLEN);
                        break;
                }
            }

            EscortAI::UpdateEscortAI(diff);
        }

    private:
        EventMap _events;
        ObjectGuid _player;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_magwinAI(creature);
    }
};

/*######
## npc_geezle
######*/

enum Geezle
{
    QUEST_TREES_COMPANY = 9531,

    SPELL_TREE_DISGUISE = 30298,

    GEEZLE_SAY_1    = 0,
    SPARK_SAY_2     = 3,
    SPARK_SAY_3     = 4,
    GEEZLE_SAY_4    = 1,
    SPARK_SAY_5     = 5,
    SPARK_SAY_6     = 6,
    GEEZLE_SAY_7    = 2,

    EMOTE_SPARK     = 7,

    NPC_SPARK       = 17243,
    GO_NAGA_FLAG    = 181694
};

Position const SparkPos = {-5029.91f, -11291.79f, 8.096f, 0.0f};

class npc_geezle : public CreatureScript
{
public:
    npc_geezle() : CreatureScript("npc_geezle") { }

    struct npc_geezleAI : public ScriptedAI
    {
        npc_geezleAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            SparkGUID.Clear();
            Step = 0;
            EventStarted = false;
            SayTimer = 0;
        }

        ObjectGuid SparkGUID;

        uint8 Step;
        uint32 SayTimer;

        bool EventStarted;

        void Reset() override
        {
            Initialize();
            StartEvent();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void StartEvent()
        {
            Step = 0;
            EventStarted = true;
            if (Creature* Spark = me->SummonCreature(NPC_SPARK, SparkPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000))
            {
                SparkGUID = Spark->GetGUID();
                Spark->setActive(true);
                Spark->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            }
            SayTimer = 8000;
        }

        uint32 NextStep(uint8 step)
        {
            Creature* Spark = ObjectAccessor::GetCreature(*me, SparkGUID);
            if (!Spark)
                return 99999999;

            switch (step)
            {
                case 0:
                    Spark->GetMotionMaster()->MovePoint(0, -5080.70f, -11253.61f, 0.56f);
                    me->GetMotionMaster()->MovePoint(0, -5092.26f, -11252, 0.71f);
                    return 9000;
                case 1:
                    DespawnNagaFlag(true);
                    Spark->AI()->Talk(EMOTE_SPARK);
                    return 1000;
                case 2:
                    Talk(GEEZLE_SAY_1, Spark);
                    Spark->SetFacingToObject(me);
                    me->SetFacingToObject(Spark);
                    return 5000;
                case 3:
                    Spark->AI()->Talk(SPARK_SAY_2);
                    return 7000;
                case 4:
                    Spark->AI()->Talk(SPARK_SAY_3);
                    return 8000;
                case 5:
                    Talk(GEEZLE_SAY_4, Spark);
                    return 8000;
                case 6:
                    Spark->AI()->Talk(SPARK_SAY_5);
                    return 9000;
                case 7:
                    Spark->AI()->Talk(SPARK_SAY_6);
                    return 8000;
                case 8:
                    Talk(GEEZLE_SAY_7, Spark);
                    return 2000;
                case 9:
                    me->GetMotionMaster()->MoveTargetedHome();
                    Spark->GetMotionMaster()->MovePoint(0, SparkPos);
                    CompleteQuest();
                    return 9000;
                case 10:
                    Spark->DisappearAndDie();
                    DespawnNagaFlag(false);
                    me->DisappearAndDie();
                default: return 99999999;
            }
        }

        // will complete Tree's company quest for all nearby players that are disguised as trees
        void CompleteQuest()
        {
            float radius = 50.0f;
            std::list<Player*> players;
            Trinity::AnyPlayerInObjectRangeCheck checker(me, radius);
            Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
            Cell::VisitWorldObjects(me, searcher, radius);

            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if ((*itr)->GetQuestStatus(QUEST_TREES_COMPANY) == QUEST_STATUS_INCOMPLETE && (*itr)->HasAura(SPELL_TREE_DISGUISE))
                    (*itr)->KilledMonsterCredit(NPC_SPARK);
        }

        void DespawnNagaFlag(bool despawn)
        {
            std::list<GameObject*> FlagList;
            me->GetGameObjectListWithEntryInGrid(FlagList, GO_NAGA_FLAG, 100.0f);

            if (!FlagList.empty())
            {
                for (std::list<GameObject*>::const_iterator itr = FlagList.begin(); itr != FlagList.end(); ++itr)
                {
                    if (despawn)
                        (*itr)->SetLootState(GO_JUST_DEACTIVATED);
                    else
                        (*itr)->Respawn();
                }
            }
            else
                TC_LOG_ERROR("scripts", "SD2 ERROR: FlagList is empty!");
        }

        void UpdateAI(uint32 diff) override
        {
            if (SayTimer <= diff)
            {
                if (EventStarted)
                    SayTimer = NextStep(Step++);
            }
            else
                SayTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_geezleAI(creature);
    }
};

enum RavegerCage
{
    NPC_DEATH_RAVAGER       = 17556,

    SPELL_REND              = 13443,
    SPELL_ENRAGING_BITE     = 30736,

    QUEST_STRENGTH_ONE      = 9582
};

class go_ravager_cage : public GameObjectScript
{
public:
    go_ravager_cage() : GameObjectScript("go_ravager_cage") { }

    struct go_ravager_cageAI : public GameObjectAI
    {
        go_ravager_cageAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* player) override
        {
            me->UseDoorOrButton();
            if (player->GetQuestStatus(QUEST_STRENGTH_ONE) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* ravager = me->FindNearestCreature(NPC_DEATH_RAVAGER, 5.0f, true))
                {
                    ravager->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    ravager->SetReactState(REACT_AGGRESSIVE);
                    ravager->AI()->AttackStart(player);
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_ravager_cageAI(go);
    }
};

class npc_death_ravager : public CreatureScript
{
public:
    npc_death_ravager() : CreatureScript("npc_death_ravager") { }

    struct npc_death_ravagerAI : public ScriptedAI
    {
        npc_death_ravagerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            RendTimer = 30000;
            EnragingBiteTimer = 20000;
        }

        uint32 RendTimer;
        uint32 EnragingBiteTimer;

        void Reset() override
        {
            Initialize();

            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (RendTimer <= diff)
            {
                DoCastVictim(SPELL_REND);
                RendTimer = 30000;
            }
            else RendTimer -= diff;

            if (EnragingBiteTimer <= diff)
            {
                DoCastVictim(SPELL_ENRAGING_BITE);
                EnragingBiteTimer = 15000;
            }
            else EnragingBiteTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_death_ravagerAI(creature);
    }
};

// 29528 -  Inoculate Nestlewood Owlkin
class spell_inoculate_nestlewood : public AuraScript
{
    PrepareAuraScript(spell_inoculate_nestlewood);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (GetTarget()->GetTypeId() != TYPEID_UNIT) // prevent error reports in case ignored player target
            PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_inoculate_nestlewood::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_azuremyst_isle()
{
    new npc_draenei_survivor();
    new npc_engineer_spark_overgrind();
    new npc_injured_draenei();
    new npc_magwin();
    new npc_death_ravager();
    new go_ravager_cage();
    RegisterAuraScript(spell_inoculate_nestlewood);
}
