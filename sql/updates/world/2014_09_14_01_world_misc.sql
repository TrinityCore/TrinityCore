SET @CGUID := 76522;

UPDATE `creature_template` SET `gossip_menu_id`=10200 WHERE  `entry`=32239;
UPDATE`creature_template` SET `gossip_menu_id`=9928, `minlevel`=82, `maxlevel`=82, `npcflag`=1, `speed_walk`=4.8, `speed_run`=3.142857, `unit_flags2`=2099200 WHERE  `entry`=30399;
UPDATE `creature_template` SET `faction`=14, `speed_walk`=1.6, `speed_run`=1.857143, `unit_flags`=320, `unit_flags2`=2099200 WHERE  `entry`=30396;
UPDATE `creature_template` SET `speed_walk`=3.2, `speed_run`=1.428571, `unit_flags`=33088, `unit_flags2`=2099200, `HoverHeight`=2.1 WHERE  `entry`=30420;
UPDATE `creature_template` SET `faction`=2102, `unit_flags`=320 WHERE  `entry`=30429;


DELETE FROM `gossip_menu` WHERE `entry` IN(9928,10200);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10200, 14160), -- 32239
(9928, 13800); -- 30399

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(9928,10200);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(10200, 0, 0, 'I\'m ready, Highlord.', 32933, 1, 1, 0, 0, 0, 0, '', 0),
(9928, 0, 0, 'I\'m with you, Thorim.', 31225, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(9928,10200);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10200, 0, 0, 0, 9, 0, 13364, 0, 0, 0, 0, 0, '', 'Highlord Tirion Fordring - Show Gossip if Tirions Gambit Taken'),
(15, 10200, 0, 0, 1, 9, 0, 13403, 0, 0, 0, 0, 0, '', 'Highlord Tirion Fordring - Show Gossip if Tirions Gambit Taken'),
(15, 10200, 0, 0, 0, 1, 0, 61131, 0, 0, 0, 0, 0, '', 'Highlord Tirion Fordring - Show Gossip if player has aura Cultist Hood'),
(15, 10200, 0, 0, 1, 1, 0, 61131, 0, 0, 0, 0, 0, '', 'Highlord Tirion Fordring - Show Gossip if player has aura Cultist Hood'),
(15, 9928, 0, 0, 0, 9, 0, 13047, 0, 0, 0, 0, 0, '', 'Thorim - SHow Gossip if the reckoning taken');

DELETE FROM `creature_template_addon` WHERE `entry` IN(32239,32241,30399,30396,30420);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(32239, 0, 0x10000, 0x101, '49414'), -- 32239 - 49414
(32241, 0, 0x10000, 0x1, '49414'), -- 32241 - 49414
(30399, 0, 0x10000, 0x1, '54503'), -- 30399 - 54503
(30396, 0, 0x1, 0x1, ''), -- 30396
(30420, 0, 0x3010000, 0x1, '54503'); -- 30420 - 54503

DELETE FROM `creature` WHERE `id` IN(32239,32241,30399,30420);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 32239, 571, 1, 1, 6240.595, 2658.845, 570.3328, 5.864306, 120, 0, 0), -- 32239 (Area: 210)
(@CGUID+1, 32241, 571, 1, 1, 6243.453, 2667.72, 570.3328, 5.410521, 120, 0, 0), -- 32241 (Area: 210)
(@CGUID+2, 32241, 571, 1, 1, 6250.451, 2656.436, 570.3328, 2.199115, 120, 0, 0), -- 32241 (Area: 210)
(@CGUID+3, 32241, 571, 1, 1, 6252.46, 2665.359, 570.3328, 3.979351, 120, 0, 0), -- 32241 (Area: 210)
(@CGUID+4, 30399, 571, 1, 1,  8703.806, -714.0443, 934.9764, 2.321288, 120, 0, 0), -- 30399 (Area: 67)
(@CGUID+5, 30420, 571, 1, 1,  8711.395, -754.7941, 955.1224, 2.338741, 120, 0, 0); -- 30420 (Area: 67)

DELETE FROM `spell_area` WHERE `spell` IN(49416,54504) AND `area` IN(4543,4445,4521);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(54504, 4543, 13047, 13047, 0, 0, 2, 1, 74, 11),
(54504, 4445, 13047, 13047, 0, 0, 2, 1, 74, 11),
(49416, 4521, 13364, 13364, 0, 0, 2, 1, 74, 11),
(49416, 4521, 13403, 13403, 0, 0, 2, 1, 74, 11);
