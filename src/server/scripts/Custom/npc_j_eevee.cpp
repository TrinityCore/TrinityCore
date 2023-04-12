//#include "scriptPCH.h"
//#include "npc_j_eevee.h"
//
//struct EventLocations
//{
//    float m_fX, m_fY, m_fZ, m_fO;
//    int m_wait;
//};
//
//static EventLocations aJeeveeDreadsteedLocations[] =
//{
//    { -38.939999f, 812.849976f, -29.530002f, 4.890318f, 3500 }, //Jeevee spawn
//    { -27.768442f, 812.457703f, -29.535814f, 6.258483f, 4000 }, //Jeevee first point
//    { -45.293509f, 822.046747f, -29.535671f, 2.211563f, 3000 }, //Jeevee second point
//    { -44.074763f, 802.921135f, -29.535734f, 4.357706f, 3000 }, //Jeevee third point
//    { -38.939999f, 812.849976f, -29.530002f, 4.890318f, 4000 } //Jeevee last point
//};
//enum
//{
//    SPELL_J_EEVEE_SUMMONS_OBJECT = 23140,
//    SPELL_J_EEVEE_TELEPORT = 7791,
//
//    SHOUT_J_EEVEE_FREEDOM = -1780196,
//    SAY_J_EEVEE_DREADSTEED_1 = -1780197,
//    SAY_J_EEVEE_DREADSTEED_2 = -1780198,
//    SAY_J_EEVEE_DREADSTEED_3 = -1780199,
//    SAY_J_EEVEE_DREADSTEED_4 = -1780200,
//
//    SAY_J_EEVEE_SCHOLOMANCE_1 = -1900048,
//    SAY_J_EEVEE_SCHOLOMANCE_2 = -1900049,
//    SAY_J_EEVEE_SCHOLOMANCE_3 = -1900050,
//    SAY_J_EEVEE_SCHOLOMANCE_4 = -1900051,
//
//    QUEST_IMP_DELIVERY = 7629
//};
//
//
//npc_j_eevee_dreadsteedAI::npc_j_eevee_dreadsteedAI(Creature* pCreature) : ScriptedAI(pCreature)
//{
//    m_creature->SetWalk(true);
//    Reset();
//}
//
//void npc_j_eevee_dreadsteedAI::Reset()
//{
//    waitTimer = 3500;
//    currentPoint = 0;
//    waypointReached = true;
//}
//
//void npc_j_eevee_dreadsteedAI::MovementInform(uint32 uiType, uint32 uiPointId)
//{
//    if (uiType != POINT_MOTION_TYPE)
//        return;
//    switch (uiPointId)
//    {
//    case 1:
//    case 2:
//    case 3:
//        m_creature->SetFacingTo(aJeeveeDreadsteedLocations[currentPoint].m_fO);
//        waypointReached = true;
//        m_creature->CastSpell(m_creature, SPELL_J_EEVEE_SUMMONS_OBJECT, false);
//        break;
//    case 4:
//        m_creature->SetFacingTo(aJeeveeDreadsteedLocations[currentPoint].m_fO);
//        waypointReached = true;
//        if (Player* player = m_creature->GetMap()->GetPlayer(guidPlayer))
//            DoScriptText(SAY_J_EEVEE_DREADSTEED_4, m_creature, player);
//
//        DoCastSpellIfCan(m_creature, SPELL_J_EEVEE_TELEPORT, CF_TRIGGERED);
//        break;
//    }
//}
//void npc_j_eevee_dreadsteedAI::UpdateAI(uint32 const uiDiff)
//{
//    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
//    {
//        if (waypointReached)
//        {
//            if (waitTimer < uiDiff)
//            {
//                if (currentPoint < 4)
//                {
//                    switch (currentPoint)
//                    {
//                    case 0:
//                        DoScriptText(SAY_J_EEVEE_DREADSTEED_1, m_creature);
//                        break;
//                    case 1:
//                        DoScriptText(SAY_J_EEVEE_DREADSTEED_2, m_creature);
//                        break;
//                    case 2:
//                        DoScriptText(SAY_J_EEVEE_DREADSTEED_3, m_creature);
//                        break;
//                    }
//                    currentPoint++;
//                    m_creature->GetMotionMaster()->MovePoint(currentPoint, aJeeveeDreadsteedLocations[currentPoint].m_fX, aJeeveeDreadsteedLocations[currentPoint].m_fY, aJeeveeDreadsteedLocations[currentPoint].m_fZ, true);
//                    waitTimer = aJeeveeDreadsteedLocations[currentPoint].m_wait;
//                }
//                else
//                    m_creature->DisappearAndDie();
//                waypointReached = false;
//            }
//            else
//                waitTimer -= uiDiff;
//        }
//        return;
//    }
//    DoMeleeAttackIfReady();
//}
//void npc_j_eevee_dreadsteedAI::SetPlayerGuid(uint64 playerGuid)
//{
//    guidPlayer = playerGuid;
//}
//void npc_j_eevee_dreadsteedAI::ShoutFreedom()
//{
//    DoScriptText(SHOUT_J_EEVEE_FREEDOM, m_creature);
//}
//
//static EventLocations aJeeveeScholomanceLocations[] =
//{
//    { 38.706051f, 156.989319f, 83.545631f, 1.585528f, 2000 },       // 1. spawn, Text 1
//    { 38.123325f, 159.745956f, 83.545631f, 1.587492f, 300 },        // 2. Move
//    { 36.478260f, 160.530975f, 83.545631f, 3.179874f, 4000 },       // 3. Move, EMOTE_ONESHOT_ATTACK once point reached
//    { 38.123325f, 159.745956f, 83.545631f, 5.250862f, 100 },        // 4. Move, text 2 at start of movement
//    { 41.213757f, 155.202774f, 83.545631f, 0.098650f, 50 },         // 5. Move
//    { 45.890804f, 155.115601f, 83.545631f, 0.018146f, 50 },         // 6. Move
//    { 46.639896f, 160.362015f, 83.545631f, 2.549089f, 50 },         // 7. Move
//    { 44.227440f, 160.631088f, 83.545631f, 2.549089f, 4000 },       // 8. Move, EMOTE_ONESHOT_ATTACK once point reached (attack twice?)
//    { 46.639896f, 160.362015f, 83.545631f, 5.250862f, 300 },        // 9. Move, run. text 3 at start of movement
//    { 46.425823f, 154.547577f, 83.645631f, 3.108989f, 50 },         // 10. Move
//    { 34.415833f, 154.561859f, 83.645631f, 3.140403f, 50 },         // 11. Move, run
//    { 28.838001f, 160.411469f, 83.645631f, 2.378568f, 100 },        // 12. Move, run
//    { 33.201927f, 160.234833f, 83.645624f, 6.242730f, 4000 },       // 13. Move WALK again, emote attack
//    { 33.201927f, 160.234833f, 83.645624f, 6.242730f, 2000 },       // 14. Finished, speak Text 4
//};
//
//npc_j_eevee_scholomanceAI::npc_j_eevee_scholomanceAI(Creature* pCreature) : ScriptedAI(pCreature)
//{
//    m_creature->SetWalk(true);
//
//    if (m_creature->IsTemporarySummon())
//    {
//        guidPlayer = ((TemporarySummon*)m_creature)->GetSummonerGuid();
//
//        if (Player* player = m_creature->GetMap()->GetPlayer(guidPlayer))
//            player->HandleEmote(EMOTE_ONESHOT_KNEEL);
//    }
//
//    waitTimer = 4000;
//    // Repeat attack emotes at some positions
//    attackRepeatTimer = 1000;
//    currentPoint = 0;
//    waypointReached = true;
//    finished = false;
//
//    Reset();
//}
//
//void npc_j_eevee_scholomanceAI::Reset()
//{
//    // do nothing, continue from where we left off
//}
//
//void npc_j_eevee_scholomanceAI::MovementInform(uint32 uiType, uint32 uiPointId)
//{
//    if (uiType != POINT_MOTION_TYPE)
//        return;
//
//    m_creature->SetFacingTo(aJeeveeScholomanceLocations[currentPoint].m_fO);
//    waypointReached = true;
//    switch (uiPointId)
//    {
//    case 2:
//        m_creature->HandleEmote(EMOTE_ONESHOT_ATTACKUNARMED);
//        attackRepeatTimer = 1000;
//        break;
//    case 7:
//        m_creature->HandleEmote(EMOTE_ONESHOT_ATTACKUNARMED);
//        attackRepeatTimer = 1000;
//        break;
//    case 12:
//        m_creature->HandleEmote(EMOTE_ONESHOT_ATTACKUNARMED);
//        attackRepeatTimer = 1000;
//        break;
//    case 13:
//        DoCastSpellIfCan(m_creature, SPELL_J_EEVEE_TELEPORT, CF_TRIGGERED);
//        finished = true;
//        break;
//    }
//}
//
//void npc_j_eevee_scholomanceAI::UpdateAI(uint32 const uiDiff)
//{
//    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
//    {
//        if (waypointReached || finished)
//        {
//            if (waitTimer < uiDiff)
//            {
//                if (currentPoint < 13)
//                {
//                    switch (currentPoint)
//                    {
//                    case 0:
//                        DoScriptText(SAY_J_EEVEE_SCHOLOMANCE_1, m_creature);
//                        break;
//                    case 3:
//                        DoScriptText(SAY_J_EEVEE_SCHOLOMANCE_2, m_creature);
//                        break;
//                    case 8:
//                        DoScriptText(SAY_J_EEVEE_SCHOLOMANCE_3, m_creature);
//                        m_creature->SetWalk(false);
//                        break;
//                    case 11:
//                        m_creature->SetWalk(true);
//                        break;
//                    case 12:
//                        // final script text
//                        DoScriptText(SAY_J_EEVEE_SCHOLOMANCE_4, m_creature);
//
//                        if (Player* player = m_creature->GetMap()->GetPlayer(guidPlayer))
//                            player->KilledMonsterCredit(14500, m_creature->GetObjectGuid());
//
//                        break;
//                    }
//
//                    currentPoint++;
//                    m_creature->GetMotionMaster()->MovePoint(currentPoint, aJeeveeScholomanceLocations[currentPoint].m_fX, aJeeveeScholomanceLocations[currentPoint].m_fY, aJeeveeScholomanceLocations[currentPoint].m_fZ, true);
//                    waitTimer = aJeeveeScholomanceLocations[currentPoint].m_wait;
//                }
//                else
//                {
//                    m_creature->DisappearAndDie();
//                }
//
//                waypointReached = false;
//            }
//            else
//            {
//                waitTimer -= uiDiff;
//
//                if (currentPoint == 2 || currentPoint == 7 || currentPoint == 12)
//                {
//                    if (attackRepeatTimer < uiDiff)
//                    {
//                        m_creature->HandleEmote(EMOTE_ONESHOT_ATTACKUNARMED);
//
//                        attackRepeatTimer = 1000;
//                    }
//                    else
//                        attackRepeatTimer -= uiDiff;
//                }
//            }
//        }
//        return;
//    }
//    DoMeleeAttackIfReady();
//}
//
//CreatureAI* GetAI_npc_j_eevee(Creature* pCreature)
//{
//    if (pCreature->GetMapId() == 429) //Map 429 Zone 2557. Dire Maul.
//        return new npc_j_eevee_dreadsteedAI(pCreature);
//    else if (pCreature->GetMapId() == 289) // Map 289, Zone 2057. Scholomance
//        return new npc_j_eevee_scholomanceAI(pCreature);
//
//    return nullptr;
//}
//
//void AddSC_npc_j_eevee()
//{
//    Script* newscript;
//
//    newscript = new Script;
//    newscript->Name = "npc_j_eevee";
//    newscript->GetAI = &GetAI_npc_j_eevee;
//    newscript->RegisterSelf();
//}
