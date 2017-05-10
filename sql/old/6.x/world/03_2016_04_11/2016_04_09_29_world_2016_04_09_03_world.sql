-- 
DELETE FROM `player_factionchange_reputations` WHERE `alliance_id`= 589;
INSERT INTO `player_factionchange_reputations` (`alliance_id`, `horde_id`) VALUES 
(589, 1137);
UPDATE `creature` SET `equipment_id`=0 WHERE `id` IN(17404);
