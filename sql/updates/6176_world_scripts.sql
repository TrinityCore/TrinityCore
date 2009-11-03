UPDATE `creature_template` SET `AIName` = 'AOEAI',`flags_extra` = '0',`minlevel` = '70',`maxlevel` = '70',`maxlevel` = '70',`faction_A` = '14',`faction_H` = '14' WHERE `entry` IN ('23336','23069','23259');
UPDATE `creature_template` SET `spell1` = '40029' WHERE `entry` = 23069;
UPDATE `creature_template` SET `spell1` = '40610' WHERE `entry` = 23259;
UPDATE `creature_template` SET `spell1` = '40836' WHERE `entry` = 23336;