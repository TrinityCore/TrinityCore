SET @NPCTEXTID := 600052;

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=224708 AND `quest` IN (82800,0));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(224708, 82800, 57689); -- A Sedimental Moment ended by Cenderragg

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 226838;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(226838, 0, 0, 'Thank you, $c. I will not forget this.', 12, 0, 100, 0, 0, 0, 0, 0, 'Opalcreg Worker to Player'),
(226838, 0, 1, 'Thank you for working to restore the mine.', 12, 0, 100, 0, 0, 0, 0, 0, 'Opalcreg Worker to Player'),
(226838, 0, 2, 'Cogs bless you.', 12, 0, 100, 0, 0, 0, 0, 0, 'Opalcreg Worker to Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=226838 AND `MenuID`=35321);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(226838, 35321, 57689); -- Opalcreg Worker

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 267009, 0, 0, 0, 0, 0, 0, 0, 57689); -- 226838 (Opalcreg Worker)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35321 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35321, @NPCTEXTID+0, 57689); -- 226838 (Opalcreg Worker)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=35321 AND `OptionID` IN (1,0,2,3));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35321, 123365, 1, 0, 'We grabbed so much more. Don\'t worry.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35321, 122997, 0, 0, 'There\'s still a whole lot of nerubians out there. Good luck.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35321, 123364, 2, 0, 'The Stormriders will be here at any moment!', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35321, 123363, 3, 0, 'Then all my sacrifice... was for nothing?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` IN (35321));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(14, 35321, @NPCTEXTID+0, 0, 0, 9, 0, 82800, 0, 0, '', 0, 'Player for which gossip text is shown has quest A Sedimental Moment (82800) active');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (35321));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 35321, 0, 0, 0, 9, 0, 82800, 0, 0, '', 0, 'Player for which gossip text is shown has quest A Sedimental Moment (82800) active'),
(15, 35321, 1, 0, 0, 9, 0, 82800, 0, 0, '', 0, 'Player for which gossip text is shown has quest A Sedimental Moment (82800) active'),
(15, 35321, 2, 0, 0, 9, 0, 82800, 0, 0, '', 0, 'Player for which gossip text is shown has quest A Sedimental Moment (82800) active'),
(15, 35321, 3, 0, 0, 9, 0, 82800, 0, 0, '', 0, 'Player for which gossip text is shown has quest A Sedimental Moment (82800) active');

-- Opalcreg Worker smart ai
SET @ENTRY := 226838;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 35321, 0, 0, 0, 0, 80, 22683800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 35321 selected - Self: Start timed action list id #Opalcreg Worker #0 (22683800) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 35321 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 62, 0, 100, 0, 35321, 1, 0, 0, 0, 80, 22683800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 35321 selected - Self: Start timed action list id #Opalcreg Worker #0 (22683800) (update out of combat)', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 35321 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 4, 5, 62, 0, 100, 0, 35321, 2, 0, 0, 0, 80, 22683800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 2 from menu 35321 selected - Self: Start timed action list id #Opalcreg Worker #0 (22683800) (update out of combat)', ''),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 2 from menu 35321 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 6, 7, 62, 0, 100, 0, 35321, 3, 0, 0, 0, 80, 22683800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 3 from menu 35321 selected - Self: Start timed action list id #Opalcreg Worker #0 (22683800) (update out of combat)', ''),
(@ENTRY, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 3 from menu 35321 selected - Gossip player: Close gossip', '');

-- Timed list 22683800 smart ai
SET @ENTRY := 22683800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 226838, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Opalcreg Worker (226838)', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 8, 0, 0, 'After 2 seconds - Self: Move forward by 0, left by 8, up by 0 yards', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Despawn instantly', '');
