#include "antorus.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_COLLAPSING_WORLD = 1,
    SAY_FELSTORM_BARRAGE = 2,
    SAY_OPEN_PORTAL_XOROTH = 3,
    SAY_WARN_OPEN_PORTAL_XOROTH = 4,
    SAY_TRANSPORT_PORTAL = 5,
    SAY_OPEN_PORTAL_RANCORA = 6,
    SAY_WARN_OPEN_PORTAL_RANCORA = 7,
    SAY_OPEN_PORTAL_NATHREZA = 8,
    SAY_WARN_OPEN_PORTAL_NATHREZA = 9,
    SAY_DEATH = 10,

    SAY_GUARD_AGGRO = 0,
    SAY_GUARD_DEATH = 1,
};

enum Spells
{
    SPELL_OUTRO_CONV = 249125,
    SPELL_PLATFORM_NEXUS = 244450,
    SPELL_PLATFORM_XOROTH = 244454,
    SPELL_PLATFORM_XOROTH_PLAYER = 244455,
    SPELL_PLATFORM_RANCORA = 244515,
    SPELL_PLATFORM_RANCORA_PLAYER = 244512,
    SPELL_PLATFORM_NATHREZA = 245055,
    SPELL_PLATFORM_NATHREZA_PLAYER = 244513,
    SPELL_INTENSITY_MOD = 246164, //Portals Mod damage
    SPELL_PORTAL_XOROTH_AT = 254507,
    SPELL_PORTAL_RANCORA_AT = 254511,
    SPELL_PORTAL_NATHREZA_AT = 254515,
    SPELL_BERSERK = 26662,
    SPELL_DAILY_ESSENCE_HASABEL = 305310,

    //Gateways XOROTH
    SPELL_XOROTH_ENTER_GATE_AT = 244017,
    SPELL_XOROTH_EXIT_GATE_AT = 244111,
    SPELL_XOROTH_PLAYER_WP_ENTER = 244073,
    SPELL_XOROTH_PLAYER_WP_EXIT = 244112,
    SPELL_XOROTH_PLAYER_WP_FLY_AURA = 252776,
    SPELL_ACTIVATE_XOROTH = 257939,
    SPELL_EMPOWERED_XOROTH_PERIODIC = 244316, //On active portal
    SPELL_EMPOWERED_XOROTH_DMG = 244318,
    SPELL_EMPOWERED_XOROTH_VISUAL = 244487,
    SPELL_XOROTH_PERIODIC = 244319, //After died mini-boss
    SPELL_XOROTH_DMG = 244320,
    SPELL_XOROTH_VISUAL = 244488,

    //Gateways RANCORA
    SPELL_RANCORA_ENTER_GATE_AT = 244137,
    SPELL_RANCORA_EXIT_GATE_AT = 244139,
    SPELL_RANCORA_PLAYER_WP_ENTER = 244136,
    SPELL_RANCORA_PLAYER_WP_EXIT = 244138,
    SPELL_RANCORA_PLAYER_WP_FLY_AURA = 252777,
    SPELL_ACTIVATE_RANCORA = 257941,
    SPELL_EMPOWERED_RANCORA_PERIODIC = 246081, //On active portal
    SPELL_RANCORA_PERIODIC = 246083, //After died mini-boss

    //Gateways NATHREZA
    SPELL_NATHREZA_ENTER_GATE_AT = 244148,
    SPELL_NATHREZA_EXIT_GATE_AT = 244149,
    SPELL_NATHREZA_PLAYER_WP_EXIT = 244145,
    SPELL_NATHREZA_PLAYER_WP_ENTER = 244146,
    SPELL_NATHREZA_PLAYER_WP_FLY_AURA = 244494,
    SPELL_ACTIVATE_NATHREZA = 257942,
    SPELL_EMPOWERED_NATHREZA_PERIODIC = 246154, //On active portal
    SPELL_NATHREZA_PERIODIC = 246155, //After died mini-boss

    //Boss
    SPELL_EMPTY_ENERGY = 247142,
    SPELL_CLOSE_GATEWAYS = 253198, //?
    SPELL_ENERGIZE_PERIODIC = 247143,
    SPELL_REALITY_TEAR = 244016,
    SPELL_BURSTING_DARKNESS = 244021,
    SPELL_COLLAPSING_WORLD = 243983,
    SPELL_COLLAPSING_WORLD_DMG = 243984,
    SPELL_FELSTORM_BARRAGE = 244000,
    SPELL_FELSTORM_BARRAGE_DMG = 244001,
    SPELL_TRANSPORT_PORTAL = 244689,
    SPELL_TRANSPORT_PORTAL_PERIODIC = 244687,
    SPELL_TRANSPORT_BLAZING_IMP = 244692,
    SPELL_TRANSPORT_HUNGERING_STALKER = 245485,
    SPELL_TRANSPORT_FELTOUCHED_SKITTERER = 246192,
    SPELL_CATASTROPHIC_IMPLOSION = 246075,

    //Summons
    SPELL_FIERY_DETONATION = 244709, //Heroic+
    SPELL_ACIDIC_WEB = 246208,
    SPELL_HOWLING_DARK = 245538,
    SPELL_HOWLING_SHADOWS = 245504,
    SPELL_UNRELENTING = 221419,

    //Platform: XOROTH
    SPELL_EVERBURNING_FLAMES_AT = 244612,
    SPELL_EVERBURNING_FLAMES_MISSILE_PLR = 244661,
    SPELL_EVERBURNING_FLAMES_PLR_AT = 244664,
    SPELL_EVERBURNING_LIGHT_AT = 245153, //Disable Dark Visual
    SPELL_UNSTABLE_PORTAL = 255802,
    SPELL_UNSTABLE_PORTAL_DUMMY = 255804,
    SPELL_UNSTABLE_PORTAL_DMG = 255805,
    SPELL_FLAMES_OF_XOROTH = 244607,
    SPELL_SUPERNOVA = 244598,
    SPELL_AEGIS_OF_FLAMES = 244383, //Mythic

    //Platform: RANCORA
    SPELL_ACID_CLOUD = 244742,
    SPELL_CAUSTIC_DETONATION = 244853,
    SPELL_CAUSTIC_DETONATION_FILTER = 244864,
    SPELL_FELSILK_WRAP = 244926,
    SPELL_FELSILK_WRAP_SUMMON = 244946,
    SPELL_FELSILK_WRAP_VISUAL = 244948,
    SPELL_FELSILK_WRAP_STUN = 244949,
    SPELL_FELSILK_WRAP_SELF_DMG = 244952,
    SPELL_POISON_ESSENCE = 246316,
    SPELL_LEECH_ESSENCE = 244915, //Mythic
    SPELL_LEECH_ESSENCE_VISUAL = 244918,

    //Platform: NATHREZA
    SPELL_MIND_FOG_AT = 245094,
    SPELL_CLOYING_SHADOWS_AT = 245104,
    SPELL_HUNGERING_GLOOM = 245075,
    SPELL_DELUSIONS = 245050,
    SPELL_CORRUPT = 245040,
};

enum Events
{
    EVENT_REALITY_TEAR = 1,
    EVENT_FELSTORM_BARRAGE = 2,
    EVENT_TRANSPORT_PORTAL = 3,
};

enum Actions
{
    ACTION_SPAWN_GUARD = 1,
    ACTION_GATEWAY_EMPOWERED_DMG,
    ACTION_GATEWAY_NORMAL_DMG,
    ACTION_RUN_CATASTROPHIC,
    ACTION_DISABLE_CATASTROPHIC
};

enum Misc
{
    DATA_COLLAPSING_DELAY = 0,
};

Position const platformPos[4] =
{
    {-3703.84f, -1351.38f, 624.50f}, // Nexus
    {-3793.36f, -1415.95f, 645.53f}, // Xoroth
    {-3704.75f, -1254.53f, 650.19f}, // Rancora
    {-3614.83f, -1412.32f, 645.57f}  // Nathreza
};

Position const felcrushPortalPos[3][2] =
{
    { {-3738.13f, -1388.33f, 624.49f, 0.88f}, {-3666.90f, -1312.99f, 624.49f, 4.09f} },
    { {-3653.38f, -1359.35f, 624.49f, 2.85f}, {-3753.77f, -1341.14f, 624.48f, 5.94f} },
    { {-3725.36f, -1307.77f, 624.49f, 5.30f}, {-3688.55f, -1396.82f, 624.49f, 2.04f} }
};

Position const flamesPos[7] =
{
    {-3782.79f, -1435.94f, 645.18f},
    {-3775.45f, -1426.95f, 645.18f},
    {-3788.28f, -1421.96f, 645.22f},
    {-3806.18f, -1413.43f, 645.21f},
    {-3800.01f, -1400.48f, 645.19f},
    {-3813.14f, -1402.55f, 645.18f},
    {-3809.17f, -1392.95f, 645.18f}
};

Position const acidPos[4] =
{
    {-3734.01f, -1254.98f, 649.75f},
    {-3722.53f, -1246.23f, 649.75f},
    {-3688.10f, -1243.51f, 649.75f},
    {-3674.33f, -1250.97f, 649.75f}
};

enum CustomMiscIds
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9,
    EVENT_10,
};

//122104
struct boss_hasabel : BossAI
{
    boss_hasabel(Creature* creature) : BossAI(creature, DATA_HASABEL) {}

    bool hasPlayerNexusPlatform = false;
    bool platformEmpty = false;
    uint8 healthPct = 0;
    uint32 collapsingWorldDelayed = 0;
    uint32 berserkTimer = 0;
    uint32 checkPlayersTimer = 0;
    uint32 portalSpellId[3] = { SPELL_PORTAL_XOROTH_AT, SPELL_PORTAL_RANCORA_AT, SPELL_PORTAL_NATHREZA_AT };

    void Reset() override
    {
        _Reset();
        me->RemoveAllAuras();
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_AGGRESSIVE);
        me->CastSpell(me, SPELL_EMPTY_ENERGY, true);
        platformEmpty = false;
        healthPct = 91;
        collapsingWorldDelayed = 0;
        checkPlayersTimer = 0;
        berserkTimer = 0;

        for (uint8 i = 0; i < 3; ++i)
        {
            if (auto portal = me->SummonCreature(NPC_TRIG_PORTAL_AT, platformPos[i + 1]))
            {
                portal->CastSpell(portal, portalSpellId[i], true);
                //Platform: NATHREZA
                if (i == 2)
                    portal->CastSpell(portal, SPELL_MIND_FOG_AT, true);
            }
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        //me->CastSpell(me, SPELL_CLOSE_GATEWAYS, true);
        me->CastSpell(me, SPELL_ENERGIZE_PERIODIC, true);
        berserkTimer = 720 * IN_MILLISECONDS;

        checkPlayersTimer = 1000;
        events.RescheduleEvent(EVENT_REALITY_TEAR, 7000);
        events.RescheduleEvent(EVENT_FELSTORM_BARRAGE, 26000);

        for (uint8 i = 0; i < 4; ++i)
            me->CastSpell(acidPos[i], SPELL_ACID_CLOUD, true);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
        //TeleportPlayers();
        AddDelayedEvent(1000, [this]() -> void { me->CastSpell(me, SPELL_OUTRO_CONV, true); });
        instance->DoOnPlayers([](Player* player)
        {
            player->CastSpell(player, SPELL_DAILY_ESSENCE_HASABEL, true);
        });
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_VULCANAR:
           // DoActionSummon(NPC_GATEWAY_XOROTH_ENTER, ACTION_GATEWAY_NORMAL_DMG);
            break;
        case NPC_LADY_DACIDION:
            //DoActionSummon(NPC_GATEWAY_RANCORA_ENTER, ACTION_GATEWAY_NORMAL_DMG);
            break;
        case NPC_LORD_EILGAR:
            //DoActionSummon(NPC_GATEWAY_NATHREZA_ENTER, ACTION_GATEWAY_NORMAL_DMG);
            break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
        case NPC_TRIG_ETERNAL_DARKNESS:
            summon->CastSpell(summon, SPELL_CLOYING_SHADOWS_AT, true);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_ACTIVATE_XOROTH:
        {
            //DoActionSummon(NPC_VULCANAR, ACTION_SPAWN_GUARD);
            //(NPC_GATEWAY_XOROTH_ENTER, ACTION_GATEWAY_EMPOWERED_DMG);
            summons.DespawnEntry(NPC_TRIG_FLAMES_OF_XOROTH);
            for (uint8 i = 0; i < 7; ++i)
                me->SummonCreature(NPC_EVERBURNING_FLAMES, flamesPos[i]);
            break;
        }
        case SPELL_ACTIVATE_RANCORA:
            //(NPC_LADY_DACIDION, ACTION_SPAWN_GUARD);
            //DoActionSummon(NPC_GATEWAY_RANCORA_ENTER, ACTION_GATEWAY_EMPOWERED_DMG);
            summons.DespawnEntry(NPC_TRIG_ACID_OF_RANCORA);
            break;
        case SPELL_ACTIVATE_NATHREZA:
            //DoActionSummon(NPC_LORD_EILGAR, ACTION_SPAWN_GUARD);
            //DoActionSummon(NPC_GATEWAY_NATHREZA_ENTER, ACTION_GATEWAY_EMPOWERED_DMG);
            summons.DespawnEntry(NPC_TRIG_SHADOWS_OF_NATHREZA);
            break;
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_FELSTORM_BARRAGE:
            FelStorm();
            break;
        case SPELL_COLLAPSING_WORLD:
            events.RescheduleEvent(EVENT_TRANSPORT_PORTAL, 10000);
            events.RescheduleEvent(EVENT_FELSTORM_BARRAGE, 10000);
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HealthBelowPct(healthPct))
        {
            if (healthPct == 91)
            {
                healthPct = 61;
                Talk(SAY_OPEN_PORTAL_XOROTH);
                Talk(SAY_WARN_OPEN_PORTAL_XOROTH);
                me->CastSpell(me, SPELL_ACTIVATE_XOROTH, true);
                events.RescheduleEvent(EVENT_TRANSPORT_PORTAL, 2000);
            }
            else if (healthPct == 61)
            {
                healthPct = 31;
                Talk(SAY_OPEN_PORTAL_RANCORA);
                Talk(SAY_WARN_OPEN_PORTAL_RANCORA);
                me->CastSpell(me, SPELL_ACTIVATE_RANCORA, true);
            }
            else if (healthPct == 31)
            {
                healthPct = 0;
                Talk(SAY_OPEN_PORTAL_NATHREZA);
                Talk(SAY_WARN_OPEN_PORTAL_NATHREZA);
                me->CastSpell(me, SPELL_ACTIVATE_NATHREZA, true);
            }
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_COLLAPSING_DELAY)
            return collapsingWorldDelayed;

        return 0;
    }

    void FelStorm()
    {
        if (IsLFR() || IsNormalRaid())
        {
            me->SummonCreature(NPC_TRIG_FELCRUSH_PORTAL, felcrushPortalPos[urand(0, 2)][urand(0, 1)], TEMPSUMMON_TIMED_DESPAWN, 12000);
        }
        else
        {
            std::list<Position> posList;
            uint32 delay = 0;

            for (uint8 i = 0; i < 3; ++i)
                posList.push_back(felcrushPortalPos[i][urand(0, 1)]);

            //Trinity::Containers::RandomShuffle(posList);

            for (auto pos : posList)
            {
                AddDelayedCombat(delay, [this, pos]() -> void { me->SummonCreature(NPC_TRIG_FELCRUSH_PORTAL, pos, TEMPSUMMON_TIMED_DESPAWN, 12000); });
                delay += 2000;
            }
        }
    }

    void TeleportPlayers()
    {
        instance->DoOnPlayers([](Player* player)
        {
            if (!player)
                return;

            for (uint8 i = 1; i <= 3; ++i)
            {
                if (player->GetDistance(platformPos[i]) <= 40.0f)
                    player->NearTeleportTo(-3703.88f + frand(-1.5f, 1.5f), -1373.48f + frand(-1.5f, 1.5f), 625.0f, player->GetOrientation());
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (collapsingWorldDelayed)
        {
            if (collapsingWorldDelayed <= diff)
                collapsingWorldDelayed = 0;
            else
                collapsingWorldDelayed -= diff;
        }

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;
                me->CastSpell(me, SPELL_BERSERK, true);
            }
            else
                berserkTimer -= diff;
        }

        if (checkPlayersTimer)
        {
            if (checkPlayersTimer <= diff)
            {
                checkPlayersTimer = 1000;
                hasPlayerNexusPlatform = false;

                if (auto victim = me->GetVictim())
                {
                    if (victim->GetDistance(platformPos[0]) > 40.0f)
                        ModifyThreatByPercent(victim, -100);
                }

                instance->DoOnPlayers([this](Player* player)
                {
                    if (player && player->IsAlive())
                    {
                        if (player->GetDistance(platformPos[0]) <= 40.0f)
                        {
                            hasPlayerNexusPlatform = true;

                            if (!player->HasAura(SPELL_PLATFORM_NEXUS))
                                player->CastSpell(player, SPELL_PLATFORM_NEXUS, true);
                        }
                        else
                            player->RemoveAurasDueToSpell(SPELL_PLATFORM_NEXUS);
                    }
                });

                if (!hasPlayerNexusPlatform && !platformEmpty)
                {
                    platformEmpty = true;
                    //DoResetThreat();
                    me->AttackStop();

                    if (me->GetDistance(platformPos[0]) >= 40.0f)
                        me->NearTeleportTo(me->GetHomePosition());
                    else
                        me->GetMotionMaster()->MoveTargetedHome();

                    //ActivateCatastrophic(true);
                }
                else if (hasPlayerNexusPlatform && platformEmpty)
                {
                    platformEmpty = false;
                    me->SetReactState(REACT_AGGRESSIVE);
                    //ActivateCatastrophic(false);
                }
            }
            else
                checkPlayersTimer -= diff;
        }

        if (platformEmpty)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_REALITY_TEAR:
                me->CastSpell(me->GetVictim(), SPELL_REALITY_TEAR);
                events.RescheduleEvent(EVENT_REALITY_TEAR, 12000);
                break;
            case EVENT_FELSTORM_BARRAGE:
                Talk(SAY_FELSTORM_BARRAGE);
                DoCast(SPELL_FELSTORM_BARRAGE);
                collapsingWorldDelayed = 10000;
                events.RescheduleEvent(EVENT_TRANSPORT_PORTAL, 10000);
                events.RescheduleEvent(EVENT_FELSTORM_BARRAGE, 32000);
                break;
            case EVENT_TRANSPORT_PORTAL:
            {
                if (urand(0, 1))
                    Talk(SAY_TRANSPORT_PORTAL);
                Position pos;
                me->GetFirstCollisionPosition(frand(10.0f, 20.0f), frand(0.0f, 6.28f));
                me->CastSpell(pos, SPELL_TRANSPORT_PORTAL, false);
                events.RescheduleEvent(EVENT_FELSTORM_BARRAGE, 10000);
                events.RescheduleEvent(EVENT_TRANSPORT_PORTAL, 40000);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//122494, 122533, 122543, 122555, 122558, 122559
struct npc_hasabel_gateways : public ScriptedAI
{
    npc_hasabel_gateways(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    bool catastrophicActive = false;
    uint32 catastrophicTimer = 0;

    void Reset() {}

    void IsSummonedBy(Unit* summoner) override
    {
        switch (me->GetEntry())
        {
        case NPC_GATEWAY_XOROTH_ENTER:
            me->CastSpell(me, SPELL_XOROTH_ENTER_GATE_AT, true);
            break;
        case NPC_GATEWAY_XOROTH_EXIT:
            me->CastSpell(me, SPELL_XOROTH_EXIT_GATE_AT, true);
            break;
        case NPC_GATEWAY_RANCORA_ENTER:
            me->CastSpell(me, SPELL_RANCORA_ENTER_GATE_AT, true);
            break;
        case NPC_GATEWAY_RANCORA_EXIT:
            me->CastSpell(me, SPELL_RANCORA_EXIT_GATE_AT, true);
            break;
        case NPC_GATEWAY_NATHREZA_ENTER:
            me->CastSpell(me, SPELL_NATHREZA_ENTER_GATE_AT, true);
            break;
        case NPC_GATEWAY_NATHREZA_EXIT:
            me->CastSpell(me, SPELL_NATHREZA_EXIT_GATE_AT, true);
            break;
        }
    }

    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
    {
        switch (createATSpellId)
        {
        case SPELL_XOROTH_ENTER_GATE_AT:
            target->CastSpell(target, SPELL_XOROTH_PLAYER_WP_ENTER, true);
            break;
        case SPELL_XOROTH_EXIT_GATE_AT:
            target->CastSpell(target, SPELL_XOROTH_PLAYER_WP_EXIT, true);
            break;
        case SPELL_RANCORA_ENTER_GATE_AT:
            target->CastSpell(target, SPELL_RANCORA_PLAYER_WP_ENTER, true);
            break;
        case SPELL_RANCORA_EXIT_GATE_AT:
            target->CastSpell(target, SPELL_RANCORA_PLAYER_WP_EXIT, true);
            break;
        case SPELL_NATHREZA_ENTER_GATE_AT:
            target->CastSpell(target, SPELL_NATHREZA_PLAYER_WP_ENTER, true);
            break;
        case SPELL_NATHREZA_EXIT_GATE_AT:
            target->CastSpell(target, SPELL_NATHREZA_PLAYER_WP_EXIT, true);
            break;
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_EMPOWERED_XOROTH_DMG:
            me->CastSpell(me, SPELL_EMPOWERED_XOROTH_VISUAL, true);
            break;
        case SPELL_XOROTH_DMG:
            me->CastSpell(me, SPELL_XOROTH_VISUAL, true);
            break;
        }
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_INTENSITY_MOD:
            me->CastSpell(me, SPELL_INTENSITY_MOD, true);
            break;
        }
    }

    void DoAction(int32 actionID) 
    {
        switch (me->GetEntry())
        {
        case NPC_GATEWAY_XOROTH_ENTER:
        {
            if (actionID == ACTION_GATEWAY_EMPOWERED_DMG)
            {
                me->CastSpell(me, SPELL_INTENSITY_MOD, true);
                me->CastSpell(me, SPELL_EMPOWERED_XOROTH_PERIODIC, true);
            }
            else if (actionID == ACTION_GATEWAY_NORMAL_DMG)
            {
                me->RemoveAurasDueToSpell(SPELL_INTENSITY_MOD);
                me->RemoveAurasDueToSpell(SPELL_EMPOWERED_XOROTH_PERIODIC);
                me->CastSpell(me, SPELL_XOROTH_PERIODIC, true);
            }
            break;
        }
        case NPC_GATEWAY_RANCORA_ENTER:
        {
            if (actionID == ACTION_GATEWAY_EMPOWERED_DMG)
            {
                me->CastSpell(me, SPELL_INTENSITY_MOD, true);
                me->CastSpell(me, SPELL_EMPOWERED_RANCORA_PERIODIC, true);
            }
            else if (actionID == ACTION_GATEWAY_NORMAL_DMG)
            {
                me->RemoveAurasDueToSpell(SPELL_INTENSITY_MOD);
                me->RemoveAurasDueToSpell(SPELL_EMPOWERED_RANCORA_PERIODIC);
                me->CastSpell(me, SPELL_RANCORA_PERIODIC, true);
            }
            break;
        }
        case NPC_GATEWAY_NATHREZA_ENTER:
        {
            if (actionID == ACTION_GATEWAY_EMPOWERED_DMG)
            {
                me->CastSpell(me, SPELL_INTENSITY_MOD, true);
                me->CastSpell(me, SPELL_EMPOWERED_NATHREZA_PERIODIC, true);
            }
            else if (actionID == ACTION_GATEWAY_NORMAL_DMG)
            {
                me->RemoveAurasDueToSpell(SPELL_INTENSITY_MOD);
                me->RemoveAurasDueToSpell(SPELL_EMPOWERED_NATHREZA_PERIODIC);
                me->CastSpell(me, SPELL_NATHREZA_PERIODIC, true);
            }
            break;
        }
        }

        if (actionID == ACTION_RUN_CATASTROPHIC)
            catastrophicActive = true;
        else if (actionID == ACTION_DISABLE_CATASTROPHIC)
            catastrophicActive = false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (catastrophicActive)
        {
            if (catastrophicTimer <= diff)
            {
                catastrophicTimer = 1000;
                me->CastSpell(me, SPELL_CATASTROPHIC_IMPLOSION);
            }
            else
                catastrophicTimer -= diff;
        }
    }
};

//122211, 122212, 122213
struct npc_hasabel_guards : public ScriptedAI
{
    npc_hasabel_guards(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
        me->SetVisible(false);
    }

    InstanceScript* instance;
    EventMap events;
    ObjectGuid playerGUID;
    std::vector<uint32> platformAura;
    bool hasPlayerPlatform = false;
    uint32 checkPlayersTimer = 0;
    uint32 unstablePortalTimer = 0;

    void Reset() override
    {
        events.Reset();
        checkPlayersTimer = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_VULCANAR:
            platformAura = { SPELL_PLATFORM_XOROTH, SPELL_PLATFORM_XOROTH_PLAYER };
            if (IsMythicRaid())
                me->CastSpell(me, SPELL_AEGIS_OF_FLAMES, true);
            events.RescheduleEvent(EVENT_2, 5000); //FLAMES_OF_XOROTH
            events.RescheduleEvent(EVENT_3, 10000); //SUPERNOVA
            break;
        case NPC_LADY_DACIDION:
            platformAura = { SPELL_PLATFORM_RANCORA, SPELL_PLATFORM_RANCORA_PLAYER };
            events.RescheduleEvent(EVENT_4, 13000); //FELSILK_WRAP
            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_6, 5000); //LEECH_ESSENCE
            else
                events.RescheduleEvent(EVENT_5, 7000); //POISON_ESSENCE
            break;
        case NPC_LORD_EILGAR:
            platformAura = { SPELL_PLATFORM_NATHREZA, SPELL_PLATFORM_NATHREZA_PLAYER };
            events.RescheduleEvent(EVENT_7, 11000); //DELUSIONS
            events.RescheduleEvent(EVENT_8, 6000); //CORRUPT
            break;
        }
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        checkPlayersTimer = 2000;
        Talk(SAY_GUARD_AGGRO);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_GUARD_DEATH);
    }

    void EnterEvadeMode(EvadeReason w)
    {
        //ScriptedAI::EnterEvadeMode();

        if (!me->HasAura(platformAura[0]))
            me->NearTeleportTo(me->GetHomePosition());
        else
            me->GetMotionMaster()->MoveTargetedHome();
    }

    void DoAction(int32 const actionID) override
    {
        if (actionID == ACTION_SPAWN_GUARD)
        {
            me->SetVisible(true);
            me->SetReactState(REACT_AGGRESSIVE);
            me->CastSpell(me, SPELL_UNSTABLE_PORTAL, true);
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_CAUSTIC_DETONATION_FILTER)
        {
            if (auto aura = me->GetAura(SPELL_AEGIS_OF_FLAMES))
                aura->ModStackAmount(-1);
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_UNSTABLE_PORTAL_DUMMY)
            unstablePortalTimer = 1000;

        if (spell->Id == SPELL_FELSILK_WRAP)
        {
            auto owner = me->GetOwner();
            auto player = ObjectAccessor::GetPlayer(*me, playerGUID);
            if (!owner || !player)
                return;

            if (auto web = owner->SummonCreature(NPC_FELSILK_WEB, player->GetPosition()))
            {
                web->CastSpell(web, SPELL_FELSILK_WRAP_VISUAL, true);
                web->CastSpell(player, SPELL_FELSILK_WRAP_STUN, true);
            }
        }
    }

    void OnInterruptCast(Unit* /*caster*/, uint32 /*spellId*/, uint32 curSpellID, uint32 /*schoolMask*/)
    {
        if (curSpellID == SPELL_UNSTABLE_PORTAL_DMG)
            unstablePortalTimer = urandms(6, 8);

        if (curSpellID == SPELL_FLAMES_OF_XOROTH)
            events.RescheduleEvent(EVENT_2, urandms(6, 8));
    }

    void HealReceived(Unit* /*healer*/, uint32& heal) override
    {
        if (me->HasAura(SPELL_HUNGERING_GLOOM))
        {
            heal = 0;
            return;
        }

        //SPELL_LEECH_ESSENCE
        heal = heal * 5;
    }

    void UpdateAI(uint32 diff) override
    {
        if (unstablePortalTimer)
        {
            if (unstablePortalTimer <= diff)
            {
                unstablePortalTimer = 4000;
                me->CastSpell(me, SPELL_UNSTABLE_PORTAL_DMG);
            }
            else
                unstablePortalTimer -= diff;
        }

        if (!UpdateVictim())
            return;

        if (checkPlayersTimer)
        {
            if (checkPlayersTimer <= diff)
            {
                checkPlayersTimer = 1000;
                hasPlayerPlatform = false;

                if (auto victim = me->GetVictim())
                {
                    if (!victim->HasAura(platformAura[1]))
                        ModifyThreatByPercent(victim, -100);
                }

                instance->DoOnPlayers([this](Player* player)
                {
                    if (player && player->IsAlive() && player->HasAura(platformAura[1]))
                        hasPlayerPlatform = true;
                });

                if (!hasPlayerPlatform)
                {
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    return;
                }
            }
            else
                checkPlayersTimer -= diff;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_2:
                me->CastSpell(me, SPELL_FLAMES_OF_XOROTH);
                events.RescheduleEvent(EVENT_2, 6000);
                break;
            case EVENT_3:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                    me->CastSpell(target, SPELL_SUPERNOVA);
                events.RescheduleEvent(EVENT_3, urandms(4, 6));
                break;
            case EVENT_4:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 1, 45.0f, true, -SPELL_FELSILK_WRAP_STUN))
                {
                    playerGUID = target->GetGUID();
                    me->CastSpell(target, SPELL_FELSILK_WRAP);
                }
                events.RescheduleEvent(EVENT_4, 17000);
                break;
            case EVENT_5:
                me->CastSpell(me, SPELL_POISON_ESSENCE);
                events.RescheduleEvent(EVENT_5, 10000);
                break;
            case EVENT_6:
                me->CastSpell(me, SPELL_LEECH_ESSENCE);
                events.RescheduleEvent(EVENT_6, 10000);
                break;
            case EVENT_7:
                me->CastSpell(me, SPELL_DELUSIONS);
                events.RescheduleEvent(EVENT_7, 16000);
                break;
            case EVENT_8:
                me->CastSpell(me, SPELL_CORRUPT);
                events.RescheduleEvent(EVENT_8, 6000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//122425
struct npc_hasabel_collapsing_world : public ScriptedAI
{
    npc_hasabel_collapsing_world(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_COLLAPSING_WORLD_DMG, false, nullptr, nullptr, summoner->GetGUID());
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override {}
};

//122438
struct npc_hasabel_felcrush_portal : public ScriptedAI
{
    npc_hasabel_felcrush_portal(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(21342);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_FELSTORM_BARRAGE_DMG, false, nullptr, nullptr, summoner->GetGUID());
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override {}
};

//122761
struct npc_hasabel_transport_portal : public ScriptedAI
{
    npc_hasabel_transport_portal(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(21342);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_TRANSPORT_PORTAL_PERIODIC, true);
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override {}
};

//122783, 123223, 123702
struct npc_hasabel_portal_summon : public ScriptedAI
{
    npc_hasabel_portal_summon(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    InstanceScript* instance;
    EventMap events;
    bool hasPlayerNexusPlatform = false;
    uint32 checkPlayersTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        DoZoneInCombat(me, 60.0f);
        checkPlayersTimer = 200;

        if (IsMythicRaid())
            events.RescheduleEvent(EVENT_4, 10000);

        switch (me->GetEntry())
        {
        case NPC_BLAZING_IMP:
            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_1, 500);
            break;
        case NPC_FELTOUCHED_SKITTERER:
            events.RescheduleEvent(EVENT_2, 6000); //Need correct timer
            break;
        case NPC_HUNGERING_STALKER:
            events.RescheduleEvent(EVENT_3, 2000);
            break;
        }
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (checkPlayersTimer)
        {
            if (checkPlayersTimer <= diff)
            {
                checkPlayersTimer = 1000;
                hasPlayerNexusPlatform = false;

                if (auto victim = me->GetVictim())
                {
                    if (victim->GetDistance(platformPos[0]) > 40.0f)
                        ModifyThreatByPercent(victim, -100);
                }

                instance->DoOnPlayers([this](Player* player)
                {
                    if (player && player->IsAlive())
                    {
                        if (player->GetDistance(platformPos[0]) <= 40.0f)
                            hasPlayerNexusPlatform = true;
                    }
                });

                if (!hasPlayerNexusPlatform && me->GetReactState() == REACT_AGGRESSIVE)
                {
                  //DoResetThreat();
                    me->AttackStop();

                    if (me->GetDistance(platformPos[0]) >= 40.0f)
                        me->NearTeleportTo(me->GetHomePosition());
                    else
                        me->GetMotionMaster()->MoveTargetedHome();
                }
                else if (hasPlayerNexusPlatform && me->GetReactState() != REACT_AGGRESSIVE)
                    me->SetReactState(REACT_AGGRESSIVE);
            }
            else
                checkPlayersTimer -= diff;
        }

        if (!hasPlayerNexusPlatform)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(SPELL_FIERY_DETONATION);
                events.RescheduleEvent(EVENT_1, 8000);
                break;
            case EVENT_2:
                me->CastSpell(me->GetVictim(), SPELL_ACIDIC_WEB);
                events.RescheduleEvent(EVENT_2, 9000); //Need correct timer
                break;
            case EVENT_3:
                DoCast(me, SPELL_HOWLING_DARK, true);
                me->CastSpell(me, SPELL_HOWLING_SHADOWS);
                events.RescheduleEvent(EVENT_3, 12000);
                break;
            case EVENT_4:
                me->CastSpell(me, SPELL_UNRELENTING, true);
                events.RescheduleEvent(EVENT_4, 10000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//122733, 123003
struct npc_hasabel_everburning_flames : public ScriptedAI
{
    npc_hasabel_everburning_flames(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(21342);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (me->GetEntry() == NPC_EVERBURNING_FLAMES)
        {
            DoCast(me, SPELL_EVERBURNING_FLAMES_AT, true);
            me->GetMotionMaster()->MoveRandom(10.0f);
        }
        else
        {
            DoCast(me, SPELL_EVERBURNING_FLAMES_PLR_AT, true);
            DoCast(me, SPELL_EVERBURNING_LIGHT_AT, true);
        }
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override {}
};

//122897
struct npc_hasabel_felsilk_web : public ScriptedAI
{
    npc_hasabel_felsilk_web(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
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

    void Reset() override {}

    void UpdateAI(uint32 diff) override {}
};

//244021
class spell_hasabel_bursting_darkness : public SpellScript
{
    PrepareSpellScript(spell_hasabel_bursting_darkness);

    uint32 stack = 0;

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (stack)
            SetHitDamage(GetHitDamage() * stack);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        stack = GetEffectValue();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hasabel_bursting_darkness::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectLaunch += SpellEffectFn(spell_hasabel_bursting_darkness::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};
//247143
class spell_hasabel_energize : public AuraScript
{
    PrepareAuraScript(spell_hasabel_energize);

    uint8 powerTick = 0;
    uint8 powerCount = 0;
    uint8 tickMax = 2;

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        auto caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsInCombat())
            return;

        powerCount = caster->GetPower(POWER_ENERGY);

        if (powerCount < 100)
        {
            if (powerTick < tickMax)
            {
                ++powerTick;
                caster->SetPower(POWER_ENERGY, powerCount + 3);
            }
            else
            {
                if (tickMax == 2)
                    tickMax = 1;
                else
                    tickMax = 2;

                powerTick = 0;
                caster->SetPower(POWER_ENERGY, powerCount + 4);
            }
        }
        else if (!caster->HasUnitState(UNIT_STATE_CASTING) && !caster->AI()->GetData(DATA_COLLAPSING_DELAY))
        {
            powerTick = 3;
            caster->CastSpell(caster, SPELL_COLLAPSING_WORLD, false);
            if (auto hasabel = caster->ToCreature())
                hasabel->AI()->Talk(SAY_COLLAPSING_WORLD);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hasabel_energize::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//244687
class spell_hasabel_transport_portal : public AuraScript
{
    PrepareAuraScript(spell_hasabel_transport_portal);

    uint8 phase = 0;

    void OnApply(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        if (auto owner = GetCaster()->GetOwner())
        {
            if (owner->GetHealthPct() > 60)
                phase = 1;
            else if (owner->GetHealthPct() > 30)
                phase = 2;
            else if (owner->GetHealthPct() > 0)
                phase = 3;
        }
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!GetUnitOwner())
            return;

        if (auto owner = GetUnitOwner()->GetOwner())
        {
            switch (phase)
            {
            case 1:
                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TRANSPORT_BLAZING_IMP, true);
                break;
            case 2:
                if (aurEff->GetTickNumber() == 1 || aurEff->GetTickNumber() == 6)
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TRANSPORT_FELTOUCHED_SKITTERER, true);
                else
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TRANSPORT_BLAZING_IMP, true);
                break;
            case 3:
                if (aurEff->GetTickNumber() == 1)
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TRANSPORT_HUNGERING_STALKER, true);
                else if (aurEff->GetTickNumber() == 6)
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TRANSPORT_FELTOUCHED_SKITTERER, true);
                else
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TRANSPORT_BLAZING_IMP, true);
                break;
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_hasabel_transport_portal::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hasabel_transport_portal::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//244613
class spell_hasabel_everburning_flames : public AuraScript
{
    PrepareAuraScript(spell_hasabel_everburning_flames);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;

        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        if (auto instance = GetTarget()->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_HASABEL) != IN_PROGRESS)
                return;

            if (auto hasabel = instance->instance->GetCreature(instance->GetGuidData(NPC_HASABEL)))
                GetTarget()->CastSpell(GetTarget(), SPELL_EVERBURNING_FLAMES_MISSILE_PLR, true, nullptr, nullptr, hasabel->GetGUID());
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_hasabel_everburning_flames::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//244949
class spell_hasabel_felsilk_wrap : public AuraScript
{
    PrepareAuraScript(spell_hasabel_felsilk_wrap);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!GetCaster() || !GetCaster()->IsAlive())
            aurEff->GetBase()->Remove();

        if (GetUnitOwner() && !(aurEff->GetTickNumber() % 4))
            GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_FELSILK_WRAP_SELF_DMG, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hasabel_felsilk_wrap::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//246316
class spell_hasabel_poison_essence : public AuraScript
{
    PrepareAuraScript(spell_hasabel_poison_essence);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!GetUnitOwner())
            return;

        float amount = GetUnitOwner()->CountPctFromCurHealth(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints);
        const_cast<AuraEffect*>(aurEff)->SetAmount(amount);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hasabel_poison_essence::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

//244915
class spell_hasabel_leech_essence : public AuraScript
{
    PrepareAuraScript(spell_hasabel_leech_essence);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!GetCaster() || !GetUnitOwner())
            return;

        float amount = GetUnitOwner()->CountPctFromCurHealth(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints);
        const_cast<AuraEffect*>(aurEff)->SetAmount(amount);

        GetUnitOwner()->CastSpell(GetCaster(), SPELL_LEECH_ESSENCE_VISUAL, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hasabel_leech_essence::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_LEECH);
    }
};

//245118
class spell_hasabel_cloying_shadows : public AuraScript
{
    PrepareAuraScript(spell_hasabel_cloying_shadows);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;

        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        GetTarget()->CastSpell(GetTarget(), SPELL_HUNGERING_GLOOM, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_hasabel_cloying_shadows::OnRemove, EFFECT_0, SPELL_AURA_MOD_HEALING_PCT, AURA_EFFECT_HANDLE_REAL);
    }
};

//245075
class spell_hasabel_hungering_gloom : public AuraScript
{
    PrepareAuraScript(spell_hasabel_hungering_gloom);

    void OnApply(AuraEffect const* auraEffect, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget() || !GetTarget()->IsPlayer())
            return;

        auraEffect->GetBase()->SetDuration(4000);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_hasabel_hungering_gloom::OnApply, EFFECT_1, SPELL_AURA_MOD_HEALING_PCT, AURA_EFFECT_HANDLE_REAL);
    }
};

//244849
class spell_hasabel_caustic_slime : public AuraScript
{
    PrepareAuraScript(spell_hasabel_caustic_slime);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;

        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        GetTarget()->CastSpell(GetTarget(), SPELL_CAUSTIC_DETONATION, true);
        GetTarget()->CastSpell(GetTarget(), SPELL_CAUSTIC_DETONATION_FILTER, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_hasabel_caustic_slime::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_hasabel()
{
    RegisterCreatureAI(boss_hasabel);
    RegisterCreatureAI(npc_hasabel_gateways);
    RegisterCreatureAI(npc_hasabel_guards);
    RegisterCreatureAI(npc_hasabel_collapsing_world);
    RegisterCreatureAI(npc_hasabel_felcrush_portal);
    RegisterCreatureAI(npc_hasabel_transport_portal);
    RegisterCreatureAI(npc_hasabel_portal_summon);
    RegisterCreatureAI(npc_hasabel_everburning_flames);
    RegisterCreatureAI(npc_hasabel_felsilk_web);
    RegisterSpellScript(spell_hasabel_bursting_darkness);
    RegisterAuraScript(spell_hasabel_energize);
    RegisterAuraScript(spell_hasabel_transport_portal);
    RegisterAuraScript(spell_hasabel_everburning_flames);
    RegisterAuraScript(spell_hasabel_felsilk_wrap);
    RegisterAuraScript(spell_hasabel_poison_essence);
    RegisterAuraScript(spell_hasabel_leech_essence);
    RegisterAuraScript(spell_hasabel_cloying_shadows);
    RegisterAuraScript(spell_hasabel_hungering_gloom);
    RegisterAuraScript(spell_hasabel_caustic_slime);
}
