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

/* Script Data Start
SDName: Dalaran
SDAuthor: WarHead, MaXiMiUS
SD%Complete: 99%
SDComment: For what is 63990+63991? Same function but don't work correct...
SDCategory: Dalaran
Script Data End */

#include "precompiled.h"

/*******************************************************
 * npc_mageguard_dalaran
 *******************************************************/

enum Spells
{
    SPELL_TRESPASSER_A = 54028,
    SPELL_TRESPASSER_H = 54029
};

enum NPCs // All outdoor guards are within 35.0f of these NPCs
{
    NPC_APPLEBOUGH_A = 29547,
    NPC_SWEETBERRY_H = 29715,
};

struct TRINITY_DLL_DECL npc_mageguard_dalaranAI : public Scripted_NoMovementAI
{
    npc_mageguard_dalaranAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
    {
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        pCreature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_NORMAL, true);
        pCreature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
    }

    void Reset(){}

    void Aggro(Unit* pWho){}

    void AttackStart(Unit* pWho){}

    void MoveInLineOfSight(Unit *pWho)
    {
        if (!pWho || !pWho->IsInWorld() || pWho->GetZoneId() != 4395)
            return;

        if (!me->IsWithinDist(pWho, 65.0f, false))
            return;

        Player *pPlayer = pWho->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!pPlayer || pPlayer->isGameMaster() || pPlayer->IsBeingTeleported())
            return;

        switch (m_creature->GetEntry())
        {
            case 29254:
                if (pPlayer->GetTeam() == HORDE)              // Horde unit found in Alliance area
                    if (Creature *pOutdoorNPC = GetClosestCreatureWithEntry(me, NPC_APPLEBOUGH_A, 32.0f))
                    {
                        if (me->isInBackInMap(pWho, 12.0f))   // In my line of sight, "outdoors", and behind me
                            DoCast(pWho, SPELL_TRESPASSER_A); // Teleport the Horde unit out
                    }
                    else                                      // In my line of sight, and "indoors"
                        DoCast(pWho, SPELL_TRESPASSER_A);     // Teleport the Horde unit out
                break;
            case 29255:
                if (pPlayer->GetTeam() == ALLIANCE)           // Alliance unit found in Horde area
                    if (Creature *pOutdoorNPC = GetClosestCreatureWithEntry(me, NPC_SWEETBERRY_H, 32.0f))
                    {
                        if (me->isInBackInMap(pWho, 12.0f))   // In my line of sight, "outdoors", and behind me
                            DoCast(pWho, SPELL_TRESPASSER_H); // Teleport the Alliance unit out
                    }
                    else                                      // In my line of sight, and "indoors"
                        DoCast(pWho, SPELL_TRESPASSER_H);     // Teleport the Alliance unit out
                break;
        }
        me->SetOrientation(me->GetHomePosition().GetOrientation());
        return;
    }

    void UpdateAI(const uint32 diff){}
};

CreatureAI* GetAI_npc_mageguard_dalaran(Creature* pCreature)
{
    return new npc_mageguard_dalaranAI(pCreature);
}

void AddSC_dalaran()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_mageguard_dalaran";
    newscript->GetAI = &GetAI_npc_mageguard_dalaran;
    newscript->RegisterSelf();
}
