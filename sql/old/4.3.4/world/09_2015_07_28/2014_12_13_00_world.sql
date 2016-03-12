-- Ungroup some improperly grouped texts and set their text range
UPDATE `creature_text` SET `TextRange` = 3 WHERE `entry` = 15990 AND `groupid` = 5;
UPDATE `creature_text` SET `groupid` = 16, `TextRange` = 3, `id` = 0 WHERE `entry` = 15990 AND `groupid` = 6 AND `id` = 0;
UPDATE `creature_text` SET `groupid` = 17, `TextRange` = 3, `id` = 0 WHERE `entry` = 15990 AND `groupid` = 6 AND `id` = 1;
UPDATE `creature_text` SET `groupid` = 18, `TextRange` = 3, `id` = 0 WHERE `entry` = 15990 AND `groupid` = 6 AND `id` = 2;
UPDATE `creature_text` SET `groupid` = 19, `TextRange` = 3, `id` = 0 WHERE `entry` = 15990 AND `groupid` = 6 AND `id` = 3;
