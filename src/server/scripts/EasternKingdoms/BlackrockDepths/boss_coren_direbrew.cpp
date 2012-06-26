/*######
## BrewFest Event
######*/

#include "ScriptPCH.h"
#include "LFGMgr.h"
/*####
## brewfest_trigger 2
####*/

enum eBrewfestBarkQuests
{
    BARK_FOR_THE_THUNDERBREWS       = 11294,
    BARK_FOR_TCHALIS_VOODOO_BREWERY = 11408,
    BARK_FOR_THE_BARLEYBREWS        = 11293,
    BARK_FOR_DROHNS_DISTILLERY      = 11407,

    SPELL_RAMSTEIN_SWIFT_WORK_RAM   = 43880,
    SPELL_BREWFEST_RAM              = 43883,
    SPELL_RAM_FATIGUE               = 43052,
    SPELL_SPEED_RAM_GALLOP          = 42994,
    SPELL_SPEED_RAM_CANTER          = 42993,
    SPELL_SPEED_RAM_TROT            = 42992,
    SPELL_SPEED_RAM_NORMAL          = 43310,
    SPELL_SPEED_RAM_EXHAUSED        = 43332,

    NPC_SPEED_BUNNY_GREEN           = 24263,
    NPC_SPEED_BUNNY_YELLOW          = 24264,
    NPC_SPEED_BUNNY_RED             = 24265,
    NPC_BARKER_BUNNY_1              = 24202,
    NPC_BARKER_BUNNY_2              = 24203,
    NPC_BARKER_BUNNY_3              = 24204,
    NPC_BARKER_BUNNY_4              = 24205,
};

class npc_brewfest_trigger : public CreatureScript
{
public:
    npc_brewfest_trigger() : CreatureScript("npc_brewfest_trigger") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_brewfest_triggerAI(creature);
    }

    struct npc_brewfest_triggerAI : public ScriptedAI
    {
        npc_brewfest_triggerAI(Creature* c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit *who)
        {
            if (!who)
                return;

            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (!(CAST_PLR(who)->GetAura(SPELL_BREWFEST_RAM)))
                    return;

                if (CAST_PLR(who)->GetQuestStatus(BARK_FOR_THE_THUNDERBREWS) == QUEST_STATUS_INCOMPLETE||
                    CAST_PLR(who)->GetQuestStatus(BARK_FOR_TCHALIS_VOODOO_BREWERY) == QUEST_STATUS_INCOMPLETE||
                    CAST_PLR(who)->GetQuestStatus(BARK_FOR_THE_BARLEYBREWS) == QUEST_STATUS_INCOMPLETE||
                    CAST_PLR(who)->GetQuestStatus(BARK_FOR_DROHNS_DISTILLERY) == QUEST_STATUS_INCOMPLETE)
                {
                    uint32 creditMarkerId = me->GetEntry();
                    if ((creditMarkerId >= 24202) && (creditMarkerId <= 24205))
                    {
                        // 24202: Brewfest Barker Bunny 1, 24203: Brewfest Barker Bunny 2, 24204: Brewfest Barker Bunny 3, 24205: Brewfest Barker Bunny 4
                        if (!CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_THE_BARLEYBREWS, creditMarkerId)||
                            !CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_THE_THUNDERBREWS, creditMarkerId)||
                            !CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_DROHNS_DISTILLERY, creditMarkerId)||
                            !CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_TCHALIS_VOODOO_BREWERY, creditMarkerId))
                            CAST_PLR(who)->KilledMonsterCredit(creditMarkerId, me->GetGUID());
                        // Caso para quest 11293 que no se completa teniendo todas las marcas
                        if (CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_THE_BARLEYBREWS, NPC_BARKER_BUNNY_1)&&
                            CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_THE_BARLEYBREWS, NPC_BARKER_BUNNY_2)&&
                            CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_THE_BARLEYBREWS, NPC_BARKER_BUNNY_3)&&
                            CAST_PLR(who)->GetReqKillOrCastCurrentCount(BARK_FOR_THE_BARLEYBREWS, NPC_BARKER_BUNNY_4))
                            CAST_PLR(who)->CompleteQuest(BARK_FOR_THE_BARLEYBREWS);
                    }
                }
            }
        }
    };
};

/*####
## npc_brewfest_apple_trigger
####*/

class npc_brewfest_apple_trigger : public CreatureScript
{
public:
    npc_brewfest_apple_trigger() : CreatureScript("npc_brewfest_apple_trigger") { }

    struct npc_brewfest_apple_triggerAI : public ScriptedAI
    {
        npc_brewfest_apple_triggerAI(Creature* c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit *who)
        {
            Player *player = who->ToPlayer();
            if (!player)
                return;
            if (player->HasAura(SPELL_RAM_FATIGUE) && me->GetDistance(player->GetPositionX(),player->GetPositionY(),player->GetPositionZ()) <= 7.5f)
                player->RemoveAura(SPELL_RAM_FATIGUE);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_brewfest_apple_triggerAI(creature);
    }
};

/*####
## spell_brewfest_speed
####*/

class spell_brewfest_speed : public SpellScriptLoader
{
public:
    spell_brewfest_speed() : SpellScriptLoader("spell_brewfest_speed") {}

    class spell_brewfest_speed_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_brewfest_speed_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_RAM_FATIGUE)) //Усталость барана
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_RAMSTEIN_SWIFT_WORK_RAM)) //Стремительный рабочий баран Рамштайна
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_BREWFEST_RAM)) // Арендованный скаковой баран
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SPEED_RAM_GALLOP)) //42994
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SPEED_RAM_CANTER)) // 42993
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SPEED_RAM_TROT)) // 42992
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SPEED_RAM_NORMAL)) // 43310
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SPEED_RAM_GALLOP))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SPEED_RAM_EXHAUSED)) // Изнемогший баран
                return false;
            return true;
        }

        void HandlePeriodicTick(AuraEffect const* aurEff)
        {
            if (GetId() == SPELL_SPEED_RAM_EXHAUSED)
                return;

            Player* pCaster = GetCaster()->ToPlayer();
            if (!pCaster)
                return;
            int i;
            switch (GetId())
            {
            case SPELL_SPEED_RAM_GALLOP:
                for (i = 0; i < 5; i++)
                    pCaster->AddAura(SPELL_RAM_FATIGUE,pCaster);
                break;
            case SPELL_SPEED_RAM_CANTER:
                pCaster->AddAura(SPELL_RAM_FATIGUE,pCaster);
                break;
            case SPELL_SPEED_RAM_TROT:
                if (pCaster->HasAura(SPELL_RAM_FATIGUE))
                    if (pCaster->GetAura(SPELL_RAM_FATIGUE)->GetStackAmount() <= 2)
                        pCaster->RemoveAura(SPELL_RAM_FATIGUE);
                    else
                        pCaster->GetAura(SPELL_RAM_FATIGUE)->ModStackAmount(-2);
                break;
            case SPELL_SPEED_RAM_NORMAL:
                if (pCaster->HasAura(SPELL_RAM_FATIGUE))
                    if (pCaster->GetAura(SPELL_RAM_FATIGUE)->GetStackAmount() <= 4)
                        pCaster->RemoveAura(SPELL_RAM_FATIGUE);
                    else
                        pCaster->GetAura(SPELL_RAM_FATIGUE)->ModStackAmount(-4);
                break;
            }

            switch (aurEff->GetId())
            {
            case SPELL_SPEED_RAM_TROT:
                if (aurEff->GetTickNumber() == 4)
                    pCaster->KilledMonsterCredit(NPC_SPEED_BUNNY_GREEN, 0);
                break;
            case SPELL_SPEED_RAM_CANTER:
                if (aurEff->GetTickNumber() == 8)
                    pCaster->KilledMonsterCredit(NPC_SPEED_BUNNY_YELLOW, 0);
                break;
            case SPELL_SPEED_RAM_GALLOP:
                if (aurEff->GetTickNumber() == 8)
                    pCaster->KilledMonsterCredit(NPC_SPEED_BUNNY_RED, 0);
                break;
            }
            if (pCaster->HasAura(SPELL_RAM_FATIGUE))
                if (pCaster->GetAura(SPELL_RAM_FATIGUE)->GetStackAmount() >= 100)
                    pCaster->CastSpell(pCaster,SPELL_SPEED_RAM_EXHAUSED, false);
        }

        void OnRemove(AuraEffect const * aurEff, AuraEffectHandleModes /*mode*/)
        {
            Player* pCaster = GetCaster()->ToPlayer();
            if (!pCaster)
                return;
            if (!pCaster->HasAura(SPELL_BREWFEST_RAM) || !pCaster->HasAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM))
                return;
            if (GetId() == SPELL_SPEED_RAM_EXHAUSED)
            {
                if (pCaster->HasAura(SPELL_RAM_FATIGUE))
                    pCaster->GetAura(SPELL_RAM_FATIGUE)->ModStackAmount(-15);
            } else if (!pCaster->HasAura(SPELL_RAM_FATIGUE) || pCaster->GetAura(SPELL_RAM_FATIGUE)->GetStackAmount() < 100)

                switch (GetId())
            {
                case SPELL_SPEED_RAM_GALLOP:
                    if (!pCaster->HasAura(SPELL_SPEED_RAM_EXHAUSED))
                        pCaster->CastSpell(pCaster,SPELL_SPEED_RAM_CANTER, false);
                    break;
                case SPELL_SPEED_RAM_CANTER:
                    if (!pCaster->HasAura(SPELL_SPEED_RAM_GALLOP))
                        pCaster->CastSpell(pCaster,SPELL_SPEED_RAM_TROT, false);
                    break;
                case SPELL_SPEED_RAM_TROT:
                    if (!pCaster->HasAura(SPELL_SPEED_RAM_CANTER))
                        pCaster->CastSpell(pCaster,SPELL_SPEED_RAM_NORMAL, false);
                    break;
            }
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Player* pCaster = GetCaster()->ToPlayer();

            if (!pCaster)
                return;

            switch (GetId())
            {
            case SPELL_SPEED_RAM_GALLOP:
                pCaster->GetAura(SPELL_SPEED_RAM_GALLOP)->SetDuration(4000);
                break;
            case SPELL_SPEED_RAM_CANTER:
                pCaster->GetAura(SPELL_SPEED_RAM_CANTER)->SetDuration(4000);
                break;
            case SPELL_SPEED_RAM_TROT:
                pCaster->GetAura(SPELL_SPEED_RAM_TROT)->SetDuration(4000);
                break;
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_brewfest_speed_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_speed_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(spell_brewfest_speed_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_brewfest_speed_AuraScript();
    }
};

/*######
## Q Пей до дна!
######*/

enum BrewfestQuestChugAndChuck
{
    QUEST_CHUG_AND_CHUCK_A      = 12022,
    QUEST_CHUG_AND_CHUCK_H      = 12191,
    
    NPC_BREWFEST_STOUT          = 24108
};

class item_brewfest_ChugAndChuck : public ItemScript
{
public:
    item_brewfest_ChugAndChuck() : ItemScript("item_brewfest_ChugAndChuck") { }

    bool OnUse(Player* player, Item* pItem, const SpellCastTargets & /*pTargets*/)
    {
        if (player->GetQuestStatus(QUEST_CHUG_AND_CHUCK_A) == QUEST_STATUS_INCOMPLETE
            || player->GetQuestStatus(QUEST_CHUG_AND_CHUCK_H) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* pStout = player->FindNearestCreature(NPC_BREWFEST_STOUT, 10.0f)) // spell range
            {
                return false;
            } else
                player->SendEquipError(EQUIP_ERR_OUT_OF_RANGE, pItem, NULL);
        } else
            player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW ,pItem, NULL);
        return true;
    }
};

class item_brewfest_ram_reins : public ItemScript
{
public:
    item_brewfest_ram_reins() : ItemScript("item_brewfest_ram_reins") { }

    bool OnUse(Player* player, Item* pItem, const SpellCastTargets & /*pTargets*/)
    {
        if ((player->HasAura(SPELL_BREWFEST_RAM) || player->HasAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM)) && !player->HasAura(SPELL_SPEED_RAM_EXHAUSED))
        {
            if (player->HasAura(SPELL_SPEED_RAM_NORMAL))
                player->CastSpell(player,SPELL_SPEED_RAM_TROT,false);
            else if (player->HasAura(SPELL_SPEED_RAM_TROT))
            {
                if (player->GetAura(SPELL_SPEED_RAM_TROT)->GetDuration() < 3000)
                    player->GetAura(SPELL_SPEED_RAM_TROT)->SetDuration(4000);
                else
                    player->CastSpell(player,SPELL_SPEED_RAM_CANTER,false);
            } else if (player->HasAura(SPELL_SPEED_RAM_CANTER))
            {
                if (player->GetAura(SPELL_SPEED_RAM_CANTER)->GetDuration() < 3000)
                    player->GetAura(SPELL_SPEED_RAM_CANTER)->SetDuration(4000);
                else
                    player->CastSpell(player,SPELL_SPEED_RAM_GALLOP,false);
            } else if (player->HasAura(SPELL_SPEED_RAM_GALLOP))
                player->GetAura(SPELL_SPEED_RAM_GALLOP)->SetDuration(4000);
        }
        else
            player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW ,pItem, NULL);

        return true;
    }
};

/*####
## npc_brewfest_keg_thrower
####*/

enum BrewfestKegThrower
{
    SPELL_THROW_KEG     = 43660, // Хмельной фестиваль - брошенный бочонок - DND
    ITEM_BREWFEST_KEG   = 33797 // Переносной холодильник для пива
};

class npc_brewfest_keg_thrower : public CreatureScript
{
public:
    npc_brewfest_keg_thrower() : CreatureScript("npc_brewfest_keg_thrower") { }

    struct npc_brewfest_keg_throwerAI : public ScriptedAI
    {
        npc_brewfest_keg_throwerAI(Creature* c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit *who)
        {
            Player *player = who->ToPlayer();
            if (!player)
                return;
            if ((player->HasAura(SPELL_BREWFEST_RAM) || player->HasAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM))
                && me->GetDistance(player->GetPositionX(),player->GetPositionY(),player->GetPositionZ()) <= 25.0f
                && !player->HasItemCount(ITEM_BREWFEST_KEG,1))
            {
                me->CastSpell(player,SPELL_THROW_KEG,false);
                me->CastSpell(player,42414,false);
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_brewfest_keg_throwerAI(creature);
    }
};

/*####
## Туда и обратно
####*/

enum BrewfestKegReceiver
{
    SPELL_CREATE_TICKETS            = 44501, // Holiday - Brewfest - Daily - Relay Race - Create Tickets - DND
    
    QUEST_THERE_AND_BACK_AGAIN_A    = 11122,
    QUEST_THERE_AND_BACK_AGAIN_H    = 11412,
    
    NPC_BREWFEST_DELIVERY_BUNNY     = 24337 // [DND] Brewfest Delivery Bunny
};

class npc_brewfest_keg_receiver : public CreatureScript
{
public:
    npc_brewfest_keg_receiver() : CreatureScript("npc_brewfest_keg_receiver") { }

    struct npc_brewfest_keg_receiverAI : public ScriptedAI
    {
        npc_brewfest_keg_receiverAI(Creature* c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit *who)
        {
            Player *player = who->ToPlayer();
            if (!player)
                return;

            if ((player->HasAura(SPELL_BREWFEST_RAM) || player->HasAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM))
                && me->GetDistance(player->GetPositionX(),player->GetPositionY(),player->GetPositionZ()) <= 5.0f
                && player->HasItemCount(ITEM_BREWFEST_KEG,1))
            {
                player->CastSpell(me,SPELL_THROW_KEG,true);
                player->DestroyItemCount(ITEM_BREWFEST_KEG,1,true);
                if (player->HasAura(SPELL_BREWFEST_RAM))
                    player->GetAura(SPELL_BREWFEST_RAM)->SetDuration(player->GetAura(SPELL_BREWFEST_RAM)->GetDuration() + 30000);
                if (player->HasAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM))
                    player->GetAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM)->SetDuration(player->GetAura(SPELL_RAMSTEIN_SWIFT_WORK_RAM)->GetDuration() + 30000);
                if (player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_A)
                    || player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_H))
                {
                    player->CastSpell(player,SPELL_CREATE_TICKETS,true);
                }
                else
                {
                    player->KilledMonsterCredit(NPC_BREWFEST_DELIVERY_BUNNY,0);
                    if (player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_A) == QUEST_STATUS_INCOMPLETE)
                        player->AreaExploredOrEventHappens(QUEST_THERE_AND_BACK_AGAIN_A);
                    if (player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_H) == QUEST_STATUS_INCOMPLETE)
                        player->AreaExploredOrEventHappens(QUEST_THERE_AND_BACK_AGAIN_H);
                    if (player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_A) == QUEST_STATUS_COMPLETE
                        || player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_H) == QUEST_STATUS_COMPLETE)
                        player->RemoveAura(SPELL_BREWFEST_RAM);
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_brewfest_keg_receiverAI(creature);
    }
};

/*####
## npc_brewfest_ram_master
####*/

#define GOSSIP_ITEM_RAM "Do you have additional work?"
#define GOSSIP_ITEM_RAM_REINS "Give me another Ram Racing Reins"
#define SPELL_BREWFEST_SUMMON_RAM 43720 // Trigger Brewfest Racing Ram - Relay Race - Intro

class npc_brewfest_ram_master : public CreatureScript
{
public:
    npc_brewfest_ram_master() : CreatureScript("npc_brewfest_ram_master") { }

    bool OnGossipHello(Player *player, Creature *pCreature)
    {
        if (pCreature->isQuestGiver())
            player->PrepareQuestMenu(pCreature->GetGUID());

        if (player->HasSpellCooldown(SPELL_BREWFEST_SUMMON_RAM)
            && !player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_A)
            && !player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_H)
            && (player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_A) == QUEST_STATUS_INCOMPLETE
            || player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_H) == QUEST_STATUS_INCOMPLETE))
            player->RemoveSpellCooldown(SPELL_BREWFEST_SUMMON_RAM);

        if (!player->HasAura(SPELL_BREWFEST_RAM) && ((player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_A) == QUEST_STATUS_INCOMPLETE
            || player->GetQuestStatus(QUEST_THERE_AND_BACK_AGAIN_H) == QUEST_STATUS_INCOMPLETE
            || (!player->HasSpellCooldown(SPELL_BREWFEST_SUMMON_RAM) &&
            (player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_A)
            || player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_H))))))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RAM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if ((player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_A)
            || player->GetQuestRewardStatus(QUEST_THERE_AND_BACK_AGAIN_H))
            && !player->HasItemCount(33306,1,true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RAM_REINS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(384, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            if (player->HasItemCount(ITEM_BREWFEST_KEG,1))
                player->DestroyItemCount(ITEM_BREWFEST_KEG,1,true);
            player->CastSpell(player,SPELL_BREWFEST_SUMMON_RAM,true);
            player->AddSpellCooldown(SPELL_BREWFEST_SUMMON_RAM,0,time(NULL) + 18*60*60);
        }
        if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
        {
            player->CastSpell(player,44371,false);
        }
        return true;
    }
};

// Dark Iron Guzzler in the Brewfest achievement 'Down With The Dark Iron'
enum DarkIronGuzzler
{
    NPC_DARK_IRON_GUZZLER       = 23709,
    NPC_DARK_IRON_HERALD        = 24536,
    NPC_DARK_IRON_SPAWN_BUNNY   = 23894,
 
    NPC_FESTIVE_KEG_1           = 23702, // Thunderbrew Festive Keg
    NPC_FESTIVE_KEG_2           = 23700, // Barleybrew Festive Keg
    NPC_FESTIVE_KEG_3           = 23706, // Gordok Festive Keg
    NPC_FESTIVE_KEG_4           = 24373, // T'chalis's Festive Keg
    NPC_FESTIVE_KEG_5           = 24372, // Drohn's Festive Keg
 
    SPELL_GO_TO_NEW_TARGET      = 42498,
    SPELL_ATTACK_KEG            = 42393,
    SPELL_RETREAT               = 42341,
    SPELL_DRINK                 = 42436,
 
    SAY_RANDOM              = 0,
};
 
class npc_dark_iron_guzzler : public CreatureScript
{
public:
    npc_dark_iron_guzzler() : CreatureScript("npc_dark_iron_guzzler") { }
 
    CreatureAI *GetAI(Creature* creature) const
    {
        return new npc_dark_iron_guzzlerAI(creature);
    }
 
    struct npc_dark_iron_guzzlerAI : public ScriptedAI
    {
        npc_dark_iron_guzzlerAI(Creature* creature) : ScriptedAI(creature) { }
 
        bool atKeg;
        bool playersLost;
        bool barleyAlive;
        bool thunderAlive;
        bool gordokAlive;
        bool drohnAlive;
        bool tchaliAlive;
 
        uint32 AttackKegTimer;
        uint32 TalkTimer;
 
        void Reset()
        {
            AttackKegTimer = 5000;
            TalkTimer = (urand(1000, 120000));
            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }
 
        void IsSummonedBy(Unit* summoner)
        {
            // Only cast the spell on spawn
            DoCast(me, SPELL_GO_TO_NEW_TARGET);
        }
 
        // These values are set through SAI - when a Festive Keg dies it will set data to all Dark Iron Guzzlers within 3 yards (the killers)
        void SetData(uint32 type, uint32 data)
        {
            if (type == 10 && data == 10)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                thunderAlive = false;
            }
 
            if (type == 11 && data == 11)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                barleyAlive = false;
            }
 
            if (type == 12 && data == 12)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                gordokAlive = false;
            }
 
            if (type == 13 && data == 13)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                drohnAlive = false;
            }
 
            if (type == 14 && data == 14)
            {
                DoCast(me, SPELL_GO_TO_NEW_TARGET);
                tchaliAlive = false;
            }
        }
 
        // As you can see here we do not have to use a spellscript for this
        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_DRINK)
            {
                // Fake death - it's only visual!
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);
                me->StopMoving();
 
                // Time based on information from videos
                me->DespawnOrUnsummon(7000);
            }
 
            // Retreat - run back
            if (spell->Id == SPELL_RETREAT)
            {
                // Remove walking flag so we start running
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
 
                if (me->GetAreaId() == 1296)
                {
                    me->GetMotionMaster()->MovePoint(1, 1197.63f, -4293.571f, 21.243f);
                }
                else if (me->GetAreaId() == 1)
                {
                     me->GetMotionMaster()->MovePoint(2, -5152.3f, -603.529f, 398.356f);
                }
            }
 
            if (spell->Id == SPELL_GO_TO_NEW_TARGET)
            {
                // If we're at Durotar we target different kegs if we are at at Dun Morogh
                if (me->GetAreaId() == 1296)
                {
                    if (drohnAlive && gordokAlive && tchaliAlive)
                    {
                        switch (urand(0, 2))
                        {
                            case 0: // Gordok Festive Keg
                                me->GetMotionMaster()->MovePoint(4, 1220.86f, -4297.37f, 21.192f);
                                break;
                            case 1: // Drohn's Festive Keg
                                me->GetMotionMaster()->MovePoint(5, 1185.98f, -4312.98f, 21.294f);
                                break;
                            case 2: // Ti'chali's Festive Keg
                                me->GetMotionMaster()->MovePoint(6, 1184.12f, -4275.21f, 21.191f);
                                break;
                        }
                    }
                    else if (!drohnAlive)
                    {
                        switch (urand(0, 1))
                        {
                            case 0: // Gordok Festive Keg
                                me->GetMotionMaster()->MovePoint(4, 1220.86f, -4297.37f, 21.192f);
                                break;
                            case 1: // Ti'chali's Festive Keg
                                me->GetMotionMaster()->MovePoint(6, 1184.12f, -4275.21f, 21.191f);
                                break;
                        }
                    }
                    else if (!gordokAlive)
                    {
                        switch (urand(0, 1))
                        {
                            case 0: // Drohn's Festive Keg
                                me->GetMotionMaster()->MovePoint(5, 1185.98f, -4312.98f, 21.294f);
                                break;
                            case 1: // Ti'chali's Festive Keg
                                me->GetMotionMaster()->MovePoint(6, 1184.12f, -4275.21f, 21.191f);
                                break;
                        }
                    }
                    else if (!tchaliAlive)
                    {
                        switch (urand(0, 1))
                        {
                            case 0: // Gordok Festive Keg
                                me->GetMotionMaster()->MovePoint(4, 1220.86f, -4297.37f, 21.192f);
                                break;
                            case 1: // Drohn's Festive Keg
                                me->GetMotionMaster()->MovePoint(5, 1185.98f, -4312.98f, 21.294f);
                                break;
                        }
                    }
                }
                // If we're at Dun Morogh we target different kegs if we are at Durotar
                else if (me->GetAreaId() == 1)
                {
                    if (barleyAlive && gordokAlive && thunderAlive)
                    {
                        switch (urand(0, 2))
                        {
                            case 0: // Barleybrew Festive Keg
                                me->GetMotionMaster()->MovePoint(7, -5183.67f, -599.58f, 397.177f);
                                break;
                            case 1: // Thunderbrew Festive Keg
                                me->GetMotionMaster()->MovePoint(8, -5159.53f, -629.52f, 397.213f);
                                break;
                            case 2: // Gordok Festive Keg
                                me->GetMotionMaster()->MovePoint(9, -5148.01f, -578.34f, 397.177f);
                                break;
                        }
                    }
                    else if (!barleyAlive)
                    {
                        switch (urand(0, 1))
                        {
                            case 0: // Thunderbrew Festive Keg
                                me->GetMotionMaster()->MovePoint(8, -5159.53f, -629.52f, 397.213f);
                                break;
                            case 1: // Gordok Festive Keg
                                me->GetMotionMaster()->MovePoint(9, -5148.01f, -578.34f, 397.177f);
                                break;
                        }
                    }
                    else if (!gordokAlive)
                    {
                        switch (urand(0, 1))
                        {                            
                            case 0: // Barleybrew Festive Keg
                                me->GetMotionMaster()->MovePoint(7, -5183.67f, -599.58f, 397.177f);
                                break;
                            case 1: // Thunderbrew Festive Keg
                                me->GetMotionMaster()->MovePoint(8, -5159.53f, -629.52f, 397.213f);
                                break;
                        }
                    }
                    else if (!thunderAlive)
                    {
                        switch (urand(0, 1))
                        {
                            case 0: // Barleybrew Festive Keg
                                me->GetMotionMaster()->MovePoint(7, -5183.67f, -599.58f, 397.177f);
                                break;
                            case 1: // Gordok Festive Keg
                                me->GetMotionMaster()->MovePoint(9, -5148.01f, -578.34f, 397.177f);
                                break;
                        }
                    }
                }
                atKeg = false;
            }
        }
 
        void MovementInform(uint32 Type, uint32 PointId)
        {
            if (Type != POINT_MOTION_TYPE)
                return;
 
            // Arrived at the retreat spot, we should despawn
            if (PointId == 1 || PointId == 2)
                me->DespawnOrUnsummon(1000);
 
            // Arrived at the new keg - the spell has conditions in database
            if (PointId == 4 || PointId == 5 || PointId == 6 || PointId == 7 || PointId == 8 || PointId == 9)
            {
                DoCast(SPELL_ATTACK_KEG);
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 1, 0x01); // Sit down
                atKeg = true;
            }
        }
 
        void UpdateAI(const uint32 diff)
        {
            if (!IsHolidayActive(HOLIDAY_BREWFEST))
                return;
 
            // If all kegs are dead we should retreat because we have won
            if ((!gordokAlive && !thunderAlive && !barleyAlive) || (!gordokAlive && !drohnAlive && !tchaliAlive))
            {
                DoCast(me, SPELL_RETREAT);
 
                // We are doing this because we'll have to reset our scripts when we won
                if (Creature* herald = me->FindNearestCreature(NPC_DARK_IRON_HERALD, 100.0f))
                    herald->AI()->SetData(20, 20);
 
                // Despawn all summon bunnies so they will stop summoning guzzlers
                if (Creature* spawnbunny = me->FindNearestCreature(NPC_DARK_IRON_SPAWN_BUNNY, 100.0f))
                    spawnbunny->DespawnOrUnsummon();
            }
 
            if (TalkTimer <= diff)
            {
                me->AI()->Talk(SAY_RANDOM);
                TalkTimer = (urand(44000, 120000));
            } else TalkTimer -= diff;
 
            // Only happens if we're at keg
            if (atKeg)
            {
                if (AttackKegTimer <= diff)
                {
                    DoCast(SPELL_ATTACK_KEG);
                    AttackKegTimer = 5000;
                } else AttackKegTimer -= diff;
            }
        }
    };
};

/*######
## npc_coren direbrew
######*/

enum CorenDirebrew
{
    SPELL_DISARM                = 47310, // Обезвреживание Зловещего Варева
    SPELL_DISARM_PRECAST        = 47407, // Обезвреживание Зловещего Варева (без затраты маны)
    SPELL_MOLE_MACHINE_EMERGE   = 50313, // bad id. Появление буровой установки

    NPC_ILSA_DIREBREW           = 26764,
    NPC_URSULA_DIREBREW         = 26822,
    NPC_DIREBREW_MINION         = 26776,

    EQUIP_ID_TANKARD            = 48663,
    FACTION_HOSTILE             = 736
};

#define GOSSIP_TEXT_INSULT "Insult Coren Direbrew's brew."

static Position _pos[]=
{
    {890.87f, -133.95f, -48.0f, 1.53f},
    {892.47f, -133.26f, -48.0f, 2.16f},
    {893.54f, -131.81f, -48.0f, 2.75f}
};

class npc_coren_direbrew : public CreatureScript
{
public:
    npc_coren_direbrew() : CreatureScript("npc_coren_direbrew") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INSULT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(15858, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            creature->setFaction(FACTION_HOSTILE);
            creature->AI()->AttackStart(player);
            creature->AI()->DoZoneInCombat();
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    struct npc_coren_direbrewAI : public ScriptedAI
    {
        npc_coren_direbrewAI(Creature* c) : ScriptedAI(c), _summons(me)
        {
        }

        void Reset()
        {
            me->RestoreFaction();
            me->SetCorpseDelay(90); // 1.5 minutes

            _addTimer = 20000;
            _disarmTimer = urand(10, 15) *IN_MILLISECONDS;

            _spawnedIlsa = false;
            _spawnedUrsula = false;
            _summons.DespawnAll();

            for (uint8 i = 0; i < 3; ++i)
                if (Creature* creature = me->SummonCreature(NPC_DIREBREW_MINION, _pos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
                    _add[i] = creature->GetGUID();
        }

        void EnterCombat(Unit* /*who*/)
        {
            SetEquipmentSlots(false, EQUIP_ID_TANKARD, EQUIP_ID_TANKARD, EQUIP_NO_CHANGE);

            for (uint8 i = 0; i < 3; ++i)
            {
                if (_add[i])
                {
                    Creature* creature = ObjectAccessor::GetCreature((*me), _add[i]);
                    if (creature && creature->isAlive())
                    {
                        creature->setFaction(FACTION_HOSTILE);
                        creature->SetInCombatWithZone();
                    }
                    _add[i] = 0;
                }
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            // disarm
            if (_disarmTimer <= diff)
            {
                DoCast(SPELL_DISARM_PRECAST);
                DoCastVictim(SPELL_DISARM, false);
                _disarmTimer = urand(20, 25) *IN_MILLISECONDS;
            }
            else
                _disarmTimer -= diff;

            // spawn non-elite adds
            if (_addTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    float posX, posY, posZ;
                    target->GetPosition(posX, posY, posZ);
                    target->CastSpell(target, SPELL_MOLE_MACHINE_EMERGE, true, 0, 0, me->GetGUID());
                    me->SummonCreature(NPC_DIREBREW_MINION, posX, posY, posZ, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);

                    _addTimer = 15000;
                    if (_spawnedIlsa)
                        _addTimer -= 3000;
                    if (_spawnedUrsula)
                        _addTimer -= 3000;
                }
            }
            else
                _addTimer -= diff;

            if (!_spawnedIlsa && HealthBelowPct(66))
            {
                DoSpawnCreature(NPC_ILSA_DIREBREW, 0, 0, 0, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                _spawnedIlsa = true;
            }

            if (!_spawnedUrsula && HealthBelowPct(33))
            {
                DoSpawnCreature(NPC_URSULA_DIREBREW, 0, 0, 0, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                _spawnedUrsula = true;
            }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon)
        {
            if (me->getFaction() == FACTION_HOSTILE)
            {
                summon->setFaction(FACTION_HOSTILE);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    summon->AI()->AttackStart(target);
            }

            _summons.Summon(summon);
        }

        void JustDied(Unit* /*killer*/)
        {
            _summons.DespawnAll();

            // TODO: unhack
            Map* map = me->GetMap();
            if (map && map->IsDungeon())
            {
                Map::PlayerList const& players = map->GetPlayers();
                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        if (Player* player = i->getSource())
                            if (player->GetDistance(me) < 100.0f)
                                sLFGMgr->RewardDungeonDoneFor(287, player);
            }
        }

    private:
        SummonList _summons;
        uint64 _add[3];
        uint32 _addTimer;
        uint32 _disarmTimer;
        bool _spawnedIlsa;
        bool _spawnedUrsula;
    };

    CreatureAI* GetAI(Creature* c) const
    {
        return new npc_coren_direbrewAI(c);
    }
};

/*######
## dark iron brewmaiden
######*/

enum Brewmaiden
{
    SPELL_SEND_FIRST_MUG            = 47333,
    SPELL_SEND_SECOND_MUG           = 47339,
    //SPELL_CREATE_BREW             = 47345,
    SPELL_HAS_BREW_BUFF             = 47376,
    //SPELL_HAS_BREW                = 47331,
    //SPELL_DARK_BREWMAIDENS_STUN   = 47340,
    SPELL_CONSUME_BREW              = 47377,
    SPELL_BARRELED                  = 47442,
    SPELL_CHUCK_MUG                 = 50276
};

class npc_brewmaiden : public CreatureScript
{
public:
    npc_brewmaiden() : CreatureScript("npc_brewmaiden") { }

    struct npc_brewmaidenAI : public ScriptedAI
    {
        npc_brewmaidenAI(Creature* c) : ScriptedAI(c)
        {
        }

        void Reset()
        {
            _brewTimer = 2000;
            _barrelTimer = 5000;
            _chuckMugTimer = 10000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->SetInCombatWithZone();
        }

        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 1.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                if (me->GetEntry() == NPC_URSULA_DIREBREW)
                    me->GetMotionMaster()->MoveFollow(who, 10.0f, 0.0f);
                else
                    me->GetMotionMaster()->MoveChase(who);
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            // TODO: move to DB

            if (spell->Id == SPELL_SEND_FIRST_MUG)
                target->CastSpell(target, SPELL_HAS_BREW_BUFF, true);

            if (spell->Id == SPELL_SEND_SECOND_MUG)
                target->CastSpell(target, SPELL_CONSUME_BREW, true);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (_brewTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);

                    if (target && me->GetDistance(target) > 5.0f)
                    {
                        DoCast(target, SPELL_SEND_FIRST_MUG);
                        _brewTimer = 12000;
                    }
                }
            }
            else
                _brewTimer -= diff;

            if (_chuckMugTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_CHUCK_MUG);

                _chuckMugTimer = 15000;
            }
            else
                _chuckMugTimer -= diff;

            if (me->GetEntry() == NPC_URSULA_DIREBREW)
            {
                if (_barrelTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCastVictim(SPELL_BARRELED);
                        _barrelTimer = urand(15, 18) *IN_MILLISECONDS;
                    }
                }
                else
                    _barrelTimer -= diff;
            }
            else
                DoMeleeAttackIfReady();
        }

    private:
        uint32 _brewTimer;
        uint32 _barrelTimer;
        uint32 _chuckMugTimer;
    };

    CreatureAI* GetAI(Creature* c) const
    {
        return new npc_brewmaidenAI(c);
    }
};

/*######
## go_mole_machine_console
######*/

enum MoleMachineConsole
{
    SPELL_TELEPORT = 49466 // bad id?
};

#define GOSSIP_ITEM_MOLE_CONSOLE "[PH] Please teleport me."

class go_mole_machine_console : public GameObjectScript
{
public:
    go_mole_machine_console() : GameObjectScript("go_mole_machine_console") { }

    bool OnGossipHello (Player* player, GameObject* go)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_MOLE_CONSOLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(12709, go->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 action)
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
            player->CastSpell(player, SPELL_TELEPORT, true);

        return true;
    }
};

void AddSC_boss_coren_direbrew()
{
    //
    new npc_brewfest_trigger;
    new spell_brewfest_speed;
    new npc_brewfest_apple_trigger;
    //
    new item_brewfest_ChugAndChuck;
    new item_brewfest_ram_reins;
    new npc_brewfest_keg_thrower;
    new npc_brewfest_keg_receiver;
    new npc_brewfest_ram_master;
    new npc_dark_iron_guzzler;
    //
    new npc_coren_direbrew;
    new npc_brewmaiden;
    new go_mole_machine_console;
}
