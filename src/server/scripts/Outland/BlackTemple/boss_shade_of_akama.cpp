/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Shade_of_Akama
SD%Complete: 90
SDComment: Seems to be complete.
SDCategory: Black Temple
EndScriptData */

#include "ScriptPCH.h"
#include "black_temple.h"

#define SAY_DEATH                   -1564013
#define SAY_LOW_HEALTH              -1564014
// Ending cinematic text
#define SAY_FREE                    -1564015
#define SAY_BROKEN_FREE_01          -1564016
#define SAY_BROKEN_FREE_02          -1564017

#define GOSSIP_ITEM                 "We are ready to fight alongside you, Akama"

struct Location
{
    float x, y, o, z;
};

static Location ChannelerLocations[]=
{
    {463.161285, 401.219757, 3.141592},
    {457.377625, 391.227661, 2.106461},
    {446.012421, 391.227661, 1.071904},
    {439.533783, 401.219757, 0.000000},
    {446.012421, 411.211853, 5.210546},
    {457.377625, 411.211853, 4.177494}
};

static Location SpawnLocations[]=
{
    {498.652740, 461.728119, 0},
    {498.505003, 339.619324, 0}
};

static Location AkamaWP[]=
{
    {482.352448, 401.162720, 0, 112.783928},
    {469.597443, 402.264404, 0, 118.537910}
};

static Location BrokenCoords[]=
{
    {541.375916, 401.439575, M_PI, 112.783997},             // The place where Akama channels
    {534.130005, 352.394531, 2.164150, 112.783737},         // Behind a 'pillar' which is behind the east alcove
    {499.621185, 341.534729, 1.652856, 112.783730},         // East Alcove
    {499.151093, 461.036438, 4.770888, 112.78370},          // West Alcove
};

static Location BrokenWP[]=
{
    {492.491638, 400.744690, 3.122336, 112.783737},
    {494.335724, 382.221771, 2.676230, 112.783737},
    {489.555939, 373.507202, 2.416263, 112.783737},
    {491.136353, 427.868774, 3.519748, 112.783737},
};

// Locations
#define Z1              118.543144
#define Z2              120.783768
#define Z_SPAWN         113.537949
#define AGGRO_X         482.793182
#define AGGRO_Y         401.270172
#define AGGRO_Z         112.783928
#define AKAMA_X         514.583984
#define AKAMA_Y         400.601013
#define AKAMA_Z         112.783997

// Spells
#define SPELL_VERTEX_SHADE_BLACK    39833
#define SPELL_SHADE_SOUL_CHANNEL    40401
#define SPELL_DESTRUCTIVE_POISON    40874
#define SPELL_LIGHTNING_BOLT        42024
#define SPELL_AKAMA_SOUL_CHANNEL    40447
#define SPELL_AKAMA_SOUL_RETRIEVE   40902
#define AKAMA_SOUL_EXPEL            40855
#define SPELL_SHADE_SOUL_CHANNEL_2  40520

// Channeler entry
#define CREATURE_CHANNELER          23421
#define CREATURE_SORCERER           23215
#define CREATURE_DEFENDER           23216
#define CREATURE_BROKEN             23319

const uint32 spawnEntries[4]= { 23523, 23318, 23524 };
class mob_ashtongue_channeler : public CreatureScript
{
public:
    mob_ashtongue_channeler() : CreatureScript("mob_ashtongue_channeler") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_ashtongue_channelerAI (pCreature);
    }

    struct mob_ashtongue_channelerAI : public ScriptedAI
    {
        mob_ashtongue_channelerAI(Creature* c) : ScriptedAI(c) {ShadeGUID = 0;}

        uint64 ShadeGUID;

        void Reset() {}
        void JustDied(Unit* /*killer*/);
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(const uint32 /*diff*/) {}
    };

};
class mob_ashtongue_sorcerer : public CreatureScript
{
public:
    mob_ashtongue_sorcerer() : CreatureScript("mob_ashtongue_sorcerer") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_ashtongue_sorcererAI (pCreature);
    }

    struct mob_ashtongue_sorcererAI : public ScriptedAI
    {
        mob_ashtongue_sorcererAI(Creature* c) : ScriptedAI(c) {ShadeGUID = 0;}

        uint64 ShadeGUID;
        uint32 CheckTimer;
        bool StartBanishing;

        void Reset()
        {
            StartBanishing = false;
            CheckTimer = 5000;
        }

        void JustDied(Unit* /*killer*/);
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(const uint32 diff)
        {
            if (StartBanishing)
                return;

            if (CheckTimer <= diff)
            {
                Creature* Shade = Unit::GetCreature((*me), ShadeGUID);
                if (Shade && Shade->isAlive() && me->isAlive())
                {
                    if (me->IsWithinDist(Shade, 20,false))
                    {
                        me->GetMotionMaster()->Clear(false);
                        me->GetMotionMaster()->MoveIdle();
                        DoCast(Shade, SPELL_SHADE_SOUL_CHANNEL, true);
                        DoCast(Shade, SPELL_SHADE_SOUL_CHANNEL_2, true);

                        StartBanishing = true;
                    }
                }
                CheckTimer = 2000;
            } else CheckTimer -= diff;
        }
    };

};
class boss_shade_of_akama : public CreatureScript
{
public:
    boss_shade_of_akama() : CreatureScript("boss_shade_of_akama") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_shade_of_akamaAI (pCreature);
    }

    struct boss_shade_of_akamaAI : public ScriptedAI
    {
        boss_shade_of_akamaAI(Creature* c) : ScriptedAI(c), summons(me)
        {
            pInstance = c->GetInstanceScript();
            AkamaGUID = pInstance ? pInstance->GetData64(DATA_AKAMA_SHADE) : 0;
            me->setActive(true);//if view distance is too low
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
        }

        InstanceScript* pInstance;

        std::list<uint64> Channelers;
        std::list<uint64> Sorcerers;
        uint64 AkamaGUID;

        uint32 SorcererCount;
        uint32 DeathCount;

        uint32 ReduceHealthTimer;
        uint32 SummonTimer;
        uint32 ResetTimer;
        uint32 DefenderTimer;                                   // They are on a flat 15 second timer, independant of the other summon Creature timer.

        bool IsBanished;
        bool HasKilledAkama;
        bool reseting;
        bool GridSearcherSucceeded;
        bool HasKilledAkamaAndReseting;
        SummonList summons;

        void Reset()
        {
            reseting = true;
            HasKilledAkamaAndReseting = false;

            GridSearcherSucceeded = false;

            Sorcerers.clear();
            summons.DespawnAll();//despawn all adds

            if (Creature* Akama = Unit::GetCreature(*me, AkamaGUID))
            {
                Akama->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);//turn gossip on so players can restart the event
                if (Akama->isDead())
                {
                    Akama->Respawn();//respawn akama if dead
                    Akama->AI()->EnterEvadeMode();
                }
            }
            SorcererCount = 0;
            DeathCount = 0;

            SummonTimer = 10000;
            ReduceHealthTimer = 0;
            ResetTimer = 60000;
            DefenderTimer = 15000;

            IsBanished = true;
            HasKilledAkama = false;

            me->SetVisibility(VISIBILITY_ON);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //me->GetMotionMaster()->Clear();
            //me->GetMotionMaster()->MoveIdle();
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STUN);

            if (pInstance)
                pInstance->SetData(DATA_SHADEOFAKAMAEVENT, NOT_STARTED);

            reseting = false;
        }
        void JustDied(Unit* /*killer*/)
        {
            summons.DespawnAll();
        }
        void JustSummoned(Creature *summon)
        {
            if (summon->GetEntry() == CREATURE_DEFENDER || summon->GetEntry() == 23523 || summon->GetEntry() == 23318 || summon->GetEntry() == 23524)
                summons.Summon(summon);
        }
        void SummonedCreatureDespawn(Creature *summon)
        {
            if (summon->GetEntry() == CREATURE_DEFENDER || summon->GetEntry() == 23523 || summon->GetEntry() == 23318 || summon->GetEntry() == 23524)
                summons.Despawn(summon);
        }

        void MoveInLineOfSight(Unit * /*who*/)
        {
            if (!GridSearcherSucceeded)
            {
                FindChannelers();

                if (!Channelers.empty())
                {
                    for (std::list<uint64>::const_iterator itr = Channelers.begin(); itr != Channelers.end(); ++itr)
                    {
                        Creature* Channeler = (Unit::GetCreature(*me, *itr));
                        if (Channeler)
                        {
                            if (Channeler->isDead())
                            {
                                Channeler->RemoveCorpse();
                                Channeler->Respawn();
                            }

                            Channeler->CastSpell(me, SPELL_SHADE_SOUL_CHANNEL, true);
                            Channeler->CastSpell(me, SPELL_SHADE_SOUL_CHANNEL_2, true);
                            Channeler->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            GridSearcherSucceeded = true;
                        }
                    }
                } else sLog.outError("SD2 ERROR: No Channelers are stored in the list. This encounter will not work properly");
            }
        }

        void AttackStart(Unit* who)
        {
            if (!who || IsBanished) return;

            if (who->isTargetableForAttack() && who != me)
                DoStartMovement(who);
        }

        void IncrementDeathCount(uint64 guid = 0)               // If guid is set, will remove it from list of sorcerer
        {
            if (reseting)
                return;

            sLog.outDebug("TSCR: Increasing Death Count for Shade of Akama encounter");
            ++DeathCount;
            me->RemoveAuraFromStack(SPELL_SHADE_SOUL_CHANNEL_2);
            if (guid)
            {
                if (Sorcerers.empty())
                    sLog.outError("SD2 ERROR: Shade of Akama - attempt to remove guid %u from Sorcerers list but list is already empty", guid);
                else  Sorcerers.remove(guid);
            }
        }

        void SummonCreature()
        {
            uint32 random = rand()%2;
            float X = SpawnLocations[random].x;
            float Y = SpawnLocations[random].y;
            // max of 6 sorcerers can be summoned
            if ((rand()%3 == 0) && (DeathCount > 0) && (SorcererCount < 7))
            {
                Creature* Sorcerer = me->SummonCreature(CREATURE_SORCERER, X, Y, Z_SPAWN, 0, TEMPSUMMON_DEAD_DESPAWN, 0);
                if (Sorcerer)
                {
                    CAST_AI(mob_ashtongue_sorcerer::mob_ashtongue_sorcererAI, Sorcerer->AI())->ShadeGUID = me->GetGUID();
                    Sorcerer->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    Sorcerer->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    Sorcerer->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                    Sorcerers.push_back(Sorcerer->GetGUID());
                    --DeathCount;
                    ++SorcererCount;
                }
            }
            else
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    Creature* Spawn = me->SummonCreature(spawnEntries[i], X, Y, Z_SPAWN, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 25000);
                    if (Spawn)
                    {
                        Spawn->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        Spawn->GetMotionMaster()->MovePoint(0, AGGRO_X, AGGRO_Y, AGGRO_Z);
                        Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1);
                        Spawn->AI()->AttackStart(pTarget);
                    }
                }
            }
        }

        void FindChannelers()
        {
            std::list<Creature*> ChannelerList;
            me->GetCreatureListWithEntryInGrid(ChannelerList,CREATURE_CHANNELER,50.0f);

            if (!ChannelerList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = ChannelerList.begin(); itr != ChannelerList.end(); ++itr)
                {
                    CAST_AI(mob_ashtongue_channeler::mob_ashtongue_channelerAI, (*itr)->AI())->ShadeGUID = me->GetGUID();
                    Channelers.push_back((*itr)->GetGUID());
                    sLog.outDebug("TSCR: Shade of Akama Grid Search found channeler %u. Adding to list", (*itr)->GetGUID());
                }
            }
            else sLog.outError("SD2 ERROR: Grid Search was unable to find any channelers. Shade of Akama encounter will be buggy");
        }

        void SetSelectableChannelers()
        {
            if (Channelers.empty())
            {
                sLog.outError("SD2 ERROR: Channeler List is empty, Shade of Akama encounter will be buggy");
                return;
            }

            for (std::list<uint64>::const_iterator itr = Channelers.begin(); itr != Channelers.end(); ++itr)
                if (Creature* Channeler = (Unit::GetCreature(*me, *itr)))
                    Channeler->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void SetAkamaGUID(uint64 guid) { AkamaGUID = guid; }

        void UpdateAI(const uint32 diff)
        {
            if (!me->isInCombat())
                return;

            if (IsBanished)
            {
                // Akama is set in the threatlist so when we reset, we make sure that he is not included in our check
                if (me->getThreatManager().getThreatList().size() < 2)
                {
                    EnterEvadeMode();
                    return;
                }

                if (DefenderTimer <= diff)
                {
                    uint32 ran = rand()%2;
                    Creature* Defender = me->SummonCreature(CREATURE_DEFENDER, SpawnLocations[ran].x, SpawnLocations[ran].y, Z_SPAWN, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 25000);
                    if (Defender)
                    {
                        Defender->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        bool move = true;
                        if (AkamaGUID)
                        {
                            if (Creature* Akama = Unit::GetCreature(*me, AkamaGUID))
                            {
                                float x, y, z;
                                Akama->GetPosition(x,y,z);
                                // They move towards AKama
                                Defender->GetMotionMaster()->MovePoint(0, x, y, z);
                                Defender->AI()->AttackStart(Akama);
                            } else move = false;
                        } else move = false;
                        if (!move)
                            Defender->GetMotionMaster()->MovePoint(0, AKAMA_X, AKAMA_Y, AKAMA_Z);
                    }
                    DefenderTimer = 15000;
                } else DefenderTimer -= diff;

                if (SummonTimer <= diff)
                {
                    SummonCreature();
                    SummonTimer = 35000;
                } else SummonTimer -= diff;

                if (DeathCount >= 6)
                {
                    if (AkamaGUID)
                    {
                        Creature* Akama = Unit::GetCreature((*me), AkamaGUID);
                        if (Akama && Akama->isAlive())
                        {
                            IsBanished = false;
                            me->GetMotionMaster()->Clear(false);
                            me->GetMotionMaster()->MoveChase(Akama);
                            Akama->GetMotionMaster()->Clear();
                            // Shade should move to Akama, not the other way around
                            Akama->GetMotionMaster()->MoveIdle();
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            // Crazy amount of threat
                            me->AddThreat(Akama, 10000000.0f);
                            Akama->AddThreat(me, 10000000.0f);
                            me->Attack(Akama, true);
                            Akama->Attack(me, true);
                        }
                    }
                }
            }
            else                                                // No longer banished, let's fight Akama now
            {
                if (ReduceHealthTimer <= diff)
                {
                    if (AkamaGUID)
                    {
                        Creature* Akama = Unit::GetCreature((*me), AkamaGUID);
                        if (Akama && Akama->isAlive())
                        {
                            //10 % less health every few seconds.
                            me->DealDamage(Akama, Akama->GetMaxHealth()/10, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                            ReduceHealthTimer = 12000;
                        }
                    }
                } else ReduceHealthTimer -= diff;

                if (HasKilledAkama)
                {
                    if (!HasKilledAkamaAndReseting)//do not let players kill Shade if Akama is dead and Shade is waiting for ResetTimer!! event would bug
                    {
                        HasKilledAkamaAndReseting = true;
                        me->RemoveAllAuras();
                        me->DeleteThreatList();
                        me->CombatStop();
                        //me->SetHealth(me->GetMaxHealth());
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->GetMotionMaster()->MoveTargetedHome();
                    }
                    if (ResetTimer <= diff)
                    {
                        EnterEvadeMode();// Reset a little while after killing Akama, evade and respawn Akama
                        return;
                    } else ResetTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        }
    };

};
void mob_ashtongue_channeler::mob_ashtongue_channelerAI::JustDied(Unit* /*killer*/)
{
    Creature* Shade = (Unit::GetCreature((*me), ShadeGUID));
    if (Shade && Shade->isAlive())
        CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->IncrementDeathCount();
    else sLog.outError("SD2 ERROR: Channeler dead but unable to increment DeathCount for Shade of Akama.");
}

void mob_ashtongue_sorcerer::mob_ashtongue_sorcererAI::JustDied(Unit* /*killer*/)
{
    Creature* Shade = (Unit::GetCreature((*me), ShadeGUID));
    if (Shade && Shade->isAlive())
        CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->IncrementDeathCount(me->GetGUID());
    else sLog.outError("SD2 ERROR: Sorcerer dead but unable to increment DeathCount for Shade of Akama.");
}class npc_akama_shade : public CreatureScript
{
public:
    npc_akama_shade() : CreatureScript("npc_akama_shade") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)               //Fight time
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_akama_shade::npc_akamaAI, pCreature->AI())->BeginEvent(pPlayer);
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->isAlive())
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_akamaAI (pCreature);
    }

    struct npc_akamaAI : public ScriptedAI
    {
        npc_akamaAI(Creature* c) : ScriptedAI(c), summons(me)
        {
            ShadeHasDied = false;
            StartCombat = false;
            pInstance = c->GetInstanceScript();
            ShadeGUID = pInstance ? pInstance->GetData64(DATA_SHADEOFAKAMA) : NOT_STARTED;
            me->setActive(true);
            EventBegun = false;
            CastSoulRetrieveTimer = 0;
            SoulRetrieveTimer = 0;
            SummonBrokenTimer = 0;
            EndingTalkCount = 0;
            WayPointId = 0;
            BrokenSummonIndex = 0;
            BrokenList.clear();
            HasYelledOnce = false;
        }

        InstanceScript* pInstance;

        uint64 ShadeGUID;

        uint32 DestructivePoisonTimer;
        uint32 LightningBoltTimer;
        uint32 CheckTimer;
        uint32 CastSoulRetrieveTimer;
        uint32 SoulRetrieveTimer;
        uint32 SummonBrokenTimer;
        uint32 EndingTalkCount;
        uint32 WayPointId;
        uint32 BrokenSummonIndex;

        std::list<uint64> BrokenList;

        bool EventBegun;
        bool ShadeHasDied;
        bool StartCombat;
        bool HasYelledOnce;
        SummonList summons;

        void Reset()
        {
            DestructivePoisonTimer = 15000;
            LightningBoltTimer = 10000;
            CheckTimer = 2000;

            if (!EventBegun)
            {
                me->SetUInt32Value(UNIT_NPC_FLAGS, 0);      // Database sometimes has very very strange values
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
            summons.DespawnAll();
        }

        void JustSummoned(Creature *summon)
        {
            if (summon->GetEntry() == CREATURE_BROKEN)
                summons.Summon(summon);
        }
        void SummonedCreatureDespawn(Creature *summon)
        {
            if (summon->GetEntry() == CREATURE_BROKEN)
                summons.Despawn(summon);
        }

        void EnterCombat(Unit* /*who*/) {}

        void BeginEvent(Player* pl)
        {
            if (!pInstance)
                return;

            ShadeGUID = pInstance->GetData64(DATA_SHADEOFAKAMA);
            if (!ShadeGUID)
                return;

            Creature* Shade = (Unit::GetCreature((*me), ShadeGUID));
            if (Shade)
            {
                pInstance->SetData(DATA_SHADEOFAKAMAEVENT, IN_PROGRESS);
                // Prevent players from trying to restart event
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->SetAkamaGUID(me->GetGUID());
                CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->SetSelectableChannelers();
                Shade->AddThreat(me, 1000000.0f);
                me->CombatStart(Shade);
                Shade->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                Shade->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                if (pl) Shade->AddThreat(pl, 1.0f);
                DoZoneInCombat(Shade);
                EventBegun = true;
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch(id)
            {
            case 0: ++WayPointId; break;

            case 1:
                if (Creature* Shade = Unit::GetCreature(*me, ShadeGUID))
                {
                    me->SetUInt64Value(UNIT_FIELD_TARGET, ShadeGUID);
                    DoCast(Shade, SPELL_AKAMA_SOUL_RETRIEVE);
                    EndingTalkCount = 0;
                    SoulRetrieveTimer = 16000;
                }
                break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            EventBegun = false;
            ShadeHasDied = false;
            StartCombat = false;
            CastSoulRetrieveTimer = 0;
            SoulRetrieveTimer = 0;
            SummonBrokenTimer = 0;
            EndingTalkCount = 0;
            WayPointId = 0;
            BrokenSummonIndex = 0;
            BrokenList.clear();
            HasYelledOnce = false;
            Creature* Shade = Unit::GetCreature((*me), ShadeGUID);
            if (Shade && Shade->isAlive())
                CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->HasKilledAkama = true;
            summons.DespawnAll();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!EventBegun)
                return;

            if ((me->GetHealth()*100 / me->GetMaxHealth()) < 15 && !HasYelledOnce)
            {
                DoScriptText(SAY_LOW_HEALTH, me);
                HasYelledOnce = true;
            }

            if (ShadeGUID && !StartCombat)
            {
                Creature* Shade = (Unit::GetCreature((*me), ShadeGUID));
                if (Shade && Shade->isAlive())
                {
                    if (CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->IsBanished)
                    {
                        if (CastSoulRetrieveTimer <= diff)
                        {
                            DoCast(Shade, SPELL_AKAMA_SOUL_CHANNEL);
                            CastSoulRetrieveTimer = 500;
                        } else CastSoulRetrieveTimer -= diff;
                    }
                    else
                    {
                        me->InterruptNonMeleeSpells(false);
                        StartCombat = true;
                    }
                }
            }

            if (ShadeHasDied && (WayPointId == 1))
            {
                if (pInstance)
                    pInstance->SetData(DATA_SHADEOFAKAMAEVENT, DONE);
                me->GetMotionMaster()->MovePoint(WayPointId, AkamaWP[1].x, AkamaWP[1].y, AkamaWP[1].z);
                ++WayPointId;
            }

            if (!ShadeHasDied && StartCombat)
            {
                if (CheckTimer <= diff)
                {
                    if (ShadeGUID)
                    {
                        Creature* Shade = Unit::GetCreature((*me), ShadeGUID);
                        if (Shade && !Shade->isAlive())
                        {
                            ShadeHasDied = true;
                            WayPointId = 0;
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            me->GetMotionMaster()->MovePoint(WayPointId, AkamaWP[0].x, AkamaWP[0].y, AkamaWP[0].z);
                        }
                        if (Shade && Shade->isAlive())
                        {
                            if (Shade->getThreatManager().getThreatList().size() < 2)
                                Shade->AI()->EnterEvadeMode();
                        }
                    }
                    CheckTimer = 5000;
                } else CheckTimer -= diff;
            }

            if (SummonBrokenTimer && BrokenSummonIndex < 4)
            {
                if (SummonBrokenTimer <= diff)
                {
                    for (uint8 i = 0; i < 4; ++i)
                    {
                        float x = BrokenCoords[BrokenSummonIndex].x + (i*5);
                        float y = BrokenCoords[BrokenSummonIndex].y + (1*5);
                        float z = BrokenCoords[BrokenSummonIndex].z;
                        float o = BrokenCoords[BrokenSummonIndex].o;
                        Creature* Broken = me->SummonCreature(CREATURE_BROKEN, x, y, z, o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 360000);
                        if (Broken)
                        {
                            float wx = BrokenWP[BrokenSummonIndex].x + (i*5);
                            float wy = BrokenWP[BrokenSummonIndex].y + (i*5);
                            float wz = BrokenWP[BrokenSummonIndex].z;
                            Broken->GetMotionMaster()->MovePoint(0, wx, wy, wz);
                            Broken->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            BrokenList.push_back(Broken->GetGUID());
                        }
                    }
                    ++BrokenSummonIndex;
                    SummonBrokenTimer = 1000;
                } else SummonBrokenTimer -= diff;
            }

            if (SoulRetrieveTimer)
                if (SoulRetrieveTimer <= diff)
                {
                    switch(EndingTalkCount)
                    {
                    case 0:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        ++EndingTalkCount;
                        SoulRetrieveTimer = 2000;
                        SummonBrokenTimer = 1;
                        break;
                    case 1:
                        DoScriptText(SAY_FREE, me);
                        ++EndingTalkCount;
                        SoulRetrieveTimer = 25000;
                        break;
                    case 2:
                        if (!BrokenList.empty())
                        {
                            bool Yelled = false;
                            for (std::list<uint64>::const_iterator itr = BrokenList.begin(); itr != BrokenList.end(); ++itr)
                                if (Creature* pUnit = Unit::GetCreature(*me, *itr))
                                {
                                    if (!Yelled)
                                    {
                                        DoScriptText(SAY_BROKEN_FREE_01, pUnit);
                                        Yelled = true;
                                    }
                                    pUnit->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                                }
                        }
                        ++EndingTalkCount;
                        SoulRetrieveTimer = 1500;
                        break;
                    case 3:
                        if (!BrokenList.empty())
                        {
                            for (std::list<uint64>::const_iterator itr = BrokenList.begin(); itr != BrokenList.end(); ++itr)
                                if (Creature* pUnit = Unit::GetCreature(*me, *itr))
                                    // This is the incorrect spell, but can't seem to find the right one.
                                    pUnit->CastSpell(pUnit, 39656, true);
                        }
                        ++EndingTalkCount;
                        SoulRetrieveTimer = 5000;
                        break;
                    case 4:
                        if (!BrokenList.empty())
                        {
                            for (std::list<uint64>::const_iterator itr = BrokenList.begin(); itr != BrokenList.end(); ++itr)
                                if (Creature* pUnit = Unit::GetCreature((*me), *itr))
                                    pUnit->MonsterYell(SAY_BROKEN_FREE_02, LANG_UNIVERSAL, 0);
                        }
                        SoulRetrieveTimer = 0;
                        break;
                    }
                } else SoulRetrieveTimer -= diff;

            if (!UpdateVictim())
                return;

            if (DestructivePoisonTimer <= diff)
            {
                Creature* Shade = Unit::GetCreature((*me), ShadeGUID);
                if (Shade && Shade->isAlive())
                    DoCast(Shade, SPELL_DESTRUCTIVE_POISON);
                DestructivePoisonTimer = 15000;
            } else DestructivePoisonTimer -= diff;

            if (LightningBoltTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_LIGHTNING_BOLT);
                LightningBoltTimer = 10000;
            } else LightningBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};



void AddSC_boss_shade_of_akama()
{
    new boss_shade_of_akama();
    new mob_ashtongue_channeler();
    new mob_ashtongue_sorcerer();
    new npc_akama_shade();
}
