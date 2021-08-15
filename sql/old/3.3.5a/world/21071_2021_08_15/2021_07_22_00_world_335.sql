--
UPDATE `gameobject_template_locale` a LEFT JOIN `gameobject_template` b ON a.`entry` = b.`entry` LEFT JOIN `broadcast_text_locale` c ON b.`Data4` = c.`ID` AND a.`locale` = c.`locale` SET a.`castBarCaption` = c.`Text` WHERE b.`castBarCaption` != '' AND b.`type` = 0 AND c.`Text` != '';
UPDATE `gameobject_template_locale` a LEFT JOIN `gameobject_template` b ON a.`entry` = b.`entry` LEFT JOIN `broadcast_text_locale` c ON b.`Data6` = c.`ID` AND a.`locale` = c.`locale` SET a.`castBarCaption` = c.`Text` WHERE b.`castBarCaption` != '' AND b.`type` = 1 AND c.`Text` != '';
UPDATE `gameobject_template_locale` a LEFT JOIN `gameobject_template` b ON a.`entry` = b.`entry` LEFT JOIN `broadcast_text_locale` c ON b.`Data6` = c.`ID` AND a.`locale` = c.`locale` SET a.`castBarCaption` = c.`Text` WHERE b.`castBarCaption` != '' AND b.`type` = 2 AND c.`Text` != '';
UPDATE `gameobject_template_locale` a LEFT JOIN `gameobject_template` b ON a.`entry` = b.`entry` LEFT JOIN `broadcast_text_locale` c ON b.`Data14` = c.`ID` AND a.`locale` = c.`locale` SET a.`castBarCaption` = c.`Text` WHERE b.`castBarCaption` != '' AND b.`type` = 3 AND c.`Text` != '';
UPDATE `gameobject_template_locale` a LEFT JOIN `gameobject_template` b ON a.`entry` = b.`entry` LEFT JOIN `broadcast_text_locale` c ON b.`Data12` = c.`ID` AND a.`locale` = c.`locale` SET a.`castBarCaption` = c.`Text` WHERE b.`castBarCaption` != '' AND b.`type` = 6 AND c.`Text` != '';
UPDATE `gameobject_template_locale` a LEFT JOIN `gameobject_template` b ON a.`entry` = b.`entry` LEFT JOIN `broadcast_text_locale` c ON b.`Data14` = c.`ID` AND a.`locale` = c.`locale` SET a.`castBarCaption` = c.`Text` WHERE b.`castBarCaption` != '' AND b.`type` = 10 AND c.`Text` != '';

DELETE FROM `gameobject_template_locale` WHERE `entry` IN (176361,176393,177289);
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`) VALUES
(176361,'deDE','Geißelkessel','Einsammeln',0),
(176361,'esES','Caldera de la Plaga','Recoger',0),
(176361,'esMX','Caldera de la Plaga','Recoger',0),
(176361,'frFR','Chaudron du Fléau','Collecte',0),
(176361,'koKR','스컬지 가마솥','수집 중',0),
(176361,'ruRU','Котел Плети','Сбор',0),
(176361,'zhCN','天灾之锅','收集中',0),
(176361,'zhTW','天譴大鍋','收集中',0),
(176393,'deDE','Geißelkessel','Einsammeln',0),
(176393,'esES','Caldera de la Plaga','Recoger',0),
(176393,'esMX','Caldera de la Plaga','Recoger',0),
(176393,'frFR','Chaudron du Fléau','Collecte',0),
(176393,'koKR','스컬지 가마솥','수집 중',0),
(176393,'ruRU','Котел Плети','Сбор',0),
(176393,'zhCN','天灾之锅','收集中',0),
(176393,'zhTW','天譴大鍋','收集中',0),
(177289,'deDE','Geißelkessel','Einsammeln',0),
(177289,'esES','Caldera de la Plaga','Recoger',0),
(177289,'esMX','Caldera de la Plaga','Recoger',0),
(177289,'frFR','Chaudron du Fléau','Collecte',0),
(177289,'koKR','스컬지 가마솥','수집 중',0),
(177289,'ruRU','Котел Плети','Сбор',0),
(177289,'zhCN','天灾之锅','收集中',0),
(177289,'zhTW','天譴大鍋','收集中',0);
