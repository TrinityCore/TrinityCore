SET @OLD_GUID := 79897;
SET @NEW_GUID := 3808530;

UPDATE `gameobject` SET `guid`=`guid`-@OLD_GUID+@NEW_GUID WHERE `guid` BETWEEN @OLD_GUID AND @OLD_GUID+61;
UPDATE `gameobject_addon` SET `guid`=`guid`-@OLD_GUID+@NEW_GUID WHERE `guid` BETWEEN @OLD_GUID AND @OLD_GUID+61;
UPDATE `game_event_gameobject` SET `guid`=`guid`-@OLD_GUID+@NEW_GUID WHERE `guid` BETWEEN @OLD_GUID AND @OLD_GUID+61;
