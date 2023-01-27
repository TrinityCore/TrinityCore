/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Blasted_Lands
SD%Complete: 90
SDCategory: Blasted Lands
EndScriptData */

/* ContentData
npc_thadius_grimshade
go_stone_of_binding
EndContentData */

#include "scriptPCH.h"

struct ThadiusGrimshadeAI : public ScriptedAI
{
    ThadiusGrimshadeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        underEvent = false;
        m_uiBeginTimer = 3000;
        m_uiTranceTimer = 8000;
        grimshadeGUID = 0;
        underTrance = false;
        underSpeak = false;
        m_uiSpeakTimer = 8000;
        sentence = false;
        createObject = false;
        isStun = false;
        playerGUID = 0;
        Reset();
    }

    bool underEvent;
    bool underTrance;
    bool underSpeak;
    bool sentence;
    bool createObject;
    bool isStun;
    uint32 m_uiSpeakTimer;
    uint32 m_uiBeginTimer;
    uint32 m_uiTranceTimer;
    uint64 grimshadeGUID;
    uint64 playerGUID;

    void Reset() override
    {
    }

    void QuestCompleted(Player* pPlayer, Quest const* pQuest)
    {
        if (!underEvent)
        {
            playerGUID = pPlayer->GetGUID();
            underEvent = true;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (underEvent)
        {
            if (!createObject)
            {
                if (GameObject* pGo = m_creature->SummonGameObject(144069, -10999.166992f, -3484.187012f, 103.127243f, 2.592681f))
                    grimshadeGUID = pGo->GetGUID();
                createObject = true;
            }
            if (m_uiBeginTimer < uiDiff)
                underTrance = true;
            else
                m_uiBeginTimer -= uiDiff;

        }

        if (underTrance)
        {
            if (!isStun)
            {
                m_creature->HandleEmote(EMOTE_STATE_STUN);
                isStun = true;
            }
            if (m_uiTranceTimer < uiDiff)
                underSpeak = true;
            else
                m_uiTranceTimer -= uiDiff;

        }

        if (underSpeak)
        {
            if (!sentence)
            {
                m_creature->MonsterSay("...Cage...temple...trolls...", 0, 0);
                sentence = true;
            }
            if (m_uiSpeakTimer < uiDiff)
            {
                m_creature->HandleEmote(EMOTE_STATE_NONE);
                if (GameObject* pVision = m_creature->GetMap()->GetGameObject(grimshadeGUID))
                    pVision->Delete();

                underEvent = false;
                m_uiBeginTimer = 3000;
                m_uiTranceTimer = 3000;
                grimshadeGUID = 0;
                underTrance = false;
                underSpeak = false;
                m_uiSpeakTimer = 3000;
                sentence = false;
                createObject = false;
                isStun = false;

                if (Player* player = m_creature->GetMap()->GetPlayer(playerGUID))
                {
                    if (player->GetQuestStatus(2992) == QUEST_STATUS_INCOMPLETE)
                        player->AreaExploredOrEventHappens(2992);
                }
            }
            else
                m_uiSpeakTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_thadius_grimshade(Creature* pCreature)
{
    return new ThadiusGrimshadeAI(pCreature);
}

bool QuestAccept_npc_Thadius_Grimshade(Player* pPlayer, Creature* pQuestGiver, Quest const* pQuest)
{
    if (pQuest->GetQuestId() != 2992)
        return false;

    if (ThadiusGrimshadeAI* pThadius = dynamic_cast<ThadiusGrimshadeAI*>(pQuestGiver->AI()))
        pThadius->QuestCompleted(pPlayer, pQuest);
    return true;
}
bool GOHello_go_stone_of_binding(Player* pPlayer, GameObject* pGo)
{
// 141812 <= 7668 Servant of Razelikh   // 141857 <= 7669 Servant of Grol
// 141858 <= 7670 Servant of Allistarj  // 141859 <= 7671 Servant of Sevine
    Creature* pCreature = nullptr;
    switch(pGo->GetEntry())
    {
        case 141812:
            pCreature = pGo->FindNearestCreature(7668, 30.000000, true);//servant of razelikh
            break;
        case 141857:
            pCreature = pGo->FindNearestCreature(7669, 30.000000, true);//servant of grol
            break;
        case 141858:
            pCreature = pGo->FindNearestCreature(7670, 30.000000, true);//servant of allistarj
            break;
        case 141859:
            pCreature = pGo->FindNearestCreature(7671, 30.000000, true);//servant of sevine
            break;
    }
    if (pCreature)
        pCreature->CastSpell(pCreature, 12938, true);
    return false;
}
void AddSC_blasted_lands()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_thadius_grimshade";
    newscript->GetAI = &GetAI_thadius_grimshade;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_Thadius_Grimshade;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_stone_of_binding";
    newscript->pGOHello = &GOHello_go_stone_of_binding;
    newscript->RegisterSelf();
}
