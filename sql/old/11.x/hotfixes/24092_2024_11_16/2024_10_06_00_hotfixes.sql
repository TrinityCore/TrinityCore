--
-- Table structure for table `flight_capability`
--
DROP TABLE IF EXISTS `flight_capability`;
CREATE TABLE `flight_capability` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `AirFriction` float NOT NULL DEFAULT '0',
  `MaxVel` float NOT NULL DEFAULT '0',
  `Unknown1000_2` float NOT NULL DEFAULT '0',
  `DoubleJumpVelMod` float NOT NULL DEFAULT '0',
  `LiftCoefficient` float NOT NULL DEFAULT '0',
  `GlideStartMinHeight` float NOT NULL DEFAULT '0',
  `AddImpulseMaxSpeed` float NOT NULL DEFAULT '0',
  `BankingRateMin` float NOT NULL DEFAULT '0',
  `BankingRateMax` float NOT NULL DEFAULT '0',
  `PitchingRateDownMin` float NOT NULL DEFAULT '0',
  `PitchingRateDownMax` float NOT NULL DEFAULT '0',
  `PitchingRateUpMin` float NOT NULL DEFAULT '0',
  `PitchingRateUpMax` float NOT NULL DEFAULT '0',
  `TurnVelocityThresholdMin` float NOT NULL DEFAULT '0',
  `TurnVelocityThresholdMax` float NOT NULL DEFAULT '0',
  `SurfaceFriction` float NOT NULL DEFAULT '0',
  `OverMaxDeceleration` float NOT NULL DEFAULT '0',
  `Unknown1000_17` float NOT NULL DEFAULT '0',
  `Unknown1000_18` float NOT NULL DEFAULT '0',
  `Unknown1000_19` float NOT NULL DEFAULT '0',
  `Unknown1000_20` float NOT NULL DEFAULT '0',
  `Unknown1000_21` float NOT NULL DEFAULT '0',
  `LaunchSpeedCoefficient` float NOT NULL DEFAULT '0',
  `VigorRegenMaxVelCoefficient` float NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
