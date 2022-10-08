/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "well_of_eternity.h"
#include "Group.h"
#include "ObjectMgr.h"

enum ScriptedTextMannoroth
{
    SAY_MANNOROTH_AGGRO     = 0,
    SAY_MANNOROTH_DEATH     = 1,
    SAY_MANNOROTH_SARGERAS  = 3,
    SAY_MANNOROTH_SWORD     = 4,
    SAY_MANNOROTH_VAROTHEN  = 5,
    SAY_MANNOROTH_EVENT     = 6,
    SAY_MANNOROTH_KILL      = 7,
    SAY_MANNOROTH_SPELL     = 8,

    SAY_VAROTHEN_AGGRO      = 0,
    SAY_VAROTHEN_DEATH      = 1,
    SAY_VAROTHEN_KILL       = 2,
};

enum Spells
{
    // Mannoroth
    SPELL_FEL_FIRESTORM             = 103888,
    SPELL_FEL_FIRESTORM_SUMMON      = 103889,
    SPELL_FEL_FLAMES_AURA           = 103892,
    SPELL_FEL_FLAMES_DMG            = 103891,
    SPELL_FELBLADE                  = 103966,
    SPELL_FELBURN                   = 103972,
    SPELL_EMBEDDED_BLADE_1          = 104820,
    SPELL_EMBEDDED_BLADE_2          = 109542,
    SPELL_EMBEDDED_BLADE_DUMMY      = 104823,
    SPELL_FEL_FIRE_NOVA             = 105093,
    SPELL_NETHER_PORTAL             = 104625,
    SPELL_NETHER_TEAR               = 105041,
    SPELL_FEL_DRAIN                 = 104961,
    SPELL_SUMMON_FELHOUND_AURA      = 105053,
    SPELL_SUMMON_FELHOUND           = 105054,
    SPELL_SUMMON_FELGUARD_AURA      = 105057,
    SPELL_SUMMON_FELGUARD           = 105058,
    SPELL_SUMMON_DEVASTATOR_AURA    = 105061,
    SPELL_SUMMON_DEVASTATOR         = 105059,
    SPELL_INFERNAL                  = 105141,
    SPELL_INFERNAL_MISSILE          = 105145,

    // Captain Varo'then
    SPELL_MAGNISTRIKE               = 103669,

    // Doomguard Debilitator
    SPELL_DEBILITATING_FLAY         = 104678,

    SPELL_COMPLETE_ENCOUNTER        = 105576,

    // Illidan 2
    SPELL_WATERS_OF_ETERNITY        = 103952,
    SPELL_TAUNT                     = 104461,
    SPELL_DEMON_RUSH                = 104205,
    SPELL_DARKLANCE                 = 104394,
    SPELL_AURA_OF_IMMOLATION        = 104379,
    SPELL_GIFT_OF_SARGERAS          = 104998,
    SPELL_GIFT_OF_SARGERAS_AOE      = 105009,

    // Tyrande
    SPELL_BLESSING_OF_ELUNE         = 103917,
    SPELL_HAND_OF_ELUNE             = 105072,
    SPELL_WRATH_OF_ELUNE_1          = 105073, // 30k damage
    SPELL_WRATH_OF_ELUNE_2          = 105075, // 300k damage
    SPELL_LUNAR_SHOT_1              = 104214, // 30k damage, single
    SPELL_LUNAR_SHOT_2              = 104313, // 300k damage, single
    SPELL_LUNAR_SHOT_3              = 104688, // 300k damage, aoe
};

enum Events
{
    EVENT_MAGNISTRIKE           = 1,
    EVENT_MANNOROTH_AGGRO       = 2,
    EVENT_FEL_FIRESTORM         = 3,
    EVENT_SUMMON_DEBILITATOR    = 4,
    EVENT_SUMMON_DEBILITATOR_1  = 5,
    EVENT_FELBLADE              = 6,
    EVENT_SUMMON_DEVASTATOR     = 7,
    EVENT_EMBEDDED_BLADE        = 8,
    EVENT_EMBEDDED_BLADE_1      = 9,
    EVENT_DEBILITATING_FLAY     = 10,
    EVENT_CHECK_PLAYERS         = 12,
    EVENT_MANNOROTH_SARGERAS_1  = 13, // Illidan says
    EVENT_MANNOROTH_SARGERAS_2  = 14, // Tyrande says
    EVENT_INFERNAL              = 15, // Tyrande says
    EVENT_GIFT_OF_SARGERAS_1    = 16, // Illidan says
    EVENT_GIFT_OF_SARGERAS_2    = 17, // Tyrande says
    EVENT_GIFT_OF_SARGERAS_3    = 18, // Illidan says
    EVENT_GIFT_OF_SARGERAS_4    = 19, // Tyrande says
    EVENT_GIFT_OF_SARGERAS_5    = 20, // Illidan says
    EVENT_DESPAWN               = 21,
};

enum Adds
{
    NPC_FEL_FLAMES              = 55502,
    NPC_INFERNAL                = 56036,
    NPC_FELGUARD                = 56002,
    NPC_FELHOUND                = 56001,
    NPC_DOOMGUARD_DEVASTATOR    = 57410,
    NPC_DOOMGUARD_DEBILITATOR   = 55762,
    NPC_VAROTHEN_MAGICAL_BLADE  = 55837,
    NPC_EMBEDDED_BLADE          = 55838,
    NPC_PURPOSE_BUNNY_1         = 45979,
    NPC_PURPOSE_BUNNY_2         = 54020,
};

enum Actions
{
    ACTION_VAROTHEN_DIED    = 1,
    ACTION_DEBILITATING_OFF = 2,
};

const Position portalPos = {3338.699951f, -5699.775879f, 13.01f, 3.87f};

const Position varothenPos = {3319.669922f, -5716.470215f, 16.18f, 2.68f};

const Position debilitatorPos[2] =
{
    {3295.439941f, -5687.229980f, 14.19f, 5.74f}, // left dreadlord
    {3324.479980f, -5694.270020f, 13.97f, 3.17f}  // right dreadlord
};

const Position devastatorPos[3] =
{
    {3302.872803f, -5676.763672f, 12.53f, 4.74f},
    {3326.123047f, -5690.420410f, 13.14f, 3.81f},
    {3316.755127f, -5686.553711f, 14.03f, 4.26f}
};

const Position stalkerPos[3] =
{
    {3295.44f, -5687.23f, 14.19f, 5.74213f},
    {3324.48f, -5694.27f, 13.97f, 3.1765f},
    {3339.81f, -5698.5f, 15.5043f, 3.97935f},
};

class boss_mannoroth : public CreatureScript
{
public:
    boss_mannoroth() : CreatureScript("boss_mannoroth") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_mannorothAI(pCreature);
    }

    struct boss_mannorothAI : public BossAI
    {
        boss_mannorothAI(Creature* pCreature) : BossAI(pCreature, DATA_MANNOROTH)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
        }

        void InitializeAI() override
        {
            if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptIdOrAdd(WoEScriptName))
                me->IsAIEnabled = false;
            else if (!me->isDead())
                Reset();
        }

        void Reset() override
        {
            _Reset();

            me->SummonCreature(NPC_VAROTHEN, varothenPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

            phase = 0;
            bVarothen = false;
            bAchieve = false;
            bDebilitating = false;
            bEndEncounter = false;
        }

        void JustReachedHome() override
        {
            if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 150.0f))
                pTyrande->AI()->DoAction(7); // ACTION_MANNOROTH_RESET
            if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 150.0f))
                pIllidan->AI()->DoAction(7); // ACTION_MANNOROTH_RESET
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            me->Attack(who, false);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            if (Creature* pVarothen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VAROTHEN)))
                if (!pVarothen->IsInCombat())
                    DoZoneInCombat(pVarothen);

            if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 150.0f))
                pIllidan->AI()->DoAction(6); // ACTION_MANNOROTH_AGGRO

            phase = 0;
            bVarothen = false;
            bAchieve = false;
            bDebilitating = false;
            bEndEncounter = false;

            events.ScheduleEvent(EVENT_MANNOROTH_AGGRO, 5000);
            //events.ScheduleEvent(EVENT_FEL_FIRESTORM, 20000);
            events.ScheduleEvent(EVENT_SUMMON_DEBILITATOR, 65000);
            events.ScheduleEvent(EVENT_SUMMON_DEVASTATOR, urand(5000, 8000));
            events.ScheduleEvent(EVENT_SUMMON_DEVASTATOR, urand(5000, 8000));
            events.ScheduleEvent(EVENT_SUMMON_DEVASTATOR, urand(5000, 8000));
            events.ScheduleEvent(EVENT_CHECK_PLAYERS, 3000);

            for (uint8 i = 0; i < 2; ++i)
                if (Creature* pStalker = me->SummonCreature(NPC_PURPOSE_BUNNY_1, stalkerPos[i]))
                    pStalker->RemoveAllAuras();

            if (Creature* pStalker = me->SummonCreature(NPC_PURPOSE_BUNNY_2, stalkerPos[2]))
                pStalker->RemoveAllAuras();

            DoZoneInCombat();
            instance->SetBossState(DATA_MANNOROTH, IN_PROGRESS);
        }

        void KilledUnit(Unit* who) override
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_MANNOROTH_KILL);
        }

        bool AllowAchieve()
        {
            return bAchieve;
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_VAROTHEN_DIED)
            {
                bVarothen = true;
                events.ScheduleEvent(EVENT_EMBEDDED_BLADE, 5000);
            } else if (action == ACTION_DEBILITATING_OFF)
            {
                bDebilitating = true;
            }
        }

        void DamageTaken(Unit* /*who*/, uint32&damage) override
        {
            if (!bDebilitating)
                if (me->HealthBelowPctDamaged(88, damage))
                    damage = 0;

            if (damage >= me->GetHealth())
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->HealthBelowPct(90) && !bVarothen)
            {
                Talk(SAY_MANNOROTH_VAROTHEN);
                DoCast(me, SPELL_FEL_DRAIN);
                bVarothen = true;
                bAchieve = true;
                return;
            }
            if (me->HealthBelowPct(85) && (phase == 0))
            {
                phase = 1;
                events.CancelEvent(EVENT_SUMMON_DEVASTATOR);
                Talk(SAY_MANNOROTH_SARGERAS);
                DoCast(me, SPELL_NETHER_TEAR);
                events.ScheduleEvent(EVENT_MANNOROTH_SARGERAS_1, 15000);
                events.ScheduleEvent(EVENT_MANNOROTH_SARGERAS_2, 23000);
                return;
            } else if (me->HealthBelowPct(70) && (phase == 1))
            {
                phase = 2;
                DoCast(me, SPELL_SUMMON_FELGUARD_AURA, true);
            } else if (me->HealthBelowPct(60) && (phase == 2))
            {
                phase = 3;
                DoCast(me, SPELL_SUMMON_DEVASTATOR_AURA, true);
            } else if (me->HealthBelowPct(50) && (phase == 3))
            {
                phase = 4;
                Talk(SAY_MANNOROTH_EVENT);
                DoCast(me, SPELL_INFERNAL);
                events.ScheduleEvent(EVENT_INFERNAL, 20000);
                return;
            } else if (me->HealthBelowPct(25) && (phase == 4))
            {
                phase = 5;
                bEndEncounter = true;
                CompleteEncounter();
                return;
            }

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYERS:
                    if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        events.Reset();
                        EnterEvadeMode();
                        return;
                    } else
                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 3000);
                    break;
                case EVENT_MANNOROTH_AGGRO:
                    Talk(SAY_MANNOROTH_AGGRO);
                    break;
                case EVENT_FEL_FIRESTORM:
                    //DoCast(me, SPELL_FEL_FIRESTORM);
                    //events.ScheduleEvent(EVENT_FEL_FIRESTORM, urand(25000, 35000));
                    break;
                case EVENT_FELBLADE:
                    DoCast(me, SPELL_FELBLADE);
                    events.ScheduleEvent(EVENT_FELBLADE, urand(15000, 25000));
                    break;
                case EVENT_SUMMON_DEBILITATOR:
                    DoCast(me, SPELL_NETHER_PORTAL);
                    events.ScheduleEvent(EVENT_SUMMON_DEBILITATOR_1, 7000);
                    break;
                case EVENT_SUMMON_DEBILITATOR_1:
                    for (uint8 i = 0; i < 2; ++i)
                        me->SummonCreature(NPC_DOOMGUARD_DEBILITATOR, debilitatorPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    break;
                case EVENT_SUMMON_DEVASTATOR:
                    {
                        uint32 i = urand(0, 2);
                        me->SummonCreature(NPC_DOOMGUARD_DEVASTATOR, devastatorPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                        events.ScheduleEvent(EVENT_SUMMON_DEVASTATOR, urand(5000, 8000));
                        break;
                    }
                case EVENT_EMBEDDED_BLADE:
                    Talk(SAY_MANNOROTH_SWORD);
                    DoCast(me, SPELL_EMBEDDED_BLADE_2, true);
                    DoCast(me, SPELL_EMBEDDED_BLADE_DUMMY, true);
                    events.ScheduleEvent(EVENT_EMBEDDED_BLADE_1, 3000);

                    break;
                case EVENT_EMBEDDED_BLADE_1:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 100.0f))
                        pIllidan->AI()->Talk(15); // SAY_ILLIDAN_2_SWORD
                    //events.RescheduleEvent(EVENT_FEL_FIRESTORM, urand(25000, 30000));
                    //events.RescheduleEvent(EVENT_FELBLADE, urand(10000, 55000));
                    break;
                case EVENT_MANNOROTH_SARGERAS_1:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 100.0f))
                        pIllidan->AI()->Talk(19); // SAY_ILLIDAN_2_SPELL
                    DoCast(me, SPELL_SUMMON_FELHOUND_AURA, true);
                    break;
                case EVENT_MANNOROTH_SARGERAS_2:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 150.0f))
                    {
                        pTyrande->AI()->Talk(10); // SAY_TYRANDE_ARROWS
                        pTyrande->AI()->DoAction(9); // ACTION_MANNOROTH_SARGERAS
                    }
                    break;
                case EVENT_INFERNAL:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 150.0f))
                    {
                        pTyrande->AI()->Talk(14); // SAY_TYRANDE_MANY_DEMONS
                        pTyrande->AI()->DoAction(10); // ACTION_MANNOROTH_INFERNO
                    }
                    //events.RescheduleEvent(EVENT_FEL_FIRESTORM, urand(40000, 50000));
                    //events.RescheduleEvent(EVENT_FELBLADE, urand(45000, 55000));
                    events.ScheduleEvent(EVENT_GIFT_OF_SARGERAS_1, 5000);
                    break;
                case EVENT_GIFT_OF_SARGERAS_1:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 100.0f))
                    {
                        pIllidan->AI()->Talk(16); // SAY_ILLIDAN_2_BUFF_1
                        pIllidan->CastSpell(me, SPELL_GIFT_OF_SARGERAS);
                    }
                    events.ScheduleEvent(EVENT_GIFT_OF_SARGERAS_2, 8000);
                    break;
                case EVENT_GIFT_OF_SARGERAS_2:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 150.0f))
                        pTyrande->AI()->Talk(11); // SAY_TYRANDE_NO_1
                    events.ScheduleEvent(EVENT_GIFT_OF_SARGERAS_3, 2000);
                    break;
                case EVENT_GIFT_OF_SARGERAS_3:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 100.0f))
                        pIllidan->AI()->Talk(17); // SAY_ILLIDAN_2_BUFF_2
                    events.ScheduleEvent(EVENT_GIFT_OF_SARGERAS_4, 8000);
                    break;
                case EVENT_GIFT_OF_SARGERAS_4:
                    if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 150.0f))
                        pTyrande->AI()->Talk(12); // SAY_TYRANDE_NO_2
                    events.ScheduleEvent(EVENT_GIFT_OF_SARGERAS_5, 2000);
                    break;
                case EVENT_GIFT_OF_SARGERAS_5:
                    if (Creature* pIllidan = me->FindNearestCreature(NPC_ILLIDAN_2, 100.0f))
                        pIllidan->AI()->Talk(18); // SAY_ILLIDAN_2_BUFF_3
                    break;
                case EVENT_DESPAWN:
                    instance->DoRespawnGameObject(instance->GetGuidData(DATA_MINOR_CACHE), DAY);
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
                }
            }

            //DoMeleeAttackIfReady();
        }
    private:
        uint8 phase;
        bool bVarothen;
        bool bAchieve;
        bool bDebilitating;
        bool bEndEncounter;

        void CompleteEncounter()
        {
            Talk(SAY_MANNOROTH_DEATH);
            events.Reset();
            summons.DespawnAll();
            me->InterruptNonMeleeSpells(true);

            if (instance)
            {
                // Achievement
                //instance->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_COMPLETE_ENCOUNTER, 0, 0, me);

                // Guild Achievement
                /*Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (Player* pPlayer = i->GetSource())
                            if (Group* pGroup = pPlayer->GetGroup())
                                if (pPlayer->GetGuildId() && pGroup->IsGuildGroup(pPlayer->GetGuildId(), true, true))
                                {
                                    pGroup->UpdateGuildAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_COMPLETE_ENCOUNTER, 0, 0, NULL, me);
                                    break;
                                }
                    }
                }*/

                   if (me->GetMap()->IsHeroic())
                       {
                          if (!me->GetMap()->GetPlayers().isEmpty())
                          {
                              for (Map::PlayerList::const_iterator i = me->GetMap()->GetPlayers().begin(); i != me->GetMap()->GetPlayers().end(); ++i)
                              {
                                   if (!i->GetSource())
                                       continue;

                                   i->GetSource()->KilledMonsterCredit(NPC_MANNOROTH);
                                   i->GetSource()->ModifyCurrency(CURRENCY_TYPE_JUSTICE_POINTS, 7000);
                              }
                          }
                       }

                instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 105576, 0, me);
                me->SummonGameObject(209541, 3356.39f, -5748.73f, 15.2165f, 2.60053f, QuaternionData(), 200000);
                //instance->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_COMPLETE_ENCOUNTER, me);
                instance->SetBossState(DATA_MANNOROTH, DONE);
            }

            if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 150.0f))
                pTyrande->AI()->DoAction(11); // ACTION_MANNOROTH_END

            events.ScheduleEvent(EVENT_DESPAWN, 5000);
        }
    };
};

class npc_mannoroth_varothen : public CreatureScript
{
public:
    npc_mannoroth_varothen() : CreatureScript("npc_mannoroth_varothen") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_mannoroth_varothenAI(pCreature);
    }

    struct npc_mannoroth_varothenAI : public ScriptedAI
    {
        npc_mannoroth_varothenAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->setActive(true);
            pInstance = me->GetInstanceScript();

        }

        void Reset() override
        {
            events.Reset();
            if (!me->FindNearestCreature(NPC_ILLIDAN_2, 100.0f))
                me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            Talk(SAY_VAROTHEN_AGGRO);
            events.ScheduleEvent(EVENT_MAGNISTRIKE, urand(3000, 7000));

            if (pInstance)
                if (Creature* pMannoroth = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_MANNOROTH)))
                    if (!pMannoroth->IsInCombat())
                        DoZoneInCombat(pMannoroth);
        }

        void KilledUnit(Unit* who) override
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_VAROTHEN_KILL);
        }

        void SpellHit(Unit* who, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_ARCHIVED_VAROTHEN_1)
                DoCast(who, SPELL_ARCHIVED_VAROTHEN_2, true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_VAROTHEN_DEATH);

            if (pInstance)
            {
                if (Creature* pMannoroth = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_MANNOROTH)))
                    pMannoroth->AI()->DoAction(ACTION_VAROTHEN_DIED);

                Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();
                if (!PlayerList.isEmpty())
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        if (Player* pPlayer = i->GetSource())
                            if (me->GetDistance(pPlayer) <= 50.0f && pPlayer->GetQuestStatus(QUEST_DOCUMENTING_THE_TIMEWAYS) == QUEST_STATUS_INCOMPLETE)
                                pPlayer->CastSpell(me, SPELL_ARCHIVED_VAROTHEN_1, true);
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
                if (eventId == EVENT_MAGNISTRIKE)
                {
                    DoCastVictim(SPELL_MAGNISTRIKE);
                    events.ScheduleEvent(EVENT_MAGNISTRIKE, urand(10000, 15000));
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        InstanceScript* pInstance;
    };
};

class npc_mannoroth_doomguard_debilitator : public CreatureScript
{
public:
    npc_mannoroth_doomguard_debilitator() : CreatureScript("npc_mannoroth_doomguard_debilitator") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_mannoroth_doomguard_debilitatorAI(pCreature);
    }

    struct npc_mannoroth_doomguard_debilitatorAI : public ScriptedAI
    {
        npc_mannoroth_doomguard_debilitatorAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*owner*/) override
        {
            events.ScheduleEvent(EVENT_DEBILITATING_FLAY, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* pTyrande = me->FindNearestCreature(NPC_TYRANDE, 100.0f))
                pTyrande->AI()->DoAction(8); // ACTION_DEBILITATING_OFF
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_DEBILITATING_FLAY)
                {
                    DoCast(me, SPELL_DEBILITATING_FLAY);
                }
            }
        }
    private:
        EventMap events;
    };
};

class spell_mannoroth_gift_of_sargeras : public SpellScriptLoader
{
public:
    spell_mannoroth_gift_of_sargeras() : SpellScriptLoader("spell_mannoroth_gift_of_sargeras") { }

    class spell_mannoroth_gift_of_sargeras_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mannoroth_gift_of_sargeras_SpellScript);

        void HandleAfterHit()
        {
            if (!GetCaster())
                return;

            GetCaster()->CastSpell(GetCaster(), SPELL_GIFT_OF_SARGERAS_AOE, true);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_mannoroth_gift_of_sargeras_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mannoroth_gift_of_sargeras_SpellScript();
    }
};

typedef boss_mannoroth::boss_mannorothAI MannorothAI;

class achievement_thats_not_cannon : public AchievementCriteriaScript
{
public:
    achievement_thats_not_cannon() : AchievementCriteriaScript("achievement_thats_not_cannon") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        if (!target)
            return false;

        if (MannorothAI* mannorothAI = CAST_AI(MannorothAI, target->GetAI()))
            return mannorothAI->AllowAchieve();

        return false;
    }
};

void AddSC_boss_mannoroth()
{
    new boss_mannoroth();
    new npc_mannoroth_varothen();
    new npc_mannoroth_doomguard_debilitator();
    new spell_mannoroth_gift_of_sargeras();
    new achievement_thats_not_cannon();
}
