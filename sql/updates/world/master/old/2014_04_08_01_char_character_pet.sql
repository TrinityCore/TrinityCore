-- Warlock
DELETE FROM `character_pet` WHERE `slot` > 24 AND `slot` < 36;
-- Stamped
DELETE FROM `character_pet` WHERE `slot` > 35 AND `slot` < 41;
-- Other
DELETE FROM `character_pet` WHERE `slot` = 100;
DELETE FROM pet_aura WHERE guid not in (select id from character_pet);
DELETE FROM pet_aura_effect WHERE guid not in (select id from character_pet);
DELETE FROM pet_spell WHERE guid not in (select id from character_pet);
DELETE FROM pet_spell_cooldown WHERE guid not in (select id from character_pet);
