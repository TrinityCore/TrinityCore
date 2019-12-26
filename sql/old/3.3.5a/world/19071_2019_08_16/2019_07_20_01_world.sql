DELETE FROM `npc_text` WHERE `ID`=9635;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(9635, "Please, $r, get me out of here! Unlocking the cage will surely attract my brother's attention. Kill Darkweaver Syth!", 16052);

DELETE FROM `gossip_menu` WHERE `MenuID`=7868 AND `TextID`=9635;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7868, 9635, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7868 AND `SourceEntry` IN (9635, 9636);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7868 AND `ConditionTypeOrReference`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7868, 9635, 0, 0, 13, 1, 0, 3, 2, 1, 0, 0, "", "Gossip text requires boss Darkweaver Sith NOT defeated"),
(14, 7868, 9636, 0, 0, 13, 1, 0, 3, 2, 0, 0, 0, "", "Gossip text requires boss Darkweaver Sith defeated"),
(15, 7868, 0, 0, 0, 13, 1, 0, 3, 2, 0, 0, 0, "", "Gossip option requires boss Darkweaver Sith defeated");

DELETE FROM `creature_text` WHERE `CreatureID`=18956 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18956, 1, 0, "Well done! Hurry, though, we don't want to be caught!", 14, 0, 100, 0, 0, 0, 16056, 0, "Lakka");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1895600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1895600, 9, 0, 0, 0, 0, 100, 7, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lakka - On Script - Close Gossip"),
(1895600, 9, 1, 0, 0, 0, 100, 7, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lakka - On Script - Remove Gossip Npcflag"),
(1895600, 9, 2, 0, 0, 0, 100, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lakka - On Script - Say Line 0"),
(1895600, 9, 3, 0, 0, 0, 100, 7, 0, 0, 0, 0, 0, 33, 18956, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, "Lakka - On Script - Quest Credit 'Brother Against Brother'"),
(1895600, 9, 4, 0, 0, 0, 100, 7, 1000, 1000, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 67620, 183051, 0, 0, 0, 0, 0, "Lakka - On Script - Activate Gameobject Sethekk Cage"),
(1895600, 9, 5, 0, 0, 0, 100, 7, 2000, 2000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -155.6249, 162.0906, 0.0098, 0, "Lakka - On Script - Move To Pos"),
(1895600, 9, 6, 0, 0, 0, 100, 7, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lakka - On Script - Despawn In 5 Seconds");
