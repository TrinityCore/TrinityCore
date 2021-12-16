-- Guardian of the ...
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2299200,2299300,2299400) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2299200,9,0,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Flag Immune to Players"),
(2299200,9,1,0,0,0,100,0,0,0,0,0,0,17,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Emote State 27"),
(2299200,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Say Line 0"),
(2299200,9,3,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Say Line 1"),
(2299200,9,4,0,0,0,100,0,4500,4500,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Remove Flag Immune to Players"),
(2299200,9,5,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Emote State 0"),
(2299200,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Start Attack Stored Target"),

(2299300,9,0,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Flag Immune to Players"),
(2299300,9,1,0,0,0,100,0,0,0,0,0,0,17,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Emote State 27"),
(2299300,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Say Line 0"),
(2299300,9,3,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Say Line 1"),
(2299300,9,4,0,0,0,100,0,4500,4500,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Remove Immune to Players"),
(2299300,9,5,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Emote State 0"),
(2299300,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Start Attack Stored Target"),

(2299400,9,0,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Flag Immune to Players"),
(2299400,9,1,0,0,0,100,0,0,0,0,0,0,17,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Emote State 27"),
(2299400,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Say Line 0"),
(2299400,9,3,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Say Line 1"),
(2299400,9,4,0,0,0,100,0,4500,4500,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Remove Flag Immune to Players"),
(2299400,9,5,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Emote State 0"),
(2299400,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Start Attack Stored Target");

-- Ravager Cage SAI
SET @ID := 181849;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,1,0,1,70,0,100,0,2,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ravager Cage - On Gameobject State Changed - Store Targetlist"),
(@ID,1,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,17556,5,0,0,0,0,0,0,"Ravager Cage - On Link - Send Target 1 (Death Ravager)"),
(@ID,1,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,17556,5,0,0,0,0,0,0,"Ravager Cage - On Link - Set Data 0 1 (Death Ravager)");

-- Death Ravager SAI
-- That flag is weird, it's not present always for unknown reason but creature respawns with it
SET @ID := 17556;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |256 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,38,0,100,0,0,1,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Death Ravager - On Data Set 0 1 - Remove Flag Immune to Players"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Death Ravager - On Link - Start Attack Stored Target"),
(@ID,0,2,0,0,0,100,0,5000,5000,15000,15000,0,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Death Ravager - In Combat - Cast 'Rend'"),
(@ID,0,3,0,0,0,100,0,0,0,3000,3000,0,11,30736,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Death Ravager - In Combat - Cast 'Enraging Bite'");

-- Creatures with not default respawn time should never be affected by dynamic respawn
UPDATE `creature` SET `spawntimesecs` = 15 WHERE `id` = 17556; -- Sniff
DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` = 84649;

-- Panther Cage SAI
SET @ID := 176195;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,1,0,1,70,0,100,0,2,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Panther Cage - On Gameobject State Changed - Store Targetlist"),
(@ID,1,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,10992,5,0,0,0,0,0,0,"Panther Cage - On Link - Send Target 1 (Enraged Panther)"),
(@ID,1,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,10992,5,0,0,0,0,0,0,"Panther Cage - On Link - Set Data 0 1 (Enraged Panther)");

-- Enraged Panther SAI
-- Same story with the flag because I didn't seen it in 2 sniffs but the flag is present in CreatureDifficulty
SET @ID := 10992;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |256 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,38,0,100,0,0,1,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Enraged Panther - On Data Set 0 1 - Remove Flag Immune to Players"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Enraged Panther - On Link - Start Attack Stored Target");

-- Talbuk Doe / Talbuk Sire (Sniffed)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` IN (20610,20777);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20610,20777) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2061000,2077700) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20610,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Aggro - Say Line 0"),
-- (20610,0,1,0,4,0,100,0,0,0,0,0,0,39,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Aggro - Call For Help"),
(20610,0,1,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,20777,0,0,0,0,0,0,0,"Talbuk Doe - On Aggro - Set Data 0 1 (Talbuk Sire)"),
(20610,0,2,0,0,0,100,0,5000,10000,10000,10000,0,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Talbuk Doe - In Combat - Cast 'Gore'"),
(20610,0,3,0,2,0,100,1,0,20,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - Between 0-20% Health - Say Line 1 (No Repeat)"),
(20610,0,4,0,8,0,100,1,35771,0,0,0,0,80,2061000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Spellhit 'Tag Subbued Talbuk' - Run Script (No Repeat)"),

(20777,0,0,0,0,0,100,0,5000,10000,15000,15000,0,11,32023,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Sire - In Combat - Cast 'Hoof Stomp'"),
(20777,0,1,0,2,0,100,1,0,20,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Sire - Between 0-20% Health - Say Line 0 (No Repeat)"),
(20777,0,2,0,8,0,100,1,35771,0,0,0,0,80,2061000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Sire - On Spellhit 'Tag Subbued Talbuk' - Run Script (No Repeat)"),
(20777,0,3,0,38,0,100,0,0,1,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,0,"Talbuk Sire - On Data Set 0 1 - Start Attack Closest Player"),

(2061000,9,0,0,0,0,100,0,0,0,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Disable Evade"),
(2061000,9,1,0,0,0,100,0,0,0,0,0,0,11,40347,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Cast 'Talbuk Tagging Credit'"),
(2061000,9,2,0,0,0,100,0,0,0,0,0,0,11,14915,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Cast 'Self Visual - Sleep Until Cancelled (DND)'"),
(2061000,9,3,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Set Flag Immune to Players"),
(2061000,9,4,0,0,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Set Flag Standstate Dead"),
(2061000,9,5,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Combat Stop"),
(2061000,9,6,0,0,0,100,0,60000,60000,0,0,0,28,14915,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Remove Aura 'Self Visual - Sleep Until Cancelled (DND)'"),
(2061000,9,7,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Remove Flag Immune to Players"),
(2061000,9,8,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Remove Flag Standstate Dead"),
(2061000,9,9,0,0,0,100,0,0,0,0,0,0,117,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Talbuk Doe - On Script - Enable Evade");
