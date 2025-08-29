DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_ravager', 'spell_warr_ravager_damage_rage_gain');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(228920, 'spell_warr_ravager'),
(156287, 'spell_warr_ravager_damage_rage_gain');

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=76168 AND `ID`=41);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(76168, 41, 21679, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Ravager

DELETE FROM `creature_template_addon` WHERE `entry`=76168;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(76168, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, '153709'); -- 76168 (Ravager) - Ravager

UPDATE `creature_template` SET `unit_flags`=0x02000000, `unit_flags2`=0x4000800, `unit_flags3`=0x41008000  WHERE `entry`=76168;

UPDATE `creature_template_difficulty` SET `StaticFlags1`=`StaticFlags1`|0x10000000, `StaticFlags3`=`StaticFlags3`|0x02000000, `StaticFlags5`=`StaticFlags5`|0x00002000 WHERE `Entry`=76168;
