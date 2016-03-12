-- 
DELETE FROM `areatrigger_scripts` WHERE `entry`=3587;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(3587, 'at_ancient_leaf');
DELETE FROM `creature` WHERE `id` IN (14524, 14525, 14526);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=1;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(1, 2, 1, 14524, 6204.051758, -1172.575684, 370.079224, 0.86052, 3, 100000),
(1, 2, 1, 14525, 6246.953613, -1155.985718, 366.182953, 2.90269, 3, 100000),
(1, 2, 1, 14526, 6193.449219, -1137.834106, 366.260529, 5.77332, 3, 100000); 
