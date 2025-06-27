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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"

enum ThalorienDawnseekerTexts
{
    SAY_THALORIEN_1 = 0,
    SAY_THALORIEN_2 = 1,
    SAY_THALORIEN_3 = 2,
    SAY_THALORIEN_4 = 3,
    SAY_THALORIEN_5 = 4,
    SAY_THALORIEN_6 = 5,
    SAY_THALORIEN_7 = 6,
    SAY_THALORIEN_8 = 7,
    SAY_THALORIEN_9 = 8,
    SAY_THALORIEN_10 = 9,

    SAY_MORLEN_1 = 0,
    SAY_MORLEN_2 = 1,
    SAY_MORLEN_3 = 2,
    SAY_MORLEN_4 = 3,
    SAY_MORLEN_5 = 4
};

enum ThalorienDawnseekerSummons
{
    SUMMON_SUNWELL_DEFENDER = 1,
    SUMMON_SCOURGE_ZOMBIE   = 2,
    SUMMON_GHOUL_INVADER    = 3,
    SUMMON_CRYPT_RAIDER     = 4
};

enum ThalorienDawnseekerActions
{
    ACTION_START_QUEST = 1
};

enum ThalorienDawnseekerEvents
{
    EVENT_INTRO_0           = 1,
    EVENT_INTRO_1           = 2,
    EVENT_INTRO_2           = 3,
    EVENT_INTRO_3           = 4,
    EVENT_SALUTE            = 5,
    EVENT_DEFENDERS_RUN     = 6,
    EVENT_DEFENDERS_RUN_2   = 7,
    EVENT_THALORIEN_GO      = 8,
    EVENT_INTRO_4           = 9,
    EVENT_SUMMON_MORLEN     = 10,
    EVENT_INTRO_5           = 11,
    EVENT_MORLEN_1          = 12,
    EVENT_SPAWN_WAVE_1      = 13,
    EVENT_SPAWN_WAVE_2      = 14,
    EVENT_SPAWN_WAVE_3      = 15,
    EVENT_WAVE_ATTACK       = 16,
    EVENT_MORLEN_2          = 17,
    EVENT_MORLEN_ATTACK     = 18,
    EVENT_OUTRO_1           = 19,
    EVENT_OUTRO_2           = 20,
    EVENT_OUTRO_3           = 21,
    EVENT_OUTRO_4           = 22,
    EVENT_KNEEL             = 23
};

enum ThalorienDawnseeker
{
    MENU_EXAMINE_REMAINS        = 10908,

    NPC_THALORIEN_DAWNSEEKER    = 37205,
    NPC_SUNWELL_DEFENDER        = 37211,
    NPC_MORLEN_GOLDGRIP         = 37542,
    NPC_SCOURGE_ZOMBIE          = 37538,
    NPC_GHOUL_INVADER           = 37539,
    NPC_CRYPT_RAIDER            = 37541,

    SPELL_BLOOD_PRESENCE        = 50689,
    SPELL_KILL_CREDIT           = 70265,
    SPELL_POLYMORPH_VISUAL      = 27123
};

uint8 const defenders = 10;
float const defendersOrientation = 5.67232f;
Position const defendersRun[] =
{
        { 11934.78f, -7064.424f, 33.38046f },
        { 11927.9f,  -7061.303f, 32.00986f },
        { 11927.81f, -7067.289f, 31.81058f },
        { 11927.89f, -7058.299f, 32.13486f },
        { 11927.9f,  -7061.303f, 32.00986f },

        { 11934.78f, -7064.424f, 33.38046f },
        { 11920.69f, -7061.134f, 30.40684f },
        { 11920.56f, -7067.133f, 30.41605f },
        { 11920.76f, -7058.135f, 30.61656f },
        { 11920.5f,  -7070.132f, 30.40836f }
};

Position const thalorienSummon = { 11795.32f, -7070.476f, 26.27511f, 5.67232f  };
Position const thalorienFight = { 11788.46f, -7063.375f, 25.79677f, 3.054326f };
Position const morlenSummon = { 11766.46f, -7050.078f, 26.19846f, 5.637414f  };

struct npc_thalorien_dawnseeker : public ScriptedAI
{
    npc_thalorien_dawnseeker(Creature* creature) : ScriptedAI(creature), _summons(me)
    {
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == MENU_EXAMINE_REMAINS)
        {
            CloseGossipMenuFor(player);
            DoAction(ACTION_START_QUEST);
            _playerGUID = player->GetGUID();
        }
        return false;
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_QUEST)
        {
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

            if (Creature* thalorien = me->SummonCreature(NPC_THALORIEN_DAWNSEEKER, thalorienSummon, TEMPSUMMON_CORPSE_DESPAWN))
                _thalorienGUID = thalorien->GetGUID();
            me->SummonCreatureGroup(SUMMON_SUNWELL_DEFENDER);

            _events.ScheduleEvent(EVENT_INTRO_0, 3s);
        }
    }

    void Reset() override
    {
        me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        _summons.DespawnAll();
        _playerGUID.Clear();
        _morlenGUID.Clear();
        _thalorienGUID.Clear();
        _events.Reset();
    }

    void ThalorienTalk(uint32 id)
    {
        if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
            thalorien->AI()->Talk(id);
    }

    void MorlenTalk(uint32 id)
    {
        if (Creature* morlen = ObjectAccessor::GetCreature(*me, _morlenGUID))
            morlen->AI()->Talk(id);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_0:
                    ThalorienTalk(SAY_THALORIEN_1);

                    _events.ScheduleEvent(EVENT_INTRO_1, 5s);
                    break;
                case EVENT_INTRO_1:
                    ThalorienTalk(SAY_THALORIEN_2);

                    _events.ScheduleEvent(EVENT_INTRO_2, 6s);
                    break;
                case EVENT_INTRO_2:
                    ThalorienTalk(SAY_THALORIEN_3);

                    _events.ScheduleEvent(EVENT_INTRO_3, 7s);
                    break;

                case EVENT_INTRO_3:
                    ThalorienTalk(SAY_THALORIEN_4);

                    _events.ScheduleEvent(EVENT_SALUTE, 4s);
                    break;
                case EVENT_SALUTE:
                    for (auto& summon : _summons)
                        if (Creature* creature = ObjectAccessor::GetCreature(*me, summon))
                            creature->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);

                    _events.ScheduleEvent(EVENT_DEFENDERS_RUN, 3s);
                    break;
                case EVENT_DEFENDERS_RUN:
                {
                    _events.ScheduleEvent(EVENT_DEFENDERS_RUN_2, 3s);
                    _events.ScheduleEvent(EVENT_THALORIEN_GO, 2s);

                    uint8 defendersCount = 0;
                    for (auto& summon : _summons)
                    {
                        Creature* creature = ObjectAccessor::GetCreature(*me, summon);
                        if (!creature)
                            continue;

                        if (creature->GetEntry() != NPC_SUNWELL_DEFENDER)
                            continue;

                        defendersCount++;
                        if (defendersCount <= 5)
                            creature->SetFacingTo(defendersOrientation);
                        else
                            if (defendersCount - 1 < defenders)
                                creature->GetMotionMaster()->MovePoint(0, defendersRun[defendersCount - 1]);
                    }

                    break;
                }
                case EVENT_DEFENDERS_RUN_2:
                {
                    uint8 defendersCount = 0;
                    for (auto& summon : _summons)
                    {
                        Creature* creature = ObjectAccessor::GetCreature(*me, summon);
                        if (!creature)
                            continue;

                        if (creature->GetEntry() != NPC_SUNWELL_DEFENDER)
                            continue;

                        ++defendersCount;
                        if (defendersCount < defenders)
                            creature->GetMotionMaster()->MovePoint(0, defendersRun[defendersCount]);
                    }

                    break;
                }
                case EVENT_THALORIEN_GO:
                    if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
                    {
                        thalorien->SetWalk(true);
                        thalorien->GetMotionMaster()->MovePoint(0, thalorienFight);
                        thalorien->SetEmoteState(EMOTE_STATE_READY2H);
                        thalorien->SetHomePosition(thalorienFight);
                    }

                    _events.ScheduleEvent(EVENT_INTRO_4, 4s);
                    break;
                case EVENT_INTRO_4:
                    ThalorienTalk(SAY_THALORIEN_5);

                    _events.ScheduleEvent(EVENT_SUMMON_MORLEN, 6s);
                    _events.ScheduleEvent(EVENT_INTRO_5, 9s);
                    break;
                case EVENT_INTRO_5:
                    ThalorienTalk(SAY_THALORIEN_6);

                    _events.ScheduleEvent(EVENT_MORLEN_1, 6s);
                    break;
                case EVENT_SUMMON_MORLEN:
                    if (Creature* morlen = me->SummonCreature(NPC_MORLEN_GOLDGRIP, morlenSummon, TEMPSUMMON_CORPSE_DESPAWN))
                    {
                        _morlenGUID = morlen->GetGUID();
                        morlen->AI()->DoCastSelf(SPELL_BLOOD_PRESENCE);
                    }

                    break;
                case EVENT_MORLEN_1:
                    MorlenTalk(SAY_MORLEN_1);

                    _events.ScheduleEvent(EVENT_SPAWN_WAVE_1, 7s);
                    break;
                case EVENT_SPAWN_WAVE_1:
                    MorlenTalk(SAY_MORLEN_2);

                    me->SummonCreatureGroup(SUMMON_SCOURGE_ZOMBIE);

                    _events.ScheduleEvent(EVENT_WAVE_ATTACK, 3s);
                    break;
                case EVENT_SPAWN_WAVE_2:
                    MorlenTalk(SAY_MORLEN_3);

                    me->SummonCreatureGroup(SUMMON_GHOUL_INVADER);

                    _events.ScheduleEvent(EVENT_WAVE_ATTACK, 3s);
                    break;
                case EVENT_SPAWN_WAVE_3:
                    MorlenTalk(SAY_MORLEN_4);

                    me->SummonCreatureGroup(SUMMON_CRYPT_RAIDER);

                    _events.ScheduleEvent(EVENT_WAVE_ATTACK, 3s);
                    break;
                case EVENT_WAVE_ATTACK:
                    for (auto& summon : _summons)
                    {
                        Creature* creature = ObjectAccessor::GetCreature(*me, summon);
                        if (!creature)
                            continue;

                        if (creature->GetEntry() == NPC_THALORIEN_DAWNSEEKER ||
                            creature->GetEntry() == NPC_MORLEN_GOLDGRIP)
                            continue;

                        creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
                            creature->AI()->AttackStart(thalorien);
                    }

                    break;
                case EVENT_MORLEN_2:
                    MorlenTalk(SAY_MORLEN_5);

                    _events.ScheduleEvent(EVENT_MORLEN_ATTACK, 1s);
                    break;
                case EVENT_MORLEN_ATTACK:
                    if (Creature* morlen = ObjectAccessor::GetCreature(*me, _morlenGUID))
                    {
                        morlen->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
                            morlen->AI()->AttackStart(thalorien);
                    }

                    break;
                case EVENT_OUTRO_1:
                    if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            thalorien->AI()->DoCast(player, SPELL_KILL_CREDIT);

                    ThalorienTalk(SAY_THALORIEN_7);

                    _events.ScheduleEvent(EVENT_OUTRO_2, 5s);
                    break;
                case EVENT_OUTRO_2:
                    ThalorienTalk(SAY_THALORIEN_8);

                    _events.ScheduleEvent(EVENT_OUTRO_3, 7s);
                    break;
                case EVENT_OUTRO_3:
                    if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
                        thalorien->AI()->DoCastSelf(SPELL_POLYMORPH_VISUAL);

                    ThalorienTalk(SAY_THALORIEN_9);

                    _events.ScheduleEvent(EVENT_OUTRO_4, 5s);
                    break;
                case EVENT_OUTRO_4:
                    ThalorienTalk(SAY_THALORIEN_10);

                    _events.ScheduleEvent(EVENT_KNEEL, 6s);
                    break;
                case EVENT_KNEEL:
                    if (Creature* thalorien = ObjectAccessor::GetCreature(*me, _thalorienGUID))
                    {
                        thalorien->SetStandState(UNIT_STAND_STATE_KNEEL);
                        thalorien->DespawnOrUnsummon(5s);
                    }

                    me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);

                    break;
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);

        if (_summons.size() == 2)
        {
            if (summon->GetEntry() == NPC_SCOURGE_ZOMBIE)
                _events.ScheduleEvent(EVENT_SPAWN_WAVE_2, 1s);
            else if (summon->GetEntry() == NPC_GHOUL_INVADER)
                _events.ScheduleEvent(EVENT_SPAWN_WAVE_3, 1s);
            else if (summon->GetEntry() == NPC_CRYPT_RAIDER)
                _events.ScheduleEvent(EVENT_MORLEN_2, 1s);
        }
        else if (_summons.size() == 1)
        {
            if (summon->GetEntry() == NPC_MORLEN_GOLDGRIP)
                _events.ScheduleEvent(EVENT_OUTRO_1, 2s);
        }
    }

private:
    EventMap _events;
    SummonList _summons;
    ObjectGuid _playerGUID;
    ObjectGuid _thalorienGUID;
    ObjectGuid _morlenGUID;
};

void AddSC_isle_of_queldanas()
{
    RegisterCreatureAI(npc_thalorien_dawnseeker);
}
