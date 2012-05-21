-- Forge of Souls Trash update

-- Npc Updates

-- Spiteful Apparition
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=36551;
UPDATE `creature` SET `spawndist`=20,`MovementType`=1,`curhealth`=1,`curmana`=0 WHERE `id`=36551;
DELETE FROM `creature_template_addon` WHERE `entry`=36551;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (36551,1, '69105 69136');
-- Spiteful Apparition (Ambient)
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=36967;
UPDATE `creature` SET  `spawndist`=20,`MovementType`=1,`curhealth`=1,`curmana`=0 WHERE `id`=36967;
DELETE FROM `creature_template_addon` WHERE `entry`=36967;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (36967,1, '69663 69658');
-- Spectral Warden
UPDATE `creature_addon` SET `auras`='69144' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=36666);

-- SAI Updates

-- Spiteful Apparition SAI
SET @ENTRY   := 36551; -- NPC entry
SET @SPELL1  := 41253; -- Greater Invisibility
SET @SPELL2  := 68895; -- Spite (Normal)
SET @SPELL3  := 70212; -- Spite (Heroic)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Spiteful Apparition - On Reset - Cast Greater Invisibility'),
(@ENTRY,0,1,0,10,0,100,6,0,10,3000,4000,28,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Spiteful Apparition - OOC range - Remove Greater Invisibility'),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,7000,9000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spiteful Apparition - Combat - Cast Spite "Normal"'),
(@ENTRY,0,3,0,0,0,100,4,7000,9000,7000,9000,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spiteful Apparition - Combat - Cast Spite "Heroic"');

-- Soulguard Reaper SAI
SET @ENTRY   := 36499; -- NPC entry
SET @SPELL1  := 68797; -- Soulguard Channel
SET @SPELL2  := 69058; -- Shadow Lance
SET @SPELL3  := 69060; -- Frost Nova (Normal)
SET @SPELL4  := 70209; -- Frost Nova (Heroic)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Reaper - OOC - Cast Soulguard Channel'),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,7000,9000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Reaper - Combat - Cast Shadow Lance'),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,8000,10000,11,@SPELL3,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Soulguard Reaper - Combat - Cast Frost Nova "Normal"'),
(@ENTRY,0,3,0,0,0,100,4,7000,9000,8000,10000,11,@SPELL4,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Soulguard Reaper - Combat - Cast Frost Nova "Heroic"'),
(@ENTRY,0,4,0,4,0,100,6,0,0,0,0,39,30,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Reaper - Aggro - Call for help');

-- Soulguard Beam Focus Target
SET @ENTRY   := 36508; -- NPC entry
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-201770,-201785,-201741);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-201770,0,0,0,1,0,100,6,1000,1000,5000,5000,45,0,1,0,0,0,0,19,36620,60,0,0,0,0,0, 'Soulguard Beam Focus Target - OOC - Set data on Soulguard Adept'),
(-201785,0,0,0,1,0,100,6,1000,1000,5000,5000,45,0,1,0,0,0,0,19,36620,60,0,0,0,0,0, 'Soulguard Beam Focus Target - OOC - Set data on Soulguard Adept'),
(-201741,0,0,0,1,0,100,6,1000,1000,5000,5000,45,0,1,0,0,0,0,19,36620,60,0,0,0,0,0, 'Soulguard Beam Focus Target - OOC - Set data on Soulguard Adept'),
(-201741,0,1,0,1,0,100,6,1000,1000,5000,5000,45,0,1,0,0,0,0,19,36564,60,0,0,0,0,0, 'Soulguard Beam Focus Target - OOC - Set data on Soulguard Bonecaster');

-- Spectral Warden SAI
SET @ENTRY   := 36666; -- NPC entry
SET @SPELL1  := 69633; -- Veil of Shadow
SET @SPELL2  := 69148; -- Wail of Souls (Normal)
SET @SPELL3  := 70210; -- Wail of Souls (Heroic)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,9000,10000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spectral Warden - Combat - Cast Veil of Shadow'),
(@ENTRY,0,1,0,0,0,100,2,9000,11000,5000,6000,11,@SPELL1,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Spectral Warden - Combat - Cast Wail of Souls'),
(@ENTRY,0,2,0,0,0,100,4,9000,11000,5000,6000,11,@SPELL2,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Spectral Warden - Combat - Cast Wail of Souls');

-- Soulguard Watchman SAI
SET @ENTRY   := 36478; -- NPC entry
SET @SPELL1  := 69056; -- Shroud of Runes
SET @SPELL2  := 69053; -- Unholy Rage
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,6,0,10000,16000,20000,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Watchman - Combat - Cast Shroud of Runes'),
(@ENTRY,0,1,2,0,0,100,6,8000,16000,32000,40000,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Watchman - Combat - Cast Unholy Rage'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Watchman - Combat - Say 0'),
(@ENTRY,0,3,0,4,0,100,6,0,0,0,0,39,20,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Watchman - Aggro - Call for help');
-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Soulguard Watchman');

-- Soul Horror SAI
SET @ENTRY   := 36522; -- NPC entry
SET @SPELL1  := 69088; -- Soul Strike (Normal)
SET @SPELL2  := 70211; -- Soul Strike (Heroic)
SET @SPELL3  := 69107; -- Killing Spree Invis Aura
SET @SPELL4  := 69106; -- Killing Spree Aura
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6000,5000,6000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soul Horror - Combat - Cast Soul Strike'),
(@ENTRY,0,1,0,0,0,100,4,5000,6000,5000,6000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soul Horror - Combat - Cast Soul Strike'),
(@ENTRY,0,4,0,4,0,100,6,0,0,0,0,39,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soul Horror - Aggro - Call for help');

-- Soulguard Animator SAI
SET @ENTRY   := 36516; -- NPC entry
SET @SPELL1  := 68834; -- Soulguard Channel Beam02
SET @SPELL2  := 69562; -- Raise Dead
SET @SPELL3  := 69131; -- Soul Sickness
SET @SPELL4  := 69128; -- Soul Siphon
SET @SPELL5  := 69068; -- Shadow Bolt (Normal)
SET @SPELL6  := 70208; -- Shadow Bolt (Heroic)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,1000,1000,11,@SPELL1,0,0,0,0,0,9,36522,1,15,0,0,0,0, 'Soulguard Animator - OOC - Cast Soulguard Channel Beam02'),
(@ENTRY,0,1,0,0,1,100,6,20000,25000,20000,25000,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Combat - Cast Raise Dead'),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,9000,11000,11,@SPELL3,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Soulguard Animator - Combat - Cast Soul Sickness'),
(@ENTRY,0,3,0,0,0,100,6,9000,11000,7000,9000,11,@SPELL4,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Soulguard Animator - Combat - Cast Soul Siphon'),
(@ENTRY,0,4,0,0,0,100,2,4000,5000,3500,4500,11,@SPELL5,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Animator - Combat - Cast Shadow Bolt "Normal"'),
(@ENTRY,0,5,0,0,0,100,4,4000,5000,3500,4500,11,@SPELL6,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Animator - Combat - Cast Shadow Bolt "Heroic"'),
(@ENTRY,0,6,7,4,0,100,6,0,0,0,0,39,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Aggro - Call for help'),
(@ENTRY,0,7,0,61,0,100,6,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Aggro - Set phase 1'),
(@ENTRY,0,8,9,38,0,100,7,0,2,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Data set 2 - Set data'),
(@ENTRY,0,9,0,61,0,100,6,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Data set 2 - Set phase 2'),
(@ENTRY,0,10,11,38,0,100,7,0,3,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Data set 3 - Set data'),
(@ENTRY,0,11,0,61,0,100,6,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Animator - Data set 3 - Set phase 1');

-- Soulguard Adept SAI
SET @ENTRY   := 36620; -- NPC entry
SET @SPELL1  := 68834; -- Soulguard Channel Beam02
SET @SPELL2  := 69562; -- Raise Dead
SET @SPELL3  := 69068; -- Shadow Bolt (Normal)
SET @SPELL4  := 70208; -- Shadow Bolt (Heroic)
SET @SPELL5  := 69066; -- Drain Life (Normal)
SET @SPELL6  := 70213; -- Drain Life (Heroic)
SET @SPELL7  := 69564; -- Shadow Mend (Normal)
SET @SPELL8  := 70205; -- Shadow Mend (Heroic)
SET @SPELL9  := 68797; -- Soulguard Channel
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,1000,1000,11,@SPELL1,0,0,0,0,0,9,36522,1,15,0,0,0,0, 'Soulguard Adept - OOC - Cast Soulguard Channel Beam02'),
(@ENTRY,0,1,0,0,4,100,6,20000,25000,20000,25000,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Raise Dead'),
(@ENTRY,0,2,0,0,0,100,2,7000,8000,3500,4500,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Shadow Bolt "Normal"'),
(@ENTRY,0,3,0,0,0,100,4,7000,8000,3500,4500,11,@SPELL4,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Shadow Bolt "Heroic"'),
(@ENTRY,0,4,0,0,0,100,2,6000,7000,8000,10000,11,@SPELL5,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Drain Life "Normal"'),
(@ENTRY,0,5,0,0,0,100,4,6000,7000,8000,10000,11,@SPELL6,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Drain Life "Heroic"'),
(@ENTRY,0,6,0,0,0,100,2,30000,35000,18000,22000,11,@SPELL7,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Shadow Mend "Normal"'),
(@ENTRY,0,7,0,0,0,100,4,30000,35000,18000,22000,11,@SPELL8,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Adept - Combat - Cast Shadow Mend "Heroic"'),
(@ENTRY,0,8,0,25,0,100,6,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - On Reset - Set phase 1'),
(@ENTRY,0,9,0,38,1,100,6,0,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - On dataset 0 1 - Set phase 2'),
(@ENTRY,0,10,0,1,2,100,7,0,0,0,0,11,@SPELL9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - OOC - Cast Soulguard Channel'),
(@ENTRY,0,11,12,4,0,100,6,0,0,0,0,39,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Aggro - Call for help'),
(@ENTRY,0,12,0,61,0,100,6,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Aggro - Set phase 3'),
(@ENTRY,0,13,14,38,0,100,7,0,2,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Data set 2 - Set data'),
(@ENTRY,0,14,0,61,0,100,6,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Data set 2 - Set phase 4'),
(@ENTRY,0,15,16,38,0,100,7,0,3,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Data set 3 - Set data'),
(@ENTRY,0,16,0,61,0,100,6,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Adept - Data set 3 - Set phase 3');

-- Soulguard Bonecaster SAI
SET @ENTRY   := 36564; -- NPC entry
SET @SPELL1  := 68834; -- Soulguard Channel Beam02
SET @SPELL2  := 69562; -- Raise Dead
SET @SPELL3  := 69080; -- Bone Volley (Normal)
SET @SPELL4  := 70206; -- Bone Volley (Heroic)
SET @SPELL5  := 69069; -- Shield of Bones (Normal)
SET @SPELL6  := 70207; -- Shield of Bones (Heroic)
SET @SPELL7  := 68797; -- Soulguard Channel
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,1000,1000,11,@SPELL1,0,0,0,0,0,9,36522,1,15,0,0,0,0, 'Soulguard Bonecaster - OOC - Cast Soulguard Channel Beam02'),
(@ENTRY,0,1,0,0,4,100,6,20000,25000,20000,25000,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Combat - Cast Raise Dead'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,6000,8000,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Combat - Cast Bone Volley "Normal"'),
(@ENTRY,0,3,0,0,0,100,4,5000,7000,6000,8000,11,@SPELL4,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Combat - Cast Bone Volley "Heroic"'),
(@ENTRY,0,4,0,0,0,100,2,5000,7000,7000,9000,11,@SPELL5,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Combat - Cast Shield of Bones "Normal"'),
(@ENTRY,0,5,0,0,0,100,4,5000,7000,7000,9000,11,@SPELL6,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Combat - Cast Shield of Bones "Heroic"'),
(@ENTRY,0,6,0,25,0,100,6,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - On Reset - Set phase 1'),
(@ENTRY,0,7,0,38,1,100,6,0,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - On dataset 0 1 - Set phase 2'),
(@ENTRY,0,8,0,1,2,100,7,0,0,0,0,11,@SPELL7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - OOC - Cast Soulguard Channel'),
(@ENTRY,0,9,10,4,0,100,6,0,0,0,0,39,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Aggro - Call for help'),
(@ENTRY,0,10,0,61,0,100,6,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Aggro - Set phase 3'),
(@ENTRY,0,11,12,38,0,100,7,0,2,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Data set 2 - Set data'),
(@ENTRY,0,12,0,61,0,100,6,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Data set 2 - Set phase 4'),
(@ENTRY,0,13,14,38,0,100,7,0,3,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Data set 3 - Set data'),
(@ENTRY,0,14,0,61,0,100,6,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Soulguard Bonecaster - Data set 3 - Set phase 3');

-- Ghoul Minion SAI
SET @ENTRY   := 36916; -- NPC entry
SET @SPELL1  := 69088; -- Soul Strike (Normal)
SET @SPELL2  := 70211; -- Soul Strike (Heroic)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,6,0,0,0,0,45,0,2,0,0,0,0,23,0,0,0,0,0,0,0, 'Ghoul Minion - Just Summoned - Set Data Summoner'),
(@ENTRY,0,1,0,61,0,100,6,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ghoul Minion - Just Summoned - Set Random Movement'),
(@ENTRY,0,2,0,0,0,100,6,115000,115000,115000,115000,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ghoul Minion - combat - die after 2 min'),
(@ENTRY,0,3,0,1,0,100,6,15000,15000,15000,15000,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ghoul Minion - OOC - die after 15 sec'),
(@ENTRY,0,4,5,6,0,100,6,15000,15000,15000,15000,45,0,3,0,0,0,0,23,0,0,0,0,0,0,0, 'Ghoul Minion - on Death - Set data summoner'),
(@ENTRY,0,5,0,61,0,100,6,15000,15000,15000,15000,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ghoul Minion - on Death - despawn after 3 sec');
