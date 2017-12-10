-- Disable PathFinding for High Warlord Naj'entus
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry`=22887;

UPDATE `creature_addon` SET `auras`=19818 WHERE `guid`=40527;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_najentus_needle_spine';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39992,'spell_najentus_needle_spine');

DELETE FROM `creature_text` WHERE `entry`=22887 AND (`groupid` IN(5,6) OR (`groupid`=4 AND `id`=1));
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22887,4,1,'My patience has run out! Die! Die!',14,0,100,0,0,11458,21096,0,"High Warlord Naj'entus SAY_ENRAGE2"),
(22887,5,0,'Lord Illidan will... crush you!',14,0,100,0,0,11459,21093,0,"High Warlord Naj'entus SAY_DEATH");

UPDATE `creature_text` SET `text`='Stick around...',`BroadcastTextId`=21089 WHERE `entry`=22887 AND `groupid`=1 AND `id`=0;
