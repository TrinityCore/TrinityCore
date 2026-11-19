-- BLIZZ, CONSISTENCY PLS.
UPDATE `locales_creature` SET `name_loc1` = REPLACE(`name_loc1`, "[4.x 미사용]", "");
UPDATE `locales_creature` SET `name_loc1` = REPLACE(`name_loc1`, "[4.x 폐기] ", "");
UPDATE `locales_creature` SET `name_loc1` = REPLACE(`name_loc1`, " (4.x 미사용)", "");
UPDATE `locales_creature` SET `name_loc1` = REPLACE(`name_loc1`, "zzOLD", "") WHERE `entry` NOT IN (22970, 22971, 15384, 21122);

UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[DEPRECATED 4.x] ", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[DEPRECATED 4.0] ", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[DEPRECATED 4.x]", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[DEPRECATED 4.0]", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[INUTILISÉ 4.x] ", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[Inutilisé pour 4.x] ", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[INUTILISÉ pour 4.x] ", "");
UPDATE `locales_creature` SET `name_loc2` = REPLACE(`name_loc2`, "[VIEUX]", "") WHERE `entry` NOT IN (22970, 22971, 15384, 21122);

UPDATE `locales_creature` SET `name_loc3` = REPLACE(`name_loc3`, "[Deprecated for 4.x] ", "");
UPDATE `locales_creature` SET `name_loc3` = REPLACE(`name_loc3`, "[DEPRECATED 4.0] ", "");
UPDATE `locales_creature` SET `name_loc3` = REPLACE(`name_loc3`, "[INUTILISÉ 4.x] ", "");
UPDATE `locales_creature` SET `name_loc3` = REPLACE(`name_loc3`, "[Inutilisé pour 4.x] ", "");

UPDATE `locales_creature` SET `name_loc5` = REPLACE(`name_loc5`, "[Deprecated for 4.x] ", "");
UPDATE `locales_creature` SET `name_loc5` = REPLACE(`name_loc5`, "[Deprecated for 4.x]", "");
UPDATE `locales_creature` SET `name_loc5` = REPLACE(`name_loc5`, "[UNUSED 4.x ]", "");
UPDATE `locales_creature` SET `name_loc5` = REPLACE(`name_loc5`, "(Deprecated in 4.x)", "");
UPDATE `locales_creature` SET `name_loc5` = REPLACE(`name_loc5`, "zzOLD", "") WHERE `entry` NOT IN (22970, 22971, 15384, 21122);

UPDATE `locales_creature` SET `name_loc6` = REPLACE(`name_loc6`, "[Deprecated for 4.x] ", "");
UPDATE `locales_creature` SET `name_loc6` = REPLACE(`name_loc6`, "[Deprecated for 4.x]", "");
UPDATE `locales_creature` SET `name_loc6` = REPLACE(`name_loc6`, "[UNUSED 4.x ]", "");
UPDATE `locales_creature` SET `name_loc6` = REPLACE(`name_loc6`, " (Deprecated in 4.x)", "");
UPDATE `locales_creature` SET `name_loc6` = REPLACE(`name_loc6`, "zzOLD", "") WHERE `entry` NOT IN (22970, 22971, 15384, 21122);

UPDATE `locales_creature` SET `name_loc7` = REPLACE(`name_loc7`, "[Deprecated for 4.x] ", "");
UPDATE `locales_creature` SET `name_loc7` = REPLACE(`name_loc7`, "[Deprecated for 4.x]", "");
UPDATE `locales_creature` SET `name_loc7` = REPLACE(`name_loc7`, "[UNUSED 4.x ]", "");
UPDATE `locales_creature` SET `name_loc7` = REPLACE(`name_loc7`, " (Deprecated in 4.x)", "");
UPDATE `locales_creature` SET `name_loc7` = REPLACE(`name_loc7`, "zzOLD", "") WHERE `entry` NOT IN (22970, 22971, 15384, 21122);

UPDATE `locales_creature` SET `name_loc8` = REPLACE(`name_loc8`, "[Deprecated for 4.x] ", "");
UPDATE `locales_creature` SET `name_loc8` = REPLACE(`name_loc8`, "[Deprecated for 4.x]", "");
UPDATE `locales_creature` SET `name_loc8` = REPLACE(`name_loc8`, "[UNUSED 4.x ]", "");
UPDATE `locales_creature` SET `name_loc8` = REPLACE(`name_loc8`, "[UNUSED] ", "") WHERE `entry` IN (4318, 4115);
UPDATE `locales_creature` SET `name_loc8` = REPLACE(`name_loc8`, " (Deprecated in 4.x)", "");
UPDATE `locales_creature` SET `name_loc8` = REPLACE(`name_loc8`, "zzOLD", "") WHERE `entry` NOT IN (22970, 22971, 15384, 21122);
