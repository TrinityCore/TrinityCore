-- fix Sniffing Out the Perpetrator (issue #17914)
UPDATE `smart_scripts` SET `event_flags`= `event_flags`|512 WHERE (`entryorguid` in (29903,29677) and `source_type`=0) OR (`entryorguid` in (2967700,2990300) and `source_type`=9);
UPDATE `smart_scripts` SET `action_param2`=`action_param2`|0x40 WHERE `entryorguid`=29696 AND `source_type`=0 AND `id`=0;
