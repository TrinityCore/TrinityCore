/*
 *
 */

#include "scriptPCH.h"
#include "Group.h"
#include "quest_stormwind_rendezvous.h"

/*
 *
 */

npc_reginald_windsorAI::npc_reginald_windsorAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    npc_reginald_windsorAI::Reset();
    npc_reginald_windsorAI::ResetCreature();
}

Player* npc_reginald_windsorAI::GetPlayer() const
{
    return me->GetMap()->GetPlayer(playerGUID);
}

Creature* npc_reginald_windsorAI::GetGuard(uint8 num) const
{
    return me->GetMap()->GetCreature(GuardsGUIDs[num]);
}

void npc_reginald_windsorAI::ResetCreature()
{
    m_bRoweKnows = false;
    m_squireRoweGuid.Clear();

    m_uiDespawnTimer = 5 * MINUTE * IN_MILLISECONDS;
    Timer = 3000;
    Tick = 0;
    playerGUID = 0;
    GreetPlayer = false;
    QuestAccepted = false;
    BeginQuest = false;
    Begin = true;
    NeedCheck = false;
    PhaseFinale = false;
    TheEnd = false;
    CombatJustEnded = false;

    for (uint8 i = 0; i < 6; i++)
    {
        GuardTimer[i] = 0;
        GuardNeed[i] = false;
    }
    for (uint64 & guid : GuardsGUIDs)
        guid = 0;

    for (uint64 & guid : DragsGUIDs)
        guid = 0;
}

void npc_reginald_windsorAI::JustDied(Unit* /*pKiller*/)
{
    PokeRowe();
    m_creature->DespawnOrUnsummon(7 * MINUTE * IN_MILLISECONDS);
}

void npc_reginald_windsorAI::PokeRowe()
{
    if (!m_bRoweKnows)
    {
        // let Squire Rowe know he can allow players to proceed with quest now
        if (auto pRowe = m_creature->GetMap()->GetCreature(m_squireRoweGuid))
        {
            if (auto pRoweAI = static_cast<npc_squire_roweAI*>(pRowe->AI()))
            {
                pRoweAI->ResetCreature();
                m_bRoweKnows = true;
            }
        }
    }
}

void npc_reginald_windsorAI::CompleteQuest()
{
    if (Player* pPlayer = GetPlayer())
    {
        if (Group* jGroup = pPlayer->GetGroup())
        {
            for (GroupReference* pRef = jGroup->GetFirstMember(); pRef != nullptr; pRef = pRef->next())
            {
                if (pRef->getSource()->GetQuestStatus(QUEST_THE_GREAT_MASQUERADE) == QUEST_STATUS_INCOMPLETE)
                    pRef->getSource()->CompleteQuest(QUEST_THE_GREAT_MASQUERADE);
            }
        }
        else
        {
            if (pPlayer->GetQuestStatus(QUEST_THE_GREAT_MASQUERADE) == QUEST_STATUS_INCOMPLETE)
                pPlayer->CompleteQuest(QUEST_THE_GREAT_MASQUERADE);
        }
    }
}

void npc_reginald_windsorAI::EndScene()
{
    if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
    {
        float X = 0.0f;
        float Y = 0.0f;
        float Z = 0.0f;
        float orientation = 0.0f;
        Bolvar->SetStandState(UNIT_STAND_STATE_STAND);
        Bolvar->GetRespawnCoord(X, Y, Z, &orientation);
        Bolvar->GetMotionMaster()->MovePoint(0, X, Y, Z, MOVE_NONE, 0, orientation);
    }

    if (Creature* Anduin = m_creature->FindNearestCreature(NPC_ANDUIN_WRYNN, 150.0f))
    {
        float X = 0.0f;
        float Y = 0.0f;
        float Z = 0.0f;
        float orientation = 0.0f;
        Anduin->GetRespawnCoord(X, Y, Z, &orientation);
        Anduin->GetMotionMaster()->MovePoint(0, X, Y, Z, MOVE_NONE, 0, orientation);
        float x = Anduin->GetPositionX() - X;
        float y = Anduin->GetPositionY() - Y;
        FinalTimer = 1000 + sqrt((x * x) + (y * y)) / (Anduin->GetSpeed(MOVE_WALK) * 0.001f);
        PhaseFinale = true;
    }

    if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
    {
        Onyxia->RemoveAurasDueToSpell(SPELL_GREATER_INVISIBILITY);
        Onyxia->CastSpell(Onyxia, SPELL_INVISIBILITY, true);
    }
}

void npc_reginald_windsorAI::UpdateAI_corpse(uint32 const uiDiff)
{
    if (!PhaseFinale)
        return;

    if (FinalTimer < uiDiff)
    {
        float X = 0.0f;
        float Y = 0.0f;
        float Z = 0.0f;
        float O = 0.0f;
        if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
        {
            Bolvar->GetRespawnCoord(X, Y, Z, &O);
            Bolvar->SetFacingTo(O);
        }
        if (Creature* Anduin = m_creature->FindNearestCreature(NPC_ANDUIN_WRYNN, 150.0f))
        {
            Anduin->GetRespawnCoord(X, Y, Z, &O);
            Anduin->SetFacingTo(O);
        }
        if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
        {
            Onyxia->GetRespawnCoord(X, Y, Z, &O);
            Onyxia->SetFacingTo(O);
            Onyxia->SetEntry(NPC_KATRANA_PRESTOR);
            Onyxia->UpdateEntry(NPC_KATRANA_PRESTOR);
        }
        TheEnd = true;
        FinalTimer = 5000;
    }
    else
        FinalTimer -= uiDiff;

    if (TheEnd)
    {
        if (FinalTimer < uiDiff)
        {
            PokeRowe();
            TheEnd = false;
        }
    }
}

uint32 GetRandomGuardText()
{
    switch (urand(0, 7))
    {
        case 0:
            return 8167; // Light be with you, sir.
        case 1:
            return 8170; // You are an inspiration to us all, sir.
        case 2:
            return 8172; // There walks a hero.
        case 3:
            return 8175; // Make way!
        case 4:
            return 8177; // We are but dirt beneath your feet, sir.
        case 5:
            return 8180; // A moment I shall remember for always.
        case 6:
            return 8183; // ...nerves of thorium.
    }
    return 8184; // A living legend... 
}

void npc_reginald_windsorAI::MoveInLineOfSight(Unit* Victim)
{
    if (Victim && Victim->IsAlive())
    {
        if (Victim->GetEntry() == NPC_STORMWIND_CITY_GUARD ||
            Victim->GetEntry() == NPC_STORMWIND_ROYAL_GUARD ||
            Victim->GetEntry() == NPC_STORMWIND_CITY_PATROL)
        {
            if (Victim->GetDistance2d(m_creature) < 8.0f && NeedCheck)
            {
                bool Continuer = true;
                for (uint64 guid : GuardsGUIDs)
                {
                    if (Victim->GetGUID() == guid || m_creature->GetPositionY() < 360)
                        Continuer = false;
                }
                if (Continuer)
                {
                    Victim->SetFacingToObject(m_creature);
                    Victim->HandleEmote(EMOTE_ONESHOT_SALUTE);
                    Victim->MonsterSay(GetRandomGuardText());
                    int Var = 0;
                    while (GuardsGUIDs[Var] && Var < 29)
                        Var++;

                    GuardsGUIDs[Var] = Victim->GetGUID();
                }
            }
        }
    }
}

void npc_reginald_windsorAI::SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpellEntry)
{
    if (pSpellEntry->Id == SPELL_WINDSOR_DEATH)
        m_creature->SetFeignDeath(true);
}

void npc_reginald_windsorAI::UpdateAI(uint32 const uiDiff)
{
    // in case of idle / afk players
    if (m_uiDespawnTimer < uiDiff)
    {
        PokeRowe();
        m_creature->DespawnOrUnsummon();
    }
    else
        m_uiDespawnTimer -= uiDiff;

    for (int i = 0; i < 6; i++)
    {
        if (GuardNeed[i])
        {
            if (GuardTimer[i] < uiDiff)
            {
                if (Creature* pGuard = GetGuard(i))
                {
                    int Var = i + 7;
                    pGuard->SetFacingTo(WindsorEventMove[Var].o);
                    pGuard->SetStandState(UNIT_STAND_STATE_KNEEL);
                    GuardNeed[i] = false;
                }
            }
            else
                GuardTimer[i] -= uiDiff;
        }
    }
    if (Begin)
    {
        if (m_creature->GetDistance2d(WindsorWaypoints[0].x, WindsorWaypoints[0].y) < 2.0f)
        {
            if (Timer <= uiDiff)
            {
                Begin = false;
                m_creature->SetWalk(true);
                m_creature->SetSpeedRate(MOVE_WALK, 1.0f);

                if (Creature* pRowe = m_creature->FindNearestCreature(NPC_ROWE, 50.0f))
                    pRowe->HandleEmote(EMOTE_ONESHOT_SALUTE);

                Timer = 2000;
                SummonHorse = true;
            }
            else
                Timer -= uiDiff;
        }
    }

    if (SummonHorse)
    {
        if (Timer <= uiDiff)
        {
            SummonHorse = false;
            m_creature->Unmount();
            DoCast(m_creature, SPELL_WINDSOR_DISMISS_HORSE, true);
            if (Creature* pMercutio = m_creature->FindNearestCreature(NPC_MERCUTIO, 10.0f))
            {
                pMercutio->SetWalk(false);
                m_creature->SetFacingToObject(pMercutio);
            }
            ShooHorse = true;
            Timer = 2000;
        }
        else
            Timer -= uiDiff;
    }

    if (ShooHorse)
    {
        if (Timer <= uiDiff)
        {
            ShooHorse = false;
            if (Creature* pMercutio = m_creature->FindNearestCreature(NPC_MERCUTIO, 10.0f))
            {
                DoScriptText(SAY_WINDSOR1, m_creature);
                pMercutio->GetMotionMaster()->MovePoint(0, -9148.395508f, 371.322174f, 90.543655f);
            }
            GreetPlayer = true;
            Timer = 5000;
        }
        else
            Timer -= uiDiff;
    }

    if (!BeginQuest)
    {
        if (GreetPlayer)
        {
            if (Timer <= uiDiff)
            {
                Player* pPlayer = GetPlayer();
                if (pPlayer)
                {
                    m_creature->SetFacingToObject(pPlayer);
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    DoScriptText(SAY_WINDSOR2, m_creature, pPlayer);
                }
                GreetPlayer = false;
            }
            else
                Timer -= uiDiff;
        }
        return;
    }

    if (Timer < uiDiff)
    {
        std::list<Creature*> DragListe;
        float X = 0.0f;
        float Y = 0.0f;
        uint32 eventGardId = 6;
        switch (Tick)
        {
        case 0:
            m_uiDespawnTimer = 20 * MINUTE * IN_MILLISECONDS;
            DoScriptText(SAY_WINDSOR3, m_creature);
            Timer = 5000;
            break;
        case 1:
            m_creature->SetFacingTo(0.659f);
            DoScriptText(SAY_WINDSOR4, m_creature);
            Timer = 5000;
            break;
        case 2:
            for (int i = 0; i < 6; i++)
            {
                int Var = i + 1;
                Creature* pSummon = m_creature->SummonCreature(NPC_STORMWIND_CITY_GUARD,
                    WindsorEventMove[Var].x,
                    WindsorEventMove[Var].y,
                    WindsorEventMove[Var].z,
                    WindsorEventMove[Var].o, TEMPSUMMON_TIMED_DESPAWN, 240 * IN_MILLISECONDS);
                if (pSummon)
                {
                    GuardsGUIDs[i] = pSummon->GetGUID();
                    pSummon->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                }
            }
            if (Creature* Onyxia = m_creature->SummonCreature(NPC_KATRANA_PRESTOR, -9075.6f, 466.11f, 120.383f, 6.27f, TEMPSUMMON_TIMED_DESPAWN, 10 * IN_MILLISECONDS))
            {
                Onyxia->SetDisplayId(11686); // invisible
                Onyxia->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                DoScriptText(SAY_ONYXIA1, Onyxia);
            }
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                General->GetMotionMaster()->MovePoint(0, WindsorEventMove[0].x, WindsorEventMove[0].y, WindsorEventMove[0].z);
                General->Unmount();
            }
            m_creature->GetMotionMaster()->MovePoint(0, WindsorWaypoints[1].x, WindsorWaypoints[1].y, WindsorWaypoints[1].z);
            X = m_creature->GetPositionX() - WindsorWaypoints[1].x;
            Y = m_creature->GetPositionY() - WindsorWaypoints[1].y;
            Timer = 1000 + sqrt(X * X + Y * Y) / (m_creature->GetSpeed(MOVE_WALK) * 0.001f);
            break;
        case 3:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
                DoScriptText(SAY_MARCUS1, General);
            Timer = 5000;
            break;
        case 4:
            DoScriptText(SAY_WINDSOR5, m_creature);
            Timer = 5000;
            break;
        case 5:
            DoScriptText(SAY_WINDSOR6, m_creature);
            Timer = 5000;
            break;
        case 6:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
                DoScriptText(SAY_MARCUS2, General);
            Timer = 5000;
            break;
        case 7:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
                DoScriptText(SAY_MARCUS3, General);
            Timer = 5000;
            break;
        case 8:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
                DoScriptText(SAY_MARCUS4, General);
            Timer = 10000;
            break;
        case 9:
            DoScriptText(SAY_WINDSOR7, m_creature);
            Timer = 5000;
            break;
        case 10:
            DoScriptText(SAY_WINDSOR8, m_creature);
            Timer = 5000;
            break;
        case 11:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                if (Creature* pGuard = GetGuard(0))
                    General->SetFacingToObject(pGuard);
                DoScriptText(SAY_MARCUS5, General);
            }
            break;
        case 12:
            eventGardId = 0;
            break;
        case 13:
            eventGardId = 1;
            break;
        case 14:
            eventGardId = 2;
            Timer = 5000;
            break;
        case 15:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                if (Creature* pGuard = GetGuard(3))
                    General->SetFacingToObject(pGuard);
                DoScriptText(SAY_MARCUS6, General);
            }
            break;
        case 16:
            eventGardId = 3;
            break;
        case 17:
            eventGardId = 4;
            break;
        case 18:
            eventGardId = 5;
            Timer = 5000;
            break;
        case 19:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                General->SetFacingToObject(m_creature);
                DoScriptText(SAY_MARCUS7, General);
            }
            Timer = 5000;
            break;
        case 20:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
                General->HandleEmote(EMOTE_ONESHOT_SALUTE);
            Timer = 5000;
            break;
        case 21:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
                DoScriptText(SAY_MARCUS8, General);
            Timer = 5000;
            break;
        case 22:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                General->GetMotionMaster()->MovePoint(0, WindsorEventMove[13].x, WindsorEventMove[13].y, WindsorEventMove[13].z);
                X = General->GetPositionX() - WindsorEventMove[13].x;
                Y = General->GetPositionY() - WindsorEventMove[13].y;
                Timer = 1000 + sqrt(X * X + Y * Y) / (m_creature->GetSpeed(MOVE_WALK) * 0.001f);
            }
            else Timer = 1000;
            break;
        case 23:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                General->SetStandState(UNIT_STAND_STATE_KNEEL);
                General->SetFacingTo(WindsorEventMove[13].o);
                m_creature->SetFacingToObject(General);
                DoScriptText(SAY_WINDSOR9, m_creature);
            }
            Timer = 10000;
            break;
        case 24:
            if (Creature* pGuard = GetGuard(0))
                m_creature->SetFacingToObject(pGuard);
            DoScriptText(SAY_WINDSOR10, m_creature);
            Timer = 5000;
            break;
        case 28:
            NeedCheck = true;
            break;
        case 29:
            if (Creature* General = m_creature->FindNearestCreature(NPC_MARCUS_JONATHAN, 150.0f))
            {
                General->ForcedDespawn();
                General->Respawn();
            }
            break;
        case 43:
            m_uiDespawnTimer = 10 * MINUTE * IN_MILLISECONDS;
            BeginQuest = false;
            m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            DoScriptText(SAY_WINDSOR11, m_creature);
            break;
        case 50:
            DoScriptText(SAY_WINDSOR13, m_creature);
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                Bolvar->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
                Onyxia->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            Timer = 4000;
            break;
        case 51:
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                DoScriptText(SAY_BOLVAR1, Bolvar);
            break;
        case 52:
            if (Creature* Anduin = m_creature->FindNearestCreature(NPC_ANDUIN_WRYNN, 150.0f))
            {
                Anduin->SetWalk(false);
                Anduin->GetMotionMaster()->MovePoint(0, WindsorEventMove[14].x, WindsorEventMove[14].y,
                                                     WindsorEventMove[14].z);
            }
            Timer = 5000;
            break;
        case 53:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
            {
                m_creature->SetFacingToObject(Onyxia);
                DoScriptText(SAY_WINDSOR14, m_creature);
            }
            Timer = 5000;
            break;
        case 54:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
                DoScriptText(SAY_ONYXIA2, Onyxia);
            Timer = 4000;
            break;
        case 55:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
                DoScriptText(SAY_ONYXIA3, Onyxia);
            Timer = 10000;
            break;
        case 56:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
                DoScriptText(SAY_ONYXIA4, Onyxia);
            Timer = 5000;
            break;
        case 57:
            DoScriptText(SAY_WINDSOR15, m_creature);
            Timer = 5000;
            break;
        case 58:
            DoScriptText(SAY_WINDSOR16, m_creature, m_creature);
            Timer = 5000;
            break;
        case 59:
            DoScriptText(SAY_WINDSOR17, m_creature);
            Timer = 4000;
            break;
        case 60:
            DoScriptText(SAY_WINDSOR18, m_creature);
            Timer = 5000;
            break;
        case 61:
            DoScriptText(SAY_WINDSOR19, m_creature, m_creature);
            Timer = 2000;
            break;
        case 62:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
                m_creature->CastSpell(Onyxia, SPELL_WINSOR_READ_TABLETS, false);
            Timer = 10000;
            break;
        case 63:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_KATRANA_PRESTOR, 150.0f))
            {
                Onyxia->UpdateEntry(NPC_LADY_ONYXIA);
                Onyxia->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
            }
            Timer = 1000;
            break;
        case 64:
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                DoScriptText(SAY_BOLVAR2, Bolvar, Bolvar);
            Timer = 2000;
            break;
        case 65:
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
            {
                Bolvar->SetWalk(false);
                Bolvar->GetMotionMaster()->MovePoint(0, WindsorEventMove[15].x, WindsorEventMove[15].y, WindsorEventMove[15].z,
                        MOVE_NONE, 0, 5.740616f);
                X = Bolvar->GetPositionX() - WindsorEventMove[15].x;
                Y = Bolvar->GetPositionY() - WindsorEventMove[15].y;
                Timer = 1000 + sqrt((X * X) + (Y * Y)) / (m_creature->GetSpeed(MOVE_WALK) * 0.001f);
            }
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
                DoScriptText(SAY_ONYXIA5, Onyxia);
            else Timer = 4000;
            break;
        case 66:
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                DoScriptText(SAY_BOLVAR3, Bolvar);
            break;
        case 67:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
                DoScriptText(SAY_ONYXIA6, Onyxia);
            Timer = 2000;
            break;
        case 68:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
            {
                DoScriptText(SAY_ONYXIA7, Onyxia);
                int Var = 0;
                GetCreatureListWithEntryInGrid(DragListe, Onyxia, NPC_STORMWIND_ROYAL_GUARD, 25.0f);
                for (const auto& itr : DragListe)
                {
                    DragsGUIDs[Var] = itr->GetGUID();
                    itr->UpdateEntry(NPC_ONYXIA_ELITE_GUARD);
                    itr->AIM_Initialize();
                    itr->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (!urand(0, 2))
                        DoScriptText(SAY_HISS, itr);
                    Var++;
                }
            }
            Timer = 4000;
            break;
        case 69:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
                Onyxia->CastSpell(m_creature, SPELL_WINDSOR_DEATH, false);
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                Bolvar->HandleEmote(EMOTE_STATE_READYUNARMED);
            Timer = 1500;
            break;
        case 70:
            DoScriptText(SAY_WINDSOR20, m_creature);
            Timer = 1000;
            break;
        case 71:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
            {
                DoScriptText(SAY_ONYXIA8, Onyxia);
                if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                {
                    Bolvar->SetFactionTemporary(FACTION_BOLVAR_COMBAT, TEMPFACTION_RESTORE_COMBAT_STOP);
                    int Var = 0;
                    while (DragsGUIDs[Var] && Var < 9)
                    {
                        if (Creature* crea = me->GetMap()->GetCreature(DragsGUIDs[Var]))
                        {
                            crea->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            crea->GetThreatManager().addThreatDirectly(Bolvar, 5000.0f);
                            crea->SetTargetGuid(Bolvar->GetGUID());
                            Bolvar->AddThreat(crea);
                            Bolvar->SetInCombatWith(crea);
                            crea->SetInCombatWith(Bolvar);
                        }
                        Var++;
                    }
                }
            }
            Timer = 5000;
            break;
        case 72:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
            {
                DoScriptText(SAY_ONYXIA9, Onyxia);
                Onyxia->CastSpell(Onyxia, SPELL_PRESTOR_DESPAWNS, true);
            }
            Timer = 1000;
            break;
        case 73:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
            {
                Onyxia->ForcedDespawn();
                Onyxia->SetRespawnDelay(30 * MINUTE);
                Onyxia->SetRespawnTime(30 * MINUTE);
                Onyxia->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            }
            Timer = 15000;
            break;
        case 74:
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
                DoScriptText(SAY_BOVLAR4, Bolvar, Bolvar);
        case 75:
            if (Creature* Onyxia = m_creature->FindNearestCreature(NPC_LADY_ONYXIA, 150.0f))
            {
                Onyxia->ForcedDespawn();
                Onyxia->SetRespawnDelay(30 * MINUTE);
                Onyxia->SetRespawnTime(30 * MINUTE);
                Onyxia->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            }
            Tick = 100; // come back when combat is done
            PhaseFinale = true;
            break;
        case 76:
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
            {
                Bolvar->HandleEmote(EMOTE_STATE_STAND);

                DoScriptText(SAY_BOLVAR5, Bolvar);
                Bolvar->SetWalk(true);
                Bolvar->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                Bolvar->SetStandState(UNIT_STAND_STATE_KNEEL);
            }
            Timer = 1000;
            break;
        case 77:
            CompleteQuest();
            DoScriptText(SAY_WINDSOR21, m_creature);
            Timer = 8000;
            break;
        case 78:
            DoScriptText(SAY_WINDSOR22, m_creature);
            m_creature->CastSpell(m_creature, 5, true); // death
            EndScene();
            BeginQuest = false;
            break;
        }
        if (eventGardId < 6)
        {
            if (Creature* pGuard = GetGuard(eventGardId))
            {
                int Var = eventGardId + 7;
                pGuard->GetMotionMaster()->MovePoint(0, WindsorEventMove[Var].x, WindsorEventMove[Var].y, WindsorEventMove[Var].z);
                X = pGuard->GetPositionX() - WindsorEventMove[Var].x;
                Y = pGuard->GetPositionY() - WindsorEventMove[Var].y;
            }
            GuardTimer[eventGardId] = 1000 + sqrt(X * X + Y * Y) / (m_creature->GetSpeed(MOVE_WALK) * 0.001f);
            GuardNeed[eventGardId] = true;
            Timer = 1000;
        }
        if (Tick > 26 && Tick < 44)
        {
            int Var = Tick - 25;
            m_creature->GetMotionMaster()->MovePoint(0, WindsorWaypoints[Var].x, WindsorWaypoints[Var].y, WindsorWaypoints[Var].z,
                                                     MOVE_NONE, 0.0f, WindsorWaypoints[Var].o);
            X = m_creature->GetPositionX() - WindsorWaypoints[Var].x;
            Y = m_creature->GetPositionY() - WindsorWaypoints[Var].y;
            Timer = 1000 + sqrt(X * X + Y * Y) / (m_creature->GetSpeed(MOVE_WALK) * 0.001f);
        }
        else if (Tick > 44 && Tick < 50)
        {
            int Var = Tick - 26;
            m_creature->GetMotionMaster()->MovePoint(0, WindsorWaypoints[Var].x, WindsorWaypoints[Var].y, WindsorWaypoints[Var].z,
                                                     MOVE_NONE, 0.0f, WindsorWaypoints[Var].o);
            X = m_creature->GetPositionX() - WindsorWaypoints[Var].x;
            Y = m_creature->GetPositionY() - WindsorWaypoints[Var].y;
            Timer = 1000 + sqrt(X * X + Y * Y) / (m_creature->GetSpeed(MOVE_WALK) * 0.001f);
        }
        else if (PhaseFinale)
        {
            if (Creature* Bolvar = m_creature->FindNearestCreature(NPC_BOLVAR_FORDRAGON, 150.0f))
            {
                if (!Bolvar->IsInCombat())
                {
                    if (!CombatJustEnded)
                    {
                        Bolvar->SetWalk(true);
                        Bolvar->GetMotionMaster()->MovePoint(0, -8447.39f, 335.35f, 121.747f, 0, 0, 1.29f);
                        Bolvar->ClearTemporaryFaction();
                        CombatJustEnded = true;
                        Timer = 5000;
                        Tick = 76;
                        return;
                    }
                }
            }
        }
        Tick++;
    }
    else
        Timer -= uiDiff;
}

bool QuestAccept_npc_reginald_windsor(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_THE_GREAT_MASQUERADE)
    {
        if (auto pWindsorEventAI = dynamic_cast<npc_reginald_windsorAI*>(pCreature->AI()))
        {
            pWindsorEventAI->BeginQuest = true;
            pWindsorEventAI->QuestAccepted = true;
            pWindsorEventAI->GreetPlayer = false;
            pWindsorEventAI->playerGUID = pPlayer->GetGUID();
            pWindsorEventAI->m_uiDespawnTimer = 30 * MINUTE * IN_MILLISECONDS;
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }
    }
    return true;
}

bool GossipHello_npc_reginald_windsor(Player* pPlayer, Creature* pCreature)
{
    if (auto pWindsorEventAI = static_cast<npc_reginald_windsorAI*>(pCreature->AI()))
    {
        if (pPlayer == pWindsorEventAI->GetPlayer() && pWindsorEventAI->QuestAccepted)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, 8256, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        else if (pCreature->IsQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->SEND_GOSSIP_MENU(5633, pCreature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_reginald_windsor(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF:
        if (auto pWindsorEventAI = static_cast<npc_reginald_windsorAI*>(pCreature->AI()))
        {
            pWindsorEventAI->BeginQuest = true;
            DoScriptText(SAY_WINDSOR12, pCreature);
            pCreature->SetUInt32Value(UNIT_NPC_FLAGS, 0);
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        break;
    }
    return true;
}

CreatureAI* GetAI_npc_reginald_windsor(Creature* pCreature)
{
    return new npc_reginald_windsorAI(pCreature);
}

/*
* Squire Rowe
*/

npc_squire_roweAI::npc_squire_roweAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    npc_squire_roweAI::Reset();
    npc_squire_roweAI::ResetCreature();
}

void npc_squire_roweAI::ResetCreature()
{
    m_playerGuid.Clear();
    m_uiTimer = 2000;
    m_uiStep = 0;
    m_bEventProcessed = false;
    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    m_bWindsorUp = false;
}

void npc_squire_roweAI::MovementInform(uint32 uiType, uint32 uiPointId)
{
    if (!m_bEventProcessed || uiType != POINT_MOTION_TYPE)
        return;

    switch (uiPointId)
    {
    case 1:
        m_creature->GetMotionMaster()->MovePoint(2, RoweWaypoints[1].x, RoweWaypoints[1].y, RoweWaypoints[1].z);
        break;
    case 2:
        m_creature->HandleEmote(EMOTE_ONESHOT_KNEEL);
        m_uiTimer = 5000;
        ++m_uiStep;
        break;
    case 4:
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        DoScriptText(SAY_SIGNAL_SENT, m_creature);
        m_bEventProcessed = false;
        break;
    }
}

void npc_squire_roweAI::UpdateAI(uint32 const uiDiff)
{
    if (m_bEventProcessed)
    {
        if (m_uiTimer < uiDiff)
        {
            switch (m_uiStep)
            {
            case 0:
                m_creature->SetSpeedRate(MOVE_RUN, 1.1f);
                m_creature->GetMotionMaster()->MovePoint(1, RoweWaypoints[0].x, RoweWaypoints[0].y, RoweWaypoints[0].z);
                m_uiTimer = 1000;
                ++m_uiStep;
                break;
            case 2:
                m_creature->SummonGameObject(GO_FLARE_OF_JUSTICE, -9095.839844f, 411.178986f, 92.244499f, 2.303830f, 0.0f, 0.0f, 0.913545f, 0.406738f, 10 * IN_MILLISECONDS);
                m_creature->GetMotionMaster()->MovePoint(3, RoweWaypoints[0].x, RoweWaypoints[0].y, RoweWaypoints[0].z);
                m_uiTimer = 1500;
                ++m_uiStep;
                break;
            case 3:
                if (Creature* pWindsor = m_creature->SummonCreature(NPC_REGINALD_WINDSOR,
                    WindsorSummon.x,
                    WindsorSummon.y,
                    WindsorSummon.z,
                    WindsorSummon.o, TEMPSUMMON_MANUAL_DESPAWN, 1.5 * HOUR * IN_MILLISECONDS, true))
                {
                    auto pWindsorAI = static_cast<npc_reginald_windsorAI*>(pWindsor->AI());

                    if (pWindsorAI)
                    {
                        if (m_playerGuid)
                            pWindsorAI->playerGUID = m_playerGuid;

                        pWindsorAI->m_squireRoweGuid = m_creature->GetObjectGuid();
                    }

                    m_bWindsorUp = true;
                    pWindsor->Mount(MOUNT_WINDSOR);
                    pWindsor->SetWalk(false);
                    pWindsor->SetSpeedRate(MOVE_RUN, 1.0f);
                    pWindsor->GetMotionMaster()->MovePoint(0, WindsorWaypoints[0].x, WindsorWaypoints[0].y, WindsorWaypoints[0].z, MOVE_PATHFINDING);
                    pWindsor->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                }
                ++m_uiStep;
                break;
            case 4:
                float x, y, z, o;
                m_creature->GetRespawnCoord(x, y, z, &o);
                m_creature->GetMotionMaster()->MovePoint(4, x, y, z, MOVE_NONE, 0, o);
                ++m_uiStep;
                break;
            }
        }
        else
            m_uiTimer -= uiDiff;
    }
    else
        ScriptedAI::UpdateAI(uiDiff);
}

bool GossipHello_npc_squire_rowe(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_STORMWIND_RENDEZVOUS) == QUEST_STATUS_COMPLETE &&
        pPlayer->GetQuestStatus(QUEST_THE_GREAT_MASQUERADE) != QUEST_STATUS_COMPLETE)
    {
        auto pSquireRoweAI = static_cast<npc_squire_roweAI*>(pCreature->AI());

        if (!pSquireRoweAI)
            return true;

        if (!pSquireRoweAI->m_bWindsorUp)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Let Marshal Windsor know that I am ready.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_ROWE_READY, pCreature->GetGUID());
        }
        else
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_ROWE_BUSY, pCreature->GetGUID());
    }
    else if (pPlayer->GetQuestStatus(QUEST_THE_GREAT_MASQUERADE) == QUEST_STATUS_COMPLETE)
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_ROWE_COMPLETED, pCreature->GetGUID());
    else
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_ROWE_NOTHING, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_squire_rowe(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF:
        if (pPlayer->GetQuestStatus(QUEST_STORMWIND_RENDEZVOUS) == QUEST_STATUS_COMPLETE)
        {
            if (auto pSquireRoweAI = static_cast<npc_squire_roweAI*>(pCreature->AI()))
            {
                pSquireRoweAI->m_bEventProcessed = true;
                pSquireRoweAI->m_playerGuid = pPlayer->GetObjectGuid();
                pCreature->SetWalk(false);
                pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
        }

        pPlayer->CLOSE_GOSSIP_MENU();
        break;
    }

    return true;
}

CreatureAI* GetAI_npc_squire_rowe(Creature* pCreature)
{
    return new npc_squire_roweAI(pCreature);
}

static time_t globalWindsorLastSpawnTime = time_t(0);

bool AreaTrigger_at_stormwind_gates(Player* pPlayer, AreaTriggerEntry const* /*pAt*/)
{
    // Before patch 1.12, Windsor was spawned from the AreaTrigger at the Stormwind gates.
    // Squire Rowe was added in patch 1.12, confirmed by both Allakhazam and Thottbot comments.
    // His creature Id is also in the 1.12 range, and his display Id doesn't exist in prior clients.
    if (sWorld.GetWowPatch() >= WOW_PATCH_112 && sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVE_EVENTS))
        return false;

    // If player is dead, GM mode is ON, quest complete or no quest.
    if (!pPlayer || !pPlayer->IsAlive() || pPlayer->IsGameMaster() ||
        !(pPlayer->IsCurrentQuest(QUEST_STORMWIND_RENDEZVOUS) || (pPlayer->GetQuestRewardStatus(QUEST_STORMWIND_RENDEZVOUS) && !pPlayer->GetQuestRewardStatus(QUEST_THE_GREAT_MASQUERADE) && !pPlayer->IsCurrentQuest(QUEST_THE_GREAT_MASQUERADE))))
        return false;

    // Cooldown before Windsor can be spawned again.
    if (globalWindsorLastSpawnTime + 15 * MINUTE > sWorld.GetGameTime())
        return false;

    // Check if Windsor is already spawned.
    if (GetClosestCreatureWithEntry(pPlayer, NPC_REGINALD_WINDSOR, 200.0f))
        return false;

    if (Creature* pWindsor = pPlayer->SummonCreature(NPC_REGINALD_WINDSOR,
        WindsorSummon.x,
        WindsorSummon.y,
        WindsorSummon.z,
        WindsorSummon.o, TEMPSUMMON_MANUAL_DESPAWN, 1.5 * HOUR * IN_MILLISECONDS, true))
    {
        auto pWindsorAI = static_cast<npc_reginald_windsorAI*>(pWindsor->AI());

        if (pWindsorAI)
        {
            pWindsorAI->playerGUID = pPlayer->GetGUID();
            pWindsorAI->m_squireRoweGuid = ObjectGuid();
        }

        pWindsor->Mount(MOUNT_WINDSOR);
        pWindsor->SetWalk(false);
        pWindsor->SetSpeedRate(MOVE_RUN, 1.0f);
        pWindsor->GetMotionMaster()->MovePoint(0, WindsorWaypoints[0].x, WindsorWaypoints[0].y, WindsorWaypoints[0].z, MOVE_PATHFINDING);
        pWindsor->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

        globalWindsorLastSpawnTime = sWorld.GetGameTime();

        return true;
    }

    return false;
}

void AddSC_quest_stormwind_rendezvous()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_squire_rowe";
    pNewScript->GetAI = &GetAI_npc_squire_rowe;
    pNewScript->pGossipHello = &GossipHello_npc_squire_rowe;
    pNewScript->pGossipSelect = &GossipSelect_npc_squire_rowe;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_reginald_windsor";
    pNewScript->GetAI = &GetAI_npc_reginald_windsor;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_reginald_windsor;
    pNewScript->pGossipHello = &GossipHello_npc_reginald_windsor;
    pNewScript->pGossipSelect = &GossipSelect_npc_reginald_windsor;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_stormwind_gates";
    pNewScript->pAreaTrigger = &AreaTrigger_at_stormwind_gates;
    pNewScript->RegisterSelf();
}
