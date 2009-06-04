/* Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
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
SDName: Boss_Kiljaeden
SD%Complete: 70
SDComment: Phase4, Phase5, Shadow Spike, Armageddon
SDCategory: Sunwell_Plateau
EndScriptData */

//TODO rewrite Amagedon
//TODO Remove blue visual from Orbs on reset and if it is used

#include "precompiled.h"
#include "def_sunwell_plateau.h"
#include <math.h>

/*** Speech and sounds***/
enum Speeches
{
    // These are used throughout Sunwell and Magisters(?). Players can hear this while running through the instances.
    SAY_KJ_OFFCOMBAT1   = -1580066,
    SAY_KJ_OFFCOMBAT2   = -1580067,
    SAY_KJ_OFFCOMBAT3   = -1580068,
    SAY_KJ_OFFCOMBAT4   = -1580069,
    SAY_KJ_OFFCOMBAT5   = -1580070,

    // Encounter speech and sounds
    SAY_KJ_EMERGE       = -1580071,
    SAY_KJ_SLAY1        = -1580072,
    SAY_KJ_SLAY2        = -1580073,
    SAY_KJ_REFLECTION1  = -1580074,
    SAY_KJ_REFLECTION2  = -1580075,
    SAY_KJ_DARKNESS1    = -1580076,
    SAY_KJ_DARKNESS2    = -1580077,
    SAY_KJ_DARKNESS3    = -1580078,
    SAY_KJ_PHASE3       = -1580079,
    SAY_KJ_PHASE4       = -1580080,
    SAY_KJ_PHASE5       = -1580081,
    SAY_KJ_DEATH        = -1580093,
    EMOTE_KJ_DARKNESS   = -1580094,

    /*** Kalecgos - Anveena speech at the beginning of Phase 5; Anveena's sacrifice ***/
    SAY_KALECGOS_AWAKEN     = -1580082,
    SAY_ANVEENA_IMPRISONED  = -1580083,
    SAY_KALECGOS_LETGO      = -1580084,
    SAY_ANVEENA_LOST        = -1580085,
    SAY_KALECGOS_FOCUS      = -1580086,
    SAY_ANVEENA_KALEC       = -1580087,
    SAY_KALECGOS_FATE       = -1580088,
    SAY_ANVEENA_GOODBYE     = -1580089,
    SAY_KALECGOS_GOODBYE    = -1580090,
    SAY_KALECGOS_ENCOURAGE  = -1580091,

    /*** Kalecgos says throughout the fight ***/
    SAY_KALECGOS_JOIN       = -1580092,
    SAY_KALEC_ORB_READY1    = -1580095,
    SAY_KALEC_ORB_READY2    = -1580096,
    SAY_KALEC_ORB_READY3    = -1580097,
    SAY_KALEC_ORB_READY4    = -1580098
};

/*** Spells used during the encounter ***/
enum SpellIds
{
    /* Hand of the Deceiver's spells and cosmetics */
    SPELL_SHADOW_BOLT_VOLLEY                            = 45770, // ~30 yard range Shadow Bolt Volley for ~2k(?) damage
    SPELL_SHADOW_INFUSION                               = 45772, // They gain this at 20% - Immunity to Stun/Silence and makes them look angry!
    SPELL_FELFIRE_PORTAL                                = 46875, // Creates a portal that spawns Felfire Fiends (LIVE FOR THE SWARM!1 FOR THE OVERMIND!)
    SPELL_SHADOW_CHANNELING                             = 46757, // Channeling animation out of combat

    /* Volatile Felfire Fiend's spells */
    SPELL_FELFIRE_FISSION                               = 45779, // Felfire Fiends explode when they die or get close to target.

    /* Kil'Jaeden's spells and cosmetics */
    SPELL_TRANS                                         = 23188, // Surprisingly, this seems to be the right spell.. (Where is it used?)
    SPELL_REBIRTH                                       = 44200, // Emerge from the Sunwell
    SPELL_SOUL_FLAY                                     = 45442, // 9k Shadow damage over 3 seconds. Spammed throughout all the fight.
    SPELL_SOUL_FLAY_SLOW                                = 47106,
    SPELL_LEGION_LIGHTNING                              = 45664, // Chain Lightning, 4 targets, ~3k Shadow damage, 1.5k mana burn
    SPELL_FIRE_BLOOM                                    = 45641, // Places a debuff on 5 raid members, which causes them to deal 2k Fire damage to nearby allies and selves. MIGHT NOT WORK

    SPELL_SINISTER_REFLECTION                           = 45785, // Summon shadow copies of 5 raid members that fight against KJ's enemies
    SPELL_COPY_WEAPON                                   = 41055, // }
    SPELL_COPY_WEAPON2                                  = 41054, // }
    SPELL_COPY_OFFHAND                                  = 45206, // }- Spells used in Sinister Reflection creation
    SPELL_COPY_OFFHAND_WEAPON                           = 45205, // }

    SPELL_SHADOW_SPIKE                                  = 46680, // Bombard random raid members with Shadow Spikes (Very similar to Void Reaver orbs)
    SPELL_FLAME_DART                                    = 45737, // Bombards the raid with flames every 3(?) seconds
    SPELL_DARKNESS_OF_A_THOUSAND_SOULS                  = 46605, // Begins a 8-second channeling, after which he will deal 50'000 damage to the raid
    SPELL_DARKNESS_OF_A_THOUSAND_SOULS_DAMAGE           = 45657,

    /* Armageddon spells wrong visual */
    SPELL_ARMAGEDDON_TRIGGER                            = 45909, // Meteor spell trigger missile should cast creature on himself
    SPELL_ARMAGEDDON_VISUAL                             = 45911, // Does the hellfire visual to indicate where the meteor missle lands
    SPELL_ARMAGEDDON_VISUAL2                            = 45914, // Does the light visual to indicate where the meteor missle lands
    SPELL_ARMAGEDDON_VISUAL3                            = 24207, // This shouldn't correct but same as seen on the movie
    SPELL_ARMAGEDDON_SUMMON_TRIGGER                     = 45921, // Summons the triggers that cast the spells on himself need random target select
    SPELL_ARMAGEDDON_DAMAGE                             = 45915, // This does the area damage

    /* Shield Orb Spells*/
    SPELL_SHADOW_BOLT                                   = 45680, //45679 would be correct but triggers to often //TODO fix console error


    /* Anveena's spells and cosmetics (Or, generally, everything that has "Anveena" in name) */
    SPELL_ANVEENA_PRISON                                = 46367, // She hovers locked within a bubble
    SPELL_ANVEENA_ENERGY_DRAIN                          = 46410, // Sunwell energy glow animation (Control mob uses this)
    SPELL_SACRIFICE_OF_ANVEENA                          = 46474, // This is cast on Kil'Jaeden when Anveena sacrifices herself into the Sunwell

    /* Sinister Reflection Spells */
    SPELL_SR_CURSE_OF_AGONY                             = 46190,
    SPELL_SR_SHADOW_BOLT                                = 47076,

    SPELL_SR_EARTH_SHOCK                                = 47071,

    SPELL_SR_FIREBALL                                   = 47074,

    SPELL_SR_HEMORRHAGE                                 = 45897,

    SPELL_SR_HOLY_SHOCK                                 = 38921,
    SPELL_SR_HAMMER_OF_JUSTICE                          = 37369,

    SPELL_SR_HOLY_SMITE                                 = 47077,
    SPELL_SR_RENEW                                      = 47079,

    SPELL_SR_SHOOT                                      = 16496,
    SPELL_SR_MULTI_SHOT                                 = 48098,
    SPELL_SR_WING_CLIP                                  = 40652,

    SPELL_SR_WHIRLWIND                                  = 17207,

    SPELL_SR_MOONFIRE                                   = 47072,
    //SPELL_SR_PLAGU STRIKE                             = 58843, Dk Spell!

    /*** Other Spells (used by players, etc) ***/
    SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT                  = 45839, // Possess the blue dragon from the orb to help the raid.
    SPELL_ENTROPIUS_BODY                                = 46819, // Visual for Entropius at the Epilogue
    SPELL_RING_OF_BLUE_FLAMES                           = 45825  //Cast this spell when the go is activated
};

enum CreatureIds
{
    CREATURE_ANVEENA                        = 26046, // Embodiment of the Sunwell
    CREATURE_KALECGOS                       = 25319, // Helps the raid throughout the fight
    CREATURE_PROPHET                        = 26246, // Outro
    CREATURE_KILJAEDEN                      = 25315, // Give it to 'em KJ!
    CREATURE_HAND_OF_THE_DECEIVER           = 25588, // Adds found before KJ emerges
    CREATURE_FELFIRE_PORTAL                 = 25603, // Portal spawned be Hand of the Deceivers
    CREATURE_VOLATILE_FELFIRE_FIEND         = 25598, // Fiends spawned by the above portal
    CREATURE_ARMAGEDDON_TARGET              = 25735, // This mob casts meteor on itself.. I think
    CREATURE_SHIELD_ORB                     = 25502, // Shield orbs circle the room raining shadow bolts on raid
    CREATURE_THE_CORE_OF_ENTROPIUS          = 26262, // Used in the ending cinematic?
    CREATURE_POWER_OF_THE_BLUE_DRAGONFLIGHT = 25653, // NPC that players possess when using the Orb of the Blue Dragonflight
    CREATURE_SPIKE_TARGET1                  = 30598, //Should summon these under Shadow Spike Channel on targets place
    CREATURE_SPIKE_TARGET2                  = 30614,
    CREATURE_SINISTER_REFLECTION            = 25708  //Sinister Relection spawnd on Phase swichtes
};

/*** GameObjects ***/
#define GAMEOBJECT_ORB_OF_THE_BLUE_DRAGONFLIGHT 188415

/*** Error messages ***/
#define ERROR_KJ_NOT_SUMMONED "TSCR ERROR: Unable to summon Kil'Jaeden for some reason"

/*** Others ***/
#define FLOOR_Z 28.050388
#define SHIELD_ORB_Z 45.000

enum Phase
{
    PHASE_DECEIVERS     = 1, // Fight 3 adds
    PHASE_NORMAL        = 2, // Kil'Jaeden emerges from the sunwell
    PHASE_DARKNESS      = 3, // At 85%, he gains few abilities; Kalecgos joins the fight
    PHASE_ARMAGEDDON    = 4, // At 55%, he gains even more abilities
    PHASE_SACRIFICE     = 5, // At 25%, Anveena sacrifices herself into the Sunwell; at this point he becomes enraged and has *significally* shorter cooldowns.
};

//Timers
enum KilJaedenTimers {
    TIMER_KALEC_JOIN       = 0,

    //Phase 2 Timer
    TIMER_SOUL_FLAY           = 1,
    TIMER_LEGION_LIGHTNING = 2,
    TIMER_FIRE_BLOOM       = 3,
    TIMER_SUMMON_SHILEDORB = 4,

    //Phase 3 Timer
    TIMER_SHADOW_SPIKE     = 5,
    TIMER_FLAME_DART       = 6,
    TIMER_DARKNESS         = 7,
    TIMER_ORBS_EMPOWER     = 8,

    //Phase 4 Timer
    TIMER_ARMAGEDDON       = 9
};

// Locations of the Hand of Deceiver adds
float DeceiverLocations[3][3]=
{
    {1682.045, 631.299, 5.936},
    {1684.099, 618.848, 0.589},
    {1694.170, 612.272, 1.416},
};

// Locations, where Shield Orbs will spawn
float ShieldOrbLocations[4][2]=
{
    {1698.900, 627.870},  //middle pont of Sunwell
    {12, 3.14},     // First one spawns northeast of KJ
    {12, 3.14/0.7}, // Second one spawns southeast
    {12, 3.14*3.8}  // Third one spawns (?)
};

float OrbLocations[4][5] = {
    (1694.48, 674.29,  28.0502, 4.86985),
    (1745.68, 621.823, 28.0505, 2.93777),
    (1704.14, 583.591, 28.1696, 1.59003),
    (1653.12, 635.41,  28.0932, 0.0977725),
};

struct Speech
{
    int32 textid;
    uint32 creature, timer;
};
// TODO: Timers
static Speech Sacrifice[]=
{
    {SAY_KALECGOS_AWAKEN,       CREATURE_KALECGOS,  5000},
    {SAY_ANVEENA_IMPRISONED,    CREATURE_ANVEENA,   5000},
    {SAY_KALECGOS_LETGO,        CREATURE_KALECGOS,  8000},
    {SAY_ANVEENA_LOST,          CREATURE_ANVEENA,   5000},
    {SAY_KALECGOS_FOCUS,        CREATURE_KALECGOS,  7000},
    {SAY_ANVEENA_KALEC,         CREATURE_ANVEENA,   2000},
    {SAY_KALECGOS_FATE,         CREATURE_KALECGOS,  3000},
    {SAY_ANVEENA_GOODBYE,       CREATURE_ANVEENA,   6000},
    {SAY_KALECGOS_GOODBYE,      CREATURE_KALECGOS,  12000},
    {SAY_KJ_PHASE5,             CREATURE_KILJAEDEN, 8000},
    {SAY_KALECGOS_ENCOURAGE,    CREATURE_KALECGOS,  5000}
};

class AllOrbsInGrid
{
public:
    AllOrbsInGrid() {}
    bool operator() (GameObject* go)
    {
        if(go->GetEntry() == GAMEOBJECT_ORB_OF_THE_BLUE_DRAGONFLIGHT)
            return true;
        return false;
    }
};

bool GOHello_go_orb_of_the_blue_flight(Player *plr, GameObject* go)
{
    if(go->GetUInt32Value(GAMEOBJECT_FACTION) == 35){
        ScriptedInstance* pInstance = (go->GetInstanceData());
        float x,y,z, dx,dy,dz;
        go->SummonCreature(CREATURE_POWER_OF_THE_BLUE_DRAGONFLIGHT, plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 121000);
        plr->CastSpell(plr, SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT, true);
        go->SetUInt32Value(GAMEOBJECT_FACTION, 0);
        Unit* Kalec = CAST_CRE(Unit::GetUnit(*plr, pInstance->GetData64(DATA_KALECGOS_KJ)));
        //Kalec->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);
        go->GetPosition(x,y,z);
        for(uint8 i = 0; i < 4; ++i){
            DynamicObject* Dyn = Kalec->GetDynObject(SPELL_RING_OF_BLUE_FLAMES);
            if(Dyn){
                Dyn->GetPosition(dx,dy,dz);
                if(x == dx && dy == y && dz == z){
                    Dyn->RemoveFromWorld();
                    break;
                }
            }
        }
        go->Refresh();
    }
    return true;
}

//AI for Kalecgos
struct TRINITY_DLL_DECL boss_kalecgos_kjAI : public ScriptedAI
{
    boss_kalecgos_kjAI(Creature* c) : ScriptedAI(c){
        pInstance = (c->GetInstanceData());
    }

    GameObject* Orb[4];
    ScriptedInstance* pInstance;
    uint8 OrbsEmpowered;
    uint8 EmpowerCount;

    bool Searched;

    void InitializeAI(){
        for(uint8 i = 0; i < 4; ++i)
            Orb[i] = NULL;
        FindOrbs();
        OrbsEmpowered = 0;
        EmpowerCount = 0;
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->setActive(true);
        Searched = false;
        FindOrbs();
    }

    void Reset(){}

    void FindOrbs()
    {
        CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
        Cell cell(pair);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();
        std::list<GameObject*> orbList;
        AllOrbsInGrid check;
        Trinity::GameObjectListSearcher<AllOrbsInGrid> searcher(me, orbList, check);
        TypeContainerVisitor<Trinity::GameObjectListSearcher<AllOrbsInGrid>, GridTypeMapContainer> visitor(searcher);
        CellLock<GridReadGuard> cell_lock(cell, pair);
        cell_lock->Visit(cell_lock, visitor, *(m_creature->GetMap()));
        if(orbList.empty())
            return;
        uint8 i = 0;
        for(std::list<GameObject*>::iterator itr = orbList.begin(); itr != orbList.end(); ++itr, ++i){
            Orb[i] = GameObject::GetGameObject(*m_creature, (*itr)->GetGUID());
        }
    }

    void ResetOrbs(){
        m_creature->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);
        for(uint8 i = 0; i < 4; ++i)
            if(Orb[i]) Orb[i]->SetUInt32Value(GAMEOBJECT_FACTION, 0);
    }

    void EmpowerOrb(bool all)
    {
        if(!Orb[OrbsEmpowered])
            return;
        uint8 random = rand()%3;
        if(all){
            m_creature->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);
            for(uint8 i = 0; i < 4; ++i){
                if(!Orb[i]) return;
                Orb[i]->CastSpell(m_creature, SPELL_RING_OF_BLUE_FLAMES);
                Orb[i]->SetUInt32Value(GAMEOBJECT_FACTION, 35);
                Orb[i]->setActive(true);
                Orb[i]->Refresh();
            }
        }else{
            float x,y,z, dx,dy,dz;
            Orb[random]->GetPosition(x,y,z);
            for(uint8 i = 0; i < 4; ++i){
                DynamicObject* Dyn = m_creature->GetDynObject(SPELL_RING_OF_BLUE_FLAMES);
                if(Dyn){
                    Dyn->GetPosition(dx,dy,dz);
                    if(x == dx && dy == y && dz == z){
                        Dyn->RemoveFromWorld();
                        break;
                     }
                 }
            }
        Orb[random]->CastSpell(m_creature, SPELL_RING_OF_BLUE_FLAMES);
        Orb[random]->SetUInt32Value(GAMEOBJECT_FACTION, 35);
        Orb[random]->setActive(true);
        Orb[random]->Refresh();
        ++OrbsEmpowered;
        }
        ++EmpowerCount;

        switch(EmpowerCount){
            case 1: DoScriptText(SAY_KALEC_ORB_READY1, m_creature); break;
            case 2: DoScriptText(SAY_KALEC_ORB_READY2, m_creature); break;
            case 3: DoScriptText(SAY_KALEC_ORB_READY3, m_creature); break;
            case 4: DoScriptText(SAY_KALEC_ORB_READY4, m_creature); break;
        }
    }

    void UpdateAI(const uint32 diff){
        if(!Searched){
            FindOrbs();
            Searched = true;
            }

        if(OrbsEmpowered == 4) OrbsEmpowered = 0;
    }
};

CreatureAI* GetAI_boss_kalecgos_kj(Creature *_Creature)
{
    return new boss_kalecgos_kjAI (_Creature);
}

//AI for Kil'jaeden
struct TRINITY_DLL_DECL boss_kiljaedenAI : public Scripted_NoMovementAI
{
    boss_kiljaedenAI(Creature* c) : Scripted_NoMovementAI(c), Summons(m_creature){
        pInstance = (c->GetInstanceData());
    }

    ScriptedInstance* pInstance;
    SummonList Summons;
    Creature*  Kalec;
    Unit*      randomPlayer;

    uint8 Phase;
    uint8 ActiveTimers;

    uint32 Timer[10];
    uint32 WaitTimer;

    /* Boolean */
    bool IsKalecJoined;
    bool IsInDarkness;
    bool TimerIsDeactiveted[10];
    bool IsWaiting;
    bool OrbActivated;

    void Reset()
    {
        // TODO: Fix timers
        Timer[TIMER_KALEC_JOIN]       = 26000;

        //Phase 2 Timer
        Timer[TIMER_SOUL_FLAY]        = 20000;
        Timer[TIMER_LEGION_LIGHTNING] = 40000;
        Timer[TIMER_FIRE_BLOOM]       = 30000;
        Timer[TIMER_SUMMON_SHILEDORB] = 45000;

        //Phase 3 Timer
        Timer[TIMER_SHADOW_SPIKE]     = 4000;
        Timer[TIMER_FLAME_DART]       = 3000;
        Timer[TIMER_DARKNESS]         = 45000;
        Timer[TIMER_ORBS_EMPOWER]     = 35000;

        //Phase 4 Timer
        Timer[TIMER_ARMAGEDDON]       = 2000;

        ActiveTimers = 5;
        WaitTimer    = 0;

        Phase = PHASE_DECEIVERS;

        IsKalecJoined = false;
        IsInDarkness  = false;
        IsWaiting     = false;
        OrbActivated  = false;

        Kalec = CAST_CRE(Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_KALECGOS_KJ)));
        ChangeTimers(false, 0);
    }

    void ChangeTimers(bool status, uint32 WTimer){
        for(uint8 i = 0; i < 10;++i)
            TimerIsDeactiveted[i] = status;
        TimerIsDeactiveted[TIMER_KALEC_JOIN] = IsKalecJoined;

        if(WTimer > 0){
            IsWaiting = true;
            WaitTimer = WTimer;
        }

        if(OrbActivated) TimerIsDeactiveted[TIMER_ORBS_EMPOWER] = true;
        if(Timer[TIMER_SHADOW_SPIKE] == 0) TimerIsDeactiveted[TIMER_SHADOW_SPIKE] = true;
        if(Phase == PHASE_SACRIFICE) TimerIsDeactiveted[TIMER_SUMMON_SHILEDORB] = true;
    }

    void JustSummoned(Creature* summoned)
    {
        if(summoned->GetEntry() == CREATURE_ARMAGEDDON_TARGET)
        {
            summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }else{
            summoned->SetLevel(m_creature->getLevel());
        }
        summoned->setFaction(m_creature->getFaction());
        Summons.Summon(summoned);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_KJ_DEATH, m_creature);

        if(pInstance)
            pInstance->SetData(DATA_KILJAEDEN_EVENT, DONE);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
        case 0: DoScriptText(SAY_KJ_SLAY1, m_creature); break;
        case 1: DoScriptText(SAY_KJ_SLAY2, m_creature); break;
        }
    }

    void EnterEvadeMode()
    {
        Scripted_NoMovementAI::EnterEvadeMode();
        Summons.DespawnAll();

        // Reset the controller
        if(pInstance){
            Creature* Control = CAST_CRE(Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_KILJAEDEN_CONTROLLER)));
            if(Control)
                CAST_AI(Scripted_NoMovementAI, Control->AI())->Reset();
        }
    }

    void EnterCombat(Unit* who){
        DoZoneInCombat();
        DoScriptText(SAY_KJ_EMERGE, m_creature);
    }

    void CastSinisterReflection()
    {
        switch(rand()%2){
        case 0: DoScriptText(SAY_KJ_REFLECTION1, m_creature); break;
        case 1: DoScriptText(SAY_KJ_REFLECTION2, m_creature); break;
        }
        DoCast(m_creature, SPELL_SINISTER_REFLECTION, true);
        for(uint8 i = 0; i < 4; i++){
            float x,y,z;
            Unit* target;
            for(uint8 z = 0; z < 6; ++z){
                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (!target->HasAura(SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT,0)) break;
            }
            target->GetPosition(x,y,z);
            Creature* SinisterReflection = m_creature->SummonCreature(CREATURE_SINISTER_REFLECTION, x,y,z,0, TEMPSUMMON_CORPSE_DESPAWN, 0);
            if(SinisterReflection)
                SinisterReflection->AI()->AttackStart(target);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim() || Phase < PHASE_NORMAL)
            return;

        if(IsWaiting){
            if(WaitTimer < diff){
                IsWaiting = false;
                ChangeTimers(false, 0);
            }
            else WaitTimer -= diff;
        }

        for(uint8 t = 0; t < ActiveTimers; ++t){
            if(Timer[t] < diff && !TimerIsDeactiveted[t]){
                switch(t){
                    case TIMER_KALEC_JOIN:
                        if(Kalec){
                            DoScriptText(SAY_KALECGOS_JOIN, Kalec);
                            IsKalecJoined = true;
                            TimerIsDeactiveted[TIMER_KALEC_JOIN] = true;
                        }
                        break;
                    case TIMER_SOUL_FLAY:
                        if(!m_creature->IsNonMeleeSpellCasted(false)){
                        m_creature->CastSpell(m_creature->getVictim(), SPELL_SOUL_FLAY, false);
                        m_creature->getVictim()->CastSpell(m_creature->getVictim(), SPELL_SOUL_FLAY_SLOW, true);
                        Timer[TIMER_SOUL_FLAY] = 3500;
                        }
                        break;
                    case TIMER_LEGION_LIGHTNING:
                        if(!m_creature->IsNonMeleeSpellCasted(false)){
                            m_creature->RemoveAurasDueToSpell(SPELL_SOUL_FLAY);
                            for(uint8 z = 0; z < 6; ++z){
                                randomPlayer = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                                if (!randomPlayer->HasAura(SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT,0)) break;
                            }
                            if(randomPlayer)DoCast(randomPlayer, SPELL_LEGION_LIGHTNING, false);
                            else error_log("try to cast SPELL_LEGION_LIGHTNING on invalid target");
                            Timer[TIMER_LEGION_LIGHTNING] = (Phase == PHASE_SACRIFICE) ? 18000 : 30000; // 18 seconds in PHASE_SACRIFICE
                            Timer[TIMER_SOUL_FLAY] = 2500;
                        }
                        break;
                    case TIMER_FIRE_BLOOM:
                        if(!m_creature->IsNonMeleeSpellCasted(false)){
                            m_creature->RemoveAurasDueToSpell(SPELL_SOUL_FLAY);
                            DoCastAOE(SPELL_FIRE_BLOOM, false);
                            Timer[TIMER_FIRE_BLOOM] = (Phase == PHASE_SACRIFICE) ? 25000 : 40000; // 25 seconds in PHASE_SACRIFICE
                            Timer[TIMER_SOUL_FLAY] = 1000;
                        }
                        break;
                    case TIMER_SUMMON_SHILEDORB:
                        for(uint8 i = 1; i < Phase; ++i){
                            float sx, sy;
                            sx = ShieldOrbLocations[0][0] + sin(ShieldOrbLocations[i][0]);
                            sy = ShieldOrbLocations[0][1] + sin(ShieldOrbLocations[i][1]);
                            m_creature->SummonCreature(CREATURE_SHIELD_ORB, sx, sy, SHIELD_ORB_Z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
                        }
                        Timer[TIMER_SUMMON_SHILEDORB] = 30000+rand()%30*1000; // 30-60seconds cooldown
                        Timer[TIMER_SOUL_FLAY] = 2000;
                        break;
                    case TIMER_SHADOW_SPIKE: //Phase 3
                        if(!m_creature->IsNonMeleeSpellCasted(false)){
                        DoCastAOE(SPELL_SHADOW_SPIKE, false);
                        Timer[TIMER_SHADOW_SPIKE] = 0;
                        TimerIsDeactiveted[TIMER_SHADOW_SPIKE] = true;
                        ChangeTimers(true, 30000);
                        }
                        break;
                    case TIMER_FLAME_DART: //Phase 3
                        DoCastAOE(SPELL_FLAME_DART, false);
                        Timer[TIMER_FLAME_DART] = 3000; //TODO Timer
                        break;
                    case TIMER_DARKNESS: //Phase 3
                        if(!m_creature->IsNonMeleeSpellCasted(false)){
                        // Begins to channel for 8 seconds, then deals 50'000 damage to all raid members.
                        if(!IsInDarkness){
                            DoScriptText(EMOTE_KJ_DARKNESS, m_creature);
                            DoCastAOE(SPELL_DARKNESS_OF_A_THOUSAND_SOULS, false);
                            ChangeTimers(true, 9000);
                            Timer[TIMER_DARKNESS] = 8750;
                            TimerIsDeactiveted[TIMER_DARKNESS] = false;
                            if(Phase == PHASE_SACRIFICE) TimerIsDeactiveted[TIMER_ARMAGEDDON] = false;
                            IsInDarkness = true;
                        }else{
                            Timer[TIMER_DARKNESS] = (Phase == PHASE_SACRIFICE) ? 20000 + rand()%15000 : 40000 + rand()%30000;
                            IsInDarkness = false;
                            DoCastAOE(SPELL_DARKNESS_OF_A_THOUSAND_SOULS_DAMAGE);
                            switch(rand()%3){
                                case 0: DoScriptText(SAY_KJ_DARKNESS1, m_creature); break;
                                case 1: DoScriptText(SAY_KJ_DARKNESS2, m_creature); break;
                                case 2: DoScriptText(SAY_KJ_DARKNESS3, m_creature); break;
                            }
                        }
                        Timer[TIMER_SOUL_FLAY] = 9000;
                        }
                        break;
                    case TIMER_ORBS_EMPOWER: //Phase 3
                        if(Phase == PHASE_SACRIFICE){
                            if(Kalec)CAST_AI(boss_kalecgos_kjAI, Kalec->AI())->EmpowerOrb(true);
                        }else if(Kalec)CAST_AI(boss_kalecgos_kjAI, Kalec->AI())->EmpowerOrb(false);
                        Timer[TIMER_ORBS_EMPOWER]= (Phase == PHASE_SACRIFICE) ? 45000 : 35000;
                        OrbActivated = true;
                        TimerIsDeactiveted[TIMER_ORBS_EMPOWER] = true;
                        break;
                    case TIMER_ARMAGEDDON: //Phase 4
                        Unit* target;
                        for(uint8 z = 0; z < 6; ++z){
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                            if (!target->HasAura(SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT,0)) break;
                        }
                        if(target){
                            float x, y, z;
                            target->GetPosition(x, y, z);
                            m_creature->SummonCreature(CREATURE_ARMAGEDDON_TARGET, x,y,z,0, TEMPSUMMON_TIMED_DESPAWN,15000);
                        }
                        Timer[TIMER_ARMAGEDDON] = 2000; // No, I'm not kidding
                        break;
                 }
                break;
            }
        }
            //Time runs over!
            for(uint8 i = 0; i < ActiveTimers; ++i)
                if(!TimerIsDeactiveted[i]){
                    Timer[i] -= diff;
                    if(((int32)Timer[i]) < 0) Timer[i] = 0;
                }

        //Phase 3
        if(Phase <= PHASE_NORMAL){
            if(Phase == PHASE_NORMAL && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 85)){
                CastSinisterReflection();
                DoScriptText(SAY_KJ_PHASE3, m_creature);
                Phase = PHASE_DARKNESS;
                OrbActivated = false;
                ActiveTimers = 9;
            }
            else return;
        }

        //Phase 4
        if(Phase <= PHASE_DARKNESS){
            if(Phase == PHASE_DARKNESS && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 55)){
                DoScriptText(SAY_KJ_PHASE4, m_creature);
                Phase = PHASE_ARMAGEDDON;
                OrbActivated = false;
                ActiveTimers = 10;
            }
            else return;
        }

        //Phase 5 specific spells all we can
        if(Phase <= PHASE_ARMAGEDDON){
            if(Phase == PHASE_ARMAGEDDON && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)){
                Phase = PHASE_SACRIFICE;
                Creature* Anveena = (Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_ANVEENA)));
                if (Anveena)Anveena->CastSpell(m_creature, SPELL_SACRIFICE_OF_ANVEENA, false);
                OrbActivated = false;
                ChangeTimers(true, 10000);// He shouldn't cast spells for ~10 seconds after Anveena's sacrifice. This will be done within Anveena's script
            }
            else return;
        }

}
};

CreatureAI* GetAI_boss_kiljaeden(Creature *_Creature)
{
    return new boss_kiljaedenAI (_Creature);
}

//AI for Kil'jaeden Event Controller
struct TRINITY_DLL_DECL mob_kiljaeden_controllerAI : public Scripted_NoMovementAI
{
    mob_kiljaeden_controllerAI(Creature* c) : Scripted_NoMovementAI(c), Summons(m_creature){
        pInstance = (c->GetInstanceData());
    }

    ScriptedInstance* pInstance;
    Creature* KalecKJ;
    SummonList Summons;

    bool SummonedDeceivers;
    bool KiljaedenDeath;

    uint32 RandomSayTimer;
    uint32 Phase;
    uint8 DeceiverDeathCount;

    void InitializeAI(){
        KalecKJ = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_KALECGOS_KJ));
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->addUnitState(UNIT_STAT_STUNNED);
    }

    void Reset(){
        Phase = PHASE_DECEIVERS;
        if(KalecKJ)CAST_AI(boss_kalecgos_kjAI, KalecKJ->AI())->ResetOrbs();
        DeceiverDeathCount = 0;
        SummonedDeceivers = false;
        KiljaedenDeath = false;
        RandomSayTimer = 30000;
        Summons.DespawnAll();
    }

    void JustSummoned(Creature* summoned){
        switch(summoned->GetEntry()){
            case CREATURE_HAND_OF_THE_DECEIVER:
                summoned->CastSpell(summoned, SPELL_SHADOW_CHANNELING, false);
                break;
            case CREATURE_ANVEENA:
                summoned->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                summoned->CastSpell(summoned, SPELL_ANVEENA_PRISON, true);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                break;
            case CREATURE_KILJAEDEN:
                summoned->CastSpell(summoned, SPELL_REBIRTH, false);
                CAST_AI(boss_kiljaedenAI, summoned->AI())->Phase=PHASE_NORMAL;
                summoned->AddThreat(m_creature->getVictim(), 1.0f);
                break;
        }
        Summons.Summon(summoned);
    }

    void UpdateAI(const uint32 diff)
    {
        if(RandomSayTimer < diff && pInstance->GetData(DATA_MURU_EVENT) != DONE && pInstance->GetData(DATA_KILJAEDEN_EVENT) == NOT_STARTED){
            switch(rand()%5){
                case 0: DoScriptText(SAY_KJ_OFFCOMBAT1, m_creature); break;
                case 1: DoScriptText(SAY_KJ_OFFCOMBAT2, m_creature); break;
                case 2: DoScriptText(SAY_KJ_OFFCOMBAT3, m_creature); break;
                case 3: DoScriptText(SAY_KJ_OFFCOMBAT4, m_creature); break;
                case 4: DoScriptText(SAY_KJ_OFFCOMBAT5, m_creature); break;
            }
            RandomSayTimer = 30000;
        }else RandomSayTimer -= diff;

        if(!SummonedDeceivers){
            for(uint8 i = 0; i < 3; ++i)
                m_creature->SummonCreature(CREATURE_HAND_OF_THE_DECEIVER, DeceiverLocations[i][0], DeceiverLocations[i][1], FLOOR_Z, DeceiverLocations[i][2], TEMPSUMMON_DEAD_DESPAWN, 0);

            DoSpawnCreature(CREATURE_ANVEENA,  0, 0, 40, 0, TEMPSUMMON_DEAD_DESPAWN, 0);
            DoCast(m_creature, SPELL_ANVEENA_ENERGY_DRAIN);
            SummonedDeceivers = true;
        }

        if(DeceiverDeathCount > 2 && Phase == PHASE_DECEIVERS){
            m_creature->RemoveAurasDueToSpell(SPELL_ANVEENA_ENERGY_DRAIN) ;
            Phase = PHASE_NORMAL;
            DoSpawnCreature(CREATURE_KILJAEDEN, 0, 0,0, 0, TEMPSUMMON_MANUAL_DESPAWN, 0);
        }
    }
};

CreatureAI* GetAI_mob_kiljaeden_controller(Creature *_Creature)
{
    return new mob_kiljaeden_controllerAI (_Creature);
}

//AI for Hand of the Deceiver
struct TRINITY_DLL_DECL mob_hand_of_the_deceiverAI : public ScriptedAI
{
    mob_hand_of_the_deceiverAI(Creature* c) : ScriptedAI(c){
        pInstance = (c->GetInstanceData());
    }
    ScriptedInstance* pInstance;

    uint32 ShadowBoltVolleyTimer;
    uint32 FelfirePortalTimer;

    void Reset(){
        // TODO: Timers!
        ShadowBoltVolleyTimer = 8000 + rand()%6000; // So they don't all cast it in the same moment.
        FelfirePortalTimer = 20000;
        if(pInstance)pInstance->SetData(DATA_KILJAEDEN_EVENT, NOT_STARTED);
    }

    void JustSummoned(Creature* summoned){
        summoned->setFaction(m_creature->getFaction());
        summoned->SetLevel(m_creature->getLevel());
    }

    void EnterCombat(Unit* who){
        if(pInstance){
            pInstance->SetData(DATA_KILJAEDEN_EVENT, IN_PROGRESS);
            Creature* Control = CAST_CRE(Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_KILJAEDEN_CONTROLLER)));
            if(Control)
                Control->AddThreat(who, 1.0f);
        }
        m_creature->InterruptNonMeleeSpells(true);
    }

    void JustDied(Unit* killer){
        if(!pInstance)
            return;

        Creature* Control = CAST_CRE(Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_KILJAEDEN_CONTROLLER)));
        if(Control)
            CAST_AI(mob_kiljaeden_controllerAI, Control->AI())->DeceiverDeathCount++;
    }

    void UpdateAI(const uint32 diff){
        if(!me->isInCombat())
            DoCast(m_creature, SPELL_SHADOW_CHANNELING);

        if(!UpdateVictim())
            return;

        // Gain Shadow Infusion at 20% health
        if(((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 20) && !m_creature->HasAura(SPELL_SHADOW_INFUSION, 0))
            DoCast(m_creature, SPELL_SHADOW_INFUSION, true);

        // Shadow Bolt Volley - Shoots Shadow Bolts at all enemies within 30 yards, for ~2k Shadow damage.
        if(ShadowBoltVolleyTimer < diff){
            DoCast(m_creature->getVictim(), SPELL_SHADOW_BOLT_VOLLEY);
            ShadowBoltVolleyTimer = 12000;
        }else ShadowBoltVolleyTimer -= diff;

        // Felfire Portal - Creatres a portal, that spawns Volatile Felfire Fiends, which do suicide bombing.
        if(FelfirePortalTimer < diff){
            Creature* Portal = DoSpawnCreature(CREATURE_FELFIRE_PORTAL, 0, 0,0, 0, TEMPSUMMON_TIMED_DESPAWN, 20000);
            if(Portal)
            {
                std::list<HostilReference*>::iterator itr;
                for(itr = m_creature->getThreatManager().getThreatList().begin(); itr != m_creature->getThreatManager().getThreatList().end(); ++itr)
                {
                    Unit* pUnit = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                    if(pUnit)
                        Portal->AddThreat(pUnit, 1.0f);
                }
            }
            FelfirePortalTimer = 20000;
        }else FelfirePortalTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_hand_of_the_deceiver(Creature *_Creature)
{
    return new mob_hand_of_the_deceiverAI (_Creature);
}

//AI for Felfire Portal
struct TRINITY_DLL_DECL mob_felfire_portalAI : public Scripted_NoMovementAI
{
    mob_felfire_portalAI(Creature* c) : Scripted_NoMovementAI(c) {}

    uint32 SpawnFiendTimer;

    void InitializeAI(){
        SpawnFiendTimer = 5000;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    // TODO: Timers
    void Reset() {

    }

    void JustSummoned(Creature* summoned)
    {
        summoned->setFaction(m_creature->getFaction());
        summoned->SetLevel(m_creature->getLevel());
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(SpawnFiendTimer < diff)
        {
            Creature* Fiend = DoSpawnCreature(CREATURE_VOLATILE_FELFIRE_FIEND, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 20000);
            if(Fiend)
                Fiend->AddThreat(SelectUnit(SELECT_TARGET_RANDOM,0), 100000.0f);
            SpawnFiendTimer = 4000 + rand()%4000;
        }else SpawnFiendTimer -= diff;
    }
};

CreatureAI* GetAI_mob_felfire_portal(Creature *_Creature)
{
    return new mob_felfire_portalAI (_Creature);
}

//AI for Felfire Fiend
struct TRINITY_DLL_DECL mob_volatile_felfire_fiendAI : public ScriptedAI
{
    mob_volatile_felfire_fiendAI(Creature* c) : ScriptedAI(c) {}

    uint32 ExplodeTimer;

    bool LockedTarget;

    void Reset()
    {
        ExplodeTimer = 2000;
        LockedTarget = false;
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(damage > m_creature->GetHealth())
            DoCast(m_creature, SPELL_FELFIRE_FISSION, true);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(!LockedTarget){
            m_creature->AddThreat(m_creature->getVictim(), 10000000.0f);
            LockedTarget = true;
        }

        if(ExplodeTimer){
            if(ExplodeTimer < diff)
                ExplodeTimer = 0;
            else ExplodeTimer -= diff;
        }
        else if(m_creature->IsWithinDistInMap(m_creature->getVictim(), 3)) // Explode if it's close enough to it's target
        {
            DoCast(m_creature->getVictim(), SPELL_FELFIRE_FISSION);
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
    }
};

CreatureAI* GetAI_mob_volatile_felfire_fiend(Creature *_Creature)
{
    return new mob_volatile_felfire_fiendAI (_Creature);
}

//AI for Armageddon target
struct TRINITY_DLL_DECL mob_armageddonAI : public Scripted_NoMovementAI
{
    mob_armageddonAI(Creature* c) : Scripted_NoMovementAI(c) {}

    uint8 Spell;
    uint32 Timer;

    void Reset(){
        Spell = 0;
        Timer = 0;
    }

    void UpdateAI(const uint32 diff)
    {
        if(Timer < diff){
            switch(Spell){
                case 0:
                    DoCast(m_creature, SPELL_ARMAGEDDON_VISUAL, true);
                    ++Spell;
                    break;
                case 1:
                    DoCast(m_creature, SPELL_ARMAGEDDON_VISUAL2, true);
                    Timer = 9000;
                    ++Spell;
                    break;
                case 2:
                    DoCast(m_creature, SPELL_ARMAGEDDON_TRIGGER, true);
                    ++Spell;
                    Timer = 5000;
                    break;
                case 3:
                    m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    m_creature->RemoveCorpse();
                    break;
            }
        }else Timer -=diff;
    }
};

CreatureAI* GetAI_mob_armageddon(Creature *_Creature)
{
    return new mob_armageddonAI (_Creature);
}

//AI for Shield Orbs
struct TRINITY_DLL_DECL mob_shield_orbAI : public ScriptedAI
{
    mob_shield_orbAI(Creature* c) : ScriptedAI(c) {
        pInstance = (c->GetInstanceData());
    }

    bool PointReached;
    bool Clockwise;
    uint32 Timer;
    uint32 CheckTimer;
    ScriptedInstance* pInstance;
    float x, y, r, c, mx, my;

    void InitializeAI(){
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
        PointReached = true;
        Timer = 500+ rand()%500;
        CheckTimer = 1000;
        r = 17;
        c = 0;
        mx = ShieldOrbLocations[0][0];
        my = ShieldOrbLocations[0][1];
        if(rand()%2 == 0)Clockwise = true;
        else Clockwise = false;
    }

    void Reset(){}

    void UpdateAI(const uint32 diff){
        if(PointReached){
            if(Clockwise){
                y = my - r * sin(c);
                x = mx - r * cos(c);
            }else{
                y = my + r * sin(c);
                x = mx + r * cos(c);
            }
            PointReached = false;
            CheckTimer = 1000;
            m_creature->GetMotionMaster()->MovePoint(1,x, y, SHIELD_ORB_Z);
            c += 3.1415926535/32;
            if(c > 2*3.1415926535) c = 0;
        }else{
            if (CheckTimer < diff){
                DoTeleportTo(x,y,SHIELD_ORB_Z);
                PointReached = true;
            }else CheckTimer -= diff;

        }

        if (Timer < diff){
            Unit* random = (Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_PLAYER_GUID)));
            if (random)DoCast(random, SPELL_SHADOW_BOLT, false);
            Timer = 500+ rand()%500;
        }else Timer -= diff;
    }

    void MovementInform(uint32 type, uint32 id){
        if(type != POINT_MOTION_TYPE)
            return;

        PointReached = true;
    }
};

CreatureAI* GetAI_mob_shield_orb(Creature *_Creature)
{
    return new mob_shield_orbAI (_Creature);
}

//AI for Sinister Reflection
struct TRINITY_DLL_DECL mob_sinster_reflectionAI : public ScriptedAI
{
    mob_sinster_reflectionAI(Creature* c) : ScriptedAI(c) {}

    uint8 Class;
    uint32 Timer[3];

    void Reset(){
        Timer[0] = 0;
        Timer[1] = 0;
        Timer[2] = 0;
        Class = 0;
    }

    void UpdateAI(const uint32 diff){

        if(Class == 0){
            Class = m_creature->getVictim()->getClass();
            switch(Class){
                case CLASS_DRUID:
                    break;
                case CLASS_HUNTER:
                    break;
                case CLASS_MAGE:
                    break;
                case CLASS_WARLOCK:
                    break;
                case CLASS_WARRIOR:
                    m_creature->SetCanDualWield(true);
                    break;
                case CLASS_PALADIN:
                    break;
                case CLASS_PRIEST:
                    break;
                case CLASS_SHAMAN:
                    m_creature->SetCanDualWield(true);
                    break;
                case CLASS_ROGUE:
                    m_creature->SetCanDualWield(true);
                    break;
            }
        }

        switch(Class){
            case CLASS_DRUID:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_MOONFIRE, false);
                    Timer[1] = 3000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_HUNTER:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_MULTI_SHOT, false);
                    Timer[1] = 9000;
                }
                if(Timer[2] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_SHOOT, false);
                    Timer[2] = 5000;
                }
                if(m_creature->IsWithinMeleeRange(m_creature->getVictim(), 6)){
                    if(Timer[3] < diff){
                        DoCast(m_creature->getVictim(), SPELL_SR_MULTI_SHOT, false);
                        Timer[3] = 7000;
                    }
                    DoMeleeAttackIfReady();
                }
                break;
            case CLASS_MAGE:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_FIREBALL, false);
                    Timer[1] = 3000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_WARLOCK:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_SHADOW_BOLT, false);
                    Timer[1] = 4000;
                }
                if(Timer[2] < diff){
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_SR_CURSE_OF_AGONY, true);
                    Timer[2] = 3000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_WARRIOR:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_WHIRLWIND, false);
                    Timer[1] = 10000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_PALADIN:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_HAMMER_OF_JUSTICE, false);
                    Timer[1] = 7000;
                }
                if(Timer[2] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_HOLY_SHOCK, false);
                    Timer[2] = 3000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_PRIEST:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_HOLY_SMITE, false);
                    Timer[1] = 5000;
                }
                if(Timer[2] < diff){
                    DoCast(m_creature,  SPELL_SR_RENEW, false);
                    Timer[2] = 7000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_SHAMAN:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_EARTH_SHOCK, false);
                    Timer[1] = 5000;
                }
                DoMeleeAttackIfReady();
                break;
            case CLASS_ROGUE:
                if(Timer[1] < diff){
                    DoCast(m_creature->getVictim(), SPELL_SR_HEMORRHAGE, true);
                    Timer[1] = 5000;
                }
                DoMeleeAttackIfReady();
                break;
            }
            debug_log("Sinister-Timer");
            for(uint8 i = 0; i < 3; ++i)
                Timer[i] -= diff;
        }

};

CreatureAI* GetAI_mob_sinster_reflection(Creature *_Creature)
{
    return new mob_sinster_reflectionAI (_Creature);
}

void AddSC_boss_kiljaeden()
{
    Script* newscript;

    newscript = new Script;
    newscript->pGOHello = &GOHello_go_orb_of_the_blue_flight;
    newscript->Name = "go_orb_of_the_blue_flight";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_boss_kalecgos_kj;
    newscript->Name = "boss_kalecgos_kj";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_boss_kiljaeden;
    newscript->Name = "boss_kiljaeden";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_kiljaeden_controller;
    newscript->Name = "mob_kiljaeden_controller";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_hand_of_the_deceiver;
    newscript->Name = "mob_hand_of_the_deceiver";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_felfire_portal;
    newscript->Name = "mob_felfire_portal";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_volatile_felfire_fiend;
    newscript->Name = "mob_volatile_felfire_fiend";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_armageddon;
    newscript->Name = "mob_armageddon";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_shield_orb;
    newscript->Name = "mob_shield_orb";
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->GetAI = &GetAI_mob_sinster_reflection;
    newscript->Name = "mob_sinster_reflection";
    newscript->RegisterSelf();
};
