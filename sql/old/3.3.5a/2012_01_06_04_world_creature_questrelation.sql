-- Fix Captain Vimes questrelation
DELETE FROM `creature_questrelation` WHERE `quest`=1220;
INSERT INTO `creature_questrelation` (`id`,`quest`) VALUES
(4947,1220),
(23951,1220);
