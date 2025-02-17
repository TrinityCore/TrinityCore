-- Bodley - Pieces of Lord Valthalak's Amulet: Set correct spellID for recover gossips
UPDATE `smart_scripts` SET `action_param1`=27542,`comment`='Bodley - On Gossip Select - Cast Add Item Top' WHERE `entryorguid`=16033 AND `source_type`=0 AND `event_param1`=57015 AND `event_param2`=0;
UPDATE `smart_scripts` SET `action_param1`=27544,`comment`='Bodley - On Gossip Select - Cast Add Item Left' WHERE `entryorguid`=16033 AND `source_type`=0 AND `event_param1`=57015 AND `event_param2`=1;
