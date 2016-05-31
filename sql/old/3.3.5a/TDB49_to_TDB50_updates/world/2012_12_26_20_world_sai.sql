-- Kroshius SAI
SET @ENTRY := 14467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kroshius - On Respawn - Say Line 0"),
(@ENTRY,0,1,2,11,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kroshius - On Respawn - Remove unit_flag 768"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,2,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kroshius - On Respawn - Set Faction 16"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,9000,12000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kroshius - In Combat - Cast Knock Away");

-- Nightmare Aberration SAI
SET @ENTRY := 30617;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Aberration - On Respawn - Cast Shadowform");

-- Nightmare Figment SAI
SET @ENTRY := 30627;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Figment - On Respawn - Cast Shadowform");

-- Dragonflayer Vrykul SAI
SET @ENTRY := 23652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,43381,0,0,0,33,24281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Vrykul - On Spellhit Plague Spray - Quest Credit");

-- Arcanist Dulial SAI
SET @ENTRY := 35599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Dulial - On Respawn - Cast Frost Armor");

-- Slag SAI
SET @ENTRY := 28585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,10000,25000,30000,11,61509,36,0,0,0,0,2,0,0,0,0,0,0,0,"Slag - In Combat - Cast Melt Armor"),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,23113,7,0,0,0,0,1,0,0,0,0,0,0,0,"Slag - On Death - Cast Blast Wave"),
(@ENTRY,0,2,0,0,0,100,4,5000,10000,25000,30000,11,61510,36,0,0,0,0,2,0,0,0,0,0,0,0,"Slag - In Combat - Cast Melt Armor"),
(@ENTRY,0,3,0,6,0,100,5,0,0,0,0,11,22424,7,0,0,0,0,1,0,0,0,0,0,0,0,"Slag - On Death - Cast Blast Wave");

-- Bridenbrad Light Bunny SAI
SET @ENTRY := 30712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,"Bridenbrad Light Bunny - On Respawn - Morph Into 0"),
(@ENTRY,0,1,0,1,0,100,1,6000,6000,6000,6000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bridenbrad Light Bunny - Out Of Combat - Forced Despawn");

-- A'dal SAI
SET @ENTRY := 30691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,6000,6000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"A'dal - Out Of Combat - Forced Despawn");

-- M'ori SAI
SET @ENTRY := 30692;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,6000,6000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"M'ori - Out Of Combat - Forced Despawn");

-- K'uri SAI
SET @ENTRY := 30693;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,6000,6000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"K'uri - Out Of Combat - Forced Despawn");

-- Spirit of Bridenbrad SAI
SET @ENTRY := 30694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,3000,3000,3000,3000,11,57771,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Bridenbrad - Out Of Combat - Cast Holy Nova"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,90,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Bridenbrad - Out Of Combat - Stand Up"),
(@ENTRY,0,2,0,1,0,100,1,6000,6000,6000,6000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Bridenbrad - Out Of Combat - Forced Despawn");

-- Val'kyr Battle-maiden SAI
SET @ENTRY := 28487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Val'kyr Battle-maiden - On Respawn - Play Emote 402"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,4,3439,0,0,0,0,0,1,0,0,0,0,0,0,0,"Val'kyr Battle-maiden - On Respawn - Play Sound 3439");

-- Azuremyst Pink Elekk SAI
SET @ENTRY := 23528;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44654,0,0,0,33,23528,0,0,0,0,0,7,0,0,0,0,0,0,0,"Azuremyst Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azuremyst Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Forced Despawn");

-- Elwynn Pink Elekk SAI
SET @ENTRY := 23507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44654,0,0,0,33,23507,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elwynn Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elwynn Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Forced Despawn");

-- Teldrassil Pink Elekk SAI
SET @ENTRY := 23527;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44654,0,0,0,33,23527,0,0,0,0,0,7,0,0,0,0,0,0,0,"Teldrassil Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teldrassil Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Forced Despawn");

-- Mulgore Pink Elekk SAI
SET @ENTRY := 23529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44654,0,0,0,33,23529,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mulgore Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mulgore Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Forced Despawn");

-- Tirisfal Pink Elekk SAI
SET @ENTRY := 23530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44654,0,0,0,33,23530,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tirisfal Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Forced Despawn");

-- Eversong Pink Elekk SAI
SET @ENTRY := 23531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44654,0,0,0,33,23531,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eversong Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Pink Elekk - On Spellhit Elekk Dispersion Ray - Kill Credit - Forced Despawn");

-- Moonglade Portal SAI
SET @ENTRY := 32790;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,"Moonglade Portal - On Respawn - Morph Into 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,61722,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonglade Portal - On Respawn - Cast Nature Portal State");

-- Moonglade Return Portal SAI
SET @ENTRY := 32788;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,"Moonglade Return Portal - On Respawn - Morph Into 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,61722,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonglade Return Portal - On Respawn - Cast Nature Portal State");

-- Harold Lagras SAI
SET @ENTRY := 23730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,44250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harold Lagras - On Respawn - Cast Breathing Tube");

-- Kel'Thuzad SAI
SET @ENTRY := 25465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,3000,6000,27000,29000,11,50312,32,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Cast Unholy Frenzy"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,4,8818,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Play Sound 8818");

-- Necropolis Beam (Target) SAI
SET @ENTRY := 25466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,5000,5000,5000,5000,11,45615,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necropolis Beam (Target) - Out Of Combat - Cast Necropolis Beam");

-- Runeforge (SE) SAI
SET @ENTRY := 28481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,51769,0,0,0,11,51738,2,0,0,0,0,1,0,0,0,0,0,0,0,"Runeforge (SE) - On Spellhit Emblazon Runeblade - Cast Shadow Storm");

-- Oil-covered Hawk SAI
SET @ENTRY := 25748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,45948,2,0,0,0,0,1,0,0,0,0,0,0,0,"Oil-covered Hawk - On Respawn - Cast Oil Coat");

-- Oil-soaked Caribou SAI
SET @ENTRY := 25750;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,45948,2,0,0,0,0,1,0,0,0,0,0,0,0,"Oil-soaked Caribou - On Respawn - Cast Oil Coat");

-- Oiled Fledgeling SAI
SET @ENTRY := 25817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,45948,2,0,0,0,0,1,0,0,0,0,0,0,0,"Oiled Fledgeling - On Respawn - Cast Oil Coat");

-- Gordunni Proxy SAI
SET @ENTRY := 23450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,11757,0,0,0,50,144064,120,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Proxy - On Spellhit Digging for Cobalt - Summon Gameobject Gordunni Dirt Mound");

-- Ymirjar Warrior SAI
SET @ENTRY := 26690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,6,2000,25000,2000,25000,11,48639,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Warrior - In Combat - Cast Hamstring"),
(@ENTRY,0,1,0,0,0,70,6,3000,35000,3000,35000,11,48640,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Warrior - In Combat - Cast Strike");

-- Ymirjar Witch Doctor SAI
SET @ENTRY := 26691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,6,2500,30000,2500,30000,11,49084,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Witch Doctor - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,1,0,0,0,70,6,4000,45000,4000,45000,11,49089,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Witch Doctor - In Combat - Cast Shrink");

-- Ymirjar Harpooner SAI
SET @ENTRY := 26692;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,6,4000,45000,4000,45000,11,49092,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Harpooner - In Combat - Cast Net"),
(@ENTRY,0,1,0,0,0,70,6,2000,25000,2000,25000,11,49091,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Harpooner - In Combat - Cast Throw"),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,11,56789,7,0,0,0,0,7,0,0,0,0,0,0,0,"Ymirjar Harpooner - On Death - Cast Summon Harpoon");

-- Valgarde Harpoon Target SAI
SET @ENTRY := 23821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,61588,0,0,0,11,52955,2,0,0,0,0,1,0,0,0,0,0,0,0,"Valgarde Harpoon Target - On Spellhit Blazing Harpoon - Cast Torch");

-- Dragonflayer Raider SAI
SET @ENTRY := 23557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,42472,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Raider - On Respawn - Cast Throw Dragonflayer Fire Bomb");

-- Rageclaw Pup SAI
SET @ENTRY := 29848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,55474,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rageclaw Pup - On Respawn - Cast Cosmetic - Sleep Zzz");

-- Temple A SAI
SET @ENTRY := 25471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,25471,0,0,0,0,0,7,0,0,0,0,0,0,0,"Temple A - On LOS Out Of Combat - Quest Credit");

-- Temple B SAI
SET @ENTRY := 25472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,25472,0,0,0,0,0,7,0,0,0,0,0,0,0,"Temple B - On LOS Out Of Combat - Quest Credit");

-- Temple C SAI
SET @ENTRY := 25473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,25473,0,0,0,0,0,7,0,0,0,0,0,0,0,"Temple C - On LOS Out Of Combat - Quest Credit");

-- Lord-Commander Arete SAI
SET @ENTRY := 29344;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,57764,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lord-Commander Arete - On Respawn - Cast Hover (Anim Override)");

-- Magister Surdiel SAI
SET @ENTRY := 32170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Surdiel - On Respawn - Cast Frost Armor");

-- Onyxian Lair Guard SAI
SET @ENTRY := 36561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,6,15000,15000,30000,30000,11,68958,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onyxian Lair Guard - In Combat - Cast Blast Nova"),
(@ENTRY,0,1,0,0,0,90,6,5000,5000,20000,20000,11,68960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onyxian Lair Guard - In Combat - Cast Ignite Weapon"),
(@ENTRY,0,2,0,0,0,80,6,7000,7000,9000,11000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onyxian Lair Guard - In Combat - Cast Cleave");

-- [Chapter II] Torch Toss Dummy SAI
SET @ENTRY := 29038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,52955,0,0,0,0,0,1,0,0,0,0,0,0,0,"[Chapter II] Torch Toss Dummy - On Respawn - Cast Torch");

-- Bone Gryphon SAI
SET @ENTRY := 29648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,57764,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bone Gryphon - On Respawn - Cast Hover (Anim Override)");

-- Stabled Kurenai Lion SAI
SET @ENTRY := 19027;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16093,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stabled Kurenai Lion - On Respawn - Cast Self Visual - Sleep Until Cancelled (DND)");

-- Stabled Kurenai Panther SAI
SET @ENTRY := 19030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16093,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stabled Kurenai Panther - On Respawn - Cast Self Visual - Sleep Until Cancelled (DND)");

-- Eidolon Watcher SAI
SET @ENTRY := 30947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58540,2,0,0,0,0,1,0,0,0,0,0,0,0,"Eidolon Watcher - On Respawn - Cast Eidolon Prison");

-- Multiphase Disturbance SAI
SET @ENTRY := 25882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,46804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Multiphase Disturbance - On Respawn - Cast Dark Fire Shield State"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,46272,0,0,0,0,0,1,0,0,0,0,0,0,0,"Multiphase Disturbance - On Respawn - Cast Oshu'gun Cloud Invisibility");

-- Ataika SAI
SET @ENTRY := 26169;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ataika - On Respawn - Cast Blue Radiation");

-- Withered Argent Footman SAI
SET @ENTRY := 28158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,54450,2,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Argent Footman - On Respawn - Cast Withered Touch"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,45857,2,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Argent Footman - On Respawn - Cast Orange Radiation");

-- Nethermine Ravager SAI
SET @ENTRY := 23326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32732,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethermine Ravager - On Respawn - Cast Flay");

-- Evidence Marker SAI
SET @ENTRY := 23583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,42175,0,0,0,0,0,1,0,0,0,0,0,0,0,"Evidence Marker - On Respawn - Cast Evidence Marker Invis");

-- Drunken Brewfest Reveler SAI
SET @ENTRY := 23698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,43905,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Brewfest Reveler - On Respawn - Cast Completely Hammered");

-- Kvaldir Mistweaver SAI
SET @ENTRY := 25479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,45658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mistweaver - On Respawn - Cast Call of the Mist");

-- Skadir Mistweaver SAI
SET @ENTRY := 25613;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,45658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skadir Mistweaver - On Respawn - Cast Call of the Mist");

-- Talonpriest Ishaal SAI
SET @ENTRY := 23066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37411,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talonpriest Ishaal - On Respawn - Cast Skettis Corrupted Ghosts");

-- Talonpriest Skizzik SAI
SET @ENTRY := 23067;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37411,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talonpriest Skizzik - On Respawn - Cast Skettis Corrupted Ghosts");

-- Talonpriest Zellek SAI
SET @ENTRY := 23068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37411,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talonpriest Zellek - On Respawn - Cast Skettis Corrupted Ghosts");

-- Troll Roof Stalker SAI
SET @ENTRY := 23090;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,32199,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troll Roof Stalker - On Respawn - Cast Stealth"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Troll Roof Stalker - On Respawn - Cast Invisibility and Stealth Detection");

-- Fel Portal Alarm SAI
SET @ENTRY := 23310;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,46907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - On Respawn - Cast Boss Fel Portal State");

-- Magic Sucker Device Buttress SAI
SET @ENTRY := 22267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,38721,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magic Sucker Device Buttress - On Respawn - Cast Magic Sucker Device Channel(dnd)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,38672,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magic Sucker Device Buttress - On Respawn - Cast Magic Sucker Device timer");

-- Witness of Doom SAI
SET @ENTRY := 22282;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witness of Doom - On Respawn - Cast Stealth Detection");

-- Darkflame Infernal SAI
SET @ENTRY := 22289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,39102,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkflame Infernal - On Respawn - Cast Glowy (Black)");

-- Nether Gas Visual Trigger SAI
SET @ENTRY := 22358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,38966,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Gas Visual Trigger - On Respawn - Cast Nether Gas Drain");

-- Bloodmaul Soothsayer SAI
SET @ENTRY := 22384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - On Respawn - Cast Demon Armor");

-- Kil'Jaeden Reaver (non-interactable) SAI
SET @ENTRY := 22389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'Jaeden Reaver (non-interactable) - On Respawn - Cast Freeze Anim");

-- Remnant of Malice SAI
SET @ENTRY := 22437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36535,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remnant of Malice - On Respawn - Cast Greater Invis (For Fragments of Memory)");

-- Remnant of Greed SAI
SET @ENTRY := 22438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36535,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remnant of Greed - On Respawn - Cast Greater Invis (For Fragments of Memory)");

-- Remnant of Corruption SAI
SET @ENTRY := 22439;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36535,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remnant of Corruption - On Respawn - Cast Greater Invis (For Fragments of Memory)");

-- Remnant of Pride SAI
SET @ENTRY := 22440;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36535,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remnant of Pride - On Respawn - Cast Greater Invis (For Fragments of Memory)");

-- Remnant of Hate SAI
SET @ENTRY := 22094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36535,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remnant of Hate - On Respawn - Cast Greater Invis (For Fragments of Memory)");

-- Shadowmoon Eye of Kilrogg SAI
SET @ENTRY := 22134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Eye of Kilrogg - On Respawn - Cast Invisibility and Stealth Detection");

-- Harbinger Saronen SAI
SET @ENTRY := 22214;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Saronen - On Respawn - Cast Power Word: Fortitude");

-- Felstorm Overseer SAI
SET @ENTRY := 22221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,39102,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felstorm Overseer - On Respawn - Cast Glowy (Black)");

-- Hellfire Wardling SAI
SET @ENTRY := 22259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,38683,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Wardling - On Respawn - Cast Magic Sucker Device Despawner, Mob");

-- Illidari Watcher SAI
SET @ENTRY := 22093;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37119,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Watcher - On Respawn - Cast Spirit Particles (Spawn)");

-- Thunderlord Clan Sub-Chief SAI
SET @ENTRY := 21951;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,22650,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderlord Clan Sub-Chief - On Respawn - Cast Ghost Visual");

-- Rema SAI
SET @ENTRY := 21956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37691,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rema - On Respawn - Cast Stealth Detection");

-- Asghar SAI
SET @ENTRY := 22025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Asghar - On Respawn - Cast Shroud of Death");

-- Fenissa the Assassin SAI
SET @ENTRY := 22060;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenissa the Assassin - On Respawn - Cast Stealth");

-- Chief Rageclaw SAI
SET @ENTRY := 29690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,600000,600000,600000,600000,11,12550,2,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Rageclaw - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,2,11,0,100,0,0,0,0,0,11,12550,2,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Rageclaw - On Respawn - Cast Lightning Shield"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Rageclaw - On Respawn - Increment Phase");

-- Gnome Cannon Shooter #Shattrath SAI
SET @ENTRY := 21935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnome Cannon Shooter #Shattrath - On Respawn - Cast Self Root Forever");

-- Accursed Apparition SAI
SET @ENTRY := 21941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Accursed Apparition - On Respawn - Cast Stealth Detection");

-- Gnome Cannon Shooter #Singing Ridge SAI
SET @ENTRY := 21942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnome Cannon Shooter #Singing Ridge - On Respawn - Cast Self Root Forever");

-- Gnome Cannon Shooter #Ruuan SAI
SET @ENTRY := 21944;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnome Cannon Shooter #Ruuan - On Respawn - Cast Self Root Forever");

-- Garm Wolfbrother SAI
SET @ENTRY := 21950;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,22650,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garm Wolfbrother - On Respawn - Cast Ghost Visual");

-- Nether Drake Egg Bunny SAI
SET @ENTRY := 21814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Drake Egg Bunny - On Respawn - Cast Spirit Particles");

-- Cleric of Karabor SAI
SET @ENTRY := 21815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37497,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cleric of Karabor - On Respawn - Cast Shadowmoon Ghost Invisibility");

-- Teron Gorefiend SAI
SET @ENTRY := 21867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teron Gorefiend - On Respawn - Cast Ghostly Facade");

-- Unliving Guardian SAI
SET @ENTRY := 21869;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Guardian - On Respawn - Cast Spirit Particles");

-- Unliving Initiate SAI
SET @ENTRY := 21870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Initiate - On Respawn - Cast Spirit Particles");

-- Chain of Shadows SAI
SET @ENTRY := 21876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37761,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chain of Shadows - On Respawn - Cast Ancient Draenei Warden");

-- Time-Lost Skettis Worshipper SAI
SET @ENTRY := 21763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37411,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Skettis Worshipper - On Respawn - Cast Skettis Corrupted Ghosts");

-- Ghostrider of Karabor SAI
SET @ENTRY := 21784;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37497,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostrider of Karabor - On Respawn - Cast Shadowmoon Ghost Invisibility");

-- Time-Lost Skettis High Priest SAI
SET @ENTRY := 21787;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37411,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Skettis High Priest - On Respawn - Cast Skettis Corrupted Ghosts");

-- Shadowmoon Zealot SAI
SET @ENTRY := 21788;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37467,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Zealot - On Respawn - Cast Shadowmoon Ghost Invisibility");

-- Vhel'kur SAI
SET @ENTRY := 21801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,37509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vhel'kur - On Respawn - Cast Ghostly Facade"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,37497,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vhel'kur - On Respawn - Cast Shadowmoon Ghost Invisibility");

-- Skethyl Owl SAI
SET @ENTRY := 21450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36978,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skethyl Owl - On Respawn - Cast Shroud of Death");

-- Ashtongue Shaman SAI
SET @ENTRY := 21453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Shaman - On Respawn - Cast Lightning Shield");

-- Time-Lost Skettis Reaver SAI
SET @ENTRY := 21651;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37411,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Skettis Reaver - On Respawn - Cast Skettis Corrupted Ghosts");

-- Oronu the Elder SAI
SET @ENTRY := 21663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oronu the Elder - On Respawn - Cast Lightning Shield");

-- Mini-Electromental Flavor SAI
SET @ENTRY := 21737;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini-Electromental Flavor - On Respawn - Cast Power Converters: Electromental Visual");

-- Destroyed Sentinel SAI
SET @ENTRY := 21761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,36716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Destroyed Sentinel - On Respawn - Cast Energy Discharge");

-- Deathforged Infernal SAI
SET @ENTRY := 21316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - On Respawn - Cast Freeze Anim");

-- Illidari Shadowstalker SAI
SET @ENTRY := 21337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,5916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Shadowstalker - On Respawn - Cast Shadowstalker Stealth");

-- T'chali the Witch Doctor SAI
SET @ENTRY := 21349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36575,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chali the Witch Doctor - On Respawn - Cast T'chali the Head Freeze State");

-- Legion Hold Fel Reaver SAI
SET @ENTRY := 21404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Hold Fel Reaver - On Respawn - Cast Freeze Anim");

-- Negaton Field SAI
SET @ENTRY := 21414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36728,0,0,0,0,0,1,0,0,0,0,0,0,0,"Negaton Field - On Respawn - Cast Negaton Field");

-- Eressea Dawnsinger SAI
SET @ENTRY := 33379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,63403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eressea Dawnsinger - On Respawn - Cast Silvermoon Champion's Pennant");

-- Elder Shaman Moky SAI
SET @ENTRY := 29733;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,12550,2,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Shaman Moky - On Respawn - Cast Lightning Shield"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Shaman Moky - On Respawn - Increment Phase");

-- Enraged Earthen Soul SAI
SET @ENTRY := 21073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Earthen Soul - On Respawn - Cast Cosmetic: Earthen Soul");

-- Dormant Infernal SAI
SET @ENTRY := 21080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36055,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dormant Infernal - On Respawn - Cast Stationary Infernal Ball");

-- Containment Beam SAI
SET @ENTRY := 21159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,36220,0,0,0,0,0,1,0,0,0,0,0,0,0,"Containment Beam - On Respawn - Cast Containment Beam");

-- Skulking Witch SAI
SET @ENTRY := 20882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulking Witch - On Respawn - Cast Greater Invisibility");

-- Void Conduit SAI
SET @ENTRY := 20899;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35242,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Conduit - On Respawn - Cast Darkstalker Birth");

-- Severed Defender SAI
SET @ENTRY := 20934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Defender - On Respawn - Cast Shroud of Death");

-- Deathstalker Visceri SAI
SET @ENTRY := 33373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,63430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathstalker Visceri - On Respawn - Cast Undercity Champion's Pennant");

-- Disembodied Exarch SAI
SET @ENTRY := 21058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Disembodied Exarch - On Respawn - Cast Shroud of Death");

-- Bladespire Mystic SAI
SET @ENTRY := 20766;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bladespire Mystic - On Respawn - Cast Lightning Shield");

-- Salaadin's Energy Ball SAI
SET @ENTRY := 20769;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salaadin's Energy Ball - On Respawn - Cast Purple Banish State");

-- Razaani Light Orb - Mini SAI
SET @ENTRY := 20771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razaani Light Orb - Mini - On Respawn - Cast Purple Banish State");

-- Seeping Sludge Globule SAI
SET @ENTRY := 20806;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35242,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeping Sludge Globule - On Respawn - Cast Darkstalker Birth");

-- Ethereum Prisoner (Tyralius) SAI
SET @ENTRY := 20825;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Prisoner (Tyralius) - On Respawn - Cast Green Banish State");

-- Blade's Edge - Deadsoul Orb SAI
SET @ENTRY := 20845;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33345,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blade's Edge - Deadsoul Orb - On Respawn - Cast Yellow Banish State");

-- Razaani Light Orb SAI
SET @ENTRY := 20635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razaani Light Orb - On Respawn - Cast Purple Banish State");

-- Fiendling Flesh Beast SAI
SET @ENTRY := 20668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37816,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fiendling Flesh Beast - On Respawn - Cast Shadowform");

-- Swiftwing Shredder SAI
SET @ENTRY := 20673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swiftwing Shredder - On Respawn - Cast Lightning Shield");

-- Ethereum Sparring Dummy SAI
SET @ENTRY := 20676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35440,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Sparring Dummy - On Respawn - Cast Spar Dummy Vertex");

-- Thunderlord Dire Wolf SAI
SET @ENTRY := 20748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37691,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderlord Dire Wolf - On Respawn - Cast Stealth Detection");

-- Mokra the Skullcrusher SAI
SET @ENTRY := 33361;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,63433,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mokra the Skullcrusher - On Respawn - Cast Orgrimmar Champion's Pennant");

-- Subservient Flesh Beast SAI
SET @ENTRY := 20451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16592,0,0,0,0,0,1,0,0,0,0,0,0,0,"Subservient Flesh Beast - On Respawn - Cast Shadowform");

-- Naberius SAI
SET @ENTRY := 20483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,28126,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naberius - On Respawn - Cast Spirit Particles (purple)");

-- Skeletal Stallion SAI
SET @ENTRY := 20495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Stallion - On Respawn - Cast Shroud of Death");

-- Ethereum Prisoner SAI
SET @ENTRY := 20520;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Prisoner - On Respawn - Cast Purple Banish State");

-- Shrouded Figure SAI
SET @ENTRY := 20154;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24313,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shrouded Figure - On Respawn - Cast Shade");

-- Bloodmaul Battle Worg SAI
SET @ENTRY := 20330;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Battle Worg - On Respawn - Cast Stealth Detection");

-- Kirin'Var Apprentice SAI
SET @ENTRY := 20409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kirin'Var Apprentice - On Respawn - Cast Shroud of Death");

-- Rhonsus SAI
SET @ENTRY := 20410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhonsus - On Respawn - Cast Shroud of Death");

-- Spectral Bovine SAI
SET @ENTRY := 20411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Bovine - On Respawn - Cast Shroud of Death");

-- Runok Wildmane SAI
SET @ENTRY := 33403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,63436,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runok Wildmane - On Respawn - Cast Thunder Bluff Champion's Pennant");

-- Bloodmaul Dire Wolf SAI
SET @ENTRY := 20058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Dire Wolf - On Respawn - Cast Invisibility and Stealth Detection");

-- Netherstorm Triangulation Point One Trigger SAI
SET @ENTRY := 20086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherstorm Triangulation Point One Trigger - On Respawn - Cast Triangulation Point One Invisibility");

-- Netherstorm Triangulation Point Two Trigger SAI
SET @ENTRY := 20114;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34858,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherstorm Triangulation Point Two Trigger - On Respawn - Cast Triangulation Point Two Invisibility");

-- Socrethar SAI
SET @ENTRY := 20132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37539,0,0,0,0,0,1,0,0,0,0,0,0,0,"Socrethar - On Respawn - Cast Nether Protection");

-- Caledis Brightdawn SAI
SET @ENTRY := 19840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34612,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caledis Brightdawn - On Respawn - Cast Caledis's Disguise");

-- Commander Hogarth SAI
SET @ENTRY := 19937;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Hogarth - On Respawn - Cast Shroud of Death");

-- Lashh'an Windwalker SAI
SET @ENTRY := 19945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lashh'an Windwalker - On Respawn - Cast Lightning Shield");

-- Ruuan'ok Cloudgazer SAI
SET @ENTRY := 19985;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ruuan'ok Cloudgazer - On Respawn - Cast Lightning Shield");

-- Bloodmaul Shaman SAI
SET @ENTRY := 19992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Shaman - On Respawn - Cast Lightning Shield");

-- Peon Bolgar SAI
SET @ENTRY := 19562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Peon Bolgar - On Respawn - Cast Invisibility and Stealth Detection");

-- Grek's Riding Wolf SAI
SET @ENTRY := 19607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37691,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grek's Riding Wolf - On Respawn - Cast Stealth Detection");

-- Ricole Nichie SAI
SET @ENTRY := 19719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ricole Nichie - On Respawn - Cast Ancestor Invisibility");

-- Zul'tore SAI
SET @ENTRY := 33372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,63399,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'tore - On Respawn - Cast Sen'jin Champion's Pennant");

-- Mixie Farshot SAI
SET @ENTRY := 19836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mixie Farshot - On Respawn - Cast Invisibility and Stealth Detection");

-- Empoor SAI
SET @ENTRY := 18482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Respawn - Cast Lightning Shield");

-- Fallen Druid SAI
SET @ENTRY := 18490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32407,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Druid - On Respawn - Cast Strange Aura");

-- Justin's Bunny Target SAI
SET @ENTRY := 18560;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32573,0,0,0,0,0,1,0,0,0,0,0,0,0,"Justin's Bunny Target - On Respawn - Cast Justin's Zappy Channel");

-- Horde Field Scout SAI
SET @ENTRY := 18564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32610,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Field Scout - On Respawn - Cast Horde Flag Visual Only");

-- Alliance Field Scout SAI
SET @ENTRY := 18581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32609,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Field Scout - On Respawn - Cast Alliance Flag Visual Only");

-- Gerk SAI
SET @ENTRY := 29455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,29455,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gerk - On LOS Out Of Combat - Quest Credit");

-- Zangarmarsh PvP Beam (Blue) SAI
SET @ENTRY := 18759;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zangarmarsh PvP Beam (Blue) - On Respawn - Cast Beam (Blue)");

-- Faenel the Drunkard SAI
SET @ENTRY := 18781;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32951,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faenel the Drunkard - On Respawn - Cast Sleeping Sleep");

-- Stonebreaker Peon SAI
SET @ENTRY := 19048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonebreaker Peon - On Respawn - Cast Invisibility and Stealth Detection");

-- Void Portal SAI
SET @ENTRY := 19224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,33569,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Portal - On Respawn - Cast Void Portal Visual");

-- Shadowmoon Peon SAI
SET @ENTRY := 19355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Peon - On Respawn - Cast Invisibility and Stealth Detection");

-- Orgrimmar Peon SAI
SET @ENTRY := 19425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Peon - On Respawn - Cast Invisibility and Stealth Detection");

-- Peon Overseer SAI
SET @ENTRY := 19426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Peon Overseer - On Respawn - Cast Invisibility and Stealth Detection");

-- Injured Grunt SAI
SET @ENTRY := 19432;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Grunt - On Respawn - Cast Invisibility and Stealth Detection");

-- Stage Spotlight SAI
SET @ENTRY := 19525;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stage Spotlight - On Respawn - Cast Spotlight");

-- Sporeggar Preserver SAI
SET @ENTRY := 18139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sporeggar Preserver - On Respawn - Cast Sporeskin");

-- Sporeggar Harvester SAI
SET @ENTRY := 18140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sporeggar Harvester - On Respawn - Cast Sporeskin");

-- Baby Murloc SAI
SET @ENTRY := 18152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baby Murloc - On Respawn - Cast Baby Murloc Passive");

-- Burr SAI
SET @ENTRY := 29454;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,29454,0,0,0,0,0,7,0,0,0,0,0,0,0,"Burr - On LOS Out Of Combat - Quest Credit");

-- Gankly Rottenfist SAI
SET @ENTRY := 18297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32199,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Respawn - Cast Stealth");

-- Theatre Spotlight SAI
SET @ENTRY := 18342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theatre Spotlight - On Respawn - Cast Spotlight");

-- Sporeggar Spawn SAI
SET @ENTRY := 18358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sporeggar Spawn - On Respawn - Cast Sporeskin");

-- Mycah SAI
SET @ENTRY := 18382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mycah - On Respawn - Cast Sporeskin");

-- Warden Treelos SAI
SET @ENTRY := 18424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Respawn - Cast Blue Radiation");

-- Drakkari Corpse SAI
SET @ENTRY := 28162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,39996,0,0,0,11,50737,16,0,0,0,0,7,0,0,0,0,0,0,0,"Drakkari Corpse - On Spellhit 40yd Dummy - Cast Create Drakkari Medallion"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Corpse - On Spellhit 40yd Dummy - Increment Phase"),
(@ENTRY,0,2,0,1,0,100,1,3000,3000,3000,3000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Corpse - Out Of Combat - Forced Despawn");

-- Snowfall Glade Pup SAI
SET @ENTRY := 26200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,39996,0,0,0,11,65208,16,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Pup - On Spellhit 40yd Dummy - Cast Self Stun"),
(@ENTRY,0,1,2,8,0,100,0,0,0,0,0,11,46773,16,0,0,0,0,7,0,0,0,0,0,0,0,"Snowfall Glade Pup - On Spellhit 40yd Dummy - Cast Planning for the Future: Create Snowfall Glade Pup"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Pup - On Spellhit 40yd Dummy - Forced Despawn");

-- Bombard the Ballistae Kill Credit Bunny SAI
SET @ENTRY := 27331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,48345,0,0,0,33,27331,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bombard the Ballistae Kill Credit Bunny - On Spellhit Siegesmith Bombs - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bombard the Ballistae Kill Credit Bunny - On Spellhit Siegesmith Bombs - Forced Despawn");

-- Iron Rune-Shaper SAI
SET @ENTRY := 26270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,47005,0,0,0,33,26264,0,0,0,0,0,7,0,0,0,0,0,0,0,"Iron Rune-Shaper - On Spellhit Throw Boulder - Quest Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune-Shaper - On Spellhit Throw Boulder - Forced Despawn");

-- Winterskorn Tribesman SAI
SET @ENTRY := 23661;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Woodsman SAI
SET @ENTRY := 23662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Shield-Maiden SAI
SET @ENTRY := 23663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Warrior SAI
SET @ENTRY := 23664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Warrior - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Raider SAI
SET @ENTRY := 23665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Raider - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Berserker SAI
SET @ENTRY := 23666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Berserker - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Rune-Seer SAI
SET @ENTRY := 23667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Rune-Caster SAI
SET @ENTRY := 23668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Oracle SAI
SET @ENTRY := 23669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,0,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,8,0,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Oracle - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Spellhit Dismembering Corpse - Set Phase 2");

-- Defeated Argent Footman SAI
SET @ENTRY := 28156;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,51276,0,0,0,11,59216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defeated Argent Footman - On Spellhit Incinerate Corpse - Cast Burning Corpse"),
(@ENTRY,0,1,2,8,0,100,0,0,0,0,0,33,28316,0,0,0,0,0,7,0,0,0,0,0,0,0,"Defeated Argent Footman - On Spellhit Incinerate Corpse - Quest Credit"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defeated Argent Footman - On Spellhit Incinerate Corpse - Increment Phase"),
(@ENTRY,0,3,0,1,0,100,1,10000,10000,10000,10000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defeated Argent Footman - Out Of Combat - Forced Despawn");

-- Oil-stained Wolf SAI
SET @ENTRY := 25791;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,45948,2,0,0,0,0,1,0,0,0,0,0,0,0,"Oil-stained Wolf - On Respawn - Cast Oil Coat");

-- Oil Pool SAI
SET @ENTRY := 25781;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,35357,2,0,0,0,0,1,0,0,0,0,0,0,0,"Oil Pool - On Respawn - Cast Spawn Feign Death"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,46011,2,0,0,0,0,1,0,0,0,0,0,0,0,"Oil Pool - On Respawn - Cast Oil Coat (small)");

-- Soldier of the Frozen Wastes SAI
SET @ENTRY := 16427;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,3,0,5,0,0,11,28458,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soldier of the Frozen Wastes - At 0 - 5 Range - Cast Dark Blast"),
(@ENTRY,0,1,0,9,0,100,5,0,5,0,0,11,55714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soldier of the Frozen Wastes - At 0 - 5 Range - Cast Dark Blast");

-- Soul Weaver SAI
SET @ENTRY := 16429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,8000,11,28459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soul Weaver - At 0 - 5 Range - Cast Wail of Souls"),
(@ENTRY,0,1,0,9,0,100,4,0,5,5000,8000,11,55765,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soul Weaver - At 0 - 5 Range - Cast Wail of Souls");

-- Tualiq Spirit SAI
SET @ENTRY := 34888;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,60000,60000,60000,60000,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tualiq Spirit - Out Of Combat - Increment Phase"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tualiq Spirit - Out Of Combat - Forced Despawn");

-- Elder Arp SAI
SET @ENTRY := 30364;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Arp - On Respawn - Cast Spotlight");

-- Elder Sardis SAI
SET @ENTRY := 30348;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Sardis - On Respawn - Cast Spotlight");

-- Elder Pamuya SAI
SET @ENTRY := 30371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Pamuya - On Respawn - Cast Spotlight");

-- Elder Northal SAI
SET @ENTRY := 30360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Northal - On Respawn - Cast Spotlight");

-- Elder Morthie SAI
SET @ENTRY := 30358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Morthie - On Respawn - Cast Spotlight");

-- Elder Skywarden SAI
SET @ENTRY := 30373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Skywarden - On Respawn - Cast Spotlight");

-- Elder Thoim SAI
SET @ENTRY := 30363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Thoim - On Respawn - Cast Spotlight");

-- Elder Lunaro SAI
SET @ENTRY := 30367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Lunaro - On Respawn - Cast Spotlight");

-- Elder Beldak SAI
SET @ENTRY := 30357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Beldak - On Respawn - Cast Spotlight");

-- Elder Tauros SAI
SET @ENTRY := 30369;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Tauros - On Respawn - Cast Spotlight");

-- Elder Muraco SAI
SET @ENTRY := 30374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Muraco - On Respawn - Cast Spotlight");

-- Elder Graymane SAI
SET @ENTRY := 30370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Graymane - On Respawn - Cast Spotlight");

-- Elder Fargal SAI
SET @ENTRY := 30359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Fargal - On Respawn - Cast Spotlight");

-- Elder Stonebeard SAI
SET @ENTRY := 30375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stonebeard - On Respawn - Cast Spotlight");

-- Elder Whurain SAI
SET @ENTRY := 30372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Whurain - On Respawn - Cast Spotlight");

-- Elder Sandrene SAI
SET @ENTRY := 30362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Sandrene - On Respawn - Cast Spotlight");

-- Elder Wanikaya SAI
SET @ENTRY := 30365;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Wanikaya - On Respawn - Cast Spotlight");

-- Elder Bluewolf SAI
SET @ENTRY := 30368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Bluewolf - On Respawn - Cast Spotlight");

-- Elder Ohanzee SAI
SET @ENTRY := 30537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Ohanzee - On Respawn - Cast Spotlight");

-- Elder Kilias SAI
SET @ENTRY := 30534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Kilias - On Respawn - Cast Spotlight");

-- Elder Nurgen SAI
SET @ENTRY := 30533;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Nurgen - On Respawn - Cast Spotlight");

-- Elder Yurauk SAI
SET @ENTRY := 30535;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Yurauk - On Respawn - Cast Spotlight");

-- Elder Jarten SAI
SET @ENTRY := 30531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Jarten - On Respawn - Cast Spotlight");

-- Elder Chogan'gada SAI
SET @ENTRY := 30538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Chogan'gada - On Respawn - Cast Spotlight");

-- Elder Igasho SAI
SET @ENTRY := 30536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Igasho - On Respawn - Cast Spotlight");

-- Elder Farwhisper SAI
SET @ENTRY := 15607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Farwhisper - On Respawn - Cast Spotlight");

-- Elder Morndeep SAI
SET @ENTRY := 15549;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Morndeep - On Respawn - Cast Spotlight");

-- Elder Splitrock SAI
SET @ENTRY := 15556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Splitrock - On Respawn - Cast Spotlight");

-- Elder Rumblerock SAI
SET @ENTRY := 15557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Rumblerock - On Respawn - Cast Spotlight");

-- Elder Silvervein SAI
SET @ENTRY := 15558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Silvervein - On Respawn - Cast Spotlight");

-- Elder Highpeak SAI
SET @ENTRY := 15559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Highpeak - On Respawn - Cast Spotlight");

-- Elder Stonefort SAI
SET @ENTRY := 15560;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stonefort - On Respawn - Cast Spotlight");

-- Elder Obsidian SAI
SET @ENTRY := 15561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Obsidian - On Respawn - Cast Spotlight");

-- Elder Hammershout SAI
SET @ENTRY := 15562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Hammershout - On Respawn - Cast Spotlight");

-- Elder Darkcore SAI
SET @ENTRY := 15564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Darkcore - On Respawn - Cast Spotlight");

-- Elder Stormbrow SAI
SET @ENTRY := 15565;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stormbrow - On Respawn - Cast Spotlight");

-- Elder Snowcrown SAI
SET @ENTRY := 15566;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Snowcrown - On Respawn - Cast Spotlight");

-- Elder Ironband SAI
SET @ENTRY := 15567;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Ironband - On Respawn - Cast Spotlight");

-- Elder Graveborn SAI
SET @ENTRY := 15568;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Graveborn - On Respawn - Cast Spotlight");

-- Elder Goldwell SAI
SET @ENTRY := 15569;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Goldwell - On Respawn - Cast Spotlight");

-- Elder Primestone SAI
SET @ENTRY := 15570;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Primestone - On Respawn - Cast Spotlight");

-- Elder Runetotem SAI
SET @ENTRY := 15572;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Runetotem - On Respawn - Cast Spotlight");

-- Elder Ragetotem SAI
SET @ENTRY := 15573;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Ragetotem - On Respawn - Cast Spotlight");

-- Elder Stonespire SAI
SET @ENTRY := 15574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Stonespire - On Respawn - Cast Spotlight");

-- Elder Bloodhoof SAI
SET @ENTRY := 15575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Bloodhoof - On Respawn - Cast Spotlight");

-- Elder Winterhoof SAI
SET @ENTRY := 15576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Winterhoof - On Respawn - Cast Spotlight");

-- Elder Skychaser SAI
SET @ENTRY := 15577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Skychaser - On Respawn - Cast Spotlight");

-- Elder Wildmane SAI
SET @ENTRY := 15578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Wildmane - On Respawn - Cast Spotlight");

-- Elder Darkhorn SAI
SET @ENTRY := 15579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Darkhorn - On Respawn - Cast Spotlight");

-- Elder Ezra Wheathoof SAI
SET @ENTRY := 15580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Ezra Wheathoof - On Respawn - Cast Spotlight");

-- Elder Grimtotem SAI
SET @ENTRY := 15581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Grimtotem - On Respawn - Cast Spotlight");

-- Elder Windtotem SAI
SET @ENTRY := 15582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Windtotem - On Respawn - Cast Spotlight");

-- Elder Thunderhorn SAI
SET @ENTRY := 15583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Thunderhorn - On Respawn - Cast Spotlight");

-- Elder Skyseer SAI
SET @ENTRY := 15584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Skyseer - On Respawn - Cast Spotlight");

-- Elder Dawnstrider SAI
SET @ENTRY := 15585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Dawnstrider - On Respawn - Cast Spotlight");

-- Elder Dreamseer SAI
SET @ENTRY := 15586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Dreamseer - On Respawn - Cast Spotlight");

-- Elder Mistwalker SAI
SET @ENTRY := 15587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Mistwalker - On Respawn - Cast Spotlight");

-- Elder High Mountain SAI
SET @ENTRY := 15588;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder High Mountain - On Respawn - Cast Spotlight");

-- Elder Windrun SAI
SET @ENTRY := 15592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Windrun - On Respawn - Cast Spotlight");

-- Elder Starsong SAI
SET @ENTRY := 15593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Starsong - On Respawn - Cast Spotlight");

-- Elder Moonstrike SAI
SET @ENTRY := 15594;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Moonstrike - On Respawn - Cast Spotlight");

-- Elder Starglade SAI
SET @ENTRY := 15596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Starglade - On Respawn - Cast Spotlight");

-- Elder Moonwarden SAI
SET @ENTRY := 15597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Moonwarden - On Respawn - Cast Spotlight");

-- Elder Bladeswift SAI
SET @ENTRY := 15598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Bladeswift - On Respawn - Cast Spotlight");

-- Elder Skygleam SAI
SET @ENTRY := 15600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Skygleam - On Respawn - Cast Spotlight");

-- Elder Starweave SAI
SET @ENTRY := 15601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Starweave - On Respawn - Cast Spotlight");

-- Elder Meadowrun SAI
SET @ENTRY := 15602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Meadowrun - On Respawn - Cast Spotlight");

-- Elder Nightwind SAI
SET @ENTRY := 15603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Nightwind - On Respawn - Cast Spotlight");

-- Elder Morningdew SAI
SET @ENTRY := 15604;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Morningdew - On Respawn - Cast Spotlight");

-- Elder Riversong SAI
SET @ENTRY := 15605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Riversong - On Respawn - Cast Spotlight");

-- Elder Brightspear SAI
SET @ENTRY := 15606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Brightspear - On Respawn - Cast Spotlight");

-- Elder Bronzebeard SAI
SET @ENTRY := 15871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Bronzebeard - On Respawn - Cast Spotlight");

-- Coldridge Mountaineer SAI
SET @ENTRY := 853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Mountaineer - On Respawn - Cast Invisibility and Stealth Detection");

-- Northshire Guard SAI
SET @ENTRY := 1642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northshire Guard - On Respawn - Cast Invisibility and Stealth Detection");

-- Jaguero Stalker SAI
SET @ENTRY := 2522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaguero Stalker - On Respawn - Cast Stealth"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaguero Stalker - On Respawn - Cast Thrash");

-- Silithid Swarm SAI
SET @ENTRY := 4196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6590,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Swarm - On Respawn - Cast Silithid Swarm Passive");

-- Overlord Ramtusk SAI
SET @ENTRY := 4420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - On Respawn - Cast Battle Stance");

-- Razorfen Quilguard SAI
SET @ENTRY := 4436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Quilguard - On Respawn - Cast Battle Stance");

-- Redrock Earth Spirit SAI
SET @ENTRY := 5890;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,8203,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redrock Earth Spirit - On Respawn - Cast Elemental Spirit Invisibility");

-- Minor Manifestation of Earth SAI
SET @ENTRY := 5891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,8203,0,0,0,0,0,1,0,0,0,0,0,0,0,"Minor Manifestation of Earth - On Respawn - Cast Elemental Spirit Invisibility");

-- Onin MacHammar SAI
SET @ENTRY := 6886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onin MacHammar - On Respawn - Cast Faded");

-- Franclorn Forgewright SAI
SET @ENTRY := 8888;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,10848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Franclorn Forgewright - On Respawn - Cast Shroud of Death");

-- Gaeriyan SAI
SET @ENTRY := 9299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,10848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaeriyan - On Respawn - Cast Shroud of Death");

-- Caer Darrow Citizen SAI
SET @ENTRY := 11277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17622,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caer Darrow Citizen - On Respawn - Cast Caer Darrow Ghosts");

-- Magnus Frostwake SAI
SET @ENTRY := 11278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17622,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnus Frostwake - On Respawn - Cast Caer Darrow Ghosts");

-- Caer Darrow Guardsman SAI
SET @ENTRY := 11279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17622,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caer Darrow Guardsman - On Respawn - Cast Caer Darrow Ghosts");

-- Caer Darrow Cannoneer SAI
SET @ENTRY := 11280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17622,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caer Darrow Cannoneer - On Respawn - Cast Caer Darrow Ghosts");

-- Caer Darrow Horseman SAI
SET @ENTRY := 11281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17622,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caer Darrow Horseman - On Respawn - Cast Caer Darrow Ghosts");

-- Magistrate Marduke SAI
SET @ENTRY := 11286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17622,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Marduke - On Respawn - Cast Caer Darrow Ghosts");

-- Shadowglen Sentinel SAI
SET @ENTRY := 12160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowglen Sentinel - On Respawn - Cast Invisibility and Stealth Detection");

-- Deeprot Tangler SAI
SET @ENTRY := 13142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,21337,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeprot Tangler - On Respawn - Cast Thorns");

-- Thief Catcher Shadowdelve SAI
SET @ENTRY := 14363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thief Catcher Shadowdelve - On Respawn - Cast Invisibility and Stealth Detection");

-- Thief Catcher Farmountain SAI
SET @ENTRY := 14365;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thief Catcher Farmountain - On Respawn - Cast Invisibility and Stealth Detection");

-- Thief Catcher Thunderbrew SAI
SET @ENTRY := 14367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thief Catcher Thunderbrew - On Respawn - Cast Invisibility and Stealth Detection");

-- Scout Stronghand SAI
SET @ENTRY := 14375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scout Stronghand - On Respawn - Cast Invisibility and Stealth Detection");

-- Scout Manslayer SAI
SET @ENTRY := 14376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scout Manslayer - On Respawn - Cast Invisibility and Stealth Detection");

-- Scout Tharr SAI
SET @ENTRY := 14377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scout Tharr - On Respawn - Cast Invisibility and Stealth Detection");

-- Huntress Skymane SAI
SET @ENTRY := 14378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntress Skymane - On Respawn - Cast Invisibility and Stealth Detection");

-- Seeker Cromwell SAI
SET @ENTRY := 14402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeker Cromwell - On Respawn - Cast Invisibility and Stealth Detection");

-- Seeker Nahr SAI
SET @ENTRY := 14403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeker Nahr - On Respawn - Cast Invisibility and Stealth Detection");

-- Seeker Thompson SAI
SET @ENTRY := 14404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeker Thompson - On Respawn - Cast Invisibility and Stealth Detection");

-- Officer Jaxon SAI
SET @ENTRY := 14423;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Officer Jaxon - On Respawn - Cast Invisibility and Stealth Detection");

-- Officer Pomeroy SAI
SET @ENTRY := 14438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Officer Pomeroy - On Respawn - Cast Invisibility and Stealth Detection");

-- Officer Brady SAI
SET @ENTRY := 14439;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,41634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Officer Brady - On Respawn - Cast Invisibility and Stealth Detection");

-- Kerri Hicks SAI
SET @ENTRY := 14832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kerri Hicks - On Respawn - Cast Demonic Knowledge");

-- Xandivious SAI
SET @ENTRY := 15623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,25818,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xandivious - On Respawn - Cast Aura of Rot");

-- Spotlight SAI
SET @ENTRY := 15631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,25824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spotlight - On Respawn - Cast Spotlight");

-- Mutated Root Lasher SAI
SET @ENTRY := 16517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,29152,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mutated Root Lasher - On Respawn - Cast Bloodmyst Radiation");

-- Mutated Owlkin SAI
SET @ENTRY := 16537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,29152,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mutated Owlkin - On Respawn - Cast Bloodmyst Radiation");

-- Thrallmar Grunt SAI
SET @ENTRY := 16580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Respawn - Cast Invisibility and Stealth Detection");

-- Thrallmar Peon SAI
SET @ENTRY := 16591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Peon - On Respawn - Cast Invisibility and Stealth Detection");

-- Thrallmar Wolf Rider SAI
SET @ENTRY := 16599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Wolf Rider - On Respawn - Cast Invisibility and Stealth Detection");

-- Red Radiation Trigger SAI
SET @ENTRY := 16922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,29152,0,0,0,0,0,1,0,0,0,0,0,0,0,"Red Radiation Trigger - On Respawn - Cast Bloodmyst Radiation");

-- Forge Camp Legionnaire SAI
SET @ENTRY := 16954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32737,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forge Camp Legionnaire - On Respawn - Cast Weapon Chain");

-- Tunneler SAI
SET @ENTRY := 16968;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunneler - On Respawn - Cast Tunnel Bore Passive");

-- Ironforge Firebreather SAI
SET @ENTRY := 17048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,29402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironforge Firebreather - On Respawn - Cast Holiday - Breath of Fire Aura (NPC)");

-- Darnassus Firebreather SAI
SET @ENTRY := 17049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,29402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassus Firebreather - On Respawn - Cast Holiday - Breath of Fire Aura (NPC)");

-- Living Cyclone SAI
SET @ENTRY := 17160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Living Cyclone - On Respawn - Cast Lightning Shield");

-- Crusader Dargath SAI
SET @ENTRY := 29468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,29468,0,0,0,0,0,7,0,0,0,0,0,0,0,"Crusader Dargath - On LOS Out Of Combat - Quest Credit");

-- Stone Guard Stok'ton SAI
SET @ENTRY := 17493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stone Guard Stok'ton - On Respawn - Cast Invisibility and Stealth Detection");

-- Caza'rez SAI
SET @ENTRY := 17558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caza'rez - On Respawn - Cast Invisibility and Stealth Detection");

-- Prince Toreth SAI
SET @ENTRY := 17674;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Toreth - On Respawn - Cast Shroud of Death");

-- Captain Edward Hanes SAI
SET @ENTRY := 17712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Edward Hanes - On Respawn - Cast Shroud of Death");

-- Gzhun'tt SAI
SET @ENTRY := 17856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gzhun'tt - On Respawn - Cast Sporeskin");

-- T'shu SAI
SET @ENTRY := 17857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'shu - On Respawn - Cast Sporeskin");

-- Khn'nix SAI
SET @ENTRY := 17866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khn'nix - On Respawn - Cast Sporeskin");

-- Fahssn SAI
SET @ENTRY := 17923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fahssn - On Respawn - Cast Sporeskin");

-- Msshi'fn SAI
SET @ENTRY := 17924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Msshi'fn - On Respawn - Cast Sporeskin");

-- Gshaff SAI
SET @ENTRY := 17925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gshaff - On Respawn - Cast Sporeskin");

-- Red Crystal Bunny SAI
SET @ENTRY := 17947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,31515,0,0,0,0,0,1,0,0,0,0,0,0,0,"Red Crystal Bunny - On Respawn - Cast Red Beam");

-- Imp Minion SAI
SET @ENTRY := 12922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,2300,2800,11,20801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Imp Minion - In Combat - Cast Firebolt");

-- Bergrisst SAI
SET @ENTRY := 23619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,28000,28000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,1,2,1,0,100,0,28000,28000,0,0,11,37718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Cast Clear Target Auras"),
(@ENTRY,0,2,0,1,0,100,1,36500,36500,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 402"),
(@ENTRY,0,3,0,1,0,100,1,42505,42505,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 403"),
(@ENTRY,0,4,0,1,0,100,1,80500,80500,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 404"),
(@ENTRY,0,5,0,1,0,100,1,94000,94000,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 405"),
(@ENTRY,0,6,0,1,0,100,1,113500,113500,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 402"),
(@ENTRY,0,7,0,1,0,100,1,137100,137100,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 403"),
(@ENTRY,0,8,0,1,0,100,1,149000,149000,0,0,11,34126,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Cast Spotlight"),
(@ENTRY,0,9,0,1,0,100,1,158300,158300,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 404"),
(@ENTRY,0,10,0,1,0,100,1,172700,172700,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 405"),
(@ENTRY,0,11,0,1,0,100,1,197500,197500,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 402"),
(@ENTRY,0,12,0,1,0,100,1,213000,213000,0,0,11,41347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Cast Spotlight"),
(@ENTRY,0,13,0,1,0,100,1,220500,220500,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 403"),
(@ENTRY,0,14,0,1,0,100,1,240500,240500,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 404"),
(@ENTRY,0,15,0,1,0,100,1,256500,256500,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 405"),
(@ENTRY,0,16,0,1,0,100,1,275500,275500,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Play Emote 402"),
(@ENTRY,0,17,0,1,0,100,1,280000,280000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,18,0,1,0,100,1,280800,280800,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bergrisst - Out Of Combat - Cast Greater Invisibility");

-- Chief Thunder-Skins SAI
SET @ENTRY := 23623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,24000,24000,0,0,11,37718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Cast Clear Target Auras"),
(@ENTRY,0,1,2,1,0,100,0,24000,24000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,2,0,1,0,100,1,34200,34200,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 402"),
(@ENTRY,0,3,0,1,0,100,1,48700,48700,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 403"),
(@ENTRY,0,4,0,1,0,100,1,61000,61000,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 404"),
(@ENTRY,0,5,0,1,0,100,1,73000,73000,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 405"),
(@ENTRY,0,6,0,1,0,100,1,95700,95700,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 402"),
(@ENTRY,0,7,0,1,0,100,1,120100,120100,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 404"),
(@ENTRY,0,8,0,1,0,100,1,132000,132000,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 405"),
(@ENTRY,0,9,0,1,0,100,1,152500,152500,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 402"),
(@ENTRY,0,10,0,1,0,100,1,165600,165600,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 403"),
(@ENTRY,0,11,0,1,0,100,1,178900,178900,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 404"),
(@ENTRY,0,12,0,1,0,100,1,190300,190300,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 405"),
(@ENTRY,0,13,0,1,0,100,1,209800,209800,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 402"),
(@ENTRY,0,14,0,1,0,100,1,223600,223600,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 403"),
(@ENTRY,0,15,0,1,0,100,1,237000,237000,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 404"),
(@ENTRY,0,16,0,1,0,100,1,251300,251300,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 405"),
(@ENTRY,0,17,0,1,0,100,1,271400,271400,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Play Emote 402"),
(@ENTRY,0,18,0,1,0,100,1,280000,280000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,19,0,1,0,100,1,280800,280800,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Thunder-Skins - Out Of Combat - Cast Greater Invisibility");

-- Mai'Kyl SAI
SET @ENTRY := 23624;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,13000,13000,0,0,11,37718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Cast Clear Target Auras"),
(@ENTRY,0,1,2,1,0,100,0,13000,13000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,2,0,1,0,100,1,24700,24700,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 402"),
(@ENTRY,0,3,0,1,0,100,1,38600,38600,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 403"),
(@ENTRY,0,4,0,1,0,100,1,52700,52700,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 404"),
(@ENTRY,0,5,0,1,0,100,1,73700,73700,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 402"),
(@ENTRY,0,6,0,1,0,100,1,90000,90000,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 403"),
(@ENTRY,0,7,0,1,0,100,1,105200,105200,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 404"),
(@ENTRY,0,8,0,1,0,100,1,108000,108000,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 402"),
(@ENTRY,0,9,0,1,0,100,1,146400,146400,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 403"),
(@ENTRY,0,10,0,1,0,100,1,160000,160000,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 404"),
(@ENTRY,0,11,0,1,0,100,1,182000,182000,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 402"),
(@ENTRY,0,12,0,1,0,100,1,199400,199400,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 403"),
(@ENTRY,0,13,0,1,0,100,1,215200,215200,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 404"),
(@ENTRY,0,14,0,1,0,100,1,234700,234700,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 402"),
(@ENTRY,0,15,0,1,0,100,1,251200,251200,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 403"),
(@ENTRY,0,16,0,1,0,100,1,265400,265400,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Play Emote 404"),
(@ENTRY,0,17,0,1,0,100,1,280000,280000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,18,0,1,0,100,1,280800,280800,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mai'Kyl - Out Of Combat - Cast Greater Invisibility");

-- Samuro SAI
SET @ENTRY := 23625;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,10000,10000,0,0,11,37718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Cast Clear Target Auras"),
(@ENTRY,0,1,2,1,0,100,0,10000,10000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,2,0,1,0,100,1,29400,29400,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 403"),
(@ENTRY,0,3,0,1,0,100,1,49500,49500,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 404"),
(@ENTRY,0,4,0,1,0,100,1,72000,72000,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 405"),
(@ENTRY,0,5,0,1,0,100,1,86400,86400,0,0,5,406,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 406"),
(@ENTRY,0,6,0,1,0,100,1,95200,95200,0,0,5,407,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 407"),
(@ENTRY,0,7,0,1,0,100,1,117400,117400,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 402"),
(@ENTRY,0,8,0,1,0,100,1,124500,124500,0,0,11,42510,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Cast L70ETC Call Lightning"),
(@ENTRY,0,9,0,1,0,100,1,128400,128400,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 403"),
(@ENTRY,0,10,0,1,0,100,1,148000,148000,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 404"),
(@ENTRY,0,11,0,1,0,100,1,171800,171800,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 405"),
(@ENTRY,0,12,0,1,0,100,1,184500,184500,0,0,5,406,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 406"),
(@ENTRY,0,13,0,1,0,100,1,196100,196100,0,0,5,407,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 407"),
(@ENTRY,0,14,0,1,0,100,1,227500,227500,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 403"),
(@ENTRY,0,15,0,1,0,100,1,246300,246300,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 404"),
(@ENTRY,0,16,0,1,0,100,1,272800,272800,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Play Emote 405"),
(@ENTRY,0,17,0,1,0,100,1,280000,280000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,18,0,1,0,100,1,280800,280800,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Samuro - Out Of Combat - Cast Greater Invisibility");

-- Sig Nicious SAI
SET @ENTRY := 23626;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,13000,13000,0,0,11,37718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Cast Clear Target Auras"),
(@ENTRY,0,1,2,1,0,100,0,13000,13000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,2,0,1,0,100,1,22700,22700,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 402"),
(@ENTRY,0,3,0,1,0,100,1,38600,38600,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 403"),
(@ENTRY,0,4,0,1,0,100,1,49700,49700,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 404"),
(@ENTRY,0,5,0,1,0,100,1,63600,63600,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 405"),
(@ENTRY,0,6,0,1,0,100,1,89700,89700,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 402"),
(@ENTRY,0,7,0,1,0,100,1,102600,102600,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 403"),
(@ENTRY,0,8,0,1,0,100,1,114900,114900,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 404"),
(@ENTRY,0,9,0,1,0,100,1,129500,129500,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 405"),
(@ENTRY,0,10,0,1,0,100,1,155800,155800,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 402"),
(@ENTRY,0,11,0,1,0,100,1,170800,170800,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 403"),
(@ENTRY,0,12,0,1,0,100,1,182300,182300,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 404"),
(@ENTRY,0,13,0,1,0,100,1,196100,196100,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 405"),
(@ENTRY,0,14,0,1,0,100,1,223500,223500,0,0,5,402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 402"),
(@ENTRY,0,15,0,1,0,100,1,239200,239200,0,0,5,403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 403"),
(@ENTRY,0,16,0,1,0,100,1,251000,251000,0,0,5,404,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 404"),
(@ENTRY,0,17,0,1,0,100,1,264600,264600,0,0,5,405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Play Emote 405"),
(@ENTRY,0,18,0,1,0,100,1,280000,280000,0,0,11,42505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Cast L70ETC Flare Effect"),
(@ENTRY,0,19,0,1,0,100,1,280800,280800,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sig Nicious - Out Of Combat - Cast Greater Invisibility");

-- [DNT] L70ETC FX Controller SAI
SET @ENTRY := 23830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,9400,9400,0,0,4,11803,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Play Sound 11803"),
(@ENTRY,0,1,0,1,0,100,1,10000,10000,0,0,11,42500,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Lightning Cloud"),
(@ENTRY,0,2,0,1,0,100,1,13600,13600,0,0,11,42499,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Earthquake"),
(@ENTRY,0,3,0,1,0,100,1,18000,18000,0,0,11,42501,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Rain of Fire"),
(@ENTRY,0,4,0,1,0,100,1,79100,79100,0,0,11,42500,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Lightning Cloud"),
(@ENTRY,0,5,0,1,0,100,1,83500,83500,0,0,11,42499,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Earthquake"),
(@ENTRY,0,6,0,1,0,100,1,87900,87900,0,0,11,42501,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Rain of Fire"),
(@ENTRY,0,7,0,1,0,100,1,133200,133200,0,0,11,42500,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Lightning Cloud"),
(@ENTRY,0,8,0,1,0,100,1,137600,137600,0,0,11,42499,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Earthquake"),
(@ENTRY,0,9,0,1,0,100,1,142300,142300,0,0,11,42501,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Rain of Fire"),
(@ENTRY,0,10,0,1,0,100,1,238500,238500,0,0,11,42500,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Lightning Cloud"),
(@ENTRY,0,11,0,1,0,100,1,242900,242900,0,0,11,42499,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Earthquake"),
(@ENTRY,0,12,0,1,0,100,1,247300,247300,0,0,11,42501,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Rain of Fire"),
(@ENTRY,0,13,0,1,0,100,1,251700,251700,0,0,11,42500,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Lightning Cloud"),
(@ENTRY,0,14,0,1,0,100,1,256100,256100,0,0,11,42499,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Earthquake"),
(@ENTRY,0,15,0,1,0,100,1,260500,260500,0,0,11,42501,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DNT] L70ETC FX Controller - Out Of Combat - Cast L70ETC Rain of Fire");

-- Earthgrab Totem SAI
SET @ENTRY := 6066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,4800,5200,11,8377,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthgrab Totem - Out Of Combat - Cast Earthgrab");

-- Corrupt Earth Totem SAI
SET @ENTRY := 21704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,37203,7,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupt Earth Totem - On Death - Cast Summon Corrupted Earth Elemental");

-- Spitfire Totem SAI
SET @ENTRY := 22091;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,12000,11,38296,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitfire Totem - In Combat - Cast Attack");

-- Cyclone (Karathress) SAI
SET @ENTRY := 22104;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,14000,11,29538,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclone (Karathress) - In Combat - Cast Cyclone");

-- Greater Earthbind Totem SAI
SET @ENTRY := 22486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,6000,7000,9000,11,3600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Earthbind Totem - In Combat - Cast Earthbind");

-- Summoned Searing Totem SAI
SET @ENTRY := 22895;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,2000,4000,11,39592,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Searing Totem - In Combat - Cast Attack");

-- Corrupted Lightning Totem SAI
SET @ENTRY := 24224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4000,2000,4000,11,43301,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Lightning Totem - In Combat - Cast Lightning");

-- Charged Sentry Totem SAI
SET @ENTRY := 28938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,2000,4000,11,52705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charged Sentry Totem - In Combat - Cast Sentry Shock");

-- Archery Target SAI
SET @ENTRY := 5202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archery Target - On Respawn - Allow Combat Movement");

-- Guse's War Rider SAI
SET @ENTRY := 14943;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,6000,9000,11,15285,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guse's War Rider - In Combat - Cast Fireball Volley"),
(@ENTRY,0,1,2,0,0,100,0,8000,11000,12000,17000,11,21188,1,0,0,0,0,5,0,0,0,0,0,0,0,"Guse's War Rider - In Combat - Cast Stun Bomb Attack"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,23969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guse's War Rider - In Combat - Cast Throw Liquid Fire");

-- Slidore's Gryphon SAI
SET @ENTRY := 14946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,6000,9000,11,15285,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slidore's Gryphon - In Combat - Cast Fireball Volley"),
(@ENTRY,0,1,2,0,0,100,0,8000,11000,12000,17000,11,21188,1,0,0,0,0,5,0,0,0,0,0,0,0,"Slidore's Gryphon - In Combat - Cast Stun Bomb Attack"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,23969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slidore's Gryphon - In Combat - Cast Throw Liquid Fire");

-- Horde Grunt SAI
SET @ENTRY := 17932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2500,2500,10000,15000,11,31754,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Grunt - In Combat - Cast Strike");

-- Anvilrage Enforcer SAI
SET @ENTRY := 24819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,9000,12000,11,13608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Enforcer - In Combat - Cast Hooked Net"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,12000,15000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Enforcer - In Combat - Cast Shield Bash");

-- Frostwolf Bloodhound SAI
SET @ENTRY := 14282;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,7000,11000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Bloodhound - In Combat - Cast Thrash");

-- Stormpike Owl SAI
SET @ENTRY := 14283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,7000,11000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Owl - In Combat - Cast Thrash");

-- Stormpike Battleguard SAI
SET @ENTRY := 14284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Battleguard - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,10000,14000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Battleguard - In Combat - Cast Improved Blocking"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,20000,25000,11,16509,1,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Battleguard - In Combat - Cast Rend"),
(@ENTRY,0,3,0,0,0,100,2,3000,5000,5000,7000,11,22591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Battleguard - In Combat - Cast Strike");

-- Frostwolf Battleguard SAI
SET @ENTRY := 14285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Battleguard - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,10000,14000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Battleguard - In Combat - Cast Improved Blocking"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,20000,25000,11,16509,1,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Battleguard - In Combat - Cast Rend"),
(@ENTRY,0,3,0,0,0,100,2,3000,5000,5000,7000,11,22591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Battleguard - In Combat - Cast Strike");

-- Stormpike Ram Rider Commander SAI
SET @ENTRY := 13577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Ram Rider Commander - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Ram Rider Commander - In Combat - Cast Cleave");

-- Mountaineer Boombellow SAI
SET @ENTRY := 13797;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mountaineer Boombellow - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,7000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mountaineer Boombellow - In Combat - Cast Strike");

-- Jotek SAI
SET @ENTRY := 13798;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jotek - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jotek - In Combat - Cast Cleave");

-- Alterac Yeti SAI
SET @ENTRY := 13959;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1500,8000,11000,20000,11,22479,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alterac Yeti - In Combat - Cast Frost Breath"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,16000,20000,11,16727,1,0,0,0,0,1,0,0,0,0,0,0,0,"Alterac Yeti - In Combat - Cast War Stomp");

-- Champion Irondeep Guard SAI
SET @ENTRY := 13554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Guard - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Guard - In Combat - Cast Cleave");

-- Seasoned Irondeep Surveyor SAI
SET @ENTRY := 13555;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Surveyor - At 50% HP - Cast Heal");

-- Veteran Irondeep Surveyor SAI
SET @ENTRY := 13556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Surveyor - At 50% HP - Cast Heal");

-- Champion Irondeep Surveyor SAI
SET @ENTRY := 13557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Surveyor - At 50% HP - Cast Heal");

-- Veteran Coldmine Invader SAI
SET @ENTRY := 13550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Invader - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Invader - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Invader - In Combat - Cast Hamstring");

-- Champion Coldmine Invader SAI
SET @ENTRY := 13551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Invader - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Invader - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Invader - In Combat - Cast Hamstring");

-- Seasoned Irondeep Guard SAI
SET @ENTRY := 13552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Guard - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Guard - In Combat - Cast Cleave");

-- Veteran Irondeep Guard SAI
SET @ENTRY := 13553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Guard - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Guard - In Combat - Cast Cleave");

-- Seasoned Coldmine Invader SAI
SET @ENTRY := 13549;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Invader - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Invader - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Invader - In Combat - Cast Hamstring");

-- Seasoned Irondeep Raider SAI
SET @ENTRY := 13543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Raider - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Raider - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Raider - In Combat - Cast Hamstring");

-- Veteran Irondeep Raider SAI
SET @ENTRY := 13544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Raider - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Raider - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Raider - In Combat - Cast Hamstring");

-- Champion Irondeep Raider SAI
SET @ENTRY := 13545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Raider - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Raider - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Raider - In Combat - Cast Hamstring");

-- Champion Coldmine Guard SAI
SET @ENTRY := 13536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Guard - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,16000,21000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Guard - In Combat - Cast Backhand");

-- Seasoned Coldmine Surveyor SAI
SET @ENTRY := 13537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Surveyor - At 50% HP - Cast Heal");

-- Veteran Coldmine Surveyor SAI
SET @ENTRY := 13538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Surveyor - At 50% HP - Cast Heal");

-- Champion Coldmine Surveyor SAI
SET @ENTRY := 13539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Surveyor - At 50% HP - Cast Heal");

-- Wing Commander Slidore SAI
SET @ENTRY := 13438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Slidore - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Slidore - In Combat - Cast Rend");

-- Wing Commander Vipore SAI
SET @ENTRY := 13439;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Vipore - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Vipore - In Combat - Cast Rend");

-- Arch Druid Renferal SAI
SET @ENTRY := 13442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,5000,8000,11,22206,32,0,0,0,0,5,0,0,0,0,0,0,0,"Arch Druid Renferal - In Combat - Cast Moonfire"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,10000,13000,11,22127,1,0,0,0,0,5,0,0,0,0,0,0,0,"Arch Druid Renferal - In Combat - Cast Entangling Roots"),
(@ENTRY,0,2,0,2,0,100,2,0,50,12000,15000,11,15981,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Renferal - At 50% HP - Cast Rejuvenation");

-- Druid of the Grove SAI
SET @ENTRY := 13443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,600000,600000,11,22128,1,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Grove - Out Of Combat - Cast Thorns"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,13000,17000,11,21668,0,0,0,0,0,5,0,0,0,0,0,0,0,"Druid of the Grove - In Combat - Cast Starfire"),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,10000,13000,11,22127,1,0,0,0,0,5,0,0,0,0,0,0,0,"Druid of the Grove - In Combat - Cast Entangling Roots");

-- Corporal Noreg Stormpike SAI
SET @ENTRY := 13447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,6000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corporal Noreg Stormpike - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,7000,11000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Corporal Noreg Stormpike - In Combat - Cast Shield Block");

-- Sergeant Yazra Bloodsnarl SAI
SET @ENTRY := 13448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,13000,18000,34000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Yazra Bloodsnarl - In Combat - Cast Rend");

-- Seasoned Coldmine Guard SAI
SET @ENTRY := 13534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Guard - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,16000,21000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Guard - In Combat - Cast Backhand");

-- Veteran Coldmine Guard SAI
SET @ENTRY := 13535;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Guard - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,16000,21000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Guard - In Combat - Cast Backhand");

-- Irondeep Miner SAI
SET @ENTRY := 13396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,10000,6000,15000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Miner - In Combat - Cast Sunder Armor");

-- Irondeep Peon SAI
SET @ENTRY := 13397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,10000,6000,15000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Peon - In Combat - Cast Sunder Armor");

-- Wing Commander Ichman SAI
SET @ENTRY := 13437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wing Commander Ichman - Out Of Combat - Cast Greater Invisibility"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,28,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wing Commander Ichman - On Aggro - Remove Aura Greater Invisibility"),
(@ENTRY,0,2,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Ichman - In Combat - Cast Strike"),
(@ENTRY,0,3,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Ichman - In Combat - Cast Rend");

-- Seasoned Defender SAI
SET @ENTRY := 13326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,6000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Defender - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,7000,11000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Defender - In Combat - Cast Shield Block");

-- Seasoned Guardian SAI
SET @ENTRY := 13328;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,6000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Guardian - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,7000,11000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Guardian - In Combat - Cast Shield Block");

-- Veteran Defender SAI
SET @ENTRY := 13331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,6000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Defender - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,7000,11000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Defender - In Combat - Cast Shield Block");

-- Veteran Guardian SAI
SET @ENTRY := 13332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,6000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Guardian - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,7000,11000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Guardian - In Combat - Cast Shield Block");

-- Frostwolf Shaman SAI
SET @ENTRY := 13284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Shaman - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,5000,7000,11,21401,0,0,0,0,0,5,0,0,0,0,0,0,0,"Frostwolf Shaman - In Combat - Cast Frost Shock"),
(@ENTRY,0,2,0,2,0,100,2,0,50,15000,22000,11,12492,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Shaman - At 50% HP - Cast Healing Wave");

-- Coldmine Peon SAI
SET @ENTRY := 13316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,10000,6000,15000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Peon - In Combat - Cast Sunder Armor");

-- Coldmine Miner SAI
SET @ENTRY := 13317;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,10000,6000,15000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Miner - In Combat - Cast Sunder Armor");

-- Wing Commander Guse SAI
SET @ENTRY := 13179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4100,9300,10200,17900,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Guse - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,1700,10300,6000,15400,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Guse - In Combat - Cast Sunder Armor");

-- Wing Commander Jeztor SAI
SET @ENTRY := 13180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4100,9300,10200,17900,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Jeztor - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,1700,10300,6000,15400,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Jeztor - In Combat - Cast Sunder Armor");

-- Wing Commander Mulverick SAI
SET @ENTRY := 13181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4100,9300,10200,17900,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Mulverick - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,1700,10300,6000,15400,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wing Commander Mulverick - In Combat - Cast Sunder Armor");

-- Coldmine Surveyor SAI
SET @ENTRY := 13097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Surveyor - At 50% HP - Cast Heal");

-- Irondeep Surveyor SAI
SET @ENTRY := 13098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Surveyor - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,20000,24000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Surveyor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,2,0,100,3,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Surveyor - At 50% HP - Cast Heal");

-- Aggi Rumblestomp SAI
SET @ENTRY := 13086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,13000,16000,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aggi Rumblestomp - In Combat - Cast Shield Slam"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,12000,15000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Aggi Rumblestomp - In Combat - Cast Shield Block");

-- Coldmine Invader SAI
SET @ENTRY := 13087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Invader - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Invader - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Invader - In Combat - Cast Hamstring");

-- Masha Swiftcut SAI
SET @ENTRY := 13088;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,14000,22000,30000,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Masha Swiftcut - In Combat - Cast Sinister Strike"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,14000,21000,11,6434,1,0,0,0,0,1,0,0,0,0,0,0,0,"Masha Swiftcut - In Combat - Cast Slice and Dice"),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,7000,11000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Masha Swiftcut - In Combat - Cast Thrash");

-- Coldmine Guard SAI
SET @ENTRY := 13089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Guard - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,16000,21000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Guard - In Combat - Cast Backhand");

-- Stormpike Guardsman SAI
SET @ENTRY := 12127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Guardsman - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,7000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Guardsman - In Combat - Cast Strike");

-- Umi Thorson SAI
SET @ENTRY := 13078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umi Thorson - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,16000,21000,11,8147,1,0,0,0,0,1,0,0,0,0,0,0,0,"Umi Thorson - In Combat - Cast Thunderclap");

-- Keetar SAI
SET @ENTRY := 13079;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,10000,11000,24000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keetar - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,7000,9000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Keetar - In Combat - Cast Strike"),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,7000,9000,11,15496,1,0,0,0,0,2,0,0,0,0,0,0,0,"Keetar - In Combat - Cast Cleave");

-- Irondeep Guard SAI
SET @ENTRY := 13080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Guard - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Guard - In Combat - Cast Cleave");

-- Irondeep Raider SAI
SET @ENTRY := 13081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Raider - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,34000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Raider - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,14000,18000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Raider - In Combat - Cast Hamstring");

-- Stormpike Defender SAI
SET @ENTRY := 12050;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,8000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Defender - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,12000,15000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Defender - In Combat - Cast Shield Block");

-- Frostwolf Legionnaire SAI
SET @ENTRY := 12051;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,13000,18000,34000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Legionnaire - In Combat - Cast Rend");

-- Frostwolf Guardian SAI
SET @ENTRY := 12053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,8000,12000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Guardian - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,12000,15000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Guardian - In Combat - Cast Shield Block");

-- Captain Galvangar SAI
SET @ENTRY := 11947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,10000,11000,24000,11,13736,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Galvangar - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Galvangar - In Combat - Cast Mortal Strike"),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Galvangar - In Combat - Cast Cleave"),
(@ENTRY,0,3,0,2,0,70,2,0,30,25000,35000,11,19134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Galvangar - At 30% HP - Cast Frightening Shout");

-- Vanndar Stormpike SAI
SET @ENTRY := 11948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,19135,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vanndar Stormpike - On Aggro - Cast Avatar"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,16000,21000,11,15588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vanndar Stormpike - In Combat - Cast Thunderclap"),
(@ENTRY,0,2,0,2,0,100,2,0,30,15000,18000,11,19135,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vanndar Stormpike - At 30% HP - Cast Avatar");

-- Wildpaw Brute SAI
SET @ENTRY := 11839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Brute - In Combat - Cast Mortal Strike");

-- Snowblind Ambusher SAI
SET @ENTRY := 11678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4900,14400,22500,41700,11,19472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Ambusher - In Combat - Cast Sinister Strike"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,4000,6000,11,7159,1,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Ambusher - In Combat - Cast Backstab");

-- Wildpaw Shaman SAI
SET @ENTRY := 11837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,16000,19000,11,12557,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Shaman - In Combat - Cast Cone of Cold"),
(@ENTRY,0,1,0,2,0,100,2,0,50,60000,65000,11,18975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Shaman - At 50% HP - Cast Summon Ice Totem");

-- Whitewhisker Overseer SAI
SET @ENTRY := 11605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,13000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Overseer - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,13589,1,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Overseer - At 30% HP - Cast Haste Aura"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Whitewhisker Overseer - At 15% HP - Flee For Assist");

-- Irondeep Skullthumper SAI
SET @ENTRY := 11602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,5000,7000,11,16172,32,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Skullthumper - In Combat - Cast Head Crack"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,16000,20000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Skullthumper - In Combat - Cast Mighty Blow"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Irondeep Skullthumper - At 15% HP - Flee For Assist");

-- Whitewhisker Digger SAI
SET @ENTRY := 11603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4100,9300,10200,17900,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Digger - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,1700,10300,6000,15400,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Digger - In Combat - Cast Sunder Armor"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Whitewhisker Digger - At 15% HP - Flee For Assist");

-- Whitewhisker Vermin SAI
SET @ENTRY := 10982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,3000,6000,11,17230,32,0,0,0,0,5,0,0,0,0,0,0,0,"Whitewhisker Vermin - In Combat - Cast Infected Wound");

-- Snowblind Harpy SAI
SET @ENTRY := 10986;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,12000,15000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Harpy - In Combat - Cast Deafening Screech");

-- Irondeep Trogg SAI
SET @ENTRY := 10987;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,6000,8000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Trogg - In Combat - Cast Strike"),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Irondeep Trogg - At 15% HP - Flee For Assist");

-- Alterac Ram SAI
SET @ENTRY := 10990;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alterac Ram - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,8700,12700,18400,34200,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alterac Ram - In Combat - Cast Rend");

-- Wildpaw Gnoll SAI
SET @ENTRY := 10991;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4000,5000,7000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Gnoll - In Combat - Cast Thrash");

-- Frostwolf SAI
SET @ENTRY := 10981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8700,12700,18400,34200,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf - In Combat - Cast Rend");

-- Amani Crocolisk SAI
SET @ENTRY := 24047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,13000,13000,11,43352,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Crocolisk - In Combat - Cast Tail Swipe"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,24000,24000,11,43353,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Crocolisk - In Combat - Cast Infected Bite");

-- Amani Lynx Cub SAI
SET @ENTRY := 24064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,1000,1000,11,42943,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Lynx Cub - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,28,42943,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Lynx Cub - On Aggro - Remove Aura Stealth"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,43317,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Lynx Cub - On Aggro - Cast Dash"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,35000,35000,11,43358,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Lynx Cub - In Combat - Cast Gut Rip");

-- Amani'shi Handler SAI
SET @ENTRY := 24065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,23200,23200,11,43364,0,0,0,0,0,5,0,0,0,0,0,0,0,"Amani'shi Handler - In Combat - Cast Tranquilizing Poison"),
(@ENTRY,0,1,0,0,0,100,2,0,0,9000,9000,11,43362,0,0,0,0,0,5,0,0,0,0,0,0,0,"Amani'shi Handler - In Combat - Cast Electrified Net");

-- Amani'shi Wind Walker SAI
SET @ENTRY := 24179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,30,30000,30000,11,43527,1,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Wind Walker - At 30% HP - Cast Chain Heal"),
(@ENTRY,0,1,0,0,0,100,2,0,0,9000,9000,11,43524,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Wind Walker - In Combat - Cast Frost Shock"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,17500,17500,11,43526,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Wind Walker - In Combat - Cast Lightning Bolt");

-- Zul'Aman - Lynx God Invisman SAI
SET @ENTRY := 23815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,23815,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zul'Aman - Lynx God Invisman - On LOS Out Of Combat - Quest Credit");

-- Amani Dragonhawk SAI
SET @ENTRY := 23834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,9000,27500,27500,11,43294,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Dragonhawk - In Combat - Cast Flame Breath");

-- Amani'shi Savage SAI
SET @ENTRY := 23889;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,10000,10000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Savage - In Combat - Cast Hamstring"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,25000,30000,11,12054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Savage - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,6000,9000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Savage - In Combat - Cast Sunder Armor");

-- Amani Lynx SAI
SET @ENTRY := 24043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Lynx - On Respawn - Cast Invisibility and Stealth Detection");

-- Amani'shi Flame Caster SAI
SET @ENTRY := 23596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,30000,30000,11,43242,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Flame Caster - In Combat - Cast Haste"),
(@ENTRY,0,1,0,0,0,100,2,0,0,18000,18000,11,43240,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Flame Caster - In Combat - Cast Fireball Volley"),
(@ENTRY,0,2,0,0,0,100,2,0,0,9700,9700,11,43245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Flame Caster - In Combat - Cast Fire Blast");

-- Amani'shi Guardian SAI
SET @ENTRY := 23597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,1500,1500,11,43249,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Guardian - In Combat - Cast Startling Roar"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,12000,12000,11,43246,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Guardian - In Combat - Cast Rend");

-- Zul'Aman - Dragonhawk God Invisman SAI
SET @ENTRY := 23813;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,23813,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zul'Aman - Dragonhawk God Invisman - On LOS Out Of Combat - Quest Credit");

-- Zul'Aman - Eagle God Invisman SAI
SET @ENTRY := 23814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,2,1,20,2000,2000,33,23814,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zul'Aman - Eagle God Invisman - On LOS Out Of Combat - Quest Credit");

-- Amani'shi Reinforcement SAI
SET @ENTRY := 23587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,2000,2000,8000,8000,11,43298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Reinforcement - In Combat - Cast Strike"),
(@ENTRY,0,1,0,4,0,75,3,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Reinforcement - On Aggro - Cast Charge");

-- Amani'shi Warbringer SAI
SET @ENTRY := 23580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,19,0,0,11,43274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Warbringer - At 19% HP - Cast Dismount Bear"),
(@ENTRY,0,1,2,2,0,100,0,0,0,0,0,90,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Warbringer - At 19% HP - Set Bytes1 0"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,19,134217728,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Warbringer - At 19% HP - Remove unit_flag 134217728"),
(@ENTRY,0,3,0,0,0,100,2,0,0,12000,12000,11,43273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Warbringer - In Combat - Cast Cleave"),
(@ENTRY,0,4,0,0,0,100,2,5000,5000,20000,20000,11,42496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Warbringer - In Combat - Cast Furious Roar"),
(@ENTRY,0,5,0,2,0,100,3,0,30,0,0,11,40743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Warbringer - At 30% HP - Cast Frenzy");

-- Amani'shi Medicine Man SAI
SET @ENTRY := 23581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,30,30000,30000,11,42477,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Medicine Man - At 30% HP - Cast Chain Heal"),
(@ENTRY,0,1,0,2,0,100,2,0,40,50000,50000,11,42478,1,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Medicine Man - At 40% HP - Cast Protective Ward"),
(@ENTRY,0,2,0,0,0,100,2,7000,7000,25000,25000,11,42376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Medicine Man - In Combat - Cast Healing Ward"),
(@ENTRY,0,3,0,0,0,100,2,1000,1000,16000,16000,11,45075,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Medicine Man - In Combat - Cast Lightning Bolt");

-- Amani'shi Tribesman SAI
SET @ENTRY := 23582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,0,0,13000,13000,11,42495,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Tribesman - In Combat - Cast Cyclone Strike"),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,9000,12000,11,36033,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Tribesman - In Combat - Cast Kick");

-- Amani Bear SAI
SET @ENTRY := 23584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,28000,28000,11,42745,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Bear - In Combat - Cast Enrage"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,20000,20000,11,42747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Bear - In Combat - Cast Crunch Armor");

-- Anubisath Swarmguard SAI
SET @ENTRY := 15538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Swarmguard - In Combat - Cast Cleave");

-- Spawn of Fankriss SAI
SET @ENTRY := 15630;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,1,30,5000,5000,11,26662,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spawn of Fankriss - At 30% HP - Cast Berserk");

-- Amani'shi Axe Thrower SAI
SET @ENTRY := 23542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,12000,12000,11,31566,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Axe Thrower - In Combat - Cast Raptor Strike"),
(@ENTRY,0,1,0,0,0,100,2,0,0,7400,7400,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Axe Thrower - In Combat - Cast Knockdown"),
(@ENTRY,0,2,0,0,0,100,2,0,0,27000,27000,11,42359,0,0,0,0,0,5,0,0,0,0,0,0,0,"Amani'shi Axe Thrower - In Combat - Cast Axe Volley"),
(@ENTRY,0,3,0,0,0,100,2,0,0,18000,18000,11,42332,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Axe Thrower - In Combat - Cast Throw Axe");

-- Obsidian Eradicator SAI
SET @ENTRY := 15262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,0,0,500,500,90,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Eradicator - Out Of Combat - Set Bytes1 0"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,1000,1000,11,25671,0,0,0,0,0,5,0,0,0,0,0,0,0,"Obsidian Eradicator - In Combat - Cast Drain Mana"),
(@ENTRY,0,2,0,3,0,100,2,99,100,1000,1000,11,26458,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Eradicator - At 100% Mana - Cast Shock Blast"),
(@ENTRY,0,3,0,0,0,100,2,0,0,40000,40000,11,20223,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Eradicator - In Combat - Cast Magic Reflection");

-- Qiraji Mindslayer SAI
SET @ENTRY := 15246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,500,500,10000,10000,11,26079,0,0,0,0,0,5,0,0,0,0,0,0,0,"Qiraji Mindslayer - In Combat - Cast Cause Insanity"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,10000,10000,11,26049,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Mindslayer - In Combat - Cast Mana Burn"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,10000,10000,11,26048,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Mindslayer - In Combat - Cast Mind Blast"),
(@ENTRY,0,3,0,0,0,100,2,7000,7000,10000,10000,11,26044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Mindslayer - In Combat - Cast Mind Flay");

-- Qiraji Brainwasher SAI
SET @ENTRY := 15247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,16000,16000,11,26079,0,0,0,0,0,6,0,0,0,0,0,0,0,"Qiraji Brainwasher - In Combat - Cast Cause Insanity"),
(@ENTRY,0,1,0,0,0,100,2,0,0,10000,10000,11,26046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Brainwasher - In Combat - Cast Mana Burn"),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,20000,20000,11,26044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Brainwasher - In Combat - Cast Mind Flay");

-- Qiraji Lasher SAI
SET @ENTRY := 15249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,10000,10000,11,26027,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Lasher - In Combat - Cast Knockback"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,10000,10000,11,26038,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Lasher - In Combat - Cast Whirlwind");

-- Qiraji Slayer SAI
SET @ENTRY := 15250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,30500,30500,11,26043,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Slayer - In Combat - Cast Battle Shout"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,15000,15000,11,26041,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Slayer - In Combat - Cast Enrage"),
(@ENTRY,0,2,0,0,0,100,2,3000,3000,10000,10000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Slayer - In Combat - Cast Knock Away"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,8000,8000,11,13736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Slayer - In Combat - Cast Whirlwind");

-- Vekniss Wasp SAI
SET @ENTRY := 15236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,10000,10000,11,26077,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Wasp - In Combat - Cast Itch");

-- Vekniss Hive Crawler SAI
SET @ENTRY := 15240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,10000,10000,11,25809,0,0,0,0,0,5,0,0,0,0,0,0,0,"Vekniss Hive Crawler - In Combat - Cast Crippling Poison"),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,10000,10000,11,25810,0,0,0,0,0,5,0,0,0,0,0,0,0,"Vekniss Hive Crawler - In Combat - Cast Mind-numbing Poison"),
(@ENTRY,0,2,0,0,0,100,2,1000,1000,10000,10000,11,26601,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Hive Crawler - In Combat - Cast Poison Bolt"),
(@ENTRY,0,3,0,0,0,100,2,0,0,4500,4500,11,25051,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Hive Crawler - In Combat - Cast Sunder Armor");

-- Crimson Hand Inquisitor SAI
SET @ENTRY := 20050;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,37274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - On Aggro - Cast Power Infusion"),
(@ENTRY,0,1,0,0,0,100,2,35000,35000,40000,65000,11,37274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - In Combat - Cast Power Infusion"),
(@ENTRY,0,2,0,0,0,100,2,25000,25000,50000,60000,11,37276,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - In Combat - Cast Mind Flay"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,20000,40000,11,37275,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - In Combat - Cast Shadow Word: Pain");

-- Crystalcore Mechanic SAI
SET @ENTRY := 20052;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,15000,15000,35000,35000,11,37123,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalcore Mechanic - In Combat - Cast Saw Blade"),
(@ENTRY,0,1,0,1,0,100,2,5000,5000,20000,40000,11,37121,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalcore Mechanic - Out Of Combat - Cast Recharge");

-- Vekniss Soldier SAI
SET @ENTRY := 15229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,60000,60000,11,25152,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Soldier - In Combat - Cast Agro Drones"),
(@ENTRY,0,1,0,0,0,100,2,500,500,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Soldier - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,1500,1500,10000,10000,11,1906,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Soldier - In Combat - Cast Debilitating Charge");

-- Vekniss Warrior SAI
SET @ENTRY := 15230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,6122,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vekniss Warrior - On Death - Cast Summon Vekniss Borer");

-- Astromancer Lord SAI
SET @ENTRY := 20046;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,38732,0,0,0,0,0,1,0,0,0,0,0,0,0,"Astromancer Lord - On Aggro - Cast Fire Shield"),
(@ENTRY,0,1,0,0,0,85,2,19000,19000,25000,25000,11,37109,0,0,0,0,0,2,0,0,0,0,0,0,0,"Astromancer Lord - In Combat - Cast Fireball Volley"),
(@ENTRY,0,2,0,0,0,75,2,25000,25000,20000,20000,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,"Astromancer Lord - In Combat - Cast Fire Blast"),
(@ENTRY,0,3,0,0,0,75,2,22000,22000,29000,29000,11,37289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Astromancer Lord - In Combat - Cast Dragon's Breath");

-- Crimson Hand Battle Mage SAI
SET @ENTRY := 20047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,25000,25000,35000,45000,11,37263,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Hand Battle Mage - In Combat - Cast Blizzard"),
(@ENTRY,0,1,0,0,0,60,2,5000,5000,15000,75000,11,37265,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hand Battle Mage - In Combat - Cast Cone of Cold"),
(@ENTRY,0,2,0,0,0,100,2,35000,35000,25000,55000,11,37262,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hand Battle Mage - In Combat - Cast Frostbolt Volley");

-- Crimson Hand Centurion SAI
SET @ENTRY := 20048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,30000,50000,11,37268,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hand Centurion - In Combat - Cast Arcane Flurry");

-- Phoenix-Hawk SAI
SET @ENTRY := 20039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,20000,20000,25000,25000,11,37156,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phoenix-Hawk - In Combat - Cast Dive"),
(@ENTRY,0,1,0,0,0,85,2,15000,15000,19000,19000,11,37159,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phoenix-Hawk - In Combat - Cast Mana Burn");

-- Crystalcore Sentinel SAI
SET @ENTRY := 20041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,25000,25000,45000,45000,11,37106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalcore Sentinel - In Combat - Cast Charged Arcane Explosion"),
(@ENTRY,0,1,0,0,0,85,2,30000,30000,30000,30000,11,37104,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crystalcore Sentinel - In Combat - Cast Overcharge"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,11,34937,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalcore Sentinel - At 15% HP - Cast Powered Down");

-- Tempest-Smith SAI
SET @ENTRY := 20042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,5000,5000,20000,40000,11,34946,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Smith - Out Of Combat - Cast Golem Repair"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,20000,40000,11,37120,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tempest-Smith - In Combat - Cast Fragmentation Bomb"),
(@ENTRY,0,2,0,0,0,100,2,25000,25000,45000,65000,11,37112,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Smith - In Combat - Cast Power Up"),
(@ENTRY,0,3,0,0,0,75,2,35000,35000,35000,75000,11,37118,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Smith - In Combat - Cast Shell Shock");

-- Apprentice Star Scryer SAI
SET @ENTRY := 20043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15000,15000,250000,250000,11,37129,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast Arcane Volley"),
(@ENTRY,0,1,0,0,0,100,2,17000,17000,19000,19000,11,38725,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,0,0,100,2,15000,15000,35000,65000,11,37133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast Arcane Buffet"),
(@ENTRY,0,3,0,0,0,100,2,40000,40000,40000,65000,11,37132,0,0,0,0,0,5,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast Arcane Shock");
