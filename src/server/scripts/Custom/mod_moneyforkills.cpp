/*
# Money For Kills #
#### A module for AzerothCore by [StygianTheBest](https://github.com/StygianTheBest/AzerothCore-Content/tree/master/Modules)
------------------------------------------------------------------------------------------------------------------
### Description ###
------------------------------------------------------------------------------------------------------------------
I created this module to award more money to players on smaller servers that don't have an AH or a lot of activity.
The player can earn a bounty on every creature killed based on the creature's level. The amounts are configurable.
They also earn larger bounties on dungeon and world bosses. To promote PVP, a player can earn a percentage of the
victim's gold on a kill. There are options to allow players in groups to get bounty rewards only if they are in
reward range of the group and an option to only reward the player that got the killing blow.
### Features ###
------------------------------------------------------------------------------------------------------------------
- Pays players bounty money for kills of players and creatures
- Bounty and other amounts can be changed in the config file
- Bounty can be paid to only the player with killing blow or all players
- Bounty can be paid to players that are near or far away from the group
- Dungeon boss kills are announced to the party
- World boss kills are announced to the world
- Player suicides are announced to the world
### Data ###
------------------------------------------------------------------------------------------------------------------
- Type: Server/Player
- Script: MoneyForKills
- Config: Yes
    - Enable/Disable Module
    - Enable Module Announce
    - Enable Killing Blow Only Bounty
    - Enable Bounty for Players Outside Reward Area
    - Set % of Gold Looted from victim on PVP kill
    - Set Bounty Multipliers for each type of kill
- SQL: No
### Version ###
------------------------------------------------------------------------------------------------------------------
- v2017.08.24 - Release
- v2017.08.31 - Added boss kills
- v2017.09.02 - Added distance check, Fixed group payment
- v2017.09.22 - Added PVPCorpseLoot as a config option
- v2017.10.11 - Fix typo in color code
### Credits ###
------------------------------------------------------------------------------------------------------------------
- [Blizzard Entertainment](http://blizzard.com)
- [TrinityCore](https://github.com/TrinityCore/TrinityCore/blob/3.3.5/THANKS)
- [SunwellCore](http://www.azerothcore.org/pages/sunwell.pl/)
- [AzerothCore](https://github.com/AzerothCore/azerothcore-wotlk/graphs/contributors)
- [AzerothCore Discord](https://discord.gg/gkt4y2x)
- [EMUDevs](https://youtube.com/user/EmuDevs)
- [AC-Web](http://ac-web.org/)
- [ModCraft.io](http://modcraft.io/)
- [OwnedCore](http://ownedcore.com/)
- [OregonCore](https://wiki.oregon-core.net/)
- [Wowhead.com](http://wowhead.com)
- [AoWoW](https://wotlk.evowow.com/)
### License ###
------------------------------------------------------------------------------------------------------------------
- This code and content is released under the [GNU AGPL v3](https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3).
*/

#include "Config.h"
#include "Group.h"
#include "Chat.h"
#include "World.h"

class MoneyForKills : public PlayerScript
{
public:
    MoneyForKills() : PlayerScript("MoneyForKills") { }

    // Player Kill Reward
    void OnPVPKill(Player* player, Player* victim)
    {
        // If enabled...
        if (sConfigMgr->GetBoolDefault("MFK.Enable", true))
        {
            const uint32 PVPMultiplier = sConfigMgr->GetIntDefault("MFK.PVP.Multiplier", 0);

            // If enabled...
            if (PVPMultiplier > 0)
            {
                // No reward for killing yourself
                if (player->GetGUID() == victim->GetGUID())
                {
                    // Inform the world
                    std::ostringstream ss;
                    ss << "|cff676767[ |cffFFFF00World |cff676767]|r:|cff4CFF00 " << player->GetName() << " met an untimely demise!";
                    sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());

                    return;
                }

                // Calculate the amount of gold to give to the victor
                const uint32 PVPCorpseLootPercent = sConfigMgr->GetIntDefault("MFK.PVP.CorpseLootPercent", 5);
                const uint32 VictimLevel = victim->getLevel();
                const int VictimLoot = (victim->GetMoney() * PVPCorpseLootPercent) / 100;
                const int BountyAmount = ((VictimLevel * PVPMultiplier) / 3);

                // Rifle the victim's corpse for loot
                if (victim->GetMoney() >= 10000)
                {
                    // Player loots 5% of the victim's gold
                    player->ModifyMoney(VictimLoot);
                    victim->ModifyMoney(-VictimLoot);

                    // Inform the player of the corpse loot
                    Notify(player, victim, NULL, "Loot", NULL, VictimLoot);

                    // Pay the player the additional PVP bounty
                    player->ModifyMoney(BountyAmount);
                }
                else
                {
                    // Pay the player the additional PVP bounty
                    player->ModifyMoney(BountyAmount);
                }

                // Inform the player of the bounty amount
                Notify(player, victim, NULL, "PVP", BountyAmount, VictimLoot);

                return;
            }
        }
    }

    // Creature Kill Reward
    void OnCreatureKill(Player* player, Creature* killed)
    {
        // If enabled...
        if (sConfigMgr->GetBoolDefault("MFK.Enable", true))
        {
            // Get the creature level
            const uint32 CreatureLevel = killed->getLevel();

            // What did the player kill?
            if (killed->IsDungeonBoss() || killed->isWorldBoss())
            {
                uint32 BossMultiplier;

                // Dungeon Boss or World Boss multiplier?
                if (killed->IsDungeonBoss())
                {
                    BossMultiplier = sConfigMgr->GetIntDefault("MFK.DungeonBoss.Multiplier", 0);
                }
                else
                {
                    BossMultiplier = sConfigMgr->GetIntDefault("MFK.WorldBoss.Multiplier", 0);
                }

                // If enabled...
                if (BossMultiplier > 0)
                {
                    // Reward based on creature level
                    const int BountyAmount = ((CreatureLevel * BossMultiplier) * 100);

                    if (killed->IsDungeonBoss())
                    {
                        // Pay the bounty amount
                        CreatureBounty(player, killed, "DungeonBoss", BountyAmount);
                    }
                    else
                    {
                        // Pay the bounty amount
                        CreatureBounty(player, killed, "WorldBoss", BountyAmount);
                    }
                }
            }
            else
            {
                const uint32 KillMultiplier = sConfigMgr->GetIntDefault("MFK.Kill.Multiplier", 0);

                // If enabled...
                if (KillMultiplier > 0)
                {
                    // Reward based on creature level
                    const int BountyAmount = ((CreatureLevel * KillMultiplier) / 3);

                    // Pay the bounty amount
                    CreatureBounty(player, killed, "MOB", BountyAmount);
                }
            }
        }
    }

    // Pay Creature Bounty
    void CreatureBounty(Player* player, Creature* killed, std::string KillType, int bounty)
    {
        Group* group = player->GetGroup();
        Group::MemberSlotList const& members = group->GetMemberSlots();
        const uint32 KillingBlowOnly = sConfigMgr->GetIntDefault("MFK.KillingBlowOnly", 0);
        const uint32 MoneyForNothing = sConfigMgr->GetIntDefault("MFK.MoneyForNothing", 0);

        // Determine who receives the bounty
        if (!group || KillingBlowOnly == 1)
        {
            // Pay a specific player bounty amount
            player->ModifyMoney(bounty);

            // Inform the player of the bounty amount
            Notify(player, NULL, killed, KillType, bounty, NULL);
        }
        else
        {
            // Pay the group (OnCreatureKill only rewards the player that got the killing blow)
            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
            {
                //Group::MemberSlot const& slot = *itr;
                Player* playerInGroup = ObjectAccessor::FindPlayer((*itr).guid);

                // Pay each player in the group
                if (playerInGroup && playerInGroup->GetSession())
                {
                    // Money for nothing and the kills for free..
                    if (MoneyForNothing == 1)
                    {
                        // Pay the bounty
                        playerInGroup->ModifyMoney(bounty);

                        // Inform the player of the bounty amount
                        Notify(playerInGroup, NULL, killed, KillType, bounty, NULL);
                    }
                    else
                    {
                        // Only pay players that are in reward distance	
                        if (playerInGroup->IsAtGroupRewardDistance(killed))
                        {
                            // Pay the bounty
                            playerInGroup->ModifyMoney(bounty);

                            // Inform the player of the bounty amount
                            Notify(playerInGroup, NULL, killed, KillType, bounty, NULL);
                        }
                    }
                }
            }
        }
    }

    // Payment/Kill Notification
    void Notify(Player* player, Player* victim, Creature* killed, std::string KillType, int bounty, int loot)
    {
        std::ostringstream ss;
        std::ostringstream sv;
        int result[3];

        // Determine type of kill
        if (KillType == "Loot")
        {
            const int copper = loot % 100;
            loot = (loot - copper) / 100;
            const int silver = loot % 100;
            const int gold = (loot - silver) / 100;
            result[0] = copper;
            result[1] = silver;
            result[2] = gold;
        }
        else
        {
            const int copper = bounty % 100;
            bounty = (bounty - copper) / 100;
            const int silver = bounty % 100;
            const int gold = (bounty - silver) / 100;
            result[0] = copper;
            result[1] = silver;
            result[2] = gold;
        }

        // Payment notification
        if (KillType == "Loot")
        {
            ss << "You loot ";
            sv << player->GetName() << " rifles through your corpse and takes ";
        }
        else if (KillType == "PVP")
        {
            ss << "|cff676767[ |cffFFFF00World |cff676767]|r:|cff4CFF00 " << player->GetName() << " |cffFF0000has slain " << victim->GetName() << " earning a bounty of ";
        }
        else
        {
            ss << "You receive a bounty of ";
        }

        // Figure out the money (todo: find a better way to handle the different strings)
        if (result[2] > 0)
        {
            ss << result[2] << " gold";
            sv << result[2] << " gold";
        }
        if (result[1] > 0)
        {
            if (result[2] > 0)
            {
                ss << " " << result[1] << " silver";
                sv << " " << result[1] << " silver";
            }
            else
            {
                ss << result[1] << " silver";
                sv << result[1] << " silver";

            }
        }
        if (result[0] > 0)
        {
            if (result[1] > 0)
            {
                ss << " " << result[0] << " copper";
                sv << " " << result[0] << " copper";
            }
            else
            {
                ss << result[0] << " copper";
                sv << result[0] << " copper";
            }
        }

        // Type of kill
        if (KillType == "Loot")
        {
            ss << " from the corpse.";
            sv << ".";
        }
        else if (KillType == "PVP")
        {
            ss << ".";
            sv << ".";
        }
        else
        {
            ss << " for the kill.";
        }

        // If it's a boss kill..
        if (KillType == "WorldBoss")
        {
            // Inform the world of the kill
            std::ostringstream sw;
            sw << "|cffFF0000[ |cffFFFF00World |cffFF0000]|r:|cff4CFF00 " << player->GetName() << "'s|r group triumphed victoriously over |CFF18BE00[" << killed->GetName() << "]|r !";
            sWorld->SendServerMessage(SERVER_MSG_STRING, sw.str().c_str());

            // Inform the player of the bounty
            ChatHandler(player->GetSession()).SendSysMessage(ss.str().c_str());
        }
        else if (KillType == "Loot")
        {
            // Inform the player of the corpse loot
            ChatHandler(player->GetSession()).SendSysMessage(ss.str().c_str());

            // Inform the victim of the corpse loot
            ChatHandler(victim->GetSession()).SendSysMessage(sv.str().c_str());
        }
        else if (KillType == "PVP")
        {
            // Inform the world of the kill
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }
        else
        {
            if (KillType == "DungeonBoss")
            {
                // Inform the player of the Dungeon Boss kill
                std::ostringstream sb;
                sb << "|cffFF8000Your group has defeated |cffFF0000" << killed->GetName() << "|cffFF8000.";
                ChatHandler(player->GetSession()).SendSysMessage(sb.str().c_str());
            }

            // Inform the player of the bounty
            ChatHandler(player->GetSession()).SendSysMessage(ss.str().c_str());
        }
    }
};

void AddSC_MoneyForKillsScripts()
{
    new MoneyForKills();
}
