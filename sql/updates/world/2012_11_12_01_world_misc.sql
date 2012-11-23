-- update quest linking for Egg Collection
UPDATE `quest_template` SET `NextQuestId`=5522 WHERE `Id`=4735;
-- --------------------------------------------------------------------------------------------------------------
-- Test of Endurance (Gecko32)
DELETE FROM `event_scripts` WHERE `id`=747 AND `command`=10 AND `datalong`=4100; -- Remove summon of Screeching Harpies
UPDATE `event_scripts` SET `delay`=5 WHERE `id`=747 AND `command`=10 AND `datalong`=4490; -- Lower summon time of Grenka Bloodscreech from 40 sec to 5 sec
-- --------------------------------------------------------------------------------------------------------------
-- Tapper Swindlekeg (24711) fix Alliance faction exploitation (nelgano)
UPDATE `creature_template` SET `unit_flags`=4864 WHERE `entry`=24711;
-- --------------------------------------------------------------------------------------------------------------
DELETE FROM `gameobject` WHERE `guid`=335;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(335,1684,1,1,1,1524.929,-4371.182,17.94367,1.62046,0,0,0,1,300,100,1);
