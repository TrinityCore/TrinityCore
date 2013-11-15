-- Naxxanar Skeletal Mage SAI
SET @ENTRY := 25396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3600,10700,5100,17200,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxanar Skeletal Mage - In Combat - Cast 9672"),
(@ENTRY,0,1,0,0,0,100,0,500,6500,4800,13700,11,9053,1,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxanar Skeletal Mage - In Combat - Cast 9053"),
(@ENTRY,0,2,0,2,0,30,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxanar Skeletal Mage - Between 0-15% Health - Say Line 0");

-- Texts for Naxxanar Skeletal Mage
SET @ENTRY := 25396;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -497 AND -496;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You cannot stop us all!",12,0,100,0,0,0,"Naxxanar Skeletal Mage"),
(@ENTRY,0,1,"Your death will soon follow....",12,0,100,0,0,0,"Naxxanar Skeletal Mage");

-- Magmoth Shaman SAI
SET @ENTRY := 25428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magmoth Shaman - Between 0-15% Health - Flee For Assist");

-- Texts for Magmoth Shaman
SET @ENTRY := 25428;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -512 AND -510;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Kada nu batteka, oht!",12,0,100,0,0,0,"Magmoth Shaman"),
(@ENTRY,0,1,"Etu Magmothregar, cha!",12,0,100,0,0,0,"Magmoth Shaman"),
(@ENTRY,0,2,"Kaganishu!",12,0,100,0,0,0,"Magmoth Shaman");

-- Magmoth Forager SAI
SET @ENTRY := 25429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Forager - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magmoth Forager - Between 0-15% Health - Flee For Assist");

-- Texts for Magmoth Forager
SET @ENTRY := 25429;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Kada nu batteka, oht!",12,0,100,0,0,0,"Magmoth Forager"),
(@ENTRY,0,1,"Etu Magmothregar, cha!",12,0,100,0,0,0,"Magmoth Forager"),
(@ENTRY,0,2,"Kaganishu!",12,0,100,0,0,0,"Magmoth Forager");

-- Mate of Magmothregar SAI
SET @ENTRY := 25432;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,50420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mate of Magmothregar - Between 0-30% Health - Cast 50420"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mate of Magmothregar - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,45691,7,0,0,0,0,1,0,0,0,0,0,0,0,"Mate of Magmothregar - On Death - Cast 45691");

-- Texts for Mate of Magmothregar
SET @ENTRY := 25432;
DELETE FROM creature_ai_texts WHERE entry IN (-106);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Mate of Magmothregar");

-- Winterfin Warrior SAI
SET @ENTRY := 25217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1800,3100,16500,20200,11,50267,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Warrior - In Combat - Cast 50267"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Winterfin Warrior - Between 0-15% Health - Flee For Assist");

-- Risen Longrunner SAI
SET @ENTRY := 25350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,5700,9600,12900,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Longrunner - In Combat - Cast 36093");

-- Beryl Treasure Hunter SAI
SET @ENTRY := 25353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,12500,15500,11,50658,0,0,0,0,0,2,0,0,0,0,0,0,0,"Beryl Treasure Hunter - In Combat - Cast 50658");

-- Shattered Sun Cleric SAI
SET @ENTRY := 25155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,90000,20000,70000,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Cleric - Out Of Combat - Emote Laugh"),
(@ENTRY,0,1,0,1,0,100,0,5000,25000,5000,25000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Cleric - Out Of Combat - Emote Talk");

-- Glrggl SAI
SET @ENTRY := 25203;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,800,6500,8800,16900,11,50169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glrggl - In Combat - Cast 50169");

-- Glimmer Bay Orca SAI
SET @ENTRY := 25204;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,800,6500,8800,18800,11,50169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glimmer Bay Orca - In Combat - Cast 50169");

-- Keymaster Urmgrgl SAI
SET @ENTRY := 25210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keymaster Urmgrgl - On LOS Out Of Combat - Say Line 0");

-- Texts for Keymaster Urmgrgl
SET @ENTRY := 25210;
DELETE FROM creature_ai_texts WHERE entry IN (-495);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I am the Keymaster. Are you the Gatekeeper?",12,0,100,0,0,0,"Keymaster Urmgrgl");

-- Winterfin Shorestriker SAI
SET @ENTRY := 25215;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Shorestriker - On Aggro - Cast 50262"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Winterfin Shorestriker - Between 0-15% Health - Flee For Assist");

-- Isuldof Iceheart SAI
SET @ENTRY := 24877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,45323,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Isuldof Iceheart - On Spellhit By 45323 - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,24877,0,0,0,0,0,7,0,0,0,0,0,0,0,"Isuldof Iceheart - On Spellhit By 45323 - Quest Credit");

-- Texts for Isuldof Iceheart
SET @ENTRY := 24877;
DELETE FROM creature_ai_texts WHERE entry IN (-10012);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Look to the seas, as your doom comes with the swell of tides",12,0,100,0,0,0,"Isuldof Iceheart");

-- Razorthorn Ravager SAI
SET @ENTRY := 24922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,12000,12000,17000,20000,11,33781,1,0,0,0,0,2,0,0,0,0,0,0,0,"Razorthorn Ravager - In Combat - Cast 33781"),
(@ENTRY,0,1,0,0,0,75,0,3000,6000,15000,20000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorthorn Ravager - In Combat - Cast 13443"),
(@ENTRY,0,2,0,0,0,100,0,6000,10000,10000,35000,11,46276,1,0,0,0,0,5,0,0,0,0,0,0,0,"Razorthorn Ravager - In Combat - Cast 46276");

-- Aged Magnataur SAI
SET @ENTRY := 24954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,120000,120000,11,50366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aged Magnataur - In Combat - Cast 50366");

-- Shattered Sun Marksman SAI
SET @ENTRY := 25142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,30000,12000,35000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Marksman - Out Of Combat - Emote Talk");

-- Shattered Sun Magi SAI
SET @ENTRY := 25153;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,90000,30000,90000,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Magi - Out Of Combat - Emote Laugh"),
(@ENTRY,0,1,0,1,0,100,0,5000,25000,5000,25000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Magi - Out Of Combat - Emote Talk");

-- Fengir the Disgraced SAI
SET @ENTRY := 24874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,45323,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fengir the Disgraced - On Spellhit By 45323 - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,24874,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fengir the Disgraced - On Spellhit By 45323 - Quest Credit");

-- Texts for Fengir the Disgraced
SET @ENTRY := 24874;
DELETE FROM creature_ai_texts WHERE entry IN (-10010);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your offering has come too late, little one. Can you feel the mist closing in upon you? The Kvaldir return...",12,0,100,0,0,0,"Fengir the Disgraced");

-- Windan of the Kvaldir SAI
SET @ENTRY := 24875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,45323,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windan of the Kvaldir - On Spellhit By 45323 - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,24875,0,0,0,0,0,7,0,0,0,0,0,0,0,"Windan of the Kvaldir - On Spellhit By 45323 - Quest Credit");

-- Texts for Windan of the Kvaldir
SET @ENTRY := 24875;
DELETE FROM creature_ai_texts WHERE entry IN (-10013);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"My brothers have awoken. Your efforts are wasted...",12,0,100,0,0,0,"Windan of the Kvaldir");

-- Rodin the Reckless SAI
SET @ENTRY := 24876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,45323,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rodin the Reckless - On Spellhit By 45323 - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,24876,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rodin the Reckless - On Spellhit By 45323 - Quest Credit");

-- Texts for Rodin the Reckless
SET @ENTRY := 24876;
DELETE FROM creature_ai_texts WHERE entry IN (-10011);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"From the mist and fog the Kvaldir approach. Flee while you still breathe the air of the living...",12,0,100,0,0,0,"Rodin the Reckless");

-- Nexus Watcher SAI
SET @ENTRY := 24770;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,11000,15000,11,36513,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Watcher - Between 0-30 Range - Cast 36513"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,10000,11,36631,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Watcher - Between 0-5 Range - Cast 36631");

-- Stonevault Pillager SAI
SET @ENTRY := 24830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Pillager - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,2,0,30,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Pillager - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Pillager - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Texts for Stonevault Pillager
SET @ENTRY := 24830;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Stonevault Pillager");

-- Nerub'ar Venomspitter SAI
SET @ENTRY := 24563;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,11000,11,6917,32,0,0,0,0,2,0,0,0,0,0,0,0,"Nerub'ar Venomspitter - In Combat - Cast 6917");

-- Nerub'ar Skitterer SAI
SET @ENTRY := 24566;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1900,9000,13800,17800,11,49749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nerub'ar Skitterer - In Combat - Cast 49749");

-- Den Vermin SAI
SET @ENTRY := 24567;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Vermin - On Respawn - Cast 8876");

-- Iceshard Elemental SAI
SET @ENTRY := 24228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,13000,11,50094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iceshard Elemental - In Combat - Cast 50094");

-- Howling Cyclone SAI
SET @ENTRY := 24229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,8000,12000,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Howling Cyclone - Between 0-30 Range - Cast 32018"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,33,24228,0,0,0,0,0,7,0,0,0,0,0,0,0,"Howling Cyclone - On Death - Quest Credit");

-- Magnataur Huntress SAI
SET @ENTRY := 24469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,7000,9000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magnataur Huntress - In Combat - Cast 50410"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,1500,19000,11,11876,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Huntress - In Combat - Cast 11876");

-- Amani Elder Lynx SAI
SET @ENTRY := 24530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,30,90000,90000,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Elder Lynx - Between 0-30% Health - Cast 34970 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,2,0,30,90000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Elder Lynx - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,12000,20000,25000,11,43357,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Elder Lynx - In Combat - Cast 43357 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,1500,1500,9000,13000,11,43356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Elder Lynx - In Combat - Cast 43356 (Normal Dungeon)");

-- Texts for Amani Elder Lynx
SET @ENTRY := 24530;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Amani Elder Lynx");

-- Bloodscalp Shaman SAI
SET @ENTRY := 697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,6000000,6000000,11,8788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Shaman - Out Of Combat - Cast 8788"),
(@ENTRY,0,1,0,0,0,100,0,13200,29600,24800,37300,11,11969,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Shaman - In Combat - Cast 11969"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Shaman - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Shaman - Between 0-30% Health - Say Line 0");

-- Texts for Bloodscalp Shaman
SET @ENTRY := 697;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodscalp Shaman");

-- Firewing Bloodwarder SAI
SET @ENTRY := 1410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,7000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firewing Bloodwarder - In Combat - Cast 16583"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,12000,18000,11,33483,1,0,0,0,0,5,0,0,0,0,0,0,0,"Firewing Bloodwarder - In Combat - Cast 33483"),
(@ENTRY,0,2,0,0,0,100,0,8000,13000,13000,18000,11,33390,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firewing Bloodwarder - In Combat - Cast 33390");

-- Forest Moss Creeper SAI
SET @ENTRY := 2350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7800,15700,48300,66300,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Moss Creeper - In Combat - Cast 3396 (Dungeon Only)");

-- Elder Mottled Boar SAI
SET @ENTRY := 3100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,0,0,11,3385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Mottled Boar - Between 0-20 Range - Cast 3385");

-- Witchwing Roguefeather SAI
SET @ENTRY := 3277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,75,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Witchwing Roguefeather - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,12000,16000,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Roguefeather - In Combat - Cast 7992"),
(@ENTRY,0,2,0,0,0,100,0,7000,11000,9000,12000,11,6595,1,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Roguefeather - In Combat - Cast 6595");

-- Texts for Witchwing Roguefeather
SET @ENTRY := 3277;
DELETE FROM creature_ai_texts WHERE entry IN (-494);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"My talons will shred your puny body, $r.",12,0,100,0,0,0,"Witchwing Roguefeather");

-- Serena Bloodfeather SAI
SET @ENTRY := 3452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,19000,19000,3000,7000,11,3264,0,0,0,0,0,2,0,0,0,0,0,0,0,"Serena Bloodfeather - In Combat - Cast 3264");

-- Razormane Stalker SAI
SET @ENTRY := 3457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,1000,1000,11,1758,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Stalker - In Combat - Cast 1758");

-- Razormane Seer SAI
SET @ENTRY := 3458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,80,0,0,65,7500,7500,11,6274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - Between 0-65% Health - Cast 6274"),
(@ENTRY,0,1,0,0,0,100,0,14000,14000,4000,4000,11,6363,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - In Combat - Cast 6363");

-- Oasis Snapjaw SAI
SET @ENTRY := 3461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,18000,17000,24000,11,6530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oasis Snapjaw - In Combat - Cast 6530");

-- Owatanka SAI
SET @ENTRY := 3473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,15000,10000,18000,11,6254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Owatanka - In Combat - Cast 6254");

-- Anaya Dawnrunner SAI
SET @ENTRY := 3667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,14000,17000,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anaya Dawnrunner - In Combat - Cast 5884 (Not found in DBCs!)"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya Dawnrunner - On Death - Say Line 0");

-- Texts for Anaya Dawnrunner
SET @ENTRY := 3667;
DELETE FROM creature_ai_texts WHERE entry IN (-554);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Finally, my soul may rest... Oh, dearest Cerellean...",12,0,100,0,0,0,"Anaya Dawnrunner");

-- Wrathtail Myrmidon SAI
SET @ENTRY := 3711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7800,15700,10200,19900,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Myrmidon - In Combat - Cast 11976"),
(@ENTRY,0,1,0,9,0,100,0,0,5,26600,39800,11,11977,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Myrmidon - Between 0-5 Range - Cast 11977"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wrathtail Myrmidon - Between 0-15% Health - Flee For Assist");

-- Wrathtail Razortail SAI
SET @ENTRY := 3712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,782,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Razortail - On Aggro - Cast 782"),
(@ENTRY,0,1,0,9,0,100,0,0,5,45000,45000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Razortail - Between 0-5 Range - Cast 6016"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wrathtail Razortail - Between 0-15% Health - Flee For Assist");

-- Rethilgore SAI
SET @ENTRY := 3914;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1300,14600,14200,36000,11,7295,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rethilgore - In Combat - Cast 7295 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,34,2,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rethilgore - On Aggro - Set Instance Data Field To 2 To Data 1 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,34,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Rethilgore - On Death - Set Instance Data Field To 2 To Data 3 (Normal Dungeon)"),
(@ENTRY,0,3,0,7,0,100,3,0,0,0,0,34,2,2,0,0,0,0,1,0,0,0,0,0,0,0,"Rethilgore - On Evade - Set Instance Data Field To 2 To Data 2 (Normal Dungeon)");

-- Cave Stalker SAI
SET @ENTRY := 4040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4300,17000,40100,64600,11,3358,32,0,0,0,0,2,0,0,0,0,0,0,0,"Cave Stalker - In Combat - Cast 3358");

-- Galak Mauler SAI
SET @ENTRY := 4095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,32000,37000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Mauler - In Combat - Cast 13730"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Galak Mauler - Between 0-15% Health - Flee For Assist");

-- Galak Windchaser SAI
SET @ENTRY := 4096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,18000,26000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Galak Windchaser - In Combat - Cast 6728"),
(@ENTRY,0,1,0,14,0,100,1,300,40,0,0,11,939,1,0,0,0,0,7,0,0,0,0,0,0,0,"Galak Windchaser - On Friendly Unit At 300 Health Within 40 Range - Cast 939"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Galak Windchaser - Between 0-15% Health - Flee For Assist");

-- Galak Marauder SAI
SET @ENTRY := 4099;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Marauder - On Aggro - Cast 6268 (Not found in DBCs!)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Galak Marauder - Between 0-15% Health - Flee For Assist");

-- Screeching Harpy SAI
SET @ENTRY := 4100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,17000,25000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Screeching Harpy - In Combat - Cast 3589 (Not found in DBCs!)");

-- Screeching Roguefeather SAI
SET @ENTRY := 4101;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,10000,15000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Screeching Roguefeather - In Combat - Cast 6595 (Not found in DBCs!)");

-- Screeching Windcaller SAI
SET @ENTRY := 4104;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,7500,35000,40000,11,6982,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Windcaller - In Combat - Cast 6982 (Not found in DBCs!)");

-- Highperch Wyvern SAI
SET @ENTRY := 4107;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3616,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highperch Wyvern - On Respawn - Cast 3616 (Not found in DBCs!)");

-- Highperch Consort SAI
SET @ENTRY := 4109;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3616,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highperch Consort - On Respawn - Cast 3616 (Not found in DBCs!)");

-- Highperch Patriarch SAI
SET @ENTRY := 4110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3616,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highperch Patriarch - On Respawn - Cast 3616 (Not found in DBCs!)");

-- Gravelsnout Kobold SAI
SET @ENTRY := 4111;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,4000,7000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Kobold - In Combat - Cast 11976 (Not found in DBCs!)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelsnout Kobold - Between 0-15% Health - Flee For Assist");

-- Gravelsnout Vermin SAI
SET @ENTRY := 4112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,12000,8000,13000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Vermin - In Combat - Cast 3427 (Not found in DBCs!)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelsnout Vermin - Between 0-15% Health - Flee For Assist");

-- Gravelsnout Digger SAI
SET @ENTRY := 4113;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,7000,10000,11,3551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Digger - In Combat - Cast 3551 (Not found in DBCs!)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelsnout Digger - Between 0-15% Health - Flee For Assist");

-- Gravelsnout Forager SAI
SET @ENTRY := 4114;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,3000,0,0,11,8245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Forager - In Combat - Cast 8245 (Not found in DBCs!)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelsnout Forager - Between 0-15% Health - Flee For Assist");

-- Expedition Researcher SAI
SET @ENTRY := 17681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Expedition Researcher - On Respawn - Say Line 0");

-- Texts for Expedition Researcher
SET @ENTRY := 17681;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Woot! Thanks!",12,0,100,0,0,0,"Expedition Researcher");

-- Netherstorm Agent SAI
SET @ENTRY := 19541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,80,0,60000,60000,200000,230000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherstorm Agent - Out Of Combat - Say Line 0");

-- Texts for Netherstorm Agent
SET @ENTRY := 19541;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Maybe I should gather up some other agents and head out there after this shift?",12,0,100,0,0,0,"Netherstorm Agent"),
(@ENTRY,0,1,"Last time someone went out to try and collect the bounty on Netherlock, all we got back was a compressed layer of foolhardy adventurer!",12,0,100,0,0,0,"Netherstorm Agent");

-- Orc Prisoner SAI
SET @ENTRY := 18598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,6,40000,60000,120000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orc Prisoner - Out Of Combat - Say Line 0 (Dungeon Only)");

-- Texts for Orc Prisoner
SET @ENTRY := 18598;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Don't feel.....so good.....",12,0,100,0,0,0,"Orc Prisoner"),
(@ENTRY,0,1,"When do we eat again?",12,0,100,0,0,0,"Orc Prisoner");

-- Cabal Cultist SAI
SET @ENTRY := 18631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,6,8000,10000,0,0,11,15614,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Cultist - On Target Casting - Cast 15614 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,3000,8000,10000,12000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Cultist - In Combat - Cast 3391 (Dungeon Only)");

-- Cabal Executioner SAI
SET @ENTRY := 18632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,10000,10000,13000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - In Combat - Cast 33500 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,7000,10000,10000,13000,11,15578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - In Combat - Cast 15578 (Heroic Dungeon)"),
(@ENTRY,0,2,0,12,0,100,6,0,20,12000,18000,11,7160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - On Target Between 0-20% Health - Cast 7160 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - Between 0-30% Health - Cast 30485 (Dungeon Only)");

-- Phasing Soldier SAI
SET @ENTRY := 18556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,11,32828,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Soldier - Out Of Combat - Cast 32828 (Dungeon Only)"),
(@ENTRY,0,1,0,13,0,90,6,8000,10000,0,0,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Soldier - On Target Casting - Cast 11972 (Dungeon Only)");

-- Phasing Cleric SAI
SET @ENTRY := 18557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,5000,20,7000,8000,11,33324,1,0,0,0,0,7,0,0,0,0,0,0,0,"Phasing Cleric - On Friendly Unit At 5000 Health Within 20 Range - Cast 33324 (Normal Dungeon)"),
(@ENTRY,0,1,0,14,0,100,4,9000,20,7000,8000,11,31739,1,0,0,0,0,7,0,0,0,0,0,0,0,"Phasing Cleric - On Friendly Unit At 9000 Health Within 20 Range - Cast 31739 (Heroic Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,2000,20,6000,8000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,"Phasing Cleric - On Friendly Unit At 2000 Health Within 20 Range - Cast 25058 (Normal Dungeon)"),
(@ENTRY,0,3,0,14,0,100,4,4000,20,6000,8000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Phasing Cleric - On Friendly Unit At 4000 Health Within 20 Range - Cast 38210 (Heroic Dungeon)");

-- Ayit SAI
SET @ENTRY := 18540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ayit - Between 0-5 Range - Cast 11972");

-- Phantasmal Possessor SAI
SET @ENTRY := 18503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,10000,20000,30000,11,33401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantasmal Possessor - In Combat - Cast 33401 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Possessor - On Evade - Forced Despawn (Dungeon Only)");

-- Raging Soul SAI
SET @ENTRY := 18506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,11,32888,1,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - In Combat - Cast 32888 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,5,0,0,0,0,11,38380,1,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - In Combat - Cast 38380 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - On Evade - Forced Despawn (Dungeon Only)");

-- Unliving Soldier SAI
SET @ENTRY := 18498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,32828,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Soldier - On Respawn - Cast 32828 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,13,0,90,6,8000,10000,0,0,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Soldier - On Target Casting - Cast 11972 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Soldier - On Evade - Forced Despawn (Dungeon Only)");

-- Dreadfang Lurker SAI
SET @ENTRY := 18466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6500,4000,9000,11,32902,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadfang Lurker - In Combat - Cast 32902 (Not found in DBCs!)");

-- Dreadfang Widow SAI
SET @ENTRY := 18467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6500,4000,9000,11,32902,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadfang Widow - In Combat - Cast 32902 (Not found in DBCs!)");

-- Teromoth SAI
SET @ENTRY := 18468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,12500,15000,22000,11,32904,0,0,0,0,0,2,0,0,0,0,0,0,0,"Teromoth - In Combat - Cast 32904 (Not found in DBCs!)");

-- Royal Teromoth SAI
SET @ENTRY := 18469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,12500,15000,22000,11,32904,0,0,0,0,0,2,0,0,0,0,0,0,0,"Royal Teromoth - In Combat - Cast 32904 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,9000,15000,11,32914,1,0,0,0,0,1,0,0,0,0,0,0,0,"Royal Teromoth - In Combat - Cast 32914 (Not found in DBCs!)");

-- Bonelasher SAI
SET @ENTRY := 18470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,5000,7000,11,34363,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bonelasher - In Combat - Cast 34363 (Not found in DBCs!)");

-- Timber Worg SAI
SET @ENTRY := 18476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,16000,20000,11,32918,1,0,0,0,0,1,0,0,0,0,0,0,0,"Timber Worg - In Combat - Cast 32918 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,4000,6000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timber Worg - In Combat - Cast 32919 (Not found in DBCs!)");

-- Timber Worg Alpha SAI
SET @ENTRY := 18477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,15000,18000,11,3149,1,0,0,0,0,1,0,0,0,0,0,0,0,"Timber Worg Alpha - In Combat - Cast 3149 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,5000,7000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timber Worg Alpha - In Combat - Cast 32919 (Not found in DBCs!)");

-- Lost Spirit SAI
SET @ENTRY := 18460;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,9000,12000,11,32938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Spirit - In Combat - Cast 32938 (Not found in DBCs!)");

-- Dampscale Basilisk SAI
SET @ENTRY := 18461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,45000,50000,11,32905,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dampscale Basilisk - In Combat - Cast 32905 (Not found in DBCs!)");

-- Dampscale Devourer SAI
SET @ENTRY := 18463;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,4000,7000,11,32906,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dampscale Devourer - In Combat - Cast 32906 (Not found in DBCs!)");

-- Skithian Windripper SAI
SET @ENTRY := 18453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Windripper - On Aggro - Cast 32924 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,6000,9000,11,32907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skithian Windripper - In Combat - Cast 32907 (Not found in DBCs!)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,16000,21000,11,16561,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Windripper - Between 0-50% Health - Cast 16561 (Not found in DBCs!)");

-- Shalassi Talonguard SAI
SET @ENTRY := 18454;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,45000,48000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shalassi Talonguard - In Combat - Cast 6016 (Not found in DBCs!)");

-- Shalassi Oracle SAI
SET @ENTRY := 18455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shalassi Oracle - On Aggro - Cast 32924 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,7000,11000,11,32907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shalassi Oracle - In Combat - Cast 32907 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,40000,45000,11,6535,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shalassi Oracle - In Combat - Cast 6535 (Not found in DBCs!)"),
(@ENTRY,0,3,0,0,0,100,0,8000,11000,13000,16000,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shalassi Oracle - In Combat - Cast 12058 (Not found in DBCs!)"),
(@ENTRY,0,4,0,0,0,100,0,12000,14000,13000,16000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shalassi Oracle - In Combat - Cast 11824 (Not found in DBCs!)");

-- Shienor Wing Guard SAI
SET @ENTRY := 18451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,11000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shienor Wing Guard - Between 0-5 Range - Cast 11972 (Not found in DBCs!)");

-- Warden Bullrok SAI
SET @ENTRY := 18407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,120000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Bullrok - Out Of Combat - Say Line 0");

-- Texts for Warden Bullrok
SET @ENTRY := 18407;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -314 AND -313;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Damm those ogres. Damn them to the Nether. Won't someone save us from these savages! This is the fifth kidnapping is as many days.",12,0,100,0,0,0,"Warden Bullrok"),
(@ENTRY,0,1,"That's the best reward we're going to be able to offer. Hopefully someone accepts the mission.",12,0,100,0,0,0,"Warden Bullrok");

-- Durn the Hungerer SAI
SET @ENTRY := 18411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,30000,30000,30000,50000,11,34771,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durn the Hungerer - In Combat - Cast 34771 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,9000,15000,11,28168,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durn the Hungerer - In Combat - Cast 28168 (Not found in DBCs!)");

-- Arcane Fiend SAI
SET @ENTRY := 18429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1300,3700,4800,6200,11,15253,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Fiend - In Combat - Cast 15253 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,1300,3700,4800,6200,11,33860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Fiend - In Combat - Cast 33860 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,2,0,13,0,100,6,25000,30000,0,0,11,15122,1,0,0,0,0,7,0,0,0,0,0,0,0,"Arcane Fiend - On Target Casting - Cast 15122 (Not found in DBCs!) (Dungeon Only)");

-- Vicious Teromoth SAI
SET @ENTRY := 18437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vicious Teromoth - On Respawn - Cast 32423 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,9000,15000,16000,24000,11,32913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vicious Teromoth - In Combat - Cast 32913 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,11000,16000,11,32914,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vicious Teromoth - In Combat - Cast 32914 (Not found in DBCs!)");

-- Naphthal'ar SAI
SET @ENTRY := 18438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,15000,16000,24000,11,32913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naphthal'ar - In Combat - Cast 32913 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,11000,16000,11,32914,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naphthal'ar - In Combat - Cast 32914 (Not found in DBCs!)");

-- Giselda the Crone SAI
SET @ENTRY := 18391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,65,0,0,11,33316,0,0,0,0,0,1,0,0,0,0,0,0,0,"Giselda the Crone - Between 0-65% Health - Cast 33316 (Not found in DBCs!)");

-- Ethereal Darkcaster SAI
SET @ENTRY := 18331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,38061,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Darkcaster - On Aggro - Cast 38061 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,2500,6100,9600,12000,11,34942,32,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Darkcaster - In Combat - Cast 34942 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,2,3700,7600,6000,6900,11,34930,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ethereal Darkcaster - In Combat - Cast 34930 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,3700,7600,6000,6900,11,34931,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ethereal Darkcaster - In Combat - Cast 34931 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,4,0,2,0,100,7,0,50,0,0,11,16592,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Darkcaster - Between 0-50% Health - Cast 16592 (Not found in DBCs!) (Dungeon Only)");

-- Tavarok SAI
SET @ENTRY := 18343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,14200,20000,38600,11,33919,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 33919 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,12000,23500,14100,24500,11,32361,1,0,0,0,0,5,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 32361 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,2,12000,20700,7400,15500,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 8374 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,12000,20700,7400,15500,11,38761,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 38761 (Not found in DBCs!) (Heroic Dungeon)");

-- Sethekk Guard SAI
SET @ENTRY := 18323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,10000,13000,11,33967,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Guard - In Combat - Cast 33967 (Not found in DBCs!) (Dungeon Only)");

-- Sethekk Prophet SAI
SET @ENTRY := 18325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,8000,12000,11,27641,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sethekk Prophet - In Combat - Cast 27641 (Not found in DBCs!) (Dungeon Only)");

-- Sethekk Shaman SAI
SET @ENTRY := 18326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,8000,8000,0,0,11,15501,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Shaman - On Target Casting - Cast 15501 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,13,0,100,4,8000,8000,0,0,11,22885,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Shaman - On Target Casting - Cast 22885 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,32663,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Shaman - On Aggro - Cast 32663 (Not found in DBCs!) (Dungeon Only)");

-- Sethekk Oracle SAI
SET @ENTRY := 18328;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,2000,8000,14000,11,32690,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Oracle - In Combat - Cast 32690 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,1000,2000,8000,14000,11,38146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Oracle - In Combat - Cast 38146 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,7,4000,7000,0,0,11,32129,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Oracle - In Combat - Cast 32129 (Not found in DBCs!) (Dungeon Only)");

-- Time-Lost Shadowmage SAI
SET @ENTRY := 18320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,4000,7000,0,0,11,32682,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Shadowmage - In Combat - Cast 32682 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,5,4000,7000,0,0,11,38149,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Shadowmage - In Combat - Cast 38149 (Not found in DBCs!) (Heroic Dungeon)");

-- Sethekk Talon Lord SAI
SET @ENTRY := 18321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Talon Lord - On Aggro - Cast 32674 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,2000,6000,10000,15000,11,32654,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sethekk Talon Lord - In Combat - Cast 32654 (Not found in DBCs!) (Dungeon Only)");

-- Sethekk Initiate SAI
SET @ENTRY := 18318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,7000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Initiate - In Combat - Cast 16145 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,12000,18000,11,33961,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Initiate - In Combat - Cast 33961 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,2,0,14,0,5,7,10000,20,0,0,11,20223,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sethekk Initiate - On Friendly Unit At 10000 Health Within 20 Range - Cast 20223 (Not found in DBCs!) (Dungeon Only)");

-- Nexus Stalker SAI
SET @ENTRY := 18314;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7900,9700,22100,11,34940,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus Stalker - In Combat - Cast 34940 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,2,3000,10400,12200,18600,11,33925,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Stalker - In Combat - Cast 33925 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,3000,10400,12200,18600,11,39332,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Stalker - In Combat - Cast 39332 (Not found in DBCs!) (Heroic Dungeon)");

-- Ethereal Theurgist SAI
SET @ENTRY := 18315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,8500,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Theurgist - Between 0-5 Range - Cast 15580 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,4,0,5,5000,8500,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Theurgist - Between 0-5 Range - Cast 34920 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4200,6500,8000,12000,11,17145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 17145 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4200,6500,8000,12000,11,38064,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 38064 (Not found in DBCs!) (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,2400,7200,18000,24000,11,13323,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 13323 (Not found in DBCs!) (Dungeon Only)");

-- Ethereal Scavenger SAI
SET @ENTRY := 18309;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9500,16200,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Scavenger - Between 0-5 Range - Cast 34920 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,2400,3600,12100,13200,11,33865,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Scavenger - In Combat - Cast 33865 (Not found in DBCs!) (Dungeon Only)"),
(@ENTRY,0,2,0,13,0,100,6,10000,14000,0,0,11,33871,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Scavenger - On Target Casting - Cast 33871 (Not found in DBCs!) (Dungeon Only)");

DELETE FROM `linked_respawn` WHERE `guid` IN (79448,86059,86060,86061,86062,86063,86064);
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=47009 WHERE `entryorguid`=26268 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=43806 WHERE `entryorguid`=24439 AND `id`=4;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=50473 WHERE `entryorguid`=27409 AND `id`=5;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=58922 WHERE `entryorguid`=31273 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=55431, `action_param3`=0 WHERE `entryorguid`=2964700 AND `id`=0;

