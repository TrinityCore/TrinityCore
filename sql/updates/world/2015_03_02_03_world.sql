SET @SUMMON := 49989;
SET @GOLEM  := 24823;
SET @BENCH  := 186958;
SET @Lebronski := 24718;

DELETE FROM `spell_target_position` WHERE `id` IN (49990); 
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(49990, 571, 478.951782, -5941.529297, 308.749969, 0.419872);

UPDATE `creature_template` SET `spell1`=44562, `AIName`='SmartAI' WHERE `entry`=@GOLEM;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Lebronski;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@GOLEM*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Lebronski AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Lebronski*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Lebronski*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BENCH AND `source_type`=1 AND `id` IN (4,5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BENCH,1,4,5,62,0,100,0,9024,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Close gossip'),
(@BENCH,1,5,0,61,0,100,0,0,0,0,0,85,@SUMMON,2,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Summon Iron Rune Construct'),
(@Lebronski,0,0,0,10,0,100,0,1,5,60000,60000,80,@Lebronski*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Turd - LOS - Action list'),
(@Lebronski*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Lebronski*100,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - Set Event phase1'),
(@Lebronski*100,9,2,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - Root'),
(@Lebronski*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Stanwad - Action list - Set Orientation'),
(@Lebronski*100,9,4,0,0,0,100,0,30000,30000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - remove root'),
(@Lebronski,0,1,0,8,1,100,0,44562,0,0,0,80,@Lebronski*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lebronski - spell hit - action list'),
(@Lebronski*100+1,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - Set Event phase 0'),
(@Lebronski*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Lebronski*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Lebronski*100+1,9,3,0,0,0,100,0,0,0,0,0,80,@GOLEM*100,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Stanwad - Action list - Action list'),
(@Lebronski*100+1,9,4,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - Pause wp'),
(@GOLEM*100,9,0,0,0,0,100,0,0,0,0,0,11,44569,0,0,0,0,0,23,0,0,0,0,0,0,0,'Stanwad - Action list - Cast Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Lebronski;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Lebronski,0,31,3,24823,0,0,'','event require npc 24823');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44562;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 44562, 0, 31, 3, 24718, 0, 0, '', 'Bluff target');

DELETE FROM `creature_text` WHERE `entry`IN (@GOLEM);   
DELETE FROM `creature_text` WHERE `entry`IN (@Lebronski) AND `groupid` IN (1, 2);  
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@GOLEM,0,0,"Model U-9207 Iron Rune Construct does not appreciate your tone of voice. Commencing total annihilation of your rug, Lebronski.",12,0,100,0,0,0,'Iron Rune Construct', 23892),
(@Lebronski,1,0,"What do you think you're doing, man? Lebronski does NOT appreciate you dragging your loose metal parts all over his rug.",12,7,100,0,0,0,'Lebronski', 23890),
(@Lebronski,2,0,"Far out, man. This bucket of bolts might make it after all...",12,7,100,0,0,0,'Lebronski', 23891);
