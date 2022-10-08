/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ObjectMgr.h"


#define MAX_HEALTH_POINTS 392500000
#define INITIAL_HEALTH_POINTS 98125000
#define INCREMENTAL 3212500

const float _chargePos[5][3] = 
{
    { -740.79f, -5019.06f, -6.277f },
    { -740.41f, -4962.37f, -6.277f },
    { -563.80f, -4963.35f, -6.277f },
    { -563.88f, -5069.82f, -6.277f },
    { -737.17f, -5072.31f, -6.277f }
};

enum eSpells
{
    SPELL_NIUZAO_CHARGE = 144608,
    SPELL_NIUZAO_HEADBUTT = 144610,
    SPELL_NIUZAO_MASSIVE_QUAKE = 144611,
    SPELL_NIUZAO_OXEN_FORTITUDE = 144606,
    SPELL_NIUZAO_OXEN_FORTITUDE_ACTIVE = 144607
};

enum eEffects
{
    EFFECT_0,
    EFFECT_1,
    EFFECT_2,
    EFFECT_3,
};

enum eEvents
{
    EVENT_NIUZAO_OXEN_FORTITUDE = 1,
    EVENT_NIUZAO_HEADBUTT,
    EVENT_NIUZAO_MASSIVE_QUAKE,
    EVENT_NIUZAO_HEALTH_66_PERCENT,
    EVENT_NIUZAO_HEALTH_33_PERCENT,
    EVENT_NIUZAO_DEFEATED,
    EVENT_NIUZAO_DEATH,
    EVENT_NIUZAO_CHARGE,
    EVENT_NIUZAO_SHAO_DO_INTRO,
    EVENT_NIUZAO_SHAO_DO_INTRO_ATTACKABLE,
    EVENT_NIUZAO_SHAO_DO_OUTRO
};

enum eSays
{
    SAY_AGGRO = 0,
    SAY_INTRO = 1,
    SAY_DEATH = 2,
    SAY_KILL = 3,
    SAY_SPELL_1 = 4,
    SAY_SPELL_2 = 5,
    SAY_SPELL_3 = 6
};

enum eActions
{
    ACTION_NIUZAO_CHARGE_66 = 1,
    ACTION_NIUZAO_CHARGE_33,
    ACTION_NIUZAO_CHARGE
};

enum eMovement
{
    MOVEMENT_NIUZAO_CHARGE = 2
};

enum Factions
{
    FACTION_FRIENDLY = 35,
    FACTION_HOSTILE_NEUTRAL = 31
};

#define MIDDLE_FACING_ANGLE 1.573f

enum Datas
{
    DATA_NIUZAO = 0,
};

enum Bosses
{
    BOSS_CHI_JI = 71952,
    BOSS_NIUZAO = 71954,
    BOSS_YU_LON = 71955,
    BOSS_XUEN = 71953,
    BOSS_ORDOS = 72057
};

#define CELESTIAL_COURT_BOSS_INTRO_TIMER_1 1000
#define CELESTIAL_COURT_BOSS_INTRO_TIMER_2 15000

static Position _timelessIsleMiddle = { -650.04f, -5016.84f, -6.27f, 1.573f };

enum EmperorActions
{
    ACTION_XUEN = 1,
    ACTION_CHIJI = 2,
    ACTION_NIUZAO = 3,
    ACTION_YULON = 4,
    ACTION_MOVE_TO_MIDDLE = 100
};

enum EmprerorTalk
{
    EMPEROR_TALK_INTRO_YULON,
    EMPEROR_TALK_INTRO_XUEN,
    EMPEROR_TALK_INTRO_CHIJI,
    EMPEROR_TALK_INTRO_NIUZAO,
    EMPEROR_TALK_OUTRO_YULON,
    EMPEROR_TALK_OUTRO_XUEN,
    EMPEROR_TALK_OUTRO_CHIJI,
    EMPEROR_TALK_OUTRO_NIUZAO,
    EMPEROR_TALK_INTRO
};

enum Creatures
{
    NPC_SKUNKY_ALEMENTAL = 71908,
    NPC_EMPEROR_SHAOHAO_TI = 73303,
    NPC_ETERNAL_KILNMASTER = 72896,
    NPC_HIGH_PRIEST_OF_ORDOS = 72898,
    NPC_BLAZEBOUND_CHANTER = 72897,

    // Generic (Invisible)
    NPC_TIME_LOST_SHRINE_TRIGGER = 73461 // I think this is the correct ID :P
};

class boss_niuzao : public CreatureScript
{
    public:
        boss_niuzao() : CreatureScript("boss_niuzao") { }

        struct boss_niuzaoAI : public BossAI
        {
            boss_niuzaoAI(Creature* creature) : BossAI(creature, DATA_NIUZAO) { }

            void Reset()
            {
                events.Reset();
                _Reset();

                if (me->getFaction() == FACTION_HOSTILE_NEUTRAL)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFacingTo(MIDDLE_FACING_ANGLE);
                }

                me->RemoveAllAuras();
                summons.DespawnAll();
                _charges = 0;
                me->SetWalk(true);
                me->setActive(true);
            }

            void EnterCombat(Unit* /*target*/)
            {
                me->SetWalk(false);
                death = false;
                Talk(SAY_AGGRO);
                events.ScheduleEvent(urand(EVENT_NIUZAO_OXEN_FORTITUDE, EVENT_NIUZAO_MASSIVE_QUAKE), urand(10000, 20000));
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_NIUZAO_CHARGE_66:
                    {
                        DoCast(SPELL_NIUZAO_CHARGE);
                        Talk(SAY_SPELL_1);
                        break;
                    }
                    case ACTION_NIUZAO_CHARGE_33:
                    {
                        DoCast(SPELL_NIUZAO_CHARGE);
                        Talk(SAY_SPELL_2);
                        break;
                    }
                    case ACTION_NIUZAO_CHARGE:
                    {
                        events.ScheduleEvent(urand(EVENT_NIUZAO_OXEN_FORTITUDE, EVENT_NIUZAO_MASSIVE_QUAKE), urand(10000, 20000));
                        me->GetMotionMaster()->MoveCharge(_chargePos[_charges][0], _chargePos[_charges][1], _chargePos[_charges][2], 15.0f, MOVEMENT_NIUZAO_CHARGE);
                        break;
                    }
                    default: break;
                };
            }

            void DamageTaken(Unit* caster, uint32 &dmg)
            {
                if (me->GetHealthPct() > 66.6f)
                {
                    _charge66 = false;
                    _charge33 = false;
                }

                if (me->GetHealthPct() < 66.6f && !_charge66)
                {
                    _charge66 = true;
                    events.ScheduleEvent(EVENT_NIUZAO_HEALTH_66_PERCENT, 500);
                }

                if (me->GetHealthPct() < 33.3f && !_charge33)
                {
                    _charge33 = true;
                    events.ScheduleEvent(EVENT_NIUZAO_HEALTH_33_PERCENT, 500);
                }
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case 1:
                    {
                        events.ScheduleEvent(EVENT_NIUZAO_SHAO_DO_INTRO, CELESTIAL_COURT_BOSS_INTRO_TIMER_1);
                        me->setFaction(FACTION_HOSTILE_NEUTRAL);
                        me->SetFacingTo(MIDDLE_FACING_ANGLE);
                        me->SetHomePosition(_timelessIsleMiddle);
                        break;
                    }
                    case MOVEMENT_NIUZAO_CHARGE:
                    {
                        if (_charges >= 4)
                        {
                            _charges = 0;
                            me->RemoveAura(SPELL_NIUZAO_CHARGE);
                            events.ScheduleEvent(urand(EVENT_NIUZAO_OXEN_FORTITUDE, EVENT_NIUZAO_MASSIVE_QUAKE), urand(8500, 15000));
                            return;
                        }

                        events.ScheduleEvent(EVENT_NIUZAO_CHARGE, 100);
                        break;
                    }
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
                        return;
            }

            void UpdateHealth()
            {
                if (!me->isInCombat())
                    return;

                // Get the Threat List
                std::list<HostileReference*> threatlist = me->getThreatManager().getThreatList();
                if (threatlist.empty()) // He doesn't have anyone in his threatlist, useless to continue
                    return;

                uint8 count = 0;
                for (auto itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                    if (Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                        if (unit->IsWithinDist(me, 100.0f))
                            count++;

                uint32 hp = me->GetMaxHealth() - me->GetHealth();
                uint32 newhp = std::min<uint32>((INCREMENTAL * count), MAX_HEALTH_POINTS);
                if (newhp != me->GetMaxHealth() && newhp > INITIAL_HEALTH_POINTS)
                {
                    me->SetMaxHealth(std::min<uint32>((me->GetMaxHealth() * count), MAX_HEALTH_POINTS));
                    me->SetHealth(newhp - hp);
                }
            }; 

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_NIUZAO_SHAO_DO_INTRO:
                    {
                        Talk(SAY_INTRO);
                        events.ScheduleEvent(EVENT_NIUZAO_SHAO_DO_INTRO_ATTACKABLE, CELESTIAL_COURT_BOSS_INTRO_TIMER_2);
                        break;
                    }
                    case EVENT_NIUZAO_SHAO_DO_INTRO_ATTACKABLE:
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetMaxHealth(INITIAL_HEALTH_POINTS);
                        break;
                    }
                    case EVENT_NIUZAO_CHARGE:
                    {
                        ++_charges;
                        DoAction(ACTION_NIUZAO_CHARGE);
                        break;
                    }
                    case EVENT_NIUZAO_MASSIVE_QUAKE:
                    {
                        if (me->HasAura(SPELL_NIUZAO_CHARGE))
                            return;

                        DoCast(SPELL_NIUZAO_MASSIVE_QUAKE);
                        Talk(SAY_SPELL_3);
                        events.ScheduleEvent(urand(EVENT_NIUZAO_OXEN_FORTITUDE, EVENT_NIUZAO_MASSIVE_QUAKE), urand(8500, 15000));
                        break;
                    }
                    case EVENT_NIUZAO_HEADBUTT:
                    {
                        if (me->HasAura(SPELL_NIUZAO_CHARGE))
                            return;

                        DoCast(SPELL_NIUZAO_HEADBUTT);
                        events.ScheduleEvent(urand(EVENT_NIUZAO_OXEN_FORTITUDE, EVENT_NIUZAO_MASSIVE_QUAKE), urand(8500, 15000));
                        break;
                    }
                    case EVENT_NIUZAO_OXEN_FORTITUDE:
                    {
                        if (me->HasAura(SPELL_NIUZAO_CHARGE))
                            return;

                        DoCast(SPELL_NIUZAO_OXEN_FORTITUDE);
                        events.ScheduleEvent(urand(EVENT_NIUZAO_OXEN_FORTITUDE, EVENT_NIUZAO_MASSIVE_QUAKE), urand(8500, 15000));
                        break;
                    }
                    case EVENT_NIUZAO_HEALTH_66_PERCENT:
                    {
                        DoAction(ACTION_NIUZAO_CHARGE_66);
                        break;
                    }
                    case EVENT_NIUZAO_HEALTH_33_PERCENT:
                    {
                        DoAction(ACTION_NIUZAO_CHARGE_33);
                        break;
                    }
                    case EVENT_NIUZAO_SHAO_DO_OUTRO:
                    {
                        if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                            shao->AI()->Talk(EMPEROR_TALK_OUTRO_CHIJI);
                        break;
                    }
                    case EVENT_NIUZAO_DEATH:
                    {
                        if (death)
                        {
                            if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                                shao->AI()->DoAction(ACTION_YULON);

                            me->DisappearAndDie();
                            death = false;
                        }
                        break;
                    }
                    default:
                        break;
                }

                if (!death && !me->HasAura(SPELL_NIUZAO_CHARGE))
                    if (!UpdateVictim())
                        return;

                DoMeleeAttackIfReady();
            }

            private:
                bool _charge66, _charge33 = false;
                bool death = false;
                uint8 _charges;
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_niuzaoAI(creature);
        }
};

// Headbutt - 144610
class spell_niuzao_headbutt : public SpellScriptLoader
{
    public:
        spell_niuzao_headbutt() : SpellScriptLoader("spell_niuzao_headbutt") { }

        class spell_niuzao_headbutt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_niuzao_headbutt_SpellScript)

            void RemoveThreat(SpellEffIndex /*eff*/)
            {
                if (!GetHitUnit())
                    return;

                if (Unit* target = GetHitUnit())
                    GetCaster()->SetReducedThreatPercent(1000, target->GetGUID());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_niuzao_headbutt_SpellScript::RemoveThreat, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_niuzao_headbutt_SpellScript();
        }
};

// Charge - 144608
class spell_niuzao_charge : public SpellScriptLoader
{
    public:
        spell_niuzao_charge() : SpellScriptLoader("spell_niuzao_charge") { }

        class spell_niuzao_charge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_niuzao_charge_AuraScript)

            void HandleEffectApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetOwner())
                    return;

                if (Creature *pOwner = GetOwner()->ToCreature())
                    pOwner->AI()->DoAction(ACTION_NIUZAO_CHARGE);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_niuzao_charge_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_niuzao_charge_AuraScript();
        }
};

void AddSC_boss_niuzao()
{
    new spell_niuzao_headbutt();
    new spell_niuzao_charge();
    new boss_niuzao();
}
