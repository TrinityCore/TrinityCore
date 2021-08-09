ALTER TABLE `conversation_actors`
  ADD COLUMN `CreatureId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Idx`,
  ADD COLUMN `CreatureDisplayInfoId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CreatureId`;

UPDATE `conversation_actors` AS ca
INNER JOIN `conversation_actor_template` AS cat ON (ca.ConversationActorId = cat.Id)
SET ca.CreatureId = cat.CreatureId, ca.CreatureDisplayInfoId = cat.CreatureModelId;

DROP TABLE `conversation_actor_template`;
