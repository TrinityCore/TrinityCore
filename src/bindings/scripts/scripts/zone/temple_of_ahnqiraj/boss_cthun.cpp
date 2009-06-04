/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Cthun
SD%Complete: 95
SDComment: Darkglare tracking issue
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"
#include "def_temple_of_ahnqiraj.h"

//Text emote
#define EMOTE_WEAKENED              -1531011

#define PI                          3.14

//****** Out of Combat ******
//Random Wispers - No txt only sound
#define RANDOM_SOUND_WHISPER        8663

//***** Phase 1 ********

//Mobs
#define BOSS_EYE_OF_CTHUN                   15589
#define MOB_CLAW_TENTACLE                   15725
#define MOB_EYE_TENTACLE                    15726
#define MOB_SMALL_PORTAL                    15904

//Eye Spells
#define SPELL_GREEN_BEAM                    26134
#define SPELL_DARK_GLARE                    26029
#define SPELL_RED_COLORATION                22518           //Probably not the right spell but looks similar

//Eye Tentacles Spells
#define SPELL_MIND_FLAY                     26143

//Claw Tentacles Spells
#define SPELL_GROUND_RUPTURE                26139
#define SPELL_HAMSTRING                     26141

#define MOB_

//*****Phase 2******
//Body spells
//#define SPELL_CARAPACE_CTHUN                26156   //Was removed from client dbcs
#define SPELL_TRANSFORM                     26232

//Eye Tentacles Spells
//SAME AS PHASE1

//Giant Claw Tentacles
#define SPELL_MASSIVE_GROUND_RUPTURE        26100

//Also casts Hamstring
#define SPELL_THRASH                        3391

//Giant Eye Tentacles
//CHAIN CASTS "SPELL_GREEN_BEAM"

//Stomach Spells
#define SPELL_MOUTH_TENTACLE                26332
#define SPELL_EXIT_STOMACH_KNOCKBACK        25383
#define SPELL_DIGESTIVE_ACID                26476

//Mobs
#define MOB_BODY_OF_CTHUN                   15809
#define MOB_GIANT_CLAW_TENTACLE             15728
#define MOB_GIANT_EYE_TENTACLE              15334
#define MOB_FLESH_TENTACLE                  15802
#define MOB_GIANT_PORTAL                    15910

//Stomach Teleport positions
#define STOMACH_X                           -8562.0f
#define STOMACH_Y                           2037.0f
#define STOMACH_Z                           -70.0f
#define STOMACH_O                           5.05f

//Flesh tentacle positions
#define TENTACLE_POS1_X                     -8571.0f
#define TENTACLE_POS1_Y                     1990.0f
#define TENTACLE_POS1_Z                     -98.0f
#define TENTACLE_POS1_O                     1.22f

#define TENTACLE_POS2_X                     -8525.0f
#define TENTACLE_POS2_Y                     1994.0f
#define TENTACLE_POS2_Z                     -98.0f
#define TENTACLE_POS2_O                     2.12f

//Kick out position
#define KICK_X                              -8545.0f
#define KICK_Y                              1984.0f
#define KICK_Z                              -96.0f

struct TRINITY_DLL_DECL flesh_tentacleAI : public Scripted_NoMovementAI
{
    flesh_tentacleAI(Creature *c) : Scripted_NoMovementAI(c), Parent(0) {}

    uint64 Parent;
    uint32 CheckTimer;

    void SpawnedByCthun(uint64 p)
    {
        Parent = p;
    }

    void Reset()
    {
        CheckTimer = 1000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff);

    void JustDied(Unit* killer);
};

struct TRINITY_DLL_DECL eye_of_cthunAI : public Scripted_NoMovementAI
{
    eye_of_cthunAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        pInst = c->GetInstanceData();
        if (!pInst)
            error_log("TSCR: No Instance eye_of_cthunAI");
    }

    ScriptedInstance* pInst;

    //Global variables
    uint32 PhaseTimer;

    //Eye beam phase
    uint32 BeamTimer;
    uint32 EyeTentacleTimer;
    uint32 ClawTentacleTimer;

    //Dark Glare phase
    uint32 DarkGlareTick;
    uint32 DarkGlareTickTimer;
    float DarkGlareAngle;
    bool ClockWise;

    void Reset()
    {
        //Phase information
        PhaseTimer = 50000;                                 //First dark glare in 50 seconds

        //Eye beam phase 50 seconds
        BeamTimer = 3000;
        EyeTentacleTimer = 45000;                           //Always spawns 5 seconds before Dark Beam
        ClawTentacleTimer = 12500;                          //4 per Eye beam phase (unsure if they spawn durring Dark beam)

        //Dark Beam phase 35 seconds (each tick = 1 second, 35 ticks)
        DarkGlareTick = 0;
        DarkGlareTickTimer = 1000;
        DarkGlareAngle = 0;
        ClockWise = false;

        //Reset flags
        m_creature->RemoveAurasDueToSpell(SPELL_RED_COLORATION);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

        //Reset Phase
        if (pInst)
            pInst->SetData(DATA_CTHUN_PHASE, 0);
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
    }

    void SpawnEyeTentacle(float x, float y)
    {
        Creature* Spawned;
        Spawned = me->SummonCreature(MOB_EYE_TENTACLE,m_creature->GetPositionX()+x,m_creature->GetPositionY()+y,m_creature->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,500);
        if (Spawned)
        {
            Unit* target;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);

            if (target)
                Spawned->AI()->AttackStart(target);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we have a target
        if (!UpdateVictim())
            return;

        //No instance
        if (!pInst)
            return;

        switch (pInst->GetData(DATA_CTHUN_PHASE))
        {
            case 0:
            {
                //BeamTimer
                if (BeamTimer < diff)
                {
                    //SPELL_GREEN_BEAM
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    if (target)
                    {
                        m_creature->InterruptNonMeleeSpells(false);
                        DoCast(target,SPELL_GREEN_BEAM);

                        //Correctly update our target
                        m_creature->SetUInt64Value(UNIT_FIELD_TARGET, target->GetGUID());
                    }

                    //Beam every 3 seconds
                    BeamTimer = 3000;
                }else BeamTimer -= diff;

                //ClawTentacleTimer
                if (ClawTentacleTimer < diff)
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    if (target)
                    {
                        Creature* Spawned = NULL;

                        //Spawn claw tentacle on the random target
                        Spawned = me->SummonCreature(MOB_CLAW_TENTACLE,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,500);

                        if (Spawned)
                            Spawned->AI()->AttackStart(target);
                    }

                    //One claw tentacle every 12.5 seconds
                    ClawTentacleTimer = 12500;
                }else ClawTentacleTimer -= diff;

                //EyeTentacleTimer
                if (EyeTentacleTimer < diff)
                {
                    //Spawn the 8 Eye Tentacles in the corret spots
                    SpawnEyeTentacle(0, 20);                //south
                    SpawnEyeTentacle(10, 10);               //south west
                    SpawnEyeTentacle(20, 0);                //west
                    SpawnEyeTentacle(10, -10);              //north west

                    SpawnEyeTentacle(0, -20);               //north
                    SpawnEyeTentacle(-10, -10);             //north east
                    SpawnEyeTentacle(-20, 0);               // east
                    SpawnEyeTentacle(-10, 10);              // south east

                    //No point actually putting a timer here since
                    //These shouldn't trigger agian until after phase shifts
                    EyeTentacleTimer = 45000;
                }else EyeTentacleTimer -= diff;

                //PhaseTimer
                if (PhaseTimer < diff)
                {
                    //Switch to Dark Beam
                    pInst->SetData(DATA_CTHUN_PHASE, 1);

                    m_creature->InterruptNonMeleeSpells(false);

                    //Select random target for dark beam to start on
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);

                    if (target)
                    {
                        //Correctly update our target
                        m_creature->SetUInt64Value(UNIT_FIELD_TARGET, target->GetGUID());

                        //Face our target
                        DarkGlareAngle = m_creature->GetAngle(target);
                        DarkGlareTickTimer = 1000;
                        DarkGlareTick = 0;
                        ClockWise = rand()%2;
                    }

                    //Add red coloration to C'thun
                    DoCast(m_creature,SPELL_RED_COLORATION);

                    //Freeze animation
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 53);

                    //Darkbeam for 35 seconds
                    PhaseTimer = 35000;
                }else PhaseTimer -= diff;

            }
            break;
            case 1:
            {
                //EyeTentacleTimer
                if (DarkGlareTick < 35)
                    if (DarkGlareTickTimer < diff)
                {
                    //Remove any target
                    m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);

                    //Set angle and cast
                    if (ClockWise)
                        m_creature->SetOrientation(DarkGlareAngle + ((float)DarkGlareTick*PI/35));
                    else m_creature->SetOrientation(DarkGlareAngle - ((float)DarkGlareTick*PI/35));

                    m_creature->StopMoving();

                    //Actual dark glare cast, maybe something missing here?
                    m_creature->CastSpell(m_creature, SPELL_DARK_GLARE, false);

                    //Increase tick
                    DarkGlareTick++;

                    //1 second per tick
                    DarkGlareTickTimer = 1000;
                }else DarkGlareTickTimer -= diff;

                //PhaseTimer
                if (PhaseTimer < diff)
                {
                    //Switch to Eye Beam
                    pInst->SetData(DATA_CTHUN_PHASE, 0);

                    BeamTimer = 3000;
                    EyeTentacleTimer = 45000;               //Always spawns 5 seconds before Dark Beam
                    ClawTentacleTimer = 12500;              //4 per Eye beam phase (unsure if they spawn durring Dark beam)

                    m_creature->InterruptNonMeleeSpells(false);

                    //Remove Red coloration from c'thun
                    m_creature->RemoveAurasDueToSpell(SPELL_RED_COLORATION);

                    //Freeze animation
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                    m_creature->SetUInt32Value(UNIT_FIELD_FLAGS, 0);

                    //Eye Beam for 50 seconds
                    PhaseTimer = 50000;
                }else PhaseTimer -= diff;
            }break;

            //Transition phase
            case 2:
            {
                //Remove any target
                m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                m_creature->SetHealth(0);
            }

            //Dead phase
            case 5:
            {
                m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
            }
        }
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        //No instance
        if (!pInst)
            return;

        switch (pInst->GetData(DATA_CTHUN_PHASE))
        {
            case 0:
            case 1:
            {
                //Only if it will kill
                if (damage < m_creature->GetHealth())
                    return;

                //Fake death in phase 0 or 1 (green beam or dark glare phase)
                m_creature->InterruptNonMeleeSpells(false);

                //Remove Red coloration from c'thun
                m_creature->RemoveAurasDueToSpell(SPELL_RED_COLORATION);

                //Reset to normal emote state and prevent select and attack
                m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                //Remove Target field
                m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);

                //Death animation/respawning;
                pInst->SetData(DATA_CTHUN_PHASE, 2);

                m_creature->SetHealth(0);
                damage = 0;

                m_creature->InterruptNonMeleeSpells(true);
                m_creature->RemoveAllAuras();
            }
            break;

            case 5:
            {
                //Allow death here
                return;
            }

            default:
            {
                //Prevent death in this phase
                damage = 0;
                return;
            }
            break;
        }
    }
};

struct TRINITY_DLL_DECL cthunAI : public Scripted_NoMovementAI
{
    cthunAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        pInst = c->GetInstanceData();
        if (!pInst)
            error_log("TSCR: No Instance eye_of_cthunAI");
    }

    ScriptedInstance* pInst;

    //Out of combat whisper timer
    uint32 WisperTimer;

    //Global variables
    uint32 PhaseTimer;

    //-------------------

    //Phase transition
    uint64 HoldPlayer;

    //Body Phase
    uint32 EyeTentacleTimer;
    uint8 FleshTentaclesKilled;
    uint32 GiantClawTentacleTimer;
    uint32 GiantEyeTentacleTimer;
    uint32 StomachAcidTimer;
    uint32 StomachEnterTimer;
    uint32 StomachEnterVisTimer;
    uint64 StomachEnterTarget;

    //Stomach map, bool = true then in stomach
    UNORDERED_MAP<uint64, bool> Stomach_Map;

    void Reset()
    {
        //One random wisper every 90 - 300 seconds
        WisperTimer = 90000;

        //Phase information
        PhaseTimer = 10000;                                 //Emerge in 10 seconds

        //No hold player for transition
        HoldPlayer = 0;

        //Body Phase
        EyeTentacleTimer = 30000;
        FleshTentaclesKilled = 0;
        GiantClawTentacleTimer = 15000;                     //15 seconds into body phase (1 min repeat)
        GiantEyeTentacleTimer = 45000;                      //15 seconds into body phase (1 min repeat)
        StomachAcidTimer = 4000;                            //Every 4 seconds
        StomachEnterTimer = 10000;                          //Every 10 seconds
        StomachEnterVisTimer = 0;                           //Always 3.5 seconds after Stomach Enter Timer
        StomachEnterTarget = 0;                             //Target to be teleported to stomach

        //Clear players in stomach and outside
        Stomach_Map.clear();

        //Reset flags
        m_creature->RemoveAurasDueToSpell(SPELL_TRANSFORM);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

        if (pInst)
            pInst->SetData(DATA_CTHUN_PHASE, 0);
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
    }

    void SpawnEyeTentacle(float x, float y)
    {
        Creature* Spawned;
        Spawned = me->SummonCreature(MOB_EYE_TENTACLE,m_creature->GetPositionX()+x,m_creature->GetPositionY()+y,m_creature->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,500);
        if (Spawned)
        {
            Unit* target;

            target = SelectRandomNotStomach();

            if (target)
                Spawned->AI()->AttackStart(target);
        }
    }

    Unit* SelectRandomNotStomach()
    {
        if (Stomach_Map.empty())
            return NULL;

        UNORDERED_MAP<uint64, bool>::iterator i = Stomach_Map.begin();

        std::list<Unit*> temp;
        std::list<Unit*>::iterator j;

        //Get all players in map
        while (i != Stomach_Map.end())
        {
            //Check for valid player
            Unit* pUnit = Unit::GetUnit(*m_creature, i->first);

            //Only units out of stomach
            if (pUnit && i->second == false)
            {
                temp.push_back(pUnit);
            }
            ++i;
        }

        if (temp.empty())
            return NULL;

        j = temp.begin();

        //Get random but only if we have more than one unit on threat list
        if (temp.size() > 1)
            advance ( i , rand() % (temp.size() - 1) );

        return (*j);
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we have a target
        if (!UpdateVictim())
        {
            //No target so we'll use this section to do our random wispers instance wide
            //WisperTimer
            if (WisperTimer < diff)
            {
                Map *map = m_creature->GetMap();
                if(!map->IsDungeon()) return;

                //Play random sound to the zone
                Map::PlayerList const &PlayerList = map->GetPlayers();

                if (!PlayerList.isEmpty())
                {
                    for(Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                    {
                        if (Player* pPlr = itr->getSource())
                            pPlr->PlayDirectSound(RANDOM_SOUND_WHISPER,pPlr);
                    }
                }

                //One random wisper every 90 - 300 seconds
                WisperTimer = 90000 + (rand()% 210000);
            }else WisperTimer -= diff;

            return;
        }

        m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);

        //No instance
        if (!pInst)
            return;

        switch (pInst->GetData(DATA_CTHUN_PHASE))
        {
            //Transition phase
            case 2:
            {
                //PhaseTimer
                if (PhaseTimer < diff)
                {
                    //Switch
                    pInst->SetData(DATA_CTHUN_PHASE, 3);

                    //Switch to c'thun model
                    m_creature->InterruptNonMeleeSpells(false);
                    DoCast(m_creature, SPELL_TRANSFORM, false);
                    m_creature->SetHealth(m_creature->GetMaxHealth());

                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                    //Emerging phase
                    //AttackStart(Unit::GetUnit(*m_creature, HoldPlayer));
                    DoZoneInCombat();

                    //Place all units in threat list on outside of stomach
                    Stomach_Map.clear();

                    std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
                    for (; i != m_creature->getThreatManager().getThreatList().end(); ++i)
                    {
                        //Outside stomach
                        Stomach_Map[(*i)->getUnitGuid()] = false;
                    }

                    //Spawn 2 flesh tentacles
                    FleshTentaclesKilled = 0;

                    Creature* Spawned;

                    //Spawn flesh tentacle
                    Spawned = me->SummonCreature(MOB_FLESH_TENTACLE, TENTACLE_POS1_X, TENTACLE_POS1_Y, TENTACLE_POS1_Z, TENTACLE_POS1_O, TEMPSUMMON_CORPSE_DESPAWN, 0);

                    if (!Spawned)
                        FleshTentaclesKilled++;
                    else
                        CAST_AI(flesh_tentacleAI, (Spawned->AI()))->SpawnedByCthun(m_creature->GetGUID());

                    //Spawn flesh tentacle
                    Spawned = me->SummonCreature(MOB_FLESH_TENTACLE, TENTACLE_POS2_X, TENTACLE_POS2_Y, TENTACLE_POS2_Z, TENTACLE_POS2_O, TEMPSUMMON_CORPSE_DESPAWN, 0);

                    if (!Spawned)
                        FleshTentaclesKilled++;
                    else
                        CAST_AI(flesh_tentacleAI, (Spawned->AI()))->SpawnedByCthun(m_creature->GetGUID());

                    PhaseTimer = 0;
                }else PhaseTimer -= diff;

            }break;

            //Body Phase
            case 3:
            {
                //Remove Target field
                m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);

                //Weaken
                if (FleshTentaclesKilled > 1)
                {
                    pInst->SetData(DATA_CTHUN_PHASE, 4);

                    DoScriptText(EMOTE_WEAKENED, m_creature);
                    PhaseTimer = 45000;

                    DoCast(m_creature, SPELL_RED_COLORATION, true);

                    UNORDERED_MAP<uint64, bool>::iterator i = Stomach_Map.begin();

                    //Kick all players out of stomach
                    while (i != Stomach_Map.end())
                    {
                        //Check for valid player
                        Unit* pUnit = Unit::GetUnit(*m_creature, i->first);

                        //Only move units in stomach
                        if (pUnit && i->second == true)
                        {
                            //Teleport each player out
                            DoTeleportPlayer(pUnit, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ()+10, rand()%6);

                            //Cast knockback on them
                            DoCast(pUnit, SPELL_EXIT_STOMACH_KNOCKBACK, true);

                            //Remove the acid debuff
                            pUnit->RemoveAurasDueToSpell(SPELL_DIGESTIVE_ACID);

                            i->second = false;
                        }
                        ++i;
                    }

                    return;
                }

                //Stomach acid
                if (StomachAcidTimer < diff)
                {
                    //Apply aura to all players in stomach
                    UNORDERED_MAP<uint64, bool>::iterator i = Stomach_Map.begin();

                    while (i != Stomach_Map.end())
                    {
                        //Check for valid player
                        Unit* pUnit = Unit::GetUnit(*m_creature, i->first);

                        //Only apply to units in stomach
                        if (pUnit && i->second == true)
                        {
                            //Cast digestive acid on them
                            DoCast(pUnit, SPELL_DIGESTIVE_ACID, true);

                            //Check if player should be kicked from stomach
                            if (pUnit->GetDistance(KICK_X, KICK_Y, KICK_Z) < 15)
                            {
                                //Teleport each player out
                                DoTeleportPlayer(pUnit, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ()+10, rand()%6);

                                //Cast knockback on them
                                DoCast(pUnit, SPELL_EXIT_STOMACH_KNOCKBACK, true);

                                //Remove the acid debuff
                                pUnit->RemoveAurasDueToSpell(SPELL_DIGESTIVE_ACID);

                                i->second = false;
                            }
                        }
                        ++i;
                    }

                    StomachAcidTimer = 4000;
                }else StomachAcidTimer -= diff;

                //Stomach Enter Timer
                if (StomachEnterTimer < diff)
                {
                    Unit* target = NULL;
                    target = SelectRandomNotStomach();

                    if (target)
                    {
                        //Set target in stomach
                        Stomach_Map[target->GetGUID()] = true;
                        target->InterruptNonMeleeSpells(false);
                        target->CastSpell(target, SPELL_MOUTH_TENTACLE, true, NULL, NULL, m_creature->GetGUID());
                        StomachEnterTarget = target->GetGUID();
                        StomachEnterVisTimer = 3800;
                    }

                    StomachEnterTimer = 13800;
                }else StomachEnterTimer -= diff;

                if (StomachEnterVisTimer && StomachEnterTarget)
                    if (StomachEnterVisTimer <= diff)
                {
                    //Check for valid player
                    Unit* pUnit = Unit::GetUnit(*m_creature, StomachEnterTarget);

                    if (pUnit)
                    {
                        DoTeleportPlayer(pUnit, STOMACH_X, STOMACH_Y, STOMACH_Z, STOMACH_O);
                    }

                    StomachEnterTarget = 0;
                    StomachEnterVisTimer = 0;
                }else StomachEnterVisTimer -= diff;

                //GientClawTentacleTimer
                if (GiantClawTentacleTimer < diff)
                {
                    Unit* target = NULL;
                    target = SelectRandomNotStomach();
                    if (target)
                    {
                        Creature* Spawned = NULL;

                        //Spawn claw tentacle on the random target
                        Spawned = me->SummonCreature(MOB_GIANT_CLAW_TENTACLE,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,500);

                        if (Spawned)
                            Spawned->AI()->AttackStart(target);
                    }

                    //One giant claw tentacle every minute
                    GiantClawTentacleTimer = 60000;
                }else GiantClawTentacleTimer -= diff;

                //GiantEyeTentacleTimer
                if (GiantEyeTentacleTimer < diff)
                {
                    Unit* target = NULL;
                    target = SelectRandomNotStomach();
                    if (target)
                    {

                        Creature* Spawned = NULL;

                        //Spawn claw tentacle on the random target
                        Spawned = me->SummonCreature(MOB_GIANT_EYE_TENTACLE,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,500);

                        if (Spawned)
                            Spawned->AI()->AttackStart(target);
                    }

                    //One giant eye tentacle every minute
                    GiantEyeTentacleTimer = 60000;
                }else GiantEyeTentacleTimer -= diff;

                //EyeTentacleTimer
                if (EyeTentacleTimer < diff)
                {
                    //Spawn the 8 Eye Tentacles in the corret spots
                    SpawnEyeTentacle(0, 25);                //south
                    SpawnEyeTentacle(12, 12);               //south west
                    SpawnEyeTentacle(25, 0);                //west
                    SpawnEyeTentacle(12, -12);              //north west

                    SpawnEyeTentacle(0, -25);               //north
                    SpawnEyeTentacle(-12, -12);             //north east
                    SpawnEyeTentacle(-25, 0);               // east
                    SpawnEyeTentacle(-12, 12);              // south east

                    //These spawn at every 30 seconds
                    EyeTentacleTimer = 30000;
                }else EyeTentacleTimer -= diff;

            }break;

            //Weakened state
            case 4:
            {
                //PhaseTimer
                if (PhaseTimer < diff)
                {
                    //Switch
                    pInst->SetData(DATA_CTHUN_PHASE, 3);

                    //Remove red coloration
                    m_creature->RemoveAurasDueToSpell(SPELL_RED_COLORATION);

                    //Spawn 2 flesh tentacles
                    FleshTentaclesKilled = 0;

                    Creature* Spawned;

                    //Spawn flesh tentacle
                    Spawned = me->SummonCreature(MOB_FLESH_TENTACLE, TENTACLE_POS1_X, TENTACLE_POS1_Y, TENTACLE_POS1_Z, TENTACLE_POS1_O, TEMPSUMMON_CORPSE_DESPAWN, 0);

                    if (!Spawned)
                        FleshTentaclesKilled++;
                    else
                        CAST_AI(flesh_tentacleAI, (Spawned->AI()))->SpawnedByCthun(m_creature->GetGUID());

                    //Spawn flesh tentacle
                    Spawned = me->SummonCreature(MOB_FLESH_TENTACLE, TENTACLE_POS2_X, TENTACLE_POS2_Y, TENTACLE_POS2_Z, TENTACLE_POS2_O, TEMPSUMMON_CORPSE_DESPAWN, 0);

                    if (!Spawned)
                        FleshTentaclesKilled++;
                    else
                        CAST_AI(flesh_tentacleAI, (Spawned->AI()))->SpawnedByCthun(m_creature->GetGUID());

                    PhaseTimer = 0;
                }else PhaseTimer -= diff;
            }
        }
    }

    void JustDied(Unit* pKiller)
    {
        //Switch
        if( pInst )
            pInst->SetData(DATA_CTHUN_PHASE, 5);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        //No instance
        if (!pInst)
            return;

        switch (pInst->GetData(DATA_CTHUN_PHASE))
        {
            case 3:
            {
                //Not weakened so reduce damage by 99%
                if (damage / 99 > 0) damage/= 99;
                else damage = 1;

                //Prevent death in non-weakened state
                if (damage >= m_creature->GetHealth())
                    damage = 0;

                return;
            }
            break;

            case 4:
            {
                //Weakened - takes normal damage
                return;
            }

            default:
                damage = 0;
                break;
        }
    }

    void FleshTentcleKilled()
    {
        FleshTentaclesKilled++;
    }
};

struct TRINITY_DLL_DECL eye_tentacleAI : public Scripted_NoMovementAI
{
    eye_tentacleAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        Unit* p = DoSpawnCreature(MOB_SMALL_PORTAL,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN, 0);
        if (p)
            Portal = p->GetGUID();
    }

    uint32 MindflayTimer;
    uint32 KillSelfTimer;
    uint64 Portal;

    void JustDied(Unit* who)
    {
        Unit* p = Unit::GetUnit(*m_creature, Portal);
        if (p)
            p->DealDamage(p, p->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
    }

    void Reset()
    {
        //Mind flay half a second after we spawn
        MindflayTimer = 500;

        //This prevents eyes from overlapping
        KillSelfTimer = 35000;
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we have a target
        if (!UpdateVictim())
            return;

        //KillSelfTimer
        if (KillSelfTimer < diff)
        {
            m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);

            return;
        }else KillSelfTimer -= diff;

        //MindflayTimer
        if (MindflayTimer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target && !target->HasAura(SPELL_DIGESTIVE_ACID))
                DoCast(target,SPELL_MIND_FLAY);

            //Mindflay every 10 seconds
            MindflayTimer = 10100;
        }else MindflayTimer -= diff;
    }
};

struct TRINITY_DLL_DECL claw_tentacleAI : public Scripted_NoMovementAI
{
    claw_tentacleAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        Unit* p = DoSpawnCreature(MOB_SMALL_PORTAL,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN, 0);
        if (p)
            Portal = p->GetGUID();
    }

    uint32 GroundRuptureTimer;
    uint32 HamstringTimer;
    uint32 EvadeTimer;
    uint64 Portal;

    void JustDied(Unit* who)
    {
        Unit* p = Unit::GetUnit(*m_creature, Portal);
        if (p)
            p->DealDamage(p, p->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
    }

    void Reset()
    {
        //First rupture should happen half a second after we spawn
        GroundRuptureTimer = 500;
        HamstringTimer = 2000;
        EvadeTimer = 5000;
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we have a target
        if (!UpdateVictim())
            return;

        //EvadeTimer
        if (!m_creature->IsWithinMeleeRange(m_creature->getVictim()))
            if (EvadeTimer < diff)
        {
            Unit* p = Unit::GetUnit(*m_creature, Portal);
            if (p)
                p->DealDamage(p, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);

            //Dissapear and reappear at new position
            m_creature->SetVisibility(VISIBILITY_OFF);

            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (!target)
            {
                m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
                return;
            }

            if (!target->HasAura(SPELL_DIGESTIVE_ACID))
            {
                m_creature->GetMap()->CreatureRelocation(m_creature, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0);
                Unit* p = DoSpawnCreature(MOB_SMALL_PORTAL,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN, 0);
                if (p)
                    Portal = p->GetGUID();

                GroundRuptureTimer = 500;
                HamstringTimer = 2000;
                EvadeTimer = 5000;
                AttackStart(target);
            }

            m_creature->SetVisibility(VISIBILITY_ON);

        }else EvadeTimer -= diff;

        //GroundRuptureTimer
        if (GroundRuptureTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_GROUND_RUPTURE);
            GroundRuptureTimer = 30000;
        }else GroundRuptureTimer -= diff;

        //HamstringTimer
        if (HamstringTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HAMSTRING);
            HamstringTimer = 5000;
        }else HamstringTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL giant_claw_tentacleAI : public Scripted_NoMovementAI
{
    giant_claw_tentacleAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        Unit* p = DoSpawnCreature(MOB_GIANT_PORTAL,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN, 0);
        if (p)
            Portal = p->GetGUID();
    }

    uint32 GroundRuptureTimer;
    uint32 ThrashTimer;
    uint32 HamstringTimer;
    uint32 EvadeTimer;
    uint64 Portal;

    void JustDied(Unit* who)
    {
        Unit* p = Unit::GetUnit(*m_creature, Portal);
        if (p)
            p->DealDamage(p, p->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
    }

    void Reset()
    {
        //First rupture should happen half a second after we spawn
        GroundRuptureTimer = 500;
        HamstringTimer = 2000;
        ThrashTimer = 5000;
        EvadeTimer = 5000;
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we have a target
        if (!UpdateVictim())
            return;

        //EvadeTimer
        if (!m_creature->IsWithinMeleeRange(m_creature->getVictim()))
            if (EvadeTimer < diff)
        {
            Unit* p = Unit::GetUnit(*m_creature, Portal);
            if (p)
                p->DealDamage(p, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);

            //Dissapear and reappear at new position
            m_creature->SetVisibility(VISIBILITY_OFF);

            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (!target)
            {
                m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
                return;
            }

            if (!target->HasAura(SPELL_DIGESTIVE_ACID))
            {
                m_creature->GetMap()->CreatureRelocation(m_creature, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0);
                Unit* p = DoSpawnCreature(MOB_GIANT_PORTAL,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN, 0);
                if (p)
                    Portal = p->GetGUID();

                GroundRuptureTimer = 500;
                HamstringTimer = 2000;
                ThrashTimer = 5000;
                EvadeTimer = 5000;
                AttackStart(target);
            }

            m_creature->SetVisibility(VISIBILITY_ON);

        }else EvadeTimer -= diff;

        //GroundRuptureTimer
        if (GroundRuptureTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_GROUND_RUPTURE);
            GroundRuptureTimer = 30000;
        }else GroundRuptureTimer -= diff;

        //ThrashTimer
        if (ThrashTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_THRASH);
            ThrashTimer = 10000;
        }else ThrashTimer -= diff;

        //HamstringTimer
        if (HamstringTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HAMSTRING);
            HamstringTimer = 10000;
        }else HamstringTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL giant_eye_tentacleAI : public Scripted_NoMovementAI
{
    giant_eye_tentacleAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        Unit* p = DoSpawnCreature(MOB_GIANT_PORTAL,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN, 0);
        if (p)
            Portal = p->GetGUID();
    }

    uint32 BeamTimer;
    uint64 Portal;

    void JustDied(Unit* who)
    {
        Unit* p = Unit::GetUnit(*m_creature, Portal);
        if (p)
            p->DealDamage(p, p->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
    }

    void Reset()
    {
        //Green Beam half a second after we spawn
        BeamTimer = 500;
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we have a target
        if (!UpdateVictim())
            return;

        //BeamTimer
        if (BeamTimer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target && !target->HasAura(SPELL_DIGESTIVE_ACID))
                DoCast(target,SPELL_GREEN_BEAM);

            //Beam every 2 seconds
            BeamTimer = 2100;
        }else BeamTimer -= diff;
    }
};

//Flesh tentacle functions
void flesh_tentacleAI::UpdateAI(const uint32 diff)
{
    //Check if we have a target
    if (!UpdateVictim())
        return;

    if (Parent)
        if (CheckTimer < diff)
    {
        Unit* pUnit = Unit::GetUnit(*m_creature, Parent);

        if (!pUnit || !pUnit->isAlive() || !pUnit->isInCombat())
        {
            Parent = 0;
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
            return;
        }

        CheckTimer = 1000;
    }else CheckTimer -= diff;

    DoMeleeAttackIfReady();
}

void flesh_tentacleAI::JustDied(Unit* killer)
{
    if (!Parent)
    {
        error_log("TSCR: flesh_tentacle: No Parent variable");
        return;
    }

    Creature* Cthun = Unit::GetCreature(*m_creature, Parent);

    if (Cthun)
        CAST_AI(cthunAI, (Cthun->AI()))->FleshTentcleKilled();
    else error_log("TSCR: flesh_tentacle: No Cthun");
}

//GetAIs
CreatureAI* GetAI_eye_of_cthun(Creature *_Creature)
{
    return new eye_of_cthunAI (_Creature);
}

CreatureAI* GetAI_cthun(Creature *_Creature)
{
    return new cthunAI (_Creature);
}

CreatureAI* GetAI_eye_tentacle(Creature *_Creature)
{
    return new eye_tentacleAI (_Creature);
}

CreatureAI* GetAI_claw_tentacle(Creature *_Creature)
{
    return new claw_tentacleAI (_Creature);
}

CreatureAI* GetAI_giant_claw_tentacle(Creature *_Creature)
{
    return new giant_claw_tentacleAI (_Creature);
}

CreatureAI* GetAI_giant_eye_tentacle(Creature *_Creature)
{
    return new giant_eye_tentacleAI (_Creature);
}

CreatureAI* GetAI_flesh_tentacle(Creature *_Creature)
{
    return new flesh_tentacleAI (_Creature);
}

void AddSC_boss_cthun()
{
    Script *newscript;

    //Eye
    newscript = new Script;
    newscript->Name="boss_eye_of_cthun";
    newscript->GetAI = &GetAI_eye_of_cthun;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_cthun";
    newscript->GetAI = &GetAI_cthun;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_eye_tentacle";
    newscript->GetAI = &GetAI_eye_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_claw_tentacle";
    newscript->GetAI = &GetAI_claw_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_giant_claw_tentacle";
    newscript->GetAI = &GetAI_giant_claw_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_giant_eye_tentacle";
    newscript->GetAI = &GetAI_giant_eye_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_giant_flesh_tentacle";
    newscript->GetAI = &GetAI_flesh_tentacle;
    newscript->RegisterSelf();
}

