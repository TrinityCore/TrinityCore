-- Fix equipment for Southsea Swashbuckler (verified with vmangos data)
UPDATE `creature_equip_template` SET `ItemID1`=1897, `ItemID2`=0, `VerifiedBuild`=31727 WHERE `CreatureID`=7858;
