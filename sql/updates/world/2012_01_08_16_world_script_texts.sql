-- Arthas text entrys fix by Albis (on Gitgub TC Issue tracker https://github.com/TrinityCore/TrinityCore/issues/4002)
UPDATE `script_texts` SET `sound` = 13855, `type` = 1 WHERE `entry` = -1575022;
UPDATE `script_texts` SET `sound` = 13848, `type` = 1 WHERE `entry` = -1575021;
UPDATE `script_texts` SET `sound` = 13847, `type` = 1 WHERE `entry` = -1575020;
UPDATE `script_texts` SET `sound` = 13845, `type` = 1 WHERE `entry` = -1575019;
UPDATE `script_texts` SET `sound` = 13842, `type` = 1 WHERE `entry` = -1575018;
UPDATE `script_texts` SET `sound` = 13856, `type` = 1 WHERE `entry` = -1575015;
UPDATE `script_texts` SET `sound` = 13857, `type` = 1 WHERE `entry` = -1575016;
UPDATE `script_texts` SET `sound` = 13858, `type` = 1 WHERE `entry` = -1575017;

DELETE FROM `script_texts` WHERE `entry` IN (-1575003, -1575014);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES 
(24266,-1575003,'Your sacrifice is a testament to your obedience. Indeed you are worthy of this charge. Arise, and forever be known as Svala Sorrowgrave!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14732,1,0,0,'SAY_DIALOG_OF_ARTHAS_1'),
(24266,-1575014,'Your first test awaits you. Destroy our uninvited guests.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14733,1,0,0,'SAY_DIALOG_OF_ARTHAS_2');
