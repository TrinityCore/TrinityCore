DELETE FROM `npc_vendor` WHERE `entry`=216164;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(216164, 1, 228220, 0, 9160, 1, 127041, 0, 58238), -- Waxy Bundle
(216164, 2, 224761, 0, 9007, 1, 0, 0, 58238), -- Quickwick Candle Kit
(216164, 3, 224721, 0, 9007, 1, 0, 0, 58238), -- Wax-Sealed Box
(216164, 4, 224643, 0, 9007, 1, 0, 0, 58238), -- Pet-Sized Candle
(216164, 5, 224722, 0, 9007, 1, 0, 0, 58238), -- Waxy Bundle of Resonance Crystals
(216164, 6, 224760, 0, 9007, 1, 0, 0, 58238), -- Wobbles
(216164, 7, 224723, 0, 9007, 1, 0, 0, 58238), -- Waxy Bundle of Leather
(216164, 8, 224725, 0, 9007, 1, 0, 0, 58238), -- Waxy Bundle of Herbs
(216164, 9, 224726, 0, 9007, 1, 0, 0, 58238), -- Waxy Box of Rocks
(216164, 10, 224724, 0, 9007, 1, 0, 0, 58238), -- Waxy Bundle of Dust
(216164, 11, 224646, 0, 9007, 1, 0, 0, 58238); -- Coppers the Kobold

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=216164;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 216164, 228220, 0, 0, 56, 0, 127041, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only while on quest \"Everyday I\'m Snufflin\'\"'),
(23, 216164, 224761, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224721, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224643, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224722, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224760, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224723, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224725, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224726, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224724, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded'),
(23, 216164, 224646, 0, 0, 8, 0, 79343, 0, 0, '', 0, 0, 0, '', 'Gnawbles vendor - See Waxy Bundle only after quest \"Everyday I\'m Snufflin\'\" is rewarded');

DELETE FROM `quest_template` WHERE `ID` IN (84433,84434);
INSERT INTO `quest_template` (`ID`, `Flags`, `LogTitle`, `LogDescription`) VALUES
(84433, 0x00000400, 'TRACKER Everyday I\'m Snufflin\' ', 'Received free wax from Gnawbles'),
(84434, 0x00000400, 'TRACKER Everyday I\'m Snufflin\' ', 'Waxy Bundle purchased from Gnawbles');
