-- 
-- DB/SAI: Update Isle of Queldanas
-- 1
-- Abyssal Flamewalker SAI
SET @ENTRY := 25001;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @ENTRY);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5500, 7800, 15600, 17800, 11, 45227, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Abyssal Flamewalker - In Combat - Cast "Abyssal Meteor Fall"'),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 2000, 4000, 8000, 12000, 11, 12744, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Abyssal Flamewalker - In Combat - Cast "Immolation"'),
(@ENTRY, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 45033, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Abyssal Flamewalker - On Reset - Cast "Abyssal Transformation"');

-- 2
-- Crypt Raider SAI
SET @ENTRY := 37541;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @ENTRY);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 31600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crypt Raider - On Aggro - Cast "Crypt Scarabs"');

-- 3
-- Darkspine Siren SAI
SET @ENTRY := 25073;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,170000,220000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Siren - In Combat - Cast 'Deafening Screech'"),
(@ENTRY,0,3,0,0,0,100,0,13000,18000,5000,25000,11,38033,64,0,0,0,0,0,0,0,0,0,0,0,0,"Darkspine Siren - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,4,0,2,0,100,1,15,0,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Darkspine Siren - Between 15-0% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Siren - In Combat - Cast 'Frostbolt'");

-- 4
-- Dawnblade Summoner SAI
SET @ENTRY := 24978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,8000,30000,120000,500000,11,44977,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Summoner - Out of Combat - Cast 'Fel Armor'"),
(@ENTRY,0,1,0,25,0,100,1,5000,10000,5000,10000,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Summoner - On Reset - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,8000,12000,11,32707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Summoner - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,3,0,0,0,100,0,15000,18000,25000,30000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Summoner - In Combat - Cast 'Immolate'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Summoner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 5
-- Dawnblade Marksman SAI
SET @ENTRY := 24979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,70,7000,13000,11,45101,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dawnblade Marksman - Within 0-70 Range Out of Combat LoS - Cast 'Flaming Arrow'"),
(@ENTRY,0,1,0,1,0,100,0,3000,3000,5000,5000,11,45101,0,0,0,0,0,19,25225,26,0,0,0,0,0,"Dawnblade Marksman - Out of Combat - Cast 'Flaming Arrow'"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Marksman - In Combat - Cast 'Shoot'");

-- 7
-- Ghoul Invader SAI
SET @ENTRY := 37539;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5700,12000,17500,11,38056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Invader - In Combat - Cast 'Flesh Rip'");

-- 8
-- Shattered Sun Sentry SAI
SET @ENTRY := 24994;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5500,12000,18000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Sun Sentry - In Combat - Cast 'Crystal Strike'");


-- 9
-- Wretched Fiend SAI
SET @ENTRY := 24966;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,60000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Fiend - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,0,0,100,0,15000,20000,15000,20000,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Fiend - In Combat - Cast 'Bitter Withdrawal'"),
(@ENTRY,0,2,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Fiend - On Aggro - Say Line 0"),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,42648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Fiend - On Respawn - Cast 'Sleeping Sleep'");
-- Wretched Fiend Texts
SET @ENTRY := 24966;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY,0,0,'The rift\'s power is ours!',12,10,100,0,0,0,24003,0,'Wretched Devourer'),
(@ENTRY,0,1,'Get away, this place is ours!',12,10,100,0,0,0,24004,0,'Wretched Devourer'),
(@ENTRY,0,2,'Mine! You shall not take this place!',12,10,100,0,0,0,24005,0,'Wretched Devourer'),
(@ENTRY,0,3,'It\'s not meant for you! Get away from here!',12,10,100,0,0,0,24006,0,'Wretched Devourer');

-- 10
-- Wretched Devourer
SET @ENTRY := 24960;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,10000,12000,11,33483,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Devourer - In Combat - Cast 'Mana Tap'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,15000,20000,11,35334,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Devourer - In Combat - Cast 'Nether Shock'"),
(@ENTRY,0,2,0,0,0,100,0,15000,17000,12000,13000,11,33390,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Devourer - In Combat - Cast 'Arcane Torrent'"),
(@ENTRY,0,3,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Devourer - On Aggro - Say Line 0");
-- Wretched Devourer Texts
SET @ENTRY := 24960;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
insert into `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) values
(@ENTRY,0,0,'The rift\'s power is ours!',12,10,100,0,0,0,24003,0,'Wretched Devourer'),
(@ENTRY,0,1,'Get away, this place is ours!',12,10,100,0,0,0,24004,0,'Wretched Devourer'),
(@ENTRY,0,2,'Mine! You shall not take this place!',12,10,100,0,0,0,24005,0,'Wretched Devourer'),
(@ENTRY,0,3,'It\'s not meant for you! Get away from here!',12,10,100,0,0,0,24006,0,'Wretched Devourer');
