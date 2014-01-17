SET @ENTRY := 18428;
UPDATE `gameobject_template` SET `ScriptName`='go_warmaul_prison' WHERE `entry` IN (182484,182486,182487,182488,182489,182490,182491,182492,182493,182494,182495,182496,182497,182498,182499,182501,182502,182503,182504);
UPDATE `quest_template` SET `ReqSpellCast1`=0 WHERE `entry`=9948;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Death to the ogres!",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,1,1,"Many thanks, hero!",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,2,2,"One day, a hero will rise and lift the orcs up to their former glory.",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,3,3,"Spirits watch over you, $R!",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,4,4,"Thank you, $R! Your service to the Mag'har will not be forgotten.",12,0,100,0,0,0,"Mag'har Prisoner");
