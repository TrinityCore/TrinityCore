-- Nat Pagle SAI
SET @ID := 20344;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+6 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,30000,30000,300000,300000,88,@ID*100+0,@ID*100+6,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out of Combat - Run Random Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+0,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+0,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+0,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+0,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2"),
(@ID*100+0,9,5,0,0,0,100,0,10000,10000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 3"),
(@ID*100+0,9,6,0,0,0,100,0,10000,10000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 4"),
(@ID*100+0,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+1,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+1,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+1,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+1,9,4,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 5"),
(@ID*100+1,9,5,0,0,0,100,0,10000,10000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 6"),
(@ID*100+1,9,6,0,0,0,100,0,10000,10000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 7"),
(@ID*100+1,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+2,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+2,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+2,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+2,9,4,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 8"),
(@ID*100+2,9,5,0,0,0,100,0,10000,10000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 9"),
(@ID*100+2,9,6,0,0,0,100,0,10000,10000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 10"),
(@ID*100+2,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+3,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+3,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+3,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+3,9,4,0,0,0,100,0,5000,5000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 11"),
(@ID*100+3,9,5,0,0,0,100,0,10000,10000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 12"),
(@ID*100+3,9,6,0,0,0,100,0,10000,10000,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 13"),
(@ID*100+3,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+4,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+4,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+4,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+4,9,4,0,0,0,100,0,5000,5000,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 14"),
(@ID*100+4,9,5,0,0,0,100,0,10000,10000,0,0,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 15"),
(@ID*100+4,9,6,0,0,0,100,0,10000,10000,0,0,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 16"),
(@ID*100+4,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+5,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+5,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+5,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+5,9,4,0,0,0,100,0,5000,5000,0,0,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 17"),
(@ID*100+5,9,5,0,0,0,100,0,10000,10000,0,0,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 18"),
(@ID*100+5,9,6,0,0,0,100,0,10000,10000,0,0,1,19,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 19"),
(@ID*100+5,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)"),

(@ID*100+6,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0"),
(@ID*100+6,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 0 (Hal McAllister)"),
(@ID*100+6,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1"),
(@ID*100+6,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 1 (Hal McAllister)"),
(@ID*100+6,9,4,0,0,0,100,0,5000,5000,0,0,1,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 20"),
(@ID*100+6,9,5,0,0,0,100,0,10000,10000,0,0,1,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 21"),
(@ID*100+6,9,6,0,0,0,100,0,10000,10000,0,0,1,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 22"),
(@ID*100+6,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,20342,0,0,0,0,0,0,"Nat Pagle - On Script - Say Line 2 (Hal McAllister)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Hal...",12,0,100,0,0,0,17966,0,"Nat Pagle"),
(@ID,1,0,"Had that dream again last night...",12,0,100,0,0,0,17968,0,"Nat Pagle"),

(@ID,2,0,"That one dream... The crazy one. Remember?",12,0,100,0,0,0,17970,0,"Nat Pagle"),
(@ID,3,0,"Tarren Mill is destroyed by some crazy force of undead and forever more becomes an enemy to Southshore.",12,0,100,0,0,0,17971,0,"Nat Pagle"),
(@ID,4,0,"Could ya imagine such a thing, Hal? Could ya?",12,0,100,0,0,0,17972,0,"Nat Pagle"),

(@ID,5,0,"That one where I'm in Durnholde and that one orc that Blackmoore keeps as his personal slave breaks out...",12,0,100,0,0,0,17973,0,"Nat Pagle"),
(@ID,6,0,"He ends up destroying the whole keep, freeing all the orcs we're keeping in the camps, and rising to power as the king of orcs... Warchief or somethin'.",12,0,100,0,0,0,17974,0,"Nat Pagle"),
(@ID,7,0,"Crazy, isn't it?",12,0,100,0,0,0,17975,0,"Nat Pagle"),

(@ID,8,0,"So I'm on some mountain with some big ol' tree. Bunch of elves runnin' around all over...",12,0,100,0,0,0,17976,0,"Nat Pagle"),
(@ID,9,0,"Out of nowhere, some 300 foot tall demon or somethin' walks up and starts climbin' the tree...",12,0,100,0,0,0,17977,0,"Nat Pagle"),
(@ID,10,0,"And if that weren't crazy enough, that big demon gets killed by a bunch of little floating light things... Oh, I was also a female elf in that one... Yep...",12,0,100,0,0,0,17978,0,"Nat Pagle"),

(@ID,11,0,"In this dream, I was fishin' master of the world. I moved to some place called Kalimdor...",12,0,100,0,0,0,17979,0,"Nat Pagle"),
(@ID,12,0,"And people from all over the world come to me to pay homage... and learn to fish.",12,0,100,0,0,0,17980,0,"Nat Pagle"),
(@ID,13,0,"I'm like some kind of fishing god...",12,0,100,0,0,0,17981,0,"Nat Pagle"),

(@ID,14,0,"I can't even believe this one... You know those two loud-mouthed ruffians, Foror and Tigule?",12,0,100,0,0,0,17982,0,"Nat Pagle"),
(@ID,15,0,"Well in this dream, they somehow end up inventing something called ice-cream and flavoring it with strawberries... Well, long story short, they end up striking it rich!",12,0,100,0,0,0,17983,0,"Nat Pagle"),
(@ID,16,0,"If that weren't crazy enough, they decide to quit the ice-cream business and become adventurers... They travel all over the place and finally disappear into some portal. I woke up in a cold sweat after that one...",12,0,100,0,0,0,17984,0,"Nat Pagle"),

(@ID,17,0,"This one's real grim... So the king's kid, Arthas... Well he goes out to battle evil, along with Uther... *Nat pats his brow dry*",12,0,100,0,0,0,17985,0,"Nat Pagle"),
(@ID,18,0,"But tragically, Arthas is consumed by the evil and becomes evil himself...",12,0,100,0,0,0,17986,0,"Nat Pagle"),
(@ID,19,0,"Well, he comes back to the king all pretendin' to be nice, draws his sword, and runs the king through, elbow to ... well you know... kills him on the spot.",12,0,100,0,0,0,17987,0,"Nat Pagle"),

(@ID,20,0,"That one where thousands of people are all watching us from up in the sky...",12,0,100,0,0,0,18060,0,"Nat Pagle"),
(@ID,21,0,"We're like their puppets - we dance and cry and fight and say silly things for their amusement.",12,0,100,0,0,0,18061,0,"Nat Pagle"),
(@ID,22,0,"Sometimes, even when I'm awake, I think they're watching us. Maybe they're watching us right now...",12,0,100,0,0,0,18062,0,"Nat Pagle");

SET @ID := 20342;
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `creature_text` WHERE `CreatureID` = @ID AND `GroupID` = 2;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,2,0,"It'll never happen, Nat.",12,0,100,0,0,0,17988,0,"Hal McAllister"),
(@ID,2,1,"Impossible!",12,0,100,0,0,0,17989,0,"Hal McAllister"),
(@ID,2,2,"I worry about you sometimes, Nat.",12,0,100,0,0,0,17990,0,"Hal McAllister"),
(@ID,2,3,"No way.",12,0,100,0,0,0,17991,0,"Hal McAllister"),
(@ID,2,4,"Nat, I've heard a whopper or two in my day but that one takes the cake.",12,0,100,0,0,0,17992,0,"Hal McAllister"),
(@ID,2,5,"What you got in that pipe, Nat?",12,0,100,0,0,0,17993,0,"Hal McAllister"),
(@ID,2,6,"*Hal shakes his head* Nat, Nat, Nat...",12,0,100,0,0,0,17994,0,"Hal McAllister"),
(@ID,2,7,"Shut up and fish, Nat.",12,0,100,0,0,0,17995,0,"Hal McAllister");
