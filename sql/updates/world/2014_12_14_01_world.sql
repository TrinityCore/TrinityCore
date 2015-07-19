SET @ENTRY := 21315; -- Guid 74638
SET @Drake := 22106;
UPDATE `creature_template` SET inhabittype=4,`speed_walk`=2.4,`speed_run`=1.71429,`ScriptName`='',`AIName`='SmartAI', unit_flags=32768, MovementType=2 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Drake;
UPDATE `creature` SET `position_x`=-3761.743,`position_y`=1081.672,`position_z`=125.3161 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@drake;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,'Ruul the Darkener - On Spawn - StarWP'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - On Spawn - Set fly on'),
(@ENTRY,0,2,0,40,0,100,0,47,@ENTRY,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,'Ruul the Darkener - Reach wp - Re Start WP'),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - On aggro -  ActionList'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - ActionList -  talk1'),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - ActionList -  talk2'),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,85,38343,1,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - On death -  Summon Ruul''s Nether Drake With Invoker_cast'),
(@Drake, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 5000, 5000, 11, 38344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Drake - IC - CAST'),
(@Drake, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 10000, 10000, 11, 36513, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drake - IC - CAST'),
(@Drake, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 25, 0, 0, 0, 0, 0, 0, 'Drake - Just Summoned - StartAttack'),
(@ENTRY, 0, 5, 0, 0, 0, 100, 0, 3000, 3000, 6000, 6000, 11, 36073, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ENTRY - IC - CAST'),
(@ENTRY, 0, 6, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 39153, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ENTRY - IC - CAST'),
(@ENTRY, 0, 7, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ENTRY - IC - CAST');
-- Waypoints for Ruul the Darkener from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-3805.743,1074.672,125.3161, 'Ruul the Darkener WP'),
(@ENTRY,2,-3806.74,1074.585,125.3161, 'Ruul the Darkener WP'),
(@ENTRY,3,-3844.399,1071.154,116.4082, 'Ruul the Darkener WP'),
(@ENTRY,4,-3871.77,1061.122,104.3527, 'Ruul the Darkener WP'),
(@ENTRY,5,-3897.401,1040.65,84.43602, 'Ruul the Darkener WP'),
(@ENTRY,6,-3923.55,1019.801,59.43599, 'Ruul the Darkener WP'),
(@ENTRY,7,-3946.312,1007.962,41.49157, 'Ruul the Darkener WP'),
(@ENTRY,8,-3981.2,987.1596,17.43604, 'Ruul the Darkener WP'),
(@ENTRY,9,-4003.07,957.1582,13.24213, 'Ruul the Darkener WP'),
(@ENTRY,10,-4012.831,932.0213,12.51513, 'Ruul the Darkener WP'),
(@ENTRY,11,-4023.356,901.5677,8.140135, 'Ruul the Darkener WP'),
(@ENTRY,12,-4033.129,864.9609,4.726814, 'Ruul the Darkener WP'),
(@ENTRY,13,-4039.05,829.5438,1.101814, 'Ruul the Darkener WP'),
(@ENTRY,14,-4046.8,785.2863,2.422696, 'Ruul the Darkener WP'),
(@ENTRY,15,-4053.405,754.4661,1.867994, 'Ruul the Darkener WP'),
(@ENTRY,16,-4077.986,718.4368,1.501426, 'Ruul the Darkener WP'),
(@ENTRY,17,-4104.671,681.145,2.619006, 'Ruul the Darkener WP'),
(@ENTRY,18,-4124.385,652.7042,3.424712, 'Ruul the Darkener WP'),
(@ENTRY,19,-4139.037,629.68,4.261003, 'Ruul the Darkener WP'),
(@ENTRY,20,-4144.591,607.7719,5.011003, 'Ruul the Darkener WP'),
(@ENTRY,21,-4148.39,587.783,8.4231, 'Ruul the Darkener WP'),
(@ENTRY,22,-4155.772,562.8152,11.38299, 'Ruul the Darkener WP'),
(@ENTRY,23,-4165.006,542.4948,15.88299, 'Ruul the Darkener WP'),
(@ENTRY,24,-4174.202,524.9961,22.73551, 'Ruul the Darkener WP'), -- fi Aller 
(@ENTRY,25,-4165.006,542.4948,15.88299, 'Ruul the Darkener WP'),-- début du retour
(@ENTRY,26,-4155.772,562.8152,11.38299, 'Ruul the Darkener WP'),
(@ENTRY,27,-4148.39,587.783,8.4231, 'Ruul the Darkener WP'),
(@ENTRY,28,-4144.591,607.7719,5.011003, 'Ruul the Darkener WP'),
(@ENTRY,29,-4139.037,629.68,4.261003, 'Ruul the Darkener WP'),
(@ENTRY,30,-4124.385,652.7042,3.424712, 'Ruul the Darkener WP'),
(@ENTRY,31,-4104.671,681.145,2.619006, 'Ruul the Darkener WP'),
(@ENTRY,32,-4077.986,718.4368,1.501426, 'Ruul the Darkener WP'),
(@ENTRY,33,-4053.405,754.4661,1.867994, 'Ruul the Darkener WP'),
(@ENTRY,34,-4046.8,785.2863,2.422696, 'Ruul the Darkener WP'),
(@ENTRY,35,-4039.05,829.5438,1.101814, 'Ruul the Darkener WP'),
(@ENTRY,36,-4033.129,864.9609,4.726814, 'Ruul the Darkener WP'),
(@ENTRY,37,-4023.356,901.5677,8.140135, 'Ruul the Darkener WP'),
(@ENTRY,38,-4012.831,932.0213,12.51513, 'Ruul the Darkener WP'),
(@ENTRY,39,-4003.07,957.1582,13.24213, 'Ruul the Darkener WP'),
(@ENTRY,40,-3981.2,987.1596,17.43604, 'Ruul the Darkener WP'),
(@ENTRY,41,-3946.312,1007.962,41.49157, 'Ruul the Darkener WP'),
(@ENTRY,42,-3923.55,1019.801,59.43599, 'Ruul the Darkener WP'),
(@ENTRY,43,-3897.401,1040.65,84.43602, 'Ruul the Darkener WP'),
(@ENTRY,44,-3871.77,1061.122,104.3527, 'Ruul the Darkener WP'),
(@ENTRY,45,-3844.399,1071.154,116.4082, 'Ruul the Darkener WP'),
(@ENTRY,46,-3806.74,1074.585,125.3161, 'Ruul the Darkener WP'),
(@ENTRY,47,-3805.743,1074.672,125.3161, 'Ruul the Darkener WP');
Delete from `creature_text` where `entry` in (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@ENTRY, 0, 0, 'The skies will darken and all will go quiet. Only then will you know the sweet serenity of death...', 12, 0, 100, 0, 0, 0, 'Ruul the Darkener', 19291),
(@ENTRY, 1, 0, 'Your world is at an end.', 12, 0, 100, 0, 0, 0, 'Ruul the Darkener', 19290);
