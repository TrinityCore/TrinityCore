-- light trash npc's (level 85, normal rank)
UPDATE `creature_template` SET `DamageModifier`= 8, `BaseVariance`= 0.5, `mingold`= 5000, `maxgold`= 9000 WHERE `entry` IN (48842, 49125);

-- generic trash npc's (level 85, elite rank)
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 5000, `maxgold`= 9000 WHERE `entry` IN (48851, 48942, 48967, 48968, 48973, 48981, 48985, 49059, 49130, 49184, 49186, 49164);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 3000, `maxgold`= 6000 WHERE `entry` IN (49126, 49174);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 13000 WHERE `entry` IN (49155, 49160);
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `DamageModifier`= 60, `BaseVariance`= 0.5, `mingold`= 3000, `maxgold`= 6000 WHERE `entry` IN (49187, 48988, 48919);
