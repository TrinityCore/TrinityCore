-- SAI for Mummified Atal''ai
SET @ENTRY := 5263;
UPDATE `smart_scripts` SET `event_flags`=2 WHERE `entryorguid`=5263  AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,8000,15000,4000,10000,11,16186,32,0,0,0,0,2,0,0,0,0,0,0,0,'Mummified Atal''ai - In Combat - Cast Fevered Plague');

UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid` IN (824,5243);
UPDATE `smart_scripts` SET `event_flags`=0 WHERE `entryorguid` IN (5261);

DELETE FROM `linked_respawn` WHERE `guid` IN (83022,83027,83023,83026);

-- Winterskorn Tribesman SAI
SET @ENTRY := 23661;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Tribesman - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Woodsman SAI
SET @ENTRY := 23662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Woodsman - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Shield-Maiden SAI
SET @ENTRY := 23663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Shield-Maiden - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Warrior SAI
SET @ENTRY := 23664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Warrior - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Warrior - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Raider SAI
SET @ENTRY := 23665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Raider - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Raider - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Berserker SAI
SET @ENTRY := 23666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Berserker - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Berserker - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Rune-Seer SAI
SET @ENTRY := 23667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Seer - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Rune-Caster SAI
SET @ENTRY := 23668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Rune-Caster - On Spellhit Dismembering Corpse - Set Phase 2");

-- Winterskorn Oracle SAI
SET @ENTRY := 23669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Respawn - Set Phase 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,43059,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Respawn - Remove Aura Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Death - Set Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,43036,0,0,0,11,43059,16,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Vrykul On Dismember"),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,11,43037,16,0,0,0,0,7,0,0,0,0,0,0,0,"Winterskorn Oracle - On Spellhit Dismembering Corpse - Cast Gruesome, But Necessary: Kill Credit"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Oracle - On Spellhit Dismembering Corpse - Set Phase 2");

-- Illidari Heartseeker SAI
SET @ENTRY := 23339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,41169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,1,100,2,5,30,3900,5900,11,41169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,1,100,3,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,1,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,2,7000,11000,19000,25000,11,41173,1,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat - Cast Rapid Shot"),
(@ENTRY,0,14,0,0,0,100,2,45000,60000,60000,75000,11,41171,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat - Cast Skeleton Shot"),
(@ENTRY,0,15,0,2,0,100,3,0,50,0,0,11,41170,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - At 50% HP - Cast Curse of the Bleakheart"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - On Evade - Display melee weapon");

-- Ashtongue Stormcaller SAI
SET @ENTRY := 22846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,39534,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - Out Of Combat - Cast Summon Storm Fury"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,41151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - On Aggro - Cast Lightning Shield"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Stormcaller - On Aggro - Cast Fireball"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3800,5200,11,41184,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At Mana +30% - Decrement Phase"),
(@ENTRY,0,12,0,0,0,100,2,12000,18000,22000,28000,11,41183,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ashtongue Stormcaller - In Combat - Cast Chain Lightning");

-- Sandfury Acolyte SAI
SET @ENTRY := 8876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - On Respawn - Set Ranged Movement"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,1,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 5 - 15 Range - Set Ranged Movement"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 30% Mana - Decrement Phase"),
(@ENTRY,0,10,0,0,0,100,2,8000,10000,25000,31000,11,11639,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,11,0,0,0,100,2,4000,6000,120000,135000,11,11980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,12,0,0,0,100,2,5000,6000,15000,22000,11,11981,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast Mana Burn");

-- Oro Eyegouge SAI
SET @ENTRY := 7606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - On Respawn - Set Ranged Movement"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Cast Curse of Weakness"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,1,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 5 - 15 Range - Set Ranged Movement"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 30% Mana - Decrement Phase"),
(@ENTRY,0,11,0,0,0,80,2,5000,7000,23000,27000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat - Cast Immolate"),
(@ENTRY,0,12,0,0,0,80,2,8000,10000,15000,18250,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat - Cast Rain of Fire");

-- Sandfury Shadowhunter SAI
SET @ENTRY := 7246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowhunter - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,2,7000,12000,18000,25000,11,11641,1,0,0,0,0,6,0,0,0,0,0,0,0,"Sandfury Shadowhunter - In Combat - Cast Hex"),
(@ENTRY,0,14,0,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,2,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,2,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,2,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - On Evade - Display melee weapon");

-- Sandfury Shadowcaster SAI
SET @ENTRY := 5648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - Out Of Combat - Cast Demon Skin"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,1,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 30% Mana - Decrement Phase"),
(@ENTRY,0,11,0,0,0,100,2,6000,9000,23000,28000,11,14032,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sandfury Shadowcaster - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,12,0,2,2,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,2,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% HP - Flee For Assist");

-- Druid of the Fang SAI
SET @ENTRY := 3840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Fang - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Fang - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,1,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,0,1,100,2,8000,11000,10000,20000,11,8040,33,0,0,0,0,6,0,0,0,0,0,0,0,"Druid of the Fang - In Combat - Cast Druid's Slumber"),
(@ENTRY,0,10,0,14,1,100,2,0,40,12000,18000,11,5187,1,0,0,0,0,7,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Unit At 0 - 40% Health - Cast Healing Touch"),
(@ENTRY,0,11,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 30% Mana - Decrement Phase"),
(@ENTRY,0,12,13,2,0,100,2,0,50,20000,25000,11,8041,1,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 50% HP - Cast Serpent Form"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 50% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 50% HP - Set Phase 3"),
(@ENTRY,0,15,16,16,0,100,2,8041,5,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Buff Missing - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Buff Missing - Set Phase 1");

-- Ymirjar Necromancer SAI
SET @ENTRY := 28368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,51432,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer (Normal) - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer (Normal) - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,2,0,40,5000,7000,11,51432,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer (Normal) - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,59254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer (Heroic) - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer (Heroic) - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,1,100,4,0,40,5000,7000,11,59254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer (Heroic) - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,8,9,3,1,100,6,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% Mana - Decrement Phase"),
(@ENTRY,0,14,0,0,0,100,2,9000,14000,18000,22000,11,49205,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer (Normal) - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,15,0,0,0,100,4,9000,14000,18000,22000,11,59255,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer (Heroic) - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,16,0,2,0,100,7,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% HP - Set Phase 3"),
(@ENTRY,0,17,18,2,4,100,6,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% HP - Flee For Assist");

-- Ymirjar Flesh Hunter SAI
SET @ENTRY := 26670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,6,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,15,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - On Aggro - Cast Shoot"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,1,100,2,5,30,5000,8000,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,4,0,100,5,0,0,0,0,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - On Aggro - Cast Shoot"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - On Aggro - Increment Phase"),
(@ENTRY,0,9,10,9,1,100,4,5,30,5000,8000,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,11,12,9,1,100,6,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,1,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,16,17,9,1,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,18,19,0,0,100,2,9000,14000,22000,26000,11,48871,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - In Combat - Cast Aimed Shot"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - In Combat - Display ranged weapon"),
(@ENTRY,0,20,21,0,0,100,4,9000,14000,22000,26000,11,59243,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - In Combat - Cast Aimed Shot"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - In Combat - Display ranged weapon"),
(@ENTRY,0,22,23,0,0,100,2,14000,17000,24000,27000,11,48872,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - In Combat - Cast Multi-Shot"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Normal) - In Combat - Display ranged weapon"),
(@ENTRY,0,24,25,0,0,100,4,14000,17000,24000,27000,11,59244,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - In Combat - Cast Multi-Shot"),
(@ENTRY,0,25,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter (Heroic) - In Combat - Display ranged weapon"),
(@ENTRY,0,26,0,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 15% HP - Increment Phase"),
(@ENTRY,0,27,28,2,2,100,6,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,28,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,29,0,7,0,100,6,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Evade - Display melee weapon");

-- Dragonflayer Seer SAI
SET @ENTRY := 26554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,6,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,48698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer (Normal) - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer (Normal) - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,2,0,40,7000,11000,11,48698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer (Normal) - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,59081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer (Heroic) - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer (Heroic) - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,1,100,4,0,40,7000,11000,11,59081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer (Heroic) - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,8,9,3,1,100,6,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 15% Mana - Decrement Phase"),
(@ENTRY,0,14,0,0,0,100,2,4000,7000,12000,15000,11,48699,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Seer (Normal) - In Combat - Cast Chain Lightning"),
(@ENTRY,0,15,0,0,0,100,4,4000,7000,12000,15000,11,59082,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Seer (Heroic) - In Combat - Cast Chain Lightning"),
(@ENTRY,0,16,0,14,0,100,2,0,30,18000,21000,11,48700,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Seer (Normal) - On Friendly Unit At 0 - 30% Health - Cast Healing Wave"),
(@ENTRY,0,17,0,14,0,100,4,0,30,18000,21000,11,59083,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Seer (Heroic) - On Friendly Unit At 0 - 30% Health - Cast Healing Wave");

-- Dark Rune Shaper SAI
SET @ENTRY := 27965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,51496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper (Normal) - On Aggro - Cast Chiseling Ray"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper (Normal) - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,1,100,2,0,40,6000,9000,11,51496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper (Normal) - At 0 - 40 Range - Cast Chiseling Ray"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,59034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper (Heroic) - On Aggro - Cast Chiseling Ray"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper (Heroic) - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,1,100,4,0,40,6000,9000,11,59034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper (Heroic) - At 0 - 40 Range - Cast Chiseling Ray"),
(@ENTRY,0,8,9,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 15% Mana - Decrement Phase");
