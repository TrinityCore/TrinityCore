-- The Plains Vision
DELETE FROM `creature_text` WHERE `CreatureID`=2983 AND `GroupID`=0; -- Remove wrong text
UPDATE `creature_text` SET `Emote`=393, `Sound`=1018 WHERE `CreatureID`=2983 AND `GroupID` IN (1,2);

DELETE FROM `smart_scripts` WHERE `entryorguid`=298301 AND `source_type`=9 AND `id`=1; -- Remove wrong text
UPDATE `smart_scripts` SET `event_param1`=1000, `event_param2`=1000 WHERE `entryorguid`=298301 AND `source_type`=9 AND `id`=2; -- Adjust timings
UPDATE `smart_scripts` SET `action_param1`=5000, `comment`="The Plains Vision - On Waypoint 49 Reached - Despawn In 5000 ms" WHERE `entryorguid`=2983 AND `source_type`=0 AND `id`=3; -- Increase despawn time

-- Seer Wiserunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=2984 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2984,0,0,0,10,0,100,0,1,5,30000,30000,1,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Seer Wiserunner - OOC LOS - Say Line 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=2984;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,2984,0,0,28,0,772,0,0,0,0,0,"","SAI triggers only if player has quest 'Rite of Vision (Part 3)' completed");
