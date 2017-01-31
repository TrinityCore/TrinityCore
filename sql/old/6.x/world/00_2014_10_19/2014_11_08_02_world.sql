UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN(37098,38418,38258);
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=38058;

-- Skybreaker Protector SAI
SET @ENTRY := 36998;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,8000,10000,11,69965,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Protector - In Combat - Cast 'Thunderclap'"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,21000,23000,11,69902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Protector - In Combat - Cast 'Devastate'"),
(@ENTRY,0,2,0,0,0,100,0,16000,16000,30000,30000,11,69903,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Protector - In Combat - Cast 'Shield Slam'"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,17000,26000,11,69901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Protector - In Combat - Cast 'Spell Reflect'"),
(@ENTRY,0,4,0,0,0,100,0,7000,7000,44000,45000,11,57807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Protector - In Combat - Cast 'Sunder Armor'");

-- Kor'kron Defender SAI
SET @ENTRY := 37032;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,8000,10000,11,69965,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Defender - In Combat - Cast 'Thunderclap'"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,21000,23000,11,69902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Defender - In Combat - Cast 'Devastate'"),
(@ENTRY,0,2,0,0,0,100,0,16000,16000,30000,30000,11,69903,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Defender - In Combat - Cast 'Shield Slam'"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,17000,26000,11,69901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Defender - In Combat - Cast 'Spell Reflect'"),
(@ENTRY,0,4,0,0,0,100,0,7000,7000,44000,45000,11,57807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Defender - In Combat - Cast 'Sunder Armor'");

-- Blighted Abomination SAI
SET @ENTRY := 37022;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,6000,6000,11,71140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blighted Abomination - In Combat - Cast 'Scourge Hook'"),
(@ENTRY,0,1,0,0,0,100,0,10000,11000,10000,11000,11,71150,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Abomination - In Combat - Cast 'Plague Cloud'"),
(@ENTRY,0,2,0,0,0,100,0,14000,15000,14000,15000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blighted Abomination - In Combat - Cast 'Cleave'");

-- Decaying Colossus SAI
SET @ENTRY := 36880;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,17000,15000,17000,11,71114,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decaying Colossus - In Combat - Cast 'Massive Stomp'");

-- Darkfallen Lieutenant SAI
SET @ENTRY := 37665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,8000,9000,11,70435,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkfallen Lieutenant - In Combat - Cast 'Rend Flesh'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,20000,20000,11,70423,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkfallen Lieutenant - In Combat - Cast 'Vampiric Curse'");

-- Darkfallen Commander SAI
SET @ENTRY := 37662;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,16000,11,70449,0,0,0,0,0,18,45,0,0,0,0,0,0,"Darkfallen Commander - In Combat - Cast 'Vampire Rush'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25000,25000,11,70750,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkfallen Commander - In Combat - Cast 'Battle Shout'");
