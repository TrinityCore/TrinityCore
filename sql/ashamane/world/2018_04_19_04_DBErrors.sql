DELETE FROM gameobject_addon WHERE `guid` NOT IN (SELECT `guid` FROM gameobject);
DELETE FROM linked_respawn WHERE `guid` NOT IN (SELECT `guid` FROM creature);
DELETE FROM linked_respawn WHERE `linkedGuid` NOT IN (SELECT `guid` FROM creature);
DELETE FROM game_event_creature WHERE `guid` NOT IN (SELECT `guid` FROM creature);
DELETE FROM game_event_gameobject WHERE `guid` NOT IN (SELECT `guid` FROM gameobject);
DELETE FROM `page_text` WHERE ID IN (3614,4546,4874,4958,5123,5124,5299,5300,5301,5303,5304,6882,7154,7264,7303);
INSERT INTO `page_text` (`ID`, `Text`) VALUES
('3614', 'Cultists, cultists everywhere ...!'),
('4546', 'Ten thousand years ago, Emperor Shaohao, the Last Emperor of Pandaria, used the power of these sacred waters to spare Pandaria from the devastation of the Sundering that destroyed the rest of the world.'),
('4874', 'Care: debris.'),
('4958', 'ATTACK! $B$BPUT FIST IN FACE! $B$BCONTINUE THE ATTACKING!'),
('5123', 'Curses! Managing the fel conversion pits should have been MY task! Nethekurse has outmaneuvered me again. $B$BNow I am given the task of overseeing the clearing of the Dark Portal and guarding the local area. Guarding it from what? Vines? Gul\'dan says prepare, but I think it more likely that my "brethren" discredited me and I have been sent into exile...'),
('5124', 'Curses! Managing the fel conversion pits should have been MY task! Nethekurse has outmaneuvered me again. $B$BNow I am given the task of overseeing the clearing of the Dark Portal and guarding the local area. Guarding it from what? Vines? Gul\'dan says prepare, but I think it more likely that my "brethren" discredited me and I have been sent into exile...'),
('5299', 'Ancient, ancient... Very ancient...'),
('5300', 'Decisions, decisions... Many decisions...'),
('5301', 'Even the best hunter escapes the prey...'),
('5303', 'Forgotten, forgotten... Very forgotten...'),
('5304', 'Old, old... Very old...'),
('6882', 'Levia\'s notes detail the precise components and incantations necessary to make contact with a powerful demon. The final page seems to contain Levia\'s personal reflections before performing the ritual.'),
('7154', '...of sea, spirit and self...'),
('7264', 'With a most pleasing sign.'),
('7303', 'Very well preserved... Too much...');

UPDATE `gameobject_template` SET `Data0`='166879' WHERE  `entry`=181102;
UPDATE `gameobject_template` SET `Data0`='220485' WHERE  `entry`=208325;
UPDATE `gameobject_template` SET `Data0`='241140' WHERE  `entry`=267034;
UPDATE `gameobject_template` SET `Data0`='42955' WHERE  `entry`=193061;
UPDATE `gameobject_template` SET `Data0`='44089' WHERE  `entry`=183322;
UPDATE `gameobject_template` SET `Data0`='44089' WHERE  `entry`=191008;
UPDATE `gameobject_template` SET `Data0`='66238' WHERE  `entry`=205876;
UPDATE `gameobject_template` SET `Data0`='66238' WHERE  `entry`=205877;
UPDATE `gameobject_template` SET `Data0`='81349' WHERE  `entry`=204422;
UPDATE `gameobject_template` SET `Data0`='85040' WHERE  `entry`=207691;

UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213571;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213572;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213573;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213574;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213575;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213576;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213577;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213578;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213579;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213580;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213581;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213582;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213583;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213584;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213585;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213586;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213587;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213588;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213589;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213590;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=213591;
UPDATE `gameobject_template` SET `Data12`='0' WHERE  `entry`=217768;

SET @OGUID := 1001;
DELETE FROM `gameobject` WHERE guid BETWEEN @OGUID + 0 AND @OGUID + 4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID + 0, '148502', '1220', '7502', '8140', '-813.854', '4471.44', '735.21', '3.81896', '-0', '-0', '-0.943192', '0.332247', '60', '255', '1', '15595'),
(@OGUID + 1, '240888', '1464', '6723', '7766', '3658.94', '-1908.82', '21.4293', '2.13391', '-0', '-0', '-0.875734', '-0.482794', '60', '255', '1', '15595'),
(@OGUID + 2, '240889', '1464', '6723', '7766', '3970.43', '-2176.72', '39.1508', '0.0211808', '-0', '-0', '-0.0105896', '-0.999944', '60', '255', '1', '15595'),
(@OGUID + 3, '266736', '1220', '7502', '8140', '-803.594', '4491.72', '746.671', '4.03496', '-0', '-0', '-0.901884', '0.431978', '60', '255', '1', '15595'),
(@OGUID + 4, '270855', '1220', '7502', '8140', '-879.914', '4454.8', '749.377', '4.42766', '-0', '-0', '-0.800279', '0.599628', '60', '255', '1', '15595');

UPDATE `npc_text` SET `Probability0`= 0 WHERE `ID` IN (2953,2955,2956,2957,7114,8321,8332,8354,10128,11128,12181,13157,14330,30000,32480,33093,33654,33814,33979,34006,34007,34008,34009,34010,34011,34012,34013);
UPDATE `npc_text` SET `Probability0`= 1, `Probability1`= 0, `Probability2`= 0, `Probability3`= 0, `Probability4`= 0,`Probability5`= 0, `Probability6`= 0, `Probability7`= 0 WHERE `ID` IN (11428);
UPDATE `npc_text` SET `Probability0`= 1, `Probability1`= 0 WHERE `ID` IN (10843);