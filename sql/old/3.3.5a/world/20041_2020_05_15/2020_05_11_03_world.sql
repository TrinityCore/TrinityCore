-- RFK
SET @ENTRY := 14102;
DELETE FROM `reference_loot_template` WHERE `Entry` = @ENTRY;
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(@ENTRY,776,0,0,0,1,1,1,1),
(@ENTRY,1488,0,0,0,1,1,1,1),
(@ENTRY,1727,0,0,0,1,1,1,1),
(@ENTRY,1975,0,0,0,1,1,1,1),
(@ENTRY,1976,0,0,0,1,1,1,1),
(@ENTRY,1978,0,0,0,1,1,1,1),
(@ENTRY,2039,0,0,0,1,1,1,1),
(@ENTRY,2264,0,0,0,1,1,1,1),
(@ENTRY,2549,0,0,0,1,1,1,1),
(@ENTRY,4438,0,0,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `Entry` IN (4427,4435,4436,4437,4438,4440,4442,4511,4512,4514,4515,4516,4517,4518,4519,4520,4522,4523,4525,4530,4531,4532,4538,4539,4623,6035,6168) AND ((`Item` IN (776,1488,1727,1975,1976,1978,2039,2264,2549,4438) AND `Reference` = 0) OR `Reference` = @ENTRY);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(4427,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4435,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4436,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4437,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4438,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4440,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4442,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4511,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4512,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4514,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4515,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4516,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4517,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4518,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4519,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4520,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4522,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4523,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4525,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4530,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4531,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4532,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4538,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4539,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(4623,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(6035,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)"),
(6168,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFK)");

-- RFD
SET @ENTRY := 14103;
DELETE FROM `reference_loot_template` WHERE `Entry` = @ENTRY;
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(@ENTRY,10567,0,0,0,1,1,1,1),
(@ENTRY,10570,0,0,0,1,1,1,1),
(@ENTRY,10571,0,0,0,1,1,1,1),
(@ENTRY,10572,0,0,0,1,1,1,1),
(@ENTRY,10573,0,0,0,1,1,1,1),
(@ENTRY,10574,0,0,0,1,1,1,1),
(@ENTRY,10578,0,0,0,1,1,1,1),
(@ENTRY,10581,0,0,0,1,1,1,1),
(@ENTRY,10582,0,0,0,1,1,1,1),
(@ENTRY,10583,0,0,0,1,1,1,1),
(@ENTRY,10584,0,0,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `Entry` IN (7327,7328,7329,7332,7335,7337,7341,7342,7345,7347,7348,7349,7351,7352,7353/*,7872,7873,7874,12865*/) AND ((`Item` IN (10567,10570,10571,10572,10573,10574,10578,10581,10582,10583,10584) AND `Reference` = 0) OR `Reference` = @ENTRY);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(7327,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7328,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7329,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7332,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7335,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7337,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7341,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7342,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7345,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7347,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7348,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7349,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7351,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7352,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
(7353,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)");
-- (7872,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
-- (7873,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
-- (7874,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)"),
-- (12865,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (RFD)");

/*
-- Scarlet Monastery(Outside)
SET @ENTRY := 14104;
DELETE FROM `reference_loot_template` WHERE `Entry` = @ENTRY;
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(@ENTRY,5819,0,0,0,1,1,1,1),
(@ENTRY,7727,0,0,0,1,1,1,1),
(@ENTRY,7728,0,0,0,1,1,1,1),
(@ENTRY,7729,0,0,0,1,1,1,1),
(@ENTRY,7730,0,0,0,1,1,1,1),
(@ENTRY,7752,0,0,0,1,1,1,1),
(@ENTRY,7753,0,0,0,1,1,1,1),
(@ENTRY,7754,0,0,0,1,1,1,1),
(@ENTRY,7786,0,0,0,1,1,1,1),
(@ENTRY,7787,0,0,0,1,1,1,1),
(@ENTRY,8226,0,0,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `Entry` IN (4280,4281,4282,4283,4284,4285) AND ((`Item` IN (5819,7727,7728,7729,7730,7752,7753,7754,7786,7787,8226) AND `Reference` = 0) OR `Reference` = @ENTRY);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(4280,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Outside))"),
(4281,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Outside))"),
(4282,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Outside))"),
(4283,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Outside))"),
(4284,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Outside))"),
(4285,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Outside))");
*/

-- Scarlet Monastery(Inside)
SET @ENTRY := 14104;
DELETE FROM `reference_loot_template` WHERE `Entry` = @ENTRY;
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(@ENTRY,1992,0,0,0,1,1,1,1),
(@ENTRY,2262,0,0,0,1,1,1,1),
(@ENTRY,5756,0,0,0,1,1,1,1),
(@ENTRY,5819,0,0,0,1,1,1,1),
(@ENTRY,7727,0,0,0,1,1,1,1),
(@ENTRY,7728,0,0,0,1,1,1,1),
(@ENTRY,7729,0,0,0,1,1,1,1),
(@ENTRY,7730,0,0,0,1,1,1,1),
(@ENTRY,7736,0,0,0,1,1,1,1),
(@ENTRY,7752,0,0,0,1,1,1,1),
(@ENTRY,7753,0,0,0,1,1,1,1),
(@ENTRY,7754,0,0,0,1,1,1,1),
(@ENTRY,7755,0,0,0,1,1,1,1),
(@ENTRY,7757,0,0,0,1,1,1,1),
(@ENTRY,7758,0,0,0,1,1,1,1),
(@ENTRY,7759,0,0,0,1,1,1,1),
(@ENTRY,7760,0,0,0,1,1,1,1),
(@ENTRY,7761,0,0,0,1,1,1,1),
(@ENTRY,7786,0,0,0,1,1,1,1),
(@ENTRY,7787,0,0,0,1,1,1,1),
(@ENTRY,8225,0,0,0,1,1,1,1),
(@ENTRY,8226,0,0,0,1,1,1,1),
(@ENTRY,10332,0,0,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `Entry` IN (4286,4287,4288,4289,4290,4291,4292,4293,4294,4295,4296,4297,4298,4299,4300,4301,4302,4303,4304,4306,4308,4540,6426,6427) AND ((`Item` IN (1992,2262,5756,5819,7727,7728,7729,7730,7736,7752,7753,7754,7755,7757,7758,7759,7760,7761,7786,7787,8225,8226,10332) AND `Reference` = 0) OR `Reference` = @ENTRY);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(4286,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4287,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4288,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4289,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4290,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4291,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4292,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4293,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4294,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4295,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4296,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4297,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4298,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4299,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4300,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4301,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4302,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4303,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4304,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4306,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4308,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(4540,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(6426,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))"),
(6427,@ENTRY,@ENTRY,0.1,0,1,0,1,1,"Rare Blue Items (Scarlet Monastery(Inside))");
