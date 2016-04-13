#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

enum Spells
{
    // Oondasta
    SPELL_CRUSH_1 = 137504,
    SPELL_FRILL_BLAST = 137505,
    SPELL_GROWING_FURY = 137502,
    SPELL_PIERCING_ROAR_1 = 137457,
    SPELL_SPIRITFIRE_BEAM = 137508, // 137511
    SPELL_ALPHA_MALE = 138391,

    // Primal Devilsaur
    SPELL_CRUSH_2 = 138765,
    SPELL_PIERCING_ROAR_2 = 138766,

    // Zandalari Dinomancer
    SPELL_DINO_FORM = 138771,
    SPELL_DINO_MENDING = 138770,

    // Pterrowing Skyscreamer
    SPELL_SKYCALL = 138817,

    // Primal Direhorn
    SPELL_DOUBLE_SWIPE = 138772,
    SPELL_TRIHORN_CHARGE = 138769,
    SPELL_TRIHORN_CHARGE_TRIGGER = 138777,
    SPELL_TRIPLE_PUNCTURE = 138768,
};

enum Texts
{
    // Dohaman
    SAY_DOHAMAN_AGGRO = 0,
    SAY_DOHAMAN_INTRO = 1,
};

enum Npcs
{
    NPC_DOHAMAN_THE_BEAST_LORD = 69926,
};

enum Items
{
    ITEM_CRACKED_PRIMAL_EGG = 94296
};

// Oondasta #69161#
class boss_oondasta : public CreatureScript
{
public:

    boss_oondasta() : CreatureScript("boss_oondasta")
    {
    }

    struct boss_oondastaAI : public ScriptedAI
    {
        boss_oondastaAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint64 dohamanGUID;
        uint32 uiCrushTimer;
        uint32 uiFrillBlastTimer;
        uint32 uiGrowingFuryTimer;
        uint32 uiPiercingRoarTimer;
        uint32 uiSpiritfireBeamTimer;

        void Reset() override
        {
            uiCrushTimer =          30*IN_MILLISECONDS;
            uiFrillBlastTimer =     40*IN_MILLISECONDS;
            uiGrowingFuryTimer =    15*IN_MILLISECONDS;
            uiPiercingRoarTimer =   20*IN_MILLISECONDS;
            uiSpiritfireBeamTimer = 12*IN_MILLISECONDS;

            me->RemoveAurasDueToSpell(SPELL_ALPHA_MALE);

            if (TempSummon* dohaman = me->SummonCreature(NPC_DOHAMAN_THE_BEAST_LORD, 6038.727539f, 1109.816528f, 55.849739f, 5.997171f, TEMPSUMMON_MANUAL_DESPAWN))
            {
                dohaman->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                dohaman->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                dohaman->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                dohaman->HandleEmoteCommand(EMOTE_STATE_COWER);

                if (dohaman->AI())
                    dohaman->AI()->Talk(SAY_DOHAMAN_INTRO);

                dohamanGUID = dohaman->GetGUID().GetEntry();
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->CastSpell(me, SPELL_ALPHA_MALE);
            me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);

            if (Creature *creature = me)
            {
                if (TempSummon* dohaman = creature->ToTempSummon())
                {
                    if (dohaman->AI())
                        dohaman->AI()->Talk(SAY_DOHAMAN_AGGRO);

                    me->Kill(dohaman);
                    dohaman->DespawnOrUnsummon(10*IN_MILLISECONDS);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiCrushTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_CRUSH_1);
                uiCrushTimer = 26*IN_MILLISECONDS;
            }
            else uiCrushTimer -= diff;

            if (uiFrillBlastTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_FRILL_BLAST);
                uiFrillBlastTimer = urand(20, 25)*IN_MILLISECONDS;
            }
            else uiFrillBlastTimer -= diff;

            if (uiGrowingFuryTimer <= diff)
            {
                me->CastSpell(me, SPELL_GROWING_FURY);
                uiGrowingFuryTimer = 25*IN_MILLISECONDS;
            }
            else uiGrowingFuryTimer -= diff;

            if (uiPiercingRoarTimer <= diff)
            {
                me->CastSpell(me, SPELL_PIERCING_ROAR_1);
                uiPiercingRoarTimer =  urand(20, 55)*IN_MILLISECONDS;
            }
            else uiPiercingRoarTimer -= diff;

            if (uiSpiritfireBeamTimer <= diff)
            {
                me->CastSpell(SelectTarget(SELECT_TARGET_RANDOM), SPELL_SPIRITFIRE_BEAM);
                uiSpiritfireBeamTimer = urand(10, 13)*IN_MILLISECONDS;
            }
            else uiSpiritfireBeamTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_oondastaAI(creature);
    }
};

// Primal Devilsaur #70011# #70010# #70008# #70009# #69991#
class npc_primal_devilsaur : public CreatureScript
{
public:

    npc_primal_devilsaur() : CreatureScript("npc_primal_devilsaur")
    {
    }

    struct npc_primal_devilsaurAI : public ScriptedAI
    {
        npc_primal_devilsaurAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiCrushTimer;
        uint32 uiPiercingRoarTimer;

        void Reset() override
        {
            uiCrushTimer = 5*IN_MILLISECONDS;
            uiPiercingRoarTimer = 20*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiCrushTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_CRUSH_2);
                uiCrushTimer = 5*IN_MILLISECONDS;
            }
            else uiCrushTimer -= diff;

            if (uiPiercingRoarTimer <= diff)
            {
                me->CastSpell(me, SPELL_PIERCING_ROAR_2);
                uiPiercingRoarTimer =  8*IN_MILLISECONDS;
            }
            else uiPiercingRoarTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_primal_devilsaurAI(creature);
    }
};

// Zandalari Dinomancer #69925#
class npc_zandalari_dinomancer : public CreatureScript
{
public:

    npc_zandalari_dinomancer() : CreatureScript("npc_zandalari_dinomancer")
    {
    }

    struct npc_zandalari_dinomancerAI : public ScriptedAI
    {
        npc_zandalari_dinomancerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiDinoMendingTimer;
        bool dinoForm;

        void Reset() override
        {
            SetEquipmentSlots(true);

            uiDinoMendingTimer = 10*IN_MILLISECONDS;
            dinoForm = false;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!dinoForm && HealthBelowPct(25))
            {
                me->CastSpell(me, SPELL_DINO_FORM);
                SetEquipmentSlots(false, 0, 0, 0);
                dinoForm = true;
            }

            if (uiDinoMendingTimer <= diff)
            {
                me->CastSpell(me, SPELL_DINO_MENDING);
                uiDinoMendingTimer = 15*IN_MILLISECONDS;
            }
            else uiDinoMendingTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_zandalari_dinomancerAI(creature);
    }
};

// Pterrorwing Skyscreamer #70020# #70021#
class npc_pterrorwing_skyscreamer : public CreatureScript
{
public:

    npc_pterrorwing_skyscreamer() : CreatureScript("npc_pterrorwing_skyscreamer")
    {
    }

    struct npc_pterrorwing_skyscreamerAI : public ScriptedAI
    {
        npc_pterrorwing_skyscreamerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiSkycallTimer;

        void Reset() override
        {
            uiSkycallTimer = 2*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiSkycallTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_SKYCALL);
                uiSkycallTimer = 6*IN_MILLISECONDS;
            }
            else uiSkycallTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pterrorwing_skyscreamerAI(creature);
    }
};

// Young Primal Devilsaur #70006# #70004# #69993# #70005# #70007#
class npc_young_primal_devilsaur : public CreatureScript
{
public:

    npc_young_primal_devilsaur() : CreatureScript("npc_young_primal_devilsaur")
    {
    }

    struct npc_young_primal_devilsaurAI : public ScriptedAI
    {
        npc_young_primal_devilsaurAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiCrushTimer;

        void Reset() override
        {
            uiCrushTimer = 2*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiCrushTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_CRUSH_2);
                uiCrushTimer = 6*IN_MILLISECONDS;
            }
            else uiCrushTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_young_primal_devilsaurAI(creature);
    }
};

// Primal Direhorn #70017# #70018# #70019# #70016# #69983#
class npc_primal_direhorn : public CreatureScript
{
public:

    npc_primal_direhorn() : CreatureScript("npc_primal_direhorn")
    {
    }

    struct npc_primal_direhornAI : public ScriptedAI
    {
        npc_primal_direhornAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiDoubleSwipeTimer;
        uint32 uiTriplePunctureTimer;

        void Reset() override
        {
            uiDoubleSwipeTimer = 8*IN_MILLISECONDS;
            uiTriplePunctureTimer = 3*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->CastSpell(me->GetVictim(), SPELL_TRIHORN_CHARGE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiDoubleSwipeTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_DOUBLE_SWIPE);
                uiDoubleSwipeTimer = 10*IN_MILLISECONDS;
            }
            else uiDoubleSwipeTimer -= diff;

            if (uiTriplePunctureTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_TRIPLE_PUNCTURE);
                uiTriplePunctureTimer = 8*IN_MILLISECONDS;
            }
            else uiTriplePunctureTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_primal_direhornAI(creature);
    }
};

// Primal Direhorn Hatchling #70014# #70015# #69992# #70012# #70013#
class npc_primal_direhorn_hatchling : public CreatureScript
{
public:

    npc_primal_direhorn_hatchling() : CreatureScript("npc_primal_direhorn_hatchling")
    {
    }

    struct npc_primal_direhorn_hatchlingAI : public ScriptedAI
    {
        npc_primal_direhorn_hatchlingAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiTriplePunctureTimer;

        void Reset() override
        {
            uiTriplePunctureTimer = 3*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->CastSpell(me->GetVictim(), SPELL_TRIHORN_CHARGE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiTriplePunctureTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), SPELL_TRIPLE_PUNCTURE);
                uiTriplePunctureTimer = 8*IN_MILLISECONDS;
            }
            else uiTriplePunctureTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_primal_direhorn_hatchlingAI(creature);
    }
};

// Trihorn Charge - 138769
class spell_trihorn_charge : public SpellScriptLoader
{
    public:
        spell_trihorn_charge() : SpellScriptLoader("spell_trihorn_charge") { }

        class spell_trihorn_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trihorn_charge_SpellScript);

            bool Validate(SpellInfo const* /*SpellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TRIHORN_CHARGE))
                    return false;

                return true;
            }

            void HandleOnHit()
            {
                if (!GetHitUnit())
                    return;

                if (GetCaster())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_TRIHORN_CHARGE_TRIGGER);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_trihorn_charge_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_trihorn_charge_SpellScript();
        }
};




class item_primal_egg : public ItemScript
{
public:
    item_primal_egg() : ItemScript("item_primal_egg") { }

    bool OnExpire(Player* player, ItemTemplate const* proto) override
    {
        player->AddItem(ITEM_CRACKED_PRIMAL_EGG, 1);
        return true;
    }
};

void AddSC_isle_of_giants()
{
    new boss_oondasta();
    new npc_primal_devilsaur();
    new npc_zandalari_dinomancer();
    new npc_pterrorwing_skyscreamer();
    new npc_young_primal_devilsaur();
    new npc_primal_direhorn();
    new npc_primal_direhorn_hatchling();
    new spell_trihorn_charge();
    new item_primal_egg();
}
