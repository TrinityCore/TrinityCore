/* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Sholazar_Basin
SD%Complete: 100
SDComment: Quest support: 11253.
SDCategory: howling_fjord
EndScriptData */

/* ContentData
npc_plaguehound_tracker
EndContentData */

/*######
## npc_plaguehound_tracker
######*/

enum
{
    QUEST_SNIFF_OUT_ENEMY        = 11253
};

struct TRINITY_DLL_DECL npc_plaguehound_trackerAI : public npc_escortAI
{
    npc_plaguehound_trackerAI(Creature* pCreature) : npc_escortAI(pCreature) { }

   
    void Reset()
    {
        InitScriptData();
    }

    void InitScriptData()
    {
        Player* pPlayer = NULL;
        if(me->isSummon())
            if(Unit* summoner = CAST_SUM(me)->GetSummoner())
                if(summoner->GetTypeId() == TYPEID_PLAYER)
                    pPlayer = CAST_PLR(summoner);

        if (!pPlayer)
            return;

        me->SetUnitMovementFlags(MOVEMENTFLAG_WALK_MODE);
        Start(false, false, pPlayer->GetGUID());
    }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = NULL;
        if(me->isSummon())
            if(Unit* summoner = CAST_SUM(me)->GetSummoner())
                if(summoner->GetTypeId() == TYPEID_PLAYER)
                    pPlayer = CAST_PLR(summoner);

        if (!pPlayer)
            return;

        switch(i)
        {
        case 26:
            me->ForcedDespawn();
            break;
        }
    }
};

CreatureAI* GetAI_npc_plaguehound_tracker(Creature* pCreature)
{
    return new npc_plaguehound_trackerAI(pCreature);
}

void AddSC_howling_fjord()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_plaguehound_tracker";
    newscript->GetAI = &GetAI_npc_plaguehound_tracker;
    newscript->RegisterSelf();
}
