-- 
-- Uruson
DELETE FROM `smart_scripts` WHERE `entryorguid`=14428 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14428,0,0,0,0,0,100,0,10000,15000,30000,35000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uruson - IC - Cast Demoralizing Roar");

-- Rageclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=7318 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7318,0,0,0,4,0,100,1,0,0,0,0,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rageclaw - On Aggro - Cast Bear Form"),
(7318,0,1,0,0,0,100,0,5000,7000,7000,10000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rageclaw - IC - Cast Maul");

-- Greenpaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1993 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1993,0,0,0,2,0,100,0,0,50,13000,19000,11,774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greenpaw - Between 0-50% Health - Cast Rejuvenation"),
(1993,0,1,0,0,0,100,0,3000,5000,7000,11000,11,2606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greenpaw - In Combat - Cast Shock");

-- Ursal the Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2039 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2039,0,0,0,0,0,100,0,4000,7000,5000,8000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursal the Mauler - In Combat - Cast Maul");

-- Grimmaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14429;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14429 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14429,0,0,0,0,0,100,0,5000,7000,12000,20000,11,19319,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimmaw - IC - Cast Vicious Bite");

-- Feral Nightsaber
DELETE FROM `smart_scripts` WHERE `entryorguid`=2034 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2034,0,0,0,0,0,100,0,5000,7000,10000,16000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feral Nightsaber - IC - Cast Muscle Tear");

-- Duskstalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=14430 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14430,0,0,0,0,0,100,0,3000,5000,4000,6000,11,3604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Duskstalker - In Combat - Cast Tendon Rip");

-- Webwood Lurker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1998;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1998 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1998,0,0,0,0,0,100,0,3000,7000,13000,17000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Webwood Lurker - In Combat - Cast Poison");

-- Webwood Venomfang
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1999;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1999 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1999,0,0,0,0,0,100,0,3000,7000,13000,17000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Webwood Venomfang - In Combat - Cast Poison");

-- Webwood Silkspinner
DELETE FROM `smart_scripts` WHERE `entryorguid`=2000 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2000,0,0,0,9,0,100,0,0,30,40000,60000,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Webwood Silkspinner - Within 0-30 Range - Cast Web"),
(2000,0,1,0,0,0,100,0,3000,7000,13000,17000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Webwood Silkspinner - In Combat - Cast Poison");

-- Giant Webwood Spider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2001 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2001,0,0,0,0,0,100,0,3000,7000,13000,17000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Webwood Spider - In Combat - Cast Poison");

-- Threggil
DELETE FROM `smart_scripts` WHERE `entryorguid`=14432 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14432,0,0,0,0,0,100,0,5000,7000,5000,8000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Threggil - IC - Cast Strike");

-- Lord Melenas
DELETE FROM `smart_scripts` WHERE `entryorguid`=2038 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2038,0,0,0,4,0,100,0,0,0,0,0,11,5759,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Melenas - On Aggro - Cast Cat Form"),
(2038,0,1,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Melenas - On Aggro - Set Event Phase 1"),
(2038,0,2,0,0,1,100,0,5000,7000,13000,18000,11,1822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Melenas - IC - Cast Rake (Phase 1)"),
(2038,0,3,4,2,1,100,1,0,30,0,0,28,5759,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Melenas - Between 0-30% Health - Remove Aura Cat Form"),
(2038,0,4,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Melenas - Between 0-30% Health - Set Phase 2"),
(2038,0,5,0,2,2,100,0,0,30,12000,18000,11,774,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Melenas - Between 0-30% Health - Cast Rejuvenation (Phase 2)");

-- Timberling Bark Ripper
DELETE FROM `smart_scripts` WHERE `entryorguid`=2025 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2025,0,0,0,0,0,100,0,5000,7000,22000,25000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timberling Bark Ripper - IC - Cast Pierce Armor");

-- Timberling Trampler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2027 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2027,0,0,0,0,0,100,0,6000,11000,7000,12000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timberling Trampler - In Combat - Cast Trample");

-- Timberling Mire Beast
DELETE FROM `smart_scripts` WHERE `entryorguid`=2029 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2029,0,0,0,0,0,100,0,5000,7000,12000,17000,11,5567,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timberling Mire Beast - IC - Cast Miring Mud");

-- Elder Timberling
DELETE FROM `smart_scripts` WHERE `entryorguid`=2030 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2030,0,0,0,1,0,100,0,500,1000,600000,600000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Timberling - Out of Combat - Cast Lightning Shield"),
(2030,0,1,0,16,0,100,0,324,1,15000,30000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Timberling - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield"),
(2030,0,2,0,2,0,100,0,0,50,9000,15000,11,332,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Timberling - Between 0-50% Health - Cast Healing Wave");

-- Fury Shelda
DELETE FROM `smart_scripts` WHERE `entryorguid`=14431 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14431,0,0,0,0,0,100,0,5000,7000,13000,17000,11,3589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fury Shelda - IC - Cast Deafening Screech");

-- Bloodfeather Harpy
DELETE FROM `smart_scripts` WHERE `entryorguid`=2015 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2015,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Harpy - On Aggro - Say Line 0"),
(2015,0,1,0,0,0,100,0,5000,8000,9000,12000,11,6958,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Harpy - In Combat - Cast Blood Leech");

-- Bloodfeather Fury
DELETE FROM `smart_scripts` WHERE `entryorguid`=2019 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2019,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Fury - On Aggro - Say Line 0"),
(2019,0,1,0,2,0,100,0,0,50,14000,18000,11,5515,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Fury - Between 0-50% Health - Cast Savagery");

DELETE FROM `creature_text` WHERE `CreatureID`=2019;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2019,0,0,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Bloodfeather Fury"),
(2019,0,1,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Bloodfeather Fury"),
(2019,0,2,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Bloodfeather Fury");

-- Bloodfeather Wind Witch
DELETE FROM `smart_scripts` WHERE `entryorguid`=2020 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2020,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Wind Witch - On Aggro - Say Line 0"),
(2020,0,1,0,0,0,100,0,5000,7000,11000,16000,11,6982,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Wind Witch - IC - Cast Gust of Wind");

DELETE FROM `creature_text` WHERE `CreatureID`=2020;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2020,0,0,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Bloodfeather Wind Witch"),
(2020,0,1,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Bloodfeather Wind Witch"),
(2020,0,2,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Bloodfeather Wind Witch");

-- Bloodfeather Matriarch
DELETE FROM `smart_scripts` WHERE `entryorguid`=2021 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2021,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Matriarch - On Aggro - Say Line 0"),
(2021,0,1,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Matriarch - In Combat CMC - Cast Lightning Bolt"),
(2021,0,2,0,2,0,100,0,0,50,18000,24000,11,332,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-50% Health - Cast Healing Wave");

DELETE FROM `creature_text` WHERE `CreatureID`=2021;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2021,0,0,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Bloodfeather Matriarch"),
(2021,0,1,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Bloodfeather Matriarch"),
(2021,0,2,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Bloodfeather Matriarch");
