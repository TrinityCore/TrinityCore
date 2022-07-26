ALTER TABLE `conversation_actors`
  ADD `NoActorObject` TINYINT(3) UNSIGNED NULL DEFAULT '0' AFTER `CreatureDisplayInfoId`,
  ADD `ActivePlayerObject` TINYINT(3) UNSIGNED NULL DEFAULT '0' AFTER `NoActorObject`;

DELETE FROM `conversation_actors` WHERE `ConversationId`=13254 AND `Idx`=1;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(13254,0,0,1,0,0,0,1,40120);
