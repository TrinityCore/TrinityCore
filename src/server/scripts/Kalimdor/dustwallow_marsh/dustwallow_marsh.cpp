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
SDName: Dustwallow_Marsh
SD%Complete: 95
SDComment: Quest support: 558, 1324. Vendor Nat Pagle
SDCategory: Dustwallow Marsh
EndScriptData */

/* ContentData
npc_lady_jaina_proudmoore
npc_private_hendel
npc_cassa_crimsonwing
EndContentData */

#include "scriptPCH.h"

/*######
## npc_private_hendel
######*/
//-----------------------------------------------------------------------------
// Full quest event implementation (Missing Diplomat part 16 id:1324).
// Author: Kampeador
//-----------------------------------------------------------------------------

// On elysium core, JustRespawned() isn't called on spawn. Only on respawn.
#define ELYSIUM_CORE_JUST_RESPAWNED

enum
{
    // ids from "script_texts" table
    SAY_PROGRESS_1_TER = -1000411, // Why don't we deal with you now, Hendel? Lady Proudmoore will speak to you back in the tower.
    SAY_PROGRESS_2_HEN = -1000412, // Please... please... Miss Proudmore. I didn't mean to...
    SAY_PROGRESS_3_TER = -1000413, // I apologize for taking so long to get here. I wanted Lady Proudmoore to be present also.
    SAY_PROGRESS_4_TER = -1000414, // We can only stay a few moments before returning to the tower. If you wish to speak to us more you may find us there.
    SAY_FAREWELL_TER = -1999901, // Farewell. We shall speak again. I'm sure.
    SAY_PROGRESS_5_SEN = -1999911, // It's Proudmoore! Get out of here!
    SAY_PROGRESS_6_SEN = -1999912, // Run!
    SAY_PROGRESS_7_SEN = -1999913, // She'll have our heads if we're caught!
    EMOTE_SURRENDER = -1000415, // private hendel, too injured, gives up the chase.
    // quest id
    QUEST_MISSING_DIPLO_PT16 = 1324, // quest id, which will be completed during this event.
    // factions
    FACTION_HOSTILE = 72,    // agressive creatures and allied theramore sentries can help
    FACTION_THERAMORE = 150, // taken from db, same as other sentries
    // guards that help Hendel
    NPC_SENTRY = 5184,
    // allies
    NPC_JAINA = 4968,
    NPC_TERVOSH = 4967,
    NPC_PAINED = 4965,
    // trigger, used to disable original NPCs (Archmage Tervosh, Jaina, Pained) during event
    NPC_CELL_TRIGGER = 25000,
    // spells used using event
    TELEPORT_VISUAL = 12980,     // used when allies are summoned
    SPELL_ENCAGE = 7081,         // cage effect on Hendel
    SPELL_TELEPORT = 7077,       // Tervosh uses this to "teleport Hendel to prison"
    SPELL_TELEPORT_GROUP = 7078, // Jaina uses this spell in the end of the event.
    // timers
    TELEPORT_BACK_DELAY = 90000, // 90 sec is a blizzlike value, can be tweaked depending on server population
    // quest phases
    MDQP_NONE = 0, // Event isn't started.
    MDQP_FIGHT = 1, // Hendel fighting with player.
    MDQP_MOVE_HOME = 2, // Hendel returns to his respawn point, used to detect if player has lost the fight.
    MDQP_ALLIES_ARRIVE = 3, // Archmage Tervosh, Jaina and Pained are arriving.
    MDQP_SPEECH = 4, // Dialog.
    MDQP_COMPLETE = 5  // The End.
};

// sentry guards spawn
struct point3o { float x, y, z, o; };
// sentry guards spawn points(taken from DB)
static const point3o guardsSpawn[] =
{
    { -2890.5f, -3344.49f, 32.3878f, 2.15425f },
    { -2889.18f, -3337.46f, 32.5128f, 3.67612f }
};

// ally spawn struct
struct mdSpawn
{
    float x, y, z;
    float dest_x, dest_y, dest_z;
    uint32 entry;
};
// ally spawn points
static const mdSpawn spawns[] =
{
    {
        -2859.716309f, -3354.161865f, 35.053226f, // spawn(x,y,z)
        -2882.960449f, -3347.482422f, 33.635021f, // destination(x,y,z)
        NPC_TERVOSH
    },
    {
        -2860.181641f, -3357.418457f, 36.818161f, // spawn(x,y,z)
        -2882.026855f, -3349.002197f, 33.953999f, // destination(x,y,z)
        NPC_JAINA
    },
    {
        -2859.032715f, -3351.402588f, 33.940628f, // spawn(x,y,z)
        -2882.014404f, -3345.890137f, 33.980751f, // destination(x,y,z)
        NPC_PAINED
    }
};

struct npc_private_hendelAI : public ScriptedAI
{
    // guards
    Creature* m_guards[2];
    // allies (Archmage Tervosh, Jaina, Pained)
    Creature* m_allies[3];
    // original allies (the ones that are in Theramore), should be not avaliable during event
    Creature* m_alliesOriginal[3];
    // trigger used to invoke cell in Theramore tower to disable original NPCs during event
    Creature* m_cellTrigger;
    // missing diplomat quest event phase index
    uint32 m_mdQuestPhase;
    // event timmers
    uint32 m_nextPhaseDelayTimer;
    // index to used to switch local phases inside quest phases
    uint32 m_localPhase;
    // player guid
    ObjectGuid m_playerGuid;

#ifdef ELYSIUM_CORE_JUST_RESPAWNED  
    bool m_justCreated;
#endif

    npc_private_hendelAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        // zero init required to prevent crash
        for (auto& guard : m_guards)
            guard = nullptr;
        for (ptrdiff_t i = 0; i < 3; ++i)
        {
            m_allies[i] = nullptr;
            m_alliesOriginal[i] = nullptr;
        }
        m_cellTrigger = nullptr;
        //set event phase to none
        m_mdQuestPhase = MDQP_NONE;

#ifdef ELYSIUM_CORE_JUST_RESPAWNED
        m_justCreated = true;
#endif

        Reset();
    }

    void Reset() override
    {
        // if Hendel returns spawn point in MDQP_FIGHT phase, players have failed a quest.
        if (m_mdQuestPhase == MDQP_FIGHT)
        {
            // Set quest failed
            Player* player = m_creature->GetMap()->GetPlayer(m_playerGuid);
            if (player)
                player->GroupEventFailHappens(QUEST_MISSING_DIPLO_PT16);
        }

        // reset player guid
        m_playerGuid.Clear();
        // reset private hendel's faction
        m_creature->SetFactionTemplateId(FACTION_THERAMORE); // theramore faction
        // reset his guards faction
        for (const auto& guard : m_guards)
        {
            if (guard && guard->IsAlive())
            {
                guard->SetFactionTemplateId(FACTION_THERAMORE); // theramore faction
            }
        }
        // reset phase flags
        m_mdQuestPhase = MDQP_NONE;
        m_nextPhaseDelayTimer = 4000; // 4 sec takes ally to reach destination point
        m_localPhase = 0;
        m_creature->SetVisibility(VISIBILITY_ON);
        // Change emote to default
        m_creature->HandleEmote(EMOTE_STATE_STAND);
        // case: When NPC respawns after previous event and looses quest giver flag for some players, so they need to relog to talk to him again.
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        // reset unattackable flag from previous event
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void AttackedBy(Unit* pAttacker) override
    {
        if (m_creature->GetVictim())
            return;

        if (m_creature->IsFriendlyTo(pAttacker))
            return;

        AttackStart(pAttacker);
    }

    // NPC has reached his spawn point
    void JustReachedHome() override
    {
        if (m_mdQuestPhase == MDQP_MOVE_HOME)
        {
            // spawn trigger to make original NPCs unavaliable during event
            m_cellTrigger = m_creature->SummonCreature(NPC_CELL_TRIGGER, -3753.458008f, -4455.059570f, 64.975151f, 0.0f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);

            // disable original NPCs
            // find original allies if they are alive
            if (m_cellTrigger)
            {
                for (ptrdiff_t i = 0; i < 3; ++i)
                {
                    m_alliesOriginal[i] = GetClosestCreatureWithEntry(m_cellTrigger, spawns[i].entry, 30.0f);
                    if (m_alliesOriginal[i])
                    {
                        // stop combat if they are in combat, and reset some flags
                        m_alliesOriginal[i]->RemoveAllAuras();
                        m_creature->DeleteThreatList();
                        m_alliesOriginal[i]->CombatStop();
                        // NPC runs to spawn point
                        MotionMaster* motionMaster = m_alliesOriginal[i]->GetMotionMaster();
                        if (motionMaster)
                            motionMaster->MoveTargetedHome();
                        // Make them temporary invisible
                        m_alliesOriginal[i]->SetVisibility(VISIBILITY_OFF);
                    }
                }
            }

            // summon allies
            for (ptrdiff_t i = 0; i < 3; ++i)
            {
                // hardcoded orientation 3.0f. Prevent pausing event, if player has left a map cell(summon with ActiveObject=true)
                m_allies[i] = m_creature->SummonCreature(spawns[i].entry, spawns[i].x, spawns[i].y, spawns[i].z, 3.0f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);

                // summon allies
                if (m_allies[i])
                {
                    // disable gossip and quest giver flags during at the beginning of the event for Tervosh
                    if (m_allies[i]->GetEntry() == NPC_TERVOSH)
                        m_allies[i]->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
                    else if (m_allies[i]->GetEntry() == NPC_JAINA) // Jaina shouldn't have gossip flag during event
                        m_allies[i]->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                    // rare case: horde players attack NPC during event so make them unattackable for them
                    m_allies[i]->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_NPC);
                    // visual teleport spell
                    m_allies[i]->CastSpell(m_allies[i], TELEPORT_VISUAL, false);
                    // move allies to the destination points
                    m_allies[i]->GetMotionMaster()->MovePoint(0, spawns[i].dest_x, spawns[i].dest_y, spawns[i].dest_z, MOVE_PATHFINDING | MOVE_RUN_MODE);
                }
            }

            // Tervosh is index 0
            Creature* tervosh = m_allies[0];
            if (!tervosh)
                return;

            // Fleeing guards
            // 1 guard always says: It's Proudmoore! Get out of here!
            // 2 guard has a random text
            int const guardTexts[3] = { SAY_PROGRESS_5_SEN, SAY_PROGRESS_6_SEN, SAY_PROGRESS_7_SEN };

            // check if there one of the guards is available
            bool first = true;
            for (const auto guard : m_guards)
            {
                // if guard is valid
                if (guard && guard->IsAlive())
                {
                    if (first)
                        DoScriptText(guardTexts[0], guard);
                    else
                        DoScriptText(guardTexts[urand(1, 2)], guard);

                    guard->RemoveAllAuras();
                    guard->CombatStop();
                    guard->GetMotionMaster()->MoveFleeing(tervosh, 0);

                    first = false;
                }
            }

            // switch phase to
            m_mdQuestPhase = MDQP_ALLIES_ARRIVE;
        }
    }

    void JustDied(Unit* pUnit) override
    {
        // case: something weird happened
        if (m_mdQuestPhase != MDQP_NONE)
        {
            // remove allies
            for (ptrdiff_t i = 0; i < 3; ++i)
            {
                // if ally is valid
                if (m_allies[i])
                {
                    static_cast<TemporarySummon*>(m_allies[i])->UnSummon();
                    m_allies[i] = nullptr;
                }
                else
                {
                    // restore original allies in Theramore if they were removed
                    if (m_alliesOriginal[i])
                        m_alliesOriginal[i]->SetVisibility(VISIBILITY_ON);
                }
            }

            // remove guards
            for (auto& guard : m_guards)
            {
                // if guard is valid
                if (guard)
                {
                    static_cast<TemporarySummon*>(guard)->UnSummon();
                    guard = nullptr;
                }
            }

            // despawn trigger
            if (m_cellTrigger)
            {
                static_cast<TemporarySummon*>(m_cellTrigger)->UnSummon();
                m_cellTrigger = nullptr;
            }
        }
    }

    void JustRespawned() override
    {
        ScriptedAI::JustRespawned(); // calls Reset()

        // private hendel spawns/respawns with two guards nearby
        // remove previous guards if they were not alive
        for (ptrdiff_t i = 0; i < 2; ++i)
        {
            if (m_guards[i])
            {
                if (m_guards[i]->IsAlive())
                    continue;
                else
                    static_cast<TemporarySummon*>(m_guards[i])->UnSummon();
            }

            m_guards[i] = m_creature->SummonCreature(NPC_SENTRY, guardsSpawn[i].x, guardsSpawn[i].y, guardsSpawn[i].z, guardsSpawn[i].o, TEMPSUMMON_MANUAL_DESPAWN, 0);
            if (m_guards[i])
                m_guards[i]->SetRespawnDelay(360);
        }
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        // This is required to handle other fight cases For example if NPC is getting attacked by opposite faction, hostile creatures, etc.
        if (m_mdQuestPhase == MDQP_NONE)
            return;

        // if player/group won a fight
        if (uiDamage > m_creature->GetHealth() || m_creature->GetHealthPercent() < 20.0f)
        {
            uiDamage = 0;

            // private hendel, too injured, gives up the chase.
            DoScriptText(EMOTE_SURRENDER, m_creature);

            m_creature->RemoveAllAuras();
            m_creature->SetFactionTemplateId(35);
            m_creature->DeleteThreatList();
            m_creature->CombatStop();

            // NPC runs to spawn point
            MotionMaster* pMotionMaster = m_creature->GetMotionMaster();
            if (pMotionMaster)
                pMotionMaster->MoveTargetedHome();

            // switch phase
            m_mdQuestPhase = MDQP_MOVE_HOME;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
#ifdef ELYSIUM_CORE_JUST_RESPAWNED
        if (m_justCreated)
        {
            m_justCreated = false;
            JustRespawned();
        }
#endif

        switch (m_mdQuestPhase)
        {
        default: // MDQP_NONE, MDQP_FIGHT, MDQP_MOVE_HOME
            ScriptedAI::UpdateAI(uiDiff);
            break;
        case MDQP_ALLIES_ARRIVE:
        {
            // check if allies are arrived
            if (m_nextPhaseDelayTimer < uiDiff)
            {
                // make allies face private hendel
                for (const auto& ally : m_allies)
                    ally->SetFacingToObject(m_creature);

                // Tervosh is index 0
                Creature* tervosh = m_allies[0];
                // make private hendel facing Tervosh with stun emote
                m_creature->SetFacingToObject(tervosh);
                m_creature->HandleEmote(EMOTE_STATE_STUN);

                tervosh->CastSpell(m_creature, SPELL_ENCAGE, false);
                // switch to speech phase
                m_mdQuestPhase = MDQP_SPEECH;

                m_nextPhaseDelayTimer = 2000; // next quest phase in 2 secs
            }
            else
                m_nextPhaseDelayTimer -= uiDiff;
        }break;
        case MDQP_SPEECH:
        {
            if (m_nextPhaseDelayTimer < uiDiff)
            {
                switch (m_localPhase)
                {
                case 0: // remove guards, say0
                {
                    // remove guards
                    for (auto& guard : m_guards)
                    {
                        // if guard is valid
                        if (guard)
                        {
                            static_cast<TemporarySummon*>(guard)->UnSummon();
                            guard = nullptr;
                        }
                    }

                    // Tervosh is index 0
                    Creature* tervosh = m_allies[0];
                    DoScriptText(SAY_PROGRESS_1_TER, tervosh);
                    m_nextPhaseDelayTimer = 6000; // next phase in 6 seconds
                } break;
                case 1: // say1
                {
                    DoScriptText(SAY_PROGRESS_2_HEN, m_creature);
                    m_nextPhaseDelayTimer = 1000; // next phase in 1 second
                }break;
                case 2: // cast teleport
                {
                    // Tervosh is index 0
                    Creature* tervosh = m_allies[0];
                    tervosh->CastSpell(m_creature, SPELL_TELEPORT, false);
                    m_nextPhaseDelayTimer = 1500; // next phase in 1.5 seconds
                } break;
                case 3:
                {
                    // Using invisibility trick here, because direct forceDespawn will stop UpdateAI() function.
                    m_creature->SetVisibility(VISIBILITY_OFF);

                    // Tervosh is index 0
                    Creature* tervosh = m_allies[0];
                    // Its now possible to turn quest in.
                    tervosh->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
                    // Set quest completed
                    Player* player = m_creature->GetMap()->GetPlayer(m_playerGuid);
                    if (player)
                        player->GroupEventHappens(QUEST_MISSING_DIPLO_PT16, m_creature);

                    m_nextPhaseDelayTimer = 4000; // next phase in 4 seconds
                } break;
                case 4: // say2
                {
                    // Tervosh is index 0
                    Creature* tervosh = m_allies[0];
                    DoScriptText(SAY_PROGRESS_3_TER, tervosh);
                    // speech delay for the say dialog index 3
                    m_nextPhaseDelayTimer = 8000; // next phase in 8 seconds
                } break;
                case 5: // say3
                {
                    // Tervosh is index 0
                    Creature* tervosh = m_allies[0];
                    DoScriptText(SAY_PROGRESS_4_TER, tervosh);

                    // switch phase to complete
                    m_mdQuestPhase = MDQP_COMPLETE;
                    // reset local phase for later reuse in MDQP_COMPLETE phase
                    m_localPhase = 0;
                    m_nextPhaseDelayTimer = TELEPORT_BACK_DELAY; // next phase in 90 seconds(blizzlike)
                } return;
                }

                // switch dialog phase
                ++m_localPhase;
            }
            else
                m_nextPhaseDelayTimer -= uiDiff;
        }break;
        case MDQP_COMPLETE:
        {
            if (m_nextPhaseDelayTimer < uiDiff)
            {
                switch (m_localPhase)
                {
                case 0: // Tervosh bows + say4
                {
                    // Tervosh is index 0
                    Creature* tervosh = m_allies[0];
                    tervosh->HandleEmote(EMOTE_ONESHOT_BOW);
                    DoScriptText(SAY_FAREWELL_TER, tervosh);
                    m_nextPhaseDelayTimer = 6000; // next phase in 6 seconds
                }break;
                case 1: // Jaina waves
                {
                    // Jaina is index 1
                    Creature* jaina = m_allies[1];
                    jaina->HandleEmote(EMOTE_ONESHOT_WAVE);
                    m_nextPhaseDelayTimer = 4000; // next phase in 4 seconds
                } break;
                case 2: // Jaina casts teleport spell
                {
                    // Jaina is index 1
                    Creature* jaina = m_allies[1];
                    jaina->CastSpell(jaina, SPELL_TELEPORT_GROUP, false);
                    m_nextPhaseDelayTimer = 4000; // next phase in 4 seconds
                } break;
                case 3: // Final, despawn
                {
                    // remove allies
                    for (auto& ally : m_allies)
                    {
                        // if ally is valid
                        if (ally)
                        {
                            static_cast<TemporarySummon*>(ally)->UnSummon();
                            ally = nullptr;
                        }
                    }

                    // restore original allies in Theramore
                    for (const auto& i : m_alliesOriginal)
                    {
                        if (i)
                        {
                            // Make them temporary invisible
                            i->SetVisibility(VISIBILITY_ON);
                            // teleport effect
                            i->CastSpell(i, TELEPORT_VISUAL, false);
                        }
                    }

                    // despawn trigger
                    if (m_cellTrigger)
                    {
                        static_cast<TemporarySummon*>(m_cellTrigger)->UnSummon();
                        m_cellTrigger = nullptr;
                    }

                    // reset event phase
                    m_mdQuestPhase = MDQP_NONE;
                    // despawn
                    m_creature->ForcedDespawn();
                } return;
                }

                // switch dialog phase
                ++m_localPhase;
            }
            else
                m_nextPhaseDelayTimer -= uiDiff;
        }break;
        }
    }

    void SummonedCreatureDespawn(Creature* creature) override 
    {
        // No dangling pointers
        for (auto& ally : m_allies)
        {
            if (ally == creature)
                ally = 0;
        }

        for (auto& guard : m_guards)
        {
            if (guard == creature)
                guard = 0;
        }
    }
};

bool QuestAccept_npc_private_hendel(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (!pPlayer || !pCreature || !pQuest)
        return false;

    // if player accepts a quest id Missing Diplomat(1324)
    if (pQuest->GetQuestId() == QUEST_MISSING_DIPLO_PT16)
    {
        npc_private_hendelAI* privateHendelAI = dynamic_cast<npc_private_hendelAI*>(pCreature->AI());
        if (privateHendelAI)
        {
            // set npc_private_hendel's faction to hostile
            pCreature->SetFactionTemplateId(FACTION_HOSTILE);
            // prevents random player pick up a quest during event
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            // save player guid for later use(trigger quest completed)
            privateHendelAI->m_playerGuid = pPlayer->GetObjectGuid();
            // make him attack player, no need to check if(in combat), because you can't pick up a quest if NPC is in combat
            privateHendelAI->AttackStart(pPlayer); // safe
                                                   // switch quest event phase to FIGHT
            privateHendelAI->m_mdQuestPhase = MDQP_FIGHT;
            // set his guards faction to hostile
            for (const auto guard : privateHendelAI->m_guards)
            {
                // if guard is valid
                if (guard)
                {
                    // if guard is alive, set his faction to hostile and make them attack player
                    if (guard->IsAlive())
                    {
                        guard->SetFactionTemplateId(FACTION_HOSTILE);
                        // rare case: players from opposite faction and hostile creatures can be used to distract guards before event starts
                        if (!guard->IsInCombat())
                            guard->AI()->AttackStart(pPlayer);
                    }
                }
            }

        }
        else
            return false;
    }
    return true;
}

CreatureAI* GetAI_npc_private_hendel(Creature* pCreature)
{
    return new npc_private_hendelAI(pCreature);
}

//-----------------------------------------------------------------------------
// Full quest event implementation (Missing Diplomat part 14 id:1265).
// Author: Kampeador
//-----------------------------------------------------------------------------
static const point3o tervoshSpawnPoint = { -3476.860840f, -4106.740723f, 17.107151f, 5.420159f };

enum
{
    QUEST_MISSING_DIPLO_PT14 = 1265, // quest id
    TERVOSH_SPAWN_DURATION = 60000, // 60 sec blizzlike value
    TERVOSH_SAY_ON_QUEST_MD_PT14 = -1999914, // Go with grace, and may the Lady's magic protect you.
    NPC_SENTRY_POINT_GUARD = 5085, // all guards around Tervosh will salute.

    SPELL_TELEPORT_VISUAL1 = 7141, // A visual spell effect when Tervosh arrives
    SPELL_TELEPORT_VISUAL2 = 7077, // A visual spell effect when Tervosh returns back
    SPELL_PROUDMOORES_DEFENSE = 7120, // player characters will receive a buff, once quest is completed

    // script phases:
    MDQP_PREPARE_TO_ARRIVE = 0, // Very rare. It occurs when a new player arrives during MDQP_TELEPORT_BACK in previous event.
    MDQP_ARRIVE = 1, // Tervosh arrives.
    MDQP_GUARDS_SALUTE = 2, // All Sentry Point guards withing 10 yards start facing Tervosh and use EMOTE_ONESHOT_SALUTE emote
    MDQP_GUARDS_RESTORE_MOVEMENT = 3, // Currently unused, core does this automatically.
    MDQP_WAITING = 4, // Wait for despawn
    MDQP_TELEPORT_BACK = 5  // Tervosh despawn during this phase
};

struct npc_archmage_tervoshAI : public ScriptedAI
{
    // this one is modified inside area-trigger script.
    bool m_eventStarted;
    // event timmers
    uint32 m_despawnDelayTimer; // once this timer expires, NPC will despawn.
    // event phase delay
    uint32 m_eventPhase;
    // guards salute timer
    uint32 m_nextPhaseDelayTimer;

    npc_archmage_tervoshAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    // used on area-trigger: if a new player arrives, reset event duration.
    void resetDespawnDelay() { m_despawnDelayTimer = TERVOSH_SPAWN_DURATION; }
    // returns the current phase in the event
    uint32 getCurrentPhase() const { return m_eventPhase; }

    void Reset() override
    {
        m_eventStarted = false;
        m_eventPhase = MDQP_ARRIVE;
        m_nextPhaseDelayTimer = 1000; // delay for the visual effect of the arrival
        m_despawnDelayTimer = TERVOSH_SPAWN_DURATION;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_eventStarted)
        {
            switch (m_eventPhase)
            {
            case MDQP_PREPARE_TO_ARRIVE:
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    m_creature->SetVisibility(VISIBILITY_ON);

                    // switch phase
                    m_nextPhaseDelayTimer = 1000; // delay for the visual effect of the arrival
                    m_eventPhase = MDQP_ARRIVE;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
            case MDQP_ARRIVE:
            {
                // use a visual effect with 1 sec delay
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    m_creature->CastSpell(m_creature, SPELL_TELEPORT_VISUAL1, false);

                    // switch phase
                    m_nextPhaseDelayTimer = 2000; // salute guards 2 sec delay
                    m_eventPhase = MDQP_GUARDS_SALUTE;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
            case MDQP_GUARDS_SALUTE:
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // find all guards nearby
                    std::list<Creature*> guards;
                    // All guards salute withing 10 yards.
                    GetCreatureListWithEntryInGrid(guards, m_creature, NPC_SENTRY_POINT_GUARD, 10);

                    // make guards face private hendel
                    for (auto const& g : guards)
                    {
                        if (!g->IsInCombat() && g->IsAlive())
                        {
                            g->StopMoving(); // Movement will be restored automatically in the core
                            g->SetFacingToObject(m_creature);

                            g->HandleEmote(EMOTE_ONESHOT_SALUTE);
                        }
                    }

                    m_eventPhase = MDQP_WAITING;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            }break;
            case MDQP_WAITING:
            {
                // possible add a visual effect
                if (m_despawnDelayTimer < uiDiff)
                {
                    // cast a visual spell effect
                    m_creature->CastSpell(m_creature, SPELL_TELEPORT_VISUAL2, false);

                    // switch phase, delay despawn by 2 seconds, 1 sec teleport visual, 1 sec latency.
                    m_nextPhaseDelayTimer = 2000; // next quest phase in 2 secs
                    m_eventPhase = MDQP_TELEPORT_BACK;
                }
                else
                    m_despawnDelayTimer -= uiDiff;
            } break;

            case MDQP_TELEPORT_BACK:
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // despawn
                    static_cast<TemporarySummon*>(m_creature)->UnSummon();
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
            }
        }
        else
            ScriptedAI::UpdateAI(uiDiff);
    }
};

bool QuestRewarded_npc_archmage_tervosh(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (!pPlayer || !pCreature || !pQuest)
        return false;

    if (pQuest->GetQuestId() == QUEST_MISSING_DIPLO_PT14)
    {
        if (npc_archmage_tervoshAI* pTervoshAI = dynamic_cast<npc_archmage_tervoshAI*>(pCreature->AI()))
        {
            // Tervosh says: Go with grace, and may the Lady's magic protect you.
            DoScriptText(TERVOSH_SAY_ON_QUEST_MD_PT14, pCreature);

            // rare case: if two players are completing this quest at the same time, then only the last one will receive a buff.
            // i am pretty sure that, this bug existed on retail, so handle this case, by making cast triggered/instant.
            pCreature->CastSpell(pPlayer, SPELL_PROUDMOORES_DEFENSE, true);
        }
    }

    return true;
}

CreatureAI* GetAI_npc_archmage_tervosh(Creature* pCreature)
{
    return new npc_archmage_tervoshAI(pCreature);
}

bool AreaTrigger_at_sentry_point(Player* pPlayer, AreaTriggerEntry const* /*pAt*/)
{
    if (!pPlayer || !pPlayer->IsAlive() || pPlayer->IsGameMaster() ||
        pPlayer->GetQuestStatus(QUEST_MISSING_DIPLO_PT14) == QUEST_STATUS_COMPLETE ||
        pPlayer->GetQuestStatus(QUEST_MISSING_DIPLO_PT14) == QUEST_STATUS_NONE)
        return false;

    // set quest completed
    pPlayer->CompleteQuest(QUEST_MISSING_DIPLO_PT14);
    pPlayer->SendQuestCompleteEvent(QUEST_MISSING_DIPLO_PT14);

    // Check if Tervosh has already arrived.
    Creature* tervosh = GetClosestCreatureWithEntry(pPlayer, NPC_TERVOSH, 15.0f); // check better distance should be shorter as possible
    // Tervosh is not here, summon him.
    if (!tervosh)
    {
        // Summon Tervosh and force map cell active during the event.
        tervosh = pPlayer->SummonCreature(NPC_TERVOSH, tervoshSpawnPoint.x, tervoshSpawnPoint.y, tervoshSpawnPoint.z, tervoshSpawnPoint.o, TEMPSUMMON_MANUAL_DESPAWN, true);
        // something weird happened
        if (!tervosh)
            return false;

        // rare case: players from the opposite faction can attack the NPC during event. Set him unattackable like on official.
        tervosh->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_NPC);

        if (npc_archmage_tervoshAI* tervoshAI = dynamic_cast<npc_archmage_tervoshAI*>(tervosh->AI()))
            tervoshAI->m_eventStarted = true;
    }
    else if (npc_archmage_tervoshAI* tervoshAI = dynamic_cast<npc_archmage_tervoshAI*>(tervosh->AI()))
    {
        // If we're already waiting, let him wait longer
        if (tervoshAI->getCurrentPhase() == MDQP_WAITING)
        {
            tervoshAI->resetDespawnDelay();
        }
        else if (tervoshAI->getCurrentPhase() == MDQP_TELEPORT_BACK)
        {
            // very rare case:
            // players can arrive when Tervosh returns back.
            // spawn Tervosh with invisiblity flag, then make him visible with 3 seconds delay

            // Summon Tervosh and force map cell active during the event.
            tervosh = pPlayer->SummonCreature(NPC_TERVOSH, tervoshSpawnPoint.x, tervoshSpawnPoint.y, tervoshSpawnPoint.z, tervoshSpawnPoint.o, TEMPSUMMON_MANUAL_DESPAWN, true);
            // something weird happened
            if (!tervosh)
                return false;
            tervosh->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_NPC);
            tervosh->SetVisibility(VISIBILITY_OFF);
            // start the event.
            if (npc_archmage_tervoshAI* tervoshNewAI = dynamic_cast<npc_archmage_tervoshAI*>(tervosh->AI()))
            {
                // set inital phase to MDQP_PREPARE_TO_ARRIVE
                tervoshNewAI->m_nextPhaseDelayTimer = 3000;
                tervoshNewAI->m_eventPhase = MDQP_PREPARE_TO_ARRIVE;
                tervoshNewAI->m_eventStarted = true;
            }
        }
    }

    return true;
}

/*######
## npc_lady_jaina_proudmoore
######*/

enum
{
    QUEST_JAINAS_AUTOGRAPH       = 558,
    QUEST_MISSING_DIPLO_PT17     = 1267,
    NPC_SUMMONED_WATER_ELEMENTAL = 10955,
    SPELL_JAINA_FIREBALL         = 20678,
    SPELL_JAINA_FIREBLAST        = 20679,
    SPELL_JAINA_BLIZZARD         = 20680,
    SPELL_JAINA_WATER_ELEMENTAL  = 20681,
    SPELL_JAINA_TELEPORT         = 20682,
    SPELL_JAINAS_AUTOGRAPH       = 23122
};

#define GOSSIP_ITEM_JAINA "I know this is rather silly but i have a young ward who is a bit shy and would like your autograph."

struct npc_lady_jaina_proudmooreAI : public ScriptedAI
{
    npc_lady_jaina_proudmooreAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSpellTimer;
    uint32 m_uiSpecialTimer;

    void Reset() override
    {
        m_uiSpellTimer = 3000;
        m_uiSpecialTimer = 15000;
    }

    void EnterCombat(Unit* enemy) override
    {
        me->PlayDistanceSound(5882);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim() || m_creature->IsNonMeleeSpellCasted())
            return;

        if (m_uiSpecialTimer < uiDiff)
        {
            if (!urand(0, 4) && !m_creature->GetGuardianCountWithEntry(NPC_SUMMONED_WATER_ELEMENTAL))
            {
                if (DoCastSpellIfCan(m_creature, SPELL_JAINA_WATER_ELEMENTAL) == CAST_OK)
                    m_uiSpecialTimer = urand(10, 20)*IN_MILLISECONDS;
            }
            else
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_JAINA_TELEPORT) == CAST_OK)
                { 
                    m_uiSpecialTimer = urand(10, 30)*IN_MILLISECONDS;

                    if (m_creature->GetDistance2d(-4018.1f, -4525.24f) > 40.0f)
                    {
                        // If we don't remove target from threat list after teleporting,
                        // Jaina will try to chase him and evade despite having other targets.
                        Unit* pOldVictim = m_creature->GetVictim();
                        m_creature->_removeAttacker(pOldVictim);
                        m_creature->GetThreatManager().modifyThreatPercent(pOldVictim, -101.0f);
                    }
                }
            }
        }
        else
            m_uiSpecialTimer -= uiDiff;

        if (m_uiSpellTimer < uiDiff)
        {
            switch (urand(0, 4))
            {
                case 0:
                case 1:
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_JAINA_FIREBALL) == CAST_OK)
                        m_uiSpellTimer = urand(3, 10)*IN_MILLISECONDS;
                    break;
                }
                case 2:
                case 3:
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_JAINA_FIREBLAST) == CAST_OK)
                        m_uiSpellTimer = urand(3, 10)*IN_MILLISECONDS;
                    break;
                }
                case 4:
                {
                    if (Unit* pTarget = m_creature->SelectRandomUnfriendlyTarget(nullptr, 25.0f))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_JAINA_BLIZZARD) == CAST_OK)
                            m_uiSpellTimer = urand(1, 3)*IN_MILLISECONDS;
                    }
                    break;
                }
            }
        }
        else
            m_uiSpellTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_lady_jaina_proudmoore(Creature* pCreature)
{
    return new npc_lady_jaina_proudmooreAI(pCreature);
}

bool GossipHello_npc_lady_jaina_proudmoore(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->IsQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_JAINAS_AUTOGRAPH) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_JAINA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    // Correct gossip text depends on The Missing Diplomat quest chain progression.
    if (pPlayer->GetQuestStatus(QUEST_MISSING_DIPLO_PT17) == QUEST_STATUS_COMPLETE)
        pPlayer->SEND_GOSSIP_MENU(3158, pCreature->GetGUID()); // Hendel is in our custody now...
    else if (pPlayer->GetQuestStatus(QUEST_MISSING_DIPLO_PT16) == QUEST_STATUS_COMPLETE)
        pPlayer->SendPreparedQuest(pCreature->GetGUID());
    else
        pPlayer->SEND_GOSSIP_MENU(3157, pCreature->GetGUID()); // I welcome you to Theramore...

    return true;
}

bool GossipSelect_npc_lady_jaina_proudmoore(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF)
    {
        pPlayer->SEND_GOSSIP_MENU(7012, pCreature->GetGUID());
        pPlayer->CastSpell(pPlayer, SPELL_JAINAS_AUTOGRAPH, false);
    }
    return true;
}

/*######
## npc_cassa_crimsonwing
######*/

enum
{
    QUEST_SURVEY_ALCAZ          = 11142,
    SPELL_ALCAZ_SURVEY          = 42295
};

#define GOSSIP_RIDE             "<Ride the gryphons to Survey Alcaz Island>"

bool GossipHello_npc_cassa_crimsonwing(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_SURVEY_ALCAZ) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_RIDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_cassa_crimsonwing(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_ALCAZ_SURVEY, false);
    }
    return true;
}

/*####
# Alita
# npc_stinky_ignatz
####*/

enum
{
    QUEST_STINKYS_ESCAPE_A   = 1222,
    QUEST_STINKYS_ESCAPE_H   = 1270,
    SAY_IGNATZ_START         = -1780190,
    SAY_IGNATZ_1             = -1780191,
    SAY_IGNATZ_2             = -1780192,
    SAY_IGNATZ_3             = -1780193,
    SAY_IGNATZ_4             = -1780194,
    SAY_IGNATZ_END           = -1780195,
    GOBJ_BOGBEAN_PLANT       = 20939
};

struct npc_stinky_ignatzAI : public npc_escortAI
{
    npc_stinky_ignatzAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        currWaypoint = 0;
        timer = 21000;
        Reset();
    }

    void Reset() override {}

    void JustRespawned() override
    {
        currWaypoint = 0;
        timer = 21000;
        npc_escortAI::JustRespawned();
    }

    uint32 currWaypoint;
    uint32 timer;

    void WaypointReached(uint32 uiPointId) override
    {
        currWaypoint = uiPointId;

        switch (uiPointId)
        {
            case 0:
                DoScriptText(SAY_IGNATZ_START, m_creature);
                break;
            case 8:
                DoScriptText(SAY_IGNATZ_1, m_creature);
                break;
            case 16:
                timer = 4000;
                if (GameObject* pGo = m_creature->FindNearestGameObject(GOBJ_BOGBEAN_PLANT, 40.0f))
                    if (!pGo->isSpawned())
                        pGo->Respawn();
                break;
            case 18:
                timer = 2000;
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;
            case 24:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    DoScriptText(SAY_IGNATZ_END, m_creature, pPlayer);
                    if (pPlayer->GetQuestStatus(QUEST_STINKYS_ESCAPE_A) == QUEST_STATUS_INCOMPLETE)
                        pPlayer->GroupEventHappens(QUEST_STINKYS_ESCAPE_A, m_creature);
                    else if (pPlayer->GetQuestStatus(QUEST_STINKYS_ESCAPE_H) == QUEST_STATUS_INCOMPLETE)
                        pPlayer->GroupEventHappens(QUEST_STINKYS_ESCAPE_H, m_creature);
                }
                break;
        }
    }
    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (timer < 20000)
            {
                switch (currWaypoint)
                {
                    case 16 :
                        if (timer < uiDiff)
                        {
                            if (Player* pPlayer = GetPlayerForEscort())
                                DoScriptText(SAY_IGNATZ_3, m_creature, pPlayer);
                            timer = 21000;
                        }
                        else
                        {
                            if (timer >= 1000 && timer < 1000 + uiDiff)
                                DoScriptText(SAY_IGNATZ_2, m_creature);
                            timer -= uiDiff;
                        }
                        break;
                    case 18 :
                        if (timer < uiDiff)
                        {
                            DoScriptText(SAY_IGNATZ_4, m_creature);
                            timer = 21000;
                        }
                        else
                        {
                            if (timer >= 1000 && timer < 1000 + uiDiff)
                            {
                                if (GameObject* pGo = m_creature->FindNearestGameObject(GOBJ_BOGBEAN_PLANT, 10.000000))
                                    pGo->Despawn();
                                m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                            }
                            timer -= uiDiff;
                        }
                        break;
                }
            }
        }
        //DoMeleeAttackIfReady();
        npc_escortAI::UpdateAI(uiDiff);
    }
};

bool QuestAccept_npc_stinky_ignatz(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_STINKYS_ESCAPE_A || pQuest->GetQuestId() == QUEST_STINKYS_ESCAPE_H)
    {
        pCreature->SetFactionTemplateId(113);
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);
        if (npc_stinky_ignatzAI* pEscortAI = dynamic_cast<npc_stinky_ignatzAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

CreatureAI* GetAI_npc_stinky_ignatz(Creature* pCreature)
{
    return new npc_stinky_ignatzAI(pCreature);
}

/*
 * Emberstrife
 */

enum
{
    EMOTE_GENERIC_FRENZY_KILL   = 7797,
    EMOTE_GENERIC_IS_WEAKENED   = -1531011,

    SPELL_FRENZY                = 8269,
    SPELL_CLEAVE                = 19983,
    SPELL_FLAME_BREATH          = 9573
};

struct npc_emberstrifeAI : ScriptedAI
{
    explicit npc_emberstrifeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_emberstrifeAI::Reset();
    }

    uint32 m_uiCleaveTimer;
    uint32 m_uiFrenzyTimer;
    uint32 m_uiFlameBreathTimer;
    bool m_bWeakened;

    void Reset() override
    {
        m_uiCleaveTimer = urand(6000, 8000);
        m_uiFrenzyTimer = 0;
        m_uiFlameBreathTimer = urand(8000, 12000);
        m_bWeakened = false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_bWeakened && m_creature->GetHealthPercent() < 11)
        {
            m_bWeakened = true;
            DoScriptText(EMOTE_GENERIC_IS_WEAKENED, m_creature);
        }

        // Cleave
        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(6000, 8000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // Flame Breath
        if (m_uiFlameBreathTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FLAME_BREATH) == CAST_OK)
                m_uiFlameBreathTimer = urand(8000, 12000);
        }
        else
            m_uiFlameBreathTimer -= uiDiff;

        // Frenzy
        if (m_creature->GetHealthPercent() < 60.0f)
        {
            if (m_uiFrenzyTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
                {
                    DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                    m_uiFrenzyTimer = 2 * MINUTE * IN_MILLISECONDS + 500;
                }
            }
            else
                m_uiFrenzyTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_emberstrife(Creature* pCreature)
{
    return new npc_emberstrifeAI(pCreature);
}

/*
 * Unforged Seal of Ascension (Emberstrife support)
 */

struct go_unforged_sealAI : GameObjectAI
{
    explicit go_unforged_sealAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        m_uiDespawnTimer = 3 * MINUTE * IN_MILLISECONDS;
    }

    uint32 m_uiDespawnTimer;

    bool OnUse(Unit* /*pCaster*/) override
    {
        me->Delete();

        return true;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiDespawnTimer < uiDiff)
            me->Delete();
        else
            m_uiDespawnTimer -= uiDiff;
    }
};

GameObjectAI* GetAI_go_unforged_seal(GameObject* pGo)
{
    return new go_unforged_sealAI(pGo);
}

/*
 * Forged Seal of Ascension (Emberstrife support)
 */

struct go_forged_sealAI : GameObjectAI
{
    explicit go_forged_sealAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        m_uiDespawnTimer = 3 * MINUTE * IN_MILLISECONDS;
    }

    uint32 m_uiDespawnTimer;

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiDespawnTimer < uiDiff)
            me->Delete();
        else
            m_uiDespawnTimer -= uiDiff;
    }
};

GameObjectAI* GetAI_go_forged_seal(GameObject* pGo)
{
    return new go_forged_sealAI(pGo);
}

/*######
##
######*/

void AddSC_dustwallow_marsh()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_private_hendel";
    newscript->GetAI = &GetAI_npc_private_hendel;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_private_hendel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lady_jaina_proudmoore";
    newscript->GetAI = &GetAI_npc_lady_jaina_proudmoore;
    newscript->pGossipHello = &GossipHello_npc_lady_jaina_proudmoore;
    newscript->pGossipSelect = &GossipSelect_npc_lady_jaina_proudmoore;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "npc_archmage_tervosh";
    newscript->GetAI = &GetAI_npc_archmage_tervosh;
    newscript->pQuestRewardedNPC = &QuestRewarded_npc_archmage_tervosh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_sentry_point";
    newscript->pAreaTrigger = &AreaTrigger_at_sentry_point;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_stinky_ignatz";
    newscript->GetAI = &GetAI_npc_stinky_ignatz;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_stinky_ignatz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_emberstrife";
    newscript->GetAI = &GetAI_npc_emberstrife;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_unforged_seal";
    newscript->GOGetAI = &GetAI_go_unforged_seal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_forged_seal";
    newscript->GOGetAI = &GetAI_go_forged_seal;
    newscript->RegisterSelf();
}
