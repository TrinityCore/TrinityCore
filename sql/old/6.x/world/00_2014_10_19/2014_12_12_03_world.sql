-- Ungroup some improperly grouped texts and set their text range
UPDATE `creature_text` SET `groupid` = 5, `TextRange` = 3 WHERE `entry` IN (16065, 16064, 30549, 16063) AND `groupid` = 1 AND `id` = 0;
UPDATE `creature_text` SET `groupid` = 6, `TextRange` = 3, `id` = 0 WHERE `entry` IN (16065, 16064, 30549, 16063) AND `groupid` = 1 AND `id` = 1;
