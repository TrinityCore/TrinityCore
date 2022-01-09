DROP TABLE IF EXISTS `summon_properties_parameters`;
CREATE TABLE `summon_properties_parameters` (
  `RecID` int UNSIGNED NOT NULL COMMENT 'SummonProperties.dbc Identifier',
  `ParamType` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`RecID`)
);

INSERT INTO `summon_properties_parameters` (`RecID`, `ParamType`) VALUES
-- Converted values from Spell::EffectSummonType and some new additions
(65, 7),
(64, 2),
(61, 2),
(67, 2),
(711, 1),
(81, 1),
(63, 1),
(1761, 2),
(41, 2),
(2909, 2),
(1101, 2),
(66, 2),
(648, 2),
(2301, 2),
(1061, 2),
(1261, 2),
(629, 2),
(181, 2),
(715, 2),
(1562, 2),
(833, 2),
(1161, 2),
(713, 2),
(3097, 2),
(2929, 2),
-- Vehicles (summon properties control 4)
(161, 4), -- Most spells with that ID use bp = 0 but one does actually use a ride spell so we can assume a RIDE_VEHICLE_HARDCODED fallback for parameter 4
(327, 3),
(367, 3),
(467, 3),
(488, 4), -- Ride spell
(493, 3),
(607, 4), -- Ride spell
(689, 4), -- Ride spell
(708, 4), -- Ride Spell
(710, 4), -- Ride Spell
(716, 4), -- Ride Spell
(718, 4), -- Ride Spell
(760, 4), -- Ride Spell
(780, 3),
(801, 4), -- Ride Spell
(824, 4), -- Ride Spell
(827, 4), -- Ride Spell
(843, 4), -- Ride Spell
(861, 4), -- Ride Spell
(1081, 4), -- Ride Spell
(1201, 3),
(1281, 4), -- Ride Spell
(1321, 3),
(1541, 4), -- Ride Spell
(1601, 4), -- Ride Spell
(1621, 4), -- Ride Spell
(1641, 3),
(1821, 4), -- Ride Spell
(1861, 3),
(2321, 3),
(2601, 3),
(2742, 3),
(2914, 3),
(2932, 4), -- Ride Spell
(2933, 3),
(2947, 3),
(2948, 4), -- Ride Spell
(2976, 3),
(2977, 3),
(2986, 3),
(3006, 3),
(3021, 4), -- Ride Spell
(3033, 3),
(3035, 4), -- Ride Spell
(3038, 4), -- Ride Spell
(3090, 4), -- Ride Spell
(3099, 4), -- Ride Spell
(3105, 4), -- Ride Spell
(3112, 4), -- Ride Spell
(3118, 3),
(3131, 3),
(3134, 4), -- Ride Spell
(3144, 3);
