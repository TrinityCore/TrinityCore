/* Copyright (C) 2006 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_KelThuzad
SD%Complete: 80%
SDComment: VERIFY SCRIPT
SDCategory: Naxxramas
EndScriptData */

#include "ScriptPCH.h"
#include "naxxramas.h"

enum Yells
{
    //when shappiron dies. dialog between kel and lich king (in this order)
    SAY_SAPP_DIALOG1                                       = -1533084, //not used
    SAY_SAPP_DIALOG2_LICH                                  = -1533085, //not used
    SAY_SAPP_DIALOG3                                       = -1533086, //not used
    SAY_SAPP_DIALOG4_LICH                                  = -1533087, //not used
    SAY_SAPP_DIALOG5                                       = -1533088, //not used
    SAY_CAT_DIED                                           = -1533089, //when cat dies, not used
    //when each of the 4 wing bosses dies
    SAY_TAUNT1                                             = -1533090, //not used
    SAY_TAUNT2                                             = -1533091, //not used
    SAY_TAUNT3                                             = -1533092, //not used
    SAY_TAUNT4                                             = -1533093, //not used
    SAY_SUMMON_MINIONS                                     = -1533105, //start of phase 1
    SAY_AGGRO_1                                            = -1533094, //start of phase 2
    SAY_AGGRO_2                                            = -1533095,
    SAY_AGGRO_3                                            = -1533096,
    SAY_SLAY_1                                             = -1533097,
    SAY_SLAY_2                                             = -1533098,
    SAY_DEATH                                              = -1533099,
    SAY_CHAIN_1                                            = -1533100,
    SAY_CHAIN_2                                            = -1533101,
    SAY_FROST_BLAST                                        = -1533102,
    SAY_SPECIAL_1                                          = -1533106,
    SAY_SPECIAL_2                                          = -1533107,
    SAY_SPECIAL_3                                          = -1533108,
    SAY_REQUEST_AID                                        = -1533103, //start of phase 3
    SAY_ANSWER_REQUEST                                     = -1533104  //lich king answer
};
enum Event
{
    EVENT_NONE,
    EVENT_BOLT,
    EVENT_NOVA,
    EVENT_CHAIN,
    EVENT_CHAINED_SPELL,
    EVENT_DETONATE,
    EVENT_FISSURE,
    EVENT_BLAST,

    EVENT_WASTE,
    EVENT_ABOMIN,
    EVENT_WEAVER,
    EVENT_ICECROWN,
    EVENT_TRIGGER,

    EVENT_PHASE,
};

enum Spells
{
    SPELL_FROST_BOLT                                       = 28478,
    H_SPELL_FROST_BOLT                                     = 55802,
    SPELL_FROST_BOLT_AOE                                   = 28479,
    H_SPELL_FROST_BOLT_AOE                                 = 55807,
    SPELL_SHADOW_FISURE                                    = 27810,
    SPELL_VOID_BLAST                                       = 27812,
    SPELL_MANA_DETONATION                                  = 27819,
    SPELL_FROST_BLAST                                      = 27808,
    SPELL_CHAINS_OF_KELTHUZAD                              = 28410, //28408 script effect
    SPELL_KELTHUZAD_CHANNEL                                = 29423,
    SPELL_BERSERK                                          = 28498,

    //spells for chained
    //warlock
    SPELL_CURSE_OF_AGONY                                   = 47864,
    SPELL_SHADOW_BOLT                                      = 47809,
    //shaman
    SPELL_EARTH_SHOCK                                      = 49231,
    SPELL_HEALING_WAVE                                     = 49273,
    //mage
    SPELL_FROST_FIREBOLT                                   = 47610,
    SPELL_ARCANE_MISSILES                                  = 42846,
    //rogue
    SPELL_HEMORRHAGE                                       = 48660,
    SPELL_MUTILATE                                         = 48666,
    //paladin
    SPELL_HOLY_SHOCK                                       = 48825,
    SPELL_HAMMER_OF_JUSTICE                                = 10308,
    //priest
    SPELL_VAMPIRIC_TOUCH                                   = 48160,
    SPELL_RENEW                                            = 48068,
    //hunter
    SPELL_MULTI_SHOT                                       = 49048,
    SPELL_VOLLEY                                           = 58434,
    //warrior
    SPELL_BLADESTORM                                       = 46924,
    SPELL_CLEAVE                                           = 47520,
    //druid
    SPELL_MOONFIRE                                         = 48463,
    SPELL_LIFEBLOOM                                        = 48451,
    //death knight
    SPELL_PLAGUE_STRIKE                                    = 49921,
    SPELL_HOWLING_BLAST                                    = 51411,
};

enum Creatures
{
    NPC_WASTE                                              = 16427, // Soldiers of the Frozen Wastes
    NPC_ABOMINATION                                        = 16428, // Unstoppable Abominations
    NPC_WEAVER                                             = 16429, // Soul Weavers
    NPC_ICECROWN                                           = 16441 // Guardians of Icecrown
};

const Position Pos[12] =
{
    {3783.272705, -5062.697266, 143.711203, 3.617599},     //LEFT_FAR
    {3730.291260, -5027.239258, 143.956909, 4.461900},     //LEFT_MIDDLE
    {3757.6, -5172.0, 143.7, 1.97},                        //WINDOW_PORTAL05
    {3759.355225, -5174.128418, 143.802383, 2.170104},     //RIGHT_FAR
    {3700.724365, -5185.123047, 143.928024, 1.309310},     //RIGHT_MIDDLE
    {3700.86, -5181.29, 143.928024, 1.42},                 //WINDOW_PORTAL04
    {3754.431396, -5080.727734, 142.036316, 3.736189},     //LEFT_FAR
    {3724.396484, -5061.330566, 142.032700, 4.564785},     //LEFT_MIDDLE
    {3732.02, -5028.53, 143.92, 4.49},                     //WINDOW_PORTAL02
    {3687.571777, -5126.831055, 142.017807, 0.604023},     //RIGHT_FAR
    {3707.990733, -5151.450195, 142.032562, 1.376855},     //RIGHT_MIDDLE
    {3782.76, -5062.97, 143.79, 3.82},                     //WINDOW_PORTAL03
};

//creatures in corners
//Unstoppable Abominations
#define MAX_ABOMINATIONS                        21
const Position PosAbominations[MAX_ABOMINATIONS] =
{
    {3755.52, -5155.22, 143.480, 2.0},
    {3744.35, -5164.03, 143.590, 2.00},
    {3749.28, -5159.04, 143.190, 2.0},
    {3774.47, -5076.28, 143.528, 2.15912},
    {3765.94, -5074.15, 143.186, 3.77233},
    {3763.15, -5063.36, 143.694, 3.77233},
    {3737.81, -5045.69, 143.709, 4.9033},
    {3728.13, -5045.01, 143.355, 1.45069},
    {3721.56, -5048.35, 143.542, 1.45069},
    {3689.55, -5049.66, 143.637, 5.2104},
    {3681.71, -5053.03, 143.242, 2.47957},
    {3677.64, -5061.44, 143.358, 2.47957},
    {3654.2, -5090.87, 143.469, 1.0313},
    {3650.39, -5097.45, 143.496, 2.5047},
    {3658.7, -5103.59, 143.607, 3.3278},
    {3659.02, -5133.97, 143.624, 3.84538},
    {3666.33, -5139.34, 143.183, 3.84538},
    {3669.74, -5149.63, 143.678, 0.528643},
    {3695.53, -5169.53, 143.671, 2.11908},
    {3701.98, -5166.51, 143.395, 1.24257},
    {3709.62, -5169.15, 143.576, 5.97695},
};

//Soldiers of the Frozen Wastes
#define MAX_WASTES                              49
const Position PosWastes[MAX_WASTES] =
{
    {3754.41, -5147.24, 143.204, 2.0},
    {3754.68, -5156.17, 143.418, 2.0},
    {3757.91, -5160.12, 143.503, 2.0},
    {3752.67, -5164.6, 143.395, 2.0},
    {3745.42, -5164.47, 143.565, 2.74587},
    {3741.2, -5155.92, 143.17, 5.29134},
    {3746.57, -5148.82, 143.176, 5.07772},
    {3778.14, -5070.1, 143.568, 3.16208},
    {3775.09, -5078.97, 143.65, 2.81022},
    {3773.54, -5083.47, 143.758, 3.21549},
    {3765, -5078.29, 143.176, 4.36688},
    {3766.94, -5072.63, 143.184, 5.27951},
    {3762.68, -5064.94, 143.635, 3.95297},
    {3769.9, -5059.94, 143.74, 3.36549},
    {3736.33, -5042.18, 143.643, 5.9471},
    {3727.51, -5040.58, 143.502, 0.871859},
    {3719.89, -5049.64, 143.58, 4.75172},
    {3720.69, -5044.43, 143.662, 1.87245},
    {3725.69, -5048.99, 143.363, 2.48271},
    {3732.33, -5054.01, 143.44, 3.59405},
    {3738.09, -5051.06, 143.718, 4.70931},
    {3682.76, -5063.5, 143.175, 0.636238},
    {3686.7, -5060.58, 143.18, 0.636238},
    {3682.45, -5057.21, 143.184, 5.61252},
    {3677.57, -5053.34, 143.369, 1.52531},
    {3677.3, -5062.26, 143.369, 2.73482},
    {3691.21, -5053.02, 143.421, 5.93218},
    {3685.22, -5053.34, 143.314, 4.70303},
    {3652.11, -5088.47, 143.555, 0.793317},
    {3648.23, -5093.21, 143.311, 1.18837},
    {3648.14, -5100.11, 143.632, 2.12221},
    {3653.88, -5099.7, 143.558, 3.04348},
    {3661.23, -5100.33, 143.42, 4.08335},
    {3663.49, -5092.77, 143.346, 4.47134},
    {3661.85, -5087.99, 143.571, 1.0148},
    {3664.56, -5149.01, 143.532, 0.0762528},
    {3665.01, -5142.04, 143.201, 1.72009},
    {3671.15, -5142.92, 143.174, 4.81535},
    {3670.18, -5134.38, 143.177, 5.37534},
    {3664.33, -5131.69, 143.262, 5.39576},
    {3658.21, -5133.63, 143.662, 1.3863},
    {3659.7, -5144.49, 143.363, 2.32328},
    {3705.71, -5179.63, 143.746, 1.06743},
    {3696.77, -5177.45, 143.759, 5.36748},
    {3700.97, -5173.13, 143.52, 3.26575},
    {3708.53, -5172.19, 143.573, 3.26575},
    {3712.49, -5167.62, 143.657, 5.63295},
    {3704.89, -5161.84, 143.239, 5.63295},
    {3695.66, -5164.63, 143.674, 1.54416},
};

//Soul Weavers
#define MAX_WEAVERS                             7
const Position PosWeavers[MAX_WEAVERS] =
{
    {3752.45, -5168.35, 143.562, 1.6094},
    {3772.2, -5070.04, 143.329, 1.93686},
    {3732.28, -5032.88, 143.771, 3.08355},
    {3689.05, -5055.7, 143.172, 6.09554},
    {3649.45, -5093.17, 143.299, 2.51805},
    {3659.7, -5144.49, 143.363, 4.08806},
    {3704.71, -5175.96, 143.597, 3.36549},
};

// predicate function to select not charmed target
struct NotCharmedTargetSelector : public std::unary_function<Unit *, bool> {
    NotCharmedTargetSelector() {}

    bool operator() (const Unit *pTarget) {
        return (!pTarget->isCharmed());
    }
};

struct boss_kelthuzadAI : public BossAI
{
    boss_kelthuzadAI(Creature* c) : BossAI(c, BOSS_KELTHUZAD), spawns(c)
    {
        uiFaction = me->getFaction();
    }

    uint32 Phase;
    uint32 uiGuardiansOfIcecrownTimer;
    uint32 uiFaction;

    uint8  nGuardiansOfIcecrownCount;
    uint8  nAbomination;
    uint8  nWeaver;

    std::map<uint64, float> chained;

    uint64 PortalsGUID[4];
    uint64 KTTriggerGUID;

    SummonList spawns; // adds spawn by the trigger. kept in separated list (i.e. not in summons)

    void Reset()
    {
        _Reset();

        PortalsGUID[0] = PortalsGUID[1] = PortalsGUID[2] = PortalsGUID[3] = 0;
        KTTriggerGUID = 0;

        me->setFaction(35);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
        std::map<uint64, float>::const_iterator itr;
        for (itr = chained.begin(); itr != chained.end(); ++itr)
        {
            if (Player* charmed = Unit::GetPlayer((*itr).first))
                charmed->SetFloatValue(OBJECT_FIELD_SCALE_X, (*itr).second);
        }

        chained.clear();
        spawns.DespawnAll();

        FindGameObjects();

        if (GameObject *pKTTrigger = me->GetMap()->GetGameObject(KTTriggerGUID))
        {
            pKTTrigger->ResetDoorOrButton();
            pKTTrigger->SetPhaseMask(1, true);
        }

        for (uint8 i = 0; i <= 3; ++i)
        {
            if (GameObject *pPortal = me->GetMap()->GetGameObject(PortalsGUID[i]))
            {
                if (!((pPortal->getLootState() == GO_READY) || (pPortal->getLootState() == GO_NOT_READY)))
                    pPortal->ResetDoorOrButton();
            }
        }

        nGuardiansOfIcecrownCount = 0;
        uiGuardiansOfIcecrownTimer = 5000;                   //5 seconds for summoning each Guardian of Icecrown in phase 3

        Phase = 0;
        nAbomination = 0;
        nWeaver = 0;
    }

    void KilledUnit()
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
    }

    void JustDied(Unit* /*Killer*/)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);

        std::map<uint64, float>::const_iterator itr;
        for (itr = chained.begin(); itr != chained.end(); ++itr)
        {
            if (Player* pPlayer = Unit::GetPlayer((*itr).first))
                pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, (*itr).second);
        }
        chained.clear();
    }

    void EnterCombat(Unit* /*who*/)
    {
        me->setFaction(uiFaction);

        _EnterCombat();
        FindGameObjects();
        for (uint8 i = 0; i <= 3; ++i)
        {
            if (GameObject *pPortal = me->GetMap()->GetGameObject(PortalsGUID[i]))
                pPortal->ResetDoorOrButton();
        }
        DoCast(me, SPELL_KELTHUZAD_CHANNEL, false);
        DoScriptText(SAY_SUMMON_MINIONS, me);
        Phase = 1;
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetFloatValue(UNIT_FIELD_COMBATREACH, 4);
        me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 4);
        events.ScheduleEvent(EVENT_TRIGGER, 5000);
        events.ScheduleEvent(EVENT_WASTE, 15000);
        events.ScheduleEvent(EVENT_ABOMIN, 30000);
        events.ScheduleEvent(EVENT_WEAVER, 50000);
        events.ScheduleEvent(EVENT_PHASE, 228000);
    }

    void FindGameObjects()
    {
        PortalsGUID[0] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL01) : 0;
        PortalsGUID[1] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL02) : 0;
        PortalsGUID[2] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL03) : 0;
        PortalsGUID[3] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL04) : 0;
        KTTriggerGUID = instance ? instance->GetData64(DATA_KELTHUZAD_TRIGGER) : 0;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateCombatState())
            return;

        events.Update(diff);

        if (Phase == 1)
        {
            while (uint32 eventId = events.GetEvent())
            {
                switch(eventId)
                {
                    case EVENT_WASTE:
                        DoSummon(NPC_WASTE, Pos[RAND(0,3,6,9)]);
                        events.RepeatEvent(urand(2000,5000));
                        break;
                    case EVENT_ABOMIN:
                        if (nAbomination < 8)
                        {
                            DoSummon(NPC_ABOMINATION, Pos[RAND(1,4,7,10)]);
                            nAbomination++;
                            events.RepeatEvent(20000);
                        }
                        else
                            events.PopEvent();
                        break;
                    case EVENT_WEAVER:
                        if (nWeaver < 8)
                        {
                            DoSummon(NPC_WEAVER, Pos[RAND(0,3,6,9)]);
                            nWeaver++;
                            events.RepeatEvent(25000);
                        }
                        else
                            events.PopEvent();
                        break;
                    case EVENT_TRIGGER:
                        if (GameObject *pKTTrigger = me->GetMap()->GetGameObject(KTTriggerGUID))
                            pKTTrigger->SetPhaseMask(2, true);
                        events.PopEvent();
                        break;
                    case EVENT_PHASE:
                        events.Reset();
                        DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2,SAY_AGGRO_3), me);
                        spawns.DespawnAll();
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                        me->CastStop();

                        DoStartMovement(me->getVictim());
                        events.ScheduleEvent(EVENT_BOLT, urand(5000,10000));
                        events.ScheduleEvent(EVENT_NOVA, 15000);
                        events.ScheduleEvent(EVENT_DETONATE, urand(30000,40000));
                        events.ScheduleEvent(EVENT_FISSURE, urand(10000,30000));
                        events.ScheduleEvent(EVENT_BLAST, urand(60000,120000));
                        if (getDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                            events.ScheduleEvent(EVENT_CHAIN, urand(30000,60000));
                        Phase = 2;
                        break;
                    default:
                        events.PopEvent();
                        break;
                }
            }
        }
        else
        {
            //start phase 3 when we are 45% health
            if (Phase != 3)
            {
                if (HealthBelowPct(45))
                {
                    Phase = 3 ;
                    DoScriptText(SAY_REQUEST_AID, me);
                    //here Lich King should respond to KelThuzad but I don't know which Creature to make talk
                    //so for now just make Kelthuzad says it.
                    DoScriptText(SAY_ANSWER_REQUEST, me);

                    for (uint8 i = 0; i <= 3; ++i)
                    {
                        if (GameObject *pPortal = me->GetMap()->GetGameObject(PortalsGUID[i]))
                        {
                            if (pPortal->getLootState() == GO_READY)
                                pPortal->UseDoorOrButton();
                        }
                    }
                }
            }
            else if (nGuardiansOfIcecrownCount < RAID_MODE(2,4))
            {
                if (uiGuardiansOfIcecrownTimer <= diff)
                {
                    // TODO : Add missing text
                    if (Creature* pGuardian = DoSummon(NPC_ICECROWN, Pos[RAND(2,5,8,11)]))
                        pGuardian->SetFloatValue(UNIT_FIELD_COMBATREACH, 2);
                    ++nGuardiansOfIcecrownCount;
                    uiGuardiansOfIcecrownTimer = 5000;
                }
                else uiGuardiansOfIcecrownTimer -= diff;
            }

            if (me->hasUnitState(UNIT_STAT_CASTING))
                return;

            if (uint32 eventId = events.GetEvent())
            {
                switch(eventId)
                {
                    case EVENT_BOLT:
                        DoCastVictim(RAID_MODE(SPELL_FROST_BOLT,H_SPELL_FROST_BOLT));
                        events.RepeatEvent(urand(5000,10000));
                        break;
                    case EVENT_NOVA:
                        DoCastAOE(RAID_MODE(SPELL_FROST_BOLT_AOE,H_SPELL_FROST_BOLT_AOE));
                        events.RepeatEvent(urand(15000,30000));
                        break;
                    case EVENT_CHAIN:
                    {
                        uint32 count = urand(1,3);
                        for (uint8 i = 1; i <= count; i++)
                        {
                            Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true);
                            if (pTarget && !pTarget->isCharmed() && (chained.find(pTarget->GetGUID()) == chained.end()))
                            {
                                DoCast(pTarget, SPELL_CHAINS_OF_KELTHUZAD);
                                float scale = pTarget->GetFloatValue(OBJECT_FIELD_SCALE_X);
                                chained.insert(std::make_pair(pTarget->GetGUID(), scale));
                                pTarget->SetFloatValue(OBJECT_FIELD_SCALE_X, scale * 2);
                                events.ScheduleEvent(EVENT_CHAINED_SPELL, 2000); //core has 2000ms to set unit flag charm
                            }
                        }
                        if (!chained.empty())
                            DoScriptText(RAND(SAY_CHAIN_1,SAY_CHAIN_2), me);
                        events.RepeatEvent(urand(100000,180000));
                        break;
                    }
                    case EVENT_CHAINED_SPELL:
                    {
                        std::map<uint64, float>::iterator itr;
                        for (itr = chained.begin(); itr != chained.end();)
                        {
                            if (Unit* player = Unit::GetPlayer((*itr).first))
                            {
                                if (!player->isCharmed())
                                {
                                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, (*itr).second);
                                    std::map<uint64, float>::iterator next = itr;
                                    ++next;
                                    chained.erase(itr);
                                    itr = next;
                                    continue;
                                }

                                if (Unit *pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, NotCharmedTargetSelector()))
                                {
                                    switch(player->getClass())
                                    {
                                        case CLASS_DRUID:
                                            if (urand(0,1))
                                                player->CastSpell(pTarget, SPELL_MOONFIRE, false);
                                            else
                                                player->CastSpell(me, SPELL_LIFEBLOOM, false);
                                            break;
                                        case CLASS_HUNTER:
                                            player->CastSpell(pTarget, RAND(SPELL_MULTI_SHOT, SPELL_VOLLEY), false);
                                            break;
                                        case CLASS_MAGE:
                                            player->CastSpell(pTarget, RAND(SPELL_FROST_FIREBOLT, SPELL_ARCANE_MISSILES), false);
                                            break;
                                        case CLASS_WARLOCK:
                                            player->CastSpell(pTarget, RAND(SPELL_CURSE_OF_AGONY, SPELL_SHADOW_BOLT), true);
                                            break;
                                        case CLASS_WARRIOR:
                                            player->CastSpell(pTarget, RAND(SPELL_BLADESTORM, SPELL_CLEAVE), false);
                                            break;
                                        case CLASS_PALADIN:
                                            if (urand(0,1))
                                                player->CastSpell(pTarget, SPELL_HAMMER_OF_JUSTICE, false);
                                            else
                                                player->CastSpell(me, SPELL_HOLY_SHOCK, false);
                                            break;
                                        case CLASS_PRIEST:
                                            if (urand(0,1))
                                                player->CastSpell(pTarget, SPELL_VAMPIRIC_TOUCH, false);
                                            else
                                                player->CastSpell(me, SPELL_RENEW, false);
                                            break;
                                        case CLASS_SHAMAN:
                                            if (urand(0,1))
                                                player->CastSpell(pTarget, SPELL_EARTH_SHOCK, false);
                                            else
                                                player->CastSpell(me, SPELL_HEALING_WAVE, false);
                                            break;
                                        case CLASS_ROGUE:
                                            player->CastSpell(pTarget, RAND(SPELL_HEMORRHAGE, SPELL_MUTILATE), false);
                                            break;
                                        case CLASS_DEATH_KNIGHT:
                                            if (urand(0,1))
                                                player->CastSpell(pTarget, SPELL_PLAGUE_STRIKE, true);
                                            else
                                                player->CastSpell(pTarget, SPELL_HOWLING_BLAST, true);
                                            break;
                                    }
                                }
                            }
                            ++itr;
                        }

                        if (chained.empty())
                            events.PopEvent();
                        else
                            events.RepeatEvent(5000);

                        break;
                    }
                    case EVENT_DETONATE:
                    {
                        std::vector<Unit*> unitList;
                        std::list<HostileReference*> *threatList = &me->getThreatManager().getThreatList();
                        for (std::list<HostileReference*>::const_iterator itr = threatList->begin(); itr != threatList->end(); ++itr)
                        {
                            if ((*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER
                                && (*itr)->getTarget()->getPowerType() == POWER_MANA
                                && (*itr)->getTarget()->GetPower(POWER_MANA))
                                unitList.push_back((*itr)->getTarget());
                        }

                        if (!unitList.empty())
                        {
                            std::vector<Unit*>::const_iterator itr = unitList.begin();
                            advance(itr, rand()%unitList.size());
                            DoCast(*itr, SPELL_MANA_DETONATION);
                            DoScriptText(RAND(SAY_SPECIAL_1,SAY_SPECIAL_2,SAY_SPECIAL_3), me);
                        }

                        events.RepeatEvent(urand(20000,50000));
                        break;
                    }
                    case EVENT_FISSURE:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                            DoCast(pTarget, SPELL_SHADOW_FISURE);
                        events.RepeatEvent(urand(10000,45000));
                        break;
                    case EVENT_BLAST:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, RAID_MODE(1,0), 0, true))
                            DoCast(pTarget, SPELL_FROST_BLAST);
                        if (rand()%2)
                            DoScriptText(SAY_FROST_BLAST, me);
                        events.RepeatEvent(urand(30000,90000));
                        break;
                    default:
                        events.PopEvent();
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    }
};

CreatureAI* GetAI_boss_kelthuzadAI(Creature* pCreature)
{
    return new boss_kelthuzadAI (pCreature);
}

bool AreaTrigger_at_kelthuzad_center(Player* pPlayer, const AreaTriggerEntry * /*at*/)
{
    if (pPlayer->isGameMaster())
        return false;

    ScriptedInstance* pInstance = pPlayer->GetInstanceData();
    if (!pInstance || pInstance->IsEncounterInProgress() || pInstance->GetBossState(BOSS_KELTHUZAD) == DONE)
        return false;

    Creature* pKelthuzad = CAST_CRE(Unit::GetUnit(*pPlayer, pInstance->GetData64(DATA_KELTHUZAD)));
    if (!pKelthuzad)
        return false;

    boss_kelthuzadAI* pKelthuzadAI = CAST_AI(boss_kelthuzadAI, pKelthuzad->AI());
    if (!pKelthuzadAI)
        return false;

    pKelthuzadAI->AttackStart(pPlayer);
    if (GameObject* trigger = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_KELTHUZAD_TRIGGER)))
    {
        if (trigger->getLootState() == GO_READY)
            trigger->UseDoorOrButton();

        // Note: summon must be done by trigger and not by KT.
        // Otherwise, they attack immediately as KT is in combat.
        for (uint8 i = 0; i <= MAX_ABOMINATIONS; ++i)
        {
            if (Creature* sum = trigger->SummonCreature(NPC_ABOMINATION, PosAbominations[i]))
            {
                pKelthuzadAI->spawns.Summon(sum);
                sum->GetMotionMaster()->MoveRandom(9.0f);
                sum->SetReactState(REACT_DEFENSIVE);
            }
        }
        for (uint8 i = 0; i <= MAX_WASTES; ++i)
        {
            if (Creature* sum = trigger->SummonCreature(NPC_WASTE, PosWastes[i]))
            {
                pKelthuzadAI->spawns.Summon(sum);
                sum->GetMotionMaster()->MoveRandom(5.0f);
                sum->SetReactState(REACT_DEFENSIVE);
            }
        }
        for (uint8 i = 0; i <= MAX_WEAVERS; ++i)
        {
            if (Creature* sum = trigger->SummonCreature(NPC_WEAVER, PosWeavers[i]))
            {
                pKelthuzadAI->spawns.Summon(sum);
                sum->GetMotionMaster()->MoveRandom(9.0f);
                sum->SetReactState(REACT_DEFENSIVE);
            }
        }
    }

    return true;
}

void AddSC_boss_kelthuzad()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_kelthuzad";
    newscript->GetAI = &GetAI_boss_kelthuzadAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_kelthuzad_center";
    newscript->pAreaTrigger = &AreaTrigger_at_kelthuzad_center;
    newscript->RegisterSelf();
}
