--
-- https://www.wowhead.com/wotlk/fr/item=4432/lettre-de-sully-balloo
DELETE FROM `page_text_locale` WHERE `ID`=332 AND `locale`='frFR';
INSERT INTO `page_text_locale` (`ID`,`locale`,`Text`,`VerifiedBuild`) VALUES
(332,'frFR','Mais, ô ma Sara, si les morts peuvent revenir à Azeroth et entourer, invisibles, ceux qu\'ils aiment, je serai toujours à vos côtés dans les jours heureux comme dans les nuits les plus sombres, partageant vos heures de joie comme vos moments de tristesse. Si jamais vous sentez une douce brise sur votre joue, ce sera mon souffle ; si l\'air rafraîchit vos tempes, ce sera mon esprit qui passe.$B$BSara, ne me pleurez pas, pensez que je suis parti et que je vous attends, car nous nous reverrons.$B$B--Sully',0);
