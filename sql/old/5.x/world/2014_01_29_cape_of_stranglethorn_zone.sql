-- Generic Modify
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=30 WHERE  `entry`=2550 AND `item`=3897;
UPDATE `creature_template` SET `faction_A`=1133, `faction_H`=2159, `Health_mod`=2134 WHERE  `entry`=43377;
UPDATE `creature_template` SET `Health_mod`=1 WHERE  `entry`=43376;
UPDATE `creature_template` SET `Health_mod`=2134 WHERE  `entry`=2535;
UPDATE `creature_template` SET `Mana_mod`=0.00002544 WHERE  `entry`=43511;
-- Quest Insert/Modify
UPDATE `quest_template` SET `Flags`=1032 WHERE  `Id`=26810;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0 WHERE  `Id`=26699;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0 WHERE  `Id`=26700;
DELETE FROM `creature_queststarter` WHERE quest IN (26597);
DELETE FROM `creature_queststarter` WHERE quest IN (607);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (2486, 26597);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (2502, 607);
DELETE FROM `creature_questender` WHERE quest IN (26597);
DELETE FROM `creature_questender` WHERE quest IN (607);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (2486, 26597); 
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (2501, 607);
UPDATE `quest_template` SET `RequiredNpcOrGo1`=2546 WHERE  `Id`=26703;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE  `Id`=26662;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE  `Id`=26663;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE  `Id`=26664;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0, `Flags`=65536 WHERE  `Id`=26663;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0, `Flags`=65536 WHERE  `Id`=26664;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0, `Flags`=1024 WHERE  `Id`=26678;
UPDATE `quest_template` SET `Flags`=1024 WHERE  `Id`=26809;
UPDATE `quest_template` SET `Flags`=66560 WHERE  `Id`=26810;
-- Quest:Perfectly Pure
UPDATE `gameobject_template` SET `data1`=759 WHERE  `entry`=759;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=36 WHERE  `entry`=759 AND `item`=58811;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=62 WHERE  `entry`=759 AND `item`=60386;
-- Quest:If They're Just Going to Leave Them Lying Around...
UPDATE `gameobject_template` SET `type`=3, `data0`=43, `data1`=204336, `data3`=1, `data6`=0 WHERE  `entry`=204336;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=100 WHERE  `entry`=204336 AND `item`=58877;
-- Quest:A Giant's Feast
DELETE FROM `creature_template` WHERE entry=(2664); 
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `difficulty_entry_4`, `difficulty_entry_5`, `difficulty_entry_6`, `difficulty_entry_7`, `difficulty_entry_8`, `difficulty_entry_9`, `difficulty_entry_10`, `difficulty_entry_11`, `difficulty_entry_12`, `difficulty_entry_13`, `difficulty_entry_14`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (2664, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4482, 0, 0, 0, 'Kelsey Yance', 'Cook', NULL, 0, 43, 43, 0, 0, 120, 120, 128, 1, 1.14286, 1, 0, 67, 88, 0, 162, 1, 2000, 2000, 1, 512, 2048, 2048, 0, 0, 0, 0, 0, 46, 67, 16, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, '', 16048);
DELETE FROM `npc_vendor` WHERE entry=(2664); 
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES (2664, 2, 59037);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES (2664, 1, 59036);
-- Quest:A Dish Best Served Huge 
DELETE FROM `creature` WHERE id=(1494);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (8174665, 1494, 0, 1, 1, 0, 0, -14644.3, 142.849, 0.828439, 2.10999, 300, 0, 0, 4440, 0, 0, 0, 0, 0);
-- Quest:The Bloodail Buccanners
UPDATE `gameobject_template` SET `flags`=0 WHERE  `entry`=2083;
-- Quest:Let's See What You've Got, Zanzil
UPDATE `creature_template` SET `faction_H`=14 WHERE  `entry`=43204;
UPDATE `creature_template` SET `faction_H`=14 WHERE  `entry`=43203;
UPDATE `creature_template` SET `faction_H`=14 WHERE  `entry`=43205;
-- Quest:Prepare For Takeoff
DELETE FROM `gameobject_template` WHERE entry=(204587);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (204587, 3, 9651, 'Narkk\'s Handbombs', '', 'Collecting', '', 0, 4, 2, 0, 0, 0, 0, 0, 0, 43, 204587, 0, 0, 0, 0, 0, 0, 26695, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);
UPDATE `gameobject_template` SET `type`=2, `data0`=43, `data1`=15426 WHERE  `entry`=204406;
-- Quest:Your First Day as a Pirate
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE  `entry`=2548;
-- Quest:Swabbing Duty
DELETE FROM `creature` WHERE id=(43511);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (8174822, 43511, 0, 1, 1, 0, 0, -14967.2, 349.034, 12.9648, 5.57421, 300, 0, 0, 393941, 0, 0, 0, 0, 0);
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE  `entry`=43511;
-- Quest not working
UPDATE `quest_template` SET `Method`=0 WHERE Id IN (26809, 26451, 26699, 26700, 26647, 26649, 26550);
