DELETE FROM `creature` WHERE `guid` IN (320863, 321478, 317305, 320149);
DELETE FROM `creature_addon` WHERE `guid` IN (320863, 321478, 317305, 320149);
DELETE FROM `creature_template_addon` WHERE `entry`= 41245;

UPDATE `creature_template` SET `npcflag`= 0x1 | 0x2, `speed_run`= 1.14286, `ScriptName`= 'npc_hoo_brann_bronzebeard' WHERE `entry`= 39908;

DELETE FROM `creature_text` WHERE `CreatureID`= 39908;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39908, 0, 0, 'This symbol, I think I\'ve seen this before... ', 12, 0, 100, 5, 0, 0, 40104, 'Brann Bronzebeard'),
(39908, 1, 0, 'Right, let\'s go! Just need to input the final entry sequence into the door mechanism... and...', 12, 0, 100, 5, 0, 20897, 40231, 'Brann Bronzebeard'),
(39908, 2, 0, 'That did the trick! The control room should be right behind this... oh... wow...', 12, 0, 100, 5, 0, 20898, 40232, 'Brann Bronzebeard'),
(39908, 3, 0, 'What? This isn\'t the control room! There\'s another entire defense mechanism in place, and the blasted Rock Troggs broke into here somehow. Troggs. Why did it have to be Troggs!', 12, 0, 100, 5, 0, 20899, 40233, 'Brann Bronzebeard'),
(39908, 4, 0, 'Ok, let me think a moment.', 12, 0, 100, 1, 0, 20900, 40234, 'Brann Bronzebeard'),
(39908, 5, 0, 'Mirrors pointing all over the place.', 12, 0, 100, 25, 0, 20902, 40240, 'Brann Bronzebeard'),
(39908, 6, 0, 'Four platforms with huge elementals.', 12, 0, 100, 25, 0, 20901, 40235, 'Brann Bronzebeard'),
(39908, 7, 0, 'I got it! I saw a tablet that mentioned this chamber. This is the Vault of Lights! Ok, simple enough. I need you adventurers to take out each of the four elementals to trigger the opening sequence for the far door!', 12, 0, 100, 5, 0, 20903, 40236, 'Brann Bronzebeard'),
(39908, 8, 0, 'One down!', 14, 0, 100, 5, 0, 20904, 40270, 'Brann Bronzebeard'),
(39908, 9, 0, 'Another one down! Just look at those light beams! They seem to be connecting to the far door!', 14, 0, 100, 5, 0, 20905, 40271, 'Brann Bronzebeard'),
(39908, 10, 0, 'One more elemental to go! The door is almost open!', 14, 0, 100, 5, 0, 20906, 40272, 'Brann Bronzebeard'),
(39908, 11, 0, 'That\'s it, you\'ve done it! The vault door is opening! Now we can... oh, no!', 14, 0, 100, 5, 0, 20907, 40273, 'Brann Bronzebeard'),
(39908, 12, 0, 'We\'ve done it! The control room is breached!', 14, 0, 100, 5, 0, 23709, 49687, 'Brann Bronzebeard'),
(39908, 13, 0, 'Here we go! Now this should only take a moment...', 14, 0, 100, 5, 0, 23710, 49688, 'Brann Bronzebeard');

UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 39908;

UPDATE `creature_template` SET `ScriptName`= 'npc_hoo_flame_warden' WHERE `entry`= 39800;
UPDATE `creature_template` SET `ScriptName`= 'npc_hoo_air_warden' WHERE `entry`= 39803;
UPDATE `creature_template` SET `ScriptName`= 'npc_hoo_earth_warden' WHERE `entry`= 39801;
UPDATE `creature_template` SET `ScriptName`= 'npc_hoo_water_warden' WHERE `entry`= 39802;
UPDATE `creature_template` SET `unit_flags`= 34080768, `flags_extra`= 128, `ScriptName`= 'npc_hoo_whirling_winds', `AIName`= '' WHERE `entry`= 41245;
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 41264;

UPDATE `creature_template` SET `difficulty_entry_1`= 48893, `RegenHealth`= 0, `ScriptName`= 'npc_hoo_aqua_bubble' WHERE `entry`= 41257;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `flags_extra`= 0x2000, `RegenHealth`= 0 WHERE `entry`= 48893;

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41257, 48893);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`,`Flight`, `Rooted`) VALUES
(41257, 2, 1, 1),
(48893, 2, 1, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_hoo_bubble_bound_script',
'spell_hoo_bubble_bound',
'spell_hoo_bubble_bound_periodic');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77335, 'spell_hoo_bubble_bound'),
(77336, 'spell_hoo_bubble_bound_periodic'),
(91158, 'spell_hoo_bubble_bound_periodic'),
(77339, 'spell_hoo_bubble_bound_script');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=77341;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,77341,0,1,31,0,3,41257,0,0,0,0,'','Bubble Bound Instakill - Target Aqua Bubble');

SET @ENTRY := 39908;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -409.9531, 367.0469, 89.81111, 0, -435),
(@PATH, 1, -397.8246, 366.967, 86.37722, 0, -285),
(@PATH, 2, -383.7813, 366.8229, 82.07919, 0, -304),
(@PATH, 3, -368.2604, 366.7448, 77.0984, 0, -459),
(@PATH, 4, -353.6458, 366.4896, 75.92504, 0, -477),
(@PATH, 5, -309.0608, 366.7205, 75.91345, 0, -1806),
(@PATH, 6, -276.3303, 367, 75.92413, 0, -908),
(@PATH, 7, -246.5104, 366.6389, 75.87791, 0, -980),
(@PATH, 8, -202.0417, 366.7517, 75.92508, 0, -1100),
(@PATH, 9, -187.6024, 366.7656, 76.23077, 0, -1099),
(@PATH, 10, -155.0938, 366.783, 86.45834, 0, -1536),
(@PATH, 11, -143.5694, 366.8177, 89.73354, 0, -1315),
(@PATH, 12, -128.5608, 366.8629, 89.74199, 0, 1092),
(@PATH, 13, -71.58507, 367.02777, 89.77716, 0, -1100),
(@PATH, 14, -35.04861, 366.65625, 89.78094, 0, 0);

UPDATE `waypoint_data` SET `velocity`= 12.0 WHERE `id`= @PATH;
UPDATE `waypoint_data` SET `velocity`= 8.0 WHERE `id`= @PATH AND `point` IN (13, 14);

UPDATE `gameobject`SET `rotation0`= 0.150108814239501953, `rotation1`= -0.15010833740234375, `rotation2`= 0.690989494323730468, `rotation3`= 0.690990805625915527 WHERE `id`= 207375 AND `map`= 644;
UPDATE `gameobject`SET `rotation0`= -0.15010881423950195, `rotation1`= -0.15010833740234375, `rotation2`= -0.69098949432373046, `rotation3`= 0.690990805625915527 WHERE `id`= 207374 AND `map`= 644;
UPDATE `gameobject`SET `rotation0`= 0.150108814239501953, `rotation1`= -0.15010833740234375, `rotation2`= 0.690989494323730468, `rotation3`= 0.690990805625915527 WHERE `id`= 207377 AND `map`= 644;
UPDATE `gameobject`SET `rotation0`= -0.15010881423950195, `rotation1`= -0.15010833740234375, `rotation2`= -0.69098949432373046, `rotation3`= 0.690990805625915527 WHERE `id`= 207376 AND `map`= 644;
