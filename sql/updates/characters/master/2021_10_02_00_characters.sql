ALTER TABLE `characters`
  ADD `createTime` bigint(20) NOT NULL DEFAULT '0' AFTER `online`,
  ADD `createMode` tinyint(4) NOT NULL DEFAULT '0' AFTER `createTime`;

 -- AT_LOGIN_FIRST: Characters that have never logged in have accurate creation timestamp in `logout_time`
UPDATE `characters` SET `createTime`=`logout_time` WHERE (`at_login` & 0x20) != 0;
 -- attempt to find lowest criteria timestamp for characters that have logged in already
UPDATE `characters` SET `createTime`=(SELECT COALESCE(MIN(candidates.`date`), UNIX_TIMESTAMP()) FROM (
SELECT MIN(cap.`date`) `date` FROM `character_achievement_progress` cap WHERE cap.`guid`=`characters`.`guid`
UNION
SELECT MIN(ca.`date`) `date` FROM `character_achievement` ca WHERE ca.`guid`=`characters`.`guid`
) candidates) WHERE (`at_login` & 0x20) = 0;
