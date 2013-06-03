-- Convert quest_end_script "10964" to SAI, alongside dropping creature c++ script
-- Indexes:
SET @CLINTAR_DREAMWALKER := 22834;
SET @SCRIPT := @CLINTAR_DREAMWALKER * 100;
SET @SPIRIT := 22916;

-- Remove template addon emote (all is handled by that SAI, this breaks it)
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=@CLINTAR_DREAMWALKER;

-- Remove from quest_end_scripts
DELETE FROM `quest_end_scripts` WHERE `id`=10964;

-- Add SAI support and drop c++ script
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@CLINTAR_DREAMWALKER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CLINTAR_DREAMWALKER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CLINTAR_DREAMWALKER,0,0,0,20,0,100,0,10964,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - On quest 10964 rewarded - Start action list'),
(@CLINTAR_DREAMWALKER,0,1,2,19,1,100,0,10965,0,0,0,12,@SPIRIT,2,100000,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - On quest 10965 accepted - Spawn creature (can happen only after actionlist stuff are complete)'),
(@CLINTAR_DREAMWALKER,0,2,0,61,1,100,0,0,0,0,0,69,3,0,0,0,0,0,8,0,0,0,7459.47,-3122.79,439.485,5.84588, 'Clintar Dreamwalker - Linked - Move to pos'),
(@CLINTAR_DREAMWALKER,0,3,4,34,1,100,0,8,3,0,0,90,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - On point 3 reached set - Set field byte 1 for sleeping'),
(@CLINTAR_DREAMWALKER,0,4,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Linked - Set phase 0'),
(@CLINTAR_DREAMWALKER,0,5,6,1,1,100,1,360000,360000,360000,360000,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - OOC (phase 1) - Set unseen'),
(@CLINTAR_DREAMWALKER,0,6,0,61,1,100,1,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Linked - Despawn'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 0 - Remove npc flag for quest giver'),
(@SCRIPT,9,1,0,0,0,100,0,3000,3000,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 1 - Remove bytes for sleeping'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 2 - Set bytes 1 kneel'),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 3 - Say line 0'),
(@SCRIPT,9,4,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 4 - Say line 1 (with exclamation emote)'),
(@SCRIPT,9,5,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 5 - Say line 2'),
(@SCRIPT,9,6,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 6 - Remove bytes 1 for kneel'),
(@SCRIPT,9,7,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 7 - Say line 3'),
(@SCRIPT,9,8,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,7453.25,-3116.29,439.604,5.534, 'Clintar Dreamwalker - Action 8 - Move to pos'),
(@SCRIPT,9,9,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,7453.79,-3116.83,439.604,5.534, 'Clintar Dreamwalker - Action 9 - Move to pos'),
(@SCRIPT,9,10,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 10 - Say line 4'),
(@SCRIPT,9,11,0,0,0,100,0,1500,1500,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 11 - Add npc flag for quest giver'),
(@SCRIPT,9,12,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Clintar Dreamwalker - Action 12 - Set phase 1');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000067,2000000068,2000000069);
DELETE FROM `creature_text` WHERE `entry`=@CLINTAR_DREAMWALKER;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@CLINTAR_DREAMWALKER,0,0, 'Clintar Dreamwalker snaps up to a kneeling position, but seems as though he''s somewhere else.',16,0,100,0,0,0, 'Clintar Dreamwalker (line 0)'),
(@CLINTAR_DREAMWALKER,1,0, 'What are you doing in Ysera''s realm, interloper? Leave us, I say! Your kind are not welcome here!',12,0,100,5,0,0, 'Clintar Dreamwalker (line 1)'),
(@CLINTAR_DREAMWALKER,2,0, 'Clintar Dreamwalker gets to his feet, beginning to recognize his surroundings.',16,0,100,0,0,0, 'Clintar Dreamwalker (line 2)'),
(@CLINTAR_DREAMWALKER,3,0, 'You - you''re not one of them! Let''s get out of sight before they find us! Hurry! ',12,0,100,1,0,0, 'Clintar Dreamwalker (line 3)'),
(@CLINTAR_DREAMWALKER,4,0, 'They''re following me, $R! Quickly, tell me why you''re here before we''re discovered! If they catch up to me, it will mean my death and yours!',12,0,100,1,0,0, 'Clintar Dreamwalker (line 4)');
