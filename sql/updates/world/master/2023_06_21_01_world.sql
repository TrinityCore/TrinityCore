-- Needed for quest a55174 and h59932 "Cooking Meat"

SET @OGUID := 600251;
-- Spawn missing campfire for Horde Exiles Reach Abandoned Camp
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`ScriptName`,`VerifiedBuild`) VALUES
(@OGUID,349962,2175,10424,10453,0,0,0,0,-1,-247.778,-2490.82,18.0611,2.26022,0,0,0.90446,0.426559,7200,255,1,'',44730);

-- Add addon data
DELETE FROM `gameobject_template_addon` WHERE `entry`=349962;
INSERT INTO `gameobject_template_addon` (`entry`,`faction`,`flags`,`mingold`,`maxgold`,`artkit0`,`artkit1`,`artkit2`,`artkit3`,`artkit4`,`WorldEffectID`,`AIAnimKitID`) VALUES
(349962,0,2113540,0,0,0,0,0,0,0,0,0);

-- Add campfires to proper spawngroups
DELETE FROM `spawn_group` WHERE `spawnId` IN (600228,@OGUID);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(128,1,600228), -- Existing Alliance campfire spawn
(129,1,@OGUID); -- New Horde campfire spawn

-- Loot for Campfire
DELETE FROM `gameobject_loot_template` WHERE `Entry`=99778;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(99778,174074,0,100,1,1,0,1,1,'Campfire - Cooked Meat');
