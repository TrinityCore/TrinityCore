-- Remove Mistwhisper Refuge Zepik spawn
DELETE FROM `creature` WHERE `id` = 28216;

-- Add SAI to High-Shaman Rakjak to give horn when accepting A rough ride
DELETE FROM `smart_scripts` WHERE `entryorguid`=28082 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28082, 0, 0, 0, 19, 0, 100, 0, 12536, 0, 0, 0, 56, 38512, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - On acccept quest A rough ride - give Zepik''s Hunting Horn');
