#include "ScriptMgr.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ThreatManager.h"
#include "GridNotifiersImpl.h"
#include "CreatureAIImpl.h"
#include "CellImpl.h"
#include "Custom/AI/CustomAI.h"

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
    SPELL_MASS_DISPEL           = 32375,
    SPELL_WEAKENED_SOUL         = 6788
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
            scheduler
                .Schedule(5ms, [this](TaskContext heal)
                {
                    if (Unit* target = DoSelectLowestHpFriendly(30.0f, 50))
                        DoCast(target, urand(0, 70) ? SPELL_FLASH_HEAL : SPELL_REJUVENATION);
                    heal.Repeat(8s);
                })
                .Schedule(5ms, [this](TaskContext powser_word_shield)
                {
                    Unit* target = DoSelectBelowHpPctFriendly(30.0f, 20, false);
                    if (target && !target->HasAura(SPELL_WEAKENED_SOUL))
                    {
                        DoCast(target, SPELL_POWER_WORD_SHIELD);
                        DoCast(target, SPELL_WEAKENED_SOUL);
                    }
                    powser_word_shield.Repeat(3s);
                })
                .Schedule(5ms, [this](TaskContext smite)
                {
                    DoCastVictim(SPELL_SMITE);
                    smite.Repeat(1180ms);
                })
                .Schedule(8s, [this](TaskContext holy_fire)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_HOLY_FIRE);
                    holy_fire.Repeat(5s, 8s);
                })
                .Schedule(2s, [this](TaskContext mass_dispel)
                {
                    std::list<Unit*> targets = DoFindFriendlySuffering(20.0f);
                    if (!targets.empty() && targets.size() > 3)
                    {
                        if (Unit* victim = me->GetVictim())
                        {
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

        void JustDied(Unit* /*killer*/) override
        {
            // Que pour Medic Helaina
            if (me->GetEntry() != 100014)
                return;

            if (Creature* spiritHealder = DoSummon(NPC_SPIRIT_HEALER, me->GetPosition(), 13000, TEMPSUMMON_TIMED_DESPAWN))
            {
                if (Creature* fx = DoSummon(NPC_INVISIBLE_STALKER, me->GetPosition(), 13000, TEMPSUMMON_TIMED_DESPAWN))
                {
                    fx->AddAura(SPELL_SPIRIT_HEALER_VISUAL, fx);
                    fx->SetObjectScale(1.5f);
                }

                double angle = 72;
                for (int i = 0; i < 5; ++i)
                {
                    Position pos = GetPositionAround(spiritHealder, angle, spiritHealder->GetObjectScale() * 3.f);
                    if (Creature* lightwell = DoSummon(NPC_LIGHTWELL, pos, 13000, TEMPSUMMON_TIMED_DESPAWN))
                        lightwell->CastSpell(lightwell, SPELL_MASS_HEAL);
                    angle += 72;
                }
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!hasUseDamageReduction && !me->HasAura(SPELL_PAIN_SUPPRESSION) && HealthBelowPct(20))
            {
                DoCast(SPELL_PAIN_SUPPRESSION);

                hasUseDamageReduction = true;

                scheduler
                    .Schedule(2s, [this](TaskContext /*context*/)
                    {
                        DoCast(SPELL_MANA_POTION);
                        DoCast(SPELL_HEALTH_POTION);
                    })
                    .Schedule(1min, [this](TaskContext /*context*/)
                    {
                        hasUseDamageReduction = false;
                    });
            }
        }

        private:
        bool hasUseDamageReduction;

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
