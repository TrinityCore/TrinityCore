-- Replaces deprecated items for the new ones
UPDATE `npc_vendor` SET `item`=37736 WHERE `entry` IN (23710,27478) AND `item`=37571; -- Belbi Quikswitch/Larkin Thunderbrew
UPDATE `npc_vendor` SET `item`=37737 WHERE `entry`=27489 AND `item`=37599; -- Ray'ma
