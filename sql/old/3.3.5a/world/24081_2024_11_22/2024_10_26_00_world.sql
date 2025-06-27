-- Stormwind Guard movement update
SET @GUID=79875;
SET @PATH=@GUID * 10;

UPDATE `creature` SET `MovementType`=0 WHERE `guid`=@GUID;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=@GUID AND `path_id`=@PATH;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
