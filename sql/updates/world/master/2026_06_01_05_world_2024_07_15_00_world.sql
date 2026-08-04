-- Forgotten Depths Ambusher
SET @ENTRY := 30204;
-- Update auras
UPDATE `creature_template_addon` SET `auras`='42459 56422' WHERE `entry`=@ENTRY; -- Dual Wield, Nerubian Submerge
-- Update unit flags
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=@ENTRY;
-- Forgotten Depths Ambusher smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 28, 56422, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Ambusher - On just summoned - Remove 'Nerubian Submerge' aura (No Repeat)"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 11, 56418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Ambusher - On link - Cast spell 'Emerge From Snow' on Self (No Repeat)"),
(@ENTRY, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, "Forgotten Depths Ambusher - On link - Attack start on closest player (No Repeat)"),
(@ENTRY, 0, 3, 0, 7, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Forgotten Depths Ambusher - On evade - Despawn instantly (No Repeat)");
