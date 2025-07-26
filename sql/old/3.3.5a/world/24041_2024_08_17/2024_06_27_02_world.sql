-- Desolace, Sar'theris Strand GY
DELETE FROM `graveyard_zone` WHERE `ID` = 1422 AND `GhostZone` = 2100;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(1422,2100,0,"Desolace, Sar'theris Strand GY");

-- Also delete most likely wrong linked GY
DELETE FROM `graveyard_zone` WHERE `ID`=31 AND `GhostZone`=2100;

-- Ghost Walker Post Spirit Healer Update
UPDATE `creature` SET `position_x`=-1432.9971923828125, `position_y`=1973.572265625, `position_z`=86.70270538330078125, `orientation`=3.246312379837036132, `spawntimesecs`=120, `VerifiedBuild`=55141 WHERE `guid`=40568 AND `id`=6491;
