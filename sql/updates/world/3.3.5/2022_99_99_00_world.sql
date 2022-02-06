-- Remove npc script from Mature Netherwing Drake, set AI to SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 21648;

-- Update NULL comment on Placing Rocknail Flayer Carcass ImplicitTarget condition
UPDATE `conditions` SET `Comment` = 'Spell \'Placing Rocknail Flayer Carcass\' ImplicitTarget is \'Mature Netherwing Drake\'' 
WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=2 AND `SourceEntry`=38439 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=21648 AND `ConditionValue3`=0;

-- Add condition to not cast 'Placing Rocknail Flayer Carcass' on targets with 'Has Eaten Recently' aura
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=3 AND `SourceEntry`=38439 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=1 AND `ConditionTarget`=0 AND `ConditionValue1`=38502 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 38439, 0, 0, 1, 0, 38502, 0, 0, 1, 0, 0, '', 'Do Not cast \'Placing Rocknail Flayer Carcass\' on targets with aura \'Has Eaten Recently\'');

-- SAI for Mature Netherwing Drake
DELETE FROM `smart_scripts` WHERE `entryorguid`=21648 AND `source_type`=0 AND `id` IN (0,1,2,3,4,5,6,7,8);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21648, 0, 0, 1, 8, 0, 100, 0, 38439, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Spellhit \'Placing Rocknail Flayer Carcass\' - Pause Waypoint'),
(21648, 0, 1, 0, 61, 0, 100, 0, 38439, 0, 0, 0, 0, 69, 1, 0, 0, 2, 0, 0, 20, 185155, 500, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Spellhit \'Placing Rocknail Flayer Carcass\' - Move To Closest GO \'Rocknail Flayer Carcass\''),
(21648, 0, 2, 3, 34, 0, 100, 0, 8, 1, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Reached Point 1 - Set Event Phase 1'),
(21648, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2164800, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Reached Point 1 - Run Script'),
(21648, 0, 4, 0, 7, 15, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 'Mature Netherwing Drake - On Evade - Set Home Position On Self Offset Z+1 (Phases 1-4)'),
(21648, 0, 5, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 0, 11, 38467, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - In Combat - Cast \'Netherbreath\''),
(21648, 0, 6, 0, 25, 10, 100, 0, 0, 0, 0, 0, 0, 11, 38502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Reset - Cast \'Has Eaten Recently\' (Phase 2 & 4)'),
(21648, 0, 7, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Reset - Set Event Phase 0'),
(21648, 0, 8, 0, 4, 3, 100, 0, 0, 0, 0, 0, 0, 23, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Aggro - Increment Phase +2 (Phase 1 & 2)');

DELETE FROM `smart_scripts` WHERE `entryorguid`=2164800 AND `source_type`=9 AND `id` IN (0,1,2,3,4,5,6,7,8);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2164800, 9, 0, 0, 0, 1, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 20, 185155, 10, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (0s) - Set Orientation GO \'Rocknail Flayer Carcass\' (Phase 1)'),
(2164800, 9, 1, 0, 0, 1, 100, 0, 1000, 1000, 0, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (1s) - Play Emote 35 (Phase 1)'),
(2164800, 9, 2, 0, 0, 1, 100, 0, 1000, 1000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 20, 185155, 10, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (1s) - Despawn GO \'Rocknail Flayer Carcass\' (Phase 1)'),
(2164800, 9, 3, 0, 0, 1, 100, 0, 0, 0, 0, 0, 0, 11, 38502, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (0s) - Cast \'Has Eaten Recently\' (Phase 1)'),
(2164800, 9, 4, 0, 0, 1, 100, 0, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (0s) - Increment Phase +1 (Phase 1)'),
(2164800, 9, 5, 0, 0, 2, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (1s) - Set Orientation Invoker (Phase 2)'),
(2164800, 9, 6, 0, 0, 2, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (1s) - Say Line 0 (Phase 2)'),
(2164800, 9, 7, 0, 0, 2, 100, 0, 0, 0, 0, 0, 0, 85, 38440, 2, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (0s) - Invoker Party Cast \'Serverside - Kill Credit: Feed Nether Drake\' (Phase 2)'),
(2164800, 9, 8, 0, 0, 2, 100, 0, 4000, 4000, 0, 0, 0, 24, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mature Netherwing Drake - On Script (4s) - Evade (Phase 2)');
