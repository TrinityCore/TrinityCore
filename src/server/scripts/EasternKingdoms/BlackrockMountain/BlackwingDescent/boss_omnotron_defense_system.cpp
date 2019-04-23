#include "ScriptMgr.h"
#include "blackwing_descent.h"
#include "Vehicle.h"
#include "Unit.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "VehicleDefines.h"
#include "Spell.h"
#include "Player.h"
#include "Map.h"
#include "InstanceScript.h"

enum NefYells
{
   // Nefarian - Heroic
   SAY_START             = 3,
   SAY_TOO_BAD           = 4,
   SAY_STORY             = 5,
   SAY_LIGHTNING         = 6,
   SAY_TOXITRON_CHEMICAL = 7,
   SAY_FINISH            = 2,
   SAY_FINISH_H          = 8
};

enum OmnoYells
{
   // Normal - Omnotron
   SAY_AGGRO             = 0,
   SAY_DEATH             = 1,
   SAY_ELECTRON_ACTIVE   = 2,
   SAY_MAGMATRON_ACTIVE  = 3,
   SAY_TOXITRON_ACTIVE   = 4,
   SAY_ARCANOTRON_ACTIVE = 5,
   SAY_ELECTRON_SHIELD   = 6,
   SAY_MAGMATRON_SHIELD  = 7,
   SAY_TOXITRON_SHIELD   = 8,
   SAY_ARCANOTRON_SHIELD = 9,
   SAY_MAGMATRON_FLAMET  = 10
};

enum Spells
{
    // Omnitron
    SPELL_INACTIVE                = 78726,
    SPELL_SHUTTING_DOWN           = 78746,
    SPELL_ACTIVATED               = 78740,
    SPELL_ACTIVATED_H             = 95016,
    SPELL_NO_REGEN                = 78725,

    // Jumbotron (statue)
    SPELL_PURPLE_BEAM             = 78699,
    SPELL_BLUE_BEAM               = 78697,
    SPELL_RED_BEAM                = 78698,
    SPELL_GREEN_BEAM              = 78700,

    // Electron
    SPELL_LIGHTNING_CONDUCTOR     = 79888,
    SPELL_ELECTRICAL_DISCHARGE    = 91465,
    SPELL_UNSTABLE_SHIELD         = 79900,
    SPELL_UNSTABLE_SHIELD_MISSILE = 79911,
    SPELL_UNSTABLE_SHIELD_DAMAGE  = 79912,
    // Toxitron
    SPELL_CHEMICAL_BOMB           = 80157,
    SPELL_POISON_SOAKED_SHELL     = 79835,
    SPELL_POISON_PROTOCOL         = 80053,
    // Magmatron
    SPELL_BARRIER                 = 79582,
    SPELL_BACKDRAFT               = 79617, // on barrier removal.
    SPELL_ACQUIRING_TARGET        = 79501,
    SPELL_FLAMETHROWER            = 79504,
    SPELL_INCINERATION_SECURITY   = 79023,
    // Arcanotron
    SPELL_POWER_GENERATOR         = 79626,
    SPELL_ARCANE_ANNIHILATOR      = 79710,
    SPELL_POWER_CONVERSION        = 79729,

    // Poison Bomb
    SPELL_FIXER                   = 80094,
    SPELL_BOMB_EXPLODE            = 80092,
    SPELL_POISON_PUDDLE           = 80095, // Where poison bomb explodes.

    // Chemical cloud
    SPELL_CLOUD                   = 80162,
    SPELL_CLOUD1                  = 80163,

    // Power generator
    SPELL_POWER_GENERATOR_AURA    = 79628,

   // Nefarian Heroic
   SPELL_GRIP_OF_DEATH            = 91849, // Pulls people into the chemical cloud. On Toxitron buffed.
   SPELL_ENCASING_SHADOWS         = 92023, // Magmatron.
   SPELL_OVERCHARGED_POWER_GENER  = 91857, // Grows and explodes with arcane bb. Arcanotron.
   SPELL_GROW                     = 44834, // Grow twice as big, then explode and cause chaos.
   SPELL_ARCANE_BLOWBACK          = 91879,
   SPELL_SHADOW_INFUSION          = 92048, // On target with lightning conductor, after 5 sec shadow conductor. Electron.
   SPELL_SHADOW_CONDUCTOR         = 92053  // Deals damage to players depending on distance from it.
};

enum Summons
{
    MOB_POISON_BOMB     = 42897,
    MOB_POISON_PUDDLE   = 42920,
    MOB_CHEMICAL_CLOUD  = 42934,
    MOB_POWER_GENERATOR = 42733
};

enum Events
{
    // General
    EVENT_SHUT_DOWN = 1,
    EVENT_ACTIVATE,

    // Omnotron
    EVENT_ACTIVATE_NEXT_CONSTRUCT,
    EVENT_UPDATE_HEALTH,

    // Magmatron
    EVENT_ACQUIRING_TARGET,
    EVENT_INCINERATION_SECURITY_MEASURE,
    EVENT_BARRIER,
    // Toxitron
    EVENT_CHEMICAL_BOMB,
    EVENT_POISON_PROTOCOL,
    EVENT_POISON_SOAKED_SHELL,
    // Electron
    EVENT_LIGHTNING_CONDUCTOR,
    EVENT_ELECTRICAL_DISCHARGE,
    EVENT_UNSTABLE_SHIELD,
    // Arcanotron
    EVENT_POWER_CONVERSION,
    EVENT_POWER_GENERATOR,
    EVENT_ARCANE_ANNIHILATOR,

    // Poison bomb
    EVENT_POISON_MOVE,

    // Heroic
    EVENT_GRIP_OF_DEATH,
    EVENT_ENCASING_SHADOWS,
    EVENT_OVERCHARGED_PG,
    EVENT_GENERATOR_EXPLODE,
    EVENT_SHADOW_INFUSION
};

enum Actions
{
    ACTION_OMNOTRON_START_EVENT,
    ACTION_OMNOTRON_RESET,
    ACTION_OMNNOTRON_EVENT_FINISHED,

    ACTION_TRON_ACTIVATE,
    ACTION_EVENT_FAILED,
    ACTION_DEACTIVATE
};

enum Misc
{
    DATA_IS_FIRST_TRON
};

Position const wayPos[2] =
{
    {-315.853f, -400.56f, 213.974f},
    {-334.152f, -400.321f, 214.005f}
};

class boss_omnotron : public CreatureScript
{
public:
    boss_omnotron() : CreatureScript("boss_omnotron") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_omnotronAI (creature);
    }

    struct boss_omnotronAI : public ScriptedAI
    {
        boss_omnotronAI(Creature* creature) : ScriptedAI(creature), intialized(false), eventActive(false)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        bool intialized;
        bool isEncounterDone;

        Creature* trons[4];

        uint8 activateTron;
        bool eventActive;

        void UpdateAI(uint32 diff) override
        {
            if(me->HasAura(SPELL_INACTIVE))
                me->RemoveAura(SPELL_INACTIVE);

            if(!intialized)
            {
                trons[0] = me->FindNearestCreature(NPC_MAGMATRON, 150.0f, true);
                trons[1] = me->FindNearestCreature(NPC_ELECTRON, 150.0f, true);
                trons[2] = me->FindNearestCreature(NPC_ARCANOTRON, 150.0f, true);
                trons[3] = me->FindNearestCreature(NPC_TOXITRON, 150.0f, true);

                for(uint8 i = 0; i<=3; i++)
                    if(trons[i] == nullptr)
                        return;

                me->SetMaxHealth(trons[0]->GetMaxHealth());

                eventActive = true;
                intialized = true;
                DoAction(ACTION_OMNOTRON_RESET);
            }

            if (intialized == true)
            {
                if (!me->FindNearestCreature(NPC_MAGMATRON, 150.0f, true) || !me->FindNearestCreature(NPC_ELECTRON, 150.0f, true) || !me->FindNearestCreature(NPC_ARCANOTRON, 150.0f, true) || !me->FindNearestCreature(NPC_TOXITRON, 150.0f, true)) // if any of the trons are dead
                    DoAction(ACTION_OMNNOTRON_EVENT_FINISHED); // Finish event.

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {

                    case EVENT_UPDATE_HEALTH:
                        for(uint8 i = 0; i<=3; i++)
                            trons[i]->SetHealth(me->GetHealth());

                        events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                        break;

                    case EVENT_ACTIVATE_NEXT_CONSTRUCT:
                        ActivateNextTron();

                        if (trons[1]->GetEntry() == NPC_MAGMATRON)
                            me->CastSpell(trons[1],SPELL_RED_BEAM,true);
                        else if (trons[1]->GetEntry() == NPC_ELECTRON)
                            me->CastSpell(trons[1],SPELL_BLUE_BEAM,true);
                        else if (trons[1]->GetEntry() == NPC_TOXITRON)
                            me->CastSpell(trons[1],SPELL_GREEN_BEAM,true);
                        else if (trons[1]->GetEntry() == NPC_ARCANOTRON)
                            me->CastSpell(trons[1],SPELL_PURPLE_BEAM,true);

                        if(me->GetMap()->IsHeroic())
                            events.ScheduleEvent(EVENT_ACTIVATE_NEXT_CONSTRUCT, 30000);
                        else
                            events.ScheduleEvent(EVENT_ACTIVATE_NEXT_CONSTRUCT, 45000);
                        break;
                    }
                }
            }
        }

        void DoAction(const int32 action) override
        {
            switch(action)
            {
            case ACTION_OMNOTRON_START_EVENT:
                // Start Encounter
                if (instance)
                    instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, IN_PROGRESS);

                eventActive = true;
                me->SetInCombatWithZone();
                if(me->GetMap()->IsHeroic())
                    me->SummonCreature(NPC_NEFARIAN_HELPER_HEROIC,-302.121f, -349.35f, 220.48f, 4.682203f,TEMPSUMMON_MANUAL_DESPAWN);

                if(me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_ACTIVATE_NEXT_CONSTRUCT, 30000);
                else
                    events.ScheduleEvent(EVENT_ACTIVATE_NEXT_CONSTRUCT, 45000);
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                break;

            case ACTION_OMNOTRON_RESET:
                // Resets Encounter

                if(eventActive)
                {
                    me->SetFullHealth();
                    me->RemoveAllAuras();
                    me->CombatStop(false);
                    me->DeleteThreatList();
                    eventActive = false;

                    DespawnMinions();
                    events.Reset();

                    ResetTrons();

                    if (instance)
                    instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, FAIL);
                }
                break;

            case ACTION_OMNNOTRON_EVENT_FINISHED:

                DespawnMinions();

                if (instance)
                    instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, DONE);

                events.Reset();
                eventActive = false;
                break;

            default:
                break;
            }
        }

        void ResetTrons()
        {
            for(uint8 i = 0; i<=3; i++)
                if(trons[i] == NULL)
                    return;

            for(uint8 i = 0; i<=3; i++)
                trons[i]->AI()->SetData(DATA_IS_FIRST_TRON, 0);

            uint8 a = urand(15,25);
            Creature* tronCache;
            for(uint8 i = 0; i<=a; i++)
            {
                uint8 moveDest = urand(0,3);
                uint8 moveTarget = urand(0,3);

                tronCache = trons[moveTarget];
                trons[moveTarget] = trons[moveDest];
                trons[moveDest] = tronCache;
            }

            for(uint8 i = 0; i<=3; i++)
                DoCast(trons[i], SPELL_INACTIVE);

            trons[0]->AI()->SetData(DATA_IS_FIRST_TRON, 1);

            for(uint8 i = 0; i<=3; i++)
                trons[i]->AI()->DoAction(ACTION_EVENT_FAILED);
        };

        void ActivateNextTron()
        {
            for(uint8 i = 0; i<=3; i++)
                if(trons[i] == NULL)
                    return;

            // Select next Tron
            Creature* tronCache = trons[0];

            // Push tron list one step to first place
            for(uint8 i = 1; i<=3; i++)
                trons[i-1] = trons[i];

            trons[3] = tronCache;

            // Activate first Tron
            trons[0]->AI()->DoAction(ACTION_TRON_ACTIVATE);
            return;
        }

    private:
        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_POISON_BOMB);
            DespawnCreatures(NPC_POISON_CLOUD);
            DespawnCreatures(NPC_NEFARIAN_HELPER_HEROIC);
            DespawnCreatures(NPC_POWER_GENERATOR);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 100.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
    };
};

class boss_trons : public CreatureScript
{
public:
    boss_trons() : CreatureScript("boss_trons") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_tronsAI (creature);
    }

    struct boss_tronsAI : public ScriptedAI
    {
        boss_tronsAI(Creature* creature) : ScriptedAI(creature), activated(false), isFirstTron(false)
        {
            instance = creature->GetInstanceScript();
            creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            creature->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            ASSERT(creature->GetVehicleKit()); // we dont actually use it, just check if exists
            homePosition = creature->GetHomePosition();
            creature->SetPower(POWER_ENERGY, 100);
            creature->SetMaxPower(POWER_ENERGY, 100);
            NowPos = 1;
        }

        InstanceScript* instance;
        EventMap events;
        int32 NowPos;
        bool activated;
        bool isFirstTron;
        bool isMovingHome;
        Position homePosition;
        Creature* omnotron;

        void EnterCombat(Unit* /*who*/) override
        {
            if(isFirstTron)
            {
                if (Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                {
                    omnotron->AI()->DoAction(ACTION_OMNOTRON_START_EVENT);
                    omnotron->AI()->Talk(SAY_AGGRO);
                }

                me->RemoveAura(SPELL_INACTIVE);
                DoAction(ACTION_TRON_ACTIVATE);
                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                    nefarian->AI()->Talk(SAY_START);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                omnotron->AI()->Talk(SAY_DEATH);

            if (me->GetMap()->IsHeroic())
            {
                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                    nefarian->AI()->Talk(SAY_FINISH_H);
            }
            else if (!me->GetMap()->IsHeroic())
            {
                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                    nefarian->AI()->Talk(SAY_FINISH);
            }

            if(instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id > 3)
                return;

            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);

            switch(id)
            {
            case 0:
                if(!isFirstTron && isMovingHome)
                {
                    isMovingHome = false;
                    me->NearTeleportTo(homePosition.GetPositionX(),homePosition.GetPositionY(),homePosition.GetPositionZ(),homePosition.GetOrientation());
                    me->SetOrientation(homePosition.GetOrientation());
                    me->RemoveAura(SPELL_NO_REGEN);
                    DoCast(me, SPELL_INACTIVE);
                    me->RemoveAura(me->GetMap()->IsHeroic() ? SPELL_ACTIVATED_H : SPELL_ACTIVATED);
                    /*WorldPacket data;
                    me->BuildHeartBeatMsg(&data);
                    me->SendMessageToSet(&data, false);*/
                }
                break;
            case 1:
                NowPos = 2;
                break;
            case 2:
                NowPos = 1;
                break;
            case 3:
                DoCast(me, SPELL_INACTIVE);
                me->NearTeleportTo(homePosition.GetPositionX(),homePosition.GetPositionY(),homePosition.GetPositionZ(),homePosition.GetOrientation());
                me->SetOrientation(homePosition.GetOrientation());
                break;
            }

        }

        void Reset() override
        {
            if (instance)
                instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, NOT_STARTED);

            if (Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                omnotron->AI()->DoAction(ACTION_OMNOTRON_RESET);
        };

        void DoAction(const int32 action) override
        {
            events.Reset();

            switch(action)
            {
                case ACTION_TRON_ACTIVATE:
                    me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat(me);
                    if(instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                    me->AddAura(SPELL_NO_REGEN, me);
                    DoCast(me, me->GetMap()->IsHeroic() ? SPELL_ACTIVATED_H : SPELL_ACTIVATED);
                    activated = true;
                    isMovingHome = false;

                    // Intialize Events
                    switch(me->GetEntry())
                    {
                        case NPC_MAGMATRON:
                            if(me->HasAura(SPELL_RED_BEAM))
                               me->RemoveAura(SPELL_RED_BEAM);
                            events.ScheduleEvent(EVENT_ACQUIRING_TARGET, 35000);
                            events.ScheduleEvent(EVENT_INCINERATION_SECURITY_MEASURE, 27000);
                            if(me->GetMap()->IsHeroic())
                                events.ScheduleEvent(EVENT_BARRIER, 33000);
                            else
                                events.ScheduleEvent(EVENT_BARRIER, 49500);
                            break;

                        case NPC_TOXITRON:
                            if(me->HasAura(SPELL_GREEN_BEAM))
                               me->RemoveAura(SPELL_GREEN_BEAM);
                            events.ScheduleEvent(EVENT_CHEMICAL_BOMB, 20000);
                            events.ScheduleEvent(EVENT_POISON_PROTOCOL, 35000);
                            if(me->GetMap()->IsHeroic())
                                events.ScheduleEvent(EVENT_POISON_SOAKED_SHELL, 33000);
                            else
                                events.ScheduleEvent(EVENT_POISON_SOAKED_SHELL, 49500);
                            break;

                        case NPC_ELECTRON:
                            if(me->HasAura(SPELL_BLUE_BEAM))
                               me->RemoveAura(SPELL_BLUE_BEAM);
                            events.ScheduleEvent(EVENT_LIGHTNING_CONDUCTOR, 25000);
                            events.ScheduleEvent(EVENT_ELECTRICAL_DISCHARGE, 12000);
                            if(me->GetMap()->IsHeroic())
                                events.ScheduleEvent(EVENT_UNSTABLE_SHIELD, 33000);
                            else
                                events.ScheduleEvent(EVENT_UNSTABLE_SHIELD, 49500);
                            break;

                        case NPC_ARCANOTRON:
                            if(me->HasAura(SPELL_PURPLE_BEAM))
                               me->RemoveAura(SPELL_PURPLE_BEAM);
                            events.ScheduleEvent(EVENT_POWER_GENERATOR, 30000);
                            events.ScheduleEvent(EVENT_ARCANE_ANNIHILATOR, 6000);
                            if(me->GetMap()->IsHeroic())
                                events.ScheduleEvent(EVENT_POWER_CONVERSION, 11000);
                            else
                                events.ScheduleEvent(EVENT_POWER_CONVERSION, 29500);
                            break;
                    }
                    break;

                case ACTION_EVENT_FAILED:
                    if(!isFirstTron)
                    { // is not First Tron
                        DoAction(ACTION_DEACTIVATE);
                    }else
                    { // is First Tron
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveAllAuras();
                        me->DeleteThreatList();
                        me->CombatStop(true);
                        me->AttackStop();
                        if(instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->GetMotionMaster()->MovePoint(1, wayPos[0]);
                        activated = true;
                        isMovingHome = false;
                    }
                    break;

                case ACTION_DEACTIVATE:
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->DeleteThreatList();
                    me->CombatStop(true);
                    me->RemoveAllAuras();
                    if(instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    me->GetMotionMaster()->MovePoint(0, homePosition);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    isMovingHome = true;
                    activated = false;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (isFirstTron)
                if (Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                    if (!omnotron->IsInCombat())
                        me->GetMotionMaster()->MovePoint(NowPos, wayPos[(NowPos - 1)]);

            if (!UpdateVictim() || !activated)
                return;

            events.Update(diff);

            if (me->GetPower(POWER_ENERGY) == 0)
            {
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->DeleteThreatList();
                me->CombatStop(true);
                me->RemoveAllAuras();
                activated = false;
                isMovingHome = false;
                me->SetPower(POWER_ENERGY, 100);
                if(instance)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAura(me->GetMap()->IsHeroic() ? SPELL_ACTIVATED_H : SPELL_ACTIVATED);
                DoCast(me, SPELL_SHUTTING_DOWN);
                return;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    // Magmatron
                case EVENT_ACQUIRING_TARGET:
                    if(Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                        omnotron->AI()->Talk(SAY_MAGMATRON_FLAMET);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        DoCast(pTarget, SPELL_ACQUIRING_TARGET);
                        if(me->GetMap()->IsHeroic())
                            if(urand(1,3) == 1) // 33% chance to do it.
                                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                                {
                                    nefarian->AI()->Talk(SAY_TOO_BAD);
                                    nefarian->CastSpell(pTarget, SPELL_ENCASING_SHADOWS, true);
                                    nefarian->AddAura(SPELL_ENCASING_SHADOWS, pTarget);
                                }
                    }
                    events.ScheduleEvent(EVENT_ACQUIRING_TARGET, 40000);
                    break;
                case EVENT_INCINERATION_SECURITY_MEASURE:
                    DoCastAOE(SPELL_INCINERATION_SECURITY);
                    events.ScheduleEvent(EVENT_INCINERATION_SECURITY_MEASURE, urand(28000, 33000));
                    break;
                case EVENT_BARRIER:
                    DoCast(me, SPELL_BARRIER);
                    if(Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                        omnotron->AI()->Talk(SAY_MAGMATRON_SHIELD);
                    return;

                    // Toxitron
                case EVENT_CHEMICAL_BOMB:
                    if(me->GetMap()->IsHeroic())
                    {
                        if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                            nefarian->AI()->Talk(SAY_TOXITRON_CHEMICAL);
                        if(urand(1,3) == 1) // 33% chance to do it.
                        events.ScheduleEvent(EVENT_GRIP_OF_DEATH, 3000);
                    }
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_CHEMICAL_BOMB);
                    events.ScheduleEvent(EVENT_CHEMICAL_BOMB, 30000);
                    break;
                case EVENT_GRIP_OF_DEATH:
                    if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                        if (Creature* poisoncloud = me->FindNearestCreature(MOB_CHEMICAL_CLOUD, 100.0f, true))
                        {
                            nefarian->NearTeleportTo(poisoncloud->GetPositionX(), poisoncloud->GetPositionY(), poisoncloud->GetPositionZ(), poisoncloud->GetOrientation());
                            nefarian->CastSpell(nefarian, SPELL_GRIP_OF_DEATH, false);
                        }
                    return;
                case EVENT_POISON_PROTOCOL:
                    DoCast(me, SPELL_POISON_PROTOCOL);
                    events.ScheduleEvent(EVENT_POISON_PROTOCOL, 40000);
                    break;
                case EVENT_POISON_SOAKED_SHELL:
                    DoCast(me, SPELL_POISON_SOAKED_SHELL);
                    if(Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                        omnotron->AI()->Talk(SAY_TOXITRON_SHIELD);
                    return;

                    // Electron
                case EVENT_LIGHTNING_CONDUCTOR:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        DoCast(pTarget, SPELL_LIGHTNING_CONDUCTOR);
                        if(me->GetMap()->IsHeroic())
                        {
                            if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                                nefarian->AI()->Talk(SAY_LIGHTNING);
                            if(urand(1,3) == 1) // 33% chance to do it.
                                pTarget->AddAura(SPELL_SHADOW_INFUSION, pTarget);
                        }
                    }
                    events.ScheduleEvent(EVENT_LIGHTNING_CONDUCTOR, 20000);
                    break;
                case EVENT_ELECTRICAL_DISCHARGE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_ELECTRICAL_DISCHARGE);
                    events.ScheduleEvent(EVENT_ELECTRICAL_DISCHARGE, urand(8000, 13000));
                    break;
                case EVENT_UNSTABLE_SHIELD:
                    DoCast(me, SPELL_UNSTABLE_SHIELD);
                    if(Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                        omnotron->AI()->Talk(SAY_ELECTRON_SHIELD);
                    return;

                    // Arcanotron
                case EVENT_POWER_CONVERSION:
                    DoCast(me, SPELL_POWER_CONVERSION);
                    if(Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
                        omnotron->AI()->Talk(SAY_ARCANOTRON_SHIELD);
                    return;
                case EVENT_POWER_GENERATOR:
                    if(me->GetMap()->IsHeroic())
                    {
                        if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 100.0f, true))
                            nefarian->AI()->Talk(SAY_STORY);
                        if(urand(1,3) == 1) // 33% chance to do it.
                        events.ScheduleEvent(EVENT_OVERCHARGED_PG, 1000);
                    }
                    DoCast(me, SPELL_POWER_GENERATOR);
                    events.ScheduleEvent(EVENT_POWER_GENERATOR, 30000);
                    break;
                case EVENT_OVERCHARGED_PG:
                        if (Unit* generator = me->FindNearestCreature(MOB_POWER_GENERATOR, 100.0f, true))
                        {
                            generator->CastSpell(generator, SPELL_OVERCHARGED_POWER_GENER, true);
                            generator->AddAura(SPELL_GROW, generator);
                            events.ScheduleEvent(EVENT_GENERATOR_EXPLODE, 10000);
                        }
                    return;
                case EVENT_GENERATOR_EXPLODE:
                        if (Unit* generator = me->FindNearestCreature(MOB_POWER_GENERATOR, 100.0f, true))
                        generator->CastSpell(generator, SPELL_ARCANE_BLOWBACK, true);
                    return;
                case EVENT_ARCANE_ANNIHILATOR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_ARCANE_ANNIHILATOR);
                    events.ScheduleEvent(EVENT_ARCANE_ANNIHILATOR, 7500);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void SetData(uint32 Type, uint32 Data) override
        {
            if(Type != DATA_IS_FIRST_TRON)
                return;

            me->SetFullHealth();

            isFirstTron = (Data == 0) ? false : true;
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if(me->HasAura(SPELL_UNSTABLE_SHIELD)) // For electron thingy.
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    DoCast(target, SPELL_UNSTABLE_SHIELD_MISSILE); // on random target xD

            if(Creature* omnotron = me->FindNearestCreature(BOSS_OMNOTRON, 100.0f, true))
            {
                if(damage >= omnotron->GetHealth() - 1)
                {
                    omnotron->SetHealth(omnotron->GetMaxHealth() - 1); // don't die, stupid.
                    omnotron->AI()->DoAction(ACTION_OMNNOTRON_EVENT_FINISHED);

                    Creature* trons[4];
                    trons[0] = me->FindNearestCreature(NPC_MAGMATRON, 150.0f, true);
                    trons[1] = me->FindNearestCreature(NPC_ELECTRON, 150.0f, true);
                    trons[2] = me->FindNearestCreature(NPC_ARCANOTRON, 150.0f, true);
                    trons[3] = me->FindNearestCreature(NPC_TOXITRON, 150.0f, true);

                    for(uint8 i = 0; i<=3; i++)
                        if(trons[i] && trons[i] != me)
                            trons[i]->DespawnOrUnsummon(100);

                    omnotron->DespawnOrUnsummon(5000);
                }
                else
                    omnotron->SetHealth(omnotron->GetHealth()- damage);
            }

        }

        void JustSummoned(Creature* summon) override
        {
            summon->setFaction(me->getFaction());
            if(summon->GetEntry() != MOB_POISON_BOMB)
            summon->SetInCombatWithZone();

            switch(summon->GetEntry())
            {
            case NPC_POWER_GENERATOR:
                summon->SetReactState(REACT_PASSIVE);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                summon->DespawnOrUnsummon(30000);
                break;
            }
        }

    };
};

class npc_poison_bomb : public CreatureScript // 42897
{
public:
    npc_poison_bomb() : CreatureScript("npc_poison_bomb") { }

    struct npc_poison_bombAI : public ScriptedAI
    {
        npc_poison_bombAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 uiFixate;
        bool HasTarget;
        Unit* myTarget;

        void IsSummonedBy(Unit* /*who*/) override
        {
            uiFixate = 3000;
            HasTarget = false;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (HasTarget)
                me->GetMotionMaster()->MoveChase(myTarget);

            if(uiFixate <= uiDiff)
            {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                {
                    myTarget = target;
                    HasTarget = true;
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(target, SPELL_FIXER);
                    uiFixate = 200000;
                }
                else uiFixate = 2000;
            } else uiFixate -= uiDiff;

            if(HasTarget && me->GetDistance(myTarget) <= 2.0f)
            {
                DoCast(me, SPELL_BOMB_EXPLODE);
                me->SummonCreature(MOB_POISON_PUDDLE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                me->DespawnOrUnsummon();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_poison_bombAI(creature);
    }
};

class npc_poison_puddle : public CreatureScript // 42920
{
public:
    npc_poison_puddle() : CreatureScript("npc_poison_puddle") { }

    struct npc_poison_puddleAI : public ScriptedAI
    {
        npc_poison_puddleAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        void IsSummonedBy(Unit* /*who*/) override
        {
            DoCast(me, SPELL_POISON_PUDDLE);
            me->SetReactState(REACT_PASSIVE);
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_poison_puddleAI(creature);
    }
};

class npc_chemical_cloud : public CreatureScript // 42934
{
public:
    npc_chemical_cloud() : CreatureScript("npc_chemical_cloud") { }

    struct npc_chemical_cloudAI : public ScriptedAI
    {
        npc_chemical_cloudAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 uiDespawn;

        void Reset() override
        {
            uiDespawn = 30000;
            DoCast(me, SPELL_CLOUD);
            DoCast(me, SPELL_CLOUD1);
            me->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            uiDespawn = 30000;
            DoCast(me, SPELL_CLOUD);
            DoCast(me, SPELL_CLOUD1);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if(uiDespawn <= uiDiff)
            {
                me->DespawnOrUnsummon();
            } else uiDespawn -= uiDiff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chemical_cloudAI(creature);
    }
};

class npc_power_generator : public CreatureScript // 42733
{
public:
    npc_power_generator() : CreatureScript("npc_power_generator") { }

    struct npc_power_generatorAI : public ScriptedAI
    {
        npc_power_generatorAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 uiDespawn;

        void Reset() override
        {
            uiDespawn = 60000;
            DoCast(me, SPELL_POWER_GENERATOR_AURA);
            me->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            uiDespawn = 60000;
            DoCast(me, SPELL_POWER_GENERATOR_AURA);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if(uiDespawn <= uiDiff)
            {
                me->DespawnOrUnsummon();
            } else uiDespawn -= uiDiff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_power_generatorAI(creature);
    }
};

class spell_shadow_conductor : public SpellScriptLoader // 92051
{
    public:
        spell_shadow_conductor() : SpellScriptLoader("spell_shadow_conductor") { }

        class spell_shadow_conductor_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_conductor_SpellScript);

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;

                float distance = GetCaster()->GetDistance2d(GetHitUnit());
                if (distance > 1.0f)
                    SetHitDamage(int32(2500 * distance));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_shadow_conductor_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shadow_conductor_SpellScript();
        }
};

class spell_omnotron_active_trigger : public SpellScriptLoader
{
public:
    spell_omnotron_active_trigger() : SpellScriptLoader("spell_omnotron_active_trigger") { }


    class spell_omnotron_active_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_omnotron_active_trigger_SpellScript);


        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!(GetHitUnit() && GetHitUnit()->IsAlive()))
                return;

            if (Unit* caster = GetCaster())
            {
                if (caster->GetPower(POWER_ENERGY) >= 1)
                    caster->SetPower(POWER_ENERGY, caster->GetPower(POWER_ENERGY) - 1);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_omnotron_active_trigger_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_omnotron_active_trigger_SpellScript();
    }
};

class spell_fire : public SpellScriptLoader
{
    public:
        spell_fire() : SpellScriptLoader("spell_fire") { }

        class spell_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_fire_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                GetCaster()->AddAura(79505,GetCaster());
                GetCaster()->AddAura(79505,GetTarget());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_fire_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_fire_AuraScript();
        }
};

void AddSC_boss_omnotron_defense_system()
{
    new boss_omnotron();
    new boss_trons();
    new npc_poison_bomb();
    new npc_poison_puddle();
    new npc_chemical_cloud();
    new npc_power_generator();
    new spell_shadow_conductor();
    new spell_omnotron_active_trigger();
    new spell_fire();
}
