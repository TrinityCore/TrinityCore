DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_divine_hymn','spell_gen_major_healing_cooldown_modifier','spell_gen_major_healing_cooldown_modifier_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(157982, 'spell_gen_major_healing_cooldown_modifier'), -- Tranquility (Direct heal + periodic)
(64844, 'spell_gen_major_healing_cooldown_modifier'), -- Divine Hymn (Direct heal)
(114942, 'spell_gen_major_healing_cooldown_modifier'), -- Healing Tide Totem (Direct heal)
(115310, 'spell_gen_major_healing_cooldown_modifier'), -- Revival (Direct heal)
(157982, 'spell_gen_major_healing_cooldown_modifier_aura'), -- Tranquility (Direct heal + periodic)
(271466, 'spell_gen_major_healing_cooldown_modifier_aura'), -- Luminous Barrier (Absorb)
(363534, 'spell_gen_major_healing_cooldown_modifier_aura'); -- Rewind (Periodic)
