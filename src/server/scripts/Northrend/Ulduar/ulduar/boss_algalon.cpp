/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "MapManager.h"
#include "ulduar.h"

#define MAXSTARS                        4
#define POINT_OUTRO                     1

enum Factions
{
    FACTION_NEUTRAL     =   15,
    FACTION_HOSTILE     =   16, //actually not needed - some spells won't hit the raid in neutral though.
    FACTION_FRIENDLY    =   35
};

enum Spells
{
    //Visuals
    SPELL_BLUE_BEAM                 = 63773,
    SPELL_ARRIVAL                   = 64997,
    SPELL_REORIGINATION             = 64996,
    SPELL_SUMMON_AZEROTH            = 64994,
    SPELL_HOVER_FALL                = 60425,
    SPELL_TELEPORT_VISUAL           = 62940,

    SPELL_BIG_BANG                  = 64443,
    SPELL_H_BIG_BANG                = 64584,
    SPELL_REMOVE_FROM_PHASE         = 64445,
    H_SPELL_BIG_BANG                = 64584,
    SPELL_COSMIC_SMASH              = 62301,
    H_SPELL_COSMIC_SMASH            = 64598,
    SPELL_COSMIC_SMASH_MISSLE       = 62304,
    SPELL_COSMIC_SMASH_DAMAGE       = 62311,
    SPELL_QUANTUM_STRIKE            = 64395,
    H_SPELL_QUANTUM_STRIKE          = 64592,
    //summons

    SPELL_ARCANE_BARAGE             = 64599,
    H_SPELL_ARCANE_BARAGE           = 64607,
    SPELL_COSMIC_SMASH_VISUAL       = 62300,
    SPELL_SUMMON_BLACK_HOLE         = 62189,
    SPELL_DESPAWN_BLACK_HOLE        = 64391,
    SPELL_BLACK_HOLE_EXPLOSION      = 64122,
    SPELL_BLACK_HOLE_AURA           = 62168,
    SPELL_BLACK_HOLE_DAMAGE         = 62169,
    SPELL_BLACK_HOLE_COSMETIC       = 64135,
    SPELL_BLACK_HOLE_TRIGGER        = 62185, //Buggy. Seems to reset the Black hole after it hits a player.
    SPELL_BLACK_HOLE_KILL_CREDIT    = 65312,
    SPELL_BLACK_HOLE_SPAWN_VISUAL   = 62003,
    SPELL_VISUAL_VOID_ZONE          = 64469,
    SPELL_UNLEASHED_DARK_MATTER     = 64450,

    SPELL_PHASE_PUNCH               = 64412,
    SPELL_PHASE_PUNCH_SHIFT         = 64417,
    SPELL_PHASE_PUNCH_ALPHA_1       = 64435, //Transparency effects for Phase Punch.
    SPELL_PHASE_PUNCH_ALPHA_2       = 64434,
    SPELL_PHASE_PUNCH_ALPHA_3       = 64428,
    SPELL_PHASE_PUNCH_ALPHA_4       = 64421,

    SPELL_ASCEND                    = 64487,
    SPELL_BERSERK                   = 64238,
    SPELL_I_DIED                    = 65082, //Must be related to an achievement.
    SPELL_KILL_CREDIT               = 65184
};

enum Creatures
{
    CREATURE_ALGALON                = 32871,
    CREATURE_COLLAPSING_STAR        = 32955,
    CREATURE_BLACK_HOLE             = 32953,
    CREATURE_LIVING_CONSTELLATION   = 33052,
    CREATURE_DARK_MATTER            = 33089,
    CREATURE_UNLEASHED_DARK_MATTER  = 34097,
    CREATURE_AZEROTH_MODEL          = 34246,
    CREATURE_ALGALON_STALKER        = 34004, //possibly used to keep algalon in combat? unused.
    CREATURE_ALGALON_ASTEROID_2     = 33105
};

enum ArchivementTimer
{
    ACHIEV_SUPERMASSIVE_START_EVENT = 21697
};

enum Texts
{   //Algalon
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_ENGAGED_FOR_FIRST_TIME                  = 2,
    SAY_SUMMON_COLLAPSING_STAR                  = 3,
    SAY_DEATH_1                                 = 4,
    SAY_DEATH_2                                 = 6,//Todo: Learn to count.
    SAY_DEATH_3                                 = 7,
    SAY_DEATH_4                                 = 8,
    SAY_DEATH_5                                 = 9,
    SAY_BERSERK                                 = 10,
    SAY_BIG_BANG                                = 11,
    SAY_PHASE_2                                 = 12,
    SAY_SUMMON_1                                = 13,
    SAY_SUMMON_2                                = 14,
    SAY_SUMMON_3                                = 15,
    SAY_TIMER_1                                 = 16,
    SAY_TIMER_2                                 = 17,
    SAY_TIMER_3                                 = 18,

    EMOTE_COLLAPSING_STARS                      = 19,
    EMOTE_COSMIC_SMASH                          = 20,
    EMOTE_BIG_BANG                              = 21,

    //Brann
    SAY_BRANN_INTRO                             = 0,
    SAY_BRANN_LEAVE                             = 1,
    SAY_BRANN_OUTRO                             = 2
};

enum Events
{

    EVENT_RESTART_ATTACKING = 1,
    EVENT_REMOVE_FROM_PHASE,
    EVENT_BIG_BANG,
    EVENT_BERSERK,
    EVENT_COSMIC_SMASH,
    EVENT_COLLAPSING_STAR,
    EVENT_PHASE_PUNCH,
    EVENT_SUMMON_CONSTELLATION,
    EVENT_SUMMON_UNLEASHED_DARK_MATTER,
    EVENT_QUANTUM_STRIKE,
};

enum Phase
{
    PHASE_INTRO,
    PHASE_1,
    PHASE_2
};

enum Actions
{
    ACTION_ALGALON_INTRO            = -123456,
    ACTION_BRANN_INTRO              = -123457,
    ACTION_BRANN_LEAVE              = -123458,
    ACTION_BLACKHOLE_SUMMON         = -123459,
    ACTION_ACTIVATE_CONSTELLATION   = -123455
};

enum Music
{
    MUSIC_INTRO         = 15878,
    MUSIC_BATTLE        = 15877 
};
static const float GroundZ = 417.321198f;

static const float RoomCenter[3] = {1632.050049f, -307.36499f, GroundZ};

static const float OutroPos[3] = {1632.050049f, -319.36499f, GroundZ};

static const float BrannOutro[3] = {1632.050049f, -294.36499f, GroundZ};

//Brann
float WPs_ulduar[9][3] =
{
    //pos_x             pos_y       pos_z
    {1661.567261f, -155.395126f, 427.261810f},
    {1633.316650f, -176.056778f, 427.286011f},
    {1633.187744f, -190.987228f, 427.378632f},
    {1632.005371f, -214.134232f, 418.470459f},
    {1631.882324f, -228.378708f, 418.082733f},
    {1634.257446f, -230.407898f, 417.336182f},
    {1635.767700f, -266.664459f, 417.321991f},
    {1630.990845f, -266.863434f, 417.321991f},
    {1632.005371f, -214.134232f, 418.470459f}
};

/*Todo:
-Correct Summon Positions for Collapsing stars and living constellations.
-Achievements.
-sniff info for better timers /positions / model radius / waypoints.
-Music: I suppose there is a way that involves using ZoneMusic.dbc since it has both music entires, but i don't know how to use them.
-Increase Monster Say Radius.
-Find better way to make him stop his attacks without evading - code works but could look better.
-heroic (25 players) support.
-???
*/

class boss_algalon : public CreatureScript
{
    public:
        boss_algalon() : CreatureScript("boss_algalon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_algalonAI(pCreature);
        }

        struct boss_algalonAI : public BossAI
        {
            boss_algalonAI(Creature *pCreature) : BossAI(pCreature, TYPE_ALGALON), summons(pCreature) {}

            uint32 Phase;
            uint32 uiPhase_timer;
            uint32 uiStep;
            uint8 staramount;
            SummonList summons;

            bool intro;
            bool fightintro;
            bool sendreplycode;
            bool outro;
            bool respawning;

            void InitializeAI()
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); //deathgrip

                const CreatureTemplate *cinfo = me->GetCreatureInfo(); //todo: remove this block once the core correctly calculates offhand damages on its own.
                float mindmg = cinfo->mindmg * cinfo->dmg_multiplier /2;
                float maxdmg = cinfo->maxdmg * cinfo->dmg_multiplier /2;
                me->SetBaseWeaponDamage(OFF_ATTACK, MINDAMAGE, mindmg);
                me->SetBaseWeaponDamage(OFF_ATTACK, MAXDAMAGE, maxdmg);
                me->SetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, mindmg);
                me->SetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, maxdmg);
                me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10); //DB Stuff, requires sniff.
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);

                Reset();
            }

            void EnterCombat(Unit* who)
            {
                if (Phase == PHASE_INTRO && instance->GetBossState(TYPE_ALGALON) == NOT_STARTED)
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
                    uiStep = 0;
                    fightintro = true;
                    return;
                }
            }

            void KilledUnit(Unit * victim)
            {
                if (!Phase == PHASE_INTRO)
                    Talk(SAY_SLAY);
            }

            void DoAction(const int32 actionId)
            {
                switch(actionId)
                {
                case ACTION_ALGALON_INTRO:
                    StartIntro(7000);
                    break;
                case ACTION_ALGALON_ASCEND:
                    respawning = false;
                    uiStep = 0;
                    uiPhase_timer = 0;
                    Phase = PHASE_INTRO;
                    summons.DespawnAll();
                    sendreplycode = true;

                    me->InterruptNonMeleeSpells(false);
                    me->SetReactState(REACT_PASSIVE);
                    break;
                }
            }

            void Reset()
            {   
                intro = false;
                fightintro = false;
                sendreplycode = false;
                outro = false;
                respawning = false;

                staramount = 0;

                _Reset();
                summons.DespawnAll();
                SetCombatMovement(false);
                Phase = PHASE_INTRO;
                if (instance)
                    instance->SetData(TYPE_ALGALON, NOT_STARTED);

                me->setFaction(FACTION_NEUTRAL);
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->SendMovementFlagUpdate();
                me->SetVisible(false);
                me->SetSheath(SHEATH_STATE_UNARMED);
                me->SetHealth(me->GetMaxHealth()); //needed, since he doesn't normally regenerate life (set in DB)

                events.ScheduleEvent(EVENT_BERSERK, 6 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BIG_BANG, 90000);
                events.ScheduleEvent(EVENT_COSMIC_SMASH, 25000);
                events.ScheduleEvent(EVENT_PHASE_PUNCH, 16000);
                events.ScheduleEvent(EVENT_QUANTUM_STRIKE, urand(4000,8000));
                events.ScheduleEvent(EVENT_COLLAPSING_STAR, 15000, PHASE_1);
                events.ScheduleEvent(EVENT_SUMMON_CONSTELLATION, 50000, PHASE_1); 
                events.CancelEvent(EVENT_REMOVE_FROM_PHASE);
                events.CancelEvent(EVENT_SUMMON_UNLEASHED_DARK_MATTER);
                events.CancelEvent(EVENT_RESTART_ATTACKING);

                if (instance->GetData(DATA_ALGALON_INTRO) == IN_PROGRESS && instance->GetData(DATA_ALGALON_TIMER) != FAIL)
                    StartIntro(20000); // respawn in 20 Seconds.
            }

            void DamageTaken(Unit * /*who*/, uint32 &Damage)
            {
                if(Damage > me->GetHealth())
                    Damage = me->GetHealth() - 1;

            }
            void JumpToNextStep(uint32 uiTimer)
            {
                uiPhase_timer = uiTimer;
                ++uiStep;
            }

            void JustSummoned(Creature* Summon)
            {
                summons.Summon(Summon);
                Summon->setFaction(me->getFaction());

                switch(Summon->GetEntry())
                {
                case CREATURE_AZEROTH_MODEL:
                    Summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PASSIVE);
                    break;
                case CREATURE_BLACK_HOLE:
                    --staramount;
                    Summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    //Summon->AddAura(SPELL_BLACK_HOLE_TRIGGER, Summon); Too buggy.
                    Summon->AddAura(SPELL_VISUAL_VOID_ZONE, Summon);
                    //Summon->AddAura(SPELL_BLACK_HOLE_COSMETIC, Summon);
                    Summon->SetReactState(REACT_PASSIVE);
                case CREATURE_COLLAPSING_STAR:
                    Summon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, me->GetGUID());
                    break;
                case CREATURE_UNLEASHED_DARK_MATTER:
                    Summon->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    Summon->SetInCombatWithZone();
                    if (Unit* Target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        Summon->AI()->AttackStart(Target);
                    break;
                }
            }

            void SummonCollapsingStars()
            {
                if (staramount == MAXSTARS)
                    return;

                Talk(SAY_SUMMON_COLLAPSING_STAR);
                Talk(EMOTE_COLLAPSING_STARS);
                Position pos;
                for (uint8 i = MAXSTARS - staramount; i>0; --i)
                {
                    pos.Relocate(RoomCenter[0], RoomCenter[1], RoomCenter[2]);
                    //pos.m_positionX += urand(15,20) * cos(static_cast<float>(2*M_PI) * float(i/4));
                    //pos.m_positionY += urand(15,20) * sin(static_cast<float>(2*M_PI) * float(i/4));
                    me->MovePosition(pos, 20, cos(static_cast<float>(2.0f*M_PI*(float)i/4.0f)));
                    if (me->SummonCreature(CREATURE_COLLAPSING_STAR, pos, TEMPSUMMON_CORPSE_DESPAWN))
                        ++staramount;

                }

            }

            void SummonLivingConstellations()
            {
                summons.DoAction(CREATURE_LIVING_CONSTELLATION, ACTION_ACTIVATE_CONSTELLATION);
            }

            void PopulateBlackHoles()
            {   
                Position pos;
                for (uint8 i = 1; i<= 8; ++i)
                {
                    me->GetNearPosition(pos, urand(15,35), (float)rand_norm() * static_cast<float>(2 * M_PI));
                    DoSummon(CREATURE_DARK_MATTER,pos,1000);
                }
            }

            void SummonConstellationsInitial()
            {
                Position pos;
                float z;
                uint8 amount =  3;
                pos.m_orientation = 0;
                for (uint32 i = 1; i<=amount; ++i)
                {
                    z = urand(20, 35);
                    pos.Relocate(RoomCenter[0], RoomCenter[1], RoomCenter[2]);
                    pos.m_positionX += 40 * cos((float)rand_norm() * static_cast<float>(2*M_PI));
                    pos.m_positionY += 40 * sin((float)rand_norm() * static_cast<float>(2*M_PI));
                    pos.m_positionZ += z;
                    me->SummonCreature(CREATURE_LIVING_CONSTELLATION, pos, TEMPSUMMON_CORPSE_DESPAWN);
                }

            }

            void StartIntro(uint32 timer = 0)
            {
                uiPhase_timer = timer;
                uiStep = 0;
                intro = true;
                Phase = PHASE_INTRO;
                me->SetOrientation(me->GetHomePosition().GetOrientation());
                me->SendMovementFlagUpdate();
            }

            void SetEncounterMusic(uint32 MusicID) //wrong. I'm almost certain it has to do with zonemusic.dbc...
            {
                WorldPacket data(SMSG_PLAY_MUSIC, 4);
                data << uint32(MusicID);
                instance->instance->SendToPlayers(&data);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch(id)
                {
                case POINT_OUTRO:
                    outro = true;
                    me->SetOrientation(me->GetHomePosition().GetOrientation());
                    uiPhase_timer = 14000;
                    me->SendMovementFlagUpdate();
                    instance->SetBossState(TYPE_ALGALON, DONE);
                    break;
                }
            }

            void DoMeleeAttacksIfReady() // we need this function because DoMeleeAttackIfReady causes the mob to hit with both weapons at the same time (not blizzlike)
            {
                if (me->IsWithinMeleeRange(me->getVictim()) && !me->IsNonMeleeSpellCasted(false))
                {
                    if (me->isAttackReady() && me->getVictim())
                    {
                        me->AttackerStateUpdate(me->getVictim());
                        me->resetAttackTimer();
                        me->setAttackTimer(OFF_ATTACK, me->getAttackTimer(BASE_ATTACK)/2);
                    }

                    if (me->isAttackReady(OFF_ATTACK) && me->getVictim())
                    {
                        me->AttackerStateUpdate(me->getVictim(), OFF_ATTACK);
                        me->resetAttackTimer(OFF_ATTACK);
                    }
                }
            }

            void HandleTalkingSequences()
            {
                if (intro)
                {
                    switch(uiStep)
                    {
                    case 0:
                        me->AddAura(SPELL_HOVER_FALL, me);
                        me->SetVisible(true);
                        me->SetFlag(UNIT_FIELD_FLAGS,  UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
                        float x,y;
                        me->GetPosition(x,y);
                        me->GetMotionMaster()->MoveCharge(x,y,GroundZ,me->GetSpeed(MOVE_FLIGHT), 0);
                        DoCast(me,SPELL_ARRIVAL,true);
                        DoCast(me,SPELL_BLUE_BEAM,true);
                        me->SetReactState(REACT_PASSIVE);
                        JumpToNextStep(3500);
                        break;
                    case 1:
                        me->RemoveAurasDueToSpell(SPELL_BLUE_BEAM);
                        Talk(SAY_SUMMON_1);
                        JumpToNextStep(7000);
                        break;
                    case 2:
                        me->m_positionZ = GroundZ;
                        me->SetOrientation(me->GetHomePosition().GetOrientation());
                        DoCast(SPELL_SUMMON_AZEROTH);
                        JumpToNextStep(5000);
                        break;
                    case 3:
                        Talk(SAY_SUMMON_2);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SendMovementFlagUpdate();
                        DoCastAOE(SPELL_REORIGINATION);
                        JumpToNextStep(8000);
                        break;
                    case 4:
                        Talk(SAY_SUMMON_3);
                        JumpToNextStep(12000);
                        break;
                    case 5:
                        if (Creature* Brann = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_BRANN_ALGALON)))
                            Brann->AI()->DoAction(ACTION_BRANN_LEAVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS,  UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
                        intro = false;
                        break;
                    }
                }
                else if (fightintro)
                {
                    switch(uiStep)
                    {
                    case 0:
                        me->SetReactState(REACT_PASSIVE);
                        Talk(SAY_AGGRO);
                        me->RemoveAllAuras();
                        me->DeleteThreatList();
                        me->CombatStop(true);
                        me->StopMoving();
                        me->SetOrientation(me->GetHomePosition().GetOrientation());
                        me->SendMovementFlagUpdate();

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveIdle();

                        summons.DespawnAll();

                        JumpToNextStep(1000);
                    case 1:
                        if (instance->GetData(DATA_ALGALON_INTRO) == IN_PROGRESS)
                        {
                            uiStep = 12;
                            uiPhase_timer = 2000;
                        }
                        else
                            JumpToNextStep(14000);
                        break;
                    case 2:
                        Talk(SAY_ENGAGED_FOR_FIRST_TIME);
                        instance->SetBossState(TYPE_ALGALON, IN_PROGRESS); //also changes room at this point.
                        JumpToNextStep(11000);
                        break;
                    case 3:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED );
                        Phase = PHASE_1;
                        fightintro = false;
                        me->SetInCombatWithZone();
                        if (Unit* Target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            AttackStart(Target);

                        me->setFaction(FACTION_HOSTILE);
                        SetEncounterMusic(MUSIC_BATTLE);
                        instance->SetData(DATA_ALGALON_INTRO,1); //First Intro Done
                        instance->SetData(DATA_ALGALON_TIMER,IN_PROGRESS);
                        PopulateBlackHoles();
                        SummonConstellationsInitial();
                        SetCombatMovement(true);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case 12: //Second Intro
                        instance->SetBossState(TYPE_ALGALON, IN_PROGRESS);
                        JumpToNextStep(6000);
                        break;
                    case 13:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
                        Phase = PHASE_1;
                        fightintro = false;
                        me->setFaction(FACTION_HOSTILE);
                        me->SetInCombatWithZone();
                        SetEncounterMusic(MUSIC_BATTLE);
                        PopulateBlackHoles();
                        SummonConstellationsInitial();
                        SetCombatMovement(true);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    }
                }
                else if (respawning)
                {
                    switch(uiStep)
                    {
                    case 0:
                        me->GetMotionMaster()->Clear(false);
                        me->GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACK_HOLE_AURA); //hack. Ascend to the heavens should hit players who are in black holes.
                        JumpToNextStep(500);
                        break;
                    case 1:
                        DoCastAOE(SPELL_ASCEND);
                        JumpToNextStep(3000);
                        break;
                    case 2:
                        me->SetVisible(false);
                        ScriptedAI::EnterEvadeMode();
                        respawning = false;
                        break;
                    }
                }
                else if (outro)
                {
                    switch(uiStep)
                    {
                    case 0:
                        me->SetSpeed(MOVE_WALK, 2.0f);
                        me->GetMotionMaster()->MovePoint(POINT_OUTRO,OutroPos[0], OutroPos[1], OutroPos[2]); 
                        ++uiStep;
                        outro = false; //will be set true once he reaches his outro point.
                        break;
                    case 1:
                        Talk(SAY_DEATH_1);
                        DoCastAOE(SPELL_KILL_CREDIT, true);
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        JumpToNextStep(40000);
                        break;
                    case 2:
                        Talk(SAY_DEATH_2); //he sometimes stands up here. I wonder why.
                        JumpToNextStep(18000);
                        break;
                    case 3:
                        Talk(SAY_DEATH_3);
                        JumpToNextStep(11000);
                        break;
                    case 4:
                        Talk(SAY_DEATH_4);
                        JumpToNextStep(12000);
                        break;
                    case 5:
                        if (Creature* Brann = me->SummonCreature(NPC_BRANN_ALGALON, BrannOutro[0], BrannOutro[1], BrannOutro[2]))
                        {
                            Brann->AI()->Talk(SAY_BRANN_OUTRO);
                            Brann->SetFacingToObject(me);
                            Brann->DespawnOrUnsummon(30000);
                        }
                        JumpToNextStep(7000);
                        break;
                    case 6:
                        Talk(SAY_DEATH_5);
                        JumpToNextStep(15000);
                        break;
                    case 7:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        DoCast(SPELL_TELEPORT_VISUAL);
                        me->DespawnOrUnsummon(2000);
                        outro = false;
                        break;
                    }
                }
                else if (sendreplycode)
                {
                    switch(uiStep)
                    {
                    case 0:
                        me->RemoveAllAuras();
                        me->DeleteThreatList();
                        me->CombatStop(true);
                        me->SetLootRecipient(NULL);
                        me->ResetPlayerDamageReq();
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        JumpToNextStep(1000);
                        break;
                    case 1:
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        JumpToNextStep(1000);
                        break;
                    case 2:
                        Talk(SAY_TIMER_1);
                        JumpToNextStep(15000);
                        break;
                    case 3:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        Talk(SAY_TIMER_2);
                        JumpToNextStep(10000);
                        break;
                    case 4:
                        DoCastAOE(SPELL_ASCEND);
                        Talk(SAY_TIMER_3);
                        JumpToNextStep(10000);
                        break;
                    case 5:
                        DoCast(SPELL_TELEPORT_VISUAL);
                        me->DespawnOrUnsummon(2000);
                        sendreplycode = false;
                        break;
                    }

                }

            }

            void UpdateAI(const uint32 diff)
            {
                if (Phase == PHASE_INTRO)
                {
                    if (uiPhase_timer <= diff)
                        HandleTalkingSequences();
                    else
                        uiPhase_timer -= diff;
                    return;
                }

                if (Phase < PHASE_1 )
                    return;

                if (!CheckInRoom())
                    return;

                if (me->getThreatManager().isThreatListEmpty()) // this replaces updatevictim(), since he casts ascend to the heavens to wipe the raid instead of just respawning.
                {
                    respawning = true;
                    me->InterruptNonMeleeSpells(false);
                    uiStep = 0;
                    Phase = PHASE_INTRO;
                }
                else if (Unit *victim = me->SelectVictim())
                    AttackStart(victim);

                if (Phase == PHASE_1 && HealthBelowPct(20))
                {
                    Phase = PHASE_2;
                    Talk(SAY_PHASE_2);
                    summons.DespawnEntry(CREATURE_BLACK_HOLE);
                    summons.DespawnEntry(CREATURE_LIVING_CONSTELLATION);
                    summons.DespawnEntry(CREATURE_COLLAPSING_STAR);
                    events.CancelEventsByGCD(PHASE_1);
                    Position pos;

                    for (uint8 i = 1; i <= 4; ++i) //Summoning the black Holes.
                    {
                        pos.Relocate(RoomCenter[0], RoomCenter[1], RoomCenter[2]);
                        pos.m_orientation =  MapManager::NormalizeOrientation(2*M_PI*i/4 + M_PI/3); 
                        pos.m_positionX += 20 * cos(pos.GetOrientation());
                        pos.m_positionY += 20 * sin(pos.GetOrientation());
                        DoSummon(CREATURE_BLACK_HOLE, pos, 0);
                    }
                    events.ScheduleEvent(EVENT_SUMMON_UNLEASHED_DARK_MATTER, 1500);
                }

                if (Phase == PHASE_2 && HealthBelowPct(3))
                {
                    Phase = PHASE_INTRO;
                    summons.DespawnAll();
                    instance->SetData(DATA_ALGALON_TIMER, DONE);

                    me->DeleteThreatList();
                    me->CombatStop(true);
                    me->StopMoving();
                    me->SetOrientation(me->GetHomePosition().GetOrientation());
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    me->SendMovementFlagUpdate();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    me->setFaction(FACTION_FRIENDLY);
                    me->SummonGameObject(GO_GIFT_OF_THE_OBSERVER, RoomCenter[0], RoomCenter[1], RoomCenter[2], M_PI/2,0,0,0,0,me->GetRespawnTime()); //should be DB spawned and then used via Respawn by the Instance script.

                    outro = true;
                    uiStep = 0;
                    uiPhase_timer = 9000;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                    switch (events.GetEvent())
                    {
                    case 0:
                        break;
                    case EVENT_RESTART_ATTACKING:
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.CancelEvent(EVENT_RESTART_ATTACKING);
                        break;
                    case EVENT_BIG_BANG:
                        Talk(SAY_BIG_BANG);
                        Talk(EMOTE_BIG_BANG);
                        DoCastAOE(RAID_MODE(SPELL_BIG_BANG,H_SPELL_BIG_BANG));
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        events.ScheduleEvent(EVENT_RESTART_ATTACKING, 15000);
                        events.RescheduleEvent(EVENT_QUANTUM_STRIKE, 16000);
                        events.ScheduleEvent(EVENT_REMOVE_FROM_PHASE, 9000);
                        events.RepeatEvent(90000);
                        break;
                    case EVENT_REMOVE_FROM_PHASE:
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACK_HOLE_AURA);
                        events.CancelEvent(EVENT_REMOVE_FROM_PHASE);
                        break;
                    case EVENT_PHASE_PUNCH:
                        DoCast(me->getVictim(), SPELL_PHASE_PUNCH);
                        events.RepeatEvent(16000);
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        Talk(SAY_BERSERK);
                        events.CancelEvent(EVENT_BERSERK);
                        break;
                    case EVENT_COSMIC_SMASH:
                        DoCast(RAID_MODE(SPELL_COSMIC_SMASH,H_SPELL_COSMIC_SMASH));
                        Talk(EMOTE_COSMIC_SMASH);
                        events.RepeatEvent(urand(25000,30000));
                        break;
                    case EVENT_QUANTUM_STRIKE:
                        DoCast(me->getVictim(), RAID_MODE(SPELL_QUANTUM_STRIKE,H_SPELL_QUANTUM_STRIKE));
                        events.RepeatEvent(urand(4000, 8000));
                        break;
                    case EVENT_COLLAPSING_STAR:
                        SummonCollapsingStars();
                        events.RepeatEvent(50000);
                        break;
                    case EVENT_SUMMON_CONSTELLATION:
                        SummonLivingConstellations();
                        SummonConstellationsInitial();
                        events.RepeatEvent(50000);
                        break;
                    case EVENT_SUMMON_UNLEASHED_DARK_MATTER:
                        summons.DoAction(CREATURE_BLACK_HOLE, ACTION_BLACKHOLE_SUMMON);
                        events.RepeatEvent(30000);
                        break;
                    default:
                        events.PopEvent();
                        break;
                    }

                    if(me->GetReactState() != REACT_PASSIVE)
                        DoMeleeAttacksIfReady();
            }
        };
};

class mob_collapsing_star : public CreatureScript
{
    public:
        mob_collapsing_star() : CreatureScript("mob_collapsing_star") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_collapsing_starAI(pCreature);
        }

        struct mob_collapsing_starAI : public PassiveAI
        {
            mob_collapsing_starAI(Creature *pCreature) : PassiveAI(pCreature) {}

            bool exploded;
            uint32 Timer;
            uint32 Damage;

            void Reset()
            {
                Timer = 1000;
                exploded = false;
                Damage = me->GetMaxHealth()/100;
                me->GetMotionMaster()->MoveRandom(15.0f);
            }
            void DamageTaken(Unit * /*Who*/, uint32 &Damage)
            {
                if(Damage > me->GetHealth())
                {
                    Damage = me->GetHealth() - 1;
                    Explode();
                }
            }

            void Explode()
            {
                if (exploded)
                    return;

                exploded = true;
                Timer = 1500;
                Position pos;

                me->RemoveAllAuras();
                me->GetPosition(&pos);
                if (me->GetOwnerGUID())
                    me->GetOwner()->SummonCreature(CREATURE_BLACK_HOLE, pos);

                DoCastAOE(SPELL_BLACK_HOLE_EXPLOSION, true);
                DoCastAOE(SPELL_BLACK_HOLE_SPAWN_VISUAL, true);
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveIdle();
                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (Timer <= diff)
                    {
                        if (Damage < me->GetHealth())
                            me->DealDamage(me, Damage, NULL, SELF_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL);
                        else
                            Explode();

                        Timer = 1000;
                }
                else Timer -= diff;
            }
        };
};

class mob_black_hole : public CreatureScript
{
    public:
        mob_black_hole() : CreatureScript("mob_black_hole") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_black_holeAI(pCreature);
        }

        struct mob_black_holeAI : public ScriptedAI
        {
            mob_black_holeAI(Creature *pCreature) : ScriptedAI(pCreature) {}

            uint32 ShiftTimer;

            void Reset()
            {
                ShiftTimer = 1000;
            }

            void DoAction(const int32 ID)
            {
                if (ID == ACTION_BLACKHOLE_SUMMON)
                    me->CastSpell(me,SPELL_UNLEASHED_DARK_MATTER, false, 0, 0, me->GetOwnerGUID());
            }

            void UpdateAI(const uint32 diff)
            {
                if (ShiftTimer <= diff)
                {
                    std::list<Player*> players;
                    Trinity::AnyPlayerInObjectRangeCheck checker(me, 5.0f);
                    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                    me->VisitNearbyWorldObject(5.0f, searcher);

                    for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (!(*itr)->HasAura(SPELL_BLACK_HOLE_AURA))
                            (*itr)->AddAura(SPELL_BLACK_HOLE_AURA, (*itr));
                    }
                    ShiftTimer = 1000;

                }
                else ShiftTimer -= diff;
            }

        };
};

class mob_living_constellation : public CreatureScript
{
    public:
        mob_living_constellation() : CreatureScript("mob_living_constellation") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_living_constellationAI(pCreature);
        }

        struct mob_living_constellationAI : public ScriptedAI
        {
            mob_living_constellationAI(Creature *pCreature) : ScriptedAI(pCreature) {}

            uint32 Arcane_Timer;
            bool active;

            void InitializeAI()
            {
                active = false;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PASSIVE);
                me->SetFlying(true);
                me->SendMovementFlagUpdate();
                me->SetReactState(REACT_PASSIVE);
                me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 6);
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 6);
                Reset();
            }

            void Reset()
            {
                Arcane_Timer = urand(4000, 5000);
            }

            void DoAction(const int32 ActionID)
            {
                switch(ActionID)
                {
                case ACTION_ACTIVATE_CONSTELLATION:
                    active = true;
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE |  UNIT_FLAG_PASSIVE);
                    DoZoneInCombat();
                    if (Unit* Target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        AttackStart(Target);

                    break;
                }
            }
            void UpdateAI(const uint32 diff)
            {
                if (!active)
                    return;

                if (!UpdateVictim())
                    return;

                if (me->getVictim()->GetTypeId() != TYPEID_PLAYER)
                    me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);
                    

                if (Creature* BH = me->FindNearestCreature(CREATURE_BLACK_HOLE, 0.1f, true))
                {
                    me->DespawnOrUnsummon();
                    BH->DespawnOrUnsummon();

                }
                if (Arcane_Timer <= diff)
                {
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true), RAID_MODE(SPELL_ARCANE_BARAGE, H_SPELL_ARCANE_BARAGE),true);
                    Arcane_Timer = urand(4000,6000);
                }
                else Arcane_Timer -= diff;
            }
        };
};

class mob_dark_matter_algalon : public CreatureScript
{
    public:
        mob_dark_matter_algalon() : CreatureScript("mob_dark_matter_algalon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_dark_matter_algalonAI(pCreature);
        }

        struct mob_dark_matter_algalonAI : public ScriptedAI
        {
            mob_dark_matter_algalonAI(Creature *pCreature) : ScriptedAI(pCreature) {}


            void InitializeAI()
            {
                me->SetPhaseMask(16, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                Reset();
            }

            void Reset()
            {
                me->GetMotionMaster()->MoveRandom(60);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->getVictim()->GetPhaseMask() != 16)
                    EnterEvadeMode();

                DoMeleeAttackIfReady();
            }

        };
};

class mob_algalon_asteroid_trigger : public CreatureScript
{
    public:
        mob_algalon_asteroid_trigger() : CreatureScript("mob_algalon_asteroid_trigger") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_algalon_asteroid_triggerAI(pCreature);
        }

        struct mob_algalon_asteroid_triggerAI : public PassiveAI
        {
            mob_algalon_asteroid_triggerAI(Creature *pCreature) : PassiveAI(pCreature) {}

            uint32 Event_Timer;
            uint8 Event_Phase;

            void Reset()
            {
                Event_Timer = 3500;
                Event_Phase = 1;
            }

            void UpdateAI(const uint32 diff)
            {
                if (Event_Timer <= diff)
                {
                    if (Event_Phase == 1)
                    {
                        if (Creature* Stalker = me->FindNearestCreature(CREATURE_ALGALON_ASTEROID_2, 45))
                            Stalker->CastSpell(me,SPELL_COSMIC_SMASH_MISSLE,true);
                        Event_Timer = 500;  
                        ++Event_Phase;
                    }
                    else
                    {
                        me->AddAura(SPELL_COSMIC_SMASH_VISUAL,me);
                        Event_Timer = 10000000;
                    }
                }
                else Event_Timer -= diff;
            }
        };
};

class mob_brann_algalon : public CreatureScript
{
    public:
        mob_brann_algalon() : CreatureScript("mob_brann_algalon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_brann_algalonAI(pCreature);
        }

        struct mob_brann_algalonAI : public PassiveAI
        {
            mob_brann_algalonAI(Creature *pCreature) : PassiveAI(pCreature) {}

            uint8 CurrWP;
            uint32 delay;
            //maybe i should convert him to escortAI?

            bool ContinueWP;
            bool leaving;
            bool outro;

            void Reset()
            {
                CurrWP = 0;
                ContinueWP = false;
                delay = 0;

                me->SetReactState(REACT_PASSIVE);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            }

            void DoAction(const int32 ActionID)
            {
                switch(ActionID)
                {
                case ACTION_BRANN_INTRO:
                    CurrWP = 0;
                    ContinueWP = true;
                    delay = 0;
                    break;
                case ACTION_BRANN_LEAVE:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    Talk(SAY_BRANN_LEAVE);
                    CurrWP = 8;
                    ContinueWP = true;
                    delay = 0;
                    break;
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;
                switch(id)
                {
                case 1: //standing at the door
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    delay = 8000;
                    break;
                case 7: //at the summon Point
                    if (Creature* Algalon =  ObjectAccessor::GetCreature(*me, me->GetInstanceScript()->GetData64(TYPE_ALGALON)))
                        Algalon->AI()->DoAction(ACTION_ALGALON_INTRO);
                    Talk(SAY_BRANN_INTRO);

                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();
                    return;
                case 8: //despawn point
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();
                    me->DespawnOrUnsummon();
                    return;
                }

                ++CurrWP;
                ContinueWP = true;
            }

            void UpdateAI(const uint32 diff)
            {
                if (delay <= diff)
                {
                    if (ContinueWP)
                    {
                        me->GetMotionMaster()->MovePoint(CurrWP, WPs_ulduar[CurrWP][0], WPs_ulduar[CurrWP][1], WPs_ulduar[CurrWP][2]);
                        ContinueWP = false;
                    }
                }
                else delay -= diff;
            }

        };
};

class spell_algalon_phase_punch : public SpellScriptLoader
{
    public:
        spell_algalon_phase_punch() : SpellScriptLoader("spell_algalon_phase_punch") { }

        class spell_algalon_phase_punch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_algalon_phase_punch_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                Unit* target = GetTarget();
                if(!caster || !target)
                    return;

                switch (target->GetAuraCount(aurEff->GetId()))
                {
                case 1:
                    caster->AddAura(SPELL_PHASE_PUNCH_ALPHA_1,target);
                    break;
                case 2:
                    caster->AddAura(SPELL_PHASE_PUNCH_ALPHA_2,target);
                    break;
                case 3:
                    caster->AddAura(SPELL_PHASE_PUNCH_ALPHA_3,target);
                    break;
                case 4:
                    caster->AddAura(SPELL_PHASE_PUNCH_ALPHA_4,target);
                    break;
                case 5:
                    target->RemoveAurasDueToSpell(aurEff->GetId());
                    //caster->CastSpell(target, SPELL_PHASE_PUNCH_SHIFT, true);
                    caster->AddAura(SPELL_PHASE_PUNCH_SHIFT, target);
                    target->CombatStop();
                    caster->getThreatManager().modifyThreatPercent(target, -100);
                    target->getHostileRefManager().deleteReferences();
                    target->UpdateObjectVisibility();
                    break;
                }
            }
            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if(target)
                {
                    target->RemoveAurasDueToSpell(SPELL_PHASE_PUNCH_ALPHA_1);
                    target->RemoveAurasDueToSpell(SPELL_PHASE_PUNCH_ALPHA_2);
                    target->RemoveAurasDueToSpell(SPELL_PHASE_PUNCH_ALPHA_3);
                    target->RemoveAurasDueToSpell(SPELL_PHASE_PUNCH_ALPHA_4);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_algalon_phase_punch_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                OnEffectRemove += AuraEffectRemoveFn(spell_algalon_phase_punch_AuraScript::OnRemove, EFFECT_0,SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_algalon_phase_punch_AuraScript();
        };
};

class go_celestial_console : public GameObjectScript
{
    public:
        go_celestial_console()
            : GameObjectScript("go_celestial_console")
        {
        }

        bool OnGossipHello(Player* player, GameObject* go)
        {
			InstanceScript* _instance = go->GetInstanceScript();

			uint32 item = uint32(go->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? 45796 : 45798);
			if (player->HasItemCount(item, 1))
			{
				if (Creature* Brann = go->SummonCreature(NPC_BRANN_ALGALON, WPs_ulduar[0][0],WPs_ulduar[0][1], WPs_ulduar[0][2])) 
				{
					go->SetFlag(GAMEOBJECT_FLAGS,  GO_FLAG_UNK1);
					Brann->AI()->DoAction(ACTION_BRANN_INTRO);
					if (GameObject* Door = ObjectAccessor::GetGameObject(*go, go->GetInstanceScript()->GetData64((GO_ALGALON_DOOR))))
						Door->SetGoState(GO_STATE_ACTIVE);

				}
			}
			return true;
        }
};

class spell_algalon_cosmic_smash_initial : public SpellScriptLoader
{
    public:
        spell_algalon_cosmic_smash_initial() : SpellScriptLoader("spell_algalon_cosmic_smash_initial") { }

        class spell_algalon_cosmic_smash_initial_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_algalon_cosmic_smash_initial_SpellScript);

            bool Load()
            {
                if (GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return false;
                return true;
            }

            void FilterTargetsInitial(std::list<Unit*>& unitList)
            {
                uint32 maxTargets = 1;
                if (GetSpellInfo()->Id == H_SPELL_COSMIC_SMASH)
                    maxTargets = 3;
                Trinity::RandomResizeList(unitList, maxTargets);

                m_unitList = unitList;
            }

            void FillTargetsSubsequential(std::list<Unit*>& unitList)
            {
                unitList = m_unitList;
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_algalon_cosmic_smash_initial_SpellScript::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_algalon_cosmic_smash_initial_SpellScript::FillTargetsSubsequential, EFFECT_1, TARGET_UNIT_AREA_ENEMY_SRC);
            }

            std::list<Unit*> m_unitList; 
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_algalon_cosmic_smash_initial_SpellScript();
        }
};

class spell_algalon_black_hole : public SpellScriptLoader
{
    public:
        spell_algalon_black_hole() : SpellScriptLoader("spell_algalon_black_hole") { }

        class spell_algalon_black_hole_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_algalon_black_hole_AuraScript);


            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetOwner()->ToUnit();

                if (target->GetTypeId() != TYPEID_PLAYER)
                {
                    PreventDefaultAction();
                    return;
                }

                target->UpdateObjectVisibility();
                target->getHostileRefManager().deleteReferences();

            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target->GetTypeId() != TYPEID_PLAYER)
                {
                    PreventDefaultAction(); 
                    return;
                }

                target->UpdateObjectVisibility();
                target->getHostileRefManager().deleteReferences();
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_algalon_black_hole_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_algalon_black_hole_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_algalon_black_hole_AuraScript();
        };
};

class spell_algalon_summon_asteroid_stalkers : public SpellScriptLoader
{
    public:
        spell_algalon_summon_asteroid_stalkers() : SpellScriptLoader("spell_algalon_summon_asteroid_stalkers") { }

        class spell_algalon_summon_asteroid_stalkers_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_algalon_summon_asteroid_stalkers_SpellScript);

            void SpellEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();

                if (!GetOriginalCaster() || GetOriginalCaster() == caster)
                    return;

                uint32 entry = uint32(GetSpellInfo()->EffectMiscValue[effIndex]);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->EffectMiscValueB[effIndex]));
                uint32 duration = uint32(GetSpellDuration(GetSpellInfo()));

                Position pos;
                caster->GetPosition(&pos);
                if (entry == CREATURE_ALGALON_ASTEROID_2)
                    pos.m_positionZ -= 40.0f; 
                TempSummon* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster);
                if (!summon)
                    return;

                summon->SetDisplayId(summon->GetCreatureInfo()->Modelid2);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                summon->SetReactState(REACT_PASSIVE);
                if (entry == CREATURE_ALGALON_ASTEROID_2)
                {
                    summon->SetFlying(true);
                    summon->SendMovementFlagUpdate();
                }
                summon->setFaction(GetOriginalCaster()->getFaction());

            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_algalon_summon_asteroid_stalkers_SpellScript::SpellEffect, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };


        SpellScript* GetSpellScript() const
        {
            return new spell_algalon_summon_asteroid_stalkers_SpellScript();
        }
};

class spell_algalon_cosmic_smash_damage : public SpellScriptLoader
{
    public:
        spell_algalon_cosmic_smash_damage() : SpellScriptLoader("spell_algalon_cosmic_smash_damage") { }

        class spell_algalon_cosmic_smash_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_algalon_cosmic_smash_damage_SpellScript);

            void CalcDamage(SpellEffIndex /*effIndex*/)
            {
                float distance = GetHitUnit()->GetExactDist2d(GetTargetDest());
                if (distance < 6.0f)
                    return;

                SetHitDamage(int32(GetHitDamage() / distance)); //formula is most likely wrong.
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_algalon_cosmic_smash_damage_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_algalon_cosmic_smash_damage_SpellScript();
        }
};

void AddSC_boss_algalon()
{
    new boss_algalon();
    new mob_algalon_asteroid_trigger();
    new mob_collapsing_star();
    new mob_living_constellation();
    new mob_black_hole();
    new mob_dark_matter_algalon();
    new mob_brann_algalon();
    new spell_algalon_phase_punch();
    new spell_algalon_summon_asteroid_stalkers();
    new spell_algalon_cosmic_smash_damage();
    new spell_algalon_black_hole();
    new spell_algalon_cosmic_smash_initial();
    new go_celestial_console();
}
