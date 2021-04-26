-- Creature Bound Zephyr 49821 SAI
SET @ENTRY := 49821;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 5000, 6000, 6000, 11, 93278, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 5000 max ms (repeat 6000 min 6000 max ms) - Self: Cast spell Lightning Shock (93278) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 5500, 5500, 6000, 6000, 11, 93277, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 5500 min and 5500 max ms (repeat 6000 min 6000 max ms) - Self: Cast spell Rending Gale (93277) on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 15000, 17000, 15000, 15000, 11, 93306, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 15000 min and 17000 max ms (repeat 15000 min 15000 max ms) - Self: Cast spell Vaporize (93306) on Victim // ");

-- Creature Bound Rumbler 49826 SAI
SET @ENTRY := 49826;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5500, 5500, 6000, 6000, 11, 93327, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 5500 min and 5500 max ms (repeat 6000 min 6000 max ms) - Self: Cast spell Entomb (93327) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 15000, 15000, 11, 93325, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 7000 max ms (repeat 15000 min 15000 max ms) - Self: Cast spell Shockwave (93325) on Self // ");

-- Creature Bound Deluge 49825 SAI
SET @ENTRY := 49825;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 10000, 11000, 16000, 17000, 11, 93340, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 10000 min and 11000 max ms (repeat 16000 min 17000 max ms) - Self: Cast spell Frost Whirl (93340) on Self // ");

-- Creature Bound Inferno 49817 SAI
SET @ENTRY := 49817;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 16000, 17000, 14000, 15000, 11, 93362, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 16000 min and 17000 max ms (repeat 14000 min 15000 max ms) - Self: Cast spell Flamestrike (93362) on Random hostile // ");

UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= `flags_extra` | 128 WHERE `entry`= 50297;
DELETE FROM `creature_template_addon` WHERE `entry`= 50297;

-- Creature Flamestrike 50297 SAI
SET @ENTRY := 50297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 93363, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Flamestrike (93363) on Self // ");

DELETE FROM `conditions` WHERE `SourceEntry` IN (93364, 93384) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 93364, 0, 0, 31, 0, 3, 49825, 0, 0, 0, '', 'Flame Strike - Target Bound Deluge'),
(13, 2, 93384, 0, 0, 31, 0, 3, 49825, 0, 0, 0, '', 'Flame Strike - Target Bound Deluge');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_bot_rending_gale',
'spell_bot_entomb',
'spell_bot_ward_of_combustion',
'spell_bot_flame_strike');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93277, 'spell_bot_rending_gale'),
(93388, 'spell_bot_rending_gale'),
(93327, 'spell_bot_entomb'),
(93385, 'spell_bot_entomb'),
(93336, 'spell_bot_ward_of_combustion'),
(93364, 'spell_bot_flame_strike'),
(93384, 'spell_bot_flame_strike');
