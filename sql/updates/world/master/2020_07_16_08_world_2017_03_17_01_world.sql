-- 
DELETE FROM `spell_scripts` WHERE `id`=38173;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(38173, 0, 0, 15, 39074, 1, 0, 0, 0, 0, 0);
UPDATE `smart_scripts` SET `action_type`=41, `action_param1`=0, `target_type`=1, `comment`='Spirit  - action list - Despawn' WHERE `entryorguid`=2202300 AND `source_type`=9 AND `id`=2;
