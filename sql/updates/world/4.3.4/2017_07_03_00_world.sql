-- Adding missing weapon skills
-- Axe (44) for shamans (64)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | 64) WHERE (`racemask` = 0 AND `skill` = 44);
-- SWORDS (43) for rogues (8)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | 8) WHERE (`racemask` = 0 AND `skill` = 43);
-- THROWN (176) for warriors (1)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | 1) WHERE (`racemask` = 0 AND `skill` = 176);
-- POLEARMS (229) for warriors (1), hunters (4), paladins (2), druids (1024)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | (1+2+4+1024)) WHERE (`racemask` = 0 AND `skill` = 229);
-- Guns (46) for warriors (1), rogues (8)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | (1+8)) WHERE (`racemask` = 0 AND `skill` = 46);
-- Crossbows (226) for warriors (1), rogues (8)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | (1+8)) WHERE (`racemask` = 0 AND `skill` = 226);
-- Bows (45) for warriors (1), rogues (8)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | (1+8)) WHERE (`racemask` = 0 AND `skill` = 45);
-- Staves (136) for warriors (1), hunters (4)
UPDATE `playercreateinfo_skills` SET `classMask` = (classmask | (1+4)) WHERE (`racemask` = 0 AND `skill` = 136);
