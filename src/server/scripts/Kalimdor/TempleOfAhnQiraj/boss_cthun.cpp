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
SDName: Boss_Cthun
SD%Complete: 95
SDComment: Darkglare tracking issue
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "temple_of_ahnqiraj.h"
#include "Player.h"

/*
 * This is a 2 phases events. Here follows an explanation of the main events and transition between phases and sub-phases.
 *
 * The first phase is the EYE phase: the Eye of C'Thun is active and C'thun is not active.
 *     During this phase, the "Eye of C'Thun" alternates between 2 sub-phases:
 *         - PHASE_EYE_GREEN_BEAM:
 *             50 sec phase during which the Eye mainly casts its Green Beam every 3 sec.
 *         - PHASE_EYE_RED_BEAM:
 *             35 sec phase during which the Eye casts its red beam every sec.
 *     This EYE phase ends when the "Eye of C'Thun" is killed. Then starts the CTHUN phase.
 *
 * The second phase is the CTHUN phase. The Eye of C'Thun is not active and C'Thun is active.
 *     This phase starts with the transformation of the Eye into C'Thun (PHASE_CTHUN_TRANSITION).
 *     After the transformation, C'Thun alternates between 2 sub-phases:
 *         - PHASE_CTHUN_STOMACH:
 *             - C'Thun is almost insensible to all damage (99% damage reduction).
 *             - It spawns 2 tentacles in its stomach.
 *             - C'Thun swallows players.
 *             - This sub-phase ends when the 2 tentacles are killed. Swallowed players are regurgitate.
 *
 *         - PHASE_CTHUN_WEAK:
 *             - weakened C'Thun takes normal damage.
 *             - This sub-phase ends after 45 secs.
 *
 *     This CTHUN phase ends when C'Thun is killed
 *
 * Note:
 * - the current phase is stored in the instance data to be easily shared between the eye and cthun.
 */

enum Phases
{
    PHASE_NOT_STARTED                           = 0,

    // Main Phase 1 - EYE
    PHASE_EYE_GREEN_BEAM                        = 1,
    PHASE_EYE_RED_BEAM                          = 2,

    // Main Phase 2 - CTHUN
    PHASE_CTHUN_TRANSITION                      = 3,
    PHASE_CTHUN_STOMACH                         = 4,
    PHASE_CTHUN_WEAK                            = 5,

    PHASE_CTHUN_DONE                            = 6,
};

enum Spells
{
    // ***** Main Phase 1 ********
    //Eye Spells
    SPELL_FREEZE_ANIM                           = 16245,
    SPELL_GREEN_BEAM                            = 26134,
    SPELL_DARK_GLARE                            = 26029,
    SPELL_RED_COLORATION                        = 22518,        //Probably not the right spell but looks similar

    //Eye Tentacles Spells
    SPELL_MIND_FLAY                             = 26143,

    //Claw Tentacles Spells
    SPELL_GROUND_RUPTURE                        = 26139,
    SPELL_HAMSTRING                             = 26141,

    // ***** Main Phase 2 ******
    //Body spells
    //SPELL_CARAPACE_CTHUN                        = 26156   //Was removed from client dbcs
    SPELL_TRANSFORM                             = 26232,
    SPELL_PURPLE_COLORATION                     = 22581,     //Probably not the right spell but looks similar

    //Eye Tentacles Spells
    //SAME AS PHASE1

    //Giant Claw Tentacles
    SPELL_MASSIVE_GROUND_RUPTURE                = 26100,

    //Also casts Hamstring
    SPELL_THRASH                                = 3391,

    //Giant Eye Tentacles
    //CHAIN CASTS "SPELL_GREEN_BEAM"

    //Stomach Spells
    SPELL_MOUTH_TENTACLE                        = 26332,
    SPELL_EXIT_STOMACH_KNOCKBACK                = 25383,
    SPELL_DIGESTIVE_ACID                        = 26476,
};

enum Actions
{
    ACTION_FLESH_TENTACLE_KILLED                = 1,
};

enum Yells
{
    //Text emote
    EMOTE_WEAKENED                              = 0,

    // ****** Out of Combat ******
    // Random Wispers - No txt only sound
    // The random sound is chosen by the client.
    RANDOM_SOUND_WHISPER                        = 8663,
};

//Stomach Teleport positions
#define STOMACH_X                           -8562.0f
#define STOMACH_Y                           2037.0f
#define STOMACH_Z                           -70.0f
#define STOMACH_O                           5.05f

//Flesh tentacle positions
const Position FleshTentaclePos[2] =
{
    { -8571.0f, 1990.0f, -98.0f, 1.22f},
    { -8525.0f, 1994.0f, -98.0f, 2.12f},
};

//Kick out position
const Position KickPos = { -8545.0f, 1984.0f, -96.0f, 0.0f};

class boss_eye_of_cthun : public CreatureScript
{
public:
    boss_eye_of_cthun() : CreatureScript("boss_eye_of_cthun") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<eye_of_cthunAI>(creature);
    }

    struct eye_of_cthunAI : public ScriptedAI
    {
        eye_of_cthunAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            SetCombatMovement(false);
        }

        InstanceScript* instance;

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

        void Reset() override
        {
            //Phase information
            PhaseTimer = 50000;                                 //First dark glare in 50 seconds

            //Eye beam phase 50 seconds
            BeamTimer = 3000;
            EyeTentacleTimer = 45000;                           //Always spawns 5 seconds before Dark Beam
            ClawTentacleTimer = 12500;                          //4 per Eye beam phase (unsure if they spawn during Dark beam)

            //Dark Beam phase 35 seconds (each tick = 1 second, 35 ticks)
            DarkGlareTick = 0;
            DarkGlareTickTimer = 1000;
            DarkGlareAngle = 0;
            ClockWise = false;

            //Reset flags
            me->RemoveAurasDueToSpell(SPELL_RED_COLORATION);
            me->RemoveAurasDueToSpell(SPELL_FREEZE_ANIM);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetVisible(true);

            //Reset Phase
            instance->SetData(DATA_CTHUN_PHASE, PHASE_NOT_STARTED);

            //to avoid having a following void zone
            Creature* pPortal= me->FindNearestCreature(NPC_CTHUN_PORTAL, 10);
            if (pPortal)
                pPortal->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
            instance->SetData(DATA_CTHUN_PHASE, PHASE_EYE_GREEN_BEAM);
        }

        void SpawnEyeTentacle(float x, float y)
        {
            if (Creature* Spawned = DoSpawnCreature(NPC_EYE_TENTACLE, x, y, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 500))
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    if (Spawned->AI())
                        Spawned->AI()->AttackStart(target);
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
                return;

            uint32 currentPhase = instance->GetData(DATA_CTHUN_PHASE);
            if (currentPhase == PHASE_EYE_GREEN_BEAM || currentPhase == PHASE_EYE_RED_BEAM)
            {
                // EyeTentacleTimer
                if (EyeTentacleTimer <= diff)
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

                    EyeTentacleTimer = 45000;
                } else EyeTentacleTimer -= diff;
            }

            switch (currentPhase)
            {
                case PHASE_EYE_GREEN_BEAM:
                    //BeamTimer
                    if (BeamTimer <= diff)
                    {
                        //SPELL_GREEN_BEAM
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->InterruptNonMeleeSpells(false);
                            DoCast(target, SPELL_GREEN_BEAM);

                            //Correctly update our target
                            me->SetTarget(target->GetGUID());
                        }

                        //Beam every 3 seconds
                        BeamTimer = 3000;
                    } else BeamTimer -= diff;

                    //ClawTentacleTimer
                    if (ClawTentacleTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            Creature* Spawned = NULL;

                            //Spawn claw tentacle on the random target
                            Spawned = me->SummonCreature(NPC_CLAW_TENTACLE, *target, TEMPSUMMON_CORPSE_DESPAWN, 500);

                            if (Spawned && Spawned->AI())
                                Spawned->AI()->AttackStart(target);
                        }

                        //One claw tentacle every 12.5 seconds
                        ClawTentacleTimer = 12500;
                    } else ClawTentacleTimer -= diff;

                    //PhaseTimer
                    if (PhaseTimer <= diff)
                    {
                        //Switch to Dark Beam
                        instance->SetData(DATA_CTHUN_PHASE, PHASE_EYE_RED_BEAM);

                        me->InterruptNonMeleeSpells(false);
                        me->SetReactState(REACT_PASSIVE);

                        //Remove any target
                        me->SetTarget(0);

                        //Select random target for dark beam to start on
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            //Face our target
                            DarkGlareAngle = me->GetAngle(target);
                            DarkGlareTickTimer = 1000;
                            DarkGlareTick = 0;
                            ClockWise = RAND(true, false);
                        }

                        //Add red coloration to C'thun
                        DoCast(me, SPELL_RED_COLORATION, true);

                        //Freeze animation
                        DoCast(me, SPELL_FREEZE_ANIM);
                        me->SetOrientation(DarkGlareAngle);
                        me->StopMoving();

                        //Darkbeam for 35 seconds
                        PhaseTimer = 35000;
                    } else PhaseTimer -= diff;

                    break;

                case PHASE_EYE_RED_BEAM:
                    if (DarkGlareTick < 35)
                    {
                        if (DarkGlareTickTimer <= diff)
                        {
                            //Set angle and cast
                            if (ClockWise)
                                me->SetOrientation(DarkGlareAngle + DarkGlareTick * M_PI / 35);
                            else
                                me->SetOrientation(DarkGlareAngle - DarkGlareTick * M_PI / 35);

                            me->StopMoving();

                            //Actual dark glare cast, maybe something missing here?
                            DoCast(me, SPELL_DARK_GLARE, false);

                            //Increase tick
                            ++DarkGlareTick;

                            //1 second per tick
                            DarkGlareTickTimer = 1000;
                        } else DarkGlareTickTimer -= diff;
                    }

                    //PhaseTimer
                    if (PhaseTimer <= diff)
                    {
                        //Switch to Eye Beam
                        instance->SetData(DATA_CTHUN_PHASE, PHASE_EYE_GREEN_BEAM);

                        BeamTimer = 3000;
                        ClawTentacleTimer = 12500;              //4 per Eye beam phase (unsure if they spawn during Dark beam)

                        me->InterruptNonMeleeSpells(false);

                        //Remove Red coloration from c'thun
                        me->RemoveAurasDueToSpell(SPELL_RED_COLORATION);
                        me->RemoveAurasDueToSpell(SPELL_FREEZE_ANIM);

                        //set it back to aggressive
                        me->SetReactState(REACT_AGGRESSIVE);

                        //Eye Beam for 50 seconds
                        PhaseTimer = 50000;
                    } else PhaseTimer -= diff;

                    break;

                //Transition phase
                case PHASE_CTHUN_TRANSITION:
                    //Remove any target
                    me->SetTarget(0);
                    me->SetHealth(0);
                    me->SetVisible(false);
                    break;

                //Dead phase
                case PHASE_CTHUN_DONE:
                    Creature* pPortal= me->FindNearestCreature(NPC_CTHUN_PORTAL, 10);
                    if (pPortal)
                        pPortal->DespawnOrUnsummon();

                    me->DespawnOrUnsummon();
                    break;
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            switch (instance->GetData(DATA_CTHUN_PHASE))
            {
                case PHASE_EYE_GREEN_BEAM:
                case PHASE_EYE_RED_BEAM:
                    //Only if it will kill
                    if (damage < me->GetHealth())
                        return;

                    //Fake death in phase 0 or 1 (green beam or dark glare phase)
                    me->InterruptNonMeleeSpells(false);

                    //Remove Red coloration from c'thun
                    me->RemoveAurasDueToSpell(SPELL_RED_COLORATION);

                    //Reset to normal emote state and prevent select and attack
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                    //Remove Target field
                    me->SetTarget(0);

                    //Death animation/respawning;
                    instance->SetData(DATA_CTHUN_PHASE, PHASE_CTHUN_TRANSITION);

                    me->SetHealth(0);
                    damage = 0;

                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAllAuras();
                    break;

                case PHASE_CTHUN_DONE:
                    //Allow death here
                    return;

                default:
                    //Prevent death in these phases
                    damage = 0;
                    return;
            }
        }
    };

};

class boss_cthun : public CreatureScript
{
public:
    boss_cthun() : CreatureScript("boss_cthun") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<cthunAI>(creature);
    }

    struct cthunAI : public ScriptedAI
    {
        cthunAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);

            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

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

        void Reset() override
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
            me->RemoveAurasDueToSpell(SPELL_TRANSFORM);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetVisible(false);

            instance->SetData(DATA_CTHUN_PHASE, PHASE_NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void SpawnEyeTentacle(float x, float y)
        {
            Creature* Spawned;
            Spawned = DoSpawnCreature(NPC_EYE_TENTACLE, x, y, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 500);
            if (Spawned && Spawned->AI())
                if (Unit* target = SelectRandomNotStomach())
                    Spawned->AI()->AttackStart(target);
        }

        Unit* SelectRandomNotStomach()
        {
            if (Stomach_Map.empty())
                return NULL;

            UNORDERED_MAP<uint64, bool>::const_iterator i = Stomach_Map.begin();

            std::list<Unit*> temp;
            std::list<Unit*>::const_iterator j;

            //Get all players in map
            while (i != Stomach_Map.end())
            {
                //Check for valid player
                Unit* unit = Unit::GetUnit(*me, i->first);

                //Only units out of stomach
                if (unit && i->second == false)
                    temp.push_back(unit);

                ++i;
            }

            if (temp.empty())
                return NULL;

            j = temp.begin();

            //Get random but only if we have more than one unit on threat list
            if (temp.size() > 1)
                advance (j, rand() % (temp.size() - 1));

            return (*j);
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
            {
                //No target so we'll use this section to do our random wispers instance wide
                //WisperTimer
                if (WisperTimer <= diff)
                {
                    Map* map = me->GetMap();
                    if (!map->IsDungeon())
                        return;

                    //Play random sound to the zone
                    Map::PlayerList const &PlayerList = map->GetPlayers();

                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                        {
                            if (Player* pPlr = itr->GetSource())
                                pPlr->PlayDirectSound(RANDOM_SOUND_WHISPER, pPlr);
                        }
                    }

                    //One random wisper every 90 - 300 seconds
                    WisperTimer = urand(90000, 300000);
                } else WisperTimer -= diff;

                return;
            }

            me->SetTarget(0);

            uint32 currentPhase = instance->GetData(DATA_CTHUN_PHASE);
            if (currentPhase == PHASE_CTHUN_STOMACH || currentPhase == PHASE_CTHUN_WEAK)
            {
                // EyeTentacleTimer
                if (EyeTentacleTimer <= diff)
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

                    EyeTentacleTimer = 30000; // every 30sec in phase 2
                } else EyeTentacleTimer -= diff;
            }

            switch (currentPhase)
            {
                //Transition phase
                case PHASE_CTHUN_TRANSITION:
                    //PhaseTimer
                    if (PhaseTimer <= diff)
                    {
                        //Switch
                        instance->SetData(DATA_CTHUN_PHASE, PHASE_CTHUN_STOMACH);

                        //Switch to c'thun model
                        me->InterruptNonMeleeSpells(false);
                        DoCast(me, SPELL_TRANSFORM, false);
                        me->SetFullHealth();

                        me->SetVisible(true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                        //Emerging phase
                        //AttackStart(Unit::GetUnit(*me, HoldpPlayer));
                        DoZoneInCombat();

                        //Place all units in threat list on outside of stomach
                        Stomach_Map.clear();

                        for (std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin(); i != me->getThreatManager().getThreatList().end(); ++i)
                            Stomach_Map[(*i)->getUnitGuid()] = false;   //Outside stomach

                        //Spawn 2 flesh tentacles
                        FleshTentaclesKilled = 0;

                        //Spawn flesh tentacle
                        for (uint8 i = 0; i < 2; i++)
                        {
                            Creature* spawned = me->SummonCreature(NPC_FLESH_TENTACLE, FleshTentaclePos[i], TEMPSUMMON_CORPSE_DESPAWN);
                            if (!spawned)
                                ++FleshTentaclesKilled;
                        }

                        PhaseTimer = 0;
                    } else PhaseTimer -= diff;

                    break;

                //Body Phase
                case PHASE_CTHUN_STOMACH:
                    //Remove Target field
                    me->SetTarget(0);

                    //Weaken
                    if (FleshTentaclesKilled > 1)
                    {
                        instance->SetData(DATA_CTHUN_PHASE, PHASE_CTHUN_WEAK);

                        Talk(EMOTE_WEAKENED);
                        PhaseTimer = 45000;

                        DoCast(me, SPELL_PURPLE_COLORATION, true);

                        UNORDERED_MAP<uint64, bool>::iterator i = Stomach_Map.begin();

                        //Kick all players out of stomach
                        while (i != Stomach_Map.end())
                        {
                            //Check for valid player
                            Unit* unit = Unit::GetUnit(*me, i->first);

                            //Only move units in stomach
                            if (unit && i->second == true)
                            {
                                //Teleport each player out
                                DoTeleportPlayer(unit, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+10, float(rand()%6));

                                //Cast knockback on them
                                DoCast(unit, SPELL_EXIT_STOMACH_KNOCKBACK, true);

                                //Remove the acid debuff
                                unit->RemoveAurasDueToSpell(SPELL_DIGESTIVE_ACID);

                                i->second = false;
                            }
                            ++i;
                        }

                        return;
                    }

                    //Stomach acid
                    if (StomachAcidTimer <= diff)
                    {
                        //Apply aura to all players in stomach
                        UNORDERED_MAP<uint64, bool>::iterator i = Stomach_Map.begin();

                        while (i != Stomach_Map.end())
                        {
                            //Check for valid player
                            Unit* unit = Unit::GetUnit(*me, i->first);

                            //Only apply to units in stomach
                            if (unit && i->second == true)
                            {
                                //Cast digestive acid on them
                                DoCast(unit, SPELL_DIGESTIVE_ACID, true);

                                //Check if player should be kicked from stomach
                                if (unit->IsWithinDist3d(&KickPos, 15.0f))
                                {
                                    //Teleport each player out
                                    DoTeleportPlayer(unit, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+10, float(rand()%6));

                                    //Cast knockback on them
                                    DoCast(unit, SPELL_EXIT_STOMACH_KNOCKBACK, true);

                                    //Remove the acid debuff
                                    unit->RemoveAurasDueToSpell(SPELL_DIGESTIVE_ACID);

                                    i->second = false;
                                }
                            }
                            ++i;
                        }

                        StomachAcidTimer = 4000;
                    } else StomachAcidTimer -= diff;

                    //Stomach Enter Timer
                    if (StomachEnterTimer <= diff)
                    {
                        if (Unit* target = SelectRandomNotStomach())
                        {
                            //Set target in stomach
                            Stomach_Map[target->GetGUID()] = true;
                            target->InterruptNonMeleeSpells(false);
                            target->CastSpell(target, SPELL_MOUTH_TENTACLE, true, NULL, NULL, me->GetGUID());
                            StomachEnterTarget = target->GetGUID();
                            StomachEnterVisTimer = 3800;
                        }

                        StomachEnterTimer = 13800;
                    } else StomachEnterTimer -= diff;

                    if (StomachEnterVisTimer && StomachEnterTarget)
                    {
                        if (StomachEnterVisTimer <= diff)
                        {
                            //Check for valid player
                            Unit* unit = Unit::GetUnit(*me, StomachEnterTarget);

                            if (unit)
                            {
                                DoTeleportPlayer(unit, STOMACH_X, STOMACH_Y, STOMACH_Z, STOMACH_O);
                            }

                            StomachEnterTarget = 0;
                            StomachEnterVisTimer = 0;
                        } else StomachEnterVisTimer -= diff;
                    }

                    //GientClawTentacleTimer
                    if (GiantClawTentacleTimer <= diff)
                    {
                        if (Unit* target = SelectRandomNotStomach())
                        {
                            //Spawn claw tentacle on the random target
                            if (Creature* spawned = me->SummonCreature(NPC_GIANT_CLAW_TENTACLE, *target, TEMPSUMMON_CORPSE_DESPAWN, 500))
                                if (spawned->AI())
                                    spawned->AI()->AttackStart(target);
                        }

                        //One giant claw tentacle every minute
                        GiantClawTentacleTimer = 60000;
                    } else GiantClawTentacleTimer -= diff;

                    //GiantEyeTentacleTimer
                    if (GiantEyeTentacleTimer <= diff)
                    {
                        if (Unit* target = SelectRandomNotStomach())
                        {
                            //Spawn claw tentacle on the random target
                            if (Creature* spawned = me->SummonCreature(NPC_GIANT_EYE_TENTACLE, *target, TEMPSUMMON_CORPSE_DESPAWN, 500))
                                if (spawned->AI())
                                    spawned->AI()->AttackStart(target);
                        }

                        //One giant eye tentacle every minute
                        GiantEyeTentacleTimer = 60000;
                    } else GiantEyeTentacleTimer -= diff;

                    break;

                //Weakened state
                case PHASE_CTHUN_WEAK:
                    //PhaseTimer
                    if (PhaseTimer <= diff)
                    {
                        //Switch
                        instance->SetData(DATA_CTHUN_PHASE, PHASE_CTHUN_STOMACH);

                        //Remove purple coloration
                        me->RemoveAurasDueToSpell(SPELL_PURPLE_COLORATION);

                        //Spawn 2 flesh tentacles
                        FleshTentaclesKilled = 0;

                        //Spawn flesh tentacle
                        for (uint8 i = 0; i < 2; i++)
                        {
                            Creature* spawned = me->SummonCreature(NPC_FLESH_TENTACLE, FleshTentaclePos[i], TEMPSUMMON_CORPSE_DESPAWN);
                            if (!spawned)
                                ++FleshTentaclesKilled;
                        }

                        PhaseTimer = 0;
                    } else PhaseTimer -= diff;

                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_CTHUN_PHASE, PHASE_CTHUN_DONE);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            switch (instance->GetData(DATA_CTHUN_PHASE))
            {
                case PHASE_CTHUN_STOMACH:
                    //Not weakened so reduce damage by 99%
                    damage /= 100;
                    if (damage == 0)
                        damage = 1;

                    //Prevent death in non-weakened state
                    if (damage >= me->GetHealth())
                        damage = 0;

                    return;

                case PHASE_CTHUN_WEAK:
                    //Weakened - takes normal damage
                    return;

                default:
                    damage = 0;
                    break;
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
                case ACTION_FLESH_TENTACLE_KILLED:
                    ++FleshTentaclesKilled;
                    break;
            }
        }
    };

};

class npc_eye_tentacle : public CreatureScript
{
public:
    npc_eye_tentacle() : CreatureScript("npc_eye_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new eye_tentacleAI(creature);
    }

    struct eye_tentacleAI : public ScriptedAI
    {
        eye_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            MindflayTimer = 500;
            KillSelfTimer = 35000;

            Portal = 0;
            if (Creature* pPortal = me->SummonCreature(NPC_SMALL_PORTAL, *me, TEMPSUMMON_CORPSE_DESPAWN))
            {
                pPortal->SetReactState(REACT_PASSIVE);
                Portal = pPortal->GetGUID();
            }

            SetCombatMovement(false);
        }

        uint32 MindflayTimer;
        uint32 KillSelfTimer;
        uint64 Portal;

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit* p = Unit::GetUnit(*me, Portal))
                p->Kill(p);
        }

        void Reset() override
        {
            //Mind flay half a second after we spawn
            MindflayTimer = 500;

            //This prevents eyes from overlapping
            KillSelfTimer = 35000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
                return;

            //KillSelfTimer
            if (KillSelfTimer <= diff)
            {
                me->Kill(me);
                return;
            } else KillSelfTimer -= diff;

            //MindflayTimer
            if (MindflayTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (target && !target->HasAura(SPELL_DIGESTIVE_ACID))
                    DoCast(target, SPELL_MIND_FLAY);

                //Mindflay every 10 seconds
                MindflayTimer = 10000;
            } else MindflayTimer -= diff;
        }
    };

};

class npc_claw_tentacle : public CreatureScript
{
public:
    npc_claw_tentacle() : CreatureScript("npc_claw_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new claw_tentacleAI(creature);
    }

    struct claw_tentacleAI : public ScriptedAI
    {
        claw_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            GroundRuptureTimer = 500;
            HamstringTimer = 2000;
            EvadeTimer = 5000;

            SetCombatMovement(false);

            Portal = 0;
            if (Creature* pPortal = me->SummonCreature(NPC_SMALL_PORTAL, *me, TEMPSUMMON_CORPSE_DESPAWN))
            {
                pPortal->SetReactState(REACT_PASSIVE);
                Portal = pPortal->GetGUID();
            }
        }

        uint32 GroundRuptureTimer;
        uint32 HamstringTimer;
        uint32 EvadeTimer;
        uint64 Portal;

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit* p = Unit::GetUnit(*me, Portal))
                p->Kill(p);
        }

        void Reset() override
        {
            //First rupture should happen half a second after we spawn
            GroundRuptureTimer = 500;
            HamstringTimer = 2000;
            EvadeTimer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
                return;

            //EvadeTimer
            if (!me->IsWithinMeleeRange(me->GetVictim()))
            {
                if (EvadeTimer <= diff)
                {
                    if (Unit* p = Unit::GetUnit(*me, Portal))
                        p->Kill(p);

                    //Dissapear and reappear at new position
                    me->SetVisible(false);

                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (!target)
                    {
                        me->Kill(me);
                        return;
                    }

                    if (!target->HasAura(SPELL_DIGESTIVE_ACID))
                    {
                        me->SetPosition(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0);
                        if (Creature* pPortal = me->SummonCreature(NPC_SMALL_PORTAL, *me, TEMPSUMMON_CORPSE_DESPAWN))
                        {
                            pPortal->SetReactState(REACT_PASSIVE);
                            Portal = pPortal->GetGUID();
                        }

                        GroundRuptureTimer = 500;
                        HamstringTimer = 2000;
                        EvadeTimer = 5000;
                        AttackStart(target);
                    }

                    me->SetVisible(true);
                } else EvadeTimer -= diff;
            }

            //GroundRuptureTimer
            if (GroundRuptureTimer <= diff)
            {
                DoCastVictim(SPELL_GROUND_RUPTURE);
                GroundRuptureTimer = 30000;
            } else GroundRuptureTimer -= diff;

            //HamstringTimer
            if (HamstringTimer <= diff)
            {
                DoCastVictim(SPELL_HAMSTRING);
                HamstringTimer = 5000;
            } else HamstringTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_giant_claw_tentacle : public CreatureScript
{
public:
    npc_giant_claw_tentacle() : CreatureScript("npc_giant_claw_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new giant_claw_tentacleAI(creature);
    }

    struct giant_claw_tentacleAI : public ScriptedAI
    {
        giant_claw_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            GroundRuptureTimer = 500;
            HamstringTimer = 2000;
            ThrashTimer = 5000;
            EvadeTimer = 5000;

            SetCombatMovement(false);

            Portal = 0;
            if (Creature* pPortal = me->SummonCreature(NPC_GIANT_PORTAL, *me, TEMPSUMMON_CORPSE_DESPAWN))
            {
                pPortal->SetReactState(REACT_PASSIVE);
                Portal = pPortal->GetGUID();
            }
        }

        uint32 GroundRuptureTimer;
        uint32 ThrashTimer;
        uint32 HamstringTimer;
        uint32 EvadeTimer;
        uint64 Portal;

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit* p = Unit::GetUnit(*me, Portal))
                p->Kill(p);
        }

        void Reset() override
        {
            //First rupture should happen half a second after we spawn
            GroundRuptureTimer = 500;
            HamstringTimer = 2000;
            ThrashTimer = 5000;
            EvadeTimer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
                return;

            //EvadeTimer
            if (!me->IsWithinMeleeRange(me->GetVictim()))
            {
                if (EvadeTimer <= diff)
                {
                    if (Unit* p = Unit::GetUnit(*me, Portal))
                        p->Kill(p);

                    //Dissapear and reappear at new position
                    me->SetVisible(false);

                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (!target)
                    {
                        me->Kill(me);
                        return;
                    }

                    if (!target->HasAura(SPELL_DIGESTIVE_ACID))
                    {
                        me->SetPosition(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0);
                        if (Creature* pPortal = me->SummonCreature(NPC_GIANT_PORTAL, *me, TEMPSUMMON_CORPSE_DESPAWN))
                        {
                            pPortal->SetReactState(REACT_PASSIVE);
                            Portal = pPortal->GetGUID();
                        }

                        GroundRuptureTimer = 500;
                        HamstringTimer = 2000;
                        ThrashTimer = 5000;
                        EvadeTimer = 5000;
                        AttackStart(target);
                    }
                    me->SetVisible(true);
                } else EvadeTimer -= diff;
            }

            //GroundRuptureTimer
            if (GroundRuptureTimer <= diff)
            {
                DoCastVictim(SPELL_GROUND_RUPTURE);
                GroundRuptureTimer = 30000;
            } else GroundRuptureTimer -= diff;

            //ThrashTimer
            if (ThrashTimer <= diff)
            {
                DoCastVictim(SPELL_THRASH);
                ThrashTimer = 10000;
            } else ThrashTimer -= diff;

            //HamstringTimer
            if (HamstringTimer <= diff)
            {
                DoCastVictim(SPELL_HAMSTRING);
                HamstringTimer = 10000;
            } else HamstringTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_giant_eye_tentacle : public CreatureScript
{
public:
    npc_giant_eye_tentacle() : CreatureScript("npc_giant_eye_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new giant_eye_tentacleAI(creature);
    }

    struct giant_eye_tentacleAI : public ScriptedAI
    {
        giant_eye_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            BeamTimer = 500;

            SetCombatMovement(false);

            Portal = 0;
            if (Creature* pPortal = me->SummonCreature(NPC_GIANT_PORTAL, *me, TEMPSUMMON_CORPSE_DESPAWN))
            {
                pPortal->SetReactState(REACT_PASSIVE);
                Portal = pPortal->GetGUID();
            }
        }

        uint32 BeamTimer;
        uint64 Portal;

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit* p = Unit::GetUnit(*me, Portal))
                p->Kill(p);
        }

        void Reset() override
        {
            //Green Beam half a second after we spawn
            BeamTimer = 500;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff) override
        {
            //Check if we have a target
            if (!UpdateVictim())
                return;

            //BeamTimer
            if (BeamTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (target && !target->HasAura(SPELL_DIGESTIVE_ACID))
                    DoCast(target, SPELL_GREEN_BEAM);

                //Beam every 2 seconds
                BeamTimer = 2100;
            } else BeamTimer -= diff;
        }
    };

};

class npc_giant_flesh_tentacle : public CreatureScript
{
public:
    npc_giant_flesh_tentacle() : CreatureScript("npc_giant_flesh_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new flesh_tentacleAI(creature);
    }

    struct flesh_tentacleAI : public ScriptedAI
    {
        flesh_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (TempSummon* summon = me->ToTempSummon())
                if (Unit* summoner = summon->GetSummoner())
                    if (summoner->IsAIEnabled)
                        summoner->GetAI()->DoAction(ACTION_FLESH_TENTACLE_KILLED);
        }
    };

};

//GetAIs

void AddSC_boss_cthun()
{
    new boss_eye_of_cthun();
    new boss_cthun();
    new npc_eye_tentacle();
    new npc_claw_tentacle();
    new npc_giant_claw_tentacle();
    new npc_giant_eye_tentacle();
    new npc_giant_flesh_tentacle();
}
