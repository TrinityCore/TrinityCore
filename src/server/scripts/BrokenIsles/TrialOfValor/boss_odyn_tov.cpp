/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016-2019 MagicStorm
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

#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "trial_of_valor.h"

/*
TODO:
Figure Faction Template: 16 ????
IntroConversation = 227863, ?? what sound is this
TestForPlayers = 229168, // this is for??
LeapIntoBattle  = 227882, // X: 2399.73 Y: 528.816 Z: 748.997 Orientation: 0
*/
enum Spells
{
    SPELL_INTRO_CONVERSATION        = 227863,
    SPELL_TEST_FOR_PLAYERS          = 229168,
    SPELL_LEAP_INTO_BATTLE          = 227882, // X: 2399.73 Y: 528.816 Z: 748.997 ORIENTATION: 0

    SPELL_SPEAR_TRANSITION_HOLY     = 228734,
    SPELL_SPEAR_TRANSITION_THUNDER  = 228740,

    SPELL_DRAW_POWER                = 227503,
    SPELL_UNERRING_BLAST            = 227629,
    SPELL_UNERRING_BLASTMISSILE     = 230989,

    SPELL_RUNEBEARER_SPAWNVISUAL    = 230415,

    SPELL_RUNIC_SHIELD_GREEN        = 227594,
    SPELL_RUNIC_SHIELD_BLUE         = 227595,
    SPELL_RUNIC_SHIELD_YELLOW       = 227596,
    SPELL_RUNIC_SHIELD_ORANGE       = 227597,
    SPELL_RUNIC_SHIELD_PURPLE       = 227598,

    // Phase 2
    SPELL_ODYNS_TEST                = 227626,
    SPELL_SPEAR_OF_LIGHT            = 228870,
    SPELL_SHATTER                   = 231016,
    SPELL_GLOWING_FRAGMENT          = 227782,
    SPELL_GLOWING_FRAGMENT_ERUPT    = 227781,

    // Phase 3
    SPELL_CLEANSING_FLAME           = 227455,
    SPELL_CLEANSING_FLAME2          = 227456,
    SPELL_STORM_OF_JUSTICE          = 227807,
    SPELL_STORMFORGED_SPEAR         = 228914,
    SPELL_ARCING_STORM              = 229254,
    SPELL_ARCING_STORM_DMG          = 229255,
    SPELL_ARCING_STORM_AURA         = 229256,

    SPELL_TELEPORT                  = 231166,

    SPELL_ODYN_BLESSING             = 197996, // UPON CLEANSING A RUNE ODYN BLESSES THE PLAYER.  IN ADDITION, THE PLAYER IS RESTORED TO FULL HEALTH.

};

uint32 GameObjects[] =
{
    245699, //GO_FloorRuneGreen
    245696, //GO_FloorRuneBlue
    245695, //GO_FloorRuneYellow
    245697, //GO_FloorRuneOrange
    245698, //GO_FloorRunePurple
};

// Marks the player as a Valhar Runebearer's target
uint32 OdynBrandedAuras[] =
{
    227500, //BrandedGreen
    227499, //BrandedBlue
    227498, //BrandedYellow
    227491, //BrandedOrange
    227490, //BrandedPurple
};
enum OdynSounds
{
    Intro                   = 77575, // figure what is
    OnDrawPower             = 77583
};

Position valarjarRunebearerPos[] =
{
    { 2466.094f, 573.3021f, 749.0782f },
    { 2496.595f, 501.7517f, 749.0782f },
    { 2465.967f, 484.0451f, 749.0782f },
    { 2409.269f, 572.1702f, 749.0782f },
    { 2409.139f, 485.3073f, 749.0782f }
};

enum OdynEvents
{
    EventDrawPower          = 1,    // Draw Power happens every 65 seconds.
    EventShieldOfLight,   // every 35 seconds
    EventStartPhase2,
    EventSpearOfLight,
    EventShatter,
    EventGlowingFragments,
    EventStartPhase3,
    EventCleansingFlame,
    EventStormOfJustice,
    EventStormforgedSpear,
    EventPeriodicCheck,
};

enum odynSays
{
    SAY_COMBAT          = 0,
    SAY_DRAW_POWER      = 1,
    SAY_FEED_POWER      = 2,
    SAY_FEED_POWER2     = 3,
    SAY_PHASE3          = 4,
    SAY_STORM           = 5,
    SAY_DIED            = 6,
};

class AuraCheck
{
public:
    explicit AuraCheck(uint32 const auraId) : _auraId(auraId) { }

    bool operator()(WorldObject* obj) const
    {
        if (Unit* target = obj->ToUnit())
            return !target->HasAura(_auraId);

        return true;
    }

private:
    uint32 const _auraId;
};

class PlayerAliveCheck
{
public:
    explicit PlayerAliveCheck() { }

    bool operator()(WorldObject* obj) const
    {
        if (Unit* target = obj->ToUnit())
            return !(target->IsInWorld() && target->IsAlive());

        return true;
    }
};

class boss_odyn_tov : public CreatureScript
{
public:

    boss_odyn_tov() : CreatureScript("boss_odyn_tov") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (!CAST_AI(boss_odyn_tov::boss_odyn_tovAI, creature->AI())->endEncounter)
            return false;

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I will fight her in your name, Odyn!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        SendGossipMenuFor(player, 1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->CastSpell(player, SPELL_TELEPORT, true);
            return true;
        }
        return false;
    }

    struct boss_odyn_tovAI : public BossAI
    {
        boss_odyn_tovAI(Creature* creature) : BossAI(creature, DATA_ODYN)
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->SetCanFly(false);

            //me->setPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);

            if (instance)
                instance->SetBossState(DATA_ODYN, NOT_STARTED);
        }

        bool canStartAttack;
        bool drawPower;
        bool inPhase2;
        bool inPhase3;
        bool endEncounter;
        ObjectGuid lastTargetGUID;
        std::list<Creature*> spearOfLights;

        void Reset() override
        {
            _Reset();
            if (instance)
                instance->SetBossState(DATA_ODYN, FAIL);

            canStartAttack = false;
            drawPower = false;
            inPhase2 = false;
            inPhase3 = false;
            endEncounter = false;
            lastTargetGUID = ObjectGuid::Empty;

            me->SetReactState(REACT_DEFENSIVE);

            events.Reset();

            me->SetPower(POWER_ENERGY, 0);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            canStartAttack = true;

            me->setActive(true);
            DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
                instance->SetBossState(DATA_ODYN, DONE);
            }
            Talk(SAY_DIED);

            me->SummonGameObject(260526, 2428.83f, 528.594f, 748.995f, 0.0f, QuaternionData(), 300000000);
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void JustReachedHome() override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustReachedHome();
                instance->SetBossState(DATA_ODYN, FAIL);
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            if (!inPhase2)
                return;

            if (!target || !spell)
                return;

            if (target->GetTypeId() != TYPEID_PLAYER)
                return;

            if (spell->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
                return;

            if (lastTargetGUID == target->GetGUID())
                me->CastSpell(me, SPELL_ODYNS_TEST, true);
            else
                lastTargetGUID = target->GetGUID();
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            BossAI::EnterEvadeMode();

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            _DespawnAtEvade(0, nullptr);
        }

        void SetPlayersInCombat(bool evade)
        {
            uint8 players = 0;
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player *player = i->GetSource())
                    {
                        if (player->IsAlive() && player->GetDistance(me) <= 500.0f)
                        {
                            ++players;

                            player->SetInCombatWith(me->ToUnit());
                        }
                    }
                }
                if (players == 0 && evade == true)
                {
                    _EnterEvadeMode();

                    Creature* hymdall = me->FindNearestCreature(BOSS_HYMDALL, 1500.0f);
                    Creature* hyrja = me->FindNearestCreature(BOSS_HYRJA, 1500.0f);

                    if (!hymdall || !hyrja)
                        return;

                    hymdall->AI()->Reset();
                    hyrja->AI()->Reset();
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            Creature* hymdall = me->FindNearestCreature(BOSS_HYMDALL, 1500.0f);
            Creature* hyrja = me->FindNearestCreature(BOSS_HYRJA, 1500.0f);

            if (!hymdall || !hyrja)
                return;

            // Valarjar's Bond
            if (hymdall->GetDistance2d(hyrja->GetPositionX(), hyrja->GetPositionY()) < 35.0f)
            {
                if (!hymdall->HasAura(SPELL_VALARJARS_BOND))
                    me->CastSpell(hymdall, SPELL_VALARJARS_BOND, true);
                if (!hyrja->HasAura(SPELL_VALARJARS_BOND))
                    me->CastSpell(hyrja, SPELL_VALARJARS_BOND, true);
            }
            else
            {
                if (hymdall->HasAura(SPELL_VALARJARS_BOND))
                    hymdall->RemoveAurasDueToSpell(SPELL_VALARJARS_BOND);
                if (hyrja->HasAura(SPELL_VALARJARS_BOND))
                    hyrja->RemoveAurasDueToSpell(SPELL_VALARJARS_BOND);
            }

            if (hymdall->HealthBelowPct(26) && hyrja->HealthBelowPct(26) && !canStartAttack && !inPhase2)
            {
                //fase 2
                hyrja->AttackStop();
                hyrja->SetReactState(REACT_PASSIVE);
                hyrja->GetMotionMaster()->MoveJump(2403.665f, 582.083f, 772.89f, 0.0f, 15.0f, 15.0f);

                hymdall->AttackStop();
                hymdall->SetReactState(REACT_PASSIVE);
                hymdall->GetMotionMaster()->MoveJump(2402.68f, 477.41f, 772.893f, 0.0f, 25.0f, 5.0f);

                events.ScheduleEvent(EventStartPhase2, 3 * IN_MILLISECONDS);
                inPhase2 = true;
            }

            if (hyrja->IsInCombat() && hymdall->IsInCombat() && !drawPower && !inPhase3)
            {
                events.ScheduleEvent(OdynEvents::EventDrawPower, 35 * IN_MILLISECONDS);
                events.ScheduleEvent(OdynEvents::EventPeriodicCheck, 1 * IN_MILLISECONDS);
                drawPower = true;
            }

            if (me->HealthBelowPct(55) && inPhase2 && !inPhase3)
            {
                Talk(SAY_PHASE3);
                events.ScheduleEvent(OdynEvents::EventStartPhase3, 3 * IN_MILLISECONDS);
                inPhase3 = true;
            }

            if (me->HealthBelowPct(10) && inPhase2 && inPhase3 && !endEncounter)
            {
                JustDied(me);
                me->SetFaction(35);
                me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                endEncounter = true;
            }

            if (!UpdateVictim() && canStartAttack)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case OdynEvents::EventDrawPower:

                        me->GetPlayerListInGrid(playerList, 500.f);
                        playerList.remove_if(PlayerAliveCheck());

                        if (roll_chance_i(50))
                            Talk(SAY_FEED_POWER);
                        else
                            Talk(SAY_FEED_POWER2);

                        for (uint8 i = 0; i < 5; i++)
                        {
                            // Activate all Runes
                            if (GameObject* rune = me->FindNearestGameObject(GameObjects[i], 200.f))
                                rune->SetGoState(GOState::GO_STATE_ACTIVE);

                            // Sumon Valarjar RuneBearer
                            if (TempSummon* valarjarRunebearer = me->SummonCreature(NPC_VALARJAR_RUNEBEARER, valarjarRunebearerPos[i], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000))
                            {
                                valarjarRunebearer->CastSpell(valarjarRunebearer, SPELL_RUNEBEARER_SPAWNVISUAL, true);
                                // Shield on Valarjar Runebearer
                                valarjarRunebearer->CastSpell(valarjarRunebearer, SPELL_RUNIC_SHIELD_GREEN + i, true);

                                // Add Marker aura on random player
                                if (!playerList.empty())
                                    if (Player* randomPlayer = Trinity::Containers::SelectRandomContainerElement(playerList))
                                    {
                                        me->AddAura(OdynBrandedAuras[i], randomPlayer->ToUnit());

                                        if (valarjarRunebearer->HasAura(SPELL_RUNIC_SHIELD_GREEN + i) && randomPlayer->HasAura(OdynBrandedAuras[i]))
                                        {
                                            valarjarRunebearer->SetTarget(randomPlayer->GetGUID());
                                            valarjarRunebearer->Attack(randomPlayer, true);
                                        }

                                        playerList.remove(randomPlayer);
                                    }
                            }
                        }
                        Talk(SAY_DRAW_POWER);
                        // Energize spell
                        me->CastSpell(me, SPELL_DRAW_POWER);

                        Trinity::Containers::RandomShuffle(valarjarRunebearerPos);

                        events.ScheduleEvent(OdynEvents::EventDrawPower, 65 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventStartPhase2:
                        Talk(SAY_COMBAT);
                        me->SetFaction(14);
                        me->SetReactState(REACT_AGGRESSIVE);
                        //me->CastSpell(me, SPELL_LEAP_INTO_BATTLE)
                        me->GetMotionMaster()->MoveJump(2399.73f, 528.816f, 748.997f, 0.0f, 25.0f, 10.0f);
                        events.ScheduleEvent(OdynEvents::EventSpearOfLight, 5 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventSpearOfLight:
                        for (uint8 i = 0; i < 3; ++i)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                                me->CastSpell(target, SPELL_SPEAR_OF_LIGHT, true);

                        events.ScheduleEvent(OdynEvents::EventSpearOfLight, urand(12 * IN_MILLISECONDS, 15 * IN_MILLISECONDS));
                        events.ScheduleEvent(OdynEvents::EventShatter, 5 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventShatter:
                        me->GetCreatureListWithEntryInGrid(spearOfLights, 114467, 500.0f);

                        if (spearOfLights.empty())
                            break;

                        for (auto spearOfLight : spearOfLights)
                        {
                            me->CastSpell(spearOfLight, SPELL_SHATTER, true);

                            if (Creature* glowingFragment = me->SummonCreature(219, spearOfLight->GetPositionX(), spearOfLight->GetPositionY(), spearOfLight->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12500))
                            {
                                glowingFragment->SetReactState(REACT_PASSIVE);
                                glowingFragment->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                                glowingFragment->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                                glowingFragment->AddAura(SPELL_GLOWING_FRAGMENT, glowingFragment);
                                glowingFragment->SetWalk(true);
                                Position randmonPos = glowingFragment->GetRandomPoint(*glowingFragment, 125.0f);
                                glowingFragment->GetMotionMaster()->MovePoint(0, randmonPos);
                            }

                            spearOfLight->DespawnOrUnsummon(0);
                        }

                        spearOfLights.clear();
                        break;

                    case OdynEvents::EventStartPhase3:
                        events.CancelEvent(EventDrawPower);
                        events.CancelEvent(EventShieldOfLight);
                        events.CancelEvent(EventSpearOfLight);
                        events.CancelEvent(EventShatter);
                        events.CancelEvent(EventGlowingFragments);

                        me->CastSpell(me, SPELL_ARCING_STORM, true);

                        events.ScheduleEvent(OdynEvents::EventStormOfJustice, 15 * IN_MILLISECONDS);
                        events.ScheduleEvent(OdynEvents::EventCleansingFlame, 1 * IN_MILLISECONDS);
                        events.ScheduleEvent(OdynEvents::EventStormforgedSpear, 18 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventCleansingFlame:
                        switch (urand(0, 1))
                        {
                            case 0:
                                me->CastSpell(2428.83f, 528.594f, 748.995f, SPELL_CLEANSING_FLAME, true);
                                break;
                            case 1:
                                me->CastSpell(2428.83f, 528.594f, 748.995f, SPELL_CLEANSING_FLAME2, true);
                                break;
                        }
                        events.ScheduleEvent(OdynEvents::EventCleansingFlame, 45 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventStormOfJustice:
                        Talk(SAY_STORM);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            me->CastSpell(target, SPELL_STORM_OF_JUSTICE, true);

                        events.ScheduleEvent(OdynEvents::EventStormOfJustice, 12 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventStormforgedSpear:
                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_STORMFORGED_SPEAR, true);

                        events.ScheduleEvent(OdynEvents::EventStormOfJustice, 16 * IN_MILLISECONDS);
                        break;

                    case OdynEvents::EventPeriodicCheck:
                        SetPlayersInCombat(true);

                        events.ScheduleEvent(OdynEvents::EventPeriodicCheck, 1 * IN_MILLISECONDS);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
        protected:
            std::list<Player*> playerList;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfValorAI<boss_odyn_tovAI>(creature);
    }
};

// 227503 Draw Power
class spell_odyn_draw_power : public SpellScriptLoader
{
public:
    spell_odyn_draw_power() : SpellScriptLoader("spell_odyn_draw_power") { }

    class spell_odyn_draw_power_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_odyn_draw_power_AuraScript);

        bool flag = true;

        void OnPeriodic(AuraEffect const* aurEff)
        {
            GetCaster()->EnergizeBySpell(GetCaster(), GetId(), flag ? 3 : 4, POWER_ENERGY);
            flag = !flag;
        }

        void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            GetCaster()->CastSpell(GetCaster(), SPELL_UNERRING_BLAST);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_odyn_draw_power_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            AfterEffectRemove += AuraEffectRemoveFn(spell_odyn_draw_power_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_odyn_draw_power_AuraScript();
    }
};

// 227629 Unerring Blast
class spell_odyn_unerring_blast : public SpellScriptLoader
{
public:
    spell_odyn_unerring_blast() : SpellScriptLoader("spell_odyn_unerring_blast") { }

    class spell_odyn_unerring_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_odyn_unerring_blast_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return true;
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            std::list<Creature*> minions;

            if (Unit* caster = GetCaster())
            {
                caster->GetCreatureListWithEntryInGrid(minions, NPC_VALARJAR_RUNEBEARER, 500.0f);

                if (minions.empty())
                    return;

                for (auto minion : minions)
                {
                    if (minion->HasAura(SPELL_RUNIC_SHIELD_BLUE))
                        caster->CastSpell(caster, 227975, true);

                    if (minion->HasAura(SPELL_RUNIC_SHIELD_GREEN))
                        caster->CastSpell(caster, 227976, true);

                    if (minion->HasAura(SPELL_RUNIC_SHIELD_ORANGE))
                        caster->CastSpell(caster, 227973, true);

                    if (minion->HasAura(SPELL_RUNIC_SHIELD_PURPLE))
                        caster->CastSpell(caster, 227961, true);

                    if (minion->HasAura(SPELL_RUNIC_SHIELD_YELLOW))
                        caster->CastSpell(caster, 227974, true);
                }

                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, SPELL_UNERRING_BLASTMISSILE, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_odyn_unerring_blast_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_odyn_unerring_blast_SpellScript();
    }
};

// 114996 Valarjar Runebearer
class npc_valarjar_runebearer : public CreatureScript
{
public:
    npc_valarjar_runebearer() : CreatureScript("npc_valarjar_runebearer") {}

    enum Events
    {
        EVENT_CHECK_RUNE    = 1,
    };

    struct npc_valarjar_runebearerAI : public ScriptedAI
    {
        npc_valarjar_runebearerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 runicShieldId, runeId, brandedId;
        std::list<Player*> playerList;

        void Reset() override
        {
            runicShieldId = 0;
            runeId = 0;
            brandedId = 0;

            events.ScheduleEvent(EVENT_CHECK_RUNE, 1 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_RUNE:
                        for (uint8 i = 0; i < 5; i++)
                        {
                            if (me->HasAura(SPELL_RUNIC_SHIELD_GREEN + i))
                            {
                                runicShieldId = SPELL_RUNIC_SHIELD_GREEN + i;
                                runeId = GameObjects[i];
                                brandedId = OdynBrandedAuras[i];
                            }
                        }

                        if (GameObject* valarjarRune = me->FindNearestGameObject(runeId, 200.f))
                        {
                            if (me->GetDistance2d(valarjarRune->GetPositionX(), valarjarRune->GetPositionY()) <= 3.0f)
                                me->RemoveAurasDueToSpell(runicShieldId);
                            else
                                me->AddAura(runicShieldId, me);
                        }
                        events.ScheduleEvent(EVENT_CHECK_RUNE, 1 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_valarjar_runebearerAI(creature);
    }
};

// 12851
class areatrigger_cleansing_flame_tov : public AreaTriggerEntityScript
{
public:
    areatrigger_cleansing_flame_tov() : AreaTriggerEntityScript("areatrigger_cleansing_flame_tov") { }

    struct areatrigger_cleansing_flame_tovAI : AreaTriggerAI
    {
        areatrigger_cleansing_flame_tovAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;

                unit->CastSpell(unit, 227475, true);
            }
        }

        void OnUnitExit(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (unit->HasAura(227475))
                    unit->RemoveAurasDueToSpell(227475);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_cleansing_flame_tovAI(areatrigger);
    }
};

// 227782
class areatrigger_glowing_fragment_tov : public AreaTriggerEntityScript
{
public:
    areatrigger_glowing_fragment_tov() : AreaTriggerEntityScript("areatrigger_glowing_fragment_tov") { }

    struct areatrigger_glowing_fragment_tovAI : AreaTriggerAI
    {
        areatrigger_glowing_fragment_tovAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnInitialize()
        {
            //UPDATE `areatrigger_template` SET `Flags`= 4 WHERE `Id` IN(12897, 12879);
            //AreaTriggerTemplate const* attemplate = at->GetTemplate();
            //attemplate.Flags = 4;
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;

                caster->CastSpell(unit, SPELL_GLOWING_FRAGMENT_ERUPT, true);

                if (Creature* creature = caster->ToCreature())
                    creature->DespawnOrUnsummon();

                at->SetDuration(1000);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_glowing_fragment_tovAI(areatrigger);
    }
};

// 229254 - Arcing Storm
class spell_odyn_arcing_storm : public SpellScriptLoader
{
public:
    spell_odyn_arcing_storm() : SpellScriptLoader("spell_odyn_arcing_storm") { }

    class spell_odyn_arcing_storm_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_odyn_arcing_storm_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
            {
                bool isCasted = false;
                std::list<Player*> playerList;

                caster->GetPlayerListInGrid(playerList, 500.f);

                if (playerList.empty())
                {
                    playerList.remove_if(PlayerAliveCheck());
                    if (Player* player = Trinity::Containers::SelectRandomContainerElement(playerList))
                    {
                        if (player->GetTypeId() == TYPEID_PLAYER && !isCasted)
                        {
                            caster->CastSpell(player, SPELL_ARCING_STORM_DMG, true);
                            isCasted = true;
                        }
                    }
                }

                caster->CastSpell(caster, SPELL_ARCING_STORM_AURA, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_odyn_arcing_storm_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_odyn_arcing_storm_AuraScript();
    }
};

class areatrigger_raging_tempest_tov : public AreaTriggerEntityScript
{
public:
    areatrigger_raging_tempest_tov() : AreaTriggerEntityScript("areatrigger_raging_tempest_tov") { }

    struct areatrigger_raging_tempest_tovAI : AreaTriggerAI
    {
        areatrigger_raging_tempest_tovAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;

                unit->CastSpell(unit, 224867, true);
                unit->CastSpell(unit, 227811, true);
            }
        }

        void OnUnitExit(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (unit->HasAura(224867))
                    unit->RemoveAurasDueToSpell(224867);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_raging_tempest_tovAI(areatrigger);
    }
};

void AddSC_boss_odyn_tov()
{
    new boss_odyn_tov();
    new spell_odyn_draw_power();
    new spell_odyn_unerring_blast();
    new npc_valarjar_runebearer();
    new areatrigger_cleansing_flame_tov();
    new areatrigger_glowing_fragment_tov();
    new spell_odyn_arcing_storm();
    new areatrigger_raging_tempest_tov();
}
