/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
    EVENT_INTRO_0       = 1,
    EVENT_INTRO_1       = 2,
    EVENT_INTRO_2       = 3,
    EVENT_INTRO_3       = 4,
    EVENT_SALUTE        = 5,
    EVENT_DEFENDERS_RUN = 6,
    EVENT_THALORIEN_GO  = 7,
    EVENT_INTRO_4       = 8,
    EVENT_SUMMON_MORLEN = 9,
    EVENT_INTRO_5       = 10,
    EVENT_MORLEN_1      = 11,
    EVENT_SPAWN_WAVE_1  = 12,
    EVENT_SPAWN_WAVE_2  = 13,
    EVENT_SPAWN_WAVE_3  = 14,
    EVENT_WAVE_ATTACK   = 15,
    EVENT_MORLEN_2      = 16,
    EVENT_MORLEN_ATTACK = 17,
    EVENT_OUTRO_1       = 18,
    EVENT_OUTRO_2       = 19,
    EVENT_OUTRO_3       = 20,
    EVENT_OUTRO_4       = 21,
    EVENT_KNEEL         = 22
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

Position const thalorienSummon = { 11795.32f, -7070.476f, 26.27511f, 5.67232f  };
Position const thalorienFight = { 11788.46f, -7063.375f, 25.79677f, 3.054326f };
Position const morlenSummon = { 11766.46f, -7050.078f, 26.19846f, 5.637414f  };

class npc_thalorien_dawnseeker : public CreatureScript
{
public:
    npc_thalorien_dawnseeker() : CreatureScript("npc_thalorien_dawnseeker") { }

    struct npc_thalorien_dawnseekerAI : public ScriptedAI
    {
        npc_thalorien_dawnseekerAI(Creature* creature) : ScriptedAI(creature), _summons(me) { }

        bool GossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
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
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                if (Creature* thalorien = me->SummonCreature(NPC_THALORIEN_DAWNSEEKER, thalorienSummon, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    _thalorien = thalorien;
                me->SummonCreatureGroup(SUMMON_SUNWELL_DEFENDER);

                _events.ScheduleEvent(EVENT_INTRO_0, 3s);
            }
        }

        void Reset() override
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            _summons.DespawnAll();
            _playerGUID.Clear();
            _events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_0:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_1);

                        _events.ScheduleEvent(EVENT_INTRO_1, 5s);
                        break;
                    case EVENT_INTRO_1:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_2);

                        _events.ScheduleEvent(EVENT_INTRO_2, 6s);
                        break;
                    case EVENT_INTRO_2:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_3);

                        _events.ScheduleEvent(EVENT_INTRO_3, 7s);
                        break;

                    case EVENT_INTRO_3:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_4);

                        _events.ScheduleEvent(EVENT_SALUTE, 4s);
                        break;
                    case EVENT_SALUTE:
                        if (_thalorien)
                            _thalorien->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);

                        for (auto& summon : _summons)
                            if (Creature* defender = ObjectAccessor::GetCreature(*me, summon))
                                defender->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);

                        _events.ScheduleEvent(EVENT_DEFENDERS_RUN, 3s);
                        break;
                    case EVENT_DEFENDERS_RUN:
                        for (auto& summon : _summons)
                            if (Creature* creature = ObjectAccessor::GetCreature(*me, summon))
                                if (creature->GetEntry() == NPC_SUNWELL_DEFENDER)
                                    creature->GetMotionMaster()->MovePoint(0, 11863.35f, -7073.44f, 27.40f);

                        _events.ScheduleEvent(EVENT_THALORIEN_GO, 1s);
                        break;
                    case EVENT_THALORIEN_GO:
                        if (_thalorien)
                        {
                            _thalorien->SetWalk(true);
                            _thalorien->GetMotionMaster()->MovePoint(0, thalorienFight);
                            _thalorien->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                            _thalorien->SetHomePosition(thalorienFight);
                        }

                        _events.ScheduleEvent(EVENT_INTRO_4, 4s);
                        break;
                    case EVENT_INTRO_4:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_5);

                        _events.ScheduleEvent(EVENT_SUMMON_MORLEN, 6s);
                        _events.ScheduleEvent(EVENT_INTRO_5, 9s);
                        break;
                    case EVENT_INTRO_5:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_6);

                        _events.ScheduleEvent(EVENT_MORLEN_1, 6s);
                        break;
                    case EVENT_SUMMON_MORLEN:
                        if (Creature* morlen = me->SummonCreature(NPC_MORLEN_GOLDGRIP, morlenSummon, TEMPSUMMON_CORPSE_DESPAWN, 0))
                            _morlen = morlen;
                            _morlen->AI()->DoCastSelf(SPELL_BLOOD_PRESENCE);

                        break;
                    case EVENT_MORLEN_1:
                        if (_morlen)
                            _morlen->AI()->Talk(SAY_MORLEN_1);

                        _events.ScheduleEvent(EVENT_SPAWN_WAVE_1, 7s);
                        break;
                    case EVENT_SPAWN_WAVE_1:
                        if (_morlen)
                            _morlen->AI()->Talk(SAY_MORLEN_2);

                        me->SummonCreatureGroup(SUMMON_SCOURGE_ZOMBIE);

                        _events.ScheduleEvent(EVENT_WAVE_ATTACK, 3s);
                        break;
                    case EVENT_SPAWN_WAVE_2:
                        if (_morlen)
                            _morlen->AI()->Talk(SAY_MORLEN_3);

                        me->SummonCreatureGroup(SUMMON_GHOUL_INVADER);

                        _events.ScheduleEvent(EVENT_WAVE_ATTACK, 3s);
                        break;
                    case EVENT_SPAWN_WAVE_3:
                        if (_morlen)
                            _morlen->AI()->Talk(SAY_MORLEN_4);

                        me->SummonCreatureGroup(SUMMON_CRYPT_RAIDER);

                        _events.ScheduleEvent(EVENT_WAVE_ATTACK, 3s);
                        break;
                    case EVENT_WAVE_ATTACK:
                        for (auto& summon : _summons)
                        {
                            Creature* creature = ObjectAccessor::GetCreature(*me, summon);
                            if (!creature)
                                continue;

                            if (creature->GetEntry() == NPC_THALORIEN_DAWNSEEKER || creature->GetEntry() == NPC_MORLEN_GOLDGRIP)
                                continue;

                            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            if (_thalorien)
                                creature->AI()->AttackStart(_thalorien);
                        }

                        break;
                    case EVENT_MORLEN_2:
                        if (_morlen)
                            _morlen->AI()->Talk(SAY_MORLEN_5);

                        _events.ScheduleEvent(EVENT_MORLEN_ATTACK, 1s);
                        break;
                    case EVENT_MORLEN_ATTACK:
                        if (_morlen)
                            _morlen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            if (_thalorien)
                                _morlen->AI()->AttackStart(_thalorien);

                        break;
                    case EVENT_OUTRO_1:
                        if (_thalorien)
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                                _thalorien->AI()->DoCast(player, SPELL_KILL_CREDIT);

                            _thalorien->AI()->Talk(SAY_THALORIEN_7);
                        }

                        _events.ScheduleEvent(EVENT_OUTRO_2, 5s);
                        break;
                    case EVENT_OUTRO_2:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_8);

                        _events.ScheduleEvent(EVENT_OUTRO_3, 7s);
                        break;
                    case EVENT_OUTRO_3:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_9);
                            _thalorien->AI()->DoCastSelf(SPELL_POLYMORPH_VISUAL);

                        _events.ScheduleEvent(EVENT_OUTRO_4, 5s);
                        break;
                    case EVENT_OUTRO_4:
                        if (_thalorien)
                            _thalorien->AI()->Talk(SAY_THALORIEN_10);

                        _events.ScheduleEvent(EVENT_KNEEL, 6s);
                        break;
                    case EVENT_KNEEL:
                        if (_thalorien)
                            _thalorien->SetStandState(UNIT_STAND_STATE_KNEEL);
                            _thalorien->DespawnOrUnsummon(5 * IN_MILLISECONDS);

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
        Creature* _thalorien;
        Creature* _morlen;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_thalorien_dawnseekerAI(creature);
    }
};

void AddSC_isle_of_queldanas()
{
    new npc_thalorien_dawnseeker();
}
