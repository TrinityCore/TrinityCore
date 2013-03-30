/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "icecrown_citadel.h"


enum TrashSpells
{
    //Quest Spell
    SPELL_SOUL_FEAST_ALL                    = 71203,

//----------LOWER SPIRE----------//
    //Nerub'ar Broodkeeper
    SPELL_CRYPTSCARABS                      = 70965,
    SPELL_DARKMENDING                       = 71020,
    SPELL_WEBWRAP                           = 70980,

    //Servant of the Throne
    SPELL_GLACIALBLAST                      = 71029,

    //Ancient Skeletal Soldier
    SPELL_SHIELDBASH                        = 70964,

    //Deathbound Ward
    SPELL_DISRUPTINGSHOUT                   = 71022,
    SPELL_SABERLASH                         = 71021,

    //Deathspeaker Attendant
    SPELL_SHADOWBOLT                        = 69387,
    SPELL_SHADOWNOVA_10N                    = 69355,
    SPELL_SHADOWNOVA_25N                    = 71106,

    //Deathspeaker Disciple
    SPELL_DARKBLESSING                      = 69391,
    SPELL_SHADOWBOLT2                       = 69387,
    SPELL_SHADOWMEND_10N                    = 69389,
    SPELL_SHADOWMEND_25N                    = 71107,

    //Deathspeaker High Priest
    SPELL_AURAOFDARKNESS                    = 69491,
    SPELL_DARKRECKONING                     = 69483,
    SPELL_DARKRECKONING_EFFECT              = 69482,

    //Deathspeaker Servant
    SPELL_CHAOSBOLT_10N                     = 69576,
    SPELL_CHAOSBOLT_25N                     = 71108,
    SPELL_CONSUMINGSHADOWS                  = 69405,
    SPELL_CURSEOFAGONY_10N                  = 69404,
    SPELL_CURSEOFAGONY_25N                  = 71112,

    //Deathspeaker Zealot
    SPELL_SHADOWCLEAVE                      = 69492,

//----------UPPER SPIRE----------//
    //Valkyr Herald
    SPELL_SEVERED_ESSENCE_10N               = 71906,
    SPELL_SEVERED_ESSENCE_25N               = 71942,

//----------PLAGUE WORKS----------//
    //Blighted Abomination
    SPELL_CLEAVE                            = 40504,
    SPELL_PLAGUE_CLOUD                      = 71150,
    SPELL_SCOURGE_HOOK                      = 71140,

    //Vengeful Fleshreaper
    SPELL_LEAPING_FACE_MAUL                 = 71164,
    SPELL_DEVOUR_HUMANOID                   = 71164,

    //Plague Scientist
    SPELL_PLAGUE_BLAST                      = 73079,
    SPELL_PLAGUE_STREAM                     = 69871,
    SPELL_COMBOBULATING_SPRAY               = 71103,

    //Pustulating Horror
    SPELL_BLIGHT_BOMB                       = 71088,
    SPELL_BUBBLING_PUS_10N                  = 71089,
    SPELL_BUBBLING_PUS_25N                  = 71090,

    //Decaying Colossus
    SPELL_MASSIVE_STOMP_10N                 = 71114,
    SPELL_MASSIVE_STOMP_25N                 = 71115,

//----------SANCTUARY OF BLOOD----------//
    //Darkfallen Archmage
    SPELL_AMPLIFY_MAGIC_10N                 = 70408,
    SPELL_AMPLIFY_MAGIC_25N                 = 72336,
    SPELL_BLAST_WAVE_10N                    = 70407,
    SPELL_BLAST_WAVE_25N                    = 71151,
    SPELL_FIREBALL_10N                      = 70409,
    SPELL_FIREBALL_25N                      = 71153,
    SPELL_POLYMORPH_SPIDER                  = 70410,
    SPELL_SIPHON_ESSENCE                    = 70299,

    //Darkfallen Blood Knight
    SPELL_VAMPIRIC_AURA                     = 71736,
    SPELL_UNHOLY_STRIKE                     = 70437,
    SPELL_BLOOD_MIRROR_DAMAGE               = 70445,
    SPELL_BLOOD_MIRROR_BUFF                 = 70451,
    SPELL_BLOOD_MIRROR_DUMMY                = 70450,

    //Darkfallen Noble
    SPELL_CHAINS_OF_SHADOW                  = 70645,
    SPELL_SHADOW_BOLT_10N                   = 72960,
    SPELL_SHADOW_BOLT_25N                   = 72961,

    //Vampiric Fiend
    SPELL_DISEASE_CLOUD                     = 41290,
    SPELL_LEECHING_ROT                      = 70671,

    //Darkfallen Advisor
    SPELL_LICH_SLAP_10N                     = 72057,
    SPELL_LICH_SLAP_25N                     = 72421,
    SPELL_SHROUD_OF_PROTECTION              = 72065,
    SPELL_SHROUD_OF_SPELL_WARDING           = 72066,

    //Darkfallen Commander
    SPELL_VAMPIRE_RUSH_10N                  = 70449,
    SPELL_VAMPIRE_RUSH_25N                  = 71155,
    SPELL_BATTLE_SHOUT                      = 70750,

    //Darkfallen Lieutenant
    SPELL_VAMPIRIC_CURSE                    = 70423,
    SPELL_REND_FLESH_10N                    = 70435,
    SPELL_REND_FLESH_25N                    = 71154,

    //Darkfallen Tactician
    SPELL_SHADOWSTEP                        = 70431,
    SPELL_BLOOD_SAP                         = 70432,
};

enum TrashEvents
{
    //Nerub'ar Broodkeeper
    EVENT_CRYPTSCARABS          = 1,
    EVENT_DARKMENDING           = 2,
    EVENT_WEBWRAP               = 3,

    //The Damned
    EVENT_BONEFLURRY            = 4,
    EVENT_SHATTEREDBONES        = 5,

    //Servant of the Throne
    EVENT_GLACIALBLAST          = 6,

    //Ancient Skeletal Soldier
    EVENT_SHIELDBASH            = 7,

    //Deathbound Ward
    EVENT_DISRUPTINGSHOUT       = 8,
    EVENT_SABERLASH             = 9,

    //Deathspeaker Attendant
    EVENT_SHADOWBOLT            = 10,
    EVENT_SHADOWNOVA            = 11,

    //Deathspeaker Disciple
    EVENT_SHADOWBOLT2           = 12,
    EVENT_DARKBLESSING          = 13,
    EVENT_SHADOWMEND            = 14,

    //Deathspeaker High Priest
    EVENT_DARKRECKONING         = 15,
    EVENT_DARKRECKONING_EFFECT  = 16,

    //Deathspeaker Servant
    EVENT_CHAOSBOLT             = 17,
    EVENT_CONSUMINGSHADOWS      = 18,
    EVENT_CURSEOFAGONY          = 19,

    //Deathspeaker Zealot
    EVENT_SHADOWCLEAVE          = 20,
};

//----------LOWER SPIRE----------//
class npc_NerubarBroodkeeper : public CreatureScript
{
public:
    npc_NerubarBroodkeeper() : CreatureScript("npc_NerubarBroodkeeper") { }
    struct npc_NerubarBroodkeeperAI: public ScriptedAI
    {
        npc_NerubarBroodkeeperAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_CRYPTSCARABS, 10000);
            events.ScheduleEvent(EVENT_DARKMENDING, 17800);
            events.ScheduleEvent(EVENT_WEBWRAP, 12000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_CRYPTSCARABS:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_CRYPTSCARABS);
                        events.RescheduleEvent(EVENT_CRYPTSCARABS, 12000);
                        break;
                    case EVENT_DARKMENDING:
                        DoCast(me, SPELL_DARKMENDING);
                        events.RescheduleEvent(EVENT_DARKMENDING, 17800);
                        break;
                    case EVENT_WEBWRAP:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_WEBWRAP);

                        events.RescheduleEvent(EVENT_WEBWRAP, 15000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_NerubarBroodkeeperAI(pCreature);
    }
};

class npc_ServantoftheThrone : public CreatureScript
{
public:
    npc_ServantoftheThrone() : CreatureScript("npc_ServantoftheThrone") { }
    struct npc_ServantoftheThroneAI: public ScriptedAI
    {
        npc_ServantoftheThroneAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_GLACIALBLAST, 13000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_GLACIALBLAST:
                        DoCastAOE(SPELL_GLACIALBLAST);
                        events.RescheduleEvent(EVENT_GLACIALBLAST, 8000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ServantoftheThroneAI(pCreature);
    }
};

class npc_AncientSkeletalSoldier : public CreatureScript
{
public:
    npc_AncientSkeletalSoldier() : CreatureScript("npc_AncientSkeletalSoldier") { }
    struct npc_AncientSkeletalSoldierAI: public ScriptedAI
    {
        npc_AncientSkeletalSoldierAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_SHIELDBASH, 8000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SHIELDBASH:
                        DoCast(me->getVictim(), SPELL_SHIELDBASH);
                        events.RescheduleEvent(EVENT_SHIELDBASH, 8000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_AncientSkeletalSoldierAI(pCreature);
    }
};

class npc_DeathboundWard : public CreatureScript
{
public:
    npc_DeathboundWard() : CreatureScript("npc_DeathboundWard") { }
    struct npc_DeathboundWardAI: public ScriptedAI
    {
        npc_DeathboundWardAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_DISRUPTINGSHOUT, 8000);
            events.ScheduleEvent(EVENT_SABERLASH, 8000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_DISRUPTINGSHOUT:
                        DoCast(me, SPELL_DISRUPTINGSHOUT);
                        events.RescheduleEvent(EVENT_DISRUPTINGSHOUT, 8000);
                        break;
                    case EVENT_SABERLASH:
                        DoCast(me->getVictim(), SPELL_SABERLASH, true);
                        events.RescheduleEvent(EVENT_SABERLASH, 8000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_DeathboundWardAI(pCreature);
    }
};

class npc_DeathspeakerAttedant : public CreatureScript
{
public:
    npc_DeathspeakerAttedant() : CreatureScript("npc_DeathspeakerAttedant") { }
    struct npc_DeathspeakerAttedantAI: public ScriptedAI
    {
        npc_DeathspeakerAttedantAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_SHADOWBOLT, 8000);
            events.ScheduleEvent(EVENT_SHADOWNOVA, 23000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SHADOWBOLT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SHADOWBOLT);

                        events.RescheduleEvent(EVENT_SHADOWBOLT, 8000);
                        break;
                    case EVENT_SHADOWNOVA:
                        DoCastAOE(RAID_MODE(SPELL_SHADOWNOVA_10N, SPELL_SHADOWNOVA_25N, SPELL_SHADOWNOVA_10N, SPELL_SHADOWNOVA_25N));
                        events.RescheduleEvent(EVENT_SHADOWNOVA, 17000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_DeathspeakerAttedantAI(pCreature);
    }
};

class npc_DeathspeakerDisciple : public CreatureScript
{
public:
    npc_DeathspeakerDisciple() : CreatureScript("npc_DeathspeakerDisciple") { }
    struct npc_DeathspeakerDiscipleAI: public ScriptedAI
    {
        npc_DeathspeakerDiscipleAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_SHADOWBOLT2, 8000);
            events.ScheduleEvent(EVENT_DARKBLESSING, urand(15000, 25000));
            events.ScheduleEvent(EVENT_SHADOWMEND, urand(10000, 20000));
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_DARKBLESSING:
                        if(Unit* pTarget = DoSelectLowestHpFriendly(30.0f,1))
                            DoCast(pTarget, SPELL_DARKBLESSING);

                        events.RescheduleEvent(EVENT_DARKBLESSING, 20000);
                        break;
                    case EVENT_SHADOWBOLT2:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SHADOWBOLT2);

                        events.RescheduleEvent(EVENT_SHADOWBOLT2, 8000);
                        break;
                    case EVENT_SHADOWMEND:
                        if(Unit* pTarget = DoSelectLowestHpFriendly(40.0f,1))
                            DoCast(pTarget, RAID_MODE(SPELL_SHADOWMEND_10N, SPELL_SHADOWMEND_25N, SPELL_SHADOWMEND_10N, SPELL_SHADOWMEND_25N));

                        events.RescheduleEvent(EVENT_SHADOWMEND, 25000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_DeathspeakerDiscipleAI(pCreature);
    }
};

class npc_DeathspeakerHighPriest : public CreatureScript
{
public:
    npc_DeathspeakerHighPriest() : CreatureScript("npc_DeathspeakerHighPriest") { }
    struct npc_DeathspeakerHighPriestAI: public ScriptedAI
    {
        npc_DeathspeakerHighPriestAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        uint64 targetGuid;

        void Reset()
        {
            targetGuid = 0;
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_DARKRECKONING, 10000);
            events.ScheduleEvent(EVENT_DARKRECKONING_EFFECT, 19000);
            DoCast(me, SPELL_AURAOFDARKNESS);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_DARKRECKONING:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            targetGuid = pTarget->GetGUID();
                            DoCast(pTarget, SPELL_DARKRECKONING);
                        }

                        events.RescheduleEvent(EVENT_DARKRECKONING, 20000);
                        break;
                    case EVENT_DARKRECKONING_EFFECT:
                        if (targetGuid)
                            if (Unit *target = me->GetUnit((*me), targetGuid))
                                if (me->IsValidAttackTarget(target))
                                    DoCast(target, SPELL_DARKRECKONING_EFFECT);

                        events.RescheduleEvent(EVENT_DARKRECKONING_EFFECT, 20000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_DeathspeakerHighPriestAI(pCreature);
    }
};

class npc_DeathspeakerServant : public CreatureScript
{
public:
    npc_DeathspeakerServant() : CreatureScript("npc_DeathspeakerServant") { }
    struct npc_DeathspeakerServantAI: public ScriptedAI
    {
        npc_DeathspeakerServantAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_CHAOSBOLT, 15000);
            events.ScheduleEvent(EVENT_CONSUMINGSHADOWS, 13000);
            events.ScheduleEvent(EVENT_CURSEOFAGONY, 10000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_CHAOSBOLT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                           DoCast(pTarget, RAID_MODE(SPELL_CHAOSBOLT_10N, SPELL_CHAOSBOLT_25N, SPELL_CHAOSBOLT_10N, SPELL_CHAOSBOLT_25N));

                        events.RescheduleEvent(EVENT_CHAOSBOLT, 15000);
                        break;
                    case EVENT_CONSUMINGSHADOWS:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_CONSUMINGSHADOWS);

                        events.RescheduleEvent(EVENT_CONSUMINGSHADOWS, 13000);
                        break;
                    case EVENT_CURSEOFAGONY:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, RAID_MODE(SPELL_CURSEOFAGONY_10N, SPELL_CURSEOFAGONY_25N, SPELL_CURSEOFAGONY_10N, SPELL_CURSEOFAGONY_25N));

                        events.RescheduleEvent(EVENT_CURSEOFAGONY, 17000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_DeathspeakerServantAI(pCreature);
    }
};

class npc_DeathspeakerZealot : public CreatureScript
{
public:
    npc_DeathspeakerZealot() : CreatureScript("npc_DeathspeakerZealot") { }
    struct npc_DeathspeakerZealotAI: public ScriptedAI
    {
        npc_DeathspeakerZealotAI(Creature *c) : ScriptedAI(c)
        {
        }
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_SHADOWCLEAVE, 8000);
        }

        void UpdateAI(uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SHADOWCLEAVE:
                        DoCast(me->getVictim(), SPELL_SHADOWCLEAVE);
                        events.RescheduleEvent(EVENT_SHADOWCLEAVE, 8000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_DeathspeakerZealotAI (pCreature);
    }
};

class npc_valkyr_herald : public CreatureScript
{
    public:
        npc_valkyr_herald() : CreatureScript("npc_valkyr_herald") { }
 
        struct npc_valkyr_heraldAI : public ScriptedAI
        {
            npc_valkyr_heraldAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiESSENCE_Timer;

            void Reset()
            {
                m_uiESSENCE_Timer = 1000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiESSENCE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_SEVERED_ESSENCE_10N, SPELL_SEVERED_ESSENCE_25N, SPELL_SEVERED_ESSENCE_10N, SPELL_SEVERED_ESSENCE_25N));
                    m_uiESSENCE_Timer = urand(2000, 8000);
                }
                else
                    m_uiESSENCE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_valkyr_heraldAI(creature);
        }
};

class npc_blighted_abomination : public CreatureScript
{
    public:
        npc_blighted_abomination() : CreatureScript("npc_blighted_abomination") { }

        struct npc_blighted_abominationAI : public ScriptedAI
        {
            npc_blighted_abominationAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCLOUD_Timer;
            uint32 m_uiCLEAVE_Timer;
            uint32 m_uiHOOK_Timer;

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void Reset()
            {
                m_uiCLOUD_Timer = 10000;
                m_uiCLEAVE_Timer = 4000;
                m_uiHOOK_Timer = 5000;
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiCLOUD_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_PLAGUE_CLOUD);
                    m_uiCLOUD_Timer = 20000;
                }
                else
                    m_uiCLOUD_Timer -= uiDiff;

                if (m_uiHOOK_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SCOURGE_HOOK);

                    m_uiHOOK_Timer = urand(12000, 20000);
                }
                else
                    m_uiHOOK_Timer -= uiDiff;
 
                if (m_uiCLEAVE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CLEAVE);

                    m_uiCLEAVE_Timer = 6000;
                }
                else
                    m_uiCLEAVE_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_blighted_abominationAI(creature);
        }
};

class npc_vengeful_fleshreapert : public CreatureScript
{
    public:
        npc_vengeful_fleshreapert() : CreatureScript("npc_vengeful_fleshreapert") { }

        struct npc_vengeful_fleshreapertAI : public ScriptedAI
        {
            npc_vengeful_fleshreapertAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiJUMP_Timer;
            uint32 m_uiDEVOUR_Timer;

            void Reset()
            {
                m_uiJUMP_Timer = urand(3000, 20000);
                m_uiDEVOUR_Timer = urand(3000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiJUMP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_LEAPING_FACE_MAUL);

                    m_uiJUMP_Timer = urand(20000,40000);
                }
                else
                    m_uiJUMP_Timer -= uiDiff;

                if (m_uiDEVOUR_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_DEVOUR_HUMANOID);

                    m_uiDEVOUR_Timer = urand(5000,8000);
                }
                else
                    m_uiDEVOUR_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_vengeful_fleshreapertAI(creature);
        }
};

class npc_plague_scientist : public CreatureScript
{
    public:
        npc_plague_scientist() : CreatureScript("npc_plague_scientist") { }
 
        struct npc_plague_scientistAI : public ScriptedAI
        {
            npc_plague_scientistAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBLAST_Timer;
            uint32 m_uiSTREAM_Timer;
            uint32 m_uiSTREAM_OUT_Timer;
            uint32 m_uiSPRAY_Timer;    

            void Reset()
            {
                m_uiBLAST_Timer = 2000;
                m_uiSTREAM_Timer = urand(8000, 12000);
                m_uiSTREAM_OUT_Timer = 24000;
                m_uiSPRAY_Timer = urand(5000, 8000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTREAM_Timer <= uiDiff)
                {
                    if (m_uiSTREAM_OUT_Timer > uiDiff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_PLAGUE_STREAM);
                        // maximo 24 segs para que deje de castear
                        m_uiSTREAM_OUT_Timer -= uiDiff;
                    }
                    else
                    {
                        me->CastStop(SPELL_PLAGUE_STREAM);
                        // se repite de entre 15 a 20 segs
                        m_uiSTREAM_OUT_Timer = urand(15000, 20000);
                    }
                }
                else
                    m_uiSTREAM_Timer -= uiDiff;

                if (m_uiSPRAY_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_COMBOBULATING_SPRAY);
                    // cada 8 a 12 segs se repite
                    m_uiSPRAY_Timer = urand(8000, 12000);
                }
                else
                    m_uiSPRAY_Timer -= uiDiff;
 
                if (m_uiBLAST_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_PLAGUE_BLAST);
                    m_uiBLAST_Timer = urand(2000, 3000);
                }
                else
                    m_uiBLAST_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_plague_scientistAI(creature);
        }
};

class npc_pustulating_horror : public CreatureScript
{
    public:
        npc_pustulating_horror() : CreatureScript("npc_pustulating_horror") { }

        struct npc_pustulating_horrorAI : public ScriptedAI
        {
            npc_pustulating_horrorAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiPUS_Timer;

            void Reset()
            {
                m_uiPUS_Timer = 2000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (HealthBelowPct(15))
                {
                    DoCastAOE(SPELL_BLIGHT_BOMB);
                    m_uiPUS_Timer = 5000;
                }

                if (m_uiPUS_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                        DoCast(target, RAID_MODE(SPELL_BUBBLING_PUS_10N, SPELL_BUBBLING_PUS_25N, SPELL_BUBBLING_PUS_10N, SPELL_BUBBLING_PUS_25N));
                    if (HealthAbovePct(15))
                        m_uiPUS_Timer = urand(15000, 25000);
                }
                else
                    m_uiPUS_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_pustulating_horrorAI(creature);
        }
};

class npc_decaying_colossus : public CreatureScript
{
    public:
        npc_decaying_colossus() : CreatureScript("npc_decaying_colossus") { }

        struct npc_decaying_colossusAI : public ScriptedAI
        {
            npc_decaying_colossusAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiSTOMP_Timer;

            void Reset()
            {
                m_uiSTOMP_Timer = 5000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTOMP_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_MASSIVE_STOMP_10N, SPELL_MASSIVE_STOMP_25N, SPELL_MASSIVE_STOMP_10N, SPELL_MASSIVE_STOMP_25N));
                    m_uiSTOMP_Timer = urand(15000, 25000);
                }
                else
                    m_uiSTOMP_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_decaying_colossusAI(creature);
        }
};

class npc_darkfallen_archmage : public CreatureScript
{
    public:
        npc_darkfallen_archmage() : CreatureScript("npc_darkfallen_archmage") { }

        struct npc_darkfallen_archmageAI : public ScriptedAI
        {
            npc_darkfallen_archmageAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiAMPLIFY_Timer;
            uint32 m_uiBLAST_Timer;
            uint32 m_uiFIREBALL_Timer;
            uint32 m_uiPOLYMORPH_Timer;

            void Reset()
            {
                m_uiAMPLIFY_Timer = urand(10000, 15000);
                m_uiBLAST_Timer = urand(8000, 10000);
                m_uiFIREBALL_Timer = 2000;
                m_uiPOLYMORPH_Timer = urand(9000, 12000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiAMPLIFY_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_AMPLIFY_MAGIC_10N, SPELL_AMPLIFY_MAGIC_25N, SPELL_AMPLIFY_MAGIC_10N, SPELL_AMPLIFY_MAGIC_25N));
                    m_uiAMPLIFY_Timer = urand(15000, 20000);
                }
                else
                    m_uiAMPLIFY_Timer -= uiDiff;

                if (m_uiPOLYMORPH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_POLYMORPH_SPIDER);

                    m_uiPOLYMORPH_Timer = urand(15000, 18000);
                }
                else
                    m_uiPOLYMORPH_Timer -= uiDiff;

                if (m_uiFIREBALL_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_FIREBALL_10N, SPELL_FIREBALL_25N, SPELL_FIREBALL_10N, SPELL_FIREBALL_25N));
                    m_uiFIREBALL_Timer = urand(3000, 4000);
                }
                else
                    m_uiFIREBALL_Timer -= uiDiff;
 
                if (m_uiBLAST_Timer <= uiDiff)
                {
                    DoCastAOE(RAID_MODE(SPELL_BLAST_WAVE_10N, SPELL_BLAST_WAVE_25N, SPELL_BLAST_WAVE_10N, SPELL_BLAST_WAVE_25N));
                    m_uiBLAST_Timer = urand(10000, 20000);
                }
                else
                    m_uiBLAST_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_archmageAI(creature);
        }
};

class npc_darkfallen_blood_knight : public CreatureScript
{
    public:
        npc_darkfallen_blood_knight() : CreatureScript("npc_darkfallen_blood_knight") { }

        struct npc_darkfallen_blood_knightAI : public ScriptedAI
        {
            npc_darkfallen_blood_knightAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiAURA_Timer;
            uint32 m_uiSTRIKE_Timer;
            uint32 m_uiMIRROR_Timer;

            void Reset()
            {
                m_uiAURA_Timer = urand(12000, 15000);
                m_uiSTRIKE_Timer = urand(2000, 3000);
                m_uiMIRROR_Timer = urand(4000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTRIKE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_UNHOLY_STRIKE);
                    m_uiSTRIKE_Timer = urand(3000, 4000);
                }
                else
                    m_uiSTRIKE_Timer -= uiDiff;

                if (m_uiAURA_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_VAMPIRIC_AURA);
                    m_uiAURA_Timer = urand(12000, 15000);
                }
                else
                    m_uiAURA_Timer -= uiDiff;

                if (m_uiMIRROR_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoCast(me->getVictim(),SPELL_BLOOD_MIRROR_DUMMY);
                        me->getVictim()->CastSpell(target,SPELL_BLOOD_MIRROR_DAMAGE,true);
                        me->CastSpell(me->getVictim(),SPELL_BLOOD_MIRROR_BUFF,true);
                        m_uiMIRROR_Timer = urand(32000, 37000);
                    }
                }
                else
                    m_uiMIRROR_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_blood_knightAI(creature);
        }
};

enum Noblemisc
{
    NPC_VAMPIRIC_FIEND           = 37901,
};
class npc_darkfallen_noble : public CreatureScript
{
    public:
        npc_darkfallen_noble() : CreatureScript("npc_darkfallen_noble") { }
 
        struct npc_darkfallen_nobleAI : public ScriptedAI
        {
            npc_darkfallen_nobleAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCHAINS_Timer;
            uint32 m_uiBOLT_Timer;
            uint32 m_uiFIEND_Timer;

            void Reset()
            {
                m_uiCHAINS_Timer = urand(2000, 4000);
                m_uiBOLT_Timer = urand(3000, 5000);
                m_uiFIEND_Timer = 15000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_SHADOW_BOLT_10N, SPELL_SHADOW_BOLT_25N, SPELL_SHADOW_BOLT_10N, SPELL_SHADOW_BOLT_25N));
                    m_uiBOLT_Timer = urand(4000, 5000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiCHAINS_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHAINS_OF_SHADOW);

                    m_uiCHAINS_Timer = urand(20000, 25000);
                }
                else
                    m_uiCHAINS_Timer -= uiDiff;

                if (m_uiFIEND_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        if (me->SummonCreature(NPC_VAMPIRIC_FIEND,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ()))
                            m_uiFIEND_Timer = 60000;
                }
                else
                    m_uiFIEND_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_nobleAI(creature);
        }
};

class npc_vampiric_fiend : public CreatureScript
{
    public:
        npc_vampiric_fiend() : CreatureScript("npc_vampiric_fiend") { }

        struct npc_vampiric_fiendAI : public ScriptedAI
        {
            npc_vampiric_fiendAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiLEECHING_Timer;

            void Reset()
            {
                m_uiLEECHING_Timer = 10000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void EnterCombat(Unit* /*target*/)
            {
                DoCast(me, SPELL_DISEASE_CLOUD);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiLEECHING_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_LEECHING_ROT);
                    me->DespawnOrUnsummon(3000); 
                    m_uiLEECHING_Timer = 10000;
                }
                else
                    m_uiLEECHING_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_vampiric_fiendAI(creature);
        }
};

class npc_darkfallen_advisor : public CreatureScript
{
    public:
        npc_darkfallen_advisor() : CreatureScript("npc_darkfallen_advisor") { }
 
        struct npc_darkfallen_advisorAI : public ScriptedAI
        {
            npc_darkfallen_advisorAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiLICH_Timer;
            uint32 m_uiPROTECTION_Timer;

            void Reset()
            {
                m_uiLICH_Timer = urand(2000, 5000);
                m_uiPROTECTION_Timer = urand(10000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiLICH_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_LICH_SLAP_10N, SPELL_LICH_SLAP_25N, SPELL_LICH_SLAP_10N, SPELL_LICH_SLAP_25N));
                    m_uiLICH_Timer = 10000;
                }
                else
                    m_uiLICH_Timer -= uiDiff;

                if (m_uiPROTECTION_Timer <= uiDiff)
                {
                    if (Unit* target = urand(0, 1) ? SelectTarget(SELECT_TARGET_RANDOM, 0) : DoSelectLowestHpFriendly(40.0f))
                    {
                        DoCast(target,SPELL_SHROUD_OF_PROTECTION);
                        DoCast(target,SPELL_SHROUD_OF_SPELL_WARDING);
                        m_uiPROTECTION_Timer = urand(15000, 20000);
                    }
                }
                else
                    m_uiPROTECTION_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_advisorAI(creature);
        }
};

class npc_darkfallen_commander : public CreatureScript
{
    public:
        npc_darkfallen_commander() : CreatureScript("npc_darkfallen_commander") { }
 
        struct npc_darkfallen_commanderAI : public ScriptedAI
        {
            npc_darkfallen_commanderAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiRUSH_Timer;
            uint32 m_uiSHOUT_Timer;

            void Reset()
            {
                m_uiRUSH_Timer = urand(4000, 8000);
                m_uiSHOUT_Timer = urand(8000, 10000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSHOUT_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_BATTLE_SHOUT);
                    m_uiSHOUT_Timer = urand(15000, 20000);
                }
                else
                    m_uiSHOUT_Timer -= uiDiff;

                if (m_uiRUSH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, RAID_MODE(SPELL_VAMPIRE_RUSH_10N,SPELL_VAMPIRE_RUSH_25N ,SPELL_VAMPIRE_RUSH_10N ,SPELL_VAMPIRE_RUSH_25N));

                    m_uiRUSH_Timer = urand(10000, 15000);
                }
                else
                    m_uiRUSH_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_commanderAI(creature);
        }
};

class npc_darkfallen_lieutenant : public CreatureScript
{
    public:
        npc_darkfallen_lieutenant() : CreatureScript("npc_darkfallen_lieutenant") { }

        struct npc_darkfallen_lieutenantAI : public ScriptedAI
        {
            npc_darkfallen_lieutenantAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiREND_Timer;
            uint32 m_uiCURSE_Timer;

            void Reset()
            {
                m_uiREND_Timer = urand(1000, 2000);
                m_uiCURSE_Timer = urand(8000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me, SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiREND_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_REND_FLESH_10N, SPELL_REND_FLESH_25N, SPELL_REND_FLESH_10N, SPELL_REND_FLESH_25N));
                    m_uiREND_Timer = 25000;
                }
                else
                    m_uiREND_Timer -= uiDiff;

                if (m_uiCURSE_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_VAMPIRIC_CURSE);

                    m_uiCURSE_Timer = urand(10000, 20000);
                }
                else
                    m_uiCURSE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_lieutenantAI(creature);
        }
};

class npc_darkfallen_tactician : public CreatureScript
{
    public:
        npc_darkfallen_tactician() : CreatureScript("npc_darkfallen_tactician") { }

        struct npc_darkfallen_tacticianAI : public ScriptedAI
        {
            npc_darkfallen_tacticianAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiSHADOWSTEP_Timer;
            uint32 m_uiSAP_Timer;
            uint32 m_uiSTRIKE_Timer;

            void Reset()
            {
                m_uiSHADOWSTEP_Timer = urand(1000, 2000);
                m_uiSAP_Timer = urand(5000, 15000);
                m_uiSTRIKE_Timer = urand(2000, 3000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTRIKE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_UNHOLY_STRIKE);
                    m_uiSTRIKE_Timer = 6000;
                }
                else
                    m_uiSTRIKE_Timer -= uiDiff;

                if (m_uiSAP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BLOOD_SAP);

                    m_uiSAP_Timer = urand(15000, 25000);
                }
                else
                    m_uiSAP_Timer -= uiDiff;

                if (m_uiSHADOWSTEP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHADOWSTEP);

                    m_uiSHADOWSTEP_Timer = urand(15000, 20000);
                }
                else
                    m_uiSHADOWSTEP_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_tacticianAI(creature);
        }
};

/*
   Recuperador de anillos perdidos.
*/

#define GMSG 537006

class npc_icc_rep_rings : public CreatureScript
{
public:
    npc_icc_rep_rings() : CreatureScript("npc_icc_rep_rings") { }

    enum AshenRings
    {
        ASHEN_VERDICT = 1156,
        C_F = 50377,
        H_F = 50378,
        MS_F = 52569,
        MA_F = 50376,
        T_F = 50375,
        C_H = 50384,
        H_H = 50386,
        MS_H = 52570,
        MA_H = 50387,
        T_H = 50388,
        C_R = 50397,
        H_R = 50399,
        MS_R = 52571,
        MA_R = 50401,
        T_R = 50403,
        C_E = 50398,
        H_E = 50400,
        MS_E = 52572,
        MA_E = 50402,
        T_E = 50404,
        QUEST_CHOOSE_YOUR_PATH = 24815
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        uint32 friendly = 3000;
        uint32 honored = 9000;
        uint32 revered = 21000;
        uint32 exalted = 42000;
        uint32 value = player->GetReputation(ASHEN_VERDICT);

        if (value >= friendly && value < honored)
        {
            if (!player->HasItemCount(C_F,1) && !player->HasItemCount(H_F,1) && !player->HasItemCount(MS_F,1) && !player->HasItemCount(MA_F,1) &&
                !player->HasItemCount(T_F,1) && player->GetQuestStatus(QUEST_CHOOSE_YOUR_PATH) == QUEST_STATUS_COMPLETE)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring caster (Friendly)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring healer (Friendly)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - strength (Friendly)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+3);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - agility (Friendly)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+4);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring tank (Friendly)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(GMSG, creature->GetGUID());
                return true;
            }
        }

        if (value >= honored && value < revered)
        {
            if (!player->HasItemCount(C_F,1) && !player->HasItemCount(H_F,1) && !player->HasItemCount(MS_F,1) && !player->HasItemCount(MA_F,1) &&
                !player->HasItemCount(T_F,1) && !player->HasItemCount(C_H,1) && !player->HasItemCount(H_H,1) && !player->HasItemCount(MS_H,1) &&
                !player->HasItemCount(MA_H,1) && !player->HasItemCount(T_H,1))
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring caster (Honored)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+6);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring healer (Honored)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+7);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - strength (Honored)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+8);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - agility (Honored)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+9);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring tank (Honored)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+10);
                player->SEND_GOSSIP_MENU(GMSG, creature->GetGUID());
                return true;
            }
        }

        if (value >= revered && value < exalted)
        {
            if (!player->HasItemCount(C_F,1) && !player->HasItemCount(H_F,1) && !player->HasItemCount(MS_F,1) && !player->HasItemCount(MA_F,1) &&
                !player->HasItemCount(T_F,1) && !player->HasItemCount(C_H,1) && !player->HasItemCount(H_H,1) && !player->HasItemCount(MS_H,1) &&
                !player->HasItemCount(MA_H,1) && !player->HasItemCount(T_H,1) && !player->HasItemCount(C_R,1) && !player->HasItemCount(H_R,1) &&
                !player->HasItemCount(MS_R,1) && !player->HasItemCount(MA_R,1) && !player->HasItemCount(T_R,1))
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring caster (Revered)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+11);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring healer (Revered)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+12);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - strength (Revered)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+13);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - agility (Revered)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+14);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring tank (Revered)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+15);
                player->SEND_GOSSIP_MENU(GMSG, creature->GetGUID());
                return true;
            }
        }

        if (value >= exalted)
        {
            if (!player->HasItemCount(C_F,1) && !player->HasItemCount(H_F,1) && !player->HasItemCount(MS_F,1) && !player->HasItemCount(MA_F,1) &&
                !player->HasItemCount(T_F,1) && !player->HasItemCount(C_H,1) && !player->HasItemCount(H_H,1) && !player->HasItemCount(MS_H,1) &&
                !player->HasItemCount(MA_H,1) && !player->HasItemCount(T_H,1) && !player->HasItemCount(C_R,1) && !player->HasItemCount(H_R,1) &&
                !player->HasItemCount(MS_R,1) && !player->HasItemCount(MA_R,1) && !player->HasItemCount(T_R,1) && !player->HasItemCount(C_E,1) &&
                !player->HasItemCount(H_E,1) && !player->HasItemCount(MS_E,1) && !player->HasItemCount(MA_E,1) && !player->HasItemCount(T_E,1))
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring caster (Exalted)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+16);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring healer (Exalted)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+17);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - strength (Exalted)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+18);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring melee - agility (Exalted)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+19);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"Ring tank (Exalted)",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+20);
                player->SEND_GOSSIP_MENU(GMSG, creature->GetGUID());
                return true;
            }
        }
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->AddItem(C_F,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->AddItem(H_F,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->AddItem(MS_F,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->AddItem(MA_F,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->AddItem(T_F,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->AddItem(C_H,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->AddItem(H_H,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+8:
                player->AddItem(MS_H,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+9:
                player->AddItem(MA_H,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+10:
                player->AddItem(T_H,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                player->AddItem(C_R,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+12:
                player->AddItem(H_R,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+13:
                player->AddItem(MS_R,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+14:
                player->AddItem(MA_R,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+15:
                player->AddItem(T_R,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+16:
                player->AddItem(C_E,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+17:
                player->AddItem(H_E,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+18:
                player->AddItem(MS_E,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+19:
                player->AddItem(MA_E,1);
                break;
            case GOSSIP_ACTION_INFO_DEF+20:
                player->AddItem(T_E,1);
                break;
        }
        player->CLOSE_GOSSIP_MENU();
        return true;
    }
};

void AddSC_icc_trash()
{
    new npc_NerubarBroodkeeper();
    new npc_ServantoftheThrone();
    new npc_AncientSkeletalSoldier();
    new npc_DeathboundWard();
    new npc_DeathspeakerAttedant();
    new npc_DeathspeakerDisciple();
    new npc_DeathspeakerHighPriest();
    new npc_DeathspeakerServant();
    new npc_DeathspeakerZealot();
    new npc_valkyr_herald();
    new npc_blighted_abomination();
    new npc_vengeful_fleshreapert();
    new npc_plague_scientist();
    new npc_pustulating_horror();
    new npc_decaying_colossus();
    new npc_darkfallen_archmage();
    new npc_darkfallen_blood_knight();
    new npc_darkfallen_noble();
    new npc_vampiric_fiend();
    new npc_darkfallen_advisor();
    new npc_darkfallen_commander();
    new npc_darkfallen_lieutenant();
    new npc_darkfallen_tactician();
    new npc_icc_rep_rings();
}