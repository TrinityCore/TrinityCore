UPDATE creature SET MovementType=1 WHERE id IN (3703,37177,853,706);
UPDATE creature_template SET MovementType=1 WHERE entry IN (3703,37177,853,706);
UPDATE creature SET spawndist=5 WHERE id IN (3703,37177,853,706);
UPDATE `creature_template` SET `faction_A`='55', `faction_H`='55' WHERE (`entry`='37081');
UPDATE `creature_template` SET `faction_A`='55', `faction_H`='55' WHERE (`entry`='853');
UPDATE `creature_template` SET `faction_A`='190', `faction_H`='190' WHERE (`entry`='37108,37173,37174');
UPDATE `quest_template` SET `RequiredNpcOrGo1`='37174', `RequiredNpcOrGo2`='37173', `RequiredNpcOrGo3`='37108' WHERE (`Id`='24489');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 37173 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(37173, '0', '0', '0', '10', '0', '100', '0', '1', '3', '10000', '10000', '1', '0', '4000', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Start 1st sentence when in range'),
(37173, '0', '1', '0', '52', '0', '100', '0', '0', '37173', '0', '0', '1', '1', '4000', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Start 2nd sentence after TEXT_OVER'),
(37173, '0', '2', '0', '52', '0', '100', '0', '1', '37173', '0', '0', '1', '2', '2000', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Start 3rd sentence after TEXT_OVER'),
(37173, '0', '3', '0', '52', '0', '100', '0', '2', '37173', '0', '0', '33', '37173', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');
DELETE FROM `creature_text` WHERE `entry` = 37173;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37173, '0', '0', 'What we gon\' do now, you ask ? We wait.', '12', '0', '100', '1', '3', '0', 'Soothsayer Rikkari 1st sentence'),
(37173, '1', '0', 'Grik\'nir says he gon\' talk to the elemental, get it to fight on our side.', '12', '0', '100', '1', '3', '0', 'Soothsayer Rikkari 2nd sentence'),
(37173, '2', '0', 'Soon enough we take over dis valley. Soon enough.', '12', '0', '100', '1', '3', '0', 'Soothsayer Rikkari 3rd sentence');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='37173');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 37108 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(37108, '0', '0', '0', '10', '0', '100', '0', '1', '3', '10000', '10000', '1', '0', '4000', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Start 1st sentence when in range'),
(37108, '0', '1', '0', '52', '0', '100', '0', '0', '37108', '0', '0', '1', '1', '4000', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Start 2nd sentence after TEXT_OVER'),
(37108, '0', '2', '0', '52', '0', '100', '0', '1', '37108', '0', '0', '1', '2', '2000', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Start 3rd sentence after TEXT_OVER'),
(37108, '0', '3', '0', '52', '0', '100', '0', '2', '37108', '0', '0', '33', '37108', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='37108');
DELETE FROM `creature_text` WHERE `entry` = 37108;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37108, '0', '0', 'Da spirits be angry with us.', '12', '0', '100', '1', '3', '0', 'Soothsayer Shi\'kala 1st sentence'),
(37108, '1', '0', 'I don\' know why the spirits be rejectin\' us so.', '12', '0', '100', '1', '3', '0', 'Soothsayer Shi\'kala 2nd sentence'),
(37108, '2', '0', 'Don\' worry, child. Grik\'nir gonna help us get through this.', '12', '0', '100', '1', '3', '0', 'Soothsayer Shi\'kala 3rd sentence');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 37174 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(37174, '0', '0', '0', '10', '0', '100', '0', '1', '3', '10000', '10000', '1', '0', '4000', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Start 1st sentence when in range'),
(37174, '0', '1', '0', '52', '0', '100', '0', '0', '37174', '0', '0', '1', '1', '4000', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Start 2nd sentence after TEXT_OVER'),
(37174, '0', '2', '0', '52', '0', '100', '0', '1', '37174', '0', '0', '1', '2', '2000', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Start 3rd sentence after TEXT_OVER'),
(37174, '0', '3', '0', '52', '0', '100', '0', '2', '37174', '0', '0', '33', '37174', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='37174');
DELETE FROM `creature_text` WHERE `entry` = 37174;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37174, '0', '0', 'Our land be a land of ice an\' snow', '12', '0', '100', '1', '3', '0', 'Soothsayer Mirim\'koa 1st sentence'),
(37174, '1', '0', 'But beneath the earth, child, there always be fire.', '12', '0', '100', '1', '3', '0', 'Soothsayer Mirim\'koa 2nd sentence'),
(37174, '2', '0', 'De spirit come from deep down to talk with Grik\'nir.', '12', '0', '100', '1', '3', '0', 'Soothsayer Mirim\'koa 3rd sentence');

DELETE FROM gameobject_loot_template WHERE entry='2843';
INSERT INTO gameobject_loot_template VALUES ('2843', '117', '9.72', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '118', '4.11', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '159', '1.45', '1', '0', '1', '5');
INSERT INTO gameobject_loot_template VALUES ('2843', '414', '2.2', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '765', '7.73', '1', '0', '1', '8');
INSERT INTO gameobject_loot_template VALUES ('2843', '774', '11.35', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '783', '5.37', '1', '0', '1', '2');
INSERT INTO gameobject_loot_template VALUES ('2843', '785', '5.46', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '818', '5.44', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '858', '3.47', '1', '0', '1', '7');
INSERT INTO gameobject_loot_template VALUES ('2843', '1179', '4.77', '1', '0', '1', '5');
INSERT INTO gameobject_loot_template VALUES ('2843', '1210', '8.28', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1429', '8.13', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1495', '8.15', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1497', '8.14', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1498', '8.14', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1499', '8.15', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1501', '8.21', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1502', '8.14', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1504', '8.17', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1506', '8.15', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1509', '8.15', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1510', '8.17', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1511', '8.22', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1512', '8.2', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1513', '8.16', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1514', '6.21', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1515', '6.17', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '1516', '6.19', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '2070', '6.77', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '2214', '6.15', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '2287', '6.21', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '2318', '6.96', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '2447', '6.77', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '2449', '6.78', '1', '0', '1', '5');
INSERT INTO gameobject_loot_template VALUES ('2843', '2450', '6.52', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '2455', '6.18', '1', '0', '1', '8');
INSERT INTO gameobject_loot_template VALUES ('2843', '2589', '6.94', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '2763', '6.18', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '2770', '6.32', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '2777', '6.17', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '2778', '6.2', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '2835', '6.46', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '2842', '6.44', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '2996', '6.19', '1', '0', '1', '6');
INSERT INTO gameobject_loot_template VALUES ('2843', '3374', '6.14', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '3375', '6.14', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '3577', '6.26', '1', '0', '1', '2');
INSERT INTO gameobject_loot_template VALUES ('2843', '4536', '6.7', '1', '0', '1', '3');
INSERT INTO gameobject_loot_template VALUES ('2843', '4537', '6.11', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '4540', '6.71', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '4541', '6.05', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '4604', '6.73', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '4605', '6.17', '1', '0', '1', '4');
INSERT INTO gameobject_loot_template VALUES ('2843', '61959', '-19.96', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '61960', '-20.02', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '61961', '-19.99', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('2843', '61962', '-20.04', '1', '0', '1', '1');

DELETE FROM gameobject_loot_template WHERE entry='203130';
INSERT INTO gameobject_loot_template VALUES ('203130', '117', '22.27', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('203130', '49751', '22.21', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('203130', '55151', '-100', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('203130', '57058', '7.18', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('203130', '62328', '9.2', '1', '0', '1', '1');
INSERT INTO gameobject_loot_template VALUES ('203130', '62772', '11.2', '1', '0', '1', '1');

UPDATE `quest_template` SET `RequiredNpcOrGo1`='41251', `RequiredSpellCast1`='93773' WHERE (`Id`='28868');
UPDATE `quest_template` SET `RequiredNpcOrGo1`='41372', `RequiredNpcOrGo2`='41373', `RequiredNpcOrGoCount1`='1', `RequiredNpcOrGoCount2`='1', `RequiredSpellCast1`='77488' WHERE (`Id`='25841');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='41372');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41372 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41372, '0', '0', '0', '52', '0', '100', '0', '0', '41372', '0', '0', '33', '41372', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='41373');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41373 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41373, '0', '0', '0', '52', '0', '100', '0', '0', '41373', '0', '0', '33', '41373', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='40991');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40991 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40991, '0', '0', '0', '52', '0', '100', '0', '0', '40991', '0', '0', '33', '40991', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='40994');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40994 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40994, '0', '0', '0', '52', '0', '100', '0', '0', '40994', '0', '0', '33', '40994', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='41056');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41056 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41056, '0', '0', '0', '52', '0', '100', '0', '0', '41056', '0', '0', '33', '41056', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', 'Give Quest Credit');

UPDATE creature SET MovementType=1 WHERE id IN (2031);
UPDATE creature_template SET MovementType=1 WHERE entry IN (2031);
UPDATE creature SET spawndist=5 WHERE id IN (2031);
UPDATE `gameobject_template` SET `data1`='2843' WHERE (`entry`='2843');
UPDATE `gameobject_template` SET `data1`='203130' WHERE (`entry`='203130');
