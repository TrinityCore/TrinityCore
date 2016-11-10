SET @Najentus=22887;

-- Disable PathFinding for High Warlord Naj'entus
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry`=@Najentus;

UPDATE `creature_addon` SET `auras`=19818 WHERE `guid`=40527;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_najentus_needle_spine';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39992,'spell_najentus_needle_spine');

DELETE FROM `creature_text` WHERE entry=@Najentus;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Najentus,0,0,'You will die in the name of Lady Vashj!',14,0,100,0,0,11450,21085,0,'najentus SAY_AGGRO'),
(@Najentus,1,0,'Stick around!',14,0,100,0,0,11451,37696,0,'najentus SAY_NEEDLE1'),
(@Najentus,1,1,'I\'ll deal with you later.',14,0,100,0,0,11452,21090,0,'najentus SAY_NEEDLE2'),
(@Najentus,2,0,'Your success was short-lived!',14,0,100,0,0,11455,21091,0,'najentus SAY_SLAY1'),
(@Najentus,2,1,'Time for you to go.',14,0,100,0,0,11456,21092,0,'najentus SAY_SLAY2'),
(@Najentus,3,0,'Be\'lanen dalorai!',14,0,100,0,0,11453,21088,0,'najentus SAY_SPECIAL1'),
(@Najentus,3,1,'Blood... will... flow!',14,0,100,0,0,11454,21087,0,'najentus SAY_SPECIAL2'),
(@Najentus,4,0,'Bal, lamer zhita!',14,0,100,0,0,11457,21095,0,'najentus SAY_ENRAGE1'),
(@Najentus,4,1,'My patience has run out! Die! Die!',14,0,100,0,0,11458,21096,0,'najentus SAY_ENRAGE2'),
(@Najentus,5,0,'Lord Illidan will... crush you!',14,0,100,0,0,11459,21093,0,'najentus SAY_DEATH');
