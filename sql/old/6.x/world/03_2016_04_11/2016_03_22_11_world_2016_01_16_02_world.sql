--
DELETE FROM `creature_template_addon` WHERE `entry` IN (16525);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(16525, 1, '29920');

UPDATE `smart_scripts` SET  `event_chance`=100 WHERE `entryorguid`=16525 AND `source_type`=0;
UPDATE `smart_scripts` SET  `event_flags`=3, `event_param1`=0, `event_param2`=0, `event_param3`=0, `event_param4`=0, `action_type`=28, `comment`="Spell Shade - In Combat - Remove Aura 'Phasing Invisibility' (Normal Dungeon)" WHERE `entryorguid`=16525 AND `source_type`=0 AND `id`=3;
