/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "precompiled.h"

/*######
## npc_a_special_surprise
######*/

enum SpecialSurprise
{
    SAY_EXEC_START_1            = -1609025,                 // speech for all
    SAY_EXEC_START_2            = -1609026,
    SAY_EXEC_START_3            = -1609027,
    SAY_EXEC_PROG_1             = -1609028,
    SAY_EXEC_PROG_2             = -1609029,
    SAY_EXEC_PROG_3             = -1609030,
    SAY_EXEC_PROG_4             = -1609031,
    SAY_EXEC_PROG_5             = -1609032,
    SAY_EXEC_PROG_6             = -1609033,
    SAY_EXEC_PROG_7             = -1609034,
    SAY_EXEC_NAME_1             = -1609035,
    SAY_EXEC_NAME_2             = -1609036,
    SAY_EXEC_RECOG_1            = -1609037,
    SAY_EXEC_RECOG_2            = -1609038,
    SAY_EXEC_RECOG_3            = -1609039,
    SAY_EXEC_RECOG_4            = -1609040,
    SAY_EXEC_RECOG_5            = -1609041,
    SAY_EXEC_RECOG_6            = -1609042,
    SAY_EXEC_NOREM_1            = -1609043,
    SAY_EXEC_NOREM_2            = -1609044,
    SAY_EXEC_NOREM_3            = -1609045,
    SAY_EXEC_NOREM_4            = -1609046,
    SAY_EXEC_NOREM_5            = -1609047,
    SAY_EXEC_NOREM_6            = -1609048,
    SAY_EXEC_NOREM_7            = -1609049,
    SAY_EXEC_NOREM_8            = -1609050,
    SAY_EXEC_NOREM_9            = -1609051,
    SAY_EXEC_THINK_1            = -1609052,
    SAY_EXEC_THINK_2            = -1609053,
    SAY_EXEC_THINK_3            = -1609054,
    SAY_EXEC_THINK_4            = -1609055,
    SAY_EXEC_THINK_5            = -1609056,
    SAY_EXEC_THINK_6            = -1609057,
    SAY_EXEC_THINK_7            = -1609058,
    SAY_EXEC_THINK_8            = -1609059,
    SAY_EXEC_THINK_9            = -1609060,
    SAY_EXEC_THINK_10           = -1609061,
    SAY_EXEC_LISTEN_1           = -1609062,
    SAY_EXEC_LISTEN_2           = -1609063,
    SAY_EXEC_LISTEN_3           = -1609064,
    SAY_EXEC_LISTEN_4           = -1609065,
    SAY_PLAGUEFIST              = -1609066,
    SAY_EXEC_TIME_1             = -1609067,
    SAY_EXEC_TIME_2             = -1609068,
    SAY_EXEC_TIME_3             = -1609069,
    SAY_EXEC_TIME_4             = -1609070,
    SAY_EXEC_TIME_5             = -1609071,
    SAY_EXEC_TIME_6             = -1609072,
    SAY_EXEC_TIME_7             = -1609073,
    SAY_EXEC_TIME_8             = -1609074,
    SAY_EXEC_TIME_9             = -1609075,
    SAY_EXEC_TIME_10            = -1609076,
    SAY_EXEC_WAITING            = -1609077,
    EMOTE_DIES                  = -1609078,

    NPC_PLAGUEFIST              = 29053
};

struct TRINITY_DLL_DECL npc_a_special_surpriseAI : public ScriptedAI
{
    npc_a_special_surpriseAI(Creature *pCreature) : ScriptedAI(pCreature) {}

    uint32 ExecuteSpeech_Timer;
    uint32 ExecuteSpeech_Counter;
    uint64 PlayerGUID;

    void Reset()
    {
        ExecuteSpeech_Timer = 0;
        ExecuteSpeech_Counter = 0;
        PlayerGUID = 0;

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
    }

    bool MeetQuestCondition(Unit* pPlayer)
    {
        switch(me->GetEntry())
        {
            case 29061:                                     // Ellen Stanbridge
                if (CAST_PLR(pPlayer)->GetQuestStatus(12742) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29072:                                     // Kug Ironjaw
                if (CAST_PLR(pPlayer)->GetQuestStatus(12748) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29067:                                     // Donovan Pulfrost
                if (CAST_PLR(pPlayer)->GetQuestStatus(12744) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29065:                                     // Yazmina Oakenthorn
                if (CAST_PLR(pPlayer)->GetQuestStatus(12743) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29071:                                     // Antoine Brack
                if (CAST_PLR(pPlayer)->GetQuestStatus(12750) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29032:                                     // Malar Bravehorn
                if (CAST_PLR(pPlayer)->GetQuestStatus(12739) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29068:                                     // Goby Blastenheimer
                if (CAST_PLR(pPlayer)->GetQuestStatus(12745) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29073:                                     // Iggy Darktusk
                if (CAST_PLR(pPlayer)->GetQuestStatus(12749) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29074:                                     // Lady Eonys
                if (CAST_PLR(pPlayer)->GetQuestStatus(12747) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
            case 29070:                                     // Valok the Righteous
                if (CAST_PLR(pPlayer)->GetQuestStatus(12746) == QUEST_STATUS_INCOMPLETE)
                    return true;
                break;
        }

        return false;
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        if (PlayerGUID || pWho->GetTypeId() != TYPEID_PLAYER || !pWho->IsWithinDist(me, INTERACTION_DISTANCE))
            return;

        if (MeetQuestCondition(pWho))
            PlayerGUID = pWho->GetGUID();
    }

    void UpdateAI(const uint32 diff) 
    {
        if (PlayerGUID && !me->getVictim() && me->isAlive())
        {
            if (ExecuteSpeech_Timer < diff)
            {
                Player* pPlayer = Unit::GetPlayer(PlayerGUID);

                if (!pPlayer)
                {
                    Reset();
                    return;
                }

                //TODO: simplify text's selection

                switch(pPlayer->getRace())
                {
                    case RACE_HUMAN:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_5, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_1, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_5, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_7, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_6, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_ORC:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_6, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_1, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_7, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_8, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_8, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_DWARF:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_2, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_2, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_3, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_2, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_5, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_2, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_3, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_NIGHTELF:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_5, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_1, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_6, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_2, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_7, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_UNDEAD_PLAYER:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_3, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_4, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_3, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_1, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_3, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_4, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_TAUREN:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_1, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_5, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_8, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_9, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_9, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_GNOME:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_4, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_1, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_4, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_6, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_5, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_TROLL:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_3, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_7, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_2, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_6, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_9, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_10, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_4, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_10, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_BLOODELF:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_1, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_1, me, pPlayer); break;
                            //case 5: //unknown
                            case 6: DoScriptText(SAY_EXEC_THINK_3, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_1, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
                    case RACE_DRAENEI:
                        switch(ExecuteSpeech_Counter)
                        {
                            case 0: DoScriptText(SAY_EXEC_START_1, me, pPlayer); break;
                            case 1: me->SetStandState(UNIT_STAND_STATE_STAND); break;
                            case 2: DoScriptText(SAY_EXEC_PROG_1, me, pPlayer); break;
                            case 3: DoScriptText(SAY_EXEC_NAME_1, me, pPlayer); break;
                            case 4: DoScriptText(SAY_EXEC_RECOG_2, me, pPlayer); break;
                            case 5: DoScriptText(SAY_EXEC_NOREM_1, me, pPlayer); break;
                            case 6: DoScriptText(SAY_EXEC_THINK_4, me, pPlayer); break;
                            case 7: DoScriptText(SAY_EXEC_LISTEN_1, me, pPlayer); break;
                            case 8:
                                if (Creature* Plaguefist = GetClosestCreatureWithEntry(me, NPC_PLAGUEFIST, 85.0f))
                                    DoScriptText(SAY_PLAGUEFIST, Plaguefist, pPlayer);
                                break;
                            case 9:
                                DoScriptText(SAY_EXEC_TIME_2, me, pPlayer);
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                                break;
                            case 10: DoScriptText(SAY_EXEC_WAITING, me, pPlayer); break;
                            case 11:
                                DoScriptText(EMOTE_DIES, me);
                                me->setDeathState(JUST_DIED);
                                me->SetHealth(0);
                                return;
                        }
                        break;
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

CreatureAI* GetAI_npc_a_special_surprise(Creature* pCreature)
{
    return new npc_a_special_surpriseAI(pCreature);
}

/*####
## npc_valkyr_battle_maiden
####*/
#define SPELL_REVIVE 51918
#define VALK_WHISPER "It is not yet your time, champion. Rise! Rise and fight once more!"

struct TRINITY_DLL_DECL npc_valkyr_battle_maidenAI : public PassiveAI
{
    npc_valkyr_battle_maidenAI(Creature *c) : PassiveAI(c) {}

    uint32 FlyBackTimer;
    float x, y, z;
    uint32 phase;

    void Reset()
    {
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlying(true);
        FlyBackTimer = 500;
        phase = 0;

        m_creature->GetPosition(x, y, z);
        z += 4; x -= 3.5; y -= 5;
        m_creature->GetMotionMaster()->Clear(false);
        m_creature->GetMap()->CreatureRelocation(m_creature, x, y, z, 0.0f);
    }

    void UpdateAI(const uint32 diff)
    {
        if(FlyBackTimer < diff)
        {
            Player *plr = NULL;
            if(me->isSummon())
                if(Unit *summoner = CAST_SUM(me)->GetSummoner())
                    if(summoner->GetTypeId() == TYPEID_PLAYER)
                        plr = CAST_PLR(summoner);

            if(!plr)
                phase = 3;

            switch(phase)
            {
                case 0:
                    m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    m_creature->HandleEmoteCommand(EMOTE_STATE_FLYGRABCLOSED);
                    FlyBackTimer = 500;
                    break;
                case 1:
                    plr->GetClosePoint(x,y,z, m_creature->GetObjectSize());
                    z += 2.5; x -= 2; y -= 1.5;
                    m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
                    m_creature->SetUInt64Value(UNIT_FIELD_TARGET, plr->GetGUID());
                    m_creature->SetVisibility(VISIBILITY_ON);
                    FlyBackTimer = 4500;
                    break;
                case 2:
                    if (!plr->isRessurectRequested())
                    {
                        m_creature->HandleEmoteCommand(EMOTE_ONESHOT_CUSTOMSPELL01);
                        DoCast(plr, SPELL_REVIVE, true);
                        m_creature->MonsterWhisper(VALK_WHISPER, plr->GetGUID());
                    }
                    FlyBackTimer = 5000;
                    break;
                case 3:
                    me->DisappearAndDie();
                    break;
                default: 
                    //Nothing To DO
                    break;
            }
            ++phase;
        }else FlyBackTimer-=diff;
    }
};

CreatureAI* GetAI_npc_valkyr_battle_maiden(Creature* pCreature)
{
    return new npc_valkyr_battle_maidenAI (pCreature);
}


void AddSC_the_scarlet_enclave()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_valkyr_battle_maiden";
    newscript->GetAI = &GetAI_npc_valkyr_battle_maiden;
    newscript->RegisterSelf();

    // A Special Suprise
    newscript = new Script;
    newscript->Name = "npc_a_special_surprise";
    newscript->GetAI = &GetAI_npc_a_special_surprise;
    newscript->RegisterSelf();
}
