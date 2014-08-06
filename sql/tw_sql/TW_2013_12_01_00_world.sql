UPDATE `creature_template` SET `ScriptName`='TW_npc_argent_squire' WHERE `entry` IN (
33518,  /* Squire Danny */
33522); /* Squire Cavin */

UPDATE `creature_template` SET `ScriptName`='TW_npc_argent_champion' WHERE `entry` IN (33707); /* Argent Champion */

-- add mount for argent champion
DELETE FROM `creature_template_addon` WHERE `entry`=33707;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33707, 0, 28919, 0, 0, 0, '');

-- add missing lance for the Argent Valiant
DELETE FROM `creature_equip_template` WHERE `entry`=33448;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`) VALUES
(33448, 1, 46106);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (9918,10224,10225,10226,10227,9919,9920,10228,9921,9922);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(9918, 5, 64805, 0, ''), -- Darnassus
(10224, 5, 64808, 0, ''), -- Exodar
(10225, 5, 64809, 0, ''), -- Gnomeregan
(10226, 5, 64810, 0, ''), -- Ironforge
(10227, 5, 64811, 0, ''), -- Orgrimmar
(9919, 5, 64812, 0, ''), -- Sen'Jin
(9920, 5, 64813, 0, ''), -- Silvermoon
(10228, 5, 64814, 0, ''), -- Stormwind
(9921, 5, 64815, 0, ''), -- Thunder Bluff
(9922, 5, 64816, 0, ''); -- Undercity

UPDATE `creature_template` SET `ScriptName`='TW_npc_argent_faction_rider',`gossip_menu_id`=0,`speed_walk`=1.2,`dmg_multiplier`=2,`unit_flags`=256 WHERE `entry` IN 
(33562,33559,33558,33564,33561,33382,33383,33384,33306,33285,33739,33738,33747,33743,33740,33746,33748,33744,33745,33749);

UPDATE `creature_template` SET `ScriptName`='TW_npc_the_black_knight' WHERE `entry`=33785;
