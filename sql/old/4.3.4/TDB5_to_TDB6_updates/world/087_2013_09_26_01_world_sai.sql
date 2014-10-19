UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='',`speed_walk`=1.428571,`speed_run`=1.6, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=12 WHERE `entry` =27002;

DELETE FROM `creature_text` WHERE `entry`=27002;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27002,0,0,'I''ll consume your flesh and pick my teeth with your bones!',14,0,100,0,0,0,'Grom''thar the Thunderbringer'),
(27002,1,0,'You''re no magnataur!  Where... did you... find... such strength?',14,0,100,0,0,0,'Grom''thar the Thunderbringer');

DELETE FROM `event_scripts` WHERE `id`=17767;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(17767,0,10,27002,300000,0,2791.477,381.7451,77.19083,2.6067);

DELETE FROM `conditions` WHERE `SourceEntry` = 48328;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ScriptName`, `Comment`) VALUES
(17,0,48328,0,0,29,0,27002,100,0,1,'',"Do not summon Grom'thar, if he is already spawned (100 Yards)"),
(17,0,48328,0,0,28,0,12151,0,0,1,'',"Do not summon Grom'thar, if player has quest objective completed, but not yet rewarded.");

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 27002;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27002;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27002,0,0,0,9,0,100,0,5,45,4000,8000,11,52167,0,0,0,0,0,5,0,0,0,0,0,0,0,'Grom''thar the Thunderbringer - On Range - Cast Magnataur Charge'),
(27002,0,1,0,9,0,100,0,0,5,7000,11000,11,52166,0,0,0,0,0,1,0,0,0,0,0,0,0,'Grom''thar the Thunderbringer - In Combat - Cast Thunder'),
(27002,0,2,3,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Grom''thar the Thunderbringer - On Just Summoned - Say'),
(27002,0,3,0,61,0,100,0,0,0,0,0,53,1,27002,0,0,0,2,1,0,0,0,0,0,0,0,'Grom''thar the Thunderbringer - Linked with Previous Event - Start WP'),
(27002,0,4,5,40,0,100,0,1,27002,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Grom''thar the Thunderbringer - On Reached WP1 - Set Home Position'),
(27002,0,5,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,'Grom''thar the Thunderbringer - Linked with Previous Event - Attack'),
(27002,0,6,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Grom''thar the Thunderbringer - On Death - Say');

DELETE FROM `waypoints` WHERE `entry`=27002;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(27002, 1, 2746.325195,420.078369,67.982117, 'Grom''thar the Thunderbringer');
