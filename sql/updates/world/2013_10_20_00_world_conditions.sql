-- DB/Conditions: Fix conditions for class trainer npcs, so gossip menus will show up correctly for every class
SET @ALLCLASMASK := 1535;
SET @CLASSMASK_PAL := 2;
SET @CLASSMASK_DK := 32;
SET @CLASSMASK_SHA := 64;

SET @MENU := 4104;
SET @MENU1 := 4528;
SET @MENU2 := 4530;
SET @MENU3 := 4529;
SET @MENU4 := 4103;
SET @MENU5 := 4652;
SET @MENU6 := 4516;
SET @MENU7 := 5123;
SET @TEXTIDOK := 5005;
SET @TEXTIDERR := 5006;

SET @MENU8 := 4515;
SET @TEXTIDOK8 := 5007;
SET @TEXTIDERR8 := 5008;

SET @MENU9 := 6647;
SET @TEXTIDOK9 := 7904;
SET @TEXTIDERR9 := 9193;

SET @MENU10 := 7522;
SET @TEXTIDOK10 := 9122;
SET @TEXTIDERR10 := 8785;

SET @MENU11 := 7377;
SET @TEXTIDOK11 := 8829;
SET @TEXTIDERR11 := 8828;

SET @MENU12 := 7467;
SET @TEXTIDOK12 := 9050;

SET @MENU13 := 7357;
SET @TEXTIDOK13 := 8786;

SET @MENU14 := 8110;
SET @TEXTIDOK14 := 10043;
SET @TEXTIDERR14 := 10040;

SET @MENU15 := 9691;
SET @MENU16 := 9692;
SET @MENU17 := 9693;

SET @TRAINEROPT := 0;
SET @TALENTOPT := 1;
SET @DUALOPT := 2;

SET @TRAINEROPT11 := 0;
SET @TALENTOPT11 := 2;
SET @DUALOPT11 := 3;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND
(
    (`SourceEntry` IN (@TEXTIDOK, @TEXTIDERR) AND `SourceGroup` IN (@MENU, @MENU1, @MENU2, @MENU3, @MENU4, @MENU5, @MENU6, @MENU7))
    OR (`SourceEntry` IN (@TEXTIDOK8, @TEXTIDERR8) AND `SourceGroup` = @MENU8)
    OR (`SourceEntry` IN (@TEXTIDOK9, @TEXTIDERR9) AND `SourceGroup` = @MENU9)
    OR (`SourceEntry` IN (@TEXTIDOK10, @TEXTIDERR10) AND `SourceGroup` = @MENU10)
    OR (`SourceEntry` IN (@TEXTIDOK11, @TEXTIDERR11) AND `SourceGroup` = @MENU11)
    OR (`SourceEntry` IN (@TEXTIDOK12, @TEXTIDERR10) AND `SourceGroup` = @MENU12)
    OR (`SourceEntry` IN (@TEXTIDOK13, @TEXTIDERR10) AND `SourceGroup` = @MENU13)
    OR (`SourceEntry` IN (@TEXTIDOK14, @TEXTIDERR14) AND `SourceGroup` = @MENU14)
);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceEntry` IN (@TRAINEROPT, @TALENTOPT, @DUALOPT)  AND `SourceGroup` IN (@MENU, @MENU1, @MENU2, @MENU3, @MENU4, @MENU5, @MENU6, @MENU7, @MENU8, @MENU9, @MENU10, @MENU12, @MENU13, @MENU14, @MENU15, @MENU16, @MENU17);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceEntry` IN (@TRAINEROPT11, @TALENTOPT11, @DUALOPT11)  AND `SourceGroup` = @MENU11;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
-- NPC ID: 986, Name: Haromm, Menu-ID: 4104, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 3173, Name: Swart, Menu-ID: 4104, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3030, Name: Siln Skychaser, Menu-ID: 4528, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU1, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU1, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU1, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU1, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU1, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3031, Name: Tigor Skychaser, Menu-ID: 4530, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU2, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU2, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU2, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU2, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU2, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3032, Name: Beram Skychaser, Menu-ID: 4529, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU3, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU3, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU3, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU3, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU3, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3062, Name: Meela Dawnstrider, Menu-ID: 4103, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 3066, Name: Narm Skychaser, Menu-ID: 4103, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU4, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU4, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU4, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU4, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU4, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3157, Name: Shikrik, Menu-ID: 4652, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU5, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU5, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU5, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU5, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU5, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3344, Name: Kardris Dreamseeker, Menu-ID: 4516, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU6, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU6, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU6, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU6, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU6, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 13417, Name: Sagorne Creststrider, Menu-ID: 5123, Trainer-Classmask: 64, Text-ID1: 5005, Text-ID2: 5006, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU7, @TEXTIDOK, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU7, @TEXTIDERR, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU7, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU7, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU7, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 3403, Name: Sian'tsu, Menu-ID: 4515, Trainer-Classmask: 64, Text-ID1: 5007, Text-ID2: 5008, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU8, @TEXTIDOK8, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU8, @TEXTIDERR8, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU8, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU8, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU8, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 15280, Name: Jesthenis Sunstriker, Menu-ID: 6647, Trainer-Classmask: 2, Text-ID1: 7904, Text-ID2: 9193, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 16275, Name: Noellene, Menu-ID: 6647, Trainer-Classmask: 2, Text-ID1: 7904, Text-ID2: 9193, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 16679, Name: Osselan, Menu-ID: 6647, Trainer-Classmask: 2, Text-ID1: 7904, Text-ID2: 9193, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 16680, Name: Ithelis, Menu-ID: 6647, Trainer-Classmask: 2, Text-ID1: 7904, Text-ID2: 9193, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 16681, Name: Champion Bachi, Menu-ID: 6647, Trainer-Classmask: 2, Text-ID1: 7904, Text-ID2: 9193, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 23128, Name: Master Pyreanor, Menu-ID: 6647, Trainer-Classmask: 2, Text-ID1: 7904, Text-ID2: 9193, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU9, @TEXTIDOK9, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Paladin'),
(14, @MENU9, @TEXTIDERR9, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_PAL), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Paladin'),
(15, @MENU9, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Paladin'),
(15, @MENU9, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Paladin'),
(15, @MENU9, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Paladin'),
-- NPC ID: 17089, Name: Firmanvaar, Menu-ID: 7522, Trainer-Classmask: 64, Text-ID1: 8785, Text-ID2: 9122, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU10, @TEXTIDOK10, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU10, @TEXTIDERR10, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU10, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU10, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU10, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 17204, Name: Farseer Nobundo, Menu-ID: 7377, Trainer-Classmask: 64, Text-ID1: 8828, Text-ID2: 8829, Trainer-Option: 0, Talent-Option: 2, Dualspec-Option: 3
(14, @MENU11, @TEXTIDOK11, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU11, @TEXTIDERR11, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU11, @TRAINEROPT11, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU11, @TALENTOPT11, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU11, @DUALOPT11, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 17212, Name: Tuluun, Menu-ID: 7467, Trainer-Classmask: 64, Text-ID1: 8785, Text-ID2: 9050, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU12, @TEXTIDOK12, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU12, @TEXTIDERR10, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU12, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU12, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU12, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 17219, Name: Sulaa, Menu-ID: 7357, Trainer-Classmask: 64, Text-ID1: 8785, Text-ID2: 8786, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 23127, Name: Farseer Javad, Menu-ID: 7357, Trainer-Classmask: 64, Text-ID1: 8785, Text-ID2: 8786, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 17519, Name: Hobahken, Menu-ID: 7357, Trainer-Classmask: 64, Text-ID1: 8785, Text-ID2: 8786, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 17520, Name: Gurrag, Menu-ID: 7357, Trainer-Classmask: 64, Text-ID1: 8785, Text-ID2: 8786, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU13, @TEXTIDOK13, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU13, @TEXTIDERR10, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU13, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU13, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU13, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 20407, Name: Farseer Umbrua, Menu-ID: 8110, Trainer-Classmask: 64, Text-ID1: 10040, Text-ID2: 10043, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(14, @MENU14, @TEXTIDOK14, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Shaman'),
(14, @MENU14, @TEXTIDERR14, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_SHA), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Shaman'),
(15, @MENU14, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU14, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
(15, @MENU14, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_SHA, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Shaman'),
-- NPC ID: 29195, Name: Lady Alistra, Menu-ID: 9691, Trainer-Classmask: 32, Text-ID1: 13172, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 28471, Name: Lady Alistra, Menu-ID: 9691, Trainer-Classmask: 32, Text-ID1: 13172, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(15, @MENU15, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
(15, @MENU15, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
(15, @MENU15, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
-- NPC ID: 29196, Name: Lord Thorval, Menu-ID: 9692, Trainer-Classmask: 32, Text-ID1: 13173, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 28472, Name: Lord Thorval, Menu-ID: 9692, Trainer-Classmask: 32, Text-ID1: 13173, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(15, @MENU16, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
(15, @MENU16, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
(15, @MENU16, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
-- NPC ID: 29194, Name: Amal'thazad, Menu-ID: 9693, Trainer-Classmask: 32, Text-ID1: 13174, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
-- NPC ID: 28474, Name: Amal'thazad, Menu-ID: 9693, Trainer-Classmask: 32, Text-ID1: 13174, Trainer-Option: 0, Talent-Option: 1, Dualspec-Option: 2
(15, @MENU17, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
(15, @MENU17, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight'),
(15, @MENU17, @DUALOPT, 0, 0, 15, 0, @CLASSMASK_DK, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Death Knight');
