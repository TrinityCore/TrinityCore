-- Apparition NPC Jorgensen issue 220
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 0, `auras` = 0 WHERE (entry = 43272);
-- Retrait de la Clé de la cage de Messner des loot du Loup issue 214
DELETE FROM `creature_loot_template` WHERE `Entry` = 43340;
-- Apparition NPC Lou Deux-Semelle issue 200
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 0, `auras` = 0 WHERE (entry = 42405);
-- Fluxos Corrigé issue 140
UPDATE `creature_template` SET `InhabitType` = 3 WHERE (entry = 108641);
