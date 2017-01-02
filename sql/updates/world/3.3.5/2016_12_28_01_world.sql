-- Exarch Admetius SAI
SET @ENTRY := 17658;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,1,9759,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exarch Admetius - On Quest 'Ending Their World' Finished - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,9759,0,0,0,80,1765800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Exarch Admetius - On Quest 'Ending Their World' Finished - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 1765800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1930.46,-11812.6,62.6309,2.30995,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1937.49,-11805.7,63.7985,5.53597,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1933.49,-11814.8,62.108,2.22748,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1939.96,-11808.2,62.6752,5.49985,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1936.87,-11817,61.1348,2.24899,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1942.61,-11810.6,61.8243,5.24734,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1940.21,-11819.8,60.3075,2.36209,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1945.48,-11813.6,60.9112,5.35298,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1944.12,-11823.2,59.0743,2.18733,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,12,17659,2,300000,0,0,0,8,0,0,0,-1948.83,-11816.8,60.053,5.34669,"Exarch Admetius - On Script - Summon Creature 'Blade of Argus'"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,12,17116,2,300000,0,0,0,8,0,0,0,-1958.72,-11821.6,58.8921,0.461123,"Exarch Admetius - On Script - Summon Creature 'Exarch Menelaous'"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,12,17214,2,300000,0,0,0,8,0,0,0,-1960.27,-11819.9,59.571,0.295709,"Exarch Admetius - On Script - Summon Creature 'Anchorite Fateema'"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,12,17101,2,300000,0,0,0,8,0,0,0,-1959.95,-11823.8,57.6277,0.372766,"Exarch Admetius - On Script - Summon Creature 'Diktynna'"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,12,17215,2,300000,0,0,0,8,0,0,0,-1961.16,-11823.4,57.702,0.640498,"Exarch Admetius - On Script - Summon Creature 'Daedal'"),
(@ENTRY,9,14,0,0,0,100,0,0,0,0,0,12,17110,2,300000,0,0,0,8,0,0,0,-1961.2,-11821.9,58.6004,0.525438,"Exarch Admetius - On Script - Summon Creature 'Acteon'"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,12,17440,2,300000,0,0,0,8,0,0,0,-1964.16,-11827,56.1668,0.561564,"Exarch Admetius - On Script - Summon Creature 'High Chief Stillpine'"),
(@ENTRY,9,16,0,0,0,100,0,0,0,0,0,12,17682,2,300000,0,0,0,8,0,0,0,-1966.07,-11824.7,57.2651,0.161011,"Exarch Admetius - On Script - Summon Creature 'Princess Stillpine'"),
(@ENTRY,9,17,0,0,0,100,0,0,0,0,0,12,17443,2,300000,0,0,0,8,0,0,0,-1966.24,-11822,58.598,6.20858,"Exarch Admetius - On Script - Summon Creature 'Kurz the Revelator'"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,12,17445,2,300000,0,0,0,8,0,0,0,-1968.9,-11829.1,55.0413,0.386419,"Exarch Admetius - On Script - Summon Creature 'Stillpine the Younger'"),
(@ENTRY,9,19,0,0,0,100,0,0,0,0,0,12,17242,2,300000,0,0,0,8,0,0,0,-1948.33,-11832.6,57.24,1.14982,"Exarch Admetius - On Script - Summon Creature 'Archaeologist Adamant Ironheart'"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,12,17240,2,300000,0,0,0,8,0,0,0,-1950.2,-11831.7,56.9671,1.09092,"Exarch Admetius - On Script - Summon Creature 'Admiral Odesyus'"),
(@ENTRY,9,21,0,0,0,100,0,0,0,0,0,12,17117,2,300000,0,0,0,8,0,0,0,-1952.31,-11831.3,56.7056,0.91224,"Exarch Admetius - On Script - Summon Creature 'Injured Night Elf Priestess'"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,12,17246,2,300000,0,0,0,8,0,0,0,-1949.92,-11834,56.7319,1.21854,"Exarch Admetius - On Script - Summon Creature Cookie McWeaksauce"),
(@ENTRY,9,23,0,0,0,100,0,0,0,0,0,12,17241,2,300000,0,0,0,8,0,0,0,-1952.39,-11833.5,56.4305,0.977035,"Exarch Admetius - On Script - Summon Creature Priestess Kyleen Ildinare"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,12,17311,2,300000,0,0,0,8,0,0,0,-1954.8,-11838.6,55.2527,1.1616,"Exarch Admetius - On Script - Summon Creature 'Cowlen'"),
(@ENTRY,9,25,0,0,0,100,0,0,0,0,0,12,17649,2,300000,0,0,0,8,0,0,0,-1955.7,-11843.1,54.1458,1.17557,"Exarch Admetius - On Script - Summon Creature Kessel"),
(@ENTRY,9,26,0,0,0,100,0,0,0,0,0,12,17468,2,300000,0,0,0,8,0,0,0,-1965.8,-11838.7,53.2196,0.792683,"Exarch Admetius - On Script - Summon Creature Prophet Velen");

-- Blade of Argus SAI
SET @ENTRY := 17659;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blade of Argus - On Just Summoned - Set Flag Standstate Kneel");

-- Diktynna SAI
SET @ENTRY := 17101;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,1,0,1,1,100,0,3000,3000,5000,8000,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - Out of Combat - Play Emote 4");

-- Exarch Menelaous SAI
SET @ENTRY := 17116;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,1,0,1,1,100,0,3000,3000,5000,8000,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - Out of Combat - Play Emote 4"),
(@ENTRY, 0, 2, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 17116, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip hello credit for quest 9663');

-- 17215SAI
SET @ENTRY := 17215;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,1,0,1,1,100,0,3000,3000,5000,8000,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - Out of Combat - Play Emote 4");

-- Acteon SAI
SET @ENTRY := 17110;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,1,0,1,1,100,0,3000,3000,5000,8000,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acteon - Out of Combat - Play Emote 4");

-- Anchorite Fateema SAI
SET @ENTRY := 17214;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Fateema - On Just Summoned - Play Emote 10");

-- Admiral Odesyus SAI
SET @ENTRY := 17240;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,33,17240,0,0,0,0,0,7,0,0,0,0,0,0,0,"Admiral Odesyus - On Gossip Hello - Quest Credit 'The Kessel Run'"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Odesyus - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,2,0,1,1,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Odesyus - Out of Combat - Play Emote 10 (Phase 1)");

-- Cowlen SAI
SET @ENTRY := 17311;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,7401,0,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cowlen - On Gossip Option 0 Selected - Play Emote 18"),
(@ENTRY,0,1,0,61,0,100,0,7401,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cowlen - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cowlen - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,3,0,1,1,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cowlen - Out of Combat - Play Emote 10 (Phase 1)");

-- Archaeologist Adamant Ironheart SAI
SET @ENTRY := 17242;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archaeologist Adamant Ironheart - On Just Summoned - Play Emote 10");

-- Injured Night Elf Priestess SAI
SET @ENTRY := 17117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Just Summoned - Remove Flag Standstate Sleep"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Just Summoned - Play Emote 10");

-- "Cookie" McWeaksauce SAI
SET @ENTRY := 17246;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Just Summoned - Play Emote 10");

-- Priestess Kyleen Il'dinare SAI
SET @ENTRY := 17241;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Priestess Kyleen Il'dinare - On Just Summoned - Play Emote 10");

-- Kessel SAI
SET @ENTRY := 17649;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kessel - On Just Summoned - Play Emote 10");
