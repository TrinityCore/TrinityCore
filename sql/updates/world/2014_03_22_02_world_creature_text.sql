SET @ENTRY := 23557;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Get on your knees and bow to da fang and claw!", 14, 0, 100, 0, 0, 12020, "Halazzi - Aggro"),
(@ENTRY, 1, 0, "You gonna leave in pieces!", 14, 0, 100, 0, 0, 0, "Halazzi - Saber"),
(@ENTRY, 1, 1, "Me gonna carve ya now!", 14, 0, 100, 0, 0, 0, "Halazzi - Saber"),
(@ENTRY, 2, 0, "Me gonna carve ya now!", 14, 0, 100, 0, 0, 12021, "Halazzi - Split"),
(@ENTRY, 3, 0, "Spirit, come back to me!", 14, 0, 100, 0, 0, 12022, "Halazzi - Merge"),
(@ENTRY, 4, 0, "You cant fight the power!", 14, 0, 100, 0, 0, 12026, "Halazzi - Killed unit"),
(@ENTRY, 4, 1, "You gonna fail!", 14, 0, 100, 0, 0, 12027, "Halazzi - Killed unit"),
(@ENTRY, 5, 0, "Chaga... choka'jinn.", 14, 0, 100, 0, 0, 12028, "Halazzi - Death"),
(@ENTRY, 6, 0, "Whatch you be doing? Pissin' yourselves...", 14, 0, 100, 0, 0, 12025, "Halazzi - Death");
