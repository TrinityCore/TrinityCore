-- [Q] Maintaining Discipline

-- Exhausted Vrykul SAI
SET @ENTRY := 30146;
SET @SPELL_DESPERATE_BLOW := 57395;
SET @SPELL_DISCIPLINING_ROD := 42837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100+0,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - Out of Combat - Set Bytes1 Sit"), -- Not doing this in creature_addon(_template) so that we can cancel this in SAI
(@ENTRY,0,1,2,8,0,100,0,@SPELL_DISCIPLINING_ROD,0,0,0,87,@ENTRY*100+0,@ENTRY*100+1,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Spellhit - Run Random Script"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Spellhit - Set Phase 1"), -- To prevent the same one to give more credits
(@ENTRY*100+0,9,0,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Attack Player"),
(@ENTRY*100+0,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Say Line 0 (random)"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Say Line 1 (random)"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,91,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Stand Up"),
(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,5,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Emote Work"),
(@ENTRY*100+1,9,3,0,0,0,100,0,0,0,0,0,33,29886,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Kill Credit"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,11,@SPELL_DESPERATE_BLOW,0,0,0,0,0,2,0,0,0,0,0,0,0,"Exhausted Vrykul - At 15% HP - Cast Desperate Blow");

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Curse you! You will not treat me like a beast!",12,0,100,1,0,0,"Exhausted Vrykul"),
(@ENTRY,0,1,"Enough! I will teach you some manners, wench!",12,0,100,1,0,0,"Exhausted Vrykul"),
(@ENTRY,0,2,"I'd rather die fighting than live like a slave!",12,0,100,1,0,0,"Exhausted Vrykul"),

(@ENTRY,1,0,"Back... to work...",12,0,100,1,0,0,"Exhausted Vrykul"),
(@ENTRY,1,1,"We will have revenge... some day.",12,0,100,1,0,0,"Exhausted Vrykul"),
(@ENTRY,1,2,"You treat us worse than animals!",12,0,100,1,0,0,"Exhausted Vrykul");

-- Captive Vrykul should be mining
DELETE FROM `creature_template_addon` WHERE `entry`=29427;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (29427,0,0,1,233,NULL);
