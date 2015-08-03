-- Mag'har Prisoner
SET @ENTRY := 18428;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Death to the ogres!",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,0,1,"Many thanks, hero!",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,0,2,"One day, a hero will rise and lift the orcs up to their former glory.",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,0,3,"Spirits watch over you, $r!",12,0,100,0,0,0,"Mag'har Prisoner"),
(@ENTRY,0,4,"Thank you, $r! Your service to the Mag'har will not be forgotten.",12,0,100,0,0,0,"Mag'har Prisoner");
