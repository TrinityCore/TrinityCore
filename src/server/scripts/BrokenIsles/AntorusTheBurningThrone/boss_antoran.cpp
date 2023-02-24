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

enum eSays
{
    //Admiral
    SAY_AGGRO = 0,
    //Trigger "Admiral in Capsule"
    SAY_FUSILLADE = 0,
    //Trigger "Engineer in Capsule"
    SAY_ENTROPIC_MINE = 0,
    //Trigger "General in Capsule"
    SAY_SUMMON_REINFORCEMENTS = 0,
    //Capsule
    SAY_LEAVE_CAPSULE = 0,
    SAY_WARN_PLAYER = 1,
    //Cruiser
    SAY_WARN_FUSILLADE = 0,
};

enum Spells
{
    SPELL_OUTRO_CONV = 249154,
    SPELL_HOLOGRAM_SPAWN_VISUAL = 253589,
    SPELL_POD_SPAWN_COSMETIC_FILTER = 245785,
    SPELL_POD_SPAWN_COSMETIC = 245777,
    SPELL_POD_RETREAT_COSMETIC = 245793, //Visual Back to Capsule
    SPELL_BOSS_VISUAL_SPAWN = 232302,
    SPELL_ZERO_ENERGY_REGEN = 72242,
    SPELL_ENERGY_FILL = 258032,
    SPELL_SHARED_HEALTH = 244103,
    SPELL_ASSUME_COMMAND = 245227,
    SPELL_HIDE_MODEL = 245212,
    SPELL_ENERGY_DRAIN = 258033,
    SPELL_DAILY_ESSENCE_ANTORAN = 305309,
    //Bosses
    SPELL_EXPLOIT_WEAKNESS = 244892,
    SPELL_SUMMON_SHADOW_AT = 256436,
    SPELL_SHOCK_GRENADE_FILTER = 244722, //Mythic
    SPELL_SHOCK_GRENADE = 244729,
    SPELL_SHOCK_GRENADE_MARK = 244737,
    SPELL_SHOCKED = 244748,
    //Engineer
    SPELL_ENTROPIC_MINE_FILTER = 245304,
    SPELL_ENTROPIC_MINE_MISSILE = 245159,
    SPELL_ENTROPIC_MINE_VIS_SPAWN = 257262,
    SPELL_ENTROPIC_MINE_VISUAL = 246601,
    SPELL_ENTROPIC_BLAST = 245121,
    SPELL_ENTROPIC_BLAST_DOT = 253290,
    //General
    SPELL_SUMMON_REINFORCEMENTS = 245546,
    SPELL_SPAWN_VISUAL = 254363,
    SPELL_PYROBLAST_FILTER = 246507,
    SPELL_PYROBLAST = 246505,
    SPELL_DEMONIC_CHARGE_FILTER = 253036,
    SPELL_DEMONIC_CHARGE = 253040,
    SPELL_BLADESTORM = 253038,
    //Capsule
    SPELL_ENTER_VEH_CAPSULE = 244141, //Ride veh
    SPELL_PSYCHIC_ASSAULT = 244172,
    SPELL_PSYCHIC_SCARRING = 244388, //Heroic - 3min
    SPELL_PSYCHIC_SCARRING_PERM = 253306, //Mythic - permanent
    SPELL_WITHERING_FIRE_MISSILE = 245033,
    SPELL_WITHERING_FIRE_VISUAL = 245085,
    SPELL_PLR_CHAOS_PULSE_MISSILE = 244419,
    SPELL_FELSHIELD_EMITTER = 255140,
    SPELL_FELSHIELD_EMITTER_SUM = 244902,
    SPELL_ACTIVATE_FELSHIELD = 244907,
    SPELL_FELSHIELD_AT = 244909,
    SPELL_DISRUPTOR_BEACON = 255147,
    SPELL_DISRUPTOR_BEACON_SUM = 245174,
    SPELL_DISRUPTION_FIELD = 254771,
    SPELL_EXTRACT_INTERLOPER = 254130, //Mythic
    SPELL_SUMMON_MYTHIC_BATS_PERIODIC = 254133,
    //Trigger generic in Capsule
    SPELL_CHAOS_PULSE_FILTER = 257976,
    SPELL_CHAOS_PULSE_MARK = 257977,
    SPELL_CHAOS_PULSE_MISSILE = 257973,
    //Admiral in Capsule
    SPELL_CRUISER_FUSILLADE = 244625,
    SPELL_CRUISER_FUSILLADE_MISSILE = 244626,
    SPELL_CRUISER_FUSILLADE_DMG = 244627,
    SPELL_ADMIRAL_FUSILLADE = 257257,
    SPELL_ZEROING_IN = 244696,
};

enum eEvents
{
    //Event Manager
    EVENT_CHAOS_PULSE = 1,
    EVENT_ENTROPIC_MINE = 2,
    EVENT_SUMMON_REINFORCEMENTS = 3,
    EVENT_CRUISER_FUSILLADE = 4,
    //Bosses
    EVENT_EXPLOIT_WEAKNESS = 1,
    EVENT_SHOCK_GRENADE = 2,
    EVENT_CHECK_VICTIM = 3
};

enum eActions
{
    ACTION_ENCOUNTERS_SUMMON = 1,
    ACTION_ENCOUNTERS_RESTART,
    ACTION_ENCOUNTERS_ENTER_COMBAT,
    ACTION_SWITCH_STAGE,
    ACTION_ACTIVATE_BOSS_EVENTS,
    ACTION_ACTIVATE_CAPSULE = 1,
    ACTION_DEACTIVATE_CAPSULE = 2
};

enum eMisc
{
    STAGE_ADMIRAL = 0,
    STAGE_ENGINEER = 1,
    STAGE_GENERAL = 2,
    INVISIBLE_MODEL = 27823,
    //SMSG_SET_AI_ANIM_KIT
    ANIM_OPEN_CAPSULE = 8810,
    ANIM_CLOSE_CAPSULE = 0
};

uint32 const commandEntry[9] =
{
    //Bosses
    NPC_ADMIRAL_SVIRAX,
    NPC_CHIEF_ENGINEER_ISHKAR,
    NPC_GENERAL_ERODUS,
    //Capsule
    NPC_ADMIRAL_POD,
    NPC_ENGINEER_POD,
    NPC_GENERAL_POD,
    //Trigger Boss in Capsule
    NPC_ADMIRAL_SVIRAX_IN_POD,
    NPC_ENGINEER_ISHKAR_IN_POD,
    NPC_GENERAL_ERODUS_IN_POD
};

Position const commandPos[9] =
{
    //Bosses
    {-2810.50f, 10880.8f, 139.57f, 4.09f}, //Admiral
    {-2809.74f, 10829.3f, 139.75f, 2.05f}, //Engineer
    {-2859.64f, 10864.8f, 139.74f, 5.93f}, //General
    //Capsule
    {-2797.72f, 10898.5f, 139.47f, 4.08f}, //Admiral capsule
    {-2798.11f, 10812.0f, 139.38f, 2.16f}, //Engineer capsule
    {-2880.24f, 10870.2f, 139.75f, 6.02f}, //General capsule
    //Trigger Bosses in Capsule
    {-2796.28f, 10901.6f, 155.90f, 4.10f}, //Trigger Admiral in capsule
    {-2796.91f, 10809.7f, 155.90f, 2.13f}, //Trigger Engineer in capsule
    {-2883.30f, 10870.7f, 155.90f, 6.06f}  //Trigger General in capsule
};

Position const fusilladePos[12] =
{
    {-2787.93f, 10830.80f, 139.62f},
    {-2819.56f, 10822.47f, 139.62f},
    {-2796.53f, 10862.35f, 139.62f},
    {-2839.66f, 10834.07f, 139.62f},
    {-2828.15f, 10854.02f, 139.62f},
    {-2816.64f, 10873.96f, 139.62f},
    {-2805.12f, 10893.90f, 139.62f},
    {-2859.77f, 10845.68f, 139.62f},
    {-2848.26f, 10865.63f, 139.62f},
    {-2836.74f, 10885.57f, 139.62f},
    {-2879.88f, 10857.29f, 139.62f},
    {-2868.36f, 10877.23f, 139.62f}
};

enum Miscs
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
};

//122637
struct boss_antoran_high_command : BossAI
{
    boss_antoran_high_command(Creature* creature) : BossAI(creature, DATA_ANTORAN) { }

    std::vector<ObjectGuid> commandVector;
    uint8 commandDiedCount = 0;
    uint8 phase = 0;
    uint32 checkBossPositionTimer = 0;

    void Reset() override 
    {
        BossAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(INVISIBLE_MODEL);
        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);
        DoAction(ACTION_ENCOUNTERS_SUMMON);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        damage = 0;
    }

    void JustDied(Unit* killer) override 
    {
        _JustDied();
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_ENCOUNTERS_SUMMON:
        {
            commandVector.clear();
            commandDiedCount = 0;
            phase = STAGE_ADMIRAL;
            for (uint8 i = 0; i < 9; ++i)
            {
                if (auto command = me->SummonCreature(commandEntry[i], commandPos[i]))
                {
                    commandVector.push_back(command->GetGUID());

                    //Engineer / General  / in Capsule
                    if (i == 1 || i == 2 || i >= 6)
                    {
                        command->SetReactState(REACT_PASSIVE);
                        //command->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        command->SetDisplayId(INVISIBLE_MODEL);
                    }
                    //All Bosses
                    if (i < 3)
                    {
                        command->CastSpell(command, SPELL_ZERO_ENERGY_REGEN, true);
                        command->SetPower(POWER_ENERGY, 0);
                    }

                    //Admiral Capsule
                    if (i == 3)
                        command->GetAI()->DoAction(ACTION_ACTIVATE_CAPSULE);
                }
            }
            if (auto summon = me->SummonCreature(NPC_HOLOGRAM_STALKER, me->GetPosition()))
            {
                summon->CastSpell(summon, SPELL_HOLOGRAM_SPAWN_VISUAL, true);
                summon->SetDisplayId(INVISIBLE_MODEL);
            }
            break;
        }
        case ACTION_ENCOUNTERS_RESTART:
        {
            if (instance->GetBossState(DATA_ANTORAN) != NOT_STARTED)
            {
                instance->SetBossState(DATA_ANTORAN, NOT_STARTED);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PSYCHIC_ASSAULT);

                if (IsHeroicRaid())
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PSYCHIC_SCARRING);
                else if (IsMythicRaid())
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PSYCHIC_SCARRING_PERM);

                if (auto admiral = Creature::GetCreature(*me, commandVector[0]))
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, admiral);

                events.Reset();
                summons.DespawnAll();
                checkBossPositionTimer = 0;
                AddDelayedEvent(5000, [=]() -> void { DoAction(ACTION_ENCOUNTERS_SUMMON); });
            }
            break;
        }
        case ACTION_ENCOUNTERS_ENTER_COMBAT:
        {
            if (auto admiral = Creature::GetCreature(*me, commandVector[0]))
            {
                //instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_START, admiral);
                admiral->CastSpell(admiral, SPELL_ENERGY_FILL, true);
                admiral->AI()->DoAction(ACTION_ACTIVATE_BOSS_EVENTS);
                admiral->AI()->Talk(SAY_AGGRO);
            }

            for (uint8 i = 0; i < 9; ++i)
            {
                if (i == 3)
                    break;

                if (auto command = Creature::GetCreature(*me, commandVector[i]))
                {
                    command->CastSpell(command, SPELL_SHARED_HEALTH, true);

                    if (command->IsAlive() && !command->IsInCombat())
                        command->AI()->DoZoneInCombat(command, 100.0f);
                }
            }
            summons.DespawnEntry(NPC_HOLOGRAM_STALKER);
            events.RescheduleEvent(EVENT_CHAOS_PULSE, urandms(6, 8));
            events.RescheduleEvent(EVENT_ENTROPIC_MINE, 15000);
            events.RescheduleEvent(EVENT_SUMMON_REINFORCEMENTS, 8000);
            checkBossPositionTimer = 2000;
            break;
        }
        case ACTION_SWITCH_STAGE:
        {
            checkBossPositionTimer = 5000;

            auto oldCommand = Creature::GetCreature(*me, commandVector[phase]);
            auto oldCapsule = Creature::GetCreature(*me, commandVector[phase + 3]);

            if (oldCommand && oldCapsule)
            {
                oldCommand->CastSpell(oldCapsule, SPELL_POD_RETREAT_COSMETIC, true);
                oldCommand->CastSpell(oldCommand, SPELL_ENERGY_DRAIN, true); //WTF?! misc == 1 - It's rage!
                oldCommand->SetPower(POWER_ENERGY, 0); //HACK
                //oldCommand->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                oldCommand->RemoveAllAuras();
                oldCommand->SetDisplayId(INVISIBLE_MODEL);
                oldCommand->NearTeleportTo(oldCommand->GetHomePosition());
                oldCapsule->GetAI()->DoAction(ACTION_DEACTIVATE_CAPSULE);

                ++phase;
                if (phase > STAGE_GENERAL)
                    phase = STAGE_ADMIRAL;
            }

            auto newCommand = Creature::GetCreature(*me, commandVector[phase]);
            auto newCapsule = Creature::GetCreature(*me, commandVector[phase + 3]);

            if (newCommand && newCapsule)
            {
                newCapsule->CastSpell(newCommand, SPELL_POD_SPAWN_COSMETIC, true);
                newCapsule->AI()->DoAction(ACTION_ACTIVATE_CAPSULE);
                newCapsule->AI()->Talk(SAY_LEAVE_CAPSULE);
                newCommand->GetAI()->DoAction(ACTION_ACTIVATE_BOSS_EVENTS);
                newCommand->CastSpell(newCommand, SPELL_ENERGY_FILL, true);
                newCommand->CastSpell(newCommand, SPELL_BOSS_VISUAL_SPAWN, true);
                newCommand->SetDisplayId(newCommand->GetNativeDisplayId());
                //newCommand->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                newCommand->SetReactState(REACT_AGGRESSIVE);

                if (phase != STAGE_GENERAL)
                    events.RescheduleEvent(EVENT_SUMMON_REINFORCEMENTS, 16000);
                else
                {
                    events.CancelEvent(EVENT_SUMMON_REINFORCEMENTS);
                    events.RescheduleEvent(EVENT_ENTROPIC_MINE, 15000);
                }

                if (phase == STAGE_ENGINEER)
                    events.CancelEvent(EVENT_ENTROPIC_MINE);

                if (phase != STAGE_ADMIRAL)
                    events.RescheduleEvent(EVENT_CRUISER_FUSILLADE, 16000);
                else
                    events.CancelEvent(EVENT_CRUISER_FUSILLADE);
            }
            break;
        }
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_ADMIRAL_SVIRAX:
        case NPC_CHIEF_ENGINEER_ISHKAR:
        case NPC_GENERAL_ERODUS:
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
            summon->SetDisplayId(summon->GetNativeDisplayId());
            //summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (++commandDiedCount == 3)
            {
                if (instance->GetBossState(DATA_ANTORAN) != DONE)
                {
                    instance->SetBossState(DATA_ANTORAN, DONE);

                    if (auto admiral = Creature::GetCreature(*me, commandVector[0]))
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, admiral);

                    instance->DoOnPlayers([](Player* player)
                    {
                        player->CastSpell(player, SPELL_DAILY_ESSENCE_ANTORAN, true);
                    });
                }

                summons.DespawnEntry(NPC_ADMIRAL_POD);
                summons.DespawnEntry(NPC_ENGINEER_POD);
                summons.DespawnEntry(NPC_GENERAL_POD);
                summons.DespawnEntry(NPC_FANATICAL_PYROMANCER);
                summons.DespawnEntry(NPC_FELBLADE_SHOCKTROOPER);
                summons.DespawnEntry(NPC_ENTROPIC_MINE);
                summons.DespawnEntry(NPC_SCREAMING_SHRIKE);
                me->DespawnOrUnsummon();
            }
            break;
        }
        }
    }

    void ChaosPulse()
    {
        auto podA = Creature::GetCreature(*me, commandVector[6]);
        auto podB = Creature::GetCreature(*me, commandVector[7]);
        auto podC = Creature::GetCreature(*me, commandVector[8]);
        if (!podA || !podB || !podC)
            return;

        switch (phase)
        {
        case STAGE_ADMIRAL:
            podB->CastSpell(podB, SPELL_CHAOS_PULSE_FILTER, true);
            podC->CastSpell(podC, SPELL_CHAOS_PULSE_FILTER, true);
            break;
        case STAGE_ENGINEER:
            podC->CastSpell(podB, SPELL_CHAOS_PULSE_FILTER, true);
            podA->CastSpell(podC, SPELL_CHAOS_PULSE_FILTER, true);
            break;
        case STAGE_GENERAL:
            podA->CastSpell(podB, SPELL_CHAOS_PULSE_FILTER, true);
            podB->CastSpell(podC, SPELL_CHAOS_PULSE_FILTER, true);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkBossPositionTimer)
        {
            if (checkBossPositionTimer <= diff)
            {
                checkBossPositionTimer = 2000;

                if (auto curBoss = Creature::GetCreature(*me, commandVector[phase]))
                {
                    if (!CheckBoundary(curBoss))
                    {
                        checkBossPositionTimer = 0;
                        DoAction(ACTION_ENCOUNTERS_RESTART);
                        return;
                    }
                }
            }
            else
                checkBossPositionTimer -= diff;
        }

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CHAOS_PULSE:
                ChaosPulse();
                events.RescheduleEvent(EVENT_CHAOS_PULSE, urandms(6, 8));
                break;
            case EVENT_ENTROPIC_MINE:
                if (auto engineer = Creature::GetCreature(*me, commandVector[STAGE_ENGINEER]))
                    engineer->CastSpell(engineer, SPELL_ENTROPIC_MINE_FILTER, true);
                if (auto engineerTrigger = Creature::GetCreature(*me, commandVector[7]))
                    engineerTrigger->AI()->ZoneTalk(SAY_ENTROPIC_MINE, nullptr);
                events.RescheduleEvent(EVENT_ENTROPIC_MINE, 10000);
                break;
            case EVENT_SUMMON_REINFORCEMENTS:
            {
                if (auto general = Creature::GetCreature(*me, commandVector[STAGE_GENERAL]))
                    general->CastSpell(general, SPELL_SUMMON_REINFORCEMENTS, true);
                if (auto curCommand = Creature::GetCreature(*me, commandVector[phase]))
                {
                    Position pos;
                    for (auto entry : { NPC_FANATICAL_PYROMANCER, NPC_FELBLADE_SHOCKTROOPER, NPC_FELBLADE_SHOCKTROOPER })
                    {
                        curCommand->GetRandomNearPosition(10.0f);
                        me->SummonCreature(entry, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    }
                }
                if (auto generalTrigger = Creature::GetCreature(*me, commandVector[8]))
                    generalTrigger->AI()->ZoneTalk(SAY_SUMMON_REINFORCEMENTS,nullptr);
                events.RescheduleEvent(EVENT_SUMMON_REINFORCEMENTS, 34000);
                break;
            }
            case EVENT_CRUISER_FUSILLADE:
            {
                if (auto cruiser = me->SummonCreature(NPC_LEGION_CRUISER, -2826.16f, 10859.2f, 247.39f, 0.4f, TEMPSUMMON_TIMED_DESPAWN, 15000))
                {
                    me->CastSpell(me, SPELL_SUMMON_SHADOW_AT, true);
                    cruiser->AI()->ZoneTalk(SAY_WARN_FUSILLADE, nullptr);
                }
                if (auto admiral = Creature::GetCreature(*me, commandVector[STAGE_ADMIRAL]))
                    admiral->CastSpell(admiral, SPELL_ADMIRAL_FUSILLADE);
                if (auto admiralTrigger = Creature::GetCreature(*me, commandVector[6]))
                    admiralTrigger->AI()->ZoneTalk(SAY_FUSILLADE, nullptr);
                events.RescheduleEvent(EVENT_CRUISER_FUSILLADE, 30000);
                break;
            }
            }
        }
    }
};

//122367
struct boss_antoran_high_command_generic : ScriptedAI
{
    boss_antoran_high_command_generic(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override { }

    void Reset() override 
    {
        ScriptedAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_ENCOUNTERS_ENTER_COMBAT);

        if (me->GetEntry() == NPC_ADMIRAL_SVIRAX)
            events.RescheduleEvent(EVENT_CHECK_VICTIM, 2000);
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        fThreat = victim->HasAura(SPELL_PSYCHIC_ASSAULT) ? 0.0f : (fThreat ? fThreat : fThreat + 1.0f);
    }

    void JustDied(Unit* killer) override {}

    void DoAction(int32 const actionId) override
    {
        switch (actionId)
        {
        case ACTION_ACTIVATE_BOSS_EVENTS:
            events.RescheduleEvent(EVENT_EXPLOIT_WEAKNESS, 8000);
            events.RescheduleEvent(EVENT_CHECK_VICTIM, 2000);
            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_SHOCK_GRENADE, 14000);
            break;
        }
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (!me->IsInCombat() || apply || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_ENERGY_FILL:
            events.Reset();
            me->AttackStop();
            me->CastSpell(me, SPELL_ASSUME_COMMAND);
            break;
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (!me->IsInCombat() || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (spellId == SPELL_SHOCK_GRENADE_MARK)
            target->CastSpell(target, SPELL_SHOCKED, true);
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_ASSUME_COMMAND:
            if (auto owner = me->GetOwner())
                owner->GetAI()->DoAction(ACTION_SWITCH_STAGE);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SHOCK_GRENADE_FILTER)
            me->CastSpell(target, SPELL_SHOCK_GRENADE, true);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_EXPLOIT_WEAKNESS:
            me->CastSpell(me->GetVictim(), SPELL_EXPLOIT_WEAKNESS);
            events.RescheduleEvent(EVENT_EXPLOIT_WEAKNESS, 8000);
            break;
        case EVENT_SHOCK_GRENADE:
            DoCast(SPELL_SHOCK_GRENADE_FILTER);
            events.RescheduleEvent(EVENT_SHOCK_GRENADE, 14000);
           break;
        case EVENT_CHECK_VICTIM:
            if (me->GetVictim() && me->GetVictim()->HasAura(SPELL_PSYCHIC_ASSAULT))
                //DoModifyThreatPercent(me->GetVictim(), -100);
            events.RescheduleEvent(EVENT_CHECK_VICTIM, 1500);
            break;
        }
    }
};

//122992
struct npc_command_entropic_mine : ScriptedAI
{
    npc_command_entropic_mine(Creature* creature) : ScriptedAI(creature) { }

private:
    std::list<Player*> playerList;
    uint32 findPlayerTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_ENTROPIC_MINE_VIS_SPAWN, true);
        DoCast(me, SPELL_ENTROPIC_MINE_VISUAL, true);
        findPlayerTimer = 2000;
    }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DISRUPTION_FIELD)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (findPlayerTimer)
        {
            if (findPlayerTimer <= diff)
            {
                findPlayerTimer = 200;
                me->GetPlayerListInGrid(playerList, 0.6f);

                if (!playerList.empty())
                {
                    findPlayerTimer = 0;
                    //me->SetAnimKitId(6142);
                    me->CastSpell(me, SPELL_ENTROPIC_BLAST, true);

                    if (auto owner = me->GetOwner())
                        me->CastSpell(me, SPELL_ENTROPIC_BLAST_DOT, true);

                    AddDelayedEvent(500, [this]() -> void { if (me) me->DespawnOrUnsummon(); });
                }
            }
            else
                findPlayerTimer -= diff;
        }
    }
};

//122890, 122718
struct npc_command_reinforcements : ScriptedAI
{
    npc_command_reinforcements(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

private:
    uint32 checkTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 100.0f);
        DoCast(me, SPELL_SPAWN_VISUAL, true);
        me->SetReactState(REACT_AGGRESSIVE);

        if (me->GetEntry() == NPC_FANATICAL_PYROMANCER)
            events.RescheduleEvent(EVENT_1, 4200);
        else
            events.RescheduleEvent(EVENT_2, 4500);

        checkTimer = 500;
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        fThreat = victim->HasAura(SPELL_PSYCHIC_ASSAULT) ? 0.0f : (fThreat ? fThreat : fThreat + 1.0f);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_PYROBLAST_FILTER)
            me->CastSpell(target, SPELL_PYROBLAST);

        if (spell->Id == SPELL_DEMONIC_CHARGE_FILTER)
            me->CastSpell(target, SPELL_DEMONIC_CHARGE, true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == EVENT_CHARGE)
            me->CastSpell(me, SPELL_BLADESTORM, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (checkTimer)
        {
            if (checkTimer <= diff)
            {
                if (me->GetVictim() && me->GetVictim()->HasAura(SPELL_PSYCHIC_ASSAULT))
                    //DoModifyThreatPercent(me->GetVictim(), -100);

                checkTimer = 1000;
            }
            else
                checkTimer -= diff;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(SPELL_PYROBLAST_FILTER);
                events.RescheduleEvent(EVENT_1, 9000);
                break;
            case EVENT_2:
                DoCast(SPELL_DEMONIC_CHARGE_FILTER);
                events.RescheduleEvent(EVENT_2, 18000);
                break;
            }
        }
    }
};

//122739
struct npc_command_legion_cruiser : ScriptedAI
{
    npc_command_legion_cruiser(Creature* creature) : ScriptedAI(creature) { }

private:
    uint32 zeroingTimer = 0;
    std::list<ObjectGuid> listGuid;

    void IsSummonedBy(Unit* summoner) override
    {
        zeroingTimer = 14000;
        me->CastSpell(me, SPELL_CRUISER_FUSILLADE);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_CRUISER_FUSILLADE)
        {
            for (uint8 i = 0; i < 12; ++i)
                me->CastSpell(fusilladePos[i], SPELL_CRUISER_FUSILLADE_MISSILE, true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (zeroingTimer)
        {
            if (zeroingTimer <= diff)
            {
                zeroingTimer = 0;

                if (auto owner = me->GetOwner())
                    owner->CastSpell(owner, SPELL_ZEROING_IN, true);
            }
            else
                zeroingTimer -= diff;
        }
    }
};

//122867
struct npc_command_felshield_emitter : ScriptedAI
{
    npc_command_felshield_emitter(Creature* creature) : ScriptedAI(creature) { }

private:
    bool isActive = false;
    uint32 checkTimer = 1000;
    uint32 despawnTimer = 0;

    void IsSummonedBy(Unit* summoner) override { }

    void Reset()
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);    
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (isActive)
            return;

        if (spell->Id == SPELL_ACTIVATE_FELSHIELD)
        {
            isActive = true;
            despawnTimer = 11000;
            me->CastSpell(me, SPELL_FELSHIELD_AT);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkTimer)
        {
            if (checkTimer <= diff)
            {
                checkTimer = 1000;

                if (instance->GetBossState(DATA_ANTORAN) != IN_PROGRESS)
                {
                    isActive = true;
                    checkTimer = 0;
                    me->DespawnOrUnsummon();
                    return;
                }
            }
            else
                checkTimer -= diff;
        }
        if (despawnTimer)
        {
            if (despawnTimer <= diff)
            {
                despawnTimer = 0;
                me->DespawnOrUnsummon();
            }
            else
                despawnTimer -= diff;
        }
    }
};

//122884
struct npc_command_disruptor_beacon : ScriptedAI
{
    npc_command_disruptor_beacon(Creature* creature) : ScriptedAI(creature) { }

private:
    uint32 fieldTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        fieldTimer = 3000;
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (fieldTimer)
        {
            if (fieldTimer <= diff)
            {
                fieldTimer = 3000;
                me->CastSpell(me, SPELL_DISRUPTION_FIELD);
            }
            else
                fieldTimer -= diff;
        }
    }
};

//128069
struct npc_command_screaming_shrike : ScriptedAI
{
    npc_command_screaming_shrike(Creature* creature) : ScriptedAI(creature) { }
private:
    uint32 checkTimer = 0;
    uint32 despawnTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 100.0f);
        checkTimer = 1000;
    }

    void Reset()
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->SetCanFly(true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            me->CastSpell(me, SPELL_EXTRACT_INTERLOPER, true);
            despawnTimer = 11000;
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (mode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (spellId == SPELL_EXTRACT_INTERLOPER)
        {
            me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkTimer)
        {
            if (checkTimer <= diff)
            {
                checkTimer = 1000;

                if (instance->GetBossState(DATA_ANTORAN) != IN_PROGRESS)
                {
                    checkTimer = 0;
                    me->DespawnOrUnsummon();
                }
            }
            else
                checkTimer -= diff;
        }

        if (despawnTimer)
        {
            if (despawnTimer <= diff)
            {
                despawnTimer = 0;
                me->DespawnOrUnsummon();
            }
            else
                despawnTimer -= diff;
        }
    }
};

//245027
class spell_command_withering_fire : public SpellScript
{
    PrepareSpellScript(spell_command_withering_fire);

    void HandleScript(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster() || !GetHitDest())
            return;

        std::list<Creature*> shipList;
        GetCreatureListWithEntryInGrid(shipList, GetCaster(), NPC_SCOUT_SHIP, 100.0f);
        auto shipA = shipList.front();
        auto shipB = shipList.back();
        uint32 delay = 0;

        Position pos[16];

        for (uint8 i = 0; i < 8; ++i)
        {
            GetCaster()->CastSpell(pos[i], SPELL_WITHERING_FIRE_MISSILE, true);
            GetCaster()->CastSpell(pos[i + 8], SPELL_WITHERING_FIRE_MISSILE, true);

            if (shipA && shipB)
            {
                shipA->CastSpell(pos[i], SPELL_WITHERING_FIRE_VISUAL, true);
                shipB->CastSpell(pos[i + 8], SPELL_WITHERING_FIRE_VISUAL, true);
            }
            delay += urand(50, 100);
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_command_withering_fire::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//244418
class spell_command_player_chaos_pulse : public SpellScript
{
    PrepareSpellScript(spell_command_player_chaos_pulse);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() && GetHitUnit())
        {
            uint32 delay = 0;

            for (uint8 i = 0; i < 3; ++i)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_PLR_CHAOS_PULSE_MISSILE, true);
                delay += 200;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_command_player_chaos_pulse::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//257976
class spell_command_chaos_pulse_filter : public SpellScript
{
    PrepareSpellScript(spell_command_chaos_pulse_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            if (object->ToPlayer()->HasAura(SPELL_CHAOS_PULSE_MARK) || object->ToPlayer()->HasAura(SPELL_PSYCHIC_ASSAULT))
                return true;

            return false;
        });

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() && GetHitUnit())
        {
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CHAOS_PULSE_MARK, true);

            uint32 delay = 0;

            for (uint8 i = 0; i < 9; ++i)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_CHAOS_PULSE_MISSILE, true);
                delay += urand(200, 400);
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_command_chaos_pulse_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_command_chaos_pulse_filter::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//245304
class spell_command_entropic_mine : public SpellScript
{
    PrepareSpellScript(spell_command_entropic_mine);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (GetCaster() && GetHitUnit())
        {
            std::list<Position> randPos;
            auto maxCount = GetSpellInfo()->GetEffect(effIndex);
            //GetHitUnit()->GenerateCollisionNonDuplicatePoints(randPos, maxCount, 3.0f, 18.0f, 5.0f);

            if (auto owner = GetCaster()->GetOwner())
            {
                for (auto pos : randPos)
                    GetCaster()->CastSpell(pos, SPELL_ENTROPIC_MINE_MISSILE, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_command_entropic_mine::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//255140, 255147
class spell_command_felshield_or_beacon : public SpellScript
{
    PrepareSpellScript(spell_command_felshield_or_beacon);

    void HandleScript(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster() || !GetHitDest())
            return;

        auto owner = GetCaster()->GetOwner();
        if (!owner)
            return;

        if (GetSpellInfo()->Id == SPELL_FELSHIELD_EMITTER)
            GetCaster()->CastSpell(GetCaster()->GetPosition(), SPELL_FELSHIELD_EMITTER_SUM, true);
        else if (GetSpellInfo()->Id == SPELL_DISRUPTOR_BEACON)
            GetCaster()->CastSpell(GetCaster()->GetPosition(), SPELL_DISRUPTOR_BEACON_SUM, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_command_felshield_or_beacon::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//244627
class spell_command_fusillade : public SpellScript
{
    PrepareSpellScript(spell_command_fusillade);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        auto caster = GetCaster()->ToCreature();
        if (!caster)
            return;
    }

    void RecalculateDamage(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster())
            return;

        if (auto instance = GetCaster()->GetInstanceScript())
            if (auto admiral = instance->instance->GetCreature(instance->GetGuidData(NPC_ADMIRAL_SVIRAX)))
            {
                if (AuraEffect const* aurEff = admiral->GetAuraEffect(SPELL_ZEROING_IN, EFFECT_0))
                {
                    int32 bonusPct = 100 + aurEff->GetAmount();
                    int32 damage = CalculatePct(GetHitDamage(), bonusPct);
                    SetHitDamage(damage);
                }
            }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_command_fusillade::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_command_fusillade::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//244172
class spell_command_psychic_assault : public AuraScript
{
    PrepareAuraScript(spell_command_psychic_assault);

    void OnTick(AuraEffect const* auraEffect)
    {
        auto unit = GetUnitOwner();
        if (!unit)
            return;

        if (unit->GetMap()->IsLFR() || unit->GetMap()->IsNormal())
            return;

        AddDelayedEvent(100, [unit]() -> void
        {
            if (unit)
            {
                if (AuraEffect const* aurEff = unit->GetAuraEffect(SPELL_PSYCHIC_ASSAULT, EFFECT_0))
                    aurEff->GetBase()->ModStackAmount(1);
            }
        });
    }

    void HandleTick(AuraEffect const* aurEff)
    {
        uint32 amount = 0;
        uint16 stack = aurEff->GetBase()->GetStackAmount();

        if (stack > 1)
            amount = aurEff->GetBaseAmount() + aurEff->GetBaseAmount() * 0.2f * stack;
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_command_psychic_assault::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_command_psychic_assault::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_antoran()
{
    RegisterCreatureAI(boss_antoran_high_command);
    RegisterCreatureAI(boss_antoran_high_command_generic);
    RegisterCreatureAI(npc_command_entropic_mine);
    RegisterCreatureAI(npc_command_reinforcements);
    RegisterCreatureAI(npc_command_legion_cruiser);
    RegisterCreatureAI(npc_command_felshield_emitter);
    RegisterCreatureAI(npc_command_disruptor_beacon);
    RegisterCreatureAI(npc_command_screaming_shrike);
    RegisterSpellScript(spell_command_withering_fire);
    RegisterSpellScript(spell_command_player_chaos_pulse);
    RegisterSpellScript(spell_command_chaos_pulse_filter);
    RegisterSpellScript(spell_command_entropic_mine);
    RegisterSpellScript(spell_command_felshield_or_beacon);
    RegisterSpellScript(spell_command_fusillade);
    RegisterAuraScript(spell_command_psychic_assault);
}
