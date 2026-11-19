--
UPDATE `creature_template` SET `ScriptName`= 'boss_general_bjarngrim' WHERE `entry`= 28586;
UPDATE `creature_template` SET `ScriptName`= 'npc_bjarngrim_stormforged_lieutenant' WHERE `entry`= 29240;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_bjarngrim_defensive_stance_dummy',
'spell_bjarngrim_battle_stance_dummy',
'spell_bjarngrim_berserker_stance_dummy',
'spell_bjarngrim_charge_up',
'spell_bjarngrim_arc_weld');

INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53790, 'spell_bjarngrim_defensive_stance_dummy'),
(53791, 'spell_bjarngrim_berserker_stance_dummy'),
(53792, 'spell_bjarngrim_battle_stance_dummy'),
(52098, 'spell_bjarngrim_charge_up'),
(59085, 'spell_bjarngrim_arc_weld');

DELETE FROM `creature_text` WHERE `CreatureID`= 28586;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28586, 0, 0, 'I am the greatest of my father\'s sons! Your end has come!', 14, 0, 100, 0, 0, 14149, 31407, 0, 'General Bjarngrim - Aggro'),
(28586, 1, 0, '%s switches to Defensive Stance!', 41, 0, 100, 0, 0, 0, 29834, 0, 'General Bjarngrim - Announce Defensive Stance'),
(28586, 2, 0, 'Give me your worst!', 14, 0, 100, 0, 0, 14150, 31408, 0, 'General Bjarngrim - Defensive Stance'),
(28586, 3, 0, '%s switches to Berserker Stance!', 41, 0, 100, 0, 0, 0, 29833, 0, 'General Bjarngrim - Announce Berserker Stance'),
(28586, 4, 0, 'GRAAAAAH! Behold the fury of iron and steel!', 14, 0, 100, 0, 0, 14152, 31410, 0, 'General Bjarngrim - Berserker Stance'),
(28586, 5, 0, '%s switches to Battle Stance!', 41, 0, 100, 0, 0, 0, 29832, 0, 'General Bjarngrim - Announce Battle Stance'),
(28586, 6, 0, 'Defend yourself, for all the good it will do!', 14, 0, 100, 0, 0, 14151, 31409, 0, 'General Bjarngrim - Battle Stance'),
(28586, 7, 0, 'So ends your curse.', 14, 0, 100, 0, 0, 14153, 31411, 0, 'General Bjarngrim - Slay 1'),
(28586, 7, 1, 'Flesh... is... weak!', 14, 0, 100, 0, 0, 14154, 31412, 0, 'General Bjarngrim - Slay 2'),
(28586, 7, 2, 'Bolvin umyol marnjar.', 14, 0, 100, 0, 0, 14155, 31413, 0, 'General Bjarngrim - Slay 3'),
(28586, 8, 0, 'How can it be...? Flesh is not... stronger!', 14, 0, 100, 0, 0, 14156, 31414, 0, 'General Bjarngrim - Death');

DELETE FROM `conditions` WHERE `SourceEntry` IN (56458) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 56458, 0, 0, 31, 0, 3, 28586, 0, 0, 0, '', 'Charge Up - Target General Bjarngrim');

SET @CGUID := 126981;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1262.023, 9.344401, 33.21593, NULL, 0),
(@PATH, 1, 1262.031, 53.14377, 33.17394, NULL, 0),
(@PATH, 2, 1261.928, 98.94911, 33.50209, NULL, 6000),
(@PATH, 3, 1261.893, 60.51574, 33.17393, NULL, 0),
(@PATH, 4, 1261.886, 21.39475, 33.17399, NULL, 0),
(@PATH, 5, 1262.132, -26.1173, 33.50208, NULL, 6000),
(@PATH, 6, 1298.901, -26.74544, 37.24462, NULL, 0),
(@PATH, 7, 1331.648, -27.02919, 40.17395, NULL, 10000),
(@PATH, 8, 1354.665, -4.239692, 41.1354, NULL, 0),
(@PATH, 9, 1371.601, 12.65864, 48.57853, NULL, 0),
(@PATH, 10, 1394.671, 35.86361, 50.03335, NULL, 6000),
(@PATH, 11, 1370.748, 12.2143, 48.29315, NULL, 0),
(@PATH, 12, 1355.246, -3.361762, 41.45641, NULL, 0),
(@PATH, 13, 1332.481, -26.59397, 40.17395, NULL, 0),
(@PATH, 14, 1295.831, -26.50022, 36.55395, NULL, 0),
(@PATH, 15, 1262.658, -26.88303, 33.50208, NULL, 10000);

DELETE FROM `waypoint_scripts` WHERE `id`  IN (12698102, 12698101);

UPDATE `creature` SET `position_x`= 1262.2057, `position_y`= -1.0628986, `position_z`= 33.50208, `orientation`= 5.140983, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

UPDATE `creature` SET `position_x`= 1265.8042, `position_y`= -4.6208167, `position_z`= 33.502056, `orientation`= 5.258189 WHERE `guid`= 126863;
UPDATE `creature` SET `position_x`= 1258.7352, `position_y`= -4.746479, `position_z`= 33.50209, `orientation`= 5.122859 WHERE `guid`= 126864;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= -52098;

DELETE FROM `spawn_group_template` WHERE `groupId`= 325;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(325, 'Halls of Lightning - General Bjarngrim - Stormforged Lieutenants', 4);

DELETE FROM `spawn_group` WHERE `spawnId` IN (126863, 126864);
DELETE FROM `spawn_group` WHERE `groupId`= 325;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(325, 0, 126863),
(325, 0, 126864);
