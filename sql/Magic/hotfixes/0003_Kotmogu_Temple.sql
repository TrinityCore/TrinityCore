INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES
('3', '441483745', '7734', '0'),
('4', '441483745', '7735', '0');

DELETE FROM `area_trigger` WHERE ID IN(7734,7735);
INSERT INTO `area_trigger` (`PosX`, `PosY`, `PosZ`, `ID`, `ContinentID`, `PhaseUseFlags`, `PhaseID`, `PhaseGroupID`, `Radius`, `BoxLength`, `BoxWidth`, `BoxHeight`, `BoxYaw`, `ShapeType`, `ShapeID`, `AreaTriggerActionSetID`, `Flags`, `VerifiedBuild`) VALUES
('1783.19', '1333.21', '6.80127', '7734', '998', '0', '0', '0', '0', '145', '178', '40', '1.562', '1', '0', '80', '0', '0'),
('1783.22', '1333.5', '6.80118', '7735', '998', '0', '0', '0', '0', '91', '66', '5', '1.562', '1', '0', '81', '0', '0');
