--
UPDATE `creature_template_locale` SET `Title`='Боеприпасы' WHERE  `entry`=28800 AND `locale`='ruRU';
UPDATE `creature_template_locale` SET `Title`='Боеприпасы' WHERE  `entry`=28813 AND `locale`='ruRU';
DELETE FROM `item_template_locale` WHERE `ID` IN (3930) AND `locale` = 'ruRU';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`) VALUES (3930, 'ruRU', 'Ключ Моури');
DELETE FROM `item_template_locale` WHERE `ID` IN (42482) AND `locale` = 'ruRU';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`) VALUES (42482, 'ruRU', 'Ключ Аметистовой крепости');
UPDATE `creature_template_locale` SET `Title`='Боеприпасы' WHERE  `entry`=30572 AND `locale`='ruRU';
UPDATE `creature_template_locale` SET `Title`='Боеприпасы' WHERE  `entry`=30437 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `Description`='Этим порошком определённо должна заинтересоваться Тиффани Картье из Даларана.' WHERE  `ID`=46849 AND `locale`='ruRU';
DELETE FROM `item_template_locale` WHERE `ID` IN (44581,44582,45796) AND `locale` = 'ruRU';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`) VALUES (44581, 'ruRU', 'Ключ для доступа к героическому режиму Радужного Средоточия');
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`) VALUES (44582, 'ruRU', 'Ключ к Радужному Средоточию');
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`) VALUES (45796, 'ruRU', 'Ключ к Священному Планетарию');
UPDATE `creature_template_locale` SET `Title`='Продавец особых боеприпасов' WHERE  `entry`=29493 AND `locale`='ruRU';
