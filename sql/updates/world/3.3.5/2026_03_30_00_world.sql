--
SET @CGUID := 147451; -- 10
SET @SPAWN_GROUP_ID := 347; -- 10

-- Trigger for fishing
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+0,21252,548,0,0,1,1,0,0,40.55804443359375,-415.83349609375,11.35667705535888671,3.333578824996948242,300,0,0,0,0,0,0,0,0,'',NULL,15595);

-- Strange Pool
UPDATE `gameobject` SET `spawntimesecs` = 5 WHERE `id` = 184956;

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Serpentshrine Cavern - The Lurker Below - Strange Pool",4);

DELETE FROM `spawn_group` WHERE `groupId`=@SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(@SPAWN_GROUP_ID+0,1,9378);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`=@SPAWN_GROUP_ID+0;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(548,1,1,@SPAWN_GROUP_ID+0,1);

-- Lurker
UPDATE `creature_text` SET `Text` = "%s takes a deep breath!", `BroadcastTextId` = 20774 WHERE `CreatureID` = 21217;

UPDATE `creature_template` SET `speed_run` = 1 WHERE `entry` = 21217;

DELETE FROM `spawn_group` WHERE `spawnId` = 93838 AND `spawnType` = 0;
DELETE FROM `creature` WHERE `guid` = 93838;

UPDATE `creature` SET `position_x` = 38.4567, `position_y` = -417.324, `position_z` = -18.916666, `orientation` = 2.9496064, `VerifiedBuild` = 15595 WHERE `id` = 21217;

-- Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+9;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+1,21865,548,0,0,1,1,0,1,99.992676,-275.775,-21.852718,0,604800,0,0,0,0,0,0,0,0,'','CoilfangAmbusher1',0),
(@CGUID+2,21865,548,0,0,1,1,0,1,158.81189,-316.7783,-20.568338,0,604800,0,0,0,0,0,0,0,0,'','CoilfangAmbusher2',0),
(@CGUID+3,21865,548,0,0,1,1,0,1,82.55382,-550.19965,-20.765057,0,604800,0,0,0,0,0,0,0,0,'','CoilfangAmbusher3',0),
(@CGUID+4,21865,548,0,0,1,1,0,1,17.01065,-557.4272,-21.487282,0,604800,0,0,0,0,0,0,0,0,'','CoilfangAmbusher4',0),
(@CGUID+5,21865,548,0,0,1,1,0,1,-14.230728,-549.0762,-21.056725,0,604800,0,0,0,0,0,0,0,0,'','CoilfangAmbusher5',0),
(@CGUID+6,21865,548,0,0,1,1,0,1,-1.9712651,-540.2956,-21.792835,0,604800,0,0,0,0,0,0,0,0,'','CoilfangAmbusher6',0),
(@CGUID+7,21873,548,0,0,1,1,0,1,106.962,-468.5177,-21.63681,0,604800,0,0,0,0,0,0,0,0,'','CoilfangGuardian1',0),
(@CGUID+8,21873,548,0,0,1,1,0,1,65.17899,-340.6617,-21.5217,0,604800,0,0,0,0,0,0,0,0,'','CoilfangGuardian2',0),
(@CGUID+9,21873,548,0,0,1,1,0,1,-49.6826,-414.9719,-20.54604,0,604800,0,0,0,0,0,0,0,0,'','CoilfangGuardian3',0);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+1 AND @CGUID+9 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+1,0,@CGUID+1),
(@SPAWN_GROUP_ID+2,0,@CGUID+2),
(@SPAWN_GROUP_ID+3,0,@CGUID+3),
(@SPAWN_GROUP_ID+4,0,@CGUID+4),
(@SPAWN_GROUP_ID+5,0,@CGUID+5),
(@SPAWN_GROUP_ID+6,0,@CGUID+6),
(@SPAWN_GROUP_ID+7,0,@CGUID+7),
(@SPAWN_GROUP_ID+8,0,@CGUID+8),
(@SPAWN_GROUP_ID+9,0,@CGUID+9);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+1 AND @SPAWN_GROUP_ID+9;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+1,"Serpentshrine Cavern - The Lurker Below - Coilfang Ambusher 000",4),
(@SPAWN_GROUP_ID+2,"Serpentshrine Cavern - The Lurker Below - Coilfang Ambusher 001",4),
(@SPAWN_GROUP_ID+3,"Serpentshrine Cavern - The Lurker Below - Coilfang Ambusher 002",4),
(@SPAWN_GROUP_ID+4,"Serpentshrine Cavern - The Lurker Below - Coilfang Ambusher 003",4),
(@SPAWN_GROUP_ID+5,"Serpentshrine Cavern - The Lurker Below - Coilfang Ambusher 004",4),
(@SPAWN_GROUP_ID+6,"Serpentshrine Cavern - The Lurker Below - Coilfang Ambusher 005",4),
(@SPAWN_GROUP_ID+7,"Serpentshrine Cavern - The Lurker Below - Coilfang Guardian 000",4),
(@SPAWN_GROUP_ID+8,"Serpentshrine Cavern - The Lurker Below - Coilfang Guardian 001",4),
(@SPAWN_GROUP_ID+9,"Serpentshrine Cavern - The Lurker Below - Coilfang Guardian 002",4);

UPDATE `creature_template` SET `speed_run` = 1.42857, `unit_flags` = 33088 WHERE `entry` IN (21865,21873);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_coilfang_guardian' WHERE `entry` = 21873;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21873 AND `source_type` = 0;

DELETE FROM `waypoint_data` WHERE `id` BETWEEN (@CGUID+1)*10 AND (@CGUID+9)*10;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
((@CGUID+1)*10,1,92.243004,-298.7507,-21.659077,NULL,0,1,0,100,0),
((@CGUID+1)*10,2,84.49333,-321.7264,-21.465435,NULL,0,1,0,100,0),
((@CGUID+1)*10,3,77.754456,-350.17313,-21.798763,NULL,0,1,0,100,0),
((@CGUID+1)*10,4,70.33445,-361.86185,-21.249367,NULL,0,1,0,100,0),
((@CGUID+1)*10,5,69.53108,-363.2255,-19.721577,NULL,1000,1,0,100,0),
((@CGUID+1)*10,6,63.842957,-380.10226,-19.721577,NULL,1000,1,0,100,0),

((@CGUID+2)*10,1,137.52756,-325.2396,-21.659077,NULL,0,1,0,100,0),
((@CGUID+2)*10,2,116.24323,-333.7009,-22.749815,NULL,0,1,0,100,0),
((@CGUID+2)*10,3,90.797005,-354.14273,-22.222033,NULL,0,1,0,100,0),
((@CGUID+2)*10,4,80.9742,-367.69354,-21.554916,NULL,0,1,0,100,0),
((@CGUID+2)*10,5,80.247444,-369.6647,-19.721577,NULL,1000,1,0,100,0),
((@CGUID+2)*10,6,78.43119,-381.565,-19.721577,NULL,1000,1,0,100,0),

((@CGUID+3)*10,1,82.55382,-550.19965,-20.765057,NULL,0,1,0,100,0),
((@CGUID+3)*10,2,78.67844,-528.1855,-21.696247,NULL,0,1,0,100,0),
((@CGUID+3)*10,3,74.803055,-506.17133,-22.627438,NULL,0,1,0,100,0),
((@CGUID+3)*10,4,64.98795,-475.87115,-20.821245,NULL,0,1,0,100,0),
((@CGUID+3)*10,5,64.17319,-473.94498,-19.793468,NULL,1000,1,0,100,0),
((@CGUID+3)*10,6,62.26062,-455.59006,-19.793468,NULL,1000,1,0,100,0),

((@CGUID+4)*10,1,17.01065,-557.4272,-21.487282,NULL,0,1,0,100,0),
((@CGUID+4)*10,2,31.464138,-533.44904,-21.821247,NULL,0,1,0,100,0),
((@CGUID+4)*10,3,45.917625,-509.47086,-22.155212,NULL,0,1,0,100,0),
((@CGUID+4)*10,4,56.789635,-479.80664,-21.487915,NULL,0,1,0,100,0),
((@CGUID+4)*10,5,56.661736,-476.9765,-19.793468,NULL,1000,1,0,100,0),
((@CGUID+4)*10,6,52.19484,-457.6492,-19.793468,NULL,1000,1,0,100,0),

((@CGUID+5)*10,1,-14.230728,-549.0762,-21.056725,NULL,0,1,0,100,0),
((@CGUID+5)*10,2,-10.106049,-527.3586,-21.869858,NULL,0,1,0,100,0),
((@CGUID+5)*10,3,-5.981369,-505.64102,-22.682991,NULL,0,1,0,100,0),
((@CGUID+5)*10,4,-1.541027,-474.3588,-21.293468,NULL,0,1,0,100,0),
((@CGUID+5)*10,5,-0.595155,-470.68518,-19.793468,NULL,1000,1,0,100,0),
((@CGUID+5)*10,6,1.217682,-459.33658,-19.793468,NULL,1000,1,0,100,0),

((@CGUID+6)*10,1,-1.9712651,-540.2956,-21.792835,NULL,0,1,0,100,0),
((@CGUID+6)*10,2,-0.557066,-530.1155,-22.001804,NULL,0,1,0,100,0),
((@CGUID+6)*10,3,0.857133,-519.93536,-22.210773,NULL,0,1,0,100,0),
((@CGUID+6)*10,4,7.354449,-476.18625,-21.18235,NULL,0,1,0,100,0),
((@CGUID+6)*10,5,10.617642,-474.0561,-19.793468,NULL,1000,1,0,100,0),
((@CGUID+6)*10,6,14.129611,-458.14767,-19.793468,NULL,1000,1,0,100,0),

((@CGUID+7)*10,1,106.962,-468.5177,-21.63681,NULL,0,1,0,100,0),
((@CGUID+7)*10,2,91.57517,-454.056,-21.75797,NULL,0,1,0,100,0),
((@CGUID+7)*10,3,76.18838,-439.5943,-21.87912,NULL,0,1,0,100,0),
((@CGUID+7)*10,4,66.96297,-435.1991,-22.1097,NULL,0,1,0,100,0),
((@CGUID+7)*10,5,63.72945,-432.9376,-19.51117,NULL,0,1,0,100,0),
((@CGUID+7)*10,6,63.72945,-432.9376,-19.51117,NULL,1000,1,0,100,0),

((@CGUID+8)*10,1,65.17899,-340.6617,-21.5217,NULL,0,1,0,100,0),
((@CGUID+8)*10,2,60.30697,-351.5978,-21.66059,NULL,0,1,0,100,0),
((@CGUID+8)*10,3,55.43496,-362.534,-21.79948,NULL,0,1,0,100,0),
((@CGUID+8)*10,4,43.63028,-383.6669,-21.65929,NULL,0,1,0,100,0),
((@CGUID+8)*10,5,39.98455,-388.5671,-19.30772,NULL,0,1,0,100,0),
((@CGUID+8)*10,6,39.98455,-388.5671,-19.30772,NULL,1000,1,0,100,0),

((@CGUID+9)*10,1,-49.6826,-414.9719,-20.54604,NULL,0,1,0,100,0),
((@CGUID+9)*10,2,-34.9814,-418.4629,-21.49302,NULL,0,1,0,100,0),
((@CGUID+9)*10,3,-20.28021,-421.9539,-22.44001,NULL,0,1,0,100,0),
((@CGUID+9)*10,4,5.458216,-424.9785,-21.60531,NULL,0,1,0,100,0),
((@CGUID+9)*10,5,10.48551,-427.2359,-19.74024,NULL,0,1,0,100,0),
((@CGUID+9)*10,6,10.48551,-427.2359,-19.74024,NULL,1000,1,0,100,0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (21865,21873);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21865,0,0,"For the Master!",12,0,0,0,0,0,16708,0,"Coilfang Ambusher"),
(21865,0,1,"Illidan reigns! ",12,0,0,0,0,0,16709,0,"Coilfang Ambusher"),
(21865,0,2,"Die, warmblood!",12,0,0,0,0,0,16710,0,"Coilfang Ambusher"),
(21865,0,3,"By Nazjatar's Depths! ",12,0,0,0,0,0,16711,0,"Coilfang Ambusher"),
(21865,0,4,"My blood is like venom!",12,0,0,0,0,0,16712,0,"Coilfang Ambusher"),

(21873,0,0,"For the Master!",12,0,0,0,0,0,16708,0,"Coilfang Guardian"),
(21873,0,1,"Illidan reigns! ",12,0,0,0,0,0,16709,0,"Coilfang Guardian"),
(21873,0,2,"Die, warmblood!",12,0,0,0,0,0,16710,0,"Coilfang Guardian"),
(21873,0,3,"By Nazjatar's Depths! ",12,0,0,0,0,0,16711,0,"Coilfang Guardian"),
(21873,0,4,"My blood is like venom!",12,0,0,0,0,0,16712,0,"Coilfang Guardian");

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_the_lurker_below_spout',
'spell_the_lurker_below_spout_periodic',
'spell_the_lurker_below_spout_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37431, 'spell_the_lurker_below_spout'),
(37429, 'spell_the_lurker_below_spout_periodic'),
(37430, 'spell_the_lurker_below_spout_periodic'),
(37433, 'spell_the_lurker_below_spout_damage');
