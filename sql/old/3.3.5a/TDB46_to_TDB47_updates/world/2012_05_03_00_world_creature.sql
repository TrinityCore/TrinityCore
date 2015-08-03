SET @GUID1 := 42158;
SET @GUID2 := 42159;
-- add creature
DELETE FROM creature WHERE guid IN (@GUID1,@GUID2);
INSERT INTO `creature`
(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`)
VALUES
(@GUID1 ,38453,571,1,1,3561.821,-2736.367,136.0317,0), -- Arcturis in Grizzly Hills
(@GUID2,35189,571,1,1,7101.845,-1443.734,924.2609,0.178631); -- Skoll in The Storm Peaks
-- Update template
UPDATE `creature_template` SET `faction_A` = 190, `faction_H`=190 WHERE `entry` IN (38453,35189);
SET @NPC= @GUID1*10;
-- Add pathing for Arcturis
DELETE FROM `creature_addon` WHERE `guid` = @GUID1;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID1,@NPC,0,0,0,0,''); -- Add path for Acturis
-- Add waypoint data for the path:
DELETE FROM `waypoint_data` WHERE `id`=@NPC;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@NPC,1,3563.499,-2737.698,137.1898),
(@NPC,2,3565.249,-2738.698,138.4398),
(@NPC,3,3566.749,-2739.948,139.9398),
(@NPC,4,3568.249,-2740.698,140.6898),
(@NPC,5,3567.839,-2741.380,141.9256),
(@NPC,6,3569.999,-2741.948,142.1898),
(@NPC,7,3570.749,-2742.448,143.1898),
(@NPC,8,3572.676,-2743.528,144.8479);
-- Spawntimefix
UPDATE `creature` SET `spawntimesecs`=39600 WHERE `guid` IN (@GUID1,@GUID2); -- Set the spawntime to 11 hours for Arcturis & Skoll
