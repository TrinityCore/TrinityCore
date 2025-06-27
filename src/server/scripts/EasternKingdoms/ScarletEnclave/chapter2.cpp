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

#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"

enum BloodyBreakoutTexts
{
    SAY_KOLTIRA_0 = 0,
    SAY_KOLTIRA_1 = 1,
    SAY_KOLTIRA_2 = 2,
    SAY_KOLTIRA_3 = 3,
    SAY_KOLTIRA_4 = 4,
    SAY_KOLTIRA_5 = 5,
    SAY_KOLTIRA_6 = 6,
    SAY_KOLTIRA_7 = 7,
    SAY_KOLTIRA_8 = 8,
    SAY_KOLTIRA_9 = 9,
    SAY_KOLTIRA_10 = 10,

    SAY_VALROTH_0 = 0,
    SAY_VALROTH_1 = 1,
    SAY_VALROTH_2 = 2,
    SAY_VALROTH_3 = 3,

    TEXT_ID_EVENT = 13425
};

enum BloodyBreakoutEvents
{
    EVENT_INTRO_0           = 1,
    EVENT_INTRO_1           = 2,
    EVENT_INTRO_2           = 3,
    EVENT_INTRO_3           = 4,
    EVENT_INTRO_4           = 5,
    EVENT_INTRO_5           = 6,
    EVENT_INTRO_6           = 7,

    EVENT_SPAWN_WAVE_1      = 8,
    EVENT_SPAWN_WAVE_2      = 9,
    EVENT_SPAWN_WAVE_3      = 10,
    EVENT_SPAWN_VALROTH     = 11,

    EVENT_KOLTIRA_ADVICE    = 12,
    EVENT_OUTRO_1           = 13,
    EVENT_OUTRO_2           = 14,
    EVENT_OUTRO_3           = 15,
    EVENT_OUTRO_4           = 16,

    EVENT_CHECK_PLAYER      = 17
};

enum BloodyBreakout
{
    POINT_ID_1                  = 1,
    POINT_ID_2                  = 2,
    POINT_ID_6                  = 6,
    POINT_ID_10                 = 10,

    SUMMON_ACOLYTES_0           = 0,
    SUMMON_ACOLYTES_1           = 1,
    SUMMON_ACOLYTES_2           = 2,
    SUMMON_VALROTH              = 3,

    QUEST_BLOODY_BREAKOUT       = 12727,

    NPC_FAKE_VALROTH            = 29011,
    NPC_VALROTH                 = 29001,
    NPC_ACOLYTE                 = 29007,
    NPC_KOLTIRA                 = 28912,
    NPC_KOLTIRA_MOUNT           = 25445,

    SPELL_KOLTIRA_TRANSFORM     = 52899,
    SPELL_ANTI_MAGIC_ZONE       = 52894,
    SPELL_HERO_AGGRO            = 53627
};

Position const koltiraPos[3] =
{
    { 1653.36f, -6038.34f, 127.584f },
    { 1653.765f, -6035.075f, 127.5844f },
    { 1651.89f, -6037.101f, 127.5844f }
};

struct npc_koltira_deathweaver : public ScriptedAI
{
    npc_koltira_deathweaver(Creature* creature) : ScriptedAI(creature), _summons(me)
    {
        _eventGossip = false;
    }

    bool OnGossipHello(Player* player) override
    {
        ObjectGuid const guid = me->GetGUID();
        _playerGUID = player->GetGUID();

        if (me->IsQuestGiver())
            player->PrepareQuestMenu(guid);

        // override default gossip
        if (_eventGossip)
        {
            SendGossipMenuFor(player, TEXT_ID_EVENT, guid);
            return true;
        }

        return false;
    }

    void OnQuestAccept(Player* /* player */, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_BLOODY_BREAKOUT)
        {
            _events.ScheduleEvent(EVENT_INTRO_0, 500ms);
            _events.ScheduleEvent(EVENT_CHECK_PLAYER, 5s);
        }
    }

    void Reset() override
    {
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        me->SetStandState(UNIT_STAND_STATE_DEAD);
        me->RemoveAllAuras();

        _events.Reset();
        _summons.DespawnAll();
        _playerGUID.Clear();
        _eventGossip = false;
    }

    void FakeValrothTalk(uint32 id)
    {
        if (Creature* fakeValroth = me->FindNearestCreature(NPC_FAKE_VALROTH, INSPECT_DISTANCE * 2))
            fakeValroth->AI()->Talk(id);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_0:
                    me->SetStandState(UNIT_STAND_STATE_SIT);
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    Talk(SAY_KOLTIRA_0);

                    _events.ScheduleEvent(EVENT_INTRO_1, 5s);
                    break;
                case EVENT_INTRO_1:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    Talk(SAY_KOLTIRA_1);

                    _events.ScheduleEvent(EVENT_INTRO_2, 2s);
                    break;
                case EVENT_INTRO_2:
                    me->GetMotionMaster()->MoveJump(koltiraPos[0], 25.0f, 15.0f);

                    _events.ScheduleEvent(EVENT_INTRO_3, 2s);
                    break;

                case EVENT_INTRO_3:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_ID_1, koltiraPos[1]);

                    break;
                case EVENT_INTRO_4:
                    DoCastSelf(SPELL_KOLTIRA_TRANSFORM);
                    me->LoadEquipment(POINT_ID_1);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->GetMotionMaster()->MovePoint(POINT_ID_2, koltiraPos[2], true, 3.839724f);

                    break;
                case EVENT_INTRO_5:
                    Talk(SAY_KOLTIRA_2);
                    DoCastSelf(SPELL_ANTI_MAGIC_ZONE);

                    _events.ScheduleEvent(EVENT_INTRO_6, 4s);
                    break;
                case EVENT_INTRO_6:
                    Talk(SAY_KOLTIRA_3);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    _eventGossip = true;

                    break;
                case EVENT_SPAWN_WAVE_1:
                    me->SummonCreatureGroup(SUMMON_ACOLYTES_0);

                    _events.ScheduleEvent(EVENT_SPAWN_WAVE_2, 29s);
                    break;
                case EVENT_SPAWN_WAVE_2:
                    Talk(SAY_KOLTIRA_4);
                    FakeValrothTalk(SAY_VALROTH_1);
                    me->SummonCreatureGroup(SUMMON_ACOLYTES_1);

                    _events.ScheduleEvent(EVENT_SPAWN_WAVE_3, 21s);
                    break;
                case EVENT_SPAWN_WAVE_3:
                    Talk(SAY_KOLTIRA_5);
                    FakeValrothTalk(SAY_VALROTH_2);
                    me->SummonCreatureGroup(SUMMON_ACOLYTES_2);

                    _events.ScheduleEvent(EVENT_SPAWN_VALROTH, 24s);
                    break;
                case EVENT_SPAWN_VALROTH:
                    Talk(SAY_KOLTIRA_6);
                    FakeValrothTalk(SAY_VALROTH_3);
                    me->SummonCreatureGroup(SUMMON_VALROTH);

                    _events.ScheduleEvent(EVENT_KOLTIRA_ADVICE, 8s, 16s);
                    break;
                case EVENT_KOLTIRA_ADVICE:
                    if (_summons.HasEntry(NPC_VALROTH))
                        Talk(SAY_KOLTIRA_7);

                    break;
                case EVENT_OUTRO_1:
                    me->RemoveAurasDueToSpell(SPELL_ANTI_MAGIC_ZONE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    Talk(SAY_KOLTIRA_8);

                    _events.ScheduleEvent(EVENT_OUTRO_2, 7s);
                    _events.CancelEvent(EVENT_CHECK_PLAYER);
                    break;
                case EVENT_OUTRO_2:
                    Talk(SAY_KOLTIRA_9);

                    _events.ScheduleEvent(EVENT_OUTRO_3, 4s);
                    break;
                case EVENT_OUTRO_3:
                    Talk(SAY_KOLTIRA_10);

                    _events.ScheduleEvent(EVENT_OUTRO_4, 3s);
                    break;
                case EVENT_OUTRO_4:
                    me->SetWalk(false);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    DoCastSelf(SPELL_HERO_AGGRO);
                    me->GetMotionMaster()->MovePath(NPC_KOLTIRA, false);

                    break;
                case EVENT_CHECK_PLAYER:
                    if (!_playerGUID)
                        return;

                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (!player->IsAlive() || !player->IsWithinDist(me, INTERACTION_DISTANCE * 6))
                        {
                            _summons.DespawnAll();
                            me->DespawnOrUnsummon(1s);
                            player->FailQuest(QUEST_BLOODY_BREAKOUT);
                        }
                    }

                    _events.ScheduleEvent(EVENT_CHECK_PLAYER, 5s);
                    break;
            }
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            if (pointId == POINT_ID_1)
            {
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                FakeValrothTalk(SAY_VALROTH_0);

                _events.ScheduleEvent(EVENT_SPAWN_WAVE_1, 1s);
                _events.ScheduleEvent(EVENT_INTRO_4, 3s);
            }
            else if (pointId == POINT_ID_2)
                _events.ScheduleEvent(EVENT_INTRO_5, 1s);
        }
        else
        {
            if (pointId == POINT_ID_6)
                me->Mount(NPC_KOLTIRA_MOUNT);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_VALROTH)
            _events.ScheduleEvent(EVENT_OUTRO_1, 1s);

        _summons.Despawn(summon);
    }

private:
    EventMap _events;
    SummonList _summons;
    ObjectGuid _playerGUID;

    bool _eventGossip;
};

//Scarlet courier
enum ScarletCourierEnum
{
    SAY_TREE1                          = 0,
    SAY_TREE2                          = 1,
    SPELL_SHOOT                        = 52818,
    GO_INCONSPICUOUS_TREE              = 191144,
    NPC_SCARLET_COURIER                = 29076
};

class npc_scarlet_courier : public CreatureScript
{
public:
    npc_scarlet_courier() : CreatureScript("npc_scarlet_courier") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_scarlet_courierAI(creature);
    }

    struct npc_scarlet_courierAI : public ScriptedAI
    {
        npc_scarlet_courierAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            uiStage = 1;
            uiStage_timer = 3000;
        }

        uint32 uiStage;
        uint32 uiStage_timer;

        void Reset() override
        {
            me->Mount(14338); // not sure about this id
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_TREE2);
            me->Dismount();
            uiStage = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
                uiStage = 2;
        }

        void UpdateAI(uint32 diff) override
        {
            if (uiStage && !me->IsInCombat())
            {
                if (uiStage_timer <= diff)
                {
                    switch (uiStage)
                    {
                    case 1:
                        me->SetWalk(true);
                        if (GameObject* tree = me->FindNearestGameObject(GO_INCONSPICUOUS_TREE, 40.0f))
                        {
                            Talk(SAY_TREE1);
                            float x, y, z;
                            tree->GetContactPoint(me, x, y, z);
                            me->GetMotionMaster()->MovePoint(1, x, y, z);
                        }
                        break;
                    case 2:
                        if (GameObject* tree = me->FindNearestGameObject(GO_INCONSPICUOUS_TREE, 40.0f))
                            if (Unit* unit = tree->GetOwner())
                                AttackStart(unit);
                        break;
                    }
                    uiStage_timer = 3000;
                    uiStage = 0;
                } else uiStage_timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_a_special_surprise
######*/
//used by 29032, 29061, 29065, 29067, 29068, 29070, 29074, 29072, 29073, 29071 but signed for 29032
enum SpecialSurprise
{
    SAY_EXEC_START            = 0,
    SAY_EXEC_PROG             = 1,
    SAY_EXEC_NAME             = 2,
    SAY_EXEC_RECOG            = 3,
    SAY_EXEC_NOREM            = 4,
    SAY_EXEC_THINK            = 5,
    SAY_EXEC_LISTEN           = 6,
    SAY_EXEC_TIME             = 7,
    SAY_EXEC_WAITING          = 8,
    EMOTE_DIES                = 9,

    SAY_PLAGUEFIST            = 0,
    NPC_PLAGUEFIST            = 29053
};

class npc_a_special_surprise : public CreatureScript
{
public:
    npc_a_special_surprise() : CreatureScript("npc_a_special_surprise") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_a_special_surpriseAI(creature);
    }

    struct npc_a_special_surpriseAI : public ScriptedAI
    {
        npc_a_special_surpriseAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ExecuteSpeech_Timer = 0;
            ExecuteSpeech_Counter = 0;
            PlayerGUID.Clear();
        }

        uint32 ExecuteSpeech_Timer;
        uint32 ExecuteSpeech_Counter;
        ObjectGuid PlayerGUID;

        void Reset() override
        {
            Initialize();

            me->SetImmuneToPC(true);
        }

        bool MeetQuestCondition(Player* player)
        {
            switch (me->GetEntry())
            {
                case 29061:                                     // Ellen Stanbridge
                    if (player->GetQuestStatus(12742) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29072:                                     // Kug Ironjaw
                    if (player->GetQuestStatus(12748) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29067:                                     // Donovan Pulfrost
                    if (player->GetQuestStatus(12744) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29065:                                     // Yazmina Oakenthorn
                    if (player->GetQuestStatus(12743) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29071:                                     // Antoine Brack
                    if (player->GetQuestStatus(12750) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29032:                                     // Malar Bravehorn
                    if (player->GetQuestStatus(12739) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29068:                                     // Goby Blastenheimer
                    if (player->GetQuestStatus(12745) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29073:                                     // Iggy Darktusk
                    if (player->GetQuestStatus(12749) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29074:                                     // Lady Eonys
                    if (player->GetQuestStatus(12747) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
                case 29070:                                     // Valok the Righteous
                    if (player->GetQuestStatus(12746) == QUEST_STATUS_INCOMPLETE)
                        return true;
                    break;
            }

            return false;
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (PlayerGUID || who->GetTypeId() != TYPEID_PLAYER || !who->IsWithinDist(me, INTERACTION_DISTANCE))
                return;

            if (MeetQuestCondition(who->ToPlayer()))
                PlayerGUID = who->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            if (PlayerGUID && !me->GetVictim() && me->IsAlive())
            {
                if (ExecuteSpeech_Timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);

                    if (!player)
                    {
                        Reset();
                        return;
                    }

                    switch (ExecuteSpeech_Counter)
                    {
                        case 0:
                            Talk(SAY_EXEC_START, player);
                            break;
                        case 1:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            break;
                        case 2:
                            Talk(SAY_EXEC_PROG, player);
                            break;
                        case 3:
                            Talk(SAY_EXEC_NAME, player);
                            break;
                        case 4:
                            Talk(SAY_EXEC_RECOG, player);
                            break;
                        case 5:
                            Talk(SAY_EXEC_NOREM, player);
                            break;
                        case 6:
                            Talk(SAY_EXEC_THINK, player);
                            break;
                        case 7:
                            Talk(SAY_EXEC_LISTEN, player);
                            break;
                        case 8:
                            if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                Plaguefist->AI()->Talk(SAY_PLAGUEFIST, player);
                            break;
                        case 9:
                            Talk(SAY_EXEC_TIME, player);
                            me->SetStandState(UNIT_STAND_STATE_KNEEL);
                            me->SetImmuneToPC(false);
                            break;
                        case 10:
                            Talk(SAY_EXEC_WAITING, player);
                            break;
                        case 11:
                            Talk(EMOTE_DIES);
                            me->setDeathState(JUST_DIED);
                            me->SetHealth(0);
                            return;
                    }

                    if (ExecuteSpeech_Counter >= 9)
                        ExecuteSpeech_Timer = 15000;
                    else
                        ExecuteSpeech_Timer = 7000;

                    ++ExecuteSpeech_Counter;
                }
                else
                    ExecuteSpeech_Timer -= diff;
            }
        }
    };
};

// 53110 - Devour Humanoid
class spell_death_knight_devour_humanoid : public SpellScript
{
    PrepareSpellScript(spell_death_knight_devour_humanoid);

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        GetHitUnit()->CastSpell(GetCaster(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_death_knight_devour_humanoid::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_the_scarlet_enclave_c2()
{
    RegisterCreatureAI(npc_koltira_deathweaver);
    new npc_scarlet_courier();
    new npc_a_special_surprise();
    RegisterSpellScript(spell_death_knight_devour_humanoid);
}
