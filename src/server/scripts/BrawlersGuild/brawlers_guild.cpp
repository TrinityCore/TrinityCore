#include "AchievementMgr.h"
#include "BrawlersGuild.h"
#include "ScriptedGossip.h"
#include "Creature.h"

// 68408, 67267
class npc_brawlers_guild_queue : public CreatureScript
{
public:
    npc_brawlers_guild_queue() : CreatureScript("npc_brawlers_guild_queue") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player)
        {
             auto ok = true;

             if (player->GetTeamId() == TEAM_ALLIANCE && !player->HasAchieved(ACHIEVEMENT_FIRST_RULE_A))
                 ok = false;

             if (player->GetTeamId() == TEAM_HORDE && !player->HasAchieved(ACHIEVEMENT_FIRST_RULE_H))
                 ok = false;

            if (player->HasAchieved(ACHIEVEMENT_FIRST_RULE_H) || player->HasAchieved(ACHIEVEMENT_FIRST_RULE_A))
            {
                AddGossipItemFor(player, 15284, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, 15284, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            }

            player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(creature), creature->GetGUID());
        }

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        if (player)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
               if (BrawlersGuild* brawlerGuild = player->GetBrawlerGuild())
                   brawlerGuild->AddPlayer(player);
                CloseGossipMenuFor(player);
            }
        }

        return true;
    }

    struct npc_brawlers_guild_queueAI : ScriptedAI
    {
        npc_brawlers_guild_queueAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        { }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brawlers_guild_queueAI(creature);
    }
};


// 68323
class npc_bizmo : public CreatureScript
{
public:
    npc_bizmo() : CreatureScript("npc_bizmo") { }

    struct npc_bizmoAI : public ScriptedAI
    {
        npc_bizmoAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            (true);
            events.Reset();
            me->Mount(44634);
            if (BrawlersGuild* brawlerGuild = me->GetBrawlerGuild())
                brawlerGuild->SetAnnouncer(me->GetGUID());
            me->GetMotionMaster()->MovePath(11854502, true);
        }

        void SetData(uint32 rank, uint32 guid) override
        {
            switch (rank)
            {
            case NPC_OOLISS:
                Talk(11);
                break;
            case NPC_DIPPY:
                Talk(14);
                break;
            case NPC_BILL_THE_JANITOR:
                Talk(15);
                break;
            case NPC_SANORIAK:
                Talk(16);
                break;
            case NPC_MASTER_PAKU:
                Talk(17);
                break;
            case NPC_DOOMFLIPPER:
                Talk(18);
                break;
            case NPC_SPLAT:
                Talk(19);
                break;
            case NPC_SHADOWMASTER:
                Talk(20);
                break;
            case NPC_JOHNNY:
                Talk(21);
                break;
            case NPC_BURNSTACHIO:
                Talk(22);
                break;
            case NPC_MEATBALL:
                Talk(23);
                break;
            case NPC_MAX_MEHABLAST:
                Talk(24);
                break;
            case NPC_STITCHES:
                Talk(25);
                break;
            case NPC_THWACK_U:
                Talk(26);
                break;
            case NPC_RAZORGRIN:
                Talk(27);
                break;
            case NPC_FIVE_GNOMES:
                Talk(28);
                break;
            case NPC_BLACKMANGE:
                Talk(29);
                break;
            case NPC_TOPPS:
                Talk(30);
                break;
            case NPC_MILLIE:
                Talk(31);
                break;
            case NPC_CARL:
                Talk(32);
                break;
            case NPC_OGREWATCH:
                Talk(33);
                break;
            case NPC_NIBBLEH:
                Talk(34);
                break;
            case NPC_SERPENT:
                Talk(35);
                break;
            case NPC_RAYD:
                Talk(36);
                break;
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bizmoAI(creature);
    }
};

// 67260
class npc_bossy : public CreatureScript
{
public:
    npc_bossy() : CreatureScript("npc_bossy") { }

    struct npc_bossyAI : public ScriptedAI
    {
        npc_bossyAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            (true);
            events.Reset();
            if (BrawlersGuild* brawlerGuild = me->GetBrawlerGuild())
                brawlerGuild->SetAnnouncer(me->GetGUID());
            me->GetMotionMaster()->MovePath(11854503, true);
        }

        void SetData(uint32 rank, uint32 guid) override
        {
            switch (rank)
            {
            case NPC_OOLISS:
                Talk(11);
                break;
            case NPC_DIPPY:
                Talk(14);
                break;
            case NPC_BILL_THE_JANITOR:
                Talk(15);
                break;
            case NPC_SANORIAK:
                Talk(16);
                break;
            case NPC_MASTER_PAKU:
                Talk(17);
                break;
            case NPC_DOOMFLIPPER:
                Talk(18);
                break;
            case NPC_SPLAT:
                Talk(19);
                break;
            case NPC_SHADOWMASTER:
                Talk(20);
                break;
            case NPC_JOHNNY:
                Talk(21);
                break;
            case NPC_BURNSTACHIO:
                Talk(22);
                break;
            case NPC_MEATBALL:
                Talk(23);
                break;
            case NPC_MAX_MEHABLAST:
                Talk(24);
                break;
            case NPC_STITCHES:
                Talk(25);
                break;
            case NPC_THWACK_U:
                Talk(26);
                break;
            case NPC_RAZORGRIN:
                Talk(27);
                break;
            case NPC_FIVE_GNOMES:
                Talk(28);
                break;
            case NPC_BLACKMANGE:
                Talk(29);
                break;
            case NPC_TOPPS:
                Talk(30);
                break;
            case NPC_MILLIE:
                Talk(31);
                break;
            case NPC_CARL:
                Talk(32);
                break;
            case NPC_OGREWATCH:
                Talk(33);
                break;
            case NPC_NIBBLEH:
                Talk(34);
                break;
            case NPC_SERPENT:
                Talk(35);
                break;
            case NPC_RAYD:
                Talk(36);
                break;
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bossyAI(creature);
    }
};

class spell_queued_for_brawl : public SpellScriptLoader
{
public:
    spell_queued_for_brawl() : SpellScriptLoader("spell_queued_for_brawl") { }

    class spell_queued_for_brawl_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_queued_for_brawl_AuraScript);

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (BrawlersGuild* brawlerGuild = GetUnitOwner()->GetBrawlerGuild())
                if (!brawlerGuild->IsPlayerInBrawl(GetOwner()->ToPlayer()))
                  brawlerGuild->RemovePlayer(GetOwner()->GetGUID());
        }

        void Register() override
        {
            AfterEffectRemove += static_cast<EffectApplyHandler>(AuraEffectRemoveFn(spell_queued_for_brawl_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL));
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_queued_for_brawl_AuraScript();
    }
};

// 93228, 93195, 93194, 144363
class brawl_invitation_item : public ItemScript
{
public:
    brawl_invitation_item() : ItemScript("brawl_invitation_item") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid /*castId*/) override
    {
        if (!player || !item)
            return false;

        if (player->HasAchieved(ACHIEVEMENT_FIRST_RULE_A) || player->HasAchieved(ACHIEVEMENT_FIRST_RULE_H))
            return false;

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            if (auto achievementEntry = sAchievementStore.LookupEntry(ACHIEVEMENT_FIRST_RULE_A))
                player->CompletedAchievement(achievementEntry);

            player->CastSpell(player, SPELL_ALLIANCE_SOUND, true);
        }
        else
        {
            if (auto achievementEntry = sAchievementStore.LookupEntry(ACHIEVEMENT_FIRST_RULE_H))
                player->CompletedAchievement(achievementEntry);

            player->CastSpell(player, SPELL_HORDE_SOUND, true);

            player->DestroyItem(player->GetEntry(), 1, true);
        }
        return true;
    }
};

void AddSC_the_brawlers_guild()
{
    new npc_brawlers_guild_queue();
    new npc_bizmo();
    new npc_bossy();
    new spell_queued_for_brawl();
    new brawl_invitation_item();
}
