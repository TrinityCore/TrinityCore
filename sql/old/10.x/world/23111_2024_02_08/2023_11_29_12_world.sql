UPDATE `gameobject_questender` SET `id`=194056 WHERE `id`=190035 AND `quest`=13433;
UPDATE `gameobject_questender` SET `id`=194057 WHERE `id`=190035 AND `quest`=13434;
UPDATE `gameobject_questender` SET `id`=194058 WHERE `id`=190035 AND `quest`=13435;
UPDATE `gameobject_questender` SET `id`=194059 WHERE `id`=190035 AND `quest`=13436;
UPDATE `gameobject_questender` SET `id`=194060 WHERE `id`=190035 AND `quest`=13437;
UPDATE `gameobject_questender` SET `id`=194061 WHERE `id`=190035 AND `quest`=13438;
UPDATE `gameobject_questender` SET `id`=194062 WHERE `id`=190035 AND `quest`=13439;
UPDATE `gameobject_questender` SET `id`=194063 WHERE `id`=190035 AND `quest`=13448;
UPDATE `gameobject_questender` SET `id`=194073 WHERE `id`=190082 AND `quest`=13464;
UPDATE `gameobject_questender` SET `id`=194074 WHERE `id`=190082 AND `quest`=13465;
UPDATE `gameobject_questender` SET `id`=194075 WHERE `id`=190082 AND `quest`=13466;
UPDATE `gameobject_questender` SET `id`=194076 WHERE `id`=190082 AND `quest`=13467;
UPDATE `gameobject_questender` SET `id`=194077 WHERE `id`=190082 AND `quest`=13468;
UPDATE `gameobject_questender` SET `id`=194078 WHERE `id`=190082 AND `quest`=13469;
UPDATE `gameobject_questender` SET `id`=194079 WHERE `id`=190082 AND `quest`=13470;
UPDATE `gameobject_questender` SET `id`=194080 WHERE `id`=190082 AND `quest`=13471;
UPDATE `gameobject_questender` SET `id`=194065 WHERE `id`=190102 AND `quest`=13452;
UPDATE `gameobject_questender` SET `id`=194066 WHERE `id`=190102 AND `quest`=13456;
UPDATE `gameobject_questender` SET `id`=194067 WHERE `id`=190102 AND `quest`=13459;
UPDATE `gameobject_questender` SET `id`=194068 WHERE `id`=190102 AND `quest`=13460;
UPDATE `gameobject_questender` SET `id`=194069 WHERE `id`=190102 AND `quest`=13461;
UPDATE `gameobject_questender` SET `id`=194070 WHERE `id`=190102 AND `quest`=13462;
UPDATE `gameobject_questender` SET `id`=194071 WHERE `id`=190102 AND `quest`=13463;
UPDATE `gameobject_questender` SET `id`=194072 WHERE `id`=190102 AND `quest`=13472;
UPDATE `gameobject_questender` SET `id`=194064 WHERE `id`=190102 AND `quest`=13473;
UPDATE `gameobject_questender` SET `id`=194081 WHERE `id`=190102 AND `quest`=13474;

DELETE FROM `gameobject_questender` WHERE `id`=208119 AND `quest`=28992;
DELETE FROM `gameobject_questender` WHERE `id`=208117 AND `quest`=28997;
DELETE FROM `gameobject_questender` WHERE `id`=215906 AND `quest` IN (39657,43055,43056,43057);

DELETE FROM `gameobject_questender` WHERE `id`=243912;
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(243912, 39657, 0);

DELETE FROM `gameobject_queststarter` WHERE `id` IN (190042,190049,190055,190056,190057,190058,190059,190060,190061,190062,190063,190077,190110,190115,191882,191883,194056,194057,194058,194059,194060,194061,194062,194063,194064,215914,243912);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190042, 12338, 0),
(190049, 12346, 0),
(190055, 12352, 0),
(190056, 12353, 0),
(190057, 12354, 0),
(190058, 12355, 0),
(190059, 12356, 0),
(190060, 12357, 0),
(190061, 12358, 0),
(190062, 12359, 0),
(190063, 12360, 0),
(190077, 12375, 0),
(190110, 12404, 0),
(190115, 12409, 0),
(191882, 12944, 0),
(191883, 12945, 0),
(194056, 13433, 0),
(194057, 13434, 0),
(194058, 13435, 0),
(194059, 13436, 0),
(194060, 13437, 0),
(194061, 13438, 0),
(194062, 13439, 0),
(194063, 13448, 0),
(194064, 13473, 0),
(215914, 32051, 0),
(243912, 39657, 0);

DELETE FROM `game_event_gameobject_quest` WHERE `id` IN (190055,190056,190057,190058,190059,190060,190061,190062,190063,190077,191882,191883,194056,194057,194058,194059,194060,194061,194062,194063,194064);
