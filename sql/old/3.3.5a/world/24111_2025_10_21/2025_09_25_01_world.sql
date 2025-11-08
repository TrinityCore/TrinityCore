-- Update Lady Hoteshem Equipment, SheathState and level.
UPDATE `creature_equip_template` SET `ItemID1`=19981, `VerifiedBuild`=0 WHERE `CreatureID`=15008 AND `ID`=1;
UPDATE `creature_template_addon` SET `SheathState`=0 WHERE `entry`=15008;
UPDATE `creature_template` SET `minlevel`=61, `maxlevel`=61 WHERE `entry`=15008;
