/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "Weather.h"
#include "GameObjectAI.h"

#include "heart_of_fear.h"

/*
During the fight, you will have to fight Mel'jarak, as well as 9 adds:
- 3 Sra-thik Amber-Trappers,
- 3 Kor'thic Elite Blademasters,
- 3 Zar'thik Battle-Menders.
The adds will all become active as soon as you engage the boss.

The three mobs in a group are tied together:
- Adds of the same kind share a health pool and have the same abilities, so they die together.
- If all three fall, Mel'jarak gains [Recklessness] and summons another group of the same type 50 seconds later.

!Note: ~ Normal - he becomes reckless for the remainder of the fight. Damage dealt +50%, taken +33%. Stacks.
       ~ Heroic - he becomes reckless for 30 sec. Damage dealt +100%, taken +600%.

Before the encounter begins, four players should interact with the weapon racks left along the wall to gain a bonus ability, Impaling Spear.
This can be used to crowd control one mantid for 50 seconds. The spear can be reapplied when desired, but Mel'jarak will only let so many of his warriors be cc'ed at a time.

- [Watchful Eye] : Adds which are crowd-controlled:
    1 ~ when 9 adds are alive, you can crowd-control 4 adds;
    2 ~ when 6 adds are alive, you can crowd-control 2 adds;
    3 ~ when 3 adds are alive, you can crowd-control 0 adds.

- On Normal, [Watchful Eye] debuff changes depending on adds up/killed.
- On Heroic, Wind Lord Mel'jarak only uses basic [Watchful Eye] debuff and only dispels crowd control effects if players incapacitate more than three warriors.
*/

enum Yells
{
    /*** Boss ***/
    SAY_INTRO               = 0, // Your defiance of the empress ends here!

    SAY_AGGRO               = 1, // All of Pandaria will fall beneath the Wings of the Empress!
    SAY_SLAY                = 2, // 0 - The Empress commands it!; 1 - Pitiful.
    SAY_DEATH               = 3, // Empress... I have... failed you...

    SAY_WHIRLING_BLADES     = 4, // My blade never misses its mark!
    SAY_RAIN_OF_BLADES      = 5, // The skies belong to the Empress!

    SAY_WATCHFUL_EYE        = 6, // 0 - You fight like cowards!; 1 - Aid me brethren!

    SAY_ADD_GROUP_DIES      = 7, // 0 - To die for the empress is an honor!; 1 - The wings of the empress cannot fail!; 2 - You will pay for your transgressions!
    SAY_SUMMON_REINFORCE    = 8,  // 0 - The Kor'thik have no equal in combat!; 1 - The mighty Zar'thik bend the wind to their will!; 2 - The Sra'thik command the elements of this land, leaving their foes imprisoned for all time!

    ANN_WHIRLING_BLADES     = 9, // Wind Lord Mel'jarak begins to cast [Whirling Blades]!
    ANN_RAIN_OF_BLADES      = 10,// Wind Lord Mel'jarak begins to cast [Rain of Blades]!
    ANN_REINFORCEMENTS      = 11 // Wind Lord Mel'jarak calls for reinforcements!
};

enum Spells
{
    /*** Boss ***/
    SPELL_WHIRLING_BLADE        = 121896, // Triggers 121898 damage every 0.25s and 121897, 122083 dummy location spells (visuals?).
    SPELL_WB_SWORD              = 121897, // Visual thrown sword
    SPELL_WB_LIGHT              = 122083, // Light effect around thrown sword
    SPELL_WB_SUMMON             = 124851, // Summons Whirling Blade NPC at target pos, which will trigger spell back to Mel'jarak
    SPELL_RAIN_OF_BLADES        = 122406, // Triggers 122407 damage spell every 0.5s.
    SPELL_WIND_BOMB             = 131813, // Triggers 131814 bomb summon npc 67053.

    SPELL_WATCHFUL_EYE_1        = 125933, // Starting Normal and always Heroic aura - 9 adds alive, can control 4 / 3 on Heroic.
    SPELL_WATCHFUL_EYE_2        = 125935, // 6 adds alive, can control 2.
    SPELL_WATCHFUL_EYE_3        = 125936, // 3 adds alive, can control 0.
    SPELL_COWARDS               = 122399, // Remove crowd control from Mel'jarak's allies.

    SPELL_RECKLESNESS_N         = 122354, // Normal stackable version.
    SPELL_RECKLESNESS_H         = 125873, // Heroic 30 sec version.

    SPELL_BERSERK_MELJARAK      = 120207, // 480 seconds or 8 mins Enrage.

    /*** Misc / Impaling Spear ***/
    SPELL_IMPALING_SPEAR        = 122220, // Aura player receives when clicking on the racks. Gives Action Bar with button 1 to throw spear.
    SPELL_BROWN_MANTID_WINGS    = 140633,
    SPELL_RED_MANTID_WINGS      = 138392,
    SPELL_BLUE_MANTID_WINGS     = 138393,

    /*** Adds ***/
    // Wind Bomb
    SPELL_WIND_BOMB_THR_DMG     = 131830, // Damage in 5 yards at throwing.
    SPELL_WIND_BOMB_ARM         = 131835, // Visual bomb arm.
    SPELL_WIND_BOMB_EXPLODE     = 131842, // If a player goes in 6 yards (on off checked with 131836).

    // The Swarm
    SPELL_FATE_OF_THE_KORT      = 121774, // Share Damage spell for Kor'thik Elite Blademasters.
    SPELL_FATE_OF_THE_SRAT      = 121802, // Share Damage spell for Sra'thik Amber-Trappers.
    SPELL_FATE_OF_THE_ZART      = 121807, // Share Damage spell for Zar'thik Battle-Menders.

    // - Kor'thik Elite Blademaster
    SPELL_KORTHIK_STRIKE        = 123962, // All 3 use this at once on the same player.

    // - Sra'thik Amber-Trapper
    SPELL_AMBER_PRISON          = 121876, // Initial cast, triggers 121881 after 3 seconds.
    SPELL_AMBER_PRISON_TRIG     = 121881, // Triggers 121874 cast.
    SPELL_AMBER_PRISON_FC       = 121874, // Triggers 121885 aura.
    SPELL_AMBER_PRISON_AURA     = 121885, // Stun, root, visual etc. !ADD THIS: /* insert into spell_linked_spell values (121885, 129078, 1, 'Summon Amber Prison when hit by aura'); */
    SPELL_AMBER_PRISON_SUMM     = 129078, // Summons 62531 Amber Prison npc.

    SPELL_RESIDUE               = 122055, // Residue afflicts players who destroy Amber Prisons.

    SPELL_CORROSIVE_RESIN       = 122064,

    // !-  Moving while afflicted by Corrosive Resin removes a stack of Corrosive Resin and creates a Corrosive Resin Pool at the player's location. -!
    SPELL_CORR_RESIN_POOL_S     = 122123, // Summons Corrosive Resin Pool npc 67046.
    SPELL_CORR_RESIN_POOL_A     = 129005, // Aura for Corrosive Resin Pool, triggers 122125 dmg each sec.

    // - Zar'thik Battle-Mender
    SPELL_MENDING               = 122193, // Triggers a 200 yard dummy + heal spell 122147.
    SPELL_QUICKENING            = 122149, // All Swarm gets boost 25% dmg + as.

    SPELL_MELJARAK_BONUS        = 132197
};

enum Events
{
    /*** Boss ***/
    EVENT_WHIRLING_BLADE     = 1, // 36 secs after pull
    EVENT_WHIRLING_BLADE_REM,
    EVENT_RAIN_OF_BLADES,         // 60 secs after pull
    EVENT_WIND_BOMB,

    // Respawn in HM
    EVENT_SUMMON_KORTHIK,
    EVENT_SUMMON_SRATHIK,
    EVENT_SUMMON_ZARTHIK,

    EVENT_BERSERK_MELJARAK,

    /*** Adds ***/
    // Wind Bomb
    EVENT_ARM,                    // 3 secs after spawn

    // - Kor'thik Elite Blademaster
    EVENT_KORTHIK_STRIKE,         // 19s after pull.

    // - Sra'thik Amber-Trapper
    EVENT_AMBER_PRISON,
    EVENT_CORROSIVE_RESIN,

    // - Zar'thik Battle-Mender
    EVENT_MENDING,
    EVENT_QUICKENING,

    // - Whirling Blade
    EVENT_WB_BACK
};

enum Adds
{
    NPC_KORTHIK_ELITE_BLADEMASTER = 62402,
    NPC_SRATHIK_AMBER_TRAPPER     = 62405,
    NPC_ZARTHIK_BATTLE_MENDER     = 62408,
    NPC_WIND_BOMB                 = 67053,
    NPC_AMBER_PRISON              = 62531,
    NPC_WHIRLING_BLADE            = 63930,
    NPC_CORROSIVE_RESIN_POOL      = 67046
};

enum Types
{
    TYPE_WHIRLING_BLADE = 1,
    TYPE_WB_DEAL_DMG,
    TYPE_IS_IN_COMBAT,
    TYPE_NO_RESPAWN
};

enum eMeljarakActions
{
    ACTION_KORTHIK_DIED = 1,
    ACTION_SRATHIK_DIED,
    ACTION_ZARTHIK_DIED,
    ACTION_ADDGROUP_DIED,
    ACTION_CHECK_CONTROLLED_ADDS
};

#define DISPLAYID_WINDBOMB 45684

// Starting Positions for Kor'thik Elite Blademaster (62402)
Position PosKorthikEliteMaster[3] =
{
    {-2084.55f, 483.10f, 503.57f, 3.141593f},
    {-2089.31f, 475.97f, 503.57f, 3.141593f},
    {-2084.55f, 467.61f, 503.57f, 3.141593f}
};

Position PosSrathikAmberTrapper[3] =
{
    {-2077.00f, 490.33f, 503.57f, 3.141593f},
    {-2083.78f, 495.89f, 503.57f, 3.141593f},
    {-2079.33f, 502.90f, 503.57f, 3.141593f}
};

Position PosZarthikBattleMender[3] =
{
    {-2077.00f, 461.88f, 503.57f, 3.141593f},
    {-2083.78f, 456.09f, 503.57f, 3.141593f},
    {-2079.33f, 449.28f, 503.57f, 3.141593f}
};

// return true if can put Adds in combat
bool StartPack(InstanceScript* pInstance, Creature* launcher, Unit* attacker)
{
    if (!pInstance)
        return false;

    // Avoid multiple call
    if (pInstance->GetBossState(DATA_MELJARAK) == IN_PROGRESS || pInstance->GetBossState(DATA_MELJARAK) == TO_BE_DECIDED)
        return false;

    Creature* Meljarak = pInstance->GetCreature(NPC_MELJARAK);
    if (!Meljarak)
        return false;

    // Previous boss must have been done
    if (!pInstance->CheckRequiredBosses(DATA_MELJARAK) && !pInstance->instance->IsLFR())
    {
        if (!Meljarak->IsInEvadeMode())
            Meljarak->AI()->EnterEvadeMode(CreatureAI::EVADE_REASON_OTHER);
        return false;
    }

    // Set boss in combat if function has been called by an add
    pInstance->SetBossState(DATA_MELJARAK, IN_PROGRESS);
    if (launcher->GetEntry() != NPC_MELJARAK)
        Meljarak->AI()->EnterCombat(attacker);

    // Set adds in combat
    uint32 addEntries[3] = {NPC_KORTHIK_ELITE_BLADEMASTER, NPC_SRATHIK_AMBER_TRAPPER, NPC_ZARTHIK_BATTLE_MENDER};
    for (uint8 i = 0; i < 3; ++i)
    {
        std::list<Creature*> addList;
        GetCreatureListWithEntryInGrid(addList, launcher, addEntries[i], 30.0f);

        if (!addList.empty())
            for (Creature* add : addList)
                add->AI()->EnterCombat(attacker);
    }

    return true;
}

class boss_wind_lord_meljarak : public CreatureScript
{
public:
    boss_wind_lord_meljarak() : CreatureScript("boss_wind_lord_meljarak") { }

    struct boss_wind_lord_meljarakAI : public BossAI
    {
        boss_wind_lord_meljarakAI(Creature* creature) : BossAI(creature, DATA_MELJARAK), summons(me)
        {
            instance = creature->GetInstanceScript();
            introDone = false;
            creature->AddAura(SPELL_WATCHFUL_EYE_1, creature);
        }

        InstanceScript* instance;
        SummonList summons;
        EventMap events;
        bool introDone;
        bool windBombScheduled;
        bool inCombat;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();

            // Removing wind bombs, amber prisons, whirling blades and Resin pools NPC
            uint32 addEntries[4] = {NPC_AMBER_PRISON, NPC_WIND_BOMB, NPC_WHIRLING_BLADE, NPC_CORROSIVE_RESIN_POOL};
            for (uint8 i = 0; i < 4; ++i)
            {
                std::list<Creature*> addList;
                GetCreatureListWithEntryInGrid(addList, me, addEntries[i], 200.0f);

                if (!addList.empty())
                    for (Creature* add : addList)
                        add->DespawnOrUnsummon();
            }

            introDone = false;
            windBombScheduled = false;
            inCombat = false;
            me->RemoveAllDynObjects();
            me->SetVirtualItem(0, EQUIP_TAYAK_MELJARAK);

            if (!me->HasAura(SPELL_BROWN_MANTID_WINGS))
                DoCast(me, SPELL_BROWN_MANTID_WINGS);

            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_IMPALING_SPEAR);
                if (instance->GetBossState(DATA_MELJARAK) == TO_BE_DECIDED)
                    instance->SetBossState(DATA_MELJARAK, NOT_STARTED);
            }

            _Reset();

            // Summon the adds.
            SummonSwarmAdds();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (introDone || !who->IsWithinDistInMap(me, 40.0f))
                return;

            Talk(SAY_INTRO);
            introDone = true;

            if (!inCombat)
                EnterCombat(who);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (instance && !inCombat)
            {
                // Already resetting : cancel damage, and do nothing more
                if (instance->GetBossState(DATA_MELJARAK) == TO_BE_DECIDED)
                {
                    damage = 0;
                    return;
                }

                if (!instance->CheckRequiredBosses(DATA_MELJARAK) && !IsLFR())
                {
                    if (!me->IsInEvadeMode())
                        EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }

                if (!inCombat)
                    EnterCombat(attacker);
            }
        }

        void EnterCombat(Unit* attacker) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER || !instance || inCombat)
                return;

            if (!StartPack(instance, me, attacker) && instance->GetBossState(DATA_MELJARAK) != IN_PROGRESS)
                return;

            inCombat = true;

            Talk(SAY_AGGRO);
            std::list<GameObject*> l_DoorList;
            GetGameObjectListWithEntryInGrid(l_DoorList, me, GOB_DOOR_TO_MELJARAK, 200.0f);

            for (GameObject* l_Door : l_DoorList)
                l_Door->SetGoState(GO_STATE_READY);

            // Normal events.
            events.ScheduleEvent(EVENT_WHIRLING_BLADE, 36000);
            events.ScheduleEvent(EVENT_RAIN_OF_BLADES, 60000);
            events.ScheduleEvent(EVENT_BERSERK_MELJARAK, 8 * MINUTE * IN_MILLISECONDS);

            // Elite Battlemasters event.
            events.ScheduleEvent(EVENT_KORTHIK_STRIKE, 19000);

            me->AddAura(SPELL_WATCHFUL_EYE_1, me);

            if (instance)
            {
                instance->SetBossState(DATA_MELJARAK, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
            }

            _EnterCombat();

            me->SetReactState(REACT_AGGRESSIVE);
            me->SetInCombatWith(attacker);
            AttackStart(attacker);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->IsPlayer())
                Talk(SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->RemoveAllAuras();
            //Reset();
            events.Reset();
            summons.DespawnAll();

            // Removing wind bombs, amber prisons, whirling blades and Resin pools NPC
            uint32 addEntries[4] = {NPC_AMBER_PRISON, NPC_WIND_BOMB, NPC_WHIRLING_BLADE, NPC_CORROSIVE_RESIN_POOL};
            for (uint8 i = 0; i < 4; ++i)
            {
                std::list<Creature*> addList;
                GetCreatureListWithEntryInGrid(addList, me, addEntries[i], 100.0f);

                if (!addList.empty())
                    for (Creature* add : addList)
                        add->DespawnOrUnsummon();
            }

            // Resetting weapons rack available
            std::list<GameObject*> rackList;
            GetGameObjectListWithEntryInGrid(rackList, me, GOB_WEAPON_RACK, 100.0f);

            if (!rackList.empty())
                for (std::list<GameObject*>::iterator itr = rackList.begin(); itr != rackList.end(); ++itr)
                    if ((*itr)->HasFlag(GO_FLAG_NOT_SELECTABLE))
                        (*itr)->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

            me->DeleteThreatList();
            me->CombatStop(true);
            me->SetFullHealth();
            me->RemoveAllAuras();
            me->RemoveAllDynObjects();
            me->SetReactState(REACT_PASSIVE);
            windBombScheduled = false;
            inCombat = false;

            SummonSwarmAdds();

            if (instance)
            {
                if (instance->IsWipe())
                    instance->SetBossState(DATA_MELJARAK, FAIL);
                else
                    instance->SetBossState(DATA_MELJARAK, TO_BE_DECIDED);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_IMPALING_SPEAR);
            }

            std::list<GameObject*> l_DoorList;
            GetGameObjectListWithEntryInGrid(l_DoorList, me, GOB_DOOR_TO_MELJARAK, 200.0f);

            for (GameObject* l_Door : l_DoorList)
                l_Door->SetGoState(GO_STATE_ACTIVE);

            me->GetMotionMaster()->MoveTargetedHome();
            _EnterEvadeMode(EVADE_REASON_OTHER);
        }

        void JustReachedHome() override
        {
            DoCast(me, SPELL_WATCHFUL_EYE_1);
            if (instance)
                if (instance->GetBossState(DATA_MELJARAK) == TO_BE_DECIDED)
                    instance->SetBossState(DATA_MELJARAK, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            events.Reset();
            me->RemoveAllDynObjects();
            summons.DespawnAll();

            // Removing wind bombs, amber prisons, whirling blades and Resin pools NPC
            uint32 addEntries[4] = {NPC_AMBER_PRISON, NPC_WIND_BOMB, NPC_WHIRLING_BLADE, NPC_CORROSIVE_RESIN_POOL};
            for (uint8 i = 0; i < 4; ++i)
            {
                std::list<Creature*> addList;
                GetCreatureListWithEntryInGrid(addList, me, addEntries[i], 200.0f);

                if (!addList.empty())
                    for (Creature* add : addList)
                        add->DespawnOrUnsummon();
            }

            if (instance)
            {
                instance->SetBossState(DATA_MELJARAK, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_IMPALING_SPEAR);
            }

            _JustDied();

            std::list<GameObject*> l_DoorList;
            GetGameObjectListWithEntryInGrid(l_DoorList, me, GOB_DOOR_TO_MELJARAK, 200.0f);

            for (GameObject* l_Door : l_DoorList)
                l_Door->SetGoState(GO_STATE_ACTIVE);

            Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
            {
                if (Player* l_Player = l_Itr->GetSource())
                    me->CastSpell(l_Player, SPELL_MELJARAK_BONUS, true);
            }

            /*if (me->GetMap()->IsLFR())
            {
                me->ResetLootRecipients();
                Player* l_Player = me->GetMap()->GetPlayers().begin()->GetSource();
                if (l_Player && l_Player->GetGroup())
                    sLFGMgr->AutomaticLootAssignation(me, l_Player->GetGroup());
            }*/
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->setActive(true);

            if (me->IsInCombat())
                summon->AI()->DoZoneInCombat();
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == TYPE_IS_IN_COMBAT)
                return inCombat ? 1 : 0;
            return 0;
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case ACTION_KORTHIK_DIED:
                {
                    DoAction(ACTION_ADDGROUP_DIED);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SUMMON_KORTHIK, 45000);
                    break;
                }
                case ACTION_SRATHIK_DIED:
                {
                    DoAction(ACTION_ADDGROUP_DIED);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SUMMON_SRATHIK, 45000);
                    break;
                }
                case ACTION_ZARTHIK_DIED:
                {
                    DoAction(ACTION_ADDGROUP_DIED);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SUMMON_ZARTHIK, 45000);
                    break;
                }
                case ACTION_ADDGROUP_DIED:
                {
                    Talk(SAY_ADD_GROUP_DIES);
                    Talk(SAY_WATCHFUL_EYE);

                    // Heroic mode
                    if (IsHeroic())
                    {
                        me->AddAura(SPELL_RECKLESNESS_H, me);
                        break;
                    }
                    // Normal mode
                    else
                    {
                        me->AddAura(SPELL_RECKLESNESS_N, me);

                        uint8 addsAlive = GetLivingAddCount();

                        // Should be 6 or 3 - At least 1 group has been killed
                        if (addsAlive < 9)
                        {
                            me->RemoveAura(SPELL_WATCHFUL_EYE_1);
                            me->AddAura(SPELL_WATCHFUL_EYE_2, me);
                            // Should be 3 - At least 2 groups have been killed
                            if (addsAlive < 6)
                            {
                                me->RemoveAura(SPELL_WATCHFUL_EYE_2);
                                me->AddAura(SPELL_WATCHFUL_EYE_3, me);
                            }
                            // 0 - All groups have been killed
                            if (!addsAlive)
                                me->RemoveAura(SPELL_WATCHFUL_EYE_3);
                        }
                        // Check the controlled adds as limit has changed since a group just died
                        DoAction(ACTION_CHECK_CONTROLLED_ADDS);
                    }
                    break;
                }
                case ACTION_CHECK_CONTROLLED_ADDS:
                {
                    // In HM, 3 adds only can be controlled. In NM : 4 adds if 9 are alive, 2 if 6 are alive and none if 3 are alive
                    uint8 limit = IsHeroic() ? 3 : (me->HasAura(SPELL_WATCHFUL_EYE_1) ? 4 : (me->HasAura(SPELL_WATCHFUL_EYE_2) ? 2 : 0));

                    if (GetSpearImpaledAdds() > limit)
                        DoCast(SPELL_COWARDS);
                    break;
                }
                default:
                    break;
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (instance)
            {
                if (inCombat && !me->IsInEvadeMode() && instance->IsWipe())
                {
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }
            }

            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->HealthBelowPct(76) && !windBombScheduled)
            {
                events.ScheduleEvent(EVENT_WIND_BOMB, 6000);
                windBombScheduled = true;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Heroic Mode : make an adds' group respawn 45secs after it died
                    case EVENT_SUMMON_KORTHIK:
                    {
                        SummonSwarmAdds(NPC_KORTHIK_ELITE_BLADEMASTER);
                        break;
                    }
                    case EVENT_SUMMON_SRATHIK:
                    {
                        SummonSwarmAdds(NPC_SRATHIK_AMBER_TRAPPER);
                        break;
                    }
                    case EVENT_SUMMON_ZARTHIK:
                    {
                        SummonSwarmAdds(NPC_ZARTHIK_BATTLE_MENDER);
                        break;
                    }
                    // Elite Battlemasters event:
                    case EVENT_KORTHIK_STRIKE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                        {
                            std::list<Creature*> battleMasters;
                            GetCreatureListWithEntryInGrid(battleMasters, me, NPC_KORTHIK_ELITE_BLADEMASTER, 150.0f);

                            if (battleMasters.empty())
                                return;

                            // Cast it.
                            for (std::list<Creature*>::iterator iter = battleMasters.begin(); iter != battleMasters.end(); ++iter)
                                if ((*iter)->IsAlive())
                                    (*iter)->CastSpell(target, SPELL_KORTHIK_STRIKE, false);
                        }

                        events.ScheduleEvent(EVENT_KORTHIK_STRIKE, urand(34000, 50000));
                        break;
                    }
                    // Normal events.
                    case EVENT_WHIRLING_BLADE:
                    {
                        Talk(SAY_WHIRLING_BLADES);
                        Talk(ANN_WHIRLING_BLADES);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                        {
                            target->CastSpell(target, SPELL_WB_SUMMON, false);
                            me->CastSpell(me, SPELL_WHIRLING_BLADE, true);
                        }
                        events.ScheduleEvent(EVENT_WHIRLING_BLADE, urand(48000, 64000));
                        break;
                    }
                    case EVENT_RAIN_OF_BLADES:
                    {
                        Talk(SAY_RAIN_OF_BLADES);
                        Talk(ANN_RAIN_OF_BLADES);
                        DoCast(me, SPELL_RAIN_OF_BLADES);
                        events.ScheduleEvent(EVENT_RAIN_OF_BLADES, urand(48000, 64000));
                        break;
                    }
                    case EVENT_WIND_BOMB:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 150.0f, true))
                            DoCast(target, SPELL_WIND_BOMB);
                        events.ScheduleEvent(EVENT_WIND_BOMB, urand(18000, 24000));
                        break;
                    }
                    case EVENT_BERSERK_MELJARAK:
                    {
                        me->AddAura(SPELL_BERSERK_MELJARAK, me);
                        break;
                    }
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    /*** Special boss functions and calculations for adds. ***/

    private:

        void SummonSwarmAdds(uint32 entry = 0)
        {
            for (uint8 i = 0; i < 3; i++)
            {
                if (!entry || entry == NPC_KORTHIK_ELITE_BLADEMASTER)
                    me->SummonCreature(NPC_KORTHIK_ELITE_BLADEMASTER, PosKorthikEliteMaster[i]);
                if (!entry || entry == NPC_SRATHIK_AMBER_TRAPPER)
                    me->SummonCreature(NPC_SRATHIK_AMBER_TRAPPER,     PosSrathikAmberTrapper[i]);
                if (!entry || entry == NPC_ZARTHIK_BATTLE_MENDER)
                    me->SummonCreature(NPC_ZARTHIK_BATTLE_MENDER,     PosZarthikBattleMender[i]);
            }
        }

        uint32 GetLivingAddCount()
        {
            uint32 livingAdds = 0;

            std::list<Creature*> allAdds;

            GetCreatureListWithEntryInGrid(allAdds, me, NPC_KORTHIK_ELITE_BLADEMASTER, 150.0f);
            GetCreatureListWithEntryInGrid(allAdds, me, NPC_SRATHIK_AMBER_TRAPPER, 150.0f);
            GetCreatureListWithEntryInGrid(allAdds, me, NPC_ZARTHIK_BATTLE_MENDER, 150.0f);

            if (allAdds.empty())
                return livingAdds;

            for (Creature* add : allAdds)
                if (add->IsAlive())
                    ++livingAdds;

            return livingAdds;
        }

        uint32 GetSpearImpaledAdds()
        {
            uint32 impaledAdds = 0;
            std::list<Creature*> allAdds;
            uint32 addEntries[3] = { NPC_KORTHIK_ELITE_BLADEMASTER, NPC_SRATHIK_AMBER_TRAPPER, NPC_ZARTHIK_BATTLE_MENDER };

            for (uint8 i = 0; i < 3; ++i)
            {
                allAdds.clear();
                GetCreatureListWithEntryInGrid(allAdds, me, addEntries[i], 150.0f);

                for (Creature* add : allAdds)
                    if (add->IsAlive() && add->HasBreakableByDamageCrowdControlAura())
                        ++impaledAdds;
            }
            return impaledAdds;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_wind_lord_meljarakAI(creature);
    }
};

// Korthik Elite Blademaster: 62402 - handled in boss script, script here only used for life sharing
class npc_korthik_elite_blademaster: public CreatureScript
{
public:
    npc_korthik_elite_blademaster() : CreatureScript("npc_korthik_elite_blademaster") { }

    struct npc_korthik_elite_blademasterAI: public ScriptedAI
    {
        npc_korthik_elite_blademasterAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        bool inCombat;
        bool respawn;

        void Reset() override
        {
            inCombat = false;
            respawn = true;
            me->SetVirtualItem(0, EQUIP_TRASH_5);
            if (!me->HasAura(SPELL_BROWN_MANTID_WINGS))
                DoCast(me, SPELL_BROWN_MANTID_WINGS);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_COWARDS || !pInstance)
                return;

            if (me->HasBreakableByDamageCrowdControlAura())
            {
                if (Creature* meljarak = pInstance->GetCreature(NPC_MELJARAK))
                    meljarak->AI()->DoAction(ACTION_CHECK_CONTROLLED_ADDS);
            }
        }

        void JustDied(Unit* killer) override
        {
            if (respawn)
            {
                // Killing the other adds of the same group
                std::list<Creature*> mobList;
                GetCreatureListWithEntryInGrid(mobList, me, me->GetEntry(), 200.0f);

                if (!mobList.empty())
                {
                    for (auto mob : mobList)
                    {
                        // Set respawn to 0 for the other mobs, to avoid infinite loops of Kill/JustDied/Respawn
                        mob->AI()->SetData(TYPE_NO_RESPAWN, 0);
                        if (mob->IsAlive())
                            killer->Kill(mob, false);
                    }
                }

                if (pInstance)
                    if (Creature* meljarak = pInstance->GetCreature(NPC_MELJARAK))
                        meljarak->AI()->DoAction(ACTION_KORTHIK_DIED);
            }
        }

        void SetData(uint32 type, uint32 /*value*/) override
        {
            if (type == TYPE_NO_RESPAWN)
                respawn = false;
        }

        void EnterCombat(Unit* attacker) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER || inCombat)
                return;

            if (!StartPack(pInstance, me, attacker))
                return;

            inCombat = true;

            me->SetInCombatWith(attacker);
            AttackStart(attacker);
        }

        void DamageTaken(Unit* killer, uint32 &damage) override
        {
            if (killer->GetEntry() == me->GetEntry())
                return;


            std::list<Creature*> mobList;
            GetCreatureListWithEntryInGrid(mobList, me, me->GetEntry(), 200.0f);

            if (!mobList.empty())
            {
                if (damage > me->GetHealth())
                {
                    for (auto mob : mobList)
                        killer->Kill(mob, true);
                }
                else
                {
                    for (auto mob : mobList)
                        if (mob->GetGUID() != me->GetGUID())
                            mob->ModifyHealth(-int32(damage));
                }
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == TYPE_IS_IN_COMBAT)
                return inCombat ? 1 : 0;
            return 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_korthik_elite_blademasterAI(creature);
    }

};

struct NonAlreadyAmberPrisoner : public std::unary_function<Unit*, bool>
{
    public:
        NonAlreadyAmberPrisoner() { }
        bool operator()(Unit const* target) const
        {
            if (target->HasAura(SPELL_AMBER_PRISON_AURA))
                return false;

            return true;
        }
};

// Srathik Amber Trapper: 62405.
class npc_srathik_amber_trapper: public CreatureScript
{
public:
    npc_srathik_amber_trapper() : CreatureScript("npc_srathik_amber_trapper") { }

    struct npc_srathik_amber_trapperAI: public ScriptedAI
    {
        npc_srathik_amber_trapperAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            charged = false;
        }

        InstanceScript* pInstance;
        EventMap events;
        bool charged;
        bool inCombat;
        bool respawn;

        void Reset() override
        {
            events.Reset();
            inCombat = false;
            respawn = true;
            me->SetVirtualItem(0, EQUIP_TRASH_9);
            me->SetVirtualItem(2, EQUIP_TRASH_9);
            if (!me->HasAura(SPELL_RED_MANTID_WINGS))
                DoCast(SPELL_RED_MANTID_WINGS);
        }

        void EnterCombat(Unit* attacker) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER || inCombat)
                return;

            if (!StartPack(pInstance, me, attacker))
                return;

            inCombat = true;

            me->SetInCombatWith(attacker);
            AttackStart(attacker);

            events.ScheduleEvent(EVENT_AMBER_PRISON, urand(13000, 47000));
            events.ScheduleEvent(EVENT_CORROSIVE_RESIN, urand(8000, 40000));
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_COWARDS || !pInstance)
                return;

            if (me->HasBreakableByDamageCrowdControlAura())
            {
                if (Creature* meljarak = pInstance->GetCreature(NPC_MELJARAK))
                    meljarak->AI()->DoAction(ACTION_CHECK_CONTROLLED_ADDS);
            }
        }

        void JustDied(Unit* killer) override
        {
            events.Reset();
            if (respawn)
            {
                // Killing the other adds of the same group
                std::list<Creature*> mobList;
                GetCreatureListWithEntryInGrid(mobList, me, me->GetEntry(), 200.0f);

                if (!mobList.empty())
                {
                    for (auto mob : mobList)
                    {
                        // Set respawn to 0 for the other mobs, to avoid infinite loops of Kill/JustDied/Respawn
                        mob->AI()->SetData(TYPE_NO_RESPAWN, 0);
                        if (mob->IsAlive())
                            killer->Kill(mob, false);
                    }
                }

                if (pInstance)
                    if (Creature* meljarak = pInstance->GetCreature(NPC_MELJARAK))
                        meljarak->AI()->DoAction(ACTION_SRATHIK_DIED);
            }
        }

        void SetData(uint32 type, uint32 /*value*/) override
        {
            if (type == TYPE_NO_RESPAWN)
                respawn = false;
        }

        void DamageTaken(Unit* killer, uint32 &damage) override
        {
            if (killer->GetEntry() == me->GetEntry())
                return;


            std::list<Creature*> mobList;
            GetCreatureListWithEntryInGrid(mobList, me, me->GetEntry(), 200.0f);

            if (mobList.empty())
                return;

            if (damage > me->GetHealth())
            {
                for (auto mob : mobList)
                    killer->Kill(mob, true);
            }
            else
            {
                for (auto mob : mobList)
                    if (mob->GetGUID() != me->GetGUID())
                        mob->ModifyHealth(-int32(damage));
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == TYPE_IS_IN_COMBAT)
                return inCombat ? 1 : 0;
            return 0;
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_AMBER_PRISON:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonAlreadyAmberPrisoner()))
                            DoCast(target, SPELL_AMBER_PRISON);
                        events.ScheduleEvent(EVENT_AMBER_PRISON, urand(35000, 70000));
                        break;

                    case EVENT_CORROSIVE_RESIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                            DoCast(target, SPELL_CORROSIVE_RESIN);
                        events.ScheduleEvent(EVENT_CORROSIVE_RESIN, urand(25000, 32000));
                        break;

                    default: break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_srathik_amber_trapperAI(creature);
    }
};

// Zarthik Battle Mender: 62408.
class npc_zarthik_battle_mender: public CreatureScript
{
public:
    npc_zarthik_battle_mender() : CreatureScript("npc_zarthik_battle_mender") { }

    struct npc_zarthik_battle_menderAI: public ScriptedAI
    {
        npc_zarthik_battle_menderAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            charged = false;
        }

        InstanceScript* pInstance;
        EventMap events;
        bool charged;
        bool inCombat;
        bool respawn;

        void Reset() override
        {
            events.Reset();
            inCombat = false;
            respawn = true;
            me->SetVirtualItem(0, EQUIP_ZORLOK);
            if (!me->HasAura(SPELL_BLUE_MANTID_WINGS))
                DoCast(me, SPELL_BLUE_MANTID_WINGS);
        }

        void EnterCombat(Unit* attacker) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER || inCombat)
                return;

            if (!StartPack(pInstance, me, attacker))
                return;

            inCombat = true;

            me->SetInCombatWith(attacker);
            AttackStart(attacker);

            events.ScheduleEvent(EVENT_MENDING, urand(30000, 49000));
            events.ScheduleEvent(EVENT_QUICKENING, urand(12000, 28000));

        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_COWARDS || !pInstance)
                return;

            if (me->HasBreakableByDamageCrowdControlAura())
            {
                if (Creature* meljarak = pInstance->GetCreature(NPC_MELJARAK))
                    meljarak->AI()->DoAction(ACTION_CHECK_CONTROLLED_ADDS);
            }
        }

        void JustDied(Unit* killer) override
        {
            events.Reset();
            if (respawn)
            {
                // Killing the other adds of the same group
                std::list<Creature*> mobList;
                GetCreatureListWithEntryInGrid(mobList, me, me->GetEntry(), 200.0f);

                if (!mobList.empty())
                {
                    for (auto mob : mobList)
                    {
                        // Set respawn to 0 for the other mobs, to avoid infinite loops of Kill/JustDied/Respawn
                        mob->AI()->SetData(TYPE_NO_RESPAWN, 0);
                        if (mob->IsAlive())
                            killer->Kill(mob, false);
                    }
                }

                if (pInstance)
                    if (Creature* meljarak = pInstance->GetCreature(NPC_MELJARAK))
                        meljarak->AI()->DoAction(ACTION_ZARTHIK_DIED);
            }
        }

        void SetData(uint32 type, uint32 /*value*/) override
        {
            if (type == TYPE_NO_RESPAWN)
                respawn = false;
        }

        void DamageTaken(Unit* killer, uint32 &damage) override
        {
            if (killer->GetEntry() == me->GetEntry())
                return;


            std::list<Creature*> mobList;
            GetCreatureListWithEntryInGrid(mobList, me, me->GetEntry(), 200.0f);

            if (mobList.empty())
                return;

            if (damage > me->GetHealth())
            {
                for (auto mob : mobList)
                    killer->Kill(mob, true);
            }
            else
            {
                for (auto mob : mobList)
                    if (mob->GetGUID() != me->GetGUID())
                        mob->ModifyHealth(-int32(damage));
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == TYPE_IS_IN_COMBAT)
                return inCombat ? 1 : 0;
            return 0;
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MENDING:
                    {
                        uint32 result = urand(0, 2);
                        uint32 addEntries[3] = {NPC_KORTHIK_ELITE_BLADEMASTER, NPC_SRATHIK_AMBER_TRAPPER, NPC_ZARTHIK_BATTLE_MENDER};

                        // Mending is cast on one add, but he shares his life with the whole group, all adds of the group are healed
                        std::list<Creature*> addList;
                        GetCreatureListWithEntryInGrid(addList, me, addEntries[result], 150.0f);

                        if (!addList.empty())
                            for (Creature* add : addList)
                                me->CastSpell(add, SPELL_MENDING, true);

                        events.ScheduleEvent(EVENT_MENDING, urand(30000, 40000));
                    }
                    case EVENT_QUICKENING:
                    {
                        DoCast(me, SPELL_QUICKENING);
                        events.ScheduleEvent(EVENT_QUICKENING, urand(33000, 54000));
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_zarthik_battle_menderAI(creature);
    }
};

// Wind Bomb: 67053.
class npc_wind_bomb_meljarak : public CreatureScript
{
    public:
        npc_wind_bomb_meljarak() : CreatureScript("npc_wind_bomb_meljarak") { }

        struct npc_wind_bomb_meljarakAI : public ScriptedAI
        {
            npc_wind_bomb_meljarakAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;
            bool canExplode;

            void IsSummonedBy(Unit* /*p_Summoner*/) override
            {
                // Forcing display id, sometimes wrong otherwise
                me->SetDisplayId(DISPLAYID_WINDBOMB);
                canExplode = false;
                me->SetInCombatWithZone();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->SetReactState(REACT_PASSIVE);

                DoCast(me, SPELL_WIND_BOMB_THR_DMG);

                events.ScheduleEvent(EVENT_ARM, 3000);
            }

            void UpdateAI(uint32 const diff) override
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_ARM)
                {
                    DoCast(me, SPELL_WIND_BOMB_ARM);
                    canExplode = true;
                }

                if (canExplode)
                {
                    if (me->SelectNearestPlayer(2.5f) != nullptr)
                    {
                        DoCast(me, SPELL_WIND_BOMB_EXPLODE);
                        canExplode = false;
                        me->DespawnOrUnsummon();
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wind_bomb_meljarakAI(creature);
        }
};

// Corrosive Resin Pool: 67046.
class npc_corrosive_resin_pool : public CreatureScript
{
public:
    npc_corrosive_resin_pool() : CreatureScript("npc_corrosive_resin_pool") { }

    struct npc_corrosive_resin_poolAI : public ScriptedAI
    {
        npc_corrosive_resin_poolAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetInCombatWithZone();
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SetReactState(REACT_PASSIVE);

            me->AddAura(SPELL_CORR_RESIN_POOL_A, me); // Damage aura.
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corrosive_resin_poolAI(creature);
    }
};

// Amber Prison: 62531.
class npc_amber_prison_meljarak : public CreatureScript
{
public:
    npc_amber_prison_meljarak() : CreatureScript("npc_amber_prison_meljarak") { }

    struct npc_amber_prison_meljarakAI : public ScriptedAI
    {
        npc_amber_prison_meljarakAI(Creature* creature) : ScriptedAI(creature) { }

        ObjectGuid targetGUID;
        uint32 timerChecktarget;

        void IsSummonedBy(Unit* summoner) override
        {
            targetGUID = summoner->GetGUID();
            timerChecktarget = 500;
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (attacker->HasAura(SPELL_RESIDUE))
                damage = 0;
        }

        void JustDied(Unit* killer) override
        {
            if (Unit* l_Target = ObjectAccessor::GetUnit(*me, targetGUID))
                l_Target->RemoveAurasDueToSpell(SPELL_AMBER_PRISON_AURA);
            me->CastSpell(killer, SPELL_RESIDUE, false);
        }

        void UpdateAI(uint32 const diff) override
        {
            if (timerChecktarget <= diff)
            {
                // Check if the debuff has expired.
                if (Unit* l_Target = ObjectAccessor::GetUnit(*me, targetGUID))
                {
                    if (l_Target && !l_Target->HasAura(SPELL_AMBER_PRISON_AURA))
                        me->DespawnOrUnsummon(100);
                }

                timerChecktarget = 500;
            }
            else
                timerChecktarget -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_amber_prison_meljarakAI (creature);
    }
};

// 63930 - Whirling Blade
class npc_whirling_blade : public CreatureScript
{
public:
    npc_whirling_blade(): CreatureScript("npc_whirling_blade") { }

    struct npc_whirling_bladeAI : public ScriptedAI
    {
        npc_whirling_bladeAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;
        uint32 dealDamages;

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_WB_BACK, 3000);

            if (Creature* Meljarak = pInstance->GetCreature(NPC_MELJARAK))
            {
                Meljarak->CastSpell(me, SPELL_WB_SWORD, false);
                Meljarak->CastSpell(me, SPELL_WB_LIGHT, false);
                dealDamages = 1;
            }
            else
                me->DespawnOrUnsummon();
        }

        void SetData(uint32 type, uint32 value) override
        {
            if (type == TYPE_WB_DEAL_DMG)
                dealDamages = value;
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == TYPE_WB_DEAL_DMG)
                return dealDamages;
            return 0;
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_WB_BACK)
            {
                if (Creature* Meljarak = pInstance->GetCreature(NPC_MELJARAK))
                {
                    me->CastSpell(Meljarak, SPELL_WB_SWORD, false);
                    me->CastSpell(Meljarak, SPELL_WB_LIGHT, false);
                    dealDamages = 1;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_whirling_bladeAI(creature);
    }
};

// Corrosive Resin: 122064.
class spell_meljarak_corrosive_resin : public SpellScriptLoader
{
    public:
        spell_meljarak_corrosive_resin() : SpellScriptLoader("spell_meljarak_corrosive_resin") { }

        class spell_meljarak_corrosive_resin_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_meljarak_corrosive_resin_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                Unit* owner = GetOwner()->ToUnit();
                if (!owner)
                    return;

                // Check target moving.
                if (owner->isMoving())
                {
                    // Check the aura.
                    if (Aura* resinAura = owner->GetAura(SPELL_CORROSIVE_RESIN))
                    {
                        // Remove the stacks.
                        if (resinAura->GetStackAmount() > 1)
                            resinAura->SetStackAmount(resinAura->GetStackAmount() - 1);
                        else
                            owner->RemoveAurasDueToSpell(SPELL_CORROSIVE_RESIN);

                        // Summon the pool.
                        owner->CastSpell(owner, SPELL_CORR_RESIN_POOL_S, false);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_meljarak_corrosive_resin_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_meljarak_corrosive_resin_AuraScript();
        }
};

// mending - 122147
class spell_mending : public SpellScriptLoader
{
public:
    spell_mending() : SpellScriptLoader("spell_mending") { }

    class spell_mending_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mending_SpellScript);

        bool Load() override
        {
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targets.clear();

            std::list<Creature*> tmpTargets;

            GetCaster()->GetCreatureListWithEntryInGridAppend(tmpTargets, NPC_KORTHIK_ELITE_BLADEMASTER, 150.0f);
            GetCaster()->GetCreatureListWithEntryInGridAppend(tmpTargets, NPC_SRATHIK_AMBER_TRAPPER, 150.0f);
            GetCaster()->GetCreatureListWithEntryInGridAppend(tmpTargets, NPC_ZARTHIK_BATTLE_MENDER, 150.0f);

            if (tmpTargets.empty())
                return;

            Creature* tmp = *tmpTargets.begin();
            float percentLife = 100.0f;

            for (auto itr : tmpTargets)
            {
                if (!itr->IsAlive())
                    continue;

                if (itr->GetHealthPct() < percentLife)
                {
                    tmp = itr;
                    percentLife = itr->GetHealthPct();
                }
            }

            targets.push_back(tmp);
        }

        void Register() override
        {
            switch (m_scriptSpellId)
            {
                case 122193:
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mending_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                    break;
                default:
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mending_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                break;
            }
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mending_SpellScript();
    }
};

// 121897 - Whirling Blade - Flying Sword
class spell_whirling_blade_sword : public SpellScriptLoader
{
public:
    spell_whirling_blade_sword() : SpellScriptLoader("spell_whirling_blade_sword") { }

    class spell_whirling_blade_sword_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_whirling_blade_sword_SpellScript);

        void BackToMeljarak(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                // In any case : Meljarak' sword not in flight, so stop damaging
                if (Creature* whirlingBlade = GetClosestCreatureWithEntry(caster, NPC_WHIRLING_BLADE, 100.0f))
                    whirlingBlade->AI()->SetData(TYPE_WB_DEAL_DMG, 0);

                // Cast by NPC Whirling Blade: remove aura to give Mel'jarak back his weapon and stop damages on players
                if (caster->GetEntry() == NPC_WHIRLING_BLADE)
                {
                    if (Creature* Meljarak = GetClosestCreatureWithEntry(caster, NPC_MELJARAK, 150.0f, true))
                    {
                        if (Meljarak->HasAura(SPELL_WHIRLING_BLADE))
                            Meljarak->RemoveAura(SPELL_WHIRLING_BLADE);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_whirling_blade_sword_SpellScript::BackToMeljarak, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_whirling_blade_sword_SpellScript();
    }
};

// 121898 - Wirling Blade - Damages
class spell_whirling_blade_damages : public SpellScriptLoader
{
public:
    spell_whirling_blade_damages() : SpellScriptLoader("spell_whirling_blade_damages") { }

    class spell_whirling_blade_damages_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_whirling_blade_damages_SpellScript);

        void SelectTargets(std::list<WorldObject*> &targets)
        {
            targets.clear();

            if (Unit* caster = GetCaster())
            {
                if (Creature* target = GetClosestCreatureWithEntry(caster, NPC_WHIRLING_BLADE, 100.0f))
                {
                    if (target->AI()->GetData(TYPE_WB_DEAL_DMG))
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, caster, 30.0f);

                        if (!playerList.empty())
                            for (auto player : playerList)
                                if (player->IsInBetween(caster, target, 3.0f))
                                    targets.push_back(player);
                    }
                }
                else
                    caster->RemoveAura(SPELL_WHIRLING_BLADE);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_whirling_blade_damages_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_whirling_blade_damages_SpellScript();
    }
};

// 211675 - Kri'thik Weapon Rack
class go_krithik_weapon_rack : public GameObjectScript
{
    public:
        go_krithik_weapon_rack() : GameObjectScript("go_krithik_weapon_rack") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (!player->HasAura(SPELL_IMPALING_SPEAR))
            {
                player->AddAura(SPELL_IMPALING_SPEAR, player);
                go->SetGoState(GO_STATE_READY);
                go->AddFlag(GO_FLAG_NOT_SELECTABLE);
                return true;
            }

            return false;
        }
};

void AddSC_boss_meljarak()
{
    new boss_wind_lord_meljarak();          // 62397
    new npc_korthik_elite_blademaster();    // 62402
    new npc_srathik_amber_trapper();        // 62405
    new npc_zarthik_battle_mender();        // 62408
    new npc_wind_bomb_meljarak();           // 67053
    new npc_corrosive_resin_pool();         // 67046
    new npc_amber_prison_meljarak();        // 62531
    new npc_whirling_blade();               // 63930
    new spell_meljarak_corrosive_resin();   // 122064
    new spell_mending();                    // 122147
    new spell_whirling_blade_sword();       // 121897
    new spell_whirling_blade_damages();     // 121898
    new go_krithik_weapon_rack();           // 211675
}
