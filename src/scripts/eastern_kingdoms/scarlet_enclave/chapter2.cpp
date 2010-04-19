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

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"

//How to win friends and influence enemies
// texts signed for creature 28939 but used for 28939,28940,28610
enum win_friends
{
    SAY_PERSUADE1                     = -1609501,
    SAY_PERSUADE2                     = -1609502,
    SAY_PERSUADE3                     = -1609503,
    SAY_PERSUADE4                     = -1609504,
    SAY_PERSUADE5                     = -1609505,
    SAY_PERSUADE6                     = -1609506,
    SAY_PERSUADE7                     = -1609507,
    SAY_CRUSADER1                     = -1609508,
    SAY_CRUSADER2                     = -1609509,
    SAY_CRUSADER3                     = -1609510,
    SAY_CRUSADER4                     = -1609511,
    SAY_CRUSADER5                     = -1609512,
    SAY_CRUSADER6                     = -1609513,
    SAY_PERSUADED1                    = -1609514,
    SAY_PERSUADED2                    = -1609515,
    SAY_PERSUADED3                    = -1609516,
    SAY_PERSUADED4                    = -1609517,
    SAY_PERSUADED5                    = -1609518,
    SAY_PERSUADED6                    = -1609519,
    SPELL_PERSUASIVE_STRIKE           = 52781
};

struct npc_crusade_persuadedAI : public ScriptedAI
{
    npc_crusade_persuadedAI(Creature *pCreature) : ScriptedAI(pCreature) {}

    uint32 uiSpeech_timer;
    uint32 uiSpeech_counter;
    uint64 uiPlayerGUID;

    void Reset()
    {
        uiSpeech_timer = 0;
        uiSpeech_counter = 0;
        uiPlayerGUID = 0;
        me->SetReactState(REACT_AGGRESSIVE);
        me->RestoreFaction();
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_PERSUASIVE_STRIKE && caster->GetTypeId() == TYPEID_PLAYER && me->isAlive() && !uiSpeech_counter)
        {
            if (CAST_PLR(caster)->GetQuestStatus(12720) == QUEST_STATUS_INCOMPLETE)
            {
                uiPlayerGUID = caster->GetGUID();
                uiSpeech_timer = 1000;
                uiSpeech_counter = 1;
                me->setFaction(caster->getFaction());
                me->CombatStop(true);
                me->GetMotionMaster()->MoveIdle();
                me->SetReactState(REACT_PASSIVE);
                DoCastAOE(58111, true);

                DoScriptText(RAND(SAY_PERSUADE1,SAY_PERSUADE2,SAY_PERSUADE3,
                                  SAY_PERSUADE4,SAY_PERSUADE5,SAY_PERSUADE6,
                                  SAY_PERSUADE7), caster);

                DoScriptText(RAND(SAY_CRUSADER1,SAY_CRUSADER2,SAY_CRUSADER3,
                                  SAY_CRUSADER4,SAY_CRUSADER5,SAY_CRUSADER6), me);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiSpeech_counter)
        {
            if (uiSpeech_timer <= diff)
            {
                Player* pPlayer = Unit::GetPlayer(uiPlayerGUID);
                if (!pPlayer)
                {
                    EnterEvadeMode();
                    return;
                }

                switch(uiSpeech_counter)
                {
                    case 1: DoScriptText(SAY_PERSUADED1, me); uiSpeech_timer = 8000; break;
                    case 2: DoScriptText(SAY_PERSUADED2, me); uiSpeech_timer = 8000; break;
                    case 3: DoScriptText(SAY_PERSUADED3, me); uiSpeech_timer = 8000; break;
                    case 4: DoScriptText(SAY_PERSUADED4, me); uiSpeech_timer = 8000; break;
                    case 5: DoScriptText(SAY_PERSUADED5, pPlayer); uiSpeech_timer = 8000; break;
                    case 6: DoScriptText(SAY_PERSUADED6, me);
                        pPlayer->Kill(me);
                        //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        uiSpeech_counter = 0;
                        pPlayer->GroupEventHappens(12720, me);
                        return;
                }

                ++uiSpeech_counter;
                DoCastAOE(58111, true);
            } else uiSpeech_timer -= diff;

            return;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_crusade_persuaded(Creature* pCreature)
{
    return new npc_crusade_persuadedAI (pCreature);
}

/*######
## npc_koltira_deathweaver
######*/

enum eKoltira
{
    SAY_BREAKOUT1                   = -1609561,
    SAY_BREAKOUT2                   = -1609562,
    SAY_BREAKOUT3                   = -1609563,
    SAY_BREAKOUT4                   = -1609564,
    SAY_BREAKOUT5                   = -1609565,
    SAY_BREAKOUT6                   = -1609566,
    SAY_BREAKOUT7                   = -1609567,
    SAY_BREAKOUT8                   = -1609568,
    SAY_BREAKOUT9                   = -1609569,
    SAY_BREAKOUT10                  = -1609570,

    SPELL_KOLTIRA_TRANSFORM         = 52899,
    SPELL_ANTI_MAGIC_ZONE           = 52894,

    QUEST_BREAKOUT                  = 12727,

    NPC_CRIMSON_ACOLYTE             = 29007,
    NPC_HIGH_INQUISITOR_VALROTH     = 29001,
    NPC_KOLTIRA_ALT                 = 28447,

    //not sure about this id
    //NPC_DEATH_KNIGHT_MOUNT          = 29201,
    MODEL_DEATH_KNIGHT_MOUNT        = 25278
};

struct npc_koltira_deathweaverAI : public npc_escortAI
{
    npc_koltira_deathweaverAI(Creature *pCreature) : npc_escortAI(pCreature)
    {
        me->SetReactState(REACT_DEFENSIVE);
    }

    uint32 m_uiWave;
    uint32 m_uiWave_Timer;
    uint64 m_uiValrothGUID;

    void Reset()
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiWave = 0;
            m_uiWave_Timer = 3000;
            m_uiValrothGUID = 0;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->LoadEquipment(0, true);
            me->RemoveAura(SPELL_ANTI_MAGIC_ZONE);
        }
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 0:
                DoScriptText(SAY_BREAKOUT1, me);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                break;
            case 1:
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;
            case 2:
                me->SetStandState(UNIT_STAND_STATE_STAND);
                //me->UpdateEntry(NPC_KOLTIRA_ALT); //unclear if we must update or not
                DoCast(me, SPELL_KOLTIRA_TRANSFORM);
                me->LoadEquipment(me->GetEquipmentId());
                break;
            case 3:
                SetEscortPaused(true);
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                DoScriptText(SAY_BREAKOUT2, me);
                DoCast(me, SPELL_ANTI_MAGIC_ZONE);  // cast again that makes bubble up
                break;
            case 4:
                SetRun(true);
                break;
            case 9:
                me->Mount(MODEL_DEATH_KNIGHT_MOUNT);
                break;
            case 10:
                me->Unmount();
                break;
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (Player* pPlayer = GetPlayerForEscort())
        {
            pSummoned->AI()->AttackStart(pPlayer);
        }

        if (pSummoned->GetEntry() == NPC_HIGH_INQUISITOR_VALROTH)
            m_uiValrothGUID = pSummoned->GetGUID();

        pSummoned->AddThreat(me, 0.0f);
        pSummoned->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    void SummonAcolyte(uint32 uiAmount)
    {
        for (uint32 i = 0; i < uiAmount; ++i)
            me->SummonCreature(NPC_CRIMSON_ACOLYTE, 1642.329, -6045.818, 127.583, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (HasEscortState(STATE_ESCORT_PAUSED))
        {
            if (m_uiWave_Timer <= uiDiff)
            {
                switch(m_uiWave)
                {
                    case 0:
                        DoScriptText(SAY_BREAKOUT3, me);
                        SummonAcolyte(3);
                        m_uiWave_Timer = 20000;
                        break;
                    case 1:
                        DoScriptText(SAY_BREAKOUT4, me);
                        SummonAcolyte(3);
                        m_uiWave_Timer = 20000;
                        break;
                    case 2:
                        DoScriptText(SAY_BREAKOUT5, me);
                        SummonAcolyte(4);
                        m_uiWave_Timer = 20000;
                        break;
                    case 3:
                        DoScriptText(SAY_BREAKOUT6, me);
                        me->SummonCreature(NPC_HIGH_INQUISITOR_VALROTH, 1642.329, -6045.818, 127.583, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
                        m_uiWave_Timer = 1000;
                        break;
                    case 4:
                    {
                        Creature* pTemp = Unit::GetCreature(*me, m_uiValrothGUID);

                        if (!pTemp || !pTemp->isAlive())
                        {
                            DoScriptText(SAY_BREAKOUT8, me);
                            m_uiWave_Timer = 5000;
                        }
                        else
                        {
                            m_uiWave_Timer = 2500;
                            return;                         //return, we don't want m_uiWave to increment now
                        }
                        break;
                    }
                    case 5:
                        DoScriptText(SAY_BREAKOUT9, me);
                        me->RemoveAurasDueToSpell(SPELL_ANTI_MAGIC_ZONE);
                        // i do not know why the armor will also be removed
                        m_uiWave_Timer = 2500;
                        break;
                    case 6:
                        DoScriptText(SAY_BREAKOUT10, me);
                        SetEscortPaused(false);
                        break;
                }

                ++m_uiWave;
            }
            else
                m_uiWave_Timer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_koltira_deathweaver(Creature* pCreature)
{
    return new npc_koltira_deathweaverAI(pCreature);
}

bool QuestAccept_npc_koltira_deathweaver(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_BREAKOUT)
    {
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);

        if (npc_escortAI* pEscortAI = CAST_AI(npc_koltira_deathweaverAI,pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID());
    }
    return true;
}

//Scarlet courier
enum ScarletCourierEnum
{
    SAY_TREE1                          = -1609531,
    SAY_TREE2                          = -1609532,
    SPELL_SHOOT                        = 52818,
    GO_INCONSPICUOUS_TREE              = 191144,
    NPC_SCARLET_COURIER                = 29076
};

struct mob_scarlet_courierAI : public ScriptedAI
{
    mob_scarlet_courierAI(Creature *pCreature) : ScriptedAI(pCreature) {}

    uint32 uiStage;
    uint32 uiStage_timer;

    void Reset()
    {
        me->Mount(14338); // not sure about this id
        uiStage = 1;
        uiStage_timer = 3000;
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_TREE2, me);
        me->Unmount();
        uiStage = 0;
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
            uiStage = 2;
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiStage && !me->isInCombat())
        {
            if (uiStage_timer <= diff)
            {
                switch(uiStage)
                {
                case 1:
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    if (GameObject* tree = me->FindNearestGameObject(GO_INCONSPICUOUS_TREE, 40.0f))
                    {
                        DoScriptText(SAY_TREE1, me);
                        float x, y, z;
                        tree->GetContactPoint(me, x, y, z);
                        me->GetMotionMaster()->MovePoint(1, x, y, z);
                    }
                    break;
                case 2:
                    if (GameObject* tree = me->FindNearestGameObject(GO_INCONSPICUOUS_TREE, 40.0f))
                        if (Unit *unit = tree->GetOwner())
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

CreatureAI* GetAI_mob_scarlet_courier(Creature* pCreature)
{
    return new mob_scarlet_courierAI (pCreature);
}

//Koltira & Valroth- Breakout

enum valroth
{
    SAY_VALROTH1                      = -1609581,
    SAY_VALROTH2                      = -1609582,
    SAY_VALROTH3                      = -1609583,
    SAY_VALROTH4                      = -1609584,
    SAY_VALROTH5                      = -1609585,
    SAY_VALROTH6                      = -1609586,
    SPELL_RENEW                       = 38210,
    SPELL_INQUISITOR_PENANCE          = 52922,
    SPELL_VALROTH_SMITE               = 52926,
    SPELL_SUMMON_VALROTH_REMAINS      = 52929
};

struct mob_high_inquisitor_valrothAI : public ScriptedAI
{
    mob_high_inquisitor_valrothAI(Creature *pCreature) : ScriptedAI(pCreature) {}

    uint32 uiRenew_timer;
    uint32 uiInquisitor_Penance_timer;
    uint32 uiValroth_Smite_timer;

    void Reset()
    {
        uiRenew_timer = 1000;
        uiInquisitor_Penance_timer = 2000;
        uiValroth_Smite_timer = 1000;
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_VALROTH2, me);
        DoCast(who, SPELL_VALROTH_SMITE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiRenew_timer <= diff)
        {
            Shout();
            DoCast(me, SPELL_RENEW);
            uiRenew_timer = 1000 + rand()%5000;
        } else uiRenew_timer -= diff;

        if (uiInquisitor_Penance_timer <= diff)
        {
            Shout();
            DoCast(me->getVictim(), SPELL_INQUISITOR_PENANCE);
            uiInquisitor_Penance_timer = 2000 + rand()%5000;
        } else uiInquisitor_Penance_timer -= diff;

        if (uiValroth_Smite_timer <= diff)
        {
            Shout();
            DoCast(me->getVictim(), SPELL_VALROTH_SMITE);
            uiValroth_Smite_timer = 1000 + rand()%5000;
        } else uiValroth_Smite_timer -= diff;

        DoMeleeAttackIfReady();
    }

    void Shout()
    {
        if (rand()%100 < 15)
            DoScriptText(RAND(SAY_VALROTH3,SAY_VALROTH4,SAY_VALROTH5), me);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_VALROTH6, me);
        killer->CastSpell(me, SPELL_SUMMON_VALROTH_REMAINS, true);
    }
};

CreatureAI* GetAI_mob_high_inquisitor_valroth(Creature* pCreature)
{
    return new mob_high_inquisitor_valrothAI (pCreature);
}

/*######
## npc_a_special_surprise
######*/
//used by 29032,29061,29065,29067,29068,29070,29074,29072,29073,29071 but signed for 29032
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

struct npc_a_special_surpriseAI : public ScriptedAI
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

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
            if (ExecuteSpeech_Timer <= diff)
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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

void AddSC_the_scarlet_enclave_c2()
{
    Script *newscript;

    // How to win friends and influence enemies
    newscript = new Script;
    newscript->Name = "npc_crusade_persuaded";
    newscript->GetAI = &GetAI_npc_crusade_persuaded;
    newscript->RegisterSelf();

    // Ambush At The Overlook
    newscript = new Script;
    newscript->Name = "mob_scarlet_courier";
    newscript->GetAI = &GetAI_mob_scarlet_courier;
    newscript->RegisterSelf();

    // 12727 Bloody Breakout
    newscript = new Script;
    newscript->Name = "npc_koltira_deathweaver";
    newscript->GetAI = &GetAI_npc_koltira_deathweaver;
    newscript->pQuestAccept = &QuestAccept_npc_koltira_deathweaver;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_high_inquisitor_valroth";
    newscript->GetAI = &GetAI_mob_high_inquisitor_valroth;
    newscript->RegisterSelf();

    // A Special Suprise
    newscript = new Script;
    newscript->Name = "npc_a_special_surprise";
    newscript->GetAI = &GetAI_npc_a_special_surprise;
    newscript->RegisterSelf();
}

/*
-- Bloody Breakout
UPDATE `creature_template` SET `ScriptName`='npc_koltira_deathweaver' WHERE `entry`='28912';
UPDATE `creature_template` SET `ScriptName`='mob_high_inquisitor_valroth',minmana=6489,maxmana=6489,unit_flags=32768 WHERE `entry`='29001';
UPDATE `creature_template` SET `ScriptName`='mob_eventai', `AIName`='EventAI',minmana=1020,maxmana=1058,unit_flags=32768 WHERE (`entry`='29007');
DELETE FROM creature_ai_scripts WHERE id BETWEEN 90030 AND 90033;
INSERT INTO `creature_ai_scripts` VALUES ('90030', '29007', '0', '0', '100', '1', '1000', '4000', '1000', '4000', '11', '15498', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Crimson Acolyte - Holy Smite');
INSERT INTO `creature_ai_scripts` VALUES ('90031', '29007', '0', '0', '100', '1', '1000', '10000', '20000', '21000', '11', '34809', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Crimson Acolyte - Holy Fury');
INSERT INTO `creature_ai_scripts` VALUES ('90032', '29007', '0', '0', '100', '1', '1000', '5000', '1000', '5000', '11', '19725', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Crimson Acolyte - Turn Undead');
INSERT INTO `creature_ai_scripts` VALUES ('90033', '29007', '4', '0', '100', '0', '0', '0', '0', '0', '11', '15498', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Crimson Acolyte aggro');
*/
