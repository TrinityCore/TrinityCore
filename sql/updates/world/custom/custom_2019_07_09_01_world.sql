-- Creature Overlook Spectre 47182 SAI
SET @ENTRY := 47182;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4500, 5000, 16000, 21000, 11, 79113, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4500 and 5000 ms (and later repeats every 16000 and 21000 ms) - Self: Cast spell Ancient Darkness (79113) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10500, 11000, 19000, 21000, 11, 88883, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10500 and 11000 ms (and later repeats every 19000 and 21000 ms) - Self: Cast spell Pact of Darkness (88883) on Self // ");

-- Creature Rustberg Bandit 47627 SAI
SET @ENTRY := 47627;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 66060, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell Sprint (66060) on Self // ");

-- Creature Suspicious Villager 47657 SAI
SET @ENTRY := 47657;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 20000, 26000, 11, 79878, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 20000 and 26000 ms) - Self: Cast spell Bloodthirst (79878) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 9000, 9000, 11000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 9000 ms (and later repeats every 9000 and 11000 ms) - Self: Cast spell Cleave (15496) on Victim // ");

-- Creature Rustberg Fisherman 47642 SAI
SET @ENTRY := 47642;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 71, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Eqipt items from creature 2 // "),
(@ENTRY, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 71, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Eqipt items from creature 1 // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 4500, 5000, 9000, 11000, 11, 32011, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4500 and 5000 ms (and later repeats every 9000 and 11000 ms) - Self: Cast spell Water Bolt (32011) on Victim // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 8500, 9000, 33000, 34000, 11, 78799, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8500 and 9000 ms (and later repeats every 33000 and 34000 ms) - Self: Cast spell Wave Crash (78799) on Victim // "),
(@ENTRY, 0, 4, 0, 1, 0, 100, 0, 14000, 19000, 14000, 19000, 5, 380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 14000 and 19000 ms (and later repeats every 14000 and 19000 ms) - Self: Play emote ONESHOT_FISHING (380) // ");

UPDATE `creature_template_addon` SET `emote`= 379 WHERE `entry`= @ENTRY;
DELETE FROM `creature_equip_template` WHERE `CreatureID`= @ENTRY AND `ID`= 2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`) VALUES
(@ENTRY, 2, 45858);

-- Creature Crazed Soldier 46989 SAI
SET @ENTRY := 46989;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 28000, 29000, 11, 81219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 28000 and 29000 ms) - Self: Cast spell Battle Shout (81219) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 2500, 3000, 11000, 11000, 11, 79881, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2500 and 3000 ms (and later repeats every 11000 and 11000 ms) - Self: Cast spell Slam (79881) on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 10000, 11000, 18000, 20000, 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 11000 ms (and later repeats every 18000 and 20000 ms) - Self: Cast spell Rend (11977) on Victim // ");

-- Creature Crazed Guard 47130 SAI
SET @ENTRY := 47130;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 2000, 2000, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 2000 and 2000 ms) - Self: Cast spell Shoot (6660) on Victim // ");

-- Creature Shipwrecked Sailor 46605 SAI
SET @ENTRY := 46605;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 7000, 8000, 9000, 11000, 11, 75388, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 8000 ms (and later repeats every 9000 and 11000 ms) - Self: Cast spell Rusty Cut (75388) on Victim // ");
UPDATE `creature_template_addon` SET `auras`= '84305' WHERE `entry`= @ENTRY;

-- Creature Tank 46608 SAI
SET @ENTRY := 46608;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 20, `mechanic_immune_mask`= 16 | 32 | 64 | 2048 | 65536 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 30000, 30000, 11, 81173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 30000 and 30000 ms) - Self: Cast spell Frenzy (81173) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 12000, 12000, 16000, 16000, 11, 69203, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 12000 and 12000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell Vicious Bite (69203) on Victim // ");
DELETE FROM `creature_template_movement` WHERE `CreatureID`= 46608;
INSERT INTO `creature_template_movement` (`CreatureID`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(46608, 0, 1, 0, 0);

-- Creature Accursed Longshoreman 46630 SAI
SET @ENTRY := 46630;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 16000, 16000, 11, 79902, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell Plague Strike (79902) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 16000, 16000, 11, 83562, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell Curse of Life (83562) on Victim // ");

-- Creature Foreman Wellson 46648 SAI
SET @ENTRY := 46648;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 10 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 30000, 60000, 30000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 30000 and 60000 ms (and later repeats every 30000 and 60000 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 4500, 5000, 8000, 11000, 11, 80146, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4500 and 5000 ms (and later repeats every 8000 and 11000 ms) - Self: Cast spell Bonk (80146) on Victim // ");

DELETE FROM `creature_text` WHERE `CreatureID`= 46648;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(46648, 0, 0, 'Let\'s get back to work, people!', 14, 0, 100, 0, 0, 0, 46722, 'Foreman Wellson'),
(46648, 0, 1, 'These ships are not going to build themselves!', 14, 0, 100, 0, 0, 0, 46723, 'Foreman Wellson'),
(46648, 0, 2, 'I expect the highest quality craftmanship from my workforce.  Double your efforts!', 14, 0, 100, 0, 0, 0, 46724, 'Foreman Wellson');
