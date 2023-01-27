delete from areatrigger_actions where entry = 1489;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `comment`) VALUES 
(1489, 0, 1, 0, 1, 81782, 0, 0, 0, 0, 0, 0, 'Priest: Power Word: Barrier on enter'),
(1489, 1, 42, 1, 1, 81782, 0, 0, 0, 0, 0, 0, 'Priest: Power Word: Barrier on exit');

delete from areatrigger_data where entry = 1489;
INSERT INTO `areatrigger_data` (`entry`, `sphereScale`, `sphereScaleMax`, `isMoving`, `moveType`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `hitType`, `Height`, `RadiusTarget`, `Float5`, `Float4`, `Radius`, `HeightTarget`, `MoveCurveID`, `ElapsedTime`, `comment`) VALUES 
(1489, 6.5, 6.5, 0, 0, 0, 0, 0, 0, 31486, 5802, 0, 0, 0, 0, 0, 6.5, 0, 0, 231, 'test');