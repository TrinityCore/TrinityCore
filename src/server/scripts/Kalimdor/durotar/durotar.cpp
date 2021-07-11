/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2010 MaNGOSZero <http://github.com/mangoszero/mangoszero/>
 *
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
SDName: Durotar
SD%Complete: 100
SDComment: Quest support: Lazy peons
SDCategory: Durotar
EndScriptData */

#include "scriptPCH.h"

enum LazyPeon
{
    QUEST_LAZY_PEONS                              = 5441,
    GO_LUMBERPILE                                 = 175784,        //300046,
    SPELL_BUFF_SLEEP                              = 17743,
    SPELL_AWAKEN_PEON                             = 19938,
    SAY_SPELL_HIT                                 = -1000600,
    SAY_SPELL_HIT2                                = -1000601, //Sleepy so sleepy
    LAZY_PEON_ENTRY                               = 10556,
    EMOTE_WORKING                                 = 234,
    WORKING_DURATION                              = 120000
};

enum States
{
    STATE_SLEEPING,
    STATE_START_MOVING_TO_LUMBERPILE,
    STATE_MOVING_TO_LUMBERPILE,
    STATE_WORKING,
    STATE_MOVING_BACK,
    STATE_WAKEUP,
};

struct LazyPeonAI : public ScriptedAI
{
    LazyPeonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        timer_before_sleep   = 0;
        timer_before_working = 3000;
        state                = STATE_SLEEPING;
        timer_before_moving_to_lumberpile = 2000;
        playerGuid.Clear();
        Reset();
    }

    uint32     timer_before_sleep;
    uint32     timer_before_working;
    uint32     timer_before_moving_to_lumberpile;
    uint8      state;
    ObjectGuid playerGuid;

    void DoAction(uint32 const state) override
    {
        this->state = state;
    }

    void Reset() override {}

    void SpellHit(Unit* caster, SpellEntry const* spell) override
    {
        if (spell->Id == SPELL_AWAKEN_PEON && m_creature->GetEntry() == LAZY_PEON_ENTRY && m_creature->HasAura(SPELL_BUFF_SLEEP))
        {
            playerGuid = caster->GetObjectGuid();

            /** Peon wake up */
            state = STATE_WAKEUP;
            timer_before_moving_to_lumberpile = 0;
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        switch (state)
        {
            case STATE_SLEEPING:
                if (!m_creature->HasAura(SPELL_BUFF_SLEEP))
                    DoCastSpellIfCan(m_creature, SPELL_BUFF_SLEEP);
                break;
            case STATE_WORKING:
                if (timer_before_sleep < diff)
                {
                    state = STATE_MOVING_BACK;
                    m_creature->HandleEmoteState(0);
                    float x, y, z, o;
                    m_creature->GetHomePosition(x, y, z, o);
                    m_creature->GetMotionMaster()->MovePoint(1, x, y, z);
                }
                else
                    timer_before_sleep -= diff;
                break;
            case STATE_WAKEUP:
                if (timer_before_working < diff)
                {
                    m_creature->RemoveAurasDueToSpell(SPELL_BUFF_SLEEP);
                    state = STATE_START_MOVING_TO_LUMBERPILE;
                    timer_before_moving_to_lumberpile = 2000;
                    timer_before_working = 3000;
                }
                else
                    timer_before_working -= diff;
                break;
            case STATE_START_MOVING_TO_LUMBERPILE:
                if (timer_before_moving_to_lumberpile < diff)
                {
                    if (GameObject* LumberPile = m_creature->FindNearestGameObject(GO_LUMBERPILE, 20.0f))
                    {
                        m_creature->SetWalk(true);
                        /*float inv_distance = 1.5 / m_creature->GetDistance(LumberPile);
                        m_creature->GetMotionMaster()->MovePoint(1,
                                                           LumberPile->GetPositionX() - inv_distance * (LumberPile->GetPositionX() - m_creature->GetPositionX()),
                                                           LumberPile->GetPositionY() - inv_distance * (LumberPile->GetPositionY() - m_creature->GetPositionY()),
                                                           LumberPile->GetPositionZ() - inv_distance * (LumberPile->GetPositionZ() - m_creature->GetPositionZ()),
                                                           MOVE_PATHFINDING);//not enough...
                                                           */
                        float fX, fY, fZ;
                        LumberPile->GetContactPoint(m_creature, fX, fY, fZ, CONTACT_DISTANCE + 0.2f);
                        m_creature->GetMotionMaster()->MovePoint(1, fX, fY, fZ, MOVE_PATHFINDING);

                        timer_before_moving_to_lumberpile = 2000;
                    }

                    if (Player* player = m_creature->GetMap()->GetPlayer(playerGuid))
                    {
                        if (urand(0, 1))
                            DoScriptText(SAY_SPELL_HIT,  m_creature, player);
                        else
                            DoScriptText(SAY_SPELL_HIT2, m_creature);
                    }
                    state = STATE_MOVING_TO_LUMBERPILE;
                }
                else
                    timer_before_moving_to_lumberpile -= diff;
                break;

            default:
                break;
        }
    }

    void MovementInform(uint32 MovementType, uint32 id) override
    {
        if (MovementType == POINT_MOTION_TYPE && id == 1)
        {
            //sLog.nostalrius("LazyPeons Movement inform.");
            if (state == STATE_MOVING_TO_LUMBERPILE)
            {
                state = STATE_WORKING;
                if (GameObject* LumberPile = m_creature->FindNearestGameObject(GO_LUMBERPILE, 20.0f))
                    m_creature->SetFacingToObject(LumberPile);
                m_creature->HandleEmoteState(EMOTE_WORKING);
                timer_before_sleep = WORKING_DURATION;
            }
            else // STATE_MOVING_BACK
            {
                state = STATE_SLEEPING;
                DoCastSpellIfCan(m_creature, SPELL_BUFF_SLEEP);
            }
        }
    }
};

bool peon_wake_up(WorldObject* pCaster, uint32 spellId, SpellEffectIndex effIndex, Creature *crTarget)
{
    if (spellId == SPELL_AWAKEN_PEON && crTarget->GetEntry() == LAZY_PEON_ENTRY && crTarget->HasAura(SPELL_BUFF_SLEEP))
    {
        /** Display updated quest status */
        if (Player* pPlayer = pCaster->ToPlayer())
            pPlayer->KilledMonsterCredit(crTarget->GetEntry(), crTarget->GetObjectGuid());
    }

    return true;
}

CreatureAI* GetAI_LazyPeon(Creature* pCreature)
{
    return new LazyPeonAI(pCreature);
}


void AddSC_durotar()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "LazyPeons";
    newscript->pEffectDummyCreature = &peon_wake_up;
    newscript->GetAI = &GetAI_LazyPeon;

    newscript->RegisterSelf();
}
