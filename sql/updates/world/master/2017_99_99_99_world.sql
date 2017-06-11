--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hun_flanking_strike','spell_hun_flanking_strike_pet','spell_hun_mongoose_bite','spell_hun_aspect_eagle','spell_hun_hunting_companion_gain_charge','spell_hun_hunting_companion');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(202800,'spell_hun_flanking_strike'),               -- Flanking Strike (202800)
(204740,'spell_hun_flanking_strike_pet'),           -- Flanking Strike pet version (204740)
(190928,'spell_hun_mongoose_bite'),                 -- Mongoose Bite (190928)
(186289,'spell_hun_aspect_eagle'),                  -- Aspect of the Eagle (186289)
(191335,'spell_hun_hunting_companion_gain_charge'), -- Hunting Companion gain charge (191335)
(191336,'spell_hun_hunting_companion');             -- Hunting Companion pet aura (191336)
