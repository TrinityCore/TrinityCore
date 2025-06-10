--
UPDATE `creature_text` SET `Text` = "Enjoy the storm warm bloods!", `Sound` = 0, `BroadcastTextId` = 19456, `comment` = "thespia SAY_CLOUD" WHERE `CreatureID` = 17797 AND `GroupID` = 0 AND `ID` = 0;

DELETE FROM `creature_formations` WHERE `leaderGUID` = 3453;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(3453,3453,0,0,3,0,0),
(3453,2090,0,0,3,0,0),
(3453,2093,0,0,3,0,0);
