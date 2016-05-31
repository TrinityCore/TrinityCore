-- Quest - Iron Rune Constructs and You: Collecting Data

SET @GUID := 49220; -- Set by TC
SET @SUMMON := 49986;
SET @GOLEM  := 24821;
SET @BENCH  := 186958;
DELETE FROM `spell_target_position` WHERE `id` in (49988); 
INSERT INTO `spell_target_position` (`id`,`MapID`,`PositionX`,`PositionY`,`PositionZ`) VALUES
(49988, 571, 478.951782, -5941.529297, 308.749969);

UPDATE `creature_template` SET `spell1`=44550, `AIName`='SmartAI' WHERE `entry`=@GOLEM;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@GOLEM AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BENCH AND `source_type`=1 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BENCH,1,2,3,62,0,100,0,9024,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Close gossip'),
(@BENCH,1,3,0,61,0,100,0,0,0,0,0,85,@SUMMON,2,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Summon Iron Rune Construct');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44550;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 44550, 0, 31, 3, 24820, 0, 0, '', 'Collect Data target');

DELETE FROM `creature` WHERE `id`=24820;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(@GUID, 24820, 571, 1, 0, 466.754089, -5921.273926, 309.139404, 0.751123, 120);

--

SET @SUMMON := 49989;
SET @GOLEM  := 24823;
SET @BENCH  := 186958;
SET @Lebronski := 24718;

DELETE FROM `spell_target_position` WHERE `id` IN (49990); 
INSERT INTO `spell_target_position` (`id`,`MapID`,`PositionX`,`PositionY`,`PositionZ`) VALUES
(49990, 571, 478.951782, -5941.529297, 308.749969);

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

--

-- Quest - Iron Rune Constructs and You: Rocket Jumping
SET @SUMMON := 49985;
SET @GOLEM  := 24806;
SET @RUNE   := 186956;
SET @BENCH  := 186958;
SET @Stanwad := 24717;
SET @Gwendolyn := 24719;
SET @Needlemeyer := 24720;
SET @Walt := 24807;
SET @Lebronski := 24718;

DELETE FROM `spell_target_position` WHERE `id` in (49984); 
INSERT INTO `spell_target_position` (`id`,`MapID`,`PositionX`,`PositionY`,`PositionZ`) VALUES
(49984, 571, 478.951782, -5941.529297, 308.749969);

UPDATE `creature_template` SET `spell1`=44498, `AIName`='SmartAI', `InhabitType`=5 WHERE `entry`=@GOLEM;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Stanwad;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@BENCH;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@GOLEM AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Stanwad*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BENCH AND `source_type`=1 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BENCH,1,0,1,62,0,100,0,9024,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Close gossip'),
(@BENCH,1,1,0,61,0,100,0,0,0,0,0,85,@SUMMON,2,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Summon Iron Rune Construct'),
(@GOLEM,0,0,1,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - Just Summoned - Set phase 1'),
(@GOLEM,0,1,0,61,0,100,0,0,0,0,0,50,186952,60,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - Just Summoned - SummonGob'),
(@GOLEM,0,2,3,8,1,100,0,44498,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - spell hit - Say text'),
(@GOLEM,0,3,4,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - spell hit - Set phase 2'),
(@GOLEM,0,4,5,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - spell hit - Set fly'),
(@GOLEM,0,5,6,61,0,100,0,0,0,0,0,53,1,@GOLEM,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - spell hit - WP start'),
(@GOLEM,0,6,7,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,65653,@RUNE,0,0,0,0,0,'Iron Rune Construct - spell hit - Activate Gobject'),
(@GOLEM,0,7,0,61,0,100,0,0,0,0,0,80,@Stanwad*100,0,0,0,0,0,19,@Stanwad,30,0,0,0,0,0,'Iron Rune Construct - spell hit - ActionList'),
(@GOLEM,0,8,9,40,0,100,0,5,@GOLEM,0,0,11,44499,0,0,0,0,0,23,0,0,0,0,0,0,0,'Iron Rune Construct - Waypoint reached - cast credit spell'),
(@GOLEM,0,9,10,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - Waypoint reached - Set phase 3'), 
(@GOLEM,0,10,0,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,65654,186957,0,0,0,0,0,'Iron Rune Construct - Just Summoned - Activate gob'),
(@GOLEM,0,11,0,1,4,100,1,7000,7000,0,0,28,46598,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - OOC (phase 3) - Remove Vehicle aura'),
(@Stanwad*100,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,@Walt,20,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,2,0,0,0,100,0,12000,12000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,3,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,4,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,@Gwendolyn,20,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,5,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,@Needlemeyer,20,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,6,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,@Lebronski,20,0,0,0,0,0,'Stanwad - Action list - TALK'),
(@Stanwad*100,9,7,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,19,@Walt,20,0,0,0,0,0,'Stanwad - Action list - TALK');

DELETE FROM `creature_text` WHERE `entry`IN (@GOLEM, @Walt, @Stanwad, @Gwendolyn, @Needlemeyer, @Lebronski);   
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@GOLEM,0,0,"Launching.",12,0,100,0,0,0,'Iron Rune Construct', 23860),
(@Walt,0,0,"Behold my perfect creation!",12,7,100,0,0,0,'Walt', 23873),
(@Stanwad,0,0,"WHOA, WHOA, WHOA! Hold everything fellas!",12,7,100,0,0,0,'Stanwad', 23875),
(@Stanwad,1,0,"Oh dear lords of stone and steel, what... I repeat... WHAT are ya gonna do with that?",12,7,100,0,0,0,'Stanwad', 23878),
(@Stanwad,2,0,"The dwarves all burst out in laughter.",16,7,100,0,0,0,'Stanwad', 23876),
(@Gwendolyn,0,0,"I'm cryin' here! Please, make the funny stop!",12,7,100,0,0,0,'Gwendolyn', 23885),
(@Needlemeyer,0,0,"If only our pappy were alive to see this!",12,0,100,0,0,0,'Needlemeyer', 23889),
(@Lebronski,0,0,"Man, that will never work. The iron dwarves are never gonna fall for that hunk o' junk!",12,7,100,0,0,0,'Lebronski', 23880),
(@Walt,1,0,"You're out of your element, Lebronski! Uncalled for! Those iron dwarves won't know what hit 'em! Now why don't you get back to uncovering the mystery of the gigantic turd on your rug and leave the real scientists to their work! ",12,7,100,0,0,0,'Walt', 23883);

DELETE FROM `waypoints` WHERE `entry`=@GOLEM;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@GOLEM,1, 479.1233, -5941.48, 316.7,'Iron Rune Construct'),
(@GOLEM,2, 479.1461, -5941.515, 339.7554,'Iron Rune Construct'),
(@GOLEM,3, 496.1333, -5940.065, 344.5331,'Iron Rune Construct'),
(@GOLEM,4, 511.516, -5936.729, 339.7554,'Iron Rune Construct'),
(@GOLEM,5, 514.5781, -5936.898, 314.1444,'Iron Rune Construct');

--

UPDATE `creature_addon` SET `mount`=0 WHERE  `guid`=97508;

/* questgiver */
-- Warmage Anzim SAI
SET @ENTRY := 25356;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,11681,0,0,0,85,45883,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmage Anzim - On Quest 'Rescuing Evanor' Taken - Invoker Cast 'Amber Ledge to Beryl Point'"),
(@ENTRY,0,1,0,61,0,100,0,11681,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Anzim - On Quest 'Rescuing Evanor' Taken - Run Script");

-- Actionlist SAI
SET @ENTRY := 2535600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Anzim - On Script - Remove Npc Flag Questgiver"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,118574,27888,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,107998,25732,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,108027,25733,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,107602,25727,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,180000,180000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Anzim - On Script - Add Npc Flag Questgiver");

/* dragons */

-- Warmage Archus SAI
SET @ENTRY := 27888;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Archus - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Archus - On Data Set 1 1 - Set Active On"),
(@ENTRY,0,2,0,40,0,100,0,1,@ENTRY,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Moran - On Waypoint 1 Reached - Pause Waypoint");

-- Warmage Preston SAI
SET @ENTRY := 25732;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Preston - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Preston - On Data Set 1 1 - Set Active On"),
(@ENTRY,0,2,0,40,0,100,0,1,@ENTRY,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Moran - On Waypoint 1 Reached - Pause Waypoint");

-- Warmage Austin SAI
SET @ENTRY := 25733;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Austin - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Austin - On Data Set 1 1 - Set Active On"),
(@ENTRY,0,2,0,40,0,100,0,1,@ENTRY,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Moran - On Waypoint 1 Reached - Pause Waypoint");

-- Warmage Moran SAI
SET @ENTRY := 25727;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,53,1,25727,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Moran - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Moran - On Data Set 1 1 - Set Active On"),
(@ENTRY,0,2,3,40,0,100,0,1,25727,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Moran - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,61,0,100,0,1,25727,0,0,75,42726,0,0,0,0,0,9,25724,0,100,0,0,0,0,"Warmage Moran - On Waypoint 1 Reached - Add Aura 'Cosmetic - Immolation (Whole Body)'");

-- Ascended Mage Hunter SAI
SET @ENTRY := 25724;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Respawn - Set Reactstate Passive"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,11,45940,0,0,0,0,0,9,25594,0,10,0,0,0,0,"Ascended Mage Hunter - Out of Combat - Cast 'Evanor's Prison Chains' (No Repeat)"),
(@ENTRY,0,2,3,23,0,100,1,42726,1,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Has Aura 'Cosmetic - Immolation (Whole Body)' - Start Random Movement (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,42726,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Has Aura 'Cosmetic - Immolation (Whole Body)' - Run Script (No Repeat)"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,114368,24771,0,0,0,0,0,"Ascended Mage Hunter - On Just Died - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 2572400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Kill Self");

-- Coldarra Invisman SAI
SET @ENTRY := 24771;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Invisman - On Data Set 1 1 - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 2477100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,4000,4000,0,0,9,0,0,0,0,0,0,20,187884,20,0,0,0,0,0,"Coldarra Invisman - On Script - activate Game Object"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,11,46013,2,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Invisman - On Script - Cast 'Summon Lady Evanor'");

-- Archmage Evanor SAI
SET @ENTRY := 25784;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Evanor - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 2578400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,46018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Cast 'Teleport'"),
(@ENTRY,9,3,0,0,0,100,0,8000,8000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=25784;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(25784, 0, 0, 'I thank you, friend of Dalaran.', 12, 0, 100, 0, 0, 0, 24995, 0, 'Archmage Evanor'),
(25784, 1, 0, 'We mustn''t tarry here... stay close - I''ll take us somewhere safe.', 12, 0, 100, 0, 0, 0, 24996, 0, 'Archmage Evanor');

DELETE FROM `spell_target_position` WHERE `id`=46018;
INSERT INTO `spell_target_position` (`id`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(46018, 0, 571, 3646.895, 5893.2773, 174.48, 0);

/* waypoint datas */
DELETE FROM `waypoints` WHERE `entry`=25727;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25727, 1,3195.641,6102.673,147.5568, 'Warmage Moran'),
(25727, 2,3437.590576,5915.928711,145.554291, 'Warmage Moran'); 
DELETE FROM `waypoints` WHERE `entry`=25733;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25733, 1,3224.336,6105.71,146.7791, 'Warmage Austin'),
(25733, 2,3435.270,5889.899,151.063, 'Warmage Austin'); 
DELETE FROM `waypoints` WHERE `entry`=25732;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25732, 1,3224.749,6083.038,147.5568, 'Warmage Preston'),
(25732, 2,3460.500,5877.4399,149.537, 'Warmage Preston'); 
DELETE FROM `waypoints` WHERE `entry`=27888;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27888, 1,3200.99,6074.898,144.9736, 'Warmage Archus'), 
(27888, 2,3457.750,5892.669,147.380, 'Warmage Archus');

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry` IN (25727, 25733, 25732, 27888);
