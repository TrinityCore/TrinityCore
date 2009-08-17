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
#include "escort_ai.h"

//How to win friends and influence enemies
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

struct TRINITY_DLL_DECL npc_crusade_persuadedAI : public ScriptedAI
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
            if(CAST_PLR(caster)->GetQuestStatus(12720) == QUEST_STATUS_INCOMPLETE)
            {
                uiPlayerGUID = caster->GetGUID();
                uiSpeech_timer = 1000;
                uiSpeech_counter = 1;
                me->setFaction(caster->getFaction());
                me->CombatStop(true);
                me->GetMotionMaster()->MoveIdle();
                me->SetReactState(REACT_PASSIVE);
                DoCastAOE(58111, true);

                switch(rand()%6)
                {
                    case 0: DoScriptText(SAY_PERSUADE1, caster);break;
                    case 1: DoScriptText(SAY_PERSUADE2, caster);break;
                    case 2: DoScriptText(SAY_PERSUADE3, caster);break;
                    case 3: DoScriptText(SAY_PERSUADE4, caster);break;
                    case 4: DoScriptText(SAY_PERSUADE5, caster);break;
                    case 5: DoScriptText(SAY_PERSUADE6, caster);break;
                    case 6: DoScriptText(SAY_PERSUADE7, caster);break;
                }

                switch(rand()%5)
                {
                    case 0: DoScriptText(SAY_CRUSADER1, me);break;
                    case 1: DoScriptText(SAY_CRUSADER2, me);break;
                    case 2: DoScriptText(SAY_CRUSADER3, me);break;
                    case 3: DoScriptText(SAY_CRUSADER4, me);break;
                    case 4: DoScriptText(SAY_CRUSADER5, me);break;
                    case 5: DoScriptText(SAY_CRUSADER6, me);break;
                }
            }
        }
    }

    void UpdateAI(const uint32 diff) 
    {
        if (uiSpeech_counter)
        {
            if (uiSpeech_timer < diff)
            {
                Player* pPlayer = Unit::GetPlayer(uiPlayerGUID);
                if(!pPlayer)
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
            }else uiSpeech_timer -= diff;

            return;
        }
        
        if(!UpdateVictim())
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

struct TRINITY_DLL_DECL npc_koltira_deathweaverAI : public npc_escortAI
{
    npc_koltira_deathweaverAI(Creature *pCreature) : npc_escortAI(pCreature) { }

    uint32 m_uiWave;
    uint32 m_uiWave_Timer;
    uint64 m_uiValrothGUID;

    void Reset()
    {
        if (!IsBeingEscorted)
        {
            m_uiWave = 0;
            m_uiWave_Timer = 3000;
            m_uiValrothGUID = 0;
        }
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 0:
                DoScriptText(SAY_BREAKOUT1, me);
                break;
            case 1:
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;
            case 2:
                me->SetStandState(UNIT_STAND_STATE_STAND);
                //me->UpdateEntry(NPC_KOLTIRA_ALT); //unclear if we must update or not
                DoCast(me, SPELL_KOLTIRA_TRANSFORM);
                break;
            case 3:
                IsOnHold = true;
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
            pSummoned->AddThreat(me, 0.0f);
        }

        if (pSummoned->GetEntry() == NPC_HIGH_INQUISITOR_VALROTH)
            m_uiValrothGUID = pSummoned->GetGUID();
    }

    void SummonAcolyte(uint32 uiAmount)
    {
        for(uint32 i = 0; i < uiAmount; ++i)
            me->SummonCreature(NPC_CRIMSON_ACOLYTE, 1642.329, -6045.818, 127.583, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (IsOnHold)
        {
            if (m_uiWave_Timer < uiDiff)
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
                        Unit* pTemp = Unit::GetUnit(*me, m_uiValrothGUID);

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
                        m_uiWave_Timer = 2500;
                        break;
                    case 6:
                        DoScriptText(SAY_BREAKOUT10, me);
                        IsOnHold = false;
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

struct TRINITY_DLL_DECL mob_scarlet_courierAI : public ScriptedAI
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

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_TREE2, me);
        me->Unmount();
        uiStage = 0;
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;

        if(id == 1)
            uiStage = 2;
    }

    void UpdateAI(const uint32 diff) 
    {
        if(uiStage && !me->isInCombat())
        {
            if (uiStage_timer < diff)
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
                        if(Unit *unit = tree->GetOwner())
                            AttackStart(unit);
                    break;
                }
                uiStage_timer = 3000;
                uiStage = 0;
            }else uiStage_timer -= diff;
        }

        if(!UpdateVictim())
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

struct TRINITY_DLL_DECL mob_high_inquisitor_valrothAI : public ScriptedAI
{
    mob_high_inquisitor_valrothAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 uiRenew_timer;
    uint32 uiInquisitor_Penance_timer;
    uint32 uiValroth_Smite_timer;

    void Reset() {
        uiRenew_timer = 1000;
        uiInquisitor_Penance_timer = 2000;
        uiValroth_Smite_timer = 1000;
    }

    void Aggro(Unit* who){
        DoScriptText(SAY_VALROTH2, me);
        DoCast(who, SPELL_VALROTH_SMITE);
    }

    void UpdateAI(const uint32 diff) 
    {
        if (uiRenew_timer < diff)
        {
            Shout();
            DoCast(me, SPELL_RENEW);
            uiRenew_timer = 1000 + rand()%5000;
        }else uiRenew_timer -= diff;

        if (uiInquisitor_Penance_timer < diff)
        {
            Shout();
            DoCast(me->getVictim(), SPELL_INQUISITOR_PENANCE);
            uiInquisitor_Penance_timer = 2000 + rand()%5000;
        }else uiInquisitor_Penance_timer -= diff;

        if (uiValroth_Smite_timer < diff)
        {
            Shout();
            DoCast(me->getVictim(), SPELL_VALROTH_SMITE);
            uiValroth_Smite_timer = 1000 + rand()%5000;
        }else uiValroth_Smite_timer -= diff;

        DoMeleeAttackIfReady();
    }

    void Shout()
    {
        switch(rand()%20)
        {
            case 0: DoScriptText(SAY_VALROTH3, me);break;
            case 1: DoScriptText(SAY_VALROTH4, me);break;
            case 2: DoScriptText(SAY_VALROTH5, me);break;
        }
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

//Light of Dawn
enum mograine
{
    ENCOUNTER_DK_NUMBER               = 5,  // how many player queue to start the quest , or -
    ENCOUNTER_DK_TIMER                = 10, // *every 5 minutes. These have to be done in instance data
    ENCOUNTER_DEFENDER_NUMBER         = 20, // how many of defender
    ENCOUNTER_EARTHSHATTER_NUMBER     = 20, // how many of earthshatter
    ENCOUNTER_ABOMINATION_NUMBER      = 3,  // how many of abomination
    ENCOUNTER_BEHEMOTH_NUMBER         = 2,  // how many of behemoth
    ENCOUNTER_GHOUL_NUMBER            = 10, // how many of ghoul
    ENCOUNTER_WARRIOR_NUMBER          = 2,  // how many of warrior
    ENCOUNTER_TOTAL_DAWN              = 300,  // Total number
    ENCOUNTER_TOTAL_SCOURGE           = 10000,

    WORLD_STATE_REMAINS               = 3592,
    WORLD_STATE_COUNTDOWN             = 3603,
    WORLD_STATE_EVENT_BEGIN           = 3605,

    SAY_LIGHT_OF_DAWN01               = -1609201, // pre text
    SAY_LIGHT_OF_DAWN02               = -1609202,
    SAY_LIGHT_OF_DAWN03               = -1609203,
    SAY_LIGHT_OF_DAWN04               = -1609204, // intro
    SAY_LIGHT_OF_DAWN05               = -1609205,
    SAY_LIGHT_OF_DAWN06               = -1609206,
    SAY_LIGHT_OF_DAWN07               = -1609207, // During the fight - Korfax, Champion of the Light
    SAY_LIGHT_OF_DAWN08               = -1609208, // Lord Maxwell Tyrosus
    SAY_LIGHT_OF_DAWN09               = -1609209, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN10               = -1609210,
    SAY_LIGHT_OF_DAWN11               = -1609211,
    SAY_LIGHT_OF_DAWN12               = -1609212,
    SAY_LIGHT_OF_DAWN13               = -1609213,
    SAY_LIGHT_OF_DAWN14               = -1609214,
    SAY_LIGHT_OF_DAWN15               = -1609215,
    SAY_LIGHT_OF_DAWN16               = -1609216,
    SAY_LIGHT_OF_DAWN17               = -1609217,
    SAY_LIGHT_OF_DAWN18               = -1609218,
    SAY_LIGHT_OF_DAWN19               = -1609219,
    SAY_LIGHT_OF_DAWN20               = -1609220,
    SAY_LIGHT_OF_DAWN21               = -1609221,
    SAY_LIGHT_OF_DAWN22               = -1609222,
    SAY_LIGHT_OF_DAWN23               = -1609223,
    SAY_LIGHT_OF_DAWN24               = -1609224,
    SAY_LIGHT_OF_DAWN25               = -1609225, // After the fight
    SAY_LIGHT_OF_DAWN26               = -1609226, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN27               = -1609227, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN28               = -1609228, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN29               = -1609229, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN30               = -1609230, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN31               = -1609231, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN32               = -1609232, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN33               = -1609233, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN34               = -1609234, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN35               = -1609235, // Darion Mograine
    SAY_LIGHT_OF_DAWN36               = -1609236, // Darion Mograine
    SAY_LIGHT_OF_DAWN37               = -1609237, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN38               = -1609238, // Darion Mograine
    SAY_LIGHT_OF_DAWN39               = -1609239, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN40               = -1609240, // Darion Mograine
    SAY_LIGHT_OF_DAWN41               = -1609241, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN42               = -1609242, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN43               = -1609243, // The Lich King
    SAY_LIGHT_OF_DAWN44               = -1609244, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN45               = -1609245, // The Lich King
    SAY_LIGHT_OF_DAWN46               = -1609246, // The Lich King
    SAY_LIGHT_OF_DAWN47               = -1609247, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN48               = -1609248, // The Lich King
    SAY_LIGHT_OF_DAWN49               = -1609249, // The Lich King
    SAY_LIGHT_OF_DAWN50               = -1609250, // Lord Maxwell Tyrosus
    SAY_LIGHT_OF_DAWN51               = -1609251, // The Lich King
    SAY_LIGHT_OF_DAWN52               = -1609252, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN53               = -1609253, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN54               = -1609254, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN55               = -1609255, // The Lich King
    SAY_LIGHT_OF_DAWN56               = -1609256, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN57               = -1609257, // The Lich King
    SAY_LIGHT_OF_DAWN58               = -1609258, // The Lich King
    SAY_LIGHT_OF_DAWN59               = -1609259, // The Lich King
    SAY_LIGHT_OF_DAWN60               = -1609260, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN61               = -1609261, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN62               = -1609262, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN63               = -1609263, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN64               = -1609264, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN65               = -1609265, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN66               = -1609266, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN67               = -1609267, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN68               = -1609268, // Highlord Darion Mograine

    EMOTE_LIGHT_OF_DAWN01             = -1609269,  // Emotes
    EMOTE_LIGHT_OF_DAWN02             = -1609270,
    EMOTE_LIGHT_OF_DAWN03             = -1609271,
    EMOTE_LIGHT_OF_DAWN04             = -1609272,
    EMOTE_LIGHT_OF_DAWN05             = -1609273,
    EMOTE_LIGHT_OF_DAWN06             = -1609274,
    EMOTE_LIGHT_OF_DAWN07             = -1609275,
    EMOTE_LIGHT_OF_DAWN08             = -1609276,
    EMOTE_LIGHT_OF_DAWN09             = -1609277,
    EMOTE_LIGHT_OF_DAWN10             = -1609278,
    EMOTE_LIGHT_OF_DAWN11             = -1609279,
    EMOTE_LIGHT_OF_DAWN12             = -1609280,
    EMOTE_LIGHT_OF_DAWN13             = -1609281,
    EMOTE_LIGHT_OF_DAWN14             = -1609282,
    EMOTE_LIGHT_OF_DAWN15             = -1609283,
    EMOTE_LIGHT_OF_DAWN16             = -1609284,
    EMOTE_LIGHT_OF_DAWN17             = -1609285,
    EMOTE_LIGHT_OF_DAWN18             = -1609286,

    GO_LIGHT_OF_DAWN                  = 191330,
    SPELL_THE_LIGHT_OF_DAWN_Q         = 53606, // quest credit

    // ---- Dark Knight npc --------------------
    // Highlord Darion Mograine
    NPC_HIGHLORD_DARION_MOGRAINE      = 29173,
    SPELL_ANTI_MAGIC_ZONE1            = 52893,
    SPELL_DEATH_STRIKE                = 53639,
    SPELL_DEATH_EMBRACE               = 53635,
    SPELL_ICY_TOUCH1                  = 49723,
    SPELL_THE_LIGHT_OF_DAWN           = 53658,
    SPELL_THE_MIGHT_OF_MOGRAINE       = 53642, // on players when begins
    SPELL_UNHOLY_BLIGHT               = 53640,
    SPELL_ALEXANDROS_MOGRAINE_SPAWN   = 53667,
    SPELL_MOGRAINE_CHARGE             = 53679,
    SPELL_ASHBRINGER                  = 53701,

    // Koltira Deathweaver & Orbaz Bloodbane are using the same abilities
    NPC_KOLTIRA_DEATHWEAVER           = 29199,
    NPC_ORBAZ_BLOODBANE               = 29204, // this guy fleed
    NPC_THASSARIAN                    = 29200, // he also does SPELL_THE_LIGHT_OF_DAWN 53658
    SPELL_BLOOD_STRIKE1               = 52374,
    SPELL_DEATH_GRIP                  = 49576,
    SPELL_ICY_TOUCH2                  = 52372,
    SPELL_PLAGUE_STRIKE1              = 50668,
    // all do SPELL_HERO_AGGRO_AURA    53627

    // Lich King
    NPC_THE_LICH_KING                 = 29183, // show up at end
    SPELL_APOCALYPSE                  = 53210,
    SPELL_TELEPORT_VISUAL             = 52233,
    SPELL_SOUL_FEAST_ALEX             = 53677, // on Alexandros
    SPELL_SOUL_FEAST_TIRION           = 53685, // on Tirion
    SPELL_ICEBOUND_VISAGE             = 53274, // not sure what is it for
    SPELL_REBUKE                      = 53680,

    // others
    NPC_RAMPAGING_ABOMINATION         = 29186,
    SPELL_CLEAVE1                     = 53633,
    SPELL_SCOURGE_HOOK                = 50335,
    SPELL_SCOURGE_AGGRO_AURA          = 53624,

    NPC_FLESH_BEHEMOTH                = 29190, // giant guy
    SPELL_STOMP                       = 53634,
    SPELL_THUNDERCLAP                 = 36706,
    SPELL_HERO_AGGRO_AURA             = 53627,

    NPC_ACHERUS_GHOUL                 = 29219, // just ghoul....
    SPELL_GHOULPLOSION                = 53632,

    NPC_WARRIOR_OF_THE_FROZEN_WASTES  = 29206, // use SPELL_CLEAVE 53631

    NPC_HIGHLORD_ALEXANDROS_MOGRAINE  = 29227, // ghost
    NPC_DARION_MOGRAINE               = 29228, // ghost

    // ---- Dawn npc --------------------
    // Highlord Tirion Fordring
    NPC_HIGHLORD_TIRION_FORDRING      = 29175,
    EQUIP_HIGHLORD_TIRION_FORDRING    = 13262,
    SPELL_LAY_ON_HANDS                = 53778,
    SPELL_REBIRTH_OF_THE_ASHBRINGER   = 53702,
    SPELL_TIRION_CHARGE               = 53705,
    SPELL_TIRION_CHARGE_VISUAL        = 53706,

    // others
    NPC_KORFAX_CHAMPION_OF_THE_LIGHT  = 29176,
    SPELL_CLEAVE                      = 53631,
    SPELL_HEROIC_LEAP                 = 53625,

    NPC_LORD_MAXWELL_TYROSUS          = 29178,
    NPC_LEONID_BARTHALOMEW_THE_REVERED = 29179,
    NPC_DUKE_NICHOLAS_ZVERENHOFF      = 29180,

    NPC_COMMANDER_ELIGOR_DAWNBRINGER  = 29177,
    SPELL_HOLY_LIGHT2                 = 37979,

    NPC_RAYNE                         = 29181,
    SPELL_REJUVENATION                = 20664,
    SPELL_STARFALL                    = 20678,
    SPELL_TRANQUILITY                 = 25817,
    SPELL_WRATH                       = 21807,

    NPC_DEFENDER_OF_THE_LIGHT         = 29174, // also does SPELL_HEROIC_LEAP 53625
    SPELL_HOLY_LIGHT1                 = 29427,
    SPELL_HOLY_STRIKE                 = 53643,
    SPELL_HOLY_WRATH                  = 53638,
    SPELL_UPPERCUT                    = 53629,

    NPC_RIMBLAT_EARTHSHATTER          = 29182,
    SPELL_CHAIN_HEAL                  = 33642,
    SPELL_THUNDER                     = 53630
};

struct Locations
{
    float x, y, z, o;
    uint32 id;
};

void UpdateWorldState(Map *map, uint32 id, uint32 state)
{
    Map::PlayerList const& players = map->GetPlayers();

    if (!players.isEmpty())
    {
        for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* pPlayer = itr->getSource())
                pPlayer->SendUpdateWorldState(id,state);
        }
    }
}

static Locations LightofDawnLoc[]=
{
    {2281.335, -5300.409, 85.170, 0},     // 0 Tirion Fordring loc
    {2283.896, -5287.914, 83.066, 1.55},  // 1 Tirion Fordring loc2
    {2281.461, -5263.014, 81.164, 0},     // 2 Tirion charges
    {2262.277, -5293.477, 82.167, 0},     // 3 Tirion run
    {2270.286, -5287.73, 82.262, 0},      // 4 Tirion relocate
    {2269.511, -5288.289, 82.225, 0},     // 5 Tirion forward
    {2262.277, -5293.477, 82.167, 0},     // 6 Tirion runs to Darion
    {2270.286, -5287.73, 82.262, 0},
    {2269.511, -5288.289, 82.225, 0},
    {2273.205, -5288.848, 82.617, 0},     // 9 Korfax loc1
    {2274.739, -5287.926, 82.684, 0},     // 10 Korfax loc2
    {2253.673, -5318.004, 81.724, 0},     // 11 Korfax kicked
    {2287.028, -5309.644, 87.253, 0},     // 12 Maxwell loc1
    {2286.978, -5308.025, 86.83, 0},      // 13 Maxwell loc2
    {2248.877, -5307.586, 82.166, 0},     // 14 maxwell kicked
    {2278.58, -5316.933, 88.319, 0},      // 15 Eligor loc1
    {2278.535, -5315.479, 88.08, 0},      // 16 Eligor loc2
    {2259.416, -5304.505, 82.149, 0},     // 17 eligor kicked
    {2289.259, -5280.355, 82.112, 0},     // 18 Koltira loc1
    {2289.02, -5281.985, 82.207, 0},      // 19 Koltira loc2
    {2273.289, -5273.675, 81.701, 0},     // 20 Thassarian loc1
    {2273.332, -5275.544, 81.849, 0},     // 21 Thassarian loc2
    {2281.198, -5257.397, 80.224, 4.66},  // 22 Alexandros loc1
    {2281.156, -5259.934, 80.647, 0},     // 23 Alexandros loc2
    {2281.294, -5281.895, 82.445, 1.35},  // 24 Darion loc1
    {2281.093, -5263.013, 81.125, 0},     // 25 Darion loc1
    {2281.313, -5250.282, 79.322, 4.69},  // 26 Lich King spawns
    {2281.523, -5261.058, 80.877, 0},     // 27 Lich king move forwards
    {2272.709, -5255.552, 78.226, 0},     // 28 Lich king kicked
    {2273.972, -5257.676, 78.862, 0}      // 29 Lich king moves forward
};

struct TRINITY_DLL_DECL npc_highlord_darion_mograineAI : public npc_escortAI
{
    npc_highlord_darion_mograineAI(Creature *pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    bool bIsBattle;
    uint32 uiStep;
    uint32 uiPhase_timer;
    uint32 uiFight_duration;
    uint32 uiTotal_dawn;
    uint32 uiTotal_scourge;
    uint32 uiSummon_counter;

    // Darion Mograine
    uint32 uiAnti_magic_zone;
    uint32 uiDeath_strike;
    uint32 uiDeath_embrace;
    uint32 uiIcy_touch;
    uint32 uiUnholy_blight;
    uint32 uiFight_speech;
    uint32 uiSpawncheck;
    uint32 uiTargetcheck;

    // Dawn
    uint64 uiTirionGUID;
    uint64 uiAlexandrosGUID;
    uint64 uiDarionGUID;
    uint64 uiKorfaxGUID;
    uint64 uiMaxwellGUID;
    uint64 uiEligorGUID;
    uint64 uiRayneGUID;
    uint64 uiDefenderGUID[ENCOUNTER_DEFENDER_NUMBER];
    uint64 uiEarthshatterGUID[ENCOUNTER_EARTHSHATTER_NUMBER];

    // Death
    uint64 uiKoltiraGUID;
    uint64 uiOrbazGUID;
    uint64 uiThassarianGUID;
    uint64 uiLichKingGUID;
    uint64 uiAbominationGUID[ENCOUNTER_ABOMINATION_NUMBER];
    uint64 uiBehemothGUID[ENCOUNTER_BEHEMOTH_NUMBER];
    uint64 uiGhoulGUID[ENCOUNTER_GHOUL_NUMBER];
    uint64 uiWarriorGUID[ENCOUNTER_WARRIOR_NUMBER];

    // Misc
    uint64 uiDawnofLightGUID;

    void Reset()
    {
        if (!IsBeingEscorted)
        {
            bIsBattle = false;
            uiStep = 0;
            uiPhase_timer = 3000;
            uiFight_duration = 300000; // 5 minutes
            uiTotal_dawn = ENCOUNTER_TOTAL_DAWN;
            uiTotal_scourge = ENCOUNTER_TOTAL_SCOURGE;
            uiSummon_counter = 0;

            uiDawnofLightGUID = 0;

            uiAnti_magic_zone = 1000 + rand()%5000;
            uiDeath_strike = 5000 + rand()%5000;
            uiDeath_embrace = 5000 + rand()%5000;
            uiIcy_touch = 5000 + rand()%5000;
            uiUnholy_blight = 5000 + rand()%5000;

            uiFight_speech = 15000;
            uiSpawncheck = 1000;
            uiTargetcheck = 10000;

            ((Unit*)me)->SetStandState(UNIT_STAND_STATE_STAND);
            me->Mount(25279);

            UpdateWorldState(me->GetMap(), WORLD_STATE_REMAINS, 0);
            //UpdateWorldState(me->GetMap(), WORLD_STATE_COUNTDOWN, 0);
            UpdateWorldState(me->GetMap(), WORLD_STATE_EVENT_BEGIN, 0);

            if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiEligorGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiRayneGUID))
                pTemp->setDeathState(JUST_DIED);

            uiTirionGUID = NULL;
            uiKorfaxGUID = NULL;
            uiMaxwellGUID = NULL;
            uiEligorGUID = NULL;
            uiRayneGUID = NULL;

            for(uint8 i = 0; i < ENCOUNTER_DEFENDER_NUMBER; ++i)
            {
                if (Unit* pTemp = Unit::GetUnit((*me), uiDefenderGUID[i]))
                    pTemp->setDeathState(JUST_DIED);
                uiDefenderGUID[i] = 0;
            }
            for(uint8 i = 0; i < ENCOUNTER_EARTHSHATTER_NUMBER; ++i)
            {
                if (Unit* pTemp = Unit::GetUnit((*me), uiEarthshatterGUID[i]))
                    pTemp->setDeathState(JUST_DIED);
                uiEarthshatterGUID[i] = 0;
            }

            if (Unit* pTemp = Unit::GetUnit((*me), uiKoltiraGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiOrbazGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiThassarianGUID))
                pTemp->setDeathState(JUST_DIED);
            if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                pTemp->setDeathState(JUST_DIED);

            uiKoltiraGUID = NULL;
            uiOrbazGUID = NULL;
            uiThassarianGUID = NULL;
            uiLichKingGUID = NULL;
            for(uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
            {
                if (Unit* pTemp = Unit::GetUnit((*me), uiAbominationGUID[i]))
                    pTemp->setDeathState(JUST_DIED);
                uiAbominationGUID[i] = 0;
            }
            for(uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
            {
                if (Unit* pTemp = Unit::GetUnit((*me), uiBehemothGUID[i]))
                    pTemp->setDeathState(JUST_DIED);
                uiBehemothGUID[i] = 0;
            }
            for(uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
            {
                if (Unit* pTemp = Unit::GetUnit((*me), uiGhoulGUID[i]))
                    pTemp->setDeathState(JUST_DIED);
                uiGhoulGUID[i] = 0;
            }
            for(uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
            {
                if (Unit* pTemp = Unit::GetUnit((*me), uiWarriorGUID[i]))
                    pTemp->setDeathState(JUST_DIED);
                uiWarriorGUID[i] = 0;
            }
        }
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (who == me)
            return;

        if (me->Attack(who, true))
        {
            me->AddThreat(who, 0.0f);
            me->SetInCombatWith(who);
            who->SetInCombatWith(me);
            DoStartMovement(who);
        }
    }

    void MoveInLineOfSight(Unit* who)
    {
        if (!who)
            return;

        if (who->isTargetableForAttack() && me->IsHostileTo(who))
            if (me->IsWithinDistInMap(who, 20) && me->IsWithinLOSInMap(who))
                AttackStart(who);
    }

    void SetHoldState(bool bOnHold)
    {
        IsOnHold = bOnHold;
    }

    void WaypointReached(uint32 i)
    {
        switch(i)
        {
            case 0:
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                SetHoldState(true);
                break;
            case 1:
                SetHoldState(true);

                if (GameObject* pGo = me->FindNearestGameObject(GO_LIGHT_OF_DAWN, 100.0f)) // make dawn of light effect off
                {
                    uiDawnofLightGUID = pGo->GetGUID();
                    pGo->SetPhaseMask(0, true);
                }

                SpawnNPC();
                if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                    DoScriptText(SAY_LIGHT_OF_DAWN07, pTemp);
                if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                    DoScriptText(SAY_LIGHT_OF_DAWN08, pTemp);

                for(uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                    NPCChangeTarget(uiGhoulGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                    NPCChangeTarget(uiWarriorGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                    NPCChangeTarget(uiAbominationGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                    NPCChangeTarget(uiBehemothGUID[i]);
                NPCChangeTarget(uiKoltiraGUID);
                NPCChangeTarget(uiOrbazGUID);
                NPCChangeTarget(uiThassarianGUID);

                me->Unmount();
                me->CastSpell(me, SPELL_THE_MIGHT_OF_MOGRAINE, true); // need to fix, on player only

                if (Unit* pTemp = Unit::GetUnit((*me), uiKoltiraGUID))
                    pTemp->Unmount();
                if (Unit* pTemp = Unit::GetUnit((*me), uiThassarianGUID))
                    pTemp->Unmount();

                bIsBattle = true;
                break;
            case 2:
                me->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                DoCast(me, SPELL_THE_LIGHT_OF_DAWN);
                break;
            case 3:
            {
                Unit* pTirion = Unit::GetUnit((*me), uiTirionGUID);

                DoScriptText(EMOTE_LIGHT_OF_DAWN05, me);
                if (me->HasAura(SPELL_THE_LIGHT_OF_DAWN, 0))
                    me->RemoveAurasDueToSpell(SPELL_THE_LIGHT_OF_DAWN);
                if (Unit* pTemp = Unit::GetUnit((*me), uiKoltiraGUID))
                {
                    if (pTemp->HasAura(SPELL_THE_LIGHT_OF_DAWN, 0))
                        pTemp->RemoveAurasDueToSpell(SPELL_THE_LIGHT_OF_DAWN);
                    pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[19].x, LightofDawnLoc[19].y, LightofDawnLoc[19].z);
                }
                if (Unit* pTemp = Unit::GetUnit((*me), uiThassarianGUID))
                {
                    if (pTemp->HasAura(SPELL_THE_LIGHT_OF_DAWN, 0))
                        pTemp->RemoveAurasDueToSpell(SPELL_THE_LIGHT_OF_DAWN);
                    pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[21].x, LightofDawnLoc[21].y, LightofDawnLoc[21].z);
                }
                if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                {
                    pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[10].x, LightofDawnLoc[10].y, LightofDawnLoc[10].z);
                }
                if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                {
                    pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[13].x, LightofDawnLoc[13].y, LightofDawnLoc[13].z);
                }
                if (Unit* pTemp = Unit::GetUnit((*me), uiEligorGUID))
                {
                    pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[16].x, LightofDawnLoc[16].y, LightofDawnLoc[16].z);
                }
                JumpToNextStep(10000);
            } break;
            case 4:
                DoScriptText(SAY_LIGHT_OF_DAWN27, me);
                ((Unit*)me)->SetStandState(UNIT_STAND_STATE_KNEEL);

                if (Unit* pTemp = Unit::GetUnit((*me), uiKoltiraGUID))
                    pTemp->SetStandState(UNIT_STAND_STATE_KNEEL);
                if (Unit* pTemp = Unit::GetUnit((*me), uiThassarianGUID))
                    pTemp->SetStandState(UNIT_STAND_STATE_KNEEL);
                SetHoldState(true);
                break;
            case 5:
                DoScriptText(SAY_LIGHT_OF_DAWN33, me);
                SetHoldState(true);
                break;
            case 6:
                SetHoldState(true);
                me->HandleEmoteCommand(EMOTE_ONESHOT_SPECIALATTACK1H);
                JumpToNextStep(1000);
                break;
            case 7:
                SetHoldState(true);
                JumpToNextStep(2000);
                break;
            case 8:
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_UNEQUIP));
                if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                    me->CastSpell(pTemp, SPELL_ASHBRINGER, true);
                DoScriptText(EMOTE_LIGHT_OF_DAWN14, me);
                SetHoldState(true);
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);

        if (!bIsBattle)
        {
            if (uiPhase_timer < diff)
            {
                // ******* Before battle *****************************************************************
                switch(uiStep)
                {
                    case 0:  // countdown
                        //UpdateWorldState(me->GetMap(), WORLD_STATE_COUNTDOWN, 1);
                        break;

                    case 1:  // just delay
                        //UpdateWorldState(me->GetMap(), WORLD_STATE_REMAINS, 1);
                        UpdateWorldState(me->GetMap(), WORLD_STATE_COUNTDOWN, 0);
                        UpdateWorldState(me->GetMap(), WORLD_STATE_EVENT_BEGIN, 1);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        JumpToNextStep(3000);
                        break;

                    case 2:
                        DoScriptText(SAY_LIGHT_OF_DAWN04, me);
                        if (Creature* pKoltira = GetClosestCreatureWithEntry(me, NPC_KOLTIRA_DEATHWEAVER, 50.0f))
                            uiKoltiraGUID = pKoltira->GetGUID();
                        if (Creature* pOrbaz = GetClosestCreatureWithEntry(me, NPC_ORBAZ_BLOODBANE, 50.0f))
                            uiOrbazGUID = pOrbaz->GetGUID();
                        if (Creature* pThassarian = GetClosestCreatureWithEntry(me, NPC_THASSARIAN, 50.0f))
                            uiThassarianGUID = pThassarian->GetGUID();
                        JumpToNextStep(10000);
                        break;

                    case 3: // rise
                        DoScriptText(SAY_LIGHT_OF_DAWN05, me);
                        JumpToNextStep(3000);
                        break;

                    case 4: // summon ghoul
                        // Dunno whats the summon spell, so workaround
                        DoCast(me, 33271); // shack effect
                        uiPhase_timer = 500;
                        if (uiSummon_counter < ENCOUNTER_GHOUL_NUMBER)
                        {
                            Unit* pTemp = me->SummonCreature(NPC_ACHERUS_GHOUL, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->setFaction(2084);
                            uiGhoulGUID[uiSummon_counter] = pTemp->GetGUID();
                            uiSummon_counter++;
                        }
                        else
                        {
                            uiSummon_counter = 0;
                            uiStep++;
                        }
                        break;

                    case 5: // summon abomination
                        DoCast(me, 33271); // shack effect
                        uiPhase_timer = 500;
                        if (uiSummon_counter < ENCOUNTER_ABOMINATION_NUMBER)
                        {
                            Unit* pTemp = me->SummonCreature(NPC_RAMPAGING_ABOMINATION, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->setFaction(2084);
                            uiAbominationGUID[uiSummon_counter] = pTemp->GetGUID();
                            uiSummon_counter++;
                        }
                        else
                        {
                            uiSummon_counter = 0;
                            uiStep++;
                        }
                        break;

                    case 6: // summon warrior
                        DoCast(me, 33271); // shack effect
                        uiPhase_timer = 500;
                        if (uiSummon_counter < ENCOUNTER_WARRIOR_NUMBER)
                        {
                            Unit* pTemp = me->SummonCreature(NPC_WARRIOR_OF_THE_FROZEN_WASTES, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->setFaction(2084);
                            uiWarriorGUID[uiSummon_counter] = pTemp->GetGUID();
                            uiSummon_counter++;
                        }
                        else
                        {
                            uiSummon_counter = 0;
                            uiStep++;
                        }
                        break;

                    case 7: // summon warrior
                        DoCast(me, 33271); // shack effect
                        uiPhase_timer = 500;
                        if (uiSummon_counter < ENCOUNTER_BEHEMOTH_NUMBER)
                        {
                            Unit* pTemp = me->SummonCreature(NPC_FLESH_BEHEMOTH, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->setFaction(2084);
                            uiBehemothGUID[uiSummon_counter] = pTemp->GetGUID();
                            uiSummon_counter++;
                        }
                        else
                        {
                            uiSummon_counter = 0;
                            uiStep++;
                        }
                        break;

                    case 8: // summon announce
                        DoScriptText(SAY_LIGHT_OF_DAWN06, me);
                        JumpToNextStep(5000);
                        break;

                    case 9: // charge begins
                        SetHoldState(false);
                        if (Unit* pTemp = Unit::GetUnit((*me), uiKoltiraGUID))
                        {
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiOrbazGUID))
                        {
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiThassarianGUID))
                        {
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        }
                        for(uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                            if (Unit* pTemp = Unit::GetUnit((*me), uiAbominationGUID[i]))
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        for(uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                            if (Unit* pTemp = Unit::GetUnit((*me), uiBehemothGUID[i]))
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        for(uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                            if (Unit* pTemp = Unit::GetUnit((*me), uiGhoulGUID[i]))
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        for(uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                            if (Unit* pTemp = Unit::GetUnit((*me), uiWarriorGUID[i]))
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                        JumpToNextStep(5000);
                        break;

                    // ******* After battle *****************************************************************
                    case 11: // Tirion starts to speak
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN28, pTemp);
                        JumpToNextStep(21000);
                        break;

                    case 12:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN29, pTemp);
                        JumpToNextStep(13000);
                        break;

                    case 13:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN30, pTemp);
                        JumpToNextStep(13000);
                        break;

                    case 14:
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_STAND);
                        DoScriptText(SAY_LIGHT_OF_DAWN31, me);
                        JumpToNextStep(7000);
                        break;

                    case 15: // summon gate
                        if (Unit* pTemp = me->SummonCreature(NPC_HIGHLORD_ALEXANDROS_MOGRAINE, LightofDawnLoc[22].x, LightofDawnLoc[22].y, LightofDawnLoc[22].z, LightofDawnLoc[22].o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                        {
                            pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pTemp->CastSpell(pTemp, SPELL_ALEXANDROS_MOGRAINE_SPAWN, true);
                            DoScriptText(EMOTE_LIGHT_OF_DAWN06, pTemp);
                            uiAlexandrosGUID = pTemp->GetGUID();
                        }
                        JumpToNextStep(4000);
                        break;

                    case 16: // Alexandros out
                        if (Unit* pTemp = Unit::GetUnit((*me), uiAlexandrosGUID))
                        {
                            pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[23].x, LightofDawnLoc[23].y, LightofDawnLoc[23].z);
                            DoScriptText(SAY_LIGHT_OF_DAWN32, pTemp);
                        }
                        SetHoldState(false); // makes darion turns back
                        JumpToNextStep(5000);
                        break;

                    case 17:
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_KNEEL);
                        DoScriptText(SAY_LIGHT_OF_DAWN34, me);
                        JumpToNextStep(5000);
                        break;

                    case 18: // Darion's spirit out
                        if (Unit* pTemp = me->SummonCreature(NPC_DARION_MOGRAINE, LightofDawnLoc[24].x, LightofDawnLoc[24].y, LightofDawnLoc[24].z, LightofDawnLoc[24].o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                        {
                            DoScriptText(SAY_LIGHT_OF_DAWN35, pTemp);
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            uiDarionGUID = pTemp->GetGUID();
                        }
                        JumpToNextStep(4000);
                        break;

                    case 19: // runs to father
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDarionGUID))
                        {
                            DoScriptText(EMOTE_LIGHT_OF_DAWN07, pTemp);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[25].x, LightofDawnLoc[25].y, LightofDawnLoc[25].z);
                        }
                        JumpToNextStep(4000);
                        break;

                    case 20:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDarionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN36, pTemp);
                        JumpToNextStep(4000);
                        break;

                    case 21:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDarionGUID))
                            DoScriptText(EMOTE_LIGHT_OF_DAWN08, pTemp);
                        JumpToNextStep(4000);
                        break;

                    case 22:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiAlexandrosGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN37, pTemp);
                        JumpToNextStep(8000);
                        break;

                    case 23:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDarionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN38, pTemp);
                        JumpToNextStep(8000);
                        break;

                    case 24:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiAlexandrosGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN39, pTemp);

                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID)) // Tirion moves forward here
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[1].x, LightofDawnLoc[1].y, LightofDawnLoc[1].z);

                        JumpToNextStep(15000);
                        break;

                    case 25:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDarionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN40, pTemp);
                        JumpToNextStep(11000);
                        break;

                    case 26:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiAlexandrosGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN41, pTemp);
                        JumpToNextStep(5000);
                        break;

                    case 27:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDarionGUID))
                            pTemp->setDeathState(JUST_DIED);
                        JumpToNextStep(24000);
                        break;

                    case 28:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiAlexandrosGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN42, pTemp);
                        JumpToNextStep(6000);
                        break;

                    case 29: // lich king spawns
                        if (Unit* pTemp = me->SummonCreature(NPC_THE_LICH_KING, LightofDawnLoc[26].x, LightofDawnLoc[26].y, LightofDawnLoc[26].z, LightofDawnLoc[26].o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                        {
                            DoScriptText(SAY_LIGHT_OF_DAWN43, pTemp);
                            uiLichKingGUID = pTemp->GetGUID();
                            if (Unit* pAlex = Unit::GetUnit((*me), uiAlexandrosGUID))
                                pTemp->CastSpell(pAlex, SPELL_SOUL_FEAST_ALEX, false);
                        }
                        JumpToNextStep(2000);
                        break;

                    case 30:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiAlexandrosGUID)) // just hide him
                        {
                            DoScriptText(EMOTE_LIGHT_OF_DAWN09, pTemp);
                            pTemp->SetVisibility(VISIBILITY_OFF);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                        {
                            pTemp->InterruptNonMeleeSpells(false);
                            DoScriptText(SAY_LIGHT_OF_DAWN45, pTemp);
                        }
                        JumpToNextStep(3000);
                        break;

                    case 31:
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_STAND);
                        DoScriptText(EMOTE_LIGHT_OF_DAWN10, me);
                        DoScriptText(SAY_LIGHT_OF_DAWN44, me);
                        JumpToNextStep(3000);
                        break;

                    case 32:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[27].x, LightofDawnLoc[27].y, LightofDawnLoc[27].z);
                        JumpToNextStep(6000);
                        break;

                    case 33: // Darion supports to jump to lich king here
// disable              if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
//  because TRINITY          DoCast(me, SPELL_MOGRAINE_CHARGE); // jumping charge
//   doesn't make it looks well, so workarounds, Darion charges, looks better
                        me->SetSpeed(MOVE_RUN, 3.0f);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                        SetHoldState(false);
                        JumpToNextStep(0);
                        break;

                    case 35: // Lich king counterattacks
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                        {
                            pTemp->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
                            DoScriptText(SAY_LIGHT_OF_DAWN46, pTemp);
                        }
                        me->SetSpeed(MOVE_RUN, 6.0f);
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_DEAD);
                        SetHoldState(false); // Darion got kicked by lich king
                        JumpToNextStep(0);
                        break;

                    case 37: // Lich king counterattacks
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_KNEEL);
                        JumpToNextStep(3000);
                        break;

                    case 38:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN47, pTemp);
                        JumpToNextStep(8000);
                        break;

                    case 39:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN48, pTemp);
                        JumpToNextStep(15000);
                        break;

                    case 40:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN49, pTemp);
                        JumpToNextStep(17000);
                        break;

                    case 41: // Lich king - Apocalypse
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                        {
                            DoScriptText(EMOTE_LIGHT_OF_DAWN11, pTemp);
                            DoScriptText(SAY_LIGHT_OF_DAWN51, pTemp);
                            if (Unit* pTirion = Unit::GetUnit((*me), uiTirionGUID))
                            {
                                ((Unit*)pTirion)->SetStandState(UNIT_STAND_STATE_KNEEL);
                                //pTemp->CastSpell(pTirion, SPELL_APOCALYPSE, false); // not working
                                pTemp->CastSpell(pTirion, SPELL_SOUL_FEAST_TIRION, false);
                                DoScriptText(EMOTE_LIGHT_OF_DAWN12, pTirion);
                            }
                        }
                        JumpToNextStep(2000);
                        break;

                    case 42: // Maxwell yells for attack
                        {
                            float fLichPositionX, fLichPositionY, fLichPositionZ;
                            if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            {
                                fLichPositionX = pTemp->GetPositionX();
                                fLichPositionY = pTemp->GetPositionY();
                                fLichPositionZ = pTemp->GetPositionZ();
                            }

                            if (fLichPositionX && fLichPositionY)
                            {
                                Unit* pTemp;
                                pTemp = me->SummonCreature(NPC_DEFENDER_OF_THE_LIGHT, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                pTemp->setFaction(me->getFaction());
                                pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                uiDefenderGUID[0] = pTemp->GetGUID();

                                pTemp = me->SummonCreature(NPC_RIMBLAT_EARTHSHATTER, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                pTemp->setFaction(me->getFaction());
                                pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                uiEarthshatterGUID[0] = pTemp->GetGUID();
                            }
                            if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                DoScriptText(SAY_LIGHT_OF_DAWN50, pTemp);
                            }
                            if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                pTemp->HandleEmoteCommand(EMOTE_STATE_ATTACK_UNARMED);
                                pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                            }
                            if (Unit* pTemp = Unit::GetUnit((*me), uiEligorGUID))
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                            }
                        }
                        JumpToNextStep(4500);
                        break;

                    case 43: // They all got kicked
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(EMOTE_LIGHT_OF_DAWN13, pTemp);

                        if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                        {
                            pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            pTemp->SetSpeed(MOVE_RUN, 6.0f);
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_DEAD);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[14].x, LightofDawnLoc[14].y, LightofDawnLoc[14].z);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                        {
                            pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            pTemp->SetSpeed(MOVE_RUN, 6.0f);
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_DEAD);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[11].x, LightofDawnLoc[11].y, LightofDawnLoc[11].z);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiEligorGUID))
                        {
                            pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            pTemp->SetSpeed(MOVE_RUN, 6.0f);
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_DEAD);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[17].x, LightofDawnLoc[17].y, LightofDawnLoc[17].z);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiDefenderGUID[0]))
                        {
                            pTemp->SetSpeed(MOVE_RUN, 6.0f);
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_DEAD);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiEarthshatterGUID[0]))
                        {
                            pTemp->SetSpeed(MOVE_RUN, 6.0f);
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_DEAD);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z);
                        }
                        JumpToNextStep(3000);
                        break;

                    case 44: // make them stand up
                        if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_STAND);
                        if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_STAND);
                        if (Unit* pTemp = Unit::GetUnit((*me), uiEligorGUID))
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_STAND);
                        JumpToNextStep(1000);
                        break;

                    case 45:
                        DoScriptText(SAY_LIGHT_OF_DAWN52, me);
                        JumpToNextStep(5000);
                        break;

                    case 46: // Darion stand up, "not today"
                        me->SetSpeed(MOVE_RUN, 1.0f);
                        me->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_STAND);
                        DoScriptText(SAY_LIGHT_OF_DAWN53, me);
                        SetHoldState(false); // Darion throws sword
                        JumpToNextStep(7000);
                        break;

                    case 47: // Ashbringer rebirth
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_KNEEL);
                        DoScriptText(EMOTE_LIGHT_OF_DAWN15, me);
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                        {
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_STAND);
                            pTemp->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_HIGHLORD_TIRION_FORDRING));
                            pTemp->CastSpell(pTemp, SPELL_REBIRTH_OF_THE_ASHBRINGER, false);
                        }
                        JumpToNextStep(1000);
                        break;

                    case 48: // Show the cleansing effect (dawn of light)
                        if (GameObject* pGo = me->GetMap()->GetGameObject(uiDawnofLightGUID))
                            pGo->SetPhaseMask(128, true);
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                        {
                            if (pTemp->HasAura(SPELL_REBIRTH_OF_THE_ASHBRINGER, 0))
                                pTemp->RemoveAurasDueToSpell(SPELL_REBIRTH_OF_THE_ASHBRINGER);
                            pTemp->CastSpell(pTemp, 41542, false); // workarounds, light expoded, makes it cool
                            pTemp->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        }
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            pTemp->InterruptNonMeleeSpells(false);
                        JumpToNextStep(2500);
                        break;

                    case 49:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN54, pTemp);
                        JumpToNextStep(4000);
                        break;

                    case 50:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN55, pTemp);
                        JumpToNextStep(5000);
                        break;

                    case 51:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN56, pTemp);
                        JumpToNextStep(1000);
                        break;

                    case 52: // Tiron charges
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                        {
                            DoScriptText(EMOTE_LIGHT_OF_DAWN16, pTemp);
                            pTemp->CastSpell(pTemp, SPELL_TIRION_CHARGE, false); // jumping charge
                            pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                            pTemp->SetSpeed(MOVE_RUN, 3.0f); // workarounds, make Tirion still running
                            pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[2].x, LightofDawnLoc[2].y, LightofDawnLoc[2].z);
                            if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                                pTemp->Relocate(LightofDawnLoc[28].x, LightofDawnLoc[28].y, LightofDawnLoc[28].z); // workarounds, he should kick back by Tirion, but here we relocate him
                        }
                        JumpToNextStep(1500);
                        break;

                    case 53:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN57, pTemp);
                        JumpToNextStep(1000);
                        break;

                    case 54:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                        {
                            pTemp->SetSpeed(MOVE_RUN, 1.0f);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[29].x, LightofDawnLoc[29].y, LightofDawnLoc[29].z); // 26
                        }
                        JumpToNextStep(4000);
                        break;

                    case 55:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_KNEEL);
                        JumpToNextStep(2000);
                        break;

                    case 56:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            ((Unit*)pTemp)->SetStandState(UNIT_STAND_STATE_STAND);
                        JumpToNextStep(1500);
                        break;

                    case 57:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN58, pTemp);
                        JumpToNextStep(10000);
                        break;

                    case 58:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN59, pTemp);
                        JumpToNextStep(10000);
                        break;

                    case 59:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID))
                            pTemp->CastSpell(pTemp, SPELL_TELEPORT_VISUAL, false);
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID)) // Tirion runs to Darion
                        {
                            pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            pTemp->SetSpeed(MOVE_RUN, 1.0f);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[6].x, LightofDawnLoc[6].y, LightofDawnLoc[6].z);
                        }
                        JumpToNextStep(2500);
                        break;

                    case 60:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiLichKingGUID)) // Lich king disappears here
                        {
                            DoScriptText(EMOTE_LIGHT_OF_DAWN17, pTemp);
                            pTemp->DealDamage(pTemp, pTemp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        }
                        JumpToNextStep(10000);
                        break;

                    case 61:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN60, pTemp);
                        JumpToNextStep(3000);
                        break;

                    case 62:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                        {
                            pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[7].x, LightofDawnLoc[7].y, LightofDawnLoc[7].z);
                        }
                        JumpToNextStep(5500);
                        break;

                    case 63:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                        {
                            pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[8].x, LightofDawnLoc[8].y, LightofDawnLoc[8].z);
                            DoScriptText(SAY_LIGHT_OF_DAWN61, pTemp);
                        }
                        JumpToNextStep(15000);
                        break;

                    case 64:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN62, pTemp);
                        JumpToNextStep(7000);
                        break;

                    case 65:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN63, pTemp);
                        JumpToNextStep(10000);
                        break;

                    case 66:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN64, pTemp);
                        JumpToNextStep(11000);
                        break;

                    case 67:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN65, pTemp);
                        JumpToNextStep(10000);
                        break;

                    case 68:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN66, pTemp);
                        JumpToNextStep(8000);
                        break;

                    case 69:
                        if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                            DoScriptText(SAY_LIGHT_OF_DAWN67, pTemp);
                        JumpToNextStep(10000);
                        break;

                    case 70:
                        ((Unit*)me)->SetStandState(UNIT_STAND_STATE_STAND);
                        DoScriptText(SAY_LIGHT_OF_DAWN68, me);
                        JumpToNextStep(10000);
                        break;

                    case 71:
                        if (GameObject* pGo = me->GetMap()->GetGameObject(uiDawnofLightGUID)) // Turn off dawn of light
                            pGo->SetPhaseMask(0, true);

                        {
                            Map *map = me->GetMap(); // search players with in 50 yards for quest credit
                            Map::PlayerList const &PlayerList = map->GetPlayers();
                            if (!PlayerList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                    if (i->getSource()->isAlive() && me->IsWithinDistInMap(i->getSource(), 50))
                                        i->getSource()->CastSpell(i->getSource(), SPELL_THE_LIGHT_OF_DAWN_Q, false);
                            }
                        }
                        me->SetVisibility(VISIBILITY_OFF); // respawns another Darion for quest turn in
                        me->SummonCreature(NPC_HIGHLORD_DARION_MOGRAINE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
                        JumpToNextStep(1000);
                        break;

                    case 72:
                        SetHoldState(false); // Escort ends
                        JumpToNextStep(0);
                        break;
                }

            }else uiPhase_timer -= diff;
        }

        // ******* During battle *****************************************************************
        else
        {
            if (uiAnti_magic_zone < diff)
            {
                DoCast(me, SPELL_ANTI_MAGIC_ZONE1);
                uiAnti_magic_zone = 25000 + rand()%5000;
            }else uiAnti_magic_zone -= diff;

            if (uiDeath_strike < diff)
            {
                DoCast(me->getVictim(), SPELL_DEATH_STRIKE);
                uiDeath_strike = 5000 + rand()%5000;
            }else uiDeath_strike -= diff;

            if (uiDeath_embrace < diff)
            {
                DoCast(me->getVictim(), SPELL_DEATH_EMBRACE);
                uiDeath_embrace = 5000 + rand()%5000;
            }else uiDeath_embrace -= diff;

            if (uiIcy_touch < diff)
            {
                DoCast(me->getVictim(), SPELL_ICY_TOUCH1);
                uiIcy_touch = 5000 + rand()%5000;
            }else uiIcy_touch -= diff;

            if (uiUnholy_blight < diff)
            {
                DoCast(me->getVictim(), SPELL_UNHOLY_BLIGHT);
                uiUnholy_blight = 5000 + rand()%5000;
            }else uiUnholy_blight -= diff;

            if (uiFight_speech < diff)
            {
                switch(rand()%15)
                {
                    case 0: DoScriptText(SAY_LIGHT_OF_DAWN09, me);break;
                    case 1: DoScriptText(SAY_LIGHT_OF_DAWN10, me);break;
                    case 2: DoScriptText(SAY_LIGHT_OF_DAWN11, me);break;
                    case 3: DoScriptText(SAY_LIGHT_OF_DAWN12, me);break;
                    case 4: DoScriptText(SAY_LIGHT_OF_DAWN13, me);break;
                    case 5: DoScriptText(SAY_LIGHT_OF_DAWN14, me);break;
                    case 6: DoScriptText(SAY_LIGHT_OF_DAWN15, me);break;
                    case 7: DoScriptText(SAY_LIGHT_OF_DAWN16, me);break;
                    case 8: DoScriptText(SAY_LIGHT_OF_DAWN17, me);break;
                    case 9: DoScriptText(SAY_LIGHT_OF_DAWN18, me);break;
                    case 10: DoScriptText(SAY_LIGHT_OF_DAWN19, me);break;
                    case 11: DoScriptText(SAY_LIGHT_OF_DAWN20, me);break;
                    case 12: DoScriptText(SAY_LIGHT_OF_DAWN21, me);break;
                    case 13: DoScriptText(SAY_LIGHT_OF_DAWN22, me);break;
                    case 14: DoScriptText(SAY_LIGHT_OF_DAWN23, me);break;
                    case 15: DoScriptText(SAY_LIGHT_OF_DAWN24, me);break;
                }
                uiFight_speech = 15000 + rand()%5000;
            }else uiFight_speech -= diff;

            // Check spawns
            if (uiSpawncheck < diff)
            {
                SpawnNPC();
                uiSpawncheck = 1000;
            }else uiSpawncheck -= diff;

            // Check targets
            if (uiTargetcheck < diff)
            {
                for(uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                    NPCChangeTarget(uiGhoulGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                    NPCChangeTarget(uiWarriorGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                    NPCChangeTarget(uiAbominationGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                    NPCChangeTarget(uiBehemothGUID[i]);
                NPCChangeTarget(uiKoltiraGUID);
                NPCChangeTarget(uiOrbazGUID);
                NPCChangeTarget(uiThassarianGUID);

                uiTargetcheck = 10000;
            }else uiTargetcheck -= diff;

            // Battle end
            if (uiFight_duration < diff + 5000)
            {
                if (!uiTirionGUID)
                    if (Unit* pTemp = me->SummonCreature(NPC_HIGHLORD_TIRION_FORDRING, LightofDawnLoc[0].x, LightofDawnLoc[0].y, LightofDawnLoc[0].z, 1.528, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000))
                    {
                        pTemp->setFaction(me->getFaction());
                        pTemp->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_UNEQUIP));
                        DoScriptText(SAY_LIGHT_OF_DAWN25, pTemp);
                        uiTirionGUID = pTemp->GetGUID();
                    }
            }
            if (uiFight_duration < diff)
            {
                bIsBattle = false;
                uiFight_duration = 300000;

                if (me->HasAura(SPELL_THE_MIGHT_OF_MOGRAINE, 0))
                    me->RemoveAurasDueToSpell(SPELL_THE_MIGHT_OF_MOGRAINE);
                me->RemoveAllAuras();
                me->DeleteThreatList();
                me->CombatStop(true);
                me->InterruptNonMeleeSpells(false);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

                for(uint8 i = 0; i < ENCOUNTER_DEFENDER_NUMBER; ++i)
                    DespawnNPC(uiDefenderGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_EARTHSHATTER_NUMBER; ++i)
                    DespawnNPC(uiEarthshatterGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                    DespawnNPC(uiAbominationGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                    DespawnNPC(uiBehemothGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                    DespawnNPC(uiGhoulGUID[i]);
                for(uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                    DespawnNPC(uiWarriorGUID[i]);

                if (Unit* pTemp = Unit::GetUnit((*me), uiKorfaxGUID))
                {
                    pTemp->RemoveAllAuras();
                    pTemp->DeleteThreatList();
                    pTemp->CombatStop(true);
                    pTemp->AttackStop();
                    pTemp->setFaction(me->getFaction());
                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[9].x, LightofDawnLoc[9].y, LightofDawnLoc[9].z);
                }

                if (Unit* pTemp = Unit::GetUnit((*me), uiMaxwellGUID))
                {
                    pTemp->RemoveAllAuras();
                    pTemp->DeleteThreatList();
                    pTemp->CombatStop(true);
                    pTemp->AttackStop();
                    pTemp->setFaction(me->getFaction());
                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[12].x, LightofDawnLoc[12].y, LightofDawnLoc[12].z);
                }

                if (Unit* pTemp = Unit::GetUnit((*me), uiEligorGUID))
                {
                    pTemp->RemoveAllAuras();
                    pTemp->DeleteThreatList();
                    pTemp->CombatStop(true);
                    pTemp->AttackStop();
                    pTemp->setFaction(me->getFaction());
                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[15].x, LightofDawnLoc[15].y, LightofDawnLoc[15].z);
                }
                DespawnNPC(uiRayneGUID);

                if (Unit* pTemp = Unit::GetUnit((*me), uiKoltiraGUID))
                {
                    pTemp->RemoveAllAuras();
                    pTemp->DeleteThreatList();
                    pTemp->CombatStop(true);
                    pTemp->AttackStop();
                    pTemp->setFaction(me->getFaction());
                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[18].x, LightofDawnLoc[18].y, LightofDawnLoc[18].z);
                    pTemp->CastSpell(pTemp, SPELL_THE_LIGHT_OF_DAWN, false);
                }

                if (Unit* pTemp = Unit::GetUnit((*me), uiOrbazGUID))
                    DoScriptText(EMOTE_LIGHT_OF_DAWN04, pTemp);

                if (Unit* pTemp = Unit::GetUnit((*me), uiThassarianGUID))
                {
                    pTemp->RemoveAllAuras();
                    pTemp->DeleteThreatList();
                    pTemp->CombatStop(true);
                    pTemp->AttackStop();
                    pTemp->setFaction(me->getFaction());
                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[20].x, LightofDawnLoc[20].y, LightofDawnLoc[20].z);
                    pTemp->CastSpell(pTemp, SPELL_THE_LIGHT_OF_DAWN, false);
                }

                if (Unit* pTemp = Unit::GetUnit((*me), uiTirionGUID))
                    DoScriptText(SAY_LIGHT_OF_DAWN26, pTemp);

                SetHoldState(false);

            }else uiFight_duration -= diff;

            DoMeleeAttackIfReady();
        }
    }

    void JumpToNextStep(uint32 uiTimer)
    {
        uiPhase_timer = uiTimer;
        uiStep++;
    }

    void NPCChangeTarget(uint64 ui_GUID)
    {
        if (Unit* pTemp = Unit::GetUnit((*me), ui_GUID))
            if (pTemp->isAlive())
                if (Unit* pTarger = SelectUnit(SELECT_TARGET_RANDOM,0))
                    if (pTarger->isAlive())
                    {
                        //((Creature*)pTemp)->DeleteThreatList();
                        ((Creature*)pTemp)->AddThreat(pTarger, 0.0f);
                        ((Creature*)pTemp)->AI()->AttackStart(pTarger);
                        ((Creature*)pTemp)->SetInCombatWith(pTarger);
                        pTarger->SetInCombatWith(pTemp);
                        //((Creature*)pTemp)->GetMotionMaster()->MoveChase(pTarger, 20.0f);
                    }
    }

    void SpawnNPC()
    {
        Unit* pTemp = NULL;

        // Death
        for(uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
        {
            if (!(pTemp = Unit::GetUnit((*me), uiGhoulGUID[i])))
            {
                pTemp = me->SummonCreature(NPC_ACHERUS_GHOUL, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2084);
                uiGhoulGUID[i] = pTemp->GetGUID();
            }
        }
        for(uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
        {
            if (!(pTemp = Unit::GetUnit((*me), uiAbominationGUID[i])))
            {
                pTemp = me->SummonCreature(NPC_WARRIOR_OF_THE_FROZEN_WASTES, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2084);
                uiAbominationGUID[i] = pTemp->GetGUID();
            }
        }
        for(uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
        {
            if (!(pTemp = Unit::GetUnit((*me), uiWarriorGUID[i])))
            {
                pTemp = me->SummonCreature(NPC_RAMPAGING_ABOMINATION, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2084);
                uiWarriorGUID[i] = pTemp->GetGUID();
            }
        }
        for(uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
        {
            if (!(pTemp = Unit::GetUnit((*me), uiBehemothGUID[i])))
            {
                pTemp = me->SummonCreature(NPC_FLESH_BEHEMOTH, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2084);
                uiBehemothGUID[i] = pTemp->GetGUID();
            }
        }

        // Dawn
        for(uint8 i = 0; i < ENCOUNTER_DEFENDER_NUMBER; ++i)
        {
            if (!(pTemp = Unit::GetUnit((*me), uiDefenderGUID[i])))
            {
                pTemp = me->SummonCreature(NPC_DEFENDER_OF_THE_LIGHT, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2089);
                me->AddThreat(pTemp, 0.0f);
                uiDefenderGUID[i] = pTemp->GetGUID();
            }
        }
        for(uint8 i = 0; i < ENCOUNTER_EARTHSHATTER_NUMBER; ++i)
        {
            if (!(pTemp = Unit::GetUnit((*me), uiEarthshatterGUID[i])))
            {
                pTemp = me->SummonCreature(NPC_RIMBLAT_EARTHSHATTER, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2089);
                me->AddThreat(pTemp, 0.0f);
                uiEarthshatterGUID[i] = pTemp->GetGUID();
            }
        }
        if (!(pTemp = Unit::GetUnit((*me), uiKorfaxGUID)))
        {
            pTemp = me->SummonCreature(NPC_KORFAX_CHAMPION_OF_THE_LIGHT, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
            pTemp->setFaction(2089);
            me->AddThreat(pTemp, 0.0f);
            uiKorfaxGUID = pTemp->GetGUID();
        }
        if (!(pTemp = Unit::GetUnit((*me), uiMaxwellGUID)))
        {
            pTemp = me->SummonCreature(NPC_LORD_MAXWELL_TYROSUS, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
            pTemp->setFaction(2089);
            me->AddThreat(pTemp, 0.0f);
            uiMaxwellGUID = pTemp->GetGUID();
        }
        if (!(pTemp = Unit::GetUnit((*me), uiEligorGUID)))
        {
            pTemp = me->SummonCreature(NPC_COMMANDER_ELIGOR_DAWNBRINGER, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
            pTemp->setFaction(2089);
            me->AddThreat(pTemp, 0.0f);
            uiEligorGUID = pTemp->GetGUID();
        }
        if (!(pTemp = Unit::GetUnit((*me), uiRayneGUID)))
        {
            pTemp = me->SummonCreature(NPC_RAYNE, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
            pTemp->setFaction(2089);
            me->AddThreat(pTemp, 0.0f);
            uiRayneGUID = pTemp->GetGUID();
        }
    }

    void DespawnNPC(uint64 pGUID)
    {
        if (Unit* pTemp = Unit::GetUnit((*me), pGUID))
            if (pTemp->isAlive())
            {
                pTemp->SetVisibility(VISIBILITY_OFF);
                pTemp->DealDamage(pTemp, pTemp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
    }
};

bool GossipHello_npc_highlord_darion_mograine(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu( pCreature->GetGUID() );

    if (pPlayer->GetQuestStatus(12801) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM( 0, "I am ready.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_highlord_darion_mograine(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            ((npc_highlord_darion_mograineAI*)pCreature->AI())->uiStep = 1;
            ((npc_highlord_darion_mograineAI*)pCreature->AI())->Start(true, false, pPlayer->GetGUID());
            break;
    }
    return true;
}

/*######
## npc the lich king in dawn of light
######*/
struct TRINITY_DLL_DECL npc_the_lich_king_tirion_dawnAI : public ScriptedAI
{
    npc_the_lich_king_tirion_dawnAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
    void Reset() {}
    void AttackStart(Unit *who) { return; } // very sample, just don't make them aggreesive
    void UpdateAI(const uint32 diff) { return; }
    void JustDied(Unit* killer) {}
};

CreatureAI* GetAI_npc_highlord_darion_mograine(Creature* pCreature)
{
    npc_highlord_darion_mograineAI* tempAI = new npc_highlord_darion_mograineAI(pCreature);

    tempAI->FillPointMovementListForCreature();

    return (CreatureAI*)tempAI;
}

CreatureAI* GetAI_npc_the_lich_king_tirion_dawn(Creature* pCreature)
{
    return new npc_the_lich_king_tirion_dawnAI (pCreature);
}

void AddSC_the_scarlet_enclave_c2()
{
    Script *newscript;

    // How to win friends and influence enemies
    newscript = new Script;
    newscript->Name="npc_crusade_persuaded";
    newscript->GetAI = &GetAI_npc_crusade_persuaded;
    newscript->RegisterSelf();

    // Ambush At The Overlook
    newscript = new Script;
    newscript->Name="mob_scarlet_courier";
    newscript->GetAI = &GetAI_mob_scarlet_courier;
    newscript->RegisterSelf();

    // 12727 Bloody Breakout
    newscript = new Script;
    newscript->Name = "npc_koltira_deathweaver";
    newscript->GetAI = &GetAI_npc_koltira_deathweaver;
    newscript->pQuestAccept = &QuestAccept_npc_koltira_deathweaver;
    newscript->RegisterSelf();



    newscript = new Script;
    newscript->Name="npc_koltira_deathweaver";
    newscript->GetAI = &GetAI_npc_koltira_deathweaver;
    newscript->pQuestAccept = &QuestAccept_npc_koltira_deathweaver;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_high_inquisitor_valroth";
    newscript->GetAI = &GetAI_mob_high_inquisitor_valroth;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_highlord_darion_mograine";
    newscript->GetAI = &GetAI_npc_highlord_darion_mograine;
    newscript->pGossipHello =  &GossipHello_npc_highlord_darion_mograine;
    newscript->pGossipSelect = &GossipSelect_npc_highlord_darion_mograine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_the_lich_king_tirion_dawn";
    newscript->GetAI = &GetAI_npc_the_lich_king_tirion_dawn;
    newscript->RegisterSelf();
}