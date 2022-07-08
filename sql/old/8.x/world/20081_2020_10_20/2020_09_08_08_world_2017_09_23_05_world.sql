-- Script out of combat texts and fix gossip texts for NPC Apothecary Venustus
DELETE FROM `gossip_menu` WHERE `MenuID`=7251 AND `TextID` IN (8566, 8567);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7251, 8566, 0),
(7251, 8567, 0);
DELETE FROM `npc_text` WHERE `ID`=8567;
INSERT INTO `npc_text` (`ID`, `Probability0`, `BroadcastTextID0`, `VerifiedBuild`) VALUES
(8567, 1, 12539, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7251;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7251, 8565, 0, 0, 8, 0, 9275, 0, 0, 1, 0, 0, "", "Show gossip text 8565 if quest 'A Little Dash of Seasoning' is NOT rewarded AND"),
(14, 7251, 8565, 0, 0, 16, 0, 128, 0, 0, 1, 0, 0, "", "Show gossip text 8565 if player is NOT a Troll"),
(14, 7251, 8567, 0, 0, 8, 0, 9275, 0, 0, 1, 0, 0, "", "Show gossip text 8567 if quest 'A Little Dash of Seasoning' is NOT rewarded AND"),
(14, 7251, 8567, 0, 0, 16, 0, 128, 0, 0, 0, 0, 0, "", "Show gossip text 8567 if player is a Troll"),
(14, 7251, 8566, 0, 0, 8, 0, 9275, 0, 0, 0, 0, 0, "", "Show gossip text 8566 if quest 'A Little Dash of Seasoning' is rewarded");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16464;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16464) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1646400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16464, 0, 0, 0, 1, 0, 100, 0, 20000, 29000, 290000, 310000, 80, 1646400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Venustus - Out Of Combat - Call Actionlist"),
(1646400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Venustus - On Script - Say Line 0"),
(1646400, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Apothecary Venustus - On Script - Say Line 1");
DELETE FROM `creature_text` WHERE `CreatureID`=16464;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16464, 0, 0, "%s cackles maniacally as he combines the two mixtures in his hands.", 16, 0, 100, 0, 0, 0, 13368, 0, "Apothecary Venustus"),
(16464, 1, 0, "Drat!  This bloodthistle extract doesn't seem to want to combine properly with my poison.  I'll not be deterred - those trolls will be dealt with!  Perhaps a different mixture?", 12, 0, 100, 5, 0, 0, 13369, 0, "Apothecary Venustus");
