-- Wasteland Outrider
UPDATE `creature_template_addon` SET `mount`= 37212 WHERE `entry`= 45905;
UPDATE `creature_loot_template` SET `QuestRequired`= 1 WHERE `Entry`= 45905 AND `Item`= 63081;

-- Warlord Ihsenn
UPDATE `creature_template_addon` SET `mount`= 37212 WHERE `entry`= 47755;
SET @ENTRY := 47755;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 42459, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Cast spell Dual Wield (42459) on Self'),
(@ENTRY, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 6434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Cast spell Slice and Dice (6434) on Self');


 -- Venomblood Scorpid
SET @ENTRY := 45859;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = '' WHERE `entry` = @ENTRY;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_uldum_draining_venom';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88882, 'spell_uldum_draining_venom');
