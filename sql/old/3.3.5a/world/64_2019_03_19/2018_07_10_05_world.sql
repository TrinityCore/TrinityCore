-- correct the emotes for Warosh:
UPDATE `creature_text` SET `Type`= 16    WHERE `CreatureID`= 10799 AND `ID`= 3;
UPDATE `creature_text` SET `Language`= 0 WHERE `CreatureID`= 10799 AND `ID`= 2;
-- remove skinning loot from Spirestone Mystic NPCs and Bijou:
UPDATE `creature_template` SET `skinloot`= 0 WHERE `entry` IN (9198, 10257);
DELETE FROM `skinning_loot_template`  WHERE `entry` IN (9198);
