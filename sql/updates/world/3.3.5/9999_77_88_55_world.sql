SET @Najentus=22887;

-- Disable PathFinding for High Warlord Naj'entus
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry`=@Najentus;

UPDATE `creature_addon` SET `auras`=19818 WHERE `guid`=40527;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_najentus_needle_spine';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39992,'spell_najentus_needle_spine');

DELETE FROM `creature_text` WHERE `entry`=@Najentus AND `groupid` IN(4,5,6);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Najentus,4,0,'Bal, lamer zhita!',14,0,100,0,0,11457,21095,0,'najentus SAY_ENRAGE1'),
(@Najentus,4,1,'My patience has run out! Die! Die!',14,0,100,0,0,11458,21096,0,'najentus SAY_ENRAGE2'),
(@Najentus,5,0,'Lord Illidan will... crush you!',14,0,100,0,0,11459,21093,0,'najentus SAY_DEATH');
