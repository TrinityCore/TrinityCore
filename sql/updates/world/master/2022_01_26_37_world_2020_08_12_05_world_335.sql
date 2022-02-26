-- Emerald Dragons + Azuregos and Lord Kazzak seem to drop similar amounts
UPDATE `creature_template` SET `mingold` = 130*100*100, `maxgold` = 182*100*100 WHERE `entry` IN (
-- Azuregos
-- https://youtu.be/7haJ41AAujk?t=118 161g, narrator says "usually about 160g"
6109,
-- Ysondre
-- https://youtu.be/3ZSRE2JQKWU?t=246 182g?
-- https://youtu.be/5_IMr6hOoHg?t=247 130g
14887,
-- Lethon
14888,
-- Emeriss
14889,
-- Taerar
-- https://youtu.be/3ZSRE2JQKWU?t=246 139g
-- https://youtu.be/PRfjvlbBTpA?t=366 78g x 2 players = 156g
14890,
-- Lord Kazzak
-- https://youtu.be/-P1iMu-CLuA?t=245 170g (look at guild chat)
12397);
