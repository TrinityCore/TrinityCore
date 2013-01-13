-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -4 AND -2;
DELETE FROM `creature_text` WHERE `entry` IN (103,38,61,95,116,121,122,449,474,481,504,583,589,590,594,824,881,6866,6927);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(103,0,0, 'I see those fools at the Abbey sent some fresh meat for us.',12,0,100,0,0,0, 'Garrick Padfoot'),
(38,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Thug - Random Say on Aggro'),
(38,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Thug - Random Say on Aggro'),
(38,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Thug - Random Say on Aggro'),
(61,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Thuros Lightfingers - Random Say on Aggro'),
(61,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Thuros Lightfingers - Random Say on Aggro'),
(61,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Thuros Lightfingers - Random Say on Aggro'),
(95,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Smuggler - Random Say on Aggro'),
(95,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Smuggler - Random Say on Aggro'),
(95,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Smuggler - Random Say on Aggro'),
(116,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Bandit - Random Say on Aggro'),
(116,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Bandit - Random Say on Aggro'),
(116,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Bandit - Random Say on Aggro'),
(121,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Pathstalker - Random Say on Aggro'),
(121,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Pathstalker - Random Say on Aggro'),
(121,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Pathstalker - Random Say on Aggro'),
(122,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Highwayman - Random Say on Aggro'),
(122,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Highwayman - Random Say on Aggro'),
(122,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Highwayman - Random Say on Aggro'),
(449,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Knuckleduster - Random Say on Aggro'),
(449,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Knuckleduster - Random Say on Aggro'),
(449,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Knuckleduster - Random Say on Aggro'),
(474,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Rogue Wizard - Random Say on Aggro'),
(474,0,1, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Rogue Wizard - Random Say on Aggro'),
(481,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Footpad - Random Say on Aggro'),
(481,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Footpad - Random Say on Aggro'),
(481,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Footpad - Random Say on Aggro'),
(504,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Trapper - Random Say on Aggro'),
(504,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Trapper - Random Say on Aggro'),
(504,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Trapper - Random Say on Aggro'),
(583,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Ambusher - Random Say on Aggro'),
(583,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Ambusher - Random Say on Aggro'),
(583,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Ambusher - Random Say on Aggro'),
(589,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Pillager - Random Say on Aggro'),
(589,0,1, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Pillager - Random Say on Aggro'),
(590,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Looter - Random Say on Aggro'),
(590,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Looter - Random Say on Aggro'),
(590,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Looter - Random Say on Aggro'),
(594,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Henchman - Random Say on Aggro'),
(594,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Henchman - Random Say on Aggro'),
(594,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Henchman - Random Say on Aggro'),
(824,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Digger - Random Say on Aggro'),
(824,0,1, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Digger - Random Say on Aggro'),
(881,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Surena Caledon - Random Say on Aggro'),
(881,0,1, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Surena Caledon - Random Say on Aggro'),
(6866,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Bodyguard - Random Say on Aggro'),
(6866,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Bodyguard - Random Say on Aggro'),
(6866,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Bodyguard - Random Say on Aggro'),
(6927,0,0, 'The Brotherhood will not tolerate your actions.',12,0,100,0,0,0, 'Defias Dockworker - Random Say on Aggro'),
(6927,0,1, 'Ah, a chance to use this freshly sharpened blade.',12,0,100,0,0,0, 'Defias Dockworker - Random Say on Aggro'),
(6927,0,2, 'Feel the power of the Brotherhood!',12,0,100,0,0,0, 'Defias Dockworker - Random Say on Aggro');

-- SAI for Garrick Padfoot
SET @ENTRY := 103;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Garrick Padfoot - On Aggro - Cast Defensive Stance Spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Garrick Padfoot - Combat - Say random text');

-- SAI for Defias Thug
SET @ENTRY := 38;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Thug - On Aggro - Say random text');

-- SAI for Thuros Lightfingers
SET @ENTRY := 61;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,40,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thuros Lightfingers - On Aggro - Say random text');

-- SAI for Defias Smuggler
SET @ENTRY := 95;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,0,1,10277,3500,4100,15,0,0,0,0,0,0,0,0,0, 'Defias Smuggler - On Spawn - Load Caster template Cast Throw'),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Smuggler - On Aggro - Cast Throw'),
(@ENTRY,0,2,0,61,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Smuggler - On Aggro - Say random text'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Smuggler - HP@15% - Flee'),
(@ENTRY,0,4,0,0,0,100,0,1300,7300,4800,4900,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Smuggler - Combat - Cast BackStab');

-- SAI for Defias Bandit
SET @ENTRY := 116;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Bandit - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,65,0,4000,4000,5000,9000,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Bandit - Combat - Cast Snap Kick');

-- SAI for Defias Pathstalker
SET @ENTRY := 121;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Pathstalker - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,65,0,1300,7300,4800,4900,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Pathstalker - Combat - Cast Backstab'),
(@ENTRY,0,2,0,0,0,100,0,1500,13600,25200,39100,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Pathstalker - Combat - Cast Shieldbash'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Pathstalker - HP@15% - Flee');

-- SAI for Defias Highwayman
SET @ENTRY := 122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Highwayman - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,1200,3600,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Highwayman - Combat - Cast Backstab'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Highwayman - HP@15% - Flee');

-- SAI for Defias Knuckleduster
SET @ENTRY := 449;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Knuckleduster - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,1400,2700,7300,15000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Knuckleduster - Combat - Cast Pummel'),
(@ENTRY,0,2,0,0,0,40,0,2100,4300,3900,4300,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Knuckleduster - Combat - Cast Thrash'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Knuckleduster - HP@15% - Flee');

-- SAI for Defias Rogue Wizard
SET @ENTRY := 474;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,0,1,13222,1500,3000,5,30,0,0,0,0,0,0,0,0, 'Defias Rogue Wizard - On Spawn - Load Caster template Cast Frostbolt'),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Rogue Wizard - OOC - Cast Frost Armor'),
(@ENTRY,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Rogue Wizard - On Aggro - Say random text');

-- SAI for Defias Footpad
SET @ENTRY := 481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Footpad - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,5900,10200,8200,14100,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Footpad - Combat - Cast Backstab'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Footpad - HP@15% - Flee');

-- SAI for Defias Trapper
SET @ENTRY := 504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Trapper - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,2300,4700,2400,7300,11,2589,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Trapper - Combat - Cast Backstab'),
(@ENTRY,0,2,0,0,0,100,0,6500,14200,20500,31100,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Trapper - Combat - Cast Net'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Trapper - HP@15% - Flee');

-- SAI for Defias Ambusher
SET @ENTRY := 583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Ambusher - On Aggro - Say random text');

-- SAI for Defias Pillager
SET @ENTRY := 589;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,0,1,20793,3400,5400,5,30,0,0,0,0,0,0,0,0, 'Defias Pillager - On Spawn - Load Caster template Cast Fireball'),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Pillager - OOC - Cast Frost Armor'),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Pillager - On Aggro - Cast Fireball'),
(@ENTRY,0,3,0,61,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Pillager - On Aggro - Say random text'),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Pillager - HP@15% - Flee');

-- SAI for Defias Looter
SET @ENTRY := 590;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Looter - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,2000,9000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Looter - Combat - Cast Backstab'),
(@ENTRY,0,2,0,0,0,80,0,2000,6000,38100,48200,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Looter - Combat - Cast Disarm'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Looter - HP@15% - Flee');

-- SAI for Defias Henchman
SET @ENTRY := 594;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Henchman - On Aggro - Say random text'),
(@ENTRY,0,1,0,13,0,100,3,3200,13800,0,0,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Henchman - Combat - Cast Shield Slam'),
(@ENTRY,0,2,0,0,0,100,3,3600,18800,0,0,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Henchman - Combat - Cast Improved Blocking'),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Henchman - HP@15% - Flee');

-- SAI for Defias Digger
SET @ENTRY := 824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,15,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Digger - On Aggro - Say random text'),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Digger - HP@15% - Flee');

-- SAI for Surena Caledon
SET @ENTRY := 881;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,0,1,20793,1500,3000,5,30,0,0,0,0,0,0,0,0, 'Surena Caledon - On Spawn - Load Caster template Cast Fireball'),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Surena Caledon - OOC - Cast Frost Armor'),
(@ENTRY,0,2,0,4,0,40,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Surena Caledon - On Aggro - Say random text');

-- SAI for Defias Bodyguard
SET @ENTRY := 6866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,40,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Bodyguard - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,70,0,2900,2900,34000,38000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Bodyguard - Combat - Cast Disarm'),
(@ENTRY,0,2,0,0,0,80,0,5500,5500,5900,12900,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Bodyguard - Combat - Cast Backstab');

-- SAI for Defias Dockworker
SET @ENTRY := 6927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Dockworker - On Aggro - Say random text'),
(@ENTRY,0,1,0,0,0,100,0,8500,10500,37100,42100,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Defias Dockworker - Combat - Cast Snapkick');
