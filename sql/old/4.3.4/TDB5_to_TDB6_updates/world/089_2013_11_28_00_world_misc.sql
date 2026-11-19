-- Torturer LeCraft SAI
SET @ENTRY := 27209;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_torturer_leCraft' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
-- Texts for Torturer LeCraft
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Come to play?",12,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,1,0,"Ow! I'll tell you NOTHING, filthy $r!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,2,0,"Wait... WAIT! What is it that you want to know? I know you're the $c named $N.",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,3,0,"OW...NO! We know that you've been stealing our armor and weapons and horses!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,4,0,"We know... that you don't... know why we're immune... to your so-called blight. Grand Admiral Westwind somehow gave the high abbot that prayer. I beg you... no more... please?",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,5,0,"AHHHHHHHHH! Please... we know... that you... have a spy... disguised as... one of us! There... that's all that I know. Please... mercy... STOP!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,6,0,"Please... stop. I'll do... anything....",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,7,0,"I beg you... no more.",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,8,0,"OWWWWWWWW!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,9,0,"You won't get... anything else... out of me!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,10,0,"They all... begged... for their... lives!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,11,0,"I TOLD YOU... I don't know... anything... else!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,12,0,"Just... end it.",15,0,100,0,0,0,"Torturer LeCraft");
