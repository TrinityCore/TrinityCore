DELETE FROM gameobject WHERE guid=197134;
DELETE FROM `creature_template_addon` WHERE `entry` = '34850';
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='35850');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('34850', '0', '2410', '0', '0', '0', '');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34850 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34850, '0', '0', '0', '1', '0', '100', '0', '5000', '5000', '60000', '60000', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'SAY Ramdom');
DELETE FROM `creature_text` WHERE `entry` = 34850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='34851');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34850, '0', '0', 'I want the perimeter secured and the gates manned by two guards at all times. No one gets in, no one gets out.', '12', '0', '30', '0', '0', '19615', 'LD Text 1'),
(34850, '0', '1', 'We protected Gilneas from the Scourge. We protected Gilneas during the Northgate rebellion. We will protect Gilneas from whatever this new threat may be.', '12', '0', '30', '0', '0', '19614', 'LD Text 2'),
(34850, '0', '2', 'Stand ready, guards! We don\'t know how many intruders we\'re dealing with, but the Headlands are overrun and we\'re cut off from the harbor towns. Expect to be outnumbered.', '12', '0', '30', '0', '0', '19616', 'LD Text 3');
DELETE FROM `creature_template_addon` WHERE `entry` = '34851';
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('34851', '0', '0', '0', '0', '431', '');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34851 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34851, '0', '0', '0', '1', '0', '60', '0', '10000', '120000', '60000', '240000', '1', '2', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'ooc say text2');
DELETE FROM `creature_text` WHERE `entry` = 34851;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34851, '0', '0', 'Why?', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '0', '1', 'Some one save me!', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '0', '2', 'I ow you my life! I will be leaving this place forever! Is it you please!', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '0', '3', 'You make my orphaned children on this day, my friend!', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '0', '4', 'The... They promised that we would have security...', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '0', '6', 'Ask for anything and you will have it! Is of save my life!', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '1', '0', 'I will not go down as easy as it!', '12', '0', '50', '0', '0', '0', 'combat Say'),
(34851, '1', '1', 'Dies dog of the Fla to the! DIES!', '12', '0', '50', '0', '0', '0', 'combat Say'),
(34851, '1', '2', 'TU to shut just a dog!', '12', '0', '50', '0', '0', '0', 'combat Say'),
(34851, '1', '3', 'You can take my life, but you won\'t take my freedom!', '12', '0', '50', '0', '0', '0', 'combat Say'),
(34851, '1', '4', 'Dies!', '12', '0', '50', '0', '0', '0', 'combat Say'),
(34851, '1', '5', 'Come then, Wolf!', '12', '0', '50', '0', '0', '0', 'combat Say'),
(34851, '2', '0', 'These... What is these things on the roof?', '12', '0', '75', '0', '0', '0', ''),
(34851, '2', '5', 'I\'m too young to die!', '12', '0', '50', '22', '0', '0', 'combat Say'),
(34851, '2', '7', 'To the rescue!', '12', '0', '50', '22', '0', '0', 'combat Say');
UPDATE `creature_template` SET `faction_A`='16', `faction_H`='16', `mindmg`='1.5', `maxdmg`='3.1', `baseattacktime`='2000', `rangeattacktime`='2000', `MovementType`='1', `InhabitType`='1' WHERE (`entry`='35660');
UPDATE creature SET MovementType=1 WHERE id=35660;
UPDATE creature SET spawndist=5 WHERE id=35660;
DELETE FROM smart_scripts WHERE entryorguid IN (35660);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='35660');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35660 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35660, '0', '0', '1', '2', '0', '100', '1', '0', '30', '0', '0', '11', '8599', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Cast Enrage at 30% HP'),
(35660, '0', '1', '0', '61', '0', '100', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Say Text at 30% HP');
DELETE FROM `creature_text` WHERE `entry` = 35660;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35660, '0', '0', '%s becomes enraged!', '16', '0', '100', '0', '0', '0', 'combat Enrage');
-- update map gilneas for worgens to be now visible
UPDATE creature SET map=654 WHERE map=638;
UPDATE gameobject SET map=654 WHERE map=638;
UPDATE playercreateinfo SET map=654 WHERE map=638;
DELETE FROM creature WHERE guid IN (340178,337003);
UPDATE creature_template SET MovementType=1 WHERE entry=34884;
UPDATE creature SET MovementType=1 WHERE id=34884;
UPDATE creature SET spawndist=5 WHERE id=34884;
UPDATE creature_template SET MovementType=1 WHERE entry=38210;
UPDATE creature SET MovementType=1 WHERE id=38210;
UPDATE creature SET spawndist=5 WHERE id=38210;
UPDATE creature_template SET faction_A=7 WHERE entry=38192;
UPDATE creature_template SET faction_A=7 WHERE entry=38210;
UPDATE `creature_template` SET `faction_A`='35', `faction_H`='35' WHERE entry=35011;
UPDATE `creature_template` SET `faction_A`='7', `faction_H`='7' WHERE entry=38464;
UPDATE `creature_template` SET `faction_A`='7', `faction_H`='7' WHERE entry=38420;
DELETE FROM `creature_template_addon` WHERE `entry` = '44086';
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('44086', '0', '0', '0', '0', '431', '');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 44086 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(44086, '0', '0', '0', '60', '0', '100', '0', '3000', '5000', '3000', '5000', '10', '431', '20', '431', '412', '397', '20', '1', '0', '0', '0', '0', '0', '0', '0', 'Panicked Citizen - Every 3 - 5 Seconds, do Random Emote'),
(44086, '0', '1', '0', '60', '0', '15', '0', '1000', '50000', '10000', '125000', '1', '1', '5000', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Panicked Citizen - Every 10-15 Seconds, 15% Chance to Say Random Phrase');
DELETE FROM `creature_text` WHERE `entry` = 44086;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(44086, '1', '0', 'The... They promised that we would have security...', '12', '0', '33', '0', '0', '0', 'Panicked Citizen Random Saying'),
(44086, '1', '1', 'It means we go from here! The screams are stronger every night.', '12', '0', '33', '0', '0', '0', 'Panicked Citizen Random Saying'),
(44086, '1', '2', 'Why are the doors closed data?', '12', '0', '33', '0', '0', '0', 'Panicked Citizen Random Saying');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='44086');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 50260 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(50260, '0', '0', '2', '38', '0', '100', '0', '1', '1', '0', '0', '89', '30', '0', '0', '0', '0', '0', '1', '0', '20', '0', '0', '0', '0', '0', 'On ooc do jump on self'),
(50260, '0', '2', '0', '61', '0', '100', '0', '0', '0', '0', '0', '41', '15000', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Respawn SELF');
UPDATE creature_template SET ScriptName='npc_gilnean_crow' WHERE entry=50260;
DELETE FROM `creature_template_addon` WHERE `entry` = '50260';
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('50260', '0', '0', '50331649', '1', '0', '');
DELETE FROM creature WHERE guid IN (816 ,784 ,779 ,775 ,773 ,772 ,761 ,755 ,749 ,748 ,746 ,2278 ,259065 ,259069 ,259077 ,259805 ,336960 ,336962 ,336965 ,336966 ,336975 ,336976 ,336977 ,336979 ,336987 ,336988 ,336989 ,336990 ,336993 ,336997 ,336999 ,337001 ,337005 ,337006 ,337011 ,337040 ,337217 ,337747 ,337765 ,337768 ,337770 ,337771 ,337775 ,339839 ,340085 ,340086 ,340087 ,340088 ,340089 ,340094 ,340095 ,340098 ,340100 ,340102 ,340104 ,340106 ,340110 ,340128 ,340138 ,340139 ,340140 ,340141 ,340160 ,340161 ,340162 ,340163 ,340180 ,340192 ,340193 ,340198 ,340200 ,340210 ,340213 ,340215 ,340216 ,340217 ,340220 ,340221 ,340489 ,341019 ,341036 ,341038 ,341041 ,341046,340101,340444);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34884 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34884, '0', '0', '1', '2', '0', '100', '1', '0', '30', '0', '0', '11', '8599', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Cast Enrage at 30% HP'),
(34884, '0', '1', '0', '61', '0', '100', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Say Text at 30% HP');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='34884');
DELETE FROM `creature_text` WHERE `entry` = 34884;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34884, '0', '0', '%s becomes enraged!', '16', '0', '100', '0', '0', '0', 'combat Enrage');
DELETE FROM `creature_queststarter` WHERE (`id`='35830') AND (`quest`='14098');
UPDATE creature_template SET npcflag=0 WHERE entry=35830;
DELETE FROM `creature_queststarter` WHERE (`id`='34884') AND (`quest`='14093');
UPDATE creature_template SET npcflag=0 WHERE entry=34884;
UPDATE `gameobject_template` SET `data3`='0' WHERE (`entry`='195306');
UPDATE `quest_template` SET `RequiredNpcOrGo1`='35830', `RequiredNpcOrGoCount1`='3' WHERE (`Id`='14098');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='35830');
UPDATE creature_template SET MovementType=0 WHERE entry=35830;
UPDATE creature SET MovementType=0 WHERE id=35830;
UPDATE creature SET spawndist=0 WHERE id=35830;
DELETE FROM creature WHERE id=35010;
DELETE FROM gameobject WHERE id IN (195327,195306) AND map=654;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1419.04, 1428.56, 35.7935, 4.59022, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1440.89, 1440.72, 35.9799, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1457.3, 1409.06, 35.5559, 4.59022, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1477.67, 1412.66, 35.5559, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1478.73, 1380.34, 36.0039, 3.17653, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1429.87, 1399.26, 36.0039, 4.59022, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1493.9, 1362.94, 35.9987, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1524.05, 1442.07, 35.9939, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1561.4, 1432.83, 35.9623, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1574.02, 1401.14, 36.6302, 3.17653, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1548.74, 1305.17, 35.8792, 3.28124, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1537.45, 1406.86, 35.5559, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1541.22, 1381.21, 36.0039, 3.17653, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1506.12, 1439.24, 35.9363, 0, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1523.36, 1413.34, 35.5559, 4.59022, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1466.05, 1362.19, 36.0039, 3.17653, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195306, 654, 0, 0, 1, 2, -1477.25, 1406.77, 35.5559, 3.17653, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1569.8, 1384.91, 36.9995, 1.46608, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1562.48, 1409.71, 36.532, 6.26573, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1583.43, 1359.09, 36.535, 1.53589, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1576.57, 1335.94, 36.535, 6.26573, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1549.55, 1309.61, 36.4266, 3.38594, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1529.5, 1322.8, 36.5849, 1.83259, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1493.83, 1371.16, 36.5577, 3.08918, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1486.29, 1334.58, 36.4891, 1.83259, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1513.22, 1371.14, 36.535, 6.21337, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1537.47, 1443.97, 36.7051, 4.71239, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1394.59, 1403.33, 36.4232, 3.12412, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1421.08, 1412.98, 36.7944, 1.53589, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1463.9, 1444.26, 36.5957, 4.71239, 0, 0, 0, 1, 120, 255, 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (NULL, 195327, 654, 0, 0, 1, 7, -1426.66, 1436.56, 36.3902, 3.07177, 0, 0, 0, 1, 120, 255, 1);
DELETE FROM smart_scripts WHERE entryorguid IN (35830);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='35830');
INSERT INTO `smart_scripts` VALUES (35830, 0, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 33, 35830, 0, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0,'Credit Kill');
DELETE FROM `creature_text` WHERE `entry` = 38218;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38218, '0', '0', 'Hey over there!', '16', '0', '100', '0', '0', '0', 'near');
UPDATE creature_template SET npcflag=128 WHERE `entry` = 38853;
UPDATE creature_template SET MovementType=1 WHERE entry=35118;
UPDATE creature SET MovementType=1 WHERE id=35118;
UPDATE creature SET spawndist=5 WHERE id=35118;
DELETE FROM gossip_menu WHERE entry=3064 AND text_id=3800;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES ('3064', '3800');
DELETE FROM gossip_menu_option WHERE menu_id=3064;
INSERT INTO `gossip_menu_option` VALUES ('3064', '0', '0', 'Absolutely.', '1', '1', '3065', '0', '0', '0', '');
DELETE FROM smart_scripts WHERE entryorguid IN (44794);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='44794');
INSERT INTO `smart_scripts` VALUES (44794, 0, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 33, 44794, 0, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0,'Credit Kill');
DELETE FROM creature WHERE id=44794 AND map=654;
INSERT INTO `creature` VALUES ('NULL', '44794', '654', '4755', '4757', '1', '2', '0', '0', '-1702.37', '1316.93', '20.2904', '4.66955', '300', '0', '0', '284', '0', '0', '0', '0', '0', '0');
DELETE FROM creature WHERE guid=409236;
DELETE FROM creature WHERE guid=409235;
DELETE FROM creature WHERE guid=337128;
DELETE FROM creature WHERE guid=259079;
INSERT INTO `creature` VALUES ('409235', '35112', '654', '4755', '4757', '1', '2', '0', '0', '-1767.38', '1345.81', '19.7319', '0.771622', '300', '0', '0', '1', '1', '0', '0', '134250752', '0', '0');
INSERT INTO `creature` VALUES ('409236', '35115', '654', '4755', '4757', '1', '2', '0', '0', '-1769.25', '1349.6', '19.5645', '5.74712', '300', '0', '0', '1', '1', '0', '0', '134250496', '0', '0');
UPDATE `quest_template` SET `Method`='0', `Flags`='0', `SpecialFlags`='0' WHERE (`Id`='14154');
UPDATE `creature_template` SET `faction_A`='35', `faction_H`='35' WHERE (`entry`='35112');
UPDATE `creature_template` SET `faction_A`='35', `faction_H`='35' WHERE (`entry`='35115');
DELETE FROM gameobject WHERE guid IN (174816,197772,198186);
DELETE FROM creature WHERE guid in (409392,409393,409396,409397);
INSERT INTO `creature` VALUES (409392, 35378, 654, 4755, 4757, 1, 2, 0, 0, -1789.56, 1427.36, 12.9412, 3.27175, 300, 0, 0, 142, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` VALUES (409393, 35550, 654, 4755, 4757, 1, 2, 0, 0, -1799.42, 1398.49, 19.8313, 5.12059, 300, 0, 0, 1, 1, 0, 0, 0, 0, 0);
INSERT INTO `creature` VALUES (409396, 35911, 654, 4755, 4758, 1, 2, 0, 0, -1744.41, 1663.26, 20.4806, 5.67744, 300, 0, 0, 1, 1, 0, 0, 0, 0, 0);
INSERT INTO `creature` VALUES (409397, 35552, 654, 4755, 4758, 1, 2, 0, 0, -1728.56, 1663.11, 20.4806, 4.464, 300, 0, 0, 4356, 0, 0, 0, 0, 0, 0);
DELETE FROM gameobject WHERE guid IN (197789,198202,197788,198202,197788);
UPDATE `creature_template` SET `faction_A`='35', `faction_H`='35' WHERE (`entry`='35618');
DELETE FROM creature WHERE guid in (409398,409399);
INSERT INTO `creature` VALUES (409398, 35618, 654, 4755, 4761, 1, 2, 0, 0, -1539.07, 1572.4, 29.2067, 0.760853, 300, 0, 0, 1, 1, 0, 0, 0, 0, 0);
INSERT INTO `creature` VALUES (409399, 35566, 654, 4755, 4761, 1, 2, 0, 0, -1619.26, 1498.83, 32.7998, 0.771063, 300, 0, 0, 4356, 0, 0, 0, 0, 0, 0);
