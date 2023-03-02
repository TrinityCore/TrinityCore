/*
 * Copyright (C) 2010-2014 Anathema Script Engine project <http://valkyrie-wow.com/>
 */

#include "scriptPCH.h"
#include "boss_omen.h"
#include "GameEventMgr.h"

/*
 *
 */

boss_omenAI::boss_omenAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    boss_omenAI::Reset();
}

void boss_omenAI::Reset()
{

}

void boss_omenAI::OnRemoveFromWorld()
{
    if (sGameEventMgr.IsActiveEvent(GAME_EVENT_MINIONS_OF_OMEN))
        sGameEventMgr.StopEvent(GAME_EVENT_MINIONS_OF_OMEN);
}

void boss_omenAI::MovementInform(uint32 movementType, uint32 data)
{
    if (movementType == POINT_MOTION_TYPE)
    {
        if (data == 1)
            m_creature->GetMotionMaster()->MovePoint(2, 7549.98f, -2855.14f, 456.968f, MOVE_PATHFINDING | MOVE_RUN_MODE);
        else if (data == 2)
            m_creature->GetMotionMaster()->MovePoint(3, OmenHome.x, OmenHome.y, OmenHome.z, MOVE_PATHFINDING | MOVE_RUN_MODE);
        else if (data == 3)
        {
            m_creature->GetMotionMaster()->Clear(false, true);
            m_creature->GetMotionMaster()->Initialize();
        }
    }
}

void boss_omenAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        return;

    if (!m_CreatureSpells.empty())
        UpdateSpellsList(uiDiff);

    DoMeleeAttackIfReady();
}

void boss_omenAI::SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpellEntry)
{
    if (pSpellEntry->Id == SPELL_ELUNES_CANDLE)
    {
        // proofs required
        //if (m_uiStarfallTimer < 2000)
        //    m_uiStarfallTimer = 2000;

        DoCastSpellIfCan(m_creature, SPELL_SELF_DAMAGE, true);
    }      
}

void boss_omenAI::JustDied(Unit* /*pKiller*/)
{
    DoCastSpellIfCan(m_creature, SPELL_OMENS_MOONLIGHT);
    OmenData.m_uiNextRespawn = time(nullptr) + 15 * MINUTE;
    OmenData.m_bOmenAlive = false;
    m_creature->DespawnOrUnsummon(5 * MINUTE * IN_MILLISECONDS);
}

void boss_omenAI::OnFireworkLaunch(Unit* pSummoner)
{
    if (!OmenData.m_bOmenAlive)
    {
        ++OmenData.m_uiFireworksCount;

        if (OmenData.m_uiFireworksCount >= 3 &&
            !sGameEventMgr.IsActiveEvent(GAME_EVENT_MINIONS_OF_OMEN))
            sGameEventMgr.StartEvent(GAME_EVENT_MINIONS_OF_OMEN);

        if (OmenData.m_uiFireworksCount < 20)
            return;

        if (OmenData.m_uiNextRespawn < time(nullptr))
        {
            auto pOmen = pSummoner->SummonCreature(NPC_OMEN,
                OmenSummon.x,
                OmenSummon.y,
                OmenSummon.z,
                OmenSummon.o, TEMPSUMMON_TIMED_COMBAT_OR_DEAD_DESPAWN, 2 * HOUR * IN_MILLISECONDS, true);

            if (pOmen)
            {
                OmenData.m_uiFireworksCount = 0;
                OmenData.m_bOmenAlive = true;
                pOmen->SetHomePosition(OmenHome.x, OmenHome.y, OmenHome.z, OmenHome.o);
                pOmen->SetWanderDistance(10.0f);
                pOmen->SetDefaultMovementType(RANDOM_MOTION_TYPE);
                pOmen->m_Events.AddLambdaEventAtOffset([pOmen]
                {
                    pOmen->PlayDistanceSound(SOUND_CHARACTER_SPLASH);
                    pOmen->PlayDistanceSound(SOUND_HYDRA_SPECIAL_AGGRO);
                }, 800);
                pOmen->m_Events.AddLambdaEventAtOffset([pOmen]
                {
                    if (!pOmen->IsInCombat())
                        pOmen->GetMotionMaster()->MovePoint(1, 7553.95f, -2848.48f, 454.56f, MOVE_RUN_MODE);
                    pOmen->GetMotionMaster()->InitializeNewDefault(true);
                }, 4000);
                
                sLog.outInfo("[Moonglade.Omen] Summoned.");
            }
            else
                sLog.outInfo("[Moonglade.Omen] Summon failed.");
        }
    }
}

CreatureAI* GetAI_boss_omen(Creature* creature)
{
    return new boss_omenAI(creature);
}

void AddSC_boss_omen()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_omen";
    pNewScript->GetAI = &GetAI_boss_omen;
    pNewScript->RegisterSelf();
}
