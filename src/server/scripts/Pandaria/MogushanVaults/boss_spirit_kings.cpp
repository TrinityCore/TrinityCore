/*
 * Copyright 2021 FuzionCore Project
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
    SPELL_ROBBED_BLIND          = 118163, // Heroic

    // Zian
    SPELL_UNDYING_SHADOWS       = 117506, // Also when vanquished
    SPELL_FIXATE                = 118303,
    SPELL_UNDYING_SHADOW_DOT    = 117514,
    SPELL_COALESCING_SHADOW_DOT = 117539,

    SPELL_SHADOW_BLAST          = 117628,
    SPELL_CHARGED_SHADOWS       = 117685,
    SPELL_SHIELD_OF_DARKNESS    = 117697, // Heroic
    SPELL_DARKNESS              = 117701, // Heroic

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
    SPELL_SPIRIT_KINGS_BONUS    = 132191,

    // Flanking Mogu
    SPELL_GHOST_VISUAL          = 117904,
    SPELL_TRIGGER_ATTACK        = 117917
};

enum eEvents
{
    // Quiang
    EVENT_FLANKING_MOGU         = 2,
    EVENT_MASSIVE_ATTACK        = 3,
    EVENT_ANNIHILATE            = 4,

    // Subetai
    EVENT_PILLAGE               = 5,
    EVENT_VOLLEY_1              = 6,
    EVENT_VOLLEY_2              = 7,
    EVENT_VOLLEY_3              = 8,
    EVENT_RAIN_OF_ARROWS        = 9,

    // Zian
    EVENT_UNDYING_SHADOWS       = 10,
    EVENT_SHADOW_BLAST          = 11,
    EVENT_CHARGED_SHADOWS       = 12,

    // Meng
    EVENT_MADDENING_SHOUT       = 13,
    EVENT_CRAZED                = 14,
    EVENT_CRAZY_THOUGHT         = 15,

    // Heroic
    EVENT_IMPERVIOUS_SHIELD     = 16,
    EVENT_DELIRIOUS             = 17,
    EVENT_SLEIGHT_OF_HAND       = 18,
    EVENT_SHIELD_OF_DARKNESS    = 19,

    EVENT_CHECK_SPIRITKINGS     = 20
};

enum equipId
{
    EQUIP_QIANG_POLEARM         = 86777,
    EQUIP_SUBETAI_SWORD         = 80283,
    EQUIP_SUBETAI_BOW           = 60790,
    EQUIP_ZIAN_STAFF            = 76369,
    EQUIP_FLANKING_MOGU_SWORD   = 68838,
    EQUIP_FLANKING_MOGU_SHIELD  = 32375
};

enum qiangTalk
{
    QIANG_AGGRO     = 0,
    QIANG_DEATH     = 1,
    QIANG_INTRO     = 2,
    QIANG_SLAY      = 3,
    QIANG_SPELL     = 4
};

enum subetaiTalk
{
    SUBETAI_AGGRO   = 0,
    SUBETAI_DEATH   = 1,
    SUBETAI_INTRO   = 2,
    SUBETAI_SLAY    = 3,
    SUBETAI_SPELL   = 4
};

enum zianTalk
{
    ZIAN_AGGRO  = 0,
    ZIAN_DEATH  = 1,
    ZIAN_INTRO  = 2,
    ZIAN_SLAY   = 3,
    ZIAN_SPELL  = 4
};

enum mengTalk
{
    MENG_AGGRO              = 0,
    MENG_DEATH_CRAZED       = 1,
    MENG_DEATH_COWARDICE    = 2,
    MENG_INTRO              = 3,
    MENG_SLAY               = 4,
    MENG_SPELL              = 5
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

/*
Position QiangTheMerciless      = {4226.33f, 1626.28f, 438.856f, 4.72348f};
Position SubetaiTheSwift        = {4257.35f, 1591.36f, 438.841f, 3.13526f};
Position ZianOfTheEndlessShadow = {4226.97f, 1558.32f, 438.804f, 1.58495f};
Position MengTheDemented        = {4198.78f, 1590.29f, 438.841f, 6.26345f};
*/

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
    NPC_ZIAN,
    NPC_MENG
};

// 60984 - Controller
class boss_spirit_kings_controler : public CreatureScript
{
    public:
        boss_spirit_kings_controler() : CreatureScript("boss_spirit_kings_controler") {}

        struct boss_spirit_kings_controlerAI : public BossAI
        {
            boss_spirit_kings_controlerAI(Creature* creature) : BossAI(creature, DATA_SPIRIT_KINGS)
            {
                pInstance = creature->GetInstanceScript();

                spiritKingsEntry.clear();
                spiritKingsEntry.resize(4, 0);

                spiritKingsEntry[0] = spiritsOrder[0];
                // We start from 1 as the first spirit kings to fight will always be the same (Qiang), so we just randomize the 3 other spirit kings
                for (uint8 i = 1; i < 4; ++i)
                {
                    // Fixed order in Heroic
                    if (IsHeroic())
                        spiritKingsEntry[i] = spiritsOrder[i];
                    // Random order in normal : pick a random entry, and check if not already assigned
                    else
                    {
                        bool duplicateEntry;
                        uint32 tmpEntry;
                        do
                        {
                            duplicateEntry = false;
                            uint8 pick = urand(1, 3);
                            tmpEntry = spiritsOrder[pick];
                            // check if tmpEntry hasn't been already chosen
                            for (uint8 j = 1; j < i; ++j)
                                if (!duplicateEntry && spiritKingsEntry[j] == tmpEntry)
                                    duplicateEntry = true;
                        } while (duplicateEntry);
                        spiritKingsEntry[i] = tmpEntry;
                    }
                }
                if (pInstance)
                {
                    EncounterState bossState = pInstance->GetBossState(DATA_SPIRIT_KINGS);
                    if (bossState != DONE && bossState != NOT_STARTED)
                        pInstance->SetBossState(DATA_SPIRIT_KINGS, NOT_STARTED);
                }
            }

            InstanceScript* pInstance;
            ObjectGuid flankingGuid[MAX_FLANKING_MOGU];
            std::vector<uint32> spiritKingsEntry;

            bool fightInProgress;
            bool _introZianDone;
            bool _introSubetaiDone;
            bool _introMengDone;
            EventMap events;

            uint8 vanquishedCount;
            uint8 nextSpirit;

            void Reset() override
            {
                _Reset();
                events.Reset();

                fightInProgress   = false;
                _introZianDone    = false;
                _introSubetaiDone = false;
                _introMengDone    = false;
                vanquishedCount   = 0;
                nextSpirit        = 0;

                for (uint8 i = 0; i < MAX_FLANKING_MOGU; ++i)
                    flankingGuid[i] = ObjectGuid::Empty;

                if (pInstance)
                    if (Creature* Qiang = pInstance->GetCreature(NPC_QIANG))
                        Qiang->AI()->DoAction(ACTION_FIRST_FIGHT);

                me->SetReactState(REACT_PASSIVE);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MADDENING_SHOUT);

                // Restoring player faction
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 200.0f);

                for (Player* player : playerList)
                    player->RestoreFaction();

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN_DOT);
            }

            void spawnFlankingMogu(uint8 moguNumber)
            {
                if (moguNumber >= MAX_FLANKING_MOGU)
                    return;

                if (Creature* flankingMogu = me->SummonCreature(NPC_FLANKING_MOGU, flankingPos[moguNumber].GetPositionX(), flankingPos[moguNumber].GetPositionY(), flankingPos[moguNumber].GetPositionZ(), flankingPos[moguNumber].GetOrientation()))
                {
                    flankingGuid[moguNumber] = flankingMogu->GetGUID();
                    flankingMogu->SetReactState(REACT_PASSIVE);
                    flankingMogu->AddAura(SPELL_GHOST_VISUAL, flankingMogu);
                    flankingMogu->SetVirtualItem(0, uint32(EQUIP_FLANKING_MOGU_SWORD));
                    flankingMogu->SetVirtualItem(2,uint32(EQUIP_FLANKING_MOGU_SHIELD));
                }
            }

            void DoAction(const int32 action) override
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

                        if (Creature* incomingSpirit = pInstance->GetCreature(spiritKingsEntry[1]))
                            me->AddAura(SPELL_ACTIVATION_VISUAL, incomingSpirit);

                        fightInProgress = true;
                        break;
                    }
                    case ACTION_FLANKING_MOGU:
                    {
                        uint8 moguBegin = urand(0, 47);
                        uint8 middleMogu = (moguBegin + 3) > 47 ? (moguBegin + 3) - 48: (moguBegin + 3);
                        float orientation = 0.0f;

                        if (Creature* flankingMogu = pInstance->instance->GetCreature(flankingGuid[middleMogu]))
                            orientation = flankingMogu->GetOrientation();

                        for (uint8 i = moguBegin; i < moguBegin + 6; ++i)
                        {
                            uint8 j = i;

                            if (j >= 48)
                                j -= 48;

                            if (Creature* flankingMogu = pInstance->instance->GetCreature(flankingGuid[j]))
                            {
                                flankingMogu->RemoveAurasDueToSpell(SPELL_GHOST_VISUAL);
                                flankingMogu->AddAura(SPELL_TRIGGER_ATTACK, flankingMogu);

                                float x = 0.0f, y = 0.0f;
                                GetPositionWithDistInOrientation(flankingMogu, 100.0f, orientation, x, y);

                                if (!x && !y)
                                    continue;

                                flankingMogu->GetMotionMaster()->MovePoint(1, x, y, flankingMogu->GetPositionZ());
                                flankingMogu->DespawnOrUnsummon(15000);

                                // Spawn a new one to remplace the old one
                                spawnFlankingMogu(j);
                            }
                        }
                        break;
                    }
                    case ACTION_ACTIVATE_SPIRIT:
                    {
                        if (IsHeroic())
                            nextSpirit = vanquishedCount + 1;

                        if (nextSpirit < 4)
                        {
                            if (!IsHeroic())
                                nextSpirit = vanquishedCount;

                            if (Creature* spirit = pInstance->GetCreature(spiritKingsEntry[nextSpirit]))
                            {
                                spirit->AI()->DoAction(ACTION_ENTER_COMBAT);

                                if (nextSpirit < 3)
                                {
                                    nextSpirit++;

                                    if (Creature* incomingSpirit = pInstance->GetCreature(spiritKingsEntry[nextSpirit]))
                                        me->AddAura(SPELL_ACTIVATION_VISUAL, incomingSpirit);
                                }
                            }
                        }
                        break;
                    }
                    case ACTION_SPIRIT_KILLED:
                    {
                        if (!fightInProgress)
                            break;

                        nextSpirit = ++vanquishedCount;

                        if (nextSpirit >= 4)
                        {
                            _JustDied();
                            summons.DespawnEntry(NPC_FLANKING_MOGU);
                            fightInProgress = false;

                            if (pInstance)
                            {
                                pInstance->SetBossState(DATA_SPIRIT_KINGS, DONE);
                                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MADDENING_SHOUT);

                                // Restoring player faction
                                std::list<Player*> playerList;
                                GetPlayerListInGrid(playerList, me, 200.0f);

                                for (Player* player : playerList)
                                    player->RestoreFaction();

                                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN);
                                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN_DOT);

                                for (auto entry: spiritKingsEntry)
                                {
                                    if (Creature* spirit = pInstance->GetCreature(entry))
                                    {
                                        spirit->LowerPlayerDamageReq(spirit->GetMaxHealth());
                                        spirit->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                                        spirit->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                        spirit->RemoveAura(SPELL_INACTIVE);


                                        if (Unit* killer = spirit->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                                            killer->Kill(spirit);
                                        else
                                            me->Kill(spirit);
                                    }
                                }

                                Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                                for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                                {
                                    if (Player* l_Player = l_Itr->GetSource())
                                        me->CastSpell(l_Player, SPELL_SPIRIT_KINGS_BONUS, true);
                                }
                            }

                            // Removing Undying Shadows
                            std::list<Creature*> shadList;
                            GetCreatureListWithEntryInGrid(shadList, me, NPC_UNDYING_SHADOW, 300.0f);

                            for (auto shadow : shadList)
                                shadow->DespawnOrUnsummon();

                            if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 200.0f, true))
                            {
                                if (lorewalkerCho->AI())
                                {
                                    lorewalkerCho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                                    lorewalkerCho->AI()->DoAction(ACTION_RUN);
                                }
                            }

                            if (GameObject* wall = GetClosestGameObjectWithEntry(me, GOB_SPIRIT_KINGS_EXIT, 100.0f))
                                if (wall->GetGoState() == GO_STATE_READY)
                                    wall->SetGoState(GO_STATE_ACTIVE);
                        }
                        else
                        {
                            // In heroic difficulty, next spirit has been activated before current spirit is killed
                            if (!IsHeroic())
                                DoAction(ACTION_ACTIVATE_SPIRIT);
                        }
                        break;
                    }
                    case ACTION_SAY_INTRO_FOR_NEXT_SPIRIT_IF_ANY:
                    {
                        if (vanquishedCount > 2)
                            break;

                        if (Creature* incomingSpirit = pInstance->GetCreature(spiritKingsEntry[vanquishedCount + 1]))
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
                    case ACTION_REACH_HOME:
                    {
                        if (pInstance)
                        {
                            pInstance->SetBossState(DATA_SPIRIT_KINGS, FAIL);
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MADDENING_SHOUT);

                            // Restoring player faction
                            std::list<Player*> playerList;
                            GetPlayerListInGrid(playerList, me, 200.0f);

                            for (Player* player : playerList)
                                player->RestoreFaction();

                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN);
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PINNED_DOWN_DOT);
                        }

                        // Reset each spirit
                        for (uint8 i = 0; i < 4; ++i)
                            if (Creature* spirit = pInstance->GetCreature(spiritsOrder[i]))
                                spirit->AI()->DoAction(ACTION_REACH_HOME);

                        fightInProgress   = false;
                        _introZianDone    = false;
                        _introSubetaiDone = false;
                        _introMengDone    = false;
                        vanquishedCount   = 0;
                        nextSpirit        = 0;

                        for (uint8 i = 0; i < MAX_FLANKING_MOGU; ++i)
                            flankingGuid[i] = ObjectGuid::Empty;

                        if (pInstance)
                            if (Creature* Qiang = pInstance->GetCreature(NPC_QIANG))
                                Qiang->AI()->DoAction(ACTION_FIRST_FIGHT);

                        me->SetReactState(REACT_PASSIVE);

                        summons.DespawnAll();
                        events.Reset();

                        break;
                    }
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(const uint32 /*diff*/) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!fightInProgress)
                    return;

                if (pInstance)
                {
                    if (pInstance->IsWipe())
                    {
                        DoAction(ACTION_REACH_HOME);
                        return;
                    }
                }
                // DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_spirit_kings_controlerAI(creature);
        }
};

// 60701 - Zian of the Endless Shadow
// 60708 - Meng the Demented
// 60709 - Qiang the Merciless
// 60710 - Subetai the Swift
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
            bool lowLife;
            bool preEventDone;

            uint8 shadowCount;
            uint8 maxShadowCount;

            void Reset() override
            {
                shadowCount = 0;
                maxShadowCount = 3;

                vanquished        = false;
                _introQiangDone   = false;
                lowLife           = false;
                preEventDone      = false;

                summons.DespawnAll();
                events.Reset();

                me->CastSpell(me, SPELL_INACTIVE, true);
                me->CastSpell(me, SPELL_INACTIVE_STUN, true);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));

                if (pInstance)
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                switch (me->GetEntry())
                {
                    case NPC_QIANG:
                        DoAction(ACTION_FIRST_FIGHT);
                        SetEquipmentSlots(false, EQUIP_QIANG_POLEARM, 0, EQUIP_NO_CHANGE);
                        break;
                    case NPC_SUBETAI:
                        SetEquipmentSlots(false, EQUIP_SUBETAI_SWORD, EQUIP_SUBETAI_SWORD, EQUIP_SUBETAI_BOW);
                        break;
                    case NPC_ZIAN:
                        SetEquipmentSlots(false, EQUIP_ZIAN_STAFF, 0, EQUIP_NO_CHANGE);
                        break;
                    case NPC_MENG:
                    default:
                        break;
                }
            }

            void JustReachedHome() override
            {
                if (me->GetEntry() != NPC_QIANG)
                {
                    me->AddAura(SPELL_INACTIVE, me);
                    me->AddAura(SPELL_INACTIVE_STUN, me);

                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                }
                else
                    if (pInstance)
                        if (pInstance->GetBossState(DATA_SPIRIT_KINGS) == FAIL)
                            pInstance->SetBossState(DATA_SPIRIT_KINGS, NOT_STARTED);
             }

            Creature* GetControler()
            {
                if (pInstance)
                    return pInstance->GetCreature(NPC_SPIRIT_GUID_CONTROLER);
                else
                    return NULL;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (me->IsWithinDistInMap(who, 50.0f, false) && !_introQiangDone && me->GetEntry() == NPC_QIANG)
                {
                    DoAction(ACTION_CHECK_SPIRITKINGS);
                    me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                    me->RemoveAurasDueToSpell(SPELL_INACTIVE_STUN);
                    me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                    _introQiangDone = true;
                    Talk(QIANG_INTRO);
                }
            }

            void EnterCombat(Unit* /*attacker*/) override
            {

                if (pInstance)
                {
                    if (!pInstance->CheckRequiredBosses(DATA_SPIRIT_KINGS))
                    {
                        EnterEvadeMode(EVADE_REASON_OTHER);
                        return;
                    }

                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    pInstance->SetBossState(DATA_SPIRIT_KINGS, IN_PROGRESS);

                    DoAction(ACTION_CHECK_SPIRITKINGS);

                }

                switch (me->GetEntry())
                {
                    case NPC_ZIAN:
                        Talk(ZIAN_AGGRO);
                        events.ScheduleEvent(EVENT_UNDYING_SHADOWS,     30000);
                        events.ScheduleEvent(EVENT_SHADOW_BLAST,        15000);
                        events.ScheduleEvent(EVENT_CHARGED_SHADOWS,     10000);
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_SHIELD_OF_DARKNESS, 50000);
                        break;
                    case NPC_MENG:
                        Talk(MENG_AGGRO);
                        events.ScheduleEvent(EVENT_MADDENING_SHOUT,     21000);
                        events.ScheduleEvent(EVENT_CRAZED,              1000);
                        events.ScheduleEvent(EVENT_CRAZY_THOUGHT,       10000);
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_DELIRIOUS,       50000);
                        me->RemoveAurasDueToSpell(SPELL_CRAZED);
                        me->RemoveAurasDueToSpell(SPELL_COWARDICE);
                        me->SetPowerType(POWER_RAGE);
                        me->SetPower(POWER_RAGE, 0);
                        break;
                    case NPC_QIANG:
                    {
                        Talk(QIANG_AGGRO);
                        events.ScheduleEvent(EVENT_FLANKING_MOGU,       40000);
                        events.ScheduleEvent(EVENT_MASSIVE_ATTACK,      3500);
                        events.ScheduleEvent(EVENT_ANNIHILATE,          urand(15000, 20000));
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_IMPERVIOUS_SHIELD, 50000);
                        if (_introQiangDone)
                            me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        else
                            me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    }
                    case NPC_SUBETAI:
                        Talk(SUBETAI_AGGRO);
                        events.ScheduleEvent(EVENT_PILLAGE,             30000);
                        events.ScheduleEvent(EVENT_VOLLEY_1,            urand(15000, 20000));
                        events.ScheduleEvent(EVENT_RAIN_OF_ARROWS,      45000);
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_SLEIGHT_OF_HAND, 50000);
                        break;
                    default:
                        break;
                }

                me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_ENTER_COMBAT:
                    {
                        if (!me->IsInCombat())
                            if (Player* victim = me->SelectNearestPlayer(50.0f))
                                AttackStart(victim);
                    }
                    // No Break
                    case ACTION_FIRST_FIGHT:
                    {
                        me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INACTIVE_STUN);
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                        me->SetFaction(14);
                        break;
                    }
                    case ACTION_REACH_HOME:
                    {
                        events.Reset();
                        summons.DespawnAll();
                        me->SetFullHealth();
                        me->SetReactState(REACT_PASSIVE);

                        vanquished      = false;
                        _introQiangDone = false;
                        lowLife         = false;
                        preEventDone    = false;

                        shadowCount     = 0;
                        maxShadowCount  = 3;

                        if (me->HasAura(SPELL_INACTIVE_STUN))
                            me->RemoveAura(SPELL_INACTIVE_STUN);
                        if (me->HasUnitState(UNIT_STATE_NOT_MOVE))
                            me->ClearUnitState(UNIT_STATE_NOT_MOVE);

                        if (pInstance)
                            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                        me->GetMotionMaster()->MoveTargetedHome();
                        me->SetFullHealth();
                        break;
                    }
                    case ACTION_CHECK_SPIRITKINGS:
                    {
                        if (GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f, true))
                        {
                            me->SetFullHealth();
                            me->SetReactState(REACT_PASSIVE);
                            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            if (pInstance)
                            {
                                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                                if (pInstance->GetBossState(DATA_SPIRIT_KINGS) != NOT_STARTED &&
                                    pInstance->GetBossState(DATA_SPIRIT_KINGS) != DONE)
                                    pInstance->SetBossState(DATA_SPIRIT_KINGS, NOT_STARTED);
                            }
                            events.ScheduleEvent(EVENT_CHECK_SPIRITKINGS, 500);
                            return;
                        }
                        else
                        {
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            if (pInstance)
                                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                            preEventDone = true;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_UNDYING_SHADOW)
                    ++shadowCount;
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);

                if (summon->GetEntry() == NPC_UNDYING_SHADOW)
                    --shadowCount;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == EVENT_CHARGE && me->GetEntry() == NPC_SUBETAI)
                    {
                        me->CastSpell(me, SPELL_PILLAGE, false);
                    }
                }
            }

            void RegeneratePower(Powers /*power*/, int32& value) override
            {
                // Any regeneration for Meng, except with Crazed or Cowardice
                if (me->GetEntry() == NPC_MENG)
                    value = 0;
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (me->GetEntry() == NPC_QIANG)
                {
                    DoAction(ACTION_CHECK_SPIRITKINGS);
                    me->RemoveAura(SPELL_INACTIVE);
                    me->RemoveAura(SPELL_INACTIVE_STUN);
                }

                if (me->GetEntry() == NPC_ZIAN && me->HasAura(SPELL_SHIELD_OF_DARKNESS))
                    me->CastSpell(me, SPELL_DARKNESS, false);

                if (me->HealthBelowPctDamaged(30, damage) && IsHeroic() && !lowLife)
                {
                    // Triggered once only
                    lowLife = true;
                    if (Creature* controler = GetControler())
                        controler->AI()->DoAction(ACTION_ACTIVATE_SPIRIT);
                }

                if (me->HealthBelowPctDamaged(5, damage) && !vanquished)
                {
                    vanquished = true;
                    damage = 0;

                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                    me->AddAura(SPELL_INACTIVE, me);
                    me->SetReactState(REACT_PASSIVE);
                    me->getThreatManager().resetAllAggro();
                    me->SetSpeed(MOVE_RUN, 0.0f);
                    me->SetSpeed(MOVE_WALK, 0.0f);
                    me->AddUnitState(UNIT_STATE_NOT_MOVE);

                    if (pInstance)
                        pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* controler = GetControler())
                        controler->AI()->DoAction(ACTION_SPIRIT_KILLED);

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

                if (me->HasAura(SPELL_COWARDICE))
                {
                    int32 percentage = me->GetPower(POWER_RAGE) / 10;
                    float bp = CalculatePct(damage, percentage);

                    bp /= 5;

                    if (attacker->HasAura(SPELL_COWARDICE_DOT))
                        bp += attacker->GetRemainingPeriodicAmount(me->GetGUID(), SPELL_COWARDICE_DOT, SPELL_AURA_PERIODIC_DAMAGE);

                    me->CastCustomSpell(attacker, SPELL_COWARDICE_DOT, &bp, nullptr, nullptr, true);
                }
            }

            void JustDied(Unit* p_Killer) override
            {
                ScriptedAI::JustDied(p_Killer);

                /*if (IsLFR())
                {
                    me->SetLootRecipient(nullptr);

                    if (me->GetEntry() == NPC_QIANG)
                    {
                        Player* l_Player = me->GetMap()->GetPlayers().begin()->GetSource();
                        if (l_Player && l_Player->GetGroup())
                            sLFGMgr->AutomaticLootAssignation(me, l_Player->GetGroup());
                    }
                }*/
            }

            void KilledUnit(Unit* who) override
            {
                if (who->IsPlayer())
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

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() && preEventDone)
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (pInstance)
                    if (pInstance->GetBossState(DATA_SPIRIT_KINGS) == NOT_STARTED && me->GetHealth() < me->GetMaxHealth())
                        pInstance->SetBossState(DATA_SPIRIT_KINGS, IN_PROGRESS);

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
                                // In Heroic Mode, there are 2 flanking orders at the same time
                                if (IsHeroic())
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
                            me->CastSpell(me, SPELL_ANNIHILATE, false);
                            events.ScheduleEvent(EVENT_ANNIHILATE, urand(15000, 20000));
                            break;
                        }
                        case EVENT_IMPERVIOUS_SHIELD:
                        {
                            me->CastSpell(me, SPELL_IMPERVIOUS_SHIELD, true);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_IMPERVIOUS_SHIELD, urand(45000, 50000));
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
                            me->CastSpell(me, SPELL_SLEIGHT_OF_HAND, true);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_SLEIGHT_OF_HAND, urand(45000, 55000));
                            break;
                        }
                        // Zian
                        case EVENT_UNDYING_SHADOWS:
                        {
                            // While in Cowardice personality, Zian is Feared.
                            if (shadowCount < maxShadowCount) // Max 3 undying shadow during the fight
                            {
                                std::list<Player*> playerList;
                                GetPlayerListInGrid(playerList, me, 300.0f);
                                std::list<Player*>::iterator itr, next;

                                // Not applying on dead players or on players who already have an undying shadow
                                for (itr = playerList.begin(); itr != playerList.end(); itr = next)
                                {
                                    next = itr;
                                    ++next;

                                    if (!(*itr)->IsAlive() || (*itr)->HasAura(SPELL_FIXATE))
                                        playerList.remove(*itr);
                                }

                                // No player to cast on: reschedule event
                                if (playerList.empty())
                                {
                                    events.ScheduleEvent(EVENT_UNDYING_SHADOWS, 10000);
                                    break;
                                }

                                // Picking a random target
                                bool searching = true;
                                itr = playerList.begin();
                                Unit* target = 0;
                                while (searching)
                                {
                                    if (urand(0, 1))
                                    {
                                        target = *itr;
                                        searching = false;
                                    }
                                    ++itr;
                                    if (itr == playerList.end())
                                        itr = playerList.begin();
                                }

                                me->CastSpell(target, SPELL_UNDYING_SHADOWS, false);
                                Talk(ZIAN_SPELL);
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
                            me->CastSpell(me, SPELL_SHIELD_OF_DARKNESS, true);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_SHIELD_OF_DARKNESS, urand(45000, 55000));
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
                            me->CastSpell(me, SPELL_DELIRIOUS, true);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_DELIRIOUS, urand(45000, 55000));
                            break;
                        }
                        case EVENT_CHECK_SPIRITKINGS:
                        {
                            DoAction(ACTION_CHECK_SPIRITKINGS);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_spirit_kingsAI(creature);
        }
};

// 60958 - Pinning Arrow
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
            ObjectGuid playerGuid;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                playerGuid = ObjectGuid::Empty;
            }

            void SetGUID(ObjectGuid guid, int32 /*id*/ = 0) override
            {
                playerGuid = guid;

                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                {
                    me->EnterVehicle(player);
                    me->AddAura(SPELL_PINNING_ARROW_VISUAL, me);
                }
            }

            void KilledUnit(Unit* victim) override
            {
                me->DespawnOrUnsummon();
                victim->RemoveAurasDueToSpell(SPELL_PINNED_DOWN_DOT);
            }

            void JustDied(Unit* /*attacker*/) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                {
                    player->RemoveAurasDueToSpell(SPELL_PINNED_DOWN_DOT);
                    player->RemoveAurasDueToSpell(SPELL_PINNED_DOWN);
                }

                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 const /*diff*/) override
            {
                if (me->HasUnitState(UNIT_STATE_UNATTACKABLE))
                    me->ClearUnitState(UNIT_STATE_UNATTACKABLE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_pinning_arrowAI(creature);
        }
};

#define PHASE_UNDYING_SHADOW    true
#define PHASE_COALESCING_SHADOW false

// 60731 - Undying Shadows
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
            ObjectGuid targetGuid;

            void Reset() override
            {
                me->CastSpell(me, SPELL_UNDYING_SHADOW_DOT, true);
                DoZoneInCombat();

                targetGuid = ObjectGuid::Empty;

                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST))
                {
                    me->CastSpell(target, SPELL_FIXATE, true);
                    me->GetMotionMaster()->MoveChase(target);
                    targetGuid = target->GetGUID();
                }

                switchPhaseTimer = 0;
                scale = me->GetObjectScale();

                phase = PHASE_UNDYING_SHADOW;
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (phase == PHASE_UNDYING_SHADOW)
                {
                    if (damage >= me->GetHealth())
                    {
                        if (Unit* target = ObjectAccessor::FindPlayer(targetGuid))
                            target->RemoveAurasDueToSpell(SPELL_FIXATE);

                        me->RemoveAurasDueToSpell(SPELL_UNDYING_SHADOW_DOT);
                        me->AddAura(SPELL_COALESCING_SHADOW_DOT, me);
                        me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                        phase = PHASE_COALESCING_SHADOW;
                        switchPhaseTimer = 30000;
                        damage = 0;
                        targetGuid = ObjectGuid::Empty;
                    }
                }
                else
                    damage = 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (switchPhaseTimer)
                {
                    if (switchPhaseTimer <= diff)
                    {
                        me->RemoveAurasDueToSpell(SPELL_COALESCING_SHADOW_DOT);
                        me->AddAura(SPELL_UNDYING_SHADOW_DOT, me);
                        me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                        phase = PHASE_UNDYING_SHADOW;
                        switchPhaseTimer = 0;
                        DoZoneInCombat();
                        me->SetHealth(me->GetMaxHealth());
                        me->SetObjectScale(scale);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->CastSpell(target, SPELL_FIXATE, true);
                            me->GetMotionMaster()->MoveChase(target);
                            targetGuid = target->GetGUID();
                        }
                    }
                    else
                    {
                        uint32 pct = uint32(float(switchPhaseTimer) / 30000.0f * 100.0f);
                        me->SetObjectScale(CalculatePct(scale, pct));

                        if (Unit* target = ObjectAccessor::FindPlayer(targetGuid))
                            target->RemoveAurasDueToSpell(SPELL_FIXATE);

                        switchPhaseTimer -= diff;
                    }
                }
                else if (!targetGuid.IsEmpty())
                {
                    if (Unit* target = ObjectAccessor::FindPlayer(targetGuid))
                        me->GetMotionMaster()->MoveChase(target);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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

            bool Load() override
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

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_massive_attacks_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_54);
                OnEffectHitTarget += SpellEffectFn(spell_massive_attacks_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
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
                        coneAngle = float(M_PI) / 1.5f;
                        break;
                    case SPELL_VOLLEY_2:
                        coneAngle = float(M_PI) / 4.f;
                        break;
                    case SPELL_VOLLEY_3:
                        coneAngle = float(M_PI) / 6.f;
                        break;
                }

                float startAngle = caster->GetOrientation() - (coneAngle / 2);
                float maxAngle   = caster->GetOrientation() + (coneAngle / 2);

                for (float actualAngle = startAngle; actualAngle <= maxAngle; actualAngle += 0.1f)
                {
                    float x = 0.0f, y = 0.0f;
                    GetPositionWithDistInOrientation(caster, 100.0f, actualAngle, x, y);

                    caster->CastSpell(x, y, caster->GetPositionZ(), SPELL_VOLLEY_VISUAL, true);
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_volley_SpellScript::HandleDummyLaunch, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
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

            void Register() override
            {
                AfterHit += SpellHitFn(spell_pinned_down_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const override
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

            void OnAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
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

            void Register() override
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_maddening_shout_AuraScript::OnAbsorb, EFFECT_0);
                OnEffectRemove += AuraEffectRemoveFn(spell_maddening_shout_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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
                        caster->EnergizeBySpell(caster, aura->GetId(), 10, POWER_RAGE);

                        if (aura->GetEffect(1))
                        {
                            if (aura->GetId() == SPELL_CRAZED)
                                aura->GetEffect(1)->ChangeAmount(caster->GetPower(POWER_RAGE) / 5);
                            else
                                aura->GetEffect(1)->ChangeAmount(caster->GetPower(POWER_RAGE) / 10);

                            aura->SetNeedClientUpdateForTargets();
                        }

                        if (caster->GetPower(POWER_RAGE) >= 1000)
                        {
                            caster->SetPower(POWER_RAGE, 0);
                            caster->CastSpell(caster, aura->GetId() == SPELL_CRAZED ? SPELL_COWARDICE : SPELL_CRAZED, true);
                            aura->Remove();
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_crazed_cowardice_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_crazed_cowardice_AuraScript();
        }

        class spell_crazed_cowardice_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_crazed_cowardice_SpellScript);

            float runSpeed;
            float walkSpeed;

            bool Load() override
            {
                // Values from DB
                runSpeed = 1.42857f;
                walkSpeed = 0.888888f;

                return GetCaster();
            }

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (GetSpellInfo()->Id == SPELL_COWARDICE)
                    {
                        caster->SetSpeed(MOVE_RUN, 0.5f);
                        caster->SetSpeed(MOVE_WALK, 0.5f);
                        caster->GetMotionMaster()->MoveFleeing(caster);
                    }
                    else
                    {
                        if (caster->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE)
                            caster->GetMotionMaster()->MovementExpired();

                        caster->SetSpeed(MOVE_RUN, runSpeed);
                        caster->SetSpeed(MOVE_WALK, walkSpeed);

                        if (Unit* target = caster->GetAI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                        {
                            caster->SetTarget(target->GetGUID());
                            caster->GetAI()->AttackStart(target);
                        }
                    }
                }
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_crazed_cowardice_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
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

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    caster->EnergizeBySpell(caster, GetSpellInfo()->Id, 100, POWER_RAGE);

                    if (Aura* cowardice = caster->GetAura(SPELL_COWARDICE))
                    {
                        if (cowardice->GetEffect(1))
                        {
                            cowardice->GetEffect(1)->ChangeAmount(caster->GetPower(POWER_RAGE) / 10);
                            cowardice->SetNeedClientUpdateForTargets();
                        }
                    }
                    else if (Aura* crazed = caster->GetAura(SPELL_CRAZED))
                    {
                        if (crazed->GetEffect(1))
                        {
                            crazed->GetEffect(1)->ChangeAmount(caster->GetPower(POWER_RAGE) / 5);
                            crazed->SetNeedClientUpdateForTargets();
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_crazy_thought_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ENERGIZE);
            }
        };

        SpellScript* GetSpellScript() const override
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

                float MaxDist = 10.0f * GetCaster()->GetObjectScale();

                Map::PlayerList const& players = GetCaster()->GetMap()->GetPlayers();
                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->GetSource())
                            if (player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) < MaxDist)
                                targets.push_back(player);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coalescing_shadow_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_coalescing_shadow_SpellScript();
        }
};

/// 118163 - Sleight of hand
class spell_sleight_of_hand : public SpellScriptLoader
{
    public:
        spell_sleight_of_hand() : SpellScriptLoader("spell_sleight_of_hand") { }

        class spell_sleight_of_hand_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sleight_of_hand_AuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);
            }

            void Remove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_sleight_of_hand_AuraScript::Apply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_sleight_of_hand_AuraScript::Remove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sleight_of_hand_AuraScript();
        }
};

// 117697 - Shield of Darkness
class spell_shield_of_darkness : public SpellScriptLoader
{
    public:
        spell_shield_of_darkness() : SpellScriptLoader("spell_shield_of_darkness") { }

        class spell_shield_of_darkness_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shield_of_darkness_SpellScript);

            void SetStack()
            {
                if (Unit* caster = GetCaster())
                {
                    Aura* shieldDarkness = caster->GetAura(SPELL_SHIELD_OF_DARKNESS);
                    shieldDarkness->SetCharges(5);
                }
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_shield_of_darkness_SpellScript::SetStack);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shield_of_darkness_SpellScript();
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
    new spell_sleight_of_hand();
    new spell_shield_of_darkness();
}
