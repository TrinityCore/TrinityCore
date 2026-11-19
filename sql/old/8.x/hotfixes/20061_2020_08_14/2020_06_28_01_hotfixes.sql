DELETE FROM `hotfix_blob` WHERE `TableHash` = 3386943305 AND `RecordId` = 113690 AND `VerifiedBuild` > 0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `Blob`, `VerifiedBuild`) VALUES (3386943305, 113690, 0x066E6E070B4F0100000000081800000000000000000000000000000001000000000000800082B30100, 34769);

DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 113773 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 113723 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 113690 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 113685 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 111729 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 111716 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 111709 AND `VerifiedBuild` > 0;
DELETE FROM `hotfix_data` WHERE `Id` = 56765 AND `TableHash` = 3386943305 AND `RecordId` = 111706 AND `VerifiedBuild` > 0;
INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`, `VerifiedBuild`) VALUES 
(56765, 3386943305, 113773, 1, 34769),
(56765, 3386943305, 113723, 1, 34769),
(56765, 3386943305, 113690, 0, 34769),
(56765, 3386943305, 113685, 1, 34769),
(56765, 3386943305, 111729, 1, 34769),
(56765, 3386943305, 111716, 1, 34769),
(56765, 3386943305, 111709, 1, 34769),
(56765, 3386943305, 111706, 1, 34769);
