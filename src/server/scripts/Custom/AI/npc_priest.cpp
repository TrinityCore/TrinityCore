#include "ScriptMgr.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ThreatManager.h"
#include "GridNotifiersImpl.h"
#include "CreatureAIImpl.h"
#include "CellImpl.h"
#include "CustomAI.h"

#include <iostream>

enum Spells
{
    SPELL_FLASH_HEAL            = 100015,
    SPELL_SMITE                 = 100016,
    SPELL_POWER_WORD_SHIELD     = 100017,
    SPELL_HOLY_FIRE             = 100018,
    SPELL_MASS_HEAL             = 100019,
    SPELL_PAIN_SUPPRESSION      = 100020,
    SPELL_MANA_POTION           = 100022,
    SPELL_HEALTH_POTION         = 100023,
    SPELL_REJUVENATION          = 100024,
    SPELL_SPIRIT_HEALER_VISUAL  = 70571,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_PRAYER_OF_MENDING     = 48113,
    SPELL_MASS_DISPEL           = 32375,
    SPELL_ETERNAL_AFFECTION     = 30878,
    SPELL_WEAKENED_SOUL         = 6788
};

enum Phase
{
    PHASE_HEALING               = 1,
    PHASE_COMBAT,
    PHASE_ENDANGERED
};

enum Misc
{
    NPC_LIGHTWELL               = 100013,
    NPC_SPIRIT_HEALER           = 100015,
    NPC_INVISIBLE_STALKER       = 32780
};

class npc_priest : public CreatureScript
{
    public:
    npc_priest() : CreatureScript("npc_priest") {}

    struct npc_priestAI : public CustomAI
    {
        npc_priestAI(Creature* creature) : CustomAI(creature), hasUseDamageReduction(false)
        {
            SetCombatMovement(false);
        }

        void Initialize() override
        {
            CustomAI::Initialize();

            hasUseDamageReduction = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            SetInCombatPhase();
        }

        void JustDied(Unit* /*killer*/) override
        {
            // Que pour Medic Helaina
            if (me->GetEntry() != 100014)
                return;

            if (Creature* spiritHealder = DoSummon(NPC_SPIRIT_HEALER, me->GetPosition(), 13s, TEMPSUMMON_TIMED_DESPAWN))
            {
                if (Creature* fx = DoSummon(NPC_INVISIBLE_STALKER, me->GetPosition(), 13s, TEMPSUMMON_TIMED_DESPAWN))
                {
                    fx->AddAura(SPELL_SPIRIT_HEALER_VISUAL, fx);
                    fx->SetObjectScale(1.5f);
                }

                double angle = 72;
                for (int i = 0; i < 5; ++i)
                {
                    Position pos = GetPositionAround(spiritHealder, angle, spiritHealder->GetObjectScale() * 3.f);
                    if (Creature* lightwell = DoSummon(NPC_LIGHTWELL, pos, 13s, TEMPSUMMON_TIMED_DESPAWN))
                        lightwell->CastSpell(lightwell, SPELL_MASS_HEAL);
                    angle += 72;
                }
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!hasUseDamageReduction && !me->HasAura(SPELL_PAIN_SUPPRESSION) && HealthBelowPct(20))
            {
                scheduler.CancelGroup(PHASE_HEALING);
                scheduler.CancelGroup(PHASE_COMBAT);

                DoCast(SPELL_PAIN_SUPPRESSION);

                hasUseDamageReduction = true;

                scheduler
                    .Schedule(1s, PHASE_ENDANGERED, [this](TaskContext /*context*/)
                    {
                        me->Say(DAMAGE_TAKEN_01, LANG_COMMON);

                        DoCast(SPELL_MANA_POTION);
                        DoCast(SPELL_ETERNAL_AFFECTION);
                    })
                    .Schedule(3s, PHASE_ENDANGERED, [this](TaskContext /*context*/)
                    {
                        SetInCombatPhase();
                    })
                    .Schedule(1min, PHASE_ENDANGERED, [this](TaskContext /*context*/)
                    {
                        hasUseDamageReduction = false;
                    });
            }
        }

        private:
        bool hasUseDamageReduction;
        const char* DAMAGE_TAKEN_01 = "La lumière me vient en aide !";

        Position GetPositionAround(Unit* target, double angle, float radius)
        {
            double ang = angle * (M_PI / 180);
            Position pos;
            pos.m_positionX = target->GetPositionX() + radius * sin(ang);
            pos.m_positionY = target->GetPositionY() + radius * cos(ang);
            pos.m_positionZ = target->GetPositionZ();
            return pos;
        }

        std::list<Unit*> DoFindFriendlySuffering(float range)
        {
            std::list<Unit*> result;

            // First get all friendly creatures
            std::list<Unit*> friends;
            Trinity::AllFriendlyInRange check(me, range);
            Trinity::UnitListSearcher<Trinity::AllFriendlyInRange> searcher(me, friends, check);
            Cell::VisitGridObjects(me, searcher, range);

            for (Unit* unit : friends)
            {
                DispelChargesList dispelList;
                unit->GetDispellableAuraList(unit, DISPEL_ALL_MASK, dispelList);
                if (dispelList.empty())
                    continue;

                result.push_back(unit);
            }

            return result;
        }

        void SetInCombatPhase()
        {
            scheduler
                .Schedule(5ms, PHASE_HEALING, [this](TaskContext rejuvenation)
                {
                    if (Unit* target = DoSelectBelowHpPctFriendly(30.0f, 80, false))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_REJUVENATION);
                        rejuvenation.Repeat(4s);
                    }
                    else
                    {
                        rejuvenation.Repeat(1s);
                    }
                })
                .Schedule(5ms, PHASE_HEALING, [this](TaskContext heal)
                {
                    if (Unit* target = DoSelectBelowHpPctFriendly(30.0f, 50, false))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_FLASH_HEAL);
                        heal.Repeat(4s);
                    }
                    else
                    {
                        heal.Repeat(1s);
                    }
                })
                .Schedule(5ms, PHASE_HEALING, [this](TaskContext prayer_of_mending)
                {
                    if (Unit* target = DoSelectBelowHpPctFriendly(30.0f, 40, false))
                    {
                        CastSpellExtraArgs args;
                        args.AddSpellBP0(3000);

                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_PRAYER_OF_MENDING, args);
                        prayer_of_mending.Repeat(10s, 14s);
                    }
                    else
                    {
                        prayer_of_mending.Repeat(2s);
                    }
                })
                .Schedule(5ms, PHASE_HEALING, [this](TaskContext power_word_shield)
                {
                    Unit* target = DoSelectBelowHpPctFriendly(30.0f, 20, false);
                    if (target && !target->HasAura(SPELL_WEAKENED_SOUL))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_POWER_WORD_SHIELD);
                        DoCast(target, SPELL_WEAKENED_SOUL);
                        power_word_shield.Repeat(3s);
                    }
                    else
                    {
                        power_word_shield.Repeat(5ms);
                    }
                })
                .Schedule(5ms, PHASE_COMBAT, [this](TaskContext smite)
                {
                    DoCastVictim(SPELL_SMITE);
                    smite.Repeat(3s);
                })
                .Schedule(8s, PHASE_COMBAT, [this](TaskContext holy_fire)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_HOLY_FIRE);
                    holy_fire.Repeat(5s, 10s);
                })
                .Schedule(2s, PHASE_HEALING, [this](TaskContext mass_dispel)
                {
                    std::list<Unit*> targets = DoFindFriendlySuffering(20.0f);
                    if (!targets.empty() && targets.size() > 3)
                    {
                        if (Unit* victim = me->GetVictim())
                        {
                            me->InterruptNonMeleeSpells(true);
                            me->CastSpell(victim->GetPosition(), SPELL_MASS_DISPEL);
                            mass_dispel.Repeat(25s, 30s);
                        }
                    }
                    else
                    {
                        mass_dispel.Repeat(2s);
                    }
                });
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_priestAI(creature);
    }
};

void AddSC_npc_priest()
{
    new npc_priest();
}
