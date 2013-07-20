-- Delete wrongly inserted spell linked spell of Scion of Eternity - "Arcane Barrage".
-- It should be handled in the original caster spell with spellscript effect.
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=56397 AND `spell_effect`=63934 AND`type`=1;

-- Update flags in creature for Malygos since differ from these in creature_template
UPDATE `creature` SET `unit_flags`=320,`dynamicflags`=8 WHERE `id`=28859;
