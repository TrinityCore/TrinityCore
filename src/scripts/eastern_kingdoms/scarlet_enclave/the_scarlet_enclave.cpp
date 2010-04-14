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

/*####
## npc_valkyr_battle_maiden
####*/
#define SPELL_REVIVE 51918
#define VALK_WHISPER "It is not yet your time, champion. Rise! Rise and fight once more!"

struct npc_valkyr_battle_maidenAI : public PassiveAI
{
    npc_valkyr_battle_maidenAI(Creature *c) : PassiveAI(c) {}

    uint32 FlyBackTimer;
    float x, y, z;
    uint32 phase;

    void Reset()
    {
        me->setActive(true);
        me->SetVisibility(VISIBILITY_OFF);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlying(true);
        FlyBackTimer = 500;
        phase = 0;

        me->GetPosition(x, y, z);
        z += 4; x -= 3.5; y -= 5;
        me->GetMotionMaster()->Clear(false);
        me->GetMap()->CreatureRelocation(me, x, y, z, 0.0f);
    }

    void UpdateAI(const uint32 diff)
    {
        if (FlyBackTimer <= diff)
        {
            Player *plr = NULL;
            if (me->isSummon())
                if (Unit *summoner = CAST_SUM(me)->GetSummoner())
                    if (summoner->GetTypeId() == TYPEID_PLAYER)
                        plr = CAST_PLR(summoner);

            if (!plr)
                phase = 3;

            switch(phase)
            {
                case 0:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    me->HandleEmoteCommand(EMOTE_STATE_FLYGRABCLOSED);
                    FlyBackTimer = 500;
                    break;
                case 1:
                    plr->GetClosePoint(x,y,z, me->GetObjectSize());
                    z += 2.5; x -= 2; y -= 1.5;
                    me->GetMotionMaster()->MovePoint(0, x, y, z);
                    me->SetUInt64Value(UNIT_FIELD_TARGET, plr->GetGUID());
                    me->SetVisibility(VISIBILITY_ON);
                    FlyBackTimer = 4500;
                    break;
                case 2:
                    if (!plr->isRessurectRequested())
                    {
                        me->HandleEmoteCommand(EMOTE_ONESHOT_CUSTOMSPELL01);
                        DoCast(plr, SPELL_REVIVE, true);
                        me->MonsterWhisper(VALK_WHISPER, plr->GetGUID());
                    }
                    FlyBackTimer = 5000;
                    break;
                case 3:
                    me->SetVisibility(VISIBILITY_OFF);
                    FlyBackTimer = 3000;
                    break;
                case 4:
                    me->DisappearAndDie();
                    break;
                default:
                    //Nothing To DO
                    break;
            }
            ++phase;
        } else FlyBackTimer-=diff;
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
    newscript->Name = "npc_valkyr_battle_maiden";
    newscript->GetAI = &GetAI_npc_valkyr_battle_maiden;
    newscript->RegisterSelf();

    // Chapter 3: Scarlet Armies Approach... - An End To All Things...
    // Chapter 4: An End To All Things... - An End To All Things...
}
