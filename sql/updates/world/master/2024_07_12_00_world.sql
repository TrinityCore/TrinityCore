DELETE FROM `creature_formations` WHERE `leaderGUID`=9001816;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(9001816,9001816,0,0,0,0,0),
(9001816,9001823,0,0,0,0,0),
(9001816,9001856,0,0,0,0,0);

UPDATE `creature` SET `StringId`='leymor_arcane_tender' WHERE `guid` IN (9001816,9001823,9001856);
