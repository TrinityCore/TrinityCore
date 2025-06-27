--
UPDATE `npc_text` SET `text0_0`="The nether drake refuses to let you mount it. Be sure to get a phase disruptor from Professor Dabiri. It will not take you up without one.", `BroadcastTextID0`=18638 WHERE `ID`=10231;
DELETE FROM `gossip_menu` WHERE `MenuID`=8229 AND `TextID`=10231;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(8229, 10231);

UPDATE `conditions` SET `ConditionTypeOrReference`=47, `ConditionValue2`=10 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8229 AND `ConditionTypeOrReference`=9;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8229;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 8229, 10231, 0, 0, 2, 0, 29778, 1, 0, 1, 0, 0, "", "Show gossip text 10231 if player does not have item 23843 in inventory AND"),
(14, 8229, 10231, 0, 0, 47, 0, 10438, 11, 0, 0, 0, 0, "", "Show gossip text 10231 if player has quest 10438");

DELETE FROM `smart_scripts` WHERE `entryorguid`=20899 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20899, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Void Conduit - On Reset - Disable Health Regen"),
(20899, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Void Conduit - On Reset - Set ReactState Passive"),
(20899, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 19554, 100, 0, 0, 0, 0, 0, 0, "Void Conduit - On Death - Say Line 0 (Dimensius the All-Devouring)");

DELETE FROM `creature_text` WHERE `CreatureID`=19554 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19554, 0, 0, "You only hasten the inevitable. In time, all will be devoured!", 14, 0, 100, 0, 0, 0, 18602, 0, "Dimensius the All-Devouring");
