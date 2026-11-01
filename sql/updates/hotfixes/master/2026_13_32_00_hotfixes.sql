-- Vehicle 6372 is the ceremonial brutosaur howdah used by the player caravan mounts.
-- It is flagged no-strafe / no-jump, so the client plays the forward run while strafing.
-- Player mount vehicles (the mammoth, the yak) only set 0x40000000 and FlagsB 1, which
-- lets the mount turn onto the diagonal. The seats stay the howdah seats.

DELETE FROM `vehicle` WHERE `ID` = 6372;
INSERT INTO `vehicle` (`ID`, `Flags`, `FlagsB`, `TurnSpeed`, `PitchSpeed`, `PitchMin`, `PitchMax`, `MouseLookOffsetPitch`, `CameraFadeDistScalarMin`, `CameraFadeDistScalarMax`, `CameraPitchOffset`, `FacingLimitRight`, `FacingLimitLeft`, `CameraYawOffset`, `VehicleUIIndicatorID`, `MissileTargetingID`, `VehiclePOITypeID`, `SeatID1`, `SeatID2`, `SeatID3`, `SeatID4`, `SeatID5`, `SeatID6`, `SeatID7`, `SeatID8`, `PowerDisplayID1`, `PowerDisplayID2`, `PowerDisplayID3`, `VerifiedBuild`) VALUES
(6372, 1073741824, 1, 3.14159, 3.14159, 0, 0, 0.785398, 1, 1.5, 0, 0, 0, 0, 0, 0, 0, 19992, 19993, 19994, 0, 0, 0, 0, 0, 0, 0, 0, 69933);

DELETE FROM `hotfix_data` WHERE `Id` = 112551;
INSERT INTO `hotfix_data` (`Id`, `UniqueId`, `TableHash`, `RecordId`, `Status`, `VerifiedBuild`) VALUES
(112551, 1, 178219711, 6372, 1, 69933);
