/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

// Todo pour le HM : Spawn les cristaux a l'entree en combat

enum eSpells
{
    // Jasper
    SPELL_JASPER_OVERLOAD               = 115843,
    SPELL_JASPER_PETRIFICATION          = 116036,
    SPELL_JASPER_PETRIFICATION_BAR      = 131270,
    SEPLL_JASPER_TRUE_FORM              = 115828,
    SPELL_JASPER_CHAINS                 = 130395,
    SPELL_JASPER_CHAINS_VISUAL          = 130403,
    SPELL_JASPER_CHAINS_DAMAGE          = 130404,
    SPELL_LIVING_JASPER                 = 116304,

    // Jade
    SPELL_JADE_OVERLOAD                 = 115842,
    SPELL_JADE_PETRIFICATION            = 116006,
    SPELL_JADE_PETRIFICATION_BAR        = 131269,
    SEPLL_JADE_TRUE_FORM                = 115827,
    SPELL_JADE_SHARDS                   = 116223,
    SPELL_LIVING_JADE                   = 116301,

    // Amethyst
    SPELL_AMETHYST_OVERLOAD             = 115844,
    SPELL_AMETHYST_PETRIFICATION        = 116057,
    SPELL_AMETHYST_PETRIFICATION_BAR    = 131255,
    SPELL_AMETHYST_TRUE_FORM            = 115829,
    SPELL_AMETHYST_POOL                 = 116235,
    SPELL_AMETHYST_POOL_DAMAGE          = 130774,
    SPELL_LIVING_AMETHYST               = 116322,

    // Cobalt
    SPELL_COBALT_OVERLOAD               = 115840,
    SPELL_COBALT_PETRIFICATION          = 115852,
    SPELL_COBALT_PETRIFICATION_BAR      = 131268,
    SEPLL_COBALT_TRUE_FORM              = 115771,
    SPELL_COBALT_MINE                   = 129460,
    SPELL_LIVING_COBALT                 = 116199,

    // Energized Tiles
    SPELL_ENERGIZED_TILE_BUFF           = 116541,
    SPELL_ENERGIZED_TILE_VISUAL         = 116542,
    SPELL_DESACTIVE_ENERGIZED_TILES     = 116529,

    // Shared
    SPELL_SOLID_STONE                   = 115745,
    SPELL_REND_FLESH                    = 125206,
    SPELL_ANIM_SIT                      = 128886,
    SPELL_ZERO_ENERGY                   = 72242,
    SPELL_TOTALY_PETRIFIED              = 115877,
};

enum eEvents
{
    // Controler
    EVENT_PETRIFICATION                 = 1,
    EVENT_TILE_DESACTIVATION            = 2,

    // Guardians
    EVENT_REGEN                         = 3,
    EVENT_CHECK_NEAR_GUARDIANS          = 4,
    EVENT_CHECK_ENERGY                  = 5,
    EVENT_REND_FLESH                    = 6,
    EVENT_MAIN_ATTACK                   = 7,
    EVENT_DESACTIVATE_TILES             = 8,
    EVENT_ENRAGE                        = 9
};

enum eTalks
{
    TALK_PETRIFICATION    = 0,
    TALK_OVERLOAD_WARNING = 1,
    TALK_OVERLOAD         = 2
};

uint32 guardiansEntry[4] =
{
    NPC_JASPER,
    NPC_JADE,
    NPC_AMETHYST,
    NPC_COBALT
};

class boss_stone_guard_controler : public CreatureScript
{
    public:
        boss_stone_guard_controler() : CreatureScript("boss_stone_guard_controler") {}

        struct boss_stone_guard_controlerAI : public ScriptedAI
        {
            boss_stone_guard_controlerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            uint32 lastPetrifierEntry;

            uint8 nextTileDesactivation;

            bool fightInProgress;

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetVisible(false);

                fightInProgress = false;
                lastPetrifierEntry = 0;
                nextTileDesactivation = 75;

                if (pInstance->GetBossState(DATA_STONE_GUARD) != DONE)
                    pInstance->SetBossState(DATA_STONE_GUARD, NOT_STARTED);
                
                events.ScheduleEvent(EVENT_PETRIFICATION, 15000);

                if (pInstance->instance->IsHeroic())
                    events.ScheduleEvent(EVENT_TILE_DESACTIVATION, 2000);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ENTER_COMBAT:
                    {
                        for (uint32 entry: guardiansEntry)
                            if (Creature* guardian = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(entry))))
                                if (guardian->IsAlive())
                                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, guardian);

                        events.ScheduleEvent(EVENT_PETRIFICATION, 15000);
                        fightInProgress = true;
                        break;
                    }
                    case ACTION_GUARDIAN_DIED:
                    {
                        if (!fightInProgress)
                            break;

                        uint8 aliveGuardianCount = 0;
                        for (uint32 entry: guardiansEntry)
                            if (Creature* guardian = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(entry))))
                                if (guardian->IsAlive())
                                    ++aliveGuardianCount;

                        if (aliveGuardianCount) // break if a guardian is still alive
                            break;

                        for (uint32 entry: guardiansEntry)
                            if (Creature* guardian = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(entry))))
                                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, guardian);
                        
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOTALY_PETRIFIED);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JASPER_CHAINS);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JASPER_PETRIFICATION_BAR);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JADE_PETRIFICATION_BAR);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AMETHYST_PETRIFICATION_BAR);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_COBALT_PETRIFICATION_BAR);
                        pInstance->SetBossState(DATA_STONE_GUARD, DONE);
                        fightInProgress = false;
                        break;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!fightInProgress)
                    return;

                if (!pInstance)
                    return;

                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_PETRIFICATION:
                    {
                        if (fightInProgress)
                        {
                            bool alreadyOnePetrificationInProgress = false;

                            for (uint8 i = 0; i < 4; ++i)
                                if (uint64 stoneGuardGuid = pInstance->GetData64(guardiansEntry[i]))
                                    if (Creature* stoneGuard = pInstance->instance->GetCreature(pInstance->GetObjectGuid(stoneGuardGuid)))
                                        if (stoneGuard->HasAura(SPELL_JASPER_PETRIFICATION)   || stoneGuard->HasAura(SPELL_JADE_PETRIFICATION) ||
                                            stoneGuard->HasAura(SPELL_AMETHYST_PETRIFICATION) || stoneGuard->HasAura(SPELL_COBALT_PETRIFICATION))
                                        {
                                            alreadyOnePetrificationInProgress = true;
                                            break;
                                        }

                            if (alreadyOnePetrificationInProgress)
                            {
                                events.ScheduleEvent(EVENT_PETRIFICATION, 20000);
                                break;
                            }

                            uint32 nextPetrifierEntry = 0;
                            do
                            {
                                nextPetrifierEntry = guardiansEntry[urand(0, 3)];
                            }
                            while (nextPetrifierEntry == lastPetrifierEntry);

                            if (uint64 stoneGuardGuid = pInstance->GetData64(nextPetrifierEntry))
                            {
                                if (Creature* stoneGuard = pInstance->instance->GetCreature(pInstance->GetObjectGuid(stoneGuardGuid)))
                                {
                                    if (stoneGuard->IsAlive() && stoneGuard->IsInCombat())
                                    {
                                        stoneGuard->AI()->DoAction(ACTION_PETRIFICATION);
                                        lastPetrifierEntry = nextPetrifierEntry;
                                        events.ScheduleEvent(EVENT_PETRIFICATION, 90000);
                                    }
                                    else
                                        events.ScheduleEvent(EVENT_PETRIFICATION, 2000);
                                }
                                else
                                    events.ScheduleEvent(EVENT_PETRIFICATION, 2000);
                            }
                            else
                                events.ScheduleEvent(EVENT_PETRIFICATION, 2000);
                        }
                        break;
                    }
                    case EVENT_TILE_DESACTIVATION:
                    {
                        if (!nextTileDesactivation)
                            break;

                        Creature* guardian = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(guardiansEntry[0])));

                        if (!guardian || !guardian->IsAlive()) // 0 can be the one despawned, we try another
                            guardian = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(guardiansEntry[1])));

                        if (guardian) // They all have same life, we can get only get one
                        {
                            if (guardian->GetHealthPct() <= nextTileDesactivation)
                            {
                                for (uint32 entry: guardiansEntry)
                                    if (Creature* gardianForSpell = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(entry))))
                                        gardianForSpell->CastSpell(gardianForSpell, SPELL_DESACTIVE_ENERGIZED_TILES, true);

                                pInstance->SetData(DATA_ACTION_REMOVE_ENERGIZED_TILE, 1);

                                if (nextTileDesactivation == 75)
                                {
                                    nextTileDesactivation = 40;
                                }
                                else
                                    nextTileDesactivation = 0;
                            }
                        }

                        events.ScheduleEvent(EVENT_TILE_DESACTIVATION, 2000);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_stone_guard_controlerAI(creature);
        }
};

class boss_generic_guardian : public CreatureScript
{
    public:
        boss_generic_guardian() : CreatureScript("boss_generic_guardian") {}

        struct boss_generic_guardianAI : public BossAI
        {
            boss_generic_guardianAI(Creature* creature) : BossAI(creature, DATA_STONE_GUARD), summons(creature) {}

            EventMap events;
            SummonList summons;
            
            uint32 actualEnergy;
            uint32 spellOverloadId;
            uint32 spellPetrificationId;
            uint32 spellPetrificationBarId;
            uint32 spellTrueFormId;
            uint32 spellMainAttack;

            uint32 crystalToSummon;
            uint64 crystalGUID;

            bool warnedForOverload;
            bool isInTrueForm;

            Creature* GetController()
            {
                if (instance) return me->GetMap()->GetCreature(instance->GetObjectGuid(instance->GetData64(NPC_STONE_GUARD_CONTROLER))); else return NULL;
            }

            void Reset()
            {
                if (!me->IsAlive())
                    return;

                me->ResetLootMode();
                events.Reset();

                actualEnergy = 0;
                isInTrueForm = false;
                warnedForOverload = false;
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
                me->setPowerType(POWER_MANA);
                me->SetMaxPower(POWER_MANA, 100);
                me->SetPower(POWER_MANA, 0);
                
                me->CastSpell(me, SPELL_SOLID_STONE, true);
                me->CastSpell(me, SPELL_ANIM_SIT,    true);
                me->CastSpell(me, SPELL_ZERO_ENERGY, true);

                if (Creature* stoneGuardControler = me->GetMap()->GetCreature(GetGUID(NPC_STONE_GUARD_CONTROLER)))
                    stoneGuardControler->AI()->Reset();

                summons.DespawnAll();
                me->RemoveAllDynObjects();

                switch (me->GetEntry())
                {
                    case NPC_JASPER:
                        spellOverloadId             = SPELL_JASPER_OVERLOAD;
                        spellPetrificationId        = SPELL_JASPER_PETRIFICATION;
                        spellPetrificationBarId     = SPELL_JASPER_PETRIFICATION_BAR;
                        spellTrueFormId             = SEPLL_JASPER_TRUE_FORM;
                        spellMainAttack             = SPELL_JASPER_CHAINS;
                        crystalToSummon             = NPC_LIVING_JASPER_CRYSTAL;
                        break;
                    case NPC_JADE:
                        spellOverloadId             = SPELL_JADE_OVERLOAD;
                        spellPetrificationId        = SPELL_JADE_PETRIFICATION;
                        spellPetrificationBarId     = SPELL_JADE_PETRIFICATION_BAR;
                        spellTrueFormId             = SEPLL_JADE_TRUE_FORM;
                        spellMainAttack             = SPELL_JADE_SHARDS;
                        crystalToSummon             = NPC_LIVING_JADE_CRYSTAL;
                        break;
                    case NPC_AMETHYST:
                        spellOverloadId             = SPELL_AMETHYST_OVERLOAD;
                        spellPetrificationId        = SPELL_AMETHYST_PETRIFICATION;
                        spellPetrificationBarId     = SPELL_AMETHYST_PETRIFICATION_BAR;
                        spellTrueFormId             = SPELL_AMETHYST_TRUE_FORM;
                        spellMainAttack             = 0;// Bugged atm SPELL_AMETHYST_POOL;
                        crystalToSummon             = NPC_LIVING_AMETHYST_CRYSTAL;
                        break;
                    case NPC_COBALT:
                        spellOverloadId             = SPELL_COBALT_OVERLOAD;
                        spellPetrificationId        = SPELL_COBALT_PETRIFICATION;
                        spellPetrificationBarId     = SPELL_COBALT_PETRIFICATION_BAR;
                        spellTrueFormId             = SEPLL_COBALT_TRUE_FORM;
                        spellMainAttack             = SPELL_COBALT_MINE;
                        crystalToSummon             = NPC_LIVING_COBALT_CRYSTAL;
                        break;
                    default:
                        spellOverloadId             = 0;
                        spellPetrificationId        = 0;
                        spellPetrificationBarId     = 0;
                        spellTrueFormId             = 0;
                        spellMainAttack             = 0;
                        crystalToSummon             = 0;
                        break;
                }

                if (crystalGUID)
                    if (Creature* crystal = instance->instance->GetCreature(instance->GetObjectGuid(crystalGUID)))
                        crystal->DespawnOrUnsummon();

                crystalGUID = 0;

                if (instance)
                    instance->DoRemoveAurasDueToSpellOnPlayers(spellPetrificationBarId);

                events.Reset();
                events.ScheduleEvent(EVENT_REGEN,                   1000);
                events.ScheduleEvent(EVENT_CHECK_NEAR_GUARDIANS,    2500);
                events.ScheduleEvent(EVENT_CHECK_ENERGY,            1000);
                events.ScheduleEvent(EVENT_REND_FLESH,              5000);
                events.ScheduleEvent(EVENT_MAIN_ATTACK,             10000);
                events.ScheduleEvent(EVENT_ENRAGE,                  480000);
            }

            void EnterCombat(Unit* attacker)
            {
                if (instance)
                    instance->SetBossState(DATA_STONE_GUARD, IN_PROGRESS);
                
                me->RemoveAurasDueToSpell(SPELL_SOLID_STONE);
                me->RemoveAurasDueToSpell(SPELL_ANIM_SIT);

                if (instance->instance->IsHeroic())
                    if (crystalToSummon)
                        if (Creature* crystal = me->SummonCreature(crystalToSummon, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                            crystalGUID = crystal->GetGUID().GetEntry();
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                if (instance)
                    if (instance->GetBossState(DATA_STONE_GUARD) != FAIL)
                        instance->SetBossState(DATA_STONE_GUARD, FAIL);
                me->RemoveAurasDueToSpell(SPELL_AMETHYST_PETRIFICATION);
                me->RemoveAurasDueToSpell(SPELL_JADE_PETRIFICATION);
                me->RemoveAurasDueToSpell(SPELL_COBALT_PETRIFICATION);
                me->RemoveAurasDueToSpell(SPELL_JASPER_PETRIFICATION);

                me->CastSpell(me, SPELL_SOLID_STONE, true);
                me->CastSpell(me, SPELL_ANIM_SIT,    true);
                me->CastSpell(me, SPELL_ZERO_ENERGY, true);

                for (uint32 entry: guardiansEntry)
                {
                    if (instance)
                    {
                        if (Creature* gardian = me->GetMap()->GetCreature(instance->GetObjectGuid(instance->GetData64(entry))))
                        {
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, gardian);
                            gardian->RemoveAurasDueToSpell(SPELL_AMETHYST_PETRIFICATION);
                            gardian->RemoveAurasDueToSpell(SPELL_JADE_PETRIFICATION);
                            gardian->RemoveAurasDueToSpell(SPELL_COBALT_PETRIFICATION);
                            gardian->RemoveAurasDueToSpell(SPELL_JASPER_PETRIFICATION);
                        }
                    }
                }

                if (instance)
                {
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JASPER_CHAINS);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOTALY_PETRIFIED);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_COBALT_PETRIFICATION_BAR);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JASPER_PETRIFICATION_BAR);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JADE_PETRIFICATION_BAR);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AMETHYST_PETRIFICATION_BAR);
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (Creature* controller = GetController())
                {
                    if (damage >= me->GetHealth() && me->IsAlive())
                    {
                        me->LowerPlayerDamageReq(me->GetMaxHealth()); // Allow player loots even if only the controller has damaged the guardian
                        controller->AI()->DoAction(ACTION_GUARDIAN_DIED);

                        for (uint32 entry: guardiansEntry)
                            if (Creature* gardian = controller->GetMap()->GetCreature(instance->GetObjectGuid(instance->GetData64(entry))))
                                if (gardian != me)
                                    attacker->Kill(gardian);

                        return;
                    }

                    for (uint32 entry: guardiansEntry)
                        if (Creature* gardian = controller->GetMap()->GetCreature(instance->GetObjectGuid(instance->GetData64(entry))))
                            if (gardian->GetGUID() != me->GetGUID() && damage < gardian->GetHealth())
                                gardian->ModifyHealth(-int32(damage));
                }
            }

            void JustDied(Unit* killer)
            {
                me->RemoveAllDynObjects();

                if (crystalGUID)
                    if (Creature* crystal = instance->instance->GetCreature(instance->GetObjectGuid(crystalGUID)))
                        crystal->DespawnOrUnsummon();

                if (Creature* controller = GetController())
                    controller->AI()->DoAction(ACTION_GUARDIAN_DIED);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ENTER_COMBAT:
                        if (!me->IsInCombat())
                            if (Player* victim = me->SelectNearestPlayer(100.0f))
                                AttackStart(victim);
                        break;
                    case ACTION_PETRIFICATION:
                    {
                        Talk(TALK_PETRIFICATION);
                        char buf[128];
                        const char *name = me->GetName().c_str();
                        sprintf(buf, "%s commence a petrifie tous les joueurs !", name);
                        //me->MonsterTextEmote(buf, 0, true);
                        me->CastSpell(me, spellPetrificationId, true);
                        instance->DoCastSpellOnPlayers(spellPetrificationBarId);
                        break;
                    }
                    case ACTION_FAIL:
                        EnterEvadeMode();
                        break;
                    default:
                        break;
                }
            }

            bool CheckNearGuardians()
            {
                for (uint32 entry: guardiansEntry)
                    if (entry != me->GetEntry())
                        if (Creature* gardian = GetClosestCreatureWithEntry(me, entry, 12.0f, true))
                            return true;

                return false;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                {
                    if (!me->isMoving() && !me->HasAura(SPELL_ANIM_SIT))
                        me->CastSpell(me, SPELL_ANIM_SIT, true);

                    return;
                }

                events.Update(diff);
                me->SetPower(POWER_MANA, actualEnergy);

                while (uint8 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_REGEN:
                        {
                            actualEnergy += isInTrueForm ? 2: 0;
                            actualEnergy = actualEnergy > 100 ? 100: actualEnergy;

                            me->SetPower(POWER_MANA, actualEnergy);
                            events.ScheduleEvent(EVENT_REGEN, 1000);
                            break;
                        }
                        case EVENT_CHECK_NEAR_GUARDIANS:
                        {
                            bool hasNearGardian = CheckNearGuardians();

                            if (!isInTrueForm && hasNearGardian)
                            {
                                me->RemoveAurasDueToSpell(SPELL_SOLID_STONE);
                                me->CastSpell(me, spellTrueFormId, true);
                                isInTrueForm = true;
                            }
                            else if (isInTrueForm && !hasNearGardian)
                            {
                                me->CastSpell(me, SPELL_SOLID_STONE, true);
                                me->RemoveAurasDueToSpell(spellTrueFormId);
                                isInTrueForm = false;
                            }

                            events.ScheduleEvent(EVENT_CHECK_NEAR_GUARDIANS, 2000);
                            break;
                        }
                        case EVENT_CHECK_ENERGY:
                        {
                            if (me->GetPower(POWER_MANA) >= me->GetMaxPower(POWER_MANA))
                            {
                               // me->MonsterTextEmote(sSpellMgr->GetSpellInfo(spellOverloadId)->SpellName, 0, true);
                                me->CastSpell(me, spellOverloadId, true);
                                me->RemoveAurasDueToSpell(spellPetrificationId);
                                actualEnergy = 0;
                                if (instance)
                                    instance->DoRemoveAurasDueToSpellOnPlayers(spellPetrificationBarId);
                            }
                            else if (me->GetPower(POWER_MANA) >= 85 && !warnedForOverload)
                            {
                                char buf[128];
                                const char *name = me->GetName().c_str();
                                sprintf(buf, "%s est proche de la surcharge !", name);
                                //me->MonsterTextEmote(buf, 0, true);
                                warnedForOverload = true;
                            }

                            events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                            break;
                        }
                        case EVENT_REND_FLESH:
                        {
                            if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(victim, SPELL_REND_FLESH, false);

                            events.ScheduleEvent(EVENT_REND_FLESH, urand(20000, 25000));
                            break;
                        }
                        case EVENT_MAIN_ATTACK:
                        {
                            if (isInTrueForm)
                            {
                                DoZoneInCombat(me, 100.0f);

                                switch (me->GetEntry())
                                {
                                    case NPC_JADE:
                                    {
                                        me->CastSpell(me, SPELL_JADE_SHARDS, false);
                                        events.ScheduleEvent(EVENT_MAIN_ATTACK, urand(9000, 12000));
                                        break;
                                    }
                                    case NPC_COBALT:
                                    case NPC_AMETHYST:
                                    {
                                        if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM))
                                            me->CastSpell(victim, spellMainAttack, false);

                                        events.ScheduleEvent(EVENT_MAIN_ATTACK, 8500);
                                        break;
                                    }
                                    case NPC_JASPER:
                                    {
                                        uint32 scheduleTime = urand(11000, 13000);
                                        for (uint8 i = 0; i < 2; ++i)
                                        {
                                            std::list<Player*> playerList;
                                            std::list<Player*> tempPlayerList;
                                            GetPlayerListInGrid(playerList, me, 100.0f);

                                            uint64 victimGuid = 0;
                                            if (me->GetVictim())
                                                victimGuid = me->GetVictim()->GetGUID().GetEntry();

                                            for (auto player: playerList)
                                                if (player->IsAlive() && !player->HasAura(SPELL_JASPER_CHAINS) && !player->HasAura(SPELL_TOTALY_PETRIFIED) && player->GetGUID().GetEntry() != victimGuid)
                                                    tempPlayerList.push_back(player);

                                            if (tempPlayerList.size() < 2)
                                            {
                                                scheduleTime = 10000;
                                                break;
                                            }

                                            Trinity::Containers::RandomResizeList(tempPlayerList, 2);
                                    
                                            Player* firstPlayer  = *tempPlayerList.begin();
                                            Player* SecondPlayer = *(++(tempPlayerList.begin()));

                                            if (!firstPlayer || !SecondPlayer)
                                                break;

                                           // if (Aura* aura = me->AddAura(SPELL_JASPER_CHAINS, firstPlayer))
                                                //aura->SetScriptGuid(0, SecondPlayer->GetGUID());

                                           // if (Aura* aura = me->AddAura(SPELL_JASPER_CHAINS, SecondPlayer))
                                                //aura->SetScriptGuid(0, firstPlayer->GetGUID());
                                        }

                                        events.ScheduleEvent(EVENT_MAIN_ATTACK, scheduleTime);
                                        break;
                                    }
                                }
                            }

                            break;
                        }
                        case EVENT_ENRAGE:
                            me->CastSpell(me, SPELL_BERSERK, true);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_generic_guardianAI(creature);
        }
};

class npc_stone_guard_crystal: public CreatureScript
{
public:
    npc_stone_guard_crystal() : CreatureScript("npc_stone_guard_crystal") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        uint32 livingSpell = 0;

        switch (creature->GetEntry())
        {
            case NPC_LIVING_AMETHYST_CRYSTAL:
                livingSpell = SPELL_LIVING_AMETHYST;
                break;
            case NPC_LIVING_COBALT_CRYSTAL:
                livingSpell = SPELL_LIVING_COBALT;
                break;
            case NPC_LIVING_JADE_CRYSTAL:
                livingSpell = SPELL_LIVING_JADE;
                break;
            case NPC_LIVING_JASPER_CRYSTAL:
                livingSpell = SPELL_LIVING_JASPER;
                break;
        }

        if (livingSpell)
            for (uint8 i = 0; i < 10; ++i)
                creature->AddAura(livingSpell, player);

        return true;
    }
};

enum eMineSpell
{
    SPELL_COBALT_MINE_VISUAL    = 129455,
    SPELL_COBALT_MINE_EXPLOSION = 116281
};

class mob_cobalt_mine : public CreatureScript
{
    public:
        mob_cobalt_mine() : CreatureScript("mob_cobalt_mine") {}

        struct mob_cobalt_mineAI : public ScriptedAI
        {
            mob_cobalt_mineAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 preparationTimer;
            bool isReady;
            bool isExploded;

            void Reset()
            {
                preparationTimer = 3000;
                isReady    = false;
                isExploded = false;
                me->AddAura(SPELL_COBALT_MINE_VISUAL, me);
            }

            void UpdateAI(uint32 diff)
            {
                if (pInstance)
                    if (pInstance->GetBossState(DATA_STONE_GUARD) != IN_PROGRESS)
                        me->DespawnOrUnsummon();

                if (preparationTimer)
                {
                    if (preparationTimer <= diff)
                    {
                        isReady = true;
                        preparationTimer = 0;
                    }
                    else
                        preparationTimer -= diff;
                }

                if (isReady && !isExploded)
                    if (me->SelectNearestPlayer(5.0f))
                    {
                        me->CastSpell(me, SPELL_COBALT_MINE_EXPLOSION, false);
                        me->DespawnOrUnsummon(700);
                        isExploded = true;
                    }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_cobalt_mineAI(creature);
        }
};

class mob_tile : public CreatureScript
{
    public:
        mob_tile() : CreatureScript("mob_tile") {}

        struct mob_tileAI : public ScriptedAI
        {
            mob_tileAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            bool isActivated;

            void Reset()
            {
                isActivated = false;
            }

            Creature* GetController()
            {
                if (pInstance) return me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_STONE_GUARD_CONTROLER))); else return NULL;
            }

            void DoAction(int32 action)
            {
                if (action != ACTION_REMOVE_ENERGIZED_TILE)
                    return;

                isActivated = false;
                me->RemoveAurasDueToSpell(SPELL_ENERGIZED_TILE_VISUAL);
                me->RemoveDynObject(SPELL_ENERGIZED_TILE_VISUAL);
            }

            void UpdateAI(uint32 diff)
            {
                if (isActivated)
                    return;

                if (!pInstance)
                    return;

                if (pInstance->GetBossState(DATA_STONE_GUARD) != IN_PROGRESS)
                    return;

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 0.5f);

                if (playerList.size() < 1)
                    return;

                Trinity::Containers::RandomResizeList(playerList, 1);

                for (auto player: playerList)
                {
                    uint32 spellToRemove = 0;
                    if (player->HasAura(SPELL_LIVING_JADE))
                        spellToRemove = SPELL_LIVING_JADE;
                    else if (player->HasAura(SPELL_LIVING_JASPER))
                        spellToRemove = SPELL_LIVING_JASPER;
                    else if (player->HasAura(SPELL_LIVING_AMETHYST))
                        spellToRemove = SPELL_LIVING_AMETHYST;
                    else if (player->HasAura(SPELL_LIVING_COBALT))
                        spellToRemove = SPELL_LIVING_COBALT;
                            
                    if (spellToRemove)
                    {
                        uint8 newStacks = player->GetAuraCount(spellToRemove) - 1;

                        if (newStacks)
                            player->SetAuraStack(spellToRemove, player, player->GetAuraCount(spellToRemove) - 1);
                        else
                            player->RemoveAurasDueToSpell(spellToRemove);

                        isActivated = true;
                        pInstance->DoCastSpellOnPlayers(SPELL_ENERGIZED_TILE_BUFF);
                        me->CastSpell(me, SPELL_ENERGIZED_TILE_VISUAL, true);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_tileAI(creature);
        }
};

// Petrification - 115852 / 116006 / 116036 / 116057
class spell_petrification : public SpellScriptLoader
{
    public:
        spell_petrification() : SpellScriptLoader("spell_petrification") { }

        class spell_petrification_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_petrification_AuraScript);

            void HandleTriggerSpell(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                Unit* caster = GetCaster();

                if (!caster)
                    return;

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, caster, 200.0f);

                for (auto target: playerList)
                {
                    if (target->HasAura(SPELL_TOTALY_PETRIFIED))
                        continue;

                    uint32 triggeredSpell = GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell;

                    if (!target->HasAura(triggeredSpell))
                        caster->AddAura(triggeredSpell, target);

                    if (Aura* triggeredAura = target->GetAura(triggeredSpell))
                    {
                        uint8 stackCount = triggeredAura->GetStackAmount();

                        uint8 newStackCount = (stackCount + 4 > 100) ? 100 : (stackCount + 4);
                        triggeredAura->SetStackAmount(newStackCount);
                        triggeredAura->RefreshDuration();
                        triggeredAura->RecalculateAmountOfEffects();

                        target->SetPower(POWER_ALTERNATE_POWER, newStackCount);

                        if (newStackCount >= 100)
                            caster->AddAura(SPELL_TOTALY_PETRIFIED, target);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_petrification_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_petrification_AuraScript();
        }
};

// Jasper Chains - 130395
class spell_jasper_chains : public SpellScriptLoader
{
    public:
        spell_jasper_chains() : SpellScriptLoader("spell_jasper_chains") { }

        class spell_jasper_chains_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jasper_chains_AuraScript);
            uint64 playerLinkedGuid;
            ObjectGuid playerLinked;

            bool Load()
            {
                playerLinkedGuid = 0;
                playerLinked = playerLinkedGuid;
                return true;
            }

            void SetGuid(uint32 type, uint64 guid)
            {
                playerLinkedGuid = guid;
                playerLinked = new ObjectGuid(playerLinkedGuid);
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                Unit* target = GetTarget();
                const SpellInfo* spell = GetSpellInfo();
                Player* linkedPlayer = ObjectAccessor::GetPlayer(*target, playerLinked);

                if (!caster || !target || !spell || !linkedPlayer || !linkedPlayer->IsAlive() || !linkedPlayer->HasAura(spell->Id))
                    if (Aura* myaura = GetAura())
                    {
                        myaura->Remove();
                        return;
                    }

                if (target->GetDistance(linkedPlayer) > spell->GetEffect(EFFECT_0)->BasePoints)
                {
                    if (Aura* aura = target->GetAura(spell->Id))
                    {
                        if (aura->GetStackAmount() >= 15)
                        {
                            aura->Remove();
                            return;
                        }
                    }
                    
                    caster->AddAura(spell->Id, target);
                    target->CastSpell(linkedPlayer, SPELL_JASPER_CHAINS_DAMAGE, true);
                }
                else
                    target->CastSpell(linkedPlayer, SPELL_JASPER_CHAINS_VISUAL, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_jasper_chains_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_jasper_chains_AuraScript();
        }
};

// Jasper Chains (damage) - 130404
class spell_jasper_chains_damage : public SpellScriptLoader
{
    public:
        spell_jasper_chains_damage() : SpellScriptLoader("spell_jasper_chains_damage") { }

        class spell_jasper_chains_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jasper_chains_damage_SpellScript);
            
            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    if (Aura* aura = target->GetAura(SPELL_JASPER_CHAINS))
                    {
                        uint8 stacks = aura->GetStackAmount();
                        float multiplicator = 1.0f;

                        if (stacks)
                            for (uint8 i = 0; i < stacks; ++i)
                                multiplicator *= 1.25f;

                        SetHitDamage(GetHitDamage() * multiplicator);
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_jasper_chains_damage_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_jasper_chains_damage_SpellScript();
        }
};

/*// 465 - Amethyst Pool
class sat_amethyst_pool : public SpellAreaTriggerScript
{
public:
    sat_amethyst_pool() : SpellAreaTriggerScript("sat_amethyst_pool") {}

    class sat_amethyst_pool_interface : public IAreaTriggerAura
    {
        bool CheckTriggering(WorldObject* triggering) override
        {
            Unit* unit = triggering->ToUnit();
            if (!unit)
                return false;

            return unit->IsAlive() && m_target->IsWithinDistInMap(unit, m_range) && !m_caster->IsFriendlyTo(unit);
        }

        void OnTriggeringApply(WorldObject* triggering) override
        {
            m_caster->AddAura(SPELL_AMETHYST_POOL_DAMAGE, triggering->ToUnit());
        }

        void OnTriggeringRemove(WorldObject* triggering) override
        {
            triggering->ToUnit()->RemoveAura(SPELL_AMETHYST_POOL_DAMAGE, m_caster->GetGUID());
        }
    };

    IAreaTrigger* GetInterface() const override
    {
        return new sat_amethyst_pool_interface();
    }
};*/

void AddSC_boss_stone_guard()
{
    new boss_stone_guard_controler();
    new boss_generic_guardian();
    new mob_cobalt_mine();
    new mob_tile();
    new npc_stone_guard_crystal();
    new spell_petrification();
    new spell_jasper_chains();
    new spell_jasper_chains_damage();
    //new sat_amethyst_pool());
}
