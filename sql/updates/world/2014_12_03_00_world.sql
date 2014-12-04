DELETE FROM `smart_scripts` WHERE `entryorguid`=18688  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1868800  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18688, 0, 0, 1, 8, 0, 100, 0, 34063, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit "Soul Mirror" - Say Line 1'),
(18688, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 36, 19480, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit "Soul Mirror" - Change Entry to Darkened Spirit'),
(18688, 0, 2, 0, 0, 0, 100, 0, 20000, 40000, 60000, 180000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - In Combat - Say Line 0 (Phase 1) (No Repeat)');

UPDATE `vehicle_template_accessory` SET `minion`=0 WHERE `entry` IN(32640,32633);
