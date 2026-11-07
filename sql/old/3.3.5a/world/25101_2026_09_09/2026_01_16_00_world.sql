--
SET @SPAWN_GROUP_ID := 329;

DELETE FROM `spawn_group` WHERE `spawnId` IN (86698,86699,86700,89259,89260,89261,89262,89263,89264,89268,89269,89270,89271) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,86698),
(@SPAWN_GROUP_ID+0,0,86699),
(@SPAWN_GROUP_ID+0,0,86700),

(@SPAWN_GROUP_ID+1,0,89259),
(@SPAWN_GROUP_ID+1,0,89260),
(@SPAWN_GROUP_ID+1,0,89261),
(@SPAWN_GROUP_ID+1,0,89262),

(@SPAWN_GROUP_ID+2,0,89263),
(@SPAWN_GROUP_ID+2,0,89264),

(@SPAWN_GROUP_ID+3,0,89268),
(@SPAWN_GROUP_ID+3,0,89269),
(@SPAWN_GROUP_ID+3,0,89270),
(@SPAWN_GROUP_ID+3,0,89271);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Zul'Aman - Nalorakk - Wave 1",4),
(@SPAWN_GROUP_ID+1,"Zul'Aman - Nalorakk - Wave 2",4),
(@SPAWN_GROUP_ID+2,"Zul'Aman - Nalorakk - Wave 3",4),
(@SPAWN_GROUP_ID+3,"Zul'Aman - Nalorakk - Wave 4",4);

UPDATE `creature` SET `StringId` = 'NalorakkWave1' WHERE `guid` IN (86698,86699,86700);
UPDATE `creature` SET `StringId` = 'NalorakkWave2' WHERE `guid` IN (89259,89260,89261,89262);
UPDATE `creature` SET `StringId` = 'NalorakkWave3' WHERE `guid` IN (89263,89264);
UPDATE `creature` SET `StringId` = 'NalorakkWave4' WHERE `guid` IN (89268,89269,89270,89271);

UPDATE `creature` SET `spawntimesecs` = 259200, `unit_flags` = 33600 WHERE `guid` IN (86698,86699,86700,89259,89260,89261,89262,89263,89264,89268,89269,89270,89271);

DELETE FROM `creature_text` WHERE `CreatureID` = 23576;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23576,0,0,"Get da move on, guards! It be killin' time!",14,0,100,51,0,12066,22144,1,"Nalorakk - SAY_WAVE_1"),
(23576,1,0,"Guards, go already! Who you more afraid of, dem... or me?",14,0,100,51,0,12067,22146,1,"Nalorakk - SAY_WAVE_2"),
(23576,2,0,"Ride now! Ride out dere and bring me back some heads!",14,0,100,51,0,12068,22151,1,"Nalorakk - SAY_WAVE_3"),
(23576,3,0,"I be losin' me patience! Go on: make dem wish dey was never born!",14,0,100,51,0,12069,22155,1,"Nalorakk - SAY_WAVE_4"),
(23576,4,0,"Mua-ha-ha!",14,0,100,0,0,0,22145,1,"Nalorakk - SAY_WAVE_DONE"),
(23576,5,0,"You be dead soon enough!",14,0,100,0,0,12070,23166,1,"Nalorakk - SAY_AGGRO"),
(23576,6,0,"I bring da pain!",14,0,100,0,0,12071,23167,1,"Nalorakk - SAY_SURGE"),
(23576,7,0,"You call on da beast, you gonna get more dan you bargain for!",14,0,100,0,0,12072,23168,1,"Nalorakk - SAY_TO_BEAR "),
(23576,8,0,"Make way for da Nalorakk!",14,0,100,0,0,12073,23169,1,"Nalorakk - SAY_TO_TROLL"),
(23576,9,0,"You had your chance; now it be too late!",14,0,100,0,0,12074,23170,1,"Nalorakk - SAY_BERSERK"),
(23576,10,0,"Now whatchoo got to say?",14,0,100,0,0,12075,23171,1,"Nalorakk - SAY_SLAY_1"),
(23576,10,1,"Da Amani gonna rule again!",14,0,100,0,0,12076,23172,1,"Nalorakk - SAY_SLAY_2"),
(23576,11,0,"I... be waitin' on da udda side....",14,0,100,0,0,12077,23173,1,"Nalorakk - SAY_DEATH"),
(23576,12,0,"What could be better than servin' da bear spirit for eternity? Come closer now. Bring your souls to me!",14,0,100,0,0,12078,23305,1,"Nalorakk - SAY_EVENT_1"),
(23576,13,0,"I smell you, strangers. Don't be delayin' your fate. Come to me now. I make your sacrifice quick.",14,0,100,0,0,12079,23306,1,"Nalorakk - SAY_EVENT_2"),
(23576,14,0,"%s transforms into a bear!",41,0,100,0,0,0,24263,0,"Nalorakk - EMOTE_TRANSFORM");

DELETE FROM `waypoint_data` WHERE `id` IN (1,2,3);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(1,1,6.854601,1420.587,11.948586,NULL,0,1,0,100,0),
(1,2,-17.603733,1420.2533,12.702607,NULL,0,1,0,100,0),
(1,3,-52.46344,1419.6982,27.29911,0,1,1,0,100,0),

(2,1,-55.543488,1419.3763,27.303112,NULL,0,1,0,100,0),
(2,2,-78.06857,1419.0736,27.302307,NULL,0,1,0,100,0),
(2,3,-80.584625,1395.3932,27.132534,NULL,0,1,0,100,0),
(2,4,-80.22266,1375.8348,40.75975,1.570796370506286621,1,1,0,100,0),

(3,1,-80.03189,1315.3905,41.195145,NULL,0,1,0,100,0),
(3,2,-79.59927,1300.4309,48.532497,1.570796370506286621,1,1,0,100,0);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_nalorakk_surge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44019, 'spell_nalorakk_surge');
