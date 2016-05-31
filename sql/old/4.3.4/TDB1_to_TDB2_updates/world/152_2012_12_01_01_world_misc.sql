-- The Sons of Hodir
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry` IN (44133,50335,44134,50336,44136,50337,44135,50338);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,32540,44133,0,0,5,0,1119,128,0,0,0,0,'','Greater Inscription of the Axe - when The Sons of Hodir exalted'),
(23,32540,50335,0,0,5,0,1119,127,0,0,0,0,'','Greater Inscription of the Axe - when The Sons of Hodir not exalted'),
(23,32540,44134,0,0,5,0,1119,128,0,0,0,0,'','Greater Inscription of the Crag - when The Sons of Hodir exalted'),
(23,32540,50336,0,0,5,0,1119,127,0,0,0,0,'','Greater Inscription of the Crag - when The Sons of Hodir not exalted'),
(23,32540,44136,0,0,5,0,1119,128,0,0,0,0,'','Greater Inscription of the Pinnacle - when The Sons of Hodir exalted'),
(23,32540,50337,0,0,5,0,1119,127,0,0,0,0,'','Greater Inscription of the Pinnacle - when The Sons of Hodir not exalted'),
(23,32540,44135,0,0,5,0,1119,128,0,0,0,0,'','Greater Inscription of the Storm - when The Sons of Hodir exalted'),
(23,32540,50338,0,0,5,0,1119,127,0,0,0,0,'','Greater Inscription of the Storm - when The Sons of Hodir not exalted');

DELETE FROM `npc_vendor` WHERE `entry`=32540 AND `item` IN (50335,50336,50337,50338);
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(32540,0,50335,0,0,0), -- Greater Inscription of the Axe
(32540,0,50336,0,0,0), -- Greater Inscription of the Crag
(32540,0,50337,0,0,0), -- Greater Inscription of the Pinnacle
(32540,0,50338,0,0,0); -- Greater Inscription of the Storm

-- Knights of the Ebon Blade
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry` IN (44149,50367);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,32538,44149,0,0,5,0,1098,192,0,0,0,0,'','Arcanum of Torment - when Knights of the Ebon Blade revered/exalted'),
(23,32538,50367,0,0,5,0,1098,63,0,0,0,0,'','Arcanum of Torment - when Knights of the Ebon Blade not revered/exalted');

DELETE FROM `npc_vendor` WHERE `entry`=32538 AND `item`=50367;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(32538,0,50367,0,0,0); -- Arcanum of Torment

-- Kirin Tor
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry` IN (44159,50368);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,32287,44159,0,0,5,0,1090,192,0,0,0,0,'','Arcanum of Burning Mysteries - when Kirin Tor revered/exalted'),
(23,32287,50368,0,0,5,0,1090,63,0,0,0,0,'','Arcanum of Burning Mysteries - when Kirin Tor not revered/exalted');

DELETE FROM `npc_vendor` WHERE `entry`=32287 AND `item`=50368;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(32287,0,50368,0,0,0); -- Arcanum of Burning Mysteries

-- The Wyrmrest Accord
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry` IN (44152,50370);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,32533,44152,0,0,5,0,1091,192,0,0,0,0,'','Arcanum of Blissful Mending - when The Wyrmrest Accord revered/exalted'),
(23,32533,50370,0,0,5,0,1091,63,0,0,0,0,'','Arcanum of Blissful Mending - when The Wyrmrest Accord not revered/exalted');

DELETE FROM `npc_vendor` WHERE `entry`=32533 AND `item`=50370;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(32533,0,50370,0,0,0); -- Arcanum of Blissful Mending

-- Horde Expedition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry` IN (44702,50373);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,32774,44702,0,0,5,0,1052,128,0,0,0,0,'','Arcanum of the Savage Gladiator - when Horde Expedition exalted'),
(23,32774,50373,0,0,5,0,1052,127,0,0,0,0,'','Arcanum of the Savage Gladiator - when Horde Expedition not exalted'),
(23,32565,44702,0,0,5,0,1052,128,0,0,0,0,'','Arcanum of the Savage Gladiator - when Horde Expeditione exalted'),
(23,32565,50373,0,0,5,0,1052,127,0,0,0,0,'','Arcanum of the Savage Gladiator - when Horde Expedition not exalted');

DELETE FROM `npc_vendor` WHERE `entry` IN (32565,32774) AND `item`=50373;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(32565,0,50373,0,0,0), -- Arcanum of the Savage Gladiator
(32774,0,50373,0,0,0); -- Arcanum of the Savage Gladiator

-- Alliance Vanguard
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry` IN (44701,50372);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,32564,44701,0,0,5,0,1037,128,0,0,0,0,'','Arcanum of the Savage Gladiator - when Alliance Vanguard rexalted'),
(23,32564,50372,0,0,5,0,1037,127,0,0,0,0,'','Arcanum of the Savage Gladiator - when Alliance Vanguard not exalted'),
(23,32773,44701,0,0,5,0,1037,128,0,0,0,0,'','Arcanum of the Savage Gladiator - when Alliance Vanguard exalted'),
(23,32773,50372,0,0,5,0,1037,127,0,0,0,0,'','Arcanum of the Savage Gladiator - when Alliance Vanguard not exalted');

DELETE FROM `npc_vendor` WHERE `entry` IN (32773,32564) AND `item`=50372;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(32564,0,50372,0,0,0), -- Arcanum of the Savage Gladiator
(32773,0,50372,0,0,0); -- Arcanum of the Savage Gladiator
