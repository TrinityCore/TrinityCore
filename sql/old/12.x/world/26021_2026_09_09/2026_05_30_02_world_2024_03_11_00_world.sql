-- Fix for "Elder Torntusk" when attacking him
-- Remove "StandState" flag "Dead" from template_addon
UPDATE `creature_template_addon` SET `StandState`=0 WHERE `entry`=14757;

-- Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=14757 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14757,0,1,0,25,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Reset - Set Flag Standstate 'Dead'"),
(14757,0,2,0,4,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Aggro - Remove Flag Standstate 'Dead'");
