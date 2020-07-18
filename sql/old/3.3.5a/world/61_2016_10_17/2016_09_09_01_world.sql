-- Fix SAI for quest "No Place to Run" (issue #16291)
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~0x4 WHERE `entry`=27430;
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|0x200 WHERE `entryorguid`=2743000 AND `source_type`=9;
UPDATE `smart_scripts` SET `event_type`=54,`comment`="Destructive Ward - On Just Summoned - Run Script" WHERE `entryorguid`=27430 AND `id`=0;
