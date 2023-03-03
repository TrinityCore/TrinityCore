-- Abyssal Watcher
SET @ENTRY := 161173;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,313737,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Abyssal Devastation'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,313977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Curse of the Void');

-- Amahtet
SET @ENTRY := 159320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,314909,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Shatter'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,314803,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Skin at 40% HP');

-- Amalgamation of Flesh
SET @ENTRY := 163841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,307044,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Nightmare Antibody');

-- Anubisath Sentinel
SET @ENTRY := 161571;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,315830,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,316133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,316097,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mending of Aqir at 40% HP');

-- Anubisath Sentinel
SET @ENTRY := 162417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,316143,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunder Clap'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,316133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP'),
(@ENTRY,0,3,0,9,0,100,0,0,8,15000,25000,11,316143,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunder Clap on Close');

-- Anubisath Sentinel
SET @ENTRY := 162508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,316133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,316620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley');

-- Anubisath Sentinel
SET @ENTRY := 162534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,316133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,316620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley');

-- Aqir Crusher
SET @ENTRY := 161218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,313938,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,313945,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psionic Frenzy at 30% HP');

-- Aqir Darter
SET @ENTRY := 157256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,307217,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psionic Resonance'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,307202,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Veil at 40% HP');

-- Aqir Drone
SET @ENTRY := 157255;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,307377,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Infusion');

-- Aqir Heartpiercer
SET @ENTRY := 162305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,316496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heartpiercer Venom');

-- Aqir Shadowcrafter
SET @ENTRY := 161416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,314998,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,315000,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Chisel');

-- Aqir Skitterer
SET @ENTRY := 161217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,308360,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fixate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Aqir Swarmer
SET @ENTRY := 162664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,308360,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fixate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Aqir Swarmkeeper
SET @ENTRY := 162303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,316677,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Germinating Parasite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,316618,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraging Toxin at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,55,15000,15000,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 55% HP'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,316663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Swarm on Aggro');

-- Aqir Venomweaver
SET @ENTRY := 161229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,305236,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,312584,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concentrated Venom'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,298510,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Aqiri Mind Toxin');

-- Ashwalker Assassin <Servant of the Black Emperor>
SET @ENTRY := 160291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Ambush');

-- Blood of Ny'alotha
SET @ENTRY := 159514;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,315094,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fixate'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,18000,11,312486,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Recurring Nightmare'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,311143,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Hemorrhage on Death'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,317672,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Frenzy at 30% HP');

-- Corrosive Digester
SET @ENTRY := 162828;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,316959,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devouring Acid'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,316951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Voracious Charge on Aggro'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,316923,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gastric Fluids on Spawn');

-- Crackling Stalker
SET @ENTRY := 157365;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,306874,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning');

-- Crushing Tendril
SET @ENTRY := 161312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Pound');

-- Cultist Sycophant
SET @ENTRY := 161251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,313994,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Demented Knife-Twister
SET @ENTRY := 159417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310834,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Darkened Dagger'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,310829,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,310764,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,3,0,7,0,100,1,0,0,0,0,11,310764,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Deresh of the Nothingness
SET @ENTRY := 159768;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,311045,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,311378,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Emanations at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,311382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Shear');

-- Eye of Drest'agath
SET @ENTRY := 157612;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310552,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,308953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Errant Blast'),
(@ENTRY,0,2,0,0,0,100,0,8000,15000,8000,22000,11,310396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Glare');

-- Eye of the Depths
SET @ENTRY := 159510;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310780,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,310838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Swing');

-- Gaze of Madness
SET @ENTRY := 157442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,312333,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deepening Madness at 40% HP');

-- Gnashing Terror
SET @ENTRY := 161334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Splash');

-- Gryth'ax the Executioner
SET @ENTRY := 159224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314847,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Decapitate'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,314851,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Expanding Darkness'),
(@ENTRY,0,2,0,0,0,100,0,10000,20000,10000,20000,11,314855,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Crash Blitz');

-- Hepthys
SET @ENTRY := 161745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,314909,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Shatter'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,314803,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Skin at 40% HP');

-- Iron-Willed Enforcer
SET @ENTRY := 162718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,315932,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Brutal Smash');

-- Jesh'ra
SET @ENTRY := 159764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,311574,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Monstrous Cleave'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Khateph
SET @ENTRY := 159321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,314909,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Shatter'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,314803,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Skin at 40% HP');

-- Leeching Parasite
SET @ENTRY := 159309;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314452,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crimson Spray'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,314451,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leeching Bite');

-- Living Blood
SET @ENTRY := 159312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314433,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sanguine Fountain'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,314400,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Bursting Blood on Death');

-- Maddened Conscript
SET @ENTRY := 159305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,311086,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,311084,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crazed Rush'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,311052,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Maw of Drest'agath
SET @ENTRY := 157613;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Splash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,310078,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spine Eruption at 40% HP');

-- Monstrous Behemoth
SET @ENTRY := 159303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,311023,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,311015,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Monstrous Eruption'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,8000,12000,8000,18000,11,311019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Weakening Blow');

-- Occult Shadowmender
SET @ENTRY := 159425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310845,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Smite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,310839,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dirge from Below at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Organ of Corruption
SET @ENTRY := 158343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310788,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pumping Blood');

-- Ossirat
SET @ENTRY := 161746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,314903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Claws'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,314909,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Shatter'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,314803,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Skin at 40% HP');

-- Prophet Skitra
SET @ENTRY := 157238;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,307937,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shred Psyche'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,318245,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,317669,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rage of the Corruptor at 30% HP');

-- Prophet Skitra
SET @ENTRY := 157620;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,307937,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shred Psyche'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,318245,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,317669,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rage of the Corruptor at 30% HP');

-- Sanguimar <Blood of N'Zoth>
SET @ENTRY := 159767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,311544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rain of Blood'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,311394,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Outflow');

-- Shath'Yar Scribe
SET @ENTRY := 163690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,311045,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,318409,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Discordant Whispers');

-- Sinister Soulcarver
SET @ENTRY := 162717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,307396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spiteful Assault');

-- Spellbound Ritualist
SET @ENTRY := 157450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,307177,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt');

-- Spellbound Ritualist
SET @ENTRY := 162716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,307177,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt');

-- Spiked Tentacle
SET @ENTRY := 159416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,311116,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reverberating Slam'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,311121,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Serrated Carapace at 40% HP');

-- Tentacle of Drest'agath
SET @ENTRY := 157614;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,310614,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,310348,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Entropic Crash'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,315766,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reality Tear at 40% HP');

-- Umbral Gatekeeper
SET @ENTRY := 163708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,318534,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gateway to Beyond'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Umbral Seer
SET @ENTRY := 159219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,311046,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt Volley'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Void Ascendant
SET @ENTRY := 162719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,307403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Annihilation');

-- Void Fanatic
SET @ENTRY := 160183;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Void Horror
SET @ENTRY := 161335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,314188,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Flay');

-- Void Initiate
SET @ENTRY := 160182;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,311045,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP');

-- Willing Sacrifice
SET @ENTRY := 162647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,311023,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dread Smash'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,311073,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Steadfast Defense at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,311019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Weakening Blow');

-- Zealous Adherent
SET @ENTRY := 159308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,311045,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,311091,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Condensing Void');