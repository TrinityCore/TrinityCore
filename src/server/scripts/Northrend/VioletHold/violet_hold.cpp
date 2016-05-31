/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "violet_hold.h"

/*
 * TODO:
 * - add missing trash emotes
 */

enum PortalCreatureIds
{
    NPC_AZURE_INVADER_1         = 30661,
    NPC_AZURE_SPELLBREAKER_1    = 30662,
    NPC_AZURE_BINDER_1          = 30663,
    NPC_AZURE_MAGE_SLAYER_1     = 30664,
    NPC_VETERAN_MAGE_HUNTER     = 30665,
    NPC_AZURE_CAPTAIN_1         = 30666,
    NPC_AZURE_SORCEROR_1        = 30667,
    NPC_AZURE_RAIDER_1          = 30668,

    NPC_AZURE_BINDER_2          = 30918,
    NPC_AZURE_INVADER_2         = 30961,
    NPC_AZURE_SPELLBREAKER_2    = 30962,
    NPC_AZURE_MAGE_SLAYER_2     = 30963,
    NPC_AZURE_BINDER_3          = 31007,
    NPC_AZURE_INVADER_3         = 31008,
    NPC_AZURE_SPELLBREAKER_3    = 31009,
    NPC_AZURE_MAGE_SLAYER_3     = 31010,
    NPC_AZURE_RAIDER_2          = 31118,
    NPC_AZURE_STALKER_1         = 32191
};

enum AzureInvaderSpells
{
    SPELL_CLEAVE                = 15496,
    SPELL_IMPALE                = 58459,
    SPELL_BRUTAL_STRIKE         = 58460,
    SPELL_SUNDER_ARMOR          = 58461
};

enum AzureSellbreakerSpells
{
    SPELL_ARCANE_BLAST          = 58462,
    SPELL_SLOW                  = 25603,
    SPELL_CHAINS_OF_ICE         = 58464,
    SPELL_CONE_OF_COLD          = 58463,
};

enum AzureBinderSpells
{
    SPELL_ARCANE_BARRAGE        = 58456,
    SPELL_ARCANE_EXPLOSION      = 58455,
    SPELL_FROST_NOVA            = 58458,
    SPELL_FROSTBOLT             = 58457,
};

enum AzureMageSlayerSpells
{
    SPELL_ARCANE_EMPOWERMENT    = 58469,
    SPELL_SPELL_LOCK            = 30849
};

enum AzureCaptainSpells
{
    SPELL_MORTAL_STRIKE         = 32736,
    SPELL_WHIRLWIND_OF_STEEL    = 41057
};

enum AzureSorcerorSpells
{
    SPELL_ARCANE_STREAM         = 60181,
    SPELL_MANA_DETONATION       = 60182,
};

enum AzureRaiderSpells
{
    SPELL_CONCUSSION_BLOW       = 52719,
    SPELL_MAGIC_REFLECTION      = 60158
};

enum AzureStalkerSpells
{
    SPELL_BACKSTAB              = 58471,
    SPELL_TACTICAL_BLINK        = 58470
};

enum AzureSaboteurSpells
{
    SPELL_SHIELD_DISRUPTION     = 58291,
    SPELL_TELEPORT_VISUAL       = 51347
};

enum TrashDoorSpell
{
    SPELL_DESTROY_DOOR_SEAL     = 58040
};

enum DefenseSystemSpells
{
    SPELL_ARCANE_LIGHTNING_DAMAGE       = 57912,
    SPELL_ARCANE_LIGHTNING_INSTAKILL    = 58152,
    SPELL_ARCANE_LIGHTNING_DUMMY        = 57930
};

enum MiscSpells
{
    SPELL_PORTAL_PERIODIC           = 58008,
    SPELL_PORTAL_CHANNEL            = 58012,
    SPELL_CRYSTAL_ACTIVATION        = 57804,

    SPELL_TELEPORT_PLAYER           = 62138,
    SPELL_TELEPORT_PLAYER_EFFECT    = 62139
};

enum MiscData
{
    DATA_PORTAL_PERIODIC_TICK       = 1
};

enum Sinclari
{
    // Sinclari
    SAY_SINCLARI_INTRO_1            = 0,
    SAY_SINCLARI_INTRO_2            = 1,
    SAY_SINCLARI_OUTRO              = 2,

    GOSSIP_MENU_START_ENCOUNTER     = 9998,
    GOSSIP_MENU_SEND_ME_IN          = 10275,

    // Sinclari Trigger
    SAY_SINCLARI_ELITE_SQUAD        = 0,
    SAY_SINCLARI_PORTAL_GUARDIAN    = 1,
    SAY_SINCLARI_PORTAL_KEEPER      = 2
};

G3D::Vector3 const FirstPortalWPs[6] =
{
    {1877.670288f, 842.280273f, 43.333591f},
    {1877.338867f, 834.615356f, 38.762287f},
    {1872.161011f, 823.854309f, 38.645401f},
    {1864.860474f, 815.787170f, 38.784843f},
    {1858.953735f, 810.048950f, 44.008759f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

G3D::Vector3 const SecondPortalFirstWPs[9] =
{
    {1902.561401f, 853.334656f, 47.106117f},
    {1895.486084f, 855.376404f, 44.334591f},
    {1882.805176f, 854.993286f, 43.333591f},
    {1877.670288f, 842.280273f, 43.333591f},
    {1877.338867f, 834.615356f, 38.762287f},
    {1872.161011f, 823.854309f, 38.645401f},
    {1864.860474f, 815.787170f, 38.784843f},
    {1858.953735f, 810.048950f, 44.008759f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

G3D::Vector3 const SecondPortalSecondWPs[8] =
{
    {1929.392212f, 837.614990f, 47.136166f},
    {1928.290649f, 824.750427f, 45.474411f},
    {1915.544922f, 826.919373f, 38.642811f},
    {1900.933960f, 818.855652f, 38.801647f},
    {1886.810547f, 813.536621f, 38.490490f},
    {1869.079712f, 808.701538f, 38.689003f},
    {1860.843384f, 806.645020f, 44.008789f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

G3D::Vector3 const ThirdPortalWPs[8] =
{
    {1934.049438f, 815.778503f, 52.408699f},
    {1928.290649f, 824.750427f, 45.474411f},
    {1915.544922f, 826.919373f, 38.642811f},
    {1900.933960f, 818.855652f, 38.801647f},
    {1886.810547f, 813.536621f, 38.490490f},
    {1869.079712f, 808.701538f, 38.689003f},
    {1860.843384f, 806.645020f, 44.008789f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

G3D::Vector3 const FourthPortalWPs[9] =
{
    {1921.658447f, 761.657043f, 50.866741f},
    {1910.559814f, 755.780457f, 47.701447f},
    {1896.664673f, 752.920898f, 47.667004f},
    {1887.398804f, 763.633240f, 47.666851f},
    {1879.020386f, 775.396973f, 38.705990f},
    {1872.439087f, 782.568604f, 38.808292f},
    {1863.573364f, 791.173584f, 38.743660f},
    {1857.811890f, 796.765564f, 43.950329f},
    {1845.577759f, 800.681152f, 44.104248f}
    //{1827.100342f, 801.605957f, 44.363358f}
};

G3D::Vector3 const FifthPortalWPs[6] =
{
    {1887.398804f, 763.633240f, 47.666851f},
    {1879.020386f, 775.396973f, 38.705990f},
    {1872.439087f, 782.568604f, 38.808292f},
    {1863.573364f, 791.173584f, 38.743660f},
    {1857.811890f, 796.765564f, 43.950329f},
    {1845.577759f, 800.681152f, 44.104248f}
    //{1827.100342f, 801.605957f, 44.363358f}
};

G3D::Vector3 const SixthPoralWPs[4] =
{
    {1888.861084f, 805.074768f, 38.375790f},
    {1869.793823f, 804.135804f, 38.647018f},
    {1861.541504f, 804.149780f, 43.968292f},
    {1843.567017f, 804.288208f, 44.139091f}
    //{1826.889648f, 803.929993f, 44.363239f}
};

G3D::Vector3 const DefaultPortalWPs[1] =
{
    { 1843.567017f, 804.288208f, 44.139091f }
};

uint32 const SaboteurMoraggPathSize = 5;
G3D::Vector3 const SaboteurMoraggPath[SaboteurMoraggPathSize] = // sniff
{
    { 1886.251f, 803.0743f, 38.42326f },
    { 1885.71f,  799.8929f, 38.37241f },
    { 1889.505f, 762.3288f, 47.66684f },
    { 1894.542f, 742.1829f, 47.66684f },
    { 1894.603f, 739.9231f, 47.66684f },
};

uint32 const SaboteurErekemPathSize = 5;
G3D::Vector3 const SaboteurErekemPath[SaboteurErekemPathSize] = // sniff
{
    { 1886.251f, 803.0743f, 38.42326f },
    { 1881.047f, 829.6866f, 38.64856f },
    { 1877.585f, 844.6685f, 38.49014f },
    { 1876.085f, 851.6685f, 42.99014f },
    { 1873.747f, 864.1373f, 43.33349f }
};

uint32 const SaboteurIchoronPathSize = 3;
G3D::Vector3 const SaboteurIchoronPath[SaboteurIchoronPathSize] = // sniff
{
    { 1886.251f, 803.0743f, 38.42326f },
    { 1888.672f, 801.2348f, 38.42305f },
    { 1901.987f, 793.3254f, 38.65126f }
};

uint32 const SaboteurLavanthorPathSize = 3;
G3D::Vector3 const SaboteurLavanthorPath[SaboteurLavanthorPathSize] = // sniff
{
    { 1886.251f, 803.0743f, 38.42326f },
    { 1867.925f, 778.8035f, 38.64702f },
    { 1853.304f, 759.0161f, 38.65761f }
};

uint32 const SaboteurXevozzPathSize = 4;
G3D::Vector3 const SaboteurXevozzPath[SaboteurXevozzPathSize] = // sniff
{
    { 1886.251f, 803.0743f, 38.42326f },
    { 1889.096f, 810.0487f, 38.43871f },
    { 1896.547f, 823.5473f, 38.72863f },
    { 1906.666f, 842.3111f, 38.63351f }
};

uint32 const SaboteurZuramatPathSize = 7;
G3D::Vector3 const SaboteurZuramatPath[SaboteurZuramatPathSize] = // sniff
{
    { 1886.251f, 803.0743f, 38.42326f },
    { 1889.69f,  807.0032f, 38.39914f },
    { 1906.91f,  818.2574f, 38.86596f },
    { 1929.03f,  824.2713f, 46.09165f },
    { 1928.441f, 842.8891f, 47.15078f },
    { 1927.454f, 851.6091f, 47.19094f },
    { 1927.947f, 852.2986f, 47.19637f }
};

Position const SinclariPositions[] = // sniff
{
    { 1829.142f, 798.219f,  44.36212f, 0.122173f }, // 0 - Crystal
    { 1820.12f,  803.916f,  44.36466f, 0.0f      }, // 1 - Outside
    { 1816.185f, 804.0629f, 44.44799f, 3.176499f }, // 2 - Second Spawn Point
    { 1827.886f, 804.0555f, 44.36467f, 0.0f      }  // 3 - Outro
};

Position const GuardsMovePosition = { 1802.099f, 803.7724f, 44.36466f, 0.0f }; // sniff

class npc_sinclari_vh : public CreatureScript
{
    public:
        npc_sinclari_vh() : CreatureScript("npc_sinclari_vh") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            // override default gossip
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                switch (instance->GetData(DATA_MAIN_EVENT_STATE))
                {
                    case IN_PROGRESS:
                        player->PrepareGossipMenu(creature, GOSSIP_MENU_SEND_ME_IN, true);
                        player->SendPreparedGossip(creature);
                        return true;
                    case DONE:
                        return true; // NYI
                    case NOT_STARTED:
                    case FAIL:
                    default:
                        break;
                }
            }

            // load default gossip
            return false;
        }

        struct npc_sinclariAI : public ScriptedAI
        {
            npc_sinclariAI(Creature* creature) : ScriptedAI(creature), _summons(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _summons.DespawnAll();
                for (uint8 i = 0; i < PortalIntroCount; ++i)
                    if (Creature* summon = me->SummonCreature(NPC_TELEPORTATION_PORTAL_INTRO, PortalIntroPositions[i], TEMPSUMMON_MANUAL_DESPAWN))
                        summon->AI()->SetData(DATA_PORTAL_LOCATION, i);

                me->SetVisible(true);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                std::list<Creature*> guardList;
                me->GetCreatureListWithEntryInGrid(guardList, NPC_VIOLET_HOLD_GUARD, 100.0f);
                for (Creature* guard : guardList)
                {
                    guard->Respawn(true);
                    guard->SetVisible(true);
                    guard->SetReactState(REACT_AGGRESSIVE);
                    guard->AI()->EnterEvadeMode();
                }
            }

            void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                if (menuId == GOSSIP_MENU_START_ENCOUNTER && gossipListId == 0)
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    _instance->SetData(DATA_MAIN_EVENT_STATE, SPECIAL);
                    ScheduleIntro();
                    player->PlayerTalkClass->SendCloseGossip();
                }
                else if (menuId == GOSSIP_MENU_SEND_ME_IN && gossipListId == 0)
                {
                    me->CastSpell(player, SPELL_TELEPORT_PLAYER, true);
                    player->PlayerTalkClass->SendCloseGossip();
                }
            }

            void DoAction(int32 actionId) override
            {
                if (actionId == ACTION_SINCLARI_OUTRO)
                {
                    me->SetVisible(true);
                    ScheduleOutro();
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _scheduler.Update(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            void ScheduleIntro()
            {
                _scheduler.Schedule(Seconds(1), [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(0, SinclariPositions[0]);
                            task.Repeat(Seconds(1));
                            break;
                        case 1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
                            me->GetMap()->SummonCreature(NPC_DEFENSE_SYSTEM, DefenseSystemLocation);
                            task.Repeat(Seconds(3));
                            break;
                        case 2:
                            me->SetFacingTo(SinclariPositions[0].GetOrientation());
                            Talk(SAY_SINCLARI_INTRO_1);

                            task.Schedule(Seconds(1), [this](TaskContext /*task*/)
                            {
                                std::list<Creature*> guardList;
                                me->GetCreatureListWithEntryInGrid(guardList, NPC_VIOLET_HOLD_GUARD, 100.0f);
                                for (Creature* guard : guardList)
                                {
                                    guard->SetReactState(REACT_PASSIVE);
                                    guard->SetWalk(false);
                                    guard->GetMotionMaster()->MovePoint(0, GuardsMovePosition);
                                }
                            });

                            task.Repeat(Seconds(2));
                            break;
                        case 3:
                            me->GetMotionMaster()->MovePoint(0, SinclariPositions[1]);
                            _summons.DespawnAll();
                            task.Repeat(Seconds(5));
                            break;
                        case 4:
                            me->SetFacingTo(SinclariPositions[1].GetOrientation());

                            task.Schedule(Seconds(1), [this](TaskContext /*task*/)
                            {
                                std::list<Creature*> guardList;
                                me->GetCreatureListWithEntryInGrid(guardList, NPC_VIOLET_HOLD_GUARD, 100.0f);
                                for (Creature* guard : guardList)
                                    guard->SetVisible(false);
                            });

                            task.Repeat(Seconds(6));
                            break;
                        case 5:
                            Talk(SAY_SINCLARI_INTRO_2);
                            task.Repeat(Seconds(4));
                            break;
                        case 6:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK_NO_SHEATHE);
                            task.Repeat(Seconds(1));
                            break;
                        case 7:
                            if (GameObject* mainDoor = _instance->GetGameObject(DATA_MAIN_DOOR))
                            {
                                mainDoor->SetGoState(GO_STATE_READY);
                                mainDoor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                            }
                            task.Repeat(Seconds(5));
                            break;
                        case 8:
                            me->SetVisible(false);
                            task.Repeat(Seconds(1));
                            break;
                        case 9:
                            _instance->SetData(DATA_MAIN_EVENT_STATE, IN_PROGRESS);
                            // [1] GUID: Full: 0xF1300077C202E6DD Type: Creature Entry: 30658 Low: 190173
                            break;
                        default:
                            break;
                    }
                });
            }

            void ScheduleOutro()
            {
                _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                {
                    Talk(SAY_SINCLARI_OUTRO);
                    me->GetMotionMaster()->MovePoint(0, SinclariPositions[3]);

                    task.Schedule(Seconds(10), [this](TaskContext /*task*/)
                    {
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    });
                });
            }

            void JustSummoned(Creature* summon) override
            {
                ScriptedAI::JustSummoned(summon);
                _summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                _summons.Despawn(summon);
                ScriptedAI::SummonedCreatureDespawn(summon);
            }

        private:
            InstanceScript* _instance;
            TaskScheduler _scheduler;

            SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_sinclariAI>(creature);
        }
};

class npc_azure_saboteur : public CreatureScript
{
    public:
        npc_azure_saboteur() : CreatureScript("npc_azure_saboteur") { }

        struct npc_azure_saboteurAI : public ScriptedAI
        {
            npc_azure_saboteurAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();

                if (_instance->GetData(DATA_WAVE_COUNT) == 6)
                    _bossId = _instance->GetData(DATA_1ST_BOSS);
                else
                    _bossId = _instance->GetData(DATA_2ND_BOSS);
            }

            void StartMovement()
            {
                uint32 pathSize = 0;
                G3D::Vector3 const* path = nullptr;

                switch (_bossId)
                {
                    case DATA_MORAGG:
                        pathSize = SaboteurMoraggPathSize;
                        path = SaboteurMoraggPath;
                        break;
                    case DATA_EREKEM:
                        pathSize = SaboteurErekemPathSize;
                        path = SaboteurErekemPath;
                        break;
                    case DATA_ICHORON:
                        pathSize = SaboteurIchoronPathSize;
                        path = SaboteurIchoronPath;
                        break;
                    case DATA_LAVANTHOR:
                        pathSize = SaboteurLavanthorPathSize;
                        path = SaboteurLavanthorPath;
                        break;
                    case DATA_XEVOZZ:
                        pathSize = SaboteurXevozzPathSize;
                        path = SaboteurXevozzPath;
                        break;
                    case DATA_ZURAMAT:
                        pathSize = SaboteurZuramatPathSize;
                        path = SaboteurZuramatPath;
                        break;
                }

                if (path)
                    me->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, path, pathSize, false);
            }

            void Reset() override
            {
                _scheduler.CancelAll();
                _scheduler.Schedule(Seconds(2), [this](TaskContext /*task*/)
                {
                    StartMovement();
                });
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == EFFECT_MOTION_TYPE && pointId == POINT_INTRO)
                {
                    _scheduler.Schedule(Seconds(0), [this](TaskContext task)
                    {
                        me->CastSpell(me, SPELL_SHIELD_DISRUPTION, false);

                        if (task.GetRepeatCounter() < 2)
                            task.Repeat(Seconds(1));
                        else
                        {
                            task.Schedule(Seconds(2), [this](TaskContext /*task*/)
                            {
                                _instance->SetData(DATA_START_BOSS_ENCOUNTER, 1);
                                me->CastSpell(me, SPELL_TELEPORT_VISUAL, false);
                                me->DespawnOrUnsummon(1000);
                            });
                        }
                    });
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _scheduler.Update(diff);
            }

        private:
            InstanceScript* _instance;
            TaskScheduler _scheduler;

            uint32 _bossId;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_saboteurAI>(creature);
        }
};

struct npc_violet_hold_teleportation_portal_commonAI : public ScriptedAI
{
    npc_violet_hold_teleportation_portal_commonAI(Creature* creature) : ScriptedAI(creature), _summons(me)
    {
        _instance = creature->GetInstanceScript();
        _portalLocation = 0;
    }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        ScheduleTasks();
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_PORTAL_LOCATION)
            _portalLocation = uint8(data);
    }

    void MoveInLineOfSight(Unit* /*who*/) override { }

    void EnterCombat(Unit* /*who*/) override { }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
        summon->AI()->SetData(DATA_PORTAL_LOCATION, _portalLocation);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        _summons.Despawn(summon);
    }

    virtual void ScheduleTasks() { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

protected:
    InstanceScript* _instance;
    SummonList _summons;
    TaskScheduler _scheduler;
    uint8 _portalLocation;
};

class npc_violet_hold_teleportation_portal : public CreatureScript
{
    public:
        npc_violet_hold_teleportation_portal() : CreatureScript("npc_violet_hold_teleportation_portal") { }

        struct npc_violet_hold_teleportation_portalAI : public npc_violet_hold_teleportation_portal_commonAI
        {
            npc_violet_hold_teleportation_portalAI(Creature* creature) : npc_violet_hold_teleportation_portal_commonAI(creature)
            {
            }

            void InitializeAI() override
            {
                npc_violet_hold_teleportation_portal_commonAI::InitializeAI();
                me->CastSpell(me, SPELL_PORTAL_PERIODIC, true);
            }

            void SetData(uint32 type, uint32 data) override
            {
                npc_violet_hold_teleportation_portal_commonAI::SetData(type, data);

                if (type == DATA_PORTAL_PERIODIC_TICK)
                {
                    if (data == 1)
                    {
                        uint32 entry = RAND(NPC_PORTAL_GUARDIAN, NPC_PORTAL_KEEPER);
                        if (Creature* portalKeeper = DoSummon(entry, me, 2.0f, 0, TEMPSUMMON_DEAD_DESPAWN))
                            me->CastSpell(portalKeeper, SPELL_PORTAL_CHANNEL, false);

                        if (Creature* sinclariTrigger = _instance->GetCreature(DATA_SINCLARI_TRIGGER))
                        {
                            if (entry == NPC_PORTAL_GUARDIAN)
                                sinclariTrigger->AI()->Talk(SAY_SINCLARI_PORTAL_GUARDIAN);
                            else if (entry == NPC_PORTAL_KEEPER)
                                sinclariTrigger->AI()->Talk(SAY_SINCLARI_PORTAL_KEEPER);
                        }
                    }
                    else
                    {
                        uint8 k = _instance->GetData(DATA_WAVE_COUNT) < 12 ? 3 : 4;
                        while (k--)
                        {
                            uint32 entry = RAND(NPC_AZURE_INVADER_1, NPC_AZURE_INVADER_2, NPC_AZURE_SPELLBREAKER_1, NPC_AZURE_SPELLBREAKER_2, NPC_AZURE_MAGE_SLAYER_1, NPC_AZURE_MAGE_SLAYER_2, NPC_AZURE_BINDER_1, NPC_AZURE_BINDER_2);
                            DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                        }
                    }
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer) override
            {
                npc_violet_hold_teleportation_portal_commonAI::SummonedCreatureDies(summon, killer);

                if (summon->GetEntry() == NPC_PORTAL_GUARDIAN || summon->GetEntry() == NPC_PORTAL_KEEPER)
                {
                    _instance->SetData(DATA_WAVE_COUNT, _instance->GetData(DATA_WAVE_COUNT) + 1);
                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_violet_hold_teleportation_portalAI>(creature);
        }
};

class npc_violet_hold_teleportation_portal_elite : public CreatureScript
{
    public:
        npc_violet_hold_teleportation_portal_elite() : CreatureScript("npc_violet_hold_teleportation_portal_elite") { }

        struct npc_violet_hold_teleportation_portal_eliteAI : public npc_violet_hold_teleportation_portal_commonAI
        {
            npc_violet_hold_teleportation_portal_eliteAI(Creature* creature) : npc_violet_hold_teleportation_portal_commonAI(creature)
            {
            }

            void ScheduleTasks() override
            {
                _scheduler.Schedule(Seconds(15), [this](TaskContext task)
                {
                    uint8 k = _instance->GetData(DATA_WAVE_COUNT) < 12 ? 3 : 4;
                    while (k--)
                    {
                        uint32 entry = RAND(NPC_AZURE_CAPTAIN_1, NPC_AZURE_RAIDER_1, NPC_AZURE_STALKER_1, NPC_AZURE_SORCEROR_1);
                        DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                    }

                    if (Creature* sinclariTrigger = _instance->GetCreature(DATA_SINCLARI_TRIGGER))
                        sinclariTrigger->AI()->Talk(SAY_SINCLARI_ELITE_SQUAD);

                    task.Schedule(Seconds(1), [this](TaskContext /*task*/)
                    {
                        me->SetVisible(false);
                    });
                });
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer) override
            {
                npc_violet_hold_teleportation_portal_commonAI::SummonedCreatureDies(summon, killer);

                if (_summons.empty())
                {
                    _instance->SetData(DATA_WAVE_COUNT, _instance->GetData(DATA_WAVE_COUNT) + 1);
                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_violet_hold_teleportation_portal_eliteAI>(creature);
        }
};

class npc_violet_hold_teleportation_portal_intro : public CreatureScript
{
    public:
        npc_violet_hold_teleportation_portal_intro() : CreatureScript("npc_violet_hold_teleportation_portal_intro") { }

        struct npc_violet_hold_teleportation_portal_introAI : public npc_violet_hold_teleportation_portal_commonAI
        {
            npc_violet_hold_teleportation_portal_introAI(Creature* creature) : npc_violet_hold_teleportation_portal_commonAI(creature)
            {
            }

            void ScheduleTasks() override
            {
                if (_instance->GetData(DATA_MAIN_EVENT_STATE) != NOT_STARTED)
                    return;

                _scheduler.Schedule(Seconds(15), [this](TaskContext task)
                {
                    uint32 entry = RAND(NPC_AZURE_INVADER_1, NPC_AZURE_MAGE_SLAYER_1, NPC_AZURE_BINDER_1);
                    DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);

                    task.Repeat();
                });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_violet_hold_teleportation_portal_introAI>(creature);
        }
};

struct violet_hold_trashAI : public npc_escortAI
{
    violet_hold_trashAI(Creature* creature) : npc_escortAI(creature)
    {
        _instance = creature->GetInstanceScript();

        _lastWaypointId = 0;

        SetDespawnAtEnd(false);

        _scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_PORTAL_LOCATION)
        {
            G3D::Vector3 const* path = nullptr;

            switch (data)
            {
                case 0:
                    _lastWaypointId = 5;
                    path = FirstPortalWPs;
                    break;
                case 7:
                    switch (urand(0, 1))
                    {
                        case 0:
                            _lastWaypointId = 8;
                            path = SecondPortalFirstWPs;
                            break;
                        case 1:
                            _lastWaypointId = 7;
                            path = SecondPortalSecondWPs;
                            break;
                    }
                    break;
                case 2:
                    _lastWaypointId = 7;
                    path = ThirdPortalWPs;
                    break;
                case 6:
                    _lastWaypointId = 8;
                    path = FourthPortalWPs;
                    break;
                case 1:
                    _lastWaypointId = 5;
                    path = FifthPortalWPs;
                    break;
                case 5:
                    _lastWaypointId = 3;
                    path = SixthPoralWPs;
                    break;
                default:
                    _lastWaypointId = 0;
                    path = DefaultPortalWPs;
                    break;
            }

            if (path)
            {
                for (uint32 i = 0; i <= _lastWaypointId; i++)
                    AddWaypoint(i, path[i].x + irand(-1, 1), path[i].y + irand(-1, 1), path[i].z, 0);
                me->SetHomePosition(path[_lastWaypointId].x, path[_lastWaypointId].y, path[_lastWaypointId].z, float(M_PI));
            }

            Start(true, true);
        }
    }

    void WaypointReached(uint32 waypointId) override
    {
        if (waypointId == _lastWaypointId)
            CreatureStartAttackDoor();
    }

    void EnterCombat(Unit* who) override
    {
        npc_escortAI::EnterCombat(who);
        ScheduledTasks();
    }

    void UpdateEscortAI(uint32 diff) override
    {
        if (_instance->GetData(DATA_MAIN_EVENT_STATE) != IN_PROGRESS)
            me->CastStop();

        if (!UpdateVictim())
            return;

        _scheduler.Update(diff,
            std::bind(&npc_escortAI::DoMeleeAttackIfReady, this));
    }

    virtual void ScheduledTasks() { }

    void CreatureStartAttackDoor()
    {
        me->SetReactState(REACT_DEFENSIVE);
        DoCastAOE(SPELL_DESTROY_DOOR_SEAL);
    }

protected:
    InstanceScript* _instance;
    TaskScheduler _scheduler;

    uint32 _lastWaypointId;
};

class npc_azure_invader : public CreatureScript
{
    public:
        npc_azure_invader() : CreatureScript("npc_azure_invader") { }

        struct npc_azure_invaderAI : public violet_hold_trashAI
        {
            npc_azure_invaderAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                if (me->GetEntry() == NPC_AZURE_INVADER_1)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        DoCastVictim(SPELL_CLEAVE);
                        task.Repeat();
                    });

                    _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                    {
                        DoCastVictim(SPELL_IMPALE);
                        task.Repeat();
                    });
                }
                else if (me->GetEntry() == NPC_AZURE_INVADER_2)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        DoCastVictim(SPELL_BRUTAL_STRIKE);
                        task.Repeat();
                    });

                    _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                    {
                        DoCastVictim(SPELL_SUNDER_ARMOR);
                        task.Repeat(Seconds(8), Seconds(10));
                    });
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_invaderAI>(creature);
        }
};

class npc_azure_binder : public CreatureScript
{
    public:
        npc_azure_binder() : CreatureScript("npc_azure_binder") { }

        struct npc_azure_binderAI : public violet_hold_trashAI
        {
            npc_azure_binderAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                if (me->GetEntry() == NPC_AZURE_BINDER_1)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        DoCastAOE(SPELL_ARCANE_EXPLOSION);
                        task.Repeat();
                    });

                    _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                            DoCast(target, SPELL_ARCANE_BARRAGE);
                        task.Repeat(Seconds(6));
                    });
                }
                else if (me->GetEntry() == NPC_AZURE_BINDER_2)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        DoCastAOE(SPELL_FROST_NOVA);
                        task.Repeat();
                    });

                    _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f))
                            DoCast(target, SPELL_FROSTBOLT);
                        task.Repeat(Seconds(6));
                    });
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_binderAI>(creature);
        }
};

class npc_azure_mage_slayer : public CreatureScript
{
    public:
        npc_azure_mage_slayer() : CreatureScript("npc_azure_mage_slayer") { }

        struct npc_azure_mage_slayerAI : public violet_hold_trashAI
        {
            npc_azure_mage_slayerAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                if (me->GetEntry() == NPC_AZURE_MAGE_SLAYER_1)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        DoCast(me, SPELL_ARCANE_EMPOWERMENT);
                        task.Repeat(Seconds(14));
                    });
                }
                else if (me->GetEntry() == NPC_AZURE_MAGE_SLAYER_2)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        // wrong spellid?
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                            DoCast(target, SPELL_SPELL_LOCK);
                        task.Repeat(Seconds(9));
                    });
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_mage_slayerAI>(creature);
        }
};

class npc_azure_raider : public CreatureScript
{
    public:
        npc_azure_raider() : CreatureScript("npc_azure_raider") { }

        struct npc_azure_raiderAI : public violet_hold_trashAI
        {
            npc_azure_raiderAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                {
                    DoCastVictim(SPELL_CONCUSSION_BLOW);
                    task.Repeat();
                });

                _scheduler.Schedule(Seconds(8), [this](TaskContext task)
                {
                    DoCast(me, SPELL_MAGIC_REFLECTION);
                    task.Repeat(Seconds(10), Seconds(15));
                });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_raiderAI>(creature);
        }
};

class npc_azure_stalker : public CreatureScript
{
    public:
        npc_azure_stalker() : CreatureScript("npc_azure_stalker") { }

        struct npc_azure_stalkerAI : public violet_hold_trashAI
        {
            npc_azure_stalkerAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                _scheduler.Schedule(Seconds(8), [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f))
                        DoCast(target, SPELL_TACTICAL_BLINK);

                    task.Schedule(Milliseconds(1300), [this](TaskContext /*task*/)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 5.0f))
                            DoCast(target, SPELL_BACKSTAB);
                    });

                    task.Repeat();
                });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_stalkerAI>(creature);
        }
};

class npc_azure_spellbreaker : public CreatureScript
{
    public:
        npc_azure_spellbreaker() : CreatureScript("npc_azure_spellbreaker") { }

        struct npc_azure_spellbreakerAI : public violet_hold_trashAI
        {
            npc_azure_spellbreakerAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                if (me->GetEntry() == NPC_AZURE_SPELLBREAKER_1)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                            DoCast(target, SPELL_ARCANE_BLAST);
                        task.Repeat(Seconds(6));
                    });

                    _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                            DoCast(target, SPELL_SLOW);
                        task.Repeat(Seconds(5));
                    });
                }
                else if (me->GetEntry() == NPC_AZURE_SPELLBREAKER_2)
                {
                    _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                            DoCast(target, SPELL_CHAINS_OF_ICE);
                        task.Repeat(Seconds(7));
                    });

                    _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                    {
                        DoCast(me, SPELL_CONE_OF_COLD);
                        task.Repeat(Seconds(5));
                    });
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_spellbreakerAI>(creature);
        }
};

class npc_azure_captain : public CreatureScript
{
    public:
        npc_azure_captain() : CreatureScript("npc_azure_captain") { }

        struct  npc_azure_captainAI : public violet_hold_trashAI
        {
            npc_azure_captainAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                _scheduler.Schedule(Seconds(5), [this](TaskContext task)
                {
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    task.Repeat();
                });

                _scheduler.Schedule(Seconds(8), [this](TaskContext task)
                {
                    DoCast(me, SPELL_WHIRLWIND_OF_STEEL);
                    task.Repeat();
                });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_captainAI>(creature);
        }
};

class npc_azure_sorceror : public CreatureScript
{
    public:
        npc_azure_sorceror() : CreatureScript("npc_azure_sorceror") { }

        struct  npc_azure_sorcerorAI : public violet_hold_trashAI
        {
            npc_azure_sorcerorAI(Creature* creature) : violet_hold_trashAI(creature) { }

            void ScheduledTasks() override
            {
                _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 35.0f))
                        DoCast(target, SPELL_ARCANE_STREAM);
                    task.Repeat(Seconds(5), Seconds(10));
                });

                _scheduler.Schedule(Seconds(), Seconds(), [this](TaskContext task)
                {
                    DoCastAOE(SPELL_MANA_DETONATION);
                    task.Repeat(Seconds(2), Seconds(6));
                });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_azure_sorcerorAI>(creature);
        }
};

class npc_violet_hold_defense_system : public CreatureScript
{
    public:
        npc_violet_hold_defense_system() : CreatureScript("npc_violet_hold_defense_system") { }

        struct npc_violet_hold_defense_systemAI : public ScriptedAI
        {
            npc_violet_hold_defense_systemAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                ScheduledTasks();
                me->DespawnOrUnsummon(7000);
            }

            void ScheduledTasks()
            {
                _scheduler.Schedule(Seconds(4), [this](TaskContext task)
                {
                    DoCastAOE(SPELL_ARCANE_LIGHTNING_DAMAGE);
                    DoCastAOE(SPELL_ARCANE_LIGHTNING_DUMMY);
                    if (task.GetRepeatCounter() == 2)
                        DoCastAOE(SPELL_ARCANE_LIGHTNING_INSTAKILL);
                    else
                        task.Repeat(Seconds(1));
                });
            }

            void UpdateAI(uint32 diff) override
            {
                _scheduler.Update(diff);
            }

        private:
            TaskScheduler _scheduler;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_violet_hold_defense_systemAI(creature);
        }
};

class go_activation_crystal : public GameObjectScript
{
    public:
        go_activation_crystal() : GameObjectScript("go_activation_crystal") { }

        bool OnGossipHello(Player* player, GameObject* /*go*/) override
        {
            player->CastSpell(player, SPELL_CRYSTAL_ACTIVATION, true);
            return false;
        }
};

// 58040 - Destroy Door Seal
class spell_violet_hold_destroy_door_seal : public SpellScriptLoader
{
    public:
        spell_violet_hold_destroy_door_seal() : SpellScriptLoader("spell_violet_hold_destroy_door_seal") { }

        class spell_violet_hold_destroy_door_seal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_violet_hold_destroy_door_seal_AuraScript);

            bool Load() override
            {
                _instance = GetUnitOwner()->GetInstanceScript();
                return _instance != nullptr;
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (uint32 integrity = _instance->GetData(DATA_DOOR_INTEGRITY))
                    _instance->SetData(DATA_DOOR_INTEGRITY, integrity - 1);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_violet_hold_destroy_door_seal_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

        private:
            InstanceScript* _instance = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_violet_hold_destroy_door_seal_AuraScript();
        }
};

// 58008 - Portal Periodic
class spell_violet_hold_portal_periodic : public SpellScriptLoader
{
    public:
        spell_violet_hold_portal_periodic() : SpellScriptLoader("spell_violet_hold_portal_periodic") { }

        class spell_violet_hold_portal_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_violet_hold_portal_periodic_AuraScript);

            void PeriodicTick(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (GetTarget()->IsAIEnabled)
                    GetTarget()->GetAI()->SetData(DATA_PORTAL_PERIODIC_TICK, aurEff->GetTickNumber());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_violet_hold_portal_periodic_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_violet_hold_portal_periodic_AuraScript();
        }
};

// 62138 - Teleport to Inside Violet Hold
class spell_violet_hold_teleport_player : public SpellScriptLoader
{
    public:
        spell_violet_hold_teleport_player() : SpellScriptLoader("spell_violet_hold_teleport_player") { }

        class spell_violet_hold_teleport_player_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_violet_hold_teleport_player_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TELEPORT_PLAYER_EFFECT))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_TELEPORT_PLAYER_EFFECT, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_violet_hold_teleport_player_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_violet_hold_teleport_player_SpellScript();
        }
};

void AddSC_violet_hold()
{
    new npc_sinclari_vh();
    new npc_violet_hold_teleportation_portal();
    new npc_violet_hold_teleportation_portal_elite();
    new npc_violet_hold_teleportation_portal_intro();
    new npc_azure_invader();
    new npc_azure_spellbreaker();
    new npc_azure_binder();
    new npc_azure_mage_slayer();
    new npc_azure_captain();
    new npc_azure_sorceror();
    new npc_azure_raider();
    new npc_azure_stalker();
    new npc_azure_saboteur();
    new npc_violet_hold_defense_system();
    new go_activation_crystal();
    new spell_violet_hold_destroy_door_seal();
    new spell_violet_hold_portal_periodic();
    new spell_violet_hold_teleport_player();
}
