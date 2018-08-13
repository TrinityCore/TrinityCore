UPDATE `creature_template` SET `gossip_menu_id`='11134', `npcflag`='3', `AIName`='SmartAI' WHERE  `entry`=38999;
DELETE FROM `creature_queststarter` WHERE `id`=38999 AND `quest`=24979;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (38999, 24979);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=39002;
DELETE FROM `creature` WHERE  `guid`=194116;
DELETE FROM `creature_addon` WHERE  `guid`=194116;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38999,3899900);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38999, 0, 0, 0, 62, 0, 100, 0, 11136, 0, 0, 0, '', 80, 3899900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - On Gossip Select - Actionlist'),
(3899900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Close Gossip'),
(3899900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Talk1'),
(3899900, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2442.93, 1600.72, 72.1552, 3.88045, 'Lilian Voss - Set Orientation'),
(3899900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 12, 39002, 8, 6666, 0, 0, 0, 8, 0, 0, 0, 2444.51, 1599.78, 66.5727, 5.39996, 'Lilian Voss - Spawn Scarlet Lieutenant Gebler'),
(3899900, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 19, 39002, 30, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Talk2'),
(3899900, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Talk'),
(3899900, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 19, 39002, 30, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Talk2'),
(3899900, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Talk'),
(3899900, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 19, 39002, 15, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Talk2'),
(3899900, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 19, 39002, 15, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Talk2'),
(3899900, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, '', 11, 73304, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Cast Shadowy Aura'),
(3899900, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 11, 73453, 1, 0, 0, 0, 0, 19, 39002, 15, 0, 0, 0, 0, 0, 'Lilian Voss - Cast Lilian\'s Shadow Hop - Event'),
(3899900, 9, 12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 51, 0, 0, 0, 0, 0, 0, 19, 39002, 15, 0, 0, 0, 0, 0, 'Lilian Voss - Kill Scarlet Lieutenant Gebler'),
(3899900, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 28, 73304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Remove Aura'),
(3899900, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, '', 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2442.93, 1600.72, 72.1552, 1.93731, 'Lilian Voss - Go to pos'),
(3899900, 9, 15, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Talk1'),
(3899900, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Talk1'),
(3899900, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 33, 38999, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Quest Credit'),
(3899900, 9, 18, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian Voss - Despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39002,3900200);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(39002, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, '', 80, 3900200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - On Spawn - Action list'),
(3900200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Set React Passive'),
(3900200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Set Immune to PC'),
(3900200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 53, 0, 39002, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Lieutenant Gebler - Waypoint');

DELETE FROM `waypoints` WHERE `entry`=39002;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(39002, 1, 2451.68, 1590.89, 72.1562, 'Scarlet Lieutenant Gebler'),
(39002, 2, 2447.75, 1587.76, 72.1562, 'Scarlet Lieutenant Gebler'),
(39002, 3, 2441.82, 1590.97, 72.1562, 'Scarlet Lieutenant Gebler'),
(39002, 4, 2441.47, 1597.17, 72.1569, 'Scarlet Lieutenant Gebler');

DELETE FROM `creature_text` WHERE `CreatureID`=38999;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(38999, 0, 0, 'Yes, my... wait, be quiet! I hear the lieutenant approaching.', 12, 0, 100, 0, 0, 0, 39000, 0, 'Lilian Voss'),
(38999, 1, 0, 'Gebler, you came! What did he say?', 12, 0, 100, 1, 0, 0, 38994, 0, 'Lilian Voss'),
(38999, 2, 0, 'What? NO! This can\'t be! Gebler, you know me... we were friends once!', 12, 0, 100, 1, 0, 0, 38996, 0, 'Lilian Voss'),
(38999, 3, 0, 'Gebler, father, why would you...', 12, 0, 100, 1, 0, 0, 39001, 0, 'Lilian Voss'),
(38999, 4, 0, 'The world of the living may have turned its back on me, but I\'m no damned Scourge. Just go.', 12, 0, 100, 1, 0, 0, 38999, 0, 'Lilian Voss');

DELETE FROM `creature_text` WHERE `CreatureID`=39002;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(39002, 0, 0, 'The time has come, my little captive... word has come back from your father.', 12, 0, 100, 0, 0, 0, 38993, 0, 'Scarlet Lieutenant Gebler'),
(39002, 1, 0, 'High Priest Voss denounces you as a daughter. He\'s ordered that you be executed immediately.', 12, 0, 100, 1, 0, 0, 38995, 0, 'Scarlet Lieutenant Gebler'),
(39002, 2, 0, 'The High Priest sends his regrets. He had hoped that one day you would be a powerful weapon against our enemies.', 12, 0, 100, 1, 0, 0, 38997, 0, 'Scarlet Lieutenant Gebler'),
(39002, 3, 0, 'Unfortunately, you were too dangerous in life, and you\'re far too dangerous in undeath. I will enjoy killing you, you Scourged witch...', 12, 0, 100, 1, 0, 0, 38998, 0, 'Scarlet Lieutenant Gebler');

DELETE FROM `npc_text` WHERE `ID` IN (15487,15488,15489);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextID0`, `BroadcastTextID1`, `BroadcastTextID2`, `BroadcastTextID3`, `BroadcastTextID4`, `BroadcastTextID5`, `BroadcastTextID6`, `BroadcastTextID7`, `VerifiedBuild`) VALUES 
(15487, 1, 0, 0, 0, 0, 0, 0, 0, 38985, 0, 0, 0, 0, 0, 0, 0, -15595),
(15488, 1, 0, 0, 0, 0, 0, 0, 0, 38987, 0, 0, 0, 0, 0, 0, 0, -15595),
(15489, 1, 0, 0, 0, 0, 0, 0, 0, 38990, 0, 0, 0, 0, 0, 0, 0, -15595);

DELETE FROM `gossip_menu` WHERE `MenuId` IN (11134,11135,11136);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES 
(11134, 15487, 0),
(11135, 15488, 0),
(11136, 15489, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (11134,11135,11136);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES 
(11134, 0, 0, 'I\'m here to rescue you.', 38986, 1, 1, 0),
(11135, 0, 0, 'Lilian, you\'re one of the Forsaken, like me. Which brings the question: why did the Scarlet Crusade put you in a cage? They usually kill the undead on sight.', 38988, 1, 1, 0),
(11136, 0, 0, 'Your father?', 38991, 1, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11134;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11134, 0, 0, 0, 9, 0, 24979, 0, 0, 0, 0, 0, '', 'Show gossip menu if player accept A Scarlet Letter');

