-- Scourge Tactics
UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid`=30273 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=30273 AND `id`=1;
-- Abjurist Belmara & Conjurer Luminrath 
UPDATE `smart_scripts` SET `target_type`=7 WHERE `entryorguid`=19546 AND `id`=2;
UPDATE `smart_scripts` SET `target_type`=7, `target_param1`=0 WHERE `entryorguid`=19580 AND `id`=2;
