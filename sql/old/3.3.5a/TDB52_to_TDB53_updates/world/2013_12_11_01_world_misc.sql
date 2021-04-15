-- Bloodmaul Warlock SAI "Fixup"
SET @ENTRY := 19994;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Cast Demon Armor"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2400,3800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Warlock - Combat - Cast Shadow Bolt"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,34932,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-30% Health - Cast Bloodmaul Buzz");

-- Bladespire Mystic SAI "Two spells were missing"
SET @ENTRY := 20766;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bladespire Mystic - OOC - Cast Lightning Shield"),
(@ENTRY,0,1,0,16,0,100,0,37599,30,600000,600000,11,37599,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bladespire Mystic - OOC - Friendly in range Cast Bloodlust"),
(@ENTRY,0,2,0,74,0,100,0,0,70,7500,14000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bladespire Mystic - Friendly HP below 70% - Cast Healing Wave");

-- Wyrmcult Poacher SAI "Had no AI"
SET @ENTRY := 21809;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,10000,10000,11,37547,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmcult Poacher - Out Of Combat - Cast Wyrmcult BroodlingCall"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmcult Poacher - Combat - Cast Shoot"),
(@ENTRY,0,2,0,9,0,100,0,0,20,9000,13000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmcult Poacher - Range - Cast Net");

-- Wyrmcult Broodlings are summoned by Poachers in AI
DELETE FROM creature WHERE id=21811;

-- Wyrmcult Broodling SAI "Had no AI"
SET @ENTRY := 21811;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,34083,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmcult Broodling - Combat - Cast Fireball");

-- Remove aura from addon being applied in SAI
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=34947);
DELETE FROM `creature_template_addon` WHERE `entry`=34947;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (34947,0,1,0, '');
