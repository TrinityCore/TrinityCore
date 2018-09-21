ALTER TABLE `conversation_template`
  ADD COLUMN `ScriptName` VARCHAR(64) NOT NULL DEFAULT '' AFTER `LastLineEndTime`;
