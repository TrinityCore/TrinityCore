-- Fix spamming of spell Ball of Flame (48246)
UPDATE `smart_scripts` SET `event_type`=54, `event_param1`=0, `event_param2`=0, `event_param3`=0, `event_param4`=0 WHERE `entryorguid`=27273;
