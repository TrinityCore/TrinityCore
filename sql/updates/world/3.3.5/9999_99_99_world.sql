--
-- Add missing gossip_menu
DELETE FROM `gossip_menu` WHERE (`MenuID`,`TextID`) IN ((7552,9380),(7581,9232),(7581,9233));
INSERT INTO `gossip_menu`(`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7552, 9380, 0),
(7581, 9232, 0),
(7581, 9233, 0);

-- Add missing npc_text
DELETE FROM `npc_text` WHERE `ID` IN (9232,9233);
INSERT INTO `npc_text`(`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `EmoteDelay0_0`, `Emote0_0`, `EmoteDelay0_1`, `Emote0_1`, `EmoteDelay0_2`, `Emote0_2`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `Probability1`, `EmoteDelay1_0`, `Emote1_0`, `EmoteDelay1_1`, `Emote1_1`, `EmoteDelay1_2`, `Emote1_2`, `text2_0`, `text2_1`, `BroadcastTextID2`, `lang2`, `Probability2`, `EmoteDelay2_0`, `Emote2_0`, `EmoteDelay2_1`, `Emote2_1`, `EmoteDelay2_2`, `Emote2_2`, `text3_0`, `text3_1`, `BroadcastTextID3`, `lang3`, `Probability3`, `EmoteDelay3_0`, `Emote3_0`, `EmoteDelay3_1`, `Emote3_1`, `EmoteDelay3_2`, `Emote3_2`, `text4_0`, `text4_1`, `BroadcastTextID4`, `lang4`, `Probability4`, `EmoteDelay4_0`, `Emote4_0`, `EmoteDelay4_1`, `Emote4_1`, `EmoteDelay4_2`, `Emote4_2`, `text5_0`, `text5_1`, `BroadcastTextID5`, `lang5`, `Probability5`, `EmoteDelay5_0`, `Emote5_0`, `EmoteDelay5_1`, `Emote5_1`, `EmoteDelay5_2`, `Emote5_2`, `text6_0`, `text6_1`, `BroadcastTextID6`, `lang6`, `Probability6`, `EmoteDelay6_0`, `Emote6_0`, `EmoteDelay6_1`, `Emote6_1`, `EmoteDelay6_2`, `Emote6_2`, `text7_0`, `text7_1`, `BroadcastTextID7`, `lang7`, `Probability7`, `EmoteDelay7_0`, `Emote7_0`, `EmoteDelay7_1`, `Emote7_1`, `EmoteDelay7_2`, `Emote7_2`, `VerifiedBuild`) VALUES
(9232, '', '', 15444, 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9233, '', '', 15448, 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- Trash Mobs Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (17899,17905,17919,17934,17932,17933,17936) AND `GroupID` IN (0,1);
DELETE FROM `creature_text` WHERE `CreatureID`=17772 AND `GroupID`=7;
INSERT INTO `creature_text`(`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17899, 0, 0, '', 12, 0, 100, 0, 0, 0, 18450, 0, 'Shadowy Necromancer say slay'),
(17899, 1, 0, '', 12, 0, 100, 0, 0, 0, 18448, 0, 'Shadowy Necromancer say death'),
(17899, 1, 1, '', 12, 0, 100, 0, 0, 0, 18447, 0, 'Shadowy Necromancer say death'),
(17899, 1, 2, '', 12, 0, 100, 0, 0, 0, 18446, 0, 'Shadowy Necromancer say death'),
(17905, 0, 0, '', 12, 0, 100, 0, 0, 0, 18451, 0, 'Banshee say slay'),
(17905, 0, 1, '', 12, 0, 100, 0, 0, 0, 18454, 0, 'Banshee say slay'),
(17905, 1, 0, '', 12, 0, 100, 0, 0, 0, 18452, 0, 'Banshee say death'),
(17905, 1, 1, '', 12, 0, 100, 0, 0, 0, 18453, 0, 'Banshee say death'),
(17919, 0, 0, '', 12, 0, 100, 0, 0, 0, 18457, 0, 'Alliance Footman say slay'),
(17919, 0, 1, '', 12, 0, 100, 0, 0, 0, 18456, 0, 'Alliance Footman say slay'),
(17919, 1, 0, '', 12, 0, 100, 0, 0, 0, 18458, 0, 'Alliance Footman say death'),
(17934, 0, 0, '', 12, 0, 100, 0, 0, 0, 18501, 0, 'Horde Headhunter say slay'),
(17934, 0, 1, '', 12, 0, 100, 0, 0, 0, 18499, 0, 'Horde Headhunter say slay'),
(17934, 0, 2, '', 12, 0, 100, 0, 0, 0, 18500, 0, 'Horde Headhunter say slay'),
(17934, 1, 0, '', 12, 0, 100, 0, 0, 0, 18502, 0, 'Horde Headhunter say death'),
(17932, 0, 0, '', 12, 0, 100, 0, 0, 0, 18486, 0, 'Horde Grunt say slay'),
(17932, 0, 1, '', 12, 0, 100, 0, 0, 0, 18485, 0, 'Horde Grunt say slay'),
(17932, 0, 2, '', 12, 0, 100, 0, 0, 0, 18488, 0, 'Horde Grunt say slay'),
(17932, 0, 3, '', 12, 0, 100, 0, 0, 0, 18490, 0, 'Horde Grunt say slay'),
(17932, 1, 0, '', 12, 0, 100, 0, 0, 0, 18487, 0, 'Horde Grunt say death'),
(17933, 0, 0, '', 12, 0, 100, 0, 0, 0, 18493, 0, 'Tauren Warrior say slay'),
(17933, 0, 1, '', 12, 0, 100, 0, 0, 0, 18494, 0, 'Tauren Warrior say slay'),
(17933, 1, 0, '', 12, 0, 100, 0, 0, 0, 18495, 0, 'Tauren Warrior say death'),
(17936, 0, 1, '', 12, 0, 100, 0, 0, 0, 18510, 0, 'Horde Shaman say slay'),
(17936, 1, 0, '', 12, 0, 100, 0, 0, 0, 18496, 0, 'Horde Shaman say death'),
(17772, 7, 0, '', 16, 0, 100, 0, 0, 0, 15310, 0, 'jaina hyjal horde base SUCCESS');
