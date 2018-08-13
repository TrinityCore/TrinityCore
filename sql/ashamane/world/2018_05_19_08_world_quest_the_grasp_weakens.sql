UPDATE `creature_template` SET `InhabitType`='4', `AIName`='SmartAI' WHERE  `entry`=38980;
UPDATE `creature_template` SET `minlevel`='10', `maxlevel`='11', `faction`='14', `InhabitType`='4', `AIName`='SmartAI' WHERE  `entry`=38981;
UPDATE `creature_template` SET `gossip_menu_id`='11156', `npcflag`='1', `AIName`='SmartAI' WHERE  `entry`=39117;
UPDATE `creature` SET `spawntimesecs`='30' WHERE  `guid`=192780;
DELETE FROM `creature` WHERE  `guid` IN (194489,300861,194487);

DELETE FROM `smart_scripts` WHERE `entryorguid`=38980;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38980, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, '', 17, 437, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit of Devlin Agamand - On Spawn - State Emote');

DELETE FROM `smart_scripts` WHERE `entryorguid`=38981;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38981, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, '', 18, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow of Agamand - On Spawn - Set Unit Flag'),
(38981, 0, 1, 0, 0, 0, 100, 0, 2000, 4500, 12000, 16000, '', 11, 31516, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow of Agamand - Cast Mind Blast'),
(38981, 0, 2, 0, 0, 0, 100, 0, 6000, 9000, 18000, 22000, '', 11, 16568, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow of Agamand - Cast Mind Flay');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39117,3911700,3911701);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(39117, 0, 0, 0, 62, 0, 100, 0, 11156, 0, 0, 0, '', 80, 3911700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - On Gossip Select - Actionlist'),
(3911700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Close Gossip'),
(3911700, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk1'),
(3911700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - On Script - Set React Passive'),
(3911700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 53, 0, 39117, 0, 0, 999990, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Start Waypoint'),
(39117, 0, 1, 0, 40, 0, 100, 0, 4, 0, 0, 0, '', 80, 3911701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - On Waypoint Reached - Actionlist'),
(3911701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 12, 38980, 1, 111110, 0, 0, 0, 8, 0, 0, 0, 2246.89, 228.612, 44.8348, 2.01968, 'Shadow Priestess Malia - Spawn'),
(3911701, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 10, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 5, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 12, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 6, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 19, 38980, 10, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Despawn'),
(3911701, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 73180, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Cast Summon Shadow of Agamand'),
(3911701, 9, 15, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, '', 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Talk'),
(3911701, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Priestess Malia - Despawn');

DELETE FROM `waypoints` WHERE `entry`=39117;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(39117, 1, 2240.26, 233.004, 34.5514, 'Shadow Priestess Malia'),
(39117, 2, 2234.65, 229.995, 38.2114, 'Shadow Priestess Malia'),
(39117, 3, 2236.93, 226.07, 38.2451, 'Shadow Priestess Malia'),
(39117, 4, 2243.65, 228.889, 41.8121, 'Shadow Priestess Malia');

DELETE FROM `npc_text` WHERE `ID`=15527;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextID0`, `BroadcastTextID1`, `BroadcastTextID2`, `BroadcastTextID3`, `BroadcastTextID4`, `BroadcastTextID5`, `BroadcastTextID6`, `BroadcastTextID7`, `VerifiedBuild`) VALUES 
(15527, 1, 0, 0, 0, 0, 0, 0, 0, 39150, 0, 0, 0, 0, 0, 0, 0, -15595);

DELETE FROM `gossip_menu` WHERE `MenuId`=11156;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES 
(11156, 15527, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=11156;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES 
(11156, 0, 0, 'I am ready', 39152, 1, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11156;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11156, 0, 0, 0, 9, 0, 25006, 0, 0, 0, 0, 0, '', 'Show gossip menu if player accept The Grasp Weakens');

DELETE FROM `creature_text` WHERE `CreatureID`=38980;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(38980, 0, 0, 'What\'s going on here?', 12, 0, 100, 0, 0, 0, 39160, 0, 'Spirit of Devlin Agamand'),
(38980, 1, 0, 'Wait, am I... home?', 12, 0, 100, 0, 0, 0, 39161, 0, 'Spirit of Devlin Agamand'),
(38980, 2, 0, 'You people... what are you doing here? Why are you in my house?', 12, 0, 100, 0, 0, 0, 39162, 0, 'Spirit of Devlin Agamand'),
(38980, 3, 0, 'Mother... father... Thurman... where are you?', 12, 0, 100, 0, 0, 0, 39163, 0, 'Spirit of Devlin Agamand'),
(38980, 4, 0, 'No... I remember. My family is dead. And so am I.', 12, 0, 100, 0, 0, 0, 39164, 0, 'Spirit of Devlin Agamand'),
(38980, 5, 0, 'And my soul.... my soul belongs to the Scourge!', 12, 0, 100, 0, 0, 0, 39165, 0, 'Spirit of Devlin Agamand'),
(38980, 6, 0, 'DIE, YOU WRETCHES!', 14, 0, 100, 0, 0, 0, 39166, 0, 'Spirit of Devlin Agamand');

DELETE FROM `creature_text` WHERE `CreatureID`=39117;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(39117, 0, 0, 'Very well. Follow me.', 12, 0, 100, 0, 0, 0, 39153, 0, 'Shadow Priestess Malia'),
(39117, 1, 0, 'Now it is time for us to begin.', 12, 0, 100, 1, 0, 0, 39154, 0, 'Shadow Priestess Malia'),
(39117, 2, 0, 'Devlin Agamand! Listen to my voice!', 14, 0, 100, 22, 0, 0, 39155, 0, 'Shadow Priestess Malia'),
(39117, 3, 0, 'Your mortal remains have been gathered, here in this place where you spent your childhood!', 14, 0, 100, 22, 0, 0, 39156, 0, 'Shadow Priestess Malia'),
(39117, 4, 0, 'Resist the Lich King\'s will, Devlin! Come to us!', 14, 0, 100, 22, 0, 0, 39157, 0, 'Shadow Priestess Malia'),
(39117, 5, 0, 'I had better return to my post. You can find me downstairs if you need anything.', 12, 0, 100, 1, 0, 0, 39158, 0, 'Shadow Priestess Malia');

