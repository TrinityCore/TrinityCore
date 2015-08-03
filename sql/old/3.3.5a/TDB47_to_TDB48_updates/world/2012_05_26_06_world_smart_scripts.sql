-- Blackhand Dreadweaver <Blackhand Legion> SAI
SET @ENTRY   := 9817;  -- NPC entry
SET @SPELL1  := 12739; -- Shadow Bolt
SET @SPELL2  := 7068;  -- Veil of Shadow
SET @SPELL3  := 12380; -- Shadow Channeling
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,2,0,0,0,0,58,1,@SPELL1,3600,6300,25,30,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - On Reset - Load caster template Cast Shadow Bolt'),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,@SPELL3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - On Reset - Aura Shadow Channeling'),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - On Aggro - Cast Shadow Bolt'),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - On Aggro - Call for help'),
(@ENTRY,0,4,0,0,0,100,2,9400,21400,22000,28800,11,@SPELL2,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - Combat - Cast Veil of Shadow'),
(@ENTRY,0,5,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - HP@15% - Flee for help'),
(@ENTRY,0,6,7,1,0,100,2,0,8000,12000,14000,92,0,0,1,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - OOC - interupt channeling'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - OOC - set phase 1'),
(@ENTRY,0,8,0,1,1,100,2,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - OOC - emote (phase 1)'),
(@ENTRY,0,9,10,1,1,100,2,4000,4000,4000,4000,11,@SPELL3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - OOC - Aura Shadow Channeling (phase 1)'),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Dreadweaver - OOC - set phase 0 (phase 1)');

-- Blackhand Summoner <Blackhand Legion> SAI
SET @ENTRY   := 9818;  -- NPC entry
SET @SPELL1  := 12466; -- Fireball
SET @SPELL2  := 15532; -- Frost Nova
SET @SPELL3  := 15792; -- Summon Blackhand Veteran
SET @SPELL4  := 15794; -- Summon Blackhand Dreadweaver
SET @SPELL5  := 12380; -- Shadow Channeling
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,2,0,0,0,0,58,1,@SPELL1,3600,6300,25,30,1,0,0,0,0,0,0,0, 'Blackhand Summoner - On Reset - Load caster template Cast Fireball'),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,@SPELL5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - On Reset - Aura Shadow Channeling'),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Blackhand Summoner - On Aggro - Cast Shadow Bolt'),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - On Aggro - Call for help'),
(@ENTRY,0,4,0,0,0,100,2,11400,11400,12700,16700,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - Combat - Cast Frost Nova'),
(@ENTRY,0,5,6,0,0,100,3,30000,35000,0,0,11,@SPELL3,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - Combat - Cast Summon Blackhand Veteran'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - Combat - say 0'),
(@ENTRY,0,7,8,0,0,100,3,40000,45000,0,0,11,@SPELL4,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - Combat - Cast Summon Blackhand Dreadweaver'),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - Combat - say 1'),
(@ENTRY,0,9,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - HP@15% - Flee for help'),
(@ENTRY,0,10,0,1,0,100,2,0,8000,12000,14000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - OOC - emote');
-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry`=9818;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(9818,0,0,'%s begins to summon in a Blackhand Veteran!',16,0,100,0,0,0,'Blackhand Summoner'),
(9818,1,0,'%s begins to summon in a Blackhand Dreadweaver!',16,0,100,0,0,0,'Blackhand Summoner');

-- Blackhand Veteran <Blackhand Legion> SAI
SET @ENTRY   := 9819;  -- NPC entry
SET @SPELL1  := 15749; -- Shield Charge
SET @SPELL2  := 14516; -- Strike
SET @SPELL3  := 11972; -- Shield Bash
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,2,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Blackhand Veteran - On Aggro - Cast Shield Charge'),
(@ENTRY,0,1,0,61,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Veteran - On Aggro - Call for help'),
(@ENTRY,0,2,0,0,0,100,2,7800,15800,13800,22900,11,@SPELL2,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Blackhand Veteran - Combat - Cast Veil of Shadow'),
(@ENTRY,0,3,0,0,0,100,2,10000,20000,6000,12000,11,@SPELL3,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Blackhand Veteran - Combat - Cast Veil of Shadow'),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Veteran - HP@15% - Flee for help'),
(@ENTRY,0,5,0,1,0,100,2,0,8000,12000,14000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Veteran - OOC - emote');

-- Rage Talon Dragonspawn SAI
SET @ENTRY   := 9096;  -- NPC entry
SET @SPELL1  := 15580; -- Strike
SET @SPELL2  := 12021; -- Fixate
SET @SPELL3  := 15572; -- Sunder Armor
SET @SPELL4  := 3391; -- Thrash
SET @SPELL5  := 8269; -- Frenzy
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,13200,6600,14400,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rage Talon Dragonspawn - Combat - Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,7700,17100,20300,34200,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rage Talon Dragonspawn - Combat - Cast Fixate'),
(@ENTRY,0,2,0,0,0,100,2,1400,12300,7100,11700,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rage Talon Dragonspawn - Combat - Cast Sunder Armor'),
(@ENTRY,0,3,0,0,0,100,2,8200,17100,5600,18100,11,@SPELL4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rage Talon Dragonspawn - Combat - Cast Thrash'),
(@ENTRY,0,4,5,2,0,100,2,0,30,120000,120000,11,@SPELL5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rage Talon Dragonspawn - HP@30% - Cast Frenzy'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Summoner - HP@30% - say 0');
-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry`=9096;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(9096,0,0,'%s goes into a frenzy!',16,0,100,0,0,0,'Rage Talon Dragonspawn');

 -- Scarshield Legionnaire <Scarshield Legion> SAI
SET @ENTRY   := 9097;  -- NPC entry
SET @SPELL1  := 15496; -- Cleave
SET @SPELL2  := 11972; -- Shield Bash
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarshield Legionnaire - On Aggro - Call for help'),
(@ENTRY,0,1,0,0,0,100,2,7800,11500,8000,22100,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Scarshield Legionnaire -  Combat - Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,2,4000,10000,14000,20000,11,@SPELL2,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Scarshield Legionnaire -  Combat - Cast Shield Bash');

-- Scarshield Acolyte <Scarshield Legion> SAI
SET @ENTRY   := 9045;  -- NPC entry
SET @SPELL1  := 14032; -- Shadow Word: Pain
SET @SPELL2  := 12039; -- Heal
SET @SPELL3  := 8362;  -- Renew
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarshield Acolyte - On Aggro - Call for help'),
(@ENTRY,0,1,0,0,0,100,2,7700,15700,21900,33500,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Scarshield Acolyte - Combat - Cast Shadow Word: Pain'),
(@ENTRY,0,2,0,2,0,100,3,0,75,0,0,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarshield Acolyte -  HP@75% - Cast Heal'),
(@ENTRY,0,3,0,14,0,100,2,35,8,5000,6000,11,@SPELL3,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Scarshield Acolyte -  Friendly hp@35 - Cast Renew on friendly unit');

-- Scarshield Spellbinder <Scarshield Legion> SAI
SET @ENTRY   := 9098;  -- NPC entry
SET @SPELL1  := 13748; -- Arcane Bolt
SET @SPELL2  := 15123; -- Resist Fire
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,2,0,0,0,0,58,1,@SPELL1,1100,3000,30,30,1,0,0,0,0,0,0,0, 'Scarshield Spellbinder - On Reset - Load caster template Cast Arcane Bolt'),
(@ENTRY,0,1,0,4,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarshield Spellbinder - On Aggro - Call for help'),
(@ENTRY,0,2,0,16,0,100,2,@SPELL2,30,3000,6000,11,@SPELL2,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Blackhand Summoner - Combat - Cast Resist Fire');

-- Blackhand Incarcerator SAI
SET @ENTRY   := 10316; -- NPC entry
SET @SPELL1  := 15281; -- Encage Emberseer
SET @SPELL2  := 12039; -- Heal
SET @SPELL3  := 8362;  -- Renew
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,1000,1000,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Incarcerator - OOC -  Cast Encage Emberseer'),
(@ENTRY,0,1,2,38,0,100,2,0,1,0,0,92,0,@SPELL1,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Incarcerator - On data set -  Stop Casting Encage Emberseer'),
(@ENTRY,0,2,4,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Incarcerator - On data set -  Remove unit flags'),
(@ENTRY,0,3,4,4,0,100,2,0,0,0,0,9,0,0,0,0,0,0,15,175244,100,0,0,0,0,0, 'Blackhand Incarcerator - On aggro -  close emberseer in door'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,15,175705,100,0,0,0,0,0, 'Blackhand Incarcerator - On aggro -  close doors'),
(@ENTRY,0,5,0,0,0,100,2,7800,15800,13800,22900,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Blackhand Incarcerator - Combat - Cast Strike'),
(@ENTRY,0,6,0,0,0,100,2,10000,20000,6000,12000,11,@SPELL3,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Blackhand Incarcerator - Combat - Cast Encage'),
(@ENTRY,0,7,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Incarcerator - HP@15% - Flee for help'),
(@ENTRY,0,8,0,6,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackhand Incarcerator - On death - Despawn after 10 sec');
