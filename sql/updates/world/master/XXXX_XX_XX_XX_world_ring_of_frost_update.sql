-- Remove old spell script
DELETE FROM `spell_script_names` WHERE `spell_id` = 82676 AND `ScriptName` = 'spell_mage_ring_of_frost';

DELETE FROM `spell_script_names` WHERE `spell_id` = 113724 AND `ScriptName` = 'spell_mage_ring_of_frost';
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(113724, 'spell_mage_ring_of_frost'); -- Ring of Frost

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=44199; -- Set flags_extra to trigger
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x22000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=44199 AND `DifficultyID`=0); -- 44199 (Ring of Frost) - Passive, Sessile, Floating - CannotTurn
