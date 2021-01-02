-- Phoenix-Hawk Hatchling shouldn't drop them
SET @ENTRY := 34116;

DELETE FROM `reference_loot_template` WHERE `Entry` IN (@ENTRY,@ENTRY+1);
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(@ENTRY,30020,0,0,0,1,1,1,1),
(@ENTRY,30024,0,0,0,1,1,1,1),
(@ENTRY,30026,0,0,0,1,1,1,1),
(@ENTRY,30028,0,0,0,1,1,1,1),
(@ENTRY,30029,0,0,0,1,1,1,1),
(@ENTRY,30030,0,0,0,1,1,1,1),
(@ENTRY+1,30021,0,0,0,1,1,1,1),
(@ENTRY+1,30022,0,0,0,1,1,1,1),
(@ENTRY+1,30023,0,0,0,1,1,1,1),
(@ENTRY+1,30025,0,0,0,1,1,1,1),
(@ENTRY+1,30027,0,0,0,1,1,1,1),
(@ENTRY+1,30620,0,0,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE (`Entry` IN (20031,20032,20033,20034,20035,20036,20037,20039,20040,20041,20042,20043,20044,20045,20046,20047,20048,20049,20050,20052) AND (`Item` IN (30020,30024,30026,30028,30029,30030) OR `Item` = @ENTRY AND `Reference` = @ENTRY)) OR (`Entry` IN (21218,21220,21221,21224,21225,21226,21227,21228,21229,21230,21231,21232,21246,21251,21263,21298,21299,21301,21339,21863) AND (`Item` IN (30021,30022,30023,30025,30027,30620) OR `Item` = @ENTRY+1 AND `Reference` = @ENTRY+1));
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(20031,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20032,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20033,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20034,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20035,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20036,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20037,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20039,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20040,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20041,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20042,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20043,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20044,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20045,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20046,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20047,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20048,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20049,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20050,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(20052,@ENTRY,@ENTRY,2,0,1,1,1,1,"Epic Items (Tempest Keep)"),
(21218,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21220,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21221,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21224,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21225,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21226,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21227,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21228,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21229,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21230,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21231,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21232,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21246,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21251,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21263,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21298,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21299,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21301,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21339,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)"),
(21863,@ENTRY+1,@ENTRY+1,2,0,1,1,1,1,"Epic Items (Serpentshrine Cavern)");

UPDATE `creature_template` SET `lootid` = 20047 WHERE `entry` = 20047;
