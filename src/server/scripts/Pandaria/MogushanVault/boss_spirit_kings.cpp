/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/*
    @TODO :
        - Event before boss, with Lorewalker Cho !
        - http://www.youtube.com/watch?v=4xbUFstYo5g
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Quiang
    SPELL_FLANKING_ORDERS       = 117910, // Also when vanquished
    SPELL_MASSIVE_ATTACKS       = 117921,
    SPELL_ANNIHILATE            = 117948,
    SPELL_IMPERVIOUS_SHIELD     = 117961, // Heroic

    // Subetai
    SPELL_PILLAGE_CHARGE        = 118047, // Also when vanquished
    SPELL_PILLAGE               = 118049,
    SPELL_VOLLEY_VISUAL         = 118100,
    SPELL_VOLLEY_1              = 118094,
    SPELL_VOLLEY_2              = 118105,
    SPELL_VOLLEY_3              = 118106,
    SPELL_RAIN_OF_ARROWS        = 118122,
    SPELL_PINNED_DOWN           = 118145,
    SPELL_PINNED_DOWN_DOT       = 118135,
    SPELL_PINNING_ARROW_VISUAL  = 118141,
    SPELL_SLEIGHT_OF_HAND       = 118162, // Heroic

    // Zian
    SPELL_UNDYING_SHADOWS       = 117506, // Also when vanquished
    SPELL_FIXATE                = 118303,
    SPELL_UNDYING_SHADOW_DOT    = 117514,
    SPELL_COALESCING_SHADOW_DOT = 117539,

    SPELL_SHADOW_BLAST          = 117628,
    SPELL_CHARGED_SHADOWS       = 117685,
    SPELL_SHIELD_OF_DARKNESS    = 117697, // Heroic

    // Meng
    SPELL_MADDENING_SHOUT       = 117708, // Also when vanquished
    SPELL_CRAZED                = 117737,
    SPELL_COWARDICE             = 117756,
    SPELL_COWARDICE_DOT         = 117829,
    SPELL_CRAZY_THOUGHT         = 117833,
    SPELL_DELIRIOUS             = 117837, // Heroic

    // Shared
    SPELL_INACTIVE              = 118205,
    SPELL_INACTIVE_STUN         = 118319,
    SPELL_KING_BERSERK          = 120207,
    SPELL_ACTIVATION_VISUAL     = 118212,

    // Flanking Mogu
    SPELL_GHOST_VISUAL          = 117904,
    SPELL_TRIGGER_ATTACK        = 117917,
};

enum eEvents
{
    // Controler
    EVENT_CHECK_WIPE            = 1,

    // Quiang
    EVENT_FLANKING_MOGU         = 2,
    EVENT_MASSIVE_ATTACK        = 3,
    EVENT_ANNIHILATE            = 4,
    EVENT_IMPERVIOUS_SHIELD     = 5,

    // Subetai
    EVENT_PILLAGE               = 6,
    EVENT_VOLLEY_1              = 7,
    EVENT_VOLLEY_2              = 8,
    EVENT_VOLLEY_3              = 9,
    EVENT_RAIN_OF_ARROWS        = 10,
    EVENT_SLEIGHT_OF_HAND       = 11,

    // Zian
    EVENT_UNDYING_SHADOWS       = 12,
    EVENT_SHADOW_BLAST          = 13,
    EVENT_CHARGED_SHADOWS       = 14,
    EVENT_SHIELD_OF_DARKNESS    = 15,

    // Meng
    EVENT_MADDENING_SHOUT       = 16,
    EVENT_CRAZED                = 17,
    EVENT_CRAZY_THOUGHT         = 18,
    EVENT_DELIRIOUS             = 19
};

enum equipId
{
    EQUIP_QIANG_POLEARM         = 86777,
    EQUIP_SUBETAI_SWORD         = 80283,
    EQUIP_SUBETAI_BOW           = 60790,
    EQUIP_ZIAN_STAFF            = 76369,
    EQUIP_FLANKING_MOGU_SWORD   = 68838,
    EQUIP_FLANKING_MOGU_SHIELD  = 32375,
};

enum qiangTalk
{
    QIANG_AGGRO     = 0,
    QIANG_DEATH     = 1,
    QIANG_INTRO     = 2,
    QIANG_SLAY      = 3,
    QIANG_SPELL     = 4,
};

enum subetaiTalk
{
    SUBETAI_AGGRO   = 0,
    SUBETAI_DEATH   = 1,
    SUBETAI_INTRO   = 2,
    SUBETAI_SLAY    = 3,
    SUBETAI_SPELL   = 4,
};

enum zianTalk
{
    ZIAN_AGGRO  = 0,
    ZIAN_DEATH  = 1,
    ZIAN_INTRO  = 2,
    ZIAN_SLAY   = 3,
    ZIAN_SPELL  = 4,
};

enum mengTalk
{
    MENG_AGGRO              = 0,
    MENG_DEATH_CRAZED       = 1,
    MENG_DEATH_COWARDICE    = 2,
    MENG_INTRO              = 3,
    MENG_SLAY               = 4,
    MENG_SPELL              = 5,
};

#define MAX_FLANKING_MOGU   48

Position flankingPos[MAX_FLANKING_MOGU] =
{
    {4195.25f, 1590.85f, 438.841f, 0.12350f},
    {4194.99f, 1586.06f, 438.841f, 0.26639f},
    {4193.99f, 1581.04f, 438.840f, 0.39482f},
    {4195.19f, 1576.21f, 438.840f, 0.52845f},
    {4196.93f, 1571.99f, 438.839f, 0.64866f},
    {4200.06f, 1568.31f, 438.839f, 0.77664f},
    {4203.17f, 1564.49f, 438.837f, 0.90416f},
    {4206.52f, 1561.59f, 438.837f, 1.01808f},
    {4209.94f, 1558.79f, 438.836f, 1.12821f},
    {4213.91f, 1556.73f, 438.837f, 1.23942f},
    {4217.99f, 1556.02f, 438.839f, 1.34239f},
    {4222.20f, 1555.52f, 438.839f, 1.44913f},
    {4226.90f, 1555.01f, 438.839f, 1.56812f},
    {4231.69f, 1555.00f, 438.839f, 1.68814f},
    {4236.49f, 1556.31f, 438.838f, 1.81247f},
    {4241.28f, 1558.22f, 438.837f, 1.94289f},
    {4245.75f, 1561.11f, 438.837f, 2.07869f},
    {4250.17f, 1563.56f, 438.837f, 2.20908f},
    {4253.08f, 1568.12f, 438.839f, 2.34491f},
    {4255.07f, 1573.32f, 438.840f, 2.48865f},
    {4257.26f, 1579.05f, 438.840f, 2.66189f},
    {4257.36f, 1584.80f, 438.841f, 2.82356f},
    {4258.93f, 1591.29f, 438.841f, 3.03247f},
    {4259.81f, 1597.36f, 438.841f, 3.21968f},
    {4265.56f, 1603.04f, 438.842f, 3.35247f},
    {4264.61f, 1608.74f, 438.843f, 3.49683f},
    {4263.33f, 1613.64f, 438.841f, 3.62029f},
    {4260.61f, 1618.46f, 438.842f, 3.75534f},
    {4257.08f, 1622.41f, 438.845f, 3.88442f},
    {4253.70f, 1625.77f, 438.845f, 4.00111f},
    {4250.06f, 1629.08f, 438.844f, 4.12039f},
    {4245.74f, 1631.66f, 438.843f, 4.24225f},
    {4241.14f, 1634.23f, 438.846f, 4.36825f},
    {4236.42f, 1635.51f, 438.847f, 4.48507f},
    {4231.43f, 1635.73f, 438.849f, 4.60476f},
    {4226.52f, 1635.65f, 438.851f, 4.72422f},
    {4221.75f, 1635.25f, 438.851f, 4.84165f},
    {4217.01f, 1633.81f, 438.853f, 4.96304f},
    {4211.88f, 1632.07f, 438.853f, 5.09767f},
    {4207.12f, 1629.80f, 438.851f, 5.22899f},
    {4202.68f, 1626.57f, 438.851f, 5.36565f},
    {4198.73f, 1623.16f, 438.850f, 5.49605f},
    {4195.37f, 1619.05f, 438.849f, 5.62901f},
    {4192.82f, 1614.57f, 438.849f, 5.75861f},
    {4190.84f, 1609.64f, 438.847f, 5.89364f},
    {4190.58f, 1604.28f, 438.850f, 6.02825f},
    {4192.61f, 1600.68f, 438.844f, 6.11362f},
    {4195.38f, 1595.63f, 438.841f, 6.25653f}
};

Position QiangTheMerciless      = {4226.33f, 1626.28f, 438.856f, 4.72348f};
Position SubetaiTheSwift        = {4257.35f, 1591.36f, 438.841f, 3.13526f};
Position ZianOfTheEndlessShadow = {4226.97f, 1558.32f, 438.804f, 1.58495f};
Position MengTheDemented        = {4198.78f, 1590.29f, 438.841f, 6.26345f};

uint32 volleySpells[3] =
{
    SPELL_VOLLEY_1,
    SPELL_VOLLEY_2,
    SPELL_VOLLEY_3
};

uint32 spiritsOrder[4] =
{
    NPC_QIANG,
    NPC_SUBETAI,
    NPC_MENG,
    NPC_ZIAN
};

class boss_spirit_kings_controler : public CreatureScript
{
    public:
        boss_spirit_kings_controler() : CreatureScript("boss_spirit_kings_controler") {}

        struct boss_spirit_kings_controlerAI : public BossAI
        {
            boss_spirit_kings_controlerAI(Creature* creature) : BossAI(creature, DATA_SPIRIT_KINGS)
            {
                pInstance = creature->GetInstanceScript();

                spiritKingsEntry.resize(4, 0);

                for (uint8 i = 0; i < 4; i++)
                    spiritKingsEntry[i] = spiritsOrder[i];
            }

            InstanceScript* pInstance;
            uint64 flankingGuid[MAX_FLANKING_MOGU];
            std::vector<uint32> spiritKingsEntry;

            bool fightInProgress;
            bool _introZianDone;
            bool _introSubetaiDone;
            bool _introMengDone;
            
            uint8 vanquishedCount;
            uint8 lastActivated;

            void Reset()
            {
                if (!pInstance)
                    return;

                if (pInstance->GetBossState(DATA_SPIRIT_KINGS) == DONE)
                    return;

                _Reset();

                fightInProgress   = false;
                _introZianDone    = false;
                _introSubetaiDone = false;
                _introMengDone    = false;
                vanquishedCount   = 0;
                lastActivated     = 0;

                for (uint8 i = 0; i < MAX_FLANKING_MOGU; ++i)
                    flankingGuid[i] = 0;

                spawnSpiritKings();
                me->SetReactState(REACT_PASSIVE);

                events.ScheduleEvent(EVENT_CHECK_WIPE, 2500);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MADDENING_SHOUT);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN_DOT);
            }

            void spawnSpiritKings()
            {
                if (Creature* Qiang = me->SummonCreature(NPC_QIANG, QiangTheMerciless.GetPositionX(), QiangTheMerciless.GetPositionY(), QiangTheMerciless.GetPositionZ(), QiangTheMerciless.GetOrientation()))
                    Qiang->AI()->DoAction(ACTION_FIRST_FIGHT);

                me->SummonCreature(NPC_SUBETAI, SubetaiTheSwift.GetPositionX(), SubetaiTheSwift.GetPositionY(), SubetaiTheSwift.GetPositionZ(), SubetaiTheSwift.GetOrientation());
                me->SummonCreature(NPC_ZIAN, ZianOfTheEndlessShadow.GetPositionX(), ZianOfTheEndlessShadow.GetPositionY(), ZianOfTheEndlessShadow.GetPositionZ(), ZianOfTheEndlessShadow.GetOrientation());
                me->SummonCreature(NPC_MENG, MengTheDemented.GetPositionX(), MengTheDemented.GetPositionY(), MengTheDemented.GetPositionZ(), MengTheDemented.GetOrientation());
            }

            void spawnFlankingMogu(uint8 moguNumber)
            {
                if (moguNumber >= MAX_FLANKING_MOGU)
                    return;

                if (Creature* flankingMogu = me->SummonCreature(NPC_FLANKING_MOGU, flankingPos[moguNumber].GetPositionX(), flankingPos[moguNumber].GetPositionY(), flankingPos[moguNumber].GetPositionZ(), flankingPos[moguNumber].GetOrientation()))
                {
                    flankingGuid[moguNumber] = flankingMogu->GetGUID().GetEntry();
                    flankingMogu->SetReactState(REACT_PASSIVE);
                    flankingMogu->AddAura(SPELL_GHOST_VISUAL, flankingMogu);
                    flankingMogu->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_FLANKING_MOGU_SWORD));
                    flankingMogu->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, uint32(EQUIP_FLANKING_MOGU_SHIELD));
                }
            }

            void DoAction(int32 action)
            {
                if (!pInstance)
                    return;

                switch (action)
                {
                    case ACTION_ENTER_COMBAT:
                    {
                        if (fightInProgress)
                            break;

                        for (uint8 i = 0; i < MAX_FLANKING_MOGU; ++i)
                            spawnFlankingMogu(i);

                        if (Creature* incomingSpirit = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(spiritKingsEntry[1]))))
                            me->AddAura(SPELL_ACTIVATION_VISUAL, incomingSpirit);

                        fightInProgress = true;
                        break;
                    }
                    case ACTION_FLANKING_MOGU:
                    {
                        uint8 moguBegin = urand(0, 47);
                        uint8 middleMogu = (moguBegin + 3) > 47 ? (moguBegin + 3) - 48: (moguBegin + 3);
                        float orientation = 0.0f;

                        if (Creature* flankingMogu = pInstance->instance->GetCreature(pInstance->GetObjectGuid(flankingGuid[middleMogu])))
                            orientation = flankingMogu->GetOrientation();

                        for (uint8 i = moguBegin; i < moguBegin + 6; ++i)
                        {
                            uint8 j = i;

                            if (j >= 48)
                                j -= 48;

                            if (Creature* flankingMogu = pInstance->instance->GetCreature(pInstance->GetObjectGuid(flankingGuid[j])))
                            {
                                flankingMogu->RemoveAurasDueToSpell(SPELL_GHOST_VISUAL);
                                flankingMogu->AddAura(SPELL_TRIGGER_ATTACK, flankingMogu);

                                float x = 0.0f, y = 0.0f;
                                //GetPositionWithDistInOrientation(flankingMogu, 100.0f, orientation, x, y);

                                if (!x && !y)
                                    continue;

                                flankingMogu->GetMotionMaster()->MovePoint(1, x, y, flankingMogu->GetPositionZ(), false);
                                flankingMogu->DespawnOrUnsummon(11000);

                                // Spawn a new one to remplace the old one
                                spawnFlankingMogu(j);
                            }
                        }
                        break;
                    }
                    case ACTION_SPIRIT_NEXT:
                    {
                        ++lastActivated;

                        if (lastActivated >= 4)
                            break;

                        if (Creature* spirit = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(spiritKingsEntry[lastActivated]))))
                        {
                            spirit->AI()->DoAction(ACTION_ENTER_COMBAT);

                            if (lastActivated < 3)
                            {
                                uint8 nextSpirit = lastActivated + 1;

                                if (Creature* incomingSpirit = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(spiritKingsEntry[nextSpirit]))))
                                    me->AddAura(SPELL_ACTIVATION_VISUAL, incomingSpirit);
                            }
                        }
                        break;
                    }
                    case ACTION_SPIRIT_KILLED:
                    {
                        uint8 nextSpirit = ++vanquishedCount;
                        if (nextSpirit >= 4)
                        {
                            pInstance->SetBossState(DATA_SPIRIT_KINGS, DONE);
                            summons.DespawnEntry(NPC_FLANKING_MOGU);

                            for (uint32 entry : spiritKingsEntry)
                            {
                                if (Creature* spirit = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(entry))))
                                {
                                    spirit->LowerPlayerDamageReq(spirit->GetMaxHealth());
                                    spirit->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    spirit->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    spirit->RemoveAura(SPELL_INACTIVE);

                                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MADDENING_SHOUT);

                                    if (Unit* killer = spirit->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                                        killer->Kill(spirit);
                                }
                            }

                            pInstance->SetBossState(DATA_SPIRIT_KINGS, DONE);
                        }
                        break;
                    }
                    case ACTION_SAY_INTRO_FOR_NEXT_SPIRIT_IF_ANY:
                    {
                        if (vanquishedCount > 2)
                            break;

                        if (Creature* incomingSpirit = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(spiritKingsEntry[vanquishedCount + 1]))))
                        {
                            switch (incomingSpirit->GetEntry())
                            {
                                case NPC_ZIAN:
                                    if (_introZianDone)
                                        break;

                                    incomingSpirit->AI()->Talk(ZIAN_INTRO);
                                    _introZianDone = true;
                                    break;
                                case NPC_SUBETAI:
                                    if (_introSubetaiDone)
                                        break;

                                    incomingSpirit->AI()->Talk(SUBETAI_INTRO);
                                    _introSubetaiDone = true;
                                    break;
                                case NPC_MENG:
                                    if (_introMengDone)
                                        break;

                                    incomingSpirit->AI()->Talk(MENG_INTRO);
                                    _introMengDone = true;
                                    break;
                                default:
                                    break;
                            }
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void UpdateAI(uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!fightInProgress)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        /*case EVENT_CHECK_WIPE:
                        {
                            if (pInstance->IsWipe())
                            {
                                pInstance->SetBossState(DATA_SPIRIT_KINGS, FAIL);
                                Reset();
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_WIPE, 2500);
                            break;
                        }*/
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_spirit_kings_controlerAI(creature);
        }
};

class boss_spirit_kings : public CreatureScript
{
    public:
        boss_spirit_kings() : CreatureScript("boss_spirit_kings") {}

        struct boss_spirit_kingsAI : public ScriptedAI
        {
            boss_spirit_kingsAI(Creature* creature) : ScriptedAI(creature), summons(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            EventMap   events;
            SummonList summons;

            bool vanquished;
            bool _introQiangDone;
            bool hasCallNext;

            uint8 shadowCount;
            uint8 maxShadowCount;

            void Reset()
            {
                shadowCount = 0;
                maxShadowCount = 3;

                vanquished        = false;
                _introQiangDone   = false;
                hasCallNext       = false;

                summons.DespawnAll();

                me->CastSpell(me, SPELL_INACTIVE, true);
                me->CastSpell(me, SPELL_INACTIVE_STUN, true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

                if (pInstance)
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                switch (me->GetEntry())
                {
                    case NPC_QIANG:
                        DoAction(ACTION_FIRST_FIGHT);
                        events.ScheduleEvent(EVENT_FLANKING_MOGU,       40000);
                        events.ScheduleEvent(EVENT_MASSIVE_ATTACK,      3500);
                        events.ScheduleEvent(EVENT_ANNIHILATE,          urand(15000, 20000));
                        SetEquipmentSlots(false, EQUIP_QIANG_POLEARM, 0, EQUIP_NO_CHANGE);

                        if (_introQiangDone)
                            me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        else
                            me->AddAura(SPELL_ACTIVATION_VISUAL, me);

                        if (pInstance->instance->IsHeroic())
                            events.ScheduleEvent(EVENT_IMPERVIOUS_SHIELD,   42000);
                        break;
                    case NPC_SUBETAI:
                        events.ScheduleEvent(EVENT_PILLAGE,             30000);
                        events.ScheduleEvent(EVENT_VOLLEY_1,            urand(15000, 20000));
                        events.ScheduleEvent(EVENT_RAIN_OF_ARROWS,      45000);
                        SetEquipmentSlots(false, EQUIP_SUBETAI_SWORD, EQUIP_SUBETAI_SWORD, EQUIP_SUBETAI_BOW);

                        if (pInstance->instance->IsHeroic())
                            events.ScheduleEvent(EVENT_SLEIGHT_OF_HAND,     42000);
                        break;
                    case NPC_ZIAN:
                        events.ScheduleEvent(EVENT_UNDYING_SHADOWS,     30000);
                        events.ScheduleEvent(EVENT_SHADOW_BLAST,        15000);
                        events.ScheduleEvent(EVENT_CHARGED_SHADOWS,     10000);
                        SetEquipmentSlots(false, EQUIP_ZIAN_STAFF, 0, EQUIP_NO_CHANGE);

                        if (pInstance->instance->IsHeroic())
                            events.ScheduleEvent(EVENT_SHIELD_OF_DARKNESS,  42500);
                        break;
                    case NPC_MENG:
                        events.ScheduleEvent(EVENT_MADDENING_SHOUT,     21000);
                        events.ScheduleEvent(EVENT_CRAZED,              1000);
                        events.ScheduleEvent(EVENT_CRAZY_THOUGHT,       10000);
                        me->RemoveAurasDueToSpell(SPELL_CRAZED);
                        me->RemoveAurasDueToSpell(SPELL_COWARDICE);
                        me->setPowerType(POWER_RAGE);
                        me->SetPower(POWER_RAGE, 0);

                        if (pInstance->instance->IsHeroic())
                            events.ScheduleEvent(EVENT_DELIRIOUS,           22500);
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome()
            {
                if (pInstance)
                    pInstance->SetBossState(DATA_SPIRIT_KINGS, FAIL);
            }

            Creature* GetControler()
            {
                if (pInstance)
                    return pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_SPIRIT_GUID_CONTROLER)));
                else
                    return NULL;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (me->IsWithinDistInMap(who, 50.0f, false) && !_introQiangDone && me->GetEntry() == NPC_QIANG)
                {
                    me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                    me->RemoveAurasDueToSpell(SPELL_INACTIVE_STUN);
                    me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                    _introQiangDone = true;
                    Talk(QIANG_INTRO);
                }
                else if (me->IsWithinDistInMap(who, 20.0f, false) && !me->IsInCombat())
                {
                    if (me->CanStartAttack(who, false))
                        AttackStart(who);
                }
            }

            void EnterCombat(Unit* attacker)
            {
                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    pInstance->SetBossState(DATA_SPIRIT_KINGS, IN_PROGRESS);

                    if (!pInstance->CheckRequiredBosses(DATA_SPIRIT_KINGS))
                        pInstance->DoCastSpellOnPlayers(7); // Suicide
                }

                switch (me->GetEntry())
                {
                    case NPC_ZIAN:
                        Talk(ZIAN_AGGRO);
                        break;
                    case NPC_MENG:
                        Talk(MENG_AGGRO);
                        break;
                    case NPC_QIANG:
                        Talk(QIANG_AGGRO);
                        break;
                    case NPC_SUBETAI:
                        Talk(SUBETAI_AGGRO);
                        break;
                    default:
                        break;
                }

                me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ENTER_COMBAT:
                        if (!me->IsInCombat())
                            if (Player* victim = me->SelectNearestPlayer(50.0f))
                                AttackStart(victim);
                    // No Break
                    case ACTION_FIRST_FIGHT:
                        me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INACTIVE_STUN);
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        me->setFaction(14);
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_UNDYING_SHADOW)
                    ++shadowCount;
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);

                if (summon->GetEntry() == NPC_UNDYING_SHADOW)
                    --shadowCount;
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE || type == EFFECT_MOTION_TYPE)
                {
                    if (id == EVENT_CHARGE && me->GetEntry() == NPC_SUBETAI)
                    {
                        me->CastSpell(me, SPELL_PILLAGE, false);
                    }
                }
            }

            void RegeneratePower(Powers power, int32& value)
            {
                // Any regeneration for Meng, except with Crazed or Cowardice
                if (me->GetEntry() == NPC_MENG)
                    value = 0;
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!pInstance)
                    return;

                if (pInstance->instance->IsHeroic())
                    if (me->HealthBelowPctDamaged(30, damage))
                        if (Creature* controler = GetControler())
                            if (!hasCallNext)
                            {
                                controler->AI()->DoAction(ACTION_SPIRIT_NEXT);
                                hasCallNext = true;
                            }

                if (me->HealthBelowPctDamaged(5, damage) && !vanquished)
                {
                    vanquished = true;
                    damage = 0;

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->AddAura(SPELL_INACTIVE, me);
                    me->SetReactState(REACT_PASSIVE);
                    me->getThreatManager().resetAllAggro();
                    me->SetSpeed(MOVE_RUN, 0.0f);
                    me->SetSpeed(MOVE_WALK, 0.0f);

                    if (pInstance)
                        pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* controler = GetControler())
                    {
                        if (!pInstance->instance->IsHeroic())
                        {
                            if (!hasCallNext)
                            {
                                controler->AI()->DoAction(ACTION_SPIRIT_NEXT);
                                hasCallNext = true;
                            }
                        }

                        controler->AI()->DoAction(ACTION_SPIRIT_KILLED);
                    }

                    // We reschedule only the vanquished spell
                    events.Reset();

                    switch (me->GetEntry())
                    {
                        case NPC_QIANG:
                            Talk(QIANG_DEATH);
                            // He calls for Flanking Orders every 75 seconds while defeated
                            events.ScheduleEvent(EVENT_FLANKING_MOGU, 75000);
                            break;
                        case NPC_SUBETAI:
                            Talk(SUBETAI_DEATH);
                            events.ScheduleEvent(EVENT_PILLAGE, 30000);
                            break;
                        case NPC_ZIAN:
                            Talk(ZIAN_DEATH);
                            events.ScheduleEvent(EVENT_UNDYING_SHADOWS, 30000);
                            break;
                        case NPC_MENG:
                            if (me->HasAura(SPELL_CRAZED))
                                Talk(MENG_DEATH_CRAZED);
                            else
                                Talk(MENG_DEATH_COWARDICE);

                            events.ScheduleEvent(EVENT_MADDENING_SHOUT, 35000);

                            me->RemoveAurasDueToSpell(SPELL_CRAZED);
                            me->RemoveAurasDueToSpell(SPELL_COWARDICE);

                            break;
                        default:
                            break;
                    }
                }
                else if (me->HealthBelowPctDamaged(10, damage))
                {
                    if (Creature* controler = GetControler())
                        controler->AI()->DoAction(ACTION_SAY_INTRO_FOR_NEXT_SPIRIT_IF_ANY);
                }

                if (Aura* aura = me->GetAura(SPELL_COWARDICE))
                {
                    int32 percentage = me->GetPower(POWER_RAGE) / 10;
                    int32 bp = int32(CalculatePct(damage, percentage));

                    bp /= 5;

                    if (Aura* cowardiceDot = attacker->GetAura(SPELL_COWARDICE_DOT))
                        bp += attacker->GetRemainingPeriodicAmount(me->GetGUID(), SPELL_COWARDICE_DOT, SPELL_AURA_PERIODIC_DAMAGE);

                    me->CastCustomSpell(attacker, SPELL_COWARDICE_DOT, &bp, NULL, NULL, true);
                }
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    switch (me->GetEntry())
                    {
                        case NPC_ZIAN:
                            Talk(ZIAN_SLAY);
                            break;
                        case NPC_MENG:
                            Talk(MENG_SLAY);
                            break;
                        case NPC_QIANG:
                            Talk(QIANG_SLAY);
                            break;
                        case NPC_SUBETAI:
                            Talk(SUBETAI_SLAY);
                            break;
                        default:
                            break;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        // Qiang
                        case EVENT_FLANKING_MOGU:
                        {
                            if (Creature* controler = GetControler())
                            {
                                me->CastSpell(me, SPELL_FLANKING_ORDERS, false);
                                controler->AI()->DoAction(ACTION_FLANKING_MOGU);
                                Talk(QIANG_SPELL);
                            }

                            if (vanquished)
                                events.ScheduleEvent(EVENT_FLANKING_MOGU, 75000);
                            else
                                events.ScheduleEvent(EVENT_FLANKING_MOGU, 40000);

                            break;
                        }
                        case EVENT_MASSIVE_ATTACK:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_MASSIVE_ATTACKS, false);

                            events.ScheduleEvent(EVENT_MASSIVE_ATTACK, 3500);
                            break;
                        }
                        case EVENT_ANNIHILATE:
                        {
                            DoCastAOE(SPELL_ANNIHILATE, false);
                            events.ScheduleEvent(EVENT_ANNIHILATE, urand(15000, 20000));
                            break;
                        }
                        case EVENT_IMPERVIOUS_SHIELD:
                        {
                            me->CastSpell(me, SPELL_IMPERVIOUS_SHIELD, false);
                            events.ScheduleEvent(EVENT_IMPERVIOUS_SHIELD, 40000);
                            break;
                        }
                        // Subetai
                        case EVENT_PILLAGE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                me->CastSpell(target, SPELL_PILLAGE_CHARGE, false);
                                Talk(SUBETAI_SPELL);
                            }

                            events.ScheduleEvent(EVENT_PILLAGE, 30000);
                            break;
                        }
                        case EVENT_VOLLEY_1:
                        case EVENT_VOLLEY_2:
                        case EVENT_VOLLEY_3:
                        {
                            me->CastSpell(me, volleySpells[eventId - EVENT_VOLLEY_1], false);
                            events.ScheduleEvent(eventId == EVENT_VOLLEY_3 ? EVENT_VOLLEY_1: eventId + 1, eventId == EVENT_VOLLEY_3 ? urand(15000, 20000): 50);
                            break;
                        }
                        case EVENT_RAIN_OF_ARROWS:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                                me->CastSpell(target, SPELL_RAIN_OF_ARROWS, false);

                            events.ScheduleEvent(EVENT_RAIN_OF_ARROWS, 45000);
                            break;
                        }
                        case EVENT_SLEIGHT_OF_HAND:
                        {
                            me->CastSpell(me, SPELL_SLEIGHT_OF_HAND, false);
                            events.ScheduleEvent(EVENT_SLEIGHT_OF_HAND, 42500);
                            break;
                        }
                        // Zian
                        case EVENT_UNDYING_SHADOWS:
                        {
                            if (shadowCount < maxShadowCount) // Max 3 undying shadow during the fight
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                                {
                                    me->CastSpell(target, SPELL_UNDYING_SHADOWS, false);
                                    Talk(ZIAN_SPELL);
                                }
                            }

                            events.ScheduleEvent(EVENT_UNDYING_SHADOWS, 45000);
                            break;
                        }
                        case EVENT_SHADOW_BLAST:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                                me->CastSpell(target, SPELL_SHADOW_BLAST, false);

                            events.ScheduleEvent(EVENT_SHADOW_BLAST, 15000);
                            break;
                        }
                        case EVENT_CHARGED_SHADOWS:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                                me->CastSpell(target, SPELL_CHARGED_SHADOWS, false);

                            events.ScheduleEvent(EVENT_CHARGED_SHADOWS, 15000);
                            break;
                        }
                        case EVENT_SHIELD_OF_DARKNESS:
                        {
                            me->CastSpell(me, SPELL_SHIELD_OF_DARKNESS, false);
                            events.ScheduleEvent(EVENT_SHIELD_OF_DARKNESS,  42500);
                            break;
                        }
                        // Meng
                        case EVENT_MADDENING_SHOUT:
                        {
                            me->CastSpell(me, SPELL_MADDENING_SHOUT, false);
                            Talk(MENG_SPELL);
                            events.ScheduleEvent(EVENT_MADDENING_SHOUT, 47000);
                            break;
                        }
                        case EVENT_CRAZED:
                        {
                            me->CastSpell(me, SPELL_CRAZED, false);
                            break;
                        }
                        case EVENT_CRAZY_THOUGHT:
                        {
                            me->CastSpell(me, SPELL_CRAZY_THOUGHT, false);
                            events.ScheduleEvent(EVENT_CRAZY_THOUGHT, 15000);
                            break;
                        }
                        case EVENT_DELIRIOUS:
                        {
                            me->CastSpell(me, SPELL_DELIRIOUS, false);
                            events.ScheduleEvent(EVENT_DELIRIOUS, 22500);
                            break;
                        }
                        default:
                            break;
                    }
                }

                if (!vanquished)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_spirit_kingsAI(creature);
        }
};

class mob_pinning_arrow : public CreatureScript
{
    public:
        mob_pinning_arrow() : CreatureScript("mob_pinning_arrow") {}

        struct mob_pinning_arrowAI : public ScriptedAI
        {
            mob_pinning_arrowAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint64 playerGuid;

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                playerGuid = 0;
            }

            void SetGUID(uint64 guid, int32 /*id*/ = 0)
            {
                playerGuid = guid;

                if (Player* player = ObjectAccessor::FindPlayer(pInstance->GetObjectGuid(playerGuid)))
                {
                    me->EnterVehicle(player);
                    me->AddAura(SPELL_PINNING_ARROW_VISUAL, me);
                }
            }

            void KilledUnit(Unit* victim)
            {
                me->DespawnOrUnsummon();
                victim->RemoveAurasDueToSpell(SPELL_PINNED_DOWN_DOT);
            }

            void JustDied(Unit* attacker)
            {
                /*if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                {
                    player->RemoveAurasDueToSpell(SPELL_PINNED_DOWN_DOT);
                    player->RemoveAurasDueToSpell(SPELL_PINNED_DOWN);
                }*/

                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_UNATTACKABLE))
                    me->ClearUnitState(UNIT_STATE_UNATTACKABLE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_pinning_arrowAI(creature);
        }
};

#define PHASE_UNDYING_SHADOW    true
#define PHASE_COALESCING_SHADOW false

class mob_undying_shadow : public CreatureScript
{
    public:
        mob_undying_shadow() : CreatureScript("mob_undying_shadow") {}

        struct mob_undying_shadowAI : public ScriptedAI
        {
            mob_undying_shadowAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            bool phase;
            uint32 switchPhaseTimer;
            float scale;
            uint64 targetGuid;

            void Reset()
            {
                me->CastSpell(me, SPELL_UNDYING_SHADOW_DOT, true);
                DoZoneInCombat();

                targetGuid = 0;

                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST))
                {
                    me->CastSpell(target, SPELL_FIXATE, true);
                    me->GetMotionMaster()->MoveChase(target);
                    targetGuid = target->GetGUID().GetEntry();
                }

                switchPhaseTimer = 0;
                scale = me->GetFloatValue(OBJECT_FIELD_SCALE_X);

                phase = PHASE_UNDYING_SHADOW;
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (phase == PHASE_UNDYING_SHADOW)
                {
                    if (damage >= me->GetHealth())
                    {
                       // if (Unit* target = ObjectAccessor::FindPlayer(targetGuid))
                         //   target->RemoveAurasDueToSpell(SPELL_FIXATE);

                        me->RemoveAurasDueToSpell(SPELL_UNDYING_SHADOW_DOT);
                        me->AddAura(SPELL_COALESCING_SHADOW_DOT, me);
                        me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        phase = PHASE_COALESCING_SHADOW;
                        switchPhaseTimer = 30000;
                        damage = 0;
                        targetGuid = 0;
                    }
                }
                else
                    damage = 0;
            }

            void UpdateAI(uint32 diff)
            {
                if (!pInstance)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (pInstance->GetBossState(DATA_SPIRIT_KINGS) == DONE)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (switchPhaseTimer)
                {
                    if (switchPhaseTimer <= diff)
                    {
                        me->RemoveAurasDueToSpell(SPELL_COALESCING_SHADOW_DOT);
                        me->AddAura(SPELL_UNDYING_SHADOW_DOT, me);
                        me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        phase = PHASE_UNDYING_SHADOW;
                        switchPhaseTimer = 0;
                        DoZoneInCombat();
                        me->SetHealth(me->GetMaxHealth());
                        me->SetObjectScale(scale);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->CastSpell(target, SPELL_FIXATE, true);
                            me->GetMotionMaster()->MoveChase(target);
                            targetGuid = target->GetGUID().GetEntry();
                        }
                    }
                    else
                    {
                        uint32 pct = uint32(float(switchPhaseTimer) / 30000.0f * 100.0f);
                        me->SetObjectScale(CalculatePct(scale, pct));

                        if (Unit* target = ObjectAccessor::FindPlayer(GetGUID(targetGuid)))
                            target->RemoveAurasDueToSpell(SPELL_FIXATE);

                        switchPhaseTimer -= diff;
                    }
                }
                else if (targetGuid)
                {
                    if (Unit* target = ObjectAccessor::FindPlayer(GetGUID(targetGuid)))
                        me->GetMotionMaster()->MoveChase(target);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_undying_shadowAI(creature);
        }
};

// Massive Attack - 117921
class spell_massive_attacks : public SpellScriptLoader
{
    public:
        spell_massive_attacks() : SpellScriptLoader("spell_massive_attacks") { }

        class spell_massive_attacks_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_massive_attacks_SpellScript);

            uint8 targetsCount;

            bool Load()
            {
                targetsCount = 1;
                return true;
            }

            void CheckTargets(std::list<WorldObject*>& targets)
            {
                targetsCount = targets.size();
            }

            void RecalculateDamage(SpellEffIndex /*effIndex*/)
            {
                SetHitDamage(GetHitDamage() / targetsCount);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_massive_attacks_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_54);
                OnEffectHitTarget += SpellEffectFn(spell_massive_attacks_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_massive_attacks_SpellScript();
        }
};

// Volley (1) - 118094, Volley (2) - 118105 and Volley (3) - 118106
class spell_volley : public SpellScriptLoader
{
    public:
        spell_volley() : SpellScriptLoader("spell_volley") { }

        class spell_volley_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_volley_SpellScript);

            void HandleDummyLaunch(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                float coneAngle = 0.0f;

                switch (GetSpellInfo()->Id)
                {
                    case SPELL_VOLLEY_1:
                        coneAngle = M_PI / (1.5f);
                        break;
                    case SPELL_VOLLEY_2:
                        coneAngle = M_PI / 4;
                        break;
                    case SPELL_VOLLEY_3:
                        coneAngle = M_PI / 6;
                        break;
                }

                float startAngle = caster->GetOrientation() - (coneAngle / 2);
                float maxAngle   = caster->GetOrientation() + (coneAngle / 2);

                for (float actualAngle = startAngle; actualAngle <= maxAngle; actualAngle += 0.1f)
                {
                    float x = 0.0f, y = 0.0f;
                    //GetPositionWithDistInOrientation(caster, 100.0f, actualAngle, x, y);

                    caster->CastSpell(x, y, caster->GetPositionZ(), SPELL_VOLLEY_VISUAL, true);
                }
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_volley_SpellScript::HandleDummyLaunch, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_volley_SpellScript();
        }
};

// Pinned Down - 118145
class spell_pinned_down : public SpellScriptLoader
{
    public:
        spell_pinned_down() : SpellScriptLoader("spell_pinned_down") { }

        class spell_pinned_down_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pinned_down_SpellScript);

            void HandleAfterHit()
            {
                if (Unit* target = GetHitUnit())
                    if (Creature* pinningArrow = target->SummonCreature(NPC_PINNING_ARROW, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN))
                        pinningArrow->AI()->SetGUID(target->GetGUID());
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_pinned_down_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pinned_down_SpellScript();
        }
};

// Maddening Shout - 117708
class spell_maddening_shout : public SpellScriptLoader
{
    public:
        spell_maddening_shout() : SpellScriptLoader("spell_maddening_shout") { }

        class spell_maddening_shout_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_maddening_shout_AuraScript);

            void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                if (Unit* attacker = dmgInfo.GetAttacker())
                    if (attacker->GetTypeId() != TYPEID_PLAYER)
                        absorbAmount = 0;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->RestoreFaction();
                    target->AttackStop();
                }
            }

            void Register()
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_maddening_shout_AuraScript::OnAbsorb, EFFECT_0);
                OnEffectRemove += AuraEffectRemoveFn(spell_maddening_shout_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_maddening_shout_AuraScript();
        }
};

// Cowardice - 117756 and Crazed - 117737
class spell_crazed_cowardice : public SpellScriptLoader
{
    public:
        spell_crazed_cowardice() : SpellScriptLoader("spell_crazed_cowardice") { }

        class spell_crazed_cowardice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_crazed_cowardice_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                
                if (Unit* caster = GetCaster())
                {
                    if (Aura* aura = GetAura())
                    {
                        bool hasDeliriousAura = caster->HasAura(SPELL_DELIRIOUS);

                        if (aura->GetId() == SPELL_CRAZED)
                            aura->SetStackAmount(aura->GetStackAmount() + hasDeliriousAura ? 2 : 1);
                        else
                            aura->SetCharges(aura->GetCharges() + hasDeliriousAura ? 2 : 1);

                        if (aura->GetStackAmount() >= 100 || aura->GetCharges() >= 100)
                        {
                            caster->CastSpell(caster, aura->GetId() == SPELL_CRAZED ? SPELL_COWARDICE: SPELL_CRAZED, true);
                            aura->Remove();
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_crazed_cowardice_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_crazed_cowardice_AuraScript();
        }

        class spell_crazed_cowardice_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_crazed_cowardice_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (GetSpellInfo()->Id == SPELL_COWARDICE)
                    {
                        caster->SetSpeed(MOVE_RUN, 0.5f);
                        caster->SetSpeed(MOVE_WALK, 0.5f);
                        if (caster->GetMotionMaster())
                            caster->GetMotionMaster()->MoveFleeing(caster);
                    }
                    else
                    {
                        if (caster->GetMotionMaster() && caster->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE)
                            caster->GetMotionMaster()->MovementExpired();

                        caster->SetSpeed(MOVE_RUN, 1.42857f);
                        caster->SetSpeed(MOVE_WALK, 0.888888f);

                        if (caster->GetAI())
                        {
                            if (Unit* target = caster->GetAI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                            {
                                caster->SetTarget(target->GetGUID());
                                caster->GetAI()->AttackStart(target);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_crazed_cowardice_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_crazed_cowardice_SpellScript();
        }
};

// Crazy Thought - 117833
class spell_crazy_thought : public SpellScriptLoader
{
    public:
        spell_crazy_thought() : SpellScriptLoader("spell_crazy_thought") { }

        class spell_crazy_thought_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_crazy_thought_SpellScript);

            void HandleEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 chargesToAdd = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;

                    if (caster->HasAura(SPELL_DELIRIOUS))
                        chargesToAdd *= 2;

                    if (Aura* crazedAura = caster->GetAura(SPELL_CRAZED))
                        crazedAura->SetStackAmount(crazedAura->GetStackAmount() + chargesToAdd);
                    else if (Aura* cowardiceAura = caster->GetAura(SPELL_COWARDICE))
                        cowardiceAura->SetCharges(cowardiceAura->GetCharges() + chargesToAdd);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_crazy_thought_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ENERGIZE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_crazy_thought_SpellScript();
        }
};

// Coalescing Shadow - 117558
class spell_coalescing_shadow : public SpellScriptLoader
{
    public:
        spell_coalescing_shadow() : SpellScriptLoader("spell_coalescing_shadow") { }

        class spell_coalescing_shadow_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_coalescing_shadow_SpellScript);

            void CorrectRange(std::list<WorldObject*>& targets)
            {
                targets.clear();

                float MaxDist = 10.0f * GetCaster()->GetFloatValue(OBJECT_FIELD_SCALE_X);

                Map::PlayerList const& players = GetCaster()->GetMap()->GetPlayers();
                    if (!players.isEmpty())
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            if (Player* player = itr->GetSource())
                                if (player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) < MaxDist)
                                    targets.push_back(player);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coalescing_shadow_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_coalescing_shadow_SpellScript();
        }
};

void AddSC_boss_spirit_kings()
{
    new boss_spirit_kings_controler();
    new boss_spirit_kings();
    new mob_pinning_arrow();
    new mob_undying_shadow();
    new spell_massive_attacks();
    new spell_volley();
    new spell_pinned_down();
    new spell_maddening_shout();
    new spell_crazed_cowardice();
    new spell_crazy_thought();
    new spell_coalescing_shadow();
}
