-- Update Position
UPDATE `gameobject` SET `position_x` = -8093.76220703125, `position_y` = 842.217041015625, `position_z` = 70.06044769287109375, `orientation` = 6.195094585418701171 WHERE `guid` = 600016; -- Telogrus Rift
UPDATE `gameobject` SET `position_x` = -8097.5068359375, `position_y` = 877.78472900390625, `position_z` = 73.15813446044921875, `orientation` = 4.330598354339599609 WHERE `guid` = 500390; -- Mechagon City Teleporter
UPDATE `gameobject` SET `position_x` = -8123.97412109375, `position_y` = 887.9617919921875, `position_z` = 77.41033935546875, `orientation` = 5.340395450592041015, `rotation2` = -0.45412921905517578, `rotation3` = 0.890935838222503662 where `guid` = 600017; -- Lightforged Beacon

UPDATE `creature` SET `position_x` = -8123.97412109375, `position_y` = 887.9617919921875, `position_z` = 77.41033935546875, `orientation` = 5.340395450592041015 WHERE `guid` = 1050137; -- Lightforged Beacon
UPDATE `creature` SET `position_x` = -8119.27099609375, `position_y` = 859.91668701171875, `position_z` = 76.33740234375, `orientation` = 1.60172891616821289 WHERE `guid` = 850185; -- Mole Machine to Stormwind City

UPDATE `areatrigger` SET `PosX` = -8097.506, `PosY` = 877.784, `PosZ` = 73.1581, `Orientation` = 4.33059 WHERE `SpawnId` = 4 AND `IsCustom` = 1;

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (10035, 10034, 11955, 14601);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10035, 'Cosmetic - See Rift to Telogrus'),
(10034, 'Cosmetic - See Lightforged Beacon'),
(11955, 'Cosmetic - See Mole Machine to Stormwind City'),
(14601, 'Cosmetic - See Mechagon City Teleporter');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (10035, 10034, 11955, 14601) AND `SourceEntry` = 1519;
