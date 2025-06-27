UPDATE `creature_template` SET `unit_flags`=33555200 WHERe `entry`=17265;
UPDATE `spell_target_position` SET `PositionX`=-11240.5, `PositionY`=-1717.25, `PositionZ`=179.238, `Orientation`=1.32986 WHERE `ID`=30171 AND `EffectIndex`=0;
UPDATE `spell_target_position` SET `PositionX`=-11251.6, `PositionY`=-1703.42, `PositionZ`=179.238, `Orientation`=6.1522 WHERE `ID`=30179 and`EffectIndex`=0;

DELETE FROM `spell_target_position` WHERE `ID`=30120;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`)VALUES
(30120, 0, 532, -11234.2, -1698.46, 179.24, 0.67621, 0);
