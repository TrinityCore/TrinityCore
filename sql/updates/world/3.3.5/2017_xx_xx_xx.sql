-- Malar Bravehorn, tauren
DELETE FROM `creature_text` WHERE `entry`=29032;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29032, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29286), 12, 0, 100, 0, 0, 0, 29286, 0, 'special_surprise SAY_EXEC_START'),
(29032, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29287), 12, 0, 100, 0, 0, 0, 29287, 0, 'special_surprise SAY_EXEC_PROG'),
(29032, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29288), 12, 0, 100, 0, 0, 0, 29288, 0, 'special_surprise SAY_EXEC_NAME'),
(29032, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29289), 12, 0, 100, 0, 0, 0, 29289, 0, 'special_surprise SAY_EXEC_RECOG'),
(29032, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29290), 12, 0, 100, 0, 0, 0, 29290, 0, 'special_surprise SAY_EXEC_NOREM'),
(29032, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29294), 12, 0, 100, 0, 0, 0, 29294, 0, 'special_surprise SAY_EXEC_THINK'),
(29032, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29295), 12, 0, 100, 0, 0, 0, 29295, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29032, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29301), 12, 0, 100, 0, 0, 0, 29301, 0, 'special_surprise SAY_EXEC_TIME'),
(29032, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29302), 12, 0, 100, 0, 0, 0, 29302, 0, 'special_surprise SAY_EXEC_WAITING'),
(29032, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29303), 16, 0, 100, 0, 0, 0, 29303, 0, 'special_surprise EMOTE_DIES');

-- Ellen Stanbridge, human
DELETE FROM `creature_text` WHERE `entry`=29061;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29061, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29310), 12, 0, 100, 0, 0, 0, 29310, 0, 'special_surprise SAY_EXEC_START'),
(29061, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29311), 12, 0, 100, 0, 0, 0, 29311, 0, 'special_surprise SAY_EXEC_PROG'),
(29061, 2, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29312), 12, 0, 100, 0, 0, 0, 29312, 0, 'special_surprise SAY_EXEC_NAME'),
(29061, 3, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29313), 12, 0, 100, 0, 0, 0, 29313, 0, 'special_surprise SAY_EXEC_RECOG'),
(29061, 4, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29314), 12, 0, 100, 0, 0, 0, 29314, 0, 'special_surprise SAY_EXEC_NOREM'),
(29061, 5, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29315), 12, 0, 100, 0, 0, 0, 29315, 0, 'special_surprise SAY_EXEC_THINK'),
(29061, 6, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29316), 12, 0, 100, 0, 0, 0, 29316, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29061, 7, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29317), 12, 0, 100, 0, 0, 0, 29317, 0, 'special_surprise SAY_EXEC_TIME'),
(29061, 8, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29318), 12, 0, 100, 0, 0, 0, 29318, 0, 'special_surprise SAY_EXEC_WAITING'),
(29061, 9, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29319), 16, 0, 100, 0, 0, 0, 29319, 0, 'special_surprise EMOTE_DIES');

-- Yazmina Oakenthorn, night elf
DELETE FROM `creature_text` WHERE `entry`=29065;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29065, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29322), 12, 0, 100, 0, 0, 0, 29322, 0, 'special_surprise SAY_EXEC_START'),
(29065, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29323), 12, 0, 100, 0, 0, 0, 29323, 0, 'special_surprise SAY_EXEC_PROG'),
(29065, 2, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29324), 12, 0, 100, 0, 0, 0, 29324, 0, 'special_surprise SAY_EXEC_NAME'),
(29065, 3, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29325), 12, 0, 100, 0, 0, 0, 29325, 0, 'special_surprise SAY_EXEC_RECOG'),
(29065, 4, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29326), 12, 0, 100, 0, 0, 0, 29326, 0, 'special_surprise SAY_EXEC_NOREM'),
(29065, 5, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29328), 12, 0, 100, 0, 0, 0, 29328, 0, 'special_surprise SAY_EXEC_THINK'),
(29065, 6, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29389), 12, 0, 100, 0, 0, 0, 29389, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29065, 7, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29330), 12, 0, 100, 0, 0, 0, 29330, 0, 'special_surprise SAY_EXEC_TIME'),
(29065, 8, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29331), 12, 0, 100, 0, 0, 0, 29331, 0, 'special_surprise SAY_EXEC_WAITING'),
(29065, 9, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29333), 16, 0, 100, 0, 0, 0, 29333, 0, 'special_surprise EMOTE_DIES');

-- Donovan Pulfrost, dwarf
DELETE FROM `creature_text` WHERE `entry`=29067;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29067, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29335), 12, 0, 100, 0, 0, 0, 29335, 0, 'special_surprise SAY_EXEC_START'),
(29067, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29336), 12, 0, 100, 0, 0, 0, 29336, 0, 'special_surprise SAY_EXEC_PROG'),
(29067, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29337), 12, 0, 100, 0, 0, 0, 29337, 0, 'special_surprise SAY_EXEC_NAME'),
(29067, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29338), 12, 0, 100, 0, 0, 0, 29338, 0, 'special_surprise SAY_EXEC_RECOG'),
(29067, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29339), 12, 0, 100, 0, 0, 0, 29339, 0, 'special_surprise SAY_EXEC_NOREM'),
(29067, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29340), 12, 0, 100, 0, 0, 0, 29340, 0, 'special_surprise SAY_EXEC_THINK'),
(29067, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29341), 12, 0, 100, 0, 0, 0, 29341, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29067, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29342), 12, 0, 100, 0, 0, 0, 29342, 0, 'special_surprise SAY_EXEC_TIME'),
(29067, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29343), 12, 0, 100, 0, 0, 0, 29343, 0, 'special_surprise SAY_EXEC_WAITING'),
(29067, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29344), 16, 0, 100, 0, 0, 0, 29344, 0, 'special_surprise EMOTE_DIES');

-- Goby Blastenheimer, gnome
DELETE FROM `creature_text` WHERE `entry`=29068;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29068, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29347), 12, 0, 100, 0, 0, 0, 29347, 0, 'special_surprise SAY_EXEC_START'),
(29068, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29348), 12, 0, 100, 0, 0, 0, 29348, 0, 'special_surprise SAY_EXEC_PROG'),
(29068, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29349), 12, 0, 100, 0, 0, 0, 29349, 0, 'special_surprise SAY_EXEC_NAME'),
(29068, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29350), 12, 0, 100, 0, 0, 0, 29350, 0, 'special_surprise SAY_EXEC_RECOG'),
(29068, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29351), 12, 0, 100, 0, 0, 0, 29351, 0, 'special_surprise SAY_EXEC_NOREM'),
(29068, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29352), 12, 0, 100, 0, 0, 0, 29352, 0, 'special_surprise SAY_EXEC_THINK'),
(29068, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29353), 12, 0, 100, 0, 0, 0, 29353, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29068, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29354), 12, 0, 100, 0, 0, 0, 29354, 0, 'special_surprise SAY_EXEC_TIME'),
(29068, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29355), 12, 0, 100, 0, 0, 0, 29355, 0, 'special_surprise SAY_EXEC_WAITING'),
(29068, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29356), 16, 0, 100, 0, 0, 0, 29356, 0, 'special_surprise EMOTE_DIES');

-- Valok the Righteous, draenai
DELETE FROM `creature_text` WHERE `entry`=29070;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29070, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29357), 12, 0, 100, 0, 0, 0, 29357, 0, 'special_surprise SAY_EXEC_START'),
(29070, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29358), 12, 0, 100, 0, 0, 0, 29358, 0, 'special_surprise SAY_EXEC_PROG'),
(29070, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29359), 12, 0, 100, 0, 0, 0, 29359, 0, 'special_surprise SAY_EXEC_NAME'),
(29070, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29360), 12, 0, 100, 0, 0, 0, 29360, 0, 'special_surprise SAY_EXEC_RECOG'),
(29070, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29361), 12, 0, 100, 0, 0, 0, 29361, 0, 'special_surprise SAY_EXEC_NOREM'),
(29070, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29362), 12, 0, 100, 0, 0, 0, 29362, 0, 'special_surprise SAY_EXEC_THINK'),
(29070, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29363), 12, 0, 100, 0, 0, 0, 29363, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29070, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29364), 12, 0, 100, 0, 0, 0, 29364, 0, 'special_surprise SAY_EXEC_TIME'),
(29070, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29365), 12, 0, 100, 0, 0, 0, 29365, 0, 'special_surprise SAY_EXEC_WAITING'),
(29070, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29366), 16, 0, 100, 0, 0, 0, 29366, 0, 'special_surprise EMOTE_DIES');

-- Antoine Brack, undead
DELETE FROM `creature_text` WHERE `entry`=29071;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29071, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29393), 12, 0, 100, 0, 0, 0, 29393, 0, 'special_surprise SAY_EXEC_START'),
(29071, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29394), 12, 0, 100, 0, 0, 0, 29394, 0, 'special_surprise SAY_EXEC_PROG'),
(29071, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29395), 12, 0, 100, 0, 0, 0, 29395, 0, 'special_surprise SAY_EXEC_NAME'),
(29071, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29396), 12, 0, 100, 0, 0, 0, 29396, 0, 'special_surprise SAY_EXEC_RECOG'),
(29071, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29397), 12, 0, 100, 0, 0, 0, 29397, 0, 'special_surprise SAY_EXEC_NOREM'),
(29071, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29398), 12, 0, 100, 0, 0, 0, 29398, 0, 'special_surprise SAY_EXEC_THINK'),
(29071, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29399), 12, 0, 100, 0, 0, 0, 29399, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29071, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29400), 12, 0, 100, 0, 0, 0, 29400, 0, 'special_surprise SAY_EXEC_TIME'),
(29071, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29401), 12, 0, 100, 0, 0, 0, 29401, 0, 'special_surprise SAY_EXEC_WAITING'),
(29071, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29402), 16, 0, 100, 0, 0, 0, 29402, 0, 'special_surprise EMOTE_DIES');

-- Kug Ironjaw, orc
DELETE FROM `creature_text` WHERE `entry`=29072;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29072, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29383), 12, 0, 100, 0, 0, 0, 29383, 0, 'special_surprise SAY_EXEC_START'),
(29072, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29384), 12, 0, 100, 0, 0, 0, 29384, 0, 'special_surprise SAY_EXEC_PROG'),
(29072, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29385), 12, 0, 100, 0, 0, 0, 29385, 0, 'special_surprise SAY_EXEC_NAME'),
(29072, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29386), 12, 0, 100, 0, 0, 0, 29386, 0, 'special_surprise SAY_EXEC_RECOG'),
(29072, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29387), 12, 0, 100, 0, 0, 0, 29387, 0, 'special_surprise SAY_EXEC_NOREM'),
(29072, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29388), 12, 0, 100, 0, 0, 0, 29388, 0, 'special_surprise SAY_EXEC_THINK'),
(29072, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29389), 12, 0, 100, 0, 0, 0, 29389, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29072, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29390), 12, 0, 100, 0, 0, 0, 29390, 0, 'special_surprise SAY_EXEC_TIME'),
(29072, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29391), 12, 0, 100, 0, 0, 0, 29391, 0, 'special_surprise SAY_EXEC_WAITING'),
(29072, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29392), 16, 0, 100, 0, 0, 0, 29392, 0, 'special_surprise EMOTE_DIES');

-- Iggy Darktusk, troll
DELETE FROM `creature_text` WHERE `entry`=29073;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29073, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29403), 12, 0, 100, 0, 0, 0, 29403, 0, 'special_surprise SAY_EXEC_START'),
(29073, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29404), 12, 0, 100, 0, 0, 0, 29404, 0, 'special_surprise SAY_EXEC_PROG'),
(29073, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29405), 12, 0, 100, 0, 0, 0, 29405, 0, 'special_surprise SAY_EXEC_NAME'),
(29073, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29406), 12, 0, 100, 0, 0, 0, 29406, 0, 'special_surprise SAY_EXEC_RECOG'),
(29073, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29407), 12, 0, 100, 0, 0, 0, 29407, 0, 'special_surprise SAY_EXEC_NOREM'),
(29073, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29408), 12, 0, 100, 0, 0, 0, 29408, 0, 'special_surprise SAY_EXEC_THINK'),
(29073, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29409), 12, 0, 100, 0, 0, 0, 29409, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29073, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29410), 12, 0, 100, 0, 0, 0, 29410, 0, 'special_surprise SAY_EXEC_TIME'),
(29073, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29411), 12, 0, 100, 0, 0, 0, 29411, 0, 'special_surprise SAY_EXEC_WAITING'),
(29073, 9, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29412), 16, 0, 100, 0, 0, 0, 29412, 0, 'special_surprise EMOTE_DIES');

-- Lady Eonys, blood elf
DELETE FROM `creature_text` WHERE `entry`=29074;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29074, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29368), 12, 0, 100, 0, 0, 0, 29368, 0, 'special_surprise SAY_EXEC_START'),
(29074, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29369), 12, 0, 100, 0, 0, 0, 29369, 0, 'special_surprise SAY_EXEC_PROG'),
(29074, 2, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29372), 12, 0, 100, 0, 0, 0, 29372, 0, 'special_surprise SAY_EXEC_NAME'),
(29074, 3, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29370), 12, 0, 100, 0, 0, 0, 29370, 0, 'special_surprise SAY_EXEC_RECOG'),
(29074, 4, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29373), 12, 0, 100, 0, 0, 0, 29373, 0, 'special_surprise SAY_EXEC_NOREM'),
(29074, 5, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29374), 12, 0, 100, 0, 0, 0, 29374, 0, 'special_surprise SAY_EXEC_THINK'),
(29074, 6, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29375), 12, 0, 100, 0, 0, 0, 29375, 0, 'special_surprise SAY_EXEC_LISTEN'),
(29074, 7, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29376), 12, 0, 100, 0, 0, 0, 29376, 0, 'special_surprise SAY_EXEC_TIME'),
(29074, 8, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=29377), 12, 0, 100, 0, 0, 0, 29377, 0, 'special_surprise SAY_EXEC_WAITING'),
(29074, 9, 0, (SELECT `MaleText`   FROM `broadcast_text` WHERE `ID`=29378), 16, 0, 100, 0, 0, 0, 29378, 0, 'special_surprise EMOTE_DIES'); -- maletext, strange, but true

-- Knight Commander Plaguefist
DELETE FROM `creature_text` WHERE `entry`=29053;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29053, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=29382), 14, 0, 100, 0, 0, 0, 29382, 0, 'special_surprise SAY_PLAGUEFIST');
