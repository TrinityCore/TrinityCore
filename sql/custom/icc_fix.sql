--Abominations have wrong spells
--Standart spells are saved in comments

--UPDATE `creature_template` SET `spell1` = 72508 WHERE `entry` IN ('38788', '38789', '38790');
UPDATE `creature_template` SET `spell1` = 72527, `spell2` = 72457, `spell3` = 70542, `spell6` = 71516 WHERE `entry` IN ('38788', '38789', '38790');
