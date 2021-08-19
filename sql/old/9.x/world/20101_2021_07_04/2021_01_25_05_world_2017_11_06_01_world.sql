-- Auchenai Crypts
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry` IN (20299); -- Auchenai Monk (1)
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry` IN (20315); -- Raging Skeleton (1)
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry` IN (20300); -- Auchenai Necromancer (1)

-- Shadow Labyrinth
-- UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (18797); -- Tortured Skeleton
UPDATE `creature_template` SET `minlevel`=70,`maxlevel`=71 WHERE `entry` IN (20641); -- Cabal Deathsworn (1)
UPDATE `creature_template` SET `maxlevel`=70 WHERE `entry` IN (20638); -- Cabal Acolyte (1)
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry` IN (20645); -- Cabal Ritualist (1)

-- Fix Stats error
-- UPDATE `creature_classlevelstats` SET `basehp0`=3635 WHERE `level`=66 AND `class` IN (1,4);
