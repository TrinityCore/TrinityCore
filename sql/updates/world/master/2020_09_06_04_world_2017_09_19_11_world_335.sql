-- Lord Maldazzar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1848;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1848 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1848,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Maldazzar - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1848,0,1,0,0,0,100,0,6000,9000,15000,20000,11,17204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Maldazzar - In Combat - Cast Summon Skeleton"),
(1848,0,2,0,0,0,100,0,12000,16000,15000,19000,11,17173,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Maldazzar - In Combat - Cast Drain Life"),
(1848,0,3,0,0,0,100,0,0,0,3400,4800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Maldazzar - In Combat - Cast Shadow Bolt");

-- Jabbering Ghoul
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10801 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10801,0,0,0,4,0,100,0,0,0,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jabbering Ghoul - On Aggro - Cast Enrage"),
(10801,0,1,0,0,0,100,0,4000,7000,9000,13000,11,12097,1,0,0,0,0,2,0,0,0,0,0,0,0,"Jabbering Ghoul - In Combat - Cast Pierce Armor"),
(10801,0,2,0,11,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jabbering Ghoul - On Respawn - Cast Birth");

-- Farmer Dalson
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10836;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10836 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10836,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farmer Dalson - Out of Combat - Cast Birth (No Repeat)"),
(10836,0,1,0,4,0,100,0,0,0,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farmer Dalson - On Aggro - Cast Enrage"),
(10836,0,2,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Farmer Dalson - In Combat - Cast Thrash"),
(10836,0,3,0,9,0,100,0,0,5,7000,12000,11,16128,33,0,0,0,0,2,0,0,0,0,0,0,0,"Farmer Dalson - In Combat - Cast Infected Bite");

-- Wandering Skeleton
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10816;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10816 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10816,0,0,0,0,0,75,0,1000,3000,3000,6000,11,17014,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wandering Skeleton - In Combat - Cast Bone Shards");

-- Foulmane
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1847;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1847 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1847,0,0,0,11,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulmane - On Respawn - Cast Birth"),
(1847,0,1,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foulmane - In Combat - Cast Thrash"),
(1847,0,2,0,9,0,100,0,0,5,19000,23000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foulmane - In Combat - Cast Rend"),
(1847,0,3,0,0,0,100,0,8000,9000,20000,22000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foulmane - Cast Infected Wound");

-- Skeletal Flayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1785;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1785 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1785,0,0,0,0,0,100,0,5000,9000,18000,26000,11,12542,0,0,0,0,0,5,0,0,0,0,0,0,0,"Skeletal Flayer - In Combat - Cast Fear");

-- Plague Lurker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1824;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1824 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1824,0,0,0,0,0,100,0,7000,9000,17000,19000,11,85713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Lurker - In Combat - Cast Intoxicating Venom");

-- Fetid Zombie
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10580;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10580 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10580,0,0,0,11,0,100,1,0,0,0,0,11,8713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fetid Zombie - On Respawn - Cast Overwhelming Musk (No Repeat)");

-- Cauldron Lord Bilemaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11075;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11075 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11075,0,0,0,9,0,100,0,0,5,7000,12000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Bilemaw - Within 0-5 Range - Cast Infected Wound"),
(11075,0,1,0,9,0,100,0,0,5,18000,22000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Bilemaw - Within 0-5 Range - Cast Rend"),
(11075,0,2,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Bilemaw - In Combat - Cast Thrash"),
(11075,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cauldron Lord Bilemaw - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=11075;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11075,0,0,"$R flesh... must feed!",14,0,100,0,0,0,6494,0,"Cauldron Lord Bilemaw");

-- Cauldron Lord Razarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11076;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11076 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11076,0,0,0,0,0,100,0,0,0,3400,4800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Razarch - In Combat - Cast Shadow Bolt"),
(11076,0,1,0,0,0,100,0,11000,15000,20000,25000,11,17204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cauldron Lord Razarch - In Combat - Cast Summon Skeleton"),
(11076,0,2,0,2,0,100,0,0,50,14000,18000,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Razarch - Between 0-50% Health - Cast Drain Life"),
(11076,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cauldron Lord Razarch - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=11076;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11076,0,0,"The Scourge beckons you, foolish $r.",14,0,100,0,0,0,6496,0,"Cauldron Lord Razarch");

-- Cauldron Lord Malvinious
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11077;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11077 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11077,0,0,0,0,0,100,0,0,0,3400,4800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Malvinious - In Combat - Cast Shadow Bolt"),
(11077,0,1,0,0,0,100,0,11000,15000,20000,25000,11,17204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cauldron Lord Malvinious - In Combat - Cast Summon Skeleton"),
(11077,0,2,0,2,0,100,0,0,50,14000,18000,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cauldron Lord Malvinious - Between 0-50% Health - Cast Drain Life"),
(11077,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cauldron Lord Malvinious - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=11077;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11077,0,0,"Who dares to approach this cauldron?  Taste my dark blade!",14,0,100,0,0,0,6495,0,"Cauldron Lord Malvinious");

-- Cauldron Lord Soulwrath
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11078;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11078 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11078,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80132,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cauldron Lord Soulwrath - Cast Unbound Darkness'),
(11078,0,1,0,0,0,100,0,10000,12000,10000,25000,11,85800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cauldron Lord Soulwrath - Cast Shadowflame'),
(11078,0,2,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cauldron Lord Soulwrath - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=11078;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11078,0,0,"$C - I will consume your light!",14,0,100,0,0,0,6497,0,"Cauldron Lord Soulwrath");

-- Decrepit Guardian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10943;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10943 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10943,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Guardian - Out of Combat - Cast Birth (No Repeat)"),
(10943,0,1,0,9,0,100,0,0,30,16000,24000,11,16333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Decrepit Guardian - Within 0-30 Range - Cast Debilitating Touch");

-- Scarlet Lumberjack
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1884;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1884 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1884,0,0,0,9,0,100,0,0,5,7000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Lumberjack - Within 0-5 Range - Cast Cleave"),
(1884,0,1,0,0,0,100,0,8000,13000,17000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Lumberjack - In Combat - Cast Rend"),
(1884,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Lumberjack - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Priest
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10608;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10608 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10608,0,0,0,0,0,100,0,0,0,3400,4800,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Priest - In Combat - Cast Holy Smite"),
(10608,0,1,0,16,0,100,0,13864,30,3000,6000,11,13864,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Priest - On Friendly Unit Missing Buff Power Word: Fortitude - Cast Power Word: Fortitude"),
(10608,0,2,0,14,0,100,0,2000,40,12000,15000,11,12039,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Priest - Friendly At 2000 Health - Cast Heal"),
(10608,0,3,0,14,0,100,0,1200,40,16000,19000,11,8362,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Priest - Friendly At 1200 Health - Cast Renew"),
(10608,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Priest - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Executioner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1841;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1841 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1841,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Executioner - Between 0-30% Health - Cast Enrage"),
(1841,0,1,0,9,0,100,0,0,5,9000,14000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Executioner - Within 0-5 Range - Cast Mortal Strike"),
(1841,0,2,0,9,0,100,0,0,5,5000,9000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Executioner - Within 0-5 Range - Cast Cleave"),
(1841,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Executioner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Judge
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1837;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1837 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1837,0,0,0,9,0,100,0,0,5,7000,12000,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Judge - Within 0-5 Range - Cast Crusader Strike"),
(1837,0,1,0,0,0,100,0,6000,8000,9000,14000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Judge - In Combat - Cast Holy Strike"),
(1837,0,2,0,0,0,100,0,9000,14000,15000,18000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Judge - In Combat - Cast Hammer of Justice"),
(1837,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Judge - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Cavalier
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1836;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1836 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1836,0,0,0,9,0,100,0,0,5,5000,9000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Cavalier - Within 0-5 Range - Cast Cleave"),
(1836,0,1,0,9,0,100,0,0,5,9000,14000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Cavalier - Within 0-5 Range - Cast Mortal Strike"),
(1836,0,2,0,0,0,100,0,6000,11000,12000,15000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Cavalier - In Combat - Cast Backhand"),
(1836,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cavalier - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Interrogator
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1838;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1838 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1838,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Interrogator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Foreman Jerris
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1843;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1843 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1843,0,0,0,9,0,100,0,0,5,9000,14000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Jerris - Within 0-5 Range - Cast Snap Kick"),
(1843,0,1,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Jerris - In Combat - Cast Thrash"),
(1843,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Jerris - Between 0-15% Health - Flee For Assist (No Repeat)");

-- High Protector Lorik
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1846;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1846 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1846,0,0,0,13,0,100,1,1000,1000,0,0,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Protector Lorik - Target Casting - Cast Shield Slam (No Repeat)"),
(1846,0,1,0,9,0,100,0,0,5,7000,12000,11,10833,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Protector Lorik - Within 0-5 Range - Cast Arcane Blast"),
(1846,0,2,0,11,0,100,0,0,0,0,0,11,8990,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Protector Lorik - On Respawn - Cast Retribution Aura"),
(1846,0,3,0,0,0,100,0,16000,21000,18000,21000,11,13874,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Protector Lorik - In Combat - Cast Divine Shield"),
(1846,0,4,0,14,0,100,1,1300,40,0,0,11,15493,1,0,0,0,0,7,0,0,0,0,0,0,0,"High Protector Lorik - On Friendly Between 0-40% Health - Cast Holy Light"),
(1846,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Protector Lorik - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Highlord Taelan Fordring
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1842;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1842 AND `id`>9 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1842,0,10,0,4,0,100,1,0,0,0,0,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Taelan Fordring - On Aggro - Cast Devotion Aura"),
(1842,0,11,0,9,0,100,0,0,5,7000,12000,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highlord Taelan Fordring - Within 0-5 Range - Cast Crusader Strike"),
(1842,0,12,0,0,0,100,0,6000,8000,9000,14000,11,17143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highlord Taelan Fordring - In Combat - Cast Holy Strike"),
(1842,0,13,0,0,0,100,0,11000,15000,11000,13000,11,18819,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highlord Taelan Fordring - In Combat - Cast Holy Cleave"),
(1842,0,14,0,14,0,100,0,1800,40,10000,13000,11,15493,0,0,0,0,0,7,0,0,0,0,0,0,0,"Highlord Taelan Fordring - On Friendly At 1800 Health - Cast Holy Light"),
(1842,0,15,0,2,0,100,1,0,15,0,0,11,17233,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Taelan Fordring - Between 0-15% Health - Cast Lay on Hands");

-- Foreman Marcrid
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1844;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1844 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1844,0,0,0,9,0,100,0,0,5,5000,8000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Marcrid - Within 0-5 Range - Cast Strike"),
(1844,0,1,0,9,0,100,0,0,5,9000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Marcrid - Within 0-5 Range - Cast Cleave"),
(1844,0,2,0,2,0,100,1,0,20,0,0,39,40,1,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Marcrid - Between 0-20% Health - Call For Help (No Repeat)"),
(1844,0,3,0,0,0,100,0,4000,10000,17000,20000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Foreman Marcrid - Cast Shadow Shock');

-- High Protector Tarsen
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1845;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1845 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1845,0,0,0,13,0,100,1,1000,1000,0,0,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Protector Tarsen - Target Casting - Cast Shield Slam (No Repeat)"),
(1845,0,1,0,9,0,100,0,0,5,12000,16000,11,10833,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Protector Tarsen - Within 0-5 Range - Cast Arcane Blast"),
(1845,0,2,0,9,0,100,0,0,5,8000,11000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Protector Tarsen - Within 0-5 Range - Cast Holy Strike"),
(1845,0,3,0,0,0,100,0,1000,3000,240000,240000,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Protector Tarsen - In Combat - Cast Devotion Aura"),
(1845,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Protector Tarsen - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Cavalier Durgen
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11611;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11611 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11611,0,0,0,11,0,100,0,0,0,0,0,11,13008,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cavalier Durgen - On Respawn - Cast Retribution Aura"),
(11611,0,1,0,0,0,100,0,6000,8000,9000,14000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cavalier Durgen - In Combat - Cast Holy Strike"),
(11611,0,2,0,0,0,100,0,9000,14000,15000,18000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cavalier Durgen - In Combat - Cast Hammer of Justice"),
(11611,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cavalier Durgen - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Huntsman Radley
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11613;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11613 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11613,0,0,0,1,0,100,1,1000,1000,0,0,11,18262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntsman Radley - On Respawn - Cast Call Bloodshot"),
(11613,0,1,0,9,0,100,0,5,30,9000,12000,11,14443,0,0,0,0,0,5,0,0,0,0,0,0,0,"Huntsman Radley - Within 5-30 Range - Cast Multi-Shot"),
(11613,0,2,0,9,0,100,0,0,5,5000,8000,11,11976,1,0,0,0,0,2,0,0,0,0,0,0,0,"Huntsman Radley - Within 0-5 Range - Cast Strike"),
(11613,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntsman Radley - Between 0-15% Health - Flee For Assist (No Repeat)"),
(11613,0,4,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Huntsman Radley - In Combat CMC - Cast Shoot");

-- Bloodshot
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11614;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11614 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11614,0,0,0,9,0,100,0,0,5,15000,18000,11,13692,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodshot - Within 0-5 Range - Cast Dire Growl");
