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

#include "scriptPCH.h"
#include "naxxramas.h"

enum KelthuzadData
{
    SAY_SUMMON_MINIONS                  = 12999,         // start of phase 1

    SAY_AGGRO1                          = 12995,         // pray for mercy
    SAY_AGGRO2                          = 12996,         // Scream your dying breath!
    SAY_AGGRO3                          = 12997,         // The end is upon you!

    SAY_SLAY1                           = 13021,
    EMOTE_SLAY                          = 13022,

    SAY_DEATH                           = 13019,

    SAY_CHAIN1                          = 13017,         // Your soul, is bound to me now!
    SAY_CHAIN2                          = 13018,         // there will be  no escape
    SAY_FROST_BLAST                     = 13020,         // I will freeze the blood in your veins!

    SAY_REQUEST_AID                     = 12998,         // Master! I require aid! 
    SAY_ANSWER_REQUEST                  = 12994,         // Very well... warriors of the frozen wastes, rise up! I command you to fight, kill, and die for your master. Let none survive...

    SAY_SPECIAL1_MANA_DET               = -1533106,         // (need find correct bct id!) Your petty magics are no challenge to the might of the Scourge! 
    SAY_SPECIAL3_MANA_DET               = -1533107,         // (need find correct bct id!) Enough! I grow tired of these distractions! 
    SAY_SPECIAL2_DISPELL                = -1533108,         // (need find correct bct id!) Fools, you have spread your powers too thin. Be free, my minions!

    EMOTE_GUARDIAN                      = -1533134,         // (need find correct bct id!) at each guardian summon, cant see that it's used in vanilla

    SPELL_VISUAL_CHANNEL                = 29423,            // channeled throughout phase one

    //spells to be casted
    SPELL_FROST_BOLT                    = 28478,
    SPELL_FROST_BOLT_NOVA               = 28479,

    SPELL_CHAINS_OF_KELTHUZAD           = 28408,           
    SPELL_CHAINS_OF_KELTHUZAD_SCALE     = 28409,
    SPELL_CHAINS_OF_KELTHUZAD_EFFECTS   = 28410,

    SPELL_MANA_DETONATION               = 27819,
    SPELL_SHADOW_FISSURE                = 27810,
    SPELL_VOID_BLAST                    = 27812,
    SPELL_FROST_BLAST                   = 27808,
    SPELL_BERSERK                       = 28498,

    SPELL_DISPELL_SHACKLES              = 28471             // not used, doing it "manually"
};

enum AddSpells
{
    // guardian of icecrown
    SPELL_BLOOD_TAP = 28470, 

    // Soul Weaver
    SPELL_WAIL_SOULS_AUR = 28460,

    // Warrior
    SPELL_DARK_BLAST_AUR  = 28458,
    SPELL_DARK_BLAST_TRIG = 28457,

    // Abomination
    SPELL_MORTAL_WOUND = 28467
};

enum Events
{
    // phase one
    EVENT_SKELETON = 1,
    EVENT_SOUL_WEAVER,
    EVENT_ABOMINATION,
    EVENT_PHASE_TWO_INTRO,
    EVENT_PHASE_TWO_START,
    EVENT_DESPAWN_PORTAL,
    EVENT_PUT_IN_COMBAT,

    // phase two
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_FROST_BLAST,
    EVENT_FROSTBOLT,
    EVENT_SHADOW_FISSURE,
    EVENT_DETONATE_MANA,
    EVENT_CHAINS,

    // phase three
    EVENT_REQUEST_REPLY,
    EVENT_SUMMON_GUARDIAN
};

// the shiny thing in center that despawns after pull
static constexpr float pullPortal[3] = { 3716.379883f, -5106.779785f, 132.9f };

// Center position of each alcove
static constexpr uint32 NUM_ALCOVES = 7;
static constexpr float alcoves[7][2] = 
{
    { 3768.40f, -5072.00f},
    { 3729.30f, -5044.10f},
    { 3683.00f, -5054.05f},
    { 3654.15f, -5093.48f},
    { 3664.55f, -5140.50f},
    { 3704.00f, -5170.00f},
    { 3751.95f, -5158.90f} 
};

// z-coordinate in the alcoves
static constexpr float alcoveZ = 143.5f; 

// number of soulweavers total, one in each alcove
static constexpr uint32 NUM_SOULWEAVER = 7;
// each soulweaver position
static constexpr float soulweaverPos[NUM_SOULWEAVER][2] =
{
    {3754.95f, -5164.93f},
    {3701.89f, -5176.95f},
    {3656.83f, -5145.56f},
    {3647.53f, -5093.56f},
    {3678.48f, -5050.46f},
    {3730.87f, -5035.93f},
    {3774.78f, -5067.68f},
};

// number of abominations, 3 in each alcove
static constexpr uint32 NUM_ABOM = 21;
// each abomination position
static constexpr float abomPos[NUM_ABOM][2] =
{
    {3740.70f, -5160.89f},
    {3756.42f, -5151.09f},
    {3748.99f, -5155.72f},

    {3694.11f, -5163.96f},
    {3713.90f, -5168.14f},
    {3704.76f, -5166.21f},

    {3661.65f, -5132.06f},
    {3672.37f, -5147.84f},
    {3666.83f, -5139.67f},

    {3658.81f, -5086.46f},
    {3654.80f, -5104.04f},
    {3656.76f, -5095.47f},

    {3691.83f, -5052.45f},
    {3675.15f, -5062.94f},
    {3683.48f, -5057.71f},

    {3738.15f, -5050.12f},
    {3717.76f, -5046.03f},
    {3728.48f, -5047.99f},

    {3772.53f, -5083.21f},
    {3760.03f, -5064.65f},
    {3765.85f, -5073.22f}
};

// total number of soulweaver and abomination waves 
static constexpr uint32 NUM_UNDEAD_SPAWNS = 14;

// milliseconds since pull for each abomination spawn
static constexpr uint32 abominationSpawnMs[NUM_UNDEAD_SPAWNS] =
{
    44000,
    72000,
    100000,
    130000,
    153000,
    176000,
    193000,
    212000,
    232000,
    252000,
    268000,
    285000,
    300000,
    318000,
};

// milliseconds since pull for each soulweaver spawn
static constexpr uint32 soulweaverSpawnMs[NUM_UNDEAD_SPAWNS] =
{
    44000,
    68000,
    97000,
    130000,
    155000,
    170000,
    190000,
    213000,
    235000,
    256000,
    271000,
    285000,
    294000,
    300000,
};

static constexpr uint32 NUM_WINDOW_PORTALS = 4;
static constexpr float windowPortals[NUM_WINDOW_PORTALS][2] =
{
    {3760.57f, -5173.93f},
    {3700.14f, -5185.68f},
    {3732.62f, -5027.67f},
    {3783.36f, -5062.35f}
};

//todo: no idea what the pull range should be
static constexpr float ALCOVE_ADD_PULL_RADIUS = 30.0f;

struct kt_p1AddAI : public ScriptedAI
{
    kt_p1AddAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        me->SetNoSearchAssistance(true);
        hasAggroed = false;
    }

    bool hasAggroed;

    void Reset() override = 0;

    void ActualAttack(Unit* target)
    {
        m_creature->AddThreat(target, 300.0f);
        ScriptedAI::AttackStart(target);
        hasAggroed = true;
    }

    void Aggro(Unit* pWho) override
    {
        // want to prevent the creature from aggroing unless we explicitly do it through base class
    }

    void AttackStart(Unit* pWho) override
    {
        if (hasAggroed)
            ScriptedAI::AttackStart(pWho);
        // want to prevent the creature from aggroing unless we explicitly do it through this class
        else if(m_creature->GetDistance2d(pWho) < ALCOVE_ADD_PULL_RADIUS)
        {
            ActualAttack(pWho);
        }
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (hasAggroed)
        {
            ScriptedAI::MoveInLineOfSight(pWho);
        }
        else if (m_creature->IsHostileTo(pWho) && m_creature->GetDistance2d(pWho) < ALCOVE_ADD_PULL_RADIUS) //todo: no idea what the pull range should be
        {
            ScriptedAI::MoveInLineOfSight(pWho);
        }
    }

    void SpellHit(Unit* unit, SpellEntry const*) override 
    {
        if(!hasAggroed)
            ActualAttack(unit);
    }
};

struct boss_kelthuzadAI : public ScriptedAI
{
    boss_kelthuzadAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
        pCreature->SetCreatureSummonLimit(240);
    }

    instance_naxxramas* m_pInstance;

    std::vector<std::pair<ObjectGuid,int>> guardians;
    std::vector<ObjectGuid> p1_adds;
    
    int p1Timer;
    bool hasPutInCombat;
    bool p3Started;
    EventMap events;
    ObjectGuid pullPortalGuid;
    uint32 numSummonedGuardians;
    uint32 nextBanshee, nextAbom;
    uint32 numSkeletons, numAboms, numBanshees;
    uint32 enrageTimer;
    uint32 timeSinceLastFrostBlast;
    uint32 timeSinceLastShadowFissure;
    uint32 timeSinceLastAEFrostBolt;
    uint32 killSayTimer;

    void Reset() override
    {
        m_creature->SetHealth(m_creature->GetMaxHealth());
        events.Reset();
        // no info on enragetimer in vanilla, but wotlk has a 19min enrage and uses a spell from 1.11 dbc
        enrageTimer = 1000 * 60 * 19; 
        numSkeletons = 0;
        numAboms = 0;
        numBanshees = 0;
        nextBanshee = 30000;
        nextAbom = 30000;
        p3Started = false;
        numSummonedGuardians = 0;
        timeSinceLastFrostBlast = 0;
        timeSinceLastShadowFissure = 0;
        timeSinceLastAEFrostBolt = 0;
        killSayTimer = 0;
        hasPutInCombat = false;

        m_creature->RemoveAurasDueToSpell(SPELL_VISUAL_CHANNEL);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

        EvadeAllGuardians();

        if (!pullPortalGuid)
        {
            if (GameObject* pGO = m_creature->SummonGameObject(GO_HUB_PORTAL, pullPortal[0], pullPortal[1], pullPortal[2], 0))
            {
                pGO->SetObjectScale(2);
                pullPortalGuid = pGO->GetObjectGuid();
                // the add remove seems to be needed to  make the gobj update scale
                if (m_pInstance)
                {
                    m_pInstance->GetMap()->Remove(pGO, false);
                    m_pInstance->GetMap()->Add(pGO);
                }
            }
        }
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (!killSayTimer)
        {
            DoScriptText(urand(0, 1) ? SAY_SLAY1 : EMOTE_SLAY, m_creature);
            killSayTimer = 5000;
        }
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (m_pInstance)
            m_pInstance->SetData(TYPE_KELTHUZAD, DONE);
        
        EvadeAllGuardians();
    }

    void MoveInLineOfSight(Unit* /*pWho*/) override { }

    void AttackStart(Unit* who) override
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;
        ScriptedAI::AttackStart(who);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        m_creature->SetInCombatWithZone();
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_KELTHUZAD, NOT_STARTED);
            m_pInstance->ToggleKelThuzadWindows(false);
            m_pInstance->ToggleKelThuzadWindows(false);
        }
        DespawnAllIntroCreatures();
        EvadeAllGuardians();
    }

    void EvadeAllGuardians()
    {
        for (const auto& guardian : guardians)
        {
            if (Creature* pCreature = m_pInstance->GetCreature(guardian.first))
            {
                pCreature->AI()->EnterEvadeMode();
            }
        }
    }

    void DespawnAllIntroCreatures()
    {
        for (const auto& guid : p1_adds)
        {
            if (Creature* pSoldier = m_pInstance->instance->GetCreature(guid))
                ((TemporarySummon*)pSoldier)->UnSummon();
        }
        p1_adds.clear();
    }

    void StartEncounter()
    {
        m_pInstance->ToggleKelThuzadWindows(false);
        m_creature->SetHealth(m_creature->GetMaxHealth());
        // on pull there are in each alcove:
        // 3 aboms
        // 1 banshee
        // around 10 skeletons?

        // during p1, 14 aboms, 14 banshees and 120 skeletons should attack, gradually faster
        m_pInstance->SetData(TYPE_KELTHUZAD, IN_PROGRESS);
        DoScriptText(SAY_SUMMON_MINIONS, m_creature);
        DoCastAOE(SPELL_VISUAL_CHANNEL);

        events.ScheduleEvent(EVENT_DESPAWN_PORTAL,  Seconds(7));
        events.ScheduleEvent(EVENT_PUT_IN_COMBAT,   Seconds(20));
        events.ScheduleEvent(EVENT_PHASE_TWO_INTRO, Minutes(5) + Seconds(20));

        p1Timer = 320000;
        events.ScheduleEvent(EVENT_SKELETON, Seconds(20));
        //events.ScheduleEvent(EVENT_SOUL_WEAVER, Seconds(35));
        //events.ScheduleEvent(EVENT_ABOMINATION, Seconds(43));
        for (uint32 i : abominationSpawnMs)
            events.ScheduleEvent(EVENT_ABOMINATION, i);
        for (uint32 i : soulweaverSpawnMs)
            events.ScheduleEvent(EVENT_SOUL_WEAVER, i);

        m_pInstance->DoUseDoorOrButton(pullPortalGuid);

        for (const auto& alcove : alcoves)
        {
            for (int j = 0; j < 10; j++)
            {
                double angle = rand_norm() * 2.0 * M_PI;
                double relDistance = rand_norm() + rand_norm();
                if (relDistance > 1)
                    relDistance = 1 - relDistance;
                float const x = alcove[0];
                float const y = alcove[1];
                float const radius = 14.0f;
                float thisX = x + std::sin(angle)*relDistance*radius;
                float thisY = y + std::cos(angle)*relDistance*radius;
                if (Creature* pCreature = m_creature->SummonCreature(NPC_SOLDIER_FROZEN, thisX, thisY, alcoveZ, frand(0, M_PI_F * 2),
                    TEMPSUMMON_MANUAL_DESPAWN))
                {
                    p1_adds.push_back(pCreature->GetObjectGuid());
                    pCreature->SetHomePosition(x, y, alcoveZ, m_creature->GetOrientation());
                    pCreature->SetWanderDistance(radius);
                }
            }
        }
        for (const auto& position : abomPos)
        {
            if (Creature* pCreature = m_creature->SummonCreature(NPC_UNSTOPPABLE_ABOM, position[0], position[1], alcoveZ, frand(0, M_PI_F * 2),
                TEMPSUMMON_MANUAL_DESPAWN))
            {
                p1_adds.push_back(pCreature->GetObjectGuid());
                pCreature->SetWanderDistance(5.0f);
            }

        }
        for (const auto& position : soulweaverPos)
        {
            if (Creature* pCreature = m_creature->SummonCreature(NPC_SOUL_WEAVER, position[0], position[1], alcoveZ, frand(0, M_PI_F * 2),
                TEMPSUMMON_MANUAL_DESPAWN))
            {
                p1_adds.push_back(pCreature->GetObjectGuid());
                pCreature->SetWanderDistance(5.0f);
            }
        }
    }

    bool SpawnAndSendP1Creature(uint32 type)
    {
        float const* spawnLoc = alcoves[urand(0, NUM_ALCOVES - 1)];
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER))
        {
            float spawnAng = 3.14f + pTarget->GetAngle(spawnLoc[0], spawnLoc[1]);
            if (Creature* pAdd = m_creature->SummonCreature(type, spawnLoc[0], spawnLoc[1], alcoveZ, spawnAng, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000))
            {
                pAdd->SetInCombatWithZone();
                ((kt_p1AddAI*)pAdd->AI())->ActualAttack(pTarget);
                return true;
            }
        }
        return false;
    }

    void UpdateP1(uint32 diff)
    {
        if (m_pInstance->GetData(TYPE_KELTHUZAD) != IN_PROGRESS)
            return;

        p1Timer -= diff;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DESPAWN_PORTAL:
                    if (GameObject* pGO = m_pInstance->GetGameObject(pullPortalGuid))
                    {
                        pullPortalGuid = 0;
                        pGO->Delete();
                    }
                    break;
                case EVENT_PUT_IN_COMBAT:
                    m_creature->SetInCombatState(false);
                    m_creature->SetInCombatWithZone();
                    hasPutInCombat = true;
                    break;
                case EVENT_SKELETON:
                {
                    if (numSkeletons < 120)
                    {
                        if (SpawnAndSendP1Creature(NPC_SOLDIER_FROZEN))
                        {
                            uint32 repeat_next = std::max(uint32(3750 - 25 * numSkeletons), uint32(2000));
                            events.Repeat(repeat_next);
                            ++numSkeletons;
                            //sLog.outBasic("[%d] Spawn SKEL #%d, next in %dms", p1Timer, numSkeletons, repeat_next);
                        }
                        else
                            events.Repeat(100);
                    }
                    break;
                }
                case EVENT_ABOMINATION:
                {
                    SpawnAndSendP1Creature(NPC_UNSTOPPABLE_ABOM);
                    ++numAboms;
                    //sLog.outBasic("[%d] Spawn ABOM #%d", p1Timer, numAboms);
                    break;
                }
                case EVENT_SOUL_WEAVER:
                {
                    SpawnAndSendP1Creature(NPC_SOUL_WEAVER);
                    ++numBanshees;
                    //sLog.outBasic("[%d] Spawn SOUL #%d", p1Timer, numBanshees);
                    break;
                }
                case EVENT_PHASE_TWO_INTRO:
                {
                    // ToDo: slightly hard to figure the exact delay between this event (the yell and despawn of adds)
                    // until he engages. Most vanilla timers say 20 seconds, but he always engages earlier than that.
                    // Seen it at around 10 seconds in a german video (https://www.youtube.com/watch?v=QafmVXupeHc),
                    // and as late as ~17-18 sec in another one (https://www.youtube.com/watch?v=6RpqjIFbQYw https://www.youtube.com/watch?v=wSQtlvVebm0)
                    events.Reset();
                    events.ScheduleEvent(EVENT_PHASE_TWO_START, Seconds(15));
                    if (numBanshees < 14)
                    {
                        SpawnAndSendP1Creature(NPC_SOUL_WEAVER);
                        sLog.outBasic("(post)[%d] Spawn bansh #%d, next in %dms", p1Timer, ++numBanshees, nextBanshee);
                    }
                    if (numAboms < 14)
                    {
                        SpawnAndSendP1Creature(NPC_UNSTOPPABLE_ABOM);
                        sLog.outBasic("(post)[%d] Spawn abom #%d, next in %dms", p1Timer, ++numAboms, nextBanshee);
                    }
                    if (numSkeletons < 120)
                    {
                        SpawnAndSendP1Creature(NPC_SOLDIER_FROZEN);
                        sLog.outBasic("(post)[%d] Spawn skele #%d, next in %dms", p1Timer, ++numSkeletons, nextBanshee);
                    }

                    DoScriptText(urand(SAY_AGGRO1, SAY_AGGRO3), m_creature);
                    m_creature->RemoveAurasDueToSpell(SPELL_VISUAL_CHANNEL);
                    DespawnAllIntroCreatures();
                    break;
                }
                case EVENT_PHASE_TWO_START:
                    // engage!
                    events.Reset();
                    events.ScheduleEvent(EVENT_FROSTBOLT,        Seconds(10));
                    events.ScheduleEvent(EVENT_SHADOW_FISSURE,   Seconds(14));
                    events.ScheduleEvent(EVENT_DETONATE_MANA,    Seconds(20));
                    events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, Seconds(30));
                    events.ScheduleEvent(EVENT_FROST_BLAST,      Seconds(50));
                    events.ScheduleEvent(EVENT_CHAINS,           Seconds(60));
                    m_creature->RemoveAurasDueToSpell(SPELL_VISUAL_CHANNEL);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    //m_creature->CastStop();
                    m_creature->InterruptNonMeleeSpells(true);

                    DoResetThreat();
                    m_creature->SetInCombatWithZone();
                    if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0))
                        AttackStart(pUnit);

                    break;
            }
        }
    }

    void DoChains()
    {
        if (DoCastSpellIfCan(m_creature, SPELL_CHAINS_OF_KELTHUZAD) != CAST_OK)
        {
            events.Repeat(Seconds(2));
            return;
        }

        DoResetThreat();
        DoScriptText(urand(0, 1) ? SAY_CHAIN1 : SAY_CHAIN2, m_creature);
        // Wowwiki the useless has this on 60sec cd,
        // but sampling a random vanilla video, the shortest cd was 60sec, with one as high as 142sec.
        // Setting this to 60-75 as a slight buff
        events.Repeat(Seconds(urand(60, 75)));
    }

    void UpdateP2P3(uint32 diff)
    {
        timeSinceLastFrostBlast += diff;
        timeSinceLastShadowFissure += diff;
        timeSinceLastAEFrostBolt += diff;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetHealthPercent() < 40.0f && !p3Started)
        {
            DoScriptText(SAY_REQUEST_AID, m_creature);
            events.ScheduleEvent(EVENT_REQUEST_REPLY, Seconds(3));
            m_pInstance->ToggleKelThuzadWindows(true);
            events.ScheduleEvent(EVENT_SUMMON_GUARDIAN, Seconds(5));
            p3Started = true;
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_REQUEST_REPLY:
                    m_pInstance->DoOrSimulateScriptTextForThisInstance(SAY_ANSWER_REQUEST, NPC_LICH_KING);
                    break;
                case EVENT_SUMMON_GUARDIAN:
                {
                    // Can be seen in videos they spawn with some delay between eachother.
                    // Not found a clear pattern, but a good guess is one spawn every 5 sec until all 5 has spawned.
                    if (numSummonedGuardians < 5)
                    {
                        // we can re-use the soulweave positions for where to spawn the guardians
                        // todo: is it completely random, or do we avoid re-using the same alcove twize?
                        int portalIndex = urand(0, NUM_WINDOW_PORTALS - 1);
                        float const* pos = windowPortals[portalIndex];

                        if (Creature* pCreature = m_creature->SummonCreature(NPC_GUARDIAN, pos[0], pos[1], alcoveZ, 0.0f, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            guardians.push_back(std::make_pair(pCreature->GetObjectGuid(), portalIndex));
                            ++numSummonedGuardians;
                            events.Repeat(Seconds(7));
                            pCreature->SetInCombatWithZone();
                            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                            {
                                pCreature->AI()->AttackStart(pTarget);
                            }
                        }
                        else
                            events.Repeat(100);
                    }
                    break;
                }
                case EVENT_FROSTBOLT_VOLLEY:
                {
                    if (timeSinceLastFrostBlast < 5000)
                    {
                        events.Repeat(5000 - timeSinceLastFrostBlast);
                        break;
                    }
                    if (DoCastSpellIfCan(m_creature, SPELL_FROST_BOLT_NOVA) == CAST_OK)
                    {
                        events.Repeat(Seconds(urand(15, 17)));
                        timeSinceLastAEFrostBolt = 0;
                    }
                    else
                        events.Repeat(Seconds(1));
                    break;
                }
                case EVENT_FROST_BLAST:
                {
                    if (timeSinceLastShadowFissure < 4000)
                    {
                        events.Repeat(4000 - timeSinceLastShadowFissure);
                        break;
                    }
                    else if (timeSinceLastAEFrostBolt < 5000)
                    {
                        events.Repeat(5000 - timeSinceLastAEFrostBolt);
                        break;
                    }
                    if (m_creature->IsNonMeleeSpellCasted())
                    {
                        events.Repeat(Seconds(1));
                        break;
                    }
                    if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                    {
                        if (DoCastSpellIfCan(pUnit, SPELL_FROST_BLAST) == CAST_OK)
                        {
                            events.Repeat(Seconds(urand(30, 60)));
                            timeSinceLastFrostBlast = 0;
                            if (urand(0, 1))
                                DoScriptText(SAY_FROST_BLAST, m_creature);
                            break;
                        }
                        else
                            events.Repeat(Seconds(1));
                    }
                    else
                        events.Repeat(Seconds(1));
                    break;
                }
                case EVENT_FROSTBOLT:
                {
                    events.Repeat(Seconds(urand(5, 7))); // todo: this is guesswork
                    DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FROST_BOLT);
                    break;
                }
                case EVENT_SHADOW_FISSURE:
                {
                    if (timeSinceLastFrostBlast < 4000)
                    {
                        events.Repeat(4000 - timeSinceLastFrostBlast);
                        break;
                    }
                    if (m_creature->IsNonMeleeSpellCasted())
                    {
                        events.Repeat(Seconds(2));
                        break;
                    }
                    if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                    {
                        if (DoCastSpellIfCan(pUnit, SPELL_SHADOW_FISSURE) == CAST_OK)
                        {
                            events.Repeat(Seconds(urand(10, 20)));
                            timeSinceLastShadowFissure = 0;
                        }
                        else
                            events.Repeat(Seconds(1));
                    }
                    else
                        events.Repeat(Seconds(1));
                    break;
                }
                case EVENT_DETONATE_MANA:
                {
                    if (m_creature->IsNonMeleeSpellCasted())
                    {
                        events.Repeat(Seconds(2));
                        break;
                    }

                    events.Repeat(Seconds(urand(20,25)));

                    if(Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_MANA_DETONATION, SELECT_FLAG_POWER_MANA|SELECT_FLAG_PLAYER))
                    {
                        if (DoCastSpellIfCan(pUnit, SPELL_MANA_DETONATION) == CAST_OK)
                        {
                            if (urand(0, 1))
                                DoScriptText(SAY_SPECIAL1_MANA_DET, m_creature);
                            break;
                        }
                    }
                    break;
                }
                case EVENT_CHAINS:
                    DoChains();
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance)
            return;

        if (hasPutInCombat)
        {
            // won't have a victim if we are in p1, even if selectHostileTarget returns true, so check that before return
            if (!m_creature->SelectHostileTarget() || (!m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) && !m_creature->GetVictim()))
                return;
        }

        if (m_pInstance->GetData(TYPE_KELTHUZAD) != IN_PROGRESS)
            return;

        killSayTimer -= std::min(killSayTimer, diff);

        if (enrageTimer < diff)
        {
            m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
            enrageTimer = 300000;
        }
        else
            enrageTimer -= diff;

        events.Update(diff);

        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            UpdateP1(diff);
        else
        {
            if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
                return;
            UpdateP2P3(diff);
        }
    }
};

struct mob_abomAI : public kt_p1AddAI
{
    mob_abomAI(Creature* pCreature) : kt_p1AddAI(pCreature)
    {
        Reset();
    }

    uint32 mortalWoundTimer;

    void Reset() override
    {
        mortalWoundTimer = 7500;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (mortalWoundTimer < diff)
        {
            if(m_creature->GetVictim() && m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTAL_WOUND) == CAST_OK)
                    mortalWoundTimer = 7500;
        }
        else
            mortalWoundTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_soldierAI : public kt_p1AddAI
{
    mob_soldierAI(Creature* pCreature) : kt_p1AddAI(pCreature)
    {
        Reset();
    }

    void Reset() override { }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_creature->HasAura(SPELL_DARK_BLAST_AUR))
            m_creature->CastSpell(m_creature, SPELL_DARK_BLAST_AUR, true);

        //if (m_creature->GetVictim() && m_creature->GetVictim()->IsPlayer()) 
        //{
        //    bool inVisibleList = m_creature->GetVictim()->ToPlayer()->IsInVisibleList(m_creature);
        //    sLog.outBasic("%s visible: %d", m_creature->GetVictim()->GetName(), inVisibleList);
        //}
        //m_creature->ForceValuesUpdateAtIndex(UNIT_FIELD_TARGET);

        // to avoid melees being able to dps while casters hold aggro, this is most likely a logic that's supposed to exist
        if (Unit* pNearest = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0))
        {
            if (m_creature->GetVictim() != pNearest && m_creature->CanReachWithMeleeAutoAttack(pNearest))
            {
                ScriptedAI::AttackStart(pNearest);
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_soulweaverAI : public kt_p1AddAI
{
    mob_soulweaverAI(Creature* pCreature) : kt_p1AddAI(pCreature) { }

    bool hasHitSomeone;

    void Reset() override
    {
        hasHitSomeone = false;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_creature->HasAura(SPELL_WAIL_SOULS_AUR))
            m_creature->CastSpell(m_creature, SPELL_WAIL_SOULS_AUR, true);

        // to avoid melees being able to dps while casters hold aggro, this is most likely a logic that's supposed to exist
        if (Unit* pNearest = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0))
        {
            if (m_creature->GetVictim() != pNearest && m_creature->CanReachWithMeleeAutoAttack(pNearest))
            {
                ScriptedAI::AttackStart(pNearest);
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_guardian_icecrownAI : public ScriptedAI
{
    mob_guardian_icecrownAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;
    uint32 bloodTapTimer;

    void Reset() override
    {
        // Not sure if this was 18 or 15sec cd in vanilla, was 15 in wotlk. But making it 15 as we already
        // overpower last phase anyway
        bloodTapTimer = 15000;
    }

    void JustReachedHome() override
    {
        m_creature->DeleteLater();
        ///m_creature->ForcedDespawn(1);
    }

    void DispellShackle(Creature* pC)
    {
        if (pC->HasAura(9484))
            pC->RemoveAurasDueToSpell(9484);
        else if (pC->HasAura(9485))
            pC->RemoveAurasDueToSpell(9485);
        else if (pC->HasAura(10955))
            pC->RemoveAurasDueToSpell(10955);
    }

    void SpellHit(Unit*, SpellEntry const* spell) override 
    {
        // if hit by any shackle spell we check how many other guardians are shackled.
        // If more than 3, we release everyone.
        switch (spell->Id)
        {
            case 10955:
            case 9485:
            case 9484:
            {
                std::list<Creature*> guardians;
                GetCreatureListWithEntryInGrid(guardians, m_creature, NPC_GUARDIAN, 130.0f);
                uint32 numShackled = 0;
                for (Creature* pC : guardians)
                {
                    if (pC->HasAura(9484) || pC->HasAura(9485) || pC->HasAura(10955))
                        ++numShackled;
                }

                if (numShackled > 3)
                {
                    if (m_pInstance)
                    {
                        if (Creature* pKT = m_pInstance->GetSingleCreatureFromStorage(NPC_KELTHUZAD))
                            DoScriptText(SAY_SPECIAL2_DISPELL, pKT);
                    }
                    for (Creature* pC : guardians)
                    {
                        DispellShackle(pC);
                    }
                }
                break;
            }
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (bloodTapTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BLOOD_TAP) == CAST_OK)
                bloodTapTimer = 15000;
        }
        else bloodTapTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_shadow_fissureAI : public ScriptedAI
{
    mob_shadow_fissureAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 timer;
    bool haveCasted;

    void Reset() override
    {
        timer = 3000;
        haveCasted = false;
    }

    void Aggro(Unit*) override { }
    void AttackStart(Unit*) override { }
    void MoveInLineOfSight(Unit* pWho) override { }

    void UpdateAI(uint32 const diff) override
    {
        if (haveCasted)
            return;

        if (timer < diff)
        {
            m_creature->CastSpell(m_creature, SPELL_VOID_BLAST, true);
            haveCasted = true;
            m_creature->ForcedDespawn(2250);
        }
        else
            timer -= diff;
    }
};

CreatureAI* GetAI_boss_kelthuzad(Creature* pCreature)
{
    return new boss_kelthuzadAI(pCreature);
}

CreatureAI* GetAI_mob_abom(Creature* pCreature)
{
    return new mob_abomAI(pCreature);
}

CreatureAI* GetAI_mob_soldier(Creature* pCreature)
{
    return new mob_soldierAI(pCreature);
}

CreatureAI* GetAI_mob_soulweaver(Creature* pCreature)
{
    return new mob_soulweaverAI(pCreature);
}

CreatureAI* GetAI_mob_guardian_icecrown(Creature* pCreature)
{
    return new mob_guardian_icecrownAI(pCreature);
}

CreatureAI* GetAI_mob_shadow_fissure(Creature* pCreature)
{
    return new mob_shadow_fissureAI(pCreature);
}

void instance_naxxramas::OnKTAreaTrigger(AreaTriggerEntry const* pAT)
{
    if (GetData(TYPE_KELTHUZAD) != NOT_STARTED)
        return;

    if (Creature* pKT = GetSingleCreatureFromStorage(NPC_KELTHUZAD))
    {
        if (boss_kelthuzadAI* ai = (boss_kelthuzadAI*)pKT->AI())
        {
            ai->StartEncounter();
        }
    }
}

void AddSC_boss_kelthuzad()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_kelthuzad";
    NewScript->GetAI = &GetAI_boss_kelthuzad;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "unstoppable_abomination_ai";
    NewScript->GetAI = &GetAI_mob_abom;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "soldier_frozen_wastes_ai";
    NewScript->GetAI = &GetAI_mob_soldier;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "soul_weaver_ai";
    NewScript->GetAI = &GetAI_mob_soulweaver;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_guardian_icecrownAI";
    NewScript->GetAI = &GetAI_mob_guardian_icecrown;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_shadow_fissure";
    NewScript->GetAI = &GetAI_mob_shadow_fissure;
    NewScript->RegisterSelf();
}
