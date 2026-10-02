--
SET @CGUID := 144991; -- 8
SET @SPAWN_GROUP_ID := 368; -- 8

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 24239;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24239,0,0,"Da shadow gonna fall on you....",14,0,100,0,0,12041,23591,0,"Hex Lord Malacrass SAY_AGGRO"),
(24239,1,0,"Ya don' kill me yet... ya don' get anudda chance!",14,0,100,0,0,12042,23592,0,"Hex Lord Malacrass SAY_BERSERK"),
(24239,2,0,"Dis a nightmare ya don' wake up from!",14,0,100,0,0,12043,23593,0,"Hex Lord Malacrass SAY_SLAY_1"),
(24239,2,1,"Azzaga choogo zinn!",14,0,100,0,0,12044,23594,0,"Hex Lord Malacrass SAY_SLAY_2"),
(24239,3,0,"Your will belong ta me now!",14,0,100,0,0,12045,23595,0,"Hex Lord Malacrass SAY_CHARM"),
(24239,4,0,"Darkness comin' for you....",14,0,100,0,0,12046,23596,0,"Hex Lord Malacrass SAY_DRAIN_POWER"),
(24239,5,0,"Your soul gonna bleed!",14,0,100,0,0,12047,23597,0,"Hex Lord Malacrass SAY_SPIRIT_BOLTS"),
(24239,6,0,"It not gonna make no difference.",14,0,100,0,0,12048,23598,0,"Hex Lord Malacrass SAY_PET_DIES_1"),
(24239,6,1,"You gonna die worse dan him.",14,0,100,0,0,12049,23599,0,"Hex Lord Malacrass SAY_PET_DIES_2"),
(24239,6,2,"Dat no bodda me.",14,0,100,0,0,12050,23600,0,"Hex Lord Malacrass SAY_PET_DIES_3"),
(24239,7,0,"Dis not... da end for me!",14,0,100,0,0,12051,23601,0,"Hex Lord Malacrass SAY_DEATH");

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_malacrass_siphon_soul',
'spell_malacrass_mind_control',
'spell_malacrass_mark_of_blood');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43498, 'spell_malacrass_siphon_soul'),
(43550, 'spell_malacrass_mind_control'),
(61606, 'spell_malacrass_mark_of_blood');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_malacrass_unstable_affliction' WHERE `ScriptName` = 'spell_hexlord_unstable_affliction';

-- Companions
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+0,24240,568,0,0,1,1,0,1,128.48448,923.04285,33.97255,1.588249564170837402,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+1,24241,568,0,0,1,1,0,1,128.48448,923.04285,33.97255,1.588249564170837402,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+2,24242,568,0,0,1,1,0,0,122.60526,923.24536,33.97256,1.570796370506286621,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+3,24243,568,0,0,1,1,0,0,122.60526,923.24536,33.97256,1.570796370506286621,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+4,24244,568,0,0,1,1,0,0,111.69282,923.15314,33.972576,1.570796370506286621,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+5,24245,568,0,0,1,1,0,0,111.69282,923.15314,33.972576,1.570796370506286621,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+6,24246,568,0,0,1,1,0,0,105.40299,923.3421,33.972588,1.553343057632446289,259200,0,0,0,0,0,0,0,0,'',NULL,12340),
(@CGUID+7,24247,568,0,0,1,1,0,0,105.40299,923.3421,33.972588,1.553343057632446289,259200,0,0,0,0,0,0,0,0,'',NULL,12340);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+7 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,@CGUID+0),
(@SPAWN_GROUP_ID+1,0,@CGUID+1),
(@SPAWN_GROUP_ID+2,0,@CGUID+2),
(@SPAWN_GROUP_ID+3,0,@CGUID+3),
(@SPAWN_GROUP_ID+4,0,@CGUID+4),
(@SPAWN_GROUP_ID+5,0,@CGUID+5),
(@SPAWN_GROUP_ID+6,0,@CGUID+6),
(@SPAWN_GROUP_ID+7,0,@CGUID+7);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+7;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Zul'Aman - Alyson Antille",4),
(@SPAWN_GROUP_ID+1,"Zul'Aman - Thurg",4),
(@SPAWN_GROUP_ID+2,"Zul'Aman - Slither",4),
(@SPAWN_GROUP_ID+3,"Zul'Aman - Lord Raadan",4),
(@SPAWN_GROUP_ID+4,"Zul'Aman - Gazakroth",4),
(@SPAWN_GROUP_ID+5,"Zul'Aman - Fenstalker",4),
(@SPAWN_GROUP_ID+6,"Zul'Aman - Darkheart",4),
(@SPAWN_GROUP_ID+7,"Zul'Aman - Koragg",4);

DELETE FROM `creature_formations` WHERE `leaderGUID` = 89357;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(89357,89357,0,0,3,0,0),
(89357,@CGUID+0,0,0,3,0,0),
(89357,@CGUID+1,0,0,3,0,0),
(89357,@CGUID+2,0,0,3,0,0),
(89357,@CGUID+3,0,0,3,0,0),
(89357,@CGUID+4,0,0,3,0,0),
(89357,@CGUID+5,0,0,3,0,0),
(89357,@CGUID+6,0,0,3,0,0),
(89357,@CGUID+7,0,0,3,0,0);
