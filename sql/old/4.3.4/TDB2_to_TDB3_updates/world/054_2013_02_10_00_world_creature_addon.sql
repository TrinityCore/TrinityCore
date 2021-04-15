-- Lordaeron Footman Specimen mounts (Swift Brown Steed)
DELETE FROM `creature_addon` WHERE `guid` IN (175259, 175263, 175225);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`) VALUES
(175263, 0, 14561),
(175259, 0, 14561),
(175225, 0, 14561);
