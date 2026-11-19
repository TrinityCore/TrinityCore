-- [Q] Still At It
-- "Tipsy" McManus SAI
SET @ENTRY := 28566;
SET @GOSSIP := 9713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100+0,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3,@ENTRY*100+4,@ENTRY*100+5,@ENTRY*100+6,@ENTRY*100+7,@ENTRY*100+8);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP,0,0,0,80,@ENTRY*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - On gossip option select - Run script"),
(@ENTRY,0,1,0,1,1,100,0,5000,5000,11000,11000,88,@ENTRY*100+1,@ENTRY*100+5,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - After 5 Sec - Run Random Script"),
(@ENTRY,0,2,0,38,1,100,0,1,1,0,0,80,@ENTRY*100+6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - On Data Set 1 1 - Run Completion Script"),
(@ENTRY,0,3,0,1,1,100,1,103900,103900,0,0,80,@ENTRY*100+8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Call Script Quest successful (phase 1) after some time (104s=9tasks)"),
(@ENTRY,0,4,0,1,2,100,1,0,0,0,0,80,@ENTRY*100+7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Timed - Run Failure Script"),
(@ENTRY,0,5,0,1,4,100,1,8000,8000,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Timed - Set Back Gossip & Quest Flags"),
(@ENTRY,0,6,0,1,4,100,1,8010,8010,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Timed - Reset script"),
-- Start Script
(@ENTRY*100+0,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tipsy McManus - Script 0 - Close Gossip"),
(@ENTRY*100+0,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 0 - Turn of Gossip & Questgiver flags"),
(@ENTRY*100+0,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 0 - Say Text 0"),
(@ENTRY*100+0,9,3,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 0 - Set Phase 1"),
-- Wants Orange
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 1 - Say Text 1"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,12,28535,1,10000,0,0,0,8,0,0,0,5549.62354,5769.51367,-73.42824,2.75762,"Tipsy McManus - Script 1 - Summon Wants Orange"),
(@ENTRY*100+1,9,2,0,0,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 1 - set phase 2"),
-- Wants Papaya
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 2 - Say Text 2"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,12,28536,1,10000,0,0,0,8,0,0,0,5549.62354,5769.51367,-73.42824,2.75762,"Tipsy McManus - Script 2 - Summon Wants Papaya"),
(@ENTRY*100+2,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 2 - set phase 2"),
-- Wants Bananas
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 3 - Say Text 3"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,12,28537,1,10000,0,0,0,8,0,0,0,5549.62354,5769.51367,-73.42824,2.75762,"Tipsy McManus - Script 3 - Summon Wants Bananas"),
(@ENTRY*100+3,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 3 - set phase 2"),
-- Steaming Valve
(@ENTRY*100+4,9,0,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 4 - Say Text 4"),
(@ENTRY*100+4,9,1,0,0,0,100,0,0,0,0,0,12,28539,1,10000,0,0,0,8,0,0,0,5548.1,5767.4,-76.2673,-2.1293,"Tipsy McManus - Script 4 - Summon Steaming Valve"),
(@ENTRY*100+4,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 4 - set phase 2"),
-- Wants Fire
(@ENTRY*100+5,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 5 - Say Text 5"),
(@ENTRY*100+5,9,1,0,0,0,100,0,0,0,0,0,12,28540,1,10000,0,0,0,8,0,0,0,5552.58,5765.66,-78.0212,-3.00195,"Tipsy McManus - Script 5 - Summon Wants Fire"),
(@ENTRY*100+5,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 5 - Set Phase 2"),
-- Task successful
(@ENTRY*100+6,9,0,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 6 - Say Text 6"),
-- End failure
(@ENTRY*100+7,9,0,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 7 - Say Text 7"),
(@ENTRY*100+7,9,1,0,0,0,100,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 7 - Set Phase 4"),
-- Completion script
(@ENTRY*100+8,9,0,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 8 - Say Text 8"),
(@ENTRY*100+8,9,1,0,0,0,100,0,0,0,0,0,50,190643,30000,0,0,0,0,8,0,0,0,5547.13525,5767.09961,-78.025856,2.25147343,"Tipsy McManus - Script 8 - Summon Thunderbrew's Jungle Punch"),
(@ENTRY*100+8,9,2,0,0,0,100,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 8 - Set Phase 4");


-- NPC talk text for "Tipsy" McManus
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Beginning the distillation in 5 seconds.",12,0,100,0,0,0,"Tipsy McManus"),
(@ENTRY,1,0,"Add another orange, quickly!",12,0,100,25,0,0,"Tipsy McManus"),
(@ENTRY,2,0,"Put a papaya in the still!",12,0,100,25,0,0,"Tipsy McManus"),
(@ENTRY,3,0,"Add bananas!",12,0,100,25,0,0,"Tipsy McManus"),
(@ENTRY,4,0,"Pressure's too high! Open the pressure valve!",12,0,100,5,0,0,"Tipsy McManus"),
(@ENTRY,5,0,"The still needs heat! Light the brazier!",12,0,100,5,0,0,"Tipsy McManus"),
(@ENTRY,6,0,"Good job! Keep your eyes open, now.",12,0,100,4,0,0,"Tipsy McManus"),
(@ENTRY,6,1,"That'll do. Never know what it'll need next...",12,0,100,4,0,0,"Tipsy McManus"),
(@ENTRY,6,2,"Nicely handled! Stay on your toes!",12,0,100,4,0,0,"Tipsy McManus"),
(@ENTRY,6,3,"Well done! Be ready for anything!",12,0,100,4,0,0,"Tipsy McManus"),
(@ENTRY,7,0,"It's no good! I'm shutting it down...",12,0,100,0,0,0,"Tipsy McManus"),
(@ENTRY,8,0,"We've done it! Come get the cask.",12,0,100,0,0,0,"Tipsy McManus");

-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(@GOSSIP,0,0,"I'm ready to start the distillation, uh, Tipsy.",1,1);

-- Add gossip_menu_option condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(15,@GOSSIP,0,9,12644); -- Quest "Still At It" Has to be active and incomplete

-- Update creature_template for Wants XX targets
UPDATE `creature_template` SET `minlevel`=70,`maxlevel`=70,`exp`=2,`unit_class`=2,`unit_flags`=`unit_flags`|33554432,`flags_extra`=`flags_extra`|128,`InhabitType`=4,`family`=23,`type`=3 WHERE `entry` IN (28535,28536,28537,28539,28540);

-- Wants Orange SAI
SET @ENTRY := 28535;
SET @SPELL_ORANGE := 51931;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_ORANGE,0,0,0,45,1,1,0,0,0,0,19,28566,0,0,0,0,0,0,"Wants Orange - On Spellhit - Set Data McManus");

-- Wants Papaya SAI
SET @ENTRY := 28536;
SET @SPELL_PAPAYA := 51933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_PAPAYA,0,0,0,45,1,1,0,0,0,0,19,28566,0,0,0,0,0,0,"Wants Papaya - On Spellhit - Set Data McManus");

-- Wants Bananas SAI
SET @ENTRY := 28537;
SET @SPELL_BANANAS := 51932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_BANANAS,0,0,0,45,1,1,0,0,0,0,19,28566,0,0,0,0,0,0,"Wants Bananas - On Spellhit - Set Data McManus");

-- Steam Valve SAI
SET @ENTRY := 28539;
SET @SPELL_STEAM_BLAST := 51920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,@SPELL_STEAM_BLAST,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steam Valve - Out Of Combat - Cast Cosmetic Steam Blast"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,28566,0,0,0,0,0,0,"Steam Valve - On Death - Set Data McManus");

-- Pressure Valve SAI
SET @ENTRY := 190635;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,64,0,100,0,500,500,0,0,51,0,0,0,0,0,0,19,28539,0,0,0,0,0,0,"Pressure Valve - On Gossip Hello - Kill Steam Valve");

-- Wants Fire SAI
SET @ENTRY := 28540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,28566,0,0,0,0,0,0,"Wants Fire - On Death - Set Data McManus");

-- Brazier SAI
SET @ENTRY := 190636;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,64,0,100,0,500,500,0,0,51,0,0,0,0,0,0,19,28540,0,0,0,0,0,0,"Brazier - On Gossip Hello - Kill Wants Fire");

-- Add Spell Targets
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (51931,51932,51933);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13,51931,18,1,28535), -- Toss Orange requires target Wants Orange
(13,51931,18,1,28536), -- Toss Orange requires target Wants Papaya
(13,51931,18,1,28537), -- Toss Orange requires target Wants Bananas
(13,51933,18,1,28535), -- Toss Papaya requires target Wants Orange
(13,51933,18,1,28536), -- Toss Papaya requires target Wants Papaya
(13,51933,18,1,28537), -- Toss Papaya requires target Wants Bananas
(13,51932,18,1,28535), -- Toss Bananas requires target Wants Orange
(13,51932,18,1,28536), -- Toss Bananas requires target Wants Papaya
(13,51932,18,1,28537); -- Toss Bananas requires target Wants Bananas
