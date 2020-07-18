-- 
-- Shadowlord Deathwail
UPDATE `creature_addon` SET `mount`=20684 WHERE `guid`=77084; -- Fix mount

DELETE FROM `creature_template_movement` WHERE `CreatureId`=22006; -- Fix inhabit type
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(22006,1,1,2,0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22006;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22006 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22006,0,0,0,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowlord Deathwail - On Just Died - Say Line 0"),
(22006,0,1,0,0,0,100,0,0,0,3000,5000,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowlord Deathwail - In Combat - Cast 'Shadow Bolt'"),
(22006,0,2,0,0,0,100,0,5000,7000,15000,17000,11,15245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowlord Deathwail - In Combat - Cast 'Shadow Bolt Volley'"),
(22006,0,3,0,0,0,100,0,9000,12000,18000,24000,11,32709,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowlord Deathwail - In Combat - Cast 'Death Coil'"),
(22006,0,4,0,0,0,100,0,14000,17000,22000,28000,11,27641,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowlord Deathwail - In Combat - Cast 'Fear'");

DELETE FROM `creature_text` WHERE `CreatureID`=22006;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22006,0,0,"Master... I've failed you...",14,0,100,0,0,0,19820,0,"Shadowlord Deathwail");

-- Shadowmoon Soulstealer
DELETE FROM `smart_scripts` WHERE `entryorguid`=22061 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22061,0,1,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Soulstealer - On Reset - Set Reactstate Passive"),
(22061,0,2,0,4,0,100,0,0,0,0,0,11,38250,0,0,0,0,0,19,22058,0,0,0,0,0,0,"Shadowmoon Soulstealer - On Aggro - Cast 'Heart of Fury Siphon'");

-- Shadowmoon Darkweaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22081;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22081 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22081,0,0,0,0,0,100,0,0,0,3000,5000,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Darkweaver - In Combat - Cast 'Shadow Bolt'"),
(22081,0,1,0,9,0,100,0,0,30,15000,18000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Darkweaver - Within 0-30 Range - Cast 'Immolate'"),
(22081,0,2,0,9,0,100,0,0,10,8000,11000,11,35373,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkweaver - Within 0-10 Range - Cast 'Shadowfury'");

-- Shadowmoon Chosen
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22084;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22084 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22084,0,0,0,9,0,100,0,0,5,15000,17000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Chosen - Within 0-5 Range - Cast 'Whirlwind'"),
(22084,0,1,0,0,0,100,0,8000,10000,18000,22000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Chosen - In Combat - Cast 'Uppercut'");

-- Shadowmoon Slayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22082;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22082 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22082,0,0,1,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Slayer - Between 0-30% Health - Cast 'Frenzy'"),
(22082,0,1,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Slayer - Between 0-30% Health - Say Line 0"),
(22082,0,2,0,0,0,100,0,5000,7000,12000,15000,11,37577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Slayer - In Combat - Cast 'Debilitating Strike'");

DELETE FROM `creature_text` WHERE `CreatureID`=22082;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22082,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Shadowmoon Slayer");

-- Shadowsworn Drakonid
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22072;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22072 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22072,0,0,0,0,0,100,0,5000,7000,11000,13000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Drakonid - In Combat - Cast 'Cleave'"),
(22072,0,1,0,0,0,100,0,6000,8000,14000,16000,11,17547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Drakonid - In Combat - Cast 'Mortal Strike'"),
(22072,0,2,0,0,0,100,0,9000,11000,18000,22000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Drakonid - In Combat - Cast 'Sunder Armor'");

-- Shadowmoon Retainer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22102;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22102 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22102,0,0,0,0,0,100,0,0,0,2000,4000,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Retainer - In Combat - Cast 'Shoot'");
