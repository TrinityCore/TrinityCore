-- Remove Disarm Immunity
UPDATE `creature_template` SET `CreatureImmunitiesId` = -172 WHERE `entry` IN (31368, 29306);
