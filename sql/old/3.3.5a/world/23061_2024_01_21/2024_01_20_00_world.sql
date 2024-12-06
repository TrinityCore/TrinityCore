-- Delete two cata texts from db
DELETE FROM `npc_text` WHERE `ID` IN (18268,17425);
DELETE FROM `broadcast_text` WHERE `ID` IN (52965,48369);
DELETE FROM `broadcast_text_locale` WHERE `ID` IN (52965,48369);
