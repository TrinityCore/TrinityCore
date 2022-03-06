-- The Arcatraz, remove CREATURE_FLAG_EXTRA_CIVILIAN, replaced by CREATURE_FLAG_EXTRA_NO_COMBAT
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 2 WHERE `entry` IN (20978,21030,21101,21186,21414,21436,21437,21438,21439,21440,21603,21620,21625,21761);

-- The Mechanar, replace passive react state with CREATURE_FLAG_EXTRA_NO_COMBAT
SET @ID := 20405;
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (@ID,21534);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,35150,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Just Summoned - Cast 'Nether Charge Passive'"),
(@ID,0,1,2,61,0,100,0,0,0,0,0,11,37670,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Cast 'Nether Charge Timer'"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Start Random Movement"),
(@ID,0,3,4,60,0,100,1,10500,10500,0,0,11,35148,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Update - Cast 'Nether Charge Countdown' (No Repeat)"),
(@ID,0,4,0,61,0,100,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Stop Random Movement");

-- VoA & Gundrak, replace CREATURE_FLAG_EXTRA_CIVILIAN with CREATURE_FLAG_EXTRA_NO_COMBAT (or add)
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 2, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (29748,29682,29791,34230,36093);
