/*
-- Hallow's End -- Schlotternächte
-- ObjectiveText -- BroadcastText -- 3.3.5

-- 1657 - Die Verpestung von Süderstade
UPDATE `quest_template_locale` SET `ObjectiveText1`="Werft die Stinkbombe in Süderstade ab", `VerifiedBuild`=18019 WHERE `ID` = 1657 AND `locale` = "deDE";

-- 8353 - Hühnchengegacker für ein Pfefferminzbonbon
UPDATE `quest_template_locale` SET `ObjectiveText1`="Gackert für Gastwirt Feuerbräu wie ein Huhn", `VerifiedBuild`=18019 WHERE `ID` = 8353 AND `locale` = "deDE";

-- 8354 - Hühnchengegacker für ein Pfefferminzbonbon
UPDATE `quest_template_locale` SET `ObjectiveText1`="Gackert für Gastwirt Feuerbräu wie ein Huhn", `VerifiedBuild`=18019 WHERE `ID` = 8354 AND `locale` = "deDE";

-- 8355 - Kaugummikugelexpress
UPDATE `quest_template_locale` SET `ObjectiveText1`="Spielt einen \"Zug\" für Talvash", `VerifiedBuild`=18019 WHERE `ID` = 8355 AND `locale` = "deDE";

-- 8356 - Muskelspiel für Nugat
UPDATE `quest_template_locale` SET `ObjectiveText1`="Gebt für Gastwirtin Gryshka mit Euren Muskeln an", `VerifiedBuild`=18019 WHERE `ID` = 8356 AND `locale` = "deDE";

-- 8357 - Tanzen für Marzipan
UPDATE `quest_template_locale` SET `ObjectiveText1`="Tanzt für Gastwirtin Saelienne", `VerifiedBuild`=18019 WHERE `ID` = 8357 AND `locale` = "deDE";

-- 8358 - Kaugummikugelexpress
UPDATE `quest_template_locale` SET `ObjectiveText1`="Spielt einen \"Zug\" für Talvash", `VerifiedBuild`=18019 WHERE `ID` = 8358 AND `locale` = "deDE";

-- 8359 - Muskelspiel für Nugat
UPDATE `quest_template_locale` SET `ObjectiveText1`="Gebt für Gastwirtin Gryshka mit Euren Muskeln an", `VerifiedBuild`=18019 WHERE `ID` = 8359 AND `locale` = "deDE";

-- 8360 - Tanzen für Marzipan
UPDATE `quest_template_locale` SET `ObjectiveText1`="Tanzt für Gastwirtin Pala", `VerifiedBuild`=18019 WHERE `ID` = 8360 AND `locale` = "deDE";

-- 11360 - Übung bei der Brandwache
UPDATE `quest_template_locale` SET `ObjectiveText1`="Löscht das Feuer", `VerifiedBuild`=18019 WHERE `ID` = 11360 AND `locale` = "deDE";

-- 11361 - Feuerübung
UPDATE `quest_template_locale` SET `ObjectiveText1`="Löscht das Feuer", `VerifiedBuild`=18019 WHERE `ID` = 11361 AND `locale` = "deDE";

-- 11439 - Übung bei der Brandwache
UPDATE `quest_template_locale` SET `ObjectiveText1`="Löscht das Feuer", `VerifiedBuild`=18019 WHERE `ID` = 11439 AND `locale` = "deDE";

-- 11440 - Übung bei der Brandwache
UPDATE `quest_template_locale` SET `ObjectiveText1`="Löscht das Feuer", `VerifiedBuild`=18019 WHERE `ID` = 11440 AND `locale` = "deDE";

-- 11449 - Feuerübung
UPDATE `quest_template_locale` SET `ObjectiveText1`="Löscht das Feuer", `VerifiedBuild`=18019 WHERE `ID` = 11449 AND `locale` = "deDE";

-- 11450 - Feuerübung
UPDATE `quest_template_locale` SET `ObjectiveText1`="Löscht das Feuer", `VerifiedBuild`=18019 WHERE `ID` = 11450 AND `locale` = "deDE";

-- Ruft den kopflosen Reiter
DELETE FROM `broadcast_text_locale` WHERE `ID` = 22695 AND `locale` = "deDE";
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`, `VerifiedBuild`) VALUES (22695, "deDE", "Erhebe dich, Reiter...", "Erhebe dich, Reiter...", 18019);

DELETE FROM `broadcast_text_locale` WHERE `ID` = 22696 AND `locale` = "deDE";
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`, `VerifiedBuild`) VALUES (22696, "deDE", "Deine Zeit ist gekommen...", "Deine Zeit ist gekommen...", 18019);

DELETE FROM `broadcast_text_locale` WHERE `ID` = 22720 AND `locale` = "deDE";
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`, `VerifiedBuild`) VALUES (22720, "deDE", "Heut' Nacht sei dein Leben...", "Heut' Nacht sei dein Leben...", 18019);

DELETE FROM `broadcast_text_locale` WHERE `ID` = 22721 AND `locale` = "deDE";
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`, `VerifiedBuild`) VALUES (22721, "deDE", "Auf ewig genommen!", "Auf ewig genommen!", 18019);
*/
