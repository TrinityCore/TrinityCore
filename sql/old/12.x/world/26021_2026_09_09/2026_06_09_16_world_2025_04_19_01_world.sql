-- 15652 (Elder Springpaw) / 20749 (Scalewing Serpent) / 21723 (Blackwind Sabercat) / 22100 (Scorpid Bonecrawler)
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry` IN (15652,20749,21723,22100);
UPDATE `creature_addon` SET `SheathState`=1, `PvpFlags`=0, `auras`=NULL WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (15652,20749,21723,22100));
