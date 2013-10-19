SET @CREATURE_GUID := 4000150; -- 11 needed
SET @GOB_GUID := 400010; -- 1 needed

UPDATE `item_template` SET `ScriptName` = 'TW_item_water_bucket' WHERE `entry` = 32971;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_halloween_fire' WHERE `entry` = 23537;
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=23686; -- fire dummies should be invisible
UPDATE `creature_template` SET `Health_mod`=20 WHERE `entry`=23543; -- HH should have 4440 hp

DELETE FROM `creature` WHERE `id` IN (23537,23686) AND `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+10;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Spawn fire dummys for fire effigys
(@CREATURE_GUID+00,23537,530,1,1,0,0,-4192.38,-12268.1,2.53389,-1.72788,300,0,0,45780,0,0,0,0,0),
(@CREATURE_GUID+01,23537,530,1,1,0,0,-4207.84,-12276.7,4.82085,-0.069813,300,0,0,45780,0,0,0,0,0),
(@CREATURE_GUID+02,23537,0,1,1,0,0,-5753.24,-533.652,405.022,1.15192,300,0,0,45780,0,0,0,0,0),
(@CREATURE_GUID+03,23537,0,1,1,0,0,-5761.17,-528.193,404.855,1.16937,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+04,23537,0,1,1,0,0,-5747.52,-527.634,401.297,0.610865,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+05,23537,1,1,1,0,0,286.565,-4561.45,28.5742,2.42601,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+06,23537,530,1,1,0,0,9235.05,-6783.4,26.4426,1.5708,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+07,23537,0,1,1,0,0,2240.44,459.159,39.2838,0.820305,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+08,23537,0,1,1,0,0,2239.49,487.861,38.3446,-0.715585,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+09,23537,0,1,1,0,0,-9328.25,56.2778,63.2509,2.60054,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+10,23537,0,1,1,0,0,-9314.1,52.4562,77.7343,2.93215,300,0,0,15260,0,0,0,0,0);
-- Spawn Fire Handlers for villages
#(@CREATURE_GUID+11,23686,1,1,1,0,0,305.144,-4724.5,9.83766,3.68348,300,0,0,7185,7196,0,0,0,0),
#(@CREATURE_GUID+12,23686,0,1,1,0,0,-9465.54,63.2228,55.8587,6.25841,300,0,0,7185,7196,0,0,0,0);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+10;
INSERT INTO `game_event_creature` VALUES
(12, @CREATURE_GUID+00),
(12, @CREATURE_GUID+01),
(12, @CREATURE_GUID+02),
(12, @CREATURE_GUID+03),
(12, @CREATURE_GUID+04),
(12, @CREATURE_GUID+05),
(12, @CREATURE_GUID+06),
(12, @CREATURE_GUID+07),
(12, @CREATURE_GUID+08),
(12, @CREATURE_GUID+09),
(12, @CREATURE_GUID+10);
#(12, @CREATURE_GUID+11),
#(12, @CREATURE_GUID+12);

-- missing water bucket in Goldshire
DELETE FROM `gameobject` WHERE `guid`=@GOB_GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GOB_GUID,186234,0,1,1,-9430.03,60.747,56.7760,3.45835, 0, 0, 0.984808, 0.173648, 1, 100, 1);

DELETE FROM `game_event_gameobject` WHERE `guid`=@GOB_GUID;
INSERT INTO `game_event_gameobject` (`eventEntry`,`guid`) VALUES
(12,@GOB_GUID);

/*
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId IN (18,19) AND SourceEntry IN (11360, 11361, 11439, 11440, 11449, 11450, 12135, 11131, 12139, 11219);
INSERT INTO `conditions` VALUES
-- Fire Brigade Practice (Alliance) Area dependance
(18, 0, 11360, 0, 23, 87, 0, 0, 0, '', NULL),
(19, 0, 11360, 0, 23, 87, 0, 0, 0, '', NULL),
(18, 0, 11439, 0, 23, 131, 0, 0, 0, '', NULL),
(19, 0, 11439, 0, 23, 131, 0, 0, 0, '', NULL),
(18, 0, 11440, 0, 23, 3576, 0, 0, 0, '', NULL),
(19, 0, 11440, 0, 23, 3576, 0, 0, 0, '', NULL),
-- Fire Training (Horde) Area dependance
(18, 0, 11361, 0, 23, 362, 0, 0, 0, '', NULL),
(19, 0, 11361, 0, 23, 362, 0, 0, 0, '', NULL),
(18, 0, 11449, 0, 23, 85, 0, 0, 0, '', NULL),
(19, 0, 11449, 0, 23, 85, 0, 0, 0, '', NULL),
(18, 0, 11450, 0, 23, 3665, 0, 0, 0, '', NULL),
(19, 0, 11450, 0, 23, 3665, 0, 0, 0, '', NULL);
*/
-- Fire Brigade Practice (Alliance) (Only 1 may be completed)
UPDATE `quest_template` SET `ExclusiveGroup` = 11360, `NextQuestId`= 12135 WHERE `id` IN (11360, 11439, 11440);
-- Fire Training (Horde) (Only 1 may be completed)
UPDATE `quest_template` SET `ExclusiveGroup` = 11361, `NextQuestId` = 12139 WHERE `id` IN (11361, 11449, 11450);
-- "Let the fires come" and Stop the Fires! (Only 1 may be completed) (Remove party accept)
UPDATE `quest_template` SET `Flags` = 4104, `ExclusiveGroup` = 12135, `PrevQuestId` = 0 WHERE `id` IN (12135, 11131); -- Alliance
UPDATE `quest_template` SET `Flags` = 4104, `ExclusiveGroup` = 12139, `PrevQuestId` = 0 WHERE `id` IN (12139, 11219); -- Horde
-- The Headless Horseman may only be taken if completed the quest "Smashing the pumpkin"
UPDATE `quest_template` SET `NextQuestId` = 11135 WHERE `id` = 12133; -- Alliance
UPDATE `quest_template` SET `NextQuestId` = 11220 WHERE `id` = 12155; -- Horde
UPDATE `quest_template` SET `RequiredRaces` = 1101, `ExclusiveGroup` = 0, `PrevQuestId` = 12133 WHERE `id` = 11135; -- Alliance
UPDATE `quest_template` SET `RequiredRaces` = 690, `ExclusiveGroup` = 0, `PrevQuestId` = 12155 WHERE `id` = 11220; -- Horde

UPDATE `creature_template` SET `ScriptName` = 'TW_npc_halloween_orphan_matron' WHERE `entry` IN (24519, 23973);
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_shade_horseman' WHERE `entry` = 23543;

DELETE FROM creature_text WHERE entry=23543;
INSERT INTO creature_text (entry, groupid, id, TEXT, TYPE, LANGUAGE, probability, emote, duration, sound, COMMENT) VALUES
(23543,1,0,'Prepare yourselves, the bells have tolled! Shelter your weak, your young and your old! Each of you shall pay the final sum. Cry for mercy, the reckoning has come!',14,0,100,1,0,11966,'Shade of the Horseman - Horseman Bomb'),
(23543,2,0,'¡My flames have died, left not a spark. I shall send you myself, to the lifeless dark.',14,0,100,1,0,11968,'Shade of the Horseman - Horseman Out'),
(23543,3,0,'¡Fire consumes! You''ve tried and failed. Let there be no doubt, justice prevailed!',14,0,100,1,0,11967,'Shade of the Horseman - Horseman Fire'),
(23543,4,0,'<%s laughs>',16,0,100,11,0,11975,'Shade of the Horseman - Laugh1'),
(23543,4,1,'<%s laughs>',16,0,100,11,0,12119,'Shade of the Horseman - Laugh2');

-- HH in Scarlet Monastery needs to be able to fly
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=23682;

-- HH in Goldshire&Razor Hill needs to be able to fly
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=23543;
