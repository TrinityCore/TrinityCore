/*
 * Copyright 2023 AzgathCore
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

#include "antorus.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "ScriptedGossip.h"

enum eSays
{
    //Eonar
    SAY_PULL = 0,
    SAY_FINAL_DOOM = 1,
    SAY_LIFE_FORCE_1 = 2,
    SAY_LIFE_FORCE_2 = 3,
    SAY_LIFE_FORCE_3 = 4,
    SAY_LIFE_FORCE_4 = 5,
    SAY_WIPE = 6,

    //Paraxis
    SAY_WARN_SPEAR_OF_DOOM = 0,
    SAY_WARN_FINAL_DOOM = 1,
    SAY_WARN_PURGE = 2,
    SAY_WARN_RAIN_OF_FEL = 3,
};

enum Spells
{
    SPELL_OUTRO_CONV = 249674,
    SPELL_TELEPORT = 254245,
    SPELL_EONAR_BONUS_ROLL = 250602,
    SPELL_DAILY_ESSENCE_EONAR = 305311,

    //Eonar
    SPELL_LIFE_ENERGY = 257673,
    SPELL_LIFE_FORCE = 250048,
    SPELL_LIFE_FORCE_PARAXIS_DMG = 250030,
    SPELL_LIFE_FORCE_VISUAL = 250043,
    SPELL_LIFE_FORCE_FILTER = 250467,
    SPELL_LIFE_FORCE_DMG = 254269,

    SPELL_JUMP_PAD_AT = 248222,
    SPELL_SWIFT_FEET = 246330,
    SPELL_TELEPORTER_AT = 249094, //Mythic
    SPELL_TP_PLAYER_ON_PARAXIS = 249103,

    //Paraxis
    SPELL_WARP_IN = 247214,
    SPELL_PARAXIS_EXPLOSION = 250361, //Encounter finish
    SPELL_PARAXIS_ARTILLERY_PERIODIC = 248836,
    SPELL_PARAXIS_ARTILLERY_FILTER = 246313,
    SPELL_PARAXIS_ARTILLERY_DMG = 246315,
    SPELL_RAIN_OF_FEL_FILTER = 248326,
    SPELL_RAIN_OF_FEL_MARK = 248332,
    SPELL_RAIN_OF_FEL_DMG = 248329,

    SPELL_SPEAR_OF_DOOM_FILTER = 248861, //Heroic+
    SPELL_SPEAR_OF_DOOM_SUMMON = 248791,
    SPELL_SPEAR_OF_DOOM_AT = 248789,

    SPELL_FINAL_DOOM = 249121, //Mythic
    SPELL_PURGE = 249934,

    //Generic Trash
    SPELL_VISUAL_SMALL_SHIP = 246896,
    SPELL_VISUAL_BIG_SHIP = 246888,
    SPELL_DEMONIC_PORTAL_VISUAL = 247189,
    SPELL_SPAWN_TRASH_VISUAL = 246951,
    SPELL_STRIKE = 245851,

    //NPC_FELGUARD
    SPELL_FELGUARD_WEAPONS_VISUAL = 247922,

    //NPC_FEL_LORD
    SPELL_FEL_LORD_WEAPONS_VISUAL = 247928,

    //NPC_VOLANT_KERAPTERON
    SPELL_SPAWN_KERAPTERON_VISUAL = 246959,
    SPELL_DEMON_ESCAPE = 252309, //unk

    //NPC_FEL_CHARGED_OBFUSCATOR
    SPELL_CLOAK_AT = 246753,
    SPELL_CLOAK_MOD_DMG = 246748,

    //NPC_FEL_INFUSED_DESTRUCTOR
    SPELL_HIGH_ALERT = 254769,
    SPELL_ARTILLERY_STRIKE = 246305,
    SPELL_ARTILLERY_MODE = 246301,

    //NPC_FEL_POWERED_PURIFIER
    SPELL_PURIFIIER = 246745,
    SPELL_PURIFICATION_AT = 250073,
    SPELL_PURIFICATION_VISUAL = 255137,
    SPELL_PURIFIIER_HIGH_ALERT = 246233,
    SPELL_PURIFIIER_FEL_SHIELDING = 250555,
    SPELL_SWING_DUMMY = 250706,
    SPELL_SWING_RIGHT = 250701,
    SPELL_SWING_LEFT = 250703,

    //NPC_PARAXIS_INQUISITOR
    SPELL_MIND_BLAST = 249196,
    SPELL_PAIN = 249194,
    SPELL_WRACK = 249126,
    SPELL_TORMENT = 249155,

    //Focusing Crystal
    SPELL_SHATTER = 250081,
    SPELL_TARGETED = 249016,
    SPELL_BURNING_EMBERS = 249015,
    SPELL_FOUL_STEPS = 249014,
    SPELL_ARCANE_SINGULARITY = 249017,
};

enum Events
{
    //Eonar
    EVENT_ENGAGE = 1,

    //Paraxis
    EVENT_COMBAT_ZONE = 1,
    EVENT_CHECK_PLAYERS = 2,
    EVENT_SUMMON_SHIP = 3,
    EVENT_KERAPTERON_PORTAL = 4,
    EVENT_RAIN_OF_FEL = 5,
    EVENT_SPEAR_OF_DOOM = 6, //Heroic+
    EVENT_FINAL_DOOM = 7, //Mythic
};

enum Actions
{
    //Eonar
    ACTION_RESTART = 1,
    ACTION_ENCOUNTER_COMPLETE = 2,

    //Paraxis
    ACTION_EVADE = 1,
    ACTION_CRYSTAL_DISABLE = 2,

    ACTION_1,
    ACTION_2,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

enum eMisc
{
    GOSSIP_ID_EONAR = 21203,
    GOSSIP_EONAR_NOT_STARTED = 32173,
    GOSSIP_EONAR_DONE = 33006,

    PATH_MID = 12444500,
    PATH_TOP = 12444501,
    PATH_BOT = 12444502,
    PATH_FLY = 12444503,
};

//NPC_INVASION_POINT - VIGNETTE
Position const invastionPos[4] =
{
    {-3983.17f, -10928.7f, 721.68f, 0.095f}, //Mid
    {-3876.61f, -10931.9f, 685.84f, 0.095f}, //Bot
    {-3931.62f, -10673.2f, 751.47f, 0.095f}, //Top
    {-4010.63f, -10679.4f, 753.04f, 0.070f}  //Fly
};

Position const shipPos[6] =
{
    //NPC_LEGION_SHIP_SMALL
    {-3982.94f, -10864.4f, 755.08f, 0.09f}, //Mid
    {-3906.69f, -10938.6f, 755.08f, 0.04f}, //Bot
    {-3908.35f, -10699.5f, 783.14f, 0.06f}, //Top

    //NPC_LEGION_SHIP_BIG
    {-3995.78f, -10879.9f, 755.08f, 0.09f}, //Mid
    {-3875.13f, -10908.0f, 755.08f, 0.04f}, //Bot
    {-3961.0f,  -10653.3f, 785.81f, 0.06f}  //Top
};

Position const trashPos[4] =
{
    {-3993.1f, -10939.0f, 721.8f, 0.8f}, //Mid
    {-3880.1f, -10927.4f, 685.9f, 2.4f}, //Bot
    {-3927.6f, -10668.0f, 751.6f, 4.0f}, //Top
    {-4003.0f, -10650.1f, 760.0f, 4.6f}  //Fly
};

Position const destructorPos[3] =
{
    {-3995.67f, -10905.17f, 721.60f, 1.12f},
    {-3896.17f, -10900.24f, 685.96f, 1.88f},
    {-3948.66f, -10689.98f, 751.36f, 3.74f}
};

//Visual
Position const lifeForcePos[4] =
{
    {-4111.94f, -10677.2f,  736.0f},
    {-4105.15f, -10689.87f, 729.02f},
    {-4105.33f, -10728.01f, 736.0f},
    {-4132.49f, -10723.22f, 749.58f}
};

//AT from Paraxis
Position const teleportPos[8] =
{
    {-4011.47f, -10717.76f, 696.82f},
    {-4016.53f, -10728.44f, 696.84f},
    {-4018.30f, -10741.89f, 696.73f},
    {-4016.58f, -10751.54f, 696.73f},

    {-4216.47f, -10688.27f, 728.31f},
    {-4218.95f, -10709.31f, 728.31f},
    {-4195.60f, -10690.69f, 728.31f},
    {-4197.89f, -10711.79f, 728.31f}
};

//122500
struct boss_eonar : public ScriptedAI
{
    boss_eonar(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        instance = me->GetInstanceScript();
        me->SetRegenerateHealth(false);
        me->SetReactState(REACT_PASSIVE);
        //me->SummonCreatureGroup(CREATURE_SUMMON_GROUP_RESET);
    }

    InstanceScript* instance;
    SummonList summons;
    EventMap events;
    bool restart = false;

    bool GossipHello(Player* player) override
    {
        if (instance->GetBossState(DATA_EONAR) == NOT_STARTED)
        {
            AddGossipItemFor(player, 0, "Start", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            //player->ADD_GOSSIP_ITEM_DB(GOSSIP_ID_EONAR, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            //player->PlayerTalkClass->SendGossipMenu(GOSSIP_EONAR_NOT_STARTED, me->GetGUID());
        }
        else if (instance->GetBossState(DATA_EONAR) == DONE)
        {
            AddGossipItemFor(player, 0, "Done", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            //player->ADD_GOSSIP_ITEM_DB(GOSSIP_ID_EONAR, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            //player->PlayerTalkClass->SendGossipMenu(GOSSIP_EONAR_DONE, me->GetGUID());
        }

        return true;
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
    {
        if (instance->GetBossState(DATA_EONAR) == NOT_STARTED)
        {
            restart = false;
            instance->SetBossState(DATA_EONAR, IN_PROGRESS);
            //me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SummonCreature(NPC_THE_PARAXIS, -4208.913f, -10699.95f, 1061.243f, 1.457f);
            events.RescheduleEvent(EVENT_ENGAGE, 10000);
        }
        else if (instance->GetBossState(DATA_EONAR) == DONE)
        {
            if (instance->GetBossState(DATA_HASABEL) == DONE)
                player->CastSpell(player, SPELL_TELEPORT, true);
            else
                player->NearTeleportTo(-3703.43f, -1589.98f, 634.29f, 1.51f);
        }

        player->PlayerTalkClass->SendCloseGossip();

        return true;
    }

    void Reset() override
    {
        if (instance->GetBossState(DATA_EONAR) != DONE)
            instance->SetBossState(DATA_EONAR, NOT_STARTED);

        events.Reset();
        me->SetPower(POWER_ENERGY, 0);
        me->SetPower(POWER_ALTERNATE_POWER, 0);
        //me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
       // me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void JustSummoned(Creature* summon)
    {
        if (summon->GetEntry() == NPC_THE_PARAXIS_2)
            return;

        summons.Summon(summon);
    }

    void DoAction(int32 const actionId) override
    {
        if (actionId == ACTION_ENCOUNTER_COMPLETE)
        {
            if (instance->GetBossState(DATA_EONAR) != DONE)
            {
                instance->SetBossState(DATA_EONAR, DONE);

                instance->HandleGameObject(instance->GetGuidData(GO_EONAR_PARAXIS_DOOR_1), true);
                instance->HandleGameObject(instance->GetGuidData(GO_EONAR_PARAXIS_DOOR_2), true);
                instance->HandleGameObject(instance->GetGuidData(GO_EONAR_PARAXIS_DOOR_3), true);

                //Visual Event: Paraxis explosion
                if (auto paraxisTrigger = me->SummonCreature(NPC_THE_PARAXIS_2, -4207.28f, -10700.0f, 642.89f, 1.45f, TEMPSUMMON_TIMED_DESPAWN, 15000))
                    paraxisTrigger->CastSpell(paraxisTrigger, SPELL_PARAXIS_EXPLOSION, true);

                AddDelayedEvent(500, [this]() -> void
                {
                    instance->DoOnPlayers([this](Player* player)
                    {
                        me->CastSpell(player, SPELL_EONAR_BONUS_ROLL, true);
                        player->CastSpell(player, SPELL_DAILY_ESSENCE_EONAR, true);
                    });
                });
            }
        }

        switch (actionId)
        {
        case ACTION_RESTART:
        case ACTION_ENCOUNTER_COMPLETE:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            summons.DespawnAll();
            me->RemoveAurasDueToSpell(SPELL_LIFE_ENERGY);
            me->SetHealth(me->GetMaxHealth());
            Reset();
            for (auto spellId : { SPELL_TARGETED, SPELL_BURNING_EMBERS, SPELL_FOUL_STEPS, SPELL_ARCANE_SINGULARITY })
                instance->DoRemoveAurasDueToSpellOnPlayers(spellId);
            TeleportParaxPlayers();
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_LIFE_FORCE_FILTER)
            target->CastSpell(target, SPELL_LIFE_FORCE_DMG, true);
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_LIFE_FORCE)
        {
            me->SetPower(POWER_ALTERNATE_POWER, 0);

            for (uint8 i = 0; i < 4; ++i)
                me->CastSpell(lifeForcePos[i], SPELL_LIFE_FORCE_VISUAL, true);

            me->CastSpell(me, SPELL_LIFE_FORCE_PARAXIS_DMG, true);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;

            if (!restart)
            {
                restart = true;
                EntryCheckPredicate pred(NPC_THE_PARAXIS);
                summons.DoAction(ACTION_EVADE, pred);
                ZoneTalk(SAY_WIPE, nullptr);
            }
        }
    }

    void TeleportParaxPlayers()
    {
        instance->DoOnPlayers([](Player* player)
        {
            if (player->GetDistance(-4207.25f, -10699.98f, 728.31f) < 120.0f)
                player->NearTeleportTo(-3909.15f, -10842.47f, 706.56f, player->GetOrientation());
        });
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_ENGAGE:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->CastSpell(me, SPELL_LIFE_ENERGY, true);
                break;
            }
        }
    }
};

//124445
struct npc_eonar_the_paraxis : public ScriptedAI
{
    npc_eonar_the_paraxis(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        instance = me->GetInstanceScript();
        me->SetRegenerateHealth(false);
        me->SetReactState(REACT_PASSIVE);
        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
    }

    InstanceScript* instance;
    SummonList summons;
    EventMap events;
    std::list<uint32> finalDoomTimer;
    uint8 portalCounter = 0;
    uint8 flyPortalCounter = 0;
    uint8 crystolActivated = 0;
    uint8 lifeForceCount = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_WARP_IN, true);

        events.RescheduleEvent(EVENT_COMBAT_ZONE, 1000);
        events.RescheduleEvent(EVENT_CHECK_PLAYERS, 2000);
        events.RescheduleEvent(EVENT_SUMMON_SHIP, 10000);

        if (IsMythicRaid())
            events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 168 * IN_MILLISECONDS); //2m48s
        else
            events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 146 * IN_MILLISECONDS); //2m26s

        events.RescheduleEvent(EVENT_RAIN_OF_FEL, 15000);

        if (IsHeroicPlusRaid())
            events.RescheduleEvent(EVENT_SPEAR_OF_DOOM, 35000);

        if (IsMythicRaid())
        {
            events.RescheduleEvent(EVENT_FINAL_DOOM, 60000);
            finalDoomTimer = { 126000, 98000, 106000, 100000 };
        }
    }

    void EnterEvadeMode(EvadeReason w)
    {
        ScriptedAI::EnterEvadeMode();
        summons.DespawnAll();
        events.Reset();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, me);
        SwitchDoorState(false);

        if (auto owner = me->GetOwner())
            owner->GetAI()->DoAction(ACTION_RESTART);
    }

    void JustDied(Unit* killer) override
    {
        events.Reset();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto owner = me->GetOwner())
        {
            if (killer->GetGUID() == me->GetGUID())
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, me);
                owner->GetAI()->DoAction(ACTION_RESTART);
            }
            else
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, me, 0, 1);
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 2075);
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_KILL_CREATURE, me->GetEntry(), 1, 0);

                owner->GetAI()->DoAction(ACTION_ENCOUNTER_COMPLETE);
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
        case NPC_FEL_INFUSED_DESTRUCTOR:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
            break;
        }

        summon->SetRegenerateHealth(false);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        uint8 energyCount = 0;

        switch (summon->GetEntry())
        {
        case NPC_FELGUARD:
            energyCount = IsMythicRaid() ? 1 : 4;
            break;
        case NPC_FEL_HOUND:
            if (IsMythicRaid())
                energyCount = 2;
            else if (IsHeroicRaid())
                energyCount = 5;
            else
                energyCount = 7;
            break;
        case NPC_VOLANT_KERAPTERON:
            if (IsMythicRaid())
                energyCount = 4;
            else if (IsHeroicRaid())
                energyCount = 7;
            else
                energyCount = 8;
            break;
        case NPC_FEL_LORD:
            energyCount = IsMythicRaid() ? 5 : 9;
            break;
        case NPC_FEL_POWERED_PURIFIER:
        case NPC_FEL_CHARGED_OBFUSCATOR:
        case NPC_FEL_INFUSED_DESTRUCTOR:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
            energyCount = IsMythicRaid() ? 6 : 10;
            break;
        case NPC_PARAXIS_INQUISITOR:
        {
            for (auto entry : { NPC_CRYSTAL_TARGETED, NPC_CRYSTAL_BURNING, NPC_CRYSTAL_FOUL_STEPS, NPC_CRYSTAL_ARCANE_SINGULARITY })
            {
                EntryCheckPredicate pred(entry);
                summons.DoAction(ACTION_1, pred);
            }
            break;
        }
        default:
            break;
        }

        if (me->GetOwner())
        {
            if (auto eonar = me->GetOwner()->ToCreature())
            {
                if (eonar->HasUnitState(UNIT_STATE_CASTING))
                    return;

                eonar->SetPower(POWER_ALTERNATE_POWER, eonar->GetPower(POWER_ALTERNATE_POWER) + energyCount);

                if (eonar->GetPower(POWER_ALTERNATE_POWER) >= 100)
                {
                    eonar->CastSpell(eonar, SPELL_LIFE_FORCE);

                    if (lifeForceCount < 4)
                    {
                       // eonar->AI()->ZoneTalk(SAY_LIFE_FORCE_1, nullptr) + lifeForceCount);
                        ++lifeForceCount;
                    }
                }
            }
        }
    }

    void DoAction(int32 const actionId) override
    {
        if (actionId == ACTION_EVADE)
            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);

        if (actionId == ACTION_CRYSTAL_DISABLE)
        {
            ++crystolActivated;

            if (crystolActivated == 4)
            {
                SwitchDoorState(true);
                me->InterruptNonMeleeSpells(false);
                me->CastSpell(me, SPELL_PURGE);
                ZoneTalk(SAY_WARN_PURGE, nullptr);
            }
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId)
    {

        if (spellId == SPELL_RAIN_OF_FEL_MARK)
            me->CastSpell(target, SPELL_RAIN_OF_FEL_DMG, true);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RAIN_OF_FEL_FILTER)
        {
            ZoneTalk(SAY_WARN_RAIN_OF_FEL, target);
            me->CastSpell(target, SPELL_RAIN_OF_FEL_MARK, true);
        }

        if (spell->Id == SPELL_SPEAR_OF_DOOM_FILTER)
            me->CastSpell(target, SPELL_SPEAR_OF_DOOM_SUMMON, true);
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_PURGE)
            SwitchDoorState(false);
    }



    void PortalEvent()
    {
        ++portalCounter;
        uint32 delayTimer = 0;

        switch (portalCounter)
        {
        case 1: // MID
        {
            if (IsMythicRaid())
            {
                SummonShip(0, 25000);
                delayTimer = 1000;
                for (uint8 i = 0; i < 8; ++i)
                {
                    if (i == 2 || i == 4 || i == 6)
                        delayTimer += 1000;

                    me->SummonCreature(NPC_FELGUARD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }

                me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                delayTimer += 9000;

                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
            }
            else
            {
                SummonShip(0, 18000);
                delayTimer = 1000;
                for (uint8 i = 0; i < 6; ++i)
                {
                    if (i == 2 || i == 4)
                        delayTimer += 1000;

                    me->SummonCreature(NPC_FELGUARD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            }
            events.RescheduleEvent(EVENT_SUMMON_SHIP, 5000);
            break;
        }
        case 2:
        {
            if (IsMythicRaid()) //BOT+TOP
            {
                //>BOT
                SummonShip(1, 49000);
                delayTimer = 24000;
                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                me->SummonCreature(NPC_FEL_CHARGED_OBFUSCATOR, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);

                //>TOP
                SummonShip(2, 24000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);

                events.RescheduleEvent(EVENT_SUMMON_SHIP, 24000);
            }
            else // BOT
            {
                SummonShip(1, 32500);
                delayTimer = 20000;
                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i == 2 || i == 4 || i == 8 || i == 10)
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 44000);
            }
            break;
        }
        case 3:
        {
            if (IsMythicRaid()) //MID
            {
                SummonShip(0, 31000);
                delayTimer = 20000;
                for (uint8 i = 0; i < 8; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 1000;

                    me->SummonCreature(NPC_FELGUARD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                me->SummonCreature(NPC_FEL_POWERED_PURIFIER, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 23500);
            }
            else //TOP
            {
                SummonShip(2, 27000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_CHARGED_OBFUSCATOR, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 35000);
            }
            break;
        }
        case 4:
        {
            if (IsMythicRaid()) //TOP
            {
                SummonShip(2, 17000);
                delayTimer = 2000;
                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 43000);
            }
            else // MID
            {
                SummonShip(0, 28000);
                delayTimer = 20000;
                for (uint8 i = 0; i < 6; ++i)
                {
                    if (i == 1 || i == 3 || i == 5)
                        delayTimer += 1000;

                    me->SummonCreature(NPC_FELGUARD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                if (IsHeroicPlusRaid())
                    me->SummonCreature(NPC_FEL_POWERED_PURIFIER, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 71000);
            }
            break;
        }
        case 5:
        {
            if (IsMythicRaid()) //BOT
            {
                SummonShip(1, 38000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);

                delayTimer = 23000;
                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 38000);
            }
            else // TOP+BOT
            {
                SummonShip(1, 32000);
                SummonShip(2, 32000);
                //>TOP
                delayTimer = 25000;
                for (uint8 i = 0; i < 6; ++i)
                {
                    if (i == 2 || i == 4)
                        delayTimer += 1000;

                    me->SummonCreature(NPC_FELGUARD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                //>BOTTOM
                delayTimer = 25000;
                for (uint8 i = 0; i < 5; ++i)
                {
                    if (i == 2 || i == 4)
                        delayTimer += 1000;

                    me->SummonCreature(NPC_FELGUARD, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                if (IsHeroicRaid())
                    me->SummonCreature(NPC_FEL_POWERED_PURIFIER, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 30000);
            }
            break;
        }
        case 6:
        {
            if (IsMythicRaid()) //MID
            {
                SummonShip(0, 55000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_POWERED_PURIFIER, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 3000);
            }
            else // MID
            {
                SummonShip(0, 42000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_CHARGED_OBFUSCATOR, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                delayTimer = 27000;
                for (uint8 i = 0; i < 6; ++i)
                {
                    if (i == 2 || i == 4)
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                if (IsHeroicRaid())
                    me->SummonCreature(NPC_FEL_POWERED_PURIFIER, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 100000); //1m40s
            }
            break;
        }
        case 7:
        {
            if (IsMythicRaid()) //TOP
            {
                SummonShip(2, 52000);
                delayTimer = 32000;
                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 26000);
                break;
            }
            else  // ALL
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 100000); //1m40s
            //no break
        }
        case 8:
        {
            if (IsMythicRaid()) //MID+BOT
            {
                //MID
                SummonShip(0, 55000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_CHARGED_OBFUSCATOR, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                //BOT
                SummonShip(1, 55000);
                delayTimer = 40000;
                for (uint8 i = 0; i < 12; ++i)
                {
                    if (i != 0 && !(i % 2))
                        delayTimer += 2000;

                    me->SummonCreature(NPC_FEL_HOUND, trashPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                events.RescheduleEvent(EVENT_SUMMON_SHIP, 50000);
            }
            else //ALL
            {
                delayTimer = 20000;
                for (uint8 i = 0; i < 3; ++i)
                {
                    SummonShip(i, 48000);
                    me->SummonCreature(NPC_FEL_LORD, trashPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    me->SummonCreature(i == 1 ? NPC_FEL_CHARGED_OBFUSCATOR : NPC_FEL_INFUSED_DESTRUCTOR, trashPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
            }
            break;
        }
        case 9: //TOP
            SummonShip(2, 45000);
            delayTimer = 20000;
            me->SummonCreature(NPC_FEL_CHARGED_OBFUSCATOR, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            for (uint8 i = 0; i < 6; ++i)
            {
                if (!(i % 2))
                    delayTimer += 1000;

                me->SummonCreature(NPC_FELGUARD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            }

            for (uint8 i = 0; i < 12; ++i)
            {
                if (!(i % 2))
                    delayTimer += 2000;

                me->SummonCreature(NPC_FEL_HOUND, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            }
            events.RescheduleEvent(EVENT_SUMMON_SHIP, 65000);
            break;
        case 10: //TOP
            SummonShip(2, 55000);
            me->SummonCreature(NPC_FEL_LORD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            me->SummonCreature(NPC_FEL_LORD, trashPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            events.RescheduleEvent(EVENT_SUMMON_SHIP, 100000); //1m40s
            break;
        case 11: //ALL
            delayTimer = 20000;
            for (uint8 i = 0; i < 3; ++i)
            {
                SummonShip(i, 48000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_FEL_LORD, trashPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(i == 1 ? NPC_FEL_CHARGED_OBFUSCATOR : NPC_FEL_INFUSED_DESTRUCTOR, trashPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            }
            break;
        default:
            break;
        }
    }

    void SummonShip(uint8 point, uint32 despawnTimer)
    {
        me->SummonCreature(NPC_INVASION_POINT, invastionPos[point], TEMPSUMMON_TIMED_DESPAWN, despawnTimer);

        if (auto sShip = me->SummonCreature(NPC_LEGION_SHIP_SMALL, shipPos[point], TEMPSUMMON_TIMED_DESPAWN, despawnTimer))
            sShip->CastSpell(sShip, SPELL_VISUAL_SMALL_SHIP, true);

        if (auto bShip = me->SummonCreature(NPC_LEGION_SHIP_BIG, shipPos[point + 3], TEMPSUMMON_TIMED_DESPAWN, despawnTimer))
            bShip->CastSpell(bShip, SPELL_VISUAL_BIG_SHIP, true);
    }

    void FlyPortalEvent()
    {
        ++flyPortalCounter;
        uint32 delayTimer = 0;

        switch (flyPortalCounter)
        {
        case 1:
            if (IsMythicRaid())
            {
                me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 25000);
                me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 25000);
                delayTimer = 18000;
                for (uint8 i = 0; i < 6; ++i)
                {
                    me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    delayTimer += 1000;
                }
                events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 82 * IN_MILLISECONDS); //1m22s
            }
            else
            {
                me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 16000);
                me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 16000);
                delayTimer = 9000;
                for (uint8 i = 0; i < 5; ++i)
                {
                    me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    delayTimer += 1000;
                }
                events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 114 * IN_MILLISECONDS); //1m54s
            }
            break;
        case 2:
            if (IsMythicRaid())
            {
                me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 22000);
                me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 22000);
                delayTimer = 12000;
                for (uint8 i = 0; i < 8; ++i)
                {
                    me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    delayTimer += 1000;
                }
                events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 90 * IN_MILLISECONDS); //1m30s
            }
            else
            {
                me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 30000);
                me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 30000);
                delayTimer = 21000;
                for (uint8 i = 0; i < 8; ++i)
                {
                    me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    delayTimer += 1000;
                }
                events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 81 * IN_MILLISECONDS); //1m21s
            }
            break;
        case 3:
            if (IsMythicRaid())
            {
                me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 40000);
                me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 40000);
                delayTimer = 20000;
                for (uint8 i = 0; i < 10; ++i)
                {
                    me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    delayTimer += 1000;
                }
                events.RescheduleEvent(EVENT_KERAPTERON_PORTAL, 100 * IN_MILLISECONDS); //1m40s
            }
            else
            {
                me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 28000);
                me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 28000);
                delayTimer = 18000;
                for (uint8 i = 0; i < 8; ++i)
                {
                    me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    delayTimer += 1000;
                }
            }
            break;
        case 4:
            me->SummonCreature(NPC_INVASION_POINT, invastionPos[3], TEMPSUMMON_TIMED_DESPAWN, 50000);
            me->SummonCreature(NPC_DEMONIC_PORTAL, trashPos[3], TEMPSUMMON_TIMED_DESPAWN, 50000);
            delayTimer = 20000;
            for (uint8 i = 0; i < 10; ++i)
            {
                me->SummonCreature(NPC_VOLANT_KERAPTERON, trashPos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                delayTimer += 1000;
            }
            break;
        }
    }

    void SwitchDoorState(bool open)
    {
        instance->HandleGameObject(instance->GetGuidData(GO_EONAR_PARAXIS_DOOR_1), open);
        instance->HandleGameObject(instance->GetGuidData(GO_EONAR_PARAXIS_DOOR_2), open);
        instance->HandleGameObject(instance->GetGuidData(GO_EONAR_PARAXIS_DOOR_3), open);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_COMBAT_ZONE:
            {
                if (me->GetOwner())
                    if (auto owner = me->GetOwner()->ToCreature())
                        owner->AI()->ZoneTalk(SAY_PULL, nullptr);
           //     instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_START, me);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();
                break;
            }
            case EVENT_CHECK_PLAYERS:

                events.RescheduleEvent(EVENT_CHECK_PLAYERS, 500);
                break;
            case EVENT_SUMMON_SHIP:
                PortalEvent();
                break;
            case EVENT_KERAPTERON_PORTAL:
                FlyPortalEvent();
                break;
            case EVENT_RAIN_OF_FEL:
                DoCast(me, SPELL_RAIN_OF_FEL_FILTER, true);
                events.RescheduleEvent(EVENT_RAIN_OF_FEL, urandms(20, 45)); //Unk
                break;
            case EVENT_SPEAR_OF_DOOM:
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                {
                    ZoneTalk(SAY_WARN_SPEAR_OF_DOOM, nullptr);
                    DoCast(me, SPELL_SPEAR_OF_DOOM_FILTER, true);
                }
                else
                {
                    events.RescheduleEvent(EVENT_SPEAR_OF_DOOM, 5000);
                    break;
                }
                events.RescheduleEvent(EVENT_SPEAR_OF_DOOM, 60 * IN_MILLISECONDS);
                break;
            case EVENT_FINAL_DOOM:
            {
                ZoneTalk(SAY_WARN_FINAL_DOOM, nullptr);
                SwitchDoorState(false);
                me->RemoveAreaTrigger(SPELL_TELEPORTER_AT);
                me->SummonCreature(NPC_PARAXIS_INQUISITOR, -4207.34f, -10700.3f, 728.35f, 1.57f);
                me->CastSpell(me, SPELL_FINAL_DOOM);
                crystolActivated = 0;

                for (uint8 i = 0; i < 4; ++i)
                    me->CastSpell(teleportPos[i], SPELL_TELEPORTER_AT, true);

                me->SummonCreature(NPC_CRYSTAL_TARGETED, -4240.0f, -10658.1f, 734.58f);
                me->SummonCreature(NPC_CRYSTAL_BURNING, -4249.0f, -10734.1f, 734.58f);
                me->SummonCreature(NPC_CRYSTAL_FOUL_STEPS, -4174.0f, -10741.9f, 734.58f);
                me->SummonCreature(NPC_CRYSTAL_ARCANE_SINGULARITY, -4165.0f, -10666.4f, 734.58f);

                if (!finalDoomTimer.empty())
                {
                    events.RescheduleEvent(EVENT_FINAL_DOOM, finalDoomTimer.front());
                    finalDoomTimer.pop_front();
                }
                if (me->GetOwner())
                    if (auto owner = me->GetOwner()->ToCreature())
                        owner->AI()->ZoneTalk(SAY_FINAL_DOOM, nullptr);
                break;
            }
            }
        }
    }
};

//123452, 123451, 123191, 124227, 123760, 124207, 123726
struct npc_eonar_trash_generic : public ScriptedAI
{
    npc_eonar_trash_generic(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);

        switch (me->GetEntry())
        {
        case NPC_FEL_INFUSED_DESTRUCTOR:
        case NPC_FEL_CHARGED_OBFUSCATOR:
        case NPC_FEL_POWERED_PURIFIER:
        case NPC_VOLANT_KERAPTERON:
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            break;
        }
        if (me->GetEntry() == NPC_VOLANT_KERAPTERON)
            me->SetCanFly(true);
    }

    InstanceScript* instance;
    EventMap events;
    Position finalPos;
    bool isDestructor = false;
    bool isPurifier = false;
    uint32 checkTargetTimer = 0;
    uint32 artilleryStartTimer = 0;
    uint32 checkSpellTimer = 0;
    uint32 swingTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        if (auto eonar = instance->instance->GetCreature(instance->GetGuidData(NPC_EONAR_EVENT)))
            //me->AddThreat(eonar, 1.0f);

        isDestructor = me->GetEntry() == NPC_FEL_INFUSED_DESTRUCTOR;
        isPurifier = me->GetEntry() == NPC_FEL_POWERED_PURIFIER;

        if (me->GetEntry() != NPC_VOLANT_KERAPTERON)
            DoCast(me, isPurifier ? SPELL_PURIFIIER : SPELL_SPAWN_TRASH_VISUAL, true);

        switch (me->GetEntry())
        {
        case NPC_FELGUARD:
            DoCast(me, SPELL_FELGUARD_WEAPONS_VISUAL, true);
            break;
        case NPC_FEL_LORD:
            DoCast(me, SPELL_FEL_LORD_WEAPONS_VISUAL, true);
            break;
        case NPC_FEL_CHARGED_OBFUSCATOR:
            DoCast(me, SPELL_CLOAK_AT, true);
            break;
        case NPC_FEL_POWERED_PURIFIER:
            DoCast(me, SPELL_PURIFICATION_AT, true);
            break;
        case NPC_VOLANT_KERAPTERON:
            DoCast(me, SPELL_SPAWN_KERAPTERON_VISUAL, true);
            break;
        default:
            break;
        }

        //Start move
        if (me->GetEntry() == NPC_VOLANT_KERAPTERON)
            events.RescheduleEvent(EVENT_1, 2000);
        else
            events.RescheduleEvent(EVENT_1, 3000);
    }

    void Reset() override {}

    void JustDied(Unit* /*killer*/)
    {
        me->SetLootRecipient(NULL);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (isDestructor && type == POINT_MOTION_TYPE && id == 1)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            DoCast(me, SPELL_HIGH_ALERT, true);
            artilleryStartTimer = 2000;
        }
    }

    void LastWPReached()
    {
        if (isDestructor)
            return;

        checkSpellTimer = 1000;
        finalPos = me->GetPosition();
        me->CastSpell(me, SPELL_STRIKE, true);
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply)
            return;

        switch (spellId)
        {
        case SPELL_HIGH_ALERT:
            artilleryStartTimer = 0;
            checkTargetTimer = 5000;
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveAurasDueToSpell(SPELL_ARTILLERY_MODE);
            events.RescheduleEvent(EVENT_2, 6000);
            break;
        case SPELL_PURIFIIER_HIGH_ALERT:
            me->RemoveAurasDueToSpell(SPELL_PURIFIIER_FEL_SHIELDING);
            break;
        }
    }

    void StartMove()
    {
        uint32 pathID[4] = { PATH_MID, PATH_BOT, PATH_TOP, PATH_FLY };

        for (uint8 i = 0; i < 4; ++i)
        {
            if (me->GetDistance(trashPos[i]) < 10.0f)
            {
                if (isDestructor)
                {
                    me->SetHomePosition(destructorPos[i]);
                    me->GetMotionMaster()->MovePoint(1, destructorPos[i]);
                }
                else
                {
                    if (me->GetEntry() == NPC_FEL_POWERED_PURIFIER)
                    {
                        me->SetReactState(REACT_DEFENSIVE);
                        swingTimer = 9000;
                    }

                    me->GetMotionMaster()->MovePath(pathID[i], (frand(-2.0f, 2.0f), frand(-2.0f, 2.0f)));
                }
                return;
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HasAura(SPELL_CLOAK_MOD_DMG))
            damage *= 0.1f;
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkSpellTimer)
        {
            if (checkSpellTimer <= diff)
            {
                checkSpellTimer = 1000;

                if (!me->HasUnitState(UNIT_STATE_STUNNED))
                {
                    if (me->GetDistance(finalPos) > 1.0f)
                    {
                        if (!me->HasUnitState(UNIT_STATE_ROOT))
                            me->GetMotionMaster()->MovePoint(2, finalPos);
                    }
                    else
                        me->CastSpell(me, SPELL_STRIKE, true);
                }
            }
            else
                checkSpellTimer -= diff;
        }

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                StartMove();
                break;
            case EVENT_2:
                me->CastSpell(me, SPELL_ARTILLERY_STRIKE);
                events.RescheduleEvent(EVENT_2, 8000);
                break;
            }
        }

        if (isDestructor)
        {
            if (artilleryStartTimer)
            {
                if (artilleryStartTimer <= diff)
                {
                    artilleryStartTimer = 0;
                    DoCast(me, SPELL_ARTILLERY_MODE, true);
                }
                else
                    artilleryStartTimer -= diff;
            }

            if (checkTargetTimer)
            {
                if (checkTargetTimer <= diff)
                {
                    checkTargetTimer = 5000;
                    bool found = false;

                    if (auto victim = me->GetVictim())
                    {
                        if (!me->IsWithinMeleeRange(victim))
                        {
                            if (auto target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 60.0f, true))
                            {
                                if (me->IsWithinMeleeRange(target))
                                {
                                    found = true;
                                    ModifyThreatByPercent(victim, -100);
                                  //  me->AddThreat(target, 10000.0f);
                                }
                            }
                        }
                        else
                            found = true;
                    }

                    if (!found && !me->HasAura(SPELL_HIGH_ALERT))
                    {
                        events.Reset();
                        me->AttackStop();
                        DoCast(me, SPELL_HIGH_ALERT, true);
                        artilleryStartTimer = 2000;
                        checkTargetTimer = 0;
                    }
                }
                else
                    checkTargetTimer -= diff;
            }
        }

        if (!UpdateVictim())
            return;

        if (swingTimer)
        {
            if (swingTimer <= diff)
            {
                swingTimer = 9000;
                if (auto victim = me->GetVictim())
                    me->CastSpell(victim, urand(0, 1) ? SPELL_SWING_RIGHT : SPELL_SWING_LEFT);
            }
            else
                swingTimer -= diff;
        }

        if (isDestructor || isPurifier)
            DoMeleeAttackIfReady();
    }
};

//125319
struct npc_eonar_spear_of_doom : public ScriptedAI
{
    npc_eonar_spear_of_doom(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    ObjectGuid targetGUID;
    uint32 moveTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        if (!summoner)
            return;

        summoner->CastSpell(me, SPELL_SPEAR_OF_DOOM_AT, true);

        moveTimer = 1000;

        if (auto player = me->SelectNearestPlayer(30.0f))
            targetGUID = player->GetGUID();
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override
    {
        if (moveTimer)
        {
            if (moveTimer <= diff)
            {
                moveTimer = 1000;

                auto player = ObjectAccessor::GetPlayer(*me, targetGUID);
                if (!player || !player->IsAlive())
                {
                    if (auto player = me->SelectNearestPlayer(30.0f))
                        targetGUID = player->GetGUID();
                }
                else if (auto player = ObjectAccessor::GetPlayer(*me, targetGUID))
                {
                    me->GetMotionMaster()->MovePoint(1, player->GetPosition(), false);
                }
            }
            else
                moveTimer -= diff;
        }
    }
};

//125429
struct npc_eonar_paraxis_inquisitor : public ScriptedAI
{
    npc_eonar_paraxis_inquisitor(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        SetCombatMovement(false);
    }

    InstanceScript* instance;
    EventMap events;
    uint32 tormentTimer = 0;

    void Reset()
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/)
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.RescheduleEvent(EVENT_1, 5000);
        events.RescheduleEvent(EVENT_2, 12000);
        events.RescheduleEvent(EVENT_3, urandms(11, 14));
        tormentTimer = 5000;
    }

    void JustDied(Unit* /*killer*/)
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void UpdateAI(uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (tormentTimer)
        {
            if (tormentTimer <= diff)
            {
                tormentTimer = 1000;

                if (me->SelectNearestPlayer(50.0f))
                {
                    if (!me->HasUnitState(UNIT_STATE_CASTING) && me->GetVictim() && !me->IsWithinMeleeRange(me->GetVictim()) && !me->HasAura(SPELL_TORMENT))
                        DoCast(SPELL_TORMENT);
                    else if (auto aura = me->GetAura(SPELL_TORMENT))
                        aura->Remove();
                }
                else
                {
                    EnterEvadeMode();
                    return;
                }
            }
            else
                tormentTimer -= diff;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(SPELL_MIND_BLAST);
                events.RescheduleEvent(EVENT_1, 10000);
                break;
            case EVENT_2:
                DoCast(SPELL_PAIN);
                events.RescheduleEvent(EVENT_2, 10000);
                break;
            case EVENT_3:
                DoCast(SPELL_WRACK);
                events.RescheduleEvent(EVENT_3, 16000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//125917, 125918, 125919, 125920
struct npc_eonar_focusing_crystal : public ScriptedAI
{
    npc_eonar_focusing_crystal(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    bool disabled = true;

    void IsSummonedBy(Unit* summoner) override
    {
        if (!summoner)
            return;

        switch (me->GetEntry())
        {
        case NPC_CRYSTAL_TARGETED: //Yellow
            summoner->CastSpell(me, 249055, true);
            DoCast(me, 259472, true);
            break;
        case NPC_CRYSTAL_BURNING: //Red
            summoner->CastSpell(me, 249054, true);
            DoCast(me, 259468, true);
            break;
        case NPC_CRYSTAL_FOUL_STEPS: //Green
            summoner->CastSpell(me, 249053, true);
            DoCast(me, 259469, true);
            break;
        case NPC_CRYSTAL_ARCANE_SINGULARITY: //Blue
            summoner->CastSpell(me, 249056, true);
            DoCast(me, 259470, true);
            break;
        }
    }

    void Reset() override {}

    void DoAction(int32 const actionId) override
    {
        if (actionId == ACTION_1)
        {
            disabled = false;
            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        if (actionId == ACTION_2)
        {
            disabled = true;
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            me->RemoveAllAuras();
            //me->SetAnimKitId(0);

            if (auto owner = me->GetOwner())
                owner->GetAI()->DoAction(ACTION_CRYSTAL_DISABLE);

            AddDelayedEvent(3000, [this]() -> void
            {
                if (me)
                    me->DespawnOrUnsummon();
            });
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//246313
class spell_eonar_paraxis_artillery : public SpellScript
{
    PrepareSpellScript(spell_eonar_paraxis_artillery);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        //Sniff: 27ppl raid - 9 casts
        if (uint32 count = ceil(GetCaster()->GetMap()->GetPlayersCountExceptGMs() / 3))
            Trinity::Containers::RandomResize(targets, count);
    }

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() && GetHitUnit())
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PARAXIS_ARTILLERY_DMG, true);
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eonar_paraxis_artillery::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_eonar_paraxis_artillery::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//249934
class spell_eonar_paraxis_purge_filter : public SpellScript
{
    PrepareSpellScript(spell_eonar_paraxis_purge_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            if (object->IsWithinBox({ -4206.80f, -10700.2f, 728.27f }, 100.0f, 100.0f, 20.0f))
                return false;

            return true;
        });
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eonar_paraxis_purge_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//248861
class spell_eonar_spear_of_doom_filter : public SpellScript
{
    PrepareSpellScript(spell_eonar_spear_of_doom_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempTargets;

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer() || object->GetAreaId() != 9333)
                return true;
            return false;
        });

        //Mythic
        for (auto object : targets)
        {
            if (object->ToPlayer()->HasAura(SPELL_TARGETED))
                tempTargets.push_back(object);
        }

        if (!tempTargets.empty())
            targets = tempTargets;
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eonar_spear_of_doom_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

//248326
class spell_eonar_rain_of_fel_filter : public SpellScript
{
    PrepareSpellScript(spell_eonar_rain_of_fel_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempTargets;

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer() || object->GetAreaId() != 9333)
                return true;
            return false;
        });

        //>Mythic
        for (auto object : targets)
        {
            if (object->ToPlayer()->HasAura(SPELL_TARGETED))
                tempTargets.push_back(object);
        }

        if (!tempTargets.empty())
        {
            if (tempTargets.size() < 3)
            {
                Trinity::Containers::RandomResize(targets, 3 - tempTargets.size());
                targets.splice(targets.end(), tempTargets);
            }
            else
            {
                targets = tempTargets;
            }
        }
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eonar_rain_of_fel_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//249103
class spell_eonar_paraxis_teleport : public SpellScript
{
    PrepareSpellScript(spell_eonar_paraxis_teleport);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster())
            return;

        Position pos;
        float dist = 15.0f;

        for (uint8 i = 0; i < 4; ++i)
        {
            if (GetCaster()->GetDistance(teleportPos[i]) < dist)
            {
                dist = GetCaster()->GetDistance(teleportPos[i]);
                pos = teleportPos[i + 4];
            }
        }
        GetHitDest()->Relocate(pos);
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(spell_eonar_paraxis_teleport::HandleDummy, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

//245781
class spell_eonar_surge_of_life : public SpellScript
{
    PrepareSpellScript(spell_eonar_surge_of_life);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster())
            return;

        Position pos = { GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ() + 50.0f, GetCaster()->GetOrientation() };
        GetHitDest()->Relocate(pos);
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(spell_eonar_surge_of_life::HandleDummy, EFFECT_1, SPELL_EFFECT_JUMP_DEST);
    }
};

//248225
class spell_eonar_jump_pad : public SpellScript
{
    PrepareSpellScript(spell_eonar_jump_pad);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        auto caster = GetCaster();
        if (!caster)
            return;

        auto owner = caster->FindNearestCreature(NPC_JUMP_PAD, 10.0f);
        if (!owner)
            return;

        std::list<Creature*> padList;
        caster->GetCreatureListWithEntryInGrid(padList, NPC_JUMP_DEST, 100.0f);
        padList.remove_if([caster, owner](Creature* pad) -> bool
        {
            if (pad == nullptr)
                return true;

            if ((pad->GetPositionZ() - caster->GetPositionZ()) > -10.0f && (pad->GetPositionZ() - caster->GetPositionZ()) < 10.0f)
                return true;

            if (!owner->isInFront(pad, 3.14f / 4.0f))
                return true;

            return false;
        });


        if (padList.size() > 1)
            padList.resize(1);

        if (!padList.empty())
            GetHitDest()->Relocate(padList.front()->GetPosition());
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(spell_eonar_jump_pad::HandleDummy, EFFECT_0, SPELL_EFFECT_JUMP_CHARGE);
    }
};

//254497, 248225
class spell_eonar_dive_down_jump : public SpellScript
{
    PrepareSpellScript(spell_eonar_dive_down_jump);

    void HandleScript()
    {
        auto caster = GetCaster();
        if (!caster)
            return;

        AddDelayedEvent(1000, [caster]() -> void { caster->CastSpell(caster, SPELL_SWIFT_FEET, true); });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_eonar_dive_down_jump::HandleScript);
        OnHit += SpellHitFn(spell_eonar_dive_down_jump::HandleScript);
    }
};

//246330
class spell_eonar_swift_feet : public AuraScript
{
    PrepareAuraScript(spell_eonar_swift_feet);

    uint32 tickTimer = 2000;

    void OnUpdate(AuraEffect const* aurEff)
    {
        if (auto aura = aurEff->GetBase())
            aura->ModStackAmount(-1);

    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_eonar_swift_feet::OnUpdate, EFFECT_0, SPELL_AURA_MOD_SPEED_NOT_STACK);
    }
};

//246301
class spell_eonar_artillery_mode : public AuraScript
{
    PrepareAuraScript(spell_eonar_artillery_mode);

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (GetCaster())
            GetCaster()->CastSpell(GetCaster(), SPELL_ARTILLERY_STRIKE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_eonar_artillery_mode::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//250081
class spell_eonar_shatter : public AuraScript
{
    PrepareAuraScript(spell_eonar_shatter);

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        auto target = GetUnitOwner()->ToCreature();
        if (!target)
            return;

        target->AI()->DoAction(ACTION_2);

        switch (target->GetEntry())
        {
        case NPC_CRYSTAL_TARGETED: //Yellow
            GetCaster()->CastSpell(GetCaster(), SPELL_TARGETED, true);
            break;
        case NPC_CRYSTAL_BURNING: //Red
            GetCaster()->CastSpell(GetCaster(), SPELL_BURNING_EMBERS, true);
            break;
        case NPC_CRYSTAL_FOUL_STEPS: //Green
            GetCaster()->CastSpell(GetCaster(), SPELL_FOUL_STEPS, true);
            break;
        case NPC_CRYSTAL_ARCANE_SINGULARITY: //Blue
            GetCaster()->CastSpell(GetCaster(), SPELL_ARCANE_SINGULARITY, true);
            break;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_eonar_shatter::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_eonar()
{
    RegisterCreatureAI(boss_eonar);
    RegisterCreatureAI(npc_eonar_the_paraxis);
    RegisterCreatureAI(npc_eonar_trash_generic);
    RegisterCreatureAI(npc_eonar_spear_of_doom);
    RegisterCreatureAI(npc_eonar_paraxis_inquisitor);
    RegisterCreatureAI(npc_eonar_focusing_crystal);
    RegisterSpellScript(spell_eonar_paraxis_artillery);
    RegisterSpellScript(spell_eonar_paraxis_purge_filter);
    RegisterSpellScript(spell_eonar_spear_of_doom_filter);
    RegisterSpellScript(spell_eonar_rain_of_fel_filter);
    RegisterSpellScript(spell_eonar_paraxis_teleport);
    RegisterSpellScript(spell_eonar_surge_of_life);
    RegisterSpellScript(spell_eonar_jump_pad);
    RegisterSpellScript(spell_eonar_dive_down_jump);
    RegisterAuraScript(spell_eonar_swift_feet);
    RegisterAuraScript(spell_eonar_artillery_mode);
    RegisterAuraScript(spell_eonar_shatter);
}
