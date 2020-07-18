--
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800, `action_param1`=9532, `comment`="Bloodscalp Mystic - In Combat CMC - Cast 'Lightning Bolt'" WHERE `entryorguid`=701 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=701 AND `source_type`=0 AND `id`=5;
