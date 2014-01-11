/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Burning_Steppes
SD%Complete: 0
SDComment:
SDCategory: Burning Steppes
EndScriptData */

enum RaggedJohn
{
    QUEST_THE_TRUE_MASTERS        = 4224,
    QUEST_MOTHERS_MILK            = 4866,
    SPELL_MOTHERS_MILK            = 16468,
    SPELL_WICKED_MILKING          = 16472
};

    struct npc_ragged_johnAI : public ScriptedAI
    {
        npc_ragged_johnAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE { }

        void MoveInLineOfSight(Unit* who) OVERRIDE
        {
            if (who->HasAura(SPELL_MOTHERS_MILK))
            {
                if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 15) && who->isInAccessiblePlaceFor(me))
                {
                    DoCast(who, SPELL_WICKED_MILKING);
                    if (Player* player = who->ToPlayer())
                        player->AreaExploredOrEventHappens(QUEST_MOTHERS_MILK);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }
    };

void AddSC_burning_steppes()
{

}
