DELETE FROM `waypoint_data` WHERE `id` = 44086000;

DELETE FROM `creature_addon` WHERE `guid` IN (236167,236751);

UPDATE `creature` SET `spawndist` = '0' WHERE `guid` =306021;

DELETE FROM `creature_equip_template` WHERE `entry` = 4075;

UPDATE `creature` SET `equipment_id` = '0' WHERE `guid` IN (407500,407502,407501);

UPDATE `creature_template` SET `spell1`=49297 WHERE `entry` IN (27664,40281);

UPDATE `creature_template_addon` SET `auras`='49384' WHERE `entry`=27664;

UPDATE `creature_template_addon` SET `auras`='75110' WHERE `entry`=40281;

DELETE FROM `areatrigger_scripts` WHERE `entry` = 6216;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6216, 'at_deepholm_flyover');

DELETE FROM `creature` WHERE `guid` = 300706;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(300706, 44839, 646, 0, 0, 1, 1, 0, 0, 286.613, 1055.34, 56.3087, 5.55553, 300, 0, 0, 42, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `exp` = '3', `faction_A` = '14', `faction_H` = '14', `mindmg` = '1035.5', `maxdmg` = '1373.7', `attackpower` = '1594', `dmg_multiplier` = '13', `minrangedmg` = '780.9', `maxrangedmg` = '1079.2', `rangedattackpower` = '225' WHERE `entry` =48666;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `exp` = '3', `faction_A` = '16', `faction_H` = '16', `mindmg` = '1035.5', `maxdmg` = '1373.7', `attackpower` = '1594', `dmg_multiplier` = '13', `minrangedmg` = '780.9', `maxrangedmg` = '1079.2', `rangedattackpower` = '225' WHERE `entry` =48594;

UPDATE `creature` SET `position_x` = '3985.59', `position_y` = '-2939.21', `position_z` = '1002.547', `orientation` = '5.11584' WHERE `guid` =118012;

DELETE FROM `creature` WHERE `guid` IN (251991,252011,252010,252013,252014,252012);

DELETE FROM `disables` WHERE `sourceType` = 2 AND `entry` = 859;

DELETE FROM `access_requirement` WHERE `mapId` IN (859,568);
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES
(859, 0, 90, 0, 0, 0, 0, 0, 0, NULL, 'Zul''Gurub (Entrance)'),
(859, 1, 85, 0, 0, 0, 0, 0, 0, NULL, 'Zul''Gurub (Entrance)'),
(568, 0, 90, 0, 0, 0, 0, 0, 0, NULL, 'Zul''Aman (Entrance)'),
(568, 1, 85, 0, 0, 0, 0, 0, 0, NULL, 'Zul''Aman (Entrance)');

DELETE FROM `disables` WHERE `sourceType` = 2 AND `entry` = 568;
DELETE FROM `disables` WHERE `sourceType` = 2 AND `entry` = 859;

INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(2, 568, 3, '', '', 'Disable Zul`Aman Instance'),
(2, 859, 3, '', '', 'Disable Zul`Gurub Instance');

DELETE FROM `creature` WHERE `guid` = 300707;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(300707, 52148, 859, 0, 0, 2, 1, 0, 0, -11788.7, -1627.92, 54.7764, 4.76761, 300, 0, 0, 6068100, 0, 0, 0, 0, 0);

UPDATE `creature` SET `spawnMask` = '2' WHERE `map` =859;

DELETE FROM `creature` WHERE `guid` IN (300708,300709);
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(300708, 52382, 1, 0, 0, 1, 2, 0, 0, 1673.02, -4355.06, 26.757, 2.82265, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
(300709, 52408, 0, 0, 0, 1, 2, 0, 0, -9009.19, 860.898, 29.6208, 0.653244, 300, 0, 0, 9215, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (300708,300709);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(300708, 0, 0, 0, 0, 0, '74426'),
(300709, 0, 0, 0, 0, 0, '74426');

DELETE FROM `creature` WHERE `guid` IN (249053,249919);

DELETE FROM `creature_template` WHERE `entry` = 60004;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(60004, 0, 0, 0, 0, 0, 38503, 38504, 0, 0, 'Harbinger of Flame', '', '', 0, 86, 86, 3, 0, 16, 16, 0, 1, 1.14286, 1, 1, 0, 0, 0, 0, 1, 2000, 2000, 8, 0, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 7.45333, 10, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_harbinger_legendary', 15595);

DELETE FROM `gameobject_template` WHERE `entry` = 209100;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(209100, 3, 10729, 'Branch of Nordrassil', '', '', '', 0, 4, 2, 69646, 0, 0, 0, 0, 0, 1691, 209100, 0, 1, 0, 0, 0, 0, 29234, 0, 0, 0, 0, 0, 37733, 0, 0, 12505, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);

DELETE FROM `creature_template_addon` WHERE `entry` = 53796;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(53796, 0, 0, 0, 0, 0, '100102');

DELETE FROM `creature` WHERE `guid` IN (300710,300711,300712,300713,300714);
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(300710, 53796, 720, 0, 0, 15, 1, 0, 0, 455.144, 515.519, 244.824, 0.0961538, 84000, 0, 0, 42, 0, 0, 0, 0, 0),
(300711, 60004, 720, 0, 0, 15, 1, 0, 0, 440.186, 473.282, 244.017, 1.34612, 84000, 0, 0, 444822, 93250, 0, 0, 0, 0),
(300712, 60004, 720, 0, 0, 15, 1, 0, 0, 465.62, 551.694, 246.882, 4.56992, 84000, 0, 0, 444822, 93250, 0, 0, 0, 0),
(300713, 60004, 720, 0, 0, 15, 1, 0, 0, 496.98, 525.752, 245.321, 3.33512, 84000, 0, 0, 444822, 93250, 0, 0, 0, 0),
(300714, 60004, 720, 0, 0, 15, 1, 0, 0, 416.498, 508.563, 243.2, 0.0718648, 84000, 0, 0, 444822, 93250, 0, 0, 0, 0);

UPDATE `creature` SET `position_x` = '455.59', `position_y` = '515.165', `position_z` = '246.879' WHERE `guid` =300710;

UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` =53796;
