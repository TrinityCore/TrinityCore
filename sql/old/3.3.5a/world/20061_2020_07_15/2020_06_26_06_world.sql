--
UPDATE `creature` a LEFT JOIN `creature_template` b ON a.`id` = b.`entry` SET `modelid` = 0 WHERE a.`id` IN (SELECT b.`entry` FROM `creature_template` WHERE b.`modelid1` != 0 AND b.`modelid2` = 0 AND b.`modelid3` = 0 AND b.`modelid4` = 0) AND a.`modelid` = b.`modelid1`;
UPDATE `creature` a LEFT JOIN `creature_template` b ON a.`id` = b.`entry` SET `modelid` = 0 WHERE a.`id` IN (SELECT b.`entry` FROM `creature_template` WHERE b.`modelid1` = 0 AND b.`modelid2` != 0 AND b.`modelid3` = 0 AND b.`modelid4` = 0) AND a.`modelid` = b.`modelid2`;
UPDATE `creature` a LEFT JOIN `creature_template` b ON a.`id` = b.`entry` SET `modelid` = 0 WHERE a.`id` IN (SELECT b.`entry` FROM `creature_template` WHERE b.`modelid1` != 0 AND b.`modelid2` != 0 AND b.`modelid3` != 0 AND b.`modelid4` != 0) AND (a.`modelid` = b.`modelid1` OR a.`modelid` = b.`modelid2` OR a.`modelid` = b.`modelid3` OR a.`modelid` = b.`modelid4`);
UPDATE `creature` SET `modelid` = 0 WHERE `id`=1505;
