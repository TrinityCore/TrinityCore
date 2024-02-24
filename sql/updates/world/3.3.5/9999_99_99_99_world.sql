-- Amberpine Outhouse
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=188666;
DELETE FROM `smart_scripts` WHERE `entryorguid`=188666 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(188666, 1, 0, 1, 62, 0, 100, 0, 9492, 0, 0, 0, 0, 45, 1, 1, 0, 9, 0, 0, 19, 27326, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Set Data to Outhouse Bunny"),
(188666, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 48341, 0, 0, 0, 0, 0, 19, 27326, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Cross Cast Indisposed III"),
(188666, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 134, 53017, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Cast Indisposed"),
(188666, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Close Gossip"),
(188666, 1, 4, 5, 62, 0, 100, 0, 9492, 1, 0, 0, 0, 45, 2, 2, 0, 9, 0, 0, 19, 27326, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Set Data to Outhouse Bunny"),
(188666, 1, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 48341, 0, 0, 0, 0, 0, 19, 27326, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Cross Cast Indisposed III"),
(188666, 1, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 134, 53017, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Cast Indisposed"),
(188666, 1, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Amberpine Outhouse - On Gossip Option Selected - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(14,15) AND `SourceGroup`=9492;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9492, 12775, 0, 0, 9, 0, 12227, 0, 0, 1, 0, 0, '', "Show gossip text if doing your duty not taken"), -- Outhouse In Use
(14, 9492, 12779, 0, 0, 9, 0, 12227, 0, 0, 0, 0, 0, '', "Show gossip text if doing your duty taken"), -- Outhouse avaiable
(15, 9492, 0, 0, 0, 9, 0, 12227, 0, 0, 0, 0, 0, '', "Show gossip option if doing your duty taken"),
(15, 9492, 0, 0, 0, 2, 0, 37247, 1, 0, 0, 0, 0, '', "Show gossip option if player has Anderhols Slider Cider"),
(15, 9492, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, '', "Show gossip option if player is Male"),
(15, 9492, 1, 0, 0, 9, 0, 12227, 0, 0, 0, 0, 0, '', "Show gossip option if doing your duty taken"),
(15, 9492, 1, 0, 0, 2, 0, 37247, 1, 0, 0, 0, 0, '', "Show gossip option if player has Anderhols Slider Cider"),
(15, 9492, 1, 0, 0, 20, 0, 1, 0, 0, 0, 0, 0, '', "Show gossip option if player is Female");

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=27326;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27326 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(2732600,2732601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27326, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 80, 2732600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - On Data Set - Run Script"),
(27326, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 0, 80, 2732601, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - On Data Set - Set Phase 2"),
(2732600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Male)"),
(2732600, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Male)"),
(2732600, 9, 4, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Male)"),
(2732600, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732600, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Male)"),
(2732600, 9, 8, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732600, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Male)"),
(2732600, 9, 10, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 47533, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Camera Shake"),
(2732600, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Male)"),
(2732601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Female)"),
(2732601, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732601, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Female)"),
(2732601, 9, 4, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732601, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Female)"),
(2732601, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732601, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Female)"),
(2732601, 9, 8, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 48329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Dustfield"),
(2732601, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Female)"),
(2732601, 9, 10, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 11, 47533, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Cast Camera Shake"),
(2732601, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 12671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Outhouse Bunny - Script - Play Sound (Female)");
