-- Charm SAI fix for "Escape from Silverbrook"
UPDATE `smart_scripts` SET `event_flags`=(`event_flags`|0x200) WHERE (`entryorguid`=27409 AND `source_type`=0) OR (`entryorguid`=2740900 AND `source_type`=9);
