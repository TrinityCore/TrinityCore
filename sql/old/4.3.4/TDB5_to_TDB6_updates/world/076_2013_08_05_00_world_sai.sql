-- Fix Redridge Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=430 AND `id`=12;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=430 AND `id`=11;
