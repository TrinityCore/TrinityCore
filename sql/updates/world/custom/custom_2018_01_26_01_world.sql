UPDATE `creature_template` SET `VehicleId`=2237 WHERE `entry`= 62454;

-- Creature Fel Soldier 18944 SAI
SET @ENTRY := 18944;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 29, 1, 120, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On data 1 set to 1 - Self: Follow Owner/Summoner by distance 1, angle 120 // Fel Soldier - On Data Set - Follow"),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 29, 6, 120, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On data 2 set to 2 - Self: Follow Owner/Summoner by distance 6, angle 120 // Fel Soldier - On Data Set - Follow"),
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 29, 1, 240, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On data 3 set to 3 - Self: Follow Owner/Summoner by distance 1, angle 240 // Fel Soldier - On Data Set - Follow"),
(@ENTRY, 0, 3, 0, 38, 0, 100, 0, 4, 4, 0, 0, 29, 6, 240, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On data 4 set to 4 - Self: Follow Owner/Summoner by distance 6, angle 240 // Fel Soldier - On Data Set - Follow"),
(@ENTRY, 0, 4, 5, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Cast spell 51347 on Self // Fel Soldier - On Reset - Cast Teleport Visual Only"),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set walk // Fel Soldier - On Respawn - Set Run False"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 0, 3000, 12000, 9000, 15000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 12000 ms (and later repeats every 9000 and 15000 ms) - Self: Cast spell 15496 on Victim // Fel Soldier - In Combat - Cast Cleave"),
(@ENTRY, 0, 7, 0, 0, 0, 100, 0, 6000, 20000, 16000, 33000, 11, 32009, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 20000 ms (and later repeats every 16000 and 33000 ms) - Self: Cast spell 32009 on Victim // Fel Soldier - In Combat - Cast Cutdown"),
(@ENTRY, 0, 8, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Call for help within 15 yards // Fel Soldier - On Aggro - Call For Help"),
(@ENTRY, 0, 9, 0, 60, 0, 100, 0, 5000, 5000, 5000, 5000, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 5000 and 5000 ms (for the first time, timer between 5000 and 5000 ms) - Self: Set home position to current position // Fel Soldier - On Update - Set Home Position"),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 1200000, 1200000, 1200000, 1200000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1200000 and 1200000 ms (and later repeats every 1200000 and 1200000 ms) - Self: Despawn instantly // ");
