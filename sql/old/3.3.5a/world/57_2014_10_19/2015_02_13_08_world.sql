--
UPDATE `smart_scripts` SET `action_param1`=25068 WHERE  `entryorguid`=25002 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=35427;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(35427,43671,1,0);

UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=38162 WHERE  `entryorguid`=19937 AND `source_type`=0 AND `id` IN (1, 3, 12);
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=70606 WHERE  `entryorguid`=37826 AND `source_type`=0 AND `id` = 0;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=25359 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=6 WHERE  `entryorguid`=25335 AND `source_type`=0 AND `id`=5;
UPDATE `smart_scripts` SET `link`=10 WHERE  `entryorguid`=25335 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `event_type`=61, `link`=0 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=21;
UPDATE `smart_scripts` SET `event_param1`=0 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=23;
UPDATE `smart_scripts` SET `link`=16 WHERE  `entryorguid`=28122 AND `source_type`=0 AND `id`=15;
