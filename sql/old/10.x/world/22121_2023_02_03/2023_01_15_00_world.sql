-- Dragonflight
SET @CGUIDNEWSTART := 9000000;
SET @CGUIDSTART := 1250000;
SET @CGUIDEND := 1449999;
SET @CINCREMENT := @CGUIDNEWSTART - @CGUIDSTART;

-- Gaps:
-- 9000973, 9000974

UPDATE `creature` SET `guid`=`guid`+@CINCREMENT WHERE `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `creature_addon` SET `guid`=`guid`+@CINCREMENT WHERE `path_id` = 0 AND `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `creature_addon` SET `guid`=`guid`+@CINCREMENT, `path_id`=`path_id`+(@CINCREMENT*10) WHERE `path_id` != 0 AND `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `waypoint_data` SET `id`=`id`+(@CINCREMENT*10) WHERE `id` BETWEEN @CGUIDSTART*10 AND @CGUIDEND*10;
UPDATE `creature_formations` SET `leaderGUID`=`leaderGUID`+@CINCREMENT WHERE `leaderGUID` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `creature_formations` SET `memberGUID`=`memberGUID`+@CINCREMENT WHERE `memberGUID` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `creature_movement_override` SET `SpawnId`=`SpawnId`+@CINCREMENT WHERE `SpawnId` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `game_event_creature` SET `guid`=`guid`+@CINCREMENT WHERE `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `game_event_model_equip` SET `guid`=`guid`+@CINCREMENT WHERE `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `game_event_npc_vendor` SET `guid`=`guid`+@CINCREMENT WHERE `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `game_event_npcflag` SET `guid`=`guid`+@CINCREMENT WHERE `guid` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `pool_members` SET `spawnId`=`spawnId`+@CINCREMENT WHERE `type`=0 AND `spawnId` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `spawn_group` SET `spawnId`=`spawnId`+@CINCREMENT WHERE `spawnType`=0 AND `spawnId` BETWEEN @CGUIDSTART AND @CGUIDEND;
UPDATE `smart_scripts` SET `target_param1`=`target_param1`+@CINCREMENT WHERE `source_type`=0 AND `target_type`=10 AND `entryorguid` BETWEEN -@CGUIDEND AND -@CGUIDSTART;
UPDATE `smart_scripts` SET `entryorguid`=`entryorguid`-@CINCREMENT WHERE `source_type`=0 AND `entryorguid` BETWEEN -@CGUIDEND AND -@CGUIDSTART;
UPDATE `conditions` SET `SourceEntry`=`SourceEntry`-@CINCREMENT WHERE `SourceTypeOrReferenceId`=22 AND `SourceId`=0 AND `SourceEntry` BETWEEN -@CGUIDEND AND -@CGUIDSTART;
UPDATE `conversation_actors` SET `ConversationActorGuid`=`ConversationActorGuid`+@CINCREMENT WHERE `ConversationActorGuid` BETWEEN @CGUIDSTART AND @CGUIDEND;

SET @OGUIDNEWSTART := 9000000;
SET @OINCREMENT := 100000;
SET @OGUIDSTART := 700000;
SET @OGUIDEND := 799999;
SET @OINCREMENT := @OGUIDNEWSTART - @OGUIDSTART;

-- Gaps:
-- 9000030

UPDATE `gameobject` SET `guid`=`guid`+@OINCREMENT WHERE `guid` BETWEEN @OGUIDSTART AND @OGUIDEND;
UPDATE `gameobject_addon` SET `guid`=`guid`+@OINCREMENT WHERE `guid` BETWEEN @OGUIDSTART AND @OGUIDEND;
UPDATE `gameobject_overrides` SET `spawnId`=`spawnId`+@OINCREMENT WHERE `spawnId` BETWEEN @OGUIDSTART AND @OGUIDEND;
UPDATE `game_event_gameobject` SET `guid`=`guid`+@OINCREMENT WHERE `guid` BETWEEN @OGUIDSTART AND @OGUIDEND;
UPDATE `pool_members` SET `spawnId`=`spawnId`+@OINCREMENT WHERE `type`=1 AND `spawnId` BETWEEN @OGUIDSTART AND @OGUIDEND;
UPDATE `spawn_group` SET `spawnId`=`spawnId`+@OINCREMENT WHERE `spawnType`=1 AND `spawnId` BETWEEN @OGUIDSTART AND @OGUIDEND;
UPDATE `smart_scripts` SET `entryorguid`=`entryorguid`-@OINCREMENT WHERE `source_type`=1 AND `entryorguid` BETWEEN -@OGUIDEND AND -@OGUIDSTART;
UPDATE `conditions` SET `SourceEntry`=`SourceEntry`-@OINCREMENT WHERE `SourceTypeOrReferenceId`=22 AND `SourceId`=1 AND `SourceEntry` BETWEEN -@OGUIDEND AND -@OGUIDSTART;
