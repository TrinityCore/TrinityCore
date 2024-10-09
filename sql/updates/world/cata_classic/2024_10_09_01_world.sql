UPDATE `creature_template` SET `faction`=29, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=173758; -- Overlord Runthak

DELETE FROM `creature_template_addon` WHERE `entry`=173758;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(173758, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 173758 (Overlord Runthak)

UPDATE `creature_template_difficulty` SET `MinLevel`=60, `MaxLevel`=60, `StaticFlags1`=536870912, `VerifiedBuild`=56713 WHERE (`Entry`=173758 AND `DifficultyID`=0); -- 173758 (Overlord Runthak) - Floating

DELETE FROM `gameobject_template` WHERE `entry`=204661;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(204661, 8, 9688, 'Brazier', '', '', '', 3.848851919174194335, 0, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56713); -- Brazier
