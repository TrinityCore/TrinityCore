-- 1015 Armor Reduction (Major) -> Acid Spit, Expose Armor and Sunder Armor
-- Remove Curse of Weakness from this group
DELETE FROM `spell_group` WHERE `id`=1015 AND `spell_id`=-1063;

-- 1019 Armor Reduction (Minor) -> Curse of Weakness, Faerie Fire and Sting
-- Add Curse of Weakness to this group
DELETE FROM `spell_group` WHERE `id`=1019 AND `spell_id`=-1063;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1019, -1063);

-- 1051 Spell Hit debuff -> Improved Faerie Fire and Misery
-- Correct Misery spell id
UPDATE `spell_group` SET `spell_id`=33196 WHERE `id`=1050 AND `spell_id`=33191;

-- Core expects these rules to have exclusive same effect stack rule, so change them
UPDATE `spell_group_stack_rules` SET `stack_rule`=3 WHERE `group_id` IN (1015,1019,1051);
