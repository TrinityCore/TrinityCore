ALTER TABLE trinity_string CHANGE content_loc1 content_koKR mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc2 content_frFR mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc3 content_deDE mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc4 content_zhCN mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc5 content_zhTW mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc6 content_esES mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc7 content_esMX mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;
ALTER TABLE trinity_string CHANGE content_loc8 content_ruRU mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL NULL;

ALTER TABLE trinity_string ADD content_enGB mediumtext NULL;
ALTER TABLE trinity_string CHANGE content_enGB content_enGB mediumtext NULL AFTER content_default;
ALTER TABLE trinity_string ADD content_enCN mediumtext NULL;
ALTER TABLE trinity_string CHANGE content_enCN content_enCN mediumtext NULL AFTER content_deDE;
ALTER TABLE trinity_string ADD content_enTW mediumtext NULL;
ALTER TABLE trinity_string CHANGE content_enTW content_enTW mediumtext NULL AFTER content_zhCN;
ALTER TABLE trinity_string ADD content_ptPT mediumtext NULL;
ALTER TABLE trinity_string ADD content_ptBR mediumtext NULL;
ALTER TABLE trinity_string ADD content_itIT mediumtext NULL;
