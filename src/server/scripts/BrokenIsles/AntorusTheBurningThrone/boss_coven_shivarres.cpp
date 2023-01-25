#include "antorus.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    //Asara
    SAY_STORM_OF_DARKNESS = 0,

    //Noura
    SAY_AGGRO = 0,
    SAY_WHIRLING_SABER = 1,

    //Diima
    SAY_ORB_OF_FROST = 0,

    //Thuraya
    SAY_COSMIC_GLARE = 0,

    //Coven
    SAY_TORMENT_OF_GOLGANNETH = 0,
    SAY_TORMENT_OF_KHAZGOROTH = 1,
    SAY_TORMENT_OF_NORGANNON = 2,
};

enum Spells
{
    SPELL_OUTRO_CONV = 250806,
    SPELL_DAILY_ESSENCE_SHIVARRES = 305315,

    SPELL_SHARED_HEALTH = 144224,
    SPELL_SHIVAN_PACT_AT = 253189,
    SPELL_SENSE_OF_DREAD = 253752,
    SPELL_SENSE_OF_DREAD_REMOVE = 253759,
    SPELL_TORMENT_OF_GOLGANNETH = 249793,
    SPELL_TORMENT_OF_KHAZGOROTH = 250333,
    SPELL_TORMENT_OF_NORGANNON = 250334,
    SPELL_TORMENT_OF_AMANTHUL = 250335,

    //Asara
    SPELL_TOUCH_OF_DARKNESS = 245303,
    SPELL_SHADOW_BLADES = 246329,
    SPELL_SHADOW_BLADES_SUMMON = 245281,
    SPELL_SHADOW_BLADES_VISUAL = 258932,
    SPELL_SHADOW_BLADES_AURA = 245290,
    SPELL_STORM_OF_DARKNESS = 252861, //Heroic+
    SPELL_STORM_OF_DARKNESS_AT = 252919,
    SPELL_STORM_OF_DARKNESS_UNK_AT = 254018, //Unk
    SPELL_STORM_OF_DARKNESS_VISUAL_AT = 254574,
    SPELL_STORM_OF_DARKNESS_SAVE_AT = 255232,

    //Noura
    SPELL_FIERY_STRIKE = 244899,
    SPELL_WHIRLING_SABER_FILTER = 246486,
    SPELL_WHIRLING_SABER_AT = 245630,
    SPELL_FULMINATING_PULSE_FILTER = 253429, //Heroic+
    SPELL_FULMINATING_PULSE_AURA = 253520,
    SPELL_FULMINATING_BURST = 253588,

    //Diima
    SPELL_FLASHFREEZE = 245518,
    SPELL_CHILLED_BLOOD_FILTER = 245520,
    SPELL_CHILLED_BLOOD_ABSORB = 245586,
    SPELL_CHILLED_BLOOD_STUN = 256356,
    SPELL_ORB_OF_FROST_FILTER = 253649, //Heroic+
    SPELL_ORB_OF_FROST_AT = 253650,

    //Thuraya
    SPELL_TOUCH_OF_THE_COSMOS = 250648,
    SPELL_COSMIC_GLARE_MARK_FILTER = 250752,
    SPELL_COSMIC_GLARE_MARK = 250755,
    SPELL_COSMIC_GLARE_SCALE = 250757,
    SPELL_COSMIC_GLARE_SEARCH_MARK = 250758,
    SPELL_COSMIC_GLARE_SUMMON = 250763,
    SPELL_COSMIC_GLARE_DMG_FILTER = 250824,
    SPELL_COSMIC_GLARE_DUMMY = 250900,
    SPELL_COSMIC_GLARE_DMG = 250912,

    //Torments
    SPELL_MACHINATIONS_OF_AMANTHUL = 250095,
    SPELL_FURY_OF_GOLGANNETH = 246739,
    SPELL_FURY_OF_GOLGANNETH_FILTER = 246772,
    SPELL_FURY_OF_GOLGANNETH_FILTER_2 = 258065,
    SPELL_FURY_OF_GOLGANNETH_AT = 246763,
    SPELL_FURY_OF_GOLGANNETH_DMG_FILTER = 246769,
    SPELL_FURY_OF_GOLGANNETH_DMG = 246770,
    SPELL_FURY_OF_GOLGANNETH_REMOVE = 258069,
    SPELL_FURY_OF_GOLGANNETH_MARK = 260806,
    SPELL_FLAMES_OF_KHAZGOROTH = 245671,
    SPELL_VISAGE_OF_THE_TITAN = 249863,
    SPELL_SPECTRAL_ARMY_OF_NORGANNON_AT = 245910,
};

enum Events
{
    //Asara
    EVENT_SHADOW_BLADES = 1,
    EVENT_STORM_OF_DARKNESS = 2,

    //Noura
    EVENT_FIERY_STRIKE = 3,
    EVENT_WHIRLING_SABER = 4,
    EVENT_FULMINATING_PULSE = 5, //Heroic+

    //Diima
    EVENT_FLASHFREEZE = 6,
    EVENT_CHILLED_BLOOD = 7,
    EVENT_ORB_OF_FROST = 8,

    //Thuraya
    EVENT_COSMIC_GLARE = 9
};

enum eActions
{
    ACTION_ENCOUNTERS_SUMMON = 1,
    ACTION_ENCOUNTERS_RESTART,
    ACTION_ENCOUNTERS_ENTER_COMBAT,
    ACTION_ENCOUNTERS_SWITCH_BOSS,

    ACTION_TORMENT_SWITCH,
    ACTION_TORMENT_END,
    ACTION_THURAYA_JUMP
};

enum Misc
{
    TORMENT_ASARA = 0,
    TORMENT_NOURA = 1,
    TORMENT_DIIMA = 2,
    TORMENT_THURAYA = 3,

    DATA_TORMENT_STAGE,

    INVISIBLE_MODEL = 27823,
};

uint32 covenEntry[4] =
{
    NPC_ASARA,
    NPC_NOURA,
    NPC_DIIMA,
    NPC_THURAYA
};

uint32 tormentSpellId[4] =
{
    SPELL_TORMENT_OF_KHAZGOROTH,
    SPELL_TORMENT_OF_NORGANNON,
    SPELL_TORMENT_OF_GOLGANNETH,
    SPELL_TORMENT_OF_AMANTHUL
};

Position const covenPos[5] =
{
    {-12626.5f, -2811.43f, 2475.55f, 3.88f}, //Asara
    {-12644.2f, -2819.47f, 2475.56f, 6.19f}, //Noura
    {-12626.4f, -2827.51f, 2475.55f, 2.35f}, //Diima
    {-12641.5f, -2826.68f, 2475.55f, 0.74f}, //Mythic: Thuraya
    {-12642.6f, -2811.89f, 2475.55f, 5.51f}  //Mythic: Noura
};

Position const tormentPos[4] =
{
    {-12663.24f, -2791.05f, 2480.8f, 2.36f}, //Khaz'goroth's Soul
    {-12605.61f, -2791.02f, 2480.8f, 0.73f}, //Norgannon's Soul
    {-12605.71f, -2848.49f, 2480.8f, 5.46f}, //Golganneth's Soul
    {-12662.43f, -2847.72f, 2480.8f, 3.88f}  //Aman'Thul's Soul
};

Position const amanthulPos[4] =
{
    {-12667.2f, -2834.27f, 2475.08f, 0.42f},
    {-12649.5f, -2787.94f, 2475.15f, 5.16f},
    {-12602.6f, -2804.43f, 2475.37f, 3.58f},
    {-12618.8f, -2851.78f, 2475.34f, 2.01f}
};

Position const golgannethPos[4] =
{
    {-12634.49f, -2780.56f, 2475.22f, 4.71f},
    {-12676.59f, -2820.14f, 2475.34f, 0.01f},
    {-12634.44f, -2860.37f, 2475.22f, 1.57f},
    {-12590.45f, -2820.04f, 2475.17f, 3.14f}
};

Position const khazgorothPos[8] =
{
    {-12676.9f, -2820.13f, 2476.93f,  0.0f},
    {-12656.8f, -2842.03f, 2475.54f, 0.80f},
    {-12634.3f, -2859.33f, 2476.88f, 1.57f},
    {-12612.0f, -2842.17f, 2475.54f, 2.31f},
    {-12586.8f, -2819.73f, 2476.91f, 3.13f},
    {-12612.1f, -2797.80f, 2475.54f, 3.95f},
    {-12634.9f, -2781.53f, 2476.91f, 4.72f},
    {-12656.6f, -2797.45f, 2475.54f, 5.48f},
};

Position const norgannonPos[20] =
{
    {-12623.6f, -2780.66f, 2476.1f,  4.70f},
    {-12673.6f, -2829.97f, 2476.13f, 6.22f},
    {-12644.8f, -2780.8f,  2476.1f,  4.70f},
    {-12672.8f, -2819.89f, 2476.12f, 6.22f},
    {-12593.7f, -2809.54f, 2476.12f, 3.12f},
    {-12634.3f, -2781.25f, 2476.1f,  4.70f},
    {-12594.2f, -2819.78f, 2476.11f, 3.12f},
    {-12592.7f, -2800.43f, 2476.11f, 3.12f},
    {-12634.7f, -2858.38f, 2476.08f, 1.56f},
    {-12614.1f, -2859.72f, 2476.07f, 1.56f},
    {-12592.7f, -2840.41f, 2476.11f, 3.12f},
    {-12673.5f, -2839.49f, 2476.13f, 6.22f},
    {-12654.7f, -2860.16f, 2476.11f, 1.56f},
    {-12654.9f, -2779.8f,  2476.1f,  4.70f},
    {-12593.7f, -2830.61f, 2476.12f, 3.12f},
    {-12673.5f, -2799.74f, 2476.12f, 6.22f},
    {-12645.1f, -2859.03f, 2476.1f,  1.56f},
    {-12614.0f, -2779.59f, 2476.1f,  4.70f},
    {-12672.9f, -2809.39f, 2476.12f, 6.22f},
    {-12624.0f, -2858.77f, 2476.07f, 1.56f}
};

//128311
struct boss_coven_shivarres : BossAI
{
    explicit boss_coven_shivarres(Creature* creature) : BossAI(creature, DATA_COVEN)
    {
        if (me->IsAlive())
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(27823);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);
            AddDelayedEvent(500, [=]() -> void { DoAction(ACTION_ENCOUNTERS_SUMMON); });
            if (IsMythicRaid())
            {
                bossCount = 4;
                tormentQueueId = { TORMENT_DIIMA, TORMENT_THURAYA, TORMENT_NOURA, TORMENT_ASARA };
            }
            else
            {
                bossCount = 3;
                tormentQueueId = { TORMENT_DIIMA, TORMENT_NOURA, TORMENT_ASARA };
            }
        }
    }

    std::vector<ObjectGuid> covenVector;
    std::vector<uint8> tormentQueueId;
    std::list<uint8> randList;
    uint8 bossCount = 0;
    uint8 stage = 0;
    int8 tempTormentId = 0;
    uint32 thurayaActivateTimer = 0;

    void Reset() override
    {
        _Reset();
    }

    void DoAction(int32 const action) override
    {
        if (instance->GetBossState(DATA_COVEN) == DONE)
            return;

        switch (action)
        {
        case ACTION_ENCOUNTERS_SUMMON:
        {
            covenVector.clear();
            tormentQueueId.clear();
            randList.clear();
            stage = 0;
            tempTormentId = -1;

            for (uint8 i = 0; i < bossCount; ++i)
            {
                if (IsMythicRaid() && i == 1) //Swap spawn cord Noura
                {
                    if (auto coven = me->SummonCreature(covenEntry[i], covenPos[4]))
                        covenVector.push_back(coven->GetGUID());
                }
                else if (auto coven = me->SummonCreature(covenEntry[i], covenPos[i]))
                    covenVector.push_back(coven->GetGUID());
            }
            break;
        }
        case ACTION_ENCOUNTERS_RESTART:
        {
            if (instance->GetBossState(DATA_COVEN) != NOT_STARTED)
            {
                instance->SetBossState(DATA_COVEN, NOT_STARTED);

                if (auto asara = Creature::GetCreature(*me, covenVector[0]))
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, asara);

                if (auto diima = Creature::GetCreature(*me, covenVector[2]))
                    diima->RemoveAreaTrigger(SPELL_ORB_OF_FROST_AT);

                RemoveDebuffs();
                events.Reset();
                summons.DespawnAll();
                me->RemoveAllAreaObjects();
                AddDelayedEvent(5000, [=]() -> void { DoAction(ACTION_ENCOUNTERS_SUMMON); });
            }
            break;
        }
        case ACTION_ENCOUNTERS_ENTER_COMBAT:
        {
            if (instance->GetBossState(DATA_COVEN) != IN_PROGRESS)
            {
                instance->SetBossState(DATA_COVEN, IN_PROGRESS);

                if (auto asara = Creature::GetCreature(*me, covenVector[0]))
            //        instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_START, asara);

                for (uint8 i = 0; i < bossCount; ++i)
                {
                    if (auto coven = Creature::GetCreature(*me, covenVector[i]))
                    {
                        coven->CastSpell(coven, SPELL_SHARED_HEALTH, true);
                        coven->CastSpell(coven, SPELL_SHIVAN_PACT_AT, true);

                        if (coven->IsAlive() && !coven->IsInCombat())
                            coven->AI()->DoZoneInCombat(coven, 100.0f);
                    }
                }

                DoAction(ACTION_ENCOUNTERS_SWITCH_BOSS);

                if (IsMythicRaid())
                    thurayaActivateTimer = 45000;
            }
            break;
        }
        case ACTION_ENCOUNTERS_SWITCH_BOSS:
        {
            if (auto boss = Creature::GetCreature(*me, covenVector[tormentQueueId[stage]]))
                boss->AI()->DoAction(GetGenerateTorment());

            stage = stage < bossCount ? stage + 1 : 0;
            break;
        }
        case SPELL_TORMENT_OF_AMANTHUL:
        {
            for (uint8 i = 0; i < 4; ++i)
                me->SummonCreature(NPC_TORMENT_OF_AMANTHUL, amanthulPos[i], TEMPSUMMON_DEAD_DESPAWN);
            break;
        }
        case SPELL_TORMENT_OF_GOLGANNETH:
        {
            for (uint8 i = 0; i < 4; ++i)
                me->SummonCreature(NPC_TORMENT_OF_GOLGANNETH, golgannethPos[i], TEMPSUMMON_DEAD_DESPAWN);
            Talk(SAY_TORMENT_OF_GOLGANNETH);
            break;
        }
        case SPELL_TORMENT_OF_KHAZGOROTH:
        {
            for (uint8 i = 0; i < 8; ++i)
                me->SummonCreature(NPC_TORMENT_OF_KHAZGOROTH, khazgorothPos[i], TEMPSUMMON_DEAD_DESPAWN);
            Talk(SAY_TORMENT_OF_KHAZGOROTH);
            break;
        }
        case SPELL_TORMENT_OF_NORGANNON:
        {
            for (uint8 i = 0; i < 20; ++i)
                me->SummonCreature(NPC_TORMENT_OF_NORGANNON, norgannonPos[i], TEMPSUMMON_DEAD_DESPAWN);
            Talk(SAY_TORMENT_OF_NORGANNON);
            break;
        }
        }
    }

    uint8 GetGenerateTorment()
    {
        if (randList.empty())
            randList = { 0, 1, 2, 3 };

        uint8 tormentId = 0;

        if (IsMythicRaid())
        {
            tormentId = randList.front();
            randList.remove(tormentId);
            return tormentId;
        }

        tormentId = Trinity::Containers::SelectRandomContainerElement(randList);

        if (tempTormentId != tormentId)
        {
            tempTormentId = tormentId;
            randList.remove(tormentId);
        }
        else
        {
            while (tempTormentId == tormentId)
            {
                tormentId = Trinity::Containers::SelectRandomContainerElement(randList);
            }
            tempTormentId = tormentId;
            randList.remove(tormentId);
        }

        return tormentId;
    }

    void RemoveDebuffs()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FURY_OF_GOLGANNETH_AT);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FURY_OF_GOLGANNETH_MARK);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_ASARA:
        case NPC_NOURA:
        case NPC_DIIMA:
        case NPC_THURAYA:
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);

            if (instance->GetBossState(DATA_COVEN) != DONE)
            {
                instance->SetBossState(DATA_COVEN, DONE);

                if (auto asara = Creature::GetCreature(*me, covenVector[0]))
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, asara);

                instance->DoOnPlayers([](Player* player)
                {
                    player->CastSpell(player, SPELL_DAILY_ESSENCE_SHIVARRES, true);
                });

                RemoveDebuffs();
                summons.DespawnEntry(NPC_TORMENT_OF_NORGANNON);
                summons.DespawnEntry(NPC_TORMENT_OF_GOLGANNETH);
                summons.DespawnEntry(NPC_TORMENT_OF_KHAZGOROTH);
                summons.DespawnEntry(NPC_TORMENT_OF_AMANTHUL);
                me->DespawnOrUnsummon();
            }
            break;
        }
        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (thurayaActivateTimer)
        {
            if (thurayaActivateTimer <= diff)
            {
                thurayaActivateTimer = 0;
                DoAction(ACTION_ENCOUNTERS_SWITCH_BOSS);
            }
            else
                thurayaActivateTimer -= diff;
        }
    }
};

//122467, 122468, 122469, 125436
struct boss_coven_shivarres_generic : ScriptedAI
{
    explicit boss_coven_shivarres_generic(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();

        if (me->GetEntry() == NPC_DIIMA || me->GetEntry() == NPC_THURAYA)
            me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    EventMap events;
    ObjectGuid cosmicGlareGUID;
    bool startTorment = false;
    bool lastTorment = false;
    bool castPause = false;

    void IsSummonedBy(Unit* summoner) override {}

    void Reset() override {}

    void JustEngagedWith(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_ENCOUNTERS_ENTER_COMBAT);

        if (me->GetEntry() == NPC_ASARA || me->GetEntry() == NPC_NOURA)
            DefaultEvents(true);

        if (me->GetEntry() == NPC_THURAYA)
        {
            AddDelayedCombat(2000, [this]() -> void
            {
                me->SetDisableGravity(true);
                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAllAuras();
                me->GetMotionMaster()->MoveJump(-12584.68f, -2819.42f, 2498.038f, 25.0f, 15.0f, ACTION_THURAYA_JUMP, 3.15f);
            });
        }
    }

    void EnterEvadeMode(EvadeReason w) 
    {
        ScriptedAI::EnterEvadeMode();

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(ACTION_ENCOUNTERS_RESTART);
    }

    void JustDied(Unit* killer) override {}

    void DefaultEvents(bool JustEngagedWith = false)
    {
        switch (me->GetEntry())
        {
        case NPC_ASARA:
            events.RescheduleEvent(EVENT_SHADOW_BLADES, 12000);
            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_STORM_OF_DARKNESS, 29000);
            break;
        case NPC_NOURA:
            if (JustEngagedWith)
                Talk(SAY_AGGRO);
            events.RescheduleEvent(EVENT_FIERY_STRIKE, 11000);
            events.RescheduleEvent(EVENT_WHIRLING_SABER, 8500);
            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_FULMINATING_PULSE, 20500);
            break;
        case NPC_DIIMA:
            events.RescheduleEvent(EVENT_FLASHFREEZE, 11000);
            events.RescheduleEvent(EVENT_CHILLED_BLOOD, 7000);
            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_ORB_OF_FROST, 30000);
            break;
        case NPC_THURAYA:
            events.RescheduleEvent(EVENT_COSMIC_GLARE, 5000);
            break;
        }
    }

    void DoAction(int32 const actionId) override
    {
        if (actionId >= 0 && actionId < 4)
        {
            if (!startTorment)
            {
                startTorment = true;
                events.Reset();
                me->AttackStop();

                AddDelayedCombat(100, [this]() -> void { me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE); });

                AddDelayedCombat(2000, [this]() -> void
                {
                    //me->SetAnimTier(3);
                    me->SetDisableGravity(true);
                    //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAllAuras();
                });
            }

            AddDelayedCombat(3000, [this, actionId]() -> void
            {
                me->GetMotionMaster()->MoveJump(tormentPos[actionId], 25.0f, 15.0f, actionId, tormentPos[actionId].GetOrientation());
            });
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        switch (id)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            //me->SetAnimTier(0);
            me->CastSpell(me, SPELL_SENSE_OF_DREAD, true);
            me->CastSpell(me, tormentSpellId[id], false);
            //DEBUG!!!
            //me->AddDelayedCombat(5000, [this] () -> void { me->InterruptNonMeleeSpells(false); });
            break;
        case ACTION_TORMENT_END:
            me->SetDisableGravity(false);
            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            DefaultEvents();
            break;
        }
    }
    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_SHADOW_BLADES)
        {
            if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                me->SetFacingToObject(target);

            auto owner = me->GetOwner();
            if (!owner)
                return;

            Position pos;
            float angle = -0.15f;

            for (uint8 i = 0; i < 3; ++i)
            {
                me->GetNearPosition(0.1f, angle);
                me->CastSpell(pos, SPELL_SHADOW_BLADES_SUMMON, true);
                angle += 0.15f;
            }
            AddDelayedCombat(1000, [this]() -> void
            {
                castPause = false;
                me->SetReactState(REACT_AGGRESSIVE);
            });
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_COSMIC_GLARE_SEARCH_MARK && cosmicGlareGUID.IsEmpty())
        {
            cosmicGlareGUID = target->GetGUID();
            me->CastSpell(target, SPELL_COSMIC_GLARE_SUMMON, true);
        }
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply || !me->IsInCombat() || instance->GetBossState(DATA_COVEN) != IN_PROGRESS)
            return;

        switch (spellId)
        {
        case SPELL_STORM_OF_DARKNESS:
        {
            if (auto owner = me->GetOwner())
            {
                owner->CastSpell(owner, SPELL_STORM_OF_DARKNESS_VISUAL_AT, true);
                me->CastSpell(owner, SPELL_STORM_OF_DARKNESS_AT, true);

                std::list<Position> randPos;
                //me->GenerateNonDuplicatePoints(randPos, owner->GetPosition(), 6, 10.0f, 40.0f, 12.0f);

                for (auto pos : randPos)
                    me->CastSpell(pos, SPELL_STORM_OF_DARKNESS_SAVE_AT, true);
            }
            break;
        }
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (!me->IsInCombat() || instance->GetBossState(DATA_COVEN) != IN_PROGRESS)
            return;

        switch (spellId)
        {
        case SPELL_TORMENT_OF_GOLGANNETH:
        case SPELL_TORMENT_OF_KHAZGOROTH:
        case SPELL_TORMENT_OF_NORGANNON:
        case SPELL_TORMENT_OF_AMANTHUL:
            me->RemoveAurasDueToSpell(SPELL_SENSE_OF_DREAD);
            me->CastSpell(me, SPELL_SENSE_OF_DREAD_REMOVE, true);
            if (auto summoner = me->GetOwner())
            {
                summoner->GetAI()->DoAction(spellId);

                if (!lastTorment)
                {
                    lastTorment = true;
                    //DoAction(summoner->GetAI()->GetModifyedData(DATA_TORMENT_STAGE));
                }
                else
                {
                    lastTorment = false;
                    startTorment = false;

                    if (auto summoner = me->GetOwner())
                        summoner->GetAI()->DoAction(ACTION_ENCOUNTERS_SWITCH_BOSS);

                    AddDelayedCombat(2000, [this]() -> void
                    {
                        me->GetMotionMaster()->MoveJump(-12634.5f, -2819.86f, 2475.45f, 25.0f, 15.0f, ACTION_TORMENT_END);
                    });
                }
            }
            break;
        case SPELL_FULMINATING_PULSE_AURA:
            if (mode == AURA_REMOVE_BY_EXPIRE)
                target->CastSpell(target, SPELL_FULMINATING_BURST, true);
            break;
        case SPELL_COSMIC_GLARE_SCALE:
            if (mode == AURA_REMOVE_BY_EXPIRE)
                DoCast(me, SPELL_COSMIC_GLARE_SEARCH_MARK, true);
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
            case EVENT_FIERY_STRIKE:
                me->CastSpell(me->GetVictim(), SPELL_FIERY_STRIKE);
                events.RescheduleEvent(EVENT_FIERY_STRIKE, 11000);
                break;
            case EVENT_WHIRLING_SABER:
                Talk(SAY_WHIRLING_SABER);
                DoCast(SPELL_WHIRLING_SABER_FILTER);
                events.RescheduleEvent(EVENT_WHIRLING_SABER, urandms(35, 37));
                break;
            case EVENT_FULMINATING_PULSE:
                DoCast(SPELL_FULMINATING_PULSE_FILTER);
                events.RescheduleEvent(EVENT_FULMINATING_PULSE, 40000);
                break;
            case EVENT_SHADOW_BLADES:
                me->AttackStop();
                castPause = true;
                DoCast(SPELL_SHADOW_BLADES);
                events.RescheduleEvent(EVENT_SHADOW_BLADES, 28000);
                break;
            case EVENT_STORM_OF_DARKNESS:
                Talk(SAY_STORM_OF_DARKNESS);
                DoCast(SPELL_STORM_OF_DARKNESS);
                events.RescheduleEvent(EVENT_STORM_OF_DARKNESS, 59000);
                break;
            case EVENT_FLASHFREEZE:
                me->CastSpell(me->GetVictim(), SPELL_FLASHFREEZE);
                events.RescheduleEvent(EVENT_FLASHFREEZE, 11000);
                break;
            case EVENT_CHILLED_BLOOD:
                DoCast(SPELL_CHILLED_BLOOD_FILTER);
                events.RescheduleEvent(EVENT_CHILLED_BLOOD, 26000);
                break;
            case EVENT_ORB_OF_FROST:
                Talk(SAY_ORB_OF_FROST);
                DoCast(SPELL_ORB_OF_FROST_FILTER);
                events.RescheduleEvent(EVENT_ORB_OF_FROST, 30000);
                break;
            case EVENT_COSMIC_GLARE:
                cosmicGlareGUID.Clear();
                Talk(SAY_COSMIC_GLARE);
                DoCast(SPELL_COSMIC_GLARE_MARK_FILTER);
                events.RescheduleEvent(EVENT_COSMIC_GLARE, 15000);
                break;
            }
        }

        if (castPause)
            return;

        if (me->GetEntry() == NPC_ASARA)
            DoSpellAttackIfReady(SPELL_TOUCH_OF_DARKNESS);
        else if (me->GetEntry() == NPC_THURAYA)
            DoSpellAttackIfReady(SPELL_TOUCH_OF_THE_COSMOS);
        else
            DoMeleeAttackIfReady();
    }
};

//125837, 123503, 124164, 124166
struct npc_coven_torment_generic : ScriptedAI
{
    explicit npc_coven_torment_generic(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    bool norgannonActive = false;
    uint32 norgannonStartTimer = 0;
    Position pos;

    void IsSummonedBy(Unit* summoner) override
    {
        switch (me->GetEntry())
        {
        case NPC_TORMENT_OF_AMANTHUL:
            me->CastSpell(me, SPELL_MACHINATIONS_OF_AMANTHUL, false);
            break;
        case NPC_TORMENT_OF_GOLGANNETH:
            me->CastSpell(me, SPELL_FURY_OF_GOLGANNETH, false);
            me->CastSpell(me, SPELL_FURY_OF_GOLGANNETH_FILTER, true);
            me->CastSpell(me, SPELL_FURY_OF_GOLGANNETH_FILTER_2, true);
            break;
        case NPC_TORMENT_OF_KHAZGOROTH:
            me->CastSpell(me, SPELL_FLAMES_OF_KHAZGOROTH, false);
            break;
        case NPC_TORMENT_OF_NORGANNON:
        {
            me->SetSpeed(MOVE_RUN, 0.25f);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
            me->CastSpell(me, SPELL_VISAGE_OF_THE_TITAN, true);
            me->CastSpell(me, SPELL_SPECTRAL_ARMY_OF_NORGANNON_AT, true);
            norgannonStartTimer = 3000;
            break;
        }
        }
    }

    void Reset() override {}

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetEntry() == NPC_TORMENT_OF_GOLGANNETH)
            me->CastSpell(me, SPELL_FURY_OF_GOLGANNETH_REMOVE, true);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FURY_OF_GOLGANNETH_DMG_FILTER)
            me->CastSpell(caster, SPELL_FURY_OF_GOLGANNETH_DMG, true);
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_MACHINATIONS_OF_AMANTHUL)
            me->CastSpell(me, SPELL_MACHINATIONS_OF_AMANTHUL, false);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || id != 1)
            return;

        if (me->GetEntry() != NPC_TORMENT_OF_NORGANNON)
            return;

        if (me->GetDistance(pos) <= 1.0f)
            me->DespawnOrUnsummon();
        else if (!norgannonStartTimer)
            norgannonStartTimer = 500;
    }

    void UpdateAI(uint32 diff) override
    {
        if (norgannonStartTimer)
        {
            if (norgannonStartTimer <= diff)
            {
                norgannonStartTimer = 0;

                if (!norgannonActive)
                {
                    norgannonActive = true;
                    //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                    //e->GetNearPoint2D(pos, 80.0f, 0.0f);
                }
                me->GetMotionMaster()->MovePoint(1, pos, false);
            }
            else
                norgannonStartTimer -= diff;
        }
    }
};

//123348
struct npc_coven_whirling_saber : ScriptedAI
{
    explicit npc_coven_whirling_saber(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    uint32 moveTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_WHIRLING_SABER_AT, true);
        moveTimer = 2000;
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override
    {
        if (moveTimer)
        {
            if (moveTimer <= diff)
            {
                moveTimer = 800;

                if (instance->GetBossState(DATA_COVEN) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (auto owner = me->GetOwner())
                {
                    if (me->GetDistance(owner) < 1.0f)
                        me->DespawnOrUnsummon();
                    else
                        me->GetMotionMaster()->MovePoint(1, owner->GetPosition(), false);
                }
            }
            else
                moveTimer -= diff;
        }
    }
};

//123086
struct npc_coven_shadow_blade : ScriptedAI
{
    explicit npc_coven_shadow_blade(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    uint32 startTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_SHADOW_BLADES_VISUAL, true);
        startTimer = 3000;
    }

    void Reset() override {}

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || id != 1)
            return;

        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (startTimer)
        {
            if (startTimer <= diff)
            {
                startTimer = 0;
                Position pos;
                //me->GetNearPoint2D(80.0f, 0.0f);
                me->GetMotionMaster()->MovePoint(1, pos, false);
                DoCast(me, SPELL_SHADOW_BLADES_AURA, true);
            }
            else
                startTimer -= diff;
        }
    }
};

//126320
struct npc_coven_cosmic_glare : ScriptedAI
{
    explicit npc_coven_cosmic_glare(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_COSMIC_GLARE_DMG_FILTER, true);
    }

    void Reset() override {}

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_COSMIC_GLARE_DMG_FILTER)
        {
            me->CastSpell(target, SPELL_COSMIC_GLARE_DUMMY, true);
            Position pos;
            float dist = 5.5f;
            float angle = me->GetRelativeAngle(target);

            for (uint8 i = 0; i < 12; ++i)
            {
                me->GetNearPosition(dist, angle);
                me->CastSpell(pos, SPELL_COSMIC_GLARE_DMG, true);
                dist += 5.5f;
            }
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//258069
class spell_coven_fury_subsides : public SpellScript
{
    PrepareSpellScript(spell_coven_fury_subsides);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_0);

        if (!GetHitUnit())
            return;

        if (auto aura = GetHitUnit()->GetAura(SPELL_FURY_OF_GOLGANNETH_MARK))
            aura->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_coven_fury_subsides::HandleScript, EFFECT_0, SPELL_EFFECT_REMOVE_AURA);
    }
};

//250752
class spell_coven_cosmic_glare : public SpellScript
{
    PrepareSpellScript(spell_coven_cosmic_glare);

    std::list<WorldObject*> tempList;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!tempList.empty())
        {
            targets = tempList;
            return;
        }

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            return false;
        });

        if (targets.size() < 2)
        {
            targets.clear();
            return;
        }

        Trinity::Containers::RandomResize(targets, 2);
        tempList.push_back(targets.front());
        targets.pop_front();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coven_cosmic_glare::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coven_cosmic_glare::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//250824
class spell_coven_cosmic_glare_dmg : public SpellScript
{
    PrepareSpellScript(spell_coven_cosmic_glare_dmg);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        auto owner = GetCaster()->GetOwner();
        if (!owner)
            return;

        ObjectGuid guid = owner->GetAI()->GetGUID(true);

        if (guid.IsEmpty())
        {
            targets.clear();
            return;
        }

        targets.remove_if([guid](WorldObject* object) -> bool
        {
            if (object == nullptr || object->GetGUID() == guid || !object->ToUnit()->HasAura(SPELL_COSMIC_GLARE_MARK))
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coven_cosmic_glare_dmg::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//245586
class spell_coven_chilled_blood : public AuraScript
{
    PrepareAuraScript(spell_coven_chilled_blood);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();

        if (!GetTarget() || mode != AURA_REMOVE_BY_EXPIRE || !aurEff->GetAmount())
            return;

        float pct = (aurEff->GetAmount() / aurEff->GetBaseAmount()) * 100.0f;
        uint32 duration = CalculatePct(12000, pct);
        GetTarget()->CastSpell(GetTarget(), SPELL_CHILLED_BLOOD_STUN, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_coven_chilled_blood::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

//253697
class spell_coven_orb_of_frost : public AuraScript
{
    PrepareAuraScript(spell_coven_orb_of_frost);

    void OnTick(AuraEffect const* /*auraEffect*/)
    {
        if (!GetCaster() || !GetUnitOwner())
            return;

        auto at = GetCaster()->GetAreaTrigger(SPELL_ORB_OF_FROST_AT);
        if (!at)
            return;

        float dist = 0.0f;

        if (dist > 40.0f)
            dist = 40.0f;

        float pct = 100 - ((dist / 40.0f) * 100.0f);
        float speedAmount = CalculatePct(85, pct);

        if (auto auraEff = GetTarget()->GetAuraEffect(GetId(), EFFECT_0))
            auraEff->ChangeAmount(speedAmount);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_coven_orb_of_frost::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};


void AddSC_boss_coven_shivarres()
{
    RegisterCreatureAI(boss_coven_shivarres);
    RegisterCreatureAI(boss_coven_shivarres_generic);
    RegisterCreatureAI(npc_coven_torment_generic);
    RegisterCreatureAI(npc_coven_whirling_saber);
    RegisterCreatureAI(npc_coven_shadow_blade);
    RegisterCreatureAI(npc_coven_cosmic_glare);
    RegisterSpellScript(spell_coven_fury_subsides);
    RegisterSpellScript(spell_coven_cosmic_glare);
    RegisterSpellScript(spell_coven_cosmic_glare_dmg);
    RegisterAuraScript(spell_coven_chilled_blood);
    RegisterAuraScript(spell_coven_orb_of_frost);
}
