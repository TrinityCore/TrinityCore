-- Conditions for Writhing Choker and Unliving Choker
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry` IN (38673,38660);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,28519,38660,0,14,12238,0,0,0,'',NULL),
(1,28519,38673,0,8,12238,0,0,0,'',NULL);

-- Mission: Plague This (11332)
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9546 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9546,1,0, 'I need to Borrow a Gryphon',1,1,0,0,954601,0,0, ''); -- Text Unsure

DELETE FROM `gossip_scripts` WHERE `id`=954601;
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(954601,0,17,33634,10,0,0,0,0,0); -- Give Player Bombs

-- SmartAI
SET @ENTRY := 23859;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0, 'Greer Orehammer - Script on Aggro'),
(@ENTRY,0,1,0,62,0,100,0,9546,1,0,0,52,745,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Plague This Taxi Start'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,7,0,0,0,0,0,0,0,'Summon Enraged Gryphon'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,7,0,0,0,0,0,0,0,'Summon Enraged Gryphon');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Guards!',0,0,100,0,0,0,'Greer Orehammer');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9546 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9546,1,0,9,11332,0,0,0,'', 'Mission Plague This is Active');
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY; -- Text Entry Not Touched as its Shared by All Flight Masters

-- Quest: Scourge Tactics (13008)
-- Webed Crusader (Crusader Verion)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=30273;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30273;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30273,0,0,0,6,0,100,0,0,0,0,0,85,56515,0x02,0,0,0,0,7,0,0,0,0,0,0,0, 'Cast Summon Freed Crusader on Death'),
(30273,0,1,0,6,0,100,0,0,0,0,0,33,30274,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Cast Summon Freed Crusader Quest Credit');
DELETE FROM `spell_scripts` WHERE `id`=56515;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(56515,0,0,15,56516,2,0,0,0,0,0);
-- Webed Crusader (Ambusher Version)
UPDATE `creature_template` SET `AIName`= 'SmartAI', `minlevel`=1, `maxlevel`=1 WHERE `entry`=30268;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30268;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30268,0,0,0,6,0,100,0,0,0,0,0,12,30204,1,30000,0,0,0,1,0,0,0,0,0,0,0, 'Summon Forgotten Depths Ambusher');
-- Freeed Crusader
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=30274;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30274;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3027400;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30274,0,0,0,54,0,100,0,0,0,0,0,80,3027400,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Freed Crusader Start Script on Spawn'),
(3027400,9,0,0,0,0,100,0,0,0,0,0,11,58054,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Freed Crusader Blessing of Kings'),
(3027400,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Freed Crusader Speach'),
(3027400,9,2,0,0,0,100,0,0,0,0,0,11,58053,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Freed Crusader Holy Light'),
(3027400,9,3,0,0,0,100,0,4000,4000,0,0,53,1,30274,0,13008,0,0,1,0,0,0,0,0,0,0, 'Freed Crusader paths to Argeant Vanguard'),
(3027400,9,4,0,0,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Freed Crusader Despawn');
-- create path point location to send Freed Crusaders to
DELETE FROM `waypoints` WHERE `entry`=30274;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(30274,1,6296.25,92.9397,390.701, 'send Freed Crusader here');
DELETE FROM `creature_text` WHERE `entry`=30274;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30274,0,0, 'Thank you and farewell, friend. I must return to the Argent Vanguard.',0,0,100,0,0,0, 'Freed Crusader Speach');
-- Forgotten Depths Ambusher
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=30204;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30204;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30204,0,0,0,54,0,100,0,0,0,0,0,11,56418,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Depths Ambusher - Emerge From Snow');
-- Spawns for Ambusher Verion
SET @GUID :=151826;
DELETE FROM `creature` WHERE `id`=30268;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID+0,30268,571,1,2,0,0,6244.78,190.194,383.08,1.50098,0,0,0,0,0,0,0,0,0,0),
(@GUID+1,30268,571,1,2,0,0,6249.75,126.806,382.534,2.47837,0,0,0,0,0,0,0,0,0,0),
(@GUID+2,30268,571,1,2,0,0,6277.33,155.167,383.491,0.43643,0,0,0,0,0,0,0,0,0,0),
(@GUID+3,30268,571,1,2,0,0,6303.7,193.736,387.669,-1.17247,0,0,0,0,0,0,0,0,0,0),
(@GUID+4,30268,571,1,2,0,0,6321.27,152.463,387.239,4.10152,0,0,0,0,0,0,0,0,0,0),
(@GUID+5,30268,571,1,2,0,0,6333.02,57.5423,389.173,4.62512,0,0,0,0,0,0,0,0,0,0),
(@GUID+6,30268,571,1,2,0,0,6335.22,110.147,391.309,6.05629,0,0,0,0,0,0,0,0,0,0),
(@GUID+7,30268,571,1,2,0,0,6339.98,186.907,389.644,-2.29057,0,0,0,0,0,0,0,0,0,0),
(@GUID+8,30268,571,1,2,0,0,6347.77,225.483,393.712,-1.99599,0,0,0,0,0,0,0,0,0,0),
(@GUID+9,30268,571,1,2,0,0,6363.71,126.463,391.424,3.89208,0,0,0,0,0,0,0,0,0,0),
(@GUID+10,30268,571,1,2,0,0,6389.44,226.344,395.383,6.16101,0,0,0,0,0,0,0,0,0,0),
(@GUID+11,30268,571,1,2,0,0,6405.67,158.456,394.692,0.85521,0,0,0,0,0,0,0,0,0,0),
(@GUID+12,30268,571,1,2,0,0,6421.84,258.293,397.279,-2.2004,0,0,0,0,0,0,0,0,0,0),
(@GUID+13,30268,571,1,2,0,0,6434.63,198.273,396.762,5.93412,0,0,0,0,0,0,0,0,0,0);
-- Pool creature
SET @Pool=7001;
DELETE FROM `pool_creature` WHERE `pool_entry` BETWEEN @Pool+0 AND @Pool+13;
INSERT INTO `pool_creature` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(207266,@Pool+0,0, 'Webbed Crusader Spawn 1'),
(@GUID+0,@Pool+0,0, 'Webbed Crusader Spawn 1'),
(207267,@Pool+1,0, 'Webbed Crusader Spawn 2'),
(@GUID+1,@Pool+1,0, 'Webbed Crusader Spawn 2'),
(207268,@Pool+2,0, 'Webbed Crusader Spawn 3'),
(@GUID+2,@Pool+2,0, 'Webbed Crusader Spawn 3'),
(207269,@Pool+3,0, 'Webbed Crusader Spawn 4'),
(@GUID+3,@Pool+3,0, 'Webbed Crusader Spawn 4'),
(207270,@Pool+4,0, 'Webbed Crusader Spawn 5'),
(@GUID+4,@Pool+4,0, 'Webbed Crusader Spawn 5'),
(207271,@Pool+5,0, 'Webbed Crusader Spawn 6'),
(@GUID+5,@Pool+5,0, 'Webbed Crusader Spawn 6'),
(207272,@Pool+6,0, 'Webbed Crusader Spawn 7'),
(@GUID+6,@Pool+6,0, 'Webbed Crusader Spawn 7'),
(207273,@Pool+7,0, 'Webbed Crusader Spawn 8'),
(@GUID+7,@Pool+7,0, 'Webbed Crusader Spawn 8'),
(207274,@Pool+8,0, 'Webbed Crusader Spawn 9'),
(@GUID+8,@Pool+8,0, 'Webbed Crusader Spawn 9'),
(207275,@Pool+9,0, 'Webbed Crusader Spawn 10'),
(@GUID+9,@Pool+9,0, 'Webbed Crusader Spawn 10'),
(207276,@Pool+10,0, 'Webbed Crusader Spawn 11'),
(@GUID+10,@Pool+10,0, 'Webbed Crusader Spawn 11'),
(207277,@Pool+11,0, 'Webbed Crusader Spawn 12'),
(@GUID+11,@Pool+11,0, 'Webbed Crusader Spawn 12'),
(207278,@Pool+12,0, 'Webbed Crusader Spawn 13'),
(@GUID+12,@Pool+12,0, 'Webbed Crusader Spawn 13'),
(207279,@Pool+13,0, 'Webbed Crusader Spawn 14'),
(@GUID+13,@Pool+13,0, 'Webbed Crusader Spawn 14');
-- Pools
DELETE FROM `pool_template` WHERE `entry` BETWEEN @Pool+0 AND @Pool+13;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@Pool+0,1, 'Webbed Crusader Spawn 1'),
(@Pool+1,1, 'Webbed Crusader Spawn 2'),
(@Pool+2,1, 'Webbed Crusader Spawn 3'),
(@Pool+3,1, 'Webbed Crusader Spawn 4'),
(@Pool+4,1, 'Webbed Crusader Spawn 5'),
(@Pool+5,1, 'Webbed Crusader Spawn 6'),
(@Pool+6,1, 'Webbed Crusader Spawn 7'),
(@Pool+7,1, 'Webbed Crusader Spawn 8'),
(@Pool+8,1, 'Webbed Crusader Spawn 9'),
(@Pool+9,1, 'Webbed Crusader Spawn 10'),
(@Pool+10,1, 'Webbed Crusader Spawn 11'),
(@Pool+11,1, 'Webbed Crusader Spawn 12'),
(@Pool+12,1, 'Webbed Crusader Spawn 13'),
(@Pool+13,1, 'Webbed Crusader Spawn 14');
