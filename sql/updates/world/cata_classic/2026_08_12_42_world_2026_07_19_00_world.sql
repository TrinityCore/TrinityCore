-- SpellScriptName
DELETE FROM `spell_script_names` WHERE `spell_id` = 76377;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76377, 'spell_vashjir_sea_legs_aura');

-- Sea Legs
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=68453 WHERE `entry`=205989; -- Saltwater Star
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=68453 WHERE `entry`=202560; -- Conch Shell

UPDATE `quest_details` SET `Emote2`=5, `VerifiedBuild`=68453 WHERE `ID`=25281; -- Pay It Forward
UPDATE `quest_details` SET `Emote2`=396, `VerifiedBuild`=68453 WHERE `ID`=24432; -- Sea Legs

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 76377;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(76377, 5146, 24432, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (A)
(76377, 5145, 24432, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (A)
(76377, 4815, 24432, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (A)
(76377, 5144, 24432, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (A)
(76377, 5146, 25929, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (H)
(76377, 5145, 25929, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (H)
(76377, 4815, 25929, 0, 0, 0, 2, 3, 64, 11), -- (Cast) SpellID: 76377 (Sea Legs) (H)
(76377, 5144, 25929, 0, 0, 0, 2, 3, 64, 11); -- (Cast) SpellID: 76377 (Sea Legs) (H)
