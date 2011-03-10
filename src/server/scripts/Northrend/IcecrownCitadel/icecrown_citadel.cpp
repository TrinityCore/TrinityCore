/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "Spell.h"

#define GOSSIP_TEXT(id) sObjectMgr->GetGossipText(id)->Options[0].Text_0
#define IS_TELEPORT_ENABLED(id) ((go->GetMap()->GetGameObject(instance->GetData64(id))->GetGoState() == GO_STATE_ACTIVE) ? true: false)
// Weekly quest support
//* Deprogramming
//* Securing the Ramparts        (DONE)
//* Residue Rendezvous
//* Blood Quickening
//* Respite for a Tormented Soul

enum Texts
{
    // Rotting Frost Giant
    EMOTE_DEATH_PLAGUE_WARNING  = 0,
};
enum Spells
{
    SPELL_ON_ORGRIMS_HAMMER_DECK    = 70121, //maybe for gunship battle

    // Rotting Frost Giant
    SPELL_DEATH_PLAGUE              = 72879,
    SPELL_DEATH_PLAGUE_AURA         = 72865,
    SPELL_RECENTLY_INFECTED         = 72884,
    SPELL_DEATH_PLAGUE_KILL         = 72867,
    SPELL_STOMP                     = 64652,
    SPELL_ARCTIC_BREATH             = 72848,

    // Frost Freeze Trap
    SPELL_COLDFLAME_JETS            = 70460,

    SPELL_SPIRIT_ALARM_1            = 70536,
    SPELL_SPIRIT_ALARM_2            = 70546,
    SPELL_SPIRIT_ALARM_3            = 70545,
    SPELL_SPIRIT_ALARM_4            = 70547,
    SPELL_DARK_RECKONING            = 69483,
    SPELL_DARK_RECKONING_SIPHON_LIFE= 69482,
    SPELL_AURA_OF_DARKNESS            = 69491,
    SPELL_SEVERED_ESSENCE_10        = 71906,
    SPELL_SEVERED_ESSENCE_25        = 71942,
    //Severed essence spells
    SPELL_CLONE_PLAYER              = 57507,
    //Druid spells
    SPELL_CAT_FORM                  = 57655,
    SPELL_MANGLE                    = 71925,
    SPELL_RIP                       = 71926,
    //Warlock
    SPELL_CORRUPTION                = 71937,
    SPELL_SHADOW_BOLT               = 71936,
    SPELL_RAIN_OF_CHAOS             = 71965,
    //Shaman
    SPELL_REPLENISHING_RAINS        = 71956,
    SPELL_LIGHTNING_BOLT            = 71934,
    //Rouge
    SPELL_DISENGAGE                 = 57635,
    SPELL_FOCUSED_ATTACKS           = 71955,
    SPELL_SINISTER_STRIKE           = 57640,
    SPELL_EVISCERATE                = 71933,
    //Mage
    SPELL_FIREBALL                  = 71928,
    //Warior
    SPELL_BLOODTHIRST               = 71938,
    SPELL_HEROIC_LEAP               = 71961,
    //Dk
    SPELL_DEATH_GRIP                = 57602,
    SPELL_NECROTIC_STRIKE           = 71951,
    SPELL_PLAGUE_STRIKE             = 71924,
    //Priest
    SPELL_GREATER_HEAL              = 71931,
    SPELL_RENEW                     = 71932,
    //Paladin
    SPELL_CLEANSE                   = 57767,
    SPELL_FLASH_OF_LIGHT            = 71930,
    SPELL_RADIANCE_AURA             = 71953,
    //Hunter
    SPELL_SHOOT_10                  = 71927,
    SPELL_SHOOT_25                  = 72258,
};

enum eEvents
{
    // Rotting Frost Giant
    EVENT_DEATH_PLAGUE     = 1,
    EVENT_STOMP               ,
    EVENT_ARCTIC_BREATH       ,

    // Frost Freeze Trap
    EVENT_ACTIVATE_TRAP       ,
    
    //Deathspeaker High Priest
    EVENT_DARK_RECKONING      ,
    //Val'kyr Herald
    EVENT_SEVERED_ESSENCE     ,

    //Druid spells
    EVENT_CAT_FORM            ,
    EVENT_MANGLE              ,
    EVENT_RIP                 ,
    //Warlock
    EVENT_CORRUPTION          ,
    EVENT_SHADOW_BOLT         ,
    EVENT_RAIN_OF_CHAOS       ,
    //Shaman
    EVENT_REPLENISHING_RAINS  ,
    EVENT_LIGHTNING_BOLT      ,
    EVENT_CAN_CAST_REPLENISHING_RAINS,
    //Rogue
    EVENT_FOCUSED_ATTACKS     ,
    EVENT_SINISTER_STRIKE     ,
    EVENT_EVISCERATE          ,
    //Mage
    EVENT_FIREBALL            ,
    //Warrior
    EVENT_BLOODTHIRST         ,
    EVENT_HEROIC_LEAP         ,
    //Dead Knight
    EVENT_DEATH_GRIP          ,
    EVENT_NECROTIC_STRIKE     ,
    EVENT_PLAGUE_STRIKE       ,
    //Priest
    EVENT_GREATER_HEAL        ,
    EVENT_RENEW               ,
    //Paladin
    EVENT_CLEANSE             ,
    EVENT_FLASH_OF_LIGHT      ,
    EVENT_RADIANCE_AURA       ,
    EVENT_CAN_CAST_RADIANCE_AURA,
    //Hunter
    EVENT_SHOOT               ,
    EVENT_DISENGAGE           ,
    EVENT_CAN_CAST_DISENGAGE
};
enum eData
{
    DATA_PLAYER_CLASS = 2,
};

enum eTeleportGossips
{
    GOSSIP_TELEPORT_LIGHTS_HAMMER           = 800000,
    GOSSIP_TELEPORT_ORATORY_OF_THE_DAMNED   = 800001,
    GOSSIP_TELEPORT_RAMPART_OF_SKULLS       = 800002,
    GOSSIP_TELEPORT_DEATHBRINGERS_RISE      = 800003,
    GOSSIP_TELEPORT_UPPER_SPIRE             = 800004,
    GOSSIP_TELEPORT_SINDRAGOSAS_LAIR        = 800005,
    GOSSIP_TELEPORT_FROZEN_THRONE           = 800006
};
enum eTrapEvents
{
    EVENT_COLDFLAME_JETS = 1,
    EVENT_REMOVE_COLDFLAME_JETS
};
enum eTrapActions
{
    ACTION_DISARM_FROST_TRAP = 2
};
//class npc_cult_fanatic_and_adherent : public CreatureScript
//{
//    public:
//        npc_cult_fanatic_and_adherent() : CreatureScript("npc_cult_fanatic_and_adherent") { }
//
//        struct npc_cult_fanatic_and_adherentAI : public ScriptedAI
//        {
//            npc_cult_fanatic_and_adherentAI(Creature* creature) : ScriptedAI(creature) { }
//
//            void Reset()
//            {
//                uiStrikeTimer = urand(8000, 11000);
//                uiVampirTimer = urand(19000, 22000);
//                uiCleaveTimer = urand(7000, 9000);
//                uiMartyrdomTimer = urand(24000, 30000);
//                uiFrostFeverTimer = urand(9000, 11000);
//                uiDeathchillTimer = urand(10000, 12000);
//                uiCurseTimer = urand(8000, 10000);
//                uiOccultTimer = urand(25000, 29000);
//
//                bEmpowerement = false;
//
//                //if(me->GetEntry() == CREATURE_REANIMATED_ADHERENT)
//                //    DoCast(me, SPELL_ADHERENT_DETERMINATION);
//                //if(me->GetEntry() == CREATURE_REANIMATED_FANATIC)
//                //    DoCast(me, SPELL_FANATIC_DETERMINATION);
//            }
//
//            void JustDied(Unit* /*who*/) { }
//
//            void SpellHit(Unit* /*caster*/, const SpellEntry * spell)
//            {
//                if(me->GetEntry() == CREATURE_ADHERENT)
//                {
//                    if (spell->Id == SPELL_EMPOWEREMENT)
//                        me->UpdateEntry(CREATURE_EMPOWERED_ADHERENT);
//                    else if (spell->Id == SPELL_DARK_EMPOWERMENT_T)
//                    {
//                        DoCast(me, SPELL_EMPOWEREMENT);
//                        bEmpowerement = true;
//                    }
//                }
//                if(me->GetEntry() == CREATURE_FANATIC)
//                {
//                    if (spell->Id == SPELL_DARKTRANSFORMATION)
//                        me->UpdateEntry(CREATURE_DEFORMED_FANATIC);
//                    else if (spell->Id == SPELL_DARK_TRANSFORMATION_T)
//                    {
//                        DoCast(me, SPELL_DARKTRANSFORMATION);
//                    }
//                }
//            }
//
//            void UpdateAI(const uint32 uiDiff)
//            {
//                if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
//                    return;
//
//                if((me->GetEntry() == CREATURE_ADHERENT) || (me->GetEntry() == CREATURE_EMPOWERED_ADHERENT) || (me->GetEntry() == CREATURE_REANIMATED_ADHERENT))
//                {
//                    if (uiMartyrdomTimer <= uiDiff && !bEmpowerement)
//                    {
//                        DoCast(me, SPELL_DARKMARTYRDOM_ADHERENT);
//                        uiMartyrdomTimer = urand(24000, 30000);
//                    } else uiMartyrdomTimer -= uiDiff;
//
//                    if (uiFrostFeverTimer <= uiDiff)
//                    {
//                        DoCast(me->getVictim(), SPELL_FROST_FEVER);
//                        uiFrostFeverTimer = urand(9000, 11000);
//                    } else uiFrostFeverTimer -= uiDiff;
//
//                    if (uiDeathchillTimer <= uiDiff)
//                    {
//                        if (me->GetEntry() == CREATURE_EMPOWERED_ADHERENT)
//                            DoCast(me->getVictim(), SPELL_DEATHCHILL_BLAST);
//                        else
//                            DoCast(me->getVictim(), SPELL_DEATHCHILL_BOLT);
//                        uiDeathchillTimer = urand(10000, 12000);
//                    } else uiDeathchillTimer -= uiDiff;
//
//                    if (uiCurseTimer <= uiDiff)
//                    {
//                        if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1))
//                            DoCast(target, SPELL_CURSE_OF_TORPOR);
//                        uiCurseTimer = urand(8000, 10000);
//                    } else uiCurseTimer -= uiDiff;
//
//                    if (uiOccultTimer <= uiDiff)
//                    {
//                        DoCast(me, SPELL_SHORUD_OF_THE_OCCULT);
//                        uiOccultTimer = urand(25000, 29000);
//                    } else uiOccultTimer -= uiDiff;
//                }
//                if((me->GetEntry() == CREATURE_FANATIC) || (me->GetEntry() == CREATURE_REANIMATED_FANATIC) || (me->GetEntry() == CREATURE_DEFORMED_FANATIC))
//                {
//                    if (uiMartyrdomTimer <= uiDiff)
//                    {
//                        DoCast(me, SPELL_DARKMARTYRDOM_FANATIC);
//                        uiMartyrdomTimer = urand(24000, 30000);
//                    } else uiMartyrdomTimer -= uiDiff;
//
//                    if (uiStrikeTimer <= uiDiff)
//                    {
//                        DoCast(me, SPELL_NECROTICSTRIKE);
//                        uiStrikeTimer = urand(8000, 11000);
//                    } else uiStrikeTimer -= uiDiff;
//
//                    if (uiCleaveTimer <= uiDiff)
//                    {
//                        DoCast(me, SPELL_SHADOWCLEAVE);
//                        uiCleaveTimer = urand(7000, 9000);
//                    } else uiCleaveTimer -= uiDiff;
//
//                    if (uiVampirTimer <= uiDiff)
//                    {
//                        DoCast(me, SPELL_VAMPIRICMIGHT);
//                        uiVampirTimer = urand(19000, 22000);
//                    } else uiVampirTimer -= uiDiff;
//                }
//
//                DoMeleeAttackIfReady();
//            }
//
//        private:
//            uint32 uiStrikeTimer;
//            uint32 uiCleaveTimer;
//            uint32 uiVampirTimer;
//            uint32 uiMartyrdomTimer;
//            uint32 uiFrostFeverTimer;
//            uint32 uiDeathchillTimer;
//            uint32 uiCurseTimer;
//            uint32 uiOccultTimer;
//
//            bool bEmpowerement;
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_cult_fanatic_and_adherentAI(creature);
//        }
//};

class go_icecrown_teleporter : public GameObjectScript
{

public:
    go_icecrown_teleporter() : GameObjectScript("go_icecrown_teleporter") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        InstanceScript* instance = go->GetInstanceScript();
        if(!instance)
            return false;
        if (instance->IsEncounterInProgress())
            return false;
        if (go->GetEntry() == GO_TELEPORT_FROZEN_THRONE)
        {
            if (instance->GetData(DATA_PROFESSOR_PUTRICIDE_EVENT) == DONE &&
                instance->GetData(DATA_BLOOD_QUEEN_LANA_THEL_EVENT) == DONE && 
                instance->GetData(DATA_SINDRAGOSA_EVENT) == DONE)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_FROZEN_THRONE), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_FROZEN_THRONE);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
                return true;
            }
            return false;
        }
        switch (go->GetEntry())
        {
            case GO_TELEPORT_ORATORY_OF_THE_DAMNED:
                instance->SetData(DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_RAMPART_OF_SKULLS:
                instance->SetData(DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED, DONE);
                instance->SetData(DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_DEATHBRINGER_RISE:
                instance->SetData(DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_UPPER_SPIRE:
                instance->SetData(DATA_TELEPORT_UPPER_SPIRE_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_SINDRAGOSA_S_LAIR:
                instance->SetData(DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_FROZEN_THRONE:
                instance->SetData(DATA_TELEPORT_FROZEN_THRONE_ACTIVATED, DONE);
                break;
        }
        instance->HandleGameObject(NULL, true, go);
        if (go->GetEntry() != GO_TELEPORT_LIGHT_S_HAMMER)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_LIGHTS_HAMMER), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_LIGHT_S_HAMMER);

        if (go->GetEntry() != GO_TELEPORT_ORATORY_OF_THE_DAMNED && instance->GetData(DATA_LORD_MARROWGAR_EVENT) == DONE && instance->GetData(DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_ORATORY_OF_THE_DAMNED), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_ORATORY_OF_THE_DAMNED);
        if (go->GetEntry() != GO_TELEPORT_RAMPART_OF_SKULLS && instance->GetData(DATA_DEATHWHISPER_EVENT) == DONE && instance->GetData(DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_RAMPART_OF_SKULLS), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_RAMPART_OF_SKULLS);
        if (go->GetEntry() != GO_TELEPORT_DEATHBRINGER_RISE
            && instance->GetData(DATA_GUNSHIP_BATTLE_EVENT) == DONE
            && instance->GetData(DATA_DEATHWHISPER_EVENT) == DONE
            && instance->GetData(DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED) == DONE
            //&& IS_TELEPORT_ENABLED(DATA_TELEPORT_DEATHBRINGERS_RISE) //Disabled until Gunship Battle encounter is implemented
            )
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_DEATHBRINGERS_RISE), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_DEATHBRINGER_S_RISE);
        }
        if (go->GetEntry() != GO_TELEPORT_UPPER_SPIRE &&
            instance->GetData(DATA_SAURFANG_EVENT) == DONE && instance->GetData(DATA_TELEPORT_UPPER_SPIRE_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_UPPER_SPIRE), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_UPPER_SPIRE);
        if (go->GetEntry() != GO_TELEPORT_SINDRAGOSA_S_LAIR &&
            instance->GetData(DATA_VALITHRIA_DREAMWALKER_EVENT) == DONE && instance->GetData(DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_SINDRAGOSAS_LAIR), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_SINDRAGOSA_S_LAIR);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 uiSender, uint32 uiAction)
        {
            //player->PlayerTalkClass->ClearMenus();
            if(!player->getAttackers().empty())
                return false;

            SpellEntry const* spell = sSpellStore.LookupEntry(uiAction);
            if (!spell)
                return false;

            if (player->isInCombat())
            {
                Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }

            if (uiSender == GOSSIP_SENDER_MAIN)
            {
                //Preload the Lich King's platform before teleporting player to there
                if (uiAction == SPELL_TELEPORT_ICC_FROZEN_THRONE)
                    player->GetMap()->LoadGrid(530.3f, -2122.67f);
                player->CastSpell(player, spell, true);
                //Give him 2 tries, just in case if player will fall through the ground
                if (uiAction == SPELL_TELEPORT_ICC_FROZEN_THRONE)
                    TeleportPlayerToFrozenThrone(player);
            }
            return true;
        }
};

class spell_icc_spirit_alarm : public SpellScriptLoader
{
    public:
        spell_icc_spirit_alarm() : SpellScriptLoader("spell_icc_spirit_alarm") { }

        class spell_icc_spirit_alarm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_spirit_alarm_SpellScript);

            void AwakenDeathboundWard(SpellEffIndex effIndex)
            {
                if (!GetTargetUnit() || GetTargetUnit()->GetTypeId() != TYPEID_PLAYER)
                    return;
                if (!GetCaster())
                    return;
                InstanceScript *instance = GetCaster()->GetInstanceScript();
                GameObject *spiritAlarm = NULL;
                Creature *pWard = NULL;
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_SPIRIT_ALARM_1:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM1));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD1));
                        //Preload Spirit Alarm traps near Lord Marrowgar
                        spiritAlarm->GetMap()->LoadGrid(-273.845f, 2220.22f);
                        spiritAlarm->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM3))->SetPhaseMask(1, true);
                        break;
                    case SPELL_SPIRIT_ALARM_2:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM2));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD2));
                        //Preload Spirit Alarm traps near Lord Marrowgar
                        spiritAlarm->GetMap()->LoadGrid(-273.845f, 2220.22f);
                        spiritAlarm->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM4))->SetPhaseMask(1, true);
                        break;
                    case SPELL_SPIRIT_ALARM_3:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM3));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD3));
                        break;
                    case SPELL_SPIRIT_ALARM_4:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM4));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD4));
                        break;
                }
                spiritAlarm->setActive(false);
                if (pWard && pWard->isAlive())
                {
                    pWard->SetReactState(REACT_AGGRESSIVE);
                    pWard->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pWard->AI()->AttackStart(GetTargetUnit());
                }
            }
            void Register()
            {
                OnEffect += SpellEffectFn(spell_icc_spirit_alarm_SpellScript::AwakenDeathboundWard, EFFECT_2, SPELL_EFFECT_SEND_EVENT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_icc_spirit_alarm_SpellScript();
        }
};

class npc_rotting_frost_giant : public CreatureScript
{
    public:
        npc_rotting_frost_giant() : CreatureScript("npc_rotting_frost_giant") { }

        struct npc_rotting_frost_giantAI : public ScriptedAI
        {
            npc_rotting_frost_giantAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                events.ScheduleEvent(EVENT_STOMP, urand(5000, 8000));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(10000, 15000));
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(EMOTE_DEATH_PLAGUE_WARNING, target->GetGUID());
                                DoCast(target, SPELL_DEATH_PLAGUE);
                            }
                            events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, urand(15000, 18000));
                            break;
                        case EVENT_ARCTIC_BREATH:
                            DoCastVictim(SPELL_ARCTIC_BREATH);
                            events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(26000, 33000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_rotting_frost_giantAI(creature);
        }
};

class DeathPlagueTargetSelector
{
    public:
        DeathPlagueTargetSelector(Unit* _caster) : caster(_caster) {}

        bool operator()(Unit* unit)
        {
            if (unit == caster)
                return true;

            if (unit->GetTypeId() != TYPEID_PLAYER)
                return true;

            if (unit->HasAura(SPELL_RECENTLY_INFECTED) || unit->HasAura(SPELL_DEATH_PLAGUE_AURA))
                return true;

            return false;
        }

        Unit* caster;
};

class spell_frost_giant_death_plague : public SpellScriptLoader
{
    public:
        spell_frost_giant_death_plague() : SpellScriptLoader("spell_frost_giant_death_plague") { }

        class spell_frost_giant_death_plague_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_frost_giant_death_plague_SpellScript);

            bool Load()
            {
                failed = false;
                return true;
            }

            // First effect
            void CountTargets(std::list<Unit*>& unitList)
            {
                unitList.remove(GetCaster());
                failed = unitList.empty();
            }

            // Second effect
            void FilterTargets(std::list<Unit*>& unitList)
            {
                // Select valid targets for jump
                unitList.remove_if(DeathPlagueTargetSelector(GetCaster()));
                if (!unitList.empty())
                {
                    std::list<Unit*>::iterator itr = unitList.begin();
                    std::advance(itr, urand(0, unitList.size()-1));
                    Unit* target = *itr;
                    unitList.clear();
                    unitList.push_back(target);
                }

                unitList.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetHitUnit() != GetCaster())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DEATH_PLAGUE_AURA, true);
                else if (failed)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEATH_PLAGUE_KILL, true);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
                OnEffect += SpellEffectFn(spell_frost_giant_death_plague_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            bool failed;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_frost_giant_death_plague_SpellScript();
        }
};

class npc_frost_freeze_trap : public CreatureScript
{
    public:
        npc_frost_freeze_trap() : CreatureScript("npc_frost_freeze_trap") { }

        struct npc_frost_freeze_trapAI: public Scripted_NoMovementAI
        {
            npc_frost_freeze_trapAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case 1000:
                    case 11000:
                        events.ScheduleEvent(EVENT_ACTIVATE_TRAP, uint32(action));
                        break;
                    case ACTION_STOP_TRAPS:
                        me->RemoveAurasDueToSpell(SPELL_COLDFLAME_JETS);
                        events.CancelEvent(EVENT_ACTIVATE_TRAP);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_ACTIVATE_TRAP)
                {
                    DoCast(me, SPELL_COLDFLAME_JETS);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRAP, 22000);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frost_freeze_trapAI(creature);
        }
};

class spell_coldflame_trap : public SpellScriptLoader
{
    public:
        spell_coldflame_trap() : SpellScriptLoader("spell_coldflame_trap") { }

        class spell_coldflame_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_coldflame_trap_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                std::list<Unit*> nonTrapped;
                if (Unit *pCaster = GetCaster())
                {
                    float x, y, z, angle, ux, uy;
                    pCaster->GetPosition(x, y, z, angle);
                    float opX = x + 25.0f * cos(angle);
                    float opY = y + 25.0f * sin(angle);
                    for (std::list<Unit*>::iterator it = unitList.begin(); it != unitList.end(); ++it)
                    {
                        Unit *curUnit = *it;
                        float unitRadius = curUnit->GetObjectSize();
                        ux = curUnit->GetPositionX();
                        uy = curUnit->GetPositionY();
                        if (   ux - unitRadius > std::max(x, opX)
                            || ux + unitRadius < std::min(x, opX)
                            || uy - unitRadius > std::max(y, opY)
                            || uy + unitRadius < std::min(y, opY))
                        {
                            nonTrapped.push_back(curUnit);
                            continue;
                        }

                        float angle = pCaster->GetAngle(curUnit) - pCaster->GetAngle(opX, opY);
                        bool inBetween = abs(sin(angle)) * curUnit->GetExactDist2d(pCaster) < unitRadius;
                        if (!inBetween)
                            nonTrapped.push_back(curUnit);
                    }
                }
                for (std::list<Unit*>::iterator it = nonTrapped.begin(); it != nonTrapped.end(); ++it)
                    unitList.erase(std::find(unitList.begin(), unitList.end(), *it));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_coldflame_trap_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_PATH);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_coldflame_trap_SpellScript();
        }
};

class at_icc_saurfang_portal : public AreaTriggerScript
{
    public:
        at_icc_saurfang_portal() : AreaTriggerScript("at_icc_saurfang_portal") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetData(DATA_SAURFANG_EVENT) != DONE)
                return true;

            player->GetMap()->LoadGrid(4207.0f, 2769.23f);
            player->TeleportTo(631, 4126.35f, 2769.23f, 350.963f, 0.0f);

            if (instance->GetData(DATA_COLDFLAME_JETS_EVENT) == NOT_STARTED)
            {
                // Process relocation now, to preload the grid and initialize traps
                player->GetMap()->PlayerRelocation(player, 4126.35f, 2769.23f, 350.963f, 0.0f);

                instance->SetData(DATA_COLDFLAME_JETS_EVENT, IN_PROGRESS);

                std::list<Creature*> traps;
                if (GameObject *go = player->GetMap()->GetGameObject(instance->GetData64(GUID_TELEPORT_UPPER_SPIRE)))
                    GetCreatureListWithEntryInGrid(traps, go, NPC_FROST_FREEZE_TRAP, 200.0f);
                traps.sort(Trinity::ObjectDistanceOrderPred(player));
                bool instant = false;
                for (std::list<Creature*>::iterator itr = traps.begin(); itr != traps.end(); ++itr)
                {
                    (*itr)->AI()->DoAction(instant ? 1000 : 11000);
                    instant = !instant;
                }
            }
            return true;
        }
};

class at_icc_shutdown_traps : public AreaTriggerScript
{
    public:
        at_icc_shutdown_traps() : AreaTriggerScript("at_icc_shutdown_traps") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_COLDFLAME_JETS_EVENT) == IN_PROGRESS)
                    instance->SetData(DATA_COLDFLAME_JETS_EVENT, DONE);
            return true;
        }
};

class npc_deathspeaker_high_priest : public CreatureScript
{
public:
    npc_deathspeaker_high_priest() : CreatureScript("npc_deathspeaker_high_priest") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_deathspeaker_high_priestAI (pCreature);

    }

    struct npc_deathspeaker_high_priestAI : public ScriptedAI
    {

        npc_deathspeaker_high_priestAI(Creature *c) : ScriptedAI(c)
        {
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCast(me, SPELL_AURA_OF_DARKNESS);
            events.Reset();
            events.ScheduleEvent(EVENT_DARK_RECKONING, 10000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DARK_RECKONING:
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,1, 35.0f, false, -SPELL_DARK_RECKONING))
                            DoCast(pTarget, SPELL_DARK_RECKONING);
                        events.ScheduleEvent(EVENT_DARK_RECKONING, 20000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            EventMap events;
    };

};
class spell_icc_dark_reckoning : public SpellScriptLoader
{
    public:
        spell_icc_dark_reckoning() : SpellScriptLoader("spell_icc_dark_reckoning") { }

        class spell_icc_dark_reckoning_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_icc_dark_reckoning_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_DARK_RECKONING) ||
                    !sSpellStore.LookupEntry(SPELL_DARK_RECKONING_SIPHON_LIFE))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit *caster = GetCaster(), *target = GetTarget();
                if (caster && caster->isAlive() && target && target->isAlive())
                    caster->CastSpell(target, SPELL_DARK_RECKONING_SIPHON_LIFE, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_icc_dark_reckoning_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_icc_dark_reckoning_AuraScript();
        }
};
class npc_val_kyr_herald : public CreatureScript
{
public:
    npc_val_kyr_herald() : CreatureScript("npc_val_kyr_herald") { }

    CreatureAI* GetAI(Creature* pCreature) const

    {
        return new npc_val_kyr_heraldAI (pCreature);

    }

    struct npc_val_kyr_heraldAI : public ScriptedAI
    {

        npc_val_kyr_heraldAI(Creature *c) : ScriptedAI(c), summons(c)
        {
            instance = c->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_SEVERED_ESSENCE, 8000);
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }

        void JustDied (Unit *killer)
        {
            summons.DespawnAll();
        }

        void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
        {
            // Not good target or too many players
            if (pTarget->GetTypeId() != TYPEID_PLAYER || !pTarget->isAlive())
                return;
            // Summon clone
            me->SummonCreature(NPC_SEVERED_ESSENCE, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), pTarget->GetOrientation(),TEMPSUMMON_CORPSE_DESPAWN, 0);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SEVERED_ESSENCE:
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0, 100.0f, true))
                        {
                            DoCast(me, RAID_MODE<uint32>(SPELL_SEVERED_ESSENCE_10, SPELL_SEVERED_ESSENCE_25, SPELL_SEVERED_ESSENCE_10, SPELL_SEVERED_ESSENCE_25));
                        }
                        events.ScheduleEvent(EVENT_SEVERED_ESSENCE, 40000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            InstanceScript *instance;
            EventMap events;
            SummonList summons;
    };

};

class npc_severed_essence : public CreatureScript
{
public:
    npc_severed_essence() : CreatureScript("npc_severed_essence") { }

    CreatureAI* GetAI(Creature* pCreature) const

    {
        return new npc_severed_essenceAI (pCreature);

    }

    struct npc_severed_essenceAI : public ScriptedAI
    {
        npc_severed_essenceAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
            playerClass = 0;
        }

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* owner)
        {
            if (owner->GetTypeId() != TYPEID_UNIT || owner->GetEntry() != NPC_VALKYR_HERALD)
                return;
            uiOwnerId = owner->GetGUID();
        }

        void KilledUnit(Unit* victim)
        {
            if (Unit *newVictim = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f))
                AttackStart(newVictim);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Unit *player = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
            {
                player->CastSpell(me, SPELL_CLONE_PLAYER, true);
                SetData(DATA_PLAYER_CLASS, player->getClass());
            }
            else
            {
                me->DespawnOrUnsummon();
                return;
            }
            ASSERT(playerClass != 0);
            events.Reset();
            switch (playerClass)
            {
                case CLASS_DRUID:
                {
                    events.ScheduleEvent(EVENT_CAT_FORM, 100);
                    events.ScheduleEvent(EVENT_MANGLE, 3000);
                    events.ScheduleEvent(EVENT_RIP, 8000);
                    break;
                }
                case CLASS_WARLOCK:
                {
                    events.ScheduleEvent(EVENT_CORRUPTION, 100);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 3000);
                    events.ScheduleEvent(EVENT_RAIN_OF_CHAOS, 8000);
                    break;
                }
                case CLASS_SHAMAN:
                {
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 3000);
                    bCanCastReplenishingRains = true;
                    break;
                }
                case CLASS_ROGUE:
                {
                    events.ScheduleEvent(EVENT_FOCUSED_ATTACKS, 10000);
                    events.ScheduleEvent(EVENT_SINISTER_STRIKE, 2000);
                    events.ScheduleEvent(EVENT_EVISCERATE, 8000);
                    break;
                }
                case CLASS_MAGE:
                {
                    events.ScheduleEvent(EVENT_FIREBALL, 100);
                    break;
                }
                case CLASS_WARRIOR:
                {
                    events.ScheduleEvent(EVENT_BLOODTHIRST, 5000);
                    events.ScheduleEvent(EVENT_HEROIC_LEAP, 8000);
                    break;
                }
                case CLASS_DEATH_KNIGHT:
                {
                    events.ScheduleEvent(EVENT_DEATH_GRIP, 100);
                    events.ScheduleEvent(EVENT_NECROTIC_STRIKE, 4000);
                    events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 7000);
                    break;
                }
                case CLASS_HUNTER:
                {
                    events.ScheduleEvent(EVENT_SHOOT, 100);
                    bCanCastDisengage = true;
                    break;
                }
                case CLASS_PALADIN:
                {
                    events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, 100);
                    events.ScheduleEvent(EVENT_CLEANSE, 3000);
                    bCanCastRadianceAura = true;
                    break;
                case CLASS_PRIEST:
                {
                    events.ScheduleEvent(EVENT_GREATER_HEAL, 100);
                    events.ScheduleEvent(EVENT_RENEW, 1000);
                    break;
                }
            }
            }
        }
        void DamageTaken(Unit* /*done_by*/, uint32& /*damage*/)
        {
            switch (playerClass)
            {
                case CLASS_SHAMAN:
                {
                    if(HealthBelowPct(30) && bCanCastReplenishingRains)
                    {
                        events.ScheduleEvent(EVENT_REPLENISHING_RAINS, 100);
                        events.ScheduleEvent(EVENT_CAN_CAST_REPLENISHING_RAINS, 15000);
                        bCanCastReplenishingRains = false;
                    }
                }
                case CLASS_HUNTER:
                {
                    if (!bCanCastDisengage)
                        break;
                    std::list<HostileReference*> &players = me->getThreatManager().getThreatList();
                    if (players.empty())
                        break;
                    for (std::list<HostileReference*>::iterator it = players.begin(); it != players.end(); ++it)
                    {
                        if (Unit *curTarget = (*it)->getTarget())
                        {
                            if (me->GetDistance2d(curTarget) < 5.0f)
                            {
                                me->SetFacingToObject(curTarget);
                                DoCast(curTarget, SPELL_DISENGAGE);
                                bCanCastDisengage = false;
                                events.ScheduleEvent(EVENT_CAN_CAST_DISENGAGE, 15000);
                                break;
                            }
                        }
                    }
                    break;
                }
                case CLASS_PALADIN:
                    if(HealthBelowPct(30) && bCanCastRadianceAura)
                    {
                        events.ScheduleEvent(EVENT_RADIANCE_AURA, 100);
                        events.ScheduleEvent(EVENT_CAN_CAST_RADIANCE_AURA, 15000);
                        bCanCastRadianceAura = false;
                    }
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_PLAYER_CLASS)
                playerClass = data;
        }

        void HandleDruidEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAT_FORM:
                    DoCast(me, SPELL_CAT_FORM);
                    break;
                case EVENT_MANGLE:
                    DoCast(me->getVictim(), SPELL_MANGLE);
                    events.ScheduleEvent(EVENT_MANGLE, 2000);
                    break;
                case EVENT_RIP:
                    DoCast(me->getVictim(), SPELL_RIP);
                    events.ScheduleEvent(EVENT_RIP, 8000);
                    break;
            }
        }

        void HandleWarlockEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CORRUPTION:
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f, true, -SPELL_CORRUPTION))
                        DoCast(pUnit, SPELL_CORRUPTION);
                    events.ScheduleEvent(EVENT_CORRUPTION, 20000);
                    break;
                case EVENT_SHADOW_BOLT:
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 5000);
                    break;
                case EVENT_RAIN_OF_CHAOS:
                    DoCast(me->getVictim(), SPELL_RAIN_OF_CHAOS);
                    events.ScheduleEvent(EVENT_RAIN_OF_CHAOS, 18000);
                    break;
            }
        }

        void HandleShamanEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAN_CAST_REPLENISHING_RAINS:
                    bCanCastReplenishingRains = true;
                    break;
                case EVENT_REPLENISHING_RAINS:
                    DoCast(me, SPELL_REPLENISHING_RAINS);
                    break;
                case EVENT_LIGHTNING_BOLT:
                    DoCast(me->getVictim(), SPELL_LIGHTNING_BOLT);
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 4000);
                    break;

            }
        }

        void HandleRogueEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_FOCUSED_ATTACKS:
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 1, 5.0f, true, -SPELL_FOCUSED_ATTACKS))
                        DoCast(pUnit, SPELL_FOCUSED_ATTACKS);
                    events.ScheduleEvent(EVENT_FOCUSED_ATTACKS, 15000);
                    break;
                case EVENT_SINISTER_STRIKE:
                    DoCast(me->getVictim(), SPELL_SINISTER_STRIKE);
                    events.ScheduleEvent(EVENT_SINISTER_STRIKE, 1000);
                    break;
                case EVENT_EVISCERATE:
                    DoCast(me->getVictim(), SPELL_EVISCERATE);
                    events.ScheduleEvent(EVENT_EVISCERATE, 6000);
                    break;
            }
        }

        void HandleMageEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_FIREBALL:
                    DoCast(me->getVictim(), SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 3500);
                    break;
            }
        }

        void HandleWarriorEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_BLOODTHIRST:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                        DoCast(pUnit, SPELL_BLOODTHIRST);
                    events.ScheduleEvent(EVENT_BLOODTHIRST, 12000);
                    break;
                }
                case EVENT_HEROIC_LEAP:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 1, 8.0f, true))
                        DoCast(pUnit, SPELL_HEROIC_LEAP);
                    events.ScheduleEvent(EVENT_HEROIC_LEAP, 45000);
                    break;
                }
            }
        }

        void HandleDeathKnightEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_DEATH_GRIP:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                    {
                        DoCast(pUnit, EVENT_DEATH_GRIP);
                        me->getThreatManager().clearReferences();
                        AttackStart(pUnit);
                    }
                    events.ScheduleEvent(EVENT_DEATH_GRIP, 35000);
                    break;
                }
                case EVENT_NECROTIC_STRIKE:
                {
                    DoCast(me->getVictim(), SPELL_NECROTIC_STRIKE);
                    events.ScheduleEvent(EVENT_NECROTIC_STRIKE, 6000);
                    break;
                }
                case EVENT_PLAGUE_STRIKE:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                        DoCast(pUnit, SPELL_PLAGUE_STRIKE);
                    events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 7000);
                    break;
                }

            }
        }

        void HandleHunterEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAN_CAST_DISENGAGE:
                {
                    bCanCastDisengage = true;
                    break;
                }
                case EVENT_SHOOT:
                {
                    DoCast(me->getVictim(), RAID_MODE<uint32>(SPELL_SHOOT_10, SPELL_SHOOT_25, SPELL_SHOOT_10, SPELL_SHOOT_25));
                    events.ScheduleEvent(EVENT_SHOOT, 2000);
                    break;
                }
            }
        }

        void HandlePaladinEvents()
        {
            Creature *valkyrHerald;
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAN_CAST_RADIANCE_AURA:
                {
                    bCanCastRadianceAura = true;
                    break;
                }
                case EVENT_FLASH_OF_LIGHT:
                {
                    if ((valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 40.0f)) && urand(0, 1))
                    {
                        DoCast(valkyrHerald, SPELL_FLASH_OF_LIGHT);
                    }
                    else
                    {
                        std::list<Creature*> others;
                        GetCreatureListWithEntryInGrid(others, me, NPC_SEVERED_ESSENCE, 40.0f);
                        Unit *pMob = 0;
                        for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            if (!pMob || pMob->GetHealthPct() < (*itr)->GetHealthPct())
                                pMob = (*itr);
                        if (!pMob)
                            pMob = valkyrHerald;
                        if (pMob)
                            DoCast(pMob, SPELL_FLASH_OF_LIGHT);
                    }
                    events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, 5000);
                    break;
                }
                case EVENT_CLEANSE:
                {
                    if (valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 30.0f))
                        DoCast(valkyrHerald, SPELL_CLEANSE);
                    events.ScheduleEvent(EVENT_CLEANSE, 5000);
                    break;
                }
                case EVENT_RADIANCE_AURA:
                {
                    DoCast(me, SPELL_RADIANCE_AURA);
                    break;
                }
            }
        }

        void HandlePriestEvents()
        {
            Creature *valkyrHerald;
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_RENEW:
                {
                    if ((valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 40.0f)) && urand(0, 1))
                    {
                        DoCast(valkyrHerald, SPELL_RENEW);
                    }
                    else
                    {
                        std::list<Creature*> others;
                        GetCreatureListWithEntryInGrid(others, me, NPC_SEVERED_ESSENCE, 40.0f);
                        Unit *pMob = 0;
                        for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            if (!((*itr)->HasAura(SPELL_RENEW)) && (!pMob || pMob->GetHealthPct() < (*itr)->GetHealthPct()))
                                pMob = (*itr);
                        if (!pMob)
                        {
                            Aura *pMobAura;
                            for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            {
                                if (!pMob && (*itr)->HasAura(SPELL_RENEW))
                                {
                                    pMob = (*itr);
                                    continue;
                                }
                                if ((*itr)->HasAura(SPELL_RENEW) &&
                                    ((pMobAura = (*itr)->GetAura(SPELL_RENEW)) && pMobAura->GetDuration() < pMob->GetAura(SPELL_RENEW)->GetDuration()))
                                    pMob = (*itr);
                            }
                        }
                        if (!pMob)
                            pMob = valkyrHerald;
                        if (pMob)
                            DoCast(pMob, SPELL_RENEW);
                    }
                    events.ScheduleEvent(EVENT_RENEW, 5000);
                    break;
                }
                case EVENT_GREATER_HEAL:
                {
                    if ((valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 40.0f)) && urand(0, 1))
                    {
                        DoCast(valkyrHerald, SPELL_GREATER_HEAL);
                    }
                    else
                    {
                        std::list<Creature*> others;
                        GetCreatureListWithEntryInGrid(others, me, NPC_SEVERED_ESSENCE, 40.0f);
                        Unit *pMob = 0;
                        for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            if (!pMob || pMob->GetHealthPct() < (*itr)->GetHealthPct())
                                pMob = (*itr);
                        if (!pMob)
                            pMob = valkyrHerald;
                        if (pMob)
                            DoCast(pMob, SPELL_GREATER_HEAL);
                    }
                    events.ScheduleEvent(EVENT_GREATER_HEAL, 5000);
                    break;
                }
            }
        }


        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);

            switch (playerClass)
            {
                case CLASS_DRUID:
                    HandleDruidEvents();
                    break;
                case CLASS_WARLOCK:
                    HandleWarlockEvents();
                case CLASS_SHAMAN:
                    HandleShamanEvents();
                case CLASS_ROGUE:
                    HandleRogueEvents();
                case CLASS_MAGE:
                    HandleMageEvents();
                case CLASS_WARRIOR:
                    HandleWarriorEvents();
                case CLASS_DEATH_KNIGHT:
                    HandleDeathKnightEvents();
                case CLASS_HUNTER:
                    HandleHunterEvents();
                case CLASS_PALADIN:
                    HandlePaladinEvents();
                case CLASS_PRIEST:
                    HandlePriestEvents();
                default:
                    break;
            }
            DoMeleeAttackIfReady();
        }
        private:
            uint8 playerClass;
            InstanceScript *instance;
            EventMap events;
            uint64 uiOwnerId;
            bool bCanCastReplenishingRains;
            bool bCanCastDisengage;
            bool bCanCastRadianceAura;
    };

};

void AddSC_icecrown_citadel()
{
    //new npc_cult_fanatic_and_adherent();
    new go_icecrown_teleporter();
    new npc_frost_freeze_trap();
    new spell_icc_spirit_alarm();
    new spell_coldflame_trap();
    new npc_deathspeaker_high_priest();
    new spell_icc_dark_reckoning();
    new npc_val_kyr_herald();
    new npc_severed_essence();
    new npc_rotting_frost_giant();
    new spell_frost_giant_death_plague();
    new at_icc_saurfang_portal();
    new at_icc_shutdown_traps();
}
