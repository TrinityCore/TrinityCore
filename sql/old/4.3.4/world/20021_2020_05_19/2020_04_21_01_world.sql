UPDATE `creature_template` SET `unit_flags`= 0x8 | 0x100 | 0x200 WHERE `entry` IN (48115, 48633, 48634, 48636, 48637, 48638);
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (48115, 48633, 48634, 48636, 48637, 48638);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Random`) VALUES
(48115, 0, 0, 1, 1, 0),
(48633, 0, 0, 1, 1, 0),
(48634, 0, 0, 1, 1, 0),
(48636, 0, 0, 1, 1, 0),
(48637, 0, 0, 1, 1, 0),
(48638, 0, 0, 1, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (48115, 48633, 48634, 48636, 48637, 48638);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(48115, 1, '89481'),
(48633, 1, '89481'),
(48634, 1, '89481'),
(48636, 1, '89481'),
(48637, 1, '89481'),
(48638, 1, '89481');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_gen_guild_battle_standard',
'spell_gen_guild_battle_standard_buff');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(89481, 'spell_gen_guild_battle_standard'),
(90216, 'spell_gen_guild_battle_standard_buff'),
(90708, 'spell_gen_guild_battle_standard_buff');

SET @ENTRY := 48115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 23235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

SET @ENTRY := 48633;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 23235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

SET @ENTRY := 48634;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 23235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

SET @ENTRY := 48636;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 23235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

SET @ENTRY := 48637;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 23235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

SET @ENTRY := 48638;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 23235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");
