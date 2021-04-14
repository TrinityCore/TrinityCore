DELETE FROM `spell_target_position` WHERE `ID` IN (323581);
INSERT INTO `spell_target_position`(`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(323581, 0, 2287, -2209.5, 5544.76, 4224.14, 36949),
UPDATE `gameobject_template` SET `Data0`='323581' WHERE  `entry`=349295;