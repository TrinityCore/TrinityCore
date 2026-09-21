-- Remove PvPFlags for Cavedweller Worg
UPDATE `creature_template_addon` SET `PvPFlags`=0 WHERE `entry`=30164;

-- update worg fur drop rate
UPDATE `creature_loot_template` SET `Chance`=27 WHERE `Item`=42510 AND `Entry`=30164;
