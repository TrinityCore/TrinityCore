-- Talk text for Mordresh Fire Eye from sniff
SET @ENTRY := 7357;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'We will enslave the quilboar!',12,0,100,1,0,5819, 'Mordresh Fire Eye - SAY_OOC_1'),
(@ENTRY,1,0,'We will spread across this barren land!',12,0,100,1,0,5820, 'Mordresh Fire Eye - SAY_OOC_2'),
(@ENTRY,2,0,'Soon, the Scourge will rule the world!',12,0,100,22,0,5821, 'Mordresh Fire Eye - SAY_OOC_3'),
(@ENTRY,3,0,'Slay them, my brethren! For the Scourge!',14,0,100,0,0,5822, 'Mordresh Fire Eye - SAY_AGGRO');

-- Talk text for Belnistrasz from sniff
SET @ENTRY := 8516;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'All right, stay close.  These fiends will jump right out of the shadows at you if you let your guard down.',12,0,100,0,0,0,'Belnistrasz SAY_QUEST_ACCEPTED'),
(@ENTRY,1,0,'Okay, here we go.  It's going to take about five minutes to shut this thing down through the ritual.  Once I start, keep the vermin off of me or it will be the end of us all!',12,0,100,0,0,0,'Belnistrasz SAY_EVENT_START'),
(@ENTRY,2,0,'Three minutes left -- I can feel the energy starting to build! Keep up the solid defense!',14,0,100,0,0,0,'Belnistrasz SAY_EVENT_THREE_MIN_LEFT'),
(@ENTRY,3,0,'Just two minutes to go!  We're half way there, but don't let your guard down!',14,0,100,0,0,0,'Belnistrasz SAY_EVENT_TWO_MIN_LEFT'),
(@ENTRY,4,0,'One more minute!  Hold on now, the ritual is about to take hold!',14,0,100,0,0,0,'Belnistrasz SAY_EVENT_ONE_MIN_LEFT'),
(@ENTRY,5,0,'That's it -- we made it!  The ritual is set in motion, and idol fires are about to go out for good!  You truly are the heroes I thought you would be!',14,0,100,4,0,0,'Belnistrasz SAY_EVENT_END'),
(@ENTRY,6,0,'You'll rue the day you crossed me, $N',12,0,100,0,0,0,'Belnistrasz SAY_AGGRO');
(@ENTRY,7,0,'Watch out for the $N!',12,0,100,0,0,0,'Belnistrasz SAY_WATCH_OUT');

-- Fix trigger location
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=`flags_extra`|128 WHERE `entry`=8662;

-- Condition for spell Belnistrasz Idol Shutdown Visual
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=12774;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 12774, 0, 0, 31, 0, 3, 8662, 0, 0, 0, 0, '', 'Belnistrasz Idol Shutdown Visual targets Idol Oven Fire Target');

-- Add cpp scripts
UPDATE creature_template SET `AIName`= '',ScriptName = 'boss_tuten_kash' WHERE entry=7355;
UPDATE creature_template SET `AIName`= '',ScriptName = 'boss_mordresh_fire_eye' WHERE entry=7357;
UPDATE creature_template SET `AIName`= '',ScriptName = 'boss_glutton' WHERE entry=8567;
UPDATE creature_template SET `AIName`= '',ScriptName = 'npc_belnistrasz' WHERE entry=8516;
UPDATE creature_template SET `AIName`= '',ScriptName = 'npc_idol_room_spawner' WHERE entry=8611;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (7355,7357,8567,8516) AND `source_type`=0;

-- Pathing for Belnistrasz Entry: 8516
SET @NPC := 87171;
SET @PATH := @NPC * 10;
DELETE FROM `creature_template_addon` WHERE `entry`=8516;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (8516,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2603.313,724.335,54.608,0,0,1,0,100,0),
(@PATH,2,2593.379,726.272,55.112,0,0,1,0,100,0),
(@PATH,3,2588.499,733.1947,55.3959,0,0,1,0,100,0),
(@PATH,4,2572.573,752.5162,54.71815,0,0,1,0,100,0),
(@PATH,5,2558.068,748.3008,54.3559,0,0,1,0,100,0),
(@PATH,6,2539.677,777.1356,46.95155,0,0,1,0,100,0),
(@PATH,7,2527.828,800.8403,44.74713,0,0,1,0,100,0),
(@PATH,8,2495.996,785.7536,39.51203,0,0,1,0,100,0),
(@PATH,9,2484.358,814.8914,43.57789,0,0,1,0,100,0),
(@PATH,10,2501.128,847.9614,47.5574,0,0,1,0,100,0),
(@PATH,11,2537.36,874.4713,47.67798,0,0,1,0,100,0),
(@PATH,12,2548.493,894.6515,47.69307,0,0,1,0,100,0),
(@PATH,13,2541.478,910.5101,46.17223,0,0,1,0,100,0),
(@PATH,14,2519.403,925.6332,46.51501,0,0,1,0,100,0),
(@PATH,15,2527.237,951.4606,49.2807,0,0,1,0,100,0),
(@PATH,16,2541.675,976.5887,50.41221,0,0,1,0,100,0),
(@PATH,17,2554.084,973.8665,50.36161,0,0,1,0,100,0),
(@PATH,18,2575.601,950.1381,52.84592,0,0,1,0,100,0);

DELETE FROM `creature_questender` WHERE `id`=8516 AND `quest`=3525;
DELETE FROM `gameobject_questender` WHERE `id`=152097 AND `quest`=3525;
INSERT INTO `gameobject_questender` (`id`,`quest`) VALUES (152097,3525);

-- Death's Head Geomancer SAI
SET @ENTRY := 7335;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3000,4000,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Geomancer - Combat - Cast Fireball (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,10000,6000,15000,11,6725,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Geomancer - Combat - Cast Flame Spike (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,16000,8000,20000,11,11436,1,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Geomancer - Combat - Cast Slow (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Death's Head Geomancer - 0-15% Health - Flee For Assist (Normal Dungeon)");
