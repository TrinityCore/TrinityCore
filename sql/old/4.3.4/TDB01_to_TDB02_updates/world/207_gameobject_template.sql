UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=206608; -- Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=206610; -- Elevator
UPDATE `gameobject_template` SET `flags`=40,`faction`=114 WHERE `entry`=208471; -- Doodad_org_arena_ivory_pillar01
UPDATE `gameobject_template` SET `flags`=40,`faction`=114 WHERE `entry`=208470; -- Doodad_org_arena_lightning_pillar01
UPDATE `gameobject_template` SET `flags`=40,`faction`=114 WHERE `entry`=208469; -- Doodad_org_arena_pillar01
UPDATE `gameobject_template` SET `flags`=40,`faction`=114 WHERE `entry`=208468; -- Doodad_org_arena_axe_pillar01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=208001; -- The Blightbringer
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=208000; -- The Graceful Maiden
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=207889; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `flags`=40,`faction`=1375 WHERE `entry`=207547; -- Lift of the Makers
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=207209; -- Doodad_Abyssal_Jellyfish_Elevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=206609; -- Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=205080; -- Doodad_GnomeElevatorCar02
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=205079; -- Doodad_GnomeElevatorCar04
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=204246; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=204245; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=204244; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=204243; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=204423; -- Orc Gunship
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=4170; -- Mesa Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=4171; -- Mesa Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=11898; -- Mesa Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=11899; -- Mesa Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=203716; -- Blackwing Descent Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=207834; -- Doodad_BlackWingV2_Elevator_Onyxia01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=196838; -- Doodad_Goblin_PoolElevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=196837; -- Doodad_Goblin_PoolElevator01
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=152614; -- Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=47297; -- Mesa Elevator
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=47296; -- Mesa Elevator

-- Remove double spawn
SET @OGUID :=76;

DELETE FROM `gameobject` WHERE `Id` IN (206608,206610);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 206608, 1, 1, 1, 1704.782, -4265.96, 34.88367, 3.976283, 0, 0, 0.9563048, -0.2923717, 120, 255, 24), -- Elevator
(@OGUID+1, 206610, 1, 1, 1, 1755.314, -4396.597, 42.34779, 3.744939, 0, 0, 0.9563048, -0.2923717, 120, 255, 24); -- Elevator
