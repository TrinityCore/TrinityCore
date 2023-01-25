#include "AreaTriggerAI.h"
#include "tomb_of_sargeras.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    //Engine of Souls
    SAY_ENGINE_AGGRO = 0,
    SAY_TORMENTED_CRIES = 0, //Trigger Talk
    SAY_WARN_SPEAR_OF_ANGUISH = 1,

    //The Desolate Host
    SAY_HOST_AGGRO = 0,
    SAY_HOST_DEATH = 1,

    //Soul Queen Dejahna
    SAY_QUEEN_AGGRO = 0,
    SAY_SOULBIND = 1,
    SAY_WARN_SOULBIND = 2,
    SAY_WARN_WAILING_SOULS = 3,
    SAY_WAILING_SOULS = 4,
    SAY_QUEEN_DEATH = 5,

    //Generic owner
    SAY_PHASE_2 = 0,
};

enum Spells
{
    SPELL_SPIRITUAL_FONT_REAL = 241576,
    SPELL_SPIRITUAL_FONT_SPIRIT = 241577,
    SPELL_SOUL_TRANSFER = 240851,
    SPELL_SPIRITUAL_BARRIER_VIS_REAL = 235113, //Only has trash and pets player in Real world
    SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT = 235620, //Only has trash and pets player in Spirit world
    SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM = 235732, //Spirit world - Phase 8308
    SPELL_SPIRITUAL_BARRIER_REAL_REALM = 235734, //Real world - Phase 8309
    SPELL_SPIRIT_REALM = 235621,
    SPELL_SWIRLING_SOULS_VISUAL = 241645,
    SPELL_SHARED_HEALTH = 236963,
    SPELL_CORPOREAL_REALM_REMOVE = 235590,
    SPELL_SPIRIT_PRESENCE_AT = 235589,
    SPELL_BERSERK = 47008,

    SPELL_QUIETUS = 236595,
    SPELL_QUIETUS_DMG = 236507,
    SPELL_QUIETUS_MOD = 236678,

    //Heroic+
    SPELL_DISSONANCE_REAL_FILTER = 239014,
    SPELL_DISSONANCE_SPIRIT_FILTER = 239015,
    SPELL_DISSONANCE_REAL = 239006,
    SPELL_DISSONANCE_SPIRIT = 239007,

    //Mythic
    SPELL_BOUND_ESSENCE_AURA = 236351,
    SPELL_BOUND_ESSENCE_MISSILE = 238580,

    //Engine of Souls
    SPELL_BONE_SHARDS = 236142,
    SPELL_COLLAPSING_FISSURE_FILTER = 235885,
    SPELL_COLLAPSING_FISSURE_MISSILE = 235889,
    SPELL_COLLAPSING_FISSURE_AT = 235890,
    SPELL_TORMENTED_CRIES_CHANNEL = 238570,
    SPELL_TORMENTED_CRIES_SUMMON = 236065,
    SPELL_TORMENTED_CRIES_MARK = 238018,
    SPELL_TORMENTED_CRIES_FILTER = 235988,
    SPELL_TORMENTED_CRIES_AT = 235989,
    SPELL_SPEAR_OF_ANGUISH_FILTER = 235923, //Heroic+
    SPELL_SPEAR_OF_ANGUISH_MARK = 235924,
    SPELL_SPEAR_OF_ANGUISH_HEAL_ABSORB = 238442,

    //Reanimated Templar
    SPELL_RUPTURING_SLAM_AT = 235927,
    SPELL_BONECAGE_ARMOR = 236513,

    //Ghastly Bonewarden
    SPELL_SHADOW_CHANNELLING = 173746,
    SPELL_GRASPING_DARKNESS = 235968,

    //Soul Queen Dejahna
    SPELL_CRUSH_MIND = 241566,
    SPELL_SOULBIND = 236449,
    SPELL_SOULBIND_DUMMY = 236459,
    SPELL_SOULBIND_FIND_PLAYER = 236465,
    SPELL_SOULBIND_DMG = 236464,
    SPELL_SOULBIND_VISUAL_FIND_SPIRIT = 245611, //Find player on the Spirit world
    SPELL_SOULBIND_VISUAL_FIND_REAL = 245612, //Find player on the Real world
    SPELL_WAILING_SOULS = 236072,
    SPELL_WITHER = 236131, //Heroic+
    SPELL_WITHER_2 = 236138,

    //Fallen Priestess
    SPELL_SOUL_REND = 229231,
    SPELL_SHATTERING_SCREAM = 235969,
    SPELL_SHATTERING_SCREAM_EXPLOSION = 236772,
    SPELL_SPIRIT_CHAINS = 236361,

    //Soul Residue
    SPELL_FIXATE = 238459,
    SPELL_SOUL_ROT_AT = 236235,
    SPELL_SOUL_ERUPTION = 236158,
    SPELL_SOUL_ERUPTION_TRANSFORM = 236160, //Change model
    SPELL_UNRELENTING = 221419,

    //The Desolate Host
    SPELL_SUNDERING_DOOM = 236542,
    SPELL_DOOMED_SUNDERING = 236544,
    SPELL_TORMENT = 236548,
};

enum eEvents
{
    //Engine of Souls
    EVENT_COLLAPSING_FISSURE = 1,
    EVENT_TORMENTED_CRIES = 2,
    EVENT_SPEAR_OF_ANGUISH = 3, //Heroic+

    //Soul Queen Dejahna
    EVENT_WAILING_SOULS = 1,
    EVENT_SOULBIND = 2,
    EVENT_WITHER = 3,
    EVENT_WITHER_2 = 4,

    //The Desolate Host
    EVENT_SUNDERING_DOOM = 1,
    EVENT_DOOMED_SUNDERING = 2,
};

enum eMisc
{
    //SMSG_PLAY_SPELL_VISUAL_KIT
    VISUAL_KIT_1 = 82907,
    VISUAL_KIT_2 = 64342,
};

uint32 const bossEntry[3] =
{
    NPC_ENGINE_OF_SOULS,
    NPC_SOUL_QUEEN_DEJAHNA,
    NPC_DESOLATE_HOST
};

Position const centrPos = { 6438.45f, -1089.73f, 2881.52f };

Position const BossPos[3] =
{
    {6456.64f, -1105.83f, 2881.60f, 2.50f}, //118460 - NPC_ENGINE_OF_SOULS
    {6461.07f, -1088.02f, 2881.60f, 2.73f}, //118462 - NPC_SOUL_QUEEN_DEJAHNA
    {6447.46f, -1099.68f, 2881.60f, 2.49f}  //119072 - NPC_DESOLATE_HOST
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
    EVENT_2,
};

//120988
struct boss_the_desolate_host_generic : BossAI
{
    explicit boss_the_desolate_host_generic(Creature* creature) : BossAI(creature, DATA_THE_DESOLATE_HOST), summons(me)
    {
        if (me->IsAlive())
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            AddDelayedEvent(500, [=]() -> void { DoAction(ACTION_1); });
        }
    }

    SummonList summons;
    std::vector<ObjectGuid> bossVector;
    bool phaseTwo = false;
    uint8 bossDiedCount = 0;
    uint32 summonEngineTimer = 0;
    uint32 summonDejahnaTimer = 0;
    uint32 berserkTimer = 0;

    void Reset() override
    {
        _Reset();
    }

    void JustDied(Unit* who) override
    {
        _JustDied();

        DoCast(240057);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_DESOLATE_HOST:
        case NPC_SOUL_QUEEN_DEJAHNA:
        case NPC_ENGINE_OF_SOULS:
            break;
        default:
            summons.Summon(summon);
            break;
        }
    }

    void DoAction(int32 const action) override
    {
        if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == DONE)
            return;

        switch (action)
        {
        case ACTION_1: //Summons
        {
            DoCast(me, SPELL_SPIRIT_PRESENCE_AT, true);
            bossVector.clear();
            bossDiedCount = 0;
            for (uint8 i = 0; i < 3; ++i)
            {
                if (auto summon = me->SummonCreature(bossEntry[i], BossPos[i]))
                    bossVector.push_back(summon->GetGUID());
            }
            //me->SummonCreatureGroup(CREATURE_SUMMON_GROUP_RESET);
            break;
        }
        case ACTION_2: //Despawn after evade 
        {
            if (instance->GetBossState(DATA_THE_DESOLATE_HOST) != NOT_STARTED)
            {
                instance->SetBossState(DATA_THE_DESOLATE_HOST, NOT_STARTED);

                if (auto host = Creature::GetCreature(*me, bossVector[2]))
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, host);

                RemoveDebuff();
                //me->SummonCreatureGroupDespawn(CREATURE_SUMMON_GROUP_RESET);
                me->RemoveAllAuras();
                me->RemoveAllAreaObjects();
                summons.DespawnAll();
                phaseTwo = false;
                summonEngineTimer = 0;
                summonDejahnaTimer = 0;
                berserkTimer = 0;

                for (auto const& guid : bossVector)
                {
                    if (auto boss = Creature::GetCreature(*me, guid))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, boss);
                        boss->AI()->DoAction(ACTION_2); //Despawn summons
                        boss->SetReactState(REACT_PASSIVE);
                        boss->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                        boss->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                        boss->DespawnOrUnsummon(200);
                    }
                }
                AddDelayedEvent(15000, [=]() -> void { DoAction(ACTION_1); });
            }
            break;
        }
        case ACTION_3: //Enter Combat
        {
            if (instance->GetBossState(DATA_THE_DESOLATE_HOST) != IN_PROGRESS)
            {
                instance->SetBossState(DATA_THE_DESOLATE_HOST, IN_PROGRESS);

                for (auto const& guid : bossVector)
                {
                    if (auto boss = Creature::GetCreature(*me, guid))
                    {
                        if (boss->GetEntry() == NPC_DESOLATE_HOST)
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD_COMBAT_RES_LIMIT, boss);
                        else
                            boss->AI()->DoZoneInCombat(boss, 100.0f);
                    }
                }

                summons.DoZoneInCombat();
                summonEngineTimer = 60000;
                summonDejahnaTimer = 120000;

                if (IsMythicRaid())
                    berserkTimer = 8 * MINUTE * IN_MILLISECONDS;
            }
            break;
        }
        case ACTION_4: //Phase 2
        {
            if (!phaseTwo)
            {
                phaseTwo = true;
                summonEngineTimer = 0;
                summonDejahnaTimer = 0;
                DoCast(me, SPELL_SWIRLING_SOULS_VISUAL, true);
                if (auto host = Creature::GetCreature(*me, bossVector[2]))
                    host->GetAI()->DoAction(ACTION_1);
                if (IsMythicRaid())
                    summons.DespawnEntry(NPC_SPIRITUAL_FONT);
                Talk(SAY_PHASE_2);
            }
            break;
        }
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        switch (summon->GetEntry())
        {
        case NPC_DESOLATE_HOST:
        case NPC_ENGINE_OF_SOULS:
        case NPC_SOUL_QUEEN_DEJAHNA:
        {
            if (++bossDiedCount == 3)
            {
                if (instance->GetBossState(DATA_THE_DESOLATE_HOST) != DONE)
                {
                    instance->SetBossState(DATA_THE_DESOLATE_HOST, DONE);

                    if (auto host = Creature::GetCreature(*me, bossVector[2]))
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, host);
                }
                RemoveDebuff();
                summons.DespawnAll();
                me->DespawnOrUnsummon();
            }
            break;
        }
        case NPC_REANIMATED_TEMPLAR:
        case NPC_GHASTLY_BONEWARDEN:
        case NPC_FALLEN_PRIESTESS:
        case NPC_SOUL_RESIDUE:
        {
            if (IsMythicRaid() && instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
            {
                summon->CastSpell(summon, SPELL_BOUND_ESSENCE_MISSILE, true);
            }
            break;
        }
        default:
            break;
        }
    }

    void RemoveDebuff()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOULBIND_DUMMY);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPIRIT_REALM);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPIRITUAL_BARRIER_REAL_REALM);
    }

    void UpdateAI(uint32 diff) override
    {
        if (summonEngineTimer)
        {
            if (summonEngineTimer <= diff)
            {
                summonEngineTimer = 60000; //1 minute

                Position pos;
                for (auto entry : { NPC_REANIMATED_TEMPLAR, NPC_GHASTLY_BONEWARDEN, NPC_GHASTLY_BONEWARDEN })
                {
                   // centrPos.SimplePosXYRelocationByAngle(pos, frand(15.0f, 25.0f), frand(0.0f, 6.28f));
                    me->SummonCreature(entry, pos);
                }
            }
            else
                summonEngineTimer -= diff;
        }

        if (summonDejahnaTimer)
        {
            if (summonDejahnaTimer <= diff)
            {
                summonDejahnaTimer = 60000; //1 minute

                Position pos;
                for (auto entry : { NPC_FALLEN_PRIESTESS, NPC_FALLEN_PRIESTESS, NPC_SOUL_RESIDUE, NPC_SOUL_RESIDUE, NPC_SOUL_RESIDUE, NPC_SOUL_RESIDUE })
                {
                    //centrPos.SimplePosXYRelocationByAngle(pos, frand(15.0f, 25.0f), frand(0.0f, 6.28f));
                    me->SummonCreature(entry, pos);
                }
            }
            else
                summonDejahnaTimer -= diff;
        }

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;

                for (auto const& guid : bossVector)
                {
                    if (auto boss = Creature::GetCreature(*me, guid))
                        boss->CastSpell(boss, SPELL_BERSERK, true);
                }
            }
            else
                berserkTimer -= diff;
        }
    }
};

//118460
struct npc_tos_engine_of_souls : ScriptedAI
{
    explicit npc_tos_engine_of_souls(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        SetCombatMovement(false);
    }

    InstanceScript* instance;
    EventMap events;
    bool phaseTwo = false;

    void Reset() override
    {
        events.Reset();
        DoCast(me, SPELL_SHARED_HEALTH, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_ENGINE_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        DoCast(me, SPELL_QUIETUS, true);

        events.RescheduleEvent(EVENT_COLLAPSING_FISSURE, 7000);
        events.RescheduleEvent(EVENT_TORMENTED_CRIES, 2 * MINUTE * IN_MILLISECONDS);

        if (IsHeroicPlusRaid())
            events.RescheduleEvent(EVENT_SPEAR_OF_ANGUISH, 20000);
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? 0.0f : (fThreat ? fThreat : fThreat + 1.0f);
    }

    void EnterEvadeMode(EvadeReason w)
    {
        //ScriptedAI::EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void JustDied(Unit* killer) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HealthBelowPct(31) && !phaseTwo)
        {
            phaseTwo = true;

            if (auto summoner = me->GetOwner())
                summoner->GetAI()->DoAction(ACTION_4); //Phase 2
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_SPEAR_OF_ANGUISH_FILTER:
            Talk(SAY_WARN_SPEAR_OF_ANGUISH, target);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_COLLAPSING_FISSURE:
                DoCast(SPELL_COLLAPSING_FISSURE_FILTER);
                events.RescheduleEvent(EVENT_COLLAPSING_FISSURE, 32000);
                break;
            case EVENT_TORMENTED_CRIES:
                DoCast(SPELL_TORMENTED_CRIES_CHANNEL);
                events.RescheduleEvent(EVENT_TORMENTED_CRIES, 2 * MINUTE * IN_MILLISECONDS);
                break;
            case EVENT_SPEAR_OF_ANGUISH:
                DoCast(SPELL_SPEAR_OF_ANGUISH_FILTER);
                events.RescheduleEvent(EVENT_SPEAR_OF_ANGUISH, 20000);
                break;
            }
        }
        DoSpellAttackIfReady(SPELL_BONE_SHARDS);
    }
};

//118462
struct npc_tos_soul_queen_dejahna : ScriptedAI
{
    explicit npc_tos_soul_queen_dejahna(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        SetCombatMovement(false);
    }

    InstanceScript* instance;
    EventMap events;
    std::list<ObjectGuid> soulsList;
    bool phaseTwo = false;

    void Reset() override
    {
        events.Reset();
        DoCast(me, SPELL_SHARED_HEALTH, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_QUEEN_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        DoCast(me, SPELL_QUIETUS, true);
        events.RescheduleEvent(EVENT_WAILING_SOULS, 1 * MINUTE * IN_MILLISECONDS);
        events.RescheduleEvent(EVENT_SOULBIND, 12000);

        if (IsHeroicPlusRaid())
            events.RescheduleEvent(EVENT_WITHER, 20000);
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? (fThreat ? fThreat : fThreat + 1.0f) : 0.0f;
    }

    void EnterEvadeMode(EvadeReason w)
    {
        //ScriptedAI::EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_QUEEN_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HealthBelowPct(31) && !phaseTwo)
        {
            phaseTwo = true;

            if (auto summoner = me->GetOwner())
                summoner->GetAI()->DoAction(ACTION_4); //Phase 2
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case 236454:
        case 236455:
        {
            soulsList.push_back(target->GetGUID());
            if (soulsList.size() > 1)
            {
                auto guidA = soulsList.front();
                auto guidB = soulsList.back();

                AddDelayedCombat(100, [this, guidA, guidB]() -> void
                {
                    if (me)
                    {
                        if (auto playerA = ObjectAccessor::GetPlayer(*me, guidA))
                        {
                            if (auto playerB = ObjectAccessor::GetPlayer(*me, guidB))
                            {
                                playerA->CastSpell(playerA, SPELL_SOULBIND_DUMMY, true, nullptr, nullptr, playerB->GetGUID());
                                playerB->CastSpell(playerB, SPELL_SOULBIND_DUMMY, true, nullptr, nullptr, playerA->GetGUID());
                            }
                        }
                    }
                });
            }
            break;
        }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_WAILING_SOULS:
                Talk(SAY_WARN_WAILING_SOULS);
                Talk(SAY_WAILING_SOULS);
                DoCast(SPELL_WAILING_SOULS);
                events.RescheduleEvent(EVENT_WAILING_SOULS, 2 * MINUTE * IN_MILLISECONDS);
                break;
            case EVENT_SOULBIND:
            {
                soulsList.clear();
                bool foundReal = false;
                bool foundSpirit = false;
                /*std::list<ThreatReference*> threatList = me->GetThreatManager().GetUnsortedThreatList();
                for (auto ref : threatList)
                {
                    if (auto player = ObjectAccessor::GetPlayer(*me, ref->getUnitGuid()))   ( fix later )
                    {
                        if (!player->HasAura(SPELL_SOULBIND_DUMMY))
                        {
                            if (player->HasAura(SPELL_SPIRIT_REALM))
                                foundSpirit = true;
                            else
                                foundReal = true;
                        }
                    }

                }
                if (foundReal && foundSpirit)
                {
                    Talk(SAY_SOULBIND);
                    Talk(SAY_WARN_SOULBIND);
                    DoCast(SPELL_SOULBIND);
                }
                events.RescheduleEvent(EVENT_SOULBIND, 24000);
                break;*/
            }
            case EVENT_WITHER:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 1, [this](Unit const* t) { return t->HasAura(SPELL_SPIRIT_REALM) && !t->HasAura(SPELL_SOULBIND_DUMMY); }))
                    DoCast(target, SPELL_WITHER);
                events.RescheduleEvent(EVENT_WITHER, 38000);
                events.RescheduleEvent(EVENT_WITHER_2, 10000);
                break;
            case EVENT_WITHER_2:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 1, [this](Unit const* t) { return t->HasAura(SPELL_SPIRIT_REALM) && !t->HasAura(SPELL_SOULBIND_DUMMY); }))
                    DoCast(target, SPELL_WITHER_2);
                break;
            }
        }
        DoSpellAttackIfReady(SPELL_CRUSH_MIND);
    }
};

//119072
struct npc_tos_desolate_host : ScriptedAI
{
    explicit npc_tos_desolate_host(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        me->SetVisible(false);
    }

    InstanceScript* instance;
    EventMap events;
    uint32 tormentTimer = 0;

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        events.RescheduleEvent(EVENT_SUNDERING_DOOM, 14000);
        events.RescheduleEvent(EVENT_DOOMED_SUNDERING, 24000);
    }

    void EnterEvadeMode(EvadeReason w) 
    {
       // ScriptedAI::EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_HOST_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }


    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
        {
            AddDelayedEvent(4000, [this]() -> void
            {
                if (me)
                {
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->SetVisible(true);
                    Talk(SAY_HOST_AGGRO);
                    DoCast(me, SPELL_SHARED_HEALTH, true);
                    me->SendPlaySpellVisualKit(0, VISUAL_KIT_1, 100);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat(me, 100.0f);
                    tormentTimer = 30000;
                }
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (tormentTimer)
        {
            if (tormentTimer <= diff)
            {
                tormentTimer = 20000;
                DoCast(me, SPELL_TORMENT, true);
            }
            else
                tormentTimer -= diff;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SUNDERING_DOOM:
                me->CastSpell(me, SPELL_SUNDERING_DOOM);
                events.RescheduleEvent(EVENT_SUNDERING_DOOM, 26000);
                break;
            case EVENT_DOOMED_SUNDERING:
                me->CastSpell(me, SPELL_DOOMED_SUNDERING);
                events.RescheduleEvent(EVENT_DOOMED_SUNDERING, 26000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//118701
struct npc_tos_spiritual_font : ScriptedAI
{
    explicit npc_tos_spiritual_font(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(11686);

        me->SetNpcFlags(UNIT_NPC_FLAG_SPELLCLICK);
        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
    }

    void Reset() override
    {
        DoCast(me, SPELL_SPIRITUAL_FONT_REAL, true);
        DoCast(me, SPELL_SPIRITUAL_FONT_SPIRIT, true);
    }

    void UpdateAI(uint32 diff) override {}
};

//118715, 119938
struct npc_tos_reanimated_templar : ScriptedAI
{
    explicit npc_tos_reanimated_templar(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        mirror = me->GetEntry() == NPC_REANIMATED_TEMPLAR_MIRROR;
    }

    InstanceScript* instance;
    EventMap events;
    bool armor = false;
    bool mirror = false;

    void IsSummonedBy(Unit* summoner) override
    {
        if (!mirror)
        {
            if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
                me->SendPlaySpellVisualKit(0, VISUAL_KIT_2, 100);
            else
                me->SetStandState(UNIT_STAND_STATE_KNEEL);

            if (IsMythicRaid())
                DoCast(me, SPELL_BOUND_ESSENCE_AURA, true);
        }

        if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
            DoZoneInCombat(me, 100.0f);
    }

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        events.RescheduleEvent(EVENT_1, 12000);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        if (!mirror)
            me->SetStandState(UNIT_STAND_STATE_STAND);
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        if (!mirror)
            fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? 0.0f : (fThreat ? fThreat : fThreat + 1.0f);
        else
            fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? (fThreat ? fThreat : fThreat + 1.0f) : 0.0f;
    }

    void EnterEvadeMode(EvadeReason w) 
    {
       // ScriptedAI::EnterEvadeMode();

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (IsHeroicPlusRaid() && me->HealthBelowPct(51) && !armor)
        {
            armor = true;
            DoCast(me, SPELL_BONECAGE_ARMOR, true);
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SHATTERING_SCREAM_EXPLOSION)
            me->RemoveAurasDueToSpell(SPELL_BONECAGE_ARMOR);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(SPELL_RUPTURING_SLAM_AT);
                events.RescheduleEvent(EVENT_1, 22000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//118728, 119939
struct npc_tos_ghastly_bonewarden : ScriptedAI
{
    explicit npc_tos_ghastly_bonewarden(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        mirror = me->GetEntry() == NPC_GHASTLY_BONEWARDEN_MIRROR;
    }

    InstanceScript* instance;
    EventMap events;
    bool armor = false;
    bool mirror = false;

    void IsSummonedBy(Unit* summoner) override
    {
        if (!mirror)
        {
            if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
                me->SendPlaySpellVisualKit(0, VISUAL_KIT_2, 100);
            else
                DoCast(me, SPELL_SHADOW_CHANNELLING, true);

            if (IsMythicRaid())
                DoCast(me, SPELL_BOUND_ESSENCE_AURA, true);
        }

        if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
            DoZoneInCombat(me, 100.0f);
    }

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        events.RescheduleEvent(EVENT_1, 4000);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        if (!mirror)
            me->InterruptNonMeleeSpells(false);
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        if (!mirror)
            fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? 0.0f : (fThreat ? fThreat : fThreat + 1.0f);
        else
            fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? (fThreat ? fThreat : fThreat + 1.0f) : 0.0f;
    }

    void EnterEvadeMode(EvadeReason w) 
    {
        //ScriptedAI::EnterEvadeMode();

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (IsHeroicPlusRaid() && me->HealthBelowPct(51) && !armor)
        {
            armor = true;
            DoCast(me, SPELL_BONECAGE_ARMOR, true);
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SHATTERING_SCREAM_EXPLOSION)
            me->RemoveAurasDueToSpell(SPELL_BONECAGE_ARMOR);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;


        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (!mirror)
                {
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return !t->HasAura(SPELL_SPIRIT_REALM); }))
                        DoCast(target, SPELL_GRASPING_DARKNESS);
                }
                else
                {
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return t->HasAura(SPELL_SPIRIT_REALM); }))
                        DoCast(target, SPELL_GRASPING_DARKNESS);
                }
                events.RescheduleEvent(EVENT_1, urand(4, 6) * IN_MILLISECONDS);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//118729, 119940
struct npc_tos_fallen_priestess : ScriptedAI
{
    explicit npc_tos_fallen_priestess(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        mirror = me->GetEntry() == NPC_FALLEN_PRIESTESS_MIRROR;
    }

    InstanceScript* instance;
    EventMap events;
    bool mirror = false;

    void IsSummonedBy(Unit* summoner) override
    {
        if (!mirror)
        {
            if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
                me->SendPlaySpellVisualKit(0, VISUAL_KIT_2, 100);
            else
                DoCast(me, SPELL_SOUL_REND, true);

            if (IsMythicRaid())
                DoCast(me, SPELL_BOUND_ESSENCE_AURA, true);
        }

        if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
            DoZoneInCombat(me, 100.0f);
    }

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        events.RescheduleEvent(EVENT_1, 4000);
        events.RescheduleEvent(EVENT_2, 14000);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        if (!mirror)
            me->InterruptNonMeleeSpells(false);
    }

    void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
    {
        if (!mirror)
            fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? (fThreat ? fThreat : fThreat + 1.0f) : 0.0f;
        else
            fThreat = victim->HasAura(SPELL_SPIRIT_REALM) ? 0.0f : (fThreat ? fThreat : fThreat + 1.0f);
    }

    void EnterEvadeMode(EvadeReason w)
    {
        //ScriptedAI::EnterEvadeMode();

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return (!mirror && t->HasAura(SPELL_SPIRIT_REALM)) || (mirror && !t->HasAura(SPELL_SPIRIT_REALM)); }))
                {
                    ResetThreatList();
                    AddThreat(target, 10000.0f);
                    DoCast(target, SPELL_SHATTERING_SCREAM);
                }
                events.RescheduleEvent(EVENT_1, urand(10, 15) * IN_MILLISECONDS);
                break;
            case EVENT_2:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return (!mirror && t->HasAura(SPELL_SPIRIT_REALM)) || (mirror && !t->HasAura(SPELL_SPIRIT_REALM)); }))
                {
                    ResetThreatList();
                    AddThreat(target, 10000.0f);
                    DoCast(target, SPELL_SPIRIT_CHAINS);
                }
                events.RescheduleEvent(EVENT_2, 14000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//118730
struct npc_tos_soul_residue : ScriptedAI
{
    explicit npc_tos_soul_residue(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        mirror = me->GetEntry() == NPC_SOUL_RESIDUE_MIRROR;
        me->SetReactState(REACT_PASSIVE);
        me->SetSpeed(MOVE_RUN, 0.5f);
    }

    InstanceScript* instance;
    bool died = false;
    bool mirror = false;
    uint32 rotTimer = 0;
    uint32 unrelentingTImer = 0;
    uint32 fixateTimer = 0;
    ObjectGuid targetGUID;

    void IsSummonedBy(Unit* summoner) override
    {
        if (!mirror)
        {
            if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
                me->SendPlaySpellVisualKit(0, VISUAL_KIT_2, 100);

            if (IsMythicRaid())
                DoCast(me, SPELL_BOUND_ESSENCE_AURA, true);
        }

        if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
            DoZoneInCombat(me, 100.0f);
    }

    void Reset() override {}

    void JustEngagedWith(Unit* who) override
    {
        rotTimer = 2000;
        fixateTimer = 1000;

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_3);

        if (IsMythicRaid())
            unrelentingTImer = 4000;
    }

    void EnterEvadeMode(EvadeReason w)
    {
        //ScriptedAI::EnterEvadeMode();

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;

            if (!died)
            {
                died = true;
                me->AttackStop();
                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_SOUL_ERUPTION, true);
                DoCast(me, SPELL_SOUL_ERUPTION_TRANSFORM, true);

                if (auto summoner = me->GetOwner())
                    if (summoner->IsCreature())
                        summoner->ToCreature()->AI()->SummonedCreatureDies(me, nullptr);

                AddDelayedEvent(5000, [=]() -> void { me->DespawnOrUnsummon(); });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;


        if (rotTimer)
        {
            if (rotTimer <= diff)
            {
                rotTimer = 2000;
                if (me->isMoving())
                    if (auto owner = me->GetOwner())
                        me->CastSpell(me, SPELL_SOUL_ROT_AT, true);
            }
            else
                rotTimer -= diff;
        }

        if (unrelentingTImer)
        {
            if (unrelentingTImer <= diff)
            {
                unrelentingTImer = 4000;
                DoCast(me, SPELL_UNRELENTING, true);
            }
            else
                unrelentingTImer -= diff;
        }

        if (fixateTimer)
        {
            if (fixateTimer <= diff)
            {
                fixateTimer = 2000;

                if (!targetGUID.IsEmpty())
                {
                    auto player = ObjectAccessor::GetPlayer(*me, targetGUID);
                    if (!player || !player->IsAlive() || (!mirror && !player->HasAura(SPELL_SPIRIT_REALM)) || (mirror && player->HasAura(SPELL_SPIRIT_REALM)))
                    {
                        targetGUID.Clear();
                        me->AttackStop();
                    }
                }

                if (targetGUID.IsEmpty())
                {
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return (!mirror && t->HasAura(SPELL_SPIRIT_REALM)) || (mirror && !t->HasAura(SPELL_SPIRIT_REALM)); }))
                    {
                        targetGUID = target->GetGUID();
                        DoCast(target, SPELL_FIXATE, true);
                        me->ClearUnitState(UNIT_STATE_CASTING);
                        AttackStart(target);
                    }
                }
            }
            else
                fixateTimer -= diff;
        }
        DoMeleeAttackIfReady();
    }
};

//118924
struct npc_tos_tormented_cries : ScriptedAI
{
    explicit npc_tos_tormented_cries(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        Talk(SAY_TORMENTED_CRIES);
        me->CastSpell(me, SPELL_TORMENTED_CRIES_FILTER, true);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_TORMENTED_CRIES_FILTER)
        {
            me->SetFacingToObject(target);
            DoCast(target, SPELL_TORMENTED_CRIES_MARK, true);
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (spellId == SPELL_TORMENTED_CRIES_MARK && target && mode == AURA_REMOVE_BY_EXPIRE)
        {
            me->SetFacingToObject(target);
            if (auto owner = me->GetOwner())
                me->CastSpell(target, SPELL_TORMENTED_CRIES_AT, false, nullptr, nullptr, owner->GetGUID());
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//236673
class spell_tos_quietus_filter : public SpellScript
{
    PrepareSpellScript(spell_tos_quietus_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempTargets;

        if (auto caster = GetCaster())
        {
            if (caster->GetEntry() == NPC_ENGINE_OF_SOULS)
            {
                for (auto const& target : targets)
                {
                    if (auto player = target->ToPlayer())
                        if (player->IsAlive() && !player->HasAura(SPELL_SPIRIT_REALM))
                            tempTargets.push_back(target);
                }
            }
            else if (caster->GetEntry() == NPC_SOUL_QUEEN_DEJAHNA)
            {
                for (auto const& target : targets)
                {
                    if (auto player = target->ToPlayer())
                        if (player->IsAlive() && player->HasAura(SPELL_SPIRIT_REALM))
                            tempTargets.push_back(target);
                }
            }

            if (tempTargets.empty())
            {
                caster->CastSpell(caster, SPELL_QUIETUS_DMG, true);
                caster->CastSpell(caster, SPELL_QUIETUS_MOD, true);
            }
        }
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_quietus_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//236465
class spell_tos_soulbind_finder : public SpellScript
{
    PrepareSpellScript(spell_tos_soulbind_finder);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();
        if (!caster || !target)
            return;

        if (auto aura = target->GetAura(SPELL_SOULBIND_DUMMY, caster->GetGUID()))
        {
            aura->Remove();
            caster->RemoveAurasDueToSpell(SPELL_SOULBIND_DUMMY);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_soulbind_finder::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//245611, 245612
class spell_tos_soulbind_visual_finder : public SpellScript
{
    PrepareSpellScript(spell_tos_soulbind_visual_finder);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (auto caster = GetCaster())
        {
            targets.remove_if([caster](WorldObject* object) -> bool
            {
                if (object->IsPlayer() && object->ToPlayer()->HasAura(SPELL_SOULBIND_DUMMY, caster->GetGUID()))
                    return false;

                return true;
            });
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_soulbind_visual_finder::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

//236563, 236564, 236567, 236568
class spell_tos_sundering_doom : public SpellScript
{
    PrepareSpellScript(spell_tos_sundering_doom);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        if (!targets.empty())
        {
            targetsCount = targets.size();
        }
        else
        {
            if (auto aura = GetCaster()->GetAura(SPELL_TORMENT))
                aura->ModStackAmount(5);
            else
                GetCaster()->CastSpell(GetCaster(), SPELL_TORMENT, true);
        }
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();
        if (!caster || !target)
            return;

        if (GetSpellInfo()->Id == 236563 || GetSpellInfo()->Id == 236567)
        {
            if (targetsCount)
                SetHitDamage(GetHitDamage() / targetsCount);
        }
        else if (GetSpellInfo()->Id == 236564 || GetSpellInfo()->Id == 236568)
        {
            auto distance = caster->GetExactDist2d(target) * 4.0f;
            if (distance > 90.0f)
                distance = 90.0f;
            auto pctModifier = 100.0f - distance;

            SetHitDamage(CalculatePct(GetHitDamage(), pctModifier));
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_sundering_doom::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_tos_sundering_doom::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//239014, 239015
class spell_tos_dissonance : public SpellScript
{
    PrepareSpellScript(spell_tos_dissonance);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        bool find = false;

        if (GetSpellInfo()->Id == SPELL_DISSONANCE_REAL_FILTER)
        {
            for (auto target : targets)
            {
                if (auto unit = target->ToUnit())
                    if (unit->HasAura(SPELL_SPIRIT_REALM))
                    {
                        find = true;
                        break;
                    }
            }
        }
        else if (GetSpellInfo()->Id == SPELL_DISSONANCE_SPIRIT_FILTER)
        {
            for (auto target : targets)
            {
                if (auto unit = target->ToUnit())
                    if (!unit->HasAura(SPELL_SPIRIT_REALM))
                    {
                        find = true;
                        break;
                    }
            }
        }

        if (find)
        {
            if (GetSpellInfo()->Id == SPELL_DISSONANCE_REAL_FILTER)
                GetCaster()->CastSpell(GetCaster(), SPELL_DISSONANCE_REAL, true); //Dmg spirit realm targets
            else if (GetSpellInfo()->Id == SPELL_DISSONANCE_SPIRIT_FILTER)
                GetCaster()->CastSpell(GetCaster(), SPELL_DISSONANCE_SPIRIT, true); //Dmg real realm targets
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_dissonance::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

//239006, 239007
class spell_tos_dissonance_filter : public SpellScript
{
    PrepareSpellScript(spell_tos_dissonance_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        std::list<WorldObject*> tempTargets;

        if (GetSpellInfo()->Id == SPELL_DISSONANCE_REAL)
        {
            for (auto target : targets)
            {
                if (auto player = target->ToPlayer())
                    if (player->HasAura(SPELL_SPIRIT_REALM))
                    {
                        tempTargets.push_back(target);
                    }
            }
        }
        else if (GetSpellInfo()->Id == SPELL_DISSONANCE_SPIRIT)
        {
            for (auto target : targets)
            {
                if (auto player = target->ToPlayer())
                    if (!player->HasAura(SPELL_SPIRIT_REALM))
                    {
                        tempTargets.push_back(target);
                    }
            }
        }
        targets = tempTargets;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_dissonance_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

//235933, 242796
class spell_tos_spear_of_anguish : public SpellScript
{
    PrepareSpellScript(spell_tos_spear_of_anguish);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!targetsCount)
            targetsCount = targets.size();

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr)
                return true;

            if (object->ToUnit()->IsImmunedToSpell(GetSpellInfo(), GetCaster()))
                return true;

            return false;
        });
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (GetSpellInfo()->Id == 242796 && targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_2);

        auto target = GetHitUnit();
        if (!target || target->IsImmunedToSpell(GetSpellInfo(), GetCaster()))
            return;

        target->CastSpell(target, SPELL_SOUL_TRANSFER, true);
        target->CastSpell(target, SPELL_SPIRIT_REALM, true);
        target->RemoveAurasDueToSpell(SPELL_SPIRITUAL_BARRIER_REAL_REALM);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_spear_of_anguish::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_spear_of_anguish::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_tos_spear_of_anguish::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_tos_spear_of_anguish::HandleDummy, EFFECT_2, SPELL_EFFECT_FORCE_CAST);
    }
};

//238585
class spell_tos_bound_essence : public SpellScript
{
    PrepareSpellScript(spell_tos_bound_essence);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (auto caster = GetCaster())
        {
            if (auto owner = caster->GetOwner())
            {
                WorldLocation* loc = GetHitDest();

                switch (caster->GetEntry())
                {
                case NPC_REANIMATED_TEMPLAR:
                    owner->SummonCreature(NPC_REANIMATED_TEMPLAR_MIRROR, loc->GetPosition());
                    break;
                case NPC_GHASTLY_BONEWARDEN:
                    owner->SummonCreature(NPC_GHASTLY_BONEWARDEN_MIRROR, loc->GetPosition());
                    break;
                case NPC_FALLEN_PRIESTESS:
                    owner->SummonCreature(NPC_FALLEN_PRIESTESS_MIRROR, loc->GetPosition());
                    break;
                case NPC_SOUL_RESIDUE:
                    owner->SummonCreature(NPC_SOUL_RESIDUE_MIRROR, loc->GetPosition());
                    break;
                }
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_tos_bound_essence::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//235923
class spell_tos_spear_of_anguish_filter : public SpellScript
{
    PrepareSpellScript(spell_tos_spear_of_anguish_filter);

    std::list<WorldObject*> tankList;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            if (object->ToPlayer()->HasAura(SPELL_SPIRIT_REALM) || object->ToPlayer()->HasAura(SPELL_SOULBIND_DUMMY))
                return true;

            if (object->ToPlayer()->IsAlive())
                tankList.push_back(object);

            return false;
        });

        if (targets.size() > 1)
        {
            if (auto topAggro = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_MAXTHREAT))
            {
                if (topAggro->IsPlayer() && topAggro->ToPlayer()->IsAlive())
                    targets.remove(topAggro);
                else if (!tankList.empty())
                    targets.remove(Trinity::Containers::SelectRandomContainerElement(tankList));
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_spear_of_anguish_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//235988
class spell_tos_tormented_cries_filter : public SpellScript
{
    PrepareSpellScript(spell_tos_tormented_cries_filter);

    std::list<WorldObject*> tankList;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            if (object->ToPlayer()->HasAura(SPELL_SPIRIT_REALM) || object->ToPlayer()->HasAura(SPELL_SPEAR_OF_ANGUISH_MARK))
                return true;

            if (object->ToPlayer()->IsAlive())
                tankList.push_back(object);

            return false;
        });

        if (targets.size() > 1)
        {
            if (auto topAggro = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_MAXTHREAT))
            {
                if (topAggro->IsPlayer() && topAggro->ToPlayer()->IsAlive())
                    targets.remove(topAggro);
                else if (!tankList.empty())
                    targets.remove(Trinity::Containers::SelectRandomContainerElement(tankList));
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_tormented_cries_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//236459
class spell_tos_soulbind : public AuraScript
{
    PrepareAuraScript(spell_tos_soulbind);

    uint8 counter = 0;

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        ++counter;

        if (GetUnitOwner())
        {
            GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SOULBIND_FIND_PLAYER, true);

            if (counter == 2)
            {
                if (GetUnitOwner()->HasAura(SPELL_SPIRIT_REALM))
                {
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SOULBIND_VISUAL_FIND_REAL, true);
                }
                else
                {
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SOULBIND_VISUAL_FIND_SPIRIT, true);
                }
            }
            else if (counter == 8)
            {
                counter = 0;
                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SOULBIND_DMG, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_soulbind::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//236515
class spell_tos_shattering_scream : public AuraScript
{
    PrepareAuraScript(spell_tos_shattering_scream);

    void OnTick(AuraEffect const* aurEff)
    {
        if (GetUnitOwner() && aurEff->GetBase()->GetStackAmount() == 5)
        {
            GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SHATTERING_SCREAM_EXPLOSION, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_shattering_scream::OnTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//235113, 235620, 235732, 235734
class spell_tos_spiritual_barrier_dissonance : public AuraScript
{
    PrepareAuraScript(spell_tos_spiritual_barrier_dissonance);

    uint32 tickTimer = 3000;

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget())
        {
            //GetTarget()->SetFlag(OBJECT_FIELD_DYNAMIC_FLAGS, UNIT_DYNFLAG_NOT_SELECTABLE_MODEL);

            if (GetTarget()->IsPlayer())
            {

                bool isSpiritRealm = GetId() == SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM;

               /* HostileRefManager& refManager = GetTarget()->getHostileRefManager();
                ThreatReference* ref = refManager.getFirst();

                while (ref)
                {
                    if (auto unit = ref->GetSource()->GetOwner())
                        if (auto creature = unit->ToCreature())
                        {
                            switch (creature->GetEntry())
                            {
                                //Real Realm
                            case NPC_ENGINE_OF_SOULS:
                            case NPC_REANIMATED_TEMPLAR:
                            case NPC_GHASTLY_BONEWARDEN:
                            case NPC_TORMENTED_CRIES_TRIG:
                            case NPC_FALLEN_PRIESTESS_MIRROR:  FIX LATER
                            case NPC_SOUL_RESIDUE_MIRROR:
                                if (isSpiritRealm)
                                    creature->getThreatManager().modifyThreatPercent(GetTarget(), -100);
                                break;
                                //Spirit Realm
                            case NPC_SOUL_QUEEN_DEJAHNA:
                            case NPC_FALLEN_PRIESTESS:
                            case NPC_SOUL_RESIDUE:
                            case NPC_REANIMATED_TEMPLAR_MIRROR:
                            case NPC_GHASTLY_BONEWARDEN_MIRROR:
                                if (!isSpiritRealm)
                                    creature->getThreatManager().modifyThreatPercent(GetTarget(), -100);
                                break;
                            default:
                                break;
                            }
                        }

                    ref = ref->next();
                }*/
            }
        }
    }

    void OnUpdate(AuraEffect const* auraEffect)
    {

        if (GetUnitOwner() && GetUnitOwner()->GetMap()->IsHeroic() && GetUnitOwner()->IsAlive())
        {
            if (auto instance = GetUnitOwner()->GetInstanceScript())
                if (instance->GetBossState(DATA_THE_DESOLATE_HOST) != IN_PROGRESS)
                    return;

            if (GetId() == SPELL_SPIRITUAL_BARRIER_VIS_REAL || GetId() == SPELL_SPIRITUAL_BARRIER_REAL_REALM)
                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_DISSONANCE_REAL_FILTER, true);
            else if (GetId() == SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT || GetId() == SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM)
                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_DISSONANCE_SPIRIT_FILTER, true);
        }


    }

    void Register() override
    {
        OnEffectApply += AuraEffectRemoveFn(spell_tos_spiritual_barrier_dissonance::OnApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectRemoveFn(spell_tos_spiritual_barrier_dissonance::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectRemoveFn(spell_tos_spiritual_barrier_dissonance::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_spiritual_barrier_dissonance::OnUpdate, EFFECT_0, SPELL_AURA_PHASE);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_spiritual_barrier_dissonance::OnUpdate, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//966000
struct at_tos_spirit_presence : AreaTriggerAI
{
    at_tos_spirit_presence(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    bool IsValidTarget(Unit* caster, Unit* target)
    {
        if (!target)
            return false;
        if (target->IsPlayer())
        {
            if (target->HasAura(SPELL_SPIRIT_REALM) && !target->HasAura(SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM))
            {
                target->RemoveAurasDueToSpell(SPELL_SPIRITUAL_BARRIER_REAL_REALM);
                target->CastSpell(target, SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM, true);
            }
            else if (!target->HasAura(SPELL_SPIRIT_REALM) && !target->HasAura(SPELL_SPIRITUAL_BARRIER_REAL_REALM))
            {
                target->RemoveAurasDueToSpell(SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM);
                target->CastSpell(target, SPELL_SPIRITUAL_BARRIER_REAL_REALM, true);
            }
        }
        else
        {
            switch (target->GetEntry())
            {
                //Real Realm
            case NPC_ENGINE_OF_SOULS:
            case NPC_REANIMATED_TEMPLAR:
            case NPC_GHASTLY_BONEWARDEN:
            case NPC_TORMENTED_CRIES_TRIG:
            case NPC_FALLEN_PRIESTESS_MIRROR:
            case NPC_SOUL_RESIDUE_MIRROR:
                if (!target->HasAura(SPELL_SPIRITUAL_BARRIER_VIS_REAL))
                    target->CastSpell(target, SPELL_SPIRITUAL_BARRIER_VIS_REAL, true);
                break;
                //Spirit Realm
            case NPC_SOUL_QUEEN_DEJAHNA:
            case NPC_FALLEN_PRIESTESS:
            case NPC_SOUL_RESIDUE:
            case NPC_REANIMATED_TEMPLAR_MIRROR:
            case NPC_GHASTLY_BONEWARDEN_MIRROR:
                if (!target->HasAura(SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT))
                {
                    target->CastSpell(target, SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT, true);
                    target->CastSpell(target, SPELL_SPIRIT_REALM, true);
                }
                break;
            default:
                break;
            }

            if (auto owner = target->GetOwner())
            {
                if (owner->IsPlayer())
                {
                    if (owner->HasAura(SPELL_SPIRIT_REALM))
                    {
                        if (!target->HasAura(SPELL_SPIRIT_REALM))
                        {
                            target->RemoveAurasDueToSpell(SPELL_SPIRITUAL_BARRIER_VIS_REAL);
                            target->CastSpell(target, SPELL_SPIRIT_REALM, true);
                            target->CastSpell(target, SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT, true);
                        }
                    }
                    else
                    {
                        if (target->HasAura(SPELL_SPIRIT_REALM))
                        {
                            target->RemoveAurasDueToSpell(SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT);
                            target->RemoveAurasDueToSpell(SPELL_SPIRIT_REALM);
                            target->CastSpell(target, SPELL_SPIRITUAL_BARRIER_VIS_REAL, true);
                        }
                    }
                }
            }
        }

        return true;
    }
};

void AddSC_boss_desolate_host()
{
    RegisterCreatureAI(boss_the_desolate_host_generic);
    RegisterCreatureAI(npc_tos_engine_of_souls);
    RegisterCreatureAI(npc_tos_soul_queen_dejahna);
    RegisterCreatureAI(npc_tos_desolate_host);
    RegisterCreatureAI(npc_tos_spiritual_font);
    RegisterCreatureAI(npc_tos_reanimated_templar);
    RegisterCreatureAI(npc_tos_ghastly_bonewarden);
    RegisterCreatureAI(npc_tos_fallen_priestess);
    RegisterCreatureAI(npc_tos_soul_residue);
    RegisterCreatureAI(npc_tos_tormented_cries);
    RegisterSpellScript(spell_tos_quietus_filter);
    RegisterSpellScript(spell_tos_soulbind_finder);
    RegisterSpellScript(spell_tos_soulbind_visual_finder);
    RegisterSpellScript(spell_tos_sundering_doom);
    RegisterSpellScript(spell_tos_dissonance);
    RegisterSpellScript(spell_tos_dissonance_filter);
    RegisterSpellScript(spell_tos_spear_of_anguish);
    RegisterSpellScript(spell_tos_bound_essence);
    RegisterSpellScript(spell_tos_spear_of_anguish_filter);
    RegisterSpellScript(spell_tos_tormented_cries_filter);
    RegisterAuraScript(spell_tos_soulbind);
    RegisterAuraScript(spell_tos_shattering_scream);
    RegisterAuraScript(spell_tos_spiritual_barrier_dissonance);
    RegisterAreaTriggerAI(at_tos_spirit_presence);
}
