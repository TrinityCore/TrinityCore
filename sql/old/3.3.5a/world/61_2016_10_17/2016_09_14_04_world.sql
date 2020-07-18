-- Krolmir, Hammer of Storms (quest 13010): Set correct target_type for Quest Kill Credit
UPDATE `smart_scripts` SET `target_type`=23 WHERE `entryorguid`=3033100 AND `source_type`=9 AND `id`=17;
