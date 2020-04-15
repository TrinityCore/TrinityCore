-- 
SET @CGUID     := 81116;
SET @EVENT_ID := 74;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2 AND `eventEntry`=@EVENT_ID;
INSERT INTO `game_event_creature` SELECT @EVENT_ID, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+2;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+3 AND @CGUID+5 AND `eventEntry`=@EVENT_ID+1;
INSERT INTO `game_event_creature` SELECT @EVENT_ID+1, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+3 AND @CGUID+5;
