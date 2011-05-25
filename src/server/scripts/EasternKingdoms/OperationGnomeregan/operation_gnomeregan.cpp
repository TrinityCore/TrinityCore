/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 gmlt.A
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "Group.h"
#include "operation_gnomeregan.h"

class npc_og_suit : public CreatureScript
{
    public:
        npc_og_suit() : CreatureScript("npc_og_suit") {}

        struct npc_og_suitAI : public npc_escortAI
        {
            npc_og_suitAI(Creature* pCreature) : npc_escortAI(pCreature) {}

            void WaypointReached(uint32 i)
            {
            }

            void SetupMovement(uint32 variation)
            {
                switch (variation)
                {
                    case 0:
                        AddWaypoint(0, -5063.989746f, 485.176605f, 401.554596f);
                        AddWaypoint(1, -5063.474121f, 475.547302f, 402.917847f);
                        AddWaypoint(2, -5076.217285f, 469.422577f, 403.661407f);
                        AddWaypoint(3, -5088.637207f, 462.860535f, 405.323853f);
                        AddWaypoint(4, -5095.611816f, 455.524353f, 404.919037f);
                        AddWaypoint(5, -5121.946777f, 444.406799f, 396.678772f);
                        AddWaypoint(6, -5137.889648f, 449.120300f, 394.424469f);
                        AddWaypoint(7, -5149.414063f, 457.053406f, 392.511566f);
                        AddWaypoint(8, -5160.174316f, 468.878296f, 390.560455f);
                        AddWaypoint(9, -5180.711914f, 484.161713f, 388.160278f);
                        AddWaypoint(10, -5189.939941f, 498.311462f, 387.892426f);
                        AddWaypoint(11, -5192.106934f, 510.962097f, 387.746155f);
                        AddWaypoint(12, -5193.543945f, 529.913147f, 388.696655f);
                        AddWaypoint(13, -5191.546387f, 550.148438f, 393.705780f);
                        AddWaypoint(14, -5188.546875f, 586.246826f, 404.783936f);
                        break;
                    case 1:
                        AddWaypoint(0, -5069.393066f, 483.890228f, 401.484985f);
                        AddWaypoint(1, -5068.837402f, 477.813507f, 402.159088f);
                        AddWaypoint(2, -5079.646484f, 472.017700f, 402.333557f);
                        AddWaypoint(3, -5092.053711f, 465.606750f, 404.372650f);
                        AddWaypoint(4, -5100.974609f, 458.543640f, 403.343445f);
                        AddWaypoint(5, -5123.000488f, 449.164886f, 396.634552f);
                        AddWaypoint(6, -5135.452637f, 452.087646f, 394.234161f);
                        AddWaypoint(7, -5145.298340f, 459.457916f, 392.519470f);
                        AddWaypoint(8, -5155.757813f, 471.958282f, 390.643585f);
                        AddWaypoint(9, -5177.949219f, 486.992096f, 388.152344f);
                        AddWaypoint(10, -5185.644043f, 497.995270f, 387.916534f);
                        AddWaypoint(11, -5188.020508f, 510.212585f, 387.776581f);
                        AddWaypoint(12, -5189.084961f, 530.316467f, 388.683136f);
                        AddWaypoint(13, -5187.695313f, 553.590210f, 394.830505f);
                        AddWaypoint(14, -5183.902832f, 589.274170f, 405.504333f);
                        break;
                    case 2:
                        AddWaypoint(0, -5072.857910f, 480.193024f, 401.575989f);
                        AddWaypoint(1, -5081.426758f, 476.311279f, 401.928589f);
                        AddWaypoint(2, -5093.935059f, 470.681549f, 403.441467f);
                        AddWaypoint(3, -5102.093262f, 463.836243f, 403.325378f);
                        AddWaypoint(4, -5124.031250f, 453.702057f, 396.498871f);
                        AddWaypoint(5, -5132.045898f, 454.890564f, 394.364868f);
                        AddWaypoint(6, -5142.617188f, 463.545746f, 392.404541f);
                        AddWaypoint(7, -5152.081055f, 476.321075f, 391.080353f);
                        AddWaypoint(8, -5174.884766f, 489.358124f, 388.310547f);
                        AddWaypoint(9, -5181.639648f, 499.796936f, 387.963043f);
                        AddWaypoint(10, -5183.538574f, 509.857727f, 387.984863f);
                        AddWaypoint(11, -5183.844238f, 528.578613f, 388.656555f);
                        AddWaypoint(12, -5184.622559f, 548.945251f, 393.504517f);
                        AddWaypoint(13, -5179.573730f, 585.523010f, 404.546021f);
                        break;
                    case 3:
                        AddWaypoint(0, -5086.023926f, 713.154724f, 260.556427f);
                        AddWaypoint(1, -5076.176270f, 720.441162f, 260.530670f);
                        AddWaypoint(2, -5061.914063f, 721.010620f, 260.532135f);
                        AddWaypoint(3, -5057.044434f, 728.671509f, 260.554199f);
                        AddWaypoint(4, -5054.104980f, 728.641357f, 261.240845f);
                        AddWaypoint(5, -5046.533691f, 731.763855f, 256.475403f);
                        AddWaypoint(6, -4975.580078f, 725.948120f, 256.266113f);
                        AddWaypoint(7, -4948.541992f, 724.022522f, 260.442596f);
                        AddWaypoint(8, -4947.177246f, 723.911560f, 261.646118f);
                        AddWaypoint(9, -4943.868164f, 723.567993f, 261.646118f);
                        AddWaypoint(10, -4945.804199f, 720.004578f, 261.646118f);
                        AddWaypoint(11, -4946.651367f, 721.550781f, 261.645966f);
                        break;
                    case 4:
                        AddWaypoint(0, -5085.565918f, 725.892761f, 260.554840f);
                        AddWaypoint(1, -5077.067383f, 730.409729f, 260.539093f);
                        AddWaypoint(2, -5064.545410f, 735.317627f, 260.517822f);
                        AddWaypoint(3, -5055.252441f, 737.436584f, 260.556335f);
                        AddWaypoint(4, -5053.518555f, 737.214722f, 261.237610f);
                        AddWaypoint(5, -5046.488281f, 737.037964f, 256.475586f);
                        AddWaypoint(6, -5039.229492f, 739.272888f, 256.475586f);
                        AddWaypoint(7, -4948.179199f, 731.976929f, 260.396484f);
                        AddWaypoint(8, -4946.559570f, 731.800903f, 261.645752f);
                        AddWaypoint(9, -4943.546875f, 731.456848f, 261.645752f);
                        AddWaypoint(10, -4944.289063f, 735.979248f, 261.645752f);
                        AddWaypoint(11, -4945.196289f, 733.968018f, 261.645752f);
                        break;
                    default:
                        sLog->outError("Unexpected movement variation (%i) in npc_og_suitAI::SetupMovement call!", variation);
                        return;
                }
                if (npc_og_suitAI* pEscortAI = CAST_AI(npc_og_suitAI, me->AI()))
                {
                    pEscortAI->Start(true, true);
                    pEscortAI->SetDespawnAtFar(false);
                    pEscortAI->SetDespawnAtEnd(false);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_suitAI(pCreature);
    }
};

class npc_og_infantry : public CreatureScript
{
    public:
        npc_og_infantry() : CreatureScript("npc_og_infantry") {}

        struct npc_og_infantryAI : public npc_escortAI
        {
            npc_og_infantryAI(Creature* pCreature) : npc_escortAI(pCreature) {}

            bool bDeployable;
            bool bRooted;
            uint32 uiGCD;
            uint32 uiGrenade_timer;
            uint32 uiDeploy_timer;
            uint32 uiVariation;

            void Reset()
            {
                bDeployable = true;
                bRooted = false;
                uiGCD = 2500;
                uiGrenade_timer = urand(10000, 15000);
            }

            void WaypointReached(uint32 i)
            {
                if (i == 9 && uiVariation <= 3)
                    if (Creature* pSuit = me->FindNearestCreature(NPC_BATTLE_SUIT, 50, true))
                    {
                        CAST_AI(npc_og_suit::npc_og_suitAI, pSuit->AI())->SetupMovement(uiVariation);
                        pSuit->setFaction(FACTION_GNOMEREGAN);
                    }
            }

            void Deploy()
            {
                me->CastSpell(me, SPELL_PARACHUTE_AURA, true);
                uiDeploy_timer = 2500;
            }

            void SetupMovement(uint32 variation)
            {
                switch (variation)
                {
                    case 0:
                        AddWaypoint(0, -5158.309082f, 470.632172f, 390.470764f);
                        AddWaypoint(1, -5145.815918f, 455.817719f, 392.905914f);
                        AddWaypoint(2, -5133.497070f, 447.780579f, 394.853760f);
                        AddWaypoint(3, -5123.107910f, 447.636963f, 396.523224f);
                        AddWaypoint(4, -5113.999512f, 450.278076f, 399.421631f);
                        AddWaypoint(5, -5099.395020f, 459.180542f, 403.653595f);
                        AddWaypoint(6, -5092.314941f, 464.330475f, 404.561371f);
                        AddWaypoint(7, -5077.594238f, 472.013489f, 402.421844f);
                        AddWaypoint(8, -5061.697754f, 479.314331f, 402.391602f);
                        AddWaypoint(9, -5064.035645f, 486.302704f, 401.484802f);
                        break;
                    case 1:
                        AddWaypoint(0, -5156.698242f, 473.458801f, 390.562836f);
                        AddWaypoint(1, -5143.689453f, 459.033173f, 392.722260f);
                        AddWaypoint(2, -5131.758301f, 450.333496f, 394.751221f);
                        AddWaypoint(3, -5124.032715f, 451.750183f, 396.452881f);
                        AddWaypoint(4, -5115.258789f, 453.386505f, 399.366028f);
                        AddWaypoint(5, -5100.275879f, 462.415070f, 403.588318f);
                        AddWaypoint(6, -5092.391602f, 467.532990f, 404.065125f);
                        AddWaypoint(7, -5077.200684f, 474.754211f, 402.065674f);
                        AddWaypoint(8, -5068.790039f, 478.631042f, 402.016907f);
                        AddWaypoint(9, -5069.553223f, 485.221466f, 401.486023f);
                        break;
                    case 2:
                        AddWaypoint(0, -5154.232910f, 475.711517f, 390.823730f);
                        AddWaypoint(1, -5140.836914f, 461.044586f, 392.818695f);
                        AddWaypoint(2, -5130.810059f, 454.405426f, 394.685913f);
                        AddWaypoint(3, -5124.641113f, 455.657715f, 396.326508f);
                        AddWaypoint(4, -5115.422852f, 456.902405f, 399.631653f);
                        AddWaypoint(5, -5101.960938f, 464.402954f, 403.353455f);
                        AddWaypoint(6, -5093.451172f, 469.957916f, 403.570282f);
                        AddWaypoint(7, -5078.112305f, 477.189697f, 401.767792f);
                        AddWaypoint(8, -5071.622559f, 476.510834f, 402.198334f);
                        AddWaypoint(9, -5073.813477f, 481.830627f, 401.484741f);
                        break;
                    default:
                        sLog->outError("Unexpected movement variation (%i) in npc_og_infantryAI::SetupMovement call!", variation);
                        return;
                }
                uiVariation = variation;
                if (npc_og_infantryAI* pEscortAI = CAST_AI(npc_og_infantryAI, me->AI()))
                {
                    pEscortAI->Start(true, true);
                    pEscortAI->SetDespawnAtFar(false);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (uiDeploy_timer <= diff && bDeployable)
                {
                    bDeployable = false;
                    me->RemoveAurasDueToSpell(SPELL_PARACHUTE_AURA);
                    if (Creature* pCannon = me->FindNearestCreature(NPC_CANNON, 100, true))
                        me->AI()->AttackStart(pCannon);
                }
                else
                    uiDeploy_timer -= diff;

                if (!UpdateVictim())
                    return;

                if (me->GetDistance2d(me->getVictim()) <= 5.0f)
                {
                    me->ClearUnitState(UNIT_STAT_ROOT);
                    bRooted = false;
                }
                else 
                {
                    if (me->GetDistance2d(me->getVictim()) <= 30.0f)
                    {
                        me->AddUnitState(UNIT_STAT_ROOT);
                        bRooted = true;
                    }
                    else
                    {
                        me->ClearUnitState(UNIT_STAT_ROOT);
                        bRooted = false;
                    }
                }
                

                if (!bRooted)
                {
                    if (uiGCD <= diff)
                    {
                        if (!urand(0, 3))
                            DoCast(me->getVictim(), SPELL_ATTACK);

                        uiGCD = 5000;
                    }
                    else
                        uiGCD -= diff;
                }
                else
                {
                    if (uiGCD <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_SHOOT);
                        uiGCD = 5000;
                    }
                    else
                        uiGCD -= diff;
                }

                if (uiGrenade_timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_GRENADE);
                    uiGrenade_timer = urand(10000, 15000);
                }
                else
                    uiGrenade_timer -= diff;
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_infantryAI(pCreature);
    }
};

class npc_og_tank : public CreatureScript
{
    public:
        npc_og_tank() : CreatureScript("npc_og_tank") {}

        struct npc_og_tankAI : public npc_escortAI
        {
            npc_og_tankAI(Creature* pCreature) : npc_escortAI(pCreature) {}

            bool IsSelfRooted;
            uint32 uiGCD;

            void Reset()
            {
                IsSelfRooted = false;
                uiGCD = 5000;
            }

            void WaypointReached(uint32 i)
            {
            }

            void SetupMovement(uint32 variation)
            {
                switch (variation)
                {
                    case 0:
                        AddWaypoint(0, -5280.954102f, 559.265808f, 385.679932f);
                        AddWaypoint(1, -5267.337402f, 540.788391f, 387.169342f);
                        AddWaypoint(2, -5255.488281f, 521.325256f, 386.325378f);
                        AddWaypoint(3, -5241.595215f, 513.660339f, 387.892212f);
                        AddWaypoint(4, -5229.519531f, 508.052399f, 387.756287f);
                        AddWaypoint(5, -5208.560059f, 495.748932f, 387.916199f);
                        AddWaypoint(6, -5196.718750f, 480.324402f, 387.072052f);
                        AddWaypoint(7, -5164.643555f, 447.614532f, 394.698822f);
                        AddWaypoint(8, -5137.479492f, 428.433716f, 395.987518f);
                        AddWaypoint(9, -5138.148926f, 404.461121f, 396.885284f);
                        AddWaypoint(10, -5139.549805f, 386.402893f, 396.906952f);
                        AddWaypoint(11, -5140.363281f, 375.913422f, 397.931152f);
                        AddWaypoint(12, -5142.502441f, 346.961121f, 398.053497f);
                        AddWaypoint(13, -5141.139160f, 359.352966f, 397.011078f);
                        AddWaypoint(14, -5140.697754f, 378.842957f, 397.872406f);
                        AddWaypoint(15, -5138.448242f, 395.032410f, 396.352783f);
                        AddWaypoint(16, -5133.321289f, 431.758118f, 396.322357f);
                        AddWaypoint(17, -5161.619141f, 452.354553f, 394.115448f);
                        AddWaypoint(18, -5185.990723f, 478.249481f, 387.941895f);
                        AddWaypoint(19, -5201.514160f, 491.001923f, 387.610474f);
                        AddWaypoint(20, -5227.306641f, 500.188507f, 387.142792f);
                        AddWaypoint(21, -5237.200195f, 513.050537f, 387.736145f);
                        AddWaypoint(22, -5251.963379f, 525.391174f, 386.584442f);
                        AddWaypoint(23, -5266.466797f, 537.124451f, 387.494537f);
                        AddWaypoint(24, -5283.755859f, 560.300293f, 385.199860f);
                        break;
                    case 1:
                        AddWaypoint(0, -5263.007813f, 572.262085f, 388.673157f);
                        AddWaypoint(1, -5236.423340f, 542.552368f, 389.753387f);
                        AddWaypoint(2, -5214.283691f, 541.975586f, 389.412659f);
                        AddWaypoint(3, -5197.762207f, 531.495056f, 388.887299f);
                        AddWaypoint(4, -5179.492188f, 519.916443f, 388.667297f);
                        AddWaypoint(5, -5175.582520f, 502.293945f, 388.701996f);
                        AddWaypoint(6, -5167.252441f, 493.800568f, 390.061920f);
                        AddWaypoint(7, -5157.853027f, 480.655945f, 390.738495f);
                        AddWaypoint(8, -5145.563965f, 479.578796f, 393.390839f);
                        AddWaypoint(9, -5131.671875f, 465.390198f, 394.823059f);
                        AddWaypoint(10, -5113.997559f, 476.204285f, 397.972015f);
                        AddWaypoint(11, -5118.809570f, 470.737091f, 397.644592f);
                        AddWaypoint(12, -5136.430664f, 457.685455f, 393.588379f);
                        AddWaypoint(13, -5149.951172f, 475.280426f, 391.100586f);
                        AddWaypoint(14, -5170.628418f, 490.365723f, 388.964539f);
                        AddWaypoint(15, -5177.971191f, 510.636871f, 388.935669f);
                        AddWaypoint(16, -5179.023438f, 522.535889f, 388.936523f);
                        AddWaypoint(17, -5200.432129f, 530.929260f, 388.382721f);
                        AddWaypoint(18, -5214.941895f, 535.946106f, 388.297760f);
                        AddWaypoint(19, -5234.781250f, 535.892456f, 388.333527f);
                        AddWaypoint(20, -5250.526367f, 551.972473f, 388.484741f);
                        AddWaypoint(21, -5262.729492f, 572.853027f, 388.782532f);
                        break;
                    default:
                        sLog->outError("Unexpected movement variation (%i) in npc_og_tankAI::SetupMovement call!", variation);
                        return;
                }
                if (npc_og_tankAI* pEscortAI = CAST_AI(npc_og_tankAI, me->AI()))
                {
                    pEscortAI->Start(true, true, NULL, NULL, false, true);
                    pEscortAI->SetDespawnAtFar(false);
                    me->setActive(true);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    IsSelfRooted = false;

                    if (me->isAttackReady())
                    {
                        if (uiGCD <= diff)
                        {
                            if (!urand(0, 3))
                            {
                                DoCast(me->getVictim(), SPELL_FLAME_SPRAY);
                                uiGCD = 5000;
                            }
                        }
                        else
                            uiGCD -= diff;
                    }
                }
                else
                {
                    IsSelfRooted = true;

                    if (uiGCD <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_MACHINE_GUN);
                        uiGCD = 5000;
                    }
                    else
                        uiGCD -= diff;
                }
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_tankAI(pCreature);
    }
};

class npc_og_i_tank : public CreatureScript
{
    public:
        npc_og_i_tank() : CreatureScript("npc_og_i_tank") {}

        struct npc_og_i_tankAI : public npc_escortAI
        {
            npc_og_i_tankAI(Creature* pCreature) : npc_escortAI(pCreature) {}

            void Reset()
            {
            }

            void WaypointReached(uint32 i)
            {
            }

            void SetupMovement(uint32 variation)
            {
                switch (variation)
                {
                    case 0:
                        AddWaypoint(0, -5339.479980f, 545.804688f, 384.888336f);
                        AddWaypoint(1, -5348.981934f, 555.181458f, 385.137665f);
                        AddWaypoint(2, -5348.816406f, 567.433472f, 384.981537f);
                        AddWaypoint(3, -5348.981934f, 555.181458f, 385.137665f);
                        break;
                    case 1:
                        AddWaypoint(0, -5318.129395f, 578.573425f, 387.439697f);
                        AddWaypoint(1, -5305.049316f, 584.957153f, 389.928864f);
                        AddWaypoint(2, -5291.333496f, 589.698730f, 387.835785f);
                        AddWaypoint(3, -5283.275391f, 583.998413f, 386.930725f);
                        AddWaypoint(4, -5279.059082f, 571.535461f, 386.423187f);
                        AddWaypoint(5, -5283.275391f, 583.998413f, 386.930725f);
                        AddWaypoint(6, -5291.333496f, 589.698730f, 387.835785f);
                        AddWaypoint(7, -5305.049316f, 584.957153f, 389.928864f);
                        break;
                    default:
                        sLog->outError("Unexpected movement variation (%i) in npc_og_i_tankAI::SetupMovement call!", variation);
                        return;
                }
                if (npc_og_i_tankAI* pEscortAI = CAST_AI(npc_og_i_tankAI, me->AI()))
                {
                    pEscortAI->Start(true, true, NULL, NULL, false, true);
                    pEscortAI->SetDespawnAtFar(false);
                    me->setActive(true);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_i_tankAI(pCreature);
    }
};

class npc_og_assistants : public CreatureScript
{
    public:
        npc_og_assistants() : CreatureScript("npc_og_assistants") {}

        struct npc_og_assistantsAI : public npc_escortAI
        {
            npc_og_assistantsAI(Creature* pCreature) : npc_escortAI(pCreature) {}

            void Reset()
            {
            }

            void WaypointReached(uint32 i)
            {
                switch (i)
                {
                    case 0:
                    case 2:
                    case 11:
                    case 17:
                    case 20:
                    case 35:
                    case 52:
                    case 57:
                    case 65:
                    case 67:
                    case 71:
                    case 75:
                        SetHoldState(true);
                        break;
                    case 49:
                        SetHoldState(true);
                        me->Unmount();
                        if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 100, true))
                            me->CastSpell(pMekkatorque, SPELL_TRIGGER, true);
                        break;
                    case 50:
                        me->CastSpell(me, SPELL_PARACHUTE_AURA, true);
                        break;
                    case 51:
                        me->RemoveAurasDueToSpell(SPELL_PARACHUTE_AURA);
                        me->Mount(me->GetEntry() == NPC_FASTBLAST ? DATA_MOUNT_FAST : DATA_MOUNT_COG);
                        break;
                }
                if (i > 21)
                    me->SummonGameObject(188646, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),0,0,0,0,0,0);  // Debug feature
            }

            void SetHoldState(bool b_OnHold)
            {
                SetEscortPaused(b_OnHold);
            }


            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_assistantsAI(pCreature);
    }
};

class npc_og_boltcog : public CreatureScript
{
    public:
        npc_og_boltcog() : CreatureScript("npc_og_boltcog") {}

        struct npc_og_boltcogAI : public npc_escortAI
        {
            npc_og_boltcogAI(Creature* pCreature) : npc_escortAI(pCreature) {}

            void WaypointReached(uint32 i)
            {
            }

            void DamageTaken(Unit* /*pDone_by*/, uint32& uiDamage)
            {
                if (uiDamage > me->GetHealth())
                    if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 100, true))
                        me->CastSpell(pMekkatorque, SPELL_TRIGGER, true);
            }

            void SetupMovement()
            {
                AddWaypoint(0, -5035.236816f, 708.675232f, 260.499268f);
                AddWaypoint(1, -5033.954590f, 717.153992f, 260.528778f);
                AddWaypoint(2, -5048.367188f, 718.769409f, 260.534576f);
                AddWaypoint(3, -5048.580078f, 723.327087f, 260.738220f);
                AddWaypoint(4, -5048.201660f, 725.357117f, 261.238556f);
                AddWaypoint(5, -5044.113281f, 735.628906f, 256.475586f);
                AddWaypoint(6, -4974.464355f, 730.595642f, 256.258636f);
                AddWaypoint(7, -4950.033203f, 728.526733f, 260.143768f);
                AddWaypoint(8, -4952.264160f, 728.697937f, 259.785492f);

                if (npc_og_boltcogAI* pEscortAI = CAST_AI(npc_og_boltcogAI, me->AI()))
                {
                    pEscortAI->Start(true, true);
                    pEscortAI->SetDespawnAtFar(false);
                    pEscortAI->SetDespawnAtEnd(false);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                // AI here
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_boltcogAI(pCreature);
    }
};

class npc_og_mekkatorque : public CreatureScript
{
    public:
        npc_og_mekkatorque() : CreatureScript("npc_og_mekkatorque") { }

        struct npc_og_mekkatorqueAI : public npc_escortAI
        {
            npc_og_mekkatorqueAI(Creature* pCreature) : npc_escortAI(pCreature) { }

            uint32 uiStep;
            uint32 uiStep_timer;
            uint32 uiRLDestroyed;
            uint32 uiCannonsDestroyed;
            uint32 uiTroggs;
            uint32 uiSoldiers;
            bool   bCanSummonBomber;
            bool   bCannonIntro;
            bool   bBuffs;
            bool   bPreJumpWP_1;
            bool   bPreJumpWP_2;
            Creature* RL[4];
            Creature* Cannon[6];
            Creature* BattleSuit[3];

            void Reset()
            {
                uiStep               = 0;
                uiTroggs             = 0;
                uiSoldiers           = 0;
                uiStep_timer         = 0;
                uiRLDestroyed        = 0;
                uiCannonsDestroyed   = 0;
                bCanSummonBomber     = true;
                bCannonIntro         = false;
                bBuffs               = false;
                bPreJumpWP_1         = false;
                bPreJumpWP_2         = false;
            }

            void WaypointReached(uint32 i)
            {
                switch (i)
                {
                    case 0:
                        SetHoldState(true);
                        DoTalk(me, MEK_1_1, SOUND_MEK_1, false);
                        for (int8 n = 0; n < 4; ++n)
                            RL[n] = me->SummonCreature(NPC_RL, RLSpawn[n], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 100000);
                        me->SummonCreature(NPC_I_TANK, iTankSpawn[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                        for (int8 n = 1; n < 3; ++n)
                            if (Creature* p_iTank = me->SummonCreature(NPC_I_TANK, iTankSpawn[n], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000))
                                CAST_AI(npc_og_i_tank::npc_og_i_tankAI, p_iTank->AI())->SetupMovement(n-1);
                        JumpToNextStep(3200);
                        break;
                    case 2:
                        SetHoldState(true);
                        DoTalk(me, MEK_5_1, SOUND_MEK_5, false);
                        JumpToNextStep(3500);
                        break;
                    case 3:
                        SquadSetRun(true);
                        break;
                    case 4:
                        DoTalk(me, MEK_6_1, SOUND_MEK_6, false);
                        DoUpdateWorldState(WORLDSTATE_RL_DESTROYED, uiRLDestroyed);
                        DoUpdateWorldState(WORLDSTATE_RL_DESTROYED_CTRL, 1);
                        if (RL[0]->isAlive())
                            AttackStart(RL[0]);
                        break;
                    case 7:
                        if (RL[1]->isAlive())
                            AttackStart(RL[1]);
                        break;
                    case 8:
                        if (RL[2]->isAlive())
                            AttackStart(RL[2]);
                        break;
                    case 10:
                        if (RL[3]->isAlive())
                            AttackStart(RL[3]);
                        break;
                    case 12:
                        SetHoldState(true);
                        DoUpdateWorldState(WORLDSTATE_RL_DESTROYED_CTRL, 0);
                        DoUpdateWorldState(WORLDSTATE_AIRFIELD_ATTACKED, 0);
                        DoUpdateWorldState(WORLDSTATE_AIRFIELD_CAPTURED, 1);
                        DoTalk(me, MEK_10_1, SOUND_MEK_10, false);
                        JumpToNextStep(5500);
                        break;
                    case 18:
                        SetHoldState(true);
                        DoTalk(me, MEK_12_1, SOUND_MEK_12, false);
                        if (Creature* pDriver1 = me->SummonCreature(NPC_INFANTRY, BattleSuitDriverSpawn[0], TEMPSUMMON_MANUAL_DESPAWN))
                            if (Creature* pDriver2 = me->SummonCreature(NPC_INFANTRY, BattleSuitDriverSpawn[1], TEMPSUMMON_MANUAL_DESPAWN))
                                if (Creature* pDriver3 = me->SummonCreature(NPC_INFANTRY, BattleSuitDriverSpawn[2], TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    CAST_AI(npc_og_infantry::npc_og_infantryAI, pDriver1->AI())->SetupMovement(0);
                                    CAST_AI(npc_og_infantry::npc_og_infantryAI, pDriver2->AI())->SetupMovement(1);
                                    CAST_AI(npc_og_infantry::npc_og_infantryAI, pDriver3->AI())->SetupMovement(2);
                                }
                        JumpToNextStep(8500);
                        break;
                    case 19:
                        SetHoldState(true);
                        me->Unmount();
                        JumpToNextStep(2000);
                        break;
                    case 21:
                        SetHoldState(true);
                        me->Mount(DATA_MOUNT_MEK);
                        JumpToNextStep(7000);
                        break;
                    case 27:
                        DoUpdateWorldState(WORLDSTATE_BATTLE_NEAR_ENTRANCE, 1);
                        break;
                    case 36:
                        SetHoldState(true);
                        DoTalk(me, MEK_13_1, SOUND_MEK_13, false);
                        JumpToNextStep(6500);
                        break;
                    case 50:
                        SetHoldState(true);
                        me->Unmount();
                        JumpToNextStep(1000);
                        break;
                    case 51:
                        me->CastSpell(me, SPELL_PARACHUTE_AURA, true);
                        break;
                    case 52:
                        me->RemoveAurasDueToSpell(SPELL_PARACHUTE_AURA);
                        me->Mount(DATA_MOUNT_MEK);
                        break;
                    case 53:
                        SetHoldState(true);
                        JumpToNextStep(5000);
                        break;
                    case 58:
                        SetHoldState(true);
                        DoTalk(me, MEK_16_1, SOUND_MEK_16, false);
                        DoUpdateWorldState(WORLDSTATE_BATLLE_IN_TUNNELS, 1);
                        JumpToNextStep(3000);
                        break;
                    case 67:
                        SetHoldState(true);
                        JumpToNextStep(3000);
                        break;
                    case 68:
                        SetHoldState(true);
                        JumpToNextStep(3500);
                        break;
                    case 71:
                        SetHoldState(true);
                        break;
                    case 75:
                        SetHoldState(true);
                        me->SummonCreature(NPC_BRAG_BOT, BragBotSpawn[1], TEMPSUMMON_MANUAL_DESPAWN);
                        JumpToNextStep(2000);
                        break;
                }
                if (i > 21)
                    me->SummonGameObject(190561, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),0,0,0,0,0,0);  // Debug feature
            }

            void JumpToNextStep(uint32 uiTimer)
            {
                uiStep_timer = uiTimer;
                ++uiStep;
            }

            void SetHoldState(bool b_OnHold)
            {
                SetEscortPaused(b_OnHold);
                if (!b_OnHold)
                {
                    if (Creature* pCogspin = me->FindNearestCreature(NPC_COGSPIN, 100.0f))
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pCogspin->AI())->SetHoldState(b_OnHold);
                    if (Creature* pFastblast = me->FindNearestCreature(NPC_FASTBLAST, 100.0f))
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pFastblast->AI())->SetHoldState(b_OnHold);

                    JumpToNextStep(0);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                DoRefreshkWorldStates();

                npc_escortAI::UpdateAI(diff);

                if (bBuffs && !me->HasAura(SPELL_BRILLIANT_TACTICS))
                    me->AddAura(SPELL_BRILLIANT_TACTICS, me);

                if (bBuffs && !me->HasAura(SPELL_HEALTH_REGEN))
                    me->AddAura(SPELL_HEALTH_REGEN, me);

                if (uiStep_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            me->MonsterSay(MEK_1_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(9800);
                            break;
                        case 2:
                            me->MonsterSay(MEK_1_3, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(5000);
                            break;
                        case 3:
                            DoTalk(me, MEK_2_1, SOUND_MEK_2, false);
                            JumpToNextStep(13000);
                            break;
                        case 4:
                            DoTalk(me, MEK_3_1, SOUND_MEK_3, false);
                            JumpToNextStep(4000);
                            break;
                        case 5:
                            me->MonsterYell(MEK_3_2, LANG_UNIVERSAL, NULL);
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN_CTRL, 1);
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN, 5);
                            JumpToNextStep(600/*00*/);
                            break;
                        case 6:
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN, 4);
                            JumpToNextStep(600/*00*/);
                            break;
                        case 7:
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN, 3);
                            JumpToNextStep(600/*00*/);
                            break;
                        case 8:
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN, 2);
                            JumpToNextStep(600/*00*/);
                            break;
                        case 9:
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN, 1);
                            JumpToNextStep(600/*00*/);
                            break;
                        case 10:
                            DoUpdateWorldState(WORLDSTATE_COUNTDOWN_CTRL, 0);
                            DoUpdateWorldState(WORLDSTATE_IN_PROCCESS, 1);
                            DoTalk(me, MEK_4_1, SOUND_MEK_4, 0);
                            JumpToNextStep(7700);
                            break;
                        case 11:
                            me->MonsterYell(MEK_4_2, LANG_UNIVERSAL, NULL);
                            me->CastSpell(me, SPELL_HEALTH_REGEN, true);
                            me->CastSpell(me, SPELL_BRILLIANT_TACTICS, true);
                            bBuffs = true;
                            JumpToNextStep(2000);
                            break;
                        case 12:
                            SetHoldState(false);
                                break;
                        case 14:
                            me->MonsterSay(MEK_5_2, LANG_UNIVERSAL, NULL);
                            DoUpdateWorldState(WORLDSTATE_AIRFIELD_ATTACKED, 1);
                            JumpToNextStep(3300);
                            break;
                        case 15:
                            me->MonsterSay(MEK_5_3, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(7000);
                            break;
                        case 16:
                            SetHoldState(false);
                            break;
                        case 18:
                            me->MonsterSay(MEK_10_2, LANG_UNIVERSAL, NULL);
                            DoUpdateWorldState(WORLDSTATE_BATTLE_NEAR_WORKSHOPS, 1);
                            DoUpdateWorldState(WORLDSTATE_CANNONS_DESTROYED_CTRL, 1);
                            DoUpdateWorldState(WORLDSTATE_CANNONS_DESTROYED, 0);
                            for (int8 n = 0; n < 6; ++n)
                            {
                                Cannon[n] = me->SummonCreature(NPC_CANNON, CannonSpawn[n], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 100000);
                                Cannon[n]->CastSpell(Cannon[n], SPELL_TRIGGER, true);
                            }
                            me->SummonGameObject(OBJ_RAD_CONTROL, RadControlSpawn, 0 ,0 ,0 ,0, 0);
                            for (int8 n = 0; n < 3; ++n)
                                BattleSuit[n] = me->SummonCreature(NPC_BATTLE_SUIT, BattleSuitSpawn[n], TEMPSUMMON_MANUAL_DESPAWN);
                            JumpToNextStep(7250);
                            break;
                        case 19:
                            me->MonsterSay(MEK_10_3, LANG_UNIVERSAL, NULL);
                            if (Creature* pTank1 = me->SummonCreature(NPC_TANK, TankSpawn[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                                if (Creature* pTank2 = me->SummonCreature(NPC_TANK, TankSpawn[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                                {
                                    CAST_AI(npc_og_tank::npc_og_tankAI, pTank1->AI())->SetupMovement(0);
                                    CAST_AI(npc_og_tank::npc_og_tankAI, pTank2->AI())->SetupMovement(1);
                                }
                            DoSummonBomber();
                            JumpToNextStep(3000);
                            break;
                        case 20:
                            SetHoldState(false);
                            break;
                        case 22:
                            me->MonsterSay(MEK_12_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(8500);
                            break;
                        case 23:
                            SetHoldState(false);
                            break;
                        case 25:
                            SetEscortPaused(false);
                            JumpToNextStep(0);
                            break;
                        case 27:
                            SetHoldState(false);
                            break;
                        case 29:
                            me->MonsterSay(MEK_13_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(8000);
                            break;
                        case 30:
                            me->MonsterSay(MEK_13_3, LANG_UNIVERSAL, NULL);
                            for (int32 n = 0; n < 3; ++n)
                                BattleSuit[n]->DisappearAndDie();
                            me->SummonCreature(NPC_BRAG_BOT, BragBotSpawn[0], TEMPSUMMON_MANUAL_DESPAWN);
                            JumpToNextStep(5000);
                            break;
                        case 31:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                DoTalk(pBragBot, THERM_1_1, SOUND_THERM_1, true);
                            JumpToNextStep(7000);
                            break;
                        case 32:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_1_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(5000);
                            break;
                        case 33:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_1_3, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(3000);
                            break;
                        case 34:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_1_4, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(4500);
                            break;
                        case 35:
                            PartyCast(SPELL_EXPLOSION);
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->DisappearAndDie();
                            JumpToNextStep(1000);
                            break;
                        case 36:
                            if (uiTroggs <= 2/*20*/)
                            {
                                if (Creature* pTrogg = me->SummonCreature(NPC_I_TROGG, TroggSpawn, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 50000))
                                {
                                    pTrogg->GetMotionMaster()->MovePoint(0, -5182.56f, 611.78f, 408.96f);
                                    ++uiTroggs;
                                }
                                switch (uiTroggs)
                                {
                                    case 2:
                                        DoTalk(me, MEK_14_1, SOUND_MEK_14, false);
                                        break;
                                    case 5:
                                        me->MonsterYell(MEK_14_2, LANG_UNIVERSAL, NULL);
                                        break;
                                }
                                
                                uiStep_timer = uiTroggs % 4 == 0 ? 5000/*30000*/ : 1500;
                            }
                            else
                            {
                                if (Creature* pGasherikk = me->SummonCreature(NPC_GASHERIKK, TroggSpawn, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 50000))
                                {
                                    DoTalk(me, MEK_15_1, SOUND_MEK_15, true);
                                    pGasherikk->GetMotionMaster()->MovePoint(0, -5182.56f, 611.78f, 408.96f);
                                    JumpToNextStep(1);
                                }
                            }
                            break;
                        case 38:
                            SetHoldState(false);
                            break;
                        case 40:
                            if (!bPreJumpWP_1 || !bPreJumpWP_2)
                                uiStep_timer = 2000;
                            else
                            {
                                me->MonsterSay("1", LANG_UNIVERSAL, NULL);
                                PartyCast(SPELL_PARACHUTE);
                                SetHoldState(false);
                            }
                            break;
                        case 42:
                            SetHoldState(false);
                            break;
                        case 44:
                            if (Creature* pSuit = me->SummonCreature(NPC_BATTLE_SUIT, BattleSuitSpawn[3], TEMPSUMMON_MANUAL_DESPAWN))
                                CAST_AI(npc_og_suit::npc_og_suitAI, pSuit->AI())->SetupMovement(3);
                            if (Creature* pSuit = me->SummonCreature(NPC_BATTLE_SUIT, BattleSuitSpawn[4], TEMPSUMMON_MANUAL_DESPAWN))
                                CAST_AI(npc_og_suit::npc_og_suitAI, pSuit->AI())->SetupMovement(4);
                            JumpToNextStep(1500);
                            break;
                        case 45:
                            SetHoldState(false);
                            break;
                        case 47:
                            DoTalk(me, MEK_17_1, SOUND_MEK_17, false);
                            for (int8 n = 0; n < 4; ++n)
                                if (Creature* pSoldier = me->SummonCreature(urand(0, 1) ? NPC_I_INFANTRY : NPC_I_CAVALRY, iSoldierSpawn[n], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 50000))
                                    pSoldier->GetMotionMaster()->MovePoint(0, -4955.23f, 728.98f, 259.31f);
                            JumpToNextStep(5000);
                            break;
                        case 48:
                            SetHoldState(false);
                            break;
                        case 50:
                            SetHoldState(false);
                            JumpToNextStep(5000);
                            break;
                        case 52:
                            if (uiSoldiers <= 1/*30*/)
                            {
                                if (Creature* pSoldier = me->SummonCreature(urand(0, 1) ? NPC_I_INFANTRY : NPC_I_CAVALRY, iSoldierSpawn[urand(0,5)], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 50000))
                                {
                                    pSoldier->GetMotionMaster()->MovePoint(0, -4955.23f, 728.98f, 259.31f);
                                    ++uiSoldiers;
                                }
                                uiStep_timer = 4000;
                            }
                            else
                            {
                                if (Creature* pBoltcog = me->SummonCreature(NPC_BOLTCOG, -5035.236816f, 708.675232f, 260.499268f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 50000))
                                {
                                    CAST_AI(npc_og_boltcog::npc_og_boltcogAI, pBoltcog->AI())->SetupMovement();
                                    JumpToNextStep(15000);
                                }
                            }
                            break;
                        case 53:
                            if (Creature* pBoltcog = me->FindNearestCreature(NPC_BOLTCOG, 1000, true))
                                DoTalk(pBoltcog, BOLTCOG_1, SOUND_BOLTCOG_1, true);
                            JumpToNextStep(1);
                            break;
                        case 55:
                            SetHoldState(false);
                            break;
                        case 57:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                DoTalk(pBragBot, THERM_2_1, SOUND_THERM_2, true);
                            JumpToNextStep(6000);
                            break;
                        case 58:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_2_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(3000);
                            break;
                        case 59:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_2_3, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(5000);
                            break;
                        case 60:
                            DoTalk(me, MEK_18_1, SOUND_MEK_18, false);
                            JumpToNextStep(5000);
                            break;
                        case 61:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                DoTalk(pBragBot, THERM_3_1, SOUND_THERM_3, true);
                            JumpToNextStep(5000);
                            break;
                        case 62:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_3_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(7000);
                            break;
                        case 63:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_3_3, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(2000);
                            break;
                        case 64:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->MonsterYell(THERM_3_4, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(8000);
                            break;
                        case 65:
                            if (GameObject* pGO = me->FindNearestGameObject(OBJ_IRRADIATOR, 20))
                            {
                                pGO->SetGoState(GO_STATE_ACTIVE);
                                if (Creature* pIrraiator = me->SummonCreature(NPC_IRRADIATOR, pGO->GetPositionX(), pGO->GetPositionY(), pGO->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                                    DoTalk(pIrraiator, IRRADIATOR_1_1, SOUND_IRRADIATOR_1, true);
                            }
                            JumpToNextStep(8000);
                            break;
                        case 66:
                            DoTalk(me, MEK_19_1, SOUND_MEK_19, false);
                            JumpToNextStep(5000);
                            break;
                        case 67:
                            me->MonsterSay(MEK_19_2, LANG_UNIVERSAL, NULL);
                            me->Unmount();
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 25140);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_WORK_SHEATHED);
                            JumpToNextStep(10000);
                            break;
                        case 68:
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                DoTalk(pBragBot, THERM_4_1, SOUND_THERM_4, true);
                            JumpToNextStep(10000);
                            break;
                        case 69:
                            if (Creature* pIrraiator = me->FindNearestCreature(NPC_IRRADIATOR, 20, true))
                                DoTalk(pIrraiator, IRRADIATOR_2_1, SOUND_IRRADIATOR_2, true);
                            if (Creature* pBragBot = me->FindNearestCreature(NPC_BRAG_BOT, 20, true))
                                pBragBot->DisappearAndDie();
                            JumpToNextStep(8000);
                            break;
                        case 70:
                            if (Creature* pIrraiator = me->FindNearestCreature(NPC_IRRADIATOR, 20, true))
                                pIrraiator->DisappearAndDie();
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 53056);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            DoTalk(me, MEK_20_1, SOUND_MEK_20, false);
                            JumpToNextStep(5000);
                            break;
                        case 71:
                            if (Player* pPlayer = GetPlayerForEscort())
                            {
                                if (Group* pGroup = pPlayer->GetGroup())
                                {
                                    for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                                    {
                                        if (Player* pMember = itr->getSource())
                                        {
                                            pMember->KilledMonsterCredit(NPC_BRAG_BOT, 0);
                                            pMember->TeleportTo(0, -4839.26f, -1273.38f, 501.87f, 0.51f);
                                        }
                                    }
                                }
                                else
                                {
                                    pPlayer->KilledMonsterCredit(NPC_BRAG_BOT, 0);
                                    pPlayer->TeleportTo(0, -4839.26f, -1273.38f, 501.87f, 0.51f);
                                }
                            }
                            bBuffs = false;
                            me->RemoveAurasDueToSpell(SPELL_HEALTH_REGEN);
                            me->RemoveAurasDueToSpell(SPELL_BRILLIANT_TACTICS);
                            me->NearTeleportTo(-4827.0f, -1256.0f, 506.077f, 4.535f);
                            me->SetDisplayId(11686);
                            JumpToNextStep(15000);
                            break;
                        case 72:
                            DoTalk(me, MEK_21_1, SOUND_MEK_21, false);
                            JumpToNextStep(10000);
                            break;
                        case 73:
                            me->MonsterSay(MEK_21_2, LANG_UNIVERSAL, NULL);
                            JumpToNextStep(10000);
                            break;
                        case 74:
                            me->DisappearAndDie();
                            break;
                    }
                }
                else 
                    uiStep_timer -= diff;

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            void EnterCombat(Unit* pWho)
            {
                SquadAssist(pWho->ToCreature());
            }

            void PartyCast(uint32 spell)
            {
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    if (Group* pGroup = pPlayer->GetGroup())
                    {
                        for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                        {
                            if (Player* pMember = itr->getSource())
                                pMember->CastSpell(pMember, spell, true);
                        }
                    }
                    else
                    {
                        pPlayer->CastSpell(pPlayer, spell, true);
                    }
                }
            }

            void SpecialKill(uint32 variation)
            {
                switch (variation)
                {
                    case 0:
                    {
                        ++uiRLDestroyed;

                        if (uiStep > 14)
                        {
                            switch (uiRLDestroyed)
                            {
                                case 1:
                                    DoTalk(me, MEK_7_1, SOUND_MEK_7, false);
                                    break;
                                case 2:
                                    DoTalk(me, MEK_8_1, SOUND_MEK_8, false);
                                    break;
                                case 3:
                                    DoTalk(me, MEK_9_1, SOUND_MEK_9, false);
                                    break;
                                case 4:
                                    break;
                                default:
                                    sLog->outError("More than 4 Rocket Launchers destroyed!");
                            }
                        }

                        DoUpdateWorldState(WORLDSTATE_RL_DESTROYED, uiRLDestroyed);

                        break;
                    }
                    case 1:
                    {
                        ++uiCannonsDestroyed;

                        DoUpdateWorldState(WORLDSTATE_CANNONS_DESTROYED, uiCannonsDestroyed);

                        if (uiCannonsDestroyed == 6)
                        {
                            bCanSummonBomber = false;
                            DoUpdateWorldState(WORLDSTATE_AIRFIELD_CAPTURED, 0);
                            DoUpdateWorldState(WORLDSTATE_CANNONS_DESTROYED_CTRL, 0);
                            DoUpdateWorldState(WORLDSTATE_AIRFIELD_AND_COMMAND_CENTER_CAPTURED, 1);
                        }

                        if (uiCannonsDestroyed > 6)
                            sLog->outError("More than 6 Tankbuster Cannons destroyed!");

                        break;
                    }
                    case 2:
                    {
                        DoUpdateWorldState(WORLDSTATE_BATTLE_NEAR_ENTRANCE, 0);
                        DoUpdateWorldState(WORLDSTATE_AIRFIELD_AND_COMMAND_CENTER_CAPTURED, 0);
                        DoUpdateWorldState(WORLDSTATE_SURFACE_CAPTURED, 1);
                        JumpToNextStep(2000);
                        break;
                    }
                    default:
                        sLog->outError("Unexpected variation (%i) in npc_og_mekkatorqueAI::SpecialKill call!", variation);
                }
            }

            void DoTalk(Creature* pTalker, const char* text, uint32 sound, bool yell)
            {
                if (yell)
                    pTalker->MonsterYell(text, LANG_UNIVERSAL, NULL);
                else
                    pTalker->MonsterSay(text, LANG_UNIVERSAL, NULL);

                if (sound != 0)
                    DoPlaySoundToSet(pTalker, sound);
            }

            void SquadAssist(Creature* pTarget)
            {
                if (!pTarget->isAlive())
                    return;

                if (Creature* pCogspin = me->FindNearestCreature(NPC_COGSPIN, 100))
                    pCogspin->AI()->AttackStart(pTarget);

                if (Creature* pFastblast = me->FindNearestCreature(NPC_FASTBLAST, 100))
                    pFastblast->AI()->AttackStart(pTarget);
            }

            void SquadSetRun(bool b_Run)
            {
                if (Creature* pCogspin = me->FindNearestCreature(NPC_COGSPIN, 100))
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pCogspin->AI())->SetRun(b_Run);
                if (Creature* pFastblast = me->FindNearestCreature(NPC_FASTBLAST, 100))
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pFastblast->AI())->SetRun(b_Run);

                SetRun(b_Run);
            }

            void DoPlayMusic(uint8 musicId)
            {
                switch (musicId)
                {
                    case 0:
                        PartyCast(SPELL_MUSIC_START);
                        break;
                    case 1:
                        PartyCast(SPELL_MUSIC);
                        break;
                    case 2:
                        PartyCast(SPELL_MUSIC_END);
                        break;
                    default:
                        sLog->outError("Unexpected musicId (%i) in npc_og_mekkatorqueAI::DoPlayMusic call!", musicId);
                }
            }

            void DoSummonBomber()
            {
                if (bCanSummonBomber)
                {
                    Creature* pBomber = me->SummonCreature(NPC_BOMBER, BomberSpawn, TEMPSUMMON_CORPSE_DESPAWN);
                    pBomber->setActive(true);
                    pBomber->SetSpeed(MOVE_FLIGHT, 5.0, true);
                    pBomber->GetMotionMaster()->MovePoint(1, -5034.42f, 369.79f, 438.06f);
                }
            }

            void SpellHit(Unit* pHitter, const SpellEntry* pSpell)
            {
                if (pSpell->Id == SPELL_TRIGGER)
                {
                    switch (pHitter->GetEntry())
                    {
                        case NPC_BOLTCOG:
                            DoUpdateWorldState(WORLDSTATE_BATLLE_IN_TUNNELS, 0);
                            DoUpdateWorldState(WORLDSTATE_TUNNELS_CAPTURED, 1);
                            JumpToNextStep(100);
                            break;
                        case NPC_FASTBLAST:
                            bPreJumpWP_1 = true;
                            break;
                        case NPC_COGSPIN:
                            bPreJumpWP_2 = true;
                            break;
                    }
                }
            }

            void DoUpdateWorldState(uint32 worldstate, uint32 value)
            {
                Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

                if (PlList.isEmpty())
                    return;

                for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                {
                    if (Player* pPlayer = i->getSource())
                    {
                        if (pPlayer->GetQuestStatus(QUEST_OPERATION_GNOMEREGAN) == QUEST_STATUS_INCOMPLETE)
                            pPlayer->SendUpdateWorldState(worldstate, value);
                    }
                }
            }

            void DoRefreshkWorldStates()
            {
                Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

                if (PlList.isEmpty())
                    return;

                for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                {
                    if (Player* pPlayer = i->getSource())
                    {
                        if (pPlayer->GetQuestStatus(QUEST_OPERATION_GNOMEREGAN) == QUEST_STATUS_NONE || pPlayer->GetQuestStatus(QUEST_OPERATION_GNOMEREGAN) == QUEST_STATUS_REWARDED)
                            for (int8 n = 0; n < 15; ++n)
                                pPlayer->SendUpdateWorldState(Worldsates[n], 0);
                    }
                }
            }
        };

        bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
        {
            if (pQuest->GetQuestId() == QUEST_OPERATION_GNOMEREGAN)
            {
                if (npc_og_mekkatorqueAI* pEscortAI = CAST_AI(npc_og_mekkatorqueAI, pCreature->AI()))
                {
                    pEscortAI->Start(true, true, pPlayer->GetGUID(), pQuest);
                    pEscortAI->SetDespawnAtFar(false);
                    pEscortAI->SetDespawnAtEnd(false);
                    pCreature->setActive(true);
                }
                if (Creature* pCogspin = pCreature->FindNearestCreature(NPC_COGSPIN, 20))
                {
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pCogspin->AI())->Start(true, true, pPlayer->GetGUID(), pQuest);
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pCogspin->AI())->SetDespawnAtFar(false);
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pCogspin->AI())->SetDespawnAtEnd(false);
                        pCogspin->setActive(true);
                }
                if (Creature* pFastblast = pCreature->FindNearestCreature(NPC_FASTBLAST, 20))
                {
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pFastblast->AI())->Start(true, true, pPlayer->GetGUID(), pQuest);
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pFastblast->AI())->SetDespawnAtFar(false);
                        CAST_AI(npc_og_assistants::npc_og_assistantsAI, pFastblast->AI())->SetDespawnAtEnd(false);
                        pFastblast->setActive(true);
                }
            }
            return true;
        }

    CreatureAI *GetAI(Creature* pCreature) const
    {
        return new npc_og_mekkatorqueAI(pCreature);
    }
};

class npc_og_rl : public CreatureScript
{
    public:
        npc_og_rl() : CreatureScript("npc_og_rl") { }

        struct npc_og_rlAI : public ScriptedAI
        {
            npc_og_rlAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            void JustDied(Unit* /*who*/)
            {
                if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 1000, true))
                    CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->SpecialKill(0);
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_rlAI(pCreature);
    }

};

class npc_og_cannon : public CreatureScript
{
    public:
        npc_og_cannon() : CreatureScript("npc_og_cannon") { }

        struct npc_og_cannonAI : public ScriptedAI
        {
            npc_og_cannonAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 uiHits;

            void Reset()
            {
                if (uiHits < 5 && !me->HasAura(SPELL_CANNON_SHIELD))
                    me->CastSpell(me, SPELL_CANNON_SHIELD, true);
            }

            void SpellHit(Unit* pHitter, const SpellEntry* pSpell)
            {
                if (pSpell->Id == SPELL_ROCKET)
                {
                    ++uiHits;
                    if (uiHits == 5)
                    {
                        if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 1000, true))
                            if (!CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->bCannonIntro)
                            {
                                CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->DoTalk(pMekkatorque, MEK_11_1, SOUND_MEK_11, false);
                                CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->bCannonIntro = true;
                            }

                        me->RemoveAurasDueToSpell(SPELL_CANNON_SHIELD);
                    }
                }
                else if (pSpell->Id == SPELL_TRIGGER)
                {
                    uiHits = 0;
                    me->CastSpell(me, SPELL_CANNON_SHIELD, true);
                }
            }

            void JustDied(Unit * /*who*/)
            {
                if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 1000, true))
                    CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->SpecialKill(1);
            }

        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_cannonAI(pCreature);
    }
};

class npc_og_bomber : public CreatureScript
{
    public:
        npc_og_bomber() : CreatureScript("npc_og_bomber") { }

        struct npc_og_bomberlAI : public ScriptedAI
        {
            npc_og_bomberlAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            bool bAction;

            void Reset()
            {
                bAction = true;
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == 1)
                    if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 300, true))
                            CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->DoSummonBomber();
                            
                me->DisappearAndDie();
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() != TYPEID_UNIT)
                    return;

                if (who->GetEntry() != NPC_CANNON || !bAction || !who->HasAura(SPELL_CANNON_SHIELD))
                    return;

                Creature* pInfantry = me->SummonCreature(NPC_INFANTRY, me->GetPositionX(),  me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000);
                CAST_AI(npc_og_infantry::npc_og_infantryAI, pInfantry->AI())->Deploy();
                pInfantry->SetHomePosition(me->GetPositionX(), me->GetPositionY(), 394.9f, me->GetOrientation());
                pInfantry->Relocate(me->GetPositionX(), me->GetPositionY(), 394.9f);
                SpellEntry const* sEntry = sSpellStore.LookupEntry(SPELL_ROCKET);
                me->CastSpell(who, sEntry, true);
                CAST_AI(npc_og_cannon::npc_og_cannonAI, who->ToCreature()->AI())->SpellHit(me, sEntry);
                bAction = false;
            }
        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_bomberlAI(pCreature);
    }
};

class npc_og_trogg : public CreatureScript
{
    public:
        npc_og_trogg() : CreatureScript("npc_og_trogg") { }

        struct npc_og_troggAI : public ScriptedAI
        {
            npc_og_troggAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            void Reset()
            {
            }

            void JustDied(Unit * /*who*/)
            {
                if (me->GetEntry() == NPC_GASHERIKK)
                    if (Creature* pMekkatorque = me->FindNearestCreature(NPC_MEKKATORQUE, 100, true))
                        CAST_AI(npc_og_mekkatorque::npc_og_mekkatorqueAI, pMekkatorque->AI())->SpecialKill(2);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 0)
                    me->GetMotionMaster()->MovePoint(1, -5183.51f, 601.21f, 409.02f);

                if (id == 1)
                    me->GetMotionMaster()->MovePoint(2, -5183.19f, 590.74f, 405.92f);
            }

        };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_og_troggAI(pCreature);
    }
};

void AddSC_operation_gnomeregan()
{
    new npc_og_mekkatorque;
    new npc_og_assistants;
    new npc_og_infantry;
    new npc_og_boltcog;
    new npc_og_cannon;
    new npc_og_i_tank;
    new npc_og_bomber;
    new npc_og_trogg;
    new npc_og_tank;
    new npc_og_suit;
    new npc_og_rl;
}
