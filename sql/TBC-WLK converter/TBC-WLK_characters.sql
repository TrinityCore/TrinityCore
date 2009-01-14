ALTER TABLE character_spell
    DROP slot;
DELETE FROM `character_spell` WHERE `spell` IN (28880, 59542, 59543, 59544, 59545, 59547, 59548);
DELETE FROM `character_spell` WHERE `spell` IN (7376,3025,5419,5421,21156,7381,1178,21178,9635,21178,24905,5420,34123,33948,34090,34764,40121,40122);
DELETE FROM character_spell WHERE `spell` IN (
 20580, /*old Shadowmeld*/
 20600, /*Perception*/
 21009, /*old Shadowmeld Passive and new Elusiveness (learned as racial passive)*/
 21184  /*old Seal of Righteousness*/
);
/*old Shadow Resistance, leaned as racial passive of race 5 */
DELETE FROM character_spell USING character_spell INNER JOIN characters ON character_spell.guid = characters.guid
WHERE character_spell.spell = 20579 AND characters.race <> 5;

UPDATE IGNORE character_spell SET spell = 2018 WHERE spell = 2020;
DELETE FROM character_spell                    WHERE spell = 2020;

UPDATE IGNORE character_spell SET spell = 2018 WHERE spell = 2020;
DELETE FROM character_spell                    WHERE spell = 2020;

UPDATE IGNORE character_spell SET spell = 3100 WHERE spell = 2021;
DELETE FROM character_spell                    WHERE spell = 2021;

UPDATE IGNORE character_spell SET spell = 3104 WHERE spell = 2154;
DELETE FROM character_spell                    WHERE spell = 2154;

UPDATE IGNORE character_spell SET spell = 2108 WHERE spell = 2155;
DELETE FROM character_spell                    WHERE spell = 2155;

UPDATE IGNORE character_spell SET spell = 2259 WHERE spell = 2275;
DELETE FROM character_spell                    WHERE spell = 2275;

UPDATE IGNORE character_spell SET spell = 3101 WHERE spell = 2280;
DELETE FROM character_spell                    WHERE spell = 2280;

UPDATE IGNORE character_spell SET spell = 2366 WHERE spell = 2372;
DELETE FROM character_spell                    WHERE spell = 2372;

UPDATE IGNORE character_spell SET spell = 2368 WHERE spell = 2373;
DELETE FROM character_spell                    WHERE spell = 2373;

UPDATE IGNORE character_spell SET spell = 2550 WHERE spell = 2551;
DELETE FROM character_spell                    WHERE spell = 2551;

UPDATE IGNORE character_spell SET spell = 2575 WHERE spell = 2581;
DELETE FROM character_spell                    WHERE spell = 2581;

UPDATE IGNORE character_spell SET spell = 2576 WHERE spell = 2582;
DELETE FROM character_spell                    WHERE spell = 2582;

UPDATE IGNORE character_spell SET spell = 3273 WHERE spell = 3279;
DELETE FROM character_spell                    WHERE spell = 3279;

UPDATE IGNORE character_spell SET spell = 3274 WHERE spell = 3280;
DELETE FROM character_spell                    WHERE spell = 3280;

UPDATE IGNORE character_spell SET spell = 3102 WHERE spell = 3412;
DELETE FROM character_spell                    WHERE spell = 3412;

UPDATE IGNORE character_spell SET spell = 3464 WHERE spell = 3465;
DELETE FROM character_spell                    WHERE spell = 3465;

UPDATE IGNORE character_spell SET spell = 3538 WHERE spell = 3539;
DELETE FROM character_spell                    WHERE spell = 3539;

UPDATE IGNORE character_spell SET spell = 3564 WHERE spell = 3568;
DELETE FROM character_spell                    WHERE spell = 3568;

UPDATE IGNORE character_spell SET spell = 3570 WHERE spell = 3571;
DELETE FROM character_spell                    WHERE spell = 3571;

UPDATE IGNORE character_spell SET spell = 3811 WHERE spell = 3812;
DELETE FROM character_spell                    WHERE spell = 3812;

UPDATE IGNORE character_spell SET spell = 3908 WHERE spell = 3911;
DELETE FROM character_spell                    WHERE spell = 3911;

UPDATE IGNORE character_spell SET spell = 3909 WHERE spell = 3912;
DELETE FROM character_spell                    WHERE spell = 3912;

UPDATE IGNORE character_spell SET spell = 3910 WHERE spell = 3913;
DELETE FROM character_spell                    WHERE spell = 3913;

UPDATE IGNORE character_spell SET spell = 4036 WHERE spell = 4039;
DELETE FROM character_spell                    WHERE spell = 4039;

UPDATE IGNORE character_spell SET spell = 4037 WHERE spell = 4040;
DELETE FROM character_spell                    WHERE spell = 4040;

UPDATE IGNORE character_spell SET spell = 4038 WHERE spell = 4041;
DELETE FROM character_spell                    WHERE spell = 4041;

UPDATE IGNORE character_spell SET spell = 7620 WHERE spell = 7733;
DELETE FROM character_spell                    WHERE spell = 7733;

UPDATE IGNORE character_spell SET spell = 7731 WHERE spell = 7734;
DELETE FROM character_spell                    WHERE spell = 7734;

UPDATE IGNORE character_spell SET spell = 8613 WHERE spell = 8615;
DELETE FROM character_spell                    WHERE spell = 8615;

UPDATE IGNORE character_spell SET spell = 8617 WHERE spell = 8619;
DELETE FROM character_spell                    WHERE spell = 8619;

UPDATE IGNORE character_spell SET spell = 8618 WHERE spell = 8620;
DELETE FROM character_spell                    WHERE spell = 8620;

UPDATE IGNORE character_spell SET spell = 9785 WHERE spell = 9786;
DELETE FROM character_spell                    WHERE spell = 9786;

UPDATE IGNORE character_spell SET spell = 10248 WHERE spell = 10249;
DELETE FROM character_spell                     WHERE spell = 10249;

UPDATE IGNORE character_spell SET spell = 10662 WHERE spell = 10663;
DELETE FROM character_spell                     WHERE spell = 10663;

UPDATE IGNORE character_spell SET spell = 10768 WHERE spell = 10769;
DELETE FROM character_spell                     WHERE spell = 10769;

UPDATE IGNORE character_spell SET spell = 11611 WHERE spell = 11612;
DELETE FROM character_spell                     WHERE spell = 11612;

UPDATE IGNORE character_spell SET spell = 11993 WHERE spell = 11994;
DELETE FROM character_spell                     WHERE spell = 11994;

UPDATE IGNORE character_spell SET spell = 12180 WHERE spell = 12181;
DELETE FROM character_spell                     WHERE spell = 12181;

UPDATE IGNORE character_spell SET spell = 12656 WHERE spell = 12657;
DELETE FROM character_spell                     WHERE spell = 12657;

UPDATE IGNORE character_spell SET spell = 25229 WHERE spell = 25245;
DELETE FROM character_spell                     WHERE spell = 25245;

UPDATE IGNORE character_spell SET spell = 25230 WHERE spell = 25246;
DELETE FROM character_spell                     WHERE spell = 25246;

UPDATE IGNORE character_spell SET spell = 26790 WHERE spell = 26791;
DELETE FROM character_spell                     WHERE spell = 26791;

UPDATE IGNORE character_spell SET spell = 28596 WHERE spell = 28597;
DELETE FROM character_spell                     WHERE spell = 28597;

UPDATE IGNORE character_spell SET spell = 28695 WHERE spell = 28696;
DELETE FROM character_spell                     WHERE spell = 28696;

UPDATE IGNORE character_spell SET spell = 28894 WHERE spell = 28896;
DELETE FROM character_spell                     WHERE spell = 28896;

UPDATE IGNORE character_spell SET spell = 28895 WHERE spell = 28899;
DELETE FROM character_spell                     WHERE spell = 28899;

UPDATE IGNORE character_spell SET spell = 28897 WHERE spell = 28901;
DELETE FROM character_spell                     WHERE spell = 28901;

UPDATE IGNORE character_spell SET spell = 29354 WHERE spell = 29355;
DELETE FROM character_spell                     WHERE spell = 29355;

UPDATE IGNORE character_spell SET spell = 29844 WHERE spell = 29845;
DELETE FROM character_spell                     WHERE spell = 29845;

UPDATE IGNORE character_spell SET spell = 30350 WHERE spell = 30351;
DELETE FROM character_spell                     WHERE spell = 30351;

UPDATE IGNORE character_spell SET spell = 32549 WHERE spell = 32550;
DELETE FROM character_spell                     WHERE spell = 32550;

UPDATE IGNORE character_spell SET spell = 32678 WHERE spell = 32679;
DELETE FROM character_spell                     WHERE spell = 32679;

UPDATE IGNORE character_spell SET spell = 45357 WHERE spell = 45375;
DELETE FROM character_spell                     WHERE spell = 45375;

UPDATE IGNORE character_spell SET spell = 45358 WHERE spell = 45376;
DELETE FROM character_spell                     WHERE spell = 45376;

UPDATE IGNORE character_spell SET spell = 45359 WHERE spell = 45377;
DELETE FROM character_spell                     WHERE spell = 45377;

UPDATE IGNORE character_spell SET spell = 45360 WHERE spell = 45378;
DELETE FROM character_spell                     WHERE spell = 45378;

UPDATE IGNORE character_spell SET spell = 45361 WHERE spell = 45379;
DELETE FROM character_spell                     WHERE spell = 45379;

UPDATE IGNORE character_spell SET spell = 45363 WHERE spell = 45380;
DELETE FROM character_spell                     WHERE spell = 45380;

UPDATE IGNORE character_spell SET spell = 45542 WHERE spell = 50299;
DELETE FROM character_spell                     WHERE spell = 50299;

UPDATE IGNORE character_spell SET spell = 50305 WHERE spell = 50307;
DELETE FROM character_spell                     WHERE spell = 50307;

UPDATE IGNORE character_spell SET spell = 50310 WHERE spell = 50309;
DELETE FROM character_spell                     WHERE spell = 50309;

UPDATE IGNORE character_spell SET spell = 51294 WHERE spell = 51293;
DELETE FROM character_spell                     WHERE spell = 51293;

UPDATE IGNORE character_spell SET spell = 51296 WHERE spell = 51295;
DELETE FROM character_spell                     WHERE spell = 51295;

UPDATE IGNORE character_spell SET spell = 51300 WHERE spell = 51298;
DELETE FROM character_spell                     WHERE spell = 51298;

UPDATE IGNORE character_spell SET spell = 51302 WHERE spell = 51301;
DELETE FROM character_spell                     WHERE spell = 51301;

UPDATE IGNORE character_spell SET spell = 51304 WHERE spell = 51303;
DELETE FROM character_spell                     WHERE spell = 51303;

UPDATE IGNORE character_spell SET spell = 51306 WHERE spell = 51305;
DELETE FROM character_spell                     WHERE spell = 51305;

UPDATE IGNORE character_spell SET spell = 51309 WHERE spell = 51308;
DELETE FROM character_spell                     WHERE spell = 51308;

UPDATE IGNORE character_spell SET spell = 51311 WHERE spell = 51310;
DELETE FROM character_spell                     WHERE spell = 51310;

UPDATE IGNORE character_spell SET spell = 51313 WHERE spell = 51312;
DELETE FROM character_spell                     WHERE spell = 51312;

UPDATE IGNORE character_spell SET spell = 33095 WHERE spell = 54084;
DELETE FROM character_spell                     WHERE spell = 54084;

alter table `character_pet`
    drop column `trainpoint`,
    drop column `loyaltypoints`,
    drop column `loyalty`,
	DROP column slot,
    add `talentpoints` int(11) UNSIGNED default '0' NOT NULL after `Reactstate`;

DROP TABLE IF EXISTS `account_data`;	
CREATE TABLE `account_data` (
  `account` int(11) unsigned NOT NULL default '0',
  `type` int(11) unsigned NOT NULL default '0',
  `time` bigint(11) unsigned NOT NULL default '0',
  `data` longtext NOT NULL,
  PRIMARY KEY  (`account`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_achievement`;
CREATE TABLE `character_achievement` (
      `guid` int(11) NOT NULL,
      `achievement` int(11) NOT NULL,
      `date` int(11) NOT NULL,
      PRIMARY KEY  (`guid`,`achievement`)
    ) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_achievement_progress`;
CREATE TABLE `character_achievement_progress` (
      `guid` int(11) NOT NULL,
      `criteria` int(11) NOT NULL,
      `counter` int(11) NOT NULL,
      `date` int(11) NOT NULL,
      PRIMARY KEY  (`guid`,`criteria`)
    ) ENGINE=MyISAM DEFAULT CHARSET=utf8;
	
UPDATE characters SET data = REPLACE(data,'  ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');
UPDATE characters SET data = CONCAT(
  SUBSTRING(data, 1, length(SUBSTRING_INDEX(data, ' ', 10))), " 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 10))+2, length(SUBSTRING_INDEX(data, ' ', 18))- length(SUBSTRING_INDEX(data, ' ', 10)) - 1), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 20))+2, length(SUBSTRING_INDEX(data, ' ', 22))- length(SUBSTRING_INDEX(data, ' ', 20)) - 1), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 36))+2, length(SUBSTRING_INDEX(data, ' ', 37))- length(SUBSTRING_INDEX(data, ' ', 36)) - 1), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 22))+2, length(SUBSTRING_INDEX(data, ' ', 28))- length(SUBSTRING_INDEX(data, ' ', 22)) - 1), " 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 28))+2, length(SUBSTRING_INDEX(data, ' ', 34))- length(SUBSTRING_INDEX(data, ' ', 28)) - 1), " 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1564))+2, length(SUBSTRING_INDEX(data, ' ', 1565))- length(SUBSTRING_INDEX(data, ' ', 1564)) - 1), " 0 0 0 0 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1565))+2, length(SUBSTRING_INDEX(data, ' ', 1566))- length(SUBSTRING_INDEX(data, ' ', 1565)) - 1), " 0 0 0 0 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 34))+2, length(SUBSTRING_INDEX(data, ' ', 36))- length(SUBSTRING_INDEX(data, ' ', 34)) - 1), " 0 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 46))+2, length(SUBSTRING_INDEX(data, ' ', 48))- length(SUBSTRING_INDEX(data, ' ', 46)) - 1), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 146))+2, length(SUBSTRING_INDEX(data, ' ', 170))- length(SUBSTRING_INDEX(data, ' ', 146)) - 1), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 171))+2, length(SUBSTRING_INDEX(data, ' ', 209))- length(SUBSTRING_INDEX(data, ' ', 171)) - 1), " ",
  ((SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 209))+2, length(SUBSTRING_INDEX(data, ' ', 210))- length(SUBSTRING_INDEX(data, ' ', 209)) - 1) & ~0x100) | ((SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 46))+2, length(SUBSTRING_INDEX(data, ' ', 47))- length(SUBSTRING_INDEX(data, ' ', 46)) - 1) & 0x1000) >> 4)), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 210))+2, length(SUBSTRING_INDEX(data, ' ', 233))- length(SUBSTRING_INDEX(data, ' ', 210)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 233))+2, length(SUBSTRING_INDEX(data, ' ', 358))- length(SUBSTRING_INDEX(data, ' ', 233)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 358))+2, length(SUBSTRING_INDEX(data, ' ', 359))- length(SUBSTRING_INDEX(data, ' ', 358)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 359))+2, length(SUBSTRING_INDEX(data, ' ', 374))- length(SUBSTRING_INDEX(data, ' ', 359)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 374))+2, length(SUBSTRING_INDEX(data, ' ', 375))- length(SUBSTRING_INDEX(data, ' ', 374)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 375))+2, length(SUBSTRING_INDEX(data, ' ', 390))- length(SUBSTRING_INDEX(data, ' ', 375)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 390))+2, length(SUBSTRING_INDEX(data, ' ', 391))- length(SUBSTRING_INDEX(data, ' ', 390)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 391))+2, length(SUBSTRING_INDEX(data, ' ', 406))- length(SUBSTRING_INDEX(data, ' ', 391)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 406))+2, length(SUBSTRING_INDEX(data, ' ', 407))- length(SUBSTRING_INDEX(data, ' ', 406)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 407))+2, length(SUBSTRING_INDEX(data, ' ', 422))- length(SUBSTRING_INDEX(data, ' ', 407)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 422))+2, length(SUBSTRING_INDEX(data, ' ', 423))- length(SUBSTRING_INDEX(data, ' ', 422)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 423))+2, length(SUBSTRING_INDEX(data, ' ', 438))- length(SUBSTRING_INDEX(data, ' ', 423)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 438))+2, length(SUBSTRING_INDEX(data, ' ', 439))- length(SUBSTRING_INDEX(data, ' ', 438)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 439))+2, length(SUBSTRING_INDEX(data, ' ', 454))- length(SUBSTRING_INDEX(data, ' ', 439)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 454))+2, length(SUBSTRING_INDEX(data, ' ', 455))- length(SUBSTRING_INDEX(data, ' ', 454)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 455))+2, length(SUBSTRING_INDEX(data, ' ', 470))- length(SUBSTRING_INDEX(data, ' ', 455)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 470))+2, length(SUBSTRING_INDEX(data, ' ', 471))- length(SUBSTRING_INDEX(data, ' ', 470)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 471))+2, length(SUBSTRING_INDEX(data, ' ', 486))- length(SUBSTRING_INDEX(data, ' ', 471)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 486))+2, length(SUBSTRING_INDEX(data, ' ', 487))- length(SUBSTRING_INDEX(data, ' ', 486)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 487))+2, length(SUBSTRING_INDEX(data, ' ', 502))- length(SUBSTRING_INDEX(data, ' ', 487)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 502))+2, length(SUBSTRING_INDEX(data, ' ', 503))- length(SUBSTRING_INDEX(data, ' ', 502)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 503))+2, length(SUBSTRING_INDEX(data, ' ', 518))- length(SUBSTRING_INDEX(data, ' ', 503)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 518))+2, length(SUBSTRING_INDEX(data, ' ', 519))- length(SUBSTRING_INDEX(data, ' ', 518)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 519))+2, length(SUBSTRING_INDEX(data, ' ', 534))- length(SUBSTRING_INDEX(data, ' ', 519)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 534))+2, length(SUBSTRING_INDEX(data, ' ', 535))- length(SUBSTRING_INDEX(data, ' ', 534)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 535))+2, length(SUBSTRING_INDEX(data, ' ', 550))- length(SUBSTRING_INDEX(data, ' ', 535)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 550))+2, length(SUBSTRING_INDEX(data, ' ', 551))- length(SUBSTRING_INDEX(data, ' ', 550)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 551))+2, length(SUBSTRING_INDEX(data, ' ', 566))- length(SUBSTRING_INDEX(data, ' ', 551)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 566))+2, length(SUBSTRING_INDEX(data, ' ', 567))- length(SUBSTRING_INDEX(data, ' ', 566)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 567))+2, length(SUBSTRING_INDEX(data, ' ', 582))- length(SUBSTRING_INDEX(data, ' ', 567)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 582))+2, length(SUBSTRING_INDEX(data, ' ', 583))- length(SUBSTRING_INDEX(data, ' ', 582)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 583))+2, length(SUBSTRING_INDEX(data, ' ', 598))- length(SUBSTRING_INDEX(data, ' ', 583)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 598))+2, length(SUBSTRING_INDEX(data, ' ', 599))- length(SUBSTRING_INDEX(data, ' ', 598)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 599))+2, length(SUBSTRING_INDEX(data, ' ', 614))- length(SUBSTRING_INDEX(data, ' ', 599)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 614))+2, length(SUBSTRING_INDEX(data, ' ', 615))- length(SUBSTRING_INDEX(data, ' ', 614)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 615))+2, length(SUBSTRING_INDEX(data, ' ', 630))- length(SUBSTRING_INDEX(data, ' ', 615)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 630))+2, length(SUBSTRING_INDEX(data, ' ', 631))- length(SUBSTRING_INDEX(data, ' ', 630)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 631))+2, length(SUBSTRING_INDEX(data, ' ', 646))- length(SUBSTRING_INDEX(data, ' ', 631)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 646))+2, length(SUBSTRING_INDEX(data, ' ', 647))- length(SUBSTRING_INDEX(data, ' ', 646)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 647))+2, length(SUBSTRING_INDEX(data, ' ', 922))- length(SUBSTRING_INDEX(data, ' ', 647)) - 1),
  " 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 922))+2, length(SUBSTRING_INDEX(data, ' ', 926))- length(SUBSTRING_INDEX(data, ' ', 922)) - 1), " 0 0 0 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 926))+2, length(SUBSTRING_INDEX(data, ' ', 1332))- length(SUBSTRING_INDEX(data, ' ', 926)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1332))+2, length(SUBSTRING_INDEX(data, ' ', 1544))- length(SUBSTRING_INDEX(data, ' ', 1332)) - 1), " 0 ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1544))+2, length(SUBSTRING_INDEX(data, ' ', 1564))- length(SUBSTRING_INDEX(data, ' ', 1544)) - 1), " ",
  SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1566))+2, length(SUBSTRING_INDEX(data, ' ', 1592))- length(SUBSTRING_INDEX(data, ' ', 1566)) - 1),
  " 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ")
WHERE length(SUBSTRING_INDEX(data, ' ', 1592)) < length(data) and length(SUBSTRING_INDEX(data, ' ', 1593)) >= length(data);

UPDATE item_instance SET data = REPLACE(data,'  ',' ');
UPDATE item_instance SET data = CONCAT(TRIM(data),' ');
UPDATE item_instance SET data= CONCAT(
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',30),' ',-30),' 0 0 0 ',
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',60),' ',-60+30),' 0 ')
WHERE SUBSTRING_INDEX(data,' ',60) = data AND SUBSTRING_INDEX(data,' ',60-1) <> data;
UPDATE item_instance SET data= CONCAT(
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',30),' ',-30),' 0 0 0 ',
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',60),' ',-60+30),' 0 ',
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',134),' ',-134+60))
WHERE SUBSTRING_INDEX(data,' ',134) = data AND SUBSTRING_INDEX(data,' ',134-1) <> data;





	