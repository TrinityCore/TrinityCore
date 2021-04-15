-- Make deck of trades spell more offilike
UPDATE `spell_loot_template` SET `Chance` = 1.5 WHERE `Entry`=84193 AND `Item` IN (60839,62598);
UPDATE `spell_loot_template` SET `Chance` = 0.5 WHERE `Entry`=84193 AND `Item` IN (60840,60844);
