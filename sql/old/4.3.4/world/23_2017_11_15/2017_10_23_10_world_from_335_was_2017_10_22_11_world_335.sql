/*
-- Lady Anacondra
UPDATE `creature_template` SET `ManaModifier`=4 WHERE `entry`=3671;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3671 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3671,0,1,0,0,0,100,2,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Anacondra - In Combat - Cast Lightning Bolt"),
(3671,0,2,0,0,0,100,2,8000,12000,12000,25000,11,700,32,0,0,0,0,6,0,0,0,0,0,0,0,"Lady Anacondra - In Combat - Cast Sleep"),
(3671,0,3,0,0,0,100,2,1000,1000,50000,60000,11,8148,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Anacondra - In Combat - Cast Thorns Aura"),
(3671,0,4,0,1,0,100,3,1000,1000,0,0,11,13236,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Anacondra - Out of Combat - Cast Nature Channeling"),
(3671,0,5,0,2,0,100,2,0,50,15000,26000,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Anacondra - Between 0-50% Health - Cast Healing Touch"),
(3671,0,6,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Anacondra - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3671;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3671,0,0,"None can stand against the Serpent Lords!",14,0,100,0,0,5786,6097,0,"Lady Anacondra");

-- Lord Cobrahn
UPDATE `creature_template` SET `ManaModifier`=4 WHERE `entry`=3669;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3669 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3669,0,1,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - On Aggro - Set Event Phase 1"),
(3669,0,2,0,0,1,100,2,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Cobrahn - In Combat - Cast Lightning Bolt (Phase 1)"),
(3669,0,3,0,0,1,100,2,10000,10000,13000,20000,11,8040,0,0,0,0,0,6,0,0,0,0,0,0,0,"Lord Cobrahn - In Combat - Cast Druid's Slumber (Phase 1)"),
(3669,0,4,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - On Aggro - Say Line 0"),
(3669,0,5,0,2,1,100,2,0,50,18000,24000,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - Between 0-50% Health - Cast Healing Touch (Phase 1)"),
(3669,0,6,7,2,0,100,3,0,30,0,0,11,7965,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - Between 0-30% Health - Cast Cobrahn Serpent Form"),
(3669,0,7,8,61,0,100,3,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - Between 0-30% Health - Set Event Phase 2"),
(3669,0,8,0,61,0,100,3,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - Between 0-30% Health - Enable Combat Movement"),
(3669,0,9,0,0,2,100,2,3000,4000,3000,4000,11,17330,32,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Cobrahn - In Combat - Cast Poison (Phase 2)");

DELETE FROM `creature_text` WHERE `CreatureID`=3669;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3669,0,0,"You will never wake the dreamer!",14,0,100,0,0,5785,6094,0,"Lord Cobrahn");

-- Lord Pythas
UPDATE `creature_template` SET `ManaModifier`=4 WHERE `entry`=3670;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3670 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3670,0,1,0,0,0,100,2,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Pythas - In Combat - Cast Lightning Bolt"),
(3670,0,2,0,2,0,100,2,0,50,20000,25000,11,11431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Pythas - Between 0-50% Health - Cast Healing Touch"),
(3670,0,3,0,0,0,100,2,8000,12000,12000,20000,11,700,32,0,0,0,0,6,0,0,0,0,0,0,0,"Lord Pythas - In Combat - Cast Sleep"),
(3670,0,4,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Pythas - On Aggro - Say Line 0"),
(3670,0,5,0,0,0,100,2,5000,9000,12000,15000,11,8147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Pythas - In Combat - Cast Thunderclap");

DELETE FROM `creature_text` WHERE `CreatureID`=3670;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3670,0,0,"The coils of death will crush you!",14,0,100,0,0,5787,6095,0,"Lord Pythas");

-- Lord Serpentis
UPDATE `creature_template` SET `ManaModifier`=4 WHERE `entry`=3673;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3673 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3673,0,1,0,0,0,100,2,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Serpentis - In Combat - Cast Lightning Bolt"),
(3673,0,2,0,2,0,100,2,0,50,20000,25000,11,6778,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Serpentis - Between 0-50% Health - Cast Healing Touch"),
(3673,0,3,0,0,0,100,2,6000,8000,10000,19000,11,700,32,0,0,0,0,6,0,0,0,0,0,0,0,"Lord Serpentis - In Combat - Cast Sleep"),
(3673,0,4,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Serpentis - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3673;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3673,0,0,"I am the serpent king! I can do anything!",14,0,100,0,0,5788,6096,0,"Lord Serpentis");

-- Mutanus the Devourer
DELETE FROM `smart_scripts` WHERE `entryorguid`=3654 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3654,0,1,0,0,0,100,2,15000,21000,18000,24000,11,7399,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mutanus the Devourer - In Combat - Cast Terrify"),
(3654,0,2,0,0,0,100,2,6000,11000,25000,36000,11,7967,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mutanus the Devourer - In Combat - Cast Naralex's Nightmare"),
(3654,0,3,0,0,0,100,2,10000,14000,10000,16000,11,8150,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mutanus the Devourer - In Combat - Cast Thundercrack");

-- Druid of the Fang
DELETE FROM `smart_scripts` WHERE `entryorguid`=3840 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3840,0,3,0,14,1,100,2,800,40,12000,18000,11,5187,1,0,0,0,0,7,0,0,0,0,0,0,0,"Druid of the Fang - Friendly At 800 Health - Cast Healing Touch");

-- Deviate Venomwing
DELETE FROM `smart_scripts` WHERE `entryorguid`=5756 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5756,0,0,0,0,0,100,2,0,0,3000,4500,11,7951,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Venomwing - In Combat - Cast Toxic Spit");

UPDATE `creature_template` SET `DamageModifier`=2.5 WHERE `entry` IN (3669, 3670, 3671, 3673);
UPDATE `creature_template` SET `DamageModifier`=7.5 WHERE `entry` IN (3654, 5775);
UPDATE `creature_template` SET `DamageModifier`=1 WHERE `entry` IN (5055, 8886, 5053);
*/
