-- Hal McAllister SAI
SET @ENTRY := 20342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,13000,13000,1263000,1263000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,22000,22000,1272000,1272000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,6,51000,51000,1301000,1301000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,3,0,1,0,100,6,183000,183000,1443000,1443000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,4,0,1,0,100,6,192000,192000,1452000,1452000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,5,0,1,0,100,6,225000,225000,1485000,1485000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,6,0,1,0,100,6,363000,363000,1623000,1623000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,7,0,1,0,100,6,372000,372000,1632000,1632000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,8,0,1,0,100,6,405000,405000,1665000,1665000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,9,0,1,0,100,6,543000,543000,1803000,1803000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,10,0,1,0,100,6,552000,552000,1812000,1812000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,11,0,1,0,100,6,723000,723000,1983000,1983000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,12,0,1,0,100,6,732000,732000,1992000,1992000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,13,0,1,0,100,6,765000,765000,2025000,2025000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,14,0,1,0,100,6,903000,903000,2163000,2163000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,15,0,1,0,100,6,912000,912000,2172000,2172000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,16,0,1,0,100,6,945000,945000,2205000,2205000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,17,0,1,0,100,6,1083000,1083000,2343000,2343000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,18,0,1,0,100,6,1092000,1092000,2352000,2352000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,19,0,1,0,100,6,1125000,1125000,2385000,2385000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - Out Of Combat - Say Line 2 (Dungeon Only)");

-- Texts for Hal McAllister
SET @ENTRY := 20342;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Yea, Nat?",12,0,100,0,0,0,"Hal McAllister"),
(@ENTRY,1,0,"Which one?",12,0,100,0,0,0,"Hal McAllister"),
(@ENTRY,2,0,"What do you put in that pipe of yours Nat?",12,0,100,0,0,0,"Hal McAllister"),
(@ENTRY,2,1,"Nat, I've heard a whopper or two in my day but that one takes the cake.",12,0,100,0,0,0,"Hal McAllister"),
(@ENTRY,2,2,"Impossible!",12,0,100,0,0,0,"Hal McAllister");

-- Nat Pagle SAI
SET @ENTRY := 20344;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,10000,10000,1260000,1260000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,17000,17000,1267000,1267000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,6,27000,27000,1277000,1277000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,3,0,1,0,100,6,35000,35000,1285000,1285000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 3 (Dungeon Only)"),
(@ENTRY,0,4,0,1,0,100,6,43000,43000,1293000,1293000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 4 (Dungeon Only)"),
(@ENTRY,0,5,0,1,0,100,6,180000,180000,1440000,1440000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,6,0,1,0,100,6,187000,187000,1447000,1447000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,7,0,1,0,100,6,197000,197000,1457000,1457000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 5 (Dungeon Only)"),
(@ENTRY,0,8,0,1,0,100,6,207000,207000,1467000,1467000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 6 (Dungeon Only)"),
(@ENTRY,0,9,0,1,0,100,6,217000,217000,1477000,1477000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 7 (Dungeon Only)"),
(@ENTRY,0,10,0,1,0,100,6,360000,360000,1620000,1620000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,11,0,1,0,100,6,367000,367000,1627000,1627000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,12,0,1,0,100,6,377000,377000,1637000,1637000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 8 (Dungeon Only)"),
(@ENTRY,0,13,0,1,0,100,6,387000,387000,1647000,1647000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 9 (Dungeon Only)"),
(@ENTRY,0,14,0,1,0,100,6,397000,397000,1657000,1657000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 10 (Dungeon Only)"),
(@ENTRY,0,15,0,1,0,100,6,540000,540000,1800000,1800000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,16,0,1,0,100,6,547000,547000,1807000,1807000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,17,0,1,0,100,6,557000,557000,1817000,1817000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 11 (Dungeon Only)"),
(@ENTRY,0,18,0,1,0,100,6,567000,567000,1827000,1827000,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 12 (Dungeon Only)"),
(@ENTRY,0,19,0,1,0,100,6,577000,577000,1837000,1837000,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 13 (Dungeon Only)"),
(@ENTRY,0,20,0,1,0,100,6,720000,720000,1980000,1980000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,21,0,1,0,100,6,727000,727000,1987000,1987000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,22,0,1,0,100,6,737000,737000,1997000,1997000,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 14 (Dungeon Only)"),
(@ENTRY,0,23,0,1,0,100,6,747000,747000,2007000,2007000,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 15 (Dungeon Only)"),
(@ENTRY,0,24,0,1,0,100,6,757000,757000,2017000,2017000,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 16 (Dungeon Only)"),
(@ENTRY,0,25,0,1,0,100,6,900000,900000,2160000,2160000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,26,0,1,0,100,6,907000,907000,2167000,2167000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,27,0,1,0,100,6,917000,917000,2177000,2177000,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 17 (Dungeon Only)"),
(@ENTRY,0,28,0,1,0,100,6,927000,927000,2187000,2187000,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 18 (Dungeon Only)"),
(@ENTRY,0,29,0,1,0,100,6,937000,937000,2197000,2197000,1,19,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 19 (Dungeon Only)"),
(@ENTRY,0,30,0,1,0,100,6,1080000,1080000,2340000,2340000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,31,0,1,0,100,6,1087000,1087000,2347000,2347000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,32,0,1,0,100,6,1097000,1097000,2357000,2357000,1,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 20 (Dungeon Only)"),
(@ENTRY,0,33,0,1,0,100,6,1107000,1107000,2367000,2367000,1,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 21 (Dungeon Only)"),
(@ENTRY,0,34,0,1,0,100,6,1117000,1117000,2377000,2377000,1,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nat Pagle - Out Of Combat - Say Line 22 (Dungeon Only)");

-- Texts for Nat Pagle
SET @ENTRY := 20344;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hal...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,1,0,"Had that dream again last night...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,2,0,"That one dream... The crazy one. Remember?",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,3,0,"Tarren Mill is destroyed by some crazy force of undead and forever more becomes an enemy to Southshore.",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,4,0,"Could ya imagine such a thing, Hal? Could ya?",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,5,0,"That one where thousands of people are all watching us up from the sky...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,6,0,"We're like their puppets - we dance and cry and fight and say silly things for their amusement.",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,7,0,"Sometimes, even when I'm awake, I think they're watching us. Maybe they're watching us right now...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,8,0,"So I'm on some mountain with some big ol' tree. Bunch of elves runnin' around all over...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,9,0,"Out of nowhere, some 300 foot tall demon or somethin' walks up and starts climbin' the tree...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,10,0,"And if that weren't crazy enough, that big demon gets killed by a bunch of floating light things... Oh, I was also a female elf in that one... Yep...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,11,0,"In this dream, I was fishin' master of the world. I moved to some place called Kalimdor...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,12,0,"And people from all over the world come to me to pay homage... and learn to fish.",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,13,0,"I'm like some kind of fishing god...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,14,0,"This one's real grim... So the king's kid Arthas...Well he goes out to battle evil, along with Uther *Nat pats his brow dry*",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,15,0,"But tragically, Arthas is consumed by the evil and becomes evil himself...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,16,0,"Well, he comes back to the king all pretendin' to be nice, draws his sword, and runs the king through, elbow to... well you know... kills him on the spot...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,17,0,"I can't even believe this one... You know two loudmouthed ruffians, Foror and Tigule?",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,18,0,"Well in this dream, they somehow end up inventing something called ice-cream and flavoring it with strawberries... Well, long story short, they end up striking it rich!",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,19,0,"If that weren't crazy enough, they decided to quit the ice-cream business and become adventurers... They travel all over the place and finally disappears into some portal. I woke up in a cold sweat after that one...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,20,0,"That one where i'm in Durnholde and that one orc that Blackmoore keeps as his personal slave breaks out...",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,21,0,"He ends up destroying the whole keep, freeing all the orcs we're keeping in the camps and rising to power as the king of orcs... Warchief or somethin'.",12,0,100,0,0,0,"Nat Pagle"),
(@ENTRY,22,0,"Crazy isn't it?",12,0,100,0,0,0,"Nat Pagle");

-- Kel'Thuzad SAI
SET @ENTRY := 20350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,60000,60000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,75000,75000,315000,315000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,6,95000,95000,335000,335000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,3,0,1,0,100,6,105000,105000,345000,345000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Say Line 3 (Dungeon Only)"),
(@ENTRY,0,4,0,1,0,100,6,125000,125000,365000,365000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out Of Combat - Say Line 4 (Dungeon Only)");

-- Texts for Kel'Thuzad
SET @ENTRY := 20350;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Keep your voice down, Helcular. Strangers abound...",12,0,100,0,0,0,"Kel\'Thuzad"),
(@ENTRY,1,0,"Necromancy. It is called necromancy. And yes, I have it within my power to bless you with this gift.",12,0,100,0,0,0,"Kel\'Thuzad"),
(@ENTRY,2,0,"That is none of your concern, Helcular, as you are neither Kirin Tor nor a necromancer.",12,0,100,0,0,0,"Kel\'Thuzad"),
(@ENTRY,3,0,"But to be perfectly frank, I do not give a damn what the Kirin Tor think! They are fools, set in their archaic ways.",12,0,100,0,0,0,"Kel\'Thuzad"),
(@ENTRY,4,0,"In due time, Helcular... All in due time...",12,0,100,0,0,0,"Kel\'Thuzad");

-- Helcular SAI
SET @ENTRY := 20353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,70000,70000,310000,310000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,85000,85000,325000,325000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,6,115000,115000,355000,355000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular - Out Of Combat - Say Line 2 (Dungeon Only)");

-- Texts for Helcular
SET @ENTRY := 20353;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"So can you teach me this... this...",12,0,100,0,0,0,"Helcular"),
(@ENTRY,1,0,"And the Kirin Tor? What have they to say of this necromancy?",12,0,100,0,0,0,"Helcular"),
(@ENTRY,2,0,"Then teach me, Kel'Thuzad. Teach me everything you know...",12,0,100,0,0,0,"Helcular");

-- Young Sporebat SAI
SET @ENTRY := 20387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,75,1,0,0,0,0,11,35336,7,0,0,0,0,2,0,0,0,0,0,0,0,"Young Sporebat - On Death - Cast 35336");

-- Ango'rosh Sentry SAI
SET @ENTRY := 20443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,4000,4000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Sentry - In Combat - Cast 15496"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,10000,10000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Sentry - In Combat - Cast 13730");

-- Mal'druk the Soulrender SAI
SET @ENTRY := 20445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,6000,6000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mal'druk the Soulrender - In Combat - Cast 16568"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,35425,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mal'druk the Soulrender - Between 0-50% Health - Cast 35425");

-- Terror Totem SAI
SET @ENTRY := 20455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,15000,15000,11,35198,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terror Totem - In Combat - Cast 35198");

-- Terrorclaw SAI
SET @ENTRY := 20477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,6000,6000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terrorclaw - In Combat - Cast 40504");

-- Eclipsion Dragonhawk SAI
SET @ENTRY := 20502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2500,2500,15000,30000,11,37985,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Dragonhawk - In Combat - Cast 37985");

-- Maggoc SAI
SET @ENTRY := 20600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,36406,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maggoc - Between 0-30% Health - Cast 36406"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maggoc - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,39891,7,0,0,0,0,1,0,0,0,0,0,0,0,"Maggoc - On Death - Cast 39891");

-- Texts for Maggoc
SET @ENTRY := 20600;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Maggoc");

-- Craghide Basilisk SAI
SET @ENTRY := 20607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,12000,12000,11,35313,0,0,0,0,0,2,0,0,0,0,0,0,0,"Craghide Basilisk - In Combat - Cast 35313"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,35385,0,0,0,0,0,2,0,0,0,0,0,0,0,"Craghide Basilisk - On Aggro - Cast 35385");

-- Ripfang Lynx SAI
SET @ENTRY := 20671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ripfang Lynx - On Aggro - Cast 36589"),
(@ENTRY,0,1,0,0,0,100,0,1000,10800,7200,14900,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ripfang Lynx - In Combat - Cast 31279"),
(@ENTRY,0,2,0,0,0,100,0,6000,12000,25000,35000,11,36590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ripfang Lynx - In Combat - Cast 36590");

-- Terokkarantula SAI
SET @ENTRY := 20682;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,7000,9000,11,25809,32,0,0,0,0,5,0,0,0,0,0,0,0,"Terokkarantula - In Combat - Cast 25809"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,9000,11000,11,39271,32,0,0,0,0,2,0,0,0,0,0,0,0,"Terokkarantula - In Combat - Cast 39271");

-- Deathforge Guardian SAI
SET @ENTRY := 20878;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,8000,14000,11,37998,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Guardian - In Combat - Cast 37998"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,5000,15000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Guardian - In Combat - Cast 11972");

-- Blazing Trickster SAI
SET @ENTRY := 20905;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,34,5,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blazing Trickster - On Aggro - Set Instance Data Field To 5 To Data 1 (Dungeon Only)"),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,34,5,3,0,0,0,0,1,0,0,0,0,0,0,0,"Blazing Trickster - On Death - Set Instance Data Field To 5 To Data 3 (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blazing Trickster - On Evade - Set Instance Data Field To 4 To Data 2 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,85,6,4500,4500,12000,15000,11,36906,0,0,0,0,0,6,0,0,0,0,0,0,0,"Blazing Trickster - In Combat - Cast 36906 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,85,6,2000,2000,10000,16000,11,39023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazing Trickster - In Combat - Cast 39023 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,6,500,500,180000,190000,11,36907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blazing Trickster - In Combat - Cast 36907 (Dungeon Only)");

-- Phase-Hunter SAI
SET @ENTRY := 20906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,34,5,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phase-Hunter - On Aggro - Set Instance Data Field To 5 To Data 1 (Dungeon Only)"),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,34,5,3,0,0,0,0,1,0,0,0,0,0,0,0,"Phase-Hunter - On Death - Set Instance Data Field To 5 To Data 3 (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Phase-Hunter - On Evade - Set Instance Data Field To 4 To Data 2 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,7,0,0,1000,1000,11,36908,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phase-Hunter - In Combat - Cast 36908 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,6,2500,2500,5000,6000,11,36909,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phase-Hunter - In Combat - Cast 36909 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,6,0,0,20000,25000,11,36910,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phase-Hunter - In Combat - Cast 36910 (Dungeon Only)");

-- Akkiris Lightning-Waker SAI
SET @ENTRY := 20908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,34,7,1,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - On Aggro - Set Instance Data Field To 7 To Data 1 (Dungeon Only)"),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,34,7,3,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - On Death - Set Instance Data Field To 7 To Data 3 (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - On Evade - Set Instance Data Field To 4 To Data 2 (Dungeon Only)"),
(@ENTRY,0,3,0,4,0,100,7,0,0,0,0,11,38642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - On Aggro - Cast 38642 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,80,6,2000,2000,3000,5000,11,36915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - In Combat - Cast 36915 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,75,6,9000,9000,12000,16000,11,39028,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - In Combat - Cast 39028 (Dungeon Only)"),
(@ENTRY,0,6,0,0,0,85,6,30000,30000,90000,100000,11,36914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - In Combat - Cast 36914 (Dungeon Only)"),
(@ENTRY,0,7,0,8,0,50,6,0,127,30000,30000,11,19714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - On Spellhit By school 127 - Cast 19714 (Dungeon Only)"),
(@ENTRY,0,8,0,13,0,40,6,10000,10000,0,0,11,32691,0,0,0,0,0,7,0,0,0,0,0,0,0,"Akkiris Lightning-Waker - On Target Casting - Cast 32691 (Dungeon Only)");

-- Sulfuron Magma-Thrower SAI
SET @ENTRY := 20909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,34,7,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sulfuron Magma-Thrower - On Aggro - Set Instance Data Field To 7 To Data 1 (Dungeon Only)"),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,34,7,3,0,0,0,0,1,0,0,0,0,0,0,0,"Sulfuron Magma-Thrower - On Death - Set Instance Data Field To 7 To Data 3 (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sulfuron Magma-Thrower - On Evade - Set Instance Data Field To 4 To Data 2 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,4000,4000,60000,70000,11,36917,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sulfuron Magma-Thrower - In Combat - Cast 36917 (Dungeon Only)");

-- Blackwing Drakonaar SAI
SET @ENTRY := 20911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,34,8,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Drakonaar - On Aggro - Set Instance Data Field To 8 To Data 1 (Dungeon Only)"),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,34,8,3,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Drakonaar - On Death - Set Instance Data Field To 8 To Data 3 (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Drakonaar - On Evade - Set Instance Data Field To 4 To Data 2 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,9000,9000,20000,25000,11,39038,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Drakonaar - In Combat - Cast 39038 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,6,5000,5000,14000,18000,11,39033,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackwing Drakonaar - In Combat - Cast 39033 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,6,12000,12000,9000,18000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackwing Drakonaar - In Combat - Cast 13737 (Dungeon Only)");

-- Grishnath Basilisk SAI
SET @ENTRY := 20924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,41,70,0,0,11,37590,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grishnath Basilisk - Between 41-70% Health - Cast 37590"),
(@ENTRY,0,1,0,2,0,100,1,11,40,0,0,11,37590,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grishnath Basilisk - Between 11-40% Health - Cast 37590"),
(@ENTRY,0,2,0,2,0,100,1,0,10,0,0,11,37590,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grishnath Basilisk - Between 0-10% Health - Cast 37590");

-- Scalded Basilisk SAI
SET @ENTRY := 20925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,8000,8000,16000,16000,11,35236,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalded Basilisk - In Combat - Cast 35236");

-- Azurebeak SAI
SET @ENTRY := 21005;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9100,9100,11000,14000,11,31273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azurebeak - In Combat - Cast 31273");

-- Rina Moonspring SAI
SET @ENTRY := 21066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rina Moonspring - Out Of Combat - Say Line 0");

-- Texts for Rina Moonspring
SET @ENTRY := 21066;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s whispers softley in reverent tones under her breath.",16,0,100,0,0,0,"Rina Moonspring");

-- Coilfang Scale-Healer SAI
SET @ENTRY := 21126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4400,8100,12100,13400,11,34944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Scale-Healer - In Combat - Cast 34944 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4400,8100,12100,13400,11,37669,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Scale-Healer - In Combat - Cast 37669 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10500,13300,12100,12100,11,17139,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Scale-Healer - In Combat - Cast 17139 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,10500,13300,12100,12100,11,36052,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Scale-Healer - In Combat - Cast 36052 (Heroic Dungeon)"),
(@ENTRY,0,4,0,14,0,100,2,4000,40,0,0,11,34945,1,0,0,0,0,7,0,0,0,0,0,0,0,"Coilfang Scale-Healer - On Friendly Unit At 4000 Health Within 40 Range - Cast 34945 (Normal Dungeon)"),
(@ENTRY,0,5,0,14,0,100,4,8000,40,0,0,11,39378,1,0,0,0,0,7,0,0,0,0,0,0,0,"Coilfang Scale-Healer - On Friendly Unit At 8000 Health Within 40 Range - Cast 39378 (Heroic Dungeon)");

-- Coilfang Tempest SAI
SET @ENTRY := 21127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4900,10800,7400,14900,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Tempest - In Combat - Cast 15667 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,10800,18700,26900,26900,11,36872,33,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Tempest - In Combat - Cast 36872 (Dungeon Only)");

-- Coilfang Ray SAI
SET @ENTRY := 21128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1300,4900,12100,21300,11,34984,0,0,0,0,0,6,0,0,0,0,0,0,0,"Coilfang Ray - In Combat - Cast 34984 (Dungeon Only)");

-- Gralga SAI
SET @ENTRY := 21193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,418000,418000,418000,418000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gralga - Out Of Combat - Say Line 0");

-- Deathtalon Spirit SAI
SET @ENTRY := 21198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathtalon Spirit - On Respawn - Cast 17327"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,7000,9000,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathtalon Spirit - In Combat - Cast 36093");

-- Vashj'ir Honor Guard SAI
SET @ENTRY := 21218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8500,8500,12700,12700,11,38572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vashj'ir Honor Guard - In Combat - Cast 38572 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,13600,13600,8700,14000,11,38576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vashj'ir Honor Guard - In Combat - Cast 38576 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,50,0,0,11,38947,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vashj'ir Honor Guard - Between 0-50% Health - Cast 38947 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vashj'ir Honor Guard - Between 0-50% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Vashj'ir Honor Guard
SET @ENTRY := 21218;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Vashj\'ir Honor Guard");

-- Corrupted Rager SAI
SET @ENTRY := 21223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,18000,45000,50000,11,51613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Rager - In Combat - Cast 51613");

-- Auchenai Initiate SAI
SET @ENTRY := 21284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,7000,9000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Initiate - In Combat - Cast 38618"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,8000,11000,11,37592,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Initiate - In Combat - Cast 37592");

-- Auchenai Doomsayer SAI
SET @ENTRY := 21285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,3000,5000,11,31516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Doomsayer - In Combat - Cast 31516"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,7000,10000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Doomsayer - In Combat - Cast 16568"),
(@ENTRY,0,2,0,2,0,100,1,0,40,15000,20000,11,11642,1,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Doomsayer - Between 0-40% Health - Cast 11642");

-- Spirit Raven SAI
SET @ENTRY := 21324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit Raven - On Respawn - Cast 17327"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,12000,15000,11,38021,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit Raven - In Combat - Cast 38021"),
(@ENTRY,0,2,0,2,0,100,0,0,30,5000,8000,11,38254,33,0,0,0,0,5,0,0,0,0,0,0,0,"Spirit Raven - Between 0-30% Health - Cast 38254");

-- Ethereal Plunderer SAI
SET @ENTRY := 21368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,3000,5000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Plunderer - In Combat - Cast 7159");

-- Dark Conclave Harbinger SAI
SET @ENTRY := 21384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Harbinger - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,6000,12000,11,15496,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Harbinger - In Combat - Cast 15496"),
(@ENTRY,0,2,0,2,0,100,0,0,50,8000,8000,11,16588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Harbinger - Between 0-50% Health - Cast 16588");

-- Dark Conclave Hawkeye SAI
SET @ENTRY := 21386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Hawkeye - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,8000,14000,11,37974,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Hawkeye - In Combat - Cast 37974");

-- Blackscale SAI
SET @ENTRY := 21497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,18000,18000,11,20712,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackscale - In Combat - Cast 20712"),
(@ENTRY,0,1,0,0,0,85,0,9000,9000,25000,25000,11,29685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackscale - In Combat - Cast 29685"),
(@ENTRY,0,2,0,0,0,85,0,15000,15000,30000,30000,11,29685,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackscale - In Combat - Cast 29685");

-- Skettis Wing Guard SAI
SET @ENTRY := 21644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,9000,14000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Wing Guard - In Combat - Cast 13730"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,7000,12000,11,35321,33,0,0,0,0,5,0,0,0,0,0,0,0,"Skettis Wing Guard - In Combat - Cast 35321"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,11000,16000,11,40546,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Wing Guard - In Combat - Cast 40546"),
(@ENTRY,0,3,4,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Wing Guard - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Wing Guard - Between 0-30% Health - Say Line 0");

-- Texts for Skettis Wing Guard
SET @ENTRY := 21644;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Skettis Wing Guard");

-- Cabal Skirmisher SAI
SET @ENTRY := 21661;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,8000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Skirmisher - In Combat - Cast 15496"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Skirmisher - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Skirmisher - Between 0-30% Health - Say Line 0");

-- Texts for Cabal Skirmisher
SET @ENTRY := 21661;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Cabal Skirmisher");

-- Cabal Tomb-Raider SAI
SET @ENTRY := 21662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,3000,5000,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Tomb-Raider - In Combat - Cast 37685");

-- Bog Overlord SAI
SET @ENTRY := 21694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,37266,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Overlord - Out Of Combat - Cast 37266 (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,5,1000,1000,0,0,11,37863,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Overlord - Out Of Combat - Cast 37863 (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,30,4000,6000,11,37272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bog Overlord - Between 0-30 Range - Cast 37272 (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,30,4000,6000,11,37862,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bog Overlord - Between 0-30 Range - Cast 37862 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,2000,5000,12000,19000,11,32065,33,0,0,0,0,5,0,0,0,0,0,0,0,"Bog Overlord - In Combat - Cast 32065 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,6,7000,9500,12000,15000,11,40340,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Overlord - In Combat - Cast 40340 (Dungeon Only)"),
(@ENTRY,0,6,7,2,0,100,7,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Overlord - Between 0-20% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Overlord - Between 0-20% Health - Say Line 0 (Dungeon Only)");

-- Texts for Bog Overlord
SET @ENTRY := 21694;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bog Overlord");

-- Tidal Surger SAI
SET @ENTRY := 21695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,7000,14000,18000,11,37250,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tidal Surger - In Combat - Cast 37250 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,9000,14000,12000,15000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tidal Surger - In Combat - Cast 15531 (Dungeon Only)");

-- Steam Surger SAI
SET @ENTRY := 21696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,9000,15000,18000,11,37252,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steam Surger - In Combat - Cast 37252 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,7000,9000,15000,18000,11,39412,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steam Surger - In Combat - Cast 39412 (Heroic Dungeon)");

-- Infinite Chrono-Lord SAI
SET @ENTRY := 21697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,4,11500,27700,27700,30900,11,38539,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chrono-Lord - In Combat - Cast 38539 (Heroic Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,18800,18800,13200,20600,11,31467,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chrono-Lord - In Combat - Cast 31467 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,22300,22300,22300,22300,11,38540,1,0,0,0,0,6,0,0,0,0,0,0,0,"Infinite Chrono-Lord - In Combat - Cast 38540 (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,27300,27300,30100,30100,11,38538,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chrono-Lord - In Combat - Cast 38538 (Heroic Dungeon)");

-- Corrupted Earth Elemental SAI
SET @ENTRY := 21708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,0,23000,23000,5000,5000,11,43305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Earth Elemental - In Combat - Cast 43305");

-- Dragonmaw Wrangler SAI
SET @ENTRY := 21717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,13000,12000,16000,11,38338,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Wrangler - In Combat - Cast 38338"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Wrangler - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Wrangler - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,33,22197,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Wrangler - On Death - Quest Credit");

-- Texts for Dragonmaw Wrangler
SET @ENTRY := 21717;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Dragonmaw Wrangler");

-- Dragonmaw Shaman SAI
SET @ENTRY := 21720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,33,22197,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Shaman - On Death - Quest Credit"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shaman - On Aggro - Cast 6742"),
(@ENTRY,0,2,0,0,0,100,1,0,0,15000,15000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shaman - In Combat - Cast 12550");

-- Blackwind Sabercat SAI
SET @ENTRY := 21723;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,16000,19000,11,33912,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackwind Sabercat - In Combat - Cast 33912");

-- Overlord Or'barokh SAI
SET @ENTRY := 21769;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Or'barokh - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,123000,123000,303000,303000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Or'barokh - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,125500,125500,305500,305500,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Or'barokh - Out Of Combat - Say Line 2");

-- Texts for Overlord Or'barokh
SET @ENTRY := 21769;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What is it that you want from me, shaman?",12,0,100,6,0,0,"Overlord Or\'barokh"),
(@ENTRY,1,0,"Do you not have eyes? Did you not see the demons on our very doorstep? I do not have the soldiers to spare!",12,0,100,6,0,0,"Overlord Or\'barokh"),
(@ENTRY,2,0,"Pray to your gods, shaman. Perhaps they will come to your aid. The Horde however, cannot...",12,0,100,25,0,0,"Overlord Or\'barokh");

-- Warcaller Sardon Truslice SAI
SET @ENTRY := 21771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,20000,60000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warcaller Sardon Truslice - Out Of Combat - Say Line 0");

-- Thane Yoregar SAI
SET @ENTRY := 21773;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,200000,260000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Yoregar - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,120000,120000,200000,260000,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Yoregar - Out Of Combat - Emote Question");

-- Skettis Kaliri SAI
SET @ENTRY := 21804;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,10000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Kaliri - In Combat - Cast 5708");

-- Ironspine Chomper SAI
SET @ENTRY := 21816;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,5000,7000,11,32906,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironspine Chomper - In Combat - Cast 32906");

-- Infinite Whelp SAI
SET @ENTRY := 21818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Whelp - Out Of Combat - Cast 31326 (Dungeon Only)"),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Whelp - On Aggro - Remove Aura 31326 (Dungeon Only)"),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Whelp - On Evade - Cast 31326 (Dungeon Only)");

-- Terokk SAI
SET @ENTRY := 21838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,10000,15000,11,40721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terokk - In Combat - Cast 40721"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terokk - In Combat - Cast 15284"),
(@ENTRY,0,2,3,2,0,100,1,0,30,120000,120000,11,40733,1,0,0,0,0,1,0,0,0,0,0,0,0,"Terokk - Between 0-30% Health - Cast 40733"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terokk - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,4,5,2,0,100,1,0,25,0,0,11,28747,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terokk - Between 0-25% Health - Cast 28747"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terokk - Between 0-25% Health - Say Line 0"),
(@ENTRY,0,6,0,6,0,100,1,0,0,0,0,11,40722,7,0,0,0,0,7,0,0,0,0,0,0,0,"Terokk - On Death - Cast 40722");

-- Texts for Terokk
SET @ENTRY := 21838;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Terokk");

-- Auchenai Warrior SAI
SET @ENTRY := 21852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,5000,9000,11,38618,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Warrior - In Combat - Cast 38618");

-- Ironspine Petrifier SAI
SET @ENTRY := 21854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,14000,18000,11,32905,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ironspine Petrifier - In Combat - Cast 32905");

-- Scorchshell Pincer SAI
SET @ENTRY := 21864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,1500,1500,30000,40000,11,38208,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorchshell Pincer - In Combat - Cast 38208");

-- Vilewing Chimaera SAI
SET @ENTRY := 21879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,55000,11,16552,0,0,0,0,0,5,0,0,0,0,0,0,0,"Vilewing Chimaera - In Combat - Cast 16552");

-- Avian Ripper SAI
SET @ENTRY := 21891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4300,12100,15600,19300,11,38056,32,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Ripper - In Combat - Cast 38056 (Dungeon Only)");

-- Cabal Spell-weaver SAI
SET @ENTRY := 21902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,8000,11,32707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spell-weaver - In Combat - Cast 32707"),
(@ENTRY,0,1,0,2,0,100,1,0,50,15000,20000,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spell-weaver - Between 0-50% Health - Cast 17173");

-- Avian Warhawk SAI
SET @ENTRY := 21904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,2,3000,6000,5000,8000,11,38059,1,0,0,0,0,6,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 38059 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,90,4,3000,6000,5000,8000,11,39197,1,0,0,0,0,6,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 39197 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,5000,8000,10000,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 32901 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4000,5000,8000,10000,11,39198,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 39198 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,7000,9000,10000,12000,11,18144,0,0,0,0,0,1,0,0,0,0,0,0,0,"Avian Warhawk - In Combat - Cast 18144 (Dungeon Only)");

-- Cabal Initiate SAI
SET @ENTRY := 21907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,9000,11,15691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Initiate - In Combat - Cast 15691"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Initiate - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Initiate - Between 0-30% Health - Say Line 0");

-- Texts for Cabal Initiate
SET @ENTRY := 21907;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Cabal Initiate");

-- Eclipsion Soldier SAI
SET @ENTRY := 22016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,20,0,0,11,36476,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Soldier - Between 0-20% Health - Cast 36476");

-- Eclipsion Cavalier SAI
SET @ENTRY := 22018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,120000,240000,11,30931,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Cavalier - In Combat - Cast 30931"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,17500,42500,11,35871,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Cavalier - In Combat - Cast 35871"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,38311,3,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Cavalier - On Death - Cast 38311");

-- Scorpid Bonecrawler SAI
SET @ENTRY := 22100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,9000,12000,11,5416,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Bonecrawler - In Combat - Cast 5416"),
(@ENTRY,0,1,0,2,0,100,1,80,90,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 80-90% Health - Cast 33962"),
(@ENTRY,0,2,0,2,0,100,1,70,80,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 70-80% Health - Cast 33962"),
(@ENTRY,0,3,0,2,0,100,1,60,70,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 60-70% Health - Cast 33962"),
(@ENTRY,0,4,0,2,0,100,1,50,60,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 50-60% Health - Cast 33962"),
(@ENTRY,0,5,0,2,0,100,1,40,50,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 40-50% Health - Cast 33962"),
(@ENTRY,0,6,0,2,0,100,1,30,40,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 30-40% Health - Cast 33962"),
(@ENTRY,0,7,0,2,0,100,1,20,30,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 20-30% Health - Cast 33962"),
(@ENTRY,0,8,0,2,0,100,1,10,20,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 10-20% Health - Cast 33962"),
(@ENTRY,0,9,0,2,0,100,1,0,10,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpid Bonecrawler - Between 0-10% Health - Cast 33962");

-- Decrepit Clefthoof SAI
SET @ENTRY := 22105;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,10000,12500,11,12612,0,0,0,0,0,2,0,0,0,0,0,0,0,"Decrepit Clefthoof - In Combat - Cast 12612"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Clefthoof - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Clefthoof - Between 0-30% Health - Say Line 0");

-- Texts for Decrepit Clefthoof
SET @ENTRY := 22105;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Decrepit Clefthoof");

-- Gordunni Back-Breaker SAI
SET @ENTRY := 22143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,9000,14000,11,15610,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Back-Breaker - In Combat - Cast 15610"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,6000,9000,11,37974,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Back-Breaker - In Combat - Cast 37974"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Back-Breaker - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Back-Breaker - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,33,23450,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Back-Breaker - On Death - Quest Credit");

-- Texts for Gordunni Back-Breaker
SET @ENTRY := 22143;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Gordunni Back-Breaker");

-- Gordunni Elementalist SAI
SET @ENTRY := 22144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Elementalist - On Aggro - Cast 12550"),
(@ENTRY,0,1,0,2,0,100,1,0,60,0,0,11,32062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Elementalist - Between 0-60% Health - Cast 32062"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Elementalist - Between 0-50% Health - Cast 11986"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Elementalist - Between 0-30% Health - Cast 6742"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,33,23450,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Elementalist - On Death - Quest Credit");

-- Gordunni Head-Splitter SAI
SET @ENTRY := 22148;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5500,4000,6500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Head-Splitter - In Combat - Cast 15496"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Head-Splitter - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,23450,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Head-Splitter - On Death - Quest Credit");

-- Apexis Flayer SAI
SET @ENTRY := 22175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8300,13300,22000,26000,11,13443,0,0,0,0,0,5,0,0,0,0,0,0,0,"Apexis Flayer - In Combat - Cast 13443"),
(@ENTRY,0,1,0,0,0,100,0,4200,6200,28100,31600,11,40770,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apexis Flayer - In Combat - Cast 40770");

-- Shard-Hide Boar SAI
SET @ENTRY := 22180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4700,15300,9700,16300,11,34783,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shard-Hide Boar - In Combat - Cast 34783"),
(@ENTRY,0,1,0,0,0,100,0,8100,13300,8100,13300,11,40773,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shard-Hide Boar - In Combat - Cast 40773");

-- Slaag SAI
SET @ENTRY := 22199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,120000,120000,11,33958,1,0,0,0,0,1,0,0,0,0,0,0,0,"Slaag - Between 0-30% Health - Cast 33958"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slaag - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,39898,7,0,0,0,0,1,0,0,0,0,0,0,0,"Slaag - On Death - Cast 39898");

-- Texts for Slaag
SET @ENTRY := 22199;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Slaag");

-- Bash'ir Raider SAI
SET @ENTRY := 22241;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,7000,7000,12000,12000,11,35922,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir Raider - In Combat - Cast 35922"),
(@ENTRY,0,1,0,0,0,90,0,30000,30000,30000,30000,11,32920,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Raider - In Combat - Cast 32920");

-- Bash'ir Spell-Thief SAI
SET @ENTRY := 22242;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,38857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Spell-Thief - On Respawn - Cast 38857"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,38860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Spell-Thief - On Aggro - Cast 38860");

-- Spore Strider SAI
SET @ENTRY := 22299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,4,1000,3000,4800,6100,11,20824,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spore Strider - In Combat - Cast 20824 (Heroic Dungeon)");

-- Deathforge Mine SAI
SET @ENTRY := 22315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,2000,2000,0,0,11,38108,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Mine - In Combat - Cast 38108"),
(@ENTRY,0,1,0,0,0,100,1,2000,2000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Mine - In Combat - Die");

-- Malevolent Hatchling SAI
SET @ENTRY := 22337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,8,25,15000,19000,11,36140,1,0,0,0,0,2,0,0,0,0,0,0,0,"Malevolent Hatchling - Between 8-25 Range - Cast 36140"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,11000,14000,11,38021,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malevolent Hatchling - In Combat - Cast 38021");

-- Deathshadow Acolyte SAI
SET @ENTRY := 22341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,39102,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Acolyte - On Respawn - Cast 39102"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,8000,14000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Acolyte - In Combat - Cast 32000");

-- Deathshadow Archon SAI
SET @ENTRY := 22343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,12000,18000,11,31996,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Archon - In Combat - Cast 31996"),
(@ENTRY,0,1,2,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Archon - Between 0-20% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Archon - Between 0-20% Health - Say Line 0");

-- Texts for Deathshadow Archon
SET @ENTRY := 22343;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Deathshadow Archon");

-- Cabal Interrogator SAI
SET @ENTRY := 22378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,9000,14000,11,39043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Interrogator - In Combat - Cast 39043"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,6000,9000,11,15691,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Interrogator - In Combat - Cast 15691");

-- Hathyss the Wicked SAI
SET @ENTRY := 22381;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,90000,180000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hathyss the Wicked - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,9000,18000,11,36541,33,0,0,0,0,5,0,0,0,0,0,0,0,"Hathyss the Wicked - In Combat - Cast 36541"),
(@ENTRY,0,2,0,0,0,100,0,8000,13000,12000,17000,11,34017,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hathyss the Wicked - In Combat - Cast 34017");

-- Texts for Hathyss the Wicked
SET @ENTRY := 22381;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Incompetent fools! Auchindoun should've been ours... look at yourselves scrambling like rats!",12,0,100,0,0,0,"Hathyss the Wicked");

-- Lithic Oracle SAI
SET @ENTRY := 22387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lithic Oracle - On Aggro - Cast 32924"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,10000,15000,11,32907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lithic Oracle - In Combat - Cast 32907"),
(@ENTRY,0,2,0,0,0,100,0,1000,3000,40000,45000,11,6535,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lithic Oracle - In Combat - Cast 6535"),
(@ENTRY,0,3,0,0,0,100,0,9000,11000,9000,12000,11,11824,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lithic Oracle - In Combat - Cast 11824"),
(@ENTRY,0,4,0,0,0,100,0,4000,9000,9000,14000,11,12058,1,0,0,0,0,5,0,0,0,0,0,0,0,"Lithic Oracle - In Combat - Cast 12058");

-- Lithic Talonguard SAI
SET @ENTRY := 22388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lithic Talonguard - In Combat - Cast 6016");

-- Deathshadow Hound SAI
SET @ENTRY := 22394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Hound - On Respawn - Cast 18950"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,6000,12000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Hound - In Combat - Cast 30639");

-- Lost Torranche SAI
SET @ENTRY := 22807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lost Torranche - Between 0-15% Health - Flee For Assist");

-- Ashtongue Battlelord SAI
SET @ENTRY := 22844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,19000,19000,18000,18000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Battlelord - In Combat - Cast 15284 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,90,2,6000,6000,20000,20000,11,32588,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Battlelord - In Combat - Cast 32588 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,85,2,15000,15000,22000,22000,11,41182,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ashtongue Battlelord - In Combat - Cast 41182 (Normal Dungeon)"),
(@ENTRY,0,3,4,2,0,100,3,0,30,0,0,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Battlelord - Between 0-30% Health - Cast 34970 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Battlelord - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Ashtongue Battlelord
SET @ENTRY := 22844;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ashtongue Battlelord");

-- Grok SAI
SET @ENTRY := 22940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,156000,156000,156000,276000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grok - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,270000,270000,270000,270000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grok - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,890000,890000,890000,950000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grok - Out Of Combat - Say Line 2");

-- Texts for Grok
SET @ENTRY := 22940;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s need help! Why no one help?",12,0,100,0,0,0,"Grok"),
(@ENTRY,0,1,"If no one help. %s smash!",12,0,100,0,0,0,"Grok"),
(@ENTRY,1,0,"%s get angry if puny ones not go to Blade's Edge and talk to Mog'dorg!",12,0,100,0,0,0,"Grok"),
(@ENTRY,1,1,"Bladespire clan not fight fair. Have Gronn to help dem. You go to Blade's Edge Mountains. Talk to Mog'dorg the Wizened. Kill Gromm.",12,0,100,0,0,0,"Grok"),
(@ENTRY,1,2,"Mog'dorg the Wizened tell %s go to city, get help for Bloodmaul. %s go.",12,0,100,0,0,0,"Grok"),
(@ENTRY,2,0,"Me hungry. Fruit look tasty.",12,0,100,0,0,0,"Grok");

-- Talonsworn Forest-Rager SAI
SET @ENTRY := 23029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,12000,16000,11,15548,1,0,0,0,0,1,0,0,0,0,0,0,0,"Talonsworn Forest-Rager - In Combat - Cast 15548");

-- Monstrous Kaliri SAI
SET @ENTRY := 23051;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,11000,14000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Monstrous Kaliri - In Combat - Cast 31553"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,17000,20000,11,13738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Monstrous Kaliri - In Combat - Cast 13738"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,9000,12000,11,5708,1,0,0,0,0,1,0,0,0,0,0,0,0,"Monstrous Kaliri - In Combat - Cast 5708");

-- Shadowmoon Riding Hound SAI
SET @ENTRY := 23083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,25821,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - On Aggro - Cast 25821 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,20000,25000,11,41092,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - In Combat - Cast 41092 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Shadowmoon Riding Hound
SET @ENTRY := 23083;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Shadowmoon Riding Hound");

-- Eagle Spirit SAI
SET @ENTRY := 23136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,4,0,7,0,0,11,40240,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eagle Spirit - On Spellhit By school 7 - Cast 40240 (Heroic Dungeon)");

-- Bash'ir Surveyor SAI
SET @ENTRY := 23153;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,60000,60000,90000,90000,11,40835,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir Surveyor - In Combat - Cast 40835"),
(@ENTRY,0,1,0,0,0,75,0,25000,25000,36000,36000,11,40881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Surveyor - In Combat - Cast 40881"),
(@ENTRY,0,2,0,2,0,100,0,0,40,38000,38000,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Surveyor - Between 0-40% Health - Cast 11436");

-- Gezzarak the Huntress SAI
SET @ENTRY := 23163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gezzarak the Huntress - On Respawn - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,15000,21000,11,40542,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Cast 40542"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,17500,20000,11,40434,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Cast 40434"),
(@ENTRY,0,3,4,0,0,100,0,16000,19000,22000,25000,14,0,99,0,0,0,0,1,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Remove 99% Threat"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,40432,1,0,0,0,0,3,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Cast 40432"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Say Line 1"),
(@ENTRY,0,6,0,0,0,100,0,13000,17800,21000,26000,11,40542,1,0,0,0,0,3,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Cast 40542"),
(@ENTRY,0,7,0,0,0,100,0,13000,17800,21000,26000,11,40433,0,0,0,0,0,3,0,0,0,0,0,0,0,"Gezzarak the Huntress - In Combat - Cast 40433");

-- Texts for Gezzarak the Huntress
SET @ENTRY := 23163;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s bares her fangs and hisses menacingly at those around her.",16,0,100,0,0,0,"Gezzarak the Huntress"),
(@ENTRY,1,0,"%s focuses on $N.",16,0,100,0,0,0,"Gezzarak the Huntress");

-- Hand of Gorefiend SAI
SET @ENTRY := 23172;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,16000,45000,60000,11,38166,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Gorefiend - In Combat - Cast 38166 (Normal Dungeon)");
