-- Update wrong translation for 'Scroll of enchant shield: defense'
UPDATE `item_template_locale` SET `Name`='Pergamino de Encantar escudo: defensa' WHERE `ID`=38954 AND `locale` IN ('esES','esMX');
-- Add missing locale for 'Scroll of enchant shield: greater intellect'
DELETE FROM `item_template_locale` WHERE `ID`=44455 AND `locale` IN ('esES','esMX');
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`) VALUES
(44455, 'esES', 'Pergamino de Encantar escudo: intelecto superior', '', -12340),
(44455, 'esMX', 'Pergamino de Encantar escudo: intelecto superior', '', -12340);
