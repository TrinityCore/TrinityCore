///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "AreaTriggerAI.h"
//#include "thenighthold.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerTemplate.h"
//
//enum Says
//{
//    SAY_AGGRO                       = 0,
//    SAY_FEAST_OF_BLOOD              = 1,
//    SAY_CARRION_PLAGUE              = 2,
//    SAY_CARRION_PLAGUE_HIT_PLAYER   = 3,
//    SAY_ECHOES_OF_THE_VOID          = 4,
//    SAY_CHANGE_PHASE                = 5,
//    SAY_SUMMON_GUARDS               = 6,
//    SAY_WIPE                        = 7,
//    SAY_KILL_PLAYER                 = 8,
//    SAY_DEATH                       = 9,
//};
//
//enum Spells
//{
//    SPELL_BERSERK                   = 62535,
//    SPELL_TICH_LIGHT                = 217507, //Visual
//
//    SPELL_VAMPIRIC_AURA_AT          = 206892,
//    SPELL_VAMPIRIC_HEAL             = 206894,
//    SPELL_CARRION_PLAGUE_FILTER     = 212997,
//    SPELL_CARRION_PLAGUE            = 206480,
//    SPELL_SEEKER_SWARM_FILTER       = 213238,
//    SPELL_SEEKER_SWARM_DMG          = 206474,
//    SPELL_FEAST_OF_BLOOD            = 208230,
//    SPELL_ECHOES_OF_THE_VOID        = 213531,
//    SPELL_ECHOES_OF_THE_VOID_DMG    = 213534,
//    SPELL_SUM_FEL_SPIRE             = 208369,
//    SPELL_ILLUSIONARY_NIGHT         = 206365,
//    SPELL_ILLUSIONARY_NIGHT_PHASE   = 206311,
//
//    SPELL_BRAND_OF_ARGUS            = 212794, //Heroic+
//    SPELL_BRAND_OF_ARGUS_EXPLOSION  = 212795,
//    SPELL_BRAND_OF_ARGUS_VISUAL     = 215413,
//    SPELL_FLAMES_OF_ARGUS_AT        = 216465, //Mythic
//
//    //Tainted Blood
//    SPELL_FEAST_OF_BLOOD_JUMP       = 216421,
//    SPELL_FEAST_OF_BLOOD_FIXATE     = 216423,
//
//    //Fel Spire
//    SPELL_SUM_GO_FEL_SPIRE          = 215668,
//    SPELL_FEL_SPIRE_KNOCK           = 216295,
//    SPELL_FEL_SPIRE_TICK_AT         = 215875,
//    SPELL_FEL_SPIRE_AT              = 213650,
//    SPELL_FEL_SPIRE_SHELTER         = 215879,
//    SPELL_FEL_SPIRE_VIS_DMG         = 215906,
//    SPELL_FEL_SPIRE_DESTROYED       = 215918,
//
//    //Carrion Nightmare
//    SPELL_CARRION_NIGHTMARE_VISUAL  = 215973,
//    SPELL_CARRION_NIGHTMARE_BEEM    = 215988,
//
//    //Phantasmal Bloodfang
//    SPELL_BAT_GHOST_VISUAL          = 215605,
//    SPELL_ESSENCE_OF_NIGHT_AT       = 206462,
//    SPELL_ESSENCE_OF_NIGHT          = 206466,
//
//    //Felsworn Spellguard
//    SPELL_MOD_SCALE                 = 202427,
//    SPELL_TELEPORT_OUT              = 142193,
//    SPELL_RAPID_PURSUIT             = 216028,
//    SPELL_VOLATILE_WOUND            = 216024,
//    SPELL_NETHER_ZONE_AT            = 216026,
//
//    //Sightless Watcher
//    SPELL_FEL_DISSOLVE_IN           = 211762, //Visual Spawn
//    SPELL_BURNING_SOUL              = 216040,
//    SPELL_BURNING_SOUL_DMG          = 216041,
//    SPELL_RING_OF_SHADOWS_AT        = 216723, //Heroic+
//    SPELL_RING_OF_SHADOWS_VISUAL    = 216727,
//};
//
//enum eEvents
//{
//    EVENT_CARRION_PLAGUE            = 1,
//    EVENT_SEEKER_SWARM              = 2,
//    EVENT_FEAST_OF_BLOOD            = 3,
//    EVENT_ECHOES_OF_THE_VOID        = 4,
//    EVENT_ILLUSIONARY_NIGHT_START   = 5,
//    EVENT_SUM_GUARDS                = 6,
//    EVENT_BRAND_OF_ARGUS            = 7,
//};
//
//enum eMisc
//{
//    //SMSG_SET_AI_ANIM_KIT
//    NIGHTMARE_ANIM_1                = 11056,
//};
//
//Position const centrPos = { 241.41f, 3399.45f, 171.80f };
//
//Position const nightmarePos[5] =
//{
//    {240.79f, 3430.17f, 171.8f, 5.09f},
//    {241.73f, 3354.39f, 171.8f, 1.45f},
//    {252.31f, 3430.54f, 171.8f, 4.58f},
//    {289.90f, 3398.10f, 171.8f, 3.05f},
//    {210.68f, 3390.30f, 171.8f, 6.28f}
//};
//
//Position const guardPos[3] =
//{
//    {289.26f, 3394.23f, 171.91f, 2.38f},
//    {246.59f, 3351.88f, 171.82f, 2.38f},
//    {265.80f, 3374.88f, 171.78f, 2.35f}
//};
//
//enum Misc
//{
//    EVENT_1 = 1,
//    EVENT_2,
//    EVENT_3,
//};
////103685
//struct boss_tichonrius : BossAI
//{
//    explicit boss_tichonrius(Creature* creature) : BossAI(creature, DATA_TICHONDRIUS){}
//
//    bool voidEvent = false;
//    uint8 phase = 0;
//    uint32 killCDTimer = 0;
//    uint32 argusDelay = 0;
//    uint32 IllusionaryStartTimer = 0;
//
//    void Reset() override
//    {
//        _Reset();
//        voidEvent = false;
//        phase = 0;
//        argusDelay = 0;
//        killCDTimer = 0;
//        IllusionaryStartTimer = 0;
//        me->SetReactState(REACT_DEFENSIVE);
//        if (!me->IsVisible())
//            me->SetVisible(true);
//        DoCast(me, SPELL_TICH_LIGHT, true);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        Talk(SAY_AGGRO);
//        _JustEngagedWith();
//        DoCast(me, SPELL_VAMPIRIC_AURA_AT, true);
//
//        if (IsHeroicPlusRaid())
//            me->CastSpell(me, SPELL_BERSERK, true);
//        else
//            me->CastSpell(me, SPELL_BERSERK, true);
//
//        DefaultEvents();
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (!me->IsVisible())
//            me->SetVisible(true);
//
//        //Talk(SAY_DEATH);
//        _JustDied();
//    }
//
//    void KilledUnit(Unit* who) override
//    {
//        if (who && who->IsPlayer() && !killCDTimer)
//        {
//            killCDTimer = 3000;
//            Talk(SAY_KILL_PLAYER);
//        }
//    }
//
//    void DefaultEvents()
//    {
//        uint8 delay = phase > 0 ? 3 : 0;
//
//        events.RescheduleEvent(EVENT_CARRION_PLAGUE, (5 - delay) * IN_MILLISECONDS);
//        events.RescheduleEvent(EVENT_SEEKER_SWARM, (25 - delay) * IN_MILLISECONDS);
//        events.RescheduleEvent(EVENT_FEAST_OF_BLOOD, (20 - delay) * IN_MILLISECONDS);
//        events.RescheduleEvent(EVENT_ECHOES_OF_THE_VOID, (55 - delay) * IN_MILLISECONDS);
//
//        if (IsHeroicPlusRaid())
//            events.RescheduleEvent(EVENT_BRAND_OF_ARGUS, (15 - delay) * IN_MILLISECONDS);
//
//        if (phase < 2)
//            IllusionaryStartTimer = 125 * IN_MILLISECONDS;
//
//        if (phase == 1 || phase == 2)
//            events.RescheduleEvent(EVENT_SUM_GUARDS, 24 * IN_MILLISECONDS);
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//            case SPELL_FEAST_OF_BLOOD:
//            {
//                Position pos;
//                float angle = 0.0f;
//                for (uint8 i = 0; i < 3; ++i)
//                {
//                    if (Creature* blood = me->SummonCreature(NPC_TAINTED_BLOOD, target->GetPosition()))
//                    {
//                        blood->GetNearPosition(5.0f, angle);
//                        blood->CastSpell(pos, SPELL_FEAST_OF_BLOOD_JUMP, true);
//                        blood->CastSpell(target, SPELL_FEAST_OF_BLOOD_FIXATE, true);
//                        angle += 2.0f;
//                    }
//                }
//                break;
//            }
//            case SPELL_SEEKER_SWARM_FILTER:
//            {
//                float angle = me->GetAngle(target);
//                //me->PlayOrphanSpellVisual(target->GetPosition(), {0.f, 0.f, angle}, me->GetPosition(), 56358, 1.0f, ObjectGuid::Empty, true);
//                me->CastSpell(target, SPELL_SEEKER_SWARM_DMG, true);
//                break;
//            }
//            case SPELL_CARRION_PLAGUE:
//                Talk(SAY_CARRION_PLAGUE_HIT_PLAYER);
//                break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_ILLUSIONARY_NIGHT:
//                DoCast(me, SPELL_ILLUSIONARY_NIGHT_PHASE, true);
//                me->SummonCreature(NPC_COMBAT_STALKER, centrPos, TEMPSUMMON_TIMED_DESPAWN, 30000);
//                me->SetVisible(false);
//                break;
//        }
//    }
//
//    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//    {
//        if (!apply && spellId == SPELL_ECHOES_OF_THE_VOID)
//        {
//            voidEvent = false;
//            me->SetReactState(REACT_DEFENSIVE);
//        }
//
//        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (spellId == SPELL_ILLUSIONARY_NIGHT)
//        {
//            summons.DespawnEntry(NPC_PHANTASMAL_BLOODFANG);
//            me->RemoveDynObject(SPELL_ESSENCE_OF_NIGHT_AT);
//            me->SetVisible(true);
//            me->SetReactState(REACT_AGGRESSIVE);
//            ++phase;
//            DefaultEvents();
//
//            std::list<Player*> threatList;
//            me->GetPlayerListInGrid(threatList, 150.0f);
//            for (auto const& ref : threatList)
//            {
//                if (auto aura = ref->GetAura(SPELL_ESSENCE_OF_NIGHT))
//                {
//                    aura->SetDuration(30 * IN_MILLISECONDS);
//                    aura->SetMaxDuration(30 * IN_MILLISECONDS);
//                }
//            }
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        if (killCDTimer)
//        {
//            if (killCDTimer <= diff)
//                killCDTimer = 0;
//            else
//                killCDTimer -= diff;
//        }
//
//        if (IllusionaryStartTimer)
//        {
//            if (IllusionaryStartTimer <= diff)
//            {
//                IllusionaryStartTimer = 0;
//                events.Reset();
//                events.RescheduleEvent(EVENT_ILLUSIONARY_NIGHT_START, 1000);
//            }
//            else
//                IllusionaryStartTimer -= diff;
//        }
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING) || voidEvent)
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_CARRION_PLAGUE:
//                    Talk(SAY_CARRION_PLAGUE);
//                    DoCast(SPELL_CARRION_PLAGUE_FILTER);
//                    events.RescheduleEvent(EVENT_CARRION_PLAGUE, 25000);
//                    break;
//                case EVENT_SEEKER_SWARM:
//                    DoCast(SPELL_SEEKER_SWARM_FILTER);
//                    events.RescheduleEvent(EVENT_SEEKER_SWARM, 25000);
//                    break;
//                case EVENT_FEAST_OF_BLOOD:
//                    Talk(SAY_FEAST_OF_BLOOD);
//                    me->CastSpell(me->GetVictim(), SPELL_FEAST_OF_BLOOD);
//                    events.RescheduleEvent(EVENT_FEAST_OF_BLOOD, 25000);
//                    break;
//                case EVENT_ECHOES_OF_THE_VOID:
//                {
//                    voidEvent = true;
//                    me->AttackStop();
//                    Talk(SAY_ECHOES_OF_THE_VOID);
//                    DoCast(SPELL_ECHOES_OF_THE_VOID);
//                    float angle = centrPos.GetAngle(me) - 0.785f;
//                    Position pos;
//                    for (uint8 i = 0; i < 4; ++i)
//                    {
//                        angle += 3.14f / 2;
//
//                        me->CastSpell(pos, SPELL_SUM_FEL_SPIRE, true);
//                    }
//                    events.RescheduleEvent(EVENT_ECHOES_OF_THE_VOID, 65000);
//                    break;
//                }
//                case EVENT_ILLUSIONARY_NIGHT_START:
//                    Talk(SAY_CHANGE_PHASE);
//                    me->AttackStop();
//                    DoCast(SPELL_ILLUSIONARY_NIGHT);
//                    break;
//                case EVENT_SUM_GUARDS:
//                    Talk(SAY_SUMMON_GUARDS);
//                    for (uint8 i = 0; i < 2; ++i)
//                        me->SummonCreature(NPC_FELSWORN_SPELLGUARD, guardPos[i]);
//                    if (phase == 2)
//                        me->SummonCreature(NPC_SIGHTLESS_WATCHER, guardPos[2]);
//                    events.RescheduleEvent(EVENT_SUM_GUARDS, 52000);
//                    break;
//                case EVENT_BRAND_OF_ARGUS:
//                    DoCast(SPELL_BRAND_OF_ARGUS);
//                    events.RescheduleEvent(EVENT_BRAND_OF_ARGUS, 25000 + argusDelay);
//                    argusDelay = argusDelay ? 0 : 10000;
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////108934
//struct npc_tichonrius_tainted_blood : ScriptedAI
//{
//    explicit npc_tichonrius_tainted_blood(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//    }
//
//    ObjectGuid targetGuid;
//    bool targetFound = false;
//    uint32 AttackTimer = 0;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoZoneInCombat(me, 80.0f);
//        AttackTimer = 2000;
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        if (spell->Id == SPELL_FEAST_OF_BLOOD_FIXATE)
//            targetGuid = target->GetGUID();
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (AttackTimer)
//        {
//            if (AttackTimer <= diff)
//            {
//                AttackTimer = 2000;
//
//                if (!me->GetVictim())
//                {
//                    targetFound = false;
//
//                    if (Unit* target = me->GetVictim())
//                    {
//                        if (target->IsAlive())
//                        {
//                            ResetThreat(me);
//                            AddThreat(target, 1000.0f);
//                            me->AI()->AttackStart(target);
//                            targetFound = true;
//                        }
//                    }
//                    if (!targetFound)
//                    {
//                        if (Unit* newTarget = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 100.0f, true))
//                            DoCast(newTarget, SPELL_FEAST_OF_BLOOD_FIXATE, true);
//                        else
//                        {
//                            AttackTimer = 1000;
//                            DoZoneInCombat(me, 80.0f);
//                        }
//                    }
//                }
//            }
//            else
//                AttackTimer -= diff;
//        }
//
//        if (!UpdateVictim())
//            return;
//
//        DoMeleeAttackIfReady();
//    }
//};
//
////108625
//struct npc_tichonrius_fel_spire : ScriptedAI
//{
//    explicit npc_tichonrius_fel_spire(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    bool despawn = false;
//    uint8 playerCount = 0;
//    uint16 _castTimer = 3000;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoCast(me, SPELL_SUM_GO_FEL_SPIRE, true);
//        DoCast(me, SPELL_FEL_SPIRE_KNOCK, true);
//        DoCast(me, SPELL_FEL_SPIRE_AT, true);
//        playerCount = me->GetMap()->GetPlayersCountExceptGMs() > 10 ? me->GetMap()->GetPlayersCountExceptGMs() : 10;
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (_castTimer)
//        {
//            if (_castTimer <= diff)
//            {
//                _castTimer = 500;
//
//                if (Unit* owner = me->GetOwner())
//                {
//                    if (owner->HasAura(SPELL_ECHOES_OF_THE_VOID))
//                    {
//                        for (uint8 i = 0; i < 3; ++i)
//                            owner->CastSpell(me, SPELL_FEL_SPIRE_VIS_DMG, true);
//                    }
//                    else
//                    {
//                        despawn = true;
//                    }
//                }
//                
//            }
//            else
//                _castTimer -= diff;
//        }
//    }
//};
//
////108739
//struct npc_tichonrius_carrion_nightmare : ScriptedAI
//{
//    explicit npc_tichonrius_carrion_nightmare(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoCast(me, SPELL_CARRION_NIGHTMARE_VISUAL, true);
//
//        events.RescheduleEvent(EVENT_1, 1000);
//        events.RescheduleEvent(EVENT_2, 5000);
//        events.RescheduleEvent(EVENT_3, 6000);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                {
//                    if (auto stalker = me->FindNearestCreature(NPC_COMBAT_STALKER, 90.0f, true))
//                        if (auto player = stalker->SelectNearestPlayer(90.0f))
//                        {
//                            me->SetFacingToObject(player);
//                            me->CastSpell(player, SPELL_CARRION_NIGHTMARE_BEEM, false);
//                        }
//                    break;
//                }
//                case EVENT_2:
//                    me->SendPlaySpellVisualKit(0, 66613, 0);
//                    break;
//                case EVENT_3:
//                    me->DespawnOrUnsummon();
//                    break;
//            }
//        }
//    }
//};
//
////104271
//struct npc_tichonrius_combat_stalker : ScriptedAI
//{
//    explicit npc_tichonrius_combat_stalker(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    uint8 stage = 0;
//    uint8 count = 0;
//    uint16 _summonNightmareTimer = 7000;
//    uint16 _summonBloodfangTimer = 1000;
//
//    void IsSummonedBy(Unit* summoner) override {}
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (_summonNightmareTimer)
//        {
//            if (_summonNightmareTimer <= diff)
//            {
//                _summonNightmareTimer = 8000;
//
//                if (auto owner = me->GetOwner())
//                    owner->SummonCreature(NPC_CARRION_NIGHTMARE, nightmarePos[urand(0,4)]);
//            }
//            else
//                _summonNightmareTimer -= diff;
//        }
//
//        if (_summonBloodfangTimer)
//        {
//            if (_summonBloodfangTimer <= diff)
//            {
//                if (auto owner = me->GetOwner())
//                {
//                    Position pos;
//                    ++stage;
//
//                    switch (stage)
//                    {
//                        case 1:
//                            count = 2;
//                            _summonBloodfangTimer = 6000;
//                            break;
//                        case 2:
//                            count = 3;
//                            _summonBloodfangTimer = 3000;
//                            break;
//                        case 3:
//                            count = 4;
//                            _summonBloodfangTimer = 2000;
//                            break;
//                        case 4:
//                            count = 2;
//                            _summonBloodfangTimer = 2000;
//                            break;
//                        case 5:
//                            stage = 3; //Cycle
//                            count = 2;
//                            _summonBloodfangTimer = 1000;
//                            break;
//                    }
//
//                    for (uint8 i = 0; i < count; ++i)
//                    {
//                        me->GetRandomNearPosition(40.0f);
//                        owner->SummonCreature(NPC_PHANTASMAL_BLOODFANG, pos);
//                    }
//                }
//            }
//            else
//                _summonBloodfangTimer -= diff;
//        }
//    }
//};
//
////104326
//struct npc_tichonrius_phantasmal_bloodfang : ScriptedAI
//{
//    explicit npc_tichonrius_phantasmal_bloodfang(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        instance = me->GetInstanceScript();
//    }
//
//    InstanceScript* instance;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoCast(me, SPELL_BAT_GHOST_VISUAL, true);
//        DoZoneInCombat(me, 80.0f);
//        me->SetReactState(REACT_AGGRESSIVE);
//        //AddDelayedEvent(1000, [this]() -> void { me->SetReactState(REACT_AGGRESSIVE); });
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (Creature* tichondrius = instance->instance->GetCreature(instance->GetGuidData(DATA_TICHONDRIUS)))
//            tichondrius->CastSpell(me, SPELL_ESSENCE_OF_NIGHT_AT, true);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        DoMeleeAttackIfReady();
//    }
//};
//
////108591
//struct npc_tichonrius_felsworn_spellguard : ScriptedAI
//{
//    explicit npc_tichonrius_felsworn_spellguard(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//    }
//
//    EventMap events;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoCast(me, SPELL_MOD_SCALE, true);
//        DoCast(me, SPELL_TELEPORT_OUT, true); //Visual
//        DoZoneInCombat(me, 80.0f);
//        me->SetReactState(REACT_AGGRESSIVE);
//
//        events.RescheduleEvent(EVENT_1, 4000);
//        events.RescheduleEvent(EVENT_2, 4500);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    me->CastSpell(me->GetVictim(), SPELL_VOLATILE_WOUND, true);
//                    events.RescheduleEvent(EVENT_1, 4000);
//                    break;
//                case EVENT_2:
//                    DoCast(me, SPELL_RAPID_PURSUIT, true);
//                    events.RescheduleEvent(EVENT_2, 6000);
//                    break;
//            }
//            
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////108593
//struct npc_tichonrius_sightless_watcher : ScriptedAI
//{
//    explicit npc_tichonrius_sightless_watcher(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//    }
//
//    EventMap events;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoZoneInCombat(me, 80.0f);
//        DoCast(me, SPELL_FEL_DISSOLVE_IN, true);
//        me->SetReactState(REACT_AGGRESSIVE);
//
//        events.RescheduleEvent(EVENT_1, 9000);
//
//        if (IsHeroicPlusRaid())
//            events.RescheduleEvent(EVENT_2, 11000);
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        if (spell->Id == SPELL_RING_OF_SHADOWS_AT)
//            DoCast(me, SPELL_RING_OF_SHADOWS_VISUAL, true);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    DoCast(SPELL_BURNING_SOUL);
//                    events.RescheduleEvent(EVENT_1, 14000);
//                    break;
//                case EVENT_2:
//                    DoCast(SPELL_RING_OF_SHADOWS_AT);
//                    events.RescheduleEvent(EVENT_2, 24000);
//                    break;
//            }
//            
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////212997
//class spell_tichonrius_carrion_plague_filter : public SpellScript
//{
//    PrepareSpellScript(spell_tichonrius_carrion_plague_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        std::list<WorldObject*> tempList;
//        for (auto const& target : targets)
//        {
//            if (auto player = target->ToPlayer())
//                if (!(player->GetAuraCount(SPELL_CARRION_PLAGUE) > 1))
//                    tempList.push_back(target);
//        }
//
//        uint8 playerCount = 0;
//
//        if (targets.size() <= 15)
//            playerCount = 1;
//        else if (targets.size() <= 20)
//            playerCount = 2;
//        else if (targets.size() <= 30)
//            playerCount = 3;
//
//        targets = tempList;
//
//        if (targets.size() > playerCount)
//            Trinity::Containers::RandomResize(targets, playerCount);
//    }
//
//    void Register()
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tichonrius_carrion_plague_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////206474
//class spell_tichonrius_seeker_swarm : public SpellScript
//{
//    PrepareSpellScript(spell_tichonrius_seeker_swarm);
//
//    uint8 corruptedPlayersCount = 0;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        bool IsMythic = GetCaster()->GetMap()->IsMythic();
//
//        std::list<WorldObject*> tempTargets;
//        for (auto const& target : targets)
//        {
//            if (target->IsInBetween(GetCaster(), nullptr, IsMythic ? 5.0f : 3.0f))
//            {
//                tempTargets.push_back(target);
//
//                if (IsMythic && target->IsPlayer() && target->ToPlayer()->HasAura(SPELL_CARRION_PLAGUE))
//                    ++corruptedPlayersCount;
//            }
//        }
//
//        targets = tempTargets;
//
//        if (IsMythic)
//        {
//            if (targets.size() > 1)
//                targets.resize(1);
//        }
//    }
//
//    void HandleDummy(SpellEffIndex /*effectIndex*/)
//    {
//        if (GetCaster() && GetHitUnit())
//        {
//            if (GetCaster()->GetMap()->IsMythic())
//            {
//                if (GetHitUnit()->HasAura(SPELL_CARRION_PLAGUE))
//                    SetHitDamage(CalculatePct(GetHitDamage(), 1000));
//
//               // GetCaster()->CastSpellDuration(GetHitUnit(), SPELL_CARRION_PLAGUE, true, 0, corruptedPlayersCount + GetHitUnit()->GetAuraCount(SPELL_CARRION_PLAGUE));
//            }
//            else
//                GetCaster()->CastSpell(GetHitUnit(), SPELL_CARRION_PLAGUE, true);
//        }
//    }
//
//    void Register()
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tichonrius_seeker_swarm::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_THREAT_LIST);
//        OnEffectHitTarget += SpellEffectFn(spell_tichonrius_seeker_swarm::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////213740
//class spell_tichonrius_brand_of_argus_filter : public SpellScript
//{
//    PrepareSpellScript(spell_tichonrius_brand_of_argus_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster() || targets.size() < 4)
//            return;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            if (Creature* tichondrius = instance->instance->GetCreature(instance->GetGuidData(DATA_TICHONDRIUS)))
//            {
//                GetCaster()->RemoveAurasDueToSpell(SPELL_BRAND_OF_ARGUS);
//                tichondrius->CastSpell(GetCaster(), SPELL_BRAND_OF_ARGUS_EXPLOSION, true);
//
//                if (GetCaster()->GetMap()->IsMythic())
//                    tichondrius->CastSpell(GetCaster(), SPELL_FLAMES_OF_ARGUS_AT, true);
//            }
//    }
//
//    void Register()
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tichonrius_brand_of_argus_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//    }
//};
//
////212795
//class spell_tichonrius_brand_of_argus_dmg : public SpellScript
//{
//    PrepareSpellScript(spell_tichonrius_brand_of_argus_dmg);
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        auto distance = GetCaster()->GetExactDist2d(GetHitUnit()) * 2.0f;
//        auto pctModifier = 1u;
//        if (distance < 100.0f)
//            pctModifier = 100 - distance;
//
//        SetHitDamage(CalculatePct(GetHitDamage(), pctModifier));
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_tichonrius_brand_of_argus_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////212794
//class spell_tichonrius_brand_of_argus : public AuraScript
//{
//    PrepareAuraScript(spell_tichonrius_brand_of_argus);
//
//    void OnApply(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTarget())
//            GetTarget()->CastSpell(GetTarget(), SPELL_BRAND_OF_ARGUS_VISUAL, true);
//    }
//
//    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTarget())
//            GetTarget()->RemoveAurasDueToSpell(SPELL_BRAND_OF_ARGUS_VISUAL);
//    }
//
//    void Register() override
//    {
//        OnEffectApply += AuraEffectApplyFn(spell_tichonrius_brand_of_argus::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//        OnEffectRemove += AuraEffectRemoveFn(spell_tichonrius_brand_of_argus::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////213531
//class spell_tichonrius_echoes_void : public AuraScript
//{
//    PrepareAuraScript(spell_tichonrius_echoes_void);
//
//    void OnTick(AuraEffect const* /*aurEff*/)
//    {
//        if (Unit* caster = GetCaster())
//        {
//            std::list<Player*> threatList;
//            caster->GetPlayerListInGrid(threatList, 200.0f);
//            for (auto const& ref : threatList)
//            {
//                caster->CastSpell(ref, SPELL_ECHOES_OF_THE_VOID_DMG, true);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tichonrius_echoes_void::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////206893
//class spell_tichonrius_vampiric : public AuraScript
//{
//    PrepareAuraScript(spell_tichonrius_vampiric);
//
//    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
//    {
//        if (GetCaster() && GetTarget())
//        {
//            uint32 bonus = 0;
//            if (AuraEffect* eff = GetTarget()->GetAuraEffect(SPELL_FEAST_OF_BLOOD, EFFECT_1))
//                bonus += eff->GetAmount();
//
//            float damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount() + bonus);
//            //GetCaster()->CastCustomSpell(GetCaster(), SPELL_VAMPIRIC_HEAL, &damage, nullptr, nullptr, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectProc += AuraEffectProcFn(spell_tichonrius_vampiric::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
//    }
//};
//
////216024
//class spell_tichonrius_nether_zone : public AuraScript
//{
//    PrepareAuraScript(spell_tichonrius_nether_zone);
//
//    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (Unit* target = GetTarget())
//        {
//            if (InstanceScript* instance = target->GetInstanceScript())
//                if (Creature* tichondrius = instance->instance->GetCreature(instance->GetGuidData(DATA_TICHONDRIUS)))
//                    target->CastSpell(target, SPELL_NETHER_ZONE_AT, true, nullptr, nullptr, tichondrius->GetGUID());
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_tichonrius_nether_zone::OnRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////216040
//class spell_tichonrius_burning_soul : public AuraScript
//{
//    PrepareAuraScript(spell_tichonrius_burning_soul);
//
//    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
//            return;
//
//        if (Unit* target = GetTarget())
//        {
//            if (InstanceScript* instance = target->GetInstanceScript())
//                if (Creature* tichondrius = instance->instance->GetCreature(instance->GetGuidData(DATA_TICHONDRIUS)))
//                    target->CastSpell(target, SPELL_BURNING_SOUL_DMG, true, nullptr, nullptr, tichondrius->GetGUID());
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_tichonrius_burning_soul::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////206311
//class spell_tichonrius_illusionary_night : public AuraScript
//{
//    PrepareAuraScript(spell_tichonrius_illusionary_night);
//
//    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (GetTarget() && GetTarget()->IsPlayer() && GetTarget()->GetMap()->IsMythic() && !GetTarget()->HasAura(SPELL_ESSENCE_OF_NIGHT))
//            GetTarget()->CastSpell(GetTarget(), 27965, true);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_tichonrius_illusionary_night::OnRemove, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
//
//void AddSC_boss_tichondrius()
//{
//    RegisterCreatureAI(boss_tichonrius);
//    RegisterCreatureAI(npc_tichonrius_tainted_blood);
//    RegisterCreatureAI(npc_tichonrius_fel_spire);
//    RegisterCreatureAI(npc_tichonrius_carrion_nightmare);
//    RegisterCreatureAI(npc_tichonrius_combat_stalker);
//    RegisterCreatureAI(npc_tichonrius_phantasmal_bloodfang);
//    RegisterCreatureAI(npc_tichonrius_felsworn_spellguard);
//    RegisterCreatureAI(npc_tichonrius_sightless_watcher);
//    RegisterSpellScript(spell_tichonrius_carrion_plague_filter);
//    RegisterSpellScript(spell_tichonrius_seeker_swarm);
//    RegisterSpellScript(spell_tichonrius_brand_of_argus_filter);
//    RegisterSpellScript(spell_tichonrius_brand_of_argus_dmg);
//    RegisterAuraScript(spell_tichonrius_brand_of_argus);
//    RegisterAuraScript(spell_tichonrius_echoes_void);
//    RegisterAuraScript(spell_tichonrius_vampiric);
//    RegisterAuraScript(spell_tichonrius_nether_zone);
//    RegisterAuraScript(spell_tichonrius_burning_soul);
//    RegisterAuraScript(spell_tichonrius_illusionary_night);
//}
