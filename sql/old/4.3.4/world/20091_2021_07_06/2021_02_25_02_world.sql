-- Creature Twilight Crossfire 45264 SAI
SET @ENTRY := 45264;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 800, 800, 2000, 2000, 11, 84837, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 800 min and 800 max ms (repeat 2000 min 2000 max ms) - Self: Cast spell Shoot (84837) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 18000, 19000, 36000, 38000, 11, 36828, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 18000 min and 19000 max ms (repeat 36000 min 38000 max ms) - Self: Cast spell Rapid Fire (36828) on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 22000, 24000, 11000, 12000, 11, 90488, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 22000 min and 24000 max ms (repeat 11000 min 12000 max ms) - Self: Cast spell Wyvern Sting (90488) on Random hostile // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 26000, 26000, 13000, 15000, 11, 84836, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 26000 min and 26000 max ms (repeat 13000 min 15000 max ms) - Self: Cast spell Multi-Shot (84836) on Victim // ");

-- Creature Twilight Shadow Knight 45261 SAI
SET @ENTRY := 45261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 6000, 6000, 11, 78660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 6000 max ms (repeat 6000 min 6000 max ms) - Self: Cast spell Devastate (78660) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 15000, 16000, 30000, 32000, 11, 84832, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 15000 min and 16000 max ms (repeat 30000 min 32000 max ms) - Self: Cast spell Dismantle (84832) on Victim // ");

-- Creature Twilight Dark Mender 45266 SAI
SET @ENTRY := 45266;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 74, 0, 100, 0, 0, 90, 60, 2400, 2400, 11, 84855, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When friendly unit has HP between 0% - 90% (check every 2400 - 2400 ms) - Self: Cast spell Dark Mending (84855) on Action invoker // ");

-- Creature Twilight Dark Mender 45266 SAI
SET @ENTRY := 45266;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 74, 0, 100, 0, 0, 90, 60, 2400, 2400, 11, 84855, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When friendly unit has HP between 0% - 90% (check every 2400 - 2400 ms) - Self: Cast spell Dark Mending (84855) on Action invoker // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 12000, 12000, 12000, 0, 11, 84856, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 10000 min and 12000 max ms (repeat 12000 min 12000 max ms) - Self: Cast spell Hungering Shadows (84856) on Self // ");

-- Creature Twilight Soul Blade 45265 SAI
SET @ENTRY := 45265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 8000, 10000, 11, 84853, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 10000 max ms (repeat 8000 min 10000 max ms) - Self: Cast spell Dark Pool (84853) on Random hostile // ");

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_bot_wyvern_sting';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(90488, 'spell_bot_wyvern_sting');
