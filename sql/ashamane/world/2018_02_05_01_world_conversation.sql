DELETE FROM `conversation_actors` WHERE (`ConversationId`=2509 AND `ConversationActorId`=53568 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(2509, 53568, 0, 25901);

UPDATE `conversation_actors` SET `VerifiedBuild`=25901 WHERE (`ConversationId`=1212 AND `ConversationActorId`=50759 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=25901 WHERE (`ConversationId`=1212 AND `ConversationActorId`=50760 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=25901 WHERE (`ConversationId`=1212 AND `ConversationActorId`=50759 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=25901 WHERE (`ConversationId`=1211 AND `ConversationActorId`=50759 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=25901 WHERE (`ConversationId`=1211 AND `ConversationActorId`=50760 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=25901 WHERE (`ConversationId`=1211 AND `ConversationActorId`=50759 AND `Idx`=0);

DELETE FROM `conversation_actor_template` WHERE `Id`=53568;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(53568, 91223, 63641, 25901);

UPDATE `conversation_actor_template` SET `VerifiedBuild`=25901 WHERE `Id`=50760;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=25901 WHERE `Id`=50759;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=25901 WHERE `Id`=50760;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=25901 WHERE `Id`=50759;

DELETE FROM `conversation_line_template` WHERE `Id`=5312;
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(5312, 0, 625, 0, 0, 25901);

UPDATE `conversation_line_template` SET `StartTime`=11253, `VerifiedBuild`=25901 WHERE `Id`=2872;
UPDATE `conversation_line_template` SET `StartTime`=4990, `VerifiedBuild`=25901 WHERE `Id`=2871;
UPDATE `conversation_line_template` SET `VerifiedBuild`=25901 WHERE `Id`=2870;
UPDATE `conversation_line_template` SET `StartTime`=8962, `VerifiedBuild`=25901 WHERE `Id`=2868;
UPDATE `conversation_line_template` SET `StartTime`=5342, `VerifiedBuild`=25901 WHERE `Id`=2867;
UPDATE `conversation_line_template` SET `VerifiedBuild`=25901 WHERE `Id`=2866;

DELETE FROM `conversation_template` WHERE `Id`=2509;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(2509, 5312, 8473, 25901);

UPDATE `conversation_template` SET `LastLineEndTime`=16979, `VerifiedBuild`=25901 WHERE `Id`=1212;
UPDATE `conversation_template` SET `LastLineEndTime`=13465, `VerifiedBuild`=25901 WHERE `Id`=1211;
