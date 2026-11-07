--
UPDATE `creature_text` SET `Text` = '%s becomes enraged!', `BroadcastTextId` = 7798, `comment` = 'huhuran EMOTE_ENRAGE' WHERE `CreatureID` = 15509 AND `GroupID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 4428 WHERE `CreatureID` = 15509 AND `GroupID` = 1;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_huhuran_wyvern_sting';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26180, 'spell_huhuran_wyvern_sting');
