DELETE FROM `area_trigger` WHERE ID IN(3646, 3647);
INSERT INTO `area_trigger` (`PosX`, `PosY`, `PosZ`, `ID`, `ContinentID`, `PhaseUseFlags`, `PhaseID`, `PhaseGroupID`, `Radius`, `BoxLength`, `BoxWidth`, `BoxHeight`, `BoxYaw`, `ShapeType`, `ShapeID`, `AreaTriggerActionSetID`, `Flags`, `VerifiedBuild`) VALUES 
('1540.42', '1481.32', '351.828', '3646', '489', '0', '0', '0', '4', '0.3333', '0.3333', '0.3333', '0', '0', '0', '0', '0', '0'),
('916.023', '1434.41', '345.413', '3647', '489', '0', '0', '0', '4', '0.3333', '0.3333', '0.3333', '0', '0', '0', '0', '0', '0');

DELETE FROM `hotfix_data` WHERE TableHash = 441483745 AND RecordId IN(3646, 3647);
INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES
('1', '441483745', '3646', '0'),
('2', '441483745', '3647', '0');
