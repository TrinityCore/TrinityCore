SET @NPCTEXTID := 530005;

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (14049 /*A Most Unusual Map*/, 14046 /*The Baron's Demands*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14049, 0, 0, 0, 0, 0, 0, 0, 0, 56819), -- A Most Unusual Map
(14046, 0, 0, 0, 0, 0, 0, 0, 0, 56819); -- The Baron's Demands

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 3467;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(3467, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 3467 (Baron Longshore)

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 3467;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3467, 0, 0, 'Har! Pleasure doin\' business with ye, $n.', 12, 0, 100, 11, 0, 6923, 35052, 5, 'Baron Longshore to Player');

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 35054, 0, 0, 0, 0, 0, 0, 0, 56819); -- 3467 (Baron Longshore)

DELETE FROM `gossip_menu` WHERE (`MenuID`=10568 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10568, @NPCTEXTID+0, 56819); -- 3467 (Baron Longshore)

UPDATE `gossip_menu` SET `VerifiedBuild`=56819 WHERE (`MenuID`=10567 AND `TextID` IN (14624,14623));

UPDATE `gossip_menu_option` SET `GossipOptionID`=38560, `OptionBroadcastTextID`=35051, `VerifiedBuild`=56819 WHERE (`MenuID`=10567 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=38559, `OptionBroadcastTextID`=35050, `ActionMenuID`=10568, `VerifiedBuild`=56819 WHERE (`MenuID`=10567 AND `OptionID`=0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (10567));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 10567, 0, 0, 0, 47, 0, 14046, 8, 0, '', 0, 'Player for which gossip text is shown has The Baron\'s Demands (14046) in state incomplete'),
(15, 10567, 1, 0, 0, 47, 0, 14046, 8, 0, '', 0, 'Player for which gossip text is shown has The Baron\'s Demands (14046) in state incomplete');

-- Baron Longshore smart ai
SET @ENTRY := 3467;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 10567, 1, 0, 0, 0, 33, 34769, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 10567 selected - Gossip player: Give kill credit Baron Longshore Quest Credit (34769)', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 10567 selected - Self: Talk 0 to Gossip player', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 10567 selected - Gossip player: Close gossip', '');
