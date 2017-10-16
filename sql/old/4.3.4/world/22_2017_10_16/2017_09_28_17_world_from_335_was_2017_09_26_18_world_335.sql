/*
-- Chief Ukorz Sandscalp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7267;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7267 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7267,0,0,0,0,0,100,2,12000,16000,7500,24500,11,11837,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - In Combat - Cast Wide Slash"),
(7267,0,1,0,0,0,100,2,6000,20000,8500,19500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - In Combat - Cast Cleave"),
(7267,0,2,0,5,0,100,2,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - On Killed Unit - Say Line 0"),
(7267,0,3,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-30% Health - Cast Frenzy"),
(7267,0,4,0,2,0,100,3,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-30% Health - Say Line 1"),
(7267,0,5,0,2,0,100,3,0,60,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-60% Health - Cast Frenzy"),
(7267,0,6,0,2,0,100,3,0,60,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-60% Health - Say Line 2"),
(7267,0,7,0,4,0,100,3,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - On Aggro - Say Line 3"),
(7267,0,8,0,4,0,100,3,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - On Aggro - Cast Berserker Stance");

DELETE FROM `creature_text` WHERE `CreatureID`=7267;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7267,0,0,"Die, outlander!",14,0,100,0,0,5877,6226,0,"Chief Ukorz Sandscalp"),
(7267,1,0,"Feel the fury of the sands!",14,0,100,0,0,5879,6227,0,"Chief Ukorz Sandscalp"),
(7267,2,0,"The Sandfury reign supreme!",14,0,100,0,0,5878,6228,0,"Chief Ukorz Sandscalp"),
(7267,3,0,"This desert be mine!",14,0,100,0,0,5876,6225,0,"Chief Ukorz Sandscalp");

-- Ruuzlu
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7797;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7797 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7797,0,0,0,12,0,100,2,20,20,30000,30000,11,7160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ruuzlu - Target Between 0-20% Health - Cast Execute"),
(7797,0,1,0,0,0,100,2,8000,13000,7500,18500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruuzlu - In Combat - Cast Cleave"),
(7797,0,2,0,4,0,100,3,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ruuzlu - On Aggro - Cast Berserker Stance");

-- Gahz'rilla
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7273;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7273 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7273,0,0,0,0,0,100,2,10000,21000,22000,23000,11,11836,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gahz\'rilla - In Combat - Cast Freeze Solid"),
(7273,0,1,0,0,0,100,2,27000,31000,16000,28000,11,11902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gahz\'rilla - In Combat - Cast Gahz\'rilla Slam"),
(7273,0,2,0,0,0,100,2,8500,36000,8500,27000,11,11131,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gahz\'rilla - In Combat - Cast Icicle");

-- Hydromancer Velratha
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7795;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7795 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7795,0,0,0,0,0,100,2,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hydromancer Velratha - In Combat - Cast Shadow Bolt"),
(7795,0,1,0,2,0,100,3,0,50,0,0,11,12491,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hydromancer Velratha - Between 0-50% Health - Cast Healing Wave"),
(7795,0,2,0,9,0,100,2,0,30,17000,22000,11,15245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hydromancer Velratha - Within 0-30 Range - Cast Shadow Bolt Volley"),
(7795,0,3,0,0,0,100,2,2000,5000,13300,27700,11,11086,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hydromancer Velratha - In Combat - Cast Ward of Zum\'rah");

-- Nekrum Gutchewer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7796;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7796 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7796,0,0,0,0,0,100,2,6500,16500,16900,21500,11,8600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nekrum Gutchewer - In Combat - Cast Fevered Plague");

-- Shadowpriest Sezz'ziz
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7275;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7275 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7275,0,0,0,0,0,100,2,0,0,3400,4700,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - In Combat - Cast Shadow Bolt"),
(7275,0,1,0,0,0,100,2,11000,16000,22000,32000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - In Combat - Cast Psychic Scream"),
(7275,0,2,0,14,0,100,2,2000,40,27800,34200,11,8362,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - Friendly At 2000 Health - Cast Renew"),
(7275,0,3,0,14,0,100,2,3000,40,14200,25300,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - Friendly At 3000 Health - Cast Heal"),
(7275,0,4,0,2,0,100,3,0,30,0,0,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - Between 0-30% Health - Cast Renew");

-- Sandfury Executioner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7274;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7274 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7274,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Executioner - On Aggro - Say Line 0"),
(7274,0,1,0,0,0,100,2,8000,13000,8000,23000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Executioner - In Combat - Cast Cleave"),
(7274,0,2,0,5,0,100,2,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Executioner - On Killed Unit - Say Line 1"),
(7274,0,3,0,12,0,100,2,20,20,30000,30000,11,7160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sandfury Executioner - Target Between 0-20% Health - Cast Execute"),
(7274,0,4,0,4,0,100,3,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Executioner - On Aggro - Cast Berserker Stance");

DELETE FROM `creature_text` WHERE `CreatureID`=7274;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7274,0,0,"Let the executions begin!",14,0,100,0,0,5874,6223,0,"Sandfury Executioner"),
(7274,1,0,"Justice is done!",14,0,100,0,0,5875,6224,0,"Sandfury Executioner");

-- Theka the Martyr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7272;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7272 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7272,0,0,0,2,0,100,3,0,30,0,0,11,11089,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theka the Martyr - Between 0-30% Health - Cast Theka Transform"),
(7272,0,1,0,0,0,100,2,15700,18800,10900,22900,11,8600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theka the Martyr - In Combat - Cast Fevered Plague");
*/
