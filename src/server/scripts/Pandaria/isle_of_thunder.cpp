#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum Spells
{
    // Nalak
    SPELL_ARC_NOVA                  = 136338,
    SPELL_LIGHTNING_TETHER          = 136339,
    SPELL_STORMCLOUD                = 136340,
    SPELL_LIGHTNING_TETHER_TRIGGER  = 136353,
    SPELL_LIGHTNING_TETHER_30Y      = 136349, // if target dist > 30 from nalak
    SPELL_STATIC_SHIELD             = 136341,

    // Haywire Sunreaver Construct
    SPELL_HAYWIRE                   = 139324,
    
    // Mumta
    SPELL_SPIRIT_BOLTS              = 139004,
    SPELL_DARKNESS_DARKNESS         = 139010,
    SPELL_VENGEFUL_SPIRIT           = 139003,

    // Ku'lai the Skyclaw & Tamed Pterrorwing
    SPELL_BLADEWIND                 = 139125,
    SPELL_LEAPING_REND              = 139122,
    // SPELL_SPIRIT_BOND            = 139124,  Doesn't work
    
    // Progenitus
    SPELL_UNLEASH_BLOOD             = 139146,
    SPELL_MUTAGENIC_BURST           = 139169,
    SPELL_EVOLUTION                 = 139144,
    
    // Goda
    SPELL_SHELL_SPIN                = 139178,
    SPELL_CRYSTALLINE_SHIELD        = 139184,
    
    // God-Hulk Ramuk
    SPELL_CROUCH                    = 139014,
    SPELL_BLESSING_OF_THUNDER       = 139015,
    SPELL_POUND                     = 139016,
    
    // Al'tabim the All-Seeing
    SPELL_OMEN                      = 139250,
    SPELL_METEOR_SHOWER             = 139248,
    SPELL_SHADOW_BOLT_VOLLEY        = 139419,

    // Backbreaker Uru
    SPELL_BREAK_SPINE               = 139260,
    SPELL_MASSIVE_STOMP             = 139262,

    // Lu-Ban
    SPELL_SKYFORGED_HAMMERS         = 139269,
    SPELL_STORM_BOLT                = 139275,

    // Molthor
    //SPELL_SCARAB_SWARM              = 138036, //////////////////////////////////
    //SPELL_THUNDER_CRUSH             = 138044, // See Zandalaris shared spells //
    //SPELL_HORRIFIC_VISAGE           = 138040, //////////////////////////////////

    // Ra'sha
    SPELL_BLOODY_STRIKE             = 77558,
    SPELL_BLOODBOLT                 = 90387,
    SPELL_MARK_OF_BLOOD             = 61606,
    SPELL_MARK_OF_BLOOD_TRIGGER     = 61607,

    // Spirit of Warlord Teng
    SPELL_SPIRIT_SLASH              = 137140,
    SPELL_SPIRIT_S_WRATH            = 137402,
    SPELL_TENG_GHOST_VISUAL_1       = 134090,
    SPELL_TENG_GHOST_VISUAL_2       = 137135,

    // Draining Spirit
    SPELL_DRAIN_SPIRIT              = 137125,
    
    // Restless Spirit
    SPELL_BURIED_ALIVE              = 137280,

    // Kor'dok
    SPELL_FURIOUS_CHARGE            = 138063,
    SPELL_CALL_THUNDER              = 137997,
    SPELL_BATTLE_RAGE               = 137653,

    // Tinzo
    SPELL_DISRUPT                   = 137574,
    SPELL_FIRE_BURST                = 137703,
    SPELL_FLAME_BARRAGE             = 137705,

    // Echo of Kros
    SPELL_GHOST_DINOSAUR_STAMPEDE   = 136734,
    SPELL_GHASTLY_ROAR              = 136716,
    SPELL_DEVOUR                    = 136872,
    SPELL_RAGE_OF_KROS              = 137334,

    // Electromancer Ju'le
    SPELL_CHAIN_LIGHTNING           = 137884,
    SPELL_ELECTRIFIED               = 136691,
    SPELL_LIGHTNING_FIELD           = 136717,

    // Lightning Elemental
    SPELL_STATIC_ELECTRICITY        = 137985,

    // Qi'nor
    SPELL_LIGHTNING_BOLT            = 138018,
    SPELL_LIGHTNING_PROD            = 138019,
    SPELL_LIGHTNING_STRIKE          = 138012,
    
    // Ancient Mogu Guardian
    SPELL_MANTLE_OF_THUNDER_KING    = 138073,

    // Floor tiles (trigger)
    SPELL_NULLIFY_MAGIC             = 138004,
    SPELL_ANCIENT_FLAMES            = 138015,
    SPELL_MOGU_POWER                = 138017,

    // Windweaver Akil'amon
    SPELL_IMPENDING_GUST            = 138976,
    SPELL_LIFT_OFF                  = 139021,
    
    // Soaring Eagle
    SPELL_PLUCKED                   = 97318,
    
    // Cera
    SPELL_DOUBLE_EDGE_TRASH         = 136866,
    SPELL_CHARGE                    = 138660,
    SPELL_CHARGE_IMPACT             = 138661,
    SPELL_REFLECTIVE_ARMOR_PLATING  = 136865,

    // Incomplete Drakkari Colossus
    SPELL_DEATH_STARE               = 136854,
    SPELL_GROUND_SLAM               = 137074,
    SPELL_SHOCKWAVE                 = 136847,
    SPELL_FLAMETHROWER              = 136898,

    // Zandalaris shared spells
            /* Auras */
    SPELL_SCARAB_BROOCH             = 138046,
    SPELL_TRIBAL_MASK               = 138047,
    SPELL_STAR_MAP                  = 138048,
    SPELL_SPIRIT_CHARM              = 138049,
    SPELL_THUNDERING_SIGIL          = 138050,
            /* Spells */
    SPELL_SCARAB_SWARM              = 138036, // Needs SPELL_SCARAB_BROOCH to be casted
    SPELL_HORRIFIC_VISAGE           = 138040, // Needs SPELL_TRIBAL_MASK to be casted
    SPELL_METEOR_SHOWER_2           = 138042, // Needs SPELL_STAR_MAP to be casted
    SPELL_VENGEFUL_SPIRIT_2         = 138043, // Needs SPELL_SPIRIT_CHARM to be casted
    SPELL_THUNDER_CRUSH             = 138044, // Needs SPELL_THUNDERING_SIGIL to be casted
};

enum Texts
{
    // Nalak
    SAY_NALAK_AGGRO             = 0,
    SAY_NALAK_DEATH             = 1,
    SAY_NALAK_INTRO             = 2,
    SAY_NALAK_SLAY              = 3,
    SAY_NALAK_STORMCLOUD        = 4,
    SAY_NALAK_LIGHTNING_TETHER  = 5
};

enum Npcs
{
    BOSS_NALAK = 69099,
};

// Nalak #69099#
class boss_nalak : public CreatureScript
{
public:

    boss_nalak() : CreatureScript("boss_nalak")
    {
    }

    struct boss_nalakAI : public ScriptedAI
    {
        boss_nalakAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiArcNovaTimer;
        uint32 uiLightningTetherTimer;
        uint32 uiStormCloudTimer;

        void Reset()
        {
            me->SetBoundingRadius(100.0f);
            me->SetCombatReach(25.0f);

            me->CastSpell(me, SPELL_STATIC_SHIELD);

            Talk(SAY_NALAK_INTRO);

            uiArcNovaTimer = 39*IN_MILLISECONDS;
            uiLightningTetherTimer = 28*IN_MILLISECONDS;
            uiStormCloudTimer = urand(15, 17)*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_NALAK_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_NALAK_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_NALAK_DEATH);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiArcNovaTimer <= diff)
            {
                me->CastSpell(me, SPELL_ARC_NOVA);
                uiArcNovaTimer = 42*IN_MILLISECONDS;
            }
            else uiArcNovaTimer -= diff;

            if (uiLightningTetherTimer <= diff)
            {
                Talk(SAY_NALAK_LIGHTNING_TETHER);
                me->CastSpell(me, SPELL_LIGHTNING_TETHER);
                uiLightningTetherTimer = 35*IN_MILLISECONDS;
            }
            else uiLightningTetherTimer -= diff;

            if (uiStormCloudTimer <= diff)
            {
                Talk(SAY_NALAK_STORMCLOUD);
                me->CastSpell(me, SPELL_STORMCLOUD);
                uiStormCloudTimer = 24*IN_MILLISECONDS;
            }
            else uiStormCloudTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_nalakAI(creature);
    }
};

// Lightning Tether - 136350
class spell_lightning_tether : public SpellScriptLoader
{
    public:
        spell_lightning_tether() : SpellScriptLoader("spell_lightning_tether") { }

        class spell_lightning_tether_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_lightning_tether_SpellScript);

            void HandleOnHit()
            {
                Unit* target = GetHitUnit();

                if (!target)
                    return;

                target->CastSpell(target, SPELL_LIGHTNING_TETHER_TRIGGER);

                if (Creature* nalak = target->FindNearestCreature(BOSS_NALAK, 99999.0f))
                    if (target->GetExactDist2d(nalak->GetPositionX(), nalak->GetPositionY()) > 30.0f)
                        target->CastSpell(target, SPELL_LIGHTNING_TETHER_30Y);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_lightning_tether_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_lightning_tether_SpellScript();
        }
};

// Haywire Sunreaver Construct #50358#
class npc_sunreaver_construct : public CreatureScript
{
public:

    npc_sunreaver_construct() : CreatureScript("npc_sunreaver_construct")
    {
    }

    struct npc_sunreaver_constructAI : public ScriptedAI
    {
        npc_sunreaver_constructAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiHaywireTimer;

        void Reset()
        {
            uiHaywireTimer = 3*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiHaywireTimer <= diff)
            {
                me->CastSpell(me, SPELL_HAYWIRE);
                uiHaywireTimer = 30*IN_MILLISECONDS;
            }
            else uiHaywireTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_constructAI(creature);
    }
};

// Mumta #69664#
class npc_mumta : public CreatureScript
{
public:

    npc_mumta() : CreatureScript("npc_mumta")
    {
    }

    struct npc_mumtaAI : public ScriptedAI
    {
        npc_mumtaAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiSpiritBoltsTimer;
        uint32 uiDarknessDarknessTimer;
        uint32 uiVengefulSpiritTimer;

        void Reset()
        {
            uiSpiritBoltsTimer = 5*IN_MILLISECONDS;
            uiDarknessDarknessTimer = 10*IN_MILLISECONDS;
            uiVengefulSpiritTimer = 8*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiSpiritBoltsTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_SPIRIT_BOLTS);
                uiSpiritBoltsTimer = 12*IN_MILLISECONDS;
            }
            else uiSpiritBoltsTimer -= diff;

            if (uiDarknessDarknessTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_DARKNESS_DARKNESS);
                uiDarknessDarknessTimer = 15*IN_MILLISECONDS;
            }
            else uiDarknessDarknessTimer -= diff;

            if (uiVengefulSpiritTimer <= diff)
            {
                me->CastSpell(me, SPELL_VENGEFUL_SPIRIT);
                uiVengefulSpiritTimer = 30*IN_MILLISECONDS;
            }
            else uiVengefulSpiritTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mumtaAI(creature);
    }
};

// Ku'lai the Skyclaw #69996# - Tamed Pterrorwing #70141#
class npc_thunder_pterodactyls: public CreatureScript
{
public:

    npc_thunder_pterodactyls() : CreatureScript("npc_thunder_pterodactyls")
    {
    }

    struct npc_thunder_pterodactylsAI : public ScriptedAI
    {
        npc_thunder_pterodactylsAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiBladeWingTimer;
        // uint32 uiSpiritBondTimer;

        void Reset()
        {
            uiBladeWingTimer = 5*IN_MILLISECONDS;
            // uiSpiritBondTimer = 14*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->CastSpell(me->GetVictim(), SPELL_LEAPING_REND);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiBladeWingTimer <= diff)
            {
                me->CastSpell(me, SPELL_BLADEWIND);
                uiBladeWingTimer = 18*IN_MILLISECONDS;
            }
            else uiBladeWingTimer -= diff;

            /*if (uiSpiritBondTimer <= diff)
            {
                me->CastSpell(me, SPELL_SPIRIT_BOND);
                uiSpiritBondTimer = 30*IN_MILLISECONDS;
            }
            else uiSpiritBondTimer -= diff;*/

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thunder_pterodactylsAI(creature);
    }
};

// Progenitus #69997#
class npc_progenitus : public CreatureScript
{
public:

    npc_progenitus() : CreatureScript("npc_progenitus")
    {
    }

    struct npc_progenitusAI : public ScriptedAI
    {
        npc_progenitusAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiUnleashBloodTimer;
        uint32 uiMutagenicBurstTimer;
        uint32 uiEvolutionTimer;

        void Reset()
        {
            uiUnleashBloodTimer = 8*IN_MILLISECONDS;
            uiMutagenicBurstTimer = 4*IN_MILLISECONDS;
            uiEvolutionTimer = 16*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiUnleashBloodTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_UNLEASH_BLOOD);
                uiUnleashBloodTimer = 18*IN_MILLISECONDS;
            }
            else uiUnleashBloodTimer -= diff;

            if (uiMutagenicBurstTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_MUTAGENIC_BURST);
                uiMutagenicBurstTimer = 8*IN_MILLISECONDS;
            }
            else uiMutagenicBurstTimer -= diff;

            if (uiEvolutionTimer <= diff)
            {
                me->CastSpell(me, SPELL_EVOLUTION);
                uiEvolutionTimer = 8*IN_MILLISECONDS;
            }
            else uiEvolutionTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_progenitusAI(creature);
    }
};

// Goda #69998#
class npc_goda : public CreatureScript
{
public:

    npc_goda() : CreatureScript("npc_goda")
    {
    }

    struct npc_godaAI : public ScriptedAI
    {
        npc_godaAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiShellSpinTimer;
        uint32 uiCrystallineShieldTimer;

        void Reset()
        {
            uiShellSpinTimer = 5*IN_MILLISECONDS;
            uiCrystallineShieldTimer = 8*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiShellSpinTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_SHELL_SPIN);
                uiShellSpinTimer = 10*IN_MILLISECONDS;
            }
            else uiShellSpinTimer -= diff;

            if (uiCrystallineShieldTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_CRYSTALLINE_SHIELD);
                uiCrystallineShieldTimer = 8*IN_MILLISECONDS;
            }
            else uiCrystallineShieldTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_godaAI(creature);
    }
};

// God-Hulk Ramuk #69999#
class npc_godhulk_ramuk : public CreatureScript
{
public:

    npc_godhulk_ramuk() : CreatureScript("npc_godhulk_ramuk")
    {
    }

    struct npc_godhulk_ramukAI : public ScriptedAI
    {
        npc_godhulk_ramukAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiCrouchTimer;
        uint32 uiBlessingOfThunderTimer;
        uint32 uiPoundTimer;

        void Reset()
        {
            uiCrouchTimer = 20*IN_MILLISECONDS;
            uiBlessingOfThunderTimer = 14*IN_MILLISECONDS;
            uiPoundTimer = 8*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiCrouchTimer <= diff)
            {
                me->CastSpell(me, SPELL_CROUCH);
                uiCrouchTimer = 30*IN_MILLISECONDS;
            }
            else uiCrouchTimer -= diff;

            if (uiBlessingOfThunderTimer <= diff)
            {
                me->CastSpell(me, SPELL_BLESSING_OF_THUNDER);
                uiBlessingOfThunderTimer = 25*IN_MILLISECONDS;
            }
            else uiBlessingOfThunderTimer -= diff;

            if (uiPoundTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_POUND);
                uiPoundTimer = 12*IN_MILLISECONDS;
            }
            else uiPoundTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_godhulk_ramukAI(creature);
    }
};

// Al'tabim the All-Seeing #70000#
class npc_altabim_the_allseeing : public CreatureScript
{
public:

    npc_altabim_the_allseeing() : CreatureScript("npc_altabim_the_allseeing")
    {
    }

    struct npc_altabim_the_allseeingAI : public ScriptedAI
    {
        npc_altabim_the_allseeingAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiOmenTimer;
        uint32 uiMeteorShowerTimer;
        uint32 uiShadowBoltVolleyTimer;

        void Reset()
        {
            uiOmenTimer = 10*IN_MILLISECONDS;
            uiMeteorShowerTimer = 14*IN_MILLISECONDS;
            uiShadowBoltVolleyTimer = 6*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiOmenTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_OMEN);
                uiOmenTimer = 130*IN_MILLISECONDS;
            }
            else uiOmenTimer -= diff;

            if (uiMeteorShowerTimer <= diff)
            {
                me->CastSpell(me, SPELL_METEOR_SHOWER);
                uiMeteorShowerTimer = 80*IN_MILLISECONDS;
            }
            else uiMeteorShowerTimer -= diff;

            if (uiShadowBoltVolleyTimer <= diff)
            {
                me->CastSpell(me, SPELL_SHADOW_BOLT_VOLLEY);
                uiShadowBoltVolleyTimer = 12*IN_MILLISECONDS;
            }
            else uiShadowBoltVolleyTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_altabim_the_allseeingAI(creature);
    }
};

// Backbreaker Uru #70001#
class npc_backbreaker_uru : public CreatureScript
{
public:

    npc_backbreaker_uru() : CreatureScript("npc_backbreaker_uru")
    {
    }

    struct npc_backbreaker_uruAI : public ScriptedAI
    {
        npc_backbreaker_uruAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiBreakSpineTimer;
        uint32 uiMassiveStompTimer;

        void Reset()
        {
            uiBreakSpineTimer = 6*IN_MILLISECONDS;
            uiMassiveStompTimer = 10*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiBreakSpineTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_BREAK_SPINE);
                uiBreakSpineTimer = 20*IN_MILLISECONDS;
            }
            else uiBreakSpineTimer -= diff;

            if (uiMassiveStompTimer <= diff)
            {
                me->CastSpell(me, SPELL_MASSIVE_STOMP);
                uiMassiveStompTimer = 10*IN_MILLISECONDS;
            }
            else uiMassiveStompTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_backbreaker_uruAI(creature);
    }
};

// Lu-Ban #70002#
class npc_luban : public CreatureScript
{
public:

    npc_luban() : CreatureScript("npc_luban")
    {
    }

    struct npc_lubanAI : public ScriptedAI
    {
        npc_lubanAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiSkyforgedHammersTimer;

        void Reset()
        {
            uiSkyforgedHammersTimer = 5*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->CastSpell(me->GetVictim(), SPELL_STORM_BOLT);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiSkyforgedHammersTimer <= diff)
            {
                me->CastSpell(me, SPELL_SKYFORGED_HAMMERS);
                uiSkyforgedHammersTimer = 20*IN_MILLISECONDS;
            }
            else uiSkyforgedHammersTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lubanAI(creature);
    }
};

// Molthor #70003#
class npc_molthor : public CreatureScript
{
public:

    npc_molthor() : CreatureScript("npc_molthor")
    {
    }

    struct npc_molthorAI : public ScriptedAI
    {
        npc_molthorAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiScarabSwarmTimer;
        uint32 uiHorrificVisageTimer;
        uint32 uiThunderCrushTimer;

        void Reset()
        {
            me->CastSpell(me, SPELL_SCARAB_BROOCH);
            me->CastSpell(me, SPELL_TRIBAL_MASK);
            me->CastSpell(me, SPELL_THUNDERING_SIGIL);

            uiScarabSwarmTimer = 12*IN_MILLISECONDS;
            uiHorrificVisageTimer = 16*IN_MILLISECONDS;
            uiThunderCrushTimer = 8*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiScarabSwarmTimer <= diff)
            {
                me->CastSpell(me, SPELL_SCARAB_SWARM);
                uiScarabSwarmTimer = 45*IN_MILLISECONDS;
            }
            else uiScarabSwarmTimer -= diff;

            if (uiHorrificVisageTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_HORRIFIC_VISAGE);
                uiHorrificVisageTimer = 30*IN_MILLISECONDS;
            }
            else uiHorrificVisageTimer -= diff;

            if (uiThunderCrushTimer <= diff)
            {
                me->CastSpell(me, SPELL_THUNDER_CRUSH);
                uiThunderCrushTimer = 15*IN_MILLISECONDS;
            }
            else uiThunderCrushTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_molthorAI(creature);
    }
};

// Ra'sha #70530#
class npc_rasha : public CreatureScript
{
public:

    npc_rasha() : CreatureScript("npc_rasha")
    {
    }

    struct npc_rashaAI : public ScriptedAI
    {
        npc_rashaAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiBloodyStrikeTimer;
        uint32 uiBloodboltTimer;
        uint32 uiMarkOfBloodTimer;

        void Reset()
        {
            uiBloodyStrikeTimer = 4*IN_MILLISECONDS;
            uiBloodboltTimer = 6*IN_MILLISECONDS;
            uiMarkOfBloodTimer = 12*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiBloodyStrikeTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_BLOODY_STRIKE);
                uiBloodyStrikeTimer = 12*IN_MILLISECONDS;
            }
            else uiBloodyStrikeTimer -= diff;

            if (uiBloodboltTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_BLOODBOLT);
                uiBloodboltTimer = 18*IN_MILLISECONDS;
            }
            else uiBloodboltTimer -= diff;

            if (uiMarkOfBloodTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_MARK_OF_BLOOD);
                uiMarkOfBloodTimer = 30*IN_MILLISECONDS;
            }
            else uiMarkOfBloodTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rashaAI(creature);
    }
};

#define MAX_ZANDALARIS_SPELLS 5
#define MAX_ZANDALARIS_SPELLS_OWNED 3

// War-God Dokah #70096# - Zandalari Warbringer #69769# #69841# #69842# - Zandalari Warscout #69768#
class npc_thunder_zandalaris : public CreatureScript
{
public:

    npc_thunder_zandalaris() : CreatureScript("npc_thunder_zandalaris")
    {
    }

    struct npc_thunder_zandalarisAI : public ScriptedAI
    {
        npc_thunder_zandalarisAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiScarabSwarmTimer;
        uint32 uiHorrificVisageTimer;
        uint32 uiMeteorShowerTimer;
        uint32 uiVengefulSpiritTimer;
        uint32 uiThunderCrushTimer;

        void Reset()
        {
            std::vector<uint32> spellIds;
            for (uint8 i = 0; i < MAX_ZANDALARIS_SPELLS; i++)
                spellIds.push_back(GetZandalariSpell(i));

            for (uint8 maxSpellsOwned = 0; maxSpellsOwned < MAX_ZANDALARIS_SPELLS_OWNED; maxSpellsOwned++)
            {
                uint32 spellId = Trinity::Containers::SelectRandomContainerElement<std::vector<uint32> >(spellIds);
                me->CastSpell(me, spellId);
            }

            uiScarabSwarmTimer      = 12*IN_MILLISECONDS;
            uiHorrificVisageTimer   = 16*IN_MILLISECONDS;
            uiMeteorShowerTimer     = 20*IN_MILLISECONDS;
            uiVengefulSpiritTimer   = 25*IN_MILLISECONDS;
            uiThunderCrushTimer     = 8*IN_MILLISECONDS;
            
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiScarabSwarmTimer <= diff)
            {
                if (me->HasAura(SPELL_SCARAB_BROOCH))
                    me->CastSpell(me, SPELL_SCARAB_SWARM);

                uiScarabSwarmTimer = 45*IN_MILLISECONDS;
            }
            else uiScarabSwarmTimer -= diff;

            if (uiHorrificVisageTimer <= diff)
            {
                if (me->HasAura(SPELL_TRIBAL_MASK))
                    me->CastSpell(me->GetVictim(), SPELL_HORRIFIC_VISAGE);

                uiHorrificVisageTimer = 30*IN_MILLISECONDS;
            }
            else uiHorrificVisageTimer -= diff;

            if (uiMeteorShowerTimer <= diff)
            {
                if (me->HasAura(SPELL_STAR_MAP))
                    me->CastSpell(me, SPELL_METEOR_SHOWER_2);

                uiMeteorShowerTimer = 30*IN_MILLISECONDS;
            }
            else uiMeteorShowerTimer -= diff;

            if (uiVengefulSpiritTimer <= diff)
            {
                if (me->HasAura(SPELL_SPIRIT_CHARM))
                    me->CastSpell(me, SPELL_VENGEFUL_SPIRIT_2);

                uiVengefulSpiritTimer = 45*IN_MILLISECONDS;
            }
            else uiVengefulSpiritTimer -= diff;

            if (uiThunderCrushTimer <= diff)
            {
                if (me->HasAura(SPELL_THUNDERING_SIGIL))
                    me->CastSpell(me, SPELL_THUNDER_CRUSH);

                uiThunderCrushTimer = 15*IN_MILLISECONDS;
            }
            else uiThunderCrushTimer -= diff;

            DoMeleeAttackIfReady();
        }

        uint32 GetZandalariSpell(uint8 value)
        {
            uint32 spellId;

            switch (value)
            {
                case 0:
                    spellId = SPELL_SCARAB_BROOCH;
                    break;
                case 1:
                    spellId = SPELL_TRIBAL_MASK;
                    break;
                case 2:
                    spellId = SPELL_STAR_MAP;
                    break; 
                case 3:
                    spellId = SPELL_SPIRIT_CHARM;
                    break;
                case 4:
                    spellId = SPELL_THUNDERING_SIGIL;
                    break;
                default:
                    spellId = 0;
                    break;
            }

            return spellId;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thunder_zandalarisAI(creature);
    }
};

// Spirit of Warlord Teng #69471#
class npc_spirit_of_warlord_teng : public CreatureScript
{
public:

    npc_spirit_of_warlord_teng() : CreatureScript("npc_spirit_of_warlord_teng")
    {
    }

    struct npc_spirit_of_warlord_tengAI : public ScriptedAI
    {
        npc_spirit_of_warlord_tengAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiSpiritSlashTimer;
        uint32 uiSpiritSWrathTimer;

        void Reset()
        {
            if (me->HasAura(SPELL_TENG_GHOST_VISUAL_2))
                me->RemoveAurasDueToSpell(SPELL_TENG_GHOST_VISUAL_2);

            if (!me->HasAura(SPELL_TENG_GHOST_VISUAL_1))
            me->CastSpell(me, SPELL_TENG_GHOST_VISUAL_1);

            uiSpiritSlashTimer = 6*IN_MILLISECONDS;
            uiSpiritSWrathTimer = 12*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (me->HasAura(SPELL_TENG_GHOST_VISUAL_1))
                me->RemoveAurasDueToSpell(SPELL_TENG_GHOST_VISUAL_1);

            if (!me->HasAura(SPELL_TENG_GHOST_VISUAL_2))
                me->CastSpell(me, SPELL_TENG_GHOST_VISUAL_2);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiSpiritSlashTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_SPIRIT_SLASH);
                uiSpiritSlashTimer = 10*IN_MILLISECONDS;
            }
            else uiSpiritSlashTimer -= diff;

            if (uiSpiritSWrathTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_SPIRIT_S_WRATH);
                uiSpiritSWrathTimer = 18*IN_MILLISECONDS;
            }
            else uiSpiritSWrathTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spirit_of_warlord_tengAI(creature);
    }
};

class spell_incantation_of_gura : public SpellScriptLoader
{
public:
    spell_incantation_of_gura() : SpellScriptLoader("spell_incantation_of_gura") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            Creature* pCreature = GetHitCreature();
            Unit* pCaster = GetCaster();

            if (!pCreature || !pCaster)
                return;

            pCreature->RemoveAllAuras();
            
            if (pCreature->AI())
                pCreature->AI()->AttackStart(pCaster);

            pCreature->CastSpell(pCreature, 123625, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

void AddSC_isle_of_thunder()
{
    new boss_nalak();
    new spell_lightning_tether();

    new npc_sunreaver_construct();
    new npc_mumta();
    new npc_thunder_pterodactyls();
    new npc_progenitus();
    new npc_goda();
    new npc_godhulk_ramuk();
    new npc_altabim_the_allseeing();
    new npc_backbreaker_uru();
    new npc_luban();
    new npc_molthor();
    new npc_rasha();
    new npc_thunder_zandalaris();
    new npc_spirit_of_warlord_teng();

    new spell_incantation_of_gura();
}