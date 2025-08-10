-- Remove wrong ItemID2 from Mathrengyl Bearwalker
UPDATE `creature_equip_template` SET `ItemID2`=0, `VerifiedBuild`=12340 WHERE `CreatureID`=4217;
