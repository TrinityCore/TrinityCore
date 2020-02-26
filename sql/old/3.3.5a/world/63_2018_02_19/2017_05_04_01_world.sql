DROP TABLE IF EXISTS `npc_text_locale`;
CREATE TABLE `npc_text_locale` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Locale` varchar(4) NOT NULL,
  `Text0_0` longtext,
  `Text0_1` longtext,
  `Text1_0` longtext,
  `Text1_1` longtext,
  `Text2_0` longtext,
  `Text2_1` longtext,
  `Text3_0` longtext,
  `Text3_1` longtext,
  `Text4_0` longtext,
  `Text4_1` longtext,
  `Text5_0` longtext,
  `Text5_1` longtext,
  `Text6_0` longtext,
  `Text6_1` longtext,
  `Text7_0` longtext,
  `Text7_1` longtext,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "koKR", `Text0_0_loc1`, `Text0_1_loc1`, `Text1_0_loc1`, `Text1_1_loc1`, `Text2_0_loc1`, `Text2_1_loc1`, `Text3_0_loc1`, `Text3_1_loc1`, `Text4_0_loc1`, `Text4_1_loc1`, `Text5_0_loc1`, `Text5_1_loc1`, `Text6_0_loc1`, `Text6_1_loc1`, `Text7_0_loc1`, `Text7_1_loc1`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc1) > 0 && LENGTH(Text0_1_loc1) > 0 && LENGTH(Text1_0_loc1) > 0 && LENGTH(Text1_1_loc1) > 0 && LENGTH(Text2_0_loc1) > 0 && LENGTH(Text2_1_loc1) > 0 && LENGTH(Text3_0_loc1) > 0 && LENGTH(Text3_1_loc1) > 0 && LENGTH(Text4_0_loc1) > 0 && LENGTH(Text4_1_loc1) > 0 && LENGTH(Text5_0_loc1) > 0 && LENGTH(Text5_1_loc1) > 0 && LENGTH(Text6_0_loc1) > 0 && LENGTH(Text6_1_loc1) > 0 && LENGTH(Text7_0_loc1) > 0 && LENGTH(Text7_1_loc1) > 0);

-- frFR
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "frFR", `Text0_0_loc2`, `Text0_1_loc2`, `Text1_0_loc2`, `Text1_1_loc2`, `Text2_0_loc2`, `Text2_1_loc2`, `Text3_0_loc2`, `Text3_1_loc2`, `Text4_0_loc2`, `Text4_1_loc2`, `Text5_0_loc2`, `Text5_1_loc2`, `Text6_0_loc2`, `Text6_1_loc2`, `Text7_0_loc2`, `Text7_1_loc2`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc2) > 0 && LENGTH(Text0_1_loc2) > 0 && LENGTH(Text1_0_loc2) > 0 && LENGTH(Text1_1_loc2) > 0 && LENGTH(Text2_0_loc2) > 0 && LENGTH(Text2_1_loc2) > 0 && LENGTH(Text3_0_loc2) > 0 && LENGTH(Text3_1_loc2) > 0 && LENGTH(Text4_0_loc2) > 0 && LENGTH(Text4_1_loc2) > 0 && LENGTH(Text5_0_loc2) > 0 && LENGTH(Text5_1_loc2) > 0 && LENGTH(Text6_0_loc2) > 0 && LENGTH(Text6_1_loc2) > 0 && LENGTH(Text7_0_loc2) > 0 && LENGTH(Text7_1_loc2) > 0);

-- deDE
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "deDE", `Text0_0_loc3`, `Text0_1_loc3`, `Text1_0_loc3`, `Text1_1_loc3`, `Text2_0_loc3`, `Text2_1_loc3`, `Text3_0_loc3`, `Text3_1_loc3`, `Text4_0_loc3`, `Text4_1_loc3`, `Text5_0_loc3`, `Text5_1_loc3`, `Text6_0_loc3`, `Text6_1_loc3`, `Text7_0_loc3`, `Text7_1_loc3`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc3) > 0 && LENGTH(Text0_1_loc3) > 0 && LENGTH(Text1_0_loc3) > 0 && LENGTH(Text1_1_loc3) > 0 && LENGTH(Text2_0_loc3) > 0 && LENGTH(Text2_1_loc3) > 0 && LENGTH(Text3_0_loc3) > 0 && LENGTH(Text3_1_loc3) > 0 && LENGTH(Text4_0_loc3) > 0 && LENGTH(Text4_1_loc3) > 0 && LENGTH(Text5_0_loc3) > 0 && LENGTH(Text5_1_loc3) > 0 && LENGTH(Text6_0_loc3) > 0 && LENGTH(Text6_1_loc3) > 0 && LENGTH(Text7_0_loc3) > 0 && LENGTH(Text7_1_loc3) > 0);

-- zhCN
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "zhCN", `Text0_0_loc4`, `Text0_1_loc4`, `Text1_0_loc4`, `Text1_1_loc4`, `Text2_0_loc4`, `Text2_1_loc4`, `Text3_0_loc4`, `Text3_1_loc4`, `Text4_0_loc4`, `Text4_1_loc4`, `Text5_0_loc4`, `Text5_1_loc4`, `Text6_0_loc4`, `Text6_1_loc4`, `Text7_0_loc4`, `Text7_1_loc4`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc4) > 0 && LENGTH(Text0_1_loc4) > 0 && LENGTH(Text1_0_loc4) > 0 && LENGTH(Text1_1_loc4) > 0 && LENGTH(Text2_0_loc4) > 0 && LENGTH(Text2_1_loc4) > 0 && LENGTH(Text3_0_loc4) > 0 && LENGTH(Text3_1_loc4) > 0 && LENGTH(Text4_0_loc4) > 0 && LENGTH(Text4_1_loc4) > 0 && LENGTH(Text5_0_loc4) > 0 && LENGTH(Text5_1_loc4) > 0 && LENGTH(Text6_0_loc4) > 0 && LENGTH(Text6_1_loc4) > 0 && LENGTH(Text7_0_loc4) > 0 && LENGTH(Text7_1_loc4) > 0);

-- zhTW
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "zhTW", `Text0_0_loc5`, `Text0_1_loc5`, `Text1_0_loc5`, `Text1_1_loc5`, `Text2_0_loc5`, `Text2_1_loc5`, `Text3_0_loc5`, `Text3_1_loc5`, `Text4_0_loc5`, `Text4_1_loc5`, `Text5_0_loc5`, `Text5_1_loc5`, `Text6_0_loc5`, `Text6_1_loc5`, `Text7_0_loc5`, `Text7_1_loc5`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc5) > 0 && LENGTH(Text0_1_loc5) > 0 && LENGTH(Text1_0_loc5) > 0 && LENGTH(Text1_1_loc5) > 0 && LENGTH(Text2_0_loc5) > 0 && LENGTH(Text2_1_loc5) > 0 && LENGTH(Text3_0_loc5) > 0 && LENGTH(Text3_1_loc5) > 0 && LENGTH(Text4_0_loc5) > 0 && LENGTH(Text4_1_loc5) > 0 && LENGTH(Text5_0_loc5) > 0 && LENGTH(Text5_1_loc5) > 0 && LENGTH(Text6_0_loc5) > 0 && LENGTH(Text6_1_loc5) > 0 && LENGTH(Text7_0_loc5) > 0 && LENGTH(Text7_1_loc5) > 0);

-- esES
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "esES", `Text0_0_loc6`, `Text0_1_loc6`, `Text1_0_loc6`, `Text1_1_loc6`, `Text2_0_loc6`, `Text2_1_loc6`, `Text3_0_loc6`, `Text3_1_loc6`, `Text4_0_loc6`, `Text4_1_loc6`, `Text5_0_loc6`, `Text5_1_loc6`, `Text6_0_loc6`, `Text6_1_loc6`, `Text7_0_loc6`, `Text7_1_loc6`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc6) > 0 && LENGTH(Text0_1_loc6) > 0 && LENGTH(Text1_0_loc6) > 0 && LENGTH(Text1_1_loc6) > 0 && LENGTH(Text2_0_loc6) > 0 && LENGTH(Text2_1_loc6) > 0 && LENGTH(Text3_0_loc6) > 0 && LENGTH(Text3_1_loc6) > 0 && LENGTH(Text4_0_loc6) > 0 && LENGTH(Text4_1_loc6) > 0 && LENGTH(Text5_0_loc6) > 0 && LENGTH(Text5_1_loc6) > 0 && LENGTH(Text6_0_loc6) > 0 && LENGTH(Text6_1_loc6) > 0 && LENGTH(Text7_0_loc6) > 0 && LENGTH(Text7_1_loc6) > 0);

-- esMX
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "esMX", `Text0_0_loc7`, `Text0_1_loc7`, `Text1_0_loc7`, `Text1_1_loc7`, `Text2_0_loc7`, `Text2_1_loc7`, `Text3_0_loc7`, `Text3_1_loc7`, `Text4_0_loc7`, `Text4_1_loc7`, `Text5_0_loc7`, `Text5_1_loc7`, `Text6_0_loc7`, `Text6_1_loc7`, `Text7_0_loc7`, `Text7_1_loc7`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc7) > 0 && LENGTH(Text0_1_loc7) > 0 && LENGTH(Text1_0_loc7) > 0 && LENGTH(Text1_1_loc7) > 0 && LENGTH(Text2_0_loc7) > 0 && LENGTH(Text2_1_loc7) > 0 && LENGTH(Text3_0_loc7) > 0 && LENGTH(Text3_1_loc7) > 0 && LENGTH(Text4_0_loc7) > 0 && LENGTH(Text4_1_loc7) > 0 && LENGTH(Text5_0_loc7) > 0 && LENGTH(Text5_1_loc7) > 0 && LENGTH(Text6_0_loc7) > 0 && LENGTH(Text6_1_loc7) > 0 && LENGTH(Text7_0_loc7) > 0 && LENGTH(Text7_1_loc7) > 0);

-- ruRU
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
  (SELECT `ID`, "ruRU", `Text0_0_loc8`, `Text0_1_loc8`, `Text1_0_loc8`, `Text1_1_loc8`, `Text2_0_loc8`, `Text2_1_loc8`, `Text3_0_loc8`, `Text3_1_loc8`, `Text4_0_loc8`, `Text4_1_loc8`, `Text5_0_loc8`, `Text5_1_loc8`, `Text6_0_loc8`, `Text6_1_loc8`, `Text7_0_loc8`, `Text7_1_loc8`
   FROM `locales_npc_text`
   WHERE LENGTH(Text0_0_loc8) > 0 && LENGTH(Text0_1_loc8) > 0 && LENGTH(Text1_0_loc8) > 0 && LENGTH(Text1_1_loc8) > 0 && LENGTH(Text2_0_loc8) > 0 && LENGTH(Text2_1_loc8) > 0 && LENGTH(Text3_0_loc8) > 0 && LENGTH(Text3_1_loc8) > 0 && LENGTH(Text4_0_loc8) > 0 && LENGTH(Text4_1_loc8) > 0 && LENGTH(Text5_0_loc8) > 0 && LENGTH(Text5_1_loc8) > 0 && LENGTH(Text6_0_loc8) > 0 && LENGTH(Text6_1_loc8) > 0 && LENGTH(Text7_0_loc8) > 0 && LENGTH(Text7_1_loc8) > 0);

DROP TABLE IF EXISTS `locales_npc_text`;
