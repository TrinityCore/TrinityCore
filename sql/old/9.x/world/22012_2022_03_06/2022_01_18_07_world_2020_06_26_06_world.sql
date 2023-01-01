--
-- set creature.modelid to 0 if creature only has a single model defined in creature_template_model and that model matches value in creature table
CREATE TEMPORARY TABLE creature_guids_with_unique_model SELECT
  c.guid 
FROM
  `creature` c
  INNER JOIN (
  SELECT
    SUM(ctm.CreatureDisplayID) AS CreatureDisplayID, -- SUM works around GROUP BY requirementof sql_mode=ONLY_FULL_GROUP_BY, we can do this because we are selecting only 1 row
    ctm.CreatureID AS CreatureID 
  FROM
    creature_template_model ctm 
  GROUP BY
    ctm.CreatureID 
  HAVING
    COUNT(ctm.CreatureDisplayID) = 1 
  ) uniq_models ON c.id = uniq_models.CreatureID 
  AND c.modelid = uniq_models.CreatureDisplayID;

UPDATE `creature` SET `modelid`=0 WHERE `guid` IN (SELECT * FROM creature_guids_with_unique_model);

-- UPDATE `creature` a LEFT JOIN `creature_template` b ON a.`id` = b.`entry` SET `modelid` = 0 WHERE a.`id` IN (SELECT b.`entry` FROM `creature_template` WHERE b.`modelid1` != 0 AND b.`modelid2` = 0 AND b.`modelid3` = 0 AND b.`modelid4` = 0) AND a.`modelid` = b.`modelid1`;
-- UPDATE `creature` a LEFT JOIN `creature_template` b ON a.`id` = b.`entry` SET `modelid` = 0 WHERE a.`id` IN (SELECT b.`entry` FROM `creature_template` WHERE b.`modelid1` = 0 AND b.`modelid2` != 0 AND b.`modelid3` = 0 AND b.`modelid4` = 0) AND a.`modelid` = b.`modelid2`;
-- UPDATE `creature` a LEFT JOIN `creature_template` b ON a.`id` = b.`entry` SET `modelid` = 0 WHERE a.`id` IN (SELECT b.`entry` FROM `creature_template` WHERE b.`modelid1` != 0 AND b.`modelid2` != 0 AND b.`modelid3` != 0 AND b.`modelid4` != 0) AND (a.`modelid` = b.`modelid1` OR a.`modelid` = b.`modelid2` OR a.`modelid` = b.`modelid3` OR a.`modelid` = b.`modelid4`);
UPDATE `creature` SET `modelid` = 0 WHERE `id`=1505;
