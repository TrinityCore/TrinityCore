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

struct TRINITY_DLL_DECL mob_anti_airAI : public ScriptedAI
{
    mob_anti_airAI(Creature *c) : ScriptedAI(c)
    {
        assert(me->m_spells[0]);
        range = DoGetSpellMaxRange(me->m_spells[0]);
    }

    float range;

    void MoveInLineOfSight(Unit *who)
    {
        if(!me->getVictim() && me->canAttack(who)
            && me->IsWithinCombatRange(who, range)
            && me->IsWithinLOSInMap(who))
            AttackStart(who);
    }

    void AttackStart(Unit *who)
    {
        if(who->IsFlying() || !me->IsWithinMeleeRange(who))
        {
            if(me->Attack(who, false))
                me->GetMotionMaster()->MoveIdle();
        }
        else if(me->Attack(who, true))
            me->GetMotionMaster()->MoveChase(who);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(me->getVictim()->IsFlying() || !me->IsWithinMeleeRange(me->getVictim()))
        {
            if(!DoSpellAttackIfReady(me->m_spells[0]))
                EnterEvadeMode();
        }
        else
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_anti_air(Creature* pCreature)
{
    return new mob_anti_airAI (pCreature);
}

void AddSC_the_scarlet_enclave()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_valkyr_battle_maiden";
    newscript->GetAI = &GetAI_npc_valkyr_battle_maiden;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_anti_air";
    newscript->GetAI = &GetAI_mob_anti_air;
    newscript->RegisterSelf();
}
