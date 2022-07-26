-- Hulking Jormungar - target types & comments
UPDATE `smart_scripts` SET `target_type`= 1 WHERE `entryorguid`= 26293 AND `source_type`=0 AND `id` BETWEEN 1 AND 4;
UPDATE `smart_scripts` SET `comment`= "Hulking Jormungar - On Script - Cast 'Quest - Jormungar Explosion Spell Spawner'" WHERE `entryorguid`= 2629300 AND `source_type`= 9 AND `id`= 1;
UPDATE `smart_scripts` SET `comment`= "Hulking Jormungar - On Script - Cast 'Quest - Jormungar Explosion Summon Object'" WHERE `entryorguid`= 2629300 AND `source_type`= 9 AND `id` BETWEEN 2 AND 9;
UPDATE `smart_scripts` SET `comment`= "Hulking Jormungar - On Script - Cast 'Potent Explosive Charge'" WHERE `entryorguid`= 2629300 AND `source_type`= 9 AND `id`= 10;
