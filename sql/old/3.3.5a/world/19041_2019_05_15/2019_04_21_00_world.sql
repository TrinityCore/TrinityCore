-- 
UPDATE `gameobject_template` SET `data3`=3000 WHERE `Entry`=182052;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (182052) AND `source_type`=1 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (182052) AND `source_type`=1 AND `id`=6;
