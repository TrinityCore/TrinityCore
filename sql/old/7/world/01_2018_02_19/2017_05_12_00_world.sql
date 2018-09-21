-- Remove SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET from Backstab (53), Garrote (703), Shred (5221), Ambush (8676)
DELETE FROM `spell_custom_attr` WHERE `entry` IN (53, 703, 5221, 8676);

-- Remove SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER from Gouge (1776)
DELETE FROM `spell_custom_attr` WHERE `entry` = 1776;
