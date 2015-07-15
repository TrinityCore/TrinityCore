-- The Farstrider Lodge flavor texts
DELETE FROM `gossip_menu` WHERE `text_id` IN (3522, 3525, 3495);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(2831, 3522),
(2831, 3525),
(2801, 3495);

-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceEntry` IN (3522, 3525, 3495, 3523) AND `ConditionTypeOrReference` IN (8);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 2831, 3523, 0, 0, 8, 0, 258, 0, 0, 1, 0, 0, '', 'Show gossip text if player has quest 258 not completed'),
(14, 2831, 3522, 0, 0, 8, 0, 258, 0, 0, 0, 0, 0, '', 'Show gossip text if player has quest 258 completed'),
(14, 2831, 3525, 0, 0, 8, 0, 271, 0, 0, 0, 0, 0, '', 'Show gossip text if player has quest 271 completed'),
(14, 2801, 3495, 0, 0, 8, 0, 385, 0, 0, 0, 0, 0, '', 'Show gossip text if player has quest 385 completed');

UPDATE `npc_text` SET `BroadcastTextID0`=5854 WHERE `id`=3522;
