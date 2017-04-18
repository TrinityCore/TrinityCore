-- delete frogger spawn locations from `creature`, move them to `creature_summon_groups`
SET @FROGGER = 16027;
DELETE FROM `creature` WHERE `id` = @FROGGER;
DELETE FROM `creature_summon_groups` WHERE `summonerId`=533 AND `summonerType`=2;
INSERT INTO `creature_summon_groups` (`summonerType`,`summonerId`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(2,533,0,@FROGGER,3175.281,-3134.764,293.4368,4.244924,3,7500),
(2,533,1,@FROGGER,3154.581,-3126.18 ,293.5911,4.430199,3,7500),
(2,533,2,@FROGGER,3128.622,-3119.604,293.4113,4.738929,3,7500);
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @FROGGER*10+0 AND @FROGGER*10+2;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@FROGGER*10+0,1,3158.253,-3163.889,293.3027),
(@FROGGER*10+1,1,3145.881,-3158.563,293.3215),
(@FROGGER*10+2,1,3130.79 ,-3156.624,293.3239);
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN -76313 AND -76311 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FROGGER AND `source_type`=0 AND `id` BETWEEN 2 AND 5;
UPDATE `creature_template` SET `unit_flags`=(`unit_flags`|256) WHERE `entry`=@FROGGER;
