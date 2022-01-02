-- 
DELETE FROM `event_scripts` WHERE `id`=11027;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17715;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=181964;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17715, 1771500) AND `source_type` IN (0, 9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=181964 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181964, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 0, 12, 17715, 4, 300000, 0, 0, 0, 8, 0, 0, 0, -1896.1295, -12861.0811, 87.1412, 3.5412, "Statue of Queen Azshara - On Gameobject State Change - Summon Creature 'Atoph the Bloodcursed'"),
(17715, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, 80, 1771500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Atoph the Bloodcursed - Just Summoned - Run Script"),
(1771500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Atoph the Bloodcursed - On Script - Say Line 0"),
(1771500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -1936.4377, -12878.3730, 85.7825, 3.5632, "Atoph the Bloodcursed - On Script - Move To Pos"),
(1771500, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 50, 181965, 10, 0, 0, 0, 0, 8, 0, 0, 0, -1943.62, -12878.9, 88.3187, 3.8366, "Atoph the Bloodcursed - On Script - Summon Gameobject 'Statue Fire'"),
(1771500, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 181965, 10, 0, 0, 0, 0, 8, 0, 0, 0, -1945.27, -12881.7, 91.1005, 3.73761, "Atoph the Bloodcursed - On Script - Summon Gameobject 'Statue Fire'"),
(1771500, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 181965, 10, 0, 0, 0, 0, 8, 0, 0, 0, -1944.73, -12887.7, 88.1748, 2.81869, "Atoph the Bloodcursed - On Script - Summon Gameobject 'Statue Fire'"),
(1771500, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 181965, 10, 0, 0, 0, 0, 8, 0, 0, 0, -1951.88, -12881.8, 88.8753, 0.304646, "Atoph the Bloodcursed - On Script - Summon Gameobject 'Statue Fire'"),
(1771500, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 181965, 10, 0, 0, 0, 0, 8, 0, 0, 0, -1944.95, -12882.5, 99.2512, 4.0282, "Atoph the Bloodcursed - On Script - Summon Gameobject 'Statue Fire'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=181964;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 181964, 1, 0, 29, 0, 17715, 100, 0, 1, 0, 0, "", "Smart Event 0 for gameobject Statue of Queen Azshara executes if creature Atoph the Bloodcursed is NOT within 100 yards");

DELETE FROM `creature_text` WHERE `CreatureID`=17715;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17715, 0, 0, "Who dares defile the statue of our beloved?", 14, 0, 100, 0, 0, 0, 14366, 0, "Atoph the Bloodcursed");
