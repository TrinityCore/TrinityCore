-- Focus Wizard fix flags
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~536870912 WHERE `entry`=26816;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~262144 WHERE `entry`=26816;
-- Focus Wizard SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26816;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26816;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26816,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,1,0,0,0,0,11,23837,15,0,0,0,0,0,'Focus Wizard - On reset - Cast Surge Needle Beam'),
(26816,0,1,0,4,0,100,0,0,0,0,0,11,51777,3,0,0,0,0,1,0,0,0,0,0,0,0,'Focus Wizard - On aggro - Aura Arcane Focus'),
(26816,0,2,0,0,0,100,0,0,0,3000,3000,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,'Focus Wizard - Combat - Cast Frostfire Bolt on victim');

-- Rotting Storm Giant SAI 
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=27270;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-108034,-108035,-108036,-108037,-203372,-203373);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-108034,0,0,1,1,0,100,1,1000,1000,1000,1000,11,50389,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108034,0,1,0,61,0,100,1,0,0,0,0,11,50390,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108034,0,2,3,4,0,100,0,0,0,0,0,28,50389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108034,0,3,0,61,0,100,0,0,0,0,0,28,50390,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108035,0,0,1,1,0,100,1,1000,1000,1000,1000,11,50389,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108035,0,1,0,61,0,100,1,0,0,0,0,11,50390,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108035,0,2,3,4,0,100,0,0,0,0,0,28,50389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108035,0,3,0,61,0,100,0,0,0,0,0,28,50390,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108036,0,0,1,1,0,100,1,1000,1000,1000,1000,11,50389,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108036,0,1,0,61,0,100,1,0,0,0,0,11,50390,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108036,0,2,3,4,0,100,0,0,0,0,0,28,50389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108036,0,3,0,61,0,100,0,0,0,0,0,28,50390,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108037,0,0,1,1,0,100,1,1000,1000,1000,1000,11,50389,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108037,0,1,0,61,0,100,1,0,0,0,0,11,50390,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-108037,0,2,3,4,0,100,0,0,0,0,0,28,50389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-108037,0,3,0,61,0,100,0,0,0,0,0,28,50390,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-203372,0,0,1,1,0,100,1,1000,1000,1000,1000,11,50389,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-203372,0,1,0,61,0,100,1,0,0,0,0,11,50390,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-203372,0,2,3,4,0,100,0,0,0,0,0,28,50389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-203372,0,3,0,61,0,100,0,0,0,0,0,28,50390,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-203373,0,0,1,1,0,100,1,1000,1000,1000,1000,11,50389,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-203373,0,1,0,61,0,100,1,0,0,0,0,11,50390,1,0,0,0,0,1,0,0,0,0,0,0,0,'Rotting Storm Giant - On reset - Cast Flesh Construct Test'),
(-203373,0,2,3,4,0,100,0,0,0,0,0,28,50389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test'),
(-203373,0,3,0,61,0,100,0,0,0,0,0,28,50390,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rotting Storm Giant - On Aggro - Remove Flesh Construct Test');
-- Remove auras from creature addon
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (108034,108035,108036,108037,203372,203373);

-- Unbound Trickster SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=30856;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=30856;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=30856;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30856,0,0,0,0,0,100,0,5000,9000,9000,12000,11,13341,1,0,0,0,0,2,0,0,0,0,0,0,0,'Unbound Trickster - Combat - Cast Fire Blast'),
(30856,0,1,0,0,0,100,0,5000,9000,9000,12000,11,11976,1,0,0,0,0,2,0,0,0,0,0,0,0,'Unbound Trickster - Combat - Cast Strike');

-- SAI for Invisible Location Trigger
SET @ENTRY := 19656;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-70100,-70101,-70104,-70104);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-70100,0,0,0,1,0,100,1,1000,1000,1000,1000,11,33346,2,0,0,0,0,10,70102,@ENTRY,0,0,0,0,0,'Invisible Location Trigger - OOC once - Cast Green Beam on target'),
(-70101,0,0,0,1,0,100,1,1000,1000,1000,1000,11,33346,2,0,0,0,0,10,70102,@ENTRY,0,0,0,0,0,'Invisible Location Trigger - OOC once - Cast Green Beam on target'),
(-70103,0,0,0,1,0,100,1,1000,1000,1000,1000,11,33346,2,0,0,0,0,10,70102,@ENTRY,0,0,0,0,0,'Invisible Location Trigger - OOC once - Cast Green Beam on target'),
(-70104,0,0,0,1,0,100,1,1000,1000,1000,1000,11,33346,2,0,0,0,0,10,70102,@ENTRY,0,0,0,0,0,'Invisible Location Trigger - OOC once - Cast Green Beam on target');

-- SAI for Fulgorge
SET @ENTRY := 18678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `spawndist`=20,`MovementType`=1 WHERE `id`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,11,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - OOC - Cast Submerge Visual'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - OOC - Set Unselectable and Unattackable Flags'),
(@ENTRY,0,2,3,0,0,100,1,0,0,0,0,28,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Remove Submerge Visual'),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Remove Unselectable and Unattackable Flags'),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Set Phase 1'),
(@ENTRY,0,6,7,0,1,100,0,1000,1000,2100,4500,11,31747,1,0,0,0,0,2,0,0,0,0,0,0,0,'Fulgorge - Combat - Cast Poison (Phase 1)'),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - Combat - Prevent Combat Movement (Phase 1)'),
(@ENTRY,0,8,0,0,1,100,0,20400,20400,45000,50000,11,32738,1,0,0,0,0,2,0,0,0,0,0,0,0,'Fulgorge - Combat - Cast Bore (Phase 1)'),
(@ENTRY,0,9,10,9,1,100,0,20,60,0,0,11,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 20 - 60 Yards Range - Cast Submerge Visual (Phase 1)'),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 20 - 60 Yards Range - Set Phase 2 (Phase 1)'),
(@ENTRY,0,11,12,9,2,100,0,0,8,0,0,28,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 0 - 8 Yards - Remove Submerge Visual (Phase 2)'),
(@ENTRY,0,12,13,61,2,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - Combat - Prevent Combat Movement (Phase 2)'),
(@ENTRY,0,13,14,61,2,100,0,0,8,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 0 - 8 Yards - Remove Unselectable and Unattackable Flags (Phase 2)'),
(@ENTRY,0,14,0,61,2,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 20 - 60 Yards Range - Set Phase 1 (Phase 2)');

UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=26917;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=38017 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4625 AND `id`=1;

-- SAI for Beryl Hound
SET @ENTRY := 25355;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,50637,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Beryl Hound - On spawn - Cast Mana Break on self');

-- SAI for Tundra Penguin
SET @ENTRY := 28440;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,51583,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tundra Penguin - On spawn - Cast [DND] Creature Random Size (0 - 50) on self');

-- SAI for Spearfang Worg
SET @ENTRY := 24677;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,44366,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Spearfang Worg - On spawn - Cast Howling Fjord - Quest - Predator Dummy Periodic on self');

-- SAI for Scourging Crystal
SET @ENTRY := 24464;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,43874,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scourging Crystal - On spawn - Cast Scourge Mur''gul Camp: Force Shield Arcane Purple x3 on self');

-- SAI for Moa'ki Bottom Thresher
SET @ENTRY := 26511;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moa''ki Bottom Thresher - On spawn - Cast Thrash on self');

-- SAI for Tuskarr Turtle Rider
SET @ENTRY := 29953;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,55587,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tuskarr Turtle Rider - On spawn - Cast Tuskarr Turtle Rider CustomSpell01 on self');

-- SAI for Snowfall Glade Reaver
SET @ENTRY := 26197;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,15088,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Snowfall Glade Reaver - On spawn - Cast Flurry on self');

-- SAI for Conquest Hold Berserker
SET @ENTRY := 27500;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,15088,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Conquest Hold Berserker - On spawn - Cast Flurry on self'),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,12000,20000,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Conquest Hold Berserker - Combat - Cast Battle Shout on self');

-- SAI for Indu'le Fisherman
SET @ENTRY := 26343;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,32423,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Indu''le Fisherman - On spawn - Cast Blue Radiation on self');

-- SAI for Vengeful Taunka Spirit
SET @ENTRY := 25668;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,46695,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Vengeful Taunka Spirit - On spawn - Cast Soul Separation on self');

-- SAI for Steam Frog
SET @ENTRY := 25679;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,36151,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Steam Frog - On spawn - Cast Cosmetic: Steam Aura on self');

-- SAI for Steam Rager
SET @ENTRY := 24601;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,36151,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Steam Rager - On spawn - Cast Cosmetic: Steam Aura on self'),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,11000,14000,11,50375,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Steam Rager - Combat - Cast Steam Blast on victom');

-- SAI for Big Electromental Flavor
SET @ENTRY := 21757;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,37248,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Big Electromental Flavor - On spawn - Cast Power Converters: Electromental Visual on self');
