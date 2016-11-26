SET @Guid:=86240;
UPDATE `creature` SET `spawntimesecs`=86400 WHERE `guid` BETWEEN @Guid AND @Guid+12;
SET @Guid:=52664;
UPDATE `creature` SET `spawntimesecs`=86400 WHERE `guid` BETWEEN @Guid AND @Guid+4;
SET @Guid:=91573;
UPDATE `creature` SET `spawntimesecs`=86400 WHERE `guid` BETWEEN @Guid AND @Guid+14;
