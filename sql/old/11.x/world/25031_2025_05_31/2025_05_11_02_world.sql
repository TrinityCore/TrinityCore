-- Scriptname
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_no_npc_damage_below_override_70';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(155893, 'spell_gen_no_npc_damage_below_override_70');

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (128703 /*128703 (Vengeful Bones) - No NPC Damage Below Override Points%*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(128703, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '155893'); -- 128703 (Vengeful Bones) - No NPC Damage Below Override Points%
