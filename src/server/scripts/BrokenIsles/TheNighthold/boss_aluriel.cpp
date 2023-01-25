#include "thenighthold.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_ANNIHILATE = 1,
    SAY_MARK_OF_FROST = 2,
    SAY_REPLICATION = 3,
    SAY_DETONATE = 4,
    SAY_ANIMATE = 5,
    SAY_KILL = 6,
    SAY_MARK = 7,
    SAY_DEATH = 8
};

enum Spells
{
    SPELL_ICY_ENCHANTMENT = 213864,
    SPELL_FIERY_ENCHANTMENT = 213867,
    SPELL_MAGIC_ENCHANTMENT = 213869,
    SPELL_ANNIHILATE = 212492,
    SPELL_ANNIHILATE_DEBUFF = 215458,
    SPELL_BERSERK = 26662,
    SPELL_FEL_SOUL = 230901, //Mythic

    //Mythic: Fel Soul
    SPELL_SEVERED_SOUL = 230951,
    SPELL_SEVERED_SOUL_MOD_DMG = 230981,
    SPELL_DECIMATE = 230504,
    //Frost Phase
    SPELL_WHIRLING_BARRAGE = 230416,
    SPELL_WHIRLING_BARRAGE_FIXATE = 230418,
    //Fire Phase
    SPELL_FEL_STOMP_FILTER = 230411,
    SPELL_FEL_STOMP_JUMP = 230413,
    SPELL_FEL_STOMP_AT = 230412, //Dmg 230414
    //Arcane Phase
    SPELL_FEL_LASH = 230403,

    //Frost
    SPELL_REPLICATE_MARK_OF_FROST = 212530,
    SPELL_FROSTBITTEN = 212647,
    SPELL_MARK_OF_FROST_FILTER = 212646,
    SPELL_MARK_OF_FROST = 212587,
    SPELL_MARK_OF_FROST_FIXATE = 212531,
    SPELL_MARK_OF_FROST_EXPLOSION = 212648,
    SPELL_MARK_OF_FROST_KNOCK = 212649,
    SPELL_MARK_OF_FROST_FILTER_PLR = 220104,
    SPELL_MARK_OF_FROST_SEARCHER = 233195,
    SPELL_MARK_OF_FROST_SEARCHER_AT = 212738, //On Player
    SPELL_DETONATE_MARK_OF_FROST = 212735, //Filter
    SPELL_DETONATE_MARK_OF_FROST_AT = 212734,
    SPELL_ANIMATE_MARK_OF_FROST = 213853,
    SPELL_FROZEN_TEMPEST_FILTER = 214191, //Heroic+

    //Icy Enchantment
    SPELL_BURST_OF_ICE = 213796,
    SPELL_FROZEN_TEMPEST_TP_FILTER = 213131, //Heroic+
    SPELL_FROZEN_TEMPEST_TP = 213130, //Heroic+
    SPELL_ENTOMBED_IN_ICE = 213621, //Heroic+
    SPELL_ENTOMBED_IN_ICE_SELF = 213622, //Heroic+

    //Fire
    SPELL_SEARING_BRAND_FILTER = 213145,
    SPELL_SEARING_BRAND_MARK = 213148,
    SPELL_SEARING_BRAND_CHARGE_TIMER = 213152,
    SPELL_SEARING_BRAND_CHARGE = 213157,
    SPELL_SEARING_BRAND_AT = 213179, //Dmg 233098
    SPELL_SEARING_BRAND_DOT = 213181,
    SPELL_REPLICATE_SEARING_BRAND = 213182,
    SPELL_SEARING_BRAND_CHARGE_IMAGE = 213227,
    SPELL_DETONATE_SEARING_BRAND = 213275, //Filter
    SPELL_DETONATE_SEARING_BRAND_AT = 213276,
    SPELL_ANIMATE_SEARING_BRAND = 213567,

    //Fiery Enchantment
    SPELL_BURST_OF_FLAME = 213760,
    SPELL_DISSIPATION = 214369, //Despawn Image
    SPELL_BOUND_IN_FLAME_FILTER = 216257, //Heroic+
    SPELL_BOUND_IN_FLAME = 216256, //Heroic+
    SPELL_PYROBLAST = 213281, //Heroic+

    //Arcane
    SPELL_ARCANE_ORB_FILTER = 215455,
    SPELL_REPLICATE_ARCANE_ORB_FILTER = 213852,
    SPELL_DETONATE_ARCANE_ORB = 213390,
    SPELL_ANIMATE_ARCANE_ORB = 213564,

    //Arcane Enchantment
    SPELL_BURST_ARCANE_ORB = 213519,
    SPELL_ARCANE_ORB_SEARCH_PLR = 215456,
    SPELL_ARCANE_ORB_AT = 213377,
    SPELL_ARCANE_ORB_VISUAL = 213476,
    SPELL_ARCANE_ORB_MISSILE = 213326,
    SPELL_ARCANE_ORB_AT_2 = 213328,
    SPELL_ARMAGEDDON = 213569, //Heroic+
    SPELL_BURST_OF_MAGIC = 213808,
};

enum eEvents
{
    EVENT_ANNIHILATE = 1,
    EVENT_MARK_OF_FROST = 2,
    EVENT_REPLICATE_FROST = 3,
    EVENT_DETONATE_FROST = 4,
    EVENT_ANIMATE_FROST = 5,
    EVENT_SEARING_BRAND = 6,
    EVENT_REPLICATE_SEARING_BRAND = 7,
    EVENT_REPLICATE_SEARING_BRAND_2 = 8,
    EVENT_DETONATE_FIRE = 9,
    EVENT_ANIMATE_FIRE = 10,
    EVENT_ARCANE_ORB = 11,
    EVENT_REPLICATE_ARCANE_ORB = 12,
    EVENT_DETONATE_ARCANE_ORB = 13,
    EVENT_ANIMATE_ARCANE = 14,
    EVENT_ANIMATE_DESPAWN = 15,

    //Heroic+
    EVENT_FROZEN_TEMPEST_FILTER = 16,

    //Mythic
    EVENT_SUM_FEL_SOUL = 17,
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_6,
    EVENT_5,
    EVENT_7,
};
Position const centerPos = { 391.88f, 3246.40f, 150.45f };

//104881
class boss_spellblade_aluriel : public CreatureScript
{
public:
    boss_spellblade_aluriel() : CreatureScript("boss_spellblade_aluriel") {}

    struct boss_spellblade_alurielAI : BossAI
    {
        boss_spellblade_alurielAI(Creature* creature) : BossAI(creature, DATA_ALURIEL), berserkTimer(0)
        {
            me->SetMaxPower(POWER_MANA, 85);
        }

        std::list<ObjectGuid> playerListGUID;
        uint32 berserkTimer;

        void Reset() override
        {
            if (IsMythicRaid())
                berserkTimer = 450 * IN_MILLISECONDS;
            else if (IsHeroicRaid())
                berserkTimer = 480 * IN_MILLISECONDS;
            else
                berserkTimer = 600 * IN_MILLISECONDS;

            me->SetPower(POWER_MANA, 85);
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveAurasDueToSpell(SPELL_ICY_ENCHANTMENT);
            me->RemoveAurasDueToSpell(SPELL_FIERY_ENCHANTMENT);
            me->RemoveAurasDueToSpell(SPELL_MAGIC_ENCHANTMENT);
            RemoveAuras();
            me->GetMotionMaster()->MovePath(9100417, true);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            DefaultEvents(SPELL_ICY_ENCHANTMENT);
        }

        void DefaultEvents(uint32 phase)
        {
            events.Reset();

            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_FROZEN_TEMPEST_FILTER, 16000);

            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_SUM_FEL_SOUL, 18000);

            if (IsMythicRaid() && phase == SPELL_MAGIC_ENCHANTMENT)
                events.RescheduleEvent(EVENT_ANNIHILATE, 5000);
            else
                events.RescheduleEvent(EVENT_ANNIHILATE, 7000);

            switch (phase)
            {
            case SPELL_ICY_ENCHANTMENT:
                DoCast(me, SPELL_ICY_ENCHANTMENT, true);
                events.RescheduleEvent(EVENT_MARK_OF_FROST, 18000);
                if (IsMythicRaid())
                {
                    events.RescheduleEvent(EVENT_REPLICATE_FROST, 28000);
                    events.RescheduleEvent(EVENT_DETONATE_FROST, 48000);
                    events.RescheduleEvent(EVENT_ANIMATE_FROST, 65000);
                }
                else
                {
                    events.RescheduleEvent(EVENT_REPLICATE_FROST, 38000);
                    events.RescheduleEvent(EVENT_DETONATE_FROST, 68000);
                    events.RescheduleEvent(EVENT_ANIMATE_FROST, 75000);
                }
                break;
            case SPELL_FIERY_ENCHANTMENT:
                DoCast(me, SPELL_FIERY_ENCHANTMENT, true);
                events.RescheduleEvent(EVENT_SEARING_BRAND, 18000);
                events.RescheduleEvent(EVENT_REPLICATE_SEARING_BRAND, 26000);
                if (IsMythicRaid())
                {
                    events.RescheduleEvent(EVENT_DETONATE_FIRE, 38000);
                    events.RescheduleEvent(EVENT_ANIMATE_FIRE, 54000);
                }
                else
                {
                    events.RescheduleEvent(EVENT_DETONATE_FIRE, 45000);
                    events.RescheduleEvent(EVENT_ANIMATE_FIRE, 62000);
                }
                break;
            case SPELL_MAGIC_ENCHANTMENT:
                DoCast(me, SPELL_MAGIC_ENCHANTMENT, true);
                events.RescheduleEvent(EVENT_ARCANE_ORB, 1000);
                events.RescheduleEvent(EVENT_REPLICATE_ARCANE_ORB, 15000);
                events.RescheduleEvent(EVENT_DETONATE_ARCANE_ORB, 35000);
                events.RescheduleEvent(EVENT_ANIMATE_ARCANE, 52000);
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            RemoveAuras();
        }

        void RemoveAuraSpellId(uint32 spellId)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->HasAura(spellId))
                        player->RemoveAura(spellId);
        }

        void RemoveAuras()
        {
            RemoveAuraSpellId(SPELL_MARK_OF_FROST);
            RemoveAuraSpellId(SPELL_MARK_OF_FROST_FIXATE);
            RemoveAuraSpellId(SPELL_REPLICATE_MARK_OF_FROST);
            RemoveAuraSpellId(SPELL_SEARING_BRAND_MARK);
            RemoveAuraSpellId(SPELL_SEARING_BRAND_DOT);
        }

        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
        {
            if (!me->IsInCombat() || mode != AURA_REMOVE_BY_EXPIRE)
                return;

            if (!apply)
            {
                switch (spellId)
                {
                case SPELL_ICY_ENCHANTMENT:
                    DefaultEvents(SPELL_FIERY_ENCHANTMENT);
                    break;
                case SPELL_FIERY_ENCHANTMENT:
                    DefaultEvents(SPELL_MAGIC_ENCHANTMENT);
                    break;
                case SPELL_MAGIC_ENCHANTMENT:
                    DefaultEvents(SPELL_ICY_ENCHANTMENT);
                    break;
                case SPELL_SEARING_BRAND_CHARGE_TIMER:
                {
                    me->AttackStop();
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                }
                }
            }
        }

        void SpellFinishCast(const SpellInfo* spell)
        {
            switch (spell->Id)
            {
            case SPELL_ANNIHILATE:
                if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                    DoCast(target, SPELL_ANNIHILATE_DEBUFF, true);
                break;
            case SPELL_ANIMATE_MARK_OF_FROST:
            case SPELL_ANIMATE_SEARING_BRAND:
            case SPELL_ANIMATE_ARCANE_ORB:
                events.RescheduleEvent(EVENT_ANIMATE_DESPAWN, 1000);
                break;
            case SPELL_REPLICATE_SEARING_BRAND:
                events.RescheduleEvent(EVENT_REPLICATE_SEARING_BRAND_2, 100);
                break;
            default:
                break;
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_SEARING_BRAND_FILTER:
            case SPELL_REPLICATE_SEARING_BRAND:
                playerListGUID.push_back(target->GetGUID());
                break;
            default:
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == EVENT_CHARGE)
                me->SetReactState(REACT_AGGRESSIVE);
        }

        void SearingBrandEvent()
        {
            if (!playerListGUID.empty())
            {
                Position pos;
                bool firstMark = false;

                for (auto const& pGuid : playerListGUID)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, pGuid))
                    {
                        if (!firstMark)
                        {
                            firstMark = true;
                            DoCast(player, SPELL_SEARING_BRAND_MARK, true);
                            continue;
                        }
                        else if (playerListGUID.size() > 1)
                        {
                            me->GetRandomNearPosition(5.0f);
                            if (Creature* image = me->SummonCreature(NPC_SPELLBLADE_ALURIEL_IMAG, pos))
                            {
                                image->CastSpell(player, SPELL_SEARING_BRAND_MARK, true);
                                image->CastSpell(image, SPELL_SEARING_BRAND_CHARGE_TIMER, true);
                            }
                        }
                    }
                }
            }
        }

        void KilledUnit(Unit* who) override
        {
            if (who->IsPlayer() && urand(1, 2) == 2)
                Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (berserkTimer)
            {
                if (berserkTimer <= diff)
                {
                    berserkTimer = 0;
                    DoCast(me, SPELL_BERSERK, true);
                }
                else
                    berserkTimer -= diff;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

     
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ANNIHILATE:
                    Talk(SAY_ANNIHILATE);
                    DoCast(SPELL_ANNIHILATE);
                    if (IsMythicRaid())
                    {
                        if (me->HasAura(SPELL_ICY_ENCHANTMENT))
                            events.RescheduleEvent(EVENT_ANNIHILATE, 45000);
                        else if (me->HasAura(SPELL_FIERY_ENCHANTMENT))
                            events.RescheduleEvent(EVENT_ANNIHILATE, 38000);
                        else if (me->HasAura(SPELL_MAGIC_ENCHANTMENT))
                            events.RescheduleEvent(EVENT_ANNIHILATE, 43000);
                    }
                    else
                    {
                        if (me->HasAura(SPELL_MAGIC_ENCHANTMENT))
                            events.RescheduleEvent(EVENT_ANNIHILATE, 35000);
                        else
                            events.RescheduleEvent(EVENT_ANNIHILATE, 45000);
                    }
                    break;
                case EVENT_MARK_OF_FROST:
                    Talk(SAY_MARK_OF_FROST);
                    DoCast(me, SPELL_MARK_OF_FROST_FILTER, true);
                    break;
                case EVENT_REPLICATE_FROST:
                    Talk(SAY_REPLICATION);
                    DoCast(SPELL_REPLICATE_MARK_OF_FROST);
                    break;
                case EVENT_DETONATE_FROST:
                    Talk(SAY_DETONATE);
                    DoCast(SPELL_DETONATE_MARK_OF_FROST);
                    break;
                case EVENT_ANIMATE_FROST:
                    Talk(SAY_ANIMATE);
                    if (IsHeroicPlusRaid())
                    {
                        events.RescheduleEvent(EVENT_FROZEN_TEMPEST_FILTER, 9000);
                    }
                    DoCast(me, SPELL_ANIMATE_MARK_OF_FROST, true);
                    break;
                case EVENT_SEARING_BRAND:
                    Talk(SAY_MARK);
                    playerListGUID.clear();
                    DoCast(me, SPELL_SEARING_BRAND_FILTER, true);
                    DoCast(me, SPELL_SEARING_BRAND_CHARGE_TIMER, true);
                    break;
                case EVENT_REPLICATE_SEARING_BRAND:
                    Talk(SAY_REPLICATION);
                    playerListGUID.clear();
                    DoCast(me, SPELL_REPLICATE_SEARING_BRAND, true);
                    DoCast(me, SPELL_SEARING_BRAND_CHARGE_TIMER, true);
                    break;
                case EVENT_REPLICATE_SEARING_BRAND_2:
                    SearingBrandEvent();
                    break;
                case EVENT_DETONATE_FIRE:
                    Talk(SAY_DETONATE);
                    DoCast(SPELL_DETONATE_SEARING_BRAND);
                    break;
                case EVENT_ANIMATE_FIRE:
                    Talk(SAY_ANIMATE);
                    DoCast(SPELL_ANIMATE_SEARING_BRAND);
                    break;
                case EVENT_ARCANE_ORB:
                    Talk(SAY_MARK);
                    DoCast(me, SPELL_ARCANE_ORB_FILTER, true);
                    break;
                case EVENT_REPLICATE_ARCANE_ORB:
                {
                    Talk(SAY_REPLICATION);
                    DoCast(SPELL_REPLICATE_ARCANE_ORB_FILTER);
                    uint32 multiTimer = 2100;
                    for (uint8 i = 0; i < 2; i++)
                    {
                        AddDelayedEvent(multiTimer, [this]() -> void
                        {
                            if (me && me->IsAlive() && me->IsInCombat())
                                DoCast(me, SPELL_REPLICATE_ARCANE_ORB_FILTER, true);
                        });
                        multiTimer *= 2;
                    }
                    break;
                }
                case EVENT_DETONATE_ARCANE_ORB:
                    Talk(SAY_DETONATE);
                    DoCast(SPELL_DETONATE_ARCANE_ORB);
                    break;
                case EVENT_ANIMATE_ARCANE:
                    Talk(SAY_ANIMATE);
                    DoCast(SPELL_ANIMATE_ARCANE_ORB);
                    break;
                case EVENT_ANIMATE_DESPAWN:
                    me->RemoveAreaTrigger(SPELL_DETONATE_MARK_OF_FROST_AT);
                    me->RemoveAreaTrigger(SPELL_DETONATE_SEARING_BRAND_AT);
                    me->RemoveAreaTrigger(SPELL_ARCANE_ORB_AT_2);
                    summons.DespawnEntry(NPC_MARK_OF_FROST);
                    summons.DespawnEntry(NPC_SEARING_BRAND);
                    summons.DespawnEntry(NPC_ARCANE_ORB);
                    break;
                case EVENT_FROZEN_TEMPEST_FILTER:
                    DoCast(me, SPELL_FROZEN_TEMPEST_FILTER, true);
                    events.RescheduleEvent(EVENT_FROZEN_TEMPEST_FILTER, 16000);
                    break;
                case EVENT_SUM_FEL_SOUL:
                    DoCast(me, SPELL_FEL_SOUL, true);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_spellblade_alurielAI(creature);
    }
};

//107237, 107285, 107287
class npc_aluriel_enchantment : public CreatureScript
{
public:
    npc_aluriel_enchantment() : CreatureScript("npc_aluriel_enchantment") {}

    struct npc_aluriel_enchantmentAI : public ScriptedAI
    {
        npc_aluriel_enchantmentAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;
        SummonList summons;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoZoneInCombat(me, 100.0f);
            events.RescheduleEvent(EVENT_1, 2000);

            switch (me->GetEntry())
            {
            case NPC_ICY_ENCHANTMENT:
                DoCast(me, SPELL_BURST_OF_ICE, true);
                break;
            case NPC_FIERY_ENCHANTMENT:
            {
                DoCast(me, SPELL_BURST_OF_FLAME, true);
                if (IsHeroicPlusRaid())
                {
                    events.CancelEvent(EVENT_1);
                    SetCombatMovement(false);
                    events.RescheduleEvent(EVENT_2, 3000); // Bound in Flame
                    events.RescheduleEvent(EVENT_3, urand(5, 7) * IN_MILLISECONDS); // Pyroblast
                }
                break;
            }
            case NPC_ARCANE_ENCHANTMENT:
            {
                if (IsHeroicPlusRaid())
                {
                    events.CancelEvent(EVENT_1);
                    SetCombatMovement(false);
                    DoCast(me, SPELL_ARMAGEDDON, true);
                }
                else
                    DoCast(me, SPELL_BURST_OF_MAGIC, true);
                break;
            }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->RemoveAllAreaObjects();
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void SpellFinishCast(const SpellInfo* spell)
        {
            if (spell->Id == SPELL_PYROBLAST)
                ResetThreat(me);

            if (spell->Id == SPELL_FROZEN_TEMPEST_TP)
            {
                me->AttackStop();
                KillAllDelayedEvents();
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                AddDelayedEvent(12000, [this]() -> void
                {
                    if (me && me->IsAlive() && me->IsInCombat())
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, false);
                        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, false);
                    }
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->IsInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_2:
                    DoCast(me, SPELL_BOUND_IN_FLAME_FILTER, true);
                    events.RescheduleEvent(EVENT_2, 3000);
                    break;
                case EVENT_3:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        AddThreat(target, 1000.0f);
                        DoCast(target, SPELL_PYROBLAST);
                    }
                    events.RescheduleEvent(EVENT_3, 7000);
                    break;
                }
            }
            if (me->GetEntry() == NPC_ICY_ENCHANTMENT || !IsHeroicPlusRaid())
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aluriel_enchantmentAI(creature);
    }
};

//107980
class npc_spellblade_aluriel_image : public CreatureScript
{
public:
    npc_spellblade_aluriel_image() : CreatureScript("npc_spellblade_aluriel_image") {}

    struct npc_spellblade_aluriel_imageAI : public ScriptedAI
    {
        npc_spellblade_aluriel_imageAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;
        ObjectGuid playerGUID;

        void Reset() override {}

        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
        {
            if (apply)
                return;

            switch (spellId)
            {
            case SPELL_SEARING_BRAND_CHARGE_TIMER:
            {
                me->AttackStop();
                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                {
                    if (player->IsAlive() && player->HasAura(SPELL_SEARING_BRAND_MARK, me->GetGUID()))
                    {
                        if (Unit* owner = me->GetOwner())
                        {
                            if (player->GetDistance(centerPos) > 95.0f)
                            {
                                if (owner->IsCreature() && owner->IsAlive() && owner->IsInCombat())
                                {
                                    owner->ToCreature()->AI()->EnterEvadeMode();
                                    return;
                                }
                            }
                            player->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                            DoCast(me, SPELL_SEARING_BRAND_AT, true);
                            me->CastSpell(player, SPELL_SEARING_BRAND_DOT, true);
                            DoCast(player, SPELL_SEARING_BRAND_CHARGE_IMAGE);
                            if (!me->IsWithinLOSInMap(player))
                            {
                                DoCast(me, SPELL_DISSIPATION, true);
                                events.RescheduleEvent(EVENT_1, 500);
                            }
                        }
                        return;
                    }
                }
                me->DespawnOrUnsummon(100);
                break;
            }
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_SEARING_BRAND_MARK:
                playerGUID = target->GetGUID();
                me->SetFacingToObject(target);
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == EVENT_CHARGE)
            {
                DoCast(me, SPELL_DISSIPATION, true);
                events.RescheduleEvent(EVENT_1, 500);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->DespawnOrUnsummon();
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spellblade_aluriel_imageAI(creature);
    }
};

//107510
class npc_aluriel_arcane_orb : public CreatureScript
{
public:
    npc_aluriel_arcane_orb() : CreatureScript("npc_aluriel_arcane_orb") {}

    struct npc_aluriel_arcane_orbAI : public ScriptedAI
    {
        npc_aluriel_arcane_orbAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_FLIGHT, 0.2f);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            me->SetCanFly(true);
            DoCast(me, SPELL_BURST_ARCANE_ORB, true);
            events.RescheduleEvent(EVENT_1, 1000);
        }

        void SpellHit(Unit* target, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_DETONATE_ARCANE_ORB:
                events.Reset();
                me->GetMotionMaster()->Clear();
                me->RemoveAurasDueToSpell(SPELL_BURST_ARCANE_ORB);
                me->SetSpeed(MOVE_FLIGHT, 0.4f);
                me->GetMotionMaster()->MovePoint(2, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 10.0f, false);
                //DoCast(me, SPELL_ARCANE_ORB_VISUAL, true);
                break;
            case SPELL_ANIMATE_ARCANE_ORB:
                events.RescheduleEvent(EVENT_3, 1000); //Despawn
                break;
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_ARCANE_ORB_SEARCH_PLR:
                if (Unit* owner = me->GetOwner())
                    me->CastSpell(target, 213511, true);
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                if (id == 2)
                {
                    me->SetSpeed(MOVE_FLIGHT, 0.8f);
                    events.RescheduleEvent(EVENT_2, urand(1, 3) * 1000);
                }
                if (id == 3)
                {
                    if (Unit* owner = me->GetOwner())
                        me->CastSpell(me, SPELL_ARCANE_ORB_MISSILE, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                {
                    float angle = (float)rand_norm() * static_cast<float>(2 * M_PI);
                    float distance = 5 * (float)rand_norm();
                    float x = me->GetHomePosition().GetPositionX() + distance * std::cos(angle);
                    float y = me->GetHomePosition().GetPositionY() + distance * std::sin(angle);
                    float z = me->GetHomePosition().GetPositionZ();
                    Trinity::NormalizeMapCoord(x);
                    Trinity::NormalizeMapCoord(y);
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->MovePoint(1, x, y, z + 1.0f);
                    events.RescheduleEvent(EVENT_1, 3000);
                    break;
                }
                case EVENT_2:
                    if (Unit* owner = me->GetOwner())
                    {
                        if (Unit* target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                        {
                            if (target->GetDistance(centerPos) > 95.0f)
                            {
                                if (owner->IsCreature() && owner->IsAlive() && owner->IsInCombat())
                                {
                                    owner->ToCreature()->AI()->EnterEvadeMode();
                                    return;
                                }
                            }
                            me->CastSpell(target, SPELL_ARCANE_ORB_AT, true);
                            me->GetMotionMaster()->MovePoint(3, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), false);
                        }
                    }
                    break;
                case EVENT_3:
                    me->DespawnOrUnsummon();
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aluriel_arcane_orbAI(creature);
    }
};

//107592
class npc_aluriel_ice_shards : public CreatureScript
{
public:
    npc_aluriel_ice_shards() : CreatureScript("npc_aluriel_ice_shards") {}

    struct npc_aluriel_ice_shardsAI : public ScriptedAI
    {
        npc_aluriel_ice_shardsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisplayId(47516);
            me->SetReactState(REACT_PASSIVE);
            instance = me->GetInstanceScript();
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

        InstanceScript* instance;
        uint32 checkStateTimer = 500;

        void Reset() override {}

        void JustDied(Unit* /*killer*/) override
        {
            EventEnd();
        }

        void EventEnd()
        {
            if (Unit* owner = me->GetOwner())
                if (owner->IsAlive() && owner->HasAura(SPELL_ENTOMBED_IN_ICE, me->GetGUID()))
                    owner->RemoveAurasDueToSpell(SPELL_ENTOMBED_IN_ICE);

            me->DespawnOrUnsummon(100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (checkStateTimer)
            {
                if (checkStateTimer <= diff)
                {
                    if (!me->GetOwner() || !me->GetOwner()->IsAlive() || !instance || instance->GetBossState(DATA_ALURIEL) != IN_PROGRESS)
                    {
                        EventEnd();
                        return;
                    }
                    checkStateTimer = 1000;
                }
                else
                    checkStateTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aluriel_ice_shardsAI(creature);
    }
};

//115905
class npc_aluriel_fel_soul : public CreatureScript
{
public:
    npc_aluriel_fel_soul() : CreatureScript("npc_aluriel_fel_soul") {}

    struct npc_aluriel_fel_soulAI : public ScriptedAI
    {
        npc_aluriel_fel_soulAI(Creature* creature) : ScriptedAI(creature), addJump(false), lashSwitcher(false), despawnTimer(0)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetRegenerateHealth(false);
        }

        EventMap events;
        bool addJump;
        bool lashSwitcher;
        uint32 despawnTimer;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            me->SetHealth(summoner->GetHealth());

            despawnTimer = 45000;
            events.RescheduleEvent(EVENT_1, 100);   // Cast SPELL_SEVERED_SOUL
            events.RescheduleEvent(EVENT_2, 2000);  // Check distance owner
            events.RescheduleEvent(EVENT_3, 20000); // Cast SPELL_DECIMATE

            if (summoner->HasAura(SPELL_ICY_ENCHANTMENT))
                events.RescheduleEvent(EVENT_4, 10000); // Cast SPELL_WHIRLING_BARRAGE

            if (summoner->HasAura(SPELL_FIERY_ENCHANTMENT))
                events.RescheduleEvent(EVENT_5, 10000); // Cast SPELL_FEL_STOMP_FILTER

            if (summoner->HasAura(SPELL_MAGIC_ENCHANTMENT)) //35:31, 35:42, 35:48, 36:00, 36:06
            {
                lashSwitcher = false;
                events.RescheduleEvent(EVENT_7, 9000); // Cast SPELL_FEL_LASH
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_WHIRLING_BARRAGE_FIXATE:
                me->GetMotionMaster()->MovePoint(1, target->GetPosition());
                break;
            }
        }

        void SpellFinishCast(const SpellInfo* spell)
        {
            if (spell->Id == SPELL_SEVERED_SOUL)
                me->SetReactState(REACT_AGGRESSIVE);
        }

        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
        {
            if (!me->IsInCombat() || apply)
                return;

            if (spellId == SPELL_WHIRLING_BARRAGE)
            {
                me->GetMotionMaster()->Clear();
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
        {
            if (target && mode == AURA_REMOVE_BY_EXPIRE)
            {
                if (spellId == SPELL_WHIRLING_BARRAGE_FIXATE && me->HasAura(SPELL_WHIRLING_BARRAGE))
                {
                    me->GetMotionMaster()->Clear();
                    DoCast(me, SPELL_WHIRLING_BARRAGE_FIXATE, true);
                }
            }

        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == EFFECT_MOTION_TYPE)
            {
                switch (id)
                {
                case SPELL_FEL_STOMP_JUMP:
                    if (addJump)
                    {
                        addJump = false;
                        events.RescheduleEvent(EVENT_6, 2000);
                    }
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->IsInCombat())
                return;

            events.Update(diff);

            if (despawnTimer)
            {
                if (despawnTimer <= diff)
                {
                    despawnTimer = 0;
                    me->DespawnOrUnsummon();
                    return;
                }
                else
                    despawnTimer -= diff;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    DoZoneInCombat(me, 100.0f);
                    DoCast(SPELL_SEVERED_SOUL);
                    break;
                case EVENT_2:
                    if (Unit* owner = me->GetOwner())
                    {
                        if (me->GetDistance(owner) > 45.0f)
                        {
                            if (!me->HasAura(SPELL_SEVERED_SOUL_MOD_DMG))
                                DoCast(me, SPELL_SEVERED_SOUL_MOD_DMG, true);

                            if (!owner->HasAura(SPELL_SEVERED_SOUL_MOD_DMG))
                                owner->CastSpell(owner, SPELL_SEVERED_SOUL_MOD_DMG, true);
                        }
                    }
                    events.RescheduleEvent(EVENT_2, 2000);
                    break;
                case EVENT_3:
                    DoCastVictim(SPELL_DECIMATE);
                    events.RescheduleEvent(EVENT_3, 20000);
                    break;
                case EVENT_4: //Frost Phase
                    me->AttackStop();
                    DoCast(me, SPELL_WHIRLING_BARRAGE, true);
                    events.RescheduleEvent(EVENT_4, 20000);
                    break;
                case EVENT_5: //Fire Phase
                    addJump = true;
                    DoCast(me, SPELL_FEL_STOMP_FILTER, true);
                    events.RescheduleEvent(EVENT_5, 12000);
                    break;
                case EVENT_6:
                    DoCastVictim(SPELL_FEL_STOMP_JUMP, true);
                    break;
                case EVENT_7: //Arcane Phase
                    DoCastVictim(SPELL_FEL_LASH);
                    if (!lashSwitcher)
                    {
                        lashSwitcher = true;
                        events.RescheduleEvent(EVENT_7, 11000);
                    }
                    else
                    {
                        lashSwitcher = false;
                        events.RescheduleEvent(EVENT_7, 6000);
                    }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aluriel_fel_soulAI(creature);
    }
};

//213864, 213867, 213869
class spell_aluriel_enchantment_controll : public SpellScriptLoader
{
public:
    spell_aluriel_enchantment_controll() : SpellScriptLoader("spell_aluriel_enchantment_controll") {}

    class spell_aluriel_enchantment_controll_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aluriel_enchantment_controll_AuraScript);

        uint8 manaCount = 0;

        void OnPereodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->IsInCombat())
                {
                    manaCount = caster->GetMap()->IsMythic() ? 11 : 0;

                    if (GetId() == SPELL_MAGIC_ENCHANTMENT)
                        manaCount = 16;

                    if (caster->GetPower(POWER_MANA) <= manaCount)
                    {
                        caster->SetPower(POWER_MANA, 85);
                        caster->RemoveAurasDueToSpell(GetId(), caster->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                    }
                }
                else
                {
                    caster->RemoveAurasDueToSpell(GetId());
                    caster->SetPower(POWER_MANA, 85);
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_aluriel_enchantment_controll_AuraScript::OnPereodic, EFFECT_2, SPELL_AURA_POWER_BURN);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_aluriel_enchantment_controll_AuraScript();
    }
};

//212587
class spell_aluriel_mark_of_frost : public AuraScript
{
    PrepareAuraScript(spell_aluriel_mark_of_frost);

    void OnApply(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget())
            GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_FROST_SEARCHER_AT, true);
    }

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget())
            GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_FROST_SEARCHER_AT);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_aluriel_mark_of_frost::OnApply, SpellEffIndex::EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_aluriel_mark_of_frost::OnRemove, SpellEffIndex::EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

//233195
class spell_aluriel_mark_of_frost_searcher : public SpellScriptLoader
{
public:
    spell_aluriel_mark_of_frost_searcher() : SpellScriptLoader("spell_aluriel_mark_of_frost_searcher") {}

    class spell_aluriel_mark_of_frost_searcher_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_aluriel_mark_of_frost_searcher_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (Aura* aura = target->GetAura(SPELL_MARK_OF_FROST))
            {
                float bp = aura->GetDuration();
                aura->Remove();
                //target->CastCustomSpell(caster, SPELL_MARK_OF_FROST_FILTER_PLR, &bp, 0, 0, true);
                target->CastSpell(target, SPELL_MARK_OF_FROST_EXPLOSION, true);
                target->CastSpell(target, SPELL_MARK_OF_FROST_KNOCK, true);
            }

            if (Aura* aura = caster->GetAura(SPELL_MARK_OF_FROST))
            {
                float bp = aura->GetDuration();
                aura->Remove();
                //caster->CastCustomSpell(target, SPELL_MARK_OF_FROST_FILTER_PLR, &bp, 0, 0, true);
                caster->CastSpell(caster, SPELL_MARK_OF_FROST_EXPLOSION, true);
                caster->CastSpell(caster, SPELL_MARK_OF_FROST_KNOCK, true);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_aluriel_mark_of_frost_searcher_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_aluriel_mark_of_frost_searcher_SpellScript();
    }
};

//220104
class spell_aluriel_mark_of_frost_friendly : public SpellScriptLoader
{
public:
    spell_aluriel_mark_of_frost_friendly() : SpellScriptLoader("spell_aluriel_mark_of_frost_friendly") {}

    class spell_aluriel_mark_of_frost_friendly_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_aluriel_mark_of_frost_friendly_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            targets.remove(GetCaster());
            //targets.remove(gettar());
            std::list<WorldObject*> tempList;

            for (auto const& target : targets)
            {
                if (auto const& player = target->ToPlayer())
                    if (!player->HasAura(SPELL_MARK_OF_FROST) && !player->HasAura(SPELL_MARK_OF_FROST_FIXATE) && !player->HasAura(SPELL_FROSTBITTEN))
                        tempList.push_back(target);
            }

            if (tempList.empty())
            {
                for (auto const& target : targets)
                {
                    if (auto const& player = target->ToPlayer())
                        if (!player->HasAura(SPELL_MARK_OF_FROST) && !player->HasAura(SPELL_MARK_OF_FROST_FIXATE))
                            tempList.push_back(target);
                }
            }

            if (!tempList.empty())
            {

                std::list<WorldObject*> rangeList;
                std::list<WorldObject*> meleeList;

                for (auto const& target : tempList)
                {
                    if (auto const& player = target->ToPlayer())
                    {
                        switch (player->GetSpecializationId())
                        {
                        case ROLE_DAMAGE:
                            meleeList.push_back(target);
                            break;
                        case ROLE_HEALER:
                            rangeList.push_back(target);
                            break;
                        }
                    }
                }

                tempList.clear();
                tempList.splice(tempList.end(), rangeList);
                tempList.splice(tempList.end(), meleeList);

                if (tempList.size() > 1)
                    tempList.resize(1);
            }
            else
                tempList.push_back(GetCaster());

            targets = tempList;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit())
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_MARK_OF_FROST, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aluriel_mark_of_frost_friendly_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(spell_aluriel_mark_of_frost_friendly_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_aluriel_mark_of_frost_friendly_SpellScript();
    }
};


//213328
class spell_aluriel_detonate_arcane_orb : public SpellScriptLoader
{
public:
    spell_aluriel_detonate_arcane_orb() : SpellScriptLoader("spell_aluriel_detonate_arcane_orb") {}

    class spell_aluriel_detonate_arcane_orb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_aluriel_detonate_arcane_orb_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            float distance = GetCaster()->GetExactDist2d(GetHitUnit()) * 2.0f;
            uint32 perc = 1;
            if (distance < 100.0f)
                perc = 100 - distance;

            uint32 damage = CalculatePct(GetHitDamage(), perc);
            SetHitDamage(damage);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_aluriel_detonate_arcane_orb_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_aluriel_detonate_arcane_orb_SpellScript();
    }
};

//213622
class spell_aluriel_entombed_in_ice : public SpellScriptLoader
{
public:
    spell_aluriel_entombed_in_ice() : SpellScriptLoader("spell_aluriel_entombed_in_ice") {}

    class spell_aluriel_entombed_in_ice_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aluriel_entombed_in_ice_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
            {
                if (target->GetMapId() == 1530 && target->IsAlive() && !target->HasAura(SPELL_ENTOMBED_IN_ICE))
                {
                    if (Creature* summon = target->SummonCreature(NPC_ICE_SHARDS, target->GetPosition()))
                    {
                        target->RemoveAurasDueToSpell(SPELL_ENTOMBED_IN_ICE_SELF);
                        summon->CastSpell(target, SPELL_ENTOMBED_IN_ICE, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_aluriel_entombed_in_ice_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_aluriel_entombed_in_ice_AuraScript();
    }
};

//213166
class spell_aluriel_searing_brand : public SpellScriptLoader
{
public:
    spell_aluriel_searing_brand() : SpellScriptLoader("spell_aluriel_searing_brand") {}

    class spell_aluriel_searing_brand_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aluriel_searing_brand_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
            {
                AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();

                if (mode == AURA_REMOVE_BY_DEATH)
                    if (InstanceScript* instance = target->GetInstanceScript())
                        if (instance->GetBossState(DATA_ALURIEL) == IN_PROGRESS)
                        {
                            if (Creature* aluriel = Creature::GetCreature(*target, instance->GetGuidData(DATA_ALURIEL)))
                                target->CastSpell(target, SPELL_DETONATE_SEARING_BRAND_AT, true, nullptr, nullptr, aluriel->GetGUID());
                        }
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_aluriel_searing_brand_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_aluriel_searing_brand_AuraScript();
    }
};

//216257
class spell_aluriel_bound_in_flame : public SpellScriptLoader
{
public:
    spell_aluriel_bound_in_flame() : SpellScriptLoader("spell_aluriel_bound_in_flame") {}

    class spell_aluriel_bound_in_flame_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_aluriel_bound_in_flame_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                if (!targets.empty())
                {
                    if (Aura* flame = caster->GetAura(SPELL_BOUND_IN_FLAME))
                    {
                        if (flame->GetStackAmount() != targets.size())
                            flame->SetStackAmount(targets.size());
                    }
                    else
                        caster->CastCustomSpell(SPELL_BOUND_IN_FLAME, SPELLVALUE_AURA_STACK, targets.size(), caster, true);
                }
                else
                    caster->RemoveAurasDueToSpell(SPELL_BOUND_IN_FLAME);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aluriel_bound_in_flame_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_aluriel_bound_in_flame_SpellScript();
    }
};

//212530
class spell_replicate_mark_of_frost_filter : public SpellScript
{
    PrepareSpellScript(spell_replicate_mark_of_frost_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempList;

        for (auto const& target : targets)
        {
            if (Player* player = target->ToPlayer())
                if (!player->HasAura(SPELL_FROSTBITTEN))
                    tempList.push_back(target);
        }

        if (!tempList.empty())
            targets = tempList;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_replicate_mark_of_frost_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_replicate_mark_of_frost_filter::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//213131
class spell_aluriel_frozen_tempest_tp_filter : public SpellScriptLoader
{
public:
    spell_aluriel_frozen_tempest_tp_filter() : SpellScriptLoader("spell_aluriel_frozen_tempest_tp_filter") {}

    class spell_aluriel_frozen_tempest_tp_filter_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_aluriel_frozen_tempest_tp_filter_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!targets.empty())
            {
                std::list<WorldObject*> tempList;

                for (auto const& target : targets)
                {
                    if (auto const& player = target->ToPlayer())
                        if (!player->HasAura(SPELL_MARK_OF_FROST))
                            tempList.push_back(target);
                }

                std::list<WorldObject*> meleeList;
                std::list<WorldObject*> noMeleeList;

                for (auto const& target : tempList)
                {
                    if (auto const& player = target->ToPlayer())
                    {
                        noMeleeList.push_back(target);
                    }
                }

                tempList.clear();
                tempList.splice(tempList.end(), meleeList);
                tempList.splice(tempList.end(), noMeleeList);

                if (tempList.size() > 1)
                    tempList.resize(1);

                targets = tempList;
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aluriel_frozen_tempest_tp_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_aluriel_frozen_tempest_tp_filter_SpellScript();
    }
};

//213145, 213182
class spell_aluriel_searing_brand_filter : public SpellScript
{
    PrepareSpellScript(spell_aluriel_searing_brand_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempList;

        for (auto const& target : targets)
        {
            if (Player* player = target->ToPlayer())
                if (!player->HasAura(SPELL_MARK_OF_FROST) && !player->HasAura(213166))
                    tempList.push_back(target);
        }

        if (!tempList.empty())
            targets = tempList;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aluriel_searing_brand_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//213130
class spell_aluriel_frozen_tempest_jump : public SpellScript
{
    PrepareSpellScript(spell_aluriel_frozen_tempest_jump);

    void HandleScript(SpellEffIndex /*effectIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_1);

        if (auto const& creature = GetCaster()->ToCreature())
        {
            creature->StopMoving();
            creature->CastSpell(creature, GetSpellInfo()->GetEffect(EFFECT_1)->TriggerSpell, false);
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_aluriel_frozen_tempest_jump::HandleScript, EFFECT_1, SPELL_EFFECT_JUMP_DEST);
    }
};

void AddSC_boss_aluriel()
{
    new boss_spellblade_aluriel();
    new npc_aluriel_enchantment();
    new npc_spellblade_aluriel_image();
    new npc_aluriel_arcane_orb();
    new npc_aluriel_ice_shards();
    new npc_aluriel_fel_soul();
    new spell_aluriel_enchantment_controll();
    RegisterAuraScript(spell_aluriel_mark_of_frost);
    new spell_aluriel_mark_of_frost_searcher();
    new spell_aluriel_mark_of_frost_friendly();
    new spell_aluriel_detonate_arcane_orb();
    new spell_aluriel_entombed_in_ice();
    new spell_aluriel_searing_brand();
    new spell_aluriel_bound_in_flame();
    new spell_aluriel_frozen_tempest_tp_filter();
    RegisterSpellScript(spell_replicate_mark_of_frost_filter);
    RegisterSpellScript(spell_aluriel_searing_brand_filter);
    RegisterSpellScript(spell_aluriel_frozen_tempest_jump);
}
