-- Fix Jewelcrafting stone statues for charm SAI changes
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18372,18738) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`event_type`,`event_chance`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(18372,0,1,100,11,32253,23,"Rough Stone Statue - OOC - Cast 'Stone Healing'"),
(18738,0,1,100,11,32792,23,"Primal Stone Statue - OOC - Cast 'Stone Healing'");
UPDATE `creature_template` SET `AIName`="SmartAI",`ScriptName`="" WHERE `entry` IN (18372,18738);
UPDATE `smart_scripts` SET `event_flags`=(`event_flags`|0x200) WHERE `entryorguid` IN (18372,18734,18735,18736,18737,18738) AND `source_type`=0;
