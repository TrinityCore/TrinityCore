-- Spirit Healer (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=60, `VerifiedBuild`=40120 WHERE `entry`=6491;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=6491 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=5233;
UPDATE `creature_template_addon` SET `auras`='9036 10848' WHERE `entry`=6491;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=83 AND `TextId`=580;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=580;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE `MenuId`=83 AND `OptionIndex`=0;

-- Jessel (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=20100;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=20100 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=19336;
UPDATE `creature` SET `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=71602;
UPDATE `creature_text` SET `Emote`=6 WHERE `CreatureID`=20100 AND `GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `Emote`=6 WHERE `CreatureID`=20100 AND `GroupID`=2 AND `ID`=0;

-- Jane (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=20098;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=20098 AND `Idx`=0;
UPDATE `creature` SET `VerifiedBuild`=40120 WHERE `guid`=71601;
UPDATE `creature_text` SET `Emote`=0 WHERE `CreatureID`=20098 AND `GroupID`=0 AND `ID`=0;

-- Nova (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=20244;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=20244 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=19315;
UPDATE `creature` SET `VerifiedBuild`=40120 WHERE `guid`=71940;
UPDATE `creature_text` SET `Emote`=0 WHERE `CreatureID`=20244 AND `GroupID`=1 AND `ID`=0;
UPDATE `creature_text` SET `Emote`=0 WHERE `CreatureID`=20244 AND `GroupID`=1 AND `ID`=1;

-- Well Watcher Solanian (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15295;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15295 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15517;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=6569 AND `TextId`=7784;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=7784;
-- This quest was marked obsolete by Blizzard and cannot be obtained or completed.
DELETE FROM `creature_questender` WHERE `id`=15295 AND `quest`=37441;
UPDATE `creature` SET `curhealth`=522, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=55053;

-- Cat (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `VerifiedBuild`=40120 WHERE `entry`=6368;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=6368 AND `Idx` IN (0,1,2,3);
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID` IN (5555,5556,5585,5586);

-- Shara Sunwing (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15287;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15287 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15527;
UPDATE `creature` SET `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=54993;
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15287 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1; -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15287 AND `item`=20857 AND `ExtendedCost`=0 AND `type`=1; -- Honey Bread

-- Pao (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=63332;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=63332 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=42947;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=13895 AND `TextId`=19889;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=19889;
UPDATE `creature` SET `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=452381;

-- Pathstalker Kariel (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15285;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15519;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15285 AND `Idx`=0;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14140 AND `TextId`=9187;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=9187;
UPDATE `creature` SET `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=54991;

-- Ranger Sallina (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15513;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15513;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15513 AND `Idx`=0;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14141 AND `TextId`=9189;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=9189;
UPDATE `creature` SET `curhealth`=653, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid`=55431;

-- Delios Silverblade (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=43010;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=43010 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=33190;
UPDATE `creature` SET `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=250000;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14199 AND `TextId`=16540;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=16540;

-- Matron Arena (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15284;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15284 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15518;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14139 AND `TextId`=9186;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=9186;
UPDATE `creature` SET `curhealth`=497, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=54990;

-- Jesthenis Sunstriker (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15280;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15280 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15521;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14137 AND `TextId`=9193;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=9193;
UPDATE `creature` SET `curhealth`=653, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid`=54986;

-- Julia Sunstriker (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `gossip_menu_id`=20690, `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15279;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=20690 AND `TextId`=31032;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14136 AND `TextId`=9192;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=31032;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=9192;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE `MenuId`=20690 AND `OptionIndex` IN (0,1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE `MenuId`=14136 AND `OptionIndex`=9;
UPDATE `creature_template_addon` SET `auras`='56384' WHERE `entry`=15279;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15279 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15522;
UPDATE `creature` SET `curhealth`=522, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=54985;

-- Summoner Teli'Larien (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15283;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15283 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15524;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=14138 AND `TextId`=7903;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=7903;
UPDATE `creature` SET `curhealth`=497, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=54989;

-- Imp Minion
UPDATE `creature_template` SET `VerifiedBuild`=40120 WHERE `entry`=12922;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=12922 AND `Idx`=0;

-- Yasmine Teli'Larien (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15494;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15494 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15523;
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE `MenuId`=12670 AND `TextId`=12549;
UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=12549;
UPDATE `creature` SET `curhealth`=497, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=55416;

-- Wounded Outrunner (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=44857;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=44857 AND `Idx` IN (0,1,2,3);
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID` IN (34190,34191,34192);
UPDATE `creature` SET `curhealth`=1244, `VerifiedBuild`=40120 WHERE `guid` BETWEEN 250893 AND 250898;

-- Faraden Thelryn (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15292;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15292 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15510;
UPDATE `creature` SET `curhealth`=622, `curmana`=490, `VerifiedBuild`=40120 WHERE `guid`=54998;
UPDATE `npc_vendor` SET `IgnoreFiltering`=0, `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20912 AND `ExtendedCost`=0 AND `type`=1; -- Large Shield
UPDATE `npc_vendor` SET `IgnoreFiltering`=0, `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20911 AND `ExtendedCost`=0 AND `type`=1; -- Light Guard
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20916 AND `ExtendedCost`=0 AND `type`=1; -- Unadorned Chain Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20917 AND `ExtendedCost`=0 AND `type`=1; -- Unadorned Chain Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20915 AND `ExtendedCost`=0 AND `type`=1; -- Unadorned Chain Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20914 AND `ExtendedCost`=0 AND `type`=1; -- Unadorned Chain Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20918 AND `ExtendedCost`=0 AND `type`=1; -- Unadorned Chain Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15292 AND `item`=20919 AND `ExtendedCost`=0 AND `type`=1; -- Unadorned Chain Vest

-- Raelis Dawnstar (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15289;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15289 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15526;
UPDATE `creature` SET `curhealth`=622, `VerifiedBuild`=40120 WHERE `guid`=54995;
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20910 AND `ExtendedCost`=0 AND `type`=1; -- Stiff Shortbow
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20853 AND `ExtendedCost`=0 AND `type`=1; -- Mana Gathering Staff
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20849 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Shortsword
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20851 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Mace
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20852 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Dirk
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20850 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Axe
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20910 AND `ExtendedCost`=0 AND `type`=1; -- Stiff Shortbow
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20853 AND `ExtendedCost`=0 AND `type`=1; -- Mana Gathering Staff
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20849 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Shortsword
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20851 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Mace
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20852 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Dirk
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15289 AND `item`=20850 AND `ExtendedCost`=0 AND `type`=1; -- Arcane Forged Axe

-- Jainthess Thelryn (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=15291;
UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15291 AND `Idx`=0;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15529;
UPDATE `creature` SET `curhealth`=497, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=54997;
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20923 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20922 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20921 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20924 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20920 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20925 AND `ExtendedCost`=0 AND `type`=1; -- Sun Cured Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20987 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20988 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20985 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20986 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20989 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=40120 WHERE `entry`=15291 AND `item`=20990 AND `ExtendedCost`=0 AND `type`=1; -- Light Cloth Armor
