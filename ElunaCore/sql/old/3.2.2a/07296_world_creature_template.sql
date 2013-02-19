-- Add Spell "Launch Spear" to creature "Ymirheim Spear Gun"
UPDATE `creature_template` SET `spell1`=59894 WHERE `entry`=31280;
-- Add necessary spells for vehicles (for rev 7285).
UPDATE `creature_template` SET `spell1`=68505,`spell2`=62575,`spell3`=68282,`spell4`=66482 WHERE `entry` IN (36558,35644);
